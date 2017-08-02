# Ruby, Proxy Pattern and Metaprogramming

You have this class:

```ruby
class BankAccount
  attr_reader :balance

  def initialize(starting_balance = 0)
    @balance = starting_balance
  end

  def deposit(amount)
    @balance += amount
  end

  def withdraw(amount)
    @balance -= amount
  end
```

Probably it is not necessary to explain this code. A simple `BankAccount` class that it allows to deposit or to withdraw money. However this implementation is very insecure because anybody could remove your money. You should add an authentication mechanism.

### When you should use a Proxy pattern?

![](https://upload.wikimedia.org/wikipedia/commons/thumb/7/75/Proxy_pattern_diagram.svg/439px-Proxy_pattern_diagram.svg.png)

A Proxy pattern is used to separate the real object from the client who used it. The objective is append new improvements or functionalities. To do that, is necessary to create a new class who acts like an intermediary.

This pattern can be confused with the Adapter pattern easily. The difference is simple: the Proxy pattern don't modify the original object's behavior like the Adapter pattern, the Proxy pattern only defines how to get access to the original object.

Here a proxy class:

```ruby
require './bank_account.rb'

class AccountDummyProxy
  def initialize(real_account)
    @real_account = real_account
  end

  def balance
    @real_account.balance
  end

  def deposit(amount)
    @real_account.deposit(amount)
  end

  def withdraw(amount)
    @real_account.withdraw(amount)
  end
end
```

Yes, `AccountDummyProxy` is a dummy class, it works exactly like the original class. But now you can modify this class to add a protection mechanism like this:

```ruby
require 'etc'
require './bank_account.rb'

class AccountProtectionProxy
  def initialize(real_account, owner_name)
    @subject = real_account
    @owner_name = owner_name
  end

  def balance
    access?
    @subject.balance
  end

  def deposit(amount)
    access?
    @subject.deposit(amount)
  end

  def withdraw(amount)
    access?
    @subject.withdraw(amount)
  end

  private

  def access?
    message = "Illegal access: #{Etc.getlogin} cannot access account."
    raise message unless Etc.getlogin == @owner_name
  end
end
```

Check out the new difference in this `AccountProtectionProxy` class is the addition of a method called `access?`. The class have the real original object (`BankAccount`) in `@subject`. This `access?` check the passsed user name can access to the account, so this  method is called before to call each `@subject` method.

This class is a specific type of Proxy (Protection Proxy). You can define a Virtual Proxy which allows you to have a lazy initialization of the real object:

```ruby
require './bank_account.rb'

class AccountVirtualProxy
  def initialize(starting_balance = 0)
    @starting_balance = starting_balance
  end

  def balance
    subject.balance
  end

  def deposit(amount)
    subject.deposit(amount)
  end

  def withdraw(amount)
    subject.withdraw(amount)
  end

  private

  def subject
    @subject ||= BankAccount.new(@starting_balance)
  end
end
```

The `BankAccount` object is not created until is called at the first time when you call public methods like `balance` or `deposit`.

### When you should use Metaprogramming?

*Metaprogramming is writing code that writes code.*

Sorry, I haven't got the real answer to this. A lot of people love metaprogramming. However many people hate it too.

I think is a good idea to use metaprogramming when you have to code a lot of boring methods that they are very similar between them ([Ruby Metaprogramming is even cooler than it sounds](https://www.toptal.com/ruby/ruby-metaprogramming-cooler-than-it-sounds)).

But it's true that metaprogramming performs slower and it adds some of hidden magic ([Avoid using metaprogramming](https://matt.aimonetti.net/posts/2008/05/04/avoid-using-metaprogramming/)).

Maybe for this case is a better idea not to use metaprogramming but is a good moment to see metaprogramming in action. Here there are two ways.

Method Missing approach:

```ruby
require 'etc'
require './bank_account.rb'

class AccountProxy
  def initialize(owner_name, starting_balance = 0)
    @owner_name = owner_name
    @starting_balance = starting_balance
  end

  def method_missing(name, *args, &block)
    access?
    if subject.respond_to?(name)
      subject.public_send(name, *args, &block)
    else
      super
    end
  end

  def respond_to_missing?(name, include_private = false)
    subject.respond_to?(name) || super
  end

  private

  def access?
    message = "Illegal access: #{Etc.getlogin} cannot access account."
    raise message unless Etc.getlogin == @owner_name
  end

  def subject
    @subject ||= BankAccount.new(@starting_balance)
  end
end
```

A good recomendation is [define `respond_to_missing?`](https://robots.thoughtbot.com/always-define-respond-to-missing-when-overriding) too.

The `balance` or `amount` methods are not defined. But don't worry. When you call  `AccountProxy.new.balance` is called the `AccountProxy#method_missing` method where is called explicitily with `subject.public_send(method_name,...)`.

Dynamic Methods approach:

```ruby
require 'etc'
require './bank_account.rb'

class AccountProxyAlternative
  def initialize(owner_name, starting_balance = 0)
    @owner_name = owner_name
    @starting_balance = starting_balance

    subject.public_methods(false).each do |name|
      AccountProxyAlternative.define_action(name)
    end
  end

  def self.define_action(name)
    define_method(name) do |*args|
      access?
      subject.send(name, *args)
    end
  end

  private

  def access?
    message = "Illegal access: #{Etc.getlogin} cannot access account."
    raise message unless Etc.getlogin == @owner_name
  end

  def subject
    @subject ||= BankAccount.new(@starting_balance)
  end
end
```

In this case, the `balance` or `amount` methods are defined dynamically with `define_method` method in `self.define_action(name)` class method.

### Method Missing vs Dynamic Methods

Both approachs work although...

- Method missing is more dangerous: if you call a method called `display` which already exists (`Object#display`), this method will never call `method_missing`. To solve this is necessary implement a blank slate object, an object with just a few of necessary methods. In Ruby is enough with inherit the Proxy class from `BasicObject`.

- Dynamic methods requiere to know more information: in the previous examples the names of the dynamic methods are defined in `BankAccount` class. But if you did not know the names, you could not define them.

- Method missing is slower: if you already know how works [Ruby method lookup](https://gist.github.com/damien-roche/351bf4e7991449714533) you must understand why this technique performs worse than dynamics methods (a lot of methods calls until to find the wanted method).

So... you should use Dynamic Methods approach when you can and use Method Missing approach when it be the only way.

### Must-read

- [Design Patterns in Ruby](http://designpatternsinruby.com/) by Russ Olsen.
- [Metaprogramming Ruby 2](https://pragprog.com/book/ppmetr2/metaprogramming-ruby-2) by Paolo Perrotta.

**Code examples based on examples of `Design Patterns in Ruby` and `Metaprogramming Ruby 2`**

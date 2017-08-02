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

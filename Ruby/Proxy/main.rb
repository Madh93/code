require './account_proxy.rb'
require './account_dummy_proxy.rb'
require './account_protection_proxy.rb'
require './account_proxy_alternative.rb'
require './account_virtual_proxy.rb'

# 1. Bank account without Proxy
account = BankAccount.new(100)
account.deposit(50)
account.withdraw(20)
puts "1. Without Proxy: #{account.balance}"

# 2. Bank account with dummy Proxy (no difference)
account = AccountDummyProxy.new(BankAccount.new(100))
account.deposit(50)
account.withdraw(20)
puts "2. Dummy Proxy (no difference): #{account.balance}"

# 3. Bank account with protection Proxy (authentication system)
account = AccountProtectionProxy.new(BankAccount.new(100), Etc.getlogin)
account.deposit(50)
account.withdraw(20)
puts "3. Protection Proxy (authentication system): #{account.balance}"

# 4. Bank account with virtual Proxy (lazy initialization)
account = AccountVirtualProxy.new(100)
account.deposit(50)
account.withdraw(20)
puts "4. Virtual Proxy (lazy initialization): #{account.balance}"

# 5. Bank account with protection and virtual Proxy (method missing)
account = AccountProxy.new(Etc.getlogin, 100)
account.deposit(50)
account.withdraw(20)
puts "5. Virtual Protection Proxy (method missing): #{account.balance}"

# 6. Bank account with protection and virtual Proxy (dynamics methods)
account = AccountProxyAlternative.new(Etc.getlogin, 100)
account.deposit(50)
account.withdraw(20)
puts "6. Virtual Protection Proxy (dynamics methods): #{account.balance}"

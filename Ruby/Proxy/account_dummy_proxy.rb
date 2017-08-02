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

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

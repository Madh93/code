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

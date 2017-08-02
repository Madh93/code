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

require './contact'

# Contact List
class ContactList
  def initialize
    @contacts = []
    @contacts << Contact.new('1', 'Alice', '611222333')
    @contacts << Contact.new('2', 'Bob', '611444555')
  end

  # Show all contacts
  def all
    @contacts.map(&:to_hash)
  end

  # Get contact data
  def find(id)
    contact = @contacts.find { |c| c.id == id }
    contact.to_hash unless contact.nil?
  end

  # Add a new contact
  def add(data = {})
    @contacts << Contact.new(data[:id], data[:name], data[:number])
  end

  # Update a existing contact
  def update(data = {})
    contact = @contacts.find { |c| c.id == data[:id] }
    contact.name = data[:name] || contact.name
    contact.number = data[:number] || contact.number
  end

  # Remove a existing contact
  def remove(id)
    @contacts.delete_if { |c| c.id == id }
  end
end

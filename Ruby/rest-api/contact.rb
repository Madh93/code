# Contact
class Contact
  attr_reader :id
  attr_accessor :name, :number

  def initialize(id, name, number)
    @id = id
    @name = name
    @number = number
  end

  def to_hash
    hash = {}
    instance_variables.each do |var|
      hash[var.to_s.delete('@')] = instance_variable_get(var)
    end
    hash
  end
end

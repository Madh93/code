

class Vigenere

  attr_reader :chiper_text

  def initialize (plain_text, key)
    @plain_text, @key = plain_text, key
    @chiper_text = ""
  end

  def run

    @plain_text.each_char.with_index do |c, i|
      @chiper_text << "#{ ((((c.ord-65) + (@key[i%(@key.size)].ord-65)) % 27) + 65).chr }"
    end
  end

end


algorithm = Vigenere.new("ATTACKATDAWN", "LEMON")
algorithm.run
puts "Chiper text: #{algorithm.chiper_text}"
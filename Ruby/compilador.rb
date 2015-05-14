# LI $R1, 6
# ADD $R3, $R1, $R2     0011_0001_0010_0000 (R Type)
LI = 0b1010
OPCODE = 0b111

RType = Struct.new(:opcode,:rs,:rs,:rd)
IType = Struct.new(:opcode,:rs,:rs,:inmediate)
JType = Struct.new(:opcode,:inmediate)
MyType = Struct.new(:opcode, :inmediate, :register)

class Integer
  def to_bin(width)
    '%0*b' % [width, self]
  end
end

#1.to_bin(8) # => "00000001"
#0x55.to_bin(8) # => "01010101"
#0xaaa.to_bin(16) # => "0000101010101010"

#Entrada
instruccion = "LI $1, 8" 

cmd = instruccion.split

if cmd.first.upcase == "LI"

    inst = MyType.new(LI.to_s(2))
end

inst.register = cmd[1].delete("$,").to_i.to_bin(4)
inst.inmediate = cmd[2].to_i.to_bin(8)

puts "Codificacion: " << inst.register << "_" << inst.inmediate << "_" << inst.opcode
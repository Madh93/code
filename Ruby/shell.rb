require 'colorize'

class Shell

  def initialize
    @user = `echo -n $USER`
    @host = "migue-portatil"
    @cmd = ""
  end

  def start
    loop do
      STDOUT.flush
      print prompt
      @cmd = gets.chomp
      #STDOUT.flush
      case @cmd.split.first
        when "exit" then exit
        when "calc" then calc
        else system(@cmd)
      end
    end
  end

  def prompt
    "#{@user}@#{@host}:~$ ".yellow
  end

  def calc
    # signos = /[-+\*\/]/

    # operacion = @cmd.split.drop(1)


    # if @cmd.include?signos
    #  p "si"
    # else
    #  p "no"
    # end
    
  end

end



shell = Shell.new.start
require 'Qt'
require './board.rb'

class QtApp < Qt::MainWindow
    
    def initialize
        super
        
        setWindowTitle "Nibbles"
       
        setCentralWidget Board.new(self)
       
        resize 310, 310
        move 300, 300

        show
    end
end

app = Qt::Application.new ARGV
QtApp.new
app.exec
# Ventana con boton de salir

require 'Qt'


class QtApp < Qt::Widget

    def initialize
        super
        
        setWindowTitle "Quit button"
        
        init_ui
        
        resize 250, 150
        move 300, 300

        show
    end
    
    def init_ui    
        quit = Qt::PushButton.new 'Quit', self
        quit.resize 80, 30
        quit.move 50, 50
        connect quit, SIGNAL('clicked()'), $qApp, SLOT('quit()')
    end
    
end

app = Qt::Application.new ARGV
QtApp.new
app.exec
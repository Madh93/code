require 'Qt'

class MainWindow < Qt::Widget

  def initialize
    super

    setWindowTitle "Ruby Rules"

    layout = Qt::VBoxLayout.new
    label = Qt::Label.new("Hola mundo!")
    button = Qt::PushButton.new("Salir")

    layout.addWidget(label)
    layout.addWidget(button)
    setLayout(layout)

    connect button, SIGNAL('clicked()'), $qApp, SLOT('quit()')

    show
  end
end

app = Qt::Application.new ARGV


ventana = MainWindow.new

app.exec
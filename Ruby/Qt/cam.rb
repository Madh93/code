require 'Qt'

class MainWindow < Qt::Widget

  def initialize
    super

    setWindowTitle "Ruby Rules"
    resize(600,600)

    layout = Qt::VBoxLayout.new
    label = Qt::Label.new("Hola mundo!")
    button = Qt::PushButton.new("Salir")
    
    img = Qt::Pixmap.new("/home/migue/shin.jpg")
    scene = Qt::GraphicsScene.new
    scene.addPixmap(img)
    gv = Qt::GraphicsView.new
    gv.setScene(scene)
    gv.resize(300,300)

    layout.addWidget(gv)
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
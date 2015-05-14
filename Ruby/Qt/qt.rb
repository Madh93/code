require 'Qt'
 
app = Qt::Application.new(ARGV)
 
hello = Qt::PushButton.new('Hello World!')
hello.setWindowTitle "Center window"
hello.resize(300, 50)
hello.show()
 
app.exec()
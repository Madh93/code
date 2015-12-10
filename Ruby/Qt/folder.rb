require 'Qt'


class QtApp < Qt::Widget

    def initialize
        super
        
        setWindowTitle "New Folder"
        
        init_ui
        
        resize 300, 300
        move 300, 300

        show
    end
    
    def init_ui
    
        grid = Qt::GridLayout.new self

        nameLabel = Qt::Label.new "Name", self
        nameEdit = Qt::LineEdit.new self
        text = Qt::TextEdit.new self
        okButton = Qt::PushButton.new "OK", self
        closeButton = Qt::PushButton.new "Close", self

        grid.addWidget nameLabel, 0, 0
        grid.addWidget nameEdit, 0, 1, 1, 3
        grid.addWidget text, 1, 0, 2, 4
        grid.setColumnStretch 1, 1
        grid.addWidget okButton, 4, 2
        grid.addWidget closeButton, 4, 3

    end    
end

app = Qt::Application.new(ARGV)
QtApp.new
app.exec
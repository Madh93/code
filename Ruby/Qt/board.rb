WIDTH = 300
HEIGHT = 300
DOT_SIZE = 10
ALL_DOTS = WIDTH * HEIGHT / (DOT_SIZE * DOT_SIZE)
RAND_POS = 29
DELAY = 140

$x = [0] * ALL_DOTS
$y = [0] * ALL_DOTS

class Board < Qt::Widget

    
    def initialize(parent)
        super(parent)
        
        setFocusPolicy Qt::StrongFocus
       
        initGame
    end


    def initGame
    
        @left = false
        @right = true
        @up = false
        @down = false
        @inGame = true
        @dots = 3
        
        begin
            @ball = Qt::Image.new "dot.png"
            @apple = Qt::Image.new "apple.png"
            @head = Qt::Image.new "head.png"
        rescue
            puts "cannot load images"
        end

        for i in (0..@dots)
            $x[i] = 50 - i * 10
            $y[i] = 50
        end

        locateApple
        setStyleSheet "QWidget { background-color: #000000 }"
        
        @timer = Qt::BasicTimer.new 
        @timer.start(140, self)
        
    end


    def paintEvent event

        painter = Qt::Painter.new
        painter.begin self

        if @inGame
            drawObjects painter
        else 
            gameOver painter
        end

        painter.end
    end

    def drawObjects painter

        painter.drawImage @apple_x, @apple_y, @apple

        for z in (0..@dots)
            if z == 0
                painter.drawImage $x[z], $y[z], @head
            else 
                painter.drawImage $x[z], $y[z], @ball
            end
        end
    end

    def gameOver painter
        msg = "Game Over"
        small = Qt::Font.new "Helvetica", 12,
            Qt::Font::Bold.value
        
        metr = Qt::FontMetrics.new small
        
        textWidth = metr.width msg
        h = height
        w = width

        painter.setPen Qt::Color.new Qt::white
        painter.setFont small
        painter.translate Qt::Point.new w/2, h/2
        painter.drawText -textWidth/2, 0, msg
    end


    def checkApple

        if $x[0] == @apple_x and $y[0] == @apple_y 
            @dots = @dots + 1
            locateApple
        end
    end
    
    def move

        z = @dots

        while z > 0
            $x[z] = $x[(z - 1)]
            $y[z] = $y[(z - 1)]
            z = z - 1
        end

        if @left
            $x[0] -= DOT_SIZE
        end

        if @right 
            $x[0] += DOT_SIZE
        end

        if @up
            $y[0] -= DOT_SIZE
        end

        if @down
            $y[0] += DOT_SIZE
        end
        
     end


    def checkCollision

        z = @dots
       
        while z > 0
            if z > 4 and $x[0] == $x[z] and $y[0] == $y[z]
                @inGame = false
            end
            z = z - 1
        end

        if $y[0] > HEIGHT
            @inGame = false
        end
        
        if $y[0] < 0
            @inGame = false
        end
        
        if $x[0] > WIDTH
            @inGame = false
        end
        
        if $x[0] < 0
            @inGame = false
        end    
        
    end


    def locateApple
    
        r = rand RAND_POS
        @apple_x = r * DOT_SIZE
        r = rand RAND_POS
        @apple_y = r * DOT_SIZE
    end

    def timerEvent event

        if @inGame 
            checkApple
            checkCollision
            move
        else 
            @timer.stop
        end

        repaint
    end

    def keyPressEvent event
        
        key = event.key
        
        if key == Qt::Key_Left.value and not @right
            @left = true
            @up = false
            @down = false
        end
        
        if key == Qt::Key_Right.value and not @left
            @right = true
            @up = false
            @down = false
        end
        
        if key == Qt::Key_Up.value and not @down
            @up = true
            @right = false
            @left = false            
        end
        
        if key == Qt::Key_Down.value and not @up
            @down = true
            @right = false
            @left = false
        end
    end
end
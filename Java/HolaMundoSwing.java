import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class HolaMundoSwing {
    public static void main(String[] args) {
        JFrame frame = new JFrame("HolaMundoSwing");
        final JLabel label = new JLabel("Hola Mundo");
        frame.getContentPane().add(label);

        //frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.addWindowListener(new java.awt.event.WindowAdapter(){
           public void windowClosing(WindowEvent e){
             System.exit(0);
           }
        }
        );

        frame.pack();
        frame.setVisible(true);
    }
}
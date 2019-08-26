/*******************************
 * Unit 7, Chapter 17 - Programming Assignment
 * By Kevin Kretz | 24 July 2019
 * This is a program that displays a dialog box show a message and a randomly chosen color.
 * This random color is to be used as the background color of a JFrame window which should appear after "OK" is selected.
 * The window asks your name and thanks you for playing once "Enter" is pressed.
 ********************************/
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class KKUnit7Ch17 extends JFrame {
  private static final int WIDTH = 400;
  private static final int HEIGHT = 150;
  private JTextField nameBox;
  private JLabel greeting;
  private String randomColor;
  private JLabel namePrompt;

  public KKUnit7Ch17() {
    randomColor = showMessageDialog();

    // Upon clicking OK
    // Create a JFrame window
    // Set the background and label text color as shown in sample below

    // Red window with White for label color
    if (randomColor == "RED") {
      getContentPane().setBackground(Color.red);
      getContentPane().setForeground(Color.white);
    }

    // White(ish) window with Black for label color
    else if (randomColor == "WHITE") {
      getContentPane().setBackground(Color.white);
      getContentPane().setForeground(Color.black);
    }

    // Yellow window with Black for label color
    else if (randomColor == "YELLOW") {
      getContentPane().setBackground(Color.yellow);
      getContentPane().setForeground(Color.black);
    }

    // Green window with Blue for label color
    else if (randomColor == "GREEN") {
      getContentPane().setBackground(Color.green);
      getContentPane().setForeground(Color.blue);
    }

    // Blue window with White for label color
    else {
      getContentPane().setBackground(Color.blue);
      getContentPane().setForeground(Color.white);
    }

    setTitle("Color Changing Window");
    setSize(WIDTH, HEIGHT);
    setLayout(new FlowLayout());
    setDefaultCloseOperation(EXIT_ON_CLOSE);

    // Include a label asking to enter name
    getUserName();

    setVisible(true);
  }

// Utilize showMessageDialog to output the message shown in the sample at the bottom.
// A random color should be output with each run
  private String showMessageDialog() {
    ArrayList<String> colors = new ArrayList<String>();
    Random random = new Random();
    colors.add("RED");
    colors.add("WHITE");
    colors.add("YELLOW");
    colors.add("GREEN");
    colors.add("BLUE");

    randomColor = colors.get(random.nextInt(5));
    JOptionPane.showMessageDialog(null, "The following window color will be randomly chosen from\nRed, White, Yellow, Green and Blue.\n\nYour color will be: " + randomColor);
  
    return randomColor;
  }

  // Include a label asking to enter name
  private void getUserName() {
    namePrompt = new JLabel("What is your name?");

    // Include a textfield to get input for name
    nameBox = new JTextField(15);
    greeting = new JLabel();
    add(namePrompt);
    add(nameBox);
    add(greeting);
    nameBox.addActionListener(new Listener());
  }

  // Upon hitting "Enter" on the keyboard
  // Use an inner class for the listener
  private class Listener implements ActionListener {
    public void actionPerformed(ActionEvent e) {
      String message;
      namePrompt.setVisible(false);
      nameBox.setVisible(false);

      // output thank you message to include the name entered
      message = "Thanks for playing " + nameBox.getText();
      nameBox.setText("");
      greeting.setText(message);
    }
  }

  public static void main(String[] args) {
    new KKUnit7Ch17();
  }
}

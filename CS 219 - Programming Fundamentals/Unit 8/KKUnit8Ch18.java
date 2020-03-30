/*******************************
 * Unit 8, Chapter 18 - Programming Assignment
 * By Kevin Kretz | 02 Aug 2019
 * This is a program that that displays a JFrame window with 5 buttons.
 * The buttons will be used to control the background color.
 * The button’s text will be randomly chosen from 5 colors
 * The background color will change to the color shown on the button. 
 ********************************/

import java.util.ArrayList;
import java.util.Random;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class KKUnit8Ch18 extends JFrame {
  private static final int WIDTH = 400;
  private static final int HEIGHT = 100;

  public KKUnit8Ch18() {
    setTitle("Color Changing Frame");
    setSize(WIDTH, HEIGHT);
    setLayout(new FlowLayout());
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    createContents();
    setVisible(true);
  }

  private void createContents() {
    Random random = new Random();
    int randomNumber;
    ArrayList<JButton> buttons = new ArrayList<JButton>();

    // Create buttons to be used
    JButton red = new JButton("Red");
    JButton yellow = new JButton("Yellow");
    JButton green = new JButton("Green");
    JButton blue = new JButton("Blue");
    JButton white = new JButton("White");

    // add buttons to arrayList "buttons"
    buttons.add(red);
    buttons.add(yellow);
    buttons.add(green);
    buttons.add(blue);
    buttons.add(white);

    // display buttons in random order
    for (int i = 0; i < 5; i++) {
      randomNumber = random.nextInt(buttons.size());
      add(buttons.get(randomNumber)); // add random button to JFrame
      buttons.remove(randomNumber); //remove button from arrayList, to avoid duplicates
    }

    // add listeners for each button
    red.addActionListener(new Listener());
    yellow.addActionListener(new Listener());
    green.addActionListener(new Listener());
    blue.addActionListener(new Listener());
    white.addActionListener(new Listener());
  }

  // Change background color based on which color is clicked.
  private class Listener implements ActionListener {
    public void actionPerformed(ActionEvent e) {
      if (e.getActionCommand() == "Red"){
        getContentPane().setBackground(Color.red);
      }
      else if (e.getActionCommand() == "Blue"){
        getContentPane().setBackground(Color.blue);
      }
      else if (e.getActionCommand() == "Green"){
        getContentPane().setBackground(Color.green);
      }
      else if (e.getActionCommand() == "Yellow"){
        getContentPane().setBackground(Color.yellow);
      }
      else {
        getContentPane().setBackground(Color.white);
      }
    }
  }
  
  public static void main(String[] args) {
    new KKUnit8Ch18();
  }
}

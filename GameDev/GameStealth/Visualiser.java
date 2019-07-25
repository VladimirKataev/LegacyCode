//import
import java.util.Scanner;
import java.util.ArrayList;
import java.io.DataInputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import javax.swing.JFrame;

public class Visualiser extends JFrame implements KeyListener{
	int framesDrawn = 0;
	BufferedImage backBuffer;
	int resx = 1920;
	int resy = 1080;
	InputSpace buttons;
	public void setup(int width, int height, InputSpace actions){
		setTitle("Stealth Dude");
		setSize(width, height);
		setResizable(false);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setFocusable(true);
		requestFocusInWindow();
		addKeyListener(this);
		setExtendedState(JFrame.MAXIMIZED_BOTH);
		setUndecorated(true);
    backBuffer = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
		setVisible(true);
		resx = width;
		resy = height;
		buttons = actions;
	}
	public void draw(GameCode game){	//<<<<<<-------------get an ordered list of what to draw. draw with it's method
                Graphics gr = getGraphics();
                Graphics bbg = backBuffer.getGraphics();
                bbg.setColor(Color.WHITE);
                bbg.fillRect(0, 0, resx, resy);
								bbg.setColor(Color.BLACK);
								bbg.drawString("Yeet " + framesDrawn++,0, 10);

								game.draw(bbg);


								gr.drawImage(backBuffer, 0, 0, this);

	}

	public void keyPressed(KeyEvent e){
		System.out.println(e.getKeyCode() + " pressed");
		switch( e.getKeyCode()){
			case 87:
				buttons.up = true;
				break;
			case 65:
				buttons.left = true;
				break;
			case 83:
				buttons.down = true;
				break;
			case 68:
				buttons.right = true;
				break;
			case 10:
				buttons.select = true;
				break;
			default:
				System.out.println("button " + e.getKeyCode());
		}
	}
	public void keyReleased(KeyEvent e){
		System.out.println(e.getKeyCode() + " unpressed");
		switch( e.getKeyCode()){
			case 87:
				buttons.up = false;
				break;
			case 65:
				buttons.left = false;
				break;
			case 83:
				buttons.down = false;
				break;
			case 68:
				buttons.right = false;
				break;
			case 10:
				buttons.select = false;
				break;
			default:
				System.out.println("button " + e.getKeyCode());
		}
	}
	public void keyTyped(KeyEvent e){}
	public InputSpace getInputs(){
		return buttons;
	}
}

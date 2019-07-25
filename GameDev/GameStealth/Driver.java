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

public class Driver{
	public static void main(String[] args){
		// set up resolution, window, events, which draws onto canvas
		int resx = 1920;
		int resy = 1080;
		int fps = 60;
		Visualiser draw = new Visualiser();
		GameCode game = new GameCode();
		try{
			game.setup();
		}
		catch(Exception e){
			System.out.println("Big oof");
		}
		InputSpace actions = new InputSpace();
		draw.setup(resx, resy, actions);


		while(true){//-------------------------------------------------------Driver-side running
      long time = System.currentTimeMillis();
			time = (1000 / fps) - (System.currentTimeMillis() - time);
      if (time > 0){
        try{
          Thread.sleep(time);
        }
        catch(Exception e){}
			}
			draw.draw(game);
			game.update(draw.getInputs());
		}



	}
}

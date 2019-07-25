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
		int w = 1920;
		int h = 1080;
		int f = 60;

		try{//----------------------------------------------Read config file
			File cfg = new File("config.txt");
			Scanner readCfg = new Scanner(cfg);
			w = Integer.parseInt(readCfg.nextLine());System.out.println(w);
			h = Integer.parseInt(readCfg.nextLine());System.out.println(h);
			f = Integer.parseInt(readCfg.nextLine()); System.out.println(f);
		}
		catch(Exception e){System.out.println("xD");}

		Visualiser v = new Visualiser();
		Game g = new Game();
		UserAction user = new UserAction();
		v.setup(w,h,user);

		while(true){//-------------------------------------------------------Driver-side running
                        long time = System.currentTimeMillis(); 
			time = (1000 / f) - (System.currentTimeMillis() - time); 
                        if (time > 0) 
                        { 
                                try 
                                { 
                                        Thread.sleep(time); 
                                } 
                                catch(Exception e){} 
                        } 

			v.draw(g);
			g.update(user);
		}

		
	}
}
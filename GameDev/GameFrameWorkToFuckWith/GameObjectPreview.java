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

@SuppressWarnings("serial")
public class GameObjectPreview extends JFrame{
        boolean isRunning = true; 
        int fps = 60; 
	int windowWidth = 450;
	int windowHeight = 450;
        BufferedImage backBuffer; 
        Insets insets; 
	boolean moveMade;
        int x = 0; 
	boolean up,right,down,left;
	GameCharacter preview = new GameCharacter(200,200);
        Matrix cam = new Matrix(3,3);
        
        /** 
         * This method starts the game and runs it in a loop 
         */ 
        public void run() 
        { 
                initialize(); 
		cam.set(0,0,1.0);
		cam.set(1,1,-1.0);
		cam.set(2,2,1.0);
		cam.set(0,2, windowWidth/2);
		cam.set(1,2, windowHeight/2);
                while(isRunning) 
                { 
                        long time = System.currentTimeMillis(); 
                        
                        update(); 
                        draw(); 
                        
                        //  delay for each frame  -   time it took for one frame 
                        time = (1000 / fps) - (System.currentTimeMillis() - time); 
                        
                        if (time > 0) 
                        { 
                                try 
                                { 
                                        Thread.sleep(time); 
                                } 
                                catch(Exception e){} 
                        } 
                } 
                
                setVisible(false); 
        } 
        
        /** 
         * This method will set up everything need for the game to run 
         */ 
        void initialize() 
        { 
                setTitle("Lines"); 
                setSize(windowWidth, windowHeight); 
                setResizable(false); 
                setDefaultCloseOperation(EXIT_ON_CLOSE); 
                setVisible(true); 
		setFocusable(true);
		requestFocusInWindow();
		insets = getInsets(); 
                setSize(insets.left + windowWidth + insets.right, 
                                insets.top + windowHeight + insets.bottom); 
                
                backBuffer = new BufferedImage(windowWidth, windowHeight, BufferedImage.TYPE_INT_RGB); 

	} 
	public static void main(String[] args){
                GameObjectPreview game = new GameObjectPreview(); 
                game.run(); 
                System.exit(0); 

	}
        public void update() 
        {
        } 
        public void draw() 
        {               
                Graphics g = getGraphics(); 
                
                Graphics bbg = backBuffer.getGraphics(); 
                
                bbg.setColor(Color.WHITE); 
                bbg.fillRect(0, 0, windowWidth, windowHeight); 

		//
		//
		//	DRAWING
		//	ALGORITHMS
		//
		preview.draw(bbg, cam);

		//
		//
		//
		//
                g.drawImage(backBuffer, insets.left, insets.top, this); 
        } 

}
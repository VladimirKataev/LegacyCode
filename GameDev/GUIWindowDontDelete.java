import java.awt.*; 
import java.awt.event.*;
import java.awt.image.BufferedImage; 
import javax.swing.JFrame;
import java.util.*; 

/** 
 * Main class for the game 
 */ 
@SuppressWarnings("serial")
public class Visualiser extends JFrame implements KeyListener{        
        boolean isRunning = true; 
        int fps = 60; 
	int noWidthBlocks = 9;
	int noHeightBlocks = 9;
	int blockWidth	= 50;
	int blockHeight = 50;
        int windowWidth = noWidthBlocks * blockWidth; 
        int windowHeight = noHeightBlocks * blockHeight; 

        BufferedImage backBuffer; 
        Insets insets; 
	boolean moveMade;
        int x = 0; 
	ArrayList<String> rendOrders = new ArrayList();
	boolean up,right,down,left;
        
        public static void main(String[] args) 
        { 
                LinesDriver game = new LinesDriver(); 
                game.run(); 
                System.exit(0); 
        } 
        
        /** 
         * This method starts the game and runs it in a loop 
         */ 
        public void run() 
        { 
                initialize(); 
                
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
		addKeyListener(this);                        
		insets = getInsets(); 
                setSize(insets.left + windowWidth + insets.right, 
                                insets.top + windowHeight + insets.bottom); 
                
                backBuffer = new BufferedImage(windowWidth, windowHeight, BufferedImage.TYPE_INT_RGB); 
		addKeyListener(this);        

	} 
        
        /** 
         * These methods will check for input, move things 
         * around and check for win conditions, etc 
         */ 
	public void keyTyped(KeyEvent e){};
	public void keyPressed(KeyEvent e){
		int KeyCode = e.getKeyCode();
	}
	public void keyReleased(KeyEvent e){
		int KeyCode = e.getKeyCode();
	}
        void update() 
        {
        } 
        
        /** 
         * This method will draw everything 
         */ 
        void draw() 
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


		//
		//
		//
		//
                g.drawImage(backBuffer, insets.left, insets.top, this); 
        } 
} 
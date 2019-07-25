import java.awt.*; 
import java.awt.event.*;
import java.awt.image.BufferedImage; 
import javax.swing.JFrame; 

/** 
 * Main class for the game 
 */ 
@SuppressWarnings("serial")
public class AltTut extends JFrame implements KeyListener
{        
        boolean isRunning = true; 
        int fps = 60; 
        int windowWidth = 900; 
        int windowHeight = 900; 
        
        BufferedImage backBuffer; 
        Insets insets; 
        
        int x = 0; 
	int y = 0;
	int vx,vy;
	boolean up,right,down,left;
        
        public static void main(String[] args) 
        { 
                AltTut game = new AltTut(); 
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
                setTitle("Game Tutorial"); 
                setSize(windowWidth, windowHeight); 
                setResizable(true); 
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
         * This method will check for input, move things 
         * around and check for win conditions, etc 
         */ 
	public void keyTyped(KeyEvent e){};
	public void keyPressed(KeyEvent e){
		int KeyCode = e.getKeyCode();
		if(KeyCode == 65){
			left = true;
		}
		if(KeyCode == 87){
			up = true;
		}
		if(KeyCode == 68){
			right = true;
		}
		if(KeyCode == 83){
			down = true;
		}
		System.out.print(" +"+KeyCode);

	}
	public void keyReleased(KeyEvent e){
		int KeyCode = e.getKeyCode();
		if(KeyCode == 65){
			left = false;
		}
		if(KeyCode == 87){
			up = false;
		}
		if(KeyCode == 68){
			right = false;
		}
		if(KeyCode == 83){
			down = false;
		}
		System.out.print(" -"+KeyCode);

	}

        void update() 
        {
		if(up){vy--;}
		if(down){vy++;} 
		if(right){vx++;} 
		if(left){vx--;} 
		x += vx;y+=vy;
		x++;y++;

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
                
                bbg.setColor(Color.BLACK); 
                bbg.drawOval(x+vx, vy+y, 20, 20); 
          	bbg.drawString("YYYEEEE",10,10);

                g.drawImage(backBuffer, insets.left, insets.top, this); 
        } 
} 
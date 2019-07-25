import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.*; 	
import java.awt.event.*;
import javax.swing.JFrame;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class Game extends JComponent implements KeyListener{
	int x = 0;
	int y = 0;
	int vx = 0;
	int vy = 0;
	boolean right = false;
	boolean left = false;
	boolean up = false;
	boolean down = false;
	public void keyTyped(KeyEvent e){};
	public void keyPressed(KeyEvent e){
		int KeyCode = e.getKeyCode();
		if(KeyCode == 65){
			left = true;
			vx += -1;
		}
		if(KeyCode == 87){
			up = true;
			vy += -1;
		}
		if(KeyCode == 68){
			right = true;
			vx += 1;
		}
		if(KeyCode == 83){
			down = true;
			vy += 1;
		}
		System.out.print(" +"+KeyCode);

	}
	public void keyReleased(KeyEvent e){
		int KeyCode = e.getKeyCode();
		if(KeyCode == 65){
			left = false;
			vx = 0;
		}
		if(KeyCode == 87){
			up = false;
			vy = 0;		
		}
		if(KeyCode == 68){
			right = false;
			vx = 0;
		}
		if(KeyCode == 83){
			down = false;
			vy = 0;
		}
		System.out.print(" -"+KeyCode);

	}

	private void moveBall() {
        	x = x + vx;
        	y = y + vy;
	}
	//@Override
	public void paintComponent(Graphics g) {
	        Graphics2D g2d = (Graphics2D) g;
	        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
	        RenderingHints.VALUE_ANTIALIAS_ON);
	        g2d.fillOval(x, y, 30, 30);
	}

	public static void main(String[] args) throws InterruptedException {
		JFrame frame = new JFrame("Sample Frame");
	        Game game = new Game();
	        frame.add(game);
	        frame.setSize(300, 400);
	        frame.setVisible(true);
		frame.setResizable(true);
	        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.addKeyListener(game);

        while (true) {
        	game.moveBall();
        	game.repaint();
        	Thread.sleep(1000/20);
        }
    }
}

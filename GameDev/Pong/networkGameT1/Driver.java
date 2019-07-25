package networkGameT1;

import java.awt.Color;

import javax.swing.JFrame;

import lib.*;

public class Driver {
	static final double framePause = 1.0/60.0;
	public static void main(String[] args) throws InterruptedException {
		JFrame frame = new JFrame("network test 2");
        frame.setSize(800, 600);
        RN2GamePanel gameView = new RN2GamePanel();
        frame.add(gameView);
        gameView.initialize();
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        //Can set scene properties here
        GameScene.PlayerNumber player;
        try {
        	player = args[0].equals("1")
        			?GameScene.PlayerNumber.P1 : GameScene.PlayerNumber.P2;
        } catch(IndexOutOfBoundsException ie) {
        	System.out.println("No player type specified in cmd line args. "
        			+ "Automatically using player1 setting.");
        	player = GameScene.PlayerNumber.P1;
        }
        RN2Scene theScene = new GameScene(gameView, (double)gameView.getWidth(), 
        		(double)gameView.getHeight(), player);
        theScene.backgroundColor = Color.WHITE;
        gameView.presentScene(theScene);
        
        while(true) {
        	gameView.repaint();
        	gameView.update(framePause);
            Thread.sleep((long)(framePause*1000));
        }

	}
	

}

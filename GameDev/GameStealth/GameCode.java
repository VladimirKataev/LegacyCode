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

public class GameCode{

	int stage = 0; 	// which "level" we on (includes menus and cutscenes)
	boolean menu = true;	// whether the wsad keys move menu cursor or character
	Point camera = new Point(0,0);
	// <--------------------all classes start here;
	MenuObject startButton = new MenuObject(940, 540, "Start");
	GameCharacter mc = new GameCharacter(900, 540);
	Wall tst = new Wall(90, 25, 400, 540);
	ArrayList<Wall> collideables = new ArrayList();

	public void setup(){ //<--All initialising of the variables

		startButton.inFocus = true;
		collideables.add(tst);
	/*
		startButton.x = 940;
		startButton.y = 540;

		startButton.text = "start";
		mc.x = 900;
		mc.y = 540;
	*/
	}

	MenuObject focus  = startButton;

	public void update(InputSpace presses){
		if(stage == 0){
			if(presses.select && focus == startButton){	//condition for lvl 1 reached
				stage = 1;
				menu = false;
			}
		}
		if(stage == 1){
			mc.move(presses, collideables);

		}

	}
	public void draw(Graphics canvas){
		if(stage == 0){
			startButton.draw(canvas);
		}
		if(stage == 1){
			canvas.drawString("As Far yet", 940, 530);
			mc.draw(canvas);
			tst.draw(canvas);
		}
	}
	public ArrayList<GameObject> getMap(int level) throws Exception{
		String filename = "map" + level + ".txt";
		Scanner sc = new Scanner( new File(filename));
		try{
			while(sc.hasNextLine()){
				System.out.println(sc.nextLine());
			}

		}
		catch(Exception e){
			System.out.println("OOf");
		}

	}

}

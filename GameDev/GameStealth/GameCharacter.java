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

public class GameCharacter extends DrawableObject{
	int velx, vely;
	Point nextPos;
	Line movement;
	public GameCharacter(){
		nextPos = new Point(pos);
	}
	public GameCharacter(Point a){
		pos = a;
		nextPos = new Point(pos);

	}
	public GameCharacter(double a, double b){
		pos = new Point(a,b);
		nextPos = new Point(pos);
		movement = new Line();
	}

	public void draw(Graphics canvas){
		canvas.drawRect((int)pos.x-5,(int) pos.y-5,10, 10 );
		//Debugging
		movement.draw(canvas);
	}
	public void move(InputSpace presses, ArrayList<Wall> coll){
		velx = 0;
		vely = 0;
		movement.s.x = pos.x;
		movement.s.y = pos.y;
		movement.f.x = pos.x;
		movement.f.y = pos.y;

		if(presses.up){
			vely = -2;
		}
		if(presses.down){
			vely = 2;
		}
		if(presses.left){
			velx = -2;
		}
		if(presses.right){
			velx = 2;
		}

		//process where we want to go
		movement.f.x = movement.s.x + velx;
		movement.f.y = movement.s.y + vely;

		//Process if anything blocks
		for(int i = 0; coll.size() > i; i++){
			if(movement.intersects(coll.get(i).lineRepresentation)){
				movement.f.x = movement.s.x;
				movement.f.y = movement.s.y;
				System.out.println("Collided with " + i);
			}
		}
		pos.x = movement.f.x;
		pos.y = movement.f.y;

	}

}

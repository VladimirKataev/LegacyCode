// Name: Vladimir Kataev
//
// Program file: DrawHouse.java
//
// Class Description: Draws a basic house using Vector Graphics

import apcslib.*;
import java.awt.Color;
public class DrawHouse{
    private DrawingTool pencil;
    private SketchPad paper;
    public DrawHouse(){
	paper = new SketchPad(400,400);
	pencil = new DrawingTool(paper);
    }
    public void draw(){
	//Main Rectangle
	pencil.up();
	pencil.move(-150,-150);
	pencil.down();
	pencil.setDirection(0);
	pencil.forward(300);
	pencil.turnLeft(90);
	pencil.forward(200);
	pencil.turnLeft(90);
	pencil.forward(300);
	pencil.turnLeft(90);
	pencil.forward(200);
	pencil.turnLeft(180);
	pencil.forward(200);
	
	//Triangle Roof
	pencil.setDirection(30);
	pencil.forward(174);
	pencil.turnRight(60);
	pencil.forward(174);

	//Windows
	pencil.up();
	pencil.setDirection(-135);
	pencil.forward(100);
	pencil.down();
	pencil.setColor(Color.blue);
	int x;
	pencil.setWidth(2);
	for(x = 0; x != 30; x++){
		pencil.drawCircle(x);
	}
	pencil.up();
	pencil.setDirection(180);
	pencil.move(150);
	pencil.down();
	for(x = 0; x != 30; x++){
		pencil.drawCircle(x);
	}
	
	//Door now
	
	/*
	//Old version
	pencil.up();
	pencil.home();
	pencil.turnLeft(90);
	pencil.forward(20);
	pencil.setDirection(270);
	pencil.forward(50);
	pencil.setColor(Color.red);
	pencil.down();
	pencil.forward(100);
	pencil.turnLeft(90);
	pencil.forward(40);
	pencil.turnLeft(90);
	pencil.forward(100);
	pencil.turnLeft(90);
	pencil.forward(40);
	*/

	//New filled door mechanism 	
	pencil.up();
	pencil.home();
	pencil.move(-15,-150);
	pencil.setColor(Color.blue);
	pencil.down();
	pencil.setDirection(90);
	int drawX = 40;
	int drawY = 80;
	while(drawX > 0){
		square(drawX--,drawY--);	
	}

	//Fun thing (assuming improv fill for windows/door wasn't enough)
	pencil.up();
	pencil.home();
	pencil.setColor(Color.red);
	pencil.move(-20,85);
	pencil.setWidth(2);
	pencil.down();
	pencil.drawString("NO ENTRY");

    }
    public void square(int squareX,int squareY){
    	pencil.setDirection(90);
	pencil.forward(squareY);
	pencil.turnRight(90);
	pencil.forward(squareX);
	pencil.turnRight(90);
	pencil.forward(squareY);
	pencil.turnRight(90);
	pencil.forward(squareX);
    }
}

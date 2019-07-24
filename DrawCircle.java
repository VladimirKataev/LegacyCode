// Name: Vladimir Kataev
//
// Program file: DrawCircle.java
//
// Class Description: Draws a basic house using Vector Graphics

import apcslib.*;
import java.awt.Color;
public class DrawCircle{
	private DrawingTool pencil;
	private SketchPad paper;
	private int myRadius;
	public DrawCircle(){
		paper = new SketchPad(400,400);
		pencil = new DrawingTool(paper);
	}

	public void draw(int radius){			//formal parameters
		myRadius = radius;
		pencil.drawCircle(myRadius);
		pencil.up();
		pencil.move(-75,-75);
		pencil.down();
		pencil.setColor(Color.red);
		pencil.drawCircle(myRadius);
		pencil.up();
		pencil.home();
		pencil.move(100,50);
		pencil.down();
		pencil.setColor(Color.blue);
		pencil.drawCircle(myRadius);
	}
}

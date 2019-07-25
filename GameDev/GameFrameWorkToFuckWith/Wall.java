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

public class Wall extends GameObject{
	int x2,y2,x1,y1, rX, lX, uY, lY, dX, dY;
	Matrix points = new Matrix(3,2);
	Matrix rendPoints = new Matrix(3,2);
	double length;
	public Wall(int tx1, int ty1, int tx2, int ty2){
		x1 = tx1;
		y1 = ty1;
		x2 = tx2;
		y2 = ty2;
		dX = x2 - x1;
		dY = y2 - y1;
		length = Math.hypot(dX, dY);
		System.out.println("L="+length + "DX, DY = " + dX + "," + dY);
		// \/ used for collision detection		
		rX = x2; lX = x1;
		if(x1 > x2){rX = x1; lX = x2;}
		uY = y1; lY = y2;
		if(y2 > y1){uY = y2; lY = y1;}

		points.set(2,0,1.0);
		points.set(2,1,1.0);
		points.set(0,0,x1);
		points.set(1,0,y1);
		points.set(0,1,x2);
		points.set(1,1,y2);
	} 
	public void draw(Graphics bb, Matrix camTrans){
		rendPoints = Matrix.multiply(camTrans, points);
		//System.out.println("REND");
		bb.setColor(Color.BLACK);

		bb.drawLine((int)rendPoints.get(0,0),(int) rendPoints.get(1,0),(int) rendPoints.get(0,1),(int) rendPoints.get(1,1));
		//bb.drawString("Line",(int) rendPoints.get(0,0),(int)rendPoints.get(1,0));
	}
	public boolean checkCollision(int oX, int oY, int oWidth, int oHeight){

		//Make sure is not obvs false
		if(oX + oWidth < lX || oX - oWidth > rX || oY + oHeight < lY || oY - oHeight > uY){
			return false;
		}
		if((lX == rX) && Math.abs(oX - lX) < oWidth){return true;} // vertical wall scenario
		if((lY == uY) && Math.abs(oY - lY) < oHeight){return true;} // Horizontal wall scenario

		//System.out.print("Checking wall");
		int tX = -1* dY;
		int tY = dX;
		int tPX = x1 + tX;
		int tPY = y1 - tY;
		
		int cross = ((oX - x1)*(tX)) + ((oY - y1)*(tY));
		//System.out.print(Math.abs(cross / length));
		if(Math.abs(cross / length) < oWidth){
			return true;
		} 

		return false;
	}
}
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
	int x2,y2,x1,y1;
	Matrix points = new Matrix(3,2);
	Matrix rendPoints = new Matrix(3,2);

	public Wall(int tx1, int ty1, int tx2, int ty2){
		x1 = tx1;
		y1 = ty1;
		x2 = tx2;
		y2 = ty2;
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
		bb.drawString("Line",(int) rendPoints.get(0,0),(int)rendPoints.get(1,0));
	}
	
}
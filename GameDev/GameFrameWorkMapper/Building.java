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

public class Building extends GameObject{
	int x1;
	int y1;
	int height;
	int width;
	int[][] arrPoints= {{0,0,0,0},{0,0,0,0}};
	Matrix points;
	Matrix rendPoints;
	public Building(int tx1, int ty1, int twidth, int theight){
		x1 = tx1;
		y1 = ty1;

		height = theight;
		width = twidth;

		points = new Matrix(3,4);
		points.set(2,0,1.0);
		points.set(2,1,1.0);
		points.set(2,2,1.0);
		points.set(2,3,1.0);

		points.set(0,0,x1);
		points.set(1,0,y1);

		points.set(0,1,x1 + width);
		points.set(1,1,y1);

		points.set(0,2,x1 + width);
		points.set(1,2,y1 + height);

		points.set(0,3,x1);
		points.set(1,3,y1 + height);
		System.out.print("[");
		/*
		for(int r = 0; r < points.getRow(); r++){
			for(int c = 0; c < points.getCol(); c++){
				System.out.print(points.get(r,c) + "\t");
			}
			System.out.print("\n");
		}
		System.out.print("]");
		*/
	} 
	public void draw(Graphics bb, Matrix camTrans){
		rendPoints = Matrix.multiply(camTrans, points);
		/*
		rendPoints.set(0,2, rendPoints.get(0,1));
		rendPoints.set(0,3, rendPoints.get(0,0));
		*/
		rendPoints.set(1,2, rendPoints.get(1,1) - height);
		rendPoints.set(1,3, rendPoints.get(1,0) - height);
	
		for(int i = 0; i < 4; i++){
			arrPoints[0][i] = (int) rendPoints.get(0,i);
			arrPoints[1][i] = (int) rendPoints.get(1,i);
		}
		bb.drawPolygon(arrPoints[0], arrPoints[1], arrPoints[0].length);
		/*
		bb.drawString("0",(int)rendPoints.get(0,0),(int)rendPoints.get(1,0));
		bb.drawString("1",(int)rendPoints.get(0,1),(int)rendPoints.get(1,1));
		bb.drawString("2",(int)rendPoints.get(0,2),(int)rendPoints.get(1,2));
		bb.drawString("3",(int)rendPoints.get(0,3),(int)rendPoints.get(1,3));
		*/
	}
	public boolean checkCollision(int oX, int oY, int oWidth, int oHeight){
		//System.out.print("CD "+x1+","+y1+" vs "+oX+","+oY+"\n");
		return (oX > x1-oWidth &&
			oX < x1+width + oWidth &&
			oY > y1 - oHeight &&
			oY < y1 + height + oHeight);
	}


}
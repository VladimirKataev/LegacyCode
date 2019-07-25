//import
//package com.vladimir.GameFramework;
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

public class GameCharacter extends GameObject{
	int x;
	int y;
	int[] xpoints = new int[4];
	int[] ypoints = new int[4];
	Matrix points = new Matrix(3,4);	//goes Y,X, because fml
	Matrix rendPoints = new Matrix(3,4);

	public GameCharacter(int a, int b){
		x=a;
		y=b;
		points.set(2,0,1.0);
		points.set(2,1,1.0);
		points.set(2,2,1.0);
		points.set(2,3,1.0);

		points.set(0,0,a - 25.0);
		points.set(1,0,b + 25.0);

		points.set(0,1,a + 25.0);
		points.set(1,1,b + 25.0);

		points.set(0,2,a + 25.0);
		points.set(1,2,b - 25.0);

		points.set(0,3,a - 25.0);
		points.set(1,3,b - 25.0);

	}
	public void move(UserAction input, Matrix cam){
		if(input.getUp()){
			points.add(1,0,1);
			points.add(1,1,1);
			points.add(1,2,1);
			points.add(1,3,1);

		}
		if(input.getDown()){
			points.add(1,0,-1);
			points.add(1,1,-1);
			points.add(1,2,-1);
			points.add(1,3,-1);

		}
		if(input.getLeft()){
			points.add(0,0,-1);
			points.add(0,1,-1);
			points.add(0,2,-1);
			points.add(0,3,-1);

		}
		if(input.getRight()){
			points.add(0,0,1);
			points.add(0,1,1);
			points.add(0,2,1);
			points.add(0,3,1);

		}

	}
	public void draw(Graphics bb, Matrix camTrans){
		rendPoints = Matrix.multiply(camTrans, points);
		for(int i = 0; i < 4; i++){
			xpoints[i] = (int)rendPoints.get(0,i);
			ypoints[i] = (int)rendPoints.get(1,i);
		}
		bb.drawPolygon(xpoints, ypoints, 4);
		//bb.drawLine((int)rendPoints.get(0,0), (int) rendPoints.get(1,0),(int) rendPoints.get(0,3),(int) rendPoints.get(1,3) );
	}
}
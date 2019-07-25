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

public class Game{
	ArrayList<GameObject> gameObjects = new ArrayList<GameObject>();
	Matrix cameraMatrix;
	int cX, cY,gX,gY;
	GameCharacter mainCharacter = new GameCharacter(50,50);
	Matrix clickMatrix;
	public Game(){
		clickMatrix = new Matrix(3,1);
		clickMatrix.set(2,0,1);
		cameraMatrix = new Matrix(3,3);
		cameraMatrix.makeCamera();
		cameraMatrix.set(1,1,-0.1);
		cameraMatrix.set(0,0,0.1);
		cameraMatrix.set(0,2,960);
		cameraMatrix.set(1,2,540);

	}
	public void update(UserAction user){
		/*
		mainCharacter.move(user, cameraMatrix);
		if(user.getLeftCam()){cameraMatrix.add(0,2,1.0);}
		if(user.getRightCam()){cameraMatrix.add(0,2,-1.0);}
		if(user.getUpCam()){cameraMatrix.add(1,2,1.0);}
		if(user.getDownCam()){cameraMatrix.add(1,2,-1.0);}
		mainCharacter.setMovable(true);
		for(int i = 0; i < gameObjects.size(); i++){
			if(gameObjects.get(i).checkCollision(mainCharacter.getX(),mainCharacter.getY(),25,25)){
				System.out.print("COll");
				mainCharacter.setMovable(false);
				mainCharacter.unMove(user, cameraMatrix);				
			}
		}
		*/

		cX = user.getLastClickX();
		cY = user.getLastClickY();
		gX = cX * 10 - 9600;
		gY = cY * (-10) - 5400;
		clickMatrix.set(0,0,cX);
		clickMatrix.set(1,0,cY);
		

	}
	public ArrayList<GameObject> getGameObjects(){
		return gameObjects;
	}
	public Matrix getCamMatrix(){return cameraMatrix;}
	public String getVisText(){return (	"onScreenX:"+ cX + 
						" onScreenY:"+cY + 
						" ingame X:" + gX+
						" ingame Y"  + gY);};
}
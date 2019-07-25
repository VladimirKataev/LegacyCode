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
	GameCharacter mainCharacter = new GameCharacter(50,50);
	public Game(){
		gameObjects.add(mainCharacter);


//-\/\/\/\/\/\/\/IN MASSIVE FUCKING DESPERATE NEED OF AUTOMATION\/\/\/\/\/\/\/\/
	
		gameObjects.add(new Building(-150,75,150,300));
		gameObjects.add(new Wall( 200 , 100, 400 ,100 ));
		gameObjects.add(new Wall( 400, 100, 400, 300));
		gameObjects.add(new Wall( 400, 300, 500, 300));
		gameObjects.add(new Wall( 500, 300, 600, 200));
		gameObjects.add(new Wall( 600, 200, 600, 400));
		gameObjects.add(new Wall( 600, 400, 400, 400));
		gameObjects.add(new Wall( 400, 400, 400, 500));
		gameObjects.add(new Wall( 400, 500, 500, 600));
		gameObjects.add(new Wall( 500, 600, 300, 600));
		gameObjects.add(new Wall( 300, 600, 300, 400));
		gameObjects.add(new Wall( 300, 400, 200, 400));
		gameObjects.add(new Wall( 200, 400, 100, 500));
		gameObjects.add(new Wall( 100, 500, 100, 300));
		gameObjects.add(new Wall( 100, 300, 300, 300));
		gameObjects.add(new Wall( 300, 300, 300, 200));
		gameObjects.add(new Wall( 300, 200, 200, 100));





		cameraMatrix = new Matrix(3,3);
		cameraMatrix.makeCamera();
		cameraMatrix.set(1,1,-1);
		cameraMatrix.set(0,0,1);
		cameraMatrix.set(0,2,960);
		cameraMatrix.set(1,2,540);
	}
	public void update(UserAction user){
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

	}
	public ArrayList<GameObject> getGameObjects(){
		return gameObjects;
	}
	public Matrix getCamMatrix(){return cameraMatrix;}
}
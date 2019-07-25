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
		gameObjects.add(new Wall(-50,50, 500,500));
		cameraMatrix = new Matrix(3,3);
		cameraMatrix.makeCamera();
		cameraMatrix.set(1,1,-1.0);
	}
	public void update(UserAction user){
		mainCharacter.move(user, cameraMatrix);
		if(user.getLeftCam()){cameraMatrix.add(0,2,1.0);}
		if(user.getRightCam()){cameraMatrix.add(0,2,-1.0);}
		if(user.getUpCam()){cameraMatrix.add(1,2,1.0);}
		if(user.getDownCam()){cameraMatrix.add(1,2,-1.0);}

	}
	public ArrayList<GameObject> getGameObjects(){
		return gameObjects;
	}
	public Matrix getCamMatrix(){return cameraMatrix;}
}
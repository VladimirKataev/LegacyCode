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

public class GameCharacter{
	int x;
	int y;
	public GameCharacter(int a, int b){
		x=a;
		y=b;
	}
	public void move(UserAction input){
		if(input.getUp()){y++;}
		if(input.getDown()){y--;}
		if(input.getLeft()){x--;}
		if(input.getRight()){x++;}

	}
	public void draw(Graphics bb){

		bb.drawOval(x,y,50,50);
	}
}
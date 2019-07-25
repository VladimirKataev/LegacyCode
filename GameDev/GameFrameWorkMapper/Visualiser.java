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

public class Visualiser extends JFrame implements KeyListener, MouseListener{
	int windowWidth = 1920;
	int windowHeight = 1080;
	BufferedImage backBuffer;
	Insets insets;
	UserAction usr;
	public void setup(int wi,int he, UserAction user){
		windowWidth = wi;
		windowHeight = he;
		usr = user;
                setTitle("GAME"); 
                setSize(wi, he); 
                setResizable(true); 
                setDefaultCloseOperation(EXIT_ON_CLOSE); 
		setUndecorated(true);
                setVisible(true); 
		setFocusable(true);
		requestFocusInWindow();
		addMouseListener(this); 
		addKeyListener(this);                       
		insets = getInsets(); 
                setSize(insets.left + windowWidth + insets.right, insets.top + windowHeight + insets.bottom); 
                backBuffer = new BufferedImage(windowWidth, windowHeight, BufferedImage.TYPE_INT_RGB); 
                setVisible(true); 


	}
	public void draw(Game g){//------FIX DIS
                Graphics gr = getGraphics();                 
                Graphics bbg = backBuffer.getGraphics(); 
                bbg.setColor(Color.WHITE); 
                bbg.fillRect(0, 0, windowWidth, windowHeight); 
		bbg.setColor(Color.BLACK);

		bbg.drawString( g.getVisText(),20,20);


		for(int i = 0; i < g.getGameObjects().size(); i++){
			g.getGameObjects().get(i).draw(bbg, g.getCamMatrix());
		}


		gr.drawImage(backBuffer, insets.left, insets.top, this);
	}
	public void mouseClicked(MouseEvent e){
		usr.chg(e.getX(), e.getY(),true);
	}
	public void mousePressed(MouseEvent e){}
	public void mouseReleased(MouseEvent e){
		usr.chg(e.getX(), e.getY(),false);
	}
	public void mouseExited(MouseEvent e){}
	public void mouseEntered(MouseEvent e){}
	public void keyTyped(KeyEvent e){}
	public void keyPressed(KeyEvent e){
		usr.chg(e.getKeyCode(), true);
	}
	public void keyReleased(KeyEvent e){
		usr.chg(e.getKeyCode(), false);
	}


}
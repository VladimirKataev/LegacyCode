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

public class Game{
	ArrayList<GameCharacter> gameCharacters = new ArrayList<GameCharacter>();
	GameCharacter mainCharacter = new GameCharacter(50,50);
	public Game(){
		gameCharacters.add(mainCharacter);
	}
	public void update(UserAction user){
		mainCharacter.move(user);
	}
	public ArrayList<GameCharacter> getGameCharacters(){
		return gameCharacters;
	}
}
//import
import java.net.ServerSocket;
import java.net.Socket;
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

public class Client{
	int state;
	static int fps = 5;
	
	static String ip = "10.56.243.89";
	static String backFeed = "";
	static String toRtn = "";
	static int port = 9001;
	static int parsePos = 0;
	static boolean inQueue = false;
	static String name = "";
	static int xp = 0;
	static String request = "vled";
	static int id = 0;
	static Scanner srvrResp;
	static String srvrAns;
	static Socket srvrConn;
	static PrintWriter toSrvr;
	static String req = new String();
	static Scanner terminalText = new Scanner(System.in);
	static int[][] board = new int[7][6];
	public static void main(String[] arg){
		//setup here
		Visualiser v = new Visualiser();
		id = Integer.parseInt(send("n."+v.setup()+"\n"));

		while(true){
                        long time = System.currentTimeMillis(); 
			time = (1000 / fps) - (System.currentTimeMillis() - time); 
                        if (time > 0) 
                        { 
                                try 
                                { 
                                        Thread.sleep(time); 
                                } 
                                catch(Exception e){} 
                        } 

			v.draw(send(id+"."+v.getReq()));
		}
		
                
	}
	public static String send(String req){
		try{
		srvrConn = new Socket(ip,port);
		srvrResp = new Scanner(srvrConn.getInputStream());
		toSrvr = new PrintWriter(srvrConn.getOutputStream());
		toSrvr.print(req + ";"+"\n");
		toSrvr.flush();
		srvrAns = srvrResp.next();
		srvrConn.close();
		return srvrAns;
		}catch(Exception e){return("Shit be whack");}		
	}

        
	
}
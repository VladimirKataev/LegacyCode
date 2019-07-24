//import
import java.io.*;
import java.awt.*; 
import java.awt.event.*;
import java.awt.image.BufferedImage; 
import javax.swing.JFrame; 
import java.util.*;

public class Visualiser extends JFrame implements MouseListener{
	int mx, my;
	int windowWidth = 800;
	int windowHeight = 400;
	int msgOrd;
	String lastClick = "";
	int b = 0;

	boolean sent = true;
	boolean Q = false;
	boolean ig = false;
	Insets insets;
	int[][] board = new int[7][6];
	BufferedImage backBuffer;
	ArrayList<Integer> mvList = new ArrayList<Integer>();
	public String setup(){
                setTitle("Connect4"); 
                setSize(windowWidth, windowHeight); 
                setResizable(true); 
                setDefaultCloseOperation(EXIT_ON_CLOSE); 
                setVisible(true); 
		setFocusable(true);
		requestFocusInWindow();
		addMouseListener(this);                        
		insets = getInsets(); 
                setSize(insets.left + windowWidth + insets.right, insets.top + windowHeight + insets.bottom); 
                backBuffer = new BufferedImage(windowWidth, windowHeight, BufferedImage.TYPE_INT_RGB); 
		addMouseListener(this);        
		return Long.toHexString(Double.doubleToLongBits(Math.random()));

	}
	public void mouseClicked(MouseEvent e){}
	public void mousePressed(MouseEvent e){}
	public void mouseReleased(MouseEvent e){
		mx = e.getX();
		my = e.getY();
		//System.out.print("["+mx+ ":"+my+"]");
		//REQUEST CHANGE SHIT GOES HERE
		//System.out.print(Q);
		lastClick = "Update";
		if(mx > 50 && mx < 175 && my > 270 && my < 300){ 
			lastClick = "Qon";
			Q = true;
			sent = false;			
		}
		if(mx > 50 && mx < 175 && my > 330 && my < 360){ 
			lastClick = "Qoff";
			Q = false;
			sent = false;			
		}
		if(mx > 320 && mx < 728 && my > 75 && my < 330){ // CLICKED ON THE BOARD
			sent = false;
			if(mx < 380){ lastClick = "Move.0";}
			else if(mx < 435){ lastClick = "Move.1";}
			else if(mx < 495){ lastClick = "Move.2";}
			else if(mx < 555){ lastClick = "Move.3";}
			else if(mx < 613){ lastClick = "Move.4";}
			else if(mx < 671){ lastClick = "Move.5";}
			else if(mx < 725){ lastClick = "Move.6";}


		}


	}
	public void mouseEntered(MouseEvent e){}
	public void mouseExited(MouseEvent e){}


	public void draw(String servData){
		String arg1 = "";
		String arg2 = "";
		String arg3 = "";
		String arg4 = "";
		String arg5 = "";
		String toRend4 = "";
		String arg6 = "";
		//PARSE SERVER RESPONSE, DRAW ACCORDINGLY
                Graphics g = getGraphics();                 
                Graphics bbg = backBuffer.getGraphics(); 
                bbg.setColor(Color.WHITE); 
                bbg.fillRect(0, 0, windowWidth, windowHeight); 
		bbg.setColor(Color.BLACK);
		if(servData.equals("BadReq")){return;}
		int parsePos = 0;
		//----------DRAWING/PARSING GOES HERE----------
		while(servData.charAt(parsePos) != '.' && servData.charAt(parsePos) != ';'){arg1 += servData.charAt(parsePos++);}parsePos++;
		while(servData.charAt(parsePos) != '.' && servData.charAt(parsePos) != ';'){arg2 += servData.charAt(parsePos++);}parsePos++;
		while(servData.charAt(parsePos) != '.' && servData.charAt(parsePos) != ';'){arg3 += servData.charAt(parsePos++);}parsePos++;
		while(servData.charAt(parsePos) != '.' && servData.charAt(parsePos) != ';' && parsePos < servData.length() -1){arg4 += servData.charAt(parsePos++);}parsePos++;
		

		while(servData.charAt(parsePos) != '.' && servData.charAt(parsePos) != ';' && parsePos < servData.length() -2){
			arg5 += servData.charAt(parsePos++);
		} 
		if(parsePos < servData.length() && servData.charAt(parsePos) == '.'){
			parsePos++;
			while(parsePos < servData.length()){
				arg6 += servData.charAt(parsePos++);
			}
		}
		if(servData.charAt(parsePos-1) == '>'){b = parsePos - 1;}
		String arg7 = new String();//GAMEBOARD DATA COMPRESSED
		//System.out.print(servData.charAt(b));
		if(arg4.equals("true")){ toRend4  = "Queueing";}
		else if(arg5.equals("true") || arg5.equals("tru")){ 
			// INGAME, Panic, render
			board = new int[7][6];
			for(int i = b+1; i < servData.length(); i++){
				arg7 += servData.charAt(i);
				//System.out.print(servData.charAt(i));
			}
			//System.out.print("\t"+arg7);
			for(int i = 0; i < arg7.length(); i++){
				String t = "";
				t += arg7.charAt(i);
				int e = Integer.parseInt(t);
				int p = 0;
				while(board[e][p] != 0){p++;}
				board[e][p] =1 + i % 2;
			}
			toRend4  = "InGame";





			for(int x = 0; x < 7; x++){
				for(int y = 0; y < 6; y++){
					if(board[x][y] == 0){bbg.setColor(Color.WHITE); }
					if(board[x][y] == 1){bbg.setColor(Color.BLUE); }
					if(board[x][y] == 2){bbg.setColor(Color.RED); }
					bbg.fillOval(337 + 56*x, 268 - 42*y, 30,30);
					bbg.setColor(Color.BLACK);
					bbg.drawOval(337 + 56*x, 268 - 42*y, 30,30);
				}
			}

			bbg.drawRect(320, 50, 406, 252);
			for(int x = 0; x < 7; x++){
				bbg.drawRect(320 + 58*x, 50, 58, 252);
			}
			for(int y = 0; y < 6; y++){
				bbg.drawRect(320, 50 + 42*y, 406, 42);
			}
			// clear movesList, parse further, render on board, 
			
			ig = true;

		}
		else{toRend4 = "Passive"; }

		bbg.drawString("Server hosting courtesy of Mark Masulis.                               Vlad-CSGO-Skins.co.uk.ru", 50,395);
		bbg.drawRect(50,50,100,25); bbg.drawString(arg1, 55, 65); bbg.drawString("ID:", 70, 40);
		bbg.drawRect(175,50,125,25);bbg.drawString(arg2, 180, 65); bbg.drawString("Name:", 185, 40);
		bbg.drawRect(50,100, 100,25);bbg.drawString(arg3, 55, 115); bbg.drawString("XP:", 70, 90);
		bbg.drawRect(175, 100, 100, 25); bbg.drawString(toRend4, 180, 115); bbg.drawString("GameState:", 185, 90);
		bbg.drawRect(50, 250, 125, 30); bbg.drawString("Enter MatchMaking", 55, 275);
		bbg.drawRect(50, 300, 125, 30); bbg.drawString("Exit MM Queue", 55, 325);

		g.drawImage(backBuffer, insets.left, insets.top, this);
	}
	public String getReq(){
		if (sent == true){return "Update";}
		sent = true;	
		//System.out.println(lastClick);
		return (lastClick);
	}
}
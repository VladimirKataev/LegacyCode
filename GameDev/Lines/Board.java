//import
import java.awt.*;
public class Board{
	boolean playerAMove;
	int[][] board;
	int boardHorizontalBlocks;
	int boardVerticalBlocks;
	public static Board(){
		int boardHorizontalBlocks = 8;
		int boardVerticalBlocks = 8;
		boolean playerAMove = false;
		board = new int[boardHorizontalBlocks][boardVerticalBlocks];		
	}
	private boolean playerBMoveAllowed(int x, int y){
		if(board[x][y] == 0){
			return true
		}
		return false;
	}
	public boolean playerBMove(int color, int x, int y){
		if(playerBMoveAllowed(x,y)){
			board[x][y] = color;
			playerAMove = true;
			return true;
		}
		return false;
	}
	private boolean playerAMoveAllowed(int x1, int y1, int x2, int y2){
		int[][] pathBoard = new int[boardHorizontalBlocks][boardVerticalBlocks];
		boolean found = false;
		boolean blocked = false;
		int gen = 1;
		pathBoard[x1][y1] = 1
		while (!found && !blocked){//----------------------------------------------Pathfind till found/ded
			for(int xp = 0; xp < boardHorizontalBlocks; xp++){
				for(int yp = 0; yp < boardVerticalBlocks; yp++){
					blocked = true;
					if(pathBoard[xp][yp] == gen){//-------------------If the cell is of gen, check surround for better
						

					}					
				}
			}
		}
		if(found){ return true;}
		else{return false;}
	}
}
import java.util.ArrayList;

public class GameBoard{
	public ClientRecord p1 = new ClientRecord(-1,"[]");
	public ClientRecord p2 = new ClientRecord(-1,"[]");
	public boolean gameOver;
	public boolean p1Won;
	public boolean p1Turn;		//    x  y
	public int[][] moves = new int[7][6];	
	public ArrayList <String> movesList = new ArrayList<String>();	
	public ClientRecord getP1(){return p1;}
	public ClientRecord getP2(){return p2;}
	public boolean p1Turn(){return p1Turn;}
	public void reRank(){
		//FIX DIS \/\/\/\/\/\/\/\/ SHIET
		if(p1.getScore() == p2.getScore()){		//Basic win/loss counter
			if(p1Won()){
				p1.changeScore(1); 
				p2.changeScore(-1);
			}
			else{
				p2.changeScore(1);
				p1.changeScore(-1);
			}	
		}
		p1.incrementPlays();
		p2.incrementPlays();
		p1.setGame(null);
		p2.setGame(null);
		p1.setQueue(false);
		p2.setQueue(false);
	}
	public GameBoard(ClientRecord a,ClientRecord b){
		p1 = a;
		p2 = b;
		gameOver = false;
		p1Won = false;
		p1Turn = true;
	}

	public boolean moveAllowed(ClientRecord p,String m){
		if(p != p1 && p != p2){return false;}
		int a;
		if(((p == p1) && !p1Turn) || ((p == p2) && p1Turn)){return false;}
		try{
			a = Integer.parseInt(m);
			if(moves[a][5] == 0){return true;}
			return false;
		}
		catch(Exception e){return false;}
	}
	public void move(ClientRecord p,String m){
		int a = 0;
		if (p == p1 && moveAllowed(p,m)){
			for(int i = a; i < 6; i++){
				if(moves[Integer.parseInt(m)][i] != 0){a++;}
			}		
			moves[Integer.parseInt(m)][a] =1;
			movesList.add(m);

		}
		if (p == p2 && moveAllowed(p,m)){
			for(int i = a; i < 6; i++){
				if(moves[Integer.parseInt(m)][i] != 0){a++;}
			}		

			moves[Integer.parseInt(m)][a] =2;
			movesList.add(m);
		}

		p1Turn = !p1Turn;		
	}
	public boolean isOver(){
		for(int x = 0; x < 7; x++){
			for(int y = 0; y < 6; y++){
				if(x < 4 && moves[x][y] == 1&& moves[x+1][y] == 1&& moves[x+2][y] == 1&& moves[x+3][y] == 1){p1Won = true;gameOver = true;return true;}
				if(y < 3 && moves[x][y] == 1&& moves[x][y+1] == 1&& moves[x][y+2] == 1&& moves[x][y+3] == 1){p1Won = true;gameOver = true;return true;}
				if(y < 3 && x < 4 && moves[x][y] == 1&& moves[x+1][y+1] == 1&& moves[x+2][y+2] == 1&& moves[x+3][y+3] == 1){p1Won = true;gameOver = true;return true;}
				if(y > 3 && x < 4 && moves[x][y] == 1&& moves[x+1][y-1] == 1&& moves[x+2][y-2] == 1&& moves[x+3][y-3] == 1){p1Won = true;gameOver = true;return true;}

				if(x < 4 && moves[x][y] == 2&& moves[x+1][y] == 2&& moves[x+2][y] == 2&& moves[x+3][y] == 2){p1Won = false;gameOver = true;return true;}
				if(y < 3 && moves[x][y] == 2&& moves[x][y+1] == 2&& moves[x][y+2] == 2&& moves[x][y+3] == 2){p1Won = false;gameOver = true;return true;}
				if(y < 3 && x < 4 && moves[x][y] == 2&& moves[x+1][y+1] == 2&& moves[x+2][y+2] == 2&& moves[x+3][y+3] == 2){p1Won = false;gameOver = true;return true;}
				if(y > 3 && x < 4 && moves[x][y] == 2&& moves[x+1][y-1] == 2&& moves[x+2][y-2] == 2&& moves[x+3][y-3] == 2){p1Won = false;gameOver = true;return true;}

			}
			System.out.print("\n");
		}
		return false;
	}
	public boolean p1Won(){
		//TEST THIS MOTHERFUCKING PIECE OF ASS SHIT
		return (p1Won && gameOver);
	}
	public String toString(){
		String toRtn = new String();
		toRtn += p1.getId() + ":" + p2.getId() + ">";
		for(int i = 0; i < movesList.size(); i++){ toRtn += movesList.get(i);}
		return toRtn;
	}

}
//import
public class ClientRecord{
	int id;
	int score = 0;
	boolean inQueue;
	int gamesPlayed = 0;
	int queueDesp = 5;
	String name = "";
	GameBoard inGame = null;
	ClientRecord(int ID, String Name){
		id = ID;
		score = 0;
		name = Name;
		inQueue = false;
	}
	ClientRecord(String toSerialise){
		int n = 0;
		String a = "";
		while(toSerialise.charAt(n) != '.'){
			a += toSerialise.charAt(n++);
		}
		id = Integer.parseInt(a);
		n++;
		while(toSerialise.charAt(n) != '.'){
			name += toSerialise.charAt(n++);
		}
		n++;
		String sc = "";
		while(n < toSerialise.length()){
			sc += toSerialise.charAt(n++);
		}
		score = Integer.parseInt(sc);		
	}

	public int getScore(){return score;}
	public void setScore(int ds){score += ds;}
	public String getName(){return name;}
	public void setName(String n){name = n;}
	public void setQueue(boolean s){inQueue = s;}
	public boolean getQueue(){return inQueue;}
	public void setGame(GameBoard n){inGame = n;}
	public GameBoard getGame(){return inGame;}
	public int getGamesPlayed(){return gamesPlayed;}
	public void incrementPlays(){gamesPlayed++;}
	public void changeScore(int ds){score += ds;}
	public int getId(){return id;}
	public void setQueueDesp(int s){queueDesp = s;}
	
	public boolean goodMatch(ClientRecord o){
		if(o.getId() == id){return false;}
		//FIX DIS \/\/\/\/\/\/\/\/ SHIET
		if(o.getScore() == score){
			return true;
		}
		return false;

	}

	public String toString(){
		String toRtn = "";
		toRtn += id;
		toRtn += name;
		toRtn += ".";
		toRtn += score;
		toRtn += ".";
		toRtn += inQueue;
		toRtn += "." + (inGame != null);
		return toRtn;
	}
}
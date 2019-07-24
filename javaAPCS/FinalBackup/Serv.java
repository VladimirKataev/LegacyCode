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

public class Serv{
	static ArrayList<ClientRecord> dbc = new ArrayList<ClientRecord>();
	static ArrayList<ClientRecord> dbq = new ArrayList<ClientRecord>();
	static ArrayList<GameBoard> dbg = new ArrayList<GameBoard>();
	public static void main(String[] args){
		int port = 9001;
		String recText;
		String sndText;
		PrintWriter out;
		Scanner in;
		//refillClientList();
		try{
			ServerSocket server = new ServerSocket(port);
			Socket chatSocket;
			while(true){
				chatSocket = server.accept();
				in = null;
				in = new Scanner(chatSocket.getInputStream());

				out = new PrintWriter(chatSocket.getOutputStream());
				recText = in.next();
				out.println(processInput(recText));
				out.flush();
				chatSocket.close();
			}
		}
		catch(Exception e){System.out.println(e);}

	}
	public static String processInput(String text){
		System.out.print(text);
		String sndText = text;
		String toRtn = "";
		String arg1 = "";
		int id = 0;
		String req = "";
		String data = "";
		int parsePos = 0;
		ClientRecord contact;

		while(sndText.charAt(parsePos) != '.' && sndText.charAt(parsePos) != '.' && parsePos < sndText.length()-1)
			{arg1 += sndText.charAt(parsePos++);}
		if(arg1.equals("n")){
			while(sndText.charAt(parsePos) != ';' && parsePos < sndText.length()-1)
				{req += sndText.charAt(parsePos++);}
			dbc.add(new ClientRecord(dbc.size(),req));
			return (""+(dbc.size()-1));
		}

		try
			{id = Integer.parseInt(arg1);}
		catch(Exception e)
			{return ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");}
		if(id >= dbc.size()){return "H4><0RZ";}


		contact = dbc.get(id);
		parsePos++;
		while(sndText.charAt(parsePos) != ';' &&sndText.charAt(parsePos) != '.' && parsePos < sndText.length()-1)
			{req += sndText.charAt(parsePos++);}
		switch(req){
			case "Qon":
				dbq.add(contact);
				contact.setQueue(true);
				return contact.toString();
			case "Qoff":
				contact.setQueue(false);
				dbq.remove(contact);
				return contact.toString();
			case "Update":
				if(contact.getGame() != null)
					{return contact.toString() + "." + contact.getGame().toString();}
				if(contact.getQueue() == true)
					{//<<--MATCHMAKING ALGORITHM-->>
						for(int i = 0; i < dbq.size(); i++){
							//System.out.println("Checking\t"+contact.toString()+"\tvs\t"+dbq.get(i).toString());
							if(contact.goodMatch(dbq.get(i))){	//Match found
								String msgMatch = contact.toString();
								System.out.println(msgMatch);
								dbg.add(new GameBoard(contact,dbq.get(i)));
								contact.setQueue(false);
								contact.setGame(dbg.get(dbg.size()-1));
								dbq.get(i).setQueueDesp(0);
								dbq.get(i).setQueue(false);
								dbq.get(i).setGame(dbg.get(dbg.size()-1));
								dbq.remove(i);
								dbq.remove(contact);
								return(msgMatch);
							}
							//else{System.out.print("No Match");}
						}
						contact.addQueueDesp(0.05f);						
					}
				
				return contact.toString();
			case "Move":
				//System.out.println(sndText.charAt(++parsePos));
				parsePos++;
				while(sndText.charAt(parsePos) != ';' && parsePos < sndText.length()){
					data += sndText.charAt(parsePos++);
				}
				System.out.println(data); //<<Data is legit and works
				if(contact.getGame() == null) {return contact.toString();}
				if(contact.getGame().moveAllowed(contact,data)){
					contact.getGame().move(contact,data);
					if(contact.getGame().isOver()){
						//rerank if so
						//return gg
						GameBoard g = contact.getGame();
						contact.getGame().reRank();
						dbg.remove(g);
						return contact.toString();

					}
					return contact.toString() + "." + contact.getGame().toString();
				}
				else{ return "BadReq";}
			default:
				return "BadReq";				
		}				
	}
}


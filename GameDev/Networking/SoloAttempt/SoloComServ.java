import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.io.DataInputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.IOException;
public class SoloComServ{
//Made By Vladimir, This is the effective Server (only servicing 1 client)
	public static void main(String[] args){	
		// if you need more variables, put here
		int port = 6677;
		int winner;
		int clientX;
		int clientY;
		int serverX;
		int serverY;
		int[][] grid = new int[9][9]; // 0 for untouch, 1 for client, 2 for server
		boolean done = false;
		boolean connected = false;
		boolean ourTurnToSend = false;
		boolean inputIsGood = false;
		String clientTextSent = new String();
		String emptyString = new String();
		String toSend = new String();
		Scanner in;
		Scanner terminalText = new Scanner(System.in);
		PrintWriter out;
		try{
			ServerSocket server = new ServerSocket(port);
			Socket chatSocket;
			chatSocket = server.accept();
			in = new Scanner(chatSocket.getInputStream());
			out = new PrintWriter(chatSocket.getOutputStream());
			System.out.println(" Try gone through, Connection established, not our turn to send");
			System.out.println("Use format \"X,Y\" for sending coordinates of move");
			//---------Game Logic goes here-------
			while(done == false){
				if(ourTurnToSend == true){
					while(inputIsGood == false){
						System.out.println("Enter Your Move:");
						toSend = terminalText.nextLine();
						if((
						(toSend.charAt(0) >='1' && toSend.charAt(0) <= '9') 	&&
						toSend.charAt(1) == ','					&&
						(toSend.charAt(2) >='1' && toSend.charAt(2) <= '9')	&&
						grid[(((int)toSend.charAt(2)-49))][(((int)toSend.charAt(0)-49))] == 0) ||
						toSend == "GG")
						{
							inputIsGood = true;							
						}
						else{
							System.out.println("You didn't format your move correctly, or that space is taken");
						}	
						if(toSend == "GG"){inputIsGood = true; done = true;}				
					
					}
					out.println(toSend);
					out.flush();
					serverX = (int)toSend.charAt(0);
					serverY = (int)toSend.charAt(2);
					serverX -= 49;
					serverY -= 49;
					grid[serverY][serverX] = 2;
					ourTurnToSend = false;
					printBoard(grid);
					winner = checkWinner(grid);
					if(winner == 2){
						System.out.println("You Win");
						out.println("GG"); out.flush();

					}
					if(winner == 1){
						System.out.println("You Lose");
						out.println("GG"); out.flush();

					}
					inputIsGood = false;
				}
				if(ourTurnToSend == false){
					System.out.println("Awaiting their move:");
					while(in.hasNext() == false){
						System.out.print("");
					}
					clientTextSent = in.next();
					System.out.println("They sent:"+clientTextSent);
					clientX = (int)clientTextSent.charAt(0);
					clientY = (int)clientTextSent.charAt(2);
					clientX -= 49;
					clientY -= 49;
					grid[clientY][clientX] = 1;
					printBoard(grid);
					winner = checkWinner(grid);
					if(winner == 2){
						System.out.println("You Win");
					}
					if(winner == 1){
						System.out.println("You Lose");
					}

					ourTurnToSend = true;
					
				}
				clientTextSent = "";
				toSend = "";
			}


		}
		catch(Exception e){
			System.out.println("Shit be whack Yo");
			e.printStackTrace();
		}
	}
	public static void printBoard(int[][] matrix){
		System.out.println("Board looks like:");
		System.out.println("#.12345678");
		System.out.print("-------");
		for(int Y = 1; Y < 10; Y++){
			System.out.print("\n"+Y+":");
			for(int X = 1; X < 10; X++){
				System.out.print(matrix[Y-1][X-1]);
			}
		}
		System.out.print("\n");
	}
	public static int checkWinner(int[][] matrix){
		for(int X = 0; X < 9; X++){
			for(int Y = 0; Y < 9; Y++){
				if(matrix[X][Y] == 1){
					try{
						if(matrix[X+1][Y] == 1 && matrix[X+2][Y] == 1 && matrix[X+3][Y] == 1){return 1;}
					}catch(Exception e){}
					try{
						if(matrix[X+1][Y+1] == 1 && matrix[X+2][Y+2] == 1 && matrix[X+3][Y+3] == 1){return 1;}
					}catch(Exception e){}
					try{
						if(matrix[X][Y+1] == 1 && matrix[X][Y+2] == 1 && matrix[X][Y+3] == 1){return 1;}
					}catch(Exception e){}

				}
				if(matrix[X][Y] == 2){
					try{
						if(matrix[X+1][Y] == 2 && matrix[X+2][Y] == 2 && matrix[X+3][Y] == 2){return 2;}
					}catch(Exception e){}
					try{
						if(matrix[X+1][Y+1] == 2 && matrix[X+2][Y+2] == 2 && matrix[X+3][Y+3] == 2){return 2;}
					}catch(Exception e){}
					try{
						if(matrix[X][Y+1] == 2 && matrix[X][Y+2] == 2 && matrix[X][Y+3] == 2){return 2;}
					}catch(Exception e){}

				}

			}
		}
		return 0;
	}

}
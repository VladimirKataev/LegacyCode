package networkGameT1;

import java.net.*;
import java.util.ArrayList;
import java.util.concurrent.CopyOnWriteArrayList;
import java.io.*;

public class ChatClient implements Runnable {  
   private Socket socket = null;
   private Thread thread = null;
   private BufferedReader console = null;
   private DataOutputStream streamOut = null;
   private ChatClientThread clientThread = null;
   private ArrayList<MessageListener> messageListeners = 
		   new ArrayList<MessageListener>();
   private CopyOnWriteArrayList<String> messagesToBeSent = 
		   new CopyOnWriteArrayList<String>();
   
   public ChatClient(String serverIP, int serverPort)
   {  System.out.println("Establishing connection. Please wait ...");
      try
      {  socket = new Socket(serverIP, serverPort);
         System.out.println("Connected: " + socket);
         start();
      }
      catch(UnknownHostException uhe)
      {  System.out.println("Host unknown: " + uhe.getMessage()); }
      catch(IOException ioe)
      {  System.out.println("Unexpected exception: " + ioe.getMessage()); }
   }
   
   public void addMessageListener(MessageListener ml) {
	   this.messageListeners.add(ml);
   }
   
   public void run()
   {  while (thread != null)
      {  try
         {  
    	  	String nextMsg = null;
    	  	while(nextMsg == null) {
    	  		nextMsg = messagesToBeSent.isEmpty() ? null :
    	  			messagesToBeSent.remove(0);
    	  	}
//    	    streamOut.writeUTF(console.readLine());
    	  	streamOut.writeUTF(nextMsg);
            streamOut.flush();
         }
         catch(IOException ioe)
         {  System.out.println("Sending error: " + ioe.getMessage());
            stop();
         }
      }
   }
   
   public void sendMessage(String msg) {
	   this.messagesToBeSent.add(msg);
   }
   
   
   public void handle(String msg)
   {  
//	  if (msg.equals(".bye"))
//      {  System.out.println("Good bye. Press RETURN to exit ...");
//         stop();
//      }
//      else
//         System.out.println(msg);
//	   System.out.println(msg);
	   for(MessageListener ml: messageListeners) {
		   ml.messageReceived(msg);
	   }
   }
   public void start() throws IOException
   {  console   = new BufferedReader(new InputStreamReader(System.in));
      streamOut = new DataOutputStream(socket.getOutputStream());
      if (thread == null)
      {  clientThread = new ChatClientThread(this, socket);
         thread = new Thread(this);                   
         thread.start();
      }
   }
   public void stop()
   {  if (thread != null)
      {  thread.stop();  
         thread = null;
      }
      try
      {  if (console   != null)  console.close();
         if (streamOut != null)  streamOut.close();
         if (socket    != null)  socket.close();
      }
      catch(IOException ioe)
      {  System.out.println("Error closing ..."); }
      clientThread.close();  
      clientThread.stop();
   }
   
   public static class ChatClientThread extends Thread
   {  private Socket           socket   = null;
      private ChatClient       client   = null;
      private DataInputStream  streamIn = null;

      public ChatClientThread(ChatClient _client, Socket _socket)
      {  client   = _client;
         socket   = _socket;
         open();  
         start();
      }
      public void open()
      {  try
         {  streamIn  = new DataInputStream(socket.getInputStream());
         }
         catch(IOException ioe)
         {  System.out.println("Error getting input stream: " + ioe);
            client.stop();
         }
      }
      public void close()
      {  try
         {  if (streamIn != null) streamIn.close();
         }
         catch(IOException ioe)
         {  System.out.println("Error closing input stream: " + ioe);
         }
      }
      public void run()
      {  while (true)
         {  try
            {  client.handle(streamIn.readUTF());
            }
            catch(IOException ioe)
            {  System.out.println("Listening error: " + ioe.getMessage());
               client.stop();
            }
         }
      }
      
   }
   
   public static interface MessageListener {
 	  public void messageReceived(String msg);
   }

   
//   public static void main(String args[])
//   {  ChatClient client = null;
//      if (args.length != 2)
//         System.out.println("Usage: java ChatClient host port");
//      else
//         client = new ChatClient(args[0], Integer.parseInt(args[1]));
//   }
}
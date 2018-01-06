import java.io.*;
import java.net.*;

class Client
{
	 
	 
	 
	 public  static  void main(String args[]){
	 	
	 	
	 	if(args.length==1)
	 	{
	 		
	 		try{
	 			Socket socket=new Socket("127.0.0.1",8888);
	 			
	 			// 1st send message to server
	 			
	 			PrintWriter printWriter=new PrintWriter(socket.getOutputStream(),true);
	 		    printWriter.println(args[0]);
	 			
	 			//2nd read and display response from server 
	 			
	 			BufferedReader buffereReader=new BufferedReader(new InputStreamReader(socket.getInputStream()));
	 			System.out.println("The following reply was received from server:"+buffereReader.readLine());
	 		
	 			
	 		}catch(Exception e)
	 		{
	 			System.out.println("exception in listenSocket ::"+e);
	 			System.exit(1);
	 		}
	 	}
	 	else{
	 		System.err.println("Usage:Clint <server> <name>");
	 	}
	 }
}
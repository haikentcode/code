import java.io.*;
import java.net.*;


public class Server
{
	
	
	public  static void main(String args[])
	{
		
		try{
			
			ServerSocket serverSocket=new ServerSocket(8888);
            Socket socket=serverSocket.accept();
            
            // 1st read and dispaly incoming msg
            
            BufferedReader buffereReader=new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String message=buffereReader.readLine();
            
            System.out.println("The following message was received from clinet"+message);
            
            //Respond to client echoing back the incoming client message
            
            PrintWriter printWriter=new PrintWriter(socket.getOutputStream(),true);
            printWriter.println("Server echoing back the followint message '"+message+"' from client");
		
            
	}catch(IOException e)
	{System.out.println("exception->"+e);
	System.exit(-1);
	}
  }
}
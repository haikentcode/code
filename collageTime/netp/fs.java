import java.io.*;
import java.net.*;

public class fs 
{
  
  public static void main(String arg[])
  {


  	
    try{

    	ServerSocket ss=new ServerSocket(9001);
  	    Socket s=ss.accept();
        BufferedReader in;
        PrintWriter out;
    
    	in=new BufferedReader(new InputStreamReader(s.getInputStream()));
        out=new PrintWriter(s.getOutputStream(),true);


        while(true){
        String message=in.readLine();

        System.out.println("clint message: "+message);

       // out.println("hello client");
     }
        


      }catch(IOException e)
   {

   }
   


  }


}

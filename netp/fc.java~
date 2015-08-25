import java.io.*;
import java.net.*;

public class fc
{

	public static void main(String arg[])
	{
     
     BufferedReader in;
     PrintWriter out;

     try{

     	Socket s=new Socket("10.42.0.1",9001);
       
        in=new BufferedReader(new InputStreamReader(s.getInputStream()));
        out=new PrintWriter(s.getOutputStream(),true);

        out.println("clint is online");

        System.out.println("sever reply : "+in.readLine());




     }catch(IOException e)
     {


     }

    
	}
}





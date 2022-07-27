import java.io.*;
import java.net.*;

public class runts {

   ServerSocket ss=new ServerSocket(9006);

   runts() throws Exception
   {
    
    while(true)
    {
      Socket s=ss.accept();

      thrd obj=new thrd(s);

    }

   }

   public static void main(String arg[]) throws Exception
   {

    new runts();

   }


   class thrd extends Thread
   {

   	BufferedReader in;
   	PrintWriter out;
   	Socket s;


      thrd(Socket s) throws Exception 
      {
         this.s=s;
         in=new BufferedReader(new InputStreamReader(s.getInputStream()));
         out=new PrintWriter(s.getOutputStream());
         start();

     }


     public void run(){
                   
                     
                    while(true)
                    {   
                    	try{
                           String str="";

                    	System.out.println(str=in.readLine());

                    	if(str==null) break;

                    }catch(IOException e)
                    {

                    }
                    }


                   }

   }


}
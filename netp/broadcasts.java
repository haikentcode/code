
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashSet;


public class broadcasts 
{

	ServerSocket ss=new ServerSocket(9004);
	private static HashSet<PrintWriter> hs=new HashSet<PrintWriter>();
   
   broadcasts() throws Exception
    {
     
     while(true){
     Socket s=ss.accept();
     ServerThread obj=new ServerThread(s);
      }

    }

    public static void main(String arg[]) throws Exception
    {

    	new broadcasts();
    }

    class ServerThread extends Thread{
                
             private BufferedReader in;
             private PrintWriter out;
             private Socket s;
            




             ServerThread(Socket s) throws Exception
             {
               
               this.s=s;
             
               start();

             }

            public   void run()
             {
               

               
               try
               {


               in=new BufferedReader(new InputStreamReader(s.getInputStream()));
               out=new PrintWriter(s.getOutputStream(),true);
               hs.add(out);


                  while(true){
                  	
                  String message="";
                  message=in.readLine();
                  if(message==null) break;
                  System.out.println("->"+message);
                  
                  for(PrintWriter ut:hs)
                  	  ut.println(message);


                   }
                }catch(IOException e)
               {

               }


            }

    }




}
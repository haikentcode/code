
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashSet;


public class evotings 
{

	ServerSocket ss=new ServerSocket(9124);
	private static HashSet<PrintWriter> hs=new HashSet<PrintWriter>();
   
    evotings() throws Exception
     {
     
     while(true){
     Socket s=ss.accept();
     ServerThread obj=new ServerThread(s);
      }

    }

    public static void main(String arg[]) throws Exception
    {

    	new evotings();
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

      boolean valid_voting(String f,String s)
            {

                 return true;
            }
                

            public   void run()
             {
               

               
               try
               {


               in=new BufferedReader(new InputStreamReader(s.getInputStream()));
               out=new PrintWriter(s.getOutputStream(),true);
               boolean voting_status=true;
                
                String msg="Candidate NAME for PR are->ARPAN SUNIL SUKDEEP PIUSH PRASHANT.";

               out.println(msg);

             
               while(voting_status)
               {
                 
                 out.println("Enter FIrst PR name");
                 String fpr=in.readLine();
                 System.out.println("votefor->"+fpr);

                 out.println("Enter Second PR name");
                 String spr=in.readLine();
                 System.out.println("votefor->"+spr);
                  
                 if(this.valid_voting(fpr,spr)) 
                 {
                 out.println("YOU HAVE DONE"+"\n"+"THANK YOU !"); 
                 voting_status=false;
                 }
                 else
                 {
                   out.println("You have done mistake please try again");
                 }               

              }

              
                }catch(IOException e){

                  System.out.println("Erorre find");

               }

               finally 
               {
                try{
                s.close();
              }catch(IOException ef){}

               }


            }

    }




}
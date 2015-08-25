import java.io.*;
import java.net.*;

public class appletnets  
{
 

 ServerSocket ss=new ServerSocket(9005); 
  
 appletnets() throws Exception
 {
   while(true){

   Socket s=ss.accept();
   th obj=new th(s);

    }

 }

 public static void main(String arg[]) throws Exception
  {

  new appletnets();
 
  }


  class th extends Thread
  {

    Socket s;
    BufferedReader in;
    PrintWriter out;

     th(Socket s) throws Exception
     {

       this.s=s;
       in=new BufferedReader(new InputStreamReader(s.getInputStream()));
       out=new PrintWriter(s.getOutputStream());
       start();


     }

    public void run()
     {

       try{
              String str[]=in.readLine().split("#");

              int x=Integer.parseInt(str[0]);
              int y=Integer.parseInt(str[1]);

             System.out.println("--> "+x+" "+y);

             out.println(String.valueOf(x+y));
       }
       catch(IOException e)
       {

       }

     }


  }






}
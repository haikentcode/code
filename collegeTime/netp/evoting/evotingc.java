
import java.io.*;
import java.net.*;
import java.util.Scanner;


public class evotingc 
{

  
 BufferedReader in;
 PrintWriter out;
 Scanner cn;
 Socket s;
 String IP=new String("10.42.0.1");
 int PORT=9124;

 evotingc() throws Exception
  {

  	s=new Socket(IP,PORT);
  	in=new BufferedReader(new InputStreamReader(s.getInputStream()));
  	out=new PrintWriter(s.getOutputStream(),true);

  }
   
  private void  haikuread() throws Exception
  {
   
    System.out.println(this.in.readLine());
  } 

  public static void main(String arg[]) throws Exception
  {
   
   evotingc obj=new evotingc();
   obj.haikuread();
   obj.haikuread();

  	while(true)
  	{
     
     Scanner sc=new Scanner(System.in);
     obj.out.println(sc.nextLine());
     obj.haikuread();
     

  	}
   
   

  }




}
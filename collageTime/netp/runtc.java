import java.io.*;
import java.net.*;
import java.util.*;
import jline.*;


public class runtc 
{
 
  BufferedReader in;
  PrintWriter out;
  Socket s;

  runtc() throws Exception
  {

  	s=new Socket("10.42.0.1",9006);
  	in=new BufferedReader(new InputStreamReader(s.getInputStream()));
  	out=new PrintWriter(s.getOutputStream(),true);

  }


  public static void main(String arg[]) throws Exception
  {
   
   runtc obj=new runtc();
  	while(true)
  	{
     
     Scanner sc=new Scanner(System.in);
     obj.out.println((char)System.in.read());

  	}
   
   

  }





}
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class s3{

              ServerSocket ss=new ServerSocket(9002);

              s3() throws Exception
              {

                  while(true)
                  {

                  	Socket s=ss.accept();
	          	    s3t ob=new s3t(s);
                  }

              }


	          public static void main(String arg[]) throws Exception
	          {
                
                new s3();
	          }


	         public class s3t extends Thread
	         {
              
               BufferedReader in;
               PrintWriter out;
               Socket s;
	         	
	         	s3t(Socket s) throws Exception {

                       in=new BufferedReader(new InputStreamReader(s.getInputStream()));
                       out=new PrintWriter(s.getOutputStream(),true);
                       this.s=s;
                       start();

	         	     }


	         	 public void run() 
	         	 {
                   
                   while(true) 
                   {


                   try{
                  int a=0;

                  String str=in.readLine();

                  for(String ns:str.split("#"))
                  {
                  	a+=Integer.parseInt(ns);
                  }

                  out.println(String.valueOf(a));

                 }catch(IOException e)
                 {

                 }


	         	 }    



	         }

	     }






}
import java.io.*;
import java.net.*;

public class s2 {

    
         public static void main(String arg[])
         {
               

           try
               {
                 
               BufferedReader in;
               PrintWriter out;
               ServerSocket ss=new ServerSocket(9002);
               Socket s=ss.accept();

                 in=new BufferedReader(new InputStreamReader(s.getInputStream()));
                 out=new PrintWriter(s.getOutputStream(),true);

                 

                  while(true){

                  int a=0;

                  String str=in.readLine();

                  for(String ns:str.split("#"))
                  {
                  	a+=Integer.parseInt(ns);
                  }

                  out.println(String.valueOf(a));

                 }
                 

               }

               catch(IOException e)
               {

               }



             


         }


}
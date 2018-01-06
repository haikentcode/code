import java.io.*;
import java.net.*;
import java.util.Scanner;

public class broadcastc
{
  
  
 


  public static void main(String arg[]) throws Exception
  {
  	
   if(arg.length==1){

   BufferedReader in;
   PrintWriter out;
  
    
   Socket s=new Socket("10.42.0.1",9004);
   in=new BufferedReader(new InputStreamReader(s.getInputStream()));
   out=new PrintWriter(s.getOutputStream(),true);
   

     
       
       	             if(arg[0].equals("haiku"))
       	             {

                     System.out.println("hi haikent! "+"\n");
                     while(true){
                                   Scanner sc=new Scanner(System.in);
                                   out.println(sc.nextLine());
		                     }
       	             }
       	             else
       	             {
       	             	System.out.println("hi user! "+"\n");
       	             	while(true){
       	             	              String str=in.readLine();
                                      System.out.println(str); 
                        
                                }
       	             }
       	             
                      

                  
    

     }
    

   }	

  }



import java.io.*;
import java.net.*;
import java.util.Scanner;
public class c2 {


	public static void main(String arg[])
	{

        
       
       

       try
       {

       	BufferedReader in;
        PrintWriter out; 
        Socket s=new Socket("10.42.0.1",9002);

       
        in=new BufferedReader(new InputStreamReader(s.getInputStream()));
        out=new PrintWriter(s.getOutputStream(),true);


        while(true){
        
        Scanner sc=new Scanner(System.in);
        String str=""; 
        out.println(str=sc.nextLine());

        System.out.println(str+"="+in.readLine());

        }


         
       }catch(IOException e)
       {


       }




       






	}
}
	

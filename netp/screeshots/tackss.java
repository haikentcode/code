import java.io.BufferedReader;
import java.io.InputStreamReader;
public class tackss{


public static void main(String arg[]) throws Exception
{

  tackss png=new tackss();
  
 int i=10;
 while(i--!=0){
  String image=i+"ss.jpg";
  String CMD="import -window root "+image;
  String output=png.exeC(CMD);
  
  Thread.sleep(3000);

  System.out.println(output);
}

}


private String exeC(String cmd)
{

StringBuffer output=new StringBuffer();

Process p;
try
{

	p=Runtime.getRuntime().exec(cmd);
	//p.waitFor();
	//BufferedReader reader=new BufferedReader(new InputStreamReader(p.getInputStream()));

	//String line="";

	//while((line=reader.readLine())!=null)
		// output.append(line+"\n");

 


}catch(Exception e)
{
	e.printStackTrace();
}


  return output.toString();

}


}
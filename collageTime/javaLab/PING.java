import java.io.BufferedReader;
import java.io.InputStreamReader;
public class PING{


public static void main(String arg[])
{

  PING png=new PING();
  String domain="10.10.11.1";
  String CMD="ping -c 3 "+domain;
  String output=png.exeC(CMD);
  
  System.out.println(output);

}


private String exeC(String cmd)
{

StringBuffer output=new StringBuffer();

Process p;
try
{

	p=Runtime.getRuntime().exec(cmd);
	p.waitFor();
	BufferedReader reader=new BufferedReader(new InputStreamReader(p.getInputStream()));

	String line="";

	while((line=reader.readLine())!=null)
		 output.append(line+"\n");

 


}catch(Exception e)
{
	e.printStackTrace();
}


  return output.toString();

}


}
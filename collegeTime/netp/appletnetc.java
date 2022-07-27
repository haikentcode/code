//Adapter class 
import java.awt.event.*;
import java.awt.*;
import java.applet.*;
import java.io.*;
import java.net.*;




public class appletnetc extends Applet  
{



mc obj=new mc(this);

public void init() 
{

 addMouseMotionListener(obj);
	
}




int x=100,y=100;

public void paint(Graphics g)
{

  

g.drawString("ramu",x,y);

 BufferedReader in;
 PrintWriter out;
 Socket s;
 try{
   
   s=new Socket("10.42.0.1",9005);
   in=new BufferedReader(new InputStreamReader(s.getInputStream()));
   out=new PrintWriter(s.getOutputStream(),true);
   }catch(IOException e){

   	System.out.println("problem");
   }

}

}


class mc extends MouseAdapter
{
	appletnetc k;



mc(appletnetc k) 
{
  this.k=k;

   

}

public void mouseMoved(MouseEvent e)  
{
   k.x=e.getX();
   k.y=e.getY();
   k.repaint();
 

}

}
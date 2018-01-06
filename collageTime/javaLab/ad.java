//Adapter class 
import java.awt.event.*;
import java.awt.*;
import java.applet.*;


public class ad extends Applet 
{


mc obj=new mc(this);
ma obj2=new ma(this);
public void init()
{

	addMouseMotionListener(obj);
        addKeyListener(obj2);
	
}




int x=100,y=100;

String msg="mouse";
public void paint(Graphics g)
{

g.drawString(msg,x,y);
}

}

class ma extends KeyAdapter
{

ad h;

ma(ad h)
{
this.h=h;
}


public void keyPressed(KeyEvent e)
{
   h.msg="DOWN";
   h.repaint();
}


public void KeyTyped(KeyEvent e)
{
  
   h.msg="UP";
   h.repaint();

}



}

class mc extends MouseAdapter
{

ad k;

mc(ad k)
{

this.k=k;

}

public void mouseMoved(MouseEvent e)
{
   k.x=e.getX();
   k.y=e.getY();
   k.showStatus(e.getX()+" ,"+ e.getY());
}


}

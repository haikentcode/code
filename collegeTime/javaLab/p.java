import java.applet.*;
import java.awt.event.*;
import java.awt.*;


public class p extends Applet implements KeyListener
{


String msg="";


public void init()
{

	addKeyListener(this);
	
	requestFocus();
}


public void keyPressed(KeyEvent e)
{
 msg="ma";
repaint();
}

public void keyReleased(KeyEvent e)
{
  msg+=" tuje";
	repaint();
}

public void keyTyped(KeyEvent e)
{

	msg+=" salam";
repaint();
	
}


public void paint(Graphics g){

showStatus(msg);

}

}
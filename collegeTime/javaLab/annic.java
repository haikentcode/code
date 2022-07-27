// Anonymous inner class demo.
import java.applet.*;
import java.awt.event.*;
/*
<applet code="annic" width=200 height=100>
</applet>
*/
public class annic extends Applet 
{
	
public void init() {

addMouseListener(  
	              new MouseAdapter() 
	                {
                          public void mousePressed(MouseEvent me) 
                          {
                                  showStatus("Mouse Pressed");
                          }
                   }
                );
   

                   }


}
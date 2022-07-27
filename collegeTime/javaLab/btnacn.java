//using anonymous inner class
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import static net.mindview.util.disp.*;

public class btnacn extends JFrame{

      private JButton 
      b1=new JButton("Login"),
      b2=new JButton("Signup");

      JTextField txt=new JTextField(10);


      private ActionListener bl=new ActionListener(){


      	public void actionPerformed(ActionEvent e)
      	{

      		String name=((JButton)e.getSource()).getText();

      	    txt.setText(name);
      	}

      };


      	public btnacn()
      	{
   
          b1.addActionListener(bl);
          b2.addActionListener(bl);
          setLayout(new FlowLayout());
          add(b1);
          add(b2);
          add(txt);        

      	}



  public static void main(String arg[])
  {

  	run(new btnacn(),200,100);/
  }
      




      }





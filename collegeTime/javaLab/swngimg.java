import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class swngimg
{

   JFrame jf;
   JLabel jl;
   ImageIcon ic;
	swngimg()
	{

      jf=new JFrame("Gudan");
      ic=new ImageIcon("ag.jpg");
      jl=new JLabel("love You !",ic,JLabel.CENTER);
       makeGUI();
    }


    void makeGUI()
    {

     jf.setSize(400,400);
     jf.setLayout(new FlowLayout());
     jf.add(jl);
     jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
     jf.setVisible(true);
     
    }



	public static void main(String[] arg)
	{
		SwingUtilities.invokeLater(new Runnable(){


			public void run()
			{
				new swngimg();
			}
		});
	}
}
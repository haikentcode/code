import java.awt.*;
import java.awt.event.*;

import javax.swing.*;


class swngevnt{

   JLabel jl;

   swngevnt()
   {


   	JFrame jf=new JFrame("LOve you AdIti");
   	jf.setSize(400,300);
   	jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    jf.setLayout(new FlowLayout());


   	JButton jba=new JButton("GUDAN");
   	JButton jbb=new JButton("AdIti");

    


   jba.addActionListener(new ActionListener(){

    public void actionPerformed(ActionEvent e)
    {

    jl.setText("GUDAN LOVE YOU");
    }

   });

   jbb.addActionListener(new ActionListener(){

    public void actionPerformed(ActionEvent e)
    {

    jl.setText("ADITI LOVE YOU");

    }

   });


   jl=new JLabel("MSG FOR BABY");

   	jf.add(jba);
   	jf.add(jbb);
   	jf.add(jl);

  	jf.setVisible(true);

   }


  public static void main(String[] arg)
  {

  	 SwingUtilities.invokeLater(new Runnable(){


  	 	public void run(){
         
         new swngevnt();

  	 	}
  	 });
  }

}
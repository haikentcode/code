//javalabqusn12103024
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;



class from{

   JFrame jf;
   JLabel jl;
   JButton done;
   JButton clear;
   JTextField name;
   JTextField email;
   JCheckBox jcb;
   JRadioButton rb1;
   JRadioButton rb2;
   String result="";


   from()
   {


   jf=new JFrame("Student form");
   	jf.setSize(250,500);
   	jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    jf.setLayout(new FlowLayout());
    jl=new JLabel("result show here");
    name=new JTextField(20);
    email=new JTextField(20);

    rb1=new JRadioButton("male");
    rb2=new JRadioButton("femail");

    ButtonGroup bg=new ButtonGroup();
    bg.add(rb1);
    bg.add(rb2);


    done=new JButton("DONE");
    clear=new JButton("Clear");



   clear.addActionListener(new ActionListener(){

    public void actionPerformed(ActionEvent e)
    {
     
       name.setText("name");
       email.setText("email");

     
    }

   });


   done.addActionListener(new ActionListener(){

    public void actionPerformed(ActionEvent e)
    {

      result="name="+name.getText();
      result+="  "+"email"+email.getText();
      result+=" gnder=male";
      result+=" language=Hindi,Englis";


      jl.setText(result);

    }

   });
  
    
    name.setText("Name");jf.add(name);

   
    email.setText("email");jf.add(email);

        
     jcb=new JCheckBox("Hindi"); jf.add(jcb);
     jcb=new JCheckBox("Englis"); jf.add(jcb);
     jcb=new JCheckBox("Punjabi"); jf.add(jcb);

     jf.add(rb1);
     jf.add(rb2);
     
   	jf.add(done);
   	jf.add(clear);
   	jf.add(jl);

  	jf.setVisible(true);

   }


  public static void main(String[] arg)
  {

  	 SwingUtilities.invokeLater(new Runnable(){


  	 	public void run(){
         
         new from();

  	 	}
  	 });
  }

}
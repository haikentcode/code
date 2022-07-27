import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class hiosjform implements ItemListener
{
	 
	 JFrame jf;
	 JButton jb;
	 JLabel jl;
	 JTextField jtf;
	 JCheckBox jcb;
	 JRadioButton jrb;
	 JTextArea jta;
	 ImageIcon img;
	 JPanel jp;

	hiosjform()
	{
     jf=new JFrame("hios form");

     jp=new JPanel();
     jp.setLayout(new GridLayout(5,5));
     jtf=new JTextField("Roll no",15);
     jp.add(jtf);
     jtf=new JTextField("Name",15);
     jp.add(jtf);
     jtf=new JTextField("Email id",15);
     jp.add(jtf);
     jtf=new JTextField("Branch",15);
     jp.add(jtf);
     jf.add(jp);

     jp=new JPanel();
     jp.setLayout(new GridLayout(6,10));
     jl=new JLabel("Language");
     jp.add(jl);
     jcb=new JCheckBox("Hindi");jcb.addItemListener(this);
     jp.add(jcb);
     jcb=new JCheckBox("English");jcb.addItemListener(this);
     jp.add(jcb);
     jcb=new JCheckBox("Urdu");jcb.addItemListener(this);
     jp.add(jcb);
     jcb=new JCheckBox("Punjabi");jcb.addItemListener(this);
     jp.add(jcb);
     jf.add(jp);


     jp=new JPanel();
     jp.setLayout(new GridLayout(6,10));
     jl=new JLabel("Gender");
     jp.add(jl);
     ButtonGroup bg=new ButtonGroup();
     jrb=new JRadioButton("male");   jp.add(jrb); bg.add(jrb);
     jrb=new JRadioButton("female"); jp.add(jrb); bg.add(jrb);
     jf.add(jp);
     
    

     jp=new JPanel();
     jp.setLayout(new GridLayout(6,10));
     jl=new JLabel("Category");
     jp.add(jl);
     JComboBox<String> jcb=new JComboBox<String>();
     jcb.addItem("SC");
     jcb.addItem("ST");
     jcb.addItem("OBC");
     jcb.addItem("Other");
     jp.add(jcb);
     jf.add(jp);
     

     jp=new JPanel();
     jp.setLayout(new GridLayout(10,5));
     jl=new JLabel("Address");
     jp.add(jl);
     jta=new JTextArea("hello havaaaf fdffdf",5,40);
     jp.add(jta);
     jf.add(jp);


    
     jb=new JButton("SUBMIT");
     jf.add(jb);
     jb=new JButton("CLEAR");
     jf.add(jb);  
    
    
    

    makeGUI();
	}

    
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

   
	public void itemStateChanged(ItemEvent ie)
	{

     JCheckBox cb=(JCheckBox)ie.getItem();

     if(cb.isSelected())
     {


     }
     else
     {

     }



	}




	void makeGUI()
	{
     
      jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      jf.setSize(800,650);
      jf.setLayout(new FlowLayout());
      jf.setVisible(true);

	}

  
  public static void main(String[] arg)
  {

  	 SwingUtilities.invokeLater(new Runnable(){


  	 	public void run(){
         
         new hiosjform();

  	 	}
  	 });
  }




}

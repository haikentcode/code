import java.swing.*;
import java.awt.*;
import java.awt.event.*;
import net.mindview.util.disp.*;
import net.mindview.util.*;


public class textf extends JFrame{




	private JButton
	b=new JButton("ADD DATA"),
	c=new JButton("CANCEL");


   private JTextArea t=new JTextArea(20,40);
   private Map<string,string> m=new Map<string,string>();

   public textf()
   {
   m.putAll(Counteries.capitals());

    b.addActionListener(new addActionListener(){
  
     public void actionPerformed(ActionListener e)
     {
     	for(Map.Entry me:m.entrySet())
     		t.append(me.getKey()+": "+me.getValue()+"\n");
     }


    });


    c.addActionListener(new addActionListener(){

    public void actionPerformed(ActionListener e)
     {
     	t.setText("");
     }
     
     setLayout(new FlowLayout());
     add(new JScrollPane(t));
     add(b);
     add(c);



    });

   }


   public static void main(String arg[])
   {
    
   	run(new TextArea(),475,425);
   }


}




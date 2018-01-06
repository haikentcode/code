import javax.swing.*;

import java.awt.*;

import static net.mindview.util.disp.*;


public class btn extends JFrame {


	private JButton 
	b1=new JButton("ANGEL"),
	b2=new JButton("HAIKENT");


    public btn()
    {

    	setLayout(new FlowLayout());
    	add(b1);
    	add(b2);

    }


    public static void main(String arg[])
    {

    	run(new btn(),200,100);
    }


}
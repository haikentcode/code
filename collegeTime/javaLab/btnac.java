import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import static net.mindview.util.disp.*;

public class btnac extends JFrame{
private JButton
b1=new JButton("send"),
b2=new JButton("resend");
private JTextField txt=new JTextField(10);


class bl implements ActionListener{


	public void actionPerformed(ActionEvent e){

		String name=((JButton)e.getSource()).getText();

		txt.setText(name);
	}
}


private bl b=new bl();

public btnac()
{

b1.addActionListener(b);
b2.addActionListener(b);
setLayout(new FlowLayout());	
add(b1);
add(b2);
add(txt);


}

public static void main(String arg[])
{
	run(new btnac(),200,150);
}




}
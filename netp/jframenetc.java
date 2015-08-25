import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;
import static net.mindview.util.disp.*;

public class jframenetc extends JFrame{
private JButton
b1=new JButton("send"),
b2=new JButton("resend");
private JTextField txt=new JTextField(10);


class bl implements ActionListener{


	public void actionPerformed(ActionEvent e){

		String name=((JButton)e.getSource()).getText();

		//txt.setText(name);
		send(txt.getText());
	}
}


public void send(String str)
{

 BufferedReader in;
 PrintWriter out;
 Socket s;
 try{
   
   s=new Socket("10.42.0.1",9005);
   in=new BufferedReader(new InputStreamReader(s.getInputStream()));
   out=new PrintWriter(s.getOutputStream(),true);

    out.println(str);
   

   }catch(IOException e){

   	System.out.println("problem");
   }


  
}

private bl b=new bl();

public jframenetc()
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
	run(new jframenetc(),200,150);
}




}
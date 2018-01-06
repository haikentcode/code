import javax.swing.*;
import java.util.concurrent.*;


public class jfex
{

	public static void main(String arg[]) throws Exception
	{


		JFrame frame=new JFrame("Hello Gunjan");

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300,300);
		frame.setVisible(true);

		 final JLabel label=new JLabel("hello Gunjan love you");
		frame.add(label);

        TimeUnit.SECONDS.sleep(1);

        SwingUtilities.invokeLater(new Runnable(){

           public void run()
           {

           	 label.setText("Hai Ram");
           	 
           }

        });


        label.setText("apne dil ka pta de janu mai ya na");


	}
}
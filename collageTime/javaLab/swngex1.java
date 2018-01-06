import javax.swing.*;

class swngex1{

  swngex1()
  {

    JFrame jf=new JFrame("LOVE YOU ADITI");

    jf.setSize(400,400);
    jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    JLabel jl=new JLabel("LOve you Mera swt sa baby .. Muhaa");

     jf.add(jl);
    jf.setVisible(true);

  }


  public static void  main(String[] arg)
  {

  	SwingUtilities.invokeLater(new Runnable(){

       public void run()
       {

       	new swngex1();

       }

  	});
  }


}
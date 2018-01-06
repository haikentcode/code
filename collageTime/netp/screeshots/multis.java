    import java.awt.*;
    import java.awt.image.*;
    import java.io.*;
    import java.util.*;
    import javax.imageio.*;
    import java.net.*;

class Server {

    Dimension dim;
    Rectangle captureSize;
    BufferedImage bufferedImage;


    public Server() {
                   
                   try{
                         
                        Robot robot = new Robot();
                         dim=new Dimension(Toolkit.getDefaultToolkit().getScreenSize());
                         width=(int)dim.getWidth();
                         height=(int)dim.getHeight(); 
                        captureSize = new Rectangle(dim);
                        Socket soc = new Socket("10.42.0.1", );
                        OutputStream out = soc.getOutputStream();


      for (int i = 0; i < NbrToSend; i++) {
                 
                 bufferedImage = robot.createScreenCapture(captureSize);
                 System.out.println("Captured image!");

                 ByteArrayOutputStream byteArrayO = new ByteArrayOutputStream();
                 ImageIO.write(bufferedImage,"jpg",byteArrayO);
                 byte [] byteArray = byteArrayO.toByteArray();
                System.out.println("sent: " + str + " nbrBytes=" + strB.length);
                out.write(byteArray);
                 System.out.println("Sent image! nbrBytes=" + byteArray.length);

           //out.flush();
    } // end for(i)
    }catch(Exception x) {
                  x.printStackTrace();
    }
  }

} 


  public multis()
  {


  }
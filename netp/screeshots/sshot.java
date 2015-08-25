//screenshot using java

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.File;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;


public class sshot extends JFrame {

JFrame frame;
BufferedImage bi;
Graphics g;
JPanel panel;
ImageIcon  icon;
JLabel bg;

 sshot(Image image,int w,int h)
 {
   
   
   frame=new JFrame();
   frame.setVisible(true);
   frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   frame.setSize(600,600);
   bi=new BufferedImage(w,h,BufferedImage.TYPE_INT_RGB);
   g=bi.createGraphics();

    g.drawImage(image,0,0,w,h,null);
    icon=new ImageIcon(bi);
    bg=new JLabel(icon);
    bg.setLocation(0,0);
    frame.add(bg);
   
   
 }

 public void showImage(Image image,int w,int h)
 {
    
    g.drawImage(image,0,0,w,h,null);
    icon=new ImageIcon(bi);
    bg.setIcon(icon);
    bg.setLocation(0,0);
    frame.repaint();
    
   
    
 }

 static int a=0;

 public void writeimage(Image image,int w,int h)
 {
  g.drawImage(image,0,0,w,h,null);
  writeImage(bi,"aditi"+a+".png","PNG");
  a++;
 }

 

 public static void writeImage(BufferedImage img ,String fp,String ext)
 {

 	 try
 	 {
 	 	BufferedImage bi=img;
 	 	File outfile=new File(fp);
 	 	ImageIO.write(bi,ext,outfile);


 	 }catch(IOException e){e.printStackTrace();}

 }

	public static void main(String[] arg) throws Exception
	{
    
     Robot robot=new Robot();
     Dimension d=new Dimension(Toolkit.getDefaultToolkit().getScreenSize());
     int width=(int)d.getWidth();
     int height=(int)d.getHeight();
     
     

   
    
     robot.delay(10);
     Rectangle rc=new Rectangle(0,0,width,height);
     Image image=robot.createScreenCapture(rc);
     sshot obj=new sshot(image,width,height);


     while(true){
     Rectangle rc2=new Rectangle(0,0,width,height);
     Image image2=robot.createScreenCapture(rc2);
     obj.showImage(image2,width,height);
    }
   

    


   }

}
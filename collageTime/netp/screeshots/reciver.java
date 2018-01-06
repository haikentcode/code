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
import java.net.*;
import java.io.*;

public class reciver extends JFrame
{

 PrintWriter out;
 BufferedReader in;
 Socket s;
 String IP=new String("10.42.0.1");
 int PORT=4205;
 BufferedImage img;

JFrame frame;
JPanel panel;
ImageIcon  icon;
JLabel bg;


 reciver() throws Exception
  {

   s=new Socket(IP,PORT);
   out=new PrintWriter(s.getOutputStream(),true);
   frame=new JFrame();
   frame.setVisible(true);
   frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   frame.setSize(600,600);
   bg=new JLabel(icon);
   bg.setLocation(0,0);
   frame.add(bg);

  }
   
public  void writeImage(BufferedImage img ,String fp,String ext)
 {

   try
   {
    
    BufferedImage bi=img;
    File outfile=new File(fp);
    ImageIO.write(bi,ext,outfile);


   }catch(IOException e){e.printStackTrace();}

 }



 public void show( BufferedImage img)
 {


    icon=new ImageIcon(img);
    bg.setIcon(icon);
    bg.setLocation(0,0);
    frame.repaint();

 }


  public static void main(String arg[]) throws Exception
  {
   
   reciver obj=new reciver();
 
    int i=0;

    while(true)
    {
     

     String p="aditi"+i+".png";
     obj.img=ImageIO.read(ImageIO.createImageInputStream(obj.s.getInputStream()));
     obj.show(obj.img);
     //obj.out.println("->ok");
     i++;

    }
   
   

  }




}
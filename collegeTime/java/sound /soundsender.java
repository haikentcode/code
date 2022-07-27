
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.sound.sampled.*;
import java.net.*;
import java.util.*;

class sender
{
 
  boolean stopCapture = false;
  ByteArrayOutputStream byteArrayOutputStream;
  AudioFormat audioFormat;
  TargetDataLine targetDataLine;
  AudioInputStream audioInputStream;
  SourceDataLine sourceDataLine;
  OutputStream out;
  
    Socket skt;
	Scanner sc;
	String IP;
	int PORT;	
	
	sender() throws Exception
	{
		   sc=new Scanner(System.in);
		    System.out.println("IP IS : ");
          	IP=new String("");
          	IP=sc.nextLine();
          	
          	System.out.println("PORT IS :");
          	PORT=sc.nextInt();
          	skt=new Socket(IP,PORT);
          	
            out=skt.getOutputStream();
           
            captureAudio();
          	
	}
	
	 private void captureAudio()
	 	                {
                            try{
                                 audioFormat = getAudioFormat();
                                 DataLine.Info dataLineInfo =new DataLine.Info(TargetDataLine.class,audioFormat);
                                 targetDataLine = (TargetDataLine)AudioSystem.getLine(dataLineInfo);
                                 targetDataLine.open(audioFormat);
                                 targetDataLine.start();
                              
                                 Thread captureThread =new Thread(new CaptureThread());
                                 captureThread.start();
                            } catch (Exception e) 
                            	{
                                  System.out.println(e);
                                  System.exit(0);
                                }
                        }
       
       
      private AudioFormat getAudioFormat()
      	                 {
                                  float sampleRate = 8000.0F;
                                  //8000,11025,16000,22050,44100
                                  int sampleSizeInBits = 16;
                                  //8,16
                                  int channels = 1;
                                 //1,2
                                 boolean signed = true;
                                //true,false
                                 boolean bigEndian = false;
                                //true,false
                         
                            return new AudioFormat(sampleRate,sampleSizeInBits,channels,signed,bigEndian);
                       }                   
                        
                        
      class CaptureThread extends Thread{
  
                           byte tempBuffer[] = new byte[10000];
                           public void run()
                           	{
                                 byteArrayOutputStream =new ByteArrayOutputStream();
                                 stopCapture = false;
                                  
                              try{
    	                         // out.write(5);
                                  while(!stopCapture){
        
                                         int cnt = targetDataLine.read(tempBuffer,0,tempBuffer.length);
                                         System.out.println("cnt is:"+cnt+" bfdata-> "+tempBuffer);
                                         if(cnt > 0){
                                                       
                                                    //write to server here ;;;;;;   
                                                     out.write(tempBuffer, 0, cnt-1);
                                                   }
                                             }
                                             
                                             
                                        byteArrayOutputStream.close();
                                 }catch (Exception e) {
                                                System.out.println("fuck u"+e);
                                                System.exit(0);
                                             }
                          }
                    }
         

	
}


class soundsender
{
	
	
	public static  void main(String args[]) throws Exception
	{
		new sender();
	}
	
	
}

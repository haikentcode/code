
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.sound.sampled.*;
import java.net.*;
import java.util.*;

class reciver
{
 
  boolean stopCapture = false;
  ByteArrayOutputStream byteArrayOutputStream;
  AudioFormat audioFormat;
  TargetDataLine targetDataLine;
  AudioInputStream audioInputStream;
  SourceDataLine sourceDataLine;
  InputStream in;
    Socket skt;
	Scanner sc;
	String IP;
	int PORT;	
	
	reciver() throws Exception
	{
		    sc=new Scanner(System.in);
		  	System.out.println("PORT IS :");
          	PORT=sc.nextInt();
		    ServerSocket s=new ServerSocket(PORT);
		    Socket skt=s.accept();
          	in=skt.getInputStream();
          
          	
          	playAudio();
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
                       
                       
        
       
       private void playAudio()
       	          {
                        try{
                             //byte audioData[] =byteArrayOutputStream.toByteArray(); 
                             //InputStream byteArrayInputStream= new ByteArrayInputStream(audioData);
                             AudioFormat audioFormat =getAudioFormat();
                             //audioInputStream =new AudioInputStream(byteArrayInputStream,audioFormat,audioData.length/audioFormat.getFrameSize());
                             DataLine.Info dataLineInfo =new DataLine.Info(SourceDataLine.class,audioFormat);
                             sourceDataLine = (SourceDataLine)AudioSystem.getLine(dataLineInfo);
                             sourceDataLine.open(audioFormat);
                             sourceDataLine.start();
                             Thread playThread =new Thread(new PlayThread());
                             playThread.start();
                          } catch (Exception e) {
                                          System.out.println("fudhi"+e);
                                          System.exit(0);
                                    }
                }                                   
                        
 
class PlayThread extends Thread{
  byte tempBuffer[] = new byte[10000];

  public void run(){
    try{
      int cnt;
      	    //byte a[]=new byte[100];
          	//in.read(a);
          	//System.out.println("I m read this stuff-:"+a);
      while((cnt = in.read(tempBuffer)) != -1){
          if(cnt > 0){
                       sourceDataLine.write(tempBuffer,0,tempBuffer.length);
                    }
       }
      sourceDataLine.drain();
      sourceDataLine.close();
    }catch (Exception e) {
      System.out.println("fuck u"+e);
      System.exit(0);
    }
  }
}

	
}


class soundreciver
{
	
	
	public static  void main(String args[]) throws Exception 
	{
		new reciver();
	}
	
	
}

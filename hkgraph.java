import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

   class PaintPanel extends JPanel{
   
    Insets ins;// holds the panel's insets
    int arr[][]=new int[1000][2];
    int i=0;
    
    //construct panel
    PaintPanel(){
      setBorder(BorderFactory.createLineBorder(Color.RED,5));
    }
    
    void change(int aa,int bb,int cc,int dd){
      this.arr[i][0]=aa;
      this.arr[i++][1]=bb;
      this.arr[i][0]=cc;
      this.arr[i++][1]=dd;
      if(i>=900) i=0;
      repaint();
     }
  
    // @paintComponent
    
    protected void paintComponent(Graphics g){
      
      super.paintComponent(g);
      int height=getHeight();
      int width=getWidth();
      
       ins=getInsets();
      
       for(int j=0;j<900;j++)
             g.drawLine(j,arr[j][0],j+1,arr[j][1]);

   }


   }



class hkgraph implements Runnable{


JLabel jlab;
PaintPanel pp;

   hkgraph(){

             JFrame jf=new JFrame("hk graph");
             jf.setSize(1000,150);
             jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
             pp=new PaintPanel();
             pp.change(10,20,30,40);
             jf.add(pp);
             jf.setVisible(true);
          
       }
      
      public void start(){
           
              Thread t=new Thread(this);
              t.start();
          
       }
     
       public void run(){
             
            try{
         
            Random rand;
            rand=new Random(); 
            for(;;){
            int x=rand.nextInt(100);
            int y=rand.nextInt(100);
            int a=rand.nextInt(100);
            int b=rand.nextInt(100); 
            pp.change(x,y,a,b);
            System.out.println("change");
            Thread.sleep(200);
             }

            }catch(InterruptedException e){}
       }
   
     public static void main(String arg[]){
   
         SwingUtilities.invokeLater(new Runnable(){
              
          public void run(){
             hkgraph hkg= new hkgraph();
             hkg.start();
           }
          });
   }

}

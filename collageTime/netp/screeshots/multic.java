   import java.awt.*;
    import java.awt.image.*;
    import java.io.*;
    import java.util.*;
    import javax.imageio.*;
    import java.net.*;
 
class ClientSide {

    int ix = 1;
    InputStream in;
    
    public ClientSide() {

    try{
    
    ServerSocket conn = new ServerSocket(4032);
    Socket incoming = conn.accept();
    System.out.println("Data connection Established");


    in = incoming.getInputStream();
    String fromServer = getString();
    System.out.println("First message from dataSender:"+fromServer);
 

    BufferedImage buffImg = null;

    for(;fromServer.indexOf("image") >= 0;)
       {
          //fromServer.contains("image")
         String[] str = fromServer.split(" ");
         int nbrToRead = Integer.parseInt(str[2].trim());

         System.out.println("len=" + nbrToRead + ", avail=" + in.available());

         byte[] byteArray = new byte[nbrToRead];

         int nbrRd = 0;
         int nbrLeftToRead = nbrToRead;

       while(nbrLeftToRead > 0)
                    {
                  
                      int rd =in.read(byteArray, nbrRd, nbrLeftToRead);
                       
                        if(rd < 0)
                                    break;

                      nbrRd += rd; // accumulate bytes read

                      nbrLeftToRead -= rd;

                    System.out.println("Got part of image. rd=" + rd + ", nbrLeftToRead= " + 
                                        nbrLeftToRead + " avail=" + in.available());

                   }


       System.out.println("Got image. nbrToRead=" + nbrToRead + ", nbrRd=" + nbrRd);

      //Converting the image
      
      ByteArrayInputStream byteArrayI = new ByteArrayInputStream(byteArray);
      buffImg = ImageIO.read(byteArrayI);
      File of = new File("RecvdImg" + ix++ + ".jpg");
      ImageIO.write(buffImg, "jpg" ,of);

     //Displaying the image
    //JLabel label = new JLabel(new ImageIcon(buffImg));
    //scrollPane.setViewportView(label);
    
      fromServer = getString();
      System.out.println("Client: Next: " + fromServer);

      if(fromServer == null)
         break;
    } // end for(i)

    in.close();
    conn.close();

    System.out.println("Client: Data Reciever has ended!");

    }catch(Exception x) {
                  x.printStackTrace();
    }

}

String getString() throws IOException {
    byte[] strIn = new byte[100];
    int ix = 0;
    while(true) {
    int rd = in.read();
    if((rd == (int)'\n') || (rd < 0))
    break;
    strIn[ix++] = (byte)rd;
    }
    System.out.println("created str ix=" + ix);
    if(ix == 0)
    return null;
    return new String(strIn, 0, ix);
    }

}


public class multic()
{


}
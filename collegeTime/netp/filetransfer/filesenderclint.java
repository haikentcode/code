/**
 * @(#)filesenderclint.java
 *
 *
 * @author haikent kumar hitesh
 * @version 1.00 2014/11/4
 */

import java.awt.*;
import java.io.*;
import java.net.*;

public class filesenderclint {

    public filesenderclint() {
    	
    	
    	try {
        int port = 8989; // Your Server port number
        Socket sender = new Socket("10.10.109.83", port);
        int count,i=0;

        byte[] data = new byte[1024]; // Here provide size of your file
        FileInputStream fileStream = null;
        BufferedInputStream fileBuffer = null;
        OutputStream out = sender.getOutputStream();
        InputStream in = sender.getInputStream();

        while (i < 10) {

            fileStream = new FileInputStream("k.txt");
            fileBuffer = new BufferedInputStream(fileStream);

            // Sending file data in bytes
            while ((count = fileBuffer.read(data)) > 0) {
                System.out.println("Data Sent : " + count);
                out.write(data, 0, count);
                out.flush();
            }

            // Waiting for response
            while (in.available() <= 0) {
            }
            if (in.read() == 0) {
                System.out.println("File Sent Successfully");
                i++;
            } else {
                System.out.println("File Not Sent Successfully");
            }
        }
    } catch (Exception e) {
    }
    
    }
    
    
    public static void main(String[] arg)
    {
    	new filesenderclint();
    }
    
    
}
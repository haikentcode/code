/**
 * @(#)filereciverserver.java
 *
 *
 * @author 
 * @version 1.00 2014/11/4
 */

import java.awt.*;
import java.io.*;
import java.net.*;

public class filereciverserver {

    public filereciverserver() {
    	
    	
    	try {
    		int port=8989;
    		
        ServerSocket server = new ServerSocket(port);

        // Waiting for client
        Socket receiveSocket = server.accept();
        InputStream in = receiveSocket.getInputStream();
        OutputStream out = receiveSocket.getOutputStream();
        int count, cnt = 10, i = 0;

        // cnt will be total number of files
        while (i < cnt) {
            byte data[] = new byte[1024]; // Provide file size here
            FileOutputStream fileOut = new FileOutputStream("g.txt");
            BufferedOutputStream fileBuffer = new BufferedOutputStream(fileOut);

            // Waiting till client is sending the file
            while (in.available() <= 0) {
            }
            // Receiving byte data and storing it in the file
            while ((count = in.read(data)) > 0) {
                fileBuffer.write(data, 0, count);
                System.out.println("Data Received : " + count);
                fileBuffer.flush();
            }
            // Notify client that you received that file successfully
            out.write(0);

            // Close all streams
            in.close();
            out.close();
            fileBuffer.close();
            fileOut.close();
            i++;
        }
    } catch (Exception e) {
    }
    
    
    System.out.println("error");
    }
    
    public  static void main(String[] arg)
    {
    	new filereciverserver();
    }
}
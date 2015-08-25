package com.zetcode;

import java.awt.EventQueue;
import javax.swing.JFrame;


public class snak extends JFrame {

    public snak() {

        add(new snakboard());        
        
        setTitle("Snake");
        pack();
        setResizable(false);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            
            @Override
            public void run() {                
                JFrame ex = new snak();
                ex.setVisible(true);                
            }
        });
    }
}
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/*
<applet code="form" width=250 height=250>
</applet>
*/

public class form extends JApplet implements ItemListener ,ActionListener {
  JTextField name;
  JLabel l1;
  JTextField age;
  JLabel l2;
  JTextField branch;
  JLabel l3;
  JLabel jlab; 
public void init() {
try {
SwingUtilities.invokeAndWait(
new Runnable() {
public void run() {
makeGUI();
}
}
);
} catch (Exception exc) {
System.out.println("Can't create because of " + exc);
}
}

private void makeGUI() {
        setLayout(new FlowLayout());
        l1=new JLabel("NAME:");
        add(l1);
        name=new JTextField(20);
        add(name);
	name.addActionListener(new ActionListener(){
                                              public void actionPerformed(ActionEvent ae) {
                                               showStatus(name.getText());
                                        }
                                 });
       l2=new JLabel("AGE:");
        add(l2);
        age=new JTextField(20);
        add(age);
	age.addActionListener(new ActionListener(){
                                              public void actionPerformed(ActionEvent ae) {
                                               showStatus(age.getText());
                                        }
                                 });
    l3=new JLabel("BRANCH:");
        add(l3);
        branch=new JTextField(20);
        add(branch);
	branch.addActionListener(new ActionListener(){
                                              public void actionPerformed(ActionEvent ae) {
                                               showStatus(branch.getText());
                                        }
                                 });
jlab = new JLabel("SELECT LANGUAGES");
add(jlab);
   JCheckBox cb = new JCheckBox("C");
cb.addItemListener(this);
add(cb);
cb = new JCheckBox("C++");
cb.addItemListener(this);
add(cb);

jlab = new JLabel("GENDER:");
add(jlab);

JRadioButton b1 = new JRadioButton("Male");
b1.addActionListener(this);
add(b1);

JRadioButton b2 = new JRadioButton("Female");
b2.addActionListener(this);
add(b2);

ButtonGroup bg = new ButtonGroup();
bg.add(b1);
bg.add(b2);

  }
public void itemStateChanged(ItemEvent ie) {
JCheckBox cb = (JCheckBox)ie.getItem();

if(cb.isSelected())
showStatus(cb.getText() + " is selected");
else
showStatus(cb.getText() + " is cleared");
}

public void actionPerformed(ActionEvent ae) {
showStatus(ae.getActionCommand() + "Selected");
}
}
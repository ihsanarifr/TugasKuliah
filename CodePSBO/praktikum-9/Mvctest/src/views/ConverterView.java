package views;

import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class ConverterView {
    private JFrame frame;
    private JTextField inputTextBox;
    private JLabel result;
    private JButton button;
    
    public ConverterView(String title){
        frame = new JFrame(title);
        frame.setLayout(new GridLayout(3,1));
        frame.setSize(200,100);
        
        inputTextBox = new JTextField();
        frame.add(inputTextBox);
        
        result = new JLabel();
        frame.add(result);
        
        button = new JButton("Convert");
        frame.add(button);
        
        frame.setVisible(true);
    }
    
    public String getInput(){
        return inputTextBox.getText();
    }
    
    public void setResult(String text){
        result.setText(text);
    }
    
    public void setButtonAction(ActionListener listener){
        button.addActionListener(listener);
    }
}

package controllers;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import models.Currency;
import views.ConverterView;

public class USDToIDRController {
    private Currency model;
    private ConverterView view;
    
    public USDToIDRController(){
        // load model
        model = new Currency(13900);
        // load view
        view = new ConverterView("USD to IDR");
        
        ActionListener action = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // button action & get input
                float inputUSD = Float.parseFloat(view.getInput());
                // send input
                model.setInput(inputUSD);
                // calculate result
                model.convert();
                // get output
                float outputIDR = model.getResult();
                // write result to 
                view.setResult(Float.toString(outputIDR));
            }
        };
        view.setButtonAction(action);
    }
    
    public static void main(String[] args) {
        USDToIDRController contr = new USDToIDRController();
    }
}

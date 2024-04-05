import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;

public class CurrencyConverterApp {
    private JFrame frame;
    private JTextField rupeeField, dollarField;
    private JButton convertButton;

    public CurrencyConverterApp() {
        frame = new JFrame("Currency Converter");
        frame.setSize(300, 150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(3, 2));

        JLabel rupeeLabel = new JLabel("Rupees:");
        rupeeField = new JTextField(15);

        JLabel dollarLabel = new JLabel("Dollars:");
        dollarField = new JTextField(15);
        dollarField.setEditable(false);

        convertButton = new JButton("Convert");
        convertButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                convertCurrency();
            }
        });

        panel.add(rupeeLabel);
        panel.add(rupeeField);
        panel.add(dollarLabel);
        panel.add(dollarField);
        panel.add(new JLabel()); // Placeholder
        panel.add(convertButton);

        frame.add(panel);
        frame.setVisible(true);
    }

    private void convertCurrency() {
        try {
            double rupees = Double.parseDouble(rupeeField.getText());
            double dollars = rupees / 80; 
            DecimalFormat df = new DecimalFormat("#.##");
            dollarField.setText(df.format(dollars));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(frame, "Invalid input. Please enter a valid amount in Rupees.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(CurrencyConverterApp::new);
    }
}
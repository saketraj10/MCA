import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculatorApp2 {
    private JFrame frame;
    private JTextField numField1, numField2, resultField;
    private JComboBox<String> operationCombo;
    private JButton calculateButton;

    public CalculatorApp2() {
        frame = new JFrame("Simple Calculator");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        numField1 = new JTextField(10);
        numField2 = new JTextField(10);
        resultField = new JTextField(10);
        resultField.setEditable(false);

        String[] operations = {"Addition", "Subtraction", "Multiplication", "Division"};
        operationCombo = new JComboBox<>(operations);

        calculateButton = new JButton("Calculate");
        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                performCalculation();
            }
        }); 

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 2));
        panel.add(new JLabel("Number 1:"));
        panel.add(numField1);
        panel.add(new JLabel("Number 2:"));
        panel.add(numField2);
        panel.add(new JLabel("Operation:"));
        panel.add(operationCombo);
        panel.add(new JLabel("Result:"));
        panel.add(resultField);
        panel.add(new JLabel()); // Placeholder
        panel.add(calculateButton);

        frame.add(panel);
        frame.setVisible(true);
    }

    private void performCalculation() {
        try {
            double num1 = Double.parseDouble(numField1.getText());
            double num2 = Double.parseDouble(numField2.getText());
            double result = 0;

            String selectedOperation = operationCombo.getSelectedItem().toString();
            switch (selectedOperation) {
                case "Addition":
                    result = num1 + num2;
                    break;
                case "Subtraction":
                    result = num1 - num2;
                    break;
                case "Multiplication":
                    result = num1 * num2;
                    break;
                case "Division":
                    if (num2 != 0) {
                        result = num1 / num2;
                    } else {
                        JOptionPane.showMessageDialog(frame, "Division by zero is not allowed.", "Error", JOptionPane.ERROR_MESSAGE);
                        return;
                    }
                    break;
            }

            resultField.setText(String.valueOf(result));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(frame, "Invalid input. Please enter valid numbers.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(CalculatorApp2::new);
    }
}
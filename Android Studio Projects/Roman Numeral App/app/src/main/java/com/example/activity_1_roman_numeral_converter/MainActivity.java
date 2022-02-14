package com.example.activity_1_roman_numeral_converter;

//Imports
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import org.w3c.dom.Text;

//Main CLass
public class MainActivity extends AppCompatActivity {

    //Define Variables
    Button b_convertToRoman, b_convertToNumber;
    EditText et_number, et_romanInput;
    TextView tv_romanOutput, tv_numberOutput;

    @Override
    //Create Function
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Declare the Variables
        b_convertToNumber = (Button) findViewById(R.id.b_convertToNumber);
        b_convertToRoman = (Button) findViewById(R.id.b_convertToRoman);
        et_number = (EditText) findViewById(R.id.et_number);
        et_romanInput = (EditText) findViewById(R.id.et_romanInput);
        tv_romanOutput = (TextView) findViewById(R.id.tv_romanOuput);
        tv_numberOutput = (TextView) findViewById(R.id.tv_numberOutput);

        //Button Handler for Convert to Number
        b_convertToNumber.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                NumberConverter rnc = new NumberConverter(); //Variable for the Number Converter class
                String theNumeral; //The input
                int theNumOutput; //String to Output

                theNumeral = et_romanInput.getText().toString(); //Sets the roman input to a string
                theNumOutput = rnc.toNumber(theNumeral); //Converts the roman to number

                tv_numberOutput.setText(String.valueOf(theNumOutput)); //Outputs the number
            }
        });

        //Button Handler for the Convert to Roman
        b_convertToRoman.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                NumberConverter nc = new NumberConverter(); //Variable for the Number Converter class
                int theNumber; //The input
                String theRoman; //String to Output

                theNumber = Integer.parseInt(et_number.getText().toString()); //Sets the input to a string
                theRoman = nc.toRoman(theNumber); //Converts the number to roman

                tv_romanOutput.setText(theRoman); //Outputs the Roman
            }
        });
    }
}
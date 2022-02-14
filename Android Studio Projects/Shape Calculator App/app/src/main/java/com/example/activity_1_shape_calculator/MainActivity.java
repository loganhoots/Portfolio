package com.example.activity_1_shape_calculator;

//Imports
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

//Main Class
public class MainActivity extends AppCompatActivity {

    //Define Variables
    EditText et_width_input, et_height_input;
    RadioGroup choice;
    Button b_calculate;
    TextView tv_area_output, tv_perimeter_output;

    @Override
    //Create function
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Declare the variables
        et_width_input = (EditText) findViewById(R.id.et_width_input);
        et_height_input = (EditText) findViewById(R.id.et_height_input);
        choice = (RadioGroup) findViewById(R.id.choice);
        b_calculate = (Button) findViewById(R.id.btn_calculate);
        tv_area_output = (TextView) findViewById(R.id.area_output);
        tv_perimeter_output = (TextView) findViewById(R.id.perimeter_output);

        //Button Handler
        b_calculate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Calculate calc = new Calculate(); //Variable for Calculate class
                float w, h; //Input variables for width and height
                int c, r; //Variables for the shape choice
                w = Float.parseFloat(et_width_input.getText().toString()); //Set width to the input
                h = Float.parseFloat(et_height_input.getText().toString()); //Set height to the input
                r = choice.getCheckedRadioButtonId(); //Sets r to the id of the Radio Group

                //Switch case based on the radio group
                switch (r) {
                    case R.id.rect_choice: //Checks if the choice is the rectangle
                        c = 1; //Sets the choice variable to 1
                        break;
                    case R.id.tri_choice: //Checks if the choice is the triangle
                        c = 2; //Sets the choice variable to 2
                        break;
                    case R.id.rhom_choice: //Checks if the choice is a rhombus
                        c = 1; //Sets the choice variable to 1
                        break; //This is because the rhombus and rectangle are the same computationally
                    default: //Checks for invalid characters
                        c = -1; //Sets the choice variable to -1
                        break;
                }
                tv_area_output.setText(calc.area(w,h,c)); //Sets the area output to the correct value
                tv_perimeter_output.setText(calc.perimeter(w,h,c)); //Sets the perimeter output to the correct value
            }
        });
    }
}
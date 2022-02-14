package com.example.lhoots_love_meter;

//Import libraries
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.animation.AccelerateDecelerateInterpolator;
import android.view.animation.Animation;
import android.view.animation.RotateAnimation;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

//Define main class
public class MainActivity extends AppCompatActivity {

    //Define variables
    Button b_calc;
    ImageView needle;
    EditText name_1, name_2;
    TextView output;

    //Create function
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Declare variables
        b_calc = (Button) findViewById(R.id.btn_calculate);
        needle = (ImageView) findViewById(R.id.iv_needle);
        name_1 = (EditText) findViewById(R.id.et_name_1);
        name_2 = (EditText) findViewById(R.id.et_name_2);
        output = (TextView) findViewById(R.id.tv_output);

        //Calculate Button Handler
        b_calc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String s_name_1 = name_1.getText().toString(); //Sets the first name input to s_name_1
                String s_name_2 = name_2.getText().toString(); //Sets the second name input to s_name_2

                float totalLetters = s_name_1.length() + s_name_2.length(); //Creates a float the size of both names
                int totalMatches = 0; //Initializes total matches to 0

                //Nested for loop to loop through the strings
                for (int i = 0; i < s_name_1.length(); i++) {
                    for (int j = 0; j < s_name_2.length(); j++) {
                        //Checks if the characters are the same
                        if (s_name_1.charAt(i) == s_name_2.charAt(j)) {
                            totalMatches++; //Increases total matches
                        }
                    }
                }

                //Nested for loop to loop through the strings
                for (int i = 0; i < s_name_2.length(); i++) {
                    for (int j = 0; j < s_name_1.length(); j++) {
                        //Checks if the characters are the same
                        if (s_name_2.charAt(i) == s_name_1.charAt(j)) {
                            totalMatches++; //Increases total matches
                        }
                    }
                }

                float compatScore = (float) totalMatches / totalLetters; //Calculates compatibility score
                output.setText("Compat Score: " + String.valueOf(compatScore)); //Outputs the score
                //Toast.makeText(MainActivity.this, "hi", Toast.LENGTH_SHORT).show();

                //Checks if the score is equal to 0
                if (compatScore == 0) { compatScore = -45; } //Sets the score to -45
                else if (compatScore < 0.5) { //Checks if the score is less that 0.5
                    compatScore = 1f - 2 * compatScore; //Updates the score
                    compatScore = compatScore * -45; //Scales the score for the animation
                }
                else if (compatScore < 1) { //Checks if the score is less than 1
                    compatScore = 2 * compatScore - 1f; //Updates the score
                    compatScore = compatScore * 45 ; //Scales the score for tha animation
                }
                else { compatScore = 45; } //Sets the score to 45

                //Creates an animation
                RotateAnimation spin_needle = new RotateAnimation(-45, compatScore, Animation.RELATIVE_TO_SELF, 0.5f, Animation.RELATIVE_TO_SELF, 0.5f);
                spin_needle.setDuration(2000); //Sets the animation to take 2 seconds
                spin_needle.setFillAfter(true); //Makes the image stay after animation
                spin_needle.setInterpolator(new AccelerateDecelerateInterpolator()); //Sets the acceleration
                needle.startAnimation(spin_needle); //Runs the animation of the needle
            }
        });
    }
}
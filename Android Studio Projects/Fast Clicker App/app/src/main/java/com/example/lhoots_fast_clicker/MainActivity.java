package com.example.lhoots_fast_clicker;

//Import libraries
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

//Define main class
public class MainActivity extends AppCompatActivity {

    //Define/Declare variables
    Button b_start, b_click_top, b_click_bottom;
    TextView tv_timer, tv_clicks;
    int numberOfClicks = 0, secondsLeft = 21;

    //Create Function
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Declare variables
        b_start = (Button) findViewById(R.id.btn_start);
        b_click_top = (Button) findViewById(R.id.btn_click_top);
        b_click_bottom = (Button) findViewById(R.id.btn_click_bottom);
        tv_timer = (TextView) findViewById(R.id.tv_time_left);
        tv_clicks = (TextView) findViewById(R.id.tv_clicks);

        //Turns off both click buttons
        b_click_top.setEnabled(false);
        b_click_bottom.setEnabled(false);

        //Timer Function
        CountDownTimer timer = new CountDownTimer(21000, 1000) {
            @Override
            //Updates the timer each second
            public void onTick(long millisUntilFinished) {
                secondsLeft -= 1; //Increments the timer
                tv_timer.setText("Time Left: " + secondsLeft); //Outputs the timer
            }

            //Handles when the timer ends
            @Override
            public void onFinish() {
                b_click_top.setEnabled(false); //Disables the top clicker
                b_click_bottom.setEnabled(false); //Disables the bottom clicker
                b_start.setEnabled(true); //Enables the start button
            }
        };

        //Start button handler
        b_start.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numberOfClicks = 0; //Resets the number of clicks
                secondsLeft = 21; //Updates the timer to 20 seconds

                tv_clicks.setText("Total Clicks: " + numberOfClicks); //Output the total clicks
                tv_timer.setText("Time Left: " + secondsLeft); //Outputs the time left

                b_click_top.setEnabled(true); //Enables the top clicker
                timer.start(); //Calls the timer to start
                b_start.setEnabled(false); //Disables the start button
            }
        });

        //Top Clicker Button Handler
        b_click_top.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numberOfClicks += 1; //Updates the number of clicks
                tv_clicks.setText("Total Clicks: " + numberOfClicks); //Outputs the total clicks
                b_click_top.setEnabled(false); //Disables the top clicker
                b_click_bottom.setEnabled(true); //Enables the bottom clicker
            }
        });

        //Bottom Clicker Button Handler
        b_click_bottom.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numberOfClicks += 1; //Updates the number of clicks
                tv_clicks.setText("Total Clicks: " + numberOfClicks); //Outputs the total clicks
                b_click_bottom.setEnabled(false); //Disables the bottom clicker
                b_click_top.setEnabled(true); //Enables the top clicker
            }
        });
    }
}
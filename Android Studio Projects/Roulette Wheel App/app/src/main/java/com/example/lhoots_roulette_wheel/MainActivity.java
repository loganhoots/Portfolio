package com.example.lhoots_roulette_wheel;

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
import java.util.Random;

//Creates main class
public class MainActivity extends AppCompatActivity {

    //Defines variables
    Button b_new_game, b_spin;
    ImageView iv_ball;
    EditText et_bet_red, et_bet_black, et_bet_odd, et_bet_even, et_bet_1_12, et_bet_13_24,
            et_bet_25_36, et_sn_num, et_sn_bet;
    TextView tv_cash, tv_spin_output, tv_money_output;

    //Defines/Declares Variables
    int[] wheel_num = new int[]{0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23,
            10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};
    String[] wheel_color = new String[]{"Green", "Red", "Black"};
    int spaces, int_random, color, cash = 1000, bet = 0, total;

    //Create function
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Declares variables
        b_new_game = (Button) findViewById(R.id.btn_new_game);
        b_spin = (Button) findViewById(R.id.btn_spin);
        iv_ball = (ImageView) findViewById(R.id.iv_ball);
        et_bet_red = (EditText) findViewById(R.id.et_bet_red);
        et_bet_black = (EditText) findViewById(R.id.et_bet_black);
        et_bet_odd = (EditText) findViewById(R.id.et_bet_odd);
        et_bet_even = (EditText) findViewById(R.id.et_bet_even);
        et_bet_1_12 = (EditText) findViewById(R.id.et_bet_1_12);
        et_bet_13_24 = (EditText) findViewById(R.id.et_bet_13_24);
        et_bet_25_36 = (EditText) findViewById(R.id.et_bet_25_36);
        et_sn_num = (EditText) findViewById(R.id.et_specific_number);
        et_sn_bet = (EditText) findViewById(R.id.et_specific_number_bet);
        tv_cash = (TextView) findViewById(R.id.tv_cash);
        tv_spin_output = (TextView) findViewById(R.id.tv_spin_output);
        tv_money_output = (TextView) findViewById(R.id.tv_money_output);

        //Creates a random object
        Random rand = new Random();

        //New Game Button Handler
        b_new_game.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bet = 0; //Sets the bet to 0
                cash = 1000; //Sets the starting cash to 1000
                tv_cash.setText("Cash: $" + cash); //Outputs the cash
                tv_money_output.setText(""); //Sets the money earning output to nothing
                tv_spin_output.setText(""); //Sets the spin output to nothing
            }
        });

        //Spin Button Handler
        b_spin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                spaces = 0; //Sets the spaces spun to 0
                int_random = rand.nextInt(1080); //Pulls a random int from 0 - 1079

                //Creates an animation for the ball spin
                RotateAnimation spin_ball = new RotateAnimation(0, int_random + 1080,
                        Animation.RELATIVE_TO_SELF, 0.5f, Animation.RELATIVE_TO_SELF, 0.5f);
                spin_ball.setDuration(5000); //Sets the animation to take 5 seconds
                spin_ball.setFillAfter(true); //Lets the image stay when the animation is over
                spin_ball.setInterpolator(new AccelerateDecelerateInterpolator()); //Handles the animation acceleration
                spin_ball.setAnimationListener(new Animation.AnimationListener() {
                    @Override
                    //Handles anything at the start of the animation
                    public void onAnimationStart(Animation animation) {
                        b_new_game.setEnabled(false); //Turns off the new game button
                        b_spin.setEnabled(false); //Turns off the spin button
                        while (int_random > 360) { int_random = int_random - 360; } //While the random number is greater than 360 subtract 360 from it
                        float land = (float) int_random; //Makes the random number to a float
                        while (land > 0f) { //While the float is greater than 0
                            if (land > 4.865f) { //Checks if the number is greater than half way through a section
                                land = land - 9.73f; //Updates the random number to the next space
                                spaces++; //Updates the number of spaces passed
                                if (spaces >= wheel_num.length) { spaces = 0; } //Checks if the spaces is looped, then set it to 0
                            }
                            else { land = land - 4.865f; } //Otherwise subtract half a space
                        }
                        if (spaces % 2 == 0 && wheel_num[spaces] != 0) { color = 2; } //Checks if the number of spaces is even and not 0, then set the color to black
                        else if (spaces % 2 == 1) { color = 1; } //Checks if the number off spaces is odd, then set the color to red
                        else { color = 0; } //Otherwise set the color to green
                    }

                    @Override
                    //Handles anything at the end of the animation
                    public void onAnimationEnd(Animation animation) {
                        tv_spin_output.setText(String.valueOf(wheel_num[spaces]) + " " + String.valueOf(wheel_color[color])); //Outputs where the ball lands
                        b_spin.setEnabled(true); //Enables the spin button
                        bet(); //Calls the bet function
                        b_new_game.setEnabled(true); //Enables the new game button
                    }

                    @Override
                    //Handles anything if the animation repeats
                    public void onAnimationRepeat(Animation animation) { } //Nothing happens
                });
                iv_ball.startAnimation(spin_ball); //Calls the animation on the ball
            }
        });
    }

    //Creates the bet function
    public void bet() {
        if (isNotInt(et_bet_red.getText().toString())) { et_bet_red.setText("0"); } //If the input is not an Int, set it to 0
        if (isNotInt(et_bet_black.getText().toString())) { et_bet_black.setText("0"); } //If the input is not an Int, set it to 0
        if (isNotInt(et_bet_odd.getText().toString())) { et_bet_odd.setText("0"); } //If the input is not an Int, set it to 0
        if (isNotInt(et_bet_even.getText().toString())) { et_bet_even.setText("0"); } //If the input is not an Int, set it to 0
        if (isNotInt(et_bet_1_12.getText().toString())) { et_bet_1_12.setText("0"); } //If the input is not an Int, set it to 0
        if (isNotInt(et_bet_13_24.getText().toString())) { et_bet_13_24.setText("0"); } //If the input is not an Int, set it to 0
        if (isNotInt(et_bet_25_36.getText().toString())) { et_bet_25_36.setText("0"); } //If the input is not an Int, set it to 0
        if (isNotInt(et_sn_bet.getText().toString()) || isNotInt(et_sn_num.getText().toString())) { et_sn_bet.setText("0"); et_sn_num.setText("-1"); } //If the input is not an Int, set it to 0
        //Adds all the bets together
        bet = Integer.parseInt(et_bet_red.getText().toString()) + Integer.parseInt(et_bet_black.getText().toString())
                + Integer.parseInt(et_bet_odd.getText().toString()) + Integer.parseInt(et_bet_even.getText().toString())
                + Integer.parseInt(et_bet_1_12.getText().toString()) + Integer.parseInt(et_bet_13_24.getText().toString())
                + Integer.parseInt(et_bet_25_36.getText().toString()) + Integer.parseInt(et_sn_bet.getText().toString());
        if (bet <= cash) { //Checks if the player can afford the bet
            cash = cash - bet; //Removes the bet from the player
            tv_cash.setText("Cash: $" + cash); //Updates the cash
            compare(); //Calls the compare function
        }
        else { tv_money_output.setText("Insufficient Funds"); } //Otherwise Output the player has insufficient funds
    }

    //Creates the isNotInt function
    public static boolean isNotInt(final String s) {
        if (s == null || s.length() == 0) { return true; } //Checks if the string is null or 0, return is not int
        for (char c : s.toCharArray()) { if (!Character.isDigit(c)) { return true; } } //Loops through the chars of the input to check if they're digits, return is not int
        return false; //Otherwise return is int
    }

    //Creates the compare function
    public void compare() {
        total = -bet; //Inverts the bet
        if (Integer.parseInt(et_bet_red.getText().toString()) > 0 && color == 1) { //Checks if the player bet red and it landed on red
            cash = cash + (Integer.parseInt(et_bet_red.getText().toString()) * 2); //Updates the player cash
            total = total + Integer.parseInt(et_bet_red.getText().toString()) * 2; //Updates the total change of money
        }
        if (Integer.parseInt(et_bet_black.getText().toString()) > 0 && color == 2) { //Checks if the player bet black and it landed on black
            cash = cash + (Integer.parseInt(et_bet_black.getText().toString()) * 2); //Updates the player cash
            total = total + Integer.parseInt(et_bet_black.getText().toString()) * 2; //Updates the total change of money
        }
        if (Integer.parseInt(et_bet_odd.getText().toString()) > 0 && wheel_num[spaces] % 2 == 1) { //Checks if the player bet odd and it landed on odd
            cash = cash + (Integer.parseInt(et_bet_odd.getText().toString()) * 2); //Updates the player cash
            total = total + Integer.parseInt(et_bet_odd.getText().toString()) * 2; //Updates the total change of money
        }
        if (Integer.parseInt(et_bet_even.getText().toString()) > 0 && wheel_num[spaces] % 2 == 0 && spaces != 0) { //Checks if the player bet even and it landed on even
            cash = cash + (Integer.parseInt(et_bet_even.getText().toString()) * 2); //Updates the player cash
            total = total + Integer.parseInt(et_bet_even.getText().toString()) * 2; //Updates the total change of money
        }
        if (Integer.parseInt(et_bet_1_12.getText().toString()) > 0 && wheel_num[spaces] < 13 && wheel_num[spaces] > 0) { //Checks if the player bet 1-12 and it landed 1-12
            cash = cash + (Integer.parseInt(et_bet_1_12.getText().toString()) * 3); //Updates the player cash
            total = total + Integer.parseInt(et_bet_1_12.getText().toString()) * 3; //Updates the total change of money
        }
        if (Integer.parseInt(et_bet_13_24.getText().toString()) > 0 && wheel_num[spaces] < 25 && wheel_num[spaces] > 12) { //Checks if the player bet 13-24 and it landed 13-24
            cash = cash + (Integer.parseInt(et_bet_13_24.getText().toString()) * 3); //Updates the player cash
            total = total + Integer.parseInt(et_bet_13_24.getText().toString()) * 3; //Updates the total change of money
        }
        if (Integer.parseInt(et_bet_25_36.getText().toString()) > 0 && wheel_num[spaces] < 37 && wheel_num[spaces] > 24) { //Checks if the player bet 25-36 and it landed 25-36
            cash = cash + (Integer.parseInt(et_bet_25_36.getText().toString()) * 3); //Updates the player cash
            total = total + Integer.parseInt(et_bet_25_36.getText().toString()) * 3; //Updates the total change of money
        }
        if (Integer.parseInt(et_sn_bet.getText().toString()) > 0 && wheel_num[spaces] == Integer.parseInt(et_sn_num.getText().toString())) { //Checks if the player bet a specific number and it landed the same
            cash = cash + (Integer.parseInt(et_sn_bet.getText().toString()) * 36); //Updates the player cash
            total = total + Integer.parseInt(et_sn_bet.getText().toString()) * 36; //Updates the total change of money
        }
        tv_money_output.setText("Win: $" + total); //Outputs the total change in earnings
        tv_cash.setText("Cash: $" + cash); //Outputs the new cash value
    }
}
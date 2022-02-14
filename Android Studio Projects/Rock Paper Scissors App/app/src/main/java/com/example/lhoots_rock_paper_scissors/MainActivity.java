package com.example.lhoots_rock_paper_scissors;

//Import libraries
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import java.util.Random;

//Define main class
public class MainActivity extends AppCompatActivity {

    //Define/Declare Variables
    Button btn_rock, btn_paper, btn_scissors, btn_reset;
    TextView tv_player_score, tv_computer_score, tv_output;
    ImageView iv_player_choice, iv_computer_choice;
    int playerScore = 0, computerScore = 0;

    //Create function
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Declare Variables
        btn_rock = (Button) findViewById(R.id.btn_rock);
        btn_paper = (Button) findViewById(R.id.btn_paper);
        btn_scissors = (Button) findViewById(R.id.btn_scissors);
        btn_reset = (Button) findViewById(R.id.btn_reset);
        tv_player_score = (TextView) findViewById(R.id.tv_Player_Score);
        tv_computer_score = (TextView) findViewById(R.id.tv_Computer_score);
        iv_player_choice = (ImageView) findViewById(R.id.iv_Human_Choice);
        iv_computer_choice = (ImageView) findViewById(R.id.iv_Computer_Choice);
        tv_output = (TextView) findViewById(R.id.tv_output);

        //Rock Button Handler
        btn_rock.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                iv_player_choice.setImageResource(R.drawable.ro); //Updates the player choice image to the rock
                String message = play_turn("rock"); //Runs Play Turn for the rock
                tv_output.setText(message); //Outputs the return from the Play Turn
                tv_player_score.setText("Player Score: " + playerScore); //Outputs the player score
                tv_computer_score.setText("Computer Score: " + computerScore); //Outputs the computer score
            }
        });

        //Paper Button Handler
        btn_paper.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                iv_player_choice.setImageResource(R.drawable.pa); //Updates the player choice image to the paper
                String message = play_turn("paper"); //Runs the Play Turn for the paper
                tv_output.setText(message); //Outputs the return from the Play Turn
                tv_player_score.setText("Player Score: " + playerScore); //Outputs the player score
                tv_computer_score.setText("Computer Score: " + computerScore); //Outputs the computer score
            }
        });

        //Scissors Button Handler
        btn_scissors.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                iv_player_choice.setImageResource(R.drawable.sc); //Updates the player choice image to the scissors
                String message = play_turn("scissors"); //Runs the Pay Turn for the scissors
                tv_output.setText(message); //Outputs the return from the Play Turn
                tv_player_score.setText("Player Score: " + playerScore); //Outputs the player score
                tv_computer_score.setText("Computer Score: " + computerScore); //Outputs the computer score
            }
        });

        //Reset Button Handler
        btn_reset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_output.setText("Reseting..."); //Outputs reset
                iv_player_choice.setImageResource(R.drawable.ro); //Sets the player choice image to the rock
                iv_computer_choice.setImageResource(R.drawable.ro); //Sets the computer choice image to the rock
                playerScore = 0; //Sets the player score to 0
                computerScore = 0; //Sets the computer score to 0
                tv_player_score.setText("Player Score: " + playerScore); //Outputs the player score
                tv_computer_score.setText("Computer Score: " + computerScore); //Outputs the computer score
                tv_output.setText(""); //Outputs nothing
            }
        });
    }

    //Creates the play_turn function
    public String play_turn(String player_choice)
    {
        String computer_choice = ""; //Sets the computer choice to nothing
        Random r = new Random(); //Creates a random object
        int computer_choice_number = r.nextInt(3) + 1; //Gets the next number 1 - 3
        switch (computer_choice_number) { //Switch case based on the random number
            case 1: //If the random number is one
                computer_choice = "rock"; //Sets the computer choice to rock
                iv_computer_choice.setImageResource(R.drawable.ro); //Sets the computer choice image to the rock
                break; //Breaks the switch
            case 2: //If the random number is two
                computer_choice = "paper"; //Sets the computer choice to paper
                iv_computer_choice.setImageResource(R.drawable.pa); //Sets the computer choice image to the paper
                break; //Breaks the switch
            case 3: //If the random number is three
                computer_choice = "scissors"; //Sets the computer choice to paper
                iv_computer_choice.setImageResource(R.drawable.sc); //Sets the computer choice image to the scissors
                break; //Breaks the switch
        }

        //Checks if the player choice and the computer choice are the same
        if (player_choice.equals(computer_choice)) { return "Tie. No one wins."; } //Returns the tie
        else if (player_choice.equals("rock") && computer_choice.equals("scissors")) { //Checks if the player chooses rock and the computer chooses scissors
            playerScore++; //Increases the player score
            return "Rock crushes scissors. You Win!"; //Returns the rock crushes scissors output
        }
        else if (player_choice.equals("rock") && computer_choice.equals("paper")) { //Checks if the player chooses rock and computer chooses paper
            computerScore++; //Increases the computer score
            return "Paper covers rock. You Lose!"; //Returns the paper covers rock output
        }
        else if (player_choice.equals("scissors") && computer_choice.equals("rock")) { //Checks if the player chooses scissors and the computer chooses rock
            computerScore++; //Increases the computer score
            return "Rock crushes scissors. You Lose!"; //Returns the rock crushes scissors output
        }
        else if (player_choice.equals("scissors") && computer_choice.equals("paper")) { //Checks if the player chooses scissors and the computer chooses paper
            playerScore++; //Increases the computer score
            return "Scissors cut paper. You Win!"; //Returns the scissors cuts paper output
        }
        else if (player_choice.equals("paper") && computer_choice.equals("rock")) { //Checks if the player chooses paper and the computer chooses rock
            playerScore++; //Increases player score
            return "Paper covers rock. You Win!"; //Returns the paper covers rock output
        }
        else if (player_choice.equals("paper") && computer_choice.equals("scissors")) { //Checks if the player chooses paper and the computer chooses scissors
            computerScore++; //Increases computer score
            return "Scissors cut paper. You Lose!"; //Returns the scissors cuts paper output
        }
        else { return "Help me. I'm stuck in a simulation."; } //Ultimatum line that never gets used
    }
}
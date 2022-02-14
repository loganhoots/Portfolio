package com.example.lhoots_math_quiz;

//Import Libraries
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;

//Declare main activity class
public class MainActivity extends AppCompatActivity {
    //Declare variables
    Button btn_start, btn_ans_1, btn_ans_2, btn_ans_3, btn_ans_4;
    TextView tv_score, tv_questions, tv_timer, tv_output;
    ProgressBar prog_timer;
    Game g = new Game();
    int secondsRemaining;

    //Count Down Timer Function
    CountDownTimer timer = new CountDownTimer(30000, 1000) { //30 second timer
        @Override
        public void onTick(long millisUntilFinished) { //Every second function
            secondsRemaining--; //Decrease by 1 second
            tv_timer.setText(Integer.toString(secondsRemaining) + " sec"); //Updates the seconds left
            prog_timer.setProgress(30 - secondsRemaining); //Updates the progress bar
        }

        @Override
        public void onFinish() { //On end function
            btn_ans_1.setEnabled(false); //Disables answer button
            btn_ans_2.setEnabled(false); //Disables answer button
            btn_ans_3.setEnabled(false); //Disables answer button
            btn_ans_4.setEnabled(false); //Disables answer button
            tv_output.setText("Time is up! " + g.getNumberCorrect() + "/" + (g.getTotalQuestions() - 1)); //Outputs the final score
            final Handler handler = new Handler(); //Creates a handler object
            handler.postDelayed(new Runnable() { //Sets up the handler
                @Override
                public void run() { //After the handler
                    btn_start.setVisibility(View.VISIBLE); //Sets the start button to visible
                }
            }, 4000); //Delays 4 seconds
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) { //Create function
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Assign all elements
        btn_start = findViewById(R.id.btn_start);
        btn_ans_1 = findViewById(R.id.btn_ans_1);
        btn_ans_2 = findViewById(R.id.btn_ans_2);
        btn_ans_3 = findViewById(R.id.btn_ans_3);
        btn_ans_4 = findViewById(R.id.btn_ans_4);
        tv_score = findViewById(R.id.tv_score);
        tv_questions = findViewById(R.id.tv_questions);
        tv_timer = findViewById(R.id.tv_timer);
        tv_output = findViewById(R.id.tv_output);
        prog_timer = findViewById(R.id.pbh_timer);

        tv_timer.setText("0 sec"); //Sets the timer to 0 seconds
        tv_questions.setText(""); //Sets the question to nothing
        tv_score.setText("0 Points"); //Sets the score to 0
        tv_output.setText("Press Go!"); //Sets the bottom output to "Press Go!"

        View.OnClickListener startButtonClickListener = new View.OnClickListener() { //Start button click listener
            @Override
            public void onClick(View v) { //Handles on click
                Button start_button = (Button) v; //Sets the View to the button
                secondsRemaining = 30; //Sets 30 seconds left
                g = new Game(); //Creates a new game
                tv_score.setText(Integer.toString(g.getScore()) + " Points"); //Updates the points
                start_button.setVisibility(View.INVISIBLE); //Sets the start button to invisible
                nextTurn(); //Runs the next turn
                timer.start(); //Starts the timer
            }
        };

        View.OnClickListener answerButtonClickListener = new View.OnClickListener() { //Answer button click listener
            @Override
            public void onClick(View v) { //Handles on click
                Button buttonClicked = (Button) v; //Sets the view to the button
                int answerSelected = Integer.parseInt(buttonClicked.getText().toString()); //Gets the selected answer
                g.checkAnswer(answerSelected); //Checks if its correct
                tv_score.setText(Integer.toString(g.getScore()) + " Points"); //Updates the points
                nextTurn(); //Runs the next turn
            }
        };
        //Sets the click listener to all the answer buttons
        btn_start.setOnClickListener(startButtonClickListener);
        btn_ans_1.setOnClickListener(answerButtonClickListener);
        btn_ans_2.setOnClickListener(answerButtonClickListener);
        btn_ans_3.setOnClickListener(answerButtonClickListener);
        btn_ans_4.setOnClickListener(answerButtonClickListener);
    }

    //Next turn function
    private void nextTurn() {
        g.makeNewQuestion(); //Makes a new question
        int[] answer = g.getCurrentQuestion().getAnswerArray(); //Sets all possible answers into an array
        btn_ans_1.setText(Integer.toString(answer[0])); //Sets the text of the button to an answer
        btn_ans_2.setText(Integer.toString(answer[1])); //Sets the text of the button to an answer
        btn_ans_3.setText(Integer.toString(answer[2])); //Sets the text of the button to an answer
        btn_ans_4.setText(Integer.toString(answer[3])); //Sets the text of the button to an answer
        btn_ans_1.setEnabled(true); //Enables answer button
        btn_ans_2.setEnabled(true); //Enables answer button
        btn_ans_3.setEnabled(true); //Enables answer button
        btn_ans_4.setEnabled(true); //Enables answer button
        tv_questions.setText(g.getCurrentQuestion().getQuestionPhrase()); //Outputs the next question
        tv_output.setText(g.getNumberCorrect() + "/" + (g.getTotalQuestions() - 1)); //Outputs the score
    }
}
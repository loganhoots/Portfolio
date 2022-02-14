package com.example.activity_1_jokes_application;

//Imports
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

//Main Class
public class MainActivity extends AppCompatActivity {

    //Define Variables
    Button btn_joke1, btn_joke2, btn_joke3, btn_joke4, btn_joke5, btn_joke6;
    TextView tv_message;

    @Override
    //Create Function
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Declare the variables
        btn_joke1 = findViewById(R.id.btn_joke1);
        btn_joke2 = findViewById(R.id.btn_joke2);
        btn_joke3 = findViewById(R.id.btn_joke3);
        btn_joke4 = findViewById(R.id.btn_joke4);
        btn_joke5 = findViewById(R.id.btn_joke5);
        btn_joke6 = findViewById(R.id.btn_joke6);
        tv_message = findViewById(R.id.tv_message);

        //Joke 1 Button Handler
        btn_joke1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //Toast Output line
                Toast.makeText(MainActivity.this, "To get to the other side", Toast.LENGTH_SHORT).show();
            }
        });

        //Joke 2 Button Handler
        btn_joke2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //Toast Output Line
                Toast.makeText(MainActivity.this, "Bison", Toast.LENGTH_SHORT).show();
            }
        });

        //Joke 3 Button Handler
        btn_joke3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //Toast Output Line
                Toast.makeText(MainActivity.this, "Red Paint", Toast.LENGTH_SHORT).show();
            }
        });

        //Jokes 4 5 and 6 will use the TextView to display the answer
        //Joke 4 Button Handler
        btn_joke4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_message.setText("B"); //TextView Output
            }
        });

        //Joke 5 Button Handler
        btn_joke5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_message.setText("I'm just very relaxed."); //TextView Output
            }
        });

        //Joke 6 Button Handler
        btn_joke6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_message.setText("Hahahahahaha"); //TextView Output
            }
        });
    }
}
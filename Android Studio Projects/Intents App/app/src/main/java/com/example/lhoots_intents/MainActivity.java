package com.example.lhoots_intents;

//Import Libraries
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

//Declare Main Activity Class
public class MainActivity extends AppCompatActivity {

    //Declare Variables
    Button button;

    //onCreate Function
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = findViewById(R.id.button); //Sets button id
        button.setOnClickListener(new View.OnClickListener() { //Click Listener for button
            @Override
            public void onClick(View v) { //On Click
                Intent goToPageTwo = new Intent(getApplicationContext(), page_2.class); //Sets an intent of next page
                startActivity(goToPageTwo); //Switches to next activity
            }
        });
    }
}
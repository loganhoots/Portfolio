package com.example.lhoots_lifecycle_app;

//Import Libraries
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.os.PersistableBundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

//Declare Main Activity Class
public class MainActivity extends AppCompatActivity {

    //Declare Variables
    Button btn_clicker;
    TextView tv_counter;
    int clicks = 0;

    //On Saved Instance Function
    @Override
    protected void onSaveInstanceState(@NonNull Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putInt("clicker_value", clicks); //Stores the clicks values
    }

    //On Restore Instance Function
    @Override
    protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        clicks = savedInstanceState.getInt("clicker_value"); //Restores clicks value
        tv_counter = findViewById(R.id.tv_counter); //Finds the counter ID
        tv_counter.setText(Integer.toString(clicks)); //Sets the counter to the clicks value
    }

    //On Start Function
    @Override
    protected void onStart() {
        super.onStart();
        Log.d("lifecycle_filter", "The app is started."); //Logs the app started
    }

    //On Stop Function
    @Override
    protected void onStop() {
        super.onStop();
        Log.d("lifecycle_filter", "The app is stopped."); //Logs the app stopped
    }

    //On Destroy Function
    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.d("lifecycle_filter", "The app is destroy."); //Logs the app destroyed
    }

    //On Pause Function
    @Override
    protected void onPause() {
        super.onPause();
        Log.d("lifecycle_filter", "The app is paused."); //Logs the app paused
    }

    //On Resume Function
    @Override
    protected void onResume() {
        super.onResume();
        Log.d("lifecycle_filter", "The app is resume."); //Logs the app resumed
    }

    //On Restart Function
    @Override
    protected void onRestart() {
        super.onRestart();
        Log.d("lifecycle_filter", "The app is restarted."); //Logs the app restarted
    }

    //On Create Function
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.d("lifecycle_filter", "The app is created."); //Logs the app created

        //Sets ID's for variables
        btn_clicker = findViewById(R.id.btn_clicker);
        tv_counter = findViewById(R.id.tv_counter);

        //On Click Listener for button
        btn_clicker.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                clicks++; //Increments clicks
                tv_counter.setText(Integer.toString(clicks)); //Outputs clicks
            }
        });
    }
}
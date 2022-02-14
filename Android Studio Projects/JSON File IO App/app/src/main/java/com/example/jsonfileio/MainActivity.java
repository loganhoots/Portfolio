package com.example.jsonfileio;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    Button btn_load, btn_save, btn_addCar, btn_clearList, btn_fourCars;
    TextView tv_output;
    CarList list = new CarList();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn_load = findViewById(R.id.btn_load);
        btn_save = findViewById(R.id.btn_save);
        tv_output = findViewById(R.id.tv_output);
        btn_addCar = findViewById(R.id.btn_addCar);
        btn_clearList = findViewById(R.id.btn_clearList);
        btn_fourCars = findViewById(R.id.btn_fourCars);

        tv_output.setText(list.toString());

        btn_addCar.setOnClickListener((v) -> {
            Car c1 = new Car(2010, "Corvette");
            list.getCarList().add(c1);
            Toast.makeText(this, "Added " + c1.toString(), Toast.LENGTH_SHORT).show();
            tv_output.setText(list.toString());
        });

        btn_fourCars.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Car c1 = new Car(2020, "Ford");
                Car c2 = new Car(1993, "Chevy");
                Car c3 = new Car(1982, "Dodge");
                Car c4 = new Car(2019, "Buick");
                list.getCarList().add(c1);
                list.getCarList().add(c2);
                list.getCarList().add(c3);
                list.getCarList().add(c4);
                tv_output.setText(list.toString());
            }
        });

        btn_clearList.setOnClickListener((v) -> {
            list.setCarList(new ArrayList<Car>());
            tv_output.setText(list.toString());
        });

        btn_save.setOnClickListener((v) -> {
            DataService dataService = new DataService(v.getContext());
            dataService.writeList(list, "cars.txt");
        });

        btn_load.setOnClickListener((v) -> {
            DataService dataService = new DataService(v.getContext());
            list = dataService.readList("cars.txt");
            tv_output.setText(list.toString());
        });
    }
}
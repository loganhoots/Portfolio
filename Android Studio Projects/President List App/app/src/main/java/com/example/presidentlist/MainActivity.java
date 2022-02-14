package com.example.presidentlist;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    Button btn_addOne;
    Menu menu;
    MyApplication myApplication = (MyApplication) this.getApplication();
    List<President> presidentList;

    private RecyclerView recyclerView;
    private RecyclerView.Adapter mAdapter;
    private RecyclerView.LayoutManager layoutManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        presidentList = myApplication.getPresidentList();

        btn_addOne = findViewById(R.id.btn_addOne);

        btn_addOne.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, AddEditOne.class);
                startActivity(intent);
            }
        });

        recyclerView = findViewById(R.id.lv_presidentList);
        recyclerView.setHasFixedSize(true);
        layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        mAdapter = new RecycleViewAdapter(presidentList, this);
        recyclerView.setAdapter(mAdapter);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.sort_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch(item.getItemId()) {
            case R.id.menu_A_Z:
                Collections.sort(presidentList, President.PresidentNameAZComparator);
                Toast.makeText(MainActivity.this, "Sort From A to Z", Toast.LENGTH_SHORT).show();
                break;
            case R.id.menu_Z_A:
                Collections.sort(presidentList, President.PresidentNameZAComparator);
                Toast.makeText(MainActivity.this, "Sort From Z to A", Toast.LENGTH_SHORT).show();
                break;
            case R.id.menu_date_ascend:
                Collections.sort(presidentList, President.PresidentNameDateAscendingComparator);
                Toast.makeText(MainActivity.this, "Sort by date in ascending order", Toast.LENGTH_SHORT).show();
                break;
            case R.id.menu_date_descend:
                Collections.sort(presidentList, President.PresidentNameDateDescendingComparator);
                Toast.makeText(MainActivity.this, "Sort by date in descending order", Toast.LENGTH_SHORT).show();
                break;
            default:
                return super.onOptionsItemSelected(item);
        }
        mAdapter.notifyDataSetChanged();
        return true;
    }
}
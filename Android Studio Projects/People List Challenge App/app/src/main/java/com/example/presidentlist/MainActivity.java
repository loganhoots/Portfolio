package com.example.presidentlist;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.util.Collections;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    Button btn_addOne;
    Menu menu;
    MyApplication myApplication = (MyApplication) this.getApplication();
    List<Contact> contactList;

    private RecyclerView recyclerView;
    private RecyclerView.Adapter mAdapter;
    private RecyclerView.LayoutManager layoutManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        contactList = myApplication.getContactList();

        btn_addOne = findViewById(R.id.btn_new_contact);

        btn_addOne.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, AddEditOne.class);
                startActivity(intent);
            }
        });

        recyclerView = findViewById(R.id.lv_contact_list);
        recyclerView.setHasFixedSize(true);
        layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        mAdapter = new RecycleViewAdapter(contactList, this);
        recyclerView.setAdapter(mAdapter);
        mAdapter.notifyDataSetChanged();
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
                Collections.sort(contactList, Contact.PresidentNameAZComparator);
                Toast.makeText(MainActivity.this, "Sort From A to Z", Toast.LENGTH_SHORT).show();
                break;
            case R.id.menu_Z_A:
                Collections.sort(contactList, Contact.PresidentNameZAComparator);
                Toast.makeText(MainActivity.this, "Sort From Z to A", Toast.LENGTH_SHORT).show();
                break;
            default:
                return super.onOptionsItemSelected(item);
        }
        mAdapter.notifyDataSetChanged();
        return true;
    }
}
package com.example.presidentlist;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import org.w3c.dom.Text;
import java.util.List;

public class AddEditOne extends AppCompatActivity {

    Button btn_ok, btn_cancel;
    List<President> presidentList;
    EditText et_presidentDate, et_presidentName, et_presidentURL;
    MyApplication myApplication = (MyApplication) this.getApplication();
    TextView tv_presidentID;
    int id;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_edit_one);

        presidentList = myApplication.getPresidentList();

        btn_ok = findViewById(R.id.btn_ok);
        btn_cancel = findViewById(R.id.btn_cancel);
        et_presidentDate = findViewById(R.id.et_dateElection);
        et_presidentName = findViewById(R.id.et_presidentName);
        et_presidentURL = findViewById(R.id.et_pictureURL);
        tv_presidentID = findViewById(R.id.tv_presidentIDNumber);

        Intent intent = getIntent();
        id = intent.getIntExtra("id", -1);
        President president = null;

        if (id >= 0)  {
            for(President p: presidentList) {
                if (p.getId() == id) {
                    president = p;
                }
            }
            et_presidentName.setText(president.getName());
            et_presidentDate.setText(String.valueOf(president.getDateOfElection()));
            et_presidentURL.setText(president.getImageURL());
            tv_presidentID.setText(String.valueOf(id));
        }
        else {

        }

        btn_ok.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (id >= 0) {
                    President updatedPresident = new President(id, et_presidentName.getText().toString(), Integer.parseInt(et_presidentDate.getText().toString()), et_presidentURL.getText().toString());
                    presidentList.set(id, updatedPresident);
                }
                else {
                    int nextID = myApplication.getNextID();
                    President newPresident = new President(nextID, et_presidentName.getText().toString(), Integer.parseInt(et_presidentDate.getText().toString()), et_presidentURL.getText().toString());
                    presidentList.add(newPresident);
                    myApplication.setNextID(nextID++);
                }
                Intent intent = new Intent(AddEditOne.this, MainActivity.class);
                startActivity(intent);
            }
        });

        btn_cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(AddEditOne.this, MainActivity.class);
                startActivity(intent);
            }
        });
    }
}
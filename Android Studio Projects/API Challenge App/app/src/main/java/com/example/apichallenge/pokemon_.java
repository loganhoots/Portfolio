package com.example.apichallenge;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import com.bumptech.glide.Glide;
import java.util.ArrayList;
import java.util.List;

public class pokemon_ extends AppCompatActivity {

    Button btn_back;
    TextView tv_name, tv_id, tv_height, tv_weight, tv_type_1, tv_type_2, tv_hp, tv_atk, tv_def, tv_satk, tv_sdef, tv_spd;
    ImageView iv_image;
    ListView move_list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pokemon_);

        Bundle bundle = getIntent().getExtras();

        btn_back = findViewById(R.id.btn_back);
        tv_name = findViewById(R.id.tv_name);
        tv_id = findViewById(R.id.tv_id);
        iv_image = findViewById(R.id.iv_image);
        tv_height = findViewById(R.id.tv_height);
        tv_weight = findViewById(R.id.tv_weight);
        tv_type_1 = findViewById(R.id.tv_type_1);
        tv_type_2 = findViewById(R.id.tv_type_2);
        tv_hp = findViewById(R.id.tv_hp);
        tv_atk = findViewById(R.id.tv_atk);
        tv_def = findViewById(R.id.tv_def);
        tv_satk = findViewById(R.id.tv_satk);
        tv_sdef = findViewById(R.id.tv_sdef);
        tv_spd = findViewById(R.id.tv_spd);
        move_list = findViewById(R.id.lv_moves);

        tv_name.setText(bundle.getString("p_name"));
        tv_id.setText(String.valueOf(bundle.getInt("p_id")));
        Glide.with(pokemon_.this).load(bundle.getString("p_image")).into(iv_image);
        tv_height.setText(String.valueOf(bundle.getInt("p_height")));
        tv_weight.setText(String.valueOf(bundle.getInt("p_weight")));
        tv_type_1.setText(bundle.getString("p_type_1"));
        tv_type_2.setText(bundle.getString("p_type_2"));
        tv_hp.setText(String.valueOf(bundle.getInt("p_hp")));
        tv_atk.setText(String.valueOf(bundle.getInt("p_atk")));
        tv_def.setText(String.valueOf(bundle.getInt("p_def")));
        tv_satk.setText(String.valueOf(bundle.getInt("p_satk")));
        tv_sdef.setText(String.valueOf(bundle.getInt("p_sdef")));
        tv_spd.setText(String.valueOf(bundle.getInt("p_spd")));

        List<String> move_strings = new ArrayList<>();
        move_strings.addAll((ArrayList<String>) bundle.getSerializable("p_moves"));

        ArrayAdapter arrayAdapter = new ArrayAdapter(pokemon_.this, android.R.layout.simple_list_item_1, move_strings);
        //Toast.makeText(this, move_strings.get(0), Toast.LENGTH_SHORT).show();
        move_list.setAdapter(arrayAdapter);

        btn_back.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(pokemon_.this, MainActivity.class);
                startActivity(intent);
            }
        });
    }
}
package com.example.apichallenge;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import java.io.Serializable;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    Button btn_search;
    EditText et_input;

    PokemonModel pokemonModel_ = new PokemonModel();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn_search = findViewById(R.id.btn_search);
        et_input = findViewById(R.id.et_input);

        final PokemonDataService pokemonDataService = new PokemonDataService(MainActivity.this);

        btn_search.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (et_input.getText().toString().equals("")) { et_input.setText("Error"); }
                pokemonDataService.query(et_input.getText().toString(), new PokemonDataService.VolleyResponseListener() {
                    @Override
                    public void onError(String Message) { Toast.makeText(MainActivity.this, "Error", Toast.LENGTH_SHORT).show(); }

                    @Override
                    public void onResponse(List<PokemonModel> pokemonModels) {
                        pokemonModel_ = pokemonModels.get(0);
                        Intent intent = new Intent(MainActivity.this, pokemon_.class);
                        intent.putExtra("p_name", pokemonModel_.getName());
                        intent.putExtra("p_id", pokemonModel_.getId());
                        intent.putExtra("p_image", pokemonModel_.getImageURL());
                        intent.putExtra("p_height", pokemonModel_.getHeight());
                        intent.putExtra("p_weight", pokemonModel_.getWeight());
                        intent.putExtra("p_type_1", pokemonModel_.getType1());
                        intent.putExtra("p_type_2", pokemonModel_.getType2());
                        intent.putExtra("p_hp", pokemonModel_.getHp());
                        intent.putExtra("p_atk", pokemonModel_.getAttack());
                        intent.putExtra("p_def", pokemonModel_.getDefense());
                        intent.putExtra("p_satk", pokemonModel_.getsAttack());
                        intent.putExtra("p_sdef", pokemonModel_.getsDefense());
                        intent.putExtra("p_spd", pokemonModel_.getSpeed());
                        intent.putExtra("p_moves", (Serializable) pokemonModel_.getMoves());
                        startActivity(intent);
                    }
                });
            }
        });
    }
}
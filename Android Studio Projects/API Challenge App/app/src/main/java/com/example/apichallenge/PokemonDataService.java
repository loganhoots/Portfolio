package com.example.apichallenge;

import android.content.Context;
import com.android.volley.Request;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import java.util.ArrayList;
import java.util.List;

public class PokemonDataService {
    public static final String QUERY_FOR_POKEMON = "https://www.pokeapi.co/api/v2/pokemon/";
    Context context;

    public PokemonDataService(Context context) { this.context = context; }

    public interface VolleyResponseListener {
        void onError(String Message);
        void onResponse(List<PokemonModel> pokemonModels);
    }

    public void query(String pokemonID, VolleyResponseListener volleyResponseListener) {
        List<PokemonModel> pokemonModels = new ArrayList<>();
        String url = QUERY_FOR_POKEMON + pokemonID;
        JsonObjectRequest request = new JsonObjectRequest(Request.Method.GET, url, null, new Response.Listener<JSONObject>() {
            @Override
            public void onResponse(JSONObject response) {
                try {
                    PokemonModel pokemonModel = new PokemonModel();

                    pokemonModel.setName(response.getString("name"));
                    pokemonModel.setId(response.getInt("id"));

                    JSONObject temp = (JSONObject) response.getJSONObject("sprites");
                    pokemonModel.setImageURL(temp.getString("front_default"));

                    pokemonModel.setHeight(response.getInt("height"));
                    pokemonModel.setWeight(response.getInt("weight"));

                    JSONArray pokemonInfo = response.getJSONArray("types");
                    if (pokemonInfo.length() == 2) {
                        temp = (JSONObject) pokemonInfo.get(0);
                        pokemonModel.setType1(temp.getJSONObject("type").getString("name"));
                        temp = (JSONObject) pokemonInfo.get(1);
                        pokemonModel.setType2(temp.getJSONObject("type").getString("name"));
                    }
                    else {
                        temp = (JSONObject) pokemonInfo.get(0);
                        pokemonModel.setType1(temp.getJSONObject("type").getString("name"));
                    }

                    pokemonInfo = response.getJSONArray("stats");
                    temp = (JSONObject) pokemonInfo.get(0);
                    pokemonModel.setHp(temp.getInt("base_stat"));

                    temp = (JSONObject) pokemonInfo.get(1);
                    pokemonModel.setAttack(temp.getInt("base_stat"));

                    temp = (JSONObject) pokemonInfo.get(2);
                    pokemonModel.setDefense(temp.getInt("base_stat"));

                    temp = (JSONObject) pokemonInfo.get(3);
                    pokemonModel.setsAttack(temp.getInt("base_stat"));

                    temp = (JSONObject) pokemonInfo.get(4);
                    pokemonModel.setsDefense(temp.getInt("base_stat"));

                    temp = (JSONObject) pokemonInfo.get(5);
                    pokemonModel.setSpeed(temp.getInt("base_stat"));

                    List<String> tempStrList = new ArrayList<>();
                    pokemonInfo = response.getJSONArray("moves");
                    for (int i = 0; i < pokemonInfo.length() - 1; i++) {
                        temp = (JSONObject) pokemonInfo.get(i);
                        tempStrList.add(temp.getJSONObject("move").getString("name"));
                    }
                    pokemonModel.setMoves(tempStrList);
                    pokemonModels.add(pokemonModel);
                } catch (JSONException e) { e.printStackTrace(); }
                volleyResponseListener.onResponse(pokemonModels);
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) { volleyResponseListener.onError("Error"); }
        });
        pokemonSingleton.getInstance(context).addToRequestQueue(request);
    }
}

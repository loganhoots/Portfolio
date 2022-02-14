package com.example.apichallenge;

import android.content.Context;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.Volley;

public class pokemonSingleton {
    private static pokemonSingleton instance;
    private RequestQueue requestQueue;
    private static Context ctx;

    private pokemonSingleton(Context context) {
        ctx = context;
        requestQueue = getRequestQueue();
    }

    public static synchronized pokemonSingleton getInstance(Context context) {
        if (instance == null) {
            instance = new pokemonSingleton(context);
        }
        return instance;
    }

    public RequestQueue getRequestQueue() {
        if (requestQueue == null) {
            requestQueue = Volley.newRequestQueue(ctx.getApplicationContext());
        }
        return requestQueue;
    }

    public <T> void addToRequestQueue(Request<T> req) { getRequestQueue().add(req); }
}

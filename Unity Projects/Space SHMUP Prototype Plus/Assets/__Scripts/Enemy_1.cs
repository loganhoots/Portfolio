using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy_1 : Enemy {
    [Header("Set in Inspector: Enemy_1")]
    public float waveFrequency = 2f;
    public float waveWidth = 4f;
    public float waveRotY = 45f;
    public float x0;
    public float birthTime;

    // Start is called before the first frame update
    void Start() {
        x0 = pos.x;
        birthTime = Time.time;
    }

    void Move() {

    }

    // Update is called once per frame
    void Update()
    {
        
    }
}

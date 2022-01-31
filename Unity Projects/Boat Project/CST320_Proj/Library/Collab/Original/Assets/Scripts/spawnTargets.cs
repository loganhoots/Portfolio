using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class spawnTargets : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject crate; 
    public int numberOfCrates;
    void Start()
    {
        float x,y,z;

      
        for(int i = 0; i<=numberOfCrates; i++)
        {
            x = Random.Range(-80,80);
            y = Random.Range(3,40);
            z = Random.Range(-100,-60);

            Instantiate(crate, new Vector3(x, y, z), Quaternion.identity);
        }
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class towerPlacement : MonoBehaviour
{
    float maxDistance = 100;
    public GameObject hit_;
    public GameObject GameLogic;

    private GameObject[] turrets;
    float distanceToTurret;
    float temp = 4f;
    public float distanceToPlace = 3f;
    public GameObject player;

    public int tower1Cost = 10;
    public int tower2Cost = 20;
    public int tower3Cost = 15;

    void Start() {
        GameLogic = GameObject.Find("Game Manager");
        turrets = GameObject.FindGameObjectsWithTag("pedistal");
    }

    // Update is called once per frame
    void Update() {
        for (int i = 0; i < turrets.Length; i++)
        {
            distanceToTurret = Vector3.Distance(turrets[i].transform.position, player.transform.position);
            if (distanceToTurret < temp)
            {
                temp = distanceToTurret;
                hit_ = turrets[i];
            }
        }
        if (temp <= distanceToPlace)
        {
            if (hit_ != null && !hit_.GetComponent<pedistal>().hasTower)
            {
                if (Input.GetKeyDown("e"))
                {
                    hit_.GetComponent<pedistal>().placeTower();
                }
            }
        }
        temp = 4f;
    }
}

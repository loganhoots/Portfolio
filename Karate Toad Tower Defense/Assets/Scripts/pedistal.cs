using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class pedistal : MonoBehaviour {
    public GameObject tower1Prefab;
    public GameObject tower2Prefab;
    public GameObject tower3Prefab;
    public bool hasTower = false;

    public GameObject UI;
    private Transform location;

    public GameObject GameLogic;

    public Text turret_text;
    public Text sniper_text;
    public Text aoe_text;

    void Start() {
        GameLogic = GameObject.Find("Game Manager");
    }

    void Update() {
        if (GameObject.Find("Main Camera").GetComponent<towerPlacement>().hit_ != null)
            location = GameObject.Find("Main Camera").GetComponent<towerPlacement>().hit_.transform;
        turret_text.text = "Turret - " + GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower1Cost.ToString();
        sniper_text.text = "Sniper - " + GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower2Cost.ToString();
        aoe_text.text = "Frost Machine - " + GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower3Cost.ToString();
    }

    public void placeTower() {
        Cursor.lockState = CursorLockMode.None;
        Time.timeScale = 0;
        UI.SetActive(true);
    }

    public void exit() {
        Cursor.lockState = CursorLockMode.Locked;
        Time.timeScale = 1;
        GameObject.Find("Main Camera").GetComponent<towerPlacement>().hit_.GetComponent<pedistal>().hasTower = true;
        UI.SetActive(false);
    }

    public void turret() {
        if (GameLogic.GetComponent<Logic>().money >= GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower1Cost)
        {
            Vector3 pos = new Vector3(location.position.x, 2.25f, location.position.z);
            GameLogic.GetComponent<Logic>().money -= GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower1Cost;
            Instantiate(tower1Prefab, pos, location.rotation, location);
            GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower1Cost += 10;
            exit();
        }
    }

    public void sniper() {
        if (GameLogic.GetComponent<Logic>().money >= GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower2Cost)
        {
            GameLogic.GetComponent<Logic>().money -= GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower2Cost;
            Vector3 pos = new Vector3(location.position.x, 1.5f, location.position.z);
            Instantiate(tower2Prefab, pos, location.rotation, location);
            GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower2Cost += 20;
            exit();
        }
    }

    public void aoe() {
        if (GameLogic.GetComponent<Logic>().money >= GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower3Cost)
        {
            GameLogic.GetComponent<Logic>().money -= GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower3Cost;
            Vector3 pos = new Vector3(location.position.x, 2f, location.position.z);
            Instantiate(tower3Prefab, pos, location.rotation, location);
            GameObject.Find("Main Camera").GetComponent<towerPlacement>().tower3Cost += 15;
            exit();
        }
    }

    public void quit() {
        Cursor.lockState = CursorLockMode.Locked;
        Time.timeScale = 1;
        UI.SetActive(false);
    }
}

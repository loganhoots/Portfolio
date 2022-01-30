using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using SimpleBarExample;

public class Logic : MonoBehaviour {
    public int numberOfLives = 1;
    public int winningRound = 4;
    public GameObject inGameUICanvas;
    public GameObject PauseUICanvas;
    public GameObject GameoverUICanvas;
    public GameObject WinUICanvas;
    public GameObject StartUICanvas;

    private int round = 0;
    public int money = 0;
    private int exp = 0;
    public int player_level = 1;
    private Text money_text;
    private Text lives_text;
    private Text round_text;
    private Text player_level_text;
    private GameObject spiderSpawner;
    public GameObject XPBar;

    public bool cont = false;

    void Start() {
        spiderSpawner = GameObject.Find("GameMaster");
        money_text = GameObject.Find("Money Counter Text").GetComponent<Text>();
        lives_text = GameObject.Find("Lives Counter Text").GetComponent<Text>();
        round_text = GameObject.Find("Round Counter Text").GetComponent<Text>();
        player_level_text = GameObject.Find("Player Level Counter Text").GetComponent<Text>();
    }

    public void increaseMoney(int addMoney)
    {
        money += addMoney;
    }

    void Update() {
        // Update money variable based on kills
        money_text.text = money.ToString();
        lives_text.text = numberOfLives.ToString();
        round_text.text = round.ToString();
        player_level_text.text = player_level.ToString();
    }

    void FixedUpdate() {
        player_level = XPBar.GetComponent<DemoBarAnimator>().level;
        round = spiderSpawner.GetComponent<NewWaveSpawner>().waveIndex;
        if (numberOfLives <= 0) {
            Time.timeScale = 0;
            inGameUICanvas.SetActive(false);
            PauseUICanvas.SetActive(false);
            GameoverUICanvas.SetActive(true);
            Cursor.lockState = CursorLockMode.None;
        }
        else if (round >= winningRound && !cont) {
            //win
            Time.timeScale = 0;
            inGameUICanvas.SetActive(false);
            PauseUICanvas.SetActive(false);
            StartUICanvas.SetActive(false);
            WinUICanvas.SetActive(true);
        }
        else {
            
        }
    }

    void OnCollisionEnter(Collision coll) {
        if (coll.gameObject.tag == "Enemy") {
            NewWaveSpawner.EnemiesAlive--;
            numberOfLives--;
            Destroy(coll.gameObject);
            
        }
    }
}

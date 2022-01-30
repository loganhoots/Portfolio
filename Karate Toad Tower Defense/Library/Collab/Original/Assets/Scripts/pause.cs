using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class pause : MonoBehaviour {
    public GameObject pause_button;
    public GameObject inGameUICanvas;
    public GameObject inPauseUICanvas;
    public Sprite clicked;
    public Sprite not_clicked;
    public Text speed;
    public GameObject startUICanvas;

    private float half_time = 0.75f;
    private float full_time = 1f;

    void Start() {
        startUICanvas.SetActive(true);
        inGameUICanvas.GetComponent<CanvasGroup>().alpha = 0;
        inGameUICanvas.GetComponent<CanvasGroup>().interactable = false;
        Time.timeScale = 0;
    }

    public void startClick() {
        startUICanvas.SetActive(false);
        inGameUICanvas.GetComponent<CanvasGroup>().alpha = 1;
        inGameUICanvas.GetComponent<CanvasGroup>().interactable = true;
        Time.timeScale = 1;
    }

    public void update_speed() {
        if (Time.timeScale == 1) {
            Time.timeScale = half_time;
            speed.text = half_time.ToString() + "X";
        }
        else {
            Time.timeScale = full_time;
            speed.text = full_time.ToString() + "X";
        }
    }

    public void pause_click() {
        inPauseUICanvas.SetActive(true);
        inGameUICanvas.SetActive(false);
        Time.timeScale = 0;
    }

    public void resume_click() {
        inGameUICanvas.SetActive(true);
        inPauseUICanvas.SetActive(false);
        update_speed();
    }

    public void quit_click() {
        // save any game data here
        #if UNITY_EDITOR
            // Application.Quit() does not work in the editor so
            // UnityEditor.EditorApplication.isPlaying need to be set to false to end the game
            UnityEditor.EditorApplication.isPlaying = false;
        #else
            Application.Quit();
        #endif
    }

    void Update() {
        if (inGameUICanvas.GetComponent<CanvasGroup>().interactable && Input.GetKey(KeyCode.Escape) && (Input.GetKeyUp(KeyCode.Escape) || Input.GetKeyDown(KeyCode.Escape))) {
            if (inGameUICanvas.activeSelf == true) pause_click();
            else resume_click();
        }
    }
}

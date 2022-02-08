using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class PotionHandler : MonoBehaviour
{
    public SpriteRenderer ph1, ph2, ph3, ph4;
    public Sprite fh;
    public float MoveTime = 5.0f;
    Vector3[] locations = new Vector3[9] { new Vector3(-8.5f, 4.5f, 0f), new Vector3(-8.5f, -4.5f, 0f) , new Vector3(8.5f, 4.5f, 0f),
        new Vector3(8.5f, -4.5f, 0f), new Vector3(2.5f, 4.5f, 0f), new Vector3(-2.5f, 4.5f, 0f), new Vector3(-1.5f, -4.5f, 0f),
        new Vector3(1.5f, -4.5f, 0f), new Vector3(0f, 0f, 0f) };
    public GameObject potion_UI, potion, player;
    private bool spawn = true;
    public bool has_potion = false;
    private int p_health = 4;

    // Start is called before the first frame update
    void Start()
    {
        p_health = PlayerPrefs.GetInt("health", 4);
        if (PlayerPrefs.GetInt("has_potion", 0) == 1)
        {
            has_potion = true;
            potion_UI.GetComponent<SpriteRenderer>().enabled = true;
            potion.GetComponent<SpriteRenderer>().enabled = false;
        }
        else
        {
            has_potion = false;
            potion_UI.GetComponent<SpriteRenderer>().enabled = false;
            potion.GetComponent<SpriteRenderer>().enabled = true;
        }
    }

    void Update()
    {
        if (has_potion && Input.GetMouseButtonDown(1))
        {
            potion.GetComponent<SpriteRenderer>().enabled = false;
            potion_UI.GetComponent<SpriteRenderer>().enabled = false;

            p_health = 4;
            ph1.sprite = fh;
            ph2.sprite = fh;
            ph3.sprite = fh;
            ph4.sprite = fh;
            Debug.Log("Health Time");
            if (SceneManager.GetActiveScene().buildIndex == 3) { player.GetComponent<PlayerMovementHealth>().p_health = 4; }
            if (SceneManager.GetActiveScene().buildIndex == 0) { player.GetComponent<PlayerMovement>().p_health = 4; }
            has_potion = false;
        }
    }

    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject == player)
        {
            has_potion = true;
            potion_UI.GetComponent<SpriteRenderer>().enabled = true;
            potion.GetComponent<SpriteRenderer>().enabled = false;
        }
    }
}

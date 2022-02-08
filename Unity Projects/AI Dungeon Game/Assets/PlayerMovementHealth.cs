using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class PlayerMovementHealth : MonoBehaviour
{
    public SpriteRenderer ph1, ph2, ph3, ph4;
    public Sprite fh, eh;

    public float moveSpeed = 5f;
    int coins, temp;
    public Rigidbody2D rb;
    public Animator animator;
    Vector2 movement;
    public int p_health;

    public Camera cam;
    Vector3 cam_pos;
    public GameObject player, coinSpawning, key_handler, potion_handler; 

    void Start()
    {
        if (PlayerPrefs.GetInt("has_key", 0) == 1)
        {
            key_handler.GetComponent<key_handler>().has_key = true;
            key_handler.GetComponent<key_handler>().key_UI.GetComponent<SpriteRenderer>().enabled = true;
        }
        else
        {
            key_handler.GetComponent<key_handler>().has_key = false;
            key_handler.GetComponent<key_handler>().key_UI.GetComponent<SpriteRenderer>().enabled = false;
        }

        if (PlayerPrefs.GetInt("has_potion", 0) == 1)
        {
            potion_handler.GetComponent<PotionHandler>().has_potion = true;
            potion_handler.GetComponent<PotionHandler>().potion_UI.GetComponent<SpriteRenderer>().enabled = true;
        }
        else
        {
            potion_handler.GetComponent<PotionHandler>().has_potion = false;
            potion_handler.GetComponent<PotionHandler>().potion_UI.GetComponent<SpriteRenderer>().enabled = false;
        }

        coinSpawning.GetComponent<Coin>().amount = PlayerPrefs.GetInt("coins", 0);
        coinSpawning.GetComponent<Coin>().coins.text = coinSpawning.GetComponent<Coin>().amount.ToString();
        
        p_health = PlayerPrefs.GetInt("health", 4);
        if (p_health != 4)
        {
            for (int i = 0; i < (4 - p_health); i++)
            {
                switch (i)
                {
                    case 0:
                        ph1.sprite = eh;
                        Debug.Log(p_health);
                        break;
                    case 1:
                        ph2.sprite = eh;
                        Debug.Log(p_health);
                        break;
                    case 2:
                        ph3.sprite = eh;
                        Debug.Log(p_health);
                        break;
                    case 3:
                        ph4.sprite = eh;
                        Debug.Log(p_health);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        //Input
        movement.x = Input.GetAxisRaw("Horizontal");
        movement.y = Input.GetAxisRaw("Vertical");
        animator.SetFloat("Horizontal", movement.x);
        animator.SetFloat("Vertical", movement.y);
        animator.SetFloat("Speed", movement.sqrMagnitude);

        if (player.transform.position.y >= 2.5f)
        {
            if (potion_handler.GetComponent<PotionHandler>().has_potion) { PlayerPrefs.SetInt("has_potion", 1); }
            else { PlayerPrefs.SetInt("has_potion", 0); }
            PlayerPrefs.SetInt("coins", coinSpawning.GetComponent<Coin>().amount);
            PlayerPrefs.SetInt("health", p_health);
            SceneManager.LoadScene(0);
        }
    }

    void FixedUpdate()
    {
        //Movement
        rb.MovePosition(rb.position + movement * moveSpeed * Time.fixedDeltaTime);
        cam_pos = new Vector3(player.transform.position.x, player.transform.position.y, -30);
        cam.transform.position = cam_pos;
    }
}

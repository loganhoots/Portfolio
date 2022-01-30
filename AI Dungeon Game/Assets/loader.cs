using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class loader : MonoBehaviour
{
    public SpriteRenderer ph1, ph2, ph3, ph4;
    public Sprite fh, eh;
    private int p_health = 4, temp;
    private float p_loc_x, p_loc_y;
    public GameObject goblin, player, coinSpawning, key_handler;

    // Start is called before the first frame update

    void Start()
    {
        coinSpawning.GetComponent<Coin>().amount = PlayerPrefs.GetInt("coins", 0);
        coinSpawning.GetComponent<Coin>().coins.text = coinSpawning.GetComponent<Coin>().amount.ToString();
        p_loc_x = PlayerPrefs.GetFloat("p_loc_x", -8.5f);
        p_loc_y = PlayerPrefs.GetFloat("p_loc_y", -4f);
        
        Debug.Log(p_health);
        player.transform.position = new Vector3(p_loc_x, p_loc_y, 0);

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
        if (goblin.GetComponent<Pathfinding.AIPath>().sw)
        {
            if (key_handler.GetComponent<key_handler>().has_key) { PlayerPrefs.SetInt("has_key", 1); }
            else { PlayerPrefs.SetInt("has_key", 0); }
            Debug.Log("Fight Started" + coinSpawning.GetComponent<Coin>().amount);
            PlayerPrefs.SetInt("coins", coinSpawning.GetComponent<Coin>().amount);
            PlayerPrefs.SetFloat("p_loc_x", player.transform.position.x);
            PlayerPrefs.SetFloat("p_loc_y", player.transform.position.y);
            PlayerPrefs.SetInt("health", player.GetComponent<PlayerMovement>().p_health);
            SceneManager.LoadScene(1);
        }
    }
}

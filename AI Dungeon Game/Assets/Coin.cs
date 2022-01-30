using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using UnityEngine.Tilemaps;
using UnityEngine.SceneManagement;

public class Coin : MonoBehaviour
{
    private Vector2 screenBounds;
    public GameObject coin;
    public float respawnTime = 1.0f;
    public Text coins;
    public int amount, temp, coin_room;

    public Tile door_open_bot, door_open_top;
    public Tilemap Wall, Floor;
    Vector3Int location;

    // Start is called before the first frame update
    void Start()
    {
        screenBounds = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, Screen.height, Camera.main.transform.position.z));
        if (SceneManager.GetActiveScene().buildIndex == 4)
        {
            coin_room = 1;
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (amount > 9 && SceneManager.GetActiveScene().buildIndex == 0)
        {
            location = new Vector3Int(-8, 6, 0);
            Wall.SetTile(location, door_open_top);
            location = new Vector3Int(-8, 5, 0);
            Wall.SetTile(location, null);
            Floor.SetTile(location, door_open_bot);
        }
    }

    void OnTriggerEnter2D(Collider2D col)
    {
        //temp = amount;
        if (col.gameObject.tag == "player") {
            amount ++;
            if (SceneManager.GetActiveScene().buildIndex == 4)
            {
                coin_room++;
            }
        }
        coins.text = amount.ToString();
        spawn();
        //Destroy(this.gameObject);
    }

    void spawn()
    {
        if (SceneManager.GetActiveScene().buildIndex == 0)
        { coin.transform.position = new Vector2(Random.Range(-screenBounds.x, screenBounds.x), Random.Range(-screenBounds.y, screenBounds.y)); }
        if (SceneManager.GetActiveScene().buildIndex == 4)
        {
            switch (coin_room) 
            {
                case 2:
                    coin.transform.position = new Vector2(-2f, -1f);
                    break;
                case 3:
                    coin.transform.position = new Vector2(-2f, 1f);
                    break;
                case 4:
                    coin.transform.position = new Vector2(-5f, 0f);
                    coin.GetComponent<SpriteRenderer>().enabled = false;
                    break;
                default:
                    break;
            }
        }
    }
}

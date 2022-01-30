using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.Tilemaps;

public class PlayerMovement : MonoBehaviour
{
    public SpriteRenderer ph1, ph2, ph3, ph4;
    public Sprite fh, eh;

    public float moveSpeed = 5f, door_unlock_percentage = 0.333f, room_percentage;
    public Coin coin;
    private int coins, temp, room;
    public int p_health;
    public Rigidbody2D rb;
    public Animator animator;
    Vector2 movement;

    public Camera cam;
    Vector3 cam_pos;
    public GameObject player, key_handler, coinSpawning, potion_handler;

    Vector3 door_pos = new Vector3(-7.5f, 5.5f, 0f);
    Vector3 door_key_1 = new Vector3(-4.5f, 5.5f, 0f);
    Vector3 door_key_2 = new Vector3(4.5f, 5.5f, 0f);
    Vector3 door_key_3 = new Vector3(7.5f, 5.5f, 0f);

    public Tile door_open_bot, door_open_top;
    public Tilemap Wall, Floor;

    private bool near_door = false;

    void Start() {
        p_health = PlayerPrefs.GetInt("health", 4);
        if (p_health != 4) {
            for (int i = 0; i < (4 - p_health); i++) {
                switch (i) {
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
        if (PlayerPrefs.GetInt("has_key", 0) == 1) {
            key_handler.GetComponent<key_handler>().has_key = true;
            key_handler.GetComponent<key_handler>().key_UI.GetComponent<SpriteRenderer>().enabled = true;
        }
        else { 
            key_handler.GetComponent<key_handler>().has_key = false;
            key_handler.GetComponent<key_handler>().key_UI.GetComponent<SpriteRenderer>().enabled = false;
        }
        if (PlayerPrefs.GetInt("has_potion", 0) == 1) {
            potion_handler.GetComponent<PotionHandler>().has_potion = true;
            potion_handler.GetComponent<PotionHandler>().potion_UI.GetComponent<SpriteRenderer>().enabled = true;
        }
        else {
            potion_handler.GetComponent<PotionHandler>().has_potion = false;
            potion_handler.GetComponent<PotionHandler>().potion_UI.GetComponent<SpriteRenderer>().enabled = false;
        }
        coinSpawning.GetComponent<Coin>().amount = PlayerPrefs.GetInt("coins", 0);
    }

    // Update is called once per frame
    void Update() {
        if (key_handler.GetComponent<key_handler>().has_key && Input.GetMouseButtonDown(0)) {
            if (player.transform.position.y >= (door_key_1.y - 1f) && player.transform.position.x <= (door_key_1.x + 0.5) && player.transform.position.x >= (door_key_1.x - 0.5)) {
                near_door = true;
                if (Random.Range(0.0f, 1.0f) <= door_unlock_percentage) {
                    Wall.SetTile(new Vector3Int(-5, 6, 0), door_open_top);
                    Wall.SetTile(new Vector3Int(-5, 5, 0), null);
                    Floor.SetTile(new Vector3Int(-5, 5, 0), door_open_bot);
                }
                else { Debug.Log("The Key Broke"); }
            }
            else if (player.transform.position.y >= (door_key_2.y - 1f) && player.transform.position.x <= (door_key_2.x + 0.5) && player.transform.position.x >= (door_key_2.x - 0.5)) {
                near_door = true;
                if (Random.Range(0.0f, 1.0f) <= door_unlock_percentage) {
                    Wall.SetTile(new Vector3Int(4, 6, 0), door_open_top);
                    Wall.SetTile(new Vector3Int(4, 5, 0), null);
                    Floor.SetTile(new Vector3Int(4, 5, 0), door_open_bot);
                }
                else { Debug.Log("The Key Broke"); }
            }
            else if (player.transform.position.y >= (door_key_3.y - 1f) && player.transform.position.x <= (door_key_3.x + 0.5) && player.transform.position.x >= (door_key_3.x - 0.5)) {
                near_door = true;
                if (Random.Range(0.0f, 1.0f) <= door_unlock_percentage) {
                    Wall.SetTile(new Vector3Int(7, 6, 0), door_open_top);
                    Wall.SetTile(new Vector3Int(7, 5, 0), null);
                    Floor.SetTile(new Vector3Int(7, 5, 0), door_open_bot);
                }
                else { Debug.Log("The Key Broke"); }
            }
            else { near_door = false; }

            if (near_door) {
                key_handler.GetComponent<key_handler>().key.GetComponent<SpriteRenderer>().enabled = true;
                key_handler.GetComponent<key_handler>().has_key = false;
                key_handler.GetComponent<key_handler>().key_UI.GetComponent<SpriteRenderer>().enabled = false;
            }
        }

        //Input
        movement.x = Input.GetAxisRaw("Horizontal");
        movement.y = Input.GetAxisRaw("Vertical");
        animator.SetFloat("Horizontal", movement.x);
        animator.SetFloat("Vertical", movement.y);
        animator.SetFloat("Speed", movement.sqrMagnitude);

        PlayerPrefs.SetInt("health", p_health);
        if (potion_handler.GetComponent<PotionHandler>().has_potion) { PlayerPrefs.SetInt("has_potion", 1); }
        else { PlayerPrefs.SetInt("has_potion", 0); }
        if (key_handler.GetComponent<key_handler>().has_key) { PlayerPrefs.SetInt("has_key", 1); }
        else { PlayerPrefs.SetInt("has_key", 0); }
        PlayerPrefs.SetInt("coins", coinSpawning.GetComponent<Coin>().amount);

        room_percentage = Random.Range(0.0f, 1.0f);
        if (room_percentage <= 0.2f) { room = 3; }
        else if (room_percentage > 0.2f && room_percentage <= 0.8f) { room = 1; }
        else if (room_percentage > 0.8f && room_percentage <= 1.0f) { room = 4; }

        if (player.transform.position.y >= door_pos.y && player.transform.position.x <= (door_pos.x + 0.5) && player.transform.position.x >= (door_pos.x - 0.5)) { SceneManager.LoadScene(2); }
        if (player.transform.position.y >= door_key_1.y && player.transform.position.x <= (door_key_1.x + 0.5) && player.transform.position.x >= (door_key_1.x - 0.5)) {
            PlayerPrefs.SetFloat("p_loc_x", -4.5f);
            PlayerPrefs.SetFloat("p_loc_y", 5f);
            SceneManager.LoadScene(room); ;
        }
        if (player.transform.position.y >= door_key_2.y && player.transform.position.x <= (door_key_2.x + 0.5) && player.transform.position.x >= (door_key_2.x - 0.5)) {
            PlayerPrefs.SetFloat("p_loc_x", 4.5f);
            PlayerPrefs.SetFloat("p_loc_y", 5f);
            SceneManager.LoadScene(room);
        }
        if (player.transform.position.y >= door_key_3.y && player.transform.position.x <= (door_key_3.x + 0.5) && player.transform.position.x >= (door_key_3.x - 0.5)) {
            PlayerPrefs.SetFloat("p_loc_x", 7.5f);
            PlayerPrefs.SetFloat("p_loc_y", 5f);
            SceneManager.LoadScene(room);
        }
    }

    void FixedUpdate() {
        rb.MovePosition(rb.position + movement * moveSpeed * Time.fixedDeltaTime);
        cam_pos = new Vector3(player.transform.position.x, player.transform.position.y, -30);
        cam.transform.position = cam_pos;
    }
}
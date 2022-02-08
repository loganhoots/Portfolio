using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class key_handler : MonoBehaviour
{
    public float MoveTime = 5.0f;
    Vector3[] locations = new Vector3[9] { new Vector3(-8.5f, 4.5f, 0f), new Vector3(-8.5f, -4.5f, 0f) , new Vector3(8.5f, 4.5f, 0f),
        new Vector3(8.5f, -4.5f, 0f), new Vector3(2.5f, 4.5f, 0f), new Vector3(-2.5f, 4.5f, 0f), new Vector3(-1.5f, -4.5f, 0f), 
        new Vector3(1.5f, -4.5f, 0f), new Vector3(0f, 0f, 0f) };
    public GameObject key, key_UI, player;
    public bool has_key = false;
    int temp;

    // Start is called before the first frame update
    void Start()
    {
        if (PlayerPrefs.GetInt("has_key", 0) == 1)
        {
            has_key = true;
            key_UI.GetComponent<SpriteRenderer>().enabled = true;
            key.GetComponent<SpriteRenderer>().enabled = false;
        }
        else
        {
            has_key = false;
            key_UI.GetComponent<SpriteRenderer>().enabled = false;
            key.GetComponent<SpriteRenderer>().enabled = true;
        }
        StartCoroutine(move());
    }

    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject == player)
        {
            key_UI.GetComponent<SpriteRenderer>().enabled = true;
            key.GetComponent<SpriteRenderer>().enabled = false;
            has_key = true;
        }
    }

    IEnumerator move()
    {
        while (!has_key)
        {
            yield return new WaitForSeconds(MoveTime);
            key.transform.position = locations[Random.Range(0, 9)];
        }
    }
}

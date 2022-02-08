using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;

public class intro : MonoBehaviour
{
    public GameObject player, beginning, canvas;
    public SpriteRenderer psr;
    public Sprite fl;
    public Animator ani;


    // Start is called before the first frame update
    void Start()
    {
        canvas.SetActive(false);
        StartCoroutine(beginning_walk());
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    IEnumerator beginning_walk()
    {
        ani.SetFloat("Vertical", -1);
        ani.SetFloat("Speed", 1);
        while (player.transform.position.y > 1)
        {
            yield return new WaitForSeconds(0.001f);
            player.transform.position -= new Vector3(0, 0.004f, 0);
        }
        ani.SetFloat("Speed", 0);
        psr.sprite = fl;
        player.transform.localScale = new Vector2(-1, 1);
        canvas.SetActive(true);
        beginning.GetComponent<intro>().enabled = false;
    }
}

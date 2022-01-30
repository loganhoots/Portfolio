using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Eye : MonoBehaviour
{
    private GameObject target;
    public Transform tr;
    Vector2 movement;
    Vector2 past_movement = new Vector2(0, 0);
    //Vector2 temp = tr.position;
    public float MoveTime = 1.0f;

    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(move());
    }

    // Update is called once per frame
    void Update()
    {
        target = GameObject.FindGameObjectWithTag("coin");
        movement.x = tr.position.x;
        if (movement.x > past_movement.x)
        {
            transform.localScale = new Vector2(1, 1);
        }
        else if (movement.x < past_movement.x)
        {
            transform.localScale = new Vector2(-1, 1);
        }
        else
        {
            transform.localScale = new Vector2(1, 1);
        }
        past_movement.x = tr.position.x;
    }

    IEnumerator move() 
    {
        while (true)
        {
            yield return new WaitForSeconds(MoveTime);
            if ((target.transform.position.x + 0.01f) < tr.position.x)
            {
                tr.position += new Vector3(-0.005f, 0, 0);
            }
            else if ((target.transform.position.x - 0.01f) > tr.position.x)
            {
                tr.position += new Vector3(0.005f, 0, 0);
            }
            if (target.transform.position.y < tr.position.y)
            {
                tr.position += new Vector3(0, -0.005f, 0);
            }
            else if (target.transform.position.y > tr.position.y)
            {
                tr.position += new Vector3(0, 0.005f, 0);
            }
        }
    }
}

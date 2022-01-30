using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Mushroom : MonoBehaviour
{
    private GameObject target;
    public Transform tr, player;
    Vector2 movement;
    Vector2 past_movement = new Vector2(0, 0);
    Vector3 target_position = new Vector3(0f, 2.25f, 0f);
    public float MoveTime = 1.0f;

    public Animator animator;
    bool moving;

    public float learn_speed = 3.0f, error = 0.1f, learn_factor = 0.01f;
    int lu = 0, ld = 0, mu = 0, md = 0, ru = 0, rd = 0, knowledge;
    Vector3[] locations = new Vector3[6] { new Vector3(-4.5f, 4.25f, 0f), new Vector3(-4.5f, -3.75f, 0f) , new Vector3(0f, 2.25f, 0f),
        new Vector3(0f, -0.75f, 0f), new Vector3(4.5f, 4.25f, 0f), new Vector3(4.5f, -3.75f, 0f) };

    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(move());
        StartCoroutine(kalman());
    }

    // Update is called once per frame
    void Update()
    {
        movement.x = tr.position.x;
        if (movement.x > past_movement.x)
        {
            transform.localScale = new Vector2(1, 1);
        }
        else if (movement.x < past_movement.x)
        {
            transform.localScale = new Vector2(-1, 1);
        }
        past_movement.x = tr.position.x;
    }

    IEnumerator move()
    {
        while (true)
        {
            yield return new WaitForSeconds(MoveTime);
            if ((target_position.x + 0.1) < tr.position.x)
            {
                tr.position += new Vector3(-0.005f, 0, 0);
                moving = true;
            }
            else if ((target_position.x - 0.1) > tr.position.x)
            {
                tr.position += new Vector3(0.005f, 0, 0);
                moving = true;
            }
            else 
            {
                moving = false;
            }
            if ((target_position.y + 0.1) < tr.position.y)
            {
                tr.position += new Vector3(0, -0.005f, 0);
                moving = true;
            }
            else if ((target_position.y - 0.1) > tr.position.y)
            {
                tr.position += new Vector3(0, 0.005f, 0);
                moving = true;
            }
            else
            {
                moving = false;
            }

            if (!moving) { animator.SetBool("moving", false); }
            else { animator.SetBool("moving", true); }
        }
    }

    IEnumerator kalman() 
    {
        while (true) 
        {
            yield return new WaitForSeconds(learn_speed);
            knowledge++;
            if (knowledge % 20 == 0)
            {
                knowledge = 0;
                error -= learn_factor;
            }
            if (Random.Range(0f, 1f) <= error)
            { target_position = locations[Random.Range(0, 6)]; }
            else if (player.position.x < -4)
            {
                if (player.position.y >= 0) { lu++; }
                else { ld++; }

                if (lu >= ld) { target_position = new Vector3(-4.5f, 4.25f, 0f); }
                else { target_position = new Vector3(-4.5f, -3.75f, 0f); }
            }
            else if (player.position.x > 4)
            {
                if (player.position.y >= 0) { ru++; }
                else { rd++; }

                if (ru >= rd) { target_position = new Vector3(4.5f, 4.25f, 0f); }
                else { target_position = new Vector3(4.5f, -3.75f, 0f); }
            }
            else if (player.position.x > -4 && player.position.x < 4)
            {
                if (player.position.y < 0) { md++; }
                else { mu++; }

                if (mu >= md) { target_position = new Vector3(0f, 2.25f, 0f); }
                else { target_position = new Vector3(0f, -0.75f, 0f); }
            }
        }
    }
}
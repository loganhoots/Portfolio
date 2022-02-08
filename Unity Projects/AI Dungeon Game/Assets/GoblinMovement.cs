using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GoblinMovement : MonoBehaviour
{
    public float moveSpeed = 5;

    public Transform tr;
    public Animator animator;

    Vector2 movement;
    Vector2 past_movement = new Vector2(0, 0);

    // Update is called once per frame
    void Update()
    {
        movement.x = tr.position.x;

        if (movement.x > past_movement.x)
        {
            transform.localScale = new Vector2(1, 1);
            animator.SetFloat("Run", 1f);
        }
        else if (movement.x < past_movement.x)
        {
            transform.localScale = new Vector2(-1, 1);
            animator.SetFloat("Run", 1f);
        }
        else
        {
            animator.SetFloat("Run", 0f);
        }
        
        past_movement.x = tr.position.x;
    }
}

// Library Includes
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// Player Class
public class PlayerMovement : MonoBehaviour {
    // Public Variables
    public PlayerController controller;
    public float runSpeed = 40f;
    public Animator animator;
    //Private Variables
    private bool attack = false;
    private float HorizontalMovement = 0f;

    // Update is called once per frame
    void Update() {
        if (!attack) { // Checks to see if the player is not attacking
            HorizontalMovement = Input.GetAxisRaw("Horizontal") * runSpeed;
        }
        animator.SetFloat("Horizontal Movement", HorizontalMovement);
        animator.SetBool("Attack", attack);
        if (Input.GetKey("e")) {
            attack = true;
            StartCoroutine(WaitForAttackAnimation(0.6f));
        }
    }

    void FixedUpdate() {
        controller.Move(HorizontalMovement * Time.fixedDeltaTime, false, false);
    }

    private IEnumerator WaitForAttackAnimation(float time) {
        yield return new WaitForSeconds(time);
        attack = false;
    }
}

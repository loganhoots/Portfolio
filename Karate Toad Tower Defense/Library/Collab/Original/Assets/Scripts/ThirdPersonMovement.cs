using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ThirdPersonMovement : MonoBehaviour
{
    //reference to charater controller
    public CharacterController controller;

    //reference to Main camera
    public Transform cam;

    public Animator animator;

    public float speed = 6f;

    public float turnSmoothTime = 0.1f;
    float turnSmoothVelocity;

    bool jump = false;

    // Update is called once per frame
    void Update()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");
        Vector3 direction = new Vector3(horizontal, 0f, vertical).normalized;

        animator.SetFloat("WalkSpeed", Mathf.Abs(horizontal));
        animator.SetFloat("WalkSpeed", Mathf.Abs(vertical));

        if (Input.GetButtonDown("Sprint"))
        {
            speed = 10f;

            animator.SetBool("IsRunning", true);
        }
        if (Input.GetButtonUp("Sprint"))
        {
            speed = 1f;

            animator.SetBool("IsRunning", false);
        }

        if(direction.magnitude >= 0.1f)
        {
            //rotates player
            float targetAngle = Mathf.Atan2(direction.x, direction.z) * Mathf.Rad2Deg + cam.eulerAngles.y;
            float angle = Mathf.SmoothDampAngle(transform.eulerAngles.y, targetAngle, ref turnSmoothVelocity,  turnSmoothTime);
            transform.rotation = Quaternion.Euler(0f, angle, 0f);

            Vector3 moveDir = Quaternion.Euler(0f, targetAngle, 0f) * Vector3.forward;
            controller.Move(moveDir.normalized * speed * Time.deltaTime);
        }

        if (Input.GetButtonDown("Jump"))
		{
			jump = true;
			//animator.SetBool("Grounded", false);
			animator.SetTrigger("Jumping");
		}
    }
}

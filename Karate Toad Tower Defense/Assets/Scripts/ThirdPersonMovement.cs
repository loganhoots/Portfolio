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

    public float speed;
    public float jumpHeight = 4f;


    public float turnSmoothTime = 0.1f;
    float turnSmoothVelocity;
    //public float jumpingpower = 20f;

    public float gravity = -9.81f;
    Vector3 velocity;
    public Transform groundCheck;
    public float groundDistance = 0.4f;
    public LayerMask groundMask;
    bool isGrounded;

    void Start()
    {
        controller = GetComponent<CharacterController>();
        Cursor.lockState = CursorLockMode.Locked;
    }

    // Update is called once per frame
    void Update()
    {
        isGrounded = Physics.CheckSphere(groundCheck.position, groundDistance, groundMask);
        if (isGrounded && velocity.y <0)
        {
            velocity.y = -1f;
        }

        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");
        Vector3 direction = new Vector3(horizontal, 0f, vertical).normalized;
        float magnitude = Mathf.Clamp01(direction.magnitude) * speed;
        velocity.y += gravity * Time.deltaTime;
        controller.Move(velocity * Time.deltaTime);

        FrogMoving(horizontal, vertical);
        FrogJumping();

        if(transform.position.y < -30f){
            transform.position = new Vector3(0,10,0);
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
    }

    void FrogMoving(float horizontal, float vertical)
    {
        if(Input.GetButtonDown("Horizontal"))
        {
            animator.SetFloat("WalkSpeed", Mathf.Abs(horizontal));
        }

        if(Input.GetButtonUp("Horizontal"))
        {
            animator.SetFloat("WalkSpeed", Mathf.Abs(horizontal));
        }
        
        if(Input.GetButtonDown("Vertical"))
        {
            animator.SetFloat("MoveSpeed", Mathf.Abs(vertical));
        }

        if(Input.GetButtonUp("Vertical"))
        {
            animator.SetFloat("MoveSpeed", Mathf.Abs(vertical));
        }

        if (Input.GetButtonDown("Sprint"))
        {
            speed = 10f;

            animator.SetBool("IsRunning", true);
        }
        if (Input.GetButtonUp("Sprint"))
        {
            speed = 4f;

            animator.SetBool("IsRunning", false);
        }
    }

    void FrogJumping()
    {
        if(Input.GetButtonDown("Jump") && isGrounded)
        {
            velocity.y = Mathf.Sqrt(jumpHeight * -2f * gravity);
            //animator.SetTrigger("HumanoidJumpUp");
            //rb.AddForce(transform.up * jumpingpower);
            //animator.SetBool("Grounded", false);
            
            //animator.SetBool("IsInAir", true);
            //animator.SetBool("IsFalling", true);
            //animator.SetTrigger("Jumping");
        }


        if (isGrounded == true)
        {
            animator.SetBool("Jumping", false);
        } else
        {
            animator.SetBool("Jumping", true);
        }
    }
}

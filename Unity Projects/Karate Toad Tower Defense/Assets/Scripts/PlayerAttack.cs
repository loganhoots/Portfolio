using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerAttack : MonoBehaviour
{
    //Variables
    Animator anim;
    Collider weaponCollider;
    public GameObject currentLevel2;
    public AudioSource Swish;

    bool UnlockProjectile;
    //public int currentLevel = Logic.GetComponent<DemoBarAnimator>().player_level;

    //Projectile
    public GameObject projectilePrefab;
    public Transform firePoint;
    private float projectileVelocity = 700;
    


    // Start is called before the first frame update
    void Start()
    {
        UnlockProjectile = false;
        anim = GetComponent<Animator>();
        weaponCollider = GetComponent<Collider>();
    }

    // Update is called once per frame
    void Update()
    {
        // 0=left click //1=right click //2=middle btn
        if (Input.GetMouseButtonDown(0)) { 
            anim.SetBool("attacking", true);
            Swish.Play();
            weaponCollider.enabled = true;
        }else if (Input.GetMouseButtonUp(0))
        {
            anim.SetBool("attacking", false);
            weaponCollider.enabled = false;
        }
    }

    // void PlayerProjectileAttack()
    // {
    //     currentLevel = currentLevel2.GetComponent<Logic>().player_level;

    //     if(currentLevel >= 0)
    //     {
    //         UnlockProjectile = true;
    //     }
    //     if(UnlockProjectile == true)
    //     {
    //         if(Input.GetButtonDown("Fire1"))
    //         {
    //             PlayerShoot();
    //         }
    //     }
    // }

    // void PlayerShoot()
    // {
    //     GameObject projectileGO = Instantiate(projectilePrefab, firePoint.position, firePoint.rotation);
    //     Projectile projectile = projectileGO.GetComponent<Projectile>();

    //     projectileGO.GetComponent<Rigidbody>().AddRelativeForce(new Vector3(0, projectileVelocity,0));
    // }
}

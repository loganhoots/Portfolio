using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SimpleBarExample;
using UnityEngine.UI;

public class Webspider : MonoBehaviour
{
    public float speed = 10f;
    public AudioSource Squish;

    public GameObject impactEffect;

    public int value = 1;
    public float startHealth = 100;
    private float health;

    private Transform target;
    private int wavepointIndex = 0;

    

   // public GameObject deathEffect;

    public GameObject GameLogic;
    public GameObject XPBar;


    [Header("Unity Stuff")]
    public Image healthBar;

    private void Start()
    {
        GameLogic = GameObject.Find("Game Manager");
        XPBar = GameObject.Find("XP Bar");
        target = Waypoints2.points[0];
        health = startHealth;
    }

    public void TakeDamage(float amount)
    {
        health -= amount;

        healthBar.fillAmount = health / startHealth;

        Squish.Play();

        if (health <= 0)
        {
            Die();
        }
    }

    void Die()
    {

        GameLogic.GetComponent<Logic>().increaseMoney(value);
        XPBar.GetComponent<DemoBarAnimator>().totalXP++;
        //GameObject effect = (GameObject)Instantiate(deathEffect, transform.position, Quaternion.Euler(0, 0, 0));
        NewWaveSpawner.EnemiesAlive--;
        Squish.Play();
        Debug.Log(NewWaveSpawner.EnemiesAlive);
        Destroy(gameObject);
    }

    private void Update()
    {
        Vector3 dir = target.position - transform.position;
        transform.Translate(dir.normalized * speed * Time.deltaTime, Space.World);
        transform.LookAt(target);

        if (Vector3.Distance(transform.position, target.position) <= 0.2f)
        {
            GetNextWaypoint();
        }

        void GetNextWaypoint()
        {
            if (wavepointIndex >= Waypoints2.points.Length - 1)
            {
                GameLogic.GetComponent<Logic>().numberOfLives--;
                NewWaveSpawner.EnemiesAlive--;
                Debug.Log(NewWaveSpawner.EnemiesAlive);
                Destroy(gameObject);
                return;
            }

            wavepointIndex++;
            target = Waypoints2.points[wavepointIndex];
        }

    }


    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "sword")
        {
            GameObject effectIns = (GameObject)Instantiate(impactEffect, transform.position, transform.rotation);
            Destroy(effectIns, 1f);
            
            TakeDamage(50);
            //XPBar.GetComponent<DemoBarAnimator>().totalXP += 10;
            //GameLogic.GetComponent<Logic>().money++;
            //Destroy(gameObject);
        }
    }

}

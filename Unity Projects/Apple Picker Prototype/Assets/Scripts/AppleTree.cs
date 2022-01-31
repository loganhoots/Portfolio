using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AppleTree : MonoBehaviour
{
    [Header("Set in Inspector")]

    //Initiate Variables
    public GameObject applePrefab; //Initiates Apple Prefab
    public float speed = 1f; //Initiates Apple falling speed
    public float lAndREdge = 10f; //Initiates border
    public float changeDirection = 0.1f; //Initiates Chance to change direction
    public float secondsBetweenDrops = 1f; //Initaites Drop time
    public float speedChange = 0.5f;

    // Start is called before the first frame update
    void Start()
    {
        Invoke("DropApple", 2f);
        StartCoroutine(accelerator());
    }

    void DropApple()
    {
        GameObject apple = Instantiate<GameObject>(applePrefab);
        apple.transform.position = transform.position;
        Invoke("DropApple", secondsBetweenDrops);
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 pos = transform.position; //Current position of the tree
        pos.x += speed * Time.deltaTime; //Increases the speed over time
        transform.position = pos; //Allows the tree to move

        if (pos.x < -lAndREdge)
        {
            speed = Mathf.Abs(speed);
        }
        else if (pos.x > lAndREdge)
        {
            speed = -Mathf.Abs(speed);
        }

    }

    void FixedUpdate()
    {
        if (Random.value < changeDirection)
        {
            speed *= -1;
        }
    }

    private IEnumerator accelerator()
    {
        while (true)
        {
            yield return new WaitForSeconds(1);
            if (speed > 0)
            {
                speed += speedChange;
            }
            else
            {
                speed -= speedChange;
            }
        }
    }
}

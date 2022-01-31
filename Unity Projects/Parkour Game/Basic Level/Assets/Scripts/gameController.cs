using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityStandardAssets.Characters.FirstPerson;

public class gameController : MonoBehaviour
{
    void OnTriggerEnter(Collider coll)
    {
        if (coll.gameObject.tag == "point")
        {
            Destroy(coll.gameObject);
        }
    }
}

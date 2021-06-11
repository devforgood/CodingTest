using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LinearlyIndependent : MonoBehaviour
{
    int count = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        var v1 = new Vector3(1, 2, 3);
        var v2 = new Vector3(4, 5, 6);
        var v3 = new Vector3(2, 1, 0);


        if (count++ / 100 % 2 == 0)
        {
            Debug.DrawLine(Vector3.zero, v1, Color.red);
            Debug.DrawLine(Vector3.zero, v2, Color.blue);
            Debug.DrawLine(Vector3.zero, v3, Color.green);
        }
        else
        {

            Debug.DrawLine(Vector3.zero, (10 * v1), Color.red);
            Debug.DrawLine((10 * v1), (10 * v1)+ (-5 * v2), Color.blue);
            Debug.DrawLine((10 * v1) + (-5 * v2), (10 * v1) + (-5 * v2) + (5 * v3), Color.green);
        }


    }
}

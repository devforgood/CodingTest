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

        // 각 백터에 0이 아닌 다른 값으로 곱했을때 선형 결함이 0이면 선형 종속이다.

        Debug.DrawLine(Vector3.zero, v1, Color.red);
        Debug.DrawLine(Vector3.zero, v2, Color.blue);
        Debug.DrawLine(Vector3.zero, v3, Color.green);


        if (count++ / 100 % 2 == 0)
            Debug.DrawLine(Vector3.zero, v1 + v2 + v3, Color.white);
        else
        {
            // 백터들을 가우스 소거법으로 구해서 나온 값으로 해당 값을 구해서 테스트해봄
            var v4 = (10 * v1) + (-5 * v2) + (5 * v3);
            Debug.DrawLine(Vector3.zero, (10 * v1) + (-5 * v2) + (5 * v3), Color.yellow);
        }


    }
}

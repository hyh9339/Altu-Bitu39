#include <iostream>
#include <cmath>

using namespace std;

// 유클리드 호제법
int gcdRecursion(int a, int b) {
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) { //b가 0이라면
        return a; //0으로 나눌 수 없음, a 리턴
    }
    return gcdRecursion(b, a % b); //재귀로 최대공약수 반환
}

/**
 * 최대공약수를 G, 최소공배수를 L 이라고 하자.
 * G*L = A*B 이고
 * A = G*a, B = G*b로 나타낼 수 있다.
 * 이에 따라 G*L = G*G*a*b라 할 수 있고 이를 정리하면
 * L/G = a*b 이다.
 *
 * A+B가 최소가 되려면, a+b가 최소가 되어야 하고, 그러기 위해선 a, b의 차이가 최소여야 한다.
 */

int main() {
    int gcd, lcm;

    //입력
    cin >> gcd >> lcm; //최대공약수, 최소공배수 입력

    //연산
    int ab = lcm / gcd;
    int a = -1, b = -1;
    for (int i = sqrt(ab); i > 0; i--) { //a, b의 차이가 가장 작을 제곱근부터 체크
        if (ab % i != 0) { //a가 약수인지 체크
            continue;
        }
        //i가 ab의 약수라면
        int tmp_a = i, tmp_b = ab / i; //서로소 체크를 위해
        //두 수가 서로소인지 체크 -> 만약 두 수가 서로소가 아니라면 두 수의 최대공약수가 gcd가 될 수 없음
        if (gcdRecursion(tmp_b, tmp_a) == 1) { //두 수의 최대공약수가 1이라면
            a = tmp_a;
            b = tmp_b;
            break; //두 자연수 확정 후 반복문 끝내기
        }
    }

    //출력
    cout << a * gcd << ' ' << b * gcd; //합이 최소가 되도록 만들어 출력

    return 0;
}
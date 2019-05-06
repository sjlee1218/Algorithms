#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<int> isprime(1000002,-1); // 1이면 소수인거.
vector<int> prime_numbers;

int main(){

    isprime[0] = 0;
    isprime[1] = 0;
    int start_index = 2;

    // Assume that N <= 1, 000, 000
    int M,N; // N 이 소수인가?
    cin >> M>>N;

    // 먼저, sqrt(N) 이하의 소수가 뭔지를 알아야함. -> 에라토스테네스의 체 써보자
    //isprime[2] = 1;
    //prime_numbers.push_back(2);

    for (ll i = start_index; i <= N; i++) { // 어디까지 돌았는지 기억하고 있을 수 있음. -> 최적화 가능.
        // i 가 소수인지 check
        //if (i*i > N+1)
        //    break;

        if (isprime[i] == 0)
            continue; // 이미 합성수니까 continue;

        isprime[i] = 0;
        prime_numbers.push_back(i); // i 는 소수야. -> 체로 걸러야 함.
        for (ll j = 0; j <= N; j++) {
            ll q = i*i + j*i;
            if (q > N)
                break;
            isprime[q] = 0;
        }

    }

    for(int prime : prime_numbers) {
        if (prime < M)
            continue;
        cout << prime << "\n";
    }
    return 0;
}

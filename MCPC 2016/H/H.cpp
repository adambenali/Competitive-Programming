#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<long long int> Primes(long long int n)
{
    int isPrime[n];
    fill(isPrime,isPrime+n,1);
    for (long long int p = 2; p*p <= n; p++)
        if (isPrime[p])
            for (int k = p*2;k <= n;k = k + p)
                isPrime[k] = 0;
 
    vector <long long int> primes;
    for (long long int p = 2; p <= n;p++)
       if (isPrime[p])
          primes.push_back(p);
    return primes;
}
 
long long int gcd(long long int a, long long int b) {
    return b == 0 ? a : gcd(b, a % b);
}
 
int main()
{
    vector <long long int> primes = Primes(1000000); // Precomputation
    int T,N,d,power;
    cin >> T;
    while (T--){
        cin >> N;
        long long int a[N];
        for (int j = 0;j < N;j++) cin >> a[j];
 
        d=0;
 
        // Part 1 : Small divisors
 
        for (int i = 0;i < primes.size() && primes[i] <= *max_element(a,a+N);i++){
            power=0;
            for (int j=0; j < N; j++)
                while (a[j] % primes[i] == 0){
                    a[j] /= primes[i];
                    power++;
                }
            d=max(d,power);
        }
 
        // Part 2 : Big divisors
 
        long long int GCD;
        vector <long long int> bigDivisors;
        for (int j = 0; j < N; j++){
            if (a[j] == 1)
                continue;
            if (sqrt(a[j]) == floor(sqrt(a[j]))){ //If perfect square
                bigDivisors.push_back(floor(sqrt(a[j])));
                continue;}
            for (int l = j;l < N;l++){
                GCD=gcd(a[j],a[l]);
                if (GCD != 1)
                    bigDivisors.push_back(GCD);
            }
        }
 
        for (int l = 0;l < bigDivisors.size(); l++){
            power=0;
            for (int j = 0;j < N;j++)
                while (a[j] % bigDivisors[l] == 0){
                    a[j] /= bigDivisors[l];
                    power++;
                }
            d=max(d, power);
        }
        printf("%d\n", d);
    }
    return 0;
}

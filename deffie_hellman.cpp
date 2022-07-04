#include <bits/stdc++.h>

using namespace std;
long long int power(int a, int b, int m)
{
    long long int t;
    if (b == 1)
        return a;
    t = power(a, b / 2, m);
    if (b % 2 == 0)
        return (t * t) % m;
    else
        return (((t * t) % m) * a) % m;
}

// Driver program
int main()
{
    long long int q, alpha, x, a, y, b, ka, kb;
    cout << "Enter the values of q and alpha upon which Alice And Bob both will aggree : " << endl;
    cin >> q >> alpha;

    cout << "Enter the Secret Integer for Alice : ";
    cin >> x;
    cout << "Enter the Secret Integer for Bob : ";
    cin >> y;
    cout << endl;
    a = power(alpha, x, q);
    b = power(alpha, y, q);
    cout << "Alice's private key, known only to Alice : " << a << endl;
    cout << "Bob's private key known only to Bob : " << b << endl;
    cout << endl;
    ka = power(b, x, q);
    kb = power(a, y, q);
    cout << "Alice's public key, known to Alice and Bob : " << ka << endl;
    cout << "Bob's public key, known to Alice and Bob : " << kb << endl;
    return 0;
}
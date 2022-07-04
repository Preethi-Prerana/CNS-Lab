#include <bits/stdc++.h>
using namespace std;

int power(int a, int b, int m)
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

int calc_gcd(int a, int b)
{
    int t;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    long int p, q;
    cout << "enter two large prime numbers : ";
    cin >> p;
    cin >> q;
    long int n = p * q;
    long int phi = (p - 1) * (q - 1);
    int e = 2, d = 1;
    while (e < phi)
    {
        if (calc_gcd(phi, e) == 1)
            break;
        else
            e++;
    }
    while ((e * d) % phi != 1)
        d++;
    cout << "e : " << e << "\nd : " << d << endl;
    cout << "Public key : {" << e << "," << n << "}\n";
    cout << "Private key : {" << d << "," << n << "}\n";
    cout << "enter the msg to be encrypted : ";
    int msg;
    cin >> msg;
    double ct = power(msg, e, n);
    double pt = power(ct, d, n);
    cout << "encrypted text : " << ct << "\ndecrypted text : " << pt << endl;
}
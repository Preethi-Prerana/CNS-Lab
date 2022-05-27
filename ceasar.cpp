#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n, key, c, cp, ch;
    string msg;
    cout << "1.ENCRYPTION\n2.DECRYPTION\nenter your choice : ";
    cin >> n;
    cout << "enetr the key value : ";
    cin >> key;
    cout << "enter your msg : ";
    getline(cin, msg);
    getline(cin, msg);
    msg.erase(remove(msg.begin(), msg.end(), ' '), msg.end());
    if (n == 1)
        cout << "encrypted message : ";
    else if (n == 2)
        cout << "decrypted mesage : ";
    for (int i = 0; i < msg.length(); i++)
    {
        c = toupper(msg[i]) - 65;
        if (n == 1)
            cp = (c + key) % 26;
        else if (n == 2)
            cp = (c - key) % 26;
        ch = cp + 65;
        printf("%c", ch);
    }
    return 0;
}
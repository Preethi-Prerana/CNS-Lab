#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string generateKey(string str, string key)
{
    int x = str.size();
    for (int i = 0;; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string encrypt(string str, string key)
{
    string cipher_text;
    for (int i = 0; i < str.size(); i++)
    {
        char x = (str[i] + key[i]) % 26;
        x += 'A';
        cipher_text.push_back(x);
    }
    return cipher_text;
}

string decrypt(string cipher_text, string key)
{
    string orig_text;
    for (int i = 0; i < cipher_text.size(); i++)
    {
        char x = (cipher_text[i] - key[i] + 26) % 26;
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}

int main()
{
    string str, keyword, key;
    int choice;
    cout << "1.encryption\n2.decryption\nenter your choice";
    cin >> choice;
    cout << "enter the msg (in cpaitals): ";
    getline(cin, str);
    getline(cin, str);
    cout << "enter the key used (in capitals): ";
    getline(cin, keyword);
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    keyword.erase(remove(keyword.begin(), keyword.end(), ' '), keyword.end());
    key = generateKey(str, keyword);
    if (choice == 1)
        cout << "Encrypted msg : " << encrypt(str, key);
    else if (choice == 2)
        cout << "Decrypted msg : " << decrypt(str, key);
    return 0;
}
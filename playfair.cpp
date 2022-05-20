#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char keymat[5][5] = {'-'};

string removeDuplicate(string str, int n)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < i; j++)
            if (str[i] == str[j])
                break;
        if (j == i)
            str[index++] = str[i];
    }
    string r = str.substr(0, 25);
    return r;
}

int genkeymat(string str)
{
    string key;
    string str1 = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    str.append(str1);
    int z = 0;
    int klen = str.length();
    key = removeDuplicate(str, klen);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            keymat[i][j] = key[z];
            z++;
            cout << keymat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

string create_diagrams(string s1)
{
    string s2 = "";
    int i;
    char ch = 'X';
    for (i = 0; i < s1.length();)
    {
        if (s1[i] != s1[i + 1])
        {
            s2.push_back(s1[i]);
            s2.push_back(s1[i + 1]);
            i += 2;
        }
        else
        {
            s2.push_back(s1[i]);
            s2.push_back(ch);
            i += 1;
        }
    }
    if (s2.length() % 2 != 0)
        s2.push_back(ch);
    return s2;
}

string en_dy(string s1, int n)
{
    string s2 = create_diagrams(s1);
    int i, j, k, r1, c1, r2, c2;
    char ch = 'X';
    int l = s2.length();
    for (k = 0; k < l; k += 2)
    {
        char ch1 = s2[k];
        char ch2 = s2[k + 1];
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (ch1 == keymat[i][j])
                {
                    r1 = i;
                    c1 = j;
                }
                else if (ch2 == keymat[i][j])
                {
                    r2 = i;
                    c2 = j;
                }
            }
        }
        if (c1 == c2)
        {
            if (n == 1)
            {
                s2[k] = keymat[(r1 + 1) % 5][c1];
                s2[k + 1] = keymat[(r2 + 1) % 5][c2];
            }
            else if (n == 2)
            {
                s2[k] = keymat[(r1 - 1) % 5][c1];
                s2[k + 1] = keymat[(r2 - 1) % 5][c2];
            }
        }
        else if (r1 == r2)
        {
            if (n == 1)
            {
                s2[k] = keymat[r1][(c1 + 1) % 5];
                s2[k + 1] = keymat[r2][(c2 + 1) % 5];
            }
            else if (n == 2)
            {
                s2[k] = keymat[r1][(c1 - 1) % 5];
                s2[k + 1] = keymat[r2][(c2 - 1) % 5];
            }
        }
        else
        {
            s2[k] = keymat[r1][c2];
            s2[k + 1] = keymat[r2][c1];
        }
    }
    if (n == 2)
    {
        string s3 = "";
        for (i = 0; i < s2.length(); i++)
        {
            if (s2[i] == 'X')
            {
                if (s2[i - 1] == s2[i + 1])
                    continue;
                else
                    s3.push_back(s2[i]);
            }
            else
                s3.push_back(s2[i]);
        }
        return s3;
    }
    else
        return s2;
}

int main()
{
    string key, msg;
    int n;
    cout << "1.ENCRYPTION\n2.DECRYPTION\nEnter your choice : ";
    cin >> n;
    cout << "enter the key used (in capitals) : ";
    getline(cin, key);
    getline(cin, key);
    remove(key.begin(), key.end(), ' ');
    cout << "generated key matrix : " << endl;
    genkeymat(key);
    cout << "enter the msg : ";
    getline(cin, msg);
    msg.erase(remove(msg.begin(), msg.end(), ' '), msg.end());
    if(n==1)
        cout << "cipher text : " << en_dy(msg, n);
    else if(n==2)
        cout << "plain text : " << en_dy(msg, n);
    return 0;
}
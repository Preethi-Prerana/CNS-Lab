#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int key[3][3];
int choice,i,j,k;

int mod26(int a)
{
    return a >= 0 ? (a % 26) : 26 - (abs(a) % 26);
}

void mult_mat(int a[100][3], int b[100][3], int row, int dim)
{
    // int i, j, k;
    char ch;
    int res[100][3] = {0};
    if (choice == 1)
        cout << "encrypted msg : ";
    else if (choice == 2)
        cout << "decrypted msg : ";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < dim; j++)
        {
            for (int k = 0; k < dim; k++)
                res[i][j] += a[i][k] * b[k][j];
            res[i][j] = mod26(res[i][j]) + 65;
            ch = char(res[i][j]);
            cout << ch;
        }
}

int calc_det(int K[3][3], int n)
{
    int det;
    if (n == 1)
        det = K[0][0];
    else if (n == 2)
        det = (K[0][0] * K[1][1]) - (K[0][1] * K[1][0]);
    else if (n == 3)
        det = K[0][0] * ((K[1][1] * K[2][2]) - (K[1][2] * K[2][1])) - K[0][1] * ((K[1][0] * K[2][2]) - (K[1][2] * K[2][0])) + K[0][2] * ((K[1][0] * K[2][1]) - (K[1][1] * K[2][0]));
    return mod26(det);
}

int det_inv(int D)
{
    // int i = 0;
    for (i = 1; i <= 25; i++)
        if (mod26(D * i) == 1)
            return i;
    return 0;
}

void find_inv(int m[3][3], int n, int m_inverse[3][3])
{
    int adj[3][3] = {0};
    int det = calc_det(m, n);
    int detInverse = det_inv(det);
    if (n == 2)
    {
        adj[0][0] = m[1][1];
        adj[1][1] = m[0][0];
        adj[0][1] = -m[0][1];
        adj[1][0] = -m[1][0];
    }
    else if (n == 3)
    {
        int temp[5][5] = {0};
        for ( i = 0; i < 5; i++)
            for ( j = 0; j < 5; j++)
                temp[i][j] = m[i % 3][j % 3];
        for ( i = 1; i <= 3; i++)
            for ( j = 1; j <= 3; j++)
                adj[j - 1][i - 1] = temp[i][j] * temp[i + 1][j + 1] - temp[i][j + 1] * temp[i + 1][j];
    }
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            m_inverse[i][j] = mod26(adj[i][j] * detInverse);
}

void decrypt(int a[100][3], int key[100][3], int dim, int row)
{
    int k_inv[3][3] = {0};
    find_inv(key, dim, k_inv);
    mult_mat(a, k_inv, row, dim);
}

int main()
{
    int dim;
    cout << "1.ENCRYPTION\n2.DECRYPTION\nenter your choice : ";
    cin >> choice;
    int key[3][3] = {0};
    string msg, msg1;
    cout << "enter the dimension of the key matrix : ";
    cin >> dim;
    cout << "enter the key matrix used : \n";
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            cin >> key[i][j];
    cout << "enter the message : ";
    getline(cin, msg);
    getline(cin, msg);
    msg.erase(remove(msg.begin(), msg.end(), ' '), msg.end());
    char ch;
    while (msg.length() % dim != 0)
        msg.push_back('X');
    int r = msg.length() / dim;
    int msg_mat[r][3] = {0};
    k = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < dim; j++)
        {
            msg_mat[i][j] = toupper(msg[k]) - 65;
            k++;
        }
    if (choice == 1)
        mult_mat(msg_mat, key, r, dim);
    else if (choice == 2)
        decrypt(msg_mat, key, dim, r);
    return 0;
}
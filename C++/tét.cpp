#include <cmath>
#include <iostream>
#include <string>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// Hàm kiểm tra số chính phương
bool isSquared(int n)
{
    int root = round(sqrt(n));
    return n == root * root;
}

// Hàm tính khoảng cách di chuyển
int move(string moves)
{
    int x = 0, y = 0;
    for (int i = 0; i < moves.length(); i++)
    {
        char direction = moves[i];
        i++;
        int steps = moves[i] - '0';
        switch (direction)
        {
        case 'U':
            y += steps;
            break;
        case 'D':
            y -= steps;
            break;
        case 'L':
            x -= steps;
            break;
        case 'R':
            x += steps;
            break;
        }
    }
    return round(sqrt(x * x + y * y));
}

int main()
{
    string moves;
    cin >> moves;
    int distance = move(moves);
    cout << "Khoang cach xe da di chuyen tu vi tri ban dau toi diem hien tai: "
         << distance << '\n';
    if (isPrime(distance))
    {
        cout << "So " << distance << " la so nguyen to\n";
    }
    if (isSquared(distance))
    {
        cout << "So " << distance << " la so chinh phuong\n";
    }
    return 0;
}

#include <iostream>

using namespace std;

void RingIn(int n);

void RingOut(int n)
{
    if(n >= 1)
    {
        /* Take the n ring out */
        RingOut(n-2);
        cout << "Move ring " << n << " out" << endl;
        RingIn(n-2);

        /* Remain n-1 rings all out */
        RingOut(n-1);
    }
}

void RingIn(int n)
{
    if(n >= 1)
    {
        /* First n-1 rings in */
        RingIn(n-1);

        /* Put the n ring in */
        RingOut(n-2);
        cout << "Move ring " << n << " in" << endl;
        RingIn(n-2);
    }
}

int main()
{
    int n;
    cin >> n;
    RingOut(n);
}
/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/6 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int q;
int n;
int map[20];
int num;

inline int abs(int x)	{ return (x>0)? x : -x; }

int BinToPos(int x)
{
    int cnt = 0;
    while(x > 0)
    {
        if(x == 1) break;
        x = x >> 1;
        cnt++;
    }
    return cnt+1;
}

void Queen(int row, int ld, int rd, int depth)
{
    if(row != n)
    {
        /* All valid pos in this row */
        int validPos = ~(row | ld | rd) & n;
        
        /* Take each valid pos out */
        while(validPos > 0)
        {
            /* Extract the rightest 1 out and form a binary */
            int pos = validPos & (~validPos + 1);
            validPos -= pos;
            
            /* Record */
            map[depth] = BinToPos(pos);
            
            Queen(row|pos, (ld|pos)<<1, (rd|pos)>>1, depth+1);
        }
    }
    /* Output answer */
    else
    {
        string s = to_string(map[0]);
        for(int i=1 ; i<depth ; i++)
            s  += " " + to_string(map[i]);
        cout << s << "\n";
        num++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    int cnt = 0;
    while(cin >> q)
    {
        cout << "case " << ++cnt << ":\n";
        
        num = 0;
        n = (1 << q) - 1;
        Queen(0, 0, 0, 0);
        cout << num << "\n";
    }
}
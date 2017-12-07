/* Problem : https://pc2.tfcis.org/sky/index.php/problem/view/213/ */
/* Actually it is Uva311 */
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long gift[10];
    while(cin >> gift[1] >> gift[2] >> gift[3] >> gift[4] >> gift[5] >> gift[6])
    {
        bool end = true;
        for(int i=1 ; i<=6 ; i++)
            if(gift[i] != 0)
                end = false;
        if(end)	break;
        
        for(int i=1 ; i<=6 ; i++)
            if(gift[i] < 0)
                gift[i] = 0;
        
        /* 6*6 */
        long long num = gift[6];
        
        /* 5*5, need 11 of 1*1  */
        num += gift[5];
        gift[1] -= gift[5]*11;
        
        /* 4*4, need 5 of 2*2 */
        num += gift[4];
        gift[2] -= gift[4]*5;
        
        /* 3*3 */
        num += (gift[3]/4);
        if(gift[3]%4 != 0)
        {
            /* Need one more box to contain some 3*3 */
            num++;
            int remain = gift[3] %4;
            if(remain == 1)
            {
                gift[2] -= 5;
                gift[1] -= 7;
            }
            else if(remain == 2)
            {
                gift[2] -= 3;
                gift[1] -= 6;
            }
            else
            {
                gift[2] -= 1;
                gift[1] -= 5;
            }
        }
        
        /* 2*2, if the remain num of 2*2 < 0, we can use 1*1 to replace it */
        
        if(gift[2] > 0)
        {
            num += (gift[2] / 9);
            /* Use 1*1 to fill, if needed */
            if(gift[2] % 9 != 0)
            {
                num++;
                gift[1] -= (36 - (gift[2]%9)*4);
                
            }
        }
        else if(gift[2] < 0)
        {
            gift[1] -= (-gift[2]*4);
        }
        
        /* 1*1 , we don't care if the num of 1*1 become < 0, becauz that means empty */
        if(gift[1] > 0)
        {
            num += gift[1]/36;
            if(gift[1]%36 != 0)
                num++;
        }
        
        cout << num << "\n";
    }
}
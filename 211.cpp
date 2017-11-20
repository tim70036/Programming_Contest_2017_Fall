/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/211 */
/* Bug : input is invalid */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> fillRow;
vector<int> fillCol;
int map[15][15];


int row[9];
int col[9];
int block[3][3];
int limit = (1 << 9) - 1;

int BinToNum(int x)
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

bool DFS(int curDepth, int tarDepth)
{
    /* DFS */
    if(curDepth < tarDepth)
    {
        int r = fillRow[curDepth];
        int c = fillCol[curDepth];
        
        int rowState = row[r];
        int colState = col[c];
        int blockState = block[r/3][c/3];
        
        int validNum = ~(rowState | colState | blockState) & limit;
        
        /* Take each valid num out */
        while(validNum > 0)
        {
            /* Extract the rightest 1 out and form a binary */
            int binNum = validNum & (~validNum+1);
            validNum -= binNum;
            
            /* Fill one possible num into map */
            map[r][c] = BinToNum(binNum);
            
            /* Update Status */
            row[r] |= binNum;
            col[c] |= binNum;
            block[r/3][c/3] |= binNum;
            
            if(DFS(curDepth+1, tarDepth))
                return true;
            
            /* Restore Status */
            row[r] &= (~binNum);
            col[c] &= (~binNum);
            block[r/3][c/3] &= (~binNum);
            
        }
        return false;
    }
    /* Finish */
    else
    {
        for(int i=0 ; i<9 ; i++)
            for(int j=0 ; j<9 ; j++)
                cout << map[i][j];
        cout << "\n";
        return true;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string in;
    while(cin >> in && in != "end")
    {
        /* Init */
        for(int i=0 ; i<9 ; i++)	 row[i] = col[i] = 0;
        for(int i=0 ; i<3 ; i++)	for(int j=0 ; j<3 ; j++) block[i][j] = 0;
        fillRow.clear();
        fillCol.clear();
        
        /* Input */
        int index = 0;
        bool valid = true;
        for(int i=0 ; i<9 ; i++)
        {
            for(int j=0 ; j<9 ; j++, index++)
            {
                if(in[index] == '.')
                {
                    /* Record position to be filled */
                    fillRow.push_back(i);
                    fillCol.push_back(j);
                    map[i][j] = 87;
                }
                else
                {
                    map[i][j] = in[index] - '0';
                    int oldR = row[i], oldC = col[j], oldB = block[i/3][j/3];
                    row[i] |= (1 << (map[i][j]-1));
                    col[j] |= (1 << (map[i][j]-1));
                    block[i/3][j/3] |= (1 << (map[i][j]-1));
                    
                    /* Check input valid? */
                    if(oldR == row[i] || oldC == col[j] || oldB == block[i/3][j/3])  valid = false;
                }
            }
        }
        
        if(!valid)
        {
            cout << "No solution.\n";
            continue;
        }

        if(DFS(0, fillRow.size()) == false)
            cout << "No solution.\n";
    }
}
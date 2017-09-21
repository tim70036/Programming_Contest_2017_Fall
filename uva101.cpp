#include <iostream>
#include <string>
using namespace std;

/* Which stack and which position is a block at */
int blockPos[30][2];
int blockWorld[30][30];
int blockWorldLen[30];

int main()
{
    /* Initial world */
    for(int i=0 ; i < 30 ; i++)
    {
        /* Handler, record block state */
        blockPos[i][0] = i;
        blockPos[i][1] = 0;
        
        /* World */
        blockWorld[i][0] = i;
        blockWorldLen[i] = 1;
    }
    
    int n, b1, b2;
    bool b1Pile, b2Pile;
    string cmd1, cmd2;
    cin >> n;
    while(cin >> cmd1)
    {
        if(cmd1 == "quit")	break;
        
        cin >> b1 >> cmd2 >> b2;
        
        /* Check whether b1 and b2 are in same stack */
        if(blockPos[b1][0] == blockPos[b2][0])	continue;
        
        if(cmd1 == "move")
            b1Pile = false;
        else if(cmd1 == "pile")
            b1Pile = true;
        
        if(cmd2 == "onto")
            b2Pile = false;
        else if(cmd2 == "over")
            b2Pile = true;
        
        int b1Stack = blockPos[b1][0];
        int b2Stack = blockPos[b2][0];
        
        /* Determine blocks to move */
        int b1From = blockPos[b1][1], b1To = blockWorldLen[b1Stack] - 1;
        
        /* Return the blocks on b1 ? */
        if(b1Pile == false)
        {
            for(int i = blockPos[b1][1] + 1 ; i < blockWorldLen[b1Stack] ; i++)
            {
                int block = blockWorld[b1Stack][i];
                blockWorld[block][0] = block;
                blockWorldLen[block] = 1;
                
                /* Update handler */
                blockPos[block][0] = block;
                blockPos[block][1] = 0;
            }
            
            /* Update, only move one  */
            b1To = b1From;
        }
        
        /* Update */
        blockWorldLen[b1Stack] = blockPos[b1][1]; /* b1 is out */

        /* Return the blocks on b2 ? */
        if(b2Pile == false)
        {
            for(int i = blockPos[b2][1] + 1 ; i < blockWorldLen[b2Stack] ; i++)
            {
                int block = blockWorld[b2Stack][i];
                blockWorld[block][0] = block;
                blockWorldLen[block] = 1;
                
                /* Update handler */
                blockPos[block][0] = block;
                blockPos[block][1] = 0;
            }
            
            /* Update */
            blockWorldLen[b2Stack] = blockPos[b2][1] + 1;
        }
        
        
        
        
        /* Start */
        for(int i = b1From ; i <= b1To ; i++)
        {
            int block = blockWorld[b1Stack][i];
            int tarPos = blockWorldLen[b2Stack]++;
            blockWorld[b2Stack][tarPos] = block;
            
            /* Update handler */
            blockPos[block][0] = b2Stack;
            blockPos[block][1] = tarPos;
        }
    }
    
    /* Output */
    for(int i=0 ; i<n ; i++)
    {
        printf("%d:", i);
        for(int j = 0 ; j < blockWorldLen[i] ; j++)
            printf(" %d",blockWorld[i][j]);
        puts("");
    }
}
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

typedef struct node{
	int r;
	int c;
	int dist;
	int source;
} node;

int map[1005][1005];
bool visit[1005][1005][10];

int dx[8] = {1,1, 1, 0, 0,-1,-1,-1};
int dy[8] = {1,0,-1, 1,-1, 1, 0,-1};
char table[8] = {'-', 'B', 'Y', 'G', 'R', 'P', 'O', 'D'};
int colorNum[8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	
	while(t--)
	{
		int n, max = 0; 
		string color; 
		queue<node> q;
		cin >> n;

		/* Reset */
		// memset(map,0,sizeof(int)*n*n);
		// memset(visit,0,sizeof(bool)*n*n*8);
		// memset(colorNum,0,sizeof(colorNum));
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j< n ; j++)
			{
				map[i][j] = 0;
				for(int k=0 ; k<8 ; k++)
					visit[i][j][k] = 0;
			}
		}
		for(int i=0 ; i<8 ; i++)
			colorNum[i] = 0;

		/* 3 start point */
		for(int i=0 ; i<3 ; i++)
		{
			node start;
			/* Init start point */
			cin >> color >> start.r >> start.c;
			if(color == "R")		start.source = 4;
			else if(color == "Y")	start.source = 2;
			else if(color == "B")	start.source = 1;
			start.dist = 0;

			/* Into queue */
			colorNum[map[start.r][start.c]]--;
			map[start.r][start.c] |= start.source;
			colorNum[map[start.r][start.c]]++;
			visit[start.r][start.c][start.source] = true;
			q.push(start);
		}

		/* Target */
		int tarColor;
		cin >> color;
		for(int i=1; i<8; i++)
		{
			if(table[i] == color[0])
			{
				tarColor = i;
				break;
			}	
		}

		/* BFS */
		while(!q.empty())
		{
			int curDist = q.front().dist;
			while(q.front().dist == curDist)
			{
				node curNode = q.front();
				q.pop();

				/* 8 direction */
				for(int i=0 ; i<8 ; i++)
				{
					int nextR = curNode.r + dx[i];
					int nextC = curNode.c + dy[i];

					/* Valid? */
					if(nextR >= n || nextR < 0 || nextC >= n || nextC < 0)
						continue;
					if(visit[nextR][nextC][curNode.source])
						continue;

					node nextNode;
					nextNode.r = nextR;
					nextNode.c = nextC;
					nextNode.source = curNode.source;
					nextNode.dist = curNode.dist + 1;

					/* Color change */
					colorNum[map[nextNode.r][nextNode.c]]--;
					map[nextNode.r][nextNode.c] |= map[curNode.r][curNode.c];
					colorNum[map[nextNode.r][nextNode.c]]++;
					visit[nextNode.r][nextNode.c][nextNode.source] = true;

					q.push(nextNode);
				}
			}

			max = (colorNum[tarColor] > max) ? colorNum[tarColor] : max;

			// for(int i=0 ; i<n ; i++)
			// {
			// 	for(int j=0 ; j<n ; j++)
			// 		cout << table[map[i][j]] << " ";
			// 	cout << "\n";
			// }
			// cout << "\n------------------\n";
		}

		cout << max << "\n";
	}
}
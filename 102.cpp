#include <iostream>
#include <cstdio>

using namespace std;
int bin[5][5];
int step[6];
char type[6][10] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};


int main()
{
	while(cin >> bin[0][0] >> bin[0][1] >> bin[0][2] >> bin[1][0] >> bin[1][1] >> bin[1][2] >> bin[2][0] >> bin[2][1] >> bin[2][2])
	{
		for(int i=0 ; i<6 ; i++)	step[i] = 0;

		/* BCG */
		step[0] = bin[1][0] + bin[2][0] + bin[0][2] + bin[2][2] + bin[0][1] + bin[1][1];
		/* BGC */
		step[1] = bin[1][0] + bin[2][0] + bin[0][1] + bin[2][1] + bin[0][2] + bin[1][2];


		/* CBG */
		step[2] = bin[1][2] + bin[2][2] + bin[0][0] + bin[2][0] + bin[0][1] + bin[1][1];
		/* CGB */
		step[3] = bin[1][2] + bin[2][2] + bin[0][1] + bin[2][1] + bin[0][0] + bin[1][0];

		/* GBC */
		step[4] = bin[1][1] + bin[2][1] + bin[0][0] + bin[2][0] + bin[0][2] + bin[1][2];
		/* GCB */
		step[5] = bin[1][1] + bin[2][1] + bin[0][2] + bin[2][2] + bin[0][0] + bin[1][0];


		int min = step[0];
		int index = 0;
		for(int i=0 ; i<6 ; i++)
		{
			if(step[i] < min)
			{
				index = i;
				min = step[i];
			}
		}
		printf("%s %d\n",type[index], min);
	}
}
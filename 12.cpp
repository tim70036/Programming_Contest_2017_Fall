/* Bug: Map is Slow*/
#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;

char in[2000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(scanf("%s",in) != EOF)
    {
        stack<char> st;
        int len = strlen(in);
        
        if(len % 2 != 0)
        {
            printf("MS\n");
            continue;
        }
        
        /* Ans */
        bool isSM = true;
        
        for(int i=0 ; i<len ; i++)
        {
            
            if(in[i] == '(' || in[i] == '[' || in[i] == '{')
            {
                st.push(in[i]);
            }
            else if(in[i] == ')')
            {
                if(st.empty() || st.top() != '(')
                {
                    isSM = false;
                    break;
                }
                st.pop();
            }
            else if(in[i] == ']')
            {
                if(st.empty() || st.top() != '[')
                {
                    isSM = false;
                    break;
                }
                st.pop();
            }
            else if(in[i] == '}')
            {
                if(st.empty() || st.top() != '{')
                {
                    isSM = false;
                    break;
                }
                st.pop();
            }
        }
        
        if(!st.empty()) isSM = false;
        
        if(isSM)    printf("SM\n");
        else printf("MS\n");
    }
}
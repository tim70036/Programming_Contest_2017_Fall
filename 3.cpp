/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/3 */
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string in;
    while(getline(cin, in))
    {
        string word;
        stringstream instr(in);
        int sum = 0;
        while(instr >> word)
        {
            int num = 0;
            for(auto i : word)
            {
                if(isdigit(i) == false)     break;
                
                num = num * 10 + (i - '0');
            }
            sum += num;
        }
        cout << sum << endl;
    }
}
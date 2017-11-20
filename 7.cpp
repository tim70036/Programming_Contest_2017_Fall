/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/7 */
#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    double r1, r2, i1, i2;
    char op;
    scanf("%lf %lf %c %lf %lf", &r1, &i1, &op, &r2, &i2);
    
    complex<double> a(r1, i1);
    complex<double> b(r2, i2);
    complex<double> c;
    
    if(op == '+')		c = a + b;
    else if(op == '-')	c = a - b;
    else if(op == '*')	c = a * b;
    else				c = a / b;
    
    printf("%.2lf%+.2lfi\n", c.real(), c.imag());
}
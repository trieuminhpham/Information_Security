#include <iostream>
#include "../lib/gf2_10.h"
using namespace std;

int main()
{
    unsigned int m = (1 << 10) | (1 << 3) | 1;

    unsigned int a = 523;
    unsigned int b = 1015;

    cout << "Polynomial m(x) = ";
    print_poly(m);
    cout << "\n";

    cout << "\nFinding inverse of a = " << a << "\n";

    unsigned int inv_a = gf_inverse(a, m);

    cout << "\na^-1 = ";
    print_poly(inv_a);
    cout << "\n";

    cout << "\nFinding inverse of b = " << b << "\n";

    unsigned int inv_b = gf_inverse(b, m);

    cout << "\nb^-1 = ";
    print_poly(inv_b);
    cout << "\n";

    return 0;
}
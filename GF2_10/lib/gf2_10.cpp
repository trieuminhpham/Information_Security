#include "gf2_10.h"
using namespace std;

int degree(unsigned int a)
{
    int deg = -1;
    while (a)
    {
        a >>= 1;
        deg++;
    }
    return deg;
}

unsigned int poly_mul(unsigned int a, unsigned int b)
{
    unsigned int result = 0;
    while (b)
    {
        if (b & 1)
            result ^= a;
        a <<= 1;
        b >>= 1;
    }
    return result;
}

unsigned int poly_mod(unsigned int a, unsigned int mod)
{
    int deg_mod = degree(mod);

    // Thuật toán chia đa thức lấy dư
    while (degree(a) >= deg_mod)
    {
        int shift = degree(a) - deg_mod;
        a ^= (mod << shift);
    }
    return a;
}

void print_poly(unsigned int a)
{
    bool first = true;

    for (int i = 31; i >= 0; i--)
    {
        if (a & (1u << i))
        {
            if (!first) cout << " + ";

            if (i == 0)
                cout << "1";
            else if (i == 1)
                cout << "x";
            else 
                cout << "x^" << i;

            first = false;
        }
    }

    if (first)
        cout << "0";
}

unsigned int gf_inverse(unsigned int a, unsigned int mod)
{
    unsigned int r0 = mod;
    unsigned int r1 = a;

    unsigned int t0 = 0;
    unsigned int t1 = 1;

    cout << "\n===== Extended Euclidean Algorithm =====\n";

    while (r1 != 0)
    {
        int shift = degree(r0) - degree(r1);

        if (shift < 0)
        {
            swap(r0, r1);
            swap(t0, t1);
            shift = degree(r0) - degree(r1);
        }

        unsigned int q = 1 << shift;

        cout << "\nq(x) = ";
        print_poly(q);

        r0 ^= (r1 << shift);
        t0 ^= (t1 << shift);

        cout << "\nr(x) = ";
        print_poly(r0);

        cout << "\nt(x) = ";
        print_poly(t0);

        cout << "\n-----------------------------\n";
    }

    if(r0 == 1)
        return poly_mod(t0, mod);

    return 0;
}
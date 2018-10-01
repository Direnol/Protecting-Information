//
// Created by stanley on 13.09.18.
//

#include <Encrypt.h>
#include <rsa.h>
#include <el_gamal.h>
#include <vernam.h>
#include <shamir.h>

using std::cout, std::endl,
std::cin;

int main()
{
    rsa r;
    r.print();
    cout << r.Decode(r.Encode(12)) << endl;
    el_gamal eg;
    eg.print();
    cout << eg.Decode(eg.Encode(12)) << endl;
    vernam v;
    v.print();
    cout << v.Decode(v.Encode(12)) << endl;
    shamir shamir1;
    shamir shamir2(shamir1.getP());
    shamir1.print();
    shamir2.print();
    cout << shamir2.Decode(shamir1.Decode(shamir2.Encode(shamir1.Encode(12)))) << endl;

    return 0;
}

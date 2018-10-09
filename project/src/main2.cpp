//
// Created by stanley on 13.09.18.
//

#include <Encrypt.h>
#include <rsa.h>
#include <el_gamal.h>
#include <vernam.h>
#include <shamir.h>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string in = "input";

    string our = "ouf_rsa";
    string out_rsa = "out_rsa";

    rsa r(in, our, "rsa_key");
    r.print();
    r.Encode();
    r.setIn_file(our);
    r.setOut_file(out_rsa);
    r.Decode();
    cout << r.Decode(r.Encode(12)) << endl;

    string oul = "oul";
    string out_el = "out_el";

    el_gamal eg(in, oul, "el_key");
    eg.print();
    eg.Encode();
    eg.setIn_file(oul);
    eg.setOut_file(out_el);
    eg.Decode();
    cout << eg.Decode(eg.Encode(12)) << endl;

    string ouv = "ouv";
    string out_v = "out_vern";
    vernam v(in, ouv, "ver_key");
    v.print();
    v.Encode();
    v.setIn_file(ouv);
    v.setOut_file(out_v);
    v.Decode();
    cout << v.Decode(v.Encode(12)) << endl;

    string sh1 = "sh1";
    string sh2 = "sh2";
    string sh3 = "sh3";
    string out_sh = "out_sham";

    shamir shamir1(in, sh1, "sh1_key");
    shamir shamir2(sh1, sh2, "sh2_key", shamir1.getP());
    shamir1.print();
    shamir2.print();

    shamir1.Encode();
    shamir2.Encode();
    shamir1.setIn_file(sh2);
    shamir1.setOut_file(sh3);
    shamir1.Decode();

    shamir2.setIn_file(sh3);
    shamir2.setOut_file(out_sh);
    shamir2.Decode();

    cout << shamir2.Decode(shamir1.Decode(shamir2.Encode(shamir1.Encode(12)))) << endl;

    return 0;
}

#include <Signature.h>
#include <Operation.h>

int main() {
    Signature sing;
    Operation op;
    int64_t m = 123;
    auto pq = op.get_simple_pair();
    sing.EnGamal(m, pq.first, pq.second);
    return 0;
}
//
// Created by direnol on 26.11.18.
//

#ifndef PROTECTION_INFORMATION_NODE_H
#define PROTECTION_INFORMATION_NODE_H


#include <cstdint>
#include <Operation.h>

class Node {
public:
    using node_t = uint64_t;
    using color_t = uint64_t;

    Node(uint64_t node = 0, uint64_t color = 0);

    uint64_t getNode() const;

    void setNode(uint64_t node);

    uint64_t getColor() const;

    void setColor(uint64_t color);

    void encrypt(color_t new_color);

    uint64_t z();

private:
    Operation op;
    node_t node;
    color_t color;
    //    lint P;
    uint64_t Q, N, r, Z, C, D, P;
};


#endif //PROTECTION_INFORMATION_NODE_H

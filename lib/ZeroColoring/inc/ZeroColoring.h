//
// Created by direnol on 26.11.18.
//

#ifndef PROTECTION_INFORMATION_ZEROCOLORING_H
#define PROTECTION_INFORMATION_ZEROCOLORING_H


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <Operation.h>
#include <Graph.h>

#define SIZE_COLOR 3

class ZeroColoring {
    Operation op;
    Graph graph;
    Node::color_t zmap[SIZE_COLOR];


    Node encrypt_v(Node::node_t node);

public:

    enum Color {
        RED, GREEN, BLUE
    };

    void shuffle();

    ZeroColoring(std::istream &in = std::cin);

    bool zero_g();

    void zero_v();

    void print();

    std::string static clr(Node::node_t color);

    std::pair<Node, Node> encrypt_edge(Node::node_t l, Node::node_t r);

};

#endif //PROTECTION_INFORMATION_ZEROCOLORING_H

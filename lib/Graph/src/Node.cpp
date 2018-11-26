//
// Created by direnol on 26.11.18.
//

#include <Node.h>

Node::Node(uint64_t node, uint64_t color) : node(node), color(color)
{}

uint64_t Node::getNode() const
{
    return node;
}

void Node::setNode(uint64_t node)
{
    Node::node = node;
}

uint64_t Node::getColor() const
{
    return color;
}

void Node::setColor(uint64_t color)
{
    Node::color = color;
}

uint64_t Node::z()
{

    return static_cast<uint64_t>(op.powmod(Z, C, N));
}

void Node::encrypt(Node::color_t nc)
{
    setColor(nc);
    this->P = static_cast<uint64_t>(op.get_simple());
    this->Q = static_cast<uint64_t>(op.get_simple());
    this->N = P * Q;
    this->r = ((op.get_simple() >> 2) << 2) | getColor();
    auto F = (P - 1) * (Q - 1);
    auto[d, c] = op.getCD(1 + op.getRand() % (F - 1), F);
    this->C = static_cast<uint64_t>(c);
    this->D = static_cast<uint64_t>(d);
    this->Z = static_cast<uint64_t>(op.powmod(r, D, N));
}

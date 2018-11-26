//
// Created by direnol on 26.11.18.
//

#include <ZeroColoring.h>

ZeroColoring::ZeroColoring(std::istream &in)
{
    uint64_t vertex = 0, edges = 0, color = RED;
    uint64_t v, u;
    for (Node::color_t i = 0; i < (sizeof(zmap) / sizeof(*zmap)); i++) {
        zmap[i] = i;
    }
    in >> vertex >> edges;
    for (auto i = 0; i < vertex; ++i) {
        in >> v >> color;
        this->graph.push(Node(v, color));
    }
    for (auto i = 0; i < edges; ++i) {
        in >> v >> u;
        this->graph.push(Node(v), Node(u));
    }
}

std::string ZeroColoring::clr(Node::node_t color)
{
    switch (color) {
        case ZeroColoring::RED:
            return "red";
        case ZeroColoring::GREEN:
            return "green";
        case ZeroColoring::BLUE:
            return "blue";
        default:
            break;
    }
    return "undef";
}

void ZeroColoring::print()
{
    std::cout << "Nodes: " << graph.size() << " Edges: " << graph.count_edge() << std::endl;
    for (auto it = graph.begin_node(), et = graph.end_node(); it != et; ++it) {
        std::cout << it->first << ": " << clr(it->second.getColor()) << std::endl;
    }
    for (auto it = graph.begin_edge(), et = graph.end_edge(); it != et; ++it) {
        for (auto jt: it->second) {
            std::cout << it->first << " <-> " << jt.first << std::endl;
        }
        std::cout << std::endl;
    }

}

void ZeroColoring::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(zmap), std::end(zmap), g);
}

std::pair<Node, Node> ZeroColoring::encrypt_edge(Node::node_t l, Node::node_t r)
{
    return std::make_pair(encrypt_v(l), encrypt_v(r));
}

Node ZeroColoring::encrypt_v(Node::node_t node)
{
    Node en = graph.get_node(node);
    en.setColor(zmap[en.getColor()]);
    return en;
}

bool ZeroColoring::zero_g()
{
    Node::node_t from_vertex;
    Node from(0), in(0);
    uint64_t z_b1, z_b2;
    uint64_t number_edge = graph.count_edge(), number_vertex = graph.size();
    for (int i = 0; i < number_edge; i++) {
        from_vertex = random() % number_vertex + 1;
        from = graph.get_node(from_vertex);
        in = graph.get_rand_edge_node(from_vertex);
        std::cout << "From: " << from_vertex << " : " << clr(from.getColor()) << std::endl
                  << "To: " << in.getNode() << " : " << clr(in.getColor()) << std::endl;

        z_b1 = from.z();
        z_b2 = in.z();
        std::cout << "z_b1: " << z_b1 << " z_b2: " << z_b2 << std::endl;
        if ((z_b1 & 3) == (z_b2 & 3)) {
            return false;
        }
        zero_v();
    }

    return true;
}

void ZeroColoring::zero_v()
{

    for (auto it = graph.begin_node(), et = graph.end_node(); it != et; ++it) {
        auto color = it->second.getColor();
        it->second.encrypt(zmap[color]);
    }
}


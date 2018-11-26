//
// Created by direnol on 26.11.18.
//

#include <Graph.h>

void Graph::push(Node l, Node r)
{
    auto il = l.getNode();
    auto ir = r.getNode();
    insert(l);
    insert(r);
    graph[il].insert(std::make_pair(ir, true));
    graph[ir].insert(std::make_pair(il, true));


}

void Graph::insert(Node &node)
{
    auto i = node.getNode();
//    if map no contain node
    auto it = nodes.find(i);
    if (it == nodes.end()) {
        nodes.insert(std::make_pair(i, node));
        graph.insert(std::make_pair(i, std::map<Node::node_t, bool>()));
    }
}

void Graph::push(Node node)
{
    insert(node);
}

void Graph::pop_left_edge(Node::node_t from, Node::node_t node)
{
    auto it = graph.find(from);
    if (it == graph.end()) {
        return;
    }
    auto v = it->second.find(node);
    if (v != it->second.end()) {
        it->second.erase(v);
    }
}

void Graph::pop_edge(Node::node_t l, Node::node_t r)
{
    pop_left_edge(l, r);
    pop_left_edge(r, l);

}

void Graph::pop_node(Node::node_t node)
{
    for (auto it: graph[node]) {
        pop_left_edge(it.first, node);
    }
    graph.erase(node);
    nodes.erase(node);

}

size_t Graph::size()
{
    return nodes.size();
}

size_t Graph::count_edge()
{
    size_t count = 0;
    for (auto it: graph) {
        count += it.second.size();
    }
    return count / 2;
}

bool Graph::is_edge(Node::node_t l, Node::node_t r)
{
    auto il = graph.find(l);
    if (il == graph.end()) { return false; }
    return il->second.find(r) != il->second.end();
}

std::map<Node::node_t, Node>::iterator Graph::begin_node()
{
    return nodes.begin();
}

std::map<Node::node_t, Node>::iterator Graph::end_node()
{
    return nodes.end();
}

std::map<Node::node_t, std::map<Node::node_t, bool>>::iterator Graph::begin_edge()
{
    return graph.begin();
}

std::map<Node::node_t, std::map<Node::node_t, bool>>::iterator Graph::end_edge()
{
    return graph.end();
}

std::map<Node::node_t, bool>::iterator Graph::begin_edge(Node::node_t node)
{
    return graph[node].begin();
}

bool Graph::node_exist(Node::node_t node)
{
    return nodes.find(node) != nodes.end();
}

std::map<Node::node_t, bool>::iterator Graph::end_edge(Node::node_t node)
{
    return graph[node].end();
}

Node Graph::get_node(Node::node_t node)
{
    return nodes[node];
}

size_t Graph::count_edge(Node::node_t node)
{
    return graph[node].size();
}

Node Graph::get_rand_edge_node(Node::node_t node_from)
{
    auto it = graph[node_from].begin();
    std::advance(it, op.getRand() % count_edge(node_from));
    return nodes[it->first];
}


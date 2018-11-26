//
// Created by direnol on 26.11.18.
//

#ifndef PROTECTION_INFORMATION_GRAPH_H
#define PROTECTION_INFORMATION_GRAPH_H


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <Operation.h>
#include "Node.h"

class Graph {
    Operation op;
    std::map<Node::node_t, std::map<Node::node_t, bool>> graph;
    std::map<Node::node_t, Node> nodes;

    void insert(Node &node);

    void pop_left_edge(Node::node_t from, Node::node_t node);

public:

    std::map<Node::node_t, Node>::iterator begin_node();

    std::map<Node::node_t, Node>::iterator end_node();

    std::map<Node::node_t, std::map<Node::node_t, bool>>::iterator begin_edge();

    std::map<Node::node_t, std::map<Node::node_t, bool>>::iterator end_edge();

    std::map<Node::node_t, bool>::iterator begin_edge(Node::node_t node);

    std::map<Node::node_t, bool>::iterator end_edge(Node::node_t node);

    Node get_node(Node::node_t node);

    bool node_exist(Node::node_t node);

    void push(Node l, Node r);

    void push(Node node);

    void pop_node(Node::node_t node);

    void pop_edge(Node::node_t l, Node::node_t r);

    size_t size();

    size_t count_edge();

    size_t count_edge(Node::node_t node);

    bool is_edge(Node::node_t l, Node::node_t r);

    Node get_rand_edge_node(Node::node_t node_from);
};

//using namespace std;
//
//struct data_vertex{
//    lint P;
//    lint Q;
//    lint N;
//    lint r;
//    lint z;
//    int color;
//    lint c;
//    lint d;
//    vector<lint> vec;
//};
//
//map<int, data_vertex> vmap;
//int number_vertex, number_edge;
//
//void printf_color() {
//    printf("\t\t\t\t\t\t\t[VERTEX]=>COLOR\n\t\t\t");
//    for(int i = 1; i <= number_vertex; ++i){
//        printf("[%d]=>%d, ", i, vmap[i].color);
//    }
//    printf("\n");
//    printf("\t\t\t\t____________________________________________________________\n");
//}
//
//void initialization_data_graph(){
//    FILE *file_graph = fopen("GRAV", "r");
//    if(file_graph == NULL){
//        printf("Ошибка открытия файла\n");
//        return;
//    }
//    fscanf(file_graph, "%d", &number_vertex);
//    fscanf(file_graph, "%d", &number_edge);
//    printf("\t\t\t\t\t\tvertex = %d, edge = %d\n", number_vertex, number_edge);
//
//    for(int i = 1; i <= number_vertex; ++i){
//        struct data_vertex initialization_vertex;
//        vmap[i] = initialization_vertex;
//    }
//
//    for(int i = 0; i < number_edge; ++i){
//        int from_vertex, in_vertex;
//        fscanf(file_graph, "%d", &from_vertex);
//        fscanf(file_graph, "%d", &in_vertex);
//        vmap[from_vertex].vec.push_back(in_vertex);
//        vmap[in_vertex].vec.push_back(from_vertex);
//    }
//
//    for(int i = 1; i <= number_vertex; ++i){
//        printf("\t\t\t\t\t\tvertex = %d, connected = ", i);
//        for (unsigned int j = 0; j < vmap[i].vec.size(); ++j) {
//            printf("%ld, ", vmap[i].vec[j]);
//        }
//        printf("\n");
//    }
//    for(int i = 1; i <= number_vertex; ++i){
//        fscanf(file_graph, "%d", &vmap[i].color);
//    }
//    printf_color();
//    fclose(file_graph);
//}
//
//int generation_simple_number_in_limit(lint MAX_LIMIT) {
//    int simple_number;
//    do{
//        simple_number = (random()  % (MAX_LIMIT - 3) ) + 102;
//    } while(!test_ferma(simple_number));
//    return simple_number;
//}
//
//lint inversion(lint a_euclid, lint b_euclid) {
//    lint inversion_number;
//    struct input_extended_euclid InputArgs;
//    struct output_extended_euclid OutputArgs;
//    InputArgs.a = a_euclid;
//    InputArgs.b = b_euclid;
//    func_extended_euclid(InputArgs, &OutputArgs);
//    if(OutputArgs.d == 1){
//        if(OutputArgs.x < 0){
//            inversion_number = OutputArgs.x + b_euclid;
//        } else {
//            inversion_number = OutputArgs.x;
//        }
//    } else {
//        return -1;
//    }
//    return inversion_number;
//}
//
//void EncryptedVertex(){
//    int offset = 3;
//    for(int i = 1; i <= number_vertex; ++i){
//        vmap[i].color = (vmap[i].color % offset) + 1;//смена цветов сдвигом
//        vmap[i].P = generation_simple_number_in_limit(10000);
//        vmap[i].Q = generation_simple_number_in_limit(10000);
//        vmap[i].N = vmap[i].P * vmap[i].Q;
//
//        vmap[i].r = ((generation_simple_number_in_limit(10000) >> 2) << 2) | vmap[i].color;
//
//        lint phi = (vmap[i].P - 1) * (vmap[i].Q - 1);
//        do {
//            vmap[i].c = generation_simple_number_in_limit(phi);
//            vmap[i].d = inversion(vmap[i].c, phi);
//        } while (vmap[i].d == -1);
//        struct input_fast_pow_mod InputArgs;
//        InputArgs.number = vmap[i].r;
//        InputArgs.pow = vmap[i].d;
//        InputArgs.mod = vmap[i].N;
//        vmap[i].z = func_fast_pow_mod(InputArgs);
//    }
//}
//
//bool EncryptedGraph(){
//    int from_vertex, in_vertex;
//    lint z_b1, z_b2;
//
//    for(int i = 0; i < number_edge; i++){
//        from_vertex = random() % number_vertex + 1;
//        in_vertex = vmap[from_vertex].vec[random() % vmap[from_vertex].vec.size()];
//        printf("\t\t\t\t\t\tfrom_vertex = %d, in_vertex = %d\n", from_vertex, in_vertex);
//        printf_color();
//        struct input_fast_pow_mod InputArgs;
//        InputArgs.number = vmap[from_vertex].z;
//        InputArgs.pow = vmap[from_vertex].c;
//        InputArgs.mod = vmap[from_vertex].N;
//        z_b1 = func_fast_pow_mod(InputArgs);
//
//        InputArgs.number = vmap[in_vertex].z;
//        InputArgs.pow = vmap[in_vertex].c;
//        InputArgs.mod = vmap[in_vertex].N;
//        z_b2 = func_fast_pow_mod(InputArgs);
//        //printf("z_b1 = %ld, z_b2 = %ld\n", z_b1, z_b2);
//        if((z_b1 & 3) == (z_b2 & 3)){
//            printf("FALSE\n");
//            return false;
//        }
//        EncryptedVertex();
//    }
//    printf("TRUE\n");
//    return true;
//
//}
#endif //PROTECTION_INFORMATION_GRAPH_H

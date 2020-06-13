/*
 Filename: Node.h
 Description: Declaration of the class Node to represent the node in huffman
 Author: Hung Tran
 Date: 06/12/2020
 Course: Data Structures II
*/
#ifndef HUFFMAN_TRANHD98_NODE_H
#define HUFFMAN_TRANHD98_NODE_H
#include <string>
#include "utility"
using namespace std;

class Node {
protected:
    string character;
    int frequency;
    Node *left, *right;
public:
    Node(string c, int freq, Node* left, Node*right);
    string getCha();
    int getFreq();
    Node* getLeft();
    Node* getRight();
    ~Node();
};


#endif //HUFFMAN_TRANHD98_NODE_H

/*
 Filename: Node.cpp
 Description: Implement of the class Node to represent the node in huffman
 Author: Hung Tran
 Date: 06/12/2020
 Course: Data Structures II
*/

#include "Node.h"
/**
 * Node Constructor
 * Create a node given its parameter.
 * @param c
 * @param freq
 * @param left
 * @param right
 */
Node::Node(string c, int freq, Node *left, Node *right) {
    character = c;
    frequency = freq;
    this->left = left;
    this->right = right;
}
/**
 * destructor
 */
Node::~Node() {
    if(left){
        delete left;
    }
    if(right){
        delete right;
    }
}
/**
 * left node accessor
 * @return the left node of node
 */
Node *Node::getLeft() {
    return left;
}
/**
 * Right node accessor
 * @return the right node of node
 */
Node *Node::getRight() {
    return right;
}
/**
 * Character accessor
 * @return the character of node
 */
string Node::getCha() {
    return character;
}
/**
 * Frequency accessor
 * @return the frequency of node
 */
int Node::getFreq() {
    return frequency;
}


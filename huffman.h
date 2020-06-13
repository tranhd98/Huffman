/*
 Filename: huffmantree.h
 Description: Declaration of the class HuffmanTree to represent the binary Huffman Tree
 Author: Hung Tran
 Date: 06/12/2020
 Course: Data Structures II
*/

#ifndef HUFFMAN_TRANHD98_HUFFMAN_H
#define HUFFMAN_TRANHD98_HUFFMAN_H
#include <utility>
#include <queue>
#include <map>
#include <fstream>
#include <iostream>
#include "Node.h"
#include "unordered_map"
using namespace std;

struct compare
{
    bool operator()(Node* left,Node* right);
};
struct compared
{
    bool operator()(Node* left,Node* right);
};

class huffman {
    Node *root;
    map<string, string> huffmanCodes;
    map<string, int> tempList;
    string encodedFile;
    string fileRead;
    priority_queue<Node *, vector<Node *>, compare> FreqTable;
    priority_queue<Node *, vector<Node *>, compared> FakeFreqTable;
    string getString(char x);

public:
    void readFile(string filename, int freq[256]);

    void buildFreqTable(int freq[256]);

    void buildHuffman();

    void encode(Node *root, string encoded);

    void printEncoding();

    ~huffman();

    void Write(string output);
};



#endif //HUFFMAN_TRANHD98_HUFFMAN_H

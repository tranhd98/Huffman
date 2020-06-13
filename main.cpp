/*
 Filename: huffmantree.h
 Description: Declaration of the class HuffmanTree to represent the binary Huffman Tree in main using command line
 Author: Hung Tran
 Date: 06/12/2020
 Course: Data Structures II
*/
#include <iostream>
#include <fstream>
#include "huffman.h"
int main(int argc, char* argv[]){
    int freq[256] ={0};
    for(int i = 0; i < argc;++i){
        cout << "Parameter " << i << " :" << argv[i] << endl;
    }
    if(argc != 4){
        cerr << "Not enough or too many arguments" << endl;
        return 1;
    }
    string action = argv[1];
    string input = argv[2];
    string output = argv[3];
    if(action != "-encode"){
        cerr << "Wrong operation, use -encode" << endl;
    }
    else {
        cout << " File (" << input << ") is loaded successfully" << endl;

        huffman huffmanTree;

        huffmanTree.readFile(input, freq);

        huffmanTree.buildFreqTable(freq);

        huffmanTree.buildHuffman();

        huffmanTree.printEncoding();

        huffmanTree.Write(output);
    }
};

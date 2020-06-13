/*
 Filename: huffmantree.cpp
 Description: Implement methods of the class HuffmanTree to represent the binary Huffman Tree
 Author: Hung Tran
 Date: 06/12/2020
 Course: Data Structures II
*/

#include "huffman.h"
#include <memory>
/**
 * String representation of the character from read file
 * @param x
 * @return string representation of character
 */
string huffman::getString(char x) {
    string s(1, x);
    return s;
}
/**
 * read file data
 * read from an filename and update freq array.
 * @param filename file name to read from
 * @param freq the array that store character
 */
void huffman::readFile(string filename, int freq[256]) {
    fileRead = "";
    encodedFile ="";
    char character;
    int i = 0;
    ifstream inFile;
    freq[256] = {0};
    inFile.open(filename);
    if(!inFile.is_open()){
        cout << "unable to open a file" << endl;
        exit(0);
    }
    while(!inFile.eof()){
        inFile.get(character);
        fileRead += character;
        i = character;
        if(character == '\n'){
            ++freq[13];
        }
        else if (character == '\r'){
            ++freq[10];
        }
        else {
            freq[i]++;
        }
    }
    inFile.close();
}
/**
 * build frequency table from character array
 * @param freq the array to store character as ascii code
 */
void huffman::buildFreqTable(int freq[256]) {
    for(int i = 0; i < 256; i++){
        if(freq[i] != 0) {
            if(i == 10){
                tempList.insert(pair<string, int>("LF", freq[i]));
            }
            else if(i == 13){
                tempList.insert(pair<string, int>("CR", freq[i] - 1));
            }
            else {
                tempList.insert(pair<string, int>(getString(char(i)), freq[i]));
            }
        }
    }
    for (auto it :tempList){
        Node * temp = new Node(it.first, it.second, nullptr, nullptr);
        FreqTable.push(temp);
        FakeFreqTable.push(temp);
    }
}
/**
 * build huffman tree based on frequency table
 */
void huffman::buildHuffman() {
    while(FreqTable.size() != 1){
        Node* left = FreqTable.top();
        FreqTable.pop();
        Node* right = FreqTable.top();
        FreqTable.pop();
        int sum = left->getFreq() + right->getFreq();
        string totalString = "";
        totalString = left->getCha() + right->getCha();
        Node*top = new Node(totalString, sum , left, right);
        FreqTable.push(top);
    }
    root = FreqTable.top();
    string encoded = "";
    encode(root, encoded);
}
/**
 * build encode from huffman tree using recursive
 * @param root
 * @param encoded
 */
void huffman::encode(Node *root, string encoded) {
    if(root == nullptr){
        return;
    }
    if( root->getLeft()== nullptr && root->getRight() == nullptr){
        huffmanCodes[root->getCha()] = encoded;
    }
    encode(root->getLeft(), encoded + "1");
    encode(root->getRight(), encoded + "0");
}
/**
 * print string encoding
 * transferring frequency to huffman code
 */
void huffman::printEncoding() {
    priority_queue<Node*, vector<Node*>, compared> temp = FakeFreqTable;
    while(!temp.empty()){
        cout << "{key:  " << temp.top()->getCha() << ", code " << huffmanCodes[temp.top()->getCha()] << "}" << endl;
        temp.pop();
    }
}
/**
 * destructor
 */
huffman::~huffman() {
    delete root;
}
/**
 * write to file with output parameter using encoding table that create from printEncoding() method
 * @param output
 */
void huffman::Write(string output) {
    ofstream outfile;
    outfile.open(output);
    if(!outfile){
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    for(auto i: fileRead){
        encodedFile += huffmanCodes[getString(i)];
    }
    outfile << encodedFile;
    outfile.close();
}
/**
 * compare to get priority queue ascending order according to frequency
 * @param left
 * @param right
 * @return true if left > right
 */
bool compare::operator()(Node *left, Node *right) {
    if(left->getFreq() == right->getFreq()){
       return left->getCha().at(0) > right->getCha().at(0);
    }
    else {
        return left->getFreq() > right->getFreq();
    }
}
/**
 * compare to get priority queue descending order according to frequency
 * @param left
 * @param right
 * @return true if left < right
 */
bool compared::operator()(Node *left, Node *right) {
    if(left->getFreq() == right->getFreq()){
        return left->getCha().at(0) < right->getCha().at(0);
    }
    else {
        return left->getFreq() < right->getFreq();
    }
}

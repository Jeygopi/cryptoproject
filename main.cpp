#include "Blockchain.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    
    Blockchain bChain = Blockchain();

    cout << "Mining block 1..." << endl; //endl is like new line
    bChain.AddBlock(Block(1, "Block 1 Data"));

    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, "Block 2 Data"));

    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, "Block 3 Data"));

    return 0;
};
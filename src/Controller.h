//
// Created by Samia Hafez on 9/3/2019
//

#ifndef COLCHAIN_EDGE_H
#define COLCHAIN_EDGE_H

#include <cstdint>
#include <vector>
#include "Helper.h"
#include "Block.h"


using namespace std;

class Controller {
public:
    Controller();

    void AddBlock(Block bNew);

    int getnofhelpers();
    void addHelper(Helper h);


    void startMining();


private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;
    vector<Helper> helpers;
    Block _GetLastBlock() const;
    void populatechain();
    void updateHelpers();

};

#endif //TESTCHAIN_BLOCKCHAIN_H

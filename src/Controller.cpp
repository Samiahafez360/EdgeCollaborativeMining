#include "Controller.h"
#include "ControllNetworkUtilities.h"

publlic Controller::Controller(){
// cosult the network about the chain to get the last hash and try to min over it
  populatechain();


}

void Controller::AddBlock(Block bNew){

}

int getnofhelpers(){
  return
}

void startMining(){

}

Block _GetLastBlock() const;

void populatechain(){
  //scan the network for the blockchain

  //now we will start with an empty blockchain
  _vChain.emplace_back(0, "Genesis");
}

  void updateHelpers(){
    // scan the network for helpers and which ones are available

    //Now we only add the previously known number.

  }

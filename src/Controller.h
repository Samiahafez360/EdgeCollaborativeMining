//
// Created by Samia Hafez on 9/3/2019
//

#include <cstdint>
#include <vector>
#include <thread>
#include "Helper.h"
#include "Block.h"
#include "ControllerNetworkUtilities.hpp"
#include <mutex>

#include "Helper.h"

using namespace std;

class Controller {
	
public:
	int DIFFICULTY;
	int currentstart;
    Controller();
	Controller(int initial);
    void AddBlock();

    int getnofhelpers();
   
    void startMining();
	void zkp_startMining();
	
	void updateHelpers();
	vector<Helper> helpers;

private:
	std::mutex mutex;
	bool hashFound();
	void sendrangetohelper(unsigned id, uint32_t indrange );
    void zkp_sendrangetohelper(unsigned id, uint32_t indrange );
    
	ControllerNetworkUtilities* netutils;
    uint32_t _nDifficulty;
    vector<Block> _vChain;
    
	vector<int> responses;
	vector<thread> helperths;
    Block _GetLastBlock() const;
	Block* currentblock;
    void populatechain();
    std::chrono::system_clock::time_point starttime;
};

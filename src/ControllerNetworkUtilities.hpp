#ifndef ControllerNetworkUtilities_h
#define ControllerNetworkUtilities_h


#include <cstdint>
#include <vector>
#include "Helper.h"
#include "Block.h"


class ControllerNetworkUtilities {
public:
    ControllerNetworkUtilities(int initial){
      nofhelpers = initial;
    }
	ControllerNetworkUtilities(){
      nofhelpers = 1;
    }

    int getnofAvailableHelpers(){
      return nofhelpers;
    }
    vector<char*> getAvailableHelpers(){
      return IPs;
    }
    void updateHelpers(){
      // network stuff
    }

  private:
    int nofhelpers;
    std::vector<char*> IPs;
};
 #endif 
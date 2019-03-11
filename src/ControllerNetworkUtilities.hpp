

#include <cstdint>
#include <vector>
#include "Helper.h"
#include "Block.h"


class ControllNetworkUtilities {
public:
    ControllNetworkUtilities(int initial){
      nofhelpers = initial;
    }

    int getnofAvailableHelpers(){
      return nofhelpers;
    }
    vector<char*> getAvailableHelpers(){
      return IPs;
    }


  private:
    int nofhelpers;
    std::vector<char*> IPs;
}

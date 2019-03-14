#include "Controller.h"
#include "ControllerNetworkUtilities.hpp"
#include <cmath>
#include <thread>
#include <libff/common/default_types/ec_pp.hpp>
#include <libsnark/common/default_types/r1cs_gg_ppzksnark_pp.hpp>
#include <libsnark/relations/constraint_satisfaction_problems/r1cs/examples/r1cs_examples.hpp>

#include <libsnark/common/default_types/r1cs_ppzksnark_pp.hpp>

#include <libff/algebra/fields/field_utils.hpp>
#include <libsnark/gadgetlib1/gadgets/hashes/sha256/sha256_gadget.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_gg_ppzksnark/r1cs_gg_ppzksnark.hpp>
#include <istream>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_ppzksnark/r1cs_ppzksnark.hpp>
#include <libsnark/gadgetlib1/pb_variable.hpp>
#include <libsnark/gadgetlib1/protoboard.hpp>
#include <iostream>
#include <chrono>


using namespace libsnark;

#define DIFFICULTY 2

Controller::Controller(){
	
// cosult the network about the chain to get the last hash and try to min over it
  populatechain();
  
  netutils = new ControllerNetworkUtilities();
}
Controller::Controller(int initial){
// cosult the network about the chain to get the last hash and try to min over it
  populatechain();
  netutils = new ControllerNetworkUtilities(initial);
}
// before networking
void Controller::AddBlock(){
	_vChain.push_back(*currentblock);
	std::cout<<"adding the block";
}

int Controller::getnofhelpers(){
  
	//networking: return netutils->getnofAvailableHelpers();
	return helpers.size();
}

void Controller::startMining(){
	starttime = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(starttime);

    std::cout << "started mining at " << std::ctime(&start_time);
    
	currentblock = new Block(_vChain.size(), "next block in being mined");
	int n = getnofhelpers();
	long range = powl(2,DIFFICULTY+10);
	long indrange = ceil (range*1.0 /n*1.0);
	for (unsigned i =0 ; i < n ; i++){
		helperths.push_back(std::thread(&Controller::sendrangetohelper,this,i,indrange)); 
	}
	
	
	for (unsigned i =0 ; i < n ; i++){
		helperths[i].join(); 
	}
	for (unsigned i =0 ; i < n ; i++){
		helperths.erase(helperths.begin()+i); 
	}
	
	for (unsigned i =0 ; i < n ; i++){
		if (responses[i]> 0){
			std::cout << "we found the block";
			currentblock->_nNonce = responses[i];
			AddBlock();
			break;
		} 
	}
	
	
	std::cout << "foo and bar completed.\n";
}

void Controller::sendrangetohelper(unsigned id, uint32_t indrange ){
	std::cout<<"\n thread "<< id <<"is starting" << indrange;
	responses[id] = helpers[id].minenozk(id*indrange, indrange, DIFFICULTY, *currentblock,starttime);
}



void Controller::zkp_startMining(){
	
	starttime = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(starttime);

    std::cout << "started mining at " << std::ctime(&start_time);
    
	
	currentblock = new Block(_vChain.size(), "next block in being mined");
	int n = getnofhelpers();
	long range = powl(2,DIFFICULTY+10);
	long indrange = ceil (range*1.0 /n*1.0);
	for (unsigned i =0 ; i < n ; i++){
		
		helperths.push_back(std::thread(&Controller::zkp_sendrangetohelper,this,i,indrange)); 
	}
	
	
	for (unsigned i =0 ; i < n ; i++){
		helperths[i].join(); 
	}
	for (unsigned i =0 ; i < n ; i++){
		helperths.erase(helperths.begin()+i); 
	}
	for (unsigned i =0 ; i < n ; i++){
		if (responses[i]> 0){
			std::cout << "we found the block";
			currentblock->_nNonce = responses[i];
			AddBlock();
			break;
		} 
	}
	
	
	std::cout << "mining with zk snarks completed \n \n \n \n \n \n ";
}


typedef libff::Fr<default_r1cs_ppzksnark_pp> FieldT;

void Controller::zkp_sendrangetohelper(unsigned id, uint32_t indrange ){
	//generate the keys
	
	
	
	protoboard<FieldT> pb;
	
    block_variable<FieldT>  input(pb, SHA256_block_size, "input");
    digest_variable<FieldT> output(pb, SHA256_digest_size, "output");
    sha256_two_to_one_hash_gadget<FieldT> sha256_gadget(pb, SHA256_block_size, input, output, "hash_gadget");
	std::cout<<"\n thread "<< id <<"is starting" ;
	
    sha256_gadget.generate_r1cs_constraints();

    
    const auto constraint_system = pb.get_constraint_system();

    // Create keypair
    auto keypair = r1cs_ppzksnark_generator<default_r1cs_ppzksnark_pp>(constraint_system);

	std::cout<<"\n thread "<< id <<"is starting" ;
	
	//const auto proof;
	
	responses[id] = helpers[id].minezk(id*indrange, indrange, DIFFICULTY, *currentblock, keypair.pk,starttime);
	
	//verify the proof
	bool verified = r1cs_ppzksnark_verifier_strong_IC<default_r1cs_ppzksnark_pp>(keypair.vk, pb.primary_input(), helpers[id].proof);
	cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%the proof is "<< verified;
}
Block Controller::_GetLastBlock() const{
	
}

void Controller::populatechain(){
  //scan the network for the blockchain

  //now we will start with an empty blockchain
  _vChain.emplace_back(0, "Genesis");
}

  void Controller::updateHelpers(){
    // scan the network for helpers and which ones are available

    //Now we only add the previously known number.
	helpers.emplace_back();
	responses.push_back(-1);

  }

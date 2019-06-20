
#include "Helper.h"
#include "sha256.h"
#include "Block.h"
#include <chrono>


int Helper::minenozk(uint32_t _sNonce, uint32_t range, uint32_t nDifficulty,Block mBlock,std::chrono::system_clock::time_point starttime)
{

	char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
	string str(cstr);
	uint32_t _nNonce = _sNonce;
	string sHash;
    do
    {
        sHash = _CalculateHash(mBlock._nIndex, _nNonce,mBlock.sPrevHash,mBlock._tTime,mBlock._sData);
		_nNonce++;
		if (sHash.substr(0, nDifficulty) == str){
			cout<<"\n FOOOOUUUUNNNNNNDDDDDDDD after"<<_nNonce-_sNonce<< "trials" <<_nNonce<<"\n";
			
			auto end = std::chrono::system_clock::now();
			
			std::chrono::duration<double> elapsed_seconds = end-starttime;
        	std::cout << "^^^^^^^^^^^^^^^^@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%%finished computation at " << "elapsed time: " << elapsed_seconds.count() << "s\n";
			return _nNonce-1;
		}
    }
    while (_sNonce+range >= _nNonce);
	cout<<"\n not FOOOOUUUUNNNNNNDDDD";
    return -1;
	
	
}
inline string Helper::_CalculateHash(uint32_t _nIndex, uint32_t _nNonce,string sPrevHash,time_t _tTime,string _sData) const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;
    //cout << "\n choose one" << &ss;
    return sha256(ss.str());
}

typedef libff::Fr<default_r1cs_ppzksnark_pp> FieldT;

int Helper::minezk(uint32_t start, uint32_t range,uint32_t nDifficulty,Block mBlock,r1cs_ppzksnark_proving_key<default_r1cs_ppzksnark_pp> pk,std::chrono::system_clock::time_point starttime)
{
	//create the board and the gadget
	std::cout << "\nCreate the board and the gadget\n";
	protoboard<FieldT> pb;

    block_variable<FieldT>  input(pb, SHA256_block_size, "input");
    digest_variable<FieldT> output(pb, SHA256_digest_size, "output");
    sha256_two_to_one_hash_gadget<FieldT> sha256_gadget(pb, SHA256_block_size, input, output, "hash_gadget");

    sha256_gadget.generate_r1cs_constraints();
	
	
	//do ordinary work
	
	char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
	string str(cstr);
	uint32_t _nNonce = start;
	string sHash;
    do
    {
		
		libff::print_header("Mining loooooooooppppp");
		
		stringstream ss;
		std::cout << "\nprepare the stream\n";
	
		ss << mBlock._nIndex << mBlock.sPrevHash << mBlock._tTime << mBlock._sData << _nNonce;
    
		sHash = sha256(ss.str());
		
		std::cout << "\nwitnessing \n";
	
		std::vector<bool> myVec;
		for(auto a : ss.str()) myVec.push_back(a =='1');
		const libff::bit_vector input_bv = myVec;
		input.generate_r1cs_witness(input_bv);
    
		std::vector<bool> myhashVec;
		for(auto a : sHash) myhashVec.push_back(a =='1');
		const libff::bit_vector hash_bv =myhashVec;
		output.generate_r1cs_witness(hash_bv);

		sha256_gadget.generate_r1cs_witness();
		_nNonce++;
		std::cout << "\nProving\n";
	
		proof = r1cs_ppzksnark_prover<default_r1cs_ppzksnark_pp>(pk, pb.primary_input(), pb.auxiliary_input());
		proof.print_size();
		
		if (sHash.substr(0, nDifficulty) == str){
			cout<<"\n FOOOOUUUUNNNNNNDDDDDDDD after"<<_nNonce-start<< "trials" <<_nNonce<<"\n";
			
			auto end = std::chrono::system_clock::now();
			
			std::chrono::duration<double> elapsed_seconds = end-starttime;
        	std::cout << "^^^^^^^^^^^^^^^^@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%%finished computation at " << "elapsed time: " << elapsed_seconds.count() << "s\n";
			
			return _nNonce-1;
		}
    }
    while (start+range >= _nNonce);
	cout<<"\n not FOOOOUUUUNNNNNNDDDD";
    return -1;
	
	
	


}

/*void Helper::setVK (bacs_ppzksnark_verification_key vk){
  verificationKey = vk;
}*/
  char* Helper::getIP(){
    return IP;
  }

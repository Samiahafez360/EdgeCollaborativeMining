
#include <cstdint>
#include <vector>
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


class Helper{
public:
    Helper();
    int minenozk(uint32_t start, uint32_t range);
    int minezk(uint32_t start, uint32_t range);

    void setVK (bacs_ppzksnark_verification_key vk);
    char* getIP();

private:

    char* IP;
    bacs_ppzksnark_verification_key verificationKey;

}

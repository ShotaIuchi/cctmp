//#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
//#define BOOST_MPL_LIMIT_VECTOR_SIZE 30
#define FUSION_MAX_VECTOR_SIZE 30

#include <iostream>
#include "proj_state_machine/state_machine.hh"
#include "proj_state_machine/state_machine_imple.hh"
#include "proj_state_machine/big_state_machine.hh"

int main(int argc, char* argv[])
{
    std::cout << "__state_machine__" << std::endl;
    state_machine::StateMachine m1;
    m1.start();
    big_state_machine::StateMachine m2;
    m2.start();
    return 0;
}

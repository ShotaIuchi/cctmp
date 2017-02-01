#include <iostream>
#include "proj_state_machine/state_machine.hh"

using namespace state_machine;

int main(int argc, char* argv[])
{
    std::cout << "__state_machine__" << std::endl;
    StateMachine m;
    m.start();
    return 0;
}

template <class T_EVENT> void StateMachine_::onEvent01(T_EVENT const& e) {
    std::cout << "onEvent01" << std::endl;
}
template <class T_EVENT> void StateMachine_::onEvent02(T_EVENT const& e) {
    std::cout << "onEvent02" << std::endl;
}

template <class T_EVENT, class T_STATE_MACHINE> void STATE_XXX_01::on_entry(T_EVENT const& e, T_STATE_MACHINE& m) {
    std::cout << "STATE_XXX_01::on_entry" << std::endl;
    m.process_event(EVENT_XXX_01());
}
template <class T_EVENT, class T_STATE_MACHINE> void STATE_XXX_01::on_exit (T_EVENT const& e, T_STATE_MACHINE& m) {
    std::cout << "STATE_XXX_01::on_exit" << std::endl;
}

template <class T_EVENT, class T_STATE_MACHINE> void STATE_XXX_02::on_entry(T_EVENT const& e, T_STATE_MACHINE& m) {
    std::cout << "STATE_XXX_02::on_entry" << std::endl;
    m.process_event(EVENT_XXX_02());
}
template <class T_EVENT, class T_STATE_MACHINE> void STATE_XXX_02::on_exit (T_EVENT const& e, T_STATE_MACHINE& m) {
    std::cout << "STATE_XXX_02::on_exit" << std::endl;
}

template <class T_EVENT, class T_STATE_MACHINE> void STATE_XXX_03::on_entry(T_EVENT const& e, T_STATE_MACHINE& m) {
    std::cout << "STATE_XXX_03::on_entry" << std::endl;
    m.process_event(EVENT_XXX_03());
}
template <class T_EVENT, class T_STATE_MACHINE> void STATE_XXX_03::on_exit (T_EVENT const& e, T_STATE_MACHINE& m) {
    std::cout << "STATE_XXX_03::on_exit" << std::endl;
}

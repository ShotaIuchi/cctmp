#ifndef __STATE_MACHINE_HH__
#define __STATE_MACHINE_HH__

#include <iostream>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/back/state_machine.hpp>

namespace state_machine {

struct STATE_XXX_01 : boost::msm::front::state<>
{
    template <class T_EVENT, class T_STATE_MACHINE> void on_entry(T_EVENT const& e, T_STATE_MACHINE& m);
    template <class T_EVENT, class T_STATE_MACHINE> void on_exit (T_EVENT const& e, T_STATE_MACHINE& m);
};
struct STATE_XXX_02 : boost::msm::front::state<>
{
    template <class T_EVENT, class T_STATE_MACHINE> void on_entry(T_EVENT const& e, T_STATE_MACHINE& m);
    template <class T_EVENT, class T_STATE_MACHINE> void on_exit (T_EVENT const& e, T_STATE_MACHINE& m);
};
struct STATE_XXX_03 : boost::msm::front::state<>
{
    template <class T_EVENT, class T_STATE_MACHINE> void on_entry(T_EVENT const& e, T_STATE_MACHINE& m);
    template <class T_EVENT, class T_STATE_MACHINE> void on_exit (T_EVENT const& e, T_STATE_MACHINE& m);
};

struct EVENT_XXX_01 {};
struct EVENT_XXX_02 {};
struct EVENT_XXX_03 {};

struct StateMachine_ : boost::msm::front::state_machine_def<StateMachine_>
{
    template <class T_EVENT> void onEvent01(T_EVENT const& e);
    template <class T_EVENT> void onEvent02(T_EVENT const& e);

    template <class T_EVENT> bool guardPass(T_EVENT const& e) { return true;  }
    template <class T_EVENT> bool guardStop(T_EVENT const& e) { return false; }

    struct transition_table : boost::mpl::vector <
        //       | source       | event         | target        | action                    | guard
            row< STATE_XXX_01,  EVENT_XXX_01,   STATE_XXX_02,   &StateMachine_::onEvent01,  &StateMachine_::guardPass   >
        ,   row< STATE_XXX_01,  EVENT_XXX_02,   STATE_XXX_01,   &StateMachine_::onEvent01,  &StateMachine_::guardPass   >
        , g_row< STATE_XXX_01,  EVENT_XXX_03,   STATE_XXX_01,                               &StateMachine_::guardStop   >
        //       | source       | event         | target        | action                    | guard
        , g_row< STATE_XXX_02,  EVENT_XXX_01,   STATE_XXX_01,                               &StateMachine_::guardStop   >
        ,   row< STATE_XXX_02,  EVENT_XXX_02,   STATE_XXX_03,   &StateMachine_::onEvent01,  &StateMachine_::guardPass   >
        ,   row< STATE_XXX_02,  EVENT_XXX_03,   STATE_XXX_03,   &StateMachine_::onEvent01,  &StateMachine_::guardPass   >
        //       | source       | event         | target        | action                    | guard
        , g_row< STATE_XXX_03,  EVENT_XXX_01,   STATE_XXX_01,                               &StateMachine_::guardStop   >
        , g_row< STATE_XXX_03,  EVENT_XXX_02,   STATE_XXX_01,                               &StateMachine_::guardStop   >
        , g_row< STATE_XXX_03,  EVENT_XXX_03,   STATE_XXX_01,                               &StateMachine_::guardStop   >
        > {};

    typedef STATE_XXX_01 initial_state;
};

typedef boost::msm::back::state_machine<StateMachine_> StateMachine;

};

#endif // __STATE_MACHINE_HH__

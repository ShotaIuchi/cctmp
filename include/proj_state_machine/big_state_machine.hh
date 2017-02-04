#ifndef __BIG_STATE_MACHINE_HH__
#define __BIG_STATE_MACHINE_HH__

#include <iostream>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/back/state_machine.hpp>

namespace big_state_machine {

struct STATE_XXX_01 : boost::msm::front::state<>{};
struct STATE_XXX_02 : boost::msm::front::state<>{};
struct STATE_XXX_03 : boost::msm::front::state<>{};
struct STATE_XXX_04 : boost::msm::front::state<>{};
struct STATE_XXX_05 : boost::msm::front::state<>{};
struct STATE_XXX_06 : boost::msm::front::state<>{};
struct STATE_XXX_07 : boost::msm::front::state<>{};
struct STATE_XXX_08 : boost::msm::front::state<>{};
struct STATE_XXX_09 : boost::msm::front::state<>{};
struct STATE_XXX_10 : boost::msm::front::state<>{};
struct STATE_XXX_11 : boost::msm::front::state<>{};
struct STATE_XXX_12 : boost::msm::front::state<>{};
struct STATE_XXX_13 : boost::msm::front::state<>{};
struct STATE_XXX_14 : boost::msm::front::state<>{};

struct EVENT_XXX_01 {};
struct EVENT_XXX_02 {};
struct EVENT_XXX_03 {};

struct SM : boost::msm::front::state_machine_def<SM>
{
    template <class T_EVENT> bool GUARD_NEXT(T_EVENT const& e) { return true;  }
    template <class T_EVENT> bool GUARD_STOP(T_EVENT const& e) { return false; }

    template <class T_EVENT> void ACTION_XXX_01(T_EVENT const& e) {}
    template <class T_EVENT> void ACTION_XXX_02(T_EVENT const& e) {}

    struct transition_table : boost::mpl::vector <
        //       | source       | event         | target        | action            | guard
            row< STATE_XXX_01,  EVENT_XXX_01,   STATE_XXX_02,   &SM::ACTION_XXX_01, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_02,  EVENT_XXX_02,   STATE_XXX_03,   &SM::ACTION_XXX_01, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_03,  EVENT_XXX_02,   STATE_XXX_04,   &SM::ACTION_XXX_01, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_04,  EVENT_XXX_02,   STATE_XXX_05,   &SM::ACTION_XXX_01, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_05,  EVENT_XXX_02,   STATE_XXX_06,   &SM::ACTION_XXX_01, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_06,  EVENT_XXX_02,   STATE_XXX_07,   &SM::ACTION_XXX_01, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_07,  EVENT_XXX_02,   STATE_XXX_08,   &SM::ACTION_XXX_01, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_08,  EVENT_XXX_02,   STATE_XXX_09,   &SM::ACTION_XXX_02, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_09,  EVENT_XXX_02,   STATE_XXX_10,   &SM::ACTION_XXX_02, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_10,  EVENT_XXX_02,   STATE_XXX_11,   &SM::ACTION_XXX_02, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_11,  EVENT_XXX_02,   STATE_XXX_12,   &SM::ACTION_XXX_02, &SM::GUARD_NEXT >
        ,   row< STATE_XXX_12,  EVENT_XXX_02,   STATE_XXX_13,   &SM::ACTION_XXX_02, &SM::GUARD_STOP >
        ,   row< STATE_XXX_13,  EVENT_XXX_02,   STATE_XXX_14,   &SM::ACTION_XXX_02, &SM::GUARD_STOP >
        ,   row< STATE_XXX_14,  EVENT_XXX_02,   STATE_XXX_01,   &SM::ACTION_XXX_02, &SM::GUARD_STOP >
        > {};

    typedef STATE_XXX_01 initial_state;
};

typedef boost::msm::back::state_machine<SM> StateMachine;

};

#endif // __BIG_STATE_MACHINE_HH__

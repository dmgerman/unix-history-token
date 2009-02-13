begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant/hostapd - State machine definitions  * Copyright (c) 2002-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  *  * This file includes a set of pre-processor macros that can be used to  * implement a state machine. In addition to including this header file, each  * file implementing a state machine must define STATE_MACHINE_DATA to be the  * data structure including state variables (enum<machine>_state,  * Boolean changed), and STATE_MACHINE_DEBUG_PREFIX to be a string that is used  * as a prefix for all debug messages. If SM_ENTRY_MA macro is used to define  * a group of state machines with shared data structure, STATE_MACHINE_ADDR  * needs to be defined to point to the MAC address used in debug output.  * SM_ENTRY_M macro can be used to define similar group of state machines  * without this additional debug info.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STATE_MACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|STATE_MACHINE_H
end_define

begin_comment
comment|/**  * SM_STATE - Declaration of a state machine function  * @machine: State machine name  * @state: State machine state  *  * This macro is used to declare a state machine function. It is used in place  * of a C function definition to declare functions to be run when the state is  * entered by calling SM_ENTER or SM_ENTER_GLOBAL.  */
end_comment

begin_define
define|#
directive|define
name|SM_STATE
parameter_list|(
name|machine
parameter_list|,
name|state
parameter_list|)
define|\
value|static void sm_ ## machine ## _ ## state ## _Enter(STATE_MACHINE_DATA *sm, \ 	int global)
end_define

begin_comment
comment|/**  * SM_ENTRY - State machine function entry point  * @machine: State machine name  * @state: State machine state  *  * This macro is used inside each state machine function declared with  * SM_STATE. SM_ENTRY should be in the beginning of the function body, but  * after declaration of possible local variables. This macro prints debug  * information about state transition and update the state machine state.  */
end_comment

begin_define
define|#
directive|define
name|SM_ENTRY
parameter_list|(
name|machine
parameter_list|,
name|state
parameter_list|)
define|\
value|if (!global || sm->machine ## _state != machine ## _ ## state) { \ 	sm->changed = TRUE; \ 	wpa_printf(MSG_DEBUG, STATE_MACHINE_DEBUG_PREFIX ": " #machine \ 		   " entering state " #state); \ } \ sm->machine ## _state = machine ## _ ## state;
end_define

begin_comment
comment|/**  * SM_ENTRY_M - State machine function entry point for state machine group  * @machine: State machine name  * @_state: State machine state  * @data: State variable prefix (full variable:<prefix>_state)  *  * This macro is like SM_ENTRY, but for state machine groups that use a shared  * data structure for more than one state machine. Both machine and prefix  * parameters are set to "sub-state machine" name. prefix is used to allow more  * than one state variable to be stored in the same data structure.  */
end_comment

begin_define
define|#
directive|define
name|SM_ENTRY_M
parameter_list|(
name|machine
parameter_list|,
name|_state
parameter_list|,
name|data
parameter_list|)
define|\
value|if (!global || sm->data ## _ ## state != machine ## _ ## _state) { \ 	sm->changed = TRUE; \ 	wpa_printf(MSG_DEBUG, STATE_MACHINE_DEBUG_PREFIX ": " \ 		   #machine " entering state " #_state); \ } \ sm->data ## _ ## state = machine ## _ ## _state;
end_define

begin_comment
comment|/**  * SM_ENTRY_MA - State machine function entry point for state machine group  * @machine: State machine name  * @_state: State machine state  * @data: State variable prefix (full variable:<prefix>_state)  *  * This macro is like SM_ENTRY_M, but a MAC address is included in debug  * output. STATE_MACHINE_ADDR has to be defined to point to the MAC address to  * be included in debug.  */
end_comment

begin_define
define|#
directive|define
name|SM_ENTRY_MA
parameter_list|(
name|machine
parameter_list|,
name|_state
parameter_list|,
name|data
parameter_list|)
define|\
value|if (!global || sm->data ## _ ## state != machine ## _ ## _state) { \ 	sm->changed = TRUE; \ 	wpa_printf(MSG_DEBUG, STATE_MACHINE_DEBUG_PREFIX ": " MACSTR " " \ 		   #machine " entering state " #_state, \ 		   MAC2STR(STATE_MACHINE_ADDR)); \ } \ sm->data ## _ ## state = machine ## _ ## _state;
end_define

begin_comment
comment|/**  * SM_ENTER - Enter a new state machine state  * @machine: State machine name  * @state: State machine state  *  * This macro expands to a function call to a state machine function defined  * with SM_STATE macro. SM_ENTER is used in a state machine step function to  * move the state machine to a new state.  */
end_comment

begin_define
define|#
directive|define
name|SM_ENTER
parameter_list|(
name|machine
parameter_list|,
name|state
parameter_list|)
define|\
value|sm_ ## machine ## _ ## state ## _Enter(sm, 0)
end_define

begin_comment
comment|/**  * SM_ENTER_GLOBAL - Enter a new state machine state based on global rule  * @machine: State machine name  * @state: State machine state  *  * This macro is like SM_ENTER, but this is used when entering a new state  * based on a global (not specific to any particular state) rule. A separate  * macro is used to avoid unwanted debug message floods when the same global  * rule is forcing a state machine to remain in on state.  */
end_comment

begin_define
define|#
directive|define
name|SM_ENTER_GLOBAL
parameter_list|(
name|machine
parameter_list|,
name|state
parameter_list|)
define|\
value|sm_ ## machine ## _ ## state ## _Enter(sm, 1)
end_define

begin_comment
comment|/**  * SM_STEP - Declaration of a state machine step function  * @machine: State machine name  *  * This macro is used to declare a state machine step function. It is used in  * place of a C function definition to declare a function that is used to move  * state machine to a new state based on state variables. This function uses  * SM_ENTER and SM_ENTER_GLOBAL macros to enter new state.  */
end_comment

begin_define
define|#
directive|define
name|SM_STEP
parameter_list|(
name|machine
parameter_list|)
define|\
value|static void sm_ ## machine ## _Step(STATE_MACHINE_DATA *sm)
end_define

begin_comment
comment|/**  * SM_STEP_RUN - Call the state machine step function  * @machine: State machine name  *  * This macro expands to a function call to a state machine step function  * defined with SM_STEP macro.  */
end_comment

begin_define
define|#
directive|define
name|SM_STEP_RUN
parameter_list|(
name|machine
parameter_list|)
value|sm_ ## machine ## _Step(sm)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STATE_MACHINE_H */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the functionality common to all state  *        machine object implementations.  */
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/sci_base_state_machine.h>
end_include

begin_define
define|#
directive|define
name|SCI_STATE_MACHINE_EXIT_STATE
parameter_list|(
name|state_machine
parameter_list|)
define|\
value|if ( \        ((state_machine)->state_table[(state_machine)->current_state_id].\           exit_state != NULL) \       ) \    { \       ((state_machine)->state_table[(state_machine)->current_state_id].\       exit_state((state_machine)->state_machine_owner)); \    }
end_define

begin_define
define|#
directive|define
name|SCI_STATE_MACHINE_ENTER_STATE
parameter_list|(
name|state_machine
parameter_list|)
define|\
value|((state_machine)->state_table[(state_machine)->current_state_id].\       enter_state((state_machine)->state_machine_owner))
end_define

begin_define
define|#
directive|define
name|SCI_STATE_MACHINE_SET_STATE
parameter_list|(
name|state_machine
parameter_list|,
name|id
parameter_list|)
define|\
value|((state_machine)->current_state_id = (id))
end_define

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* P R O T E C T E D    M E T H O D S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method will set the initial state and state table  *        for the state machine. The caller should follow this  *        request with the initialize request to cause the state  *        machine to start.  *  * @param[in] this_state_machine This parameter provides the state machine  *            object to be constructed.  * @param[in] state_machine_owner This parameter indicates the object that  *            is owns the state machine being constructed.  * @param[in] state_table This parameter specifies the table of state objects  *            that is managed by this state machine.  * @param[in] initial_state This parameter specifies the value of the initial  *            state for this state machine.  *  * @return none  */
end_comment

begin_function
name|void
name|sci_base_state_machine_construct
parameter_list|(
name|SCI_BASE_STATE_MACHINE_T
modifier|*
name|this_state_machine
parameter_list|,
name|SCI_BASE_OBJECT_T
modifier|*
name|my_state_machine_owner
parameter_list|,
name|SCI_BASE_STATE_T
modifier|*
name|state_table
parameter_list|,
name|U32
name|initial_state
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|SCI_LOGGING
argument_list|)
name|sci_base_subject_construct
argument_list|(
operator|&
name|this_state_machine
operator|->
name|parent
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// defined(SCI_LOGGING)
name|this_state_machine
operator|->
name|state_machine_owner
operator|=
name|my_state_machine_owner
expr_stmt|;
name|this_state_machine
operator|->
name|initial_state_id
operator|=
name|initial_state
expr_stmt|;
name|this_state_machine
operator|->
name|previous_state_id
operator|=
name|initial_state
expr_stmt|;
name|this_state_machine
operator|->
name|current_state_id
operator|=
name|initial_state
expr_stmt|;
name|this_state_machine
operator|->
name|state_table
operator|=
name|state_table
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * @brief This method will cause the state machine to enter the  *        initial state.  *  * @see sci_base_state_machine_construct() for how to set the initial state  *  * @param[in] this_state_machine This parameter specifies the state machine  *            that is to be started.  *  * @return none  */
end_comment

begin_function
name|void
name|sci_base_state_machine_start
parameter_list|(
name|SCI_BASE_STATE_MACHINE_T
modifier|*
name|this_state_machine
parameter_list|)
block|{
name|SCI_STATE_MACHINE_SET_STATE
argument_list|(
name|this_state_machine
argument_list|,
name|this_state_machine
operator|->
name|initial_state_id
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SCI_BASE_ENABLE_SUBJECT_NOTIFICATION
argument_list|)
name|sci_base_subject_notify
argument_list|(
operator|&
name|this_state_machine
operator|->
name|parent
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|SCI_STATE_MACHINE_ENTER_STATE
argument_list|(
name|this_state_machine
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * @brief This method will cause the state machine to exit it's current  *        state only.  *  * @param[in] this_state_machine This parameter specifies the state machine  *            that is to be stopped.  *  * @return none  */
end_comment

begin_function
name|void
name|sci_base_state_machine_stop
parameter_list|(
name|SCI_BASE_STATE_MACHINE_T
modifier|*
name|this_state_machine
parameter_list|)
block|{
name|SCI_STATE_MACHINE_EXIT_STATE
argument_list|(
name|this_state_machine
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SCI_BASE_ENABLE_SUBJECT_NOTIFICATION
argument_list|)
name|sci_base_subject_notify
argument_list|(
operator|&
name|this_state_machine
operator|->
name|parent
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/**  * @brief This method performs an update to the current state of  *        the state machine.  *  * @param[in] this_state_machine This parameter specifies the state machine  *            for which the caller wishes to perform a state change.  * @param[in] next_state This parameter specifies the new state for the  *            state machine.  *  * @return none  */
end_comment

begin_function
name|void
name|sci_base_state_machine_change_state
parameter_list|(
name|SCI_BASE_STATE_MACHINE_T
modifier|*
name|this_state_machine
parameter_list|,
name|U32
name|next_state
parameter_list|)
block|{
name|SCI_STATE_MACHINE_EXIT_STATE
argument_list|(
name|this_state_machine
argument_list|)
expr_stmt|;
name|this_state_machine
operator|->
name|previous_state_id
operator|=
name|this_state_machine
operator|->
name|current_state_id
expr_stmt|;
name|SCI_STATE_MACHINE_SET_STATE
argument_list|(
name|this_state_machine
argument_list|,
name|next_state
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SCI_BASE_ENABLE_SUBJECT_NOTIFICATION
argument_list|)
comment|// Notify of the state change prior to entering the state.
name|sci_base_subject_notify
argument_list|(
operator|&
name|this_state_machine
operator|->
name|parent
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|SCI_STATE_MACHINE_ENTER_STATE
argument_list|(
name|this_state_machine
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * @brief This method simply returns the current state of the  *         state machine to the caller.  *  * @param[in] this_state_machine  This parameter specifies the state  *            machine for which to retrieve the current state.  *  * @return This method returns a U32 value indicating the current state for  *         the supplied state machine.  */
end_comment

begin_function
name|U32
name|sci_base_state_machine_get_state
parameter_list|(
name|SCI_BASE_STATE_MACHINE_T
modifier|*
name|this_state_machine
parameter_list|)
block|{
return|return
name|this_state_machine
operator|->
name|current_state_id
return|;
block|}
end_function

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_STATE_MACHINE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_STATE_MACHINE_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all structures, constants, or method declarations  *        common to all state machines defined in SCI.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// __cplusplus
include|#
directive|include
file|<dev/isci/scil/sci_base_subject.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_state.h>
comment|/**  * This macro simply provides simplified retrieval of an objects state  * handler.  */
define|#
directive|define
name|SET_STATE_HANDLER
parameter_list|(
name|object
parameter_list|,
name|table
parameter_list|,
name|state
parameter_list|)
define|\
value|(object)->state_handlers =&(table)[(state)]
comment|/**  * @struct SCI_BASE_STATE_MACHINE  *  * @brief This structure defines the fields common to all state machines.  */
typedef|typedef
struct|struct
name|SCI_BASE_STATE_MACHINE
block|{
if|#
directive|if
name|defined
argument_list|(
name|SCI_LOGGING
argument_list|)
comment|/**     * The state machine object participates in the observer design pattern.     * Thus, the SCI_BASE_SUBJECT is the parent object, which allows a     * state machine to be easily monitored by a user.     */
name|SCI_BASE_SUBJECT_T
name|parent
decl_stmt|;
endif|#
directive|endif
comment|// defined(SCI_LOGGING)
comment|/**     * This field points to the start of the state machine's state table.     */
name|SCI_BASE_STATE_T
modifier|*
name|state_table
decl_stmt|;
comment|/**     * This field points to the object to which this state machine is     * associated.  It serves as a cookie to be provided to the state     * enter/exit methods.     */
name|SCI_BASE_OBJECT_T
modifier|*
name|state_machine_owner
decl_stmt|;
comment|/**     * This field simply indicates the state value for the state machine's     * initial state.     */
name|U32
name|initial_state_id
decl_stmt|;
comment|/**     * This field indicates the current state of the state machine.     */
name|U32
name|current_state_id
decl_stmt|;
comment|/**     * This field indicates the previous state of the state machine.     */
name|U32
name|previous_state_id
decl_stmt|;
block|}
name|SCI_BASE_STATE_MACHINE_T
typedef|;
comment|//******************************************************************************
comment|//* P R O T E C T E D    M E T H O D S
comment|//******************************************************************************
name|void
name|sci_base_state_machine_construct
parameter_list|(
name|SCI_BASE_STATE_MACHINE_T
modifier|*
name|this_state_machine
parameter_list|,
name|SCI_BASE_OBJECT_T
modifier|*
name|state_machine_owner
parameter_list|,
name|SCI_BASE_STATE_T
modifier|*
name|state_table
parameter_list|,
name|U32
name|initial_state
parameter_list|)
function_decl|;
name|void
name|sci_base_state_machine_start
parameter_list|(
name|SCI_BASE_STATE_MACHINE_T
modifier|*
name|this_state_machine
parameter_list|)
function_decl|;
name|void
name|sci_base_state_machine_stop
parameter_list|(
name|SCI_BASE_STATE_MACHINE_T
modifier|*
name|this_state_machine
parameter_list|)
function_decl|;
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
function_decl|;
name|U32
name|sci_base_state_machine_get_state
parameter_list|(
name|SCI_BASE_STATE_MACHINE_T
modifier|*
name|this_state_machine
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCI_BASE_STATE_MACHINE_H_
end_comment

end_unit


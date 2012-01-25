begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_STATE_MACHINE_OBSERVER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_STATE_MACHINE_OBSERVER_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the structures, constants, and methods  *        common to all state machine observer object definitions.  */
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
file|<dev/isci/scil/sci_base_observer.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_subject.h>
if|#
directive|if
name|defined
argument_list|(
name|SCI_LOGGING
argument_list|)
comment|/**  * @struct SCI_BASE_STATE_MACHINE_OBSERVER  *  * @brief The base state machine observer structure defines the fields  *        necessary for a user that wishes to observe the behavior (i.e.  *        state changes) of a state machine.  */
typedef|typedef
struct|struct
name|SCI_BASE_STATE_MACHINE_OBSERVER
block|{
comment|/**     * The field specifies that the parent object for the base state     * machine observer is the base observer itself.     */
name|SCI_BASE_OBSERVER_T
name|parent
decl_stmt|;
comment|/**     * This field contains the state recorded during the last state machine     * update.     */
name|U32
name|subject_state
decl_stmt|;
block|}
name|SCI_BASE_STATE_MACHINE_OBSERVER_T
typedef|;
comment|/**  * @brief This method provides default behavior for a state machine observer.  *        This method records the state of the subject (i.e. the state  *        machine) and returns.  *  * @param[in]  this_observer This parameter specifes the state machine  *             observer in which to record the state change from the subject.  * @param[in]  the_subject This parameter evaluates to the state machine  *             object under observation.  *  * @return none  */
name|void
name|sci_base_state_machine_observer_default_update
parameter_list|(
name|SCI_BASE_OBSERVER_T
modifier|*
name|this_observer
parameter_list|,
name|SCI_BASE_SUBJECT_T
modifier|*
name|the_subject
parameter_list|)
function_decl|;
comment|/**  * @brief This method constructs the supplied state machine observer.  *  * @param[in]  this_observer This parameter specifes the state machine  *             observer to be constructed.  *  * @return none  */
name|void
name|sci_base_state_machine_observer_construct
parameter_list|(
name|SCI_BASE_STATE_MACHINE_OBSERVER_T
modifier|*
name|this_observer
parameter_list|)
function_decl|;
else|#
directive|else
comment|// defined(SCI_LOGGING)
typedef|typedef
name|U8
name|SCI_BASE_STATE_MACHINE_OBSERVER_T
typedef|;
define|#
directive|define
name|sci_base_state_machine_observer_default_update
define|#
directive|define
name|sci_base_state_machine_observer_construct
endif|#
directive|endif
comment|// defined(SCI_LOGGING)
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
comment|// _SCI_BASE_STATE_MACHINE_OBSERVER_H_
end_comment

end_unit


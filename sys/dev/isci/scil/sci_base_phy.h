begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_PHY_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the structures, constants, and methods  *        common to all phy object definitions.  */
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
file|<dev/isci/scil/sci_base_logger.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_state_machine.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_state_machine_logger.h>
comment|/**  * @enum SCI_BASE_PHY_STATES  *  * @brief This enumeration depicts the standard states common to all phy  *        state machine implementations.  */
typedef|typedef
enum|enum
name|_SCI_BASE_PHY_STATES
block|{
comment|/**     * Simply the initial state for the base domain state machine.     */
name|SCI_BASE_PHY_STATE_INITIAL
block|,
comment|/**     * This state indicates that the phy has successfully been stopped.     * In this state no new IO operations are permitted on this phy.     * This state is entered from the INITIAL state.     * This state is entered from the STARTING state.     * This state is entered from the READY state.     * This state is entered from the RESETTING state.     */
name|SCI_BASE_PHY_STATE_STOPPED
block|,
comment|/**     * This state indicates that the phy is in the process of becomming     * ready.  In this state no new IO operations are permitted on this phy.     * This state is entered from the STOPPED state.     * This state is entered from the READY state.     * This state is entered from the RESETTING state.     */
name|SCI_BASE_PHY_STATE_STARTING
block|,
comment|/**     * This state indicates the phy is now ready.  Thus, the user     * is able to perform IO operations utilizing this phy as long as it     * is currently part of a valid port.     * This state is entered from the STARTING state.     */
name|SCI_BASE_PHY_STATE_READY
block|,
comment|/**     * This state indicates that the phy is in the process of being reset.     * In this state no new IO operations are permitted on this phy.     * This state is entered from the READY state.     */
name|SCI_BASE_PHY_STATE_RESETTING
block|,
comment|/**     * Simply the final state for the base phy state machine.     */
name|SCI_BASE_PHY_STATE_FINAL
block|,
name|SCI_BASE_PHY_MAX_STATES
block|}
name|SCI_BASE_PHY_STATES
typedef|;
comment|/**  * @struct SCI_BASE_PHY  *  * @brief This structure defines all of the fields common to PHY objects.  */
typedef|typedef
struct|struct
name|SCI_BASE_PHY
block|{
comment|/**     * This field depicts the parent object (SCI_BASE_OBJECT) for the phy.     */
name|SCI_BASE_OBJECT_T
name|parent
decl_stmt|;
comment|/**     * This field contains the information for the base phy state machine.     */
name|SCI_BASE_STATE_MACHINE_T
name|state_machine
decl_stmt|;
ifdef|#
directive|ifdef
name|SCI_LOGGING
name|SCI_BASE_STATE_MACHINE_LOGGER_T
name|state_machine_logger
decl_stmt|;
endif|#
directive|endif
comment|// SCI_LOGGING
block|}
name|SCI_BASE_PHY_T
typedef|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_PHY_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_PHY_T
modifier|*
parameter_list|)
function_decl|;
comment|/**  * @struct SCI_BASE_PHY_STATE_HANDLER  *  * @brief This structure contains all of the state handler methods common to  *        base phy state machines.  Handler methods provide the ability  *        to change the behavior for user requests or transitions depending  *        on the state the machine is in.  */
typedef|typedef
struct|struct
name|SCI_BASE_PHY_STATE_HANDLER
block|{
comment|/**     * The start_handler specifies the method invoked when there is an     * attempt to start a phy.     */
name|SCI_BASE_PHY_HANDLER_T
name|start_handler
decl_stmt|;
comment|/**     * The stop_handler specifies the method invoked when there is an     * attempt to stop a phy.     */
name|SCI_BASE_PHY_HANDLER_T
name|stop_handler
decl_stmt|;
comment|/**     * The reset_handler specifies the method invoked when there is an     * attempt to reset a phy.     */
name|SCI_BASE_PHY_HANDLER_T
name|reset_handler
decl_stmt|;
comment|/**     * The destruct_handler specifies the method invoked when attempting to     * destruct a phy.     */
name|SCI_BASE_PHY_HANDLER_T
name|destruct_handler
decl_stmt|;
block|}
name|SCI_BASE_PHY_STATE_HANDLER_T
typedef|;
comment|/**  * @brief Construct the base phy  *  * @param[in] this_phy This parameter specifies the base phy to be  *            constructed.  * @param[in] logger This parameter specifies the logger associated with  *            this base phy object.  * @param[in] state_table This parameter specifies the table of state  *            definitions to be utilized for the phy state machine.  *  * @return none  */
name|void
name|sci_base_phy_construct
parameter_list|(
name|SCI_BASE_PHY_T
modifier|*
name|this_phy
parameter_list|,
name|SCI_BASE_LOGGER_T
modifier|*
name|logger
parameter_list|,
name|SCI_BASE_STATE_T
modifier|*
name|state_table
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
comment|// _SCI_BASE_PHY_H_
end_comment

end_unit


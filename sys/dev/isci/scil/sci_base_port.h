begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_PORT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_PORT_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the structures, constants, and methods  *        common to all port object definitions.  */
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
file|<dev/isci/scil/sci_base_object.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_logger.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_state_machine.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_state_machine_logger.h>
comment|/**  * @enum SCI_BASE_PORT_STATES  *  * @brief This enumeration depicts all the states for the common port  *        state machine.  */
typedef|typedef
enum|enum
name|_SCI_BASE_PORT_STATES
block|{
comment|/**     * This state indicates that the port has successfully been stopped.     * In this state no new IO operations are permitted.     * This state is entered from the STOPPING state.     */
name|SCI_BASE_PORT_STATE_STOPPED
block|,
comment|/**     * This state indicates that the port is in the process of stopping.     * In this state no new IO operations are permitted, but existing IO     * operations are allowed to complete.     * This state is entered from the READY state.     */
name|SCI_BASE_PORT_STATE_STOPPING
block|,
comment|/**     * This state indicates the port is now ready.  Thus, the user is     * able to perform IO operations on this port.     * This state is entered from the STARTING state.     */
name|SCI_BASE_PORT_STATE_READY
block|,
comment|/**     * This state indicates the port is in the process of performing a hard     * reset.  Thus, the user is unable to perform IO operations on this     * port.     * This state is entered from the READY state.     */
name|SCI_BASE_PORT_STATE_RESETTING
block|,
comment|/**     * This state indicates the port has failed a reset request.  This state     * is entered when a port reset request times out.     * This state is entered from the RESETTING state.     */
name|SCI_BASE_PORT_STATE_FAILED
block|,
name|SCI_BASE_PORT_MAX_STATES
block|}
name|SCI_BASE_PORT_STATES
typedef|;
comment|/**  * @struct SCI_BASE_PORT  *  * @brief The base port object abstracts the fields common to all SCI  *        port objects.  */
typedef|typedef
struct|struct
name|SCI_BASE_PORT
block|{
comment|/**     * The field specifies that the parent object for the base controller     * is the base object itself.     */
name|SCI_BASE_OBJECT_T
name|parent
decl_stmt|;
comment|/**     * This field contains the information for the base port state machine.     */
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
name|SCI_BASE_PORT_T
typedef|;
struct_decl|struct
name|SCI_BASE_PHY
struct_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_PORT_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_PORT_T
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_PORT_PHY_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_PORT_T
modifier|*
parameter_list|,
name|struct
name|SCI_BASE_PHY
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_PORT_RESET_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_PORT_T
modifier|*
parameter_list|,
name|U32
name|timeout
parameter_list|)
function_decl|;
comment|/**  * @struct SCI_BASE_PORT_STATE_HANDLER  *  * @brief This structure contains all of the state handler methods common to  *        base port state machines.  Handler methods provide the ability  *        to change the behavior for user requests or transitions depending  *        on the state the machine is in.  */
typedef|typedef
struct|struct
name|SCI_BASE_PORT_STATE_HANDLER
block|{
comment|/**     * The start_handler specifies the method invoked when a user attempts to     * start a port.     */
name|SCI_BASE_PORT_HANDLER_T
name|start_handler
decl_stmt|;
comment|/**     * The stop_handler specifies the method invoked when a user attempts to     * stop a port.     */
name|SCI_BASE_PORT_HANDLER_T
name|stop_handler
decl_stmt|;
comment|/**     * The destruct_handler specifies the method invoked when attempting to     * destruct a port.     */
name|SCI_BASE_PORT_HANDLER_T
name|destruct_handler
decl_stmt|;
comment|/**     * The reset_handler specifies the method invoked when a user attempts to     * hard reset a port.     */
name|SCI_BASE_PORT_RESET_HANDLER_T
name|reset_handler
decl_stmt|;
comment|/**     * The add_phy_handler specifies the method invoked when a user attempts to     * add another phy into the port.     */
name|SCI_BASE_PORT_PHY_HANDLER_T
name|add_phy_handler
decl_stmt|;
comment|/**     * The remove_phy_handler specifies the method invoked when a user     * attempts to remove a phy from the port.     */
name|SCI_BASE_PORT_PHY_HANDLER_T
name|remove_phy_handler
decl_stmt|;
block|}
name|SCI_BASE_PORT_STATE_HANDLER_T
typedef|;
comment|/**  * @brief Construct the base port object  *  * @param[in] this_port This parameter specifies the base port to be  *            constructed.  * @param[in] logger This parameter specifies the logger to be associated  *            with this base port object.  * @param[in] state_table This parameter specifies the table of state  *            definitions to be utilized for the domain state machine.  *  * @return none  */
name|void
name|sci_base_port_construct
parameter_list|(
name|SCI_BASE_PORT_T
modifier|*
name|this_port
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
comment|// _SCI_BASE_PORT_H_
end_comment

end_unit


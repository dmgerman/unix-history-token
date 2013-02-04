begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_DOMAIN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_DOMAIN_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the structures, constants, and methods  *        common to all domain object definitions.  */
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
comment|/**  * @enum SCI_BASE_DOMAIN_STATES  *  * @brief This enumeration depicts the standard states common to all domain  *        state machine implementations.  */
typedef|typedef
enum|enum
name|_SCI_BASE_DOMAIN_STATES
block|{
comment|/**     * Simply the initial state for the base domain state machine.     */
name|SCI_BASE_DOMAIN_STATE_INITIAL
block|,
comment|/**     * This state indicates that the domain has successfully been stopped.     * In this state no new IO operations are permitted.     * This state is entered from the INITIAL state.     * This state is entered from the DISCOVERING state.     */
name|SCI_BASE_DOMAIN_STATE_STARTING
block|,
comment|/**     * This state indicates the domain is now ready.  Thus, the user     * is able to perform IO operations to remote devices in this domain.     * This state is entered from the STOPPED state.     * This state is entered from the STOPPING state.     * This state is entered from the DISCOVERING state.     */
name|SCI_BASE_DOMAIN_STATE_READY
block|,
comment|/**     * This state indicates that the domain is in the process of stopping.     * In this state no new IO operations are permitted, but existing IO     * operations in the domain are allowed to complete.     * This state is entered from the READY state.     * This state is entered from the DISCOVERING state.     */
name|SCI_BASE_DOMAIN_STATE_STOPPING
block|,
comment|/**     * This state indicates that the domain has successfully been stopped.     * In this state no new IO operations are permitted.     * This state is entered from the INITIAL state.     * This state is entered from the STOPPING state.     */
name|SCI_BASE_DOMAIN_STATE_STOPPED
block|,
comment|/**     * This state indicates that the domain is actively attempting to     * discover what remote devices are contained in it.  In this state no     * new user IO requests are permitted.     * This state is entered from the READY state.     */
name|SCI_BASE_DOMAIN_STATE_DISCOVERING
block|,
name|SCI_BASE_DOMAIN_MAX_STATES
block|}
name|SCI_BASE_DOMAIN_STATES
typedef|;
comment|/**  * @struct SCI_BASE_DOMAIN  *  * @brief This structure defines all of the fields common to DOMAIN objects.  */
typedef|typedef
struct|struct
name|SCI_BASE_DOMAIN
block|{
comment|/**     * This field depicts the parent object (SCI_BASE_OBJECT) for the domain.     */
name|SCI_BASE_OBJECT_T
name|parent
decl_stmt|;
comment|/**     * This field contains the information for the base domain state machine.     */
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
name|SCI_BASE_DOMAIN_T
typedef|;
struct_decl|struct
name|SCI_BASE_CONTROLLER
struct_decl|;
struct_decl|struct
name|SCI_BASE_REMOTE_DEVICE
struct_decl|;
struct_decl|struct
name|SCI_BASE_REQUEST
struct_decl|;
struct_decl|struct
name|SCI_BASE_REQUEST
struct_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_DOMAIN_TIMED_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_DOMAIN_T
modifier|*
parameter_list|,
name|U32
parameter_list|,
name|U32
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_DOMAIN_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_DOMAIN_T
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_DOMAIN_PORT_NOT_READY_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_DOMAIN_T
modifier|*
parameter_list|,
name|U32
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_DOMAIN_DEVICE_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_DOMAIN_T
modifier|*
parameter_list|,
name|struct
name|SCI_BASE_REMOTE_DEVICE
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_DOMAIN_REQUEST_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_DOMAIN_T
modifier|*
parameter_list|,
name|struct
name|SCI_BASE_REMOTE_DEVICE
modifier|*
parameter_list|,
name|struct
name|SCI_BASE_REQUEST
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_DOMAIN_HIGH_PRIORITY_REQUEST_COMPLETE_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_DOMAIN_T
modifier|*
parameter_list|,
name|struct
name|SCI_BASE_REMOTE_DEVICE
modifier|*
parameter_list|,
name|struct
name|SCI_BASE_REQUEST
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|SCI_IO_STATUS
parameter_list|)
function_decl|;
comment|/**  * @struct SCI_BASE_DOMAIN_STATE_HANDLER  *  * @brief This structure contains all of the state handler methods common to  *        base domain state machines.  Handler methods provide the ability  *        to change the behavior for user requests or transitions depending  *        on the state the machine is in.  */
typedef|typedef
struct|struct
name|SCI_BASE_DOMAIN_STATE_HANDLER
block|{
comment|/**     * The discover_handler specifies the method invoked when a user attempts     * to discover a domain.     */
name|SCI_BASE_DOMAIN_TIMED_HANDLER_T
name|discover_handler
decl_stmt|;
comment|/**     * The port_ready_handler specifies the method invoked an SCI Core     * informs the domain object that it's associated port is now ready     * for IO operation.     */
name|SCI_BASE_DOMAIN_HANDLER_T
name|port_ready_handler
decl_stmt|;
comment|/**     * The port_not_ready_handler specifies the method invoked an SCI Core     * informs the domain object that it's associated port is no longer ready     * for IO operation.     */
name|SCI_BASE_DOMAIN_PORT_NOT_READY_HANDLER_T
name|port_not_ready_handler
decl_stmt|;
comment|/**     * The device_start_complete_handler specifies the method invoked when a     * remote device start operation in the domain completes.     */
name|SCI_BASE_DOMAIN_DEVICE_HANDLER_T
name|device_start_complete_handler
decl_stmt|;
comment|/**     * The device_stop_complete_handler specifies the method invoked when a     * remote device stop operation in the domain completes.     */
name|SCI_BASE_DOMAIN_DEVICE_HANDLER_T
name|device_stop_complete_handler
decl_stmt|;
comment|/**     * The device_destruct_handler specifies the method invoked when sci user     * destruct a remote device of this domain.     */
name|SCI_BASE_DOMAIN_DEVICE_HANDLER_T
name|device_destruct_handler
decl_stmt|;
comment|/**     * The start_io_handler specifies the method invoked when a user     * attempts to start an IO request for a domain.     */
name|SCI_BASE_DOMAIN_REQUEST_HANDLER_T
name|start_io_handler
decl_stmt|;
comment|/**     * The start_high_priority_io_handler specifies the method invoked when a user     * attempts to start an high priority request for a domain.     */
name|SCI_BASE_DOMAIN_REQUEST_HANDLER_T
name|start_high_priority_io_handler
decl_stmt|;
comment|/**     * The complete_io_handler specifies the method invoked when a user     * attempts to complete an IO request for a domain.     */
name|SCI_BASE_DOMAIN_REQUEST_HANDLER_T
name|complete_io_handler
decl_stmt|;
comment|/**     * The complete_high_priority_io_handler specifies the method invoked when a     * user attempts to complete an high priority IO request for a domain.     */
name|SCI_BASE_DOMAIN_HIGH_PRIORITY_REQUEST_COMPLETE_HANDLER_T
name|complete_high_priority_io_handler
decl_stmt|;
comment|/**     * The continue_io_handler specifies the method invoked when a user     * attempts to continue an IO request for a domain.     */
name|SCI_BASE_DOMAIN_REQUEST_HANDLER_T
name|continue_io_handler
decl_stmt|;
comment|/**     * The start_task_handler specifies the method invoked when a user     * attempts to start a task management request for a domain.     */
name|SCI_BASE_DOMAIN_REQUEST_HANDLER_T
name|start_task_handler
decl_stmt|;
comment|/**     * The complete_task_handler specifies the method invoked when a user     * attempts to complete a task management request for a domain.     */
name|SCI_BASE_DOMAIN_REQUEST_HANDLER_T
name|complete_task_handler
decl_stmt|;
block|}
name|SCI_BASE_DOMAIN_STATE_HANDLER_T
typedef|;
comment|/**  * @brief Construct the base domain  *  * @param[in] this_domain This parameter specifies the base domain to be  *            constructed.  * @param[in] logger This parameter specifies the logger associated with  *            this base domain object.  * @param[in] state_table This parameter specifies the table of state  *            definitions to be utilized for the domain state machine.  *  * @return none  */
name|void
name|sci_base_domain_construct
parameter_list|(
name|SCI_BASE_DOMAIN_T
modifier|*
name|this_domain
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
comment|// _SCI_BASE_DOMAIN_H_
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCI_BASE_REMOTE_DEVICE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCI_BASE_REMOTE_DEVICE_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the structures, constants, and methods  *        common to all remote device object definitions.  */
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
file|<dev/isci/scil/sci_base_state_machine.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_logger.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_state_machine_logger.h>
struct_decl|struct
name|SCI_BASE_REQUEST
struct_decl|;
comment|/**  * @enum SCI_BASE_REMOTE_DEVICE_STATES  *  * @brief This enumeration depicts all the states for the common remote device  *        state machine.  */
typedef|typedef
enum|enum
name|_SCI_BASE_REMOTE_DEVICE_STATES
block|{
comment|/**     * Simply the initial state for the base remote device state machine.     */
name|SCI_BASE_REMOTE_DEVICE_STATE_INITIAL
block|,
comment|/**     * This state indicates that the remote device has successfully been     * stopped.  In this state no new IO operations are permitted.     * This state is entered from the INITIAL state.     * This state is entered from the STOPPING state.     */
name|SCI_BASE_REMOTE_DEVICE_STATE_STOPPED
block|,
comment|/**     * This state indicates the remote device is in the process of     * becoming ready (i.e. starting).  In this state no new IO operations     * are permitted.     * This state is entered from the STOPPED state.     */
name|SCI_BASE_REMOTE_DEVICE_STATE_STARTING
block|,
comment|/**     * This state indicates the remote device is now ready.  Thus, the user     * is able to perform IO operations on the remote device.     * This state is entered from the STARTING state.     */
name|SCI_BASE_REMOTE_DEVICE_STATE_READY
block|,
comment|/**     * This state indicates that the remote device is in the process of     * stopping.  In this state no new IO operations are permitted, but     * existing IO operations are allowed to complete.     * This state is entered from the READY state.     * This state is entered from the FAILED state.     */
name|SCI_BASE_REMOTE_DEVICE_STATE_STOPPING
block|,
comment|/**     * This state indicates that the remote device has failed.     * In this state no new IO operations are permitted.     * This state is entered from the INITIALIZING state.     * This state is entered from the READY state.     */
name|SCI_BASE_REMOTE_DEVICE_STATE_FAILED
block|,
comment|/**     * This state indicates the device is being reset.     * In this state no new IO operations are permitted.     * This state is entered from the READY state.     */
name|SCI_BASE_REMOTE_DEVICE_STATE_RESETTING
block|,
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_WIDE_PORTED_TARGETS
argument_list|)
comment|/**     * This state indicates the device is in the middle of updating     * its port width. All the IOs sent to this device will be Quiesced.     */
name|SCI_BASE_REMOTE_DEVICE_STATE_UPDATING_PORT_WIDTH
block|,
endif|#
directive|endif
comment|/**     * Simply the final state for the base remote device state machine.     */
name|SCI_BASE_REMOTE_DEVICE_STATE_FINAL
block|,
name|SCI_BASE_REMOTE_DEVICE_MAX_STATES
block|}
name|SCI_BASE_REMOTE_DEVICE_STATES
typedef|;
comment|/**  * @struct SCI_BASE_REMOTE_DEVICE  *  * @brief The base remote device object abstracts the fields common to all  *        SCI remote device objects.  */
typedef|typedef
struct|struct
name|SCI_BASE_REMOTE_DEVICE
block|{
comment|/**     * The field specifies that the parent object for the base remote     * device is the base object itself.     */
name|SCI_BASE_OBJECT_T
name|parent
decl_stmt|;
comment|/**     * This field contains the information for the base remote device state     * machine.     */
name|SCI_BASE_STATE_MACHINE_T
name|state_machine
decl_stmt|;
ifdef|#
directive|ifdef
name|SCI_LOGGING
comment|/**     * This field contains the state machine observer for the state machine.     */
name|SCI_BASE_STATE_MACHINE_LOGGER_T
name|state_machine_logger
decl_stmt|;
endif|#
directive|endif
comment|// SCI_LOGGING
block|}
name|SCI_BASE_REMOTE_DEVICE_T
typedef|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_REMOTE_DEVICE_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_REMOTE_DEVICE_T
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCI_BASE_REMOTE_DEVICE_REQUEST_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_REMOTE_DEVICE_T
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
name|SCI_BASE_REMOTE_DEVICE_HIGH_PRIORITY_REQUEST_COMPLETE_HANDLER_T
function_decl|)
parameter_list|(
name|SCI_BASE_REMOTE_DEVICE_T
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
comment|/**  * @struct SCI_BASE_CONTROLLER_STATE_HANDLER  *  * @brief This structure contains all of the state handler methods common to  *        base remote device state machines.  Handler methods provide the ability  *        to change the behavior for user requests or transitions depending  *        on the state the machine is in.  */
typedef|typedef
struct|struct
name|SCI_BASE_REMOTE_DEVICE_STATE_HANDLER
block|{
comment|/**     * The start_handler specifies the method invoked when a user attempts to     * start a remote device.     */
name|SCI_BASE_REMOTE_DEVICE_HANDLER_T
name|start_handler
decl_stmt|;
comment|/**     * The stop_handler specifies the method invoked when a user attempts to     * stop a remote device.     */
name|SCI_BASE_REMOTE_DEVICE_HANDLER_T
name|stop_handler
decl_stmt|;
comment|/**     * The fail_handler specifies the method invoked when a remote device     * failure has occurred.  A failure may be due to an inability to     * initialize/configure the device.     */
name|SCI_BASE_REMOTE_DEVICE_HANDLER_T
name|fail_handler
decl_stmt|;
comment|/**     * The destruct_handler specifies the method invoked when attempting to     * destruct a remote device.     */
name|SCI_BASE_REMOTE_DEVICE_HANDLER_T
name|destruct_handler
decl_stmt|;
comment|/**     * The reset handler specifies the method invloked when requesting to reset a     * remote device.     */
name|SCI_BASE_REMOTE_DEVICE_HANDLER_T
name|reset_handler
decl_stmt|;
comment|/**     * The reset complete handler specifies the method invloked when reporting     * that a reset has completed to the remote device.     */
name|SCI_BASE_REMOTE_DEVICE_HANDLER_T
name|reset_complete_handler
decl_stmt|;
comment|/**     * The start_io_handler specifies the method invoked when a user     * attempts to start an IO request for a remote device.     */
name|SCI_BASE_REMOTE_DEVICE_REQUEST_HANDLER_T
name|start_io_handler
decl_stmt|;
comment|/**     * The complete_io_handler specifies the method invoked when a user     * attempts to complete an IO request for a remote device.     */
name|SCI_BASE_REMOTE_DEVICE_REQUEST_HANDLER_T
name|complete_io_handler
decl_stmt|;
comment|/**     * The continue_io_handler specifies the method invoked when a user     * attempts to continue an IO request for a remote device.     */
name|SCI_BASE_REMOTE_DEVICE_REQUEST_HANDLER_T
name|continue_io_handler
decl_stmt|;
comment|/**     * The start_task_handler specifies the method invoked when a user     * attempts to start a task management request for a remote device.     */
name|SCI_BASE_REMOTE_DEVICE_REQUEST_HANDLER_T
name|start_task_handler
decl_stmt|;
comment|/**     * The complete_task_handler specifies the method invoked when a user     * attempts to complete a task management request for a remote device.     */
name|SCI_BASE_REMOTE_DEVICE_REQUEST_HANDLER_T
name|complete_task_handler
decl_stmt|;
block|}
name|SCI_BASE_REMOTE_DEVICE_STATE_HANDLER_T
typedef|;
comment|/**  * @brief Construct the base remote device  *  * @param[in] this_remote_device This parameter specifies the base remote  *            device to be constructed.  * @param[in] logger This parameter specifies the logger associated with  *            this base remote device object.  * @param[in] state_table This parameter specifies the table of state  *            definitions to be utilized for the remote device state machine.  *  * @return none  */
name|void
name|sci_base_remote_device_construct
parameter_list|(
name|SCI_BASE_REMOTE_DEVICE_T
modifier|*
name|this_device
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
comment|// _SCI_BASE_REMOTE_DEVICE_H_
end_comment

end_unit


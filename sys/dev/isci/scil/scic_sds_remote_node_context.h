begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_SDS_REMOTE_NODE_CONTEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_SDS_REMOTE_NODE_CONTEXT_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the structures, constants, and prototypes  *        associated with the remote node context in the silicon.  It  *        exists to model and manage the remote node context in the silicon.  */
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
file|<dev/isci/scil/sci_types.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_state.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_state_machine.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_state_machine_logger.h>
comment|// ---------------------------------------------------------------------------
comment|/**  * This constant represents an invalid remote device id, it is used to program  * the STPDARNI register so the driver knows when it has received a SIGNATURE  * FIS from the SCU.  */
define|#
directive|define
name|SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX
value|0x0FFF
define|#
directive|define
name|SCU_HARDWARE_SUSPENSION
value|(0)
define|#
directive|define
name|SCI_SOFTWARE_SUSPENSION
value|(1)
struct_decl|struct
name|SCIC_SDS_REQUEST
struct_decl|;
struct_decl|struct
name|SCIC_SDS_REMOTE_DEVICE
struct_decl|;
struct_decl|struct
name|SCIC_SDS_REMOTE_NODE_CONTEXT
struct_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|SCIC_SDS_REMOTE_NODE_CONTEXT_CALLBACK
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCIC_SDS_REMOTE_NODE_CONTEXT_OPERATION
function_decl|)
parameter_list|(
name|struct
name|SCIC_SDS_REMOTE_NODE_CONTEXT
modifier|*
name|this_rnc
parameter_list|,
name|SCIC_SDS_REMOTE_NODE_CONTEXT_CALLBACK
name|the_callback
parameter_list|,
name|void
modifier|*
name|callback_parameter
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCIC_SDS_REMOTE_NODE_CONTEXT_SUSPEND_OPERATION
function_decl|)
parameter_list|(
name|struct
name|SCIC_SDS_REMOTE_NODE_CONTEXT
modifier|*
name|this_rnc
parameter_list|,
name|U32
name|suspension_type
parameter_list|,
name|SCIC_SDS_REMOTE_NODE_CONTEXT_CALLBACK
name|the_callback
parameter_list|,
name|void
modifier|*
name|callback_parameter
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCIC_SDS_REMOTE_NODE_CONTEXT_IO_REQUEST
function_decl|)
parameter_list|(
name|struct
name|SCIC_SDS_REMOTE_NODE_CONTEXT
modifier|*
name|this_rnc
parameter_list|,
name|struct
name|SCIC_SDS_REQUEST
modifier|*
name|the_request
parameter_list|)
function_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCIC_SDS_REMOTE_NODE_CONTEXT_EVENT_HANDLER
function_decl|)
parameter_list|(
name|struct
name|SCIC_SDS_REMOTE_NODE_CONTEXT
modifier|*
name|this_rnc
parameter_list|,
name|U32
name|event_code
parameter_list|)
function_decl|;
comment|// ---------------------------------------------------------------------------
typedef|typedef
struct|struct
name|_SCIC_SDS_REMOTE_NODE_CONTEXT_HANDLERS
block|{
comment|/**     * This handle is invoked to stop the RNC.  The callback is invoked when after     * the hardware notification that the RNC has been invalidated.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_OPERATION
name|destruct_handler
decl_stmt|;
comment|/**     * This handler is invoked when there is a request to suspend  the RNC.  The     * callback is invoked after the hardware notification that the remote node is     * suspended.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_SUSPEND_OPERATION
name|suspend_handler
decl_stmt|;
comment|/**     * This handler is invoked when there is a request to resume the RNC.  The     * callback is invoked when after the RNC has reached the ready state.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_OPERATION
name|resume_handler
decl_stmt|;
comment|/**     * This handler is invoked when there is a request to start an io request     * operation.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_IO_REQUEST
name|start_io_handler
decl_stmt|;
comment|/**     * This handler is invoked when there is a request to start a task request     * operation.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_IO_REQUEST
name|start_task_handler
decl_stmt|;
comment|/**     * This handler is invoked where there is an RNC event that must be processed.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_EVENT_HANDLER
name|event_handler
decl_stmt|;
block|}
name|SCIC_SDS_REMOTE_NODE_CONTEXT_HANDLERS
typedef|;
comment|// ---------------------------------------------------------------------------
comment|/**  * @enum  *  * This is the enumeration of the remote node context states.  */
typedef|typedef
enum|enum
name|_SCIS_SDS_REMOTE_NODE_CONTEXT_STATES
block|{
comment|/**     * This state is the initial state for a remote node context.  On a resume     * request the remote node context will transition to the posting state.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_INITIAL_STATE
block|,
comment|/**     * This is a transition state that posts the RNi to the hardware. Once the RNC     * is posted the remote node context will be made ready.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_POSTING_STATE
block|,
comment|/**     * This is a transition state that will post an RNC invalidate to the     * hardware.  Once the invalidate is complete the remote node context will     * transition to the posting state.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_INVALIDATING_STATE
block|,
comment|/**     * This is a transition state that will post an RNC resume to the hardare.     * Once the event notification of resume complete is received the remote node     * context will transition to the ready state.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_RESUMING_STATE
block|,
comment|/**     * This is the state that the remote node context must be in to accept io     * request operations.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_READY_STATE
block|,
comment|/**     * This is the state that the remote node context transitions to when it gets     * a TX suspend notification from the hardware.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_TX_SUSPENDED_STATE
block|,
comment|/**     * This is the state that the remote node context transitions to when it gets     * a TX RX suspend notification from the hardware.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_TX_RX_SUSPENDED_STATE
block|,
comment|/**     * This state is a wait state for the remote node context that waits for a     * suspend notification from the hardware.  This state is entered when either     * there is a request to supend the remote node context or when there is a TC     * completion where the remote node will be suspended by the hardware.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_AWAIT_SUSPENSION_STATE
block|,
name|SCIC_SDS_REMOTE_NODE_CONTEXT_MAX_STATES
block|}
name|SCIS_SDS_REMOTE_NODE_CONTEXT_STATES
typedef|;
comment|/**  * @enum  *  * This enumeration is used to define the end destination state for the remote  * node context.  */
enum|enum
name|SCIC_SDS_REMOTE_NODE_CONTEXT_DESTINATION_STATE
block|{
name|SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_UNSPECIFIED
block|,
name|SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_READY
block|,
name|SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_FINAL
block|}
enum|;
comment|/**  * @struct SCIC_SDS_REMOTE_NODE_CONTEXT  *  * @brief  This structure contains the data associated with the remote  *         node context object.  The remote node context (RNC) object models  *         the remote device information necessary to manage the  *         silicon RNC.  */
typedef|typedef
struct|struct
name|SCIC_SDS_REMOTE_NODE_CONTEXT
block|{
comment|/**     * This contains the information used to maintain the loggers for the base     * state machine.     */
name|SCI_BASE_OBJECT_T
name|parent
decl_stmt|;
comment|/**     * This pointer simply points to the remote device object containing     * this RNC.     *     * @todo Consider making the device pointer the associated object of the     *       the parent object.     */
name|struct
name|SCIC_SDS_REMOTE_DEVICE
modifier|*
name|device
decl_stmt|;
comment|/**     * This field indicates the remote node index (RNI) associated with     * this RNC.     */
name|U16
name|remote_node_index
decl_stmt|;
comment|/**     * This field is the recored suspension code or the reason for the remote node     * context suspension.     */
name|U32
name|suspension_code
decl_stmt|;
comment|/**     * This field is TRUE if the remote node context is resuming from its current     * state.  This can cause an automatic resume on receiving a suspension     * notification.     */
name|enum
name|SCIC_SDS_REMOTE_NODE_CONTEXT_DESTINATION_STATE
name|destination_state
decl_stmt|;
comment|/**     * This field contains the callback function that the user requested to be     * called when the requested state transition is complete.     */
name|SCIC_SDS_REMOTE_NODE_CONTEXT_CALLBACK
name|user_callback
decl_stmt|;
comment|/**     * This field contains the parameter that is called when the user requested     * state transition is completed.     */
name|void
modifier|*
name|user_cookie
decl_stmt|;
comment|/**     * This field contains the data for the object's state machine.     */
name|SCI_BASE_STATE_MACHINE_T
name|state_machine
decl_stmt|;
name|SCIC_SDS_REMOTE_NODE_CONTEXT_HANDLERS
modifier|*
name|state_handlers
decl_stmt|;
ifdef|#
directive|ifdef
name|SCI_LOGGING
comment|/**     * This field conatins the ready substate machine logger.  The logger will     * emit a message each time the ready substate machine changes state.     */
name|SCI_BASE_STATE_MACHINE_LOGGER_T
name|state_machine_logger
decl_stmt|;
endif|#
directive|endif
block|}
name|SCIC_SDS_REMOTE_NODE_CONTEXT_T
typedef|;
comment|// ---------------------------------------------------------------------------
specifier|extern
name|SCI_BASE_STATE_T
name|scic_sds_remote_node_context_state_table
index|[
name|SCIC_SDS_REMOTE_NODE_CONTEXT_MAX_STATES
index|]
decl_stmt|;
specifier|extern
name|SCIC_SDS_REMOTE_NODE_CONTEXT_HANDLERS
name|scic_sds_remote_node_context_state_handler_table
index|[
name|SCIC_SDS_REMOTE_NODE_CONTEXT_MAX_STATES
index|]
decl_stmt|;
comment|// ---------------------------------------------------------------------------
name|void
name|scic_sds_remote_node_context_construct
parameter_list|(
name|struct
name|SCIC_SDS_REMOTE_DEVICE
modifier|*
name|device
parameter_list|,
name|SCIC_SDS_REMOTE_NODE_CONTEXT_T
modifier|*
name|rnc
parameter_list|,
name|U16
name|remote_node_index
parameter_list|)
function_decl|;
name|void
name|scic_sds_remote_node_context_construct_buffer
parameter_list|(
name|SCIC_SDS_REMOTE_NODE_CONTEXT_T
modifier|*
name|rnc
parameter_list|)
function_decl|;
name|BOOL
name|scic_sds_remote_node_context_is_initialized
parameter_list|(
name|SCIC_SDS_REMOTE_NODE_CONTEXT_T
modifier|*
name|rnc
parameter_list|)
function_decl|;
name|BOOL
name|scic_sds_remote_node_context_is_ready
parameter_list|(
name|SCIC_SDS_REMOTE_NODE_CONTEXT_T
modifier|*
name|this_rnc
parameter_list|)
function_decl|;
define|#
directive|define
name|scic_sds_remote_node_context_set_remote_node_index
parameter_list|(
name|rnc
parameter_list|,
name|rni
parameter_list|)
define|\
value|((rnc)->remote_node_index = (rni))
define|#
directive|define
name|scic_sds_remote_node_context_get_remote_node_index
parameter_list|(
name|rcn
parameter_list|)
define|\
value|((rnc)->remote_node_index)
define|#
directive|define
name|scic_sds_remote_node_context_event_handler
parameter_list|(
name|rnc
parameter_list|,
name|event_code
parameter_list|)
define|\
value|((rnc)->state_handlers->event_handler(rnc, event_code))
define|#
directive|define
name|scic_sds_remote_node_context_resume
parameter_list|(
name|rnc
parameter_list|,
name|callback
parameter_list|,
name|parameter
parameter_list|)
define|\
value|((rnc)->state_handlers->resume_handler(rnc, callback, parameter))
define|#
directive|define
name|scic_sds_remote_node_context_suspend
parameter_list|(
name|rnc
parameter_list|,
name|suspend_type
parameter_list|,
name|callback
parameter_list|,
name|parameter
parameter_list|)
define|\
value|((rnc)->state_handlers->suspend_handler(rnc, suspend_type, callback, parameter))
define|#
directive|define
name|scic_sds_remote_node_context_destruct
parameter_list|(
name|rnc
parameter_list|,
name|callback
parameter_list|,
name|parameter
parameter_list|)
define|\
value|((rnc)->state_handlers->destruct_handler(rnc, callback, parameter))
define|#
directive|define
name|scic_sds_remote_node_context_start_io
parameter_list|(
name|rnc
parameter_list|,
name|request
parameter_list|)
define|\
value|((rnc)->state_handlers->start_io_handler(rnc, request))
define|#
directive|define
name|scic_sds_remote_node_context_start_task
parameter_list|(
name|rnc
parameter_list|,
name|task
parameter_list|)
define|\
value|((rnc)->state_handlers->start_task_handler(rnc, task))
comment|// ---------------------------------------------------------------------------
ifdef|#
directive|ifdef
name|SCI_LOGGING
name|void
name|scic_sds_remote_node_context_initialize_state_logging
parameter_list|(
name|SCIC_SDS_REMOTE_NODE_CONTEXT_T
modifier|*
name|this_rnc
parameter_list|)
function_decl|;
name|void
name|scic_sds_remote_node_context_deinitialize_state_logging
parameter_list|(
name|SCIC_SDS_REMOTE_NODE_CONTEXT_T
modifier|*
name|this_rnc
parameter_list|)
function_decl|;
else|#
directive|else
comment|// SCI_LOGGING
define|#
directive|define
name|scic_sds_remote_node_context_initialize_state_logging
parameter_list|(
name|x
parameter_list|)
define|#
directive|define
name|scic_sds_remote_node_context_deinitialize_state_logging
parameter_list|(
name|x
parameter_list|)
endif|#
directive|endif
comment|// SCI_LOGGING
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
comment|// _SCIC_SDS_REMOTE_NODE_CONTEXT_H_
end_comment

end_unit


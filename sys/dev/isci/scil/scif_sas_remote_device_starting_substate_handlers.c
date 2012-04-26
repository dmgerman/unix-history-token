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
comment|/**  * @file  *  * @brief This file contains all of the method implementations pertaining  *        to the framework remote device STARTING sub-state handler methods.  *        The STARTING sub-state machine is responsible for ensuring that  *        all initialization and configuration for a particular remote  *        device is complete before transitioning to the READY state  *        (i.e. before allowing normal host IO).  */
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/scic_remote_device.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_logger.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_remote_device.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_domain.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_task_request.h>
end_include

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* G E N E R A L   S T O P   H A N D L E R S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method provides startig sub-state specific handling for  *        when the remote device is requested to stop.  This will occur  *        when there is a link failure during the starting operation.  *  * @param[in]  remote_device This parameter specifies the remote device  *             object for which the failure condition occurred.  *  * @return This method returns an indication as to whether the failure  *         operation completed successfully.  */
end_comment

begin_function
specifier|static
name|SCI_STATUS
name|scif_sas_remote_device_starting_state_general_stop_handler
parameter_list|(
name|SCI_BASE_REMOTE_DEVICE_T
modifier|*
name|remote_device
parameter_list|)
block|{
name|SCIF_SAS_REMOTE_DEVICE_T
modifier|*
name|fw_device
init|=
operator|(
name|SCIF_SAS_REMOTE_DEVICE_T
operator|*
operator|)
name|remote_device
decl_stmt|;
name|SCIF_LOG_INFO
argument_list|(
operator|(
name|sci_base_object_get_logger
argument_list|(
name|fw_device
argument_list|)
operator|,
name|SCIF_LOG_OBJECT_REMOTE_DEVICE
operator|,
literal|"RemoteDevice:0x%x starting device requested to stop\n"
operator|,
name|fw_device
operator|)
argument_list|)
expr_stmt|;
name|fw_device
operator|->
name|domain
operator|->
name|device_start_in_progress_count
operator|--
expr_stmt|;
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|fw_device
operator|->
name|parent
operator|.
name|state_machine
argument_list|,
name|SCI_BASE_REMOTE_DEVICE_STATE_STOPPING
argument_list|)
expr_stmt|;
return|return
name|SCI_SUCCESS
return|;
block|}
end_function

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* A W A I T   C O M P L E T E   H A N D L E R S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method provides AWAIT START COMPLETE sub-state specific  *        handling for when the remote device undergoes a failure  *        condition.  *  * @param[in]  remote_device This parameter specifies the remote device  *             object for which the failure condition occurred.  *  * @return This method returns an indication as to whether the failure  *         operation completed successfully.  */
end_comment

begin_function
specifier|static
name|SCI_STATUS
name|scif_sas_remote_device_starting_await_complete_fail_handler
parameter_list|(
name|SCI_BASE_REMOTE_DEVICE_T
modifier|*
name|remote_device
parameter_list|)
block|{
name|SCIF_SAS_REMOTE_DEVICE_T
modifier|*
name|fw_device
init|=
operator|(
name|SCIF_SAS_REMOTE_DEVICE_T
operator|*
operator|)
name|remote_device
decl_stmt|;
name|SCIF_LOG_WARNING
argument_list|(
operator|(
name|sci_base_object_get_logger
argument_list|(
name|fw_device
argument_list|)
operator|,
name|SCIF_LOG_OBJECT_REMOTE_DEVICE
operator|,
literal|"RemoteDevice:0x%x starting device failed, start complete not received\n"
operator|,
name|fw_device
operator|)
argument_list|)
expr_stmt|;
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|fw_device
operator|->
name|parent
operator|.
name|state_machine
argument_list|,
name|SCI_BASE_REMOTE_DEVICE_STATE_FAILED
argument_list|)
expr_stmt|;
return|return
name|SCI_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/**  * @brief This method provides AWAIT COMPLETE state specific handling for  *        when the core remote device object issues a device not ready  *        notification.  In the AWAIT COMPLETE state we do not inform  *        the framework user of the state change of the device, since the  *        user is unaware of the remote device start process.  *  * @param[in]  remote_device This parameter specifies the remote device  *             object for which the notification occurred.  *  * @return none.  */
end_comment

begin_function
specifier|static
name|void
name|scif_sas_remote_device_starting_await_complete_not_ready_handler
parameter_list|(
name|SCIF_SAS_REMOTE_DEVICE_T
modifier|*
name|fw_device
parameter_list|,
name|U32
name|reason_code
parameter_list|)
block|{ }
end_function

begin_comment
comment|/**  * @brief This method provides AWAIT START COMPLETE sub-state specific  *        handling for when the core provides a start complete notification  *        for the remote device.  If the start completion status indicates  *        a successful start, then the device is transitioned into the  *        READY state.  All other status cause a transition to the  *        FAILED state and a scif_cb_controller_error() notification  *        message to the framework user.  *  * @param[in]  fw_device This parameter specifies the remote device  *             object for which the notification has occurred.  *  * @return none.  */
end_comment

begin_function
specifier|static
name|void
name|scif_sas_remote_device_starting_await_complete_start_complete_handler
parameter_list|(
name|SCIF_SAS_REMOTE_DEVICE_T
modifier|*
name|fw_device
parameter_list|,
name|SCI_STATUS
name|completion_status
parameter_list|)
block|{
if|if
condition|(
name|completion_status
operator|==
name|SCI_SUCCESS
condition|)
block|{
comment|/** @todo need to add support for resetting the device first.  This can                 wait until 1.3. */
comment|/** @todo Update to comprehend situations (i.e. SATA) where config is                 needed. */
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|fw_device
operator|->
name|starting_substate_machine
argument_list|,
name|SCIF_SAS_REMOTE_DEVICE_STARTING_SUBSTATE_AWAIT_READY
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|SCIF_LOG_WARNING
argument_list|(
operator|(
name|sci_base_object_get_logger
argument_list|(
name|fw_device
argument_list|)
operator|,
name|SCIF_LOG_OBJECT_REMOTE_DEVICE
operator||
name|SCIF_LOG_OBJECT_REMOTE_DEVICE_CONFIG
operator|,
literal|"Device:0x%x Status:0x%x failed to start core device\n"
operator|,
name|fw_device
operator|)
argument_list|)
expr_stmt|;
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|fw_device
operator|->
name|parent
operator|.
name|state_machine
argument_list|,
name|SCI_BASE_REMOTE_DEVICE_STATE_FAILED
argument_list|)
expr_stmt|;
comment|// Something is seriously wrong.  Starting the core remote device
comment|// shouldn't fail in anyway in this state.
name|scif_cb_controller_error
argument_list|(
name|fw_device
operator|->
name|domain
operator|->
name|controller
argument_list|,
name|SCI_CONTROLLER_REMOTE_DEVICE_ERROR
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* C O M P L E T E   H A N D L E R S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method provides STARTING AWAIT READY sub-state specific  *        handling for when the core provides a device ready notification  *        for the remote device.  This essentially, causes a transition  *        of the framework remote device into the READY state.  *  * @param[in]  fw_device This parameter specifies the remote device  *             object for which the notification has occurred.  *  * @return none.  */
end_comment

begin_function
specifier|static
name|void
name|scif_sas_remote_device_starting_await_ready_ready_handler
parameter_list|(
name|SCIF_SAS_REMOTE_DEVICE_T
modifier|*
name|fw_device
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_WIDE_PORTED_TARGETS
argument_list|)
if|if
condition|(
name|fw_device
operator|->
name|destination_state
operator|==
name|SCIF_SAS_REMOTE_DEVICE_DESTINATION_STATE_UPDATING_PORT_WIDTH
condition|)
block|{
block|{
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|fw_device
operator|->
name|parent
operator|.
name|state_machine
argument_list|,
name|SCI_BASE_REMOTE_DEVICE_STATE_UPDATING_PORT_WIDTH
argument_list|)
expr_stmt|;
block|}
block|}
else|else
endif|#
directive|endif
block|{
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|fw_device
operator|->
name|parent
operator|.
name|state_machine
argument_list|,
name|SCI_BASE_REMOTE_DEVICE_STATE_READY
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_WIDE_PORTED_TARGETS
argument_list|)
name|scif_sas_domain_remote_device_start_complete
argument_list|(
name|fw_device
operator|->
name|domain
argument_list|,
name|fw_device
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_decl_stmt
name|SCIF_SAS_REMOTE_DEVICE_STATE_HANDLER_T
name|scif_sas_remote_device_starting_substate_handler_table
index|[]
init|=
block|{
comment|// SCIF_SAS_REMOTE_DEVICE_STARTING_SUBSTATE_AWAIT_COMPLETE
block|{
block|{
name|scif_sas_remote_device_default_start_handler
block|,
name|scif_sas_remote_device_starting_state_general_stop_handler
block|,
name|scif_sas_remote_device_starting_await_complete_fail_handler
block|,
name|scif_sas_remote_device_default_destruct_handler
block|,
name|scif_sas_remote_device_default_reset_handler
block|,
name|scif_sas_remote_device_default_reset_complete_handler
block|,
name|scif_sas_remote_device_default_start_io_handler
block|,
name|scif_sas_remote_device_default_complete_io_handler
block|,
name|scif_sas_remote_device_default_continue_io_handler
block|,
name|scif_sas_remote_device_default_start_task_handler
block|,
name|scif_sas_remote_device_default_complete_task_handler
block|}
block|,
name|scif_sas_remote_device_starting_await_complete_start_complete_handler
block|,
name|scif_sas_remote_device_default_stop_complete_handler
block|,
name|scif_sas_remote_device_default_ready_handler
block|,
name|scif_sas_remote_device_starting_await_complete_not_ready_handler
block|,
name|scif_sas_remote_device_default_start_io_handler
block|,
name|scif_sas_remote_device_default_complete_high_priority_io_handler
block|}
block|,
comment|// SCIF_SAS_REMOTE_DEVICE_STARTING_SUBSTATE_AWAIT_READY
block|{
block|{
name|scif_sas_remote_device_default_start_handler
block|,
name|scif_sas_remote_device_starting_state_general_stop_handler
block|,
name|scif_sas_remote_device_starting_await_complete_fail_handler
block|,
name|scif_sas_remote_device_default_destruct_handler
block|,
name|scif_sas_remote_device_default_reset_handler
block|,
name|scif_sas_remote_device_default_reset_complete_handler
block|,
name|scif_sas_remote_device_default_start_io_handler
block|,
name|scif_sas_remote_device_default_complete_io_handler
block|,
name|scif_sas_remote_device_default_continue_io_handler
block|,
name|scif_sas_remote_device_default_start_task_handler
block|,
name|scif_sas_remote_device_default_complete_task_handler
block|}
block|,
name|scif_sas_remote_device_default_start_complete_handler
block|,
name|scif_sas_remote_device_default_stop_complete_handler
block|,
name|scif_sas_remote_device_starting_await_ready_ready_handler
block|,
name|scif_sas_remote_device_default_not_ready_handler
block|,
name|scif_sas_remote_device_default_start_io_handler
block|,
name|scif_sas_remote_device_default_complete_high_priority_io_handler
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit


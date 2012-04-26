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
comment|/**  * @file  *  * @brief This file contains all of the method implementations pertaining  *        to the framework io request state handler methods.  */
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/scic_controller.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_logger.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_io_request.h>
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
file|<dev/isci/scil/scif_sas_controller.h>
end_include

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* C O N S T R U C T E D   H A N D L E R S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method provides CONSTRUCTED state specific handling for  *        when the user attempts to start the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be started.  *  * @return This method returns a value indicating if the IO request was  *         successfully started or not.  * @retval SCI_SUCCESS This return value indicates successful starting  *         of the IO request.  */
end_comment

begin_function
name|SCI_STATUS
name|scif_sas_io_request_constructed_start_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
return|return
name|SCI_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/**  * @brief This method provides CONSTRUCTED state specific handling for  *        when the user attempts to abort the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be aborted.  *  * @return This method returns a value indicating if the IO request was  *         successfully aborted or not.  * @retval SCI_SUCCESS This return value indicates successful aborting  *         of the IO request.  */
end_comment

begin_function
name|SCI_STATUS
name|scif_sas_io_request_constructed_abort_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|io_request
operator|->
name|state_machine
argument_list|,
name|SCI_BASE_REQUEST_STATE_COMPLETED
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
comment|//* S T A R T E D   H A N D L E R S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method provides STARTED state specific handling for  *        when the user attempts to abort the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be aborted.  *  * @return This method returns a value indicating if the aborting the  *         IO request was successfully started.  * @retval SCI_SUCCESS This return value indicates that the abort process  *         began successfully.  */
end_comment

begin_function
specifier|static
name|SCI_STATUS
name|scif_sas_io_request_started_abort_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
name|SCIF_SAS_REQUEST_T
modifier|*
name|fw_request
init|=
operator|(
name|SCIF_SAS_REQUEST_T
operator|*
operator|)
name|io_request
decl_stmt|;
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|io_request
operator|->
name|state_machine
argument_list|,
name|SCI_BASE_REQUEST_STATE_ABORTING
argument_list|)
expr_stmt|;
return|return
name|fw_request
operator|->
name|status
return|;
block|}
end_function

begin_comment
comment|/**  * @brief This method provides STARTED state specific handling for  *        when the user attempts to complete the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be completed.  *  * @return This method returns a value indicating if the completion of the  *         IO request was successful.  * @retval SCI_SUCCESS This return value indicates that the completion process  *         was successful.  */
end_comment

begin_function
specifier|static
name|SCI_STATUS
name|scif_sas_io_request_started_complete_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|io_request
operator|->
name|state_machine
argument_list|,
name|SCI_BASE_REQUEST_STATE_COMPLETED
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
comment|//* C O M P L E T E D   H A N D L E R S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method provides COMPLETED state specific handling for  *        when the user attempts to destruct the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be destructed.  *  * @return This method returns a value indicating if the destruct  *         operation was successful.  * @retval SCI_SUCCESS This return value indicates that the destruct  *         was successful.  */
end_comment

begin_function
specifier|static
name|SCI_STATUS
name|scif_sas_io_request_completed_destruct_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|io_request
operator|->
name|state_machine
argument_list|,
name|SCI_BASE_REQUEST_STATE_FINAL
argument_list|)
expr_stmt|;
name|sci_base_state_machine_logger_deinitialize
argument_list|(
operator|&
name|io_request
operator|->
name|state_machine_logger
argument_list|,
operator|&
name|io_request
operator|->
name|state_machine
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
comment|//* A B O R T I N G   H A N D L E R S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method provides ABORTING state specific handlering for when the  *        user attempts to abort the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be completed.  *  * @return This method returns a value indicating if the completion  *         operation was successful.  * @retval SCI_SUCCESS This return value indicates that the abort operation  *         was successful.  */
end_comment

begin_function
specifier|static
name|SCI_STATUS
name|scif_sas_io_request_aborting_abort_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
name|SCIF_SAS_IO_REQUEST_T
modifier|*
name|fw_request
init|=
operator|(
name|SCIF_SAS_IO_REQUEST_T
operator|*
operator|)
name|io_request
decl_stmt|;
return|return
name|scic_controller_terminate_request
argument_list|(
name|fw_request
operator|->
name|parent
operator|.
name|device
operator|->
name|domain
operator|->
name|controller
operator|->
name|core_object
argument_list|,
name|fw_request
operator|->
name|parent
operator|.
name|device
operator|->
name|core_object
argument_list|,
name|fw_request
operator|->
name|parent
operator|.
name|core_object
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * @brief This method provides ABORTING state specific handling for  *        when the user attempts to complete the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be completed.  *  * @return This method returns a value indicating if the completion  *         operation was successful.  * @retval SCI_SUCCESS This return value indicates that the completion  *         was successful.  */
end_comment

begin_function
specifier|static
name|SCI_STATUS
name|scif_sas_io_request_aborting_complete_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
name|sci_base_state_machine_change_state
argument_list|(
operator|&
name|io_request
operator|->
name|state_machine
argument_list|,
name|SCI_BASE_REQUEST_STATE_COMPLETED
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
comment|//* D E F A U L T   H A N D L E R S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method provides DEFAULT handling for when the user  *        attempts to start the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be started.  *  * @return This method returns an indication that the start operation is  *         not allowed.  * @retval SCI_FAILURE_INVALID_STATE This value is always returned.  */
end_comment

begin_function
specifier|static
name|SCI_STATUS
name|scif_sas_io_request_default_start_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
name|SCIF_LOG_ERROR
argument_list|(
operator|(
name|sci_base_object_get_logger
argument_list|(
operator|(
name|SCIF_SAS_IO_REQUEST_T
operator|*
operator|)
name|io_request
argument_list|)
operator|,
name|SCIF_LOG_OBJECT_IO_REQUEST
operator|,
literal|"IoRequest:0x%x State:0x%x invalid state to start\n"
operator|,
name|io_request
operator|,
name|sci_base_state_machine_get_state
argument_list|(
operator|&
operator|(
operator|(
name|SCIF_SAS_IO_REQUEST_T
operator|*
operator|)
name|io_request
operator|)
operator|->
name|parent
operator|.
name|parent
operator|.
name|state_machine
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|SCI_FAILURE_INVALID_STATE
return|;
block|}
end_function

begin_comment
comment|/**  * @brief This method provides DEFAULT handling for when the user  *        attempts to abort the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be aborted.  *  * @return This method returns an indication that the abort operation is  *         not allowed.  * @retval SCI_FAILURE_INVALID_STATE This value is always returned.  */
end_comment

begin_function
specifier|static
name|SCI_STATUS
name|scif_sas_io_request_default_abort_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
name|SCIF_LOG_ERROR
argument_list|(
operator|(
name|sci_base_object_get_logger
argument_list|(
operator|(
name|SCIF_SAS_IO_REQUEST_T
operator|*
operator|)
name|io_request
argument_list|)
operator|,
name|SCIF_LOG_OBJECT_IO_REQUEST
operator|,
literal|"IoRequest:0x%x State:0x%x invalid state to abort\n"
operator|,
name|io_request
operator|,
name|sci_base_state_machine_get_state
argument_list|(
operator|&
operator|(
operator|(
name|SCIF_SAS_IO_REQUEST_T
operator|*
operator|)
name|io_request
operator|)
operator|->
name|parent
operator|.
name|parent
operator|.
name|state_machine
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|SCI_FAILURE_INVALID_STATE
return|;
block|}
end_function

begin_comment
comment|/**  * @brief This method provides DEFAULT handling for when the user  *        attempts to complete the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be completed.  *  * @return This method returns an indication that complete operation is  *         not allowed.  * @retval SCI_FAILURE_INVALID_STATE This value is always returned.  */
end_comment

begin_function
name|SCI_STATUS
name|scif_sas_io_request_default_complete_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
name|SCIF_LOG_ERROR
argument_list|(
operator|(
name|sci_base_object_get_logger
argument_list|(
operator|(
name|SCIF_SAS_IO_REQUEST_T
operator|*
operator|)
name|io_request
argument_list|)
operator|,
name|SCIF_LOG_OBJECT_IO_REQUEST
operator|,
literal|"IoRequest:0x%x State:0x%x invalid state to complete\n"
operator|,
name|io_request
operator|,
name|sci_base_state_machine_get_state
argument_list|(
operator|&
operator|(
operator|(
name|SCIF_SAS_IO_REQUEST_T
operator|*
operator|)
name|io_request
operator|)
operator|->
name|parent
operator|.
name|parent
operator|.
name|state_machine
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|SCI_FAILURE_INVALID_STATE
return|;
block|}
end_function

begin_comment
comment|/**  * @brief This method provides DEFAULT handling for when the user  *        attempts to destruct the supplied IO request.  *  * @param[in] io_request This parameter specifies the IO request object  *            to be destructed.  *  * @return This method returns an indication that destruct operation is  *         not allowed.  * @retval SCI_FAILURE_INVALID_STATE This value is always returned.  */
end_comment

begin_function
name|SCI_STATUS
name|scif_sas_io_request_default_destruct_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
block|{
name|SCIF_LOG_ERROR
argument_list|(
operator|(
name|sci_base_object_get_logger
argument_list|(
operator|(
name|SCIF_SAS_IO_REQUEST_T
operator|*
operator|)
name|io_request
argument_list|)
operator|,
name|SCIF_LOG_OBJECT_IO_REQUEST
operator|,
literal|"IoRequest:0x%x State:0x%x invalid state to destruct.\n"
operator|,
name|io_request
operator|,
name|sci_base_state_machine_get_state
argument_list|(
operator|&
operator|(
operator|(
name|SCIF_SAS_IO_REQUEST_T
operator|*
operator|)
name|io_request
operator|)
operator|->
name|parent
operator|.
name|parent
operator|.
name|state_machine
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|SCI_FAILURE_INVALID_STATE
return|;
block|}
end_function

begin_decl_stmt
name|SCI_BASE_REQUEST_STATE_HANDLER_T
name|scif_sas_io_request_state_handler_table
index|[]
init|=
block|{
comment|// SCI_BASE_REQUEST_STATE_INITIAL
block|{
name|scif_sas_io_request_default_start_handler
block|,
name|scif_sas_io_request_default_abort_handler
block|,
name|scif_sas_io_request_default_complete_handler
block|,
name|scif_sas_io_request_default_destruct_handler
block|}
block|,
comment|// SCI_BASE_REQUEST_STATE_CONSTRUCTED
block|{
name|scif_sas_io_request_constructed_start_handler
block|,
name|scif_sas_io_request_constructed_abort_handler
block|,
name|scif_sas_io_request_default_complete_handler
block|,
name|scif_sas_io_request_default_destruct_handler
block|}
block|,
comment|// SCI_BASE_REQUEST_STATE_STARTED
block|{
name|scif_sas_io_request_default_start_handler
block|,
name|scif_sas_io_request_started_abort_handler
block|,
name|scif_sas_io_request_started_complete_handler
block|,
name|scif_sas_io_request_default_destruct_handler
block|}
block|,
comment|// SCI_BASE_REQUEST_STATE_COMPLETED
block|{
name|scif_sas_io_request_default_start_handler
block|,
name|scif_sas_io_request_default_abort_handler
block|,
name|scif_sas_io_request_default_complete_handler
block|,
name|scif_sas_io_request_completed_destruct_handler
block|}
block|,
comment|// SCI_BASE_REQUEST_STATE_ABORTING
block|{
name|scif_sas_io_request_default_start_handler
block|,
name|scif_sas_io_request_aborting_abort_handler
block|,
name|scif_sas_io_request_aborting_complete_handler
block|,
name|scif_sas_io_request_default_destruct_handler
block|}
block|,
comment|// SCI_BASE_REQUEST_STATE_FINAL
block|{
name|scif_sas_io_request_default_start_handler
block|,
name|scif_sas_io_request_default_abort_handler
block|,
name|scif_sas_io_request_default_complete_handler
block|,
name|scif_sas_io_request_default_destruct_handler
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit


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
comment|/**  * @file  *  * @brief This file contains the implementation of the SCIF_SAS_REQUEST  *        object.  The SCIF_SAS_REQUEST object provides data and methods  *        that are common to both IO requests and task management requests.  */
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/scic_controller.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_request.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_task_request.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_controller.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_domain.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_remote_device.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/scif_sas_logger.h>
end_include

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* P R O T E C T E D   M E T H O D S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @brief This method constructs the SCIF_SAS_REQUEST object.  *  * @param[in] fw_request This parameter specifies the request object to  *            be constructed.  * @param[in] fw_device This parameter specifies the remote device object  *            to which this request is destined.  * @param[in] logger This parameter specifies the logger associated with  *            this base request object.  * @param[in] state_table This parameter specifies the table of state  *            definitions to be utilized for the request state machine.  *  * @return none  */
end_comment

begin_function
name|void
name|scif_sas_request_construct
parameter_list|(
name|SCIF_SAS_REQUEST_T
modifier|*
name|fw_request
parameter_list|,
name|SCIF_SAS_REMOTE_DEVICE_T
modifier|*
name|fw_device
parameter_list|,
name|SCI_BASE_LOGGER_T
modifier|*
name|logger
parameter_list|,
name|SCI_BASE_STATE_T
modifier|*
name|state_table
parameter_list|)
block|{
name|sci_base_request_construct
argument_list|(
operator|&
name|fw_request
operator|->
name|parent
argument_list|,
name|logger
argument_list|,
name|state_table
argument_list|)
expr_stmt|;
name|SCIF_LOG_TRACE
argument_list|(
operator|(
name|sci_base_object_get_logger
argument_list|(
name|fw_request
argument_list|)
operator|,
name|SCIF_LOG_OBJECT_TASK_MANAGEMENT
operator|,
literal|"scif_sas_request_construct(0x%x, 0x%x, 0x%x, 0x%x) enter\n"
operator|,
name|fw_request
operator|,
name|fw_device
operator|,
name|logger
operator|,
name|state_table
operator|)
argument_list|)
expr_stmt|;
name|fw_request
operator|->
name|device
operator|=
name|fw_device
expr_stmt|;
name|fw_request
operator|->
name|is_internal
operator|=
name|FALSE
expr_stmt|;
name|fw_request
operator|->
name|lun
operator|=
literal|0
expr_stmt|;
name|fw_request
operator|->
name|terminate_requestor
operator|=
name|NULL
expr_stmt|;
name|fw_request
operator|->
name|protocol_complete_handler
operator|=
name|NULL
expr_stmt|;
name|fw_request
operator|->
name|is_high_priority
operator|=
name|FALSE
expr_stmt|;
name|fw_request
operator|->
name|is_waiting_for_abort_task_set
operator|=
name|FALSE
expr_stmt|;
name|sci_fast_list_element_init
argument_list|(
name|fw_request
argument_list|,
operator|&
name|fw_request
operator|->
name|list_element
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * @brief This method will request the SCI core to terminate the supplied  *        request.  *  * @param[in] fw_request This parameter specifies the request to be terminated.  * @param[in] core_request This parameter specifies the core request (IO or  *            task) to be terminated.  *  * @return This method returns the status of the core termination operation.  */
end_comment

begin_function
name|SCI_STATUS
name|scif_sas_request_terminate_start
parameter_list|(
name|SCIF_SAS_REQUEST_T
modifier|*
name|fw_request
parameter_list|,
name|SCI_IO_REQUEST_HANDLE_T
name|core_request
parameter_list|)
block|{
name|SCIF_LOG_TRACE
argument_list|(
operator|(
name|sci_base_object_get_logger
argument_list|(
name|fw_request
argument_list|)
operator|,
name|SCIF_LOG_OBJECT_TASK_MANAGEMENT
operator|,
literal|"scif_sas_request_terminate_start(0x%x) enter\n"
operator|,
name|fw_request
operator|)
argument_list|)
expr_stmt|;
comment|// Only increment the affected request count if this request is being
comment|// terminated at the behest of a task management request.
if|if
condition|(
name|fw_request
operator|->
name|terminate_requestor
operator|!=
name|NULL
condition|)
name|fw_request
operator|->
name|terminate_requestor
operator|->
name|affected_request_count
operator|++
expr_stmt|;
return|return
name|scic_controller_terminate_request
argument_list|(
name|fw_request
operator|->
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
name|device
operator|->
name|core_object
argument_list|,
name|core_request
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * @brief This method will perform termination completion processing for  *        the supplied request.  This includes updated the affected  *        request count, if a task management request is what generated  *        this termination.  Also, this method will attempt to transition  *        to the READY OPERATIONAL state if this represents the last  *        affected request.  *  * @param[in] fw_request This parameter specifies the request for which to  *            perform termination completion processing.  *  * @return none  */
end_comment

begin_function
name|void
name|scif_sas_request_terminate_complete
parameter_list|(
name|SCIF_SAS_REQUEST_T
modifier|*
name|fw_request
parameter_list|)
block|{
name|SCIF_LOG_TRACE
argument_list|(
operator|(
name|sci_base_object_get_logger
argument_list|(
name|fw_request
argument_list|)
operator|,
name|SCIF_LOG_OBJECT_TASK_MANAGEMENT
operator|,
literal|"scif_sas_request_terminate_complete(0x%x) enter\n"
operator|,
name|fw_request
operator|)
argument_list|)
expr_stmt|;
comment|// For requests that were terminated due to a task management request,
comment|// check to see if the task management request has completed.
if|if
condition|(
name|fw_request
operator|->
name|terminate_requestor
operator|!=
name|NULL
condition|)
name|scif_sas_task_request_operation_complete
argument_list|(
name|fw_request
operator|->
name|terminate_requestor
argument_list|)
expr_stmt|;
block|}
end_function

end_unit


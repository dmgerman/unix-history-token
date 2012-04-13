begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_TASK_REQUEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_TASK_REQUEST_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the structures and interface methods that  *        can be referenced and used by the SCI user for to utilize  *        task management requests.  */
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
file|<dev/isci/scil/sci_status.h>
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_TASK_MANAGEMENT
argument_list|)
comment|/**  * @brief This method simply returns the size required to build an SCI  *        based task managment request object.  *  * @return Return the size of the SCIC task request object.  */
name|U32
name|scic_task_request_get_object_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * @brief This method is called by the SCI user to construct all SCI Core  *        task management requests, regardless of protocol.  Memory  *        initialization and functionality common to all task request types  *        is performed in this method.  *  * @note  The SCI core implementation will create an association between  *        the user task request object and the core task request object.  *  * @param[in]  scic_controller the handle to the core controller object  *             for which to build the task managmement request.  * @param[in]  scic_remote_device the handle to the core remote device  *             object for which to build the task management request.  *             passed, then a copy of the request is built internally.  The  *             request will be copied into the actual controller request  *             memory when the task is allocated internally during the  *             scic_controller_start_task() method.  * @param[in]  io_tag This parameter specifies the IO tag to be associated  *             with this request.  If SCI_CONTROLLER_INVALID_IO_TAG is  *             passed, then a copy of the request is built internally.  The  *             request will be copied into the actual controller request  *             memory when the IO tag is allocated internally during the  *             scic_controller_start_io() method.  * @param[in]  user_task_request_object This parameter specifies the user  *             task request to be utilized during construction.  This task  *             pointer will become the associated object for the core  *             task request object.  * @param[in]  scic_task_request_memory This parameter specifies the memory  *             location to be utilized when building the core request.  * @param[out] new_scic_task_request_handle This parameter specifies a  *             pointer to the handle the core will expect in further  *             interactions with the core task request object.  *  * @return Indicate if the controller successfully built the task request.  * @retval SCI_SUCCESS This value is returned if the task request was  *         successfully built.  */
name|SCI_STATUS
name|scic_task_request_construct
parameter_list|(
name|SCI_CONTROLLER_HANDLE_T
name|scic_controller
parameter_list|,
name|SCI_REMOTE_DEVICE_HANDLE_T
name|scic_remote_device
parameter_list|,
name|U16
name|io_tag
parameter_list|,
name|void
modifier|*
name|user_task_request_object
parameter_list|,
name|void
modifier|*
name|scic_task_request_memory
parameter_list|,
name|SCI_TASK_REQUEST_HANDLE_T
modifier|*
name|new_scic_task_request_handle
parameter_list|)
function_decl|;
comment|/**  * @brief This method is called by the SCI user to construct all SCI Core  *        SSP task management requests.  Memory initialization and  *        functionality common to all task request types is performed in  *        this method.  *  * @param[out] scic_task_request This parameter specifies the handle  *             to the core task request object for which to construct  *             a SATA specific task management request.  *  * @return Indicate if the controller successfully built the task request.  * @retval SCI_SUCCESS This value is returned if the task request was  *         successfully built.  */
name|SCI_STATUS
name|scic_task_request_construct_ssp
parameter_list|(
name|SCI_TASK_REQUEST_HANDLE_T
name|scic_task_request
parameter_list|)
function_decl|;
comment|/**  * @brief This method is called by the SCI user to construct all SCI Core  *        SATA task management requests.  Memory initialization and  *        functionality common to all task request types is performed in  *        this method.  *  * @param[out] scic_task_request_handle This parameter specifies the  *             handle to the core task request object for which to construct  *             a SATA specific task management request.  *  * @return Indicate if the controller successfully built the task request.  * @retval SCI_SUCCESS This value is returned if the task request was  *         successfully built.  */
name|SCI_STATUS
name|scic_task_request_construct_sata
parameter_list|(
name|SCI_TASK_REQUEST_HANDLE_T
name|scic_task_request_handle
parameter_list|)
function_decl|;
else|#
directive|else
comment|// !defined(DISABLE_TASK_MANAGEMENT)
define|#
directive|define
name|scic_task_request_get_object_size
parameter_list|()
value|0
define|#
directive|define
name|scic_task_request_construct
parameter_list|(
name|controller
parameter_list|,
name|dev
parameter_list|,
name|tag
parameter_list|,
name|task
parameter_list|,
name|mem
parameter_list|,
name|handle
parameter_list|)
define|\
value|SCI_FAILURE
define|#
directive|define
name|scic_task_request_construct_ssp
parameter_list|(
name|task
parameter_list|)
value|SCI_FAILURE
define|#
directive|define
name|scic_task_request_construct_sata
parameter_list|(
name|task
parameter_list|)
value|SCI_FAILURE
endif|#
directive|endif
comment|// !defined(DISABLE_TASK_MANAGEMENT)
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
comment|// _SCIC_TASK_REQUEST_H_
end_comment

end_unit


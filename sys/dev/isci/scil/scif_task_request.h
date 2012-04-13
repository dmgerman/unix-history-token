begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIF_TASK_REQUEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIF_TASK_REQUEST_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the structures and interface methods that  *        can be referenced and used by the SCI user for the SCI task  *        management request object.  */
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
comment|/**  * @brief This method simply returns the size required to construct an SCI  *        based task request object (includes core& framework object size).  *  * @return Retrun the size of the SCI task request object.  */
name|U32
name|scif_task_request_get_object_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * @brief This method is called by the SCIF user to construct a task  *        management request.  This method will construct a SCIC task request  *        internally.  *  * @note  The SCI framework implementation will create an association between  *        the user task request object and the framework task request object.  *  * @param[in]  scif_controller the handle to the framework controller object  *             for which to build an IO request.  * @param[in]  scif_remote_device This parameter specifies the framework  *             remote device with which this task request is to be associated.  * @param[in]  io_tag This parameter specifies the IO tag to be associated  *             with this request.  If SCI_CONTROLLER_INVALID_IO_TAG is  *             passed, then a copy of the request is built internally.  The  *             request will be copied into the actual controller request  *             memory when the IO tag is allocated internally during the  *             scif_controller_start_task() method.  * @param[in]  user_task_request_object This parameter specifies the user  *             task request to be utilized during task construction.  This task  *             pointer will become the associated object for the framework  *             task request object.  * @param[in]  task_request_memory This parameter specifies the memory  *             to be utilized in the construction of the framework task request.  * @param[in]  scif_task_request This parameter specifies the handle to be  *             utilized for all further interactions with this task request  *             object.  *  * @return Indicate if the controller successfully built the task request.  * @retval SCI_SUCCESS This value is returned if the task request was  *         successfully built.  */
name|SCI_STATUS
name|scif_task_request_construct
parameter_list|(
name|SCI_CONTROLLER_HANDLE_T
name|scif_controller
parameter_list|,
name|SCI_REMOTE_DEVICE_HANDLE_T
name|scif_remote_device
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
name|task_request_memory
parameter_list|,
name|SCI_TASK_REQUEST_HANDLE_T
modifier|*
name|scif_task_request
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
comment|// _SCIF_TASK_REQUEST_H_
end_comment

end_unit


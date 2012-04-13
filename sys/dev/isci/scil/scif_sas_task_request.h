begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIF_SAS_TASK_REQUEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIF_SAS_TASK_REQUEST_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the protected interface structures, constants,  *        and methods for the SCIF_SAS_TASK_REQUEST object.  */
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
file|<dev/isci/scil/sati_translator_sequence.h>
include|#
directive|include
file|<dev/isci/scil/scif_task_request.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_request.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_request.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_internal_io_request.h>
include|#
directive|include
file|<dev/isci/scil/intel_sas.h>
comment|/**  * @struct SCIF_SAS_TASK_REQUEST  *  * @brief The SCI SAS Framework Task request object abstracts the SAS task  *        management behavior for the framework component.  Additionally,  *        it provides a higher level of abstraction for the core task  *        request object.  */
typedef|typedef
struct|struct
name|SCIF_SAS_TASK_REQUEST
block|{
comment|/**     * The SCIF_SAS_REQUEST is the parent object for the     * SCIF_SAS_TASK_REQUEST object.     */
name|SCIF_SAS_REQUEST_T
name|parent
decl_stmt|;
comment|/**     * This field contains the number of current requests affected by     * this task management request.  This number indicates all of the     * requests terminated in the silicon (including previous task requests).     */
name|U16
name|affected_request_count
decl_stmt|;
comment|/**     * This field specifies the tag for the IO request or the tag to be     * managed for a task management request.     * This field is utilized during internal IO requests.     */
name|U16
name|io_tag_to_manage
decl_stmt|;
comment|/**     * This field will be utilized to specify the task management function     * of this task request.     */
name|SCI_SAS_TASK_MGMT_FUNCTION_T
name|function
decl_stmt|;
block|}
name|SCIF_SAS_TASK_REQUEST_T
typedef|;
specifier|extern
name|SCI_BASE_STATE_T
name|scif_sas_task_request_state_table
index|[]
decl_stmt|;
specifier|extern
name|SCI_BASE_REQUEST_STATE_HANDLER_T
name|scif_sas_task_request_state_handler_table
index|[]
decl_stmt|;
name|void
name|scif_sas_task_request_operation_complete
parameter_list|(
name|SCIF_SAS_TASK_REQUEST_T
modifier|*
name|fw_task
parameter_list|)
function_decl|;
name|U8
name|scif_sas_task_request_get_function
parameter_list|(
name|SCIF_SAS_TASK_REQUEST_T
modifier|*
name|fw_task
parameter_list|)
function_decl|;
name|SCI_STATUS
name|scif_sas_internal_task_request_construct
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
name|task_request_memory
parameter_list|,
name|SCI_TASK_REQUEST_HANDLE_T
modifier|*
name|scif_task_request
parameter_list|,
name|U8
name|task_function
parameter_list|)
function_decl|;
name|void
name|scif_sas_internal_task_request_destruct
parameter_list|(
name|SCIF_SAS_TASK_REQUEST_T
modifier|*
name|fw_internal_task
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
comment|// _SCIF_SAS_TASK_REQUEST_H_
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIF_SAS_IO_REQUEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIF_SAS_IO_REQUEST_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the protected interface structures, constants,  *        and methods for the SCIF_SAS_IO_REQUEST object.  */
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
file|<dev/isci/scil/scif_io_request.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_request.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_request.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_stp_io_request.h>
include|#
directive|include
file|<dev/isci/scil/intel_sas.h>
struct_decl|struct
name|SCIF_SAS_CONTROLLER
struct_decl|;
struct_decl|struct
name|SCIF_SAS_REMOTE_DEVICE
struct_decl|;
comment|//Note 0xFF is the maximum possible value to IO_RETRY_LIMIT since the io_retry_count in
comment|//SCIF_SAS_IO_REQUEST is in type of U8.
define|#
directive|define
name|SCIF_SAS_IO_RETRY_LIMIT
value|0xFF
comment|/**  * @struct SCIF_SAS_IO_REQUEST  *  * @brief The SCI SAS Framework IO request object abstracts the SAS IO  *        level behavior for the framework component.  Additionally,  *        it provides a higher level of abstraction for the core IO request  *        object.  */
typedef|typedef
struct|struct
name|SCIF_SAS_IO_REQUEST
block|{
comment|/**     * The SCI_BASE_REQUEST is the parent object for the     * SCIF_SAS_IO_REQUEST object.     */
name|SCIF_SAS_REQUEST_T
name|parent
decl_stmt|;
comment|/**     * This field specifies the number of bytes to be utilized for this     * IO request.  This field is utilized during internal IO requests.     */
name|U32
name|transfer_length
decl_stmt|;
comment|/**     * This field keeps track of how many times an io got retried.     */
name|U8
name|retry_count
decl_stmt|;
block|}
name|SCIF_SAS_IO_REQUEST_T
typedef|;
specifier|extern
name|SCI_BASE_STATE_T
name|scif_sas_io_request_state_table
index|[]
decl_stmt|;
specifier|extern
name|SCI_BASE_REQUEST_STATE_HANDLER_T
name|scif_sas_io_request_state_handler_table
index|[]
decl_stmt|;
name|SCI_STATUS
name|scif_sas_io_request_constructed_start_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
function_decl|;
name|SCI_STATUS
name|scif_sas_io_request_constructed_abort_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
function_decl|;
name|SCI_STATUS
name|scif_sas_io_request_default_complete_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
function_decl|;
name|SCI_STATUS
name|scif_sas_io_request_default_destruct_handler
parameter_list|(
name|SCI_BASE_REQUEST_T
modifier|*
name|io_request
parameter_list|)
function_decl|;
name|SCI_STATUS
name|scif_sas_io_request_construct_smp
parameter_list|(
name|struct
name|SCIF_SAS_CONTROLLER
modifier|*
name|fw_controller
parameter_list|,
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|fw_device
parameter_list|,
name|void
modifier|*
name|fw_io_memory
parameter_list|,
name|void
modifier|*
name|core_io_memory
parameter_list|,
name|U16
name|io_tag
parameter_list|,
name|SMP_REQUEST_T
modifier|*
name|smp_command
parameter_list|,
name|void
modifier|*
name|user_request_object
parameter_list|)
function_decl|;
name|SCI_STATUS
name|scif_sas_io_request_continue
parameter_list|(
name|struct
name|SCIF_SAS_CONTROLLER
modifier|*
name|fw_controller
parameter_list|,
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|fw_device
parameter_list|,
name|SCIF_SAS_REQUEST_T
modifier|*
name|fw_request
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
comment|// _SCIF_SAS_IO_REQUEST_H_
end_comment

end_unit


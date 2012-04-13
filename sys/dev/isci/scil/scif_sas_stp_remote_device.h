begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIF_SAS_STP_REMOTE_DEVICE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIF_SAS_STP_REMOTE_DEVICE_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the protected interface structures, constants,  *        and methods for the SCIF_SAS_STP_REMOTE_DEVICE object.  */
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
file|<dev/isci/scil/sati_device.h>
define|#
directive|define
name|SCIF_SAS_INVALID_NCQ_TAG
value|0xFF
comment|/**  * @struct SCIF_SAS_STP_REMOTE_DEVICE  *  * @brief The SCI SAS STP Framework remote device object abstracts the SAS  *        SATA/STP remote device level behavior for the framework component.  */
typedef|typedef
struct|struct
name|SCIF_SAS_STP_REMOTE_DEVICE
block|{
comment|/**     * This field contains all of the data utilized by the SCSI-to-ATA     * Translation Implementation (SATI).     */
name|SATI_DEVICE_T
name|sati_device
decl_stmt|;
comment|/**     * This field contains a list of free NCQ tags available for use in     * SATA Native Command Queuing (NCQ) requests.     */
name|U32
name|s_active
decl_stmt|;
block|}
name|SCIF_SAS_STP_REMOTE_DEVICE_T
typedef|;
struct_decl|struct
name|SCIF_SAS_REMOTE_DEVICE
struct_decl|;
name|void
name|scif_sas_stp_remote_device_construct
parameter_list|(
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|fw_device
parameter_list|)
function_decl|;
name|U8
name|scif_sas_stp_remote_device_allocate_ncq_tag
parameter_list|(
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|fw_device
parameter_list|)
function_decl|;
name|void
name|scif_sas_stp_remote_device_free_ncq_tag
parameter_list|(
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|fw_device
parameter_list|,
name|U8
name|ncq_tag
parameter_list|)
function_decl|;
name|struct
name|SCIF_SAS_REQUEST
modifier|*
name|scif_sas_stp_remote_device_get_request_by_ncq_tag
parameter_list|(
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|fw_device
parameter_list|,
name|U8
name|ncq_tag
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
comment|// _SCIF_SAS_STP_REMOTE_DEVICE_H_
end_comment

end_unit


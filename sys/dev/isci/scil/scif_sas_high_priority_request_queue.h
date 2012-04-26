begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIF_SAS_HIGH_PRIORITY_REQUEST_QUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIF_SAS_HIGH_PRIORITY_REQUEST_QUEUE_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains all of method prototypes and type  *        definitions specific to the high priority request queue (HPRQ).  *        The HPRQ is the mechanism through which internal requests or  *        other important requests created by the framework are stored.  *        The HPRQ is checked during the scif_controller_start_io() path  *        and is given precedence over user supplied IO requests.  *        Additionally, when requests are created there is an attempt to  *        start them quickly.  */
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
file|<dev/isci/scil/sci_base_object.h>
include|#
directive|include
file|<dev/isci/scil/sci_pool.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_domain.h>
include|#
directive|include
file|<dev/isci/scil/scif_sas_internal_io_request.h>
typedef|typedef
struct|struct
name|SCIF_SAS_LOCK
block|{
name|SCI_BASE_OBJECT_T
name|parent
decl_stmt|;
name|SCI_LOCK_LEVEL
name|level
decl_stmt|;
block|}
name|SCIF_SAS_LOCK_T
typedef|;
comment|/**  * @struct SCIF_SAS_HIGH_PRIORITY_REQUEST_QUEUE_T  *  * @brief This structure depicts the fields contain in the high  *        priority request queue (HPRQ) object.  The HPRQ is used  *        to store IO or task requests that need to be completed  *        in short order.  */
typedef|typedef
struct|struct
name|SCIF_SAS_HIGH_PRIORITY_REQUEST_QUEUE
block|{
comment|/**     * This field specifies the necessary lock information (e.g. level)     * that must be taken before items are added or removed from the     * queue.     */
name|SCIF_SAS_LOCK_T
name|lock
decl_stmt|;
name|SCI_POOL_CREATE
argument_list|(
name|pool
argument_list|,
name|POINTER_UINT
argument_list|,
name|SCIF_SAS_MAX_INTERNAL_REQUEST_COUNT
argument_list|)
expr_stmt|;
block|}
name|SCIF_SAS_HIGH_PRIORITY_REQUEST_QUEUE_T
typedef|;
name|void
name|scif_sas_high_priority_request_queue_construct
parameter_list|(
name|SCIF_SAS_HIGH_PRIORITY_REQUEST_QUEUE_T
modifier|*
name|fw_hprq
parameter_list|,
name|SCI_BASE_LOGGER_T
modifier|*
name|logger
parameter_list|)
function_decl|;
name|void
name|scif_sas_high_priority_request_queue_purge_domain
parameter_list|(
name|SCIF_SAS_HIGH_PRIORITY_REQUEST_QUEUE_T
modifier|*
name|fw_hprq
parameter_list|,
name|SCIF_SAS_DOMAIN_T
modifier|*
name|fw_domain
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
comment|// _SCIF_SAS_HIGH_PRIORITY_REQUEST_QUEUE_H_
end_comment

end_unit


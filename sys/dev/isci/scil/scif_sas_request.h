begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIF_SAS_REQUEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIF_SAS_REQUEST_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the protected interface structures, constants,  *        and methods for the SCIF_SAS_REQUEST object.  This object provides  *        the common data and behavior to SAS IO and task management  *        request types.  */
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
file|<dev/isci/scil/sci_types.h>
include|#
directive|include
file|<dev/isci/scil/sci_status.h>
include|#
directive|include
file|<dev/isci/scil/sci_fast_list.h>
include|#
directive|include
file|<dev/isci/scil/sci_base_request.h>
define|#
directive|define
name|SCIF_SAS_RESPONSE_DATA_LENGTH
value|120
struct_decl|struct
name|SCIF_SAS_CONTROLLER
struct_decl|;
struct_decl|struct
name|SCIF_SAS_REMOTE_DEVICE
struct_decl|;
struct_decl|struct
name|SCIF_SAS_TASK_REQUEST
struct_decl|;
struct_decl|struct
name|SCIF_SAS_REQUEST
struct_decl|;
typedef|typedef
name|SCI_STATUS
function_decl|(
modifier|*
name|SCIF_SAS_REQUEST_COMPLETION_HANDLER_T
function_decl|)
parameter_list|(
name|struct
name|SCIF_SAS_CONTROLLER
modifier|*
parameter_list|,
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
parameter_list|,
name|struct
name|SCIF_SAS_REQUEST
modifier|*
parameter_list|,
name|SCI_STATUS
modifier|*
parameter_list|)
function_decl|;
comment|/**  * @struct SCIF_SAS_STP_REQUEST  *  * @brief This structure contains all of the data specific to performing  *        SATA/STP IO and TASK requests.  */
typedef|typedef
struct|struct
name|SCIF_SAS_STP_REQUEST
block|{
comment|/**     * This field contains the translation information utilized by SATI.     * For more information on this field please refer to     * SATI_TRANSLATOR_SEQUENCE.     */
name|SATI_TRANSLATOR_SEQUENCE_T
name|sequence
decl_stmt|;
comment|/**     * This field contains the ncq tag being utilized by this IO request.     * The NCQ tag value must be less than or equal to 31 (0<= tag<= 31).     */
name|U8
name|ncq_tag
decl_stmt|;
block|}
name|SCIF_SAS_STP_REQUEST_T
typedef|;
comment|/**  * @struct SCIF_SAS_REQUEST  *  * @brief The SCIF_SAS_REQUEST object abstracts the common SAS  *        IO& task management data and behavior for the framework component.  */
typedef|typedef
struct|struct
name|SCIF_SAS_REQUEST
block|{
comment|/**     * All SAS request types (IO or Task management) have the SCI base     * request as their parent object.     */
name|SCI_BASE_REQUEST_T
name|parent
decl_stmt|;
comment|/**     * This field references the list of state specific handler methods to     * be utilized for this request instance.     */
name|SCI_BASE_REQUEST_STATE_HANDLER_T
modifier|*
name|state_handlers
decl_stmt|;
name|SCIF_SAS_REQUEST_COMPLETION_HANDLER_T
name|protocol_complete_handler
decl_stmt|;
comment|/**     * This field is utilized to communicate state information relating     * to this IO request and it's state transitions.     */
name|SCI_STATUS
name|status
decl_stmt|;
comment|/**     * This field represents the remote device object to which this IO     * request is destined.     */
name|struct
name|SCIF_SAS_REMOTE_DEVICE
modifier|*
name|device
decl_stmt|;
comment|/**     * This field references the request object that has asked that this     * request be terminated.     */
name|struct
name|SCIF_SAS_TASK_REQUEST
modifier|*
name|terminate_requestor
decl_stmt|;
comment|/**     * This field provides list specific information that enables a request     * to be placed in a list.     */
name|SCI_FAST_LIST_ELEMENT_T
name|list_element
decl_stmt|;
comment|/**     * This field indicates if the current request is one internally     * generated by the framework or if it is a user IO/task request.     */
name|BOOL
name|is_internal
decl_stmt|;
comment|/**     * This field indicates the current request is a high priority one.     * An internal request is always high priority. But an external request     * could be high priority.     */
name|BOOL
name|is_high_priority
decl_stmt|;
comment|/**     * This field indicates the current request should not be completed     * until a pending abort task set request is completed.  For NCQ errors,     * it will allow waiting until the read log ext data is returned to     * to determine how to fail/abort the pending ios.     */
name|BOOL
name|is_waiting_for_abort_task_set
decl_stmt|;
comment|/**     * This field indicates the logical unit (LUN) for the request.     * This field is utilized during internal IO requests.     */
name|U32
name|lun
decl_stmt|;
comment|/**     * This field specifies sata specific data for the reqeust object.     * This data is only valid for SATA requests.     */
name|SCIF_SAS_STP_REQUEST_T
name|stp
decl_stmt|;
comment|/**     * This field contains the handle for the SCI Core request object that is     * managed by this framework request.     */
name|SCI_IO_REQUEST_HANDLE_T
name|core_object
decl_stmt|;
block|}
name|SCIF_SAS_REQUEST_T
typedef|;
name|void
name|scif_sas_request_construct
parameter_list|(
name|SCIF_SAS_REQUEST_T
modifier|*
name|fw_request
parameter_list|,
name|struct
name|SCIF_SAS_REMOTE_DEVICE
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
function_decl|;
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
function_decl|;
name|void
name|scif_sas_request_terminate_complete
parameter_list|(
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
comment|// _SCIF_SAS_REQUEST_H_
end_comment

end_unit


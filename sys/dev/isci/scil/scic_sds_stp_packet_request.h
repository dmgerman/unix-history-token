begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_SDS_STP_PACKET_REQUEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_SDS_STP_PACKET_REQUEST_H_
end_define

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
file|<dev/isci/scil/intel_sas.h>
include|#
directive|include
file|<dev/isci/scil/sci_types.h>
include|#
directive|include
file|<dev/isci/scil/scic_sds_stp_request.h>
comment|/**  * @file  *  * @brief This file contains the structures and constants for PACKET protocol  *        requests.  */
comment|/**  * @enum  *  * This is the enumeration of the SATA PIO DATA IN started substate machine.  */
enum|enum
name|_SCIC_SDS_STP_PACKET_REQUEST_STARTED_SUBSTATES
block|{
comment|/**     * While in this state the IO request object is waiting for the TC completion     * notification for the H2D Register FIS     */
name|SCIC_SDS_STP_PACKET_REQUEST_STARTED_PACKET_PHASE_AWAIT_TC_COMPLETION_SUBSTATE
block|,
comment|/**     * While in this state the IO request object is waiting for either a PIO Setup.     */
name|SCIC_SDS_STP_PACKET_REQUEST_STARTED_PACKET_PHASE_AWAIT_PIO_SETUP_SUBSTATE
block|,
comment|/**     * While in this state the IO request object is waiting for TC completion for     * the Packet DMA DATA fis or Raw Frame.     */
name|SCIC_SDS_STP_PACKET_REQUEST_STARTED_COMMAND_PHASE_AWAIT_TC_COMPLETION_SUBSTATE
block|,
comment|/**     * The non-data IO transit to this state in this state after receiving TC     * completion. While in this state IO request object is waiting for D2H status     * frame as UF.     */
name|SCIC_SDS_STP_PACKET_REQUEST_STARTED_COMMAND_PHASE_AWAIT_D2H_FIS_SUBSTATE
block|,
comment|/**     * The IO transit to this state in this state if the previous TC completion status     * is not success and the atapi device is suspended due to target device failed the IO.     * While in this state IO request object is waiting for device coming out of the     * suspension state then complete the IO.     */
name|SCIC_SDS_STP_PACKET_REQUEST_STARTED_COMPLETION_DELAY_SUBSTATE
block|,
name|SCIC_SDS_STP_PACKET_REQUEST_STARTED_MAX_SUBSTATES
block|}
enum|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_ATAPI
argument_list|)
specifier|extern
name|SCI_BASE_STATE_T
name|scic_sds_stp_packet_request_started_substate_table
index|[]
decl_stmt|;
specifier|extern
name|SCIC_SDS_IO_REQUEST_STATE_HANDLER_T
name|scic_sds_stp_packet_request_started_substate_handler_table
index|[]
decl_stmt|;
endif|#
directive|endif
comment|// !defined(DISABLE_ATAPI)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_ATAPI
argument_list|)
name|SCI_STATUS
name|scic_sds_stp_packet_request_construct
parameter_list|(
name|SCIC_SDS_REQUEST_T
modifier|*
name|this_request
parameter_list|)
function_decl|;
else|#
directive|else
comment|// !defined(DISABLE_ATAPI)
define|#
directive|define
name|scic_sds_stp_packet_request_construct
parameter_list|(
name|request
parameter_list|)
value|SCI_FAILURE
endif|#
directive|endif
comment|// !defined(DISABLE_ATAPI)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_ATAPI
argument_list|)
name|void
name|scu_stp_packet_request_command_phase_construct_task_context
parameter_list|(
name|SCIC_SDS_REQUEST_T
modifier|*
name|this_request
parameter_list|,
name|SCU_TASK_CONTEXT_T
modifier|*
name|task_context
parameter_list|)
function_decl|;
else|#
directive|else
comment|// !defined(DISABLE_ATAPI)
define|#
directive|define
name|scu_stp_packet_request_command_phase_construct_task_context
parameter_list|(
name|reqeust
parameter_list|,
name|tc
parameter_list|)
endif|#
directive|endif
comment|// !defined(DISABLE_ATAPI)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_ATAPI
argument_list|)
name|void
name|scu_stp_packet_request_command_phase_reconstruct_raw_frame_task_context
parameter_list|(
name|SCIC_SDS_REQUEST_T
modifier|*
name|this_request
parameter_list|,
name|SCU_TASK_CONTEXT_T
modifier|*
name|task_context
parameter_list|)
function_decl|;
else|#
directive|else
comment|// !defined(DISABLE_ATAPI)
define|#
directive|define
name|scu_stp_packet_request_command_phase_reconstruct_raw_frame_task_context
parameter_list|(
name|reqeust
parameter_list|,
name|tc
parameter_list|)
endif|#
directive|endif
comment|// !defined(DISABLE_ATAPI)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_ATAPI
argument_list|)
name|SCI_STATUS
name|scic_sds_stp_packet_request_process_status_fis
parameter_list|(
name|SCIC_SDS_REQUEST_T
modifier|*
name|this_request
parameter_list|,
name|SATA_FIS_REG_D2H_T
modifier|*
name|status_fis
parameter_list|)
function_decl|;
else|#
directive|else
comment|// !defined(DISABLE_ATAPI)
define|#
directive|define
name|scic_sds_stp_packet_request_process_status_fis
parameter_list|(
name|reqeust
parameter_list|,
name|fis
parameter_list|)
value|SCI_FAILURE
endif|#
directive|endif
comment|// !defined(DISABLE_ATAPI)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_ATAPI
argument_list|)
name|void
name|scic_sds_stp_packet_internal_request_sense_build_sgl
parameter_list|(
name|SCIC_SDS_REQUEST_T
modifier|*
name|this_request
parameter_list|)
function_decl|;
else|#
directive|else
comment|// !defined(DISABLE_ATAPI)
define|#
directive|define
name|scic_sds_stp_packet_internal_request_sense_build_sgl
parameter_list|(
name|request
parameter_list|)
endif|#
directive|endif
comment|// !defined(DISABLE_ATAPI)
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
comment|// _SCIC_SDS_STP_PACKET_REQUEST_H_
end_comment

end_unit


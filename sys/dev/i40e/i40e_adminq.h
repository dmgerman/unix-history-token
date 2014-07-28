begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I40E_ADMINQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_I40E_ADMINQ_H_
end_define

begin_include
include|#
directive|include
file|"i40e_osdep.h"
end_include

begin_include
include|#
directive|include
file|"i40e_adminq_cmd.h"
end_include

begin_define
define|#
directive|define
name|I40E_ADMINQ_DESC
parameter_list|(
name|R
parameter_list|,
name|i
parameter_list|)
define|\
value|(&(((struct i40e_aq_desc *)((R).desc_buf.va))[i]))
end_define

begin_define
define|#
directive|define
name|I40E_ADMINQ_DESC_ALIGNMENT
value|4096
end_define

begin_struct
struct|struct
name|i40e_adminq_ring
block|{
name|struct
name|i40e_virt_mem
name|dma_head
decl_stmt|;
comment|/* space for dma structures */
name|struct
name|i40e_dma_mem
name|desc_buf
decl_stmt|;
comment|/* descriptor ring memory */
name|struct
name|i40e_virt_mem
name|cmd_buf
decl_stmt|;
comment|/* command buffer memory */
union|union
block|{
name|struct
name|i40e_dma_mem
modifier|*
name|asq_bi
decl_stmt|;
name|struct
name|i40e_dma_mem
modifier|*
name|arq_bi
decl_stmt|;
block|}
name|r
union|;
name|u16
name|count
decl_stmt|;
comment|/* Number of descriptors */
name|u16
name|rx_buf_len
decl_stmt|;
comment|/* Admin Receive Queue buffer length */
comment|/* used for interrupt processing */
name|u16
name|next_to_use
decl_stmt|;
name|u16
name|next_to_clean
decl_stmt|;
comment|/* used for queue tracking */
name|u32
name|head
decl_stmt|;
name|u32
name|tail
decl_stmt|;
name|u32
name|len
decl_stmt|;
name|u32
name|bah
decl_stmt|;
name|u32
name|bal
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ASQ transaction details */
end_comment

begin_struct
struct|struct
name|i40e_asq_cmd_details
block|{
name|void
modifier|*
name|callback
decl_stmt|;
comment|/* cast from type I40E_ADMINQ_CALLBACK */
name|u64
name|cookie
decl_stmt|;
name|u16
name|flags_ena
decl_stmt|;
name|u16
name|flags_dis
decl_stmt|;
name|bool
name|async
decl_stmt|;
name|bool
name|postpone
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I40E_ADMINQ_DETAILS
parameter_list|(
name|R
parameter_list|,
name|i
parameter_list|)
define|\
value|(&(((struct i40e_asq_cmd_details *)((R).cmd_buf.va))[i]))
end_define

begin_comment
comment|/* ARQ event information */
end_comment

begin_struct
struct|struct
name|i40e_arq_event_info
block|{
name|struct
name|i40e_aq_desc
name|desc
decl_stmt|;
name|u16
name|msg_size
decl_stmt|;
name|u8
modifier|*
name|msg_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Admin Queue information */
end_comment

begin_struct
struct|struct
name|i40e_adminq_info
block|{
name|struct
name|i40e_adminq_ring
name|arq
decl_stmt|;
comment|/* receive queue */
name|struct
name|i40e_adminq_ring
name|asq
decl_stmt|;
comment|/* send queue */
name|u32
name|asq_cmd_timeout
decl_stmt|;
comment|/* send queue cmd write back timeout*/
name|u16
name|num_arq_entries
decl_stmt|;
comment|/* receive queue depth */
name|u16
name|num_asq_entries
decl_stmt|;
comment|/* send queue depth */
name|u16
name|arq_buf_size
decl_stmt|;
comment|/* receive queue buffer size */
name|u16
name|asq_buf_size
decl_stmt|;
comment|/* send queue buffer size */
name|u16
name|fw_maj_ver
decl_stmt|;
comment|/* firmware major version */
name|u16
name|fw_min_ver
decl_stmt|;
comment|/* firmware minor version */
name|u16
name|api_maj_ver
decl_stmt|;
comment|/* api major version */
name|u16
name|api_min_ver
decl_stmt|;
comment|/* api minor version */
name|bool
name|nvm_busy
decl_stmt|;
name|bool
name|nvm_release_on_done
decl_stmt|;
name|struct
name|i40e_spinlock
name|asq_spinlock
decl_stmt|;
comment|/* Send queue spinlock */
name|struct
name|i40e_spinlock
name|arq_spinlock
decl_stmt|;
comment|/* Receive queue spinlock */
comment|/* last status values on send and receive queues */
name|enum
name|i40e_admin_queue_err
name|asq_last_status
decl_stmt|;
name|enum
name|i40e_admin_queue_err
name|arq_last_status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* general information */
end_comment

begin_define
define|#
directive|define
name|I40E_AQ_LARGE_BUF
value|512
end_define

begin_define
define|#
directive|define
name|I40E_ASQ_CMD_TIMEOUT
value|100000
end_define

begin_comment
comment|/* usecs */
end_comment

begin_function_decl
name|void
name|i40e_fill_default_direct_cmd_desc
parameter_list|(
name|struct
name|i40e_aq_desc
modifier|*
name|desc
parameter_list|,
name|u16
name|opcode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I40E_ADMINQ_H_ */
end_comment

end_unit


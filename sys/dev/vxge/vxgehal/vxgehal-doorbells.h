begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_HAL_DOOR_BELLS_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_DOOR_BELLS_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/*  * struct __hal_non_offload_db_wrapper_t - Non-offload Doorbell Wrapper  * @control_0:	Bits 0 to 7 - Doorbell type.  *		Bits 8 to 31 - Reserved.  *		Bits 32 to 39 - The highest TxD in this TxDL.  *		Bits 40 to 47 - Reserved.  *		Bits 48 to 55 - Reserved.  *		Bits 56 to 63 - No snoop flags.  * @txdl_ptr:	The starting location of the TxDL in host memory.  *  * Created by the host and written to the adapter via PIO to a Kernel Doorbell  * FIFO. All non-offload doorbell wrapper fields must be written by the host as  * part of a doorbell write. Consumed by the adapter but is not written by the  * adapter.  */
end_comment

begin_typedef
typedef|typedef
name|__vxge_os_attr_cacheline_aligned
struct|struct
name|__hal_non_offload_db_wrapper_t
block|{
name|u64
name|control_0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_NODBW_GET_TYPE
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL8(ctrl0, 0)
define|#
directive|define
name|VXGE_HAL_NODBW_TYPE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 8)
define|#
directive|define
name|VXGE_HAL_NODBW_TYPE_NODBW
value|0
define|#
directive|define
name|VXGE_HAL_NODBW_GET_LAST_TXD_NUMBER
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL8(ctrl0, 32)
define|#
directive|define
name|VXGE_HAL_NODBW_LAST_TXD_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 8)
define|#
directive|define
name|VXGE_HAL_NODBW_GET_NO_SNOOP
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL8(ctrl0, 56)
define|#
directive|define
name|VXGE_HAL_NODBW_LIST_NO_SNOOP
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 56, 8)
define|#
directive|define
name|VXGE_HAL_NODBW_LIST_NO_SNOOP_TXD_READ_TXD0_WRITE
value|0x2
define|#
directive|define
name|VXGE_HAL_NODBW_LIST_NO_SNOOP_TX_FRAME_DATA_READ
value|0x1
name|u64
name|txdl_ptr
decl_stmt|;
block|}
name|__hal_non_offload_db_wrapper_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct __hal_offload_db_wrapper_t - Tx-Offload Doorbell Wrapper  * @control_0:	Bits 0 to 7 - Doorbell type.  *		Bits 8 to 31 - Identifies the session to which this Tx  *		offload doorbell applies.  *		Bits 32 to 40 - Identifies the incarnation of this Session  *		Number. The adapter assigns a Session Instance  *		Number of 0 to a session when that Session Number  *		is first used. Each subsequent assignment of that  *		Session Number from the free pool causes this  *		number to be incremented, with wrap eventually  *		occurring from 255 back to 0.  *		Bits 40 to 63 - Identifies the end of the TOWI list for  *		this session to the adapter.  * @control_1:	Bits 0 to 7 - Identifies what is included in this doorbell  *		Bits 8 to 15 - The number of Immediate data bytes included in  *		this doorbell.  *		Bits 16 to 63 - Reserved.  *  * Created by the host and written to the adapter via PIO to a Kernel Doorbell  * FIFO. All Tx Offload doorbell wrapper fields must be written by the host as  * part of a doorbell write. Consumed by the adapter but is never written by the  * adapter.  */
end_comment

begin_typedef
typedef|typedef
name|__vxge_os_attr_cacheline_aligned
struct|struct
name|__hal_offload_db_wrapper_t
block|{
name|u64
name|control_0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ODBW_GET_TYPE
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL8(ctrl0, 0)
define|#
directive|define
name|VXGE_HAL_ODBW_TYPE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 8)
define|#
directive|define
name|VXGE_HAL_ODBW_TYPE_ODBW
value|1
define|#
directive|define
name|VXGE_HAL_ODBW_GET_SESSION_NUMBER
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL24(ctrl0, 8)
define|#
directive|define
name|VXGE_HAL_ODBW_SESSION_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 8, 24)
define|#
directive|define
name|VXGE_HAL_ODBW_GET_SESSION_INST_NUMBER
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL8(ctrl0, 32)
define|#
directive|define
name|VXGE_HAL_ODBW_SESSION_INST_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 8)
define|#
directive|define
name|VXGE_HAL_ODBW_GET_HIGH_TOWI_NUMBER
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL24(ctrl0, 40)
define|#
directive|define
name|VXGE_HAL_ODBW_HIGH_TOWI_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 40, 24)
name|u64
name|control_1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ODBW_GET_ENTRY_TYPE
parameter_list|(
name|ctrl1
parameter_list|)
value|bVAL8(ctrl1, 0)
define|#
directive|define
name|VXGE_HAL_ODBW_ENTRY_TYPE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 8)
define|#
directive|define
name|VXGE_HAL_ODBW_ENTRY_TYPE_WRAPPER_ONLY
value|0x0
define|#
directive|define
name|VXGE_HAL_ODBW_ENTRY_TYPE_WRAPPER_TOWI
value|0x1
define|#
directive|define
name|VXGE_HAL_ODBW_ENTRY_TYPE_WRAPPER_TOWI_DATA
value|0x2
define|#
directive|define
name|VXGE_HAL_ODBW_GET_IMMEDIATE_BYTE_COUNT
parameter_list|(
name|ctrl1
parameter_list|)
value|bVAL8(ctrl1, 8)
define|#
directive|define
name|VXGE_HAL_ODBW_IMMEDIATE_BYTE_COUNT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 8, 8)
block|}
name|__hal_offload_db_wrapper_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct __hal_offload_atomic_db_wrapper_t - Atomic Tx-Offload Doorbell  *						 Wrapper  * @control_0:	Bits 0 to 7 - Doorbell type.  *		Bits 8 to 31 - Identifies the session to which this Tx  *		offload doorbell applies.  *		Bits 32 to 40 - Identifies the incarnation of this Session  *		Number. The adapter assigns a Session Instance  *		Number of 0 to a session when that Session Number  *		is first used. Each subsequent assignment of that  *		Session Number from the free pool causes this  *		number to be incremented, with wrap eventually  *		occurring from 255 back to 0.  *		Bits 40 to 63 - Identifies the end of the TOWI list for  *		this session to the adapter.  *  * Created by the host and written to the adapter via PIO to a Kernel Doorbell  * FIFO.  All Tx Offload doorbell wrapper fields must be written by the host as  * part of a doorbell write. Consumed by the adapter but is never written by the  * adapter.  */
end_comment

begin_typedef
typedef|typedef
name|__vxge_os_attr_cacheline_aligned
struct|struct
name|__hal_offload_atomic_db_wrapper_t
block|{
name|u64
name|control_0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ODBW_GET_TYPE
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL8(ctrl0, 0)
define|#
directive|define
name|VXGE_HAL_ODBW_TYPE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 8)
define|#
directive|define
name|VXGE_HAL_ODBW_TYPE_ATOMIC
value|2
define|#
directive|define
name|VXGE_HAL_ODBW_GET_SESSION_NUMBER
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL24(ctrl0, 8)
define|#
directive|define
name|VXGE_HAL_ODBW_SESSION_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 8, 24)
define|#
directive|define
name|VXGE_HAL_ODBW_GET_SESSION_INST_NUMBER
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL8(ctrl0, 32)
define|#
directive|define
name|VXGE_HAL_ODBW_SESSION_INST_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 8)
define|#
directive|define
name|VXGE_HAL_ODBW_GET_HIGH_TOWI_NUMBER
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL24(ctrl0, 40)
define|#
directive|define
name|VXGE_HAL_ODBW_HIGH_TOWI_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 40, 24)
block|}
name|__hal_offload_atomic_db_wrapper_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct __hal_messaging_db_wrapper_t - Messaging Doorbell Wrapper  * @control_0:	Bits 0 to 7 - Doorbell type.  *		Bits 8 to 31 - Reserved.  *		Bits 32 to 63 - The number of new message bytes made available  *		by this doorbell entry.  * @control_1:	Bits 0 to 7 - Reserved.  *		Bits 8 to 15 - The number of Immediate messaging bytes included  *		in this doorbell.  *		Bits 16 to 63 - Reserved.  *  * Created by the host and written to the adapter via PIO to a Kernel Doorbell  * FIFO. All message doorbell wrapper fields must be written by the host as  * part of a doorbell write. Consumed by the adapter but not written by adapter.  */
end_comment

begin_typedef
typedef|typedef
name|__vxge_os_attr_cacheline_aligned
struct|struct
name|__hal_messaging_db_wrapper_t
block|{
name|u64
name|control_0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MDBW_GET_TYPE
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL8(ctrl0, 0)
define|#
directive|define
name|VXGE_HAL_MDBW_TYPE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 8)
define|#
directive|define
name|VXGE_HAL_MDBW_TYPE_MDBW
value|3
define|#
directive|define
name|VXGE_HAL_MDBW_GET_MESSAGE_BYTE_COUNT
parameter_list|(
name|ctrl0
parameter_list|)
value|bVAL32(ctrl0, 32)
define|#
directive|define
name|VXGE_HAL_MDBW_MESSAGE_BYTE_COUNT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 32)
name|u64
name|control_1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MDBW_GET_IMMEDIATE_BYTE_COUNT
parameter_list|(
name|ctrl1
parameter_list|)
value|bVAL8(ctrl1, 8)
define|#
directive|define
name|VXGE_HAL_MDBW_IMMEDIATE_BYTE_COUNT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 8, 8)
block|}
name|__hal_messaging_db_wrapper_t
typedef|;
end_typedef

begin_function_decl
name|void
name|__hal_non_offload_db_post
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|,
name|u64
name|txdl_ptr
parameter_list|,
name|u32
name|num_txds
parameter_list|,
name|u32
name|no_snoop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_rxd_db_post
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|,
name|u32
name|num_bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_non_offload_db_reset
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_message_db_post
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|,
name|u32
name|num_msg_bytes
parameter_list|,
name|u8
modifier|*
name|immed_msg
parameter_list|,
name|u32
name|immed_msg_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_message_db_reset
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_DOOR_BELLS_H */
end_comment

end_unit


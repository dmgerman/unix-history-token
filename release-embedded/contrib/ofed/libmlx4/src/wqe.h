begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Cisco, Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WQE_H
end_ifndef

begin_define
define|#
directive|define
name|WQE_H
end_define

begin_enum
enum|enum
block|{
name|MLX4_SEND_DOORBELL
init|=
literal|0x14
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|MLX4_WQE_CTRL_FENCE
init|=
literal|1
operator|<<
literal|6
block|,
name|MLX4_WQE_CTRL_CQ_UPDATE
init|=
literal|3
operator|<<
literal|2
block|,
name|MLX4_WQE_CTRL_SOLICIT
init|=
literal|1
operator|<<
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|MLX4_INLINE_SEG
init|=
literal|1
operator|<<
literal|31
block|,
name|MLX4_INLINE_ALIGN
init|=
literal|64
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|MLX4_INVALID_LKEY
init|=
literal|0x100
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|mlx4_wqe_ctrl_seg
block|{
name|uint32_t
name|owner_opcode
decl_stmt|;
name|uint16_t
name|vlan_tag
decl_stmt|;
name|uint8_t
name|ins_vlan
decl_stmt|;
name|uint8_t
name|fence_size
decl_stmt|;
comment|/* 	 * High 24 bits are SRC remote buffer; low 8 bits are flags: 	 * [7]   SO (strong ordering) 	 * [5]   TCP/UDP checksum 	 * [4]   IP checksum 	 * [3:2] C (generate completion queue entry) 	 * [1]   SE (solicited event) 	 * [0]   FL (force loopback) 	 */
name|uint32_t
name|xrcrb_flags
decl_stmt|;
comment|/* 	 * imm is immediate data for send/RDMA write w/ immediate; 	 * also invalidation key for send with invalidate; input 	 * modifier for WQEs on CCQs. 	 */
name|uint32_t
name|imm
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_wqe_datagram_seg
block|{
name|uint32_t
name|av
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|dqpn
decl_stmt|;
name|uint32_t
name|qkey
decl_stmt|;
name|uint16_t
name|vlan
decl_stmt|;
name|uint8_t
name|mac
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_wqe_data_seg
block|{
name|uint32_t
name|byte_count
decl_stmt|;
name|uint32_t
name|lkey
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_wqe_inline_seg
block|{
name|uint32_t
name|byte_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_wqe_srq_next_seg
block|{
name|uint16_t
name|reserved1
decl_stmt|;
name|uint16_t
name|next_wqe_index
decl_stmt|;
name|uint32_t
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_wqe_raddr_seg
block|{
name|uint64_t
name|raddr
decl_stmt|;
name|uint32_t
name|rkey
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_wqe_atomic_seg
block|{
name|uint64_t
name|swap_add
decl_stmt|;
name|uint64_t
name|compare
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_wqe_bind_seg
block|{
name|uint32_t
name|flags1
decl_stmt|;
name|uint32_t
name|flags2
decl_stmt|;
name|uint32_t
name|new_rkey
decl_stmt|;
name|uint32_t
name|lkey
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
name|uint64_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WQE_H */
end_comment

end_unit


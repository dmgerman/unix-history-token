begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007, 2008 Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CXIO_WR_H__
end_ifndef

begin_define
define|#
directive|define
name|__CXIO_WR_H__
end_define

begin_define
define|#
directive|define
name|T3_MAX_SGE
value|4
end_define

begin_define
define|#
directive|define
name|T3_MAX_INLINE
value|64
end_define

begin_define
define|#
directive|define
name|T3_STAG0_PBL_SIZE
value|(2 * T3_MAX_SGE<< 3)
end_define

begin_define
define|#
directive|define
name|T3_STAG0_MAX_PBE_LEN
value|(128 * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|T3_STAG0_PAGE_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|Q_EMPTY
parameter_list|(
name|rptr
parameter_list|,
name|wptr
parameter_list|)
value|((rptr)==(wptr))
end_define

begin_define
define|#
directive|define
name|Q_FULL
parameter_list|(
name|rptr
parameter_list|,
name|wptr
parameter_list|,
name|size_log2
parameter_list|)
value|( (((wptr)-(rptr))>>(size_log2))&& \ 				       ((rptr)!=(wptr)) )
end_define

begin_define
define|#
directive|define
name|Q_GENBIT
parameter_list|(
name|ptr
parameter_list|,
name|size_log2
parameter_list|)
value|(!(((ptr)>>size_log2)&0x1))
end_define

begin_define
define|#
directive|define
name|Q_FREECNT
parameter_list|(
name|rptr
parameter_list|,
name|wptr
parameter_list|,
name|size_log2
parameter_list|)
value|((1UL<<size_log2)-((wptr)-(rptr)))
end_define

begin_define
define|#
directive|define
name|Q_COUNT
parameter_list|(
name|rptr
parameter_list|,
name|wptr
parameter_list|)
value|((wptr)-(rptr))
end_define

begin_define
define|#
directive|define
name|Q_PTR2IDX
parameter_list|(
name|ptr
parameter_list|,
name|size_log2
parameter_list|)
value|(ptr& ((1UL<<size_log2)-1))
end_define

begin_function
specifier|static
name|__inline
name|void
name|ring_doorbell
parameter_list|(
name|void
comment|/* __iomem  */
modifier|*
name|doorbell
parameter_list|,
name|u32
name|qpid
parameter_list|)
block|{
name|writel
argument_list|(
name|doorbell
argument_list|,
operator|(
operator|(
literal|1
operator|<<
literal|31
operator|)
operator||
name|qpid
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|SEQ32_GE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(!( (((u32) (x)) - ((u32) (y)))& 0x80000000 ))
end_define

begin_enum
enum|enum
name|t3_wr_flags
block|{
name|T3_COMPLETION_FLAG
init|=
literal|0x01
block|,
name|T3_NOTIFY_FLAG
init|=
literal|0x02
block|,
name|T3_SOLICITED_EVENT_FLAG
init|=
literal|0x04
block|,
name|T3_READ_FENCE_FLAG
init|=
literal|0x08
block|,
name|T3_LOCAL_FENCE_FLAG
init|=
literal|0x10
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
enum|;
end_enum

begin_enum
enum|enum
name|t3_wr_opcode
block|{
name|T3_WR_BP
init|=
name|FW_WROPCODE_RI_BYPASS
block|,
name|T3_WR_SEND
init|=
name|FW_WROPCODE_RI_SEND
block|,
name|T3_WR_WRITE
init|=
name|FW_WROPCODE_RI_RDMA_WRITE
block|,
name|T3_WR_READ
init|=
name|FW_WROPCODE_RI_RDMA_READ
block|,
name|T3_WR_INV_STAG
init|=
name|FW_WROPCODE_RI_LOCAL_INV
block|,
name|T3_WR_BIND
init|=
name|FW_WROPCODE_RI_BIND_MW
block|,
name|T3_WR_RCV
init|=
name|FW_WROPCODE_RI_RECEIVE
block|,
name|T3_WR_INIT
init|=
name|FW_WROPCODE_RI_RDMA_INIT
block|,
name|T3_WR_QP_MOD
init|=
name|FW_WROPCODE_RI_MODIFY_QP
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
enum|;
end_enum

begin_enum
enum|enum
name|t3_rdma_opcode
block|{
name|T3_RDMA_WRITE
block|,
comment|/* IETF RDMAP v1.0 ... */
name|T3_READ_REQ
block|,
name|T3_READ_RESP
block|,
name|T3_SEND
block|,
name|T3_SEND_WITH_INV
block|,
name|T3_SEND_WITH_SE
block|,
name|T3_SEND_WITH_SE_INV
block|,
name|T3_TERMINATE
block|,
name|T3_RDMA_INIT
block|,
comment|/* CHELSIO RI specific ... */
name|T3_BIND_MW
block|,
name|T3_FAST_REGISTER
block|,
name|T3_LOCAL_INV
block|,
name|T3_QP_MOD
block|,
name|T3_BYPASS
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
enum|;
end_enum

begin_function
specifier|static
specifier|inline
name|enum
name|t3_rdma_opcode
name|wr2opcode
parameter_list|(
name|enum
name|t3_wr_opcode
name|wrop
parameter_list|)
block|{
switch|switch
condition|(
name|wrop
condition|)
block|{
case|case
name|T3_WR_BP
case|:
return|return
name|T3_BYPASS
return|;
case|case
name|T3_WR_SEND
case|:
return|return
name|T3_SEND
return|;
case|case
name|T3_WR_WRITE
case|:
return|return
name|T3_RDMA_WRITE
return|;
case|case
name|T3_WR_READ
case|:
return|return
name|T3_READ_REQ
return|;
case|case
name|T3_WR_INV_STAG
case|:
return|return
name|T3_LOCAL_INV
return|;
case|case
name|T3_WR_BIND
case|:
return|return
name|T3_BIND_MW
return|;
case|case
name|T3_WR_INIT
case|:
return|return
name|T3_RDMA_INIT
return|;
case|case
name|T3_WR_QP_MOD
case|:
return|return
name|T3_QP_MOD
return|;
default|default:
break|break;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Work request id */
end_comment

begin_union
union|union
name|t3_wrid
block|{
struct|struct
block|{
name|u32
name|hi
decl_stmt|;
name|u32
name|low
decl_stmt|;
block|}
name|id0
struct|;
name|u64
name|id1
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|WRID
parameter_list|(
name|wrid
parameter_list|)
value|(wrid.id1)
end_define

begin_define
define|#
directive|define
name|WRID_GEN
parameter_list|(
name|wrid
parameter_list|)
value|(wrid.id0.wr_gen)
end_define

begin_define
define|#
directive|define
name|WRID_IDX
parameter_list|(
name|wrid
parameter_list|)
value|(wrid.id0.wr_idx)
end_define

begin_define
define|#
directive|define
name|WRID_LO
parameter_list|(
name|wrid
parameter_list|)
value|(wrid.id0.wr_lo)
end_define

begin_struct
struct|struct
name|fw_riwrh
block|{
name|__be32
name|op_seop_flags
decl_stmt|;
name|__be32
name|gen_tid_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_RIWR_OP
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_RIWR_OP
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_RIWR_OP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RIWR_OP)
end_define

begin_define
define|#
directive|define
name|G_FW_RIWR_OP
parameter_list|(
name|x
parameter_list|)
value|((((x)>> S_FW_RIWR_OP))& M_FW_RIWR_OP)
end_define

begin_define
define|#
directive|define
name|S_FW_RIWR_SOPEOP
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_RIWR_SOPEOP
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_RIWR_SOPEOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RIWR_SOPEOP)
end_define

begin_define
define|#
directive|define
name|S_FW_RIWR_FLAGS
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_RIWR_FLAGS
value|0x3fffff
end_define

begin_define
define|#
directive|define
name|V_FW_RIWR_FLAGS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RIWR_FLAGS)
end_define

begin_define
define|#
directive|define
name|G_FW_RIWR_FLAGS
parameter_list|(
name|x
parameter_list|)
value|((((x)>> S_FW_RIWR_FLAGS))& M_FW_RIWR_FLAGS)
end_define

begin_define
define|#
directive|define
name|S_FW_RIWR_TID
value|8
end_define

begin_define
define|#
directive|define
name|V_FW_RIWR_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RIWR_TID)
end_define

begin_define
define|#
directive|define
name|S_FW_RIWR_LEN
value|0
end_define

begin_define
define|#
directive|define
name|V_FW_RIWR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RIWR_LEN)
end_define

begin_define
define|#
directive|define
name|S_FW_RIWR_GEN
value|31
end_define

begin_define
define|#
directive|define
name|V_FW_RIWR_GEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RIWR_GEN)
end_define

begin_struct
struct|struct
name|t3_sge
block|{
name|__be32
name|stag
decl_stmt|;
name|__be32
name|len
decl_stmt|;
name|__be64
name|to
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* If num_sgle is zero, flit 5+ contains immediate data.*/
end_comment

begin_struct
struct|struct
name|t3_send_wr
block|{
name|struct
name|fw_riwrh
name|wrh
decl_stmt|;
comment|/* 0 */
name|union
name|t3_wrid
name|wrid
decl_stmt|;
comment|/* 1 */
name|u8
name|rdmaop
decl_stmt|;
comment|/* 2 */
name|u8
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|rem_stag
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
comment|/* 3 */
name|__be32
name|num_sgle
decl_stmt|;
name|struct
name|t3_sge
name|sgl
index|[
name|T3_MAX_SGE
index|]
decl_stmt|;
comment|/* 4+ */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_local_inv_wr
block|{
name|struct
name|fw_riwrh
name|wrh
decl_stmt|;
comment|/* 0 */
name|union
name|t3_wrid
name|wrid
decl_stmt|;
comment|/* 1 */
name|__be32
name|stag
decl_stmt|;
comment|/* 2 */
name|__be32
name|reserved3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_rdma_write_wr
block|{
name|struct
name|fw_riwrh
name|wrh
decl_stmt|;
comment|/* 0 */
name|union
name|t3_wrid
name|wrid
decl_stmt|;
comment|/* 1 */
name|u8
name|rdmaop
decl_stmt|;
comment|/* 2 */
name|u8
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|stag_sink
decl_stmt|;
name|__be64
name|to_sink
decl_stmt|;
comment|/* 3 */
name|__be32
name|plen
decl_stmt|;
comment|/* 4 */
name|__be32
name|num_sgle
decl_stmt|;
name|struct
name|t3_sge
name|sgl
index|[
name|T3_MAX_SGE
index|]
decl_stmt|;
comment|/* 5+ */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_rdma_read_wr
block|{
name|struct
name|fw_riwrh
name|wrh
decl_stmt|;
comment|/* 0 */
name|union
name|t3_wrid
name|wrid
decl_stmt|;
comment|/* 1 */
name|u8
name|rdmaop
decl_stmt|;
comment|/* 2 */
name|u8
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|rem_stag
decl_stmt|;
name|__be64
name|rem_to
decl_stmt|;
comment|/* 3 */
name|__be32
name|local_stag
decl_stmt|;
comment|/* 4 */
name|__be32
name|local_len
decl_stmt|;
name|__be64
name|local_to
decl_stmt|;
comment|/* 5 */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|t3_addr_type
block|{
name|T3_VA_BASED_TO
init|=
literal|0x0
block|,
name|T3_ZERO_BASED_TO
init|=
literal|0x1
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
enum|;
end_enum

begin_enum
enum|enum
name|t3_mem_perms
block|{
name|T3_MEM_ACCESS_LOCAL_READ
init|=
literal|0x1
block|,
name|T3_MEM_ACCESS_LOCAL_WRITE
init|=
literal|0x2
block|,
name|T3_MEM_ACCESS_REM_READ
init|=
literal|0x4
block|,
name|T3_MEM_ACCESS_REM_WRITE
init|=
literal|0x8
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
enum|;
end_enum

begin_struct
struct|struct
name|t3_bind_mw_wr
block|{
name|struct
name|fw_riwrh
name|wrh
decl_stmt|;
comment|/* 0 */
name|union
name|t3_wrid
name|wrid
decl_stmt|;
comment|/* 1 */
name|u16
name|reserved
decl_stmt|;
comment|/* 2 */
name|u8
name|type
decl_stmt|;
name|u8
name|perms
decl_stmt|;
name|__be32
name|mr_stag
decl_stmt|;
name|__be32
name|mw_stag
decl_stmt|;
comment|/* 3 */
name|__be32
name|mw_len
decl_stmt|;
name|__be64
name|mw_va
decl_stmt|;
comment|/* 4 */
name|__be32
name|mr_pbl_addr
decl_stmt|;
comment|/* 5 */
name|u8
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
name|u8
name|mr_pagesz
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_receive_wr
block|{
name|struct
name|fw_riwrh
name|wrh
decl_stmt|;
comment|/* 0 */
name|union
name|t3_wrid
name|wrid
decl_stmt|;
comment|/* 1 */
name|u8
name|pagesz
index|[
name|T3_MAX_SGE
index|]
decl_stmt|;
name|__be32
name|num_sgle
decl_stmt|;
comment|/* 2 */
name|struct
name|t3_sge
name|sgl
index|[
name|T3_MAX_SGE
index|]
decl_stmt|;
comment|/* 3+ */
name|__be32
name|pbl_addr
index|[
name|T3_MAX_SGE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_bypass_wr
block|{
name|struct
name|fw_riwrh
name|wrh
decl_stmt|;
name|union
name|t3_wrid
name|wrid
decl_stmt|;
comment|/* 1 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_modify_qp_wr
block|{
name|struct
name|fw_riwrh
name|wrh
decl_stmt|;
comment|/* 0 */
name|union
name|t3_wrid
name|wrid
decl_stmt|;
comment|/* 1 */
name|__be32
name|flags
decl_stmt|;
comment|/* 2 */
name|__be32
name|quiesce
decl_stmt|;
comment|/* 2 */
name|__be32
name|max_ird
decl_stmt|;
comment|/* 3 */
name|__be32
name|max_ord
decl_stmt|;
comment|/* 3 */
name|__be64
name|sge_cmd
decl_stmt|;
comment|/* 4 */
name|__be64
name|ctx1
decl_stmt|;
comment|/* 5 */
name|__be64
name|ctx0
decl_stmt|;
comment|/* 6 */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|t3_modify_qp_flags
block|{
name|MODQP_QUIESCE
init|=
literal|0x01
block|,
name|MODQP_MAX_IRD
init|=
literal|0x02
block|,
name|MODQP_MAX_ORD
init|=
literal|0x04
block|,
name|MODQP_WRITE_EC
init|=
literal|0x08
block|,
name|MODQP_READ_EC
init|=
literal|0x10
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|t3_mpa_attrs
block|{
name|uP_RI_MPA_RX_MARKER_ENABLE
init|=
literal|0x1
block|,
name|uP_RI_MPA_TX_MARKER_ENABLE
init|=
literal|0x2
block|,
name|uP_RI_MPA_CRC_ENABLE
init|=
literal|0x4
block|,
name|uP_RI_MPA_IETF_ENABLE
init|=
literal|0x8
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
enum|;
end_enum

begin_enum
enum|enum
name|t3_qp_caps
block|{
name|uP_RI_QP_RDMA_READ_ENABLE
init|=
literal|0x01
block|,
name|uP_RI_QP_RDMA_WRITE_ENABLE
init|=
literal|0x02
block|,
name|uP_RI_QP_BIND_ENABLE
init|=
literal|0x04
block|,
name|uP_RI_QP_FAST_REGISTER_ENABLE
init|=
literal|0x08
block|,
name|uP_RI_QP_STAG0_ENABLE
init|=
literal|0x10
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
enum|;
end_enum

begin_enum
enum|enum
name|rdma_init_rtr_types
block|{
name|RTR_READ
init|=
literal|1
block|,
name|RTR_WRITE
init|=
literal|2
block|,
name|RTR_SEND
init|=
literal|3
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|S_RTR_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|M_RTR_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_RTR_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RTR_TYPE)
end_define

begin_define
define|#
directive|define
name|G_RTR_TYPE
parameter_list|(
name|x
parameter_list|)
value|((((x)>> S_RTR_TYPE))& M_RTR_TYPE)
end_define

begin_define
define|#
directive|define
name|S_CHAN
value|4
end_define

begin_define
define|#
directive|define
name|M_CHAN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_CHAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CHAN)
end_define

begin_define
define|#
directive|define
name|G_CHAN
parameter_list|(
name|x
parameter_list|)
value|((((x)>> S_CHAN))& M_CHAN)
end_define

begin_struct
struct|struct
name|t3_rdma_init_attr
block|{
name|u32
name|tid
decl_stmt|;
name|u32
name|qpid
decl_stmt|;
name|u32
name|pdid
decl_stmt|;
name|u32
name|scqid
decl_stmt|;
name|u32
name|rcqid
decl_stmt|;
name|u32
name|rq_addr
decl_stmt|;
name|u32
name|rq_size
decl_stmt|;
name|enum
name|t3_mpa_attrs
name|mpaattrs
decl_stmt|;
name|enum
name|t3_qp_caps
name|qpcaps
decl_stmt|;
name|u16
name|tcp_emss
decl_stmt|;
name|u32
name|ord
decl_stmt|;
name|u32
name|ird
decl_stmt|;
name|u64
name|qp_dma_addr
decl_stmt|;
name|u32
name|qp_dma_size
decl_stmt|;
name|enum
name|rdma_init_rtr_types
name|rtr_type
decl_stmt|;
name|u16
name|flags
decl_stmt|;
name|u16
name|rqe_count
decl_stmt|;
name|u32
name|irs
decl_stmt|;
name|u32
name|chan
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_rdma_init_wr
block|{
name|struct
name|fw_riwrh
name|wrh
decl_stmt|;
comment|/* 0 */
name|union
name|t3_wrid
name|wrid
decl_stmt|;
comment|/* 1 */
name|__be32
name|qpid
decl_stmt|;
comment|/* 2 */
name|__be32
name|pdid
decl_stmt|;
name|__be32
name|scqid
decl_stmt|;
comment|/* 3 */
name|__be32
name|rcqid
decl_stmt|;
name|__be32
name|rq_addr
decl_stmt|;
comment|/* 4 */
name|__be32
name|rq_size
decl_stmt|;
name|u8
name|mpaattrs
decl_stmt|;
comment|/* 5 */
name|u8
name|qpcaps
decl_stmt|;
name|__be16
name|ulpdu_size
decl_stmt|;
name|__be16
name|flags_rtr_type
decl_stmt|;
name|__be16
name|rqe_count
decl_stmt|;
name|__be32
name|ord
decl_stmt|;
comment|/* 6 */
name|__be32
name|ird
decl_stmt|;
name|__be64
name|qp_dma_addr
decl_stmt|;
comment|/* 7 */
name|__be32
name|qp_dma_size
decl_stmt|;
comment|/* 8 */
name|__be32
name|irs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_genbit
block|{
name|u64
name|flit
index|[
literal|15
index|]
decl_stmt|;
name|__be64
name|genbit
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|rdma_init_wr_flags
block|{
name|MPA_INITIATOR
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|PRIV_QP
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|, }
enum|;
end_enum

begin_union
union|union
name|t3_wr
block|{
name|struct
name|t3_send_wr
name|send
decl_stmt|;
name|struct
name|t3_rdma_write_wr
name|write
decl_stmt|;
name|struct
name|t3_rdma_read_wr
name|read
decl_stmt|;
name|struct
name|t3_receive_wr
name|recv
decl_stmt|;
name|struct
name|t3_local_inv_wr
name|local_inv
decl_stmt|;
name|struct
name|t3_bind_mw_wr
name|bind
decl_stmt|;
name|struct
name|t3_bypass_wr
name|bypass
decl_stmt|;
name|struct
name|t3_rdma_init_wr
name|init
decl_stmt|;
name|struct
name|t3_modify_qp_wr
name|qp_mod
decl_stmt|;
name|struct
name|t3_genbit
name|genbit
decl_stmt|;
name|u64
name|flit
index|[
literal|16
index|]
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|T3_SQ_CQE_FLIT
value|13
end_define

begin_define
define|#
directive|define
name|T3_SQ_COOKIE_FLIT
value|14
end_define

begin_define
define|#
directive|define
name|T3_RQ_COOKIE_FLIT
value|13
end_define

begin_define
define|#
directive|define
name|T3_RQ_CQE_FLIT
value|14
end_define

begin_function
specifier|static
specifier|inline
name|enum
name|t3_wr_opcode
name|fw_riwrh_opcode
parameter_list|(
name|struct
name|fw_riwrh
modifier|*
name|wqe
parameter_list|)
block|{
return|return
name|G_FW_RIWR_OP
argument_list|(
name|be32toh
argument_list|(
name|wqe
operator|->
name|op_seop_flags
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|build_fw_riwrh
parameter_list|(
name|struct
name|fw_riwrh
modifier|*
name|wqe
parameter_list|,
name|enum
name|t3_wr_opcode
name|op
parameter_list|,
name|enum
name|t3_wr_flags
name|flags
parameter_list|,
name|u8
name|genbit
parameter_list|,
name|u32
name|tid
parameter_list|,
name|u8
name|len
parameter_list|)
block|{
name|wqe
operator|->
name|op_seop_flags
operator|=
name|htobe32
argument_list|(
name|V_FW_RIWR_OP
argument_list|(
name|op
argument_list|)
operator||
name|V_FW_RIWR_SOPEOP
argument_list|(
name|M_FW_RIWR_SOPEOP
argument_list|)
operator||
name|V_FW_RIWR_FLAGS
argument_list|(
name|flags
argument_list|)
argument_list|)
expr_stmt|;
name|wmb
argument_list|()
expr_stmt|;
name|wqe
operator|->
name|gen_tid_len
operator|=
name|htobe32
argument_list|(
name|V_FW_RIWR_GEN
argument_list|(
name|genbit
argument_list|)
operator||
name|V_FW_RIWR_TID
argument_list|(
name|tid
argument_list|)
operator||
name|V_FW_RIWR_LEN
argument_list|(
name|len
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 2nd gen bit... */
operator|(
operator|(
expr|union
name|t3_wr
operator|*
operator|)
name|wqe
operator|)
operator|->
name|genbit
operator|.
name|genbit
operator|=
name|htobe64
argument_list|(
name|genbit
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * T3 ULP2_TX commands  */
end_comment

begin_enum
enum|enum
name|t3_utx_mem_op
block|{
name|T3_UTX_MEM_READ
init|=
literal|2
block|,
name|T3_UTX_MEM_WRITE
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* T3 MC7 RDMA TPT entry format */
end_comment

begin_enum
enum|enum
name|tpt_mem_type
block|{
name|TPT_NON_SHARED_MR
init|=
literal|0x0
block|,
name|TPT_SHARED_MR
init|=
literal|0x1
block|,
name|TPT_MW
init|=
literal|0x2
block|,
name|TPT_MW_RELAXED_PROTECTION
init|=
literal|0x3
block|}
enum|;
end_enum

begin_enum
enum|enum
name|tpt_addr_type
block|{
name|TPT_ZBTO
init|=
literal|0
block|,
name|TPT_VATO
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|tpt_mem_perm
block|{
name|TPT_LOCAL_READ
init|=
literal|0x8
block|,
name|TPT_LOCAL_WRITE
init|=
literal|0x4
block|,
name|TPT_REMOTE_READ
init|=
literal|0x2
block|,
name|TPT_REMOTE_WRITE
init|=
literal|0x1
block|}
enum|;
end_enum

begin_struct
struct|struct
name|tpt_entry
block|{
name|__be32
name|valid_stag_pdid
decl_stmt|;
name|__be32
name|flags_pagesize_qpid
decl_stmt|;
name|__be32
name|rsvd_pbl_addr
decl_stmt|;
name|__be32
name|len
decl_stmt|;
name|__be32
name|va_hi
decl_stmt|;
name|__be32
name|va_low_or_fbo
decl_stmt|;
name|__be32
name|rsvd_bind_cnt_or_pstag
decl_stmt|;
name|__be32
name|rsvd_pbl_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_TPT_VALID
value|31
end_define

begin_define
define|#
directive|define
name|V_TPT_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_VALID)
end_define

begin_define
define|#
directive|define
name|F_TPT_VALID
value|V_TPT_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_TPT_STAG_KEY
value|23
end_define

begin_define
define|#
directive|define
name|M_TPT_STAG_KEY
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_TPT_STAG_KEY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_STAG_KEY)
end_define

begin_define
define|#
directive|define
name|G_TPT_STAG_KEY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TPT_STAG_KEY)& M_TPT_STAG_KEY)
end_define

begin_define
define|#
directive|define
name|S_TPT_STAG_STATE
value|22
end_define

begin_define
define|#
directive|define
name|V_TPT_STAG_STATE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_STAG_STATE)
end_define

begin_define
define|#
directive|define
name|F_TPT_STAG_STATE
value|V_TPT_STAG_STATE(1U)
end_define

begin_define
define|#
directive|define
name|S_TPT_STAG_TYPE
value|20
end_define

begin_define
define|#
directive|define
name|M_TPT_STAG_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_TPT_STAG_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_STAG_TYPE)
end_define

begin_define
define|#
directive|define
name|G_TPT_STAG_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TPT_STAG_TYPE)& M_TPT_STAG_TYPE)
end_define

begin_define
define|#
directive|define
name|S_TPT_PDID
value|0
end_define

begin_define
define|#
directive|define
name|M_TPT_PDID
value|0xFFFFF
end_define

begin_define
define|#
directive|define
name|V_TPT_PDID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_PDID)
end_define

begin_define
define|#
directive|define
name|G_TPT_PDID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TPT_PDID)& M_TPT_PDID)
end_define

begin_define
define|#
directive|define
name|S_TPT_PERM
value|28
end_define

begin_define
define|#
directive|define
name|M_TPT_PERM
value|0xF
end_define

begin_define
define|#
directive|define
name|V_TPT_PERM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_PERM)
end_define

begin_define
define|#
directive|define
name|G_TPT_PERM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TPT_PERM)& M_TPT_PERM)
end_define

begin_define
define|#
directive|define
name|S_TPT_REM_INV_DIS
value|27
end_define

begin_define
define|#
directive|define
name|V_TPT_REM_INV_DIS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_REM_INV_DIS)
end_define

begin_define
define|#
directive|define
name|F_TPT_REM_INV_DIS
value|V_TPT_REM_INV_DIS(1U)
end_define

begin_define
define|#
directive|define
name|S_TPT_ADDR_TYPE
value|26
end_define

begin_define
define|#
directive|define
name|V_TPT_ADDR_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_ADDR_TYPE)
end_define

begin_define
define|#
directive|define
name|F_TPT_ADDR_TYPE
value|V_TPT_ADDR_TYPE(1U)
end_define

begin_define
define|#
directive|define
name|S_TPT_MW_BIND_ENABLE
value|25
end_define

begin_define
define|#
directive|define
name|V_TPT_MW_BIND_ENABLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_MW_BIND_ENABLE)
end_define

begin_define
define|#
directive|define
name|F_TPT_MW_BIND_ENABLE
value|V_TPT_MW_BIND_ENABLE(1U)
end_define

begin_define
define|#
directive|define
name|S_TPT_PAGE_SIZE
value|20
end_define

begin_define
define|#
directive|define
name|M_TPT_PAGE_SIZE
value|0x1F
end_define

begin_define
define|#
directive|define
name|V_TPT_PAGE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|G_TPT_PAGE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TPT_PAGE_SIZE)& M_TPT_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|S_TPT_PBL_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|M_TPT_PBL_ADDR
value|0x1FFFFFFF
end_define

begin_define
define|#
directive|define
name|V_TPT_PBL_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_PBL_ADDR)
end_define

begin_define
define|#
directive|define
name|G_TPT_PBL_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TPT_PBL_ADDR)& M_TPT_PBL_ADDR)
end_define

begin_define
define|#
directive|define
name|S_TPT_QPID
value|0
end_define

begin_define
define|#
directive|define
name|M_TPT_QPID
value|0xFFFFF
end_define

begin_define
define|#
directive|define
name|V_TPT_QPID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_QPID)
end_define

begin_define
define|#
directive|define
name|G_TPT_QPID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TPT_QPID)& M_TPT_QPID)
end_define

begin_define
define|#
directive|define
name|S_TPT_PSTAG
value|0
end_define

begin_define
define|#
directive|define
name|M_TPT_PSTAG
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|V_TPT_PSTAG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_PSTAG)
end_define

begin_define
define|#
directive|define
name|G_TPT_PSTAG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TPT_PSTAG)& M_TPT_PSTAG)
end_define

begin_define
define|#
directive|define
name|S_TPT_PBL_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_TPT_PBL_SIZE
value|0xFFFFF
end_define

begin_define
define|#
directive|define
name|V_TPT_PBL_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TPT_PBL_SIZE)
end_define

begin_define
define|#
directive|define
name|G_TPT_PBL_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TPT_PBL_SIZE)& M_TPT_PBL_SIZE)
end_define

begin_comment
comment|/*  * CQE defs  */
end_comment

begin_struct
struct|struct
name|t3_cqe
block|{
name|__be32
name|header
decl_stmt|;
name|__be32
name|len
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|__be32
name|stag
decl_stmt|;
name|__be32
name|msn
decl_stmt|;
block|}
name|rcqe
struct|;
struct|struct
block|{
name|u32
name|wrid_hi
decl_stmt|;
name|u32
name|wrid_low
decl_stmt|;
block|}
name|scqe
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_CQE_OOO
value|31
end_define

begin_define
define|#
directive|define
name|M_CQE_OOO
value|0x1
end_define

begin_define
define|#
directive|define
name|G_CQE_OOO
parameter_list|(
name|x
parameter_list|)
value|((((x)>> S_CQE_OOO))& M_CQE_OOO)
end_define

begin_define
define|#
directive|define
name|V_CEQ_OOO
parameter_list|(
name|x
parameter_list|)
value|((x)<<S_CQE_OOO)
end_define

begin_define
define|#
directive|define
name|S_CQE_QPID
value|12
end_define

begin_define
define|#
directive|define
name|M_CQE_QPID
value|0x7FFFF
end_define

begin_define
define|#
directive|define
name|G_CQE_QPID
parameter_list|(
name|x
parameter_list|)
value|((((x)>> S_CQE_QPID))& M_CQE_QPID)
end_define

begin_define
define|#
directive|define
name|V_CQE_QPID
parameter_list|(
name|x
parameter_list|)
value|((x)<<S_CQE_QPID)
end_define

begin_define
define|#
directive|define
name|S_CQE_SWCQE
value|11
end_define

begin_define
define|#
directive|define
name|M_CQE_SWCQE
value|0x1
end_define

begin_define
define|#
directive|define
name|G_CQE_SWCQE
parameter_list|(
name|x
parameter_list|)
value|((((x)>> S_CQE_SWCQE))& M_CQE_SWCQE)
end_define

begin_define
define|#
directive|define
name|V_CQE_SWCQE
parameter_list|(
name|x
parameter_list|)
value|((x)<<S_CQE_SWCQE)
end_define

begin_define
define|#
directive|define
name|S_CQE_GENBIT
value|10
end_define

begin_define
define|#
directive|define
name|M_CQE_GENBIT
value|0x1
end_define

begin_define
define|#
directive|define
name|G_CQE_GENBIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_CQE_GENBIT)& M_CQE_GENBIT)
end_define

begin_define
define|#
directive|define
name|V_CQE_GENBIT
parameter_list|(
name|x
parameter_list|)
value|((x)<<S_CQE_GENBIT)
end_define

begin_define
define|#
directive|define
name|S_CQE_STATUS
value|5
end_define

begin_define
define|#
directive|define
name|M_CQE_STATUS
value|0x1F
end_define

begin_define
define|#
directive|define
name|G_CQE_STATUS
parameter_list|(
name|x
parameter_list|)
value|((((x)>> S_CQE_STATUS))& M_CQE_STATUS)
end_define

begin_define
define|#
directive|define
name|V_CQE_STATUS
parameter_list|(
name|x
parameter_list|)
value|((x)<<S_CQE_STATUS)
end_define

begin_define
define|#
directive|define
name|S_CQE_TYPE
value|4
end_define

begin_define
define|#
directive|define
name|M_CQE_TYPE
value|0x1
end_define

begin_define
define|#
directive|define
name|G_CQE_TYPE
parameter_list|(
name|x
parameter_list|)
value|((((x)>> S_CQE_TYPE))& M_CQE_TYPE)
end_define

begin_define
define|#
directive|define
name|V_CQE_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<<S_CQE_TYPE)
end_define

begin_define
define|#
directive|define
name|S_CQE_OPCODE
value|0
end_define

begin_define
define|#
directive|define
name|M_CQE_OPCODE
value|0xF
end_define

begin_define
define|#
directive|define
name|G_CQE_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((((x)>> S_CQE_OPCODE))& M_CQE_OPCODE)
end_define

begin_define
define|#
directive|define
name|V_CQE_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<<S_CQE_OPCODE)
end_define

begin_define
define|#
directive|define
name|SW_CQE
parameter_list|(
name|x
parameter_list|)
value|(G_CQE_SWCQE(be32toh((x).header)))
end_define

begin_define
define|#
directive|define
name|CQE_OOO
parameter_list|(
name|x
parameter_list|)
value|(G_CQE_OOO(be32toh((x).header)))
end_define

begin_define
define|#
directive|define
name|CQE_QPID
parameter_list|(
name|x
parameter_list|)
value|(G_CQE_QPID(be32toh((x).header)))
end_define

begin_define
define|#
directive|define
name|CQE_GENBIT
parameter_list|(
name|x
parameter_list|)
value|(G_CQE_GENBIT(be32toh((x).header)))
end_define

begin_define
define|#
directive|define
name|CQE_TYPE
parameter_list|(
name|x
parameter_list|)
value|(G_CQE_TYPE(be32toh((x).header)))
end_define

begin_define
define|#
directive|define
name|SQ_TYPE
parameter_list|(
name|x
parameter_list|)
value|(CQE_TYPE((x)))
end_define

begin_define
define|#
directive|define
name|RQ_TYPE
parameter_list|(
name|x
parameter_list|)
value|(!CQE_TYPE((x)))
end_define

begin_define
define|#
directive|define
name|CQE_STATUS
parameter_list|(
name|x
parameter_list|)
value|(G_CQE_STATUS(be32toh((x).header)))
end_define

begin_define
define|#
directive|define
name|CQE_OPCODE
parameter_list|(
name|x
parameter_list|)
value|(G_CQE_OPCODE(be32toh((x).header)))
end_define

begin_define
define|#
directive|define
name|CQE_SEND_OPCODE
parameter_list|(
name|x
parameter_list|)
value|( \ 	(G_CQE_OPCODE(be32_to_cpu((x).header)) == T3_SEND) || \ 	(G_CQE_OPCODE(be32_to_cpu((x).header)) == T3_SEND_WITH_SE) || \ 	(G_CQE_OPCODE(be32_to_cpu((x).header)) == T3_SEND_WITH_INV) || \ 	(G_CQE_OPCODE(be32_to_cpu((x).header)) == T3_SEND_WITH_SE_INV))
end_define

begin_define
define|#
directive|define
name|CQE_LEN
parameter_list|(
name|x
parameter_list|)
value|(be32toh((x).len))
end_define

begin_comment
comment|/* used for RQ completion processing */
end_comment

begin_define
define|#
directive|define
name|CQE_WRID_STAG
parameter_list|(
name|x
parameter_list|)
value|(be32toh((x).u.rcqe.stag))
end_define

begin_define
define|#
directive|define
name|CQE_WRID_MSN
parameter_list|(
name|x
parameter_list|)
value|(be32toh((x).u.rcqe.msn))
end_define

begin_comment
comment|/* used for SQ completion processing */
end_comment

begin_define
define|#
directive|define
name|CQE_WRID_SQ_WPTR
parameter_list|(
name|x
parameter_list|)
value|((x).u.scqe.wrid_hi)
end_define

begin_define
define|#
directive|define
name|CQE_WRID_WPTR
parameter_list|(
name|x
parameter_list|)
value|((x).u.scqe.wrid_low)
end_define

begin_comment
comment|/* generic accessor macros */
end_comment

begin_define
define|#
directive|define
name|CQE_WRID_HI
parameter_list|(
name|x
parameter_list|)
value|((x).u.scqe.wrid_hi)
end_define

begin_define
define|#
directive|define
name|CQE_WRID_LOW
parameter_list|(
name|x
parameter_list|)
value|((x).u.scqe.wrid_low)
end_define

begin_define
define|#
directive|define
name|TPT_ERR_SUCCESS
value|0x0
end_define

begin_define
define|#
directive|define
name|TPT_ERR_STAG
value|0x1
end_define

begin_comment
comment|/* STAG invalid: either the */
end_comment

begin_comment
comment|/* STAG is offlimt, being 0, */
end_comment

begin_comment
comment|/* or STAG_key mismatch */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_PDID
value|0x2
end_define

begin_comment
comment|/* PDID mismatch */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_QPID
value|0x3
end_define

begin_comment
comment|/* QPID mismatch */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_ACCESS
value|0x4
end_define

begin_comment
comment|/* Invalid access right */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_WRAP
value|0x5
end_define

begin_comment
comment|/* Wrap error */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_BOUND
value|0x6
end_define

begin_comment
comment|/* base and bounds voilation */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_INVALIDATE_SHARED_MR
value|0x7
end_define

begin_comment
comment|/* attempt to invalidate a  */
end_comment

begin_comment
comment|/* shared memory region */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_INVALIDATE_MR_WITH_MW_BOUND
value|0x8
end_define

begin_comment
comment|/* attempt to invalidate a  */
end_comment

begin_comment
comment|/* shared memory region */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_ECC
value|0x9
end_define

begin_comment
comment|/* ECC error detected */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_ECC_PSTAG
value|0xA
end_define

begin_comment
comment|/* ECC error detected when  */
end_comment

begin_comment
comment|/* reading PSTAG for a MW  */
end_comment

begin_comment
comment|/* Invalidate */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_PBL_ADDR_BOUND
value|0xB
end_define

begin_comment
comment|/* pbl addr out of bounds:  */
end_comment

begin_comment
comment|/* software error */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_SWFLUSH
value|0xC
end_define

begin_comment
comment|/* SW FLUSHED */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_CRC
value|0x10
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_MARKER
value|0x11
end_define

begin_comment
comment|/* Marker error */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_PDU_LEN_ERR
value|0x12
end_define

begin_comment
comment|/* invalid PDU length */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_OUT_OF_RQE
value|0x13
end_define

begin_comment
comment|/* out of RQE */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_DDP_VERSION
value|0x14
end_define

begin_comment
comment|/* wrong DDP version */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_RDMA_VERSION
value|0x15
end_define

begin_comment
comment|/* wrong RDMA version */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_OPCODE
value|0x16
end_define

begin_comment
comment|/* invalid rdma opcode */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_DDP_QUEUE_NUM
value|0x17
end_define

begin_comment
comment|/* invalid ddp queue number */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_MSN
value|0x18
end_define

begin_comment
comment|/* MSN error */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_TBIT
value|0x19
end_define

begin_comment
comment|/* tag bit not set correctly */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_MO
value|0x1A
end_define

begin_comment
comment|/* MO not 0 for TERMINATE  */
end_comment

begin_comment
comment|/* or READ_REQ */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_MSN_GAP
value|0x1B
end_define

begin_define
define|#
directive|define
name|TPT_ERR_MSN_RANGE
value|0x1C
end_define

begin_define
define|#
directive|define
name|TPT_ERR_IRD_OVERFLOW
value|0x1D
end_define

begin_define
define|#
directive|define
name|TPT_ERR_RQE_ADDR_BOUND
value|0x1E
end_define

begin_comment
comment|/* RQE addr out of bounds:  */
end_comment

begin_comment
comment|/* software error */
end_comment

begin_define
define|#
directive|define
name|TPT_ERR_INTERNAL_ERR
value|0x1F
end_define

begin_comment
comment|/* internal error (opcode  */
end_comment

begin_comment
comment|/* mismatch) */
end_comment

begin_struct
struct|struct
name|t3_swsq
block|{
name|uint64_t
name|wr_id
decl_stmt|;
name|struct
name|t3_cqe
name|cqe
decl_stmt|;
name|uint32_t
name|sq_wptr
decl_stmt|;
name|__be32
name|read_len
decl_stmt|;
name|int
name|opcode
decl_stmt|;
name|int
name|complete
decl_stmt|;
name|int
name|signaled
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_swrq
block|{
name|__u64
name|wr_id
decl_stmt|;
name|__u32
name|pbl_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A T3 WQ implements both the SQ and RQ.  */
end_comment

begin_struct
struct|struct
name|t3_wq
block|{
name|union
name|t3_wr
modifier|*
name|queue
decl_stmt|;
comment|/* DMA accessable memory */
name|bus_addr_t
name|dma_addr
decl_stmt|;
comment|/* DMA address for HW */
name|u32
name|error
decl_stmt|;
comment|/* 1 once we go to ERROR */
name|u32
name|qpid
decl_stmt|;
name|u32
name|wptr
decl_stmt|;
comment|/* idx to next available WR slot */
name|u32
name|size_log2
decl_stmt|;
comment|/* total wq size */
name|struct
name|t3_swsq
modifier|*
name|sq
decl_stmt|;
comment|/* SW SQ */
name|struct
name|t3_swsq
modifier|*
name|oldest_read
decl_stmt|;
comment|/* tracks oldest pending read */
name|u32
name|sq_wptr
decl_stmt|;
comment|/* sq_wptr - sq_rptr == count of */
name|u32
name|sq_rptr
decl_stmt|;
comment|/* pending wrs */
name|u32
name|sq_size_log2
decl_stmt|;
comment|/* sq size */
name|struct
name|t3_swrq
modifier|*
name|rq
decl_stmt|;
comment|/* SW RQ (holds consumer wr_ids */
name|u32
name|rq_wptr
decl_stmt|;
comment|/* rq_wptr - rq_rptr == count of */
name|u32
name|rq_rptr
decl_stmt|;
comment|/* pending wrs */
name|struct
name|t3_swrq
modifier|*
name|rq_oldest_wr
decl_stmt|;
comment|/* oldest wr on the SW RQ */
name|u32
name|rq_size_log2
decl_stmt|;
comment|/* rq size */
name|u32
name|rq_addr
decl_stmt|;
comment|/* rq adapter address */
name|void
modifier|*
name|doorbell
decl_stmt|;
comment|/* kernel db */
name|u64
name|udb
decl_stmt|;
comment|/* user db if any */
name|struct
name|cxio_rdev
modifier|*
name|rdev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3_cq
block|{
name|u32
name|cqid
decl_stmt|;
name|u32
name|rptr
decl_stmt|;
name|u32
name|wptr
decl_stmt|;
name|u32
name|size_log2
decl_stmt|;
name|bus_addr_t
name|dma_addr
decl_stmt|;
name|struct
name|t3_cqe
modifier|*
name|queue
decl_stmt|;
name|struct
name|t3_cqe
modifier|*
name|sw_queue
decl_stmt|;
name|u32
name|sw_rptr
decl_stmt|;
name|u32
name|sw_wptr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CQ_VLD_ENTRY
parameter_list|(
name|ptr
parameter_list|,
name|size_log2
parameter_list|,
name|cqe
parameter_list|)
value|(Q_GENBIT(ptr,size_log2) == \ 					 CQE_GENBIT(*cqe))
end_define

begin_struct
struct|struct
name|t3_cq_status_page
block|{
name|u32
name|cq_err
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|int
name|cxio_cq_in_error
parameter_list|(
name|struct
name|t3_cq
modifier|*
name|cq
parameter_list|)
block|{
return|return
operator|(
operator|(
expr|struct
name|t3_cq_status_page
operator|*
operator|)
operator|&
name|cq
operator|->
name|queue
index|[
literal|1
operator|<<
name|cq
operator|->
name|size_log2
index|]
operator|)
operator|->
name|cq_err
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|cxio_set_cq_in_error
parameter_list|(
name|struct
name|t3_cq
modifier|*
name|cq
parameter_list|)
block|{
operator|(
operator|(
expr|struct
name|t3_cq_status_page
operator|*
operator|)
operator|&
name|cq
operator|->
name|queue
index|[
literal|1
operator|<<
name|cq
operator|->
name|size_log2
index|]
operator|)
operator|->
name|cq_err
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|cxio_set_wq_in_error
parameter_list|(
name|struct
name|t3_wq
modifier|*
name|wq
parameter_list|)
block|{
name|wq
operator|->
name|queue
operator|->
name|flit
index|[
literal|13
index|]
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|t3_cqe
modifier|*
name|cxio_next_hw_cqe
parameter_list|(
name|struct
name|t3_cq
modifier|*
name|cq
parameter_list|)
block|{
name|struct
name|t3_cqe
modifier|*
name|cqe
decl_stmt|;
name|cqe
operator|=
name|cq
operator|->
name|queue
operator|+
operator|(
name|Q_PTR2IDX
argument_list|(
name|cq
operator|->
name|rptr
argument_list|,
name|cq
operator|->
name|size_log2
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|CQ_VLD_ENTRY
argument_list|(
name|cq
operator|->
name|rptr
argument_list|,
name|cq
operator|->
name|size_log2
argument_list|,
name|cqe
argument_list|)
condition|)
return|return
name|cqe
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|t3_cqe
modifier|*
name|cxio_next_sw_cqe
parameter_list|(
name|struct
name|t3_cq
modifier|*
name|cq
parameter_list|)
block|{
name|struct
name|t3_cqe
modifier|*
name|cqe
decl_stmt|;
if|if
condition|(
operator|!
name|Q_EMPTY
argument_list|(
name|cq
operator|->
name|sw_rptr
argument_list|,
name|cq
operator|->
name|sw_wptr
argument_list|)
condition|)
block|{
name|cqe
operator|=
name|cq
operator|->
name|sw_queue
operator|+
operator|(
name|Q_PTR2IDX
argument_list|(
name|cq
operator|->
name|sw_rptr
argument_list|,
name|cq
operator|->
name|size_log2
argument_list|)
operator|)
expr_stmt|;
return|return
name|cqe
return|;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|t3_cqe
modifier|*
name|cxio_next_cqe
parameter_list|(
name|struct
name|t3_cq
modifier|*
name|cq
parameter_list|)
block|{
name|struct
name|t3_cqe
modifier|*
name|cqe
decl_stmt|;
if|if
condition|(
operator|!
name|Q_EMPTY
argument_list|(
name|cq
operator|->
name|sw_rptr
argument_list|,
name|cq
operator|->
name|sw_wptr
argument_list|)
condition|)
block|{
name|cqe
operator|=
name|cq
operator|->
name|sw_queue
operator|+
operator|(
name|Q_PTR2IDX
argument_list|(
name|cq
operator|->
name|sw_rptr
argument_list|,
name|cq
operator|->
name|size_log2
argument_list|)
operator|)
expr_stmt|;
return|return
name|cqe
return|;
block|}
name|cqe
operator|=
name|cq
operator|->
name|queue
operator|+
operator|(
name|Q_PTR2IDX
argument_list|(
name|cq
operator|->
name|rptr
argument_list|,
name|cq
operator|->
name|size_log2
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|CQ_VLD_ENTRY
argument_list|(
name|cq
operator|->
name|rptr
argument_list|,
name|cq
operator|->
name|size_log2
argument_list|,
name|cqe
argument_list|)
condition|)
return|return
name|cqe
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit


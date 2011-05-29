begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Chelsio Communications, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_HW_H
end_ifndef

begin_define
define|#
directive|define
name|__T4_HW_H
end_define

begin_include
include|#
directive|include
file|"osdep.h"
end_include

begin_enum
enum|enum
block|{
name|NCHAN
init|=
literal|4
block|,
comment|/* # of HW channels */
name|MAX_MTU
init|=
literal|9600
block|,
comment|/* max MAC MTU, excluding header + FCS */
name|EEPROMSIZE
init|=
literal|17408
block|,
comment|/* Serial EEPROM physical size */
name|EEPROMVSIZE
init|=
literal|32768
block|,
comment|/* Serial EEPROM virtual address space size */
name|EEPROMPFSIZE
init|=
literal|1024
block|,
comment|/* EEPROM writable area size for PFn, n>0 */
name|RSS_NENTRIES
init|=
literal|2048
block|,
comment|/* # of entries in RSS mapping table */
name|TCB_SIZE
init|=
literal|128
block|,
comment|/* TCB size */
name|NMTUS
init|=
literal|16
block|,
comment|/* size of MTU table */
name|NCCTRL_WIN
init|=
literal|32
block|,
comment|/* # of congestion control windows */
name|NTX_SCHED
init|=
literal|8
block|,
comment|/* # of HW Tx scheduling queues */
name|PM_NSTATS
init|=
literal|5
block|,
comment|/* # of PM stats */
name|MBOX_LEN
init|=
literal|64
block|,
comment|/* mailbox size in bytes */
name|TRACE_LEN
init|=
literal|112
block|,
comment|/* length of trace data and mask */
name|FILTER_OPT_LEN
init|=
literal|36
block|,
comment|/* filter tuple width for optional components */
name|NWOL_PAT
init|=
literal|8
block|,
comment|/* # of WoL patterns */
name|WOL_PAT_LEN
init|=
literal|128
block|,
comment|/* length of WoL patterns */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|CIM_NUM_IBQ
init|=
literal|6
block|,
comment|/* # of CIM IBQs */
name|CIM_NUM_OBQ
init|=
literal|6
block|,
comment|/* # of CIM OBQs */
name|CIMLA_SIZE
init|=
literal|2048
block|,
comment|/* # of 32-bit words in CIM LA */
name|CIM_PIFLA_SIZE
init|=
literal|64
block|,
comment|/* # of 192-bit words in CIM PIF LA */
name|CIM_MALA_SIZE
init|=
literal|64
block|,
comment|/* # of 160-bit words in CIM MA LA */
name|CIM_IBQ_SIZE
init|=
literal|128
block|,
comment|/* # of 128-bit words in a CIM IBQ */
name|TPLA_SIZE
init|=
literal|128
block|,
comment|/* # of 64-bit words in TP LA */
name|ULPRX_LA_SIZE
init|=
literal|512
block|,
comment|/* # of 256-bit words in ULP_RX LA */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|SF_PAGE_SIZE
init|=
literal|256
block|,
comment|/* serial flash page size */
name|SF_SEC_SIZE
init|=
literal|64
operator|*
literal|1024
block|,
comment|/* serial flash sector size */
block|}
enum|;
end_enum

begin_comment
comment|/* SGE context types */
end_comment

begin_enum
enum|enum
name|ctxt_type
block|{
name|CTXT_EGRESS
block|,
name|CTXT_INGRESS
block|,
name|CTXT_FLM
block|,
name|CTXT_CNM
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|RSP_TYPE_FLBUF
block|,
name|RSP_TYPE_CPL
block|,
name|RSP_TYPE_INTR
block|}
enum|;
end_enum

begin_comment
comment|/* response entry types */
end_comment

begin_enum
enum|enum
block|{
name|MBOX_OWNER_NONE
block|,
name|MBOX_OWNER_FW
block|,
name|MBOX_OWNER_DRV
block|}
enum|;
end_enum

begin_comment
comment|/* mailbox owners */
end_comment

begin_enum
enum|enum
block|{
name|SGE_MAX_WR_LEN
init|=
literal|512
block|,
comment|/* max WR size in bytes */
name|SGE_CTXT_SIZE
init|=
literal|24
block|,
comment|/* size of SGE context */
name|SGE_NTIMERS
init|=
literal|6
block|,
comment|/* # of interrupt holdoff timer values */
name|SGE_NCOUNTERS
init|=
literal|4
block|,
comment|/* # of interrupt packet counter values */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|sge_qstat
block|{
comment|/* data written to SGE queue status entries */
specifier|volatile
name|__be32
name|qid
decl_stmt|;
specifier|volatile
name|__be16
name|cidx
decl_stmt|;
specifier|volatile
name|__be16
name|pidx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_QSTAT_PIDX
value|0
end_define

begin_define
define|#
directive|define
name|M_QSTAT_PIDX
value|0xffff
end_define

begin_define
define|#
directive|define
name|G_QSTAT_PIDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_QSTAT_PIDX)& M_QSTAT_PIDX)
end_define

begin_define
define|#
directive|define
name|S_QSTAT_CIDX
value|16
end_define

begin_define
define|#
directive|define
name|M_QSTAT_CIDX
value|0xffff
end_define

begin_define
define|#
directive|define
name|G_QSTAT_CIDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_QSTAT_CIDX)& M_QSTAT_CIDX)
end_define

begin_comment
comment|/*  * Structure for last 128 bits of response descriptors  */
end_comment

begin_struct
struct|struct
name|rsp_ctrl
block|{
name|__be32
name|hdrbuflen_pidx
decl_stmt|;
name|__be32
name|pldbuflen_qid
decl_stmt|;
union|union
block|{
name|u8
name|type_gen
decl_stmt|;
name|__be64
name|last_flit
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_RSPD_NEWBUF
value|31
end_define

begin_define
define|#
directive|define
name|V_RSPD_NEWBUF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RSPD_NEWBUF)
end_define

begin_define
define|#
directive|define
name|F_RSPD_NEWBUF
value|V_RSPD_NEWBUF(1U)
end_define

begin_define
define|#
directive|define
name|S_RSPD_LEN
value|0
end_define

begin_define
define|#
directive|define
name|M_RSPD_LEN
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|V_RSPD_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RSPD_LEN)
end_define

begin_define
define|#
directive|define
name|G_RSPD_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RSPD_LEN)& M_RSPD_LEN)
end_define

begin_define
define|#
directive|define
name|S_RSPD_QID
value|S_RSPD_LEN
end_define

begin_define
define|#
directive|define
name|M_RSPD_QID
value|M_RSPD_LEN
end_define

begin_define
define|#
directive|define
name|V_RSPD_QID
parameter_list|(
name|x
parameter_list|)
value|V_RSPD_LEN(x)
end_define

begin_define
define|#
directive|define
name|G_RSPD_QID
parameter_list|(
name|x
parameter_list|)
value|G_RSPD_LEN(x)
end_define

begin_define
define|#
directive|define
name|S_RSPD_GEN
value|7
end_define

begin_define
define|#
directive|define
name|V_RSPD_GEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RSPD_GEN)
end_define

begin_define
define|#
directive|define
name|F_RSPD_GEN
value|V_RSPD_GEN(1U)
end_define

begin_define
define|#
directive|define
name|S_RSPD_QOVFL
value|6
end_define

begin_define
define|#
directive|define
name|V_RSPD_QOVFL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RSPD_QOVFL)
end_define

begin_define
define|#
directive|define
name|F_RSPD_QOVFL
value|V_RSPD_QOVFL(1U)
end_define

begin_define
define|#
directive|define
name|S_RSPD_TYPE
value|4
end_define

begin_define
define|#
directive|define
name|M_RSPD_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_RSPD_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RSPD_TYPE)
end_define

begin_define
define|#
directive|define
name|G_RSPD_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RSPD_TYPE)& M_RSPD_TYPE)
end_define

begin_comment
comment|/* Rx queue interrupt deferral fields: counter enable and timer index */
end_comment

begin_define
define|#
directive|define
name|S_QINTR_CNT_EN
value|0
end_define

begin_define
define|#
directive|define
name|V_QINTR_CNT_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_QINTR_CNT_EN)
end_define

begin_define
define|#
directive|define
name|F_QINTR_CNT_EN
value|V_QINTR_CNT_EN(1U)
end_define

begin_define
define|#
directive|define
name|S_QINTR_TIMER_IDX
value|1
end_define

begin_define
define|#
directive|define
name|M_QINTR_TIMER_IDX
value|0x7
end_define

begin_define
define|#
directive|define
name|V_QINTR_TIMER_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_QINTR_TIMER_IDX)
end_define

begin_define
define|#
directive|define
name|G_QINTR_TIMER_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_QINTR_TIMER_IDX)& M_QINTR_TIMER_IDX)
end_define

begin_comment
comment|/* # of pages a pagepod can hold without needing another pagepod */
end_comment

begin_define
define|#
directive|define
name|PPOD_PAGES
value|4U
end_define

begin_struct
struct|struct
name|pagepod
block|{
name|__be64
name|vld_tid_pgsz_tag_color
decl_stmt|;
name|__be64
name|len_offset
decl_stmt|;
name|__be64
name|rsvd
decl_stmt|;
name|__be64
name|addr
index|[
name|PPOD_PAGES
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_PPOD_COLOR
value|0
end_define

begin_define
define|#
directive|define
name|M_PPOD_COLOR
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_PPOD_COLOR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PPOD_COLOR)
end_define

begin_define
define|#
directive|define
name|S_PPOD_TAG
value|6
end_define

begin_define
define|#
directive|define
name|M_PPOD_TAG
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|V_PPOD_TAG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PPOD_TAG)
end_define

begin_define
define|#
directive|define
name|S_PPOD_PGSZ
value|30
end_define

begin_define
define|#
directive|define
name|M_PPOD_PGSZ
value|0x3
end_define

begin_define
define|#
directive|define
name|V_PPOD_PGSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PPOD_PGSZ)
end_define

begin_define
define|#
directive|define
name|S_PPOD_TID
value|32
end_define

begin_define
define|#
directive|define
name|M_PPOD_TID
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|V_PPOD_TID
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_PPOD_TID)
end_define

begin_define
define|#
directive|define
name|S_PPOD_VALID
value|56
end_define

begin_define
define|#
directive|define
name|V_PPOD_VALID
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_PPOD_VALID)
end_define

begin_define
define|#
directive|define
name|F_PPOD_VALID
value|V_PPOD_VALID(1ULL)
end_define

begin_define
define|#
directive|define
name|S_PPOD_LEN
value|32
end_define

begin_define
define|#
directive|define
name|M_PPOD_LEN
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|V_PPOD_LEN
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_PPOD_LEN)
end_define

begin_define
define|#
directive|define
name|S_PPOD_OFST
value|0
end_define

begin_define
define|#
directive|define
name|M_PPOD_OFST
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|V_PPOD_OFST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PPOD_OFST)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __T4_HW_H */
end_comment

end_unit


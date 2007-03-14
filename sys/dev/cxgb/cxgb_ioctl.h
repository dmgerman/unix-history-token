begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.   3. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CHIOCTL_H__
end_ifndef

begin_define
define|#
directive|define
name|__CHIOCTL_H__
end_define

begin_comment
comment|/*  * Ioctl commands specific to this driver.  */
end_comment

begin_enum
enum|enum
block|{
name|CH_SETREG
init|=
literal|0x40
block|,
name|CH_GETREG
block|,
name|CH_SETTPI
block|,
name|CH_GETTPI
block|,
name|CH_DEVUP
block|,
name|CH_GETMTUTAB
block|,
name|CH_SETMTUTAB
block|,
name|CH_GETMTU
block|,
name|CH_SET_PM
block|,
name|CH_GET_PM
block|,
name|CH_GET_TCAM
block|,
name|CH_SET_TCAM
block|,
name|CH_GET_TCB
block|,
name|CH_READ_TCAM_WORD
block|,
name|CH_GET_MEM
block|,
name|CH_GET_SGE_CONTEXT
block|,
name|CH_GET_SGE_DESC
block|,
name|CH_LOAD_FW
block|,
name|CH_GET_PROTO
block|,
name|CH_SET_PROTO
block|,
name|CH_SET_TRACE_FILTER
block|,
name|CH_SET_QSET_PARAMS
block|,
name|CH_GET_QSET_PARAMS
block|,
name|CH_SET_QSET_NUM
block|,
name|CH_GET_QSET_NUM
block|,
name|CH_SET_PKTSCHED
block|,
name|CH_IFCONF_GETREGS
block|,
name|CH_GETMIIREGS
block|,
name|CH_SETMIIREGS
block|, 	 }
enum|;
end_enum

begin_struct
struct|struct
name|ch_reg
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ch_cntxt
block|{
name|uint32_t
name|cntxt_type
decl_stmt|;
name|uint32_t
name|cntxt_id
decl_stmt|;
name|uint32_t
name|data
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* context types */
end_comment

begin_enum
enum|enum
block|{
name|CNTXT_TYPE_EGRESS
block|,
name|CNTXT_TYPE_FL
block|,
name|CNTXT_TYPE_RSP
block|,
name|CNTXT_TYPE_CQ
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ch_desc
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|queue_num
decl_stmt|;
name|uint32_t
name|idx
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|uint8_t
name|data
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ch_mem_range
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|mem_id
decl_stmt|;
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
name|uint8_t
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ch_qset_params
block|{
name|uint32_t
name|qset_idx
decl_stmt|;
name|int32_t
name|txq_size
index|[
literal|3
index|]
decl_stmt|;
name|int32_t
name|rspq_size
decl_stmt|;
name|int32_t
name|fl_size
index|[
literal|2
index|]
decl_stmt|;
name|int32_t
name|intr_lat
decl_stmt|;
name|int32_t
name|polling
decl_stmt|;
name|int32_t
name|cong_thres
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ch_pktsched_params
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint8_t
name|sched
decl_stmt|;
name|uint8_t
name|idx
decl_stmt|;
name|uint8_t
name|min
decl_stmt|;
name|uint8_t
name|max
decl_stmt|;
name|uint8_t
name|binding
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|TCB_SIZE
end_ifndef

begin_define
define|#
directive|define
name|TCB_SIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCB size in 32-bit words */
end_comment

begin_define
define|#
directive|define
name|TCB_WORDS
value|(TCB_SIZE / 4)
end_define

begin_enum
enum|enum
block|{
name|MEM_CM
block|,
name|MEM_PMRX
block|,
name|MEM_PMTX
block|}
enum|;
end_enum

begin_comment
comment|/* ch_mem_range.mem_id values */
end_comment

begin_struct
struct|struct
name|ch_mtus
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|nmtus
decl_stmt|;
name|uint16_t
name|mtus
index|[
name|NMTUS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ch_pm
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|tx_pg_sz
decl_stmt|;
name|uint32_t
name|tx_num_pg
decl_stmt|;
name|uint32_t
name|rx_pg_sz
decl_stmt|;
name|uint32_t
name|rx_num_pg
decl_stmt|;
name|uint32_t
name|pm_total
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ch_tcam
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|tcam_size
decl_stmt|;
name|uint32_t
name|nservers
decl_stmt|;
name|uint32_t
name|nroutes
decl_stmt|;
name|uint32_t
name|nfilters
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ch_tcb
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|tcb_index
decl_stmt|;
name|uint32_t
name|tcb_data
index|[
name|TCB_WORDS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ch_tcam_word
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|buf
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ch_trace
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|sip
decl_stmt|;
name|uint32_t
name|sip_mask
decl_stmt|;
name|uint32_t
name|dip
decl_stmt|;
name|uint32_t
name|dip_mask
decl_stmt|;
name|uint16_t
name|sport
decl_stmt|;
name|uint16_t
name|sport_mask
decl_stmt|;
name|uint16_t
name|dport
decl_stmt|;
name|uint16_t
name|dport_mask
decl_stmt|;
name|uint32_t
name|vlan
range|:
literal|12
decl_stmt|,
name|vlan_mask
range|:
literal|12
decl_stmt|,
name|intf
range|:
literal|4
decl_stmt|,
name|intf_mask
range|:
literal|4
decl_stmt|;
name|uint8_t
name|proto
decl_stmt|;
name|uint8_t
name|proto_mask
decl_stmt|;
name|uint8_t
name|invert_match
range|:
literal|1
decl_stmt|,
name|config_tx
range|:
literal|1
decl_stmt|,
name|config_rx
range|:
literal|1
decl_stmt|,
name|trace_tx
range|:
literal|1
decl_stmt|,
name|trace_rx
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|REGDUMP_SIZE
value|(4 * 1024)
end_define

begin_struct
struct|struct
name|ifconf_regs
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
comment|/* bytes */
name|uint8_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mii_data
block|{
name|uint32_t
name|phy_id
decl_stmt|;
name|uint32_t
name|reg_num
decl_stmt|;
name|uint32_t
name|val_in
decl_stmt|;
name|uint32_t
name|val_out
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CHELSIO_SETREG
value|_IOW('f', CH_SETREG, struct ch_reg)
end_define

begin_define
define|#
directive|define
name|CHELSIO_GETREG
value|_IOWR('f', CH_GETREG, struct ch_reg)
end_define

begin_define
define|#
directive|define
name|CHELSIO_GET_MEM
value|_IOWR('f', CH_GET_MEM, struct ch_mem_range)
end_define

begin_define
define|#
directive|define
name|CHELSIO_GET_SGE_CONTEXT
value|_IOWR('f', CH_GET_SGE_CONTEXT, struct ch_cntxt)
end_define

begin_define
define|#
directive|define
name|CHELSIO_GET_SGE_DESC
value|_IOWR('f', CH_GET_SGE_DESC, struct ch_desc)
end_define

begin_define
define|#
directive|define
name|CHELSIO_GET_QSET_PARAMS
value|_IOWR('f', CH_GET_QSET_PARAMS, struct ch_qset_params)
end_define

begin_define
define|#
directive|define
name|CHELSIO_SET_QSET_PARAMS
value|_IOW('f', CH_SET_QSET_PARAMS, struct ch_qset_params)
end_define

begin_define
define|#
directive|define
name|CHELSIO_GET_QSET_NUM
value|_IOWR('f', CH_GET_QSET_NUM, struct ch_reg)
end_define

begin_define
define|#
directive|define
name|CHELSIO_SET_QSET_NUM
value|_IOW('f', CH_SET_QSET_NUM, struct ch_reg)
end_define

begin_define
define|#
directive|define
name|CHELSIO_SET_TRACE_FILTER
value|_IOW('f', CH_SET_TRACE_FILTER, struct ch_trace)
end_define

begin_define
define|#
directive|define
name|CHELSIO_SET_PKTSCHED
value|_IOW('f', CH_SET_PKTSCHED, struct ch_pktsched_params)
end_define

begin_define
define|#
directive|define
name|CHELSIO_IFCONF_GETREGS
value|_IOWR('f', CH_IFCONF_GETREGS, struct ifconf_regs)
end_define

begin_define
define|#
directive|define
name|SIOCGMIIREG
value|_IOWR('f', CH_GETMIIREGS, struct mii_data)
end_define

begin_define
define|#
directive|define
name|SIOCSMIIREG
value|_IOWR('f', CH_SETMIIREGS, struct mii_data)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit


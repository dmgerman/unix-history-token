begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is part of the Chelsio T4 Ethernet driver for Linux.  *  * Copyright (c) 2009-2014 Chelsio Communications, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_T4FW_INTERFACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_T4FW_INTERFACE_H_
end_define

begin_include
include|#
directive|include
file|<infiniband/types.h>
end_include

begin_enum
enum|enum
name|fw_retval
block|{
name|FW_SUCCESS
init|=
literal|0
block|,
comment|/* completed successfully */
name|FW_EPERM
init|=
literal|1
block|,
comment|/* operation not permitted */
name|FW_ENOENT
init|=
literal|2
block|,
comment|/* no such file or directory */
name|FW_EIO
init|=
literal|5
block|,
comment|/* input/output error; hw bad */
name|FW_ENOEXEC
init|=
literal|8
block|,
comment|/* exec format error; inv microcode */
name|FW_EAGAIN
init|=
literal|11
block|,
comment|/* try again */
name|FW_ENOMEM
init|=
literal|12
block|,
comment|/* out of memory */
name|FW_EFAULT
init|=
literal|14
block|,
comment|/* bad address; fw bad */
name|FW_EBUSY
init|=
literal|16
block|,
comment|/* resource busy */
name|FW_EEXIST
init|=
literal|17
block|,
comment|/* file exists */
name|FW_ENODEV
init|=
literal|19
block|,
comment|/* no such device */
name|FW_EINVAL
init|=
literal|22
block|,
comment|/* invalid argument */
name|FW_ENOSPC
init|=
literal|28
block|,
comment|/* no space left on device */
name|FW_ENOSYS
init|=
literal|38
block|,
comment|/* functionality not implemented */
name|FW_ENODATA
init|=
literal|61
block|,
comment|/* no data available */
name|FW_EPROTO
init|=
literal|71
block|,
comment|/* protocol error */
name|FW_EADDRINUSE
init|=
literal|98
block|,
comment|/* address already in use */
name|FW_EADDRNOTAVAIL
init|=
literal|99
block|,
comment|/* cannot assigned requested address */
name|FW_ENETDOWN
init|=
literal|100
block|,
comment|/* network is down */
name|FW_ENETUNREACH
init|=
literal|101
block|,
comment|/* network is unreachable */
name|FW_ENOBUFS
init|=
literal|105
block|,
comment|/* no buffer space available */
name|FW_ETIMEDOUT
init|=
literal|110
block|,
comment|/* timeout */
name|FW_EINPROGRESS
init|=
literal|115
block|,
comment|/* fw internal */
name|FW_SCSI_ABORT_REQUESTED
init|=
literal|128
block|,
comment|/* */
name|FW_SCSI_ABORT_TIMEDOUT
init|=
literal|129
block|,
comment|/* */
name|FW_SCSI_ABORTED
init|=
literal|130
block|,
comment|/* */
name|FW_SCSI_CLOSE_REQUESTED
init|=
literal|131
block|,
comment|/* */
name|FW_ERR_LINK_DOWN
init|=
literal|132
block|,
comment|/* */
name|FW_RDEV_NOT_READY
init|=
literal|133
block|,
comment|/* */
name|FW_ERR_RDEV_LOST
init|=
literal|134
block|,
comment|/* */
name|FW_ERR_RDEV_LOGO
init|=
literal|135
block|,
comment|/* */
name|FW_FCOE_NO_XCHG
init|=
literal|136
block|,
comment|/* */
name|FW_SCSI_RSP_ERR
init|=
literal|137
block|,
comment|/* */
name|FW_ERR_RDEV_IMPL_LOGO
init|=
literal|138
block|,
comment|/* */
name|FW_SCSI_UNDER_FLOW_ERR
init|=
literal|139
block|,
comment|/* */
name|FW_SCSI_OVER_FLOW_ERR
init|=
literal|140
block|,
comment|/* */
name|FW_SCSI_DDP_ERR
init|=
literal|141
block|,
comment|/* DDP error*/
name|FW_SCSI_TASK_ERR
init|=
literal|142
block|,
comment|/* No SCSI tasks available */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|FW_T4VF_SGE_BASE_ADDR
value|0x0000
end_define

begin_define
define|#
directive|define
name|FW_T4VF_MPS_BASE_ADDR
value|0x0100
end_define

begin_define
define|#
directive|define
name|FW_T4VF_PL_BASE_ADDR
value|0x0200
end_define

begin_define
define|#
directive|define
name|FW_T4VF_MBDATA_BASE_ADDR
value|0x0240
end_define

begin_define
define|#
directive|define
name|FW_T4VF_CIM_BASE_ADDR
value|0x0300
end_define

begin_enum
enum|enum
name|fw_wr_opcodes
block|{
name|FW_FILTER_WR
init|=
literal|0x02
block|,
name|FW_ULPTX_WR
init|=
literal|0x04
block|,
name|FW_TP_WR
init|=
literal|0x05
block|,
name|FW_ETH_TX_PKT_WR
init|=
literal|0x08
block|,
name|FW_OFLD_CONNECTION_WR
init|=
literal|0x2f
block|,
name|FW_FLOWC_WR
init|=
literal|0x0a
block|,
name|FW_OFLD_TX_DATA_WR
init|=
literal|0x0b
block|,
name|FW_CMD_WR
init|=
literal|0x10
block|,
name|FW_ETH_TX_PKT_VM_WR
init|=
literal|0x11
block|,
name|FW_RI_RES_WR
init|=
literal|0x0c
block|,
name|FW_RI_INIT_WR
init|=
literal|0x0d
block|,
name|FW_RI_RDMA_WRITE_WR
init|=
literal|0x14
block|,
name|FW_RI_SEND_WR
init|=
literal|0x15
block|,
name|FW_RI_RDMA_READ_WR
init|=
literal|0x16
block|,
name|FW_RI_RECV_WR
init|=
literal|0x17
block|,
name|FW_RI_BIND_MW_WR
init|=
literal|0x18
block|,
name|FW_RI_FR_NSMR_WR
init|=
literal|0x19
block|,
name|FW_RI_INV_LSTAG_WR
init|=
literal|0x1a
block|,
name|FW_ISCSI_TX_DATA_WR
init|=
literal|0x45
block|,
name|FW_LASTC2E_WR
init|=
literal|0x70
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fw_wr_hdr
block|{
name|__be32
name|hi
decl_stmt|;
name|__be32
name|lo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* work request opcode (hi) */
end_comment

begin_define
define|#
directive|define
name|FW_WR_OP_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_WR_OP_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_WR_OP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_WR_OP_S)
end_define

begin_define
define|#
directive|define
name|FW_WR_OP_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_WR_OP_S)& FW_WR_OP_M)
end_define

begin_comment
comment|/* atomic flag (hi) - firmware encapsulates CPLs in CPL_BARRIER */
end_comment

begin_define
define|#
directive|define
name|FW_WR_ATOMIC_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_WR_ATOMIC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_WR_ATOMIC_S)
end_define

begin_comment
comment|/* flush flag (hi) - firmware flushes flushable work request buffered  * in the flow context.  */
end_comment

begin_define
define|#
directive|define
name|FW_WR_FLUSH_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_WR_FLUSH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_WR_FLUSH_S)
end_define

begin_comment
comment|/* completion flag (hi) - firmware generates a cpl_fw6_ack */
end_comment

begin_define
define|#
directive|define
name|FW_WR_COMPL_S
value|21
end_define

begin_define
define|#
directive|define
name|FW_WR_COMPL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_WR_COMPL_S)
end_define

begin_define
define|#
directive|define
name|FW_WR_COMPL_F
value|FW_WR_COMPL_V(1U)
end_define

begin_comment
comment|/* work request immediate data length (hi) */
end_comment

begin_define
define|#
directive|define
name|FW_WR_IMMDLEN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_WR_IMMDLEN_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_WR_IMMDLEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_WR_IMMDLEN_S)
end_define

begin_comment
comment|/* egress queue status update to associated ingress queue entry (lo) */
end_comment

begin_define
define|#
directive|define
name|FW_WR_EQUIQ_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_WR_EQUIQ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_WR_EQUIQ_S)
end_define

begin_define
define|#
directive|define
name|FW_WR_EQUIQ_F
value|FW_WR_EQUIQ_V(1U)
end_define

begin_comment
comment|/* egress queue status update to egress queue status entry (lo) */
end_comment

begin_define
define|#
directive|define
name|FW_WR_EQUEQ_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_WR_EQUEQ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_WR_EQUEQ_S)
end_define

begin_define
define|#
directive|define
name|FW_WR_EQUEQ_F
value|FW_WR_EQUEQ_V(1U)
end_define

begin_comment
comment|/* flow context identifier (lo) */
end_comment

begin_define
define|#
directive|define
name|FW_WR_FLOWID_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_WR_FLOWID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_WR_FLOWID_S)
end_define

begin_comment
comment|/* length in units of 16-bytes (lo) */
end_comment

begin_define
define|#
directive|define
name|FW_WR_LEN16_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_WR_LEN16_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_WR_LEN16_S)
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_PR_IV_P_FC
value|0X32B
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_PR_OV_P_FC
value|0X327
end_define

begin_comment
comment|/* filter wr reply code in cookie in CPL_SET_TCB_RPL */
end_comment

begin_enum
enum|enum
name|fw_filter_wr_cookie
block|{
name|FW_FILTER_WR_SUCCESS
block|,
name|FW_FILTER_WR_FLT_ADDED
block|,
name|FW_FILTER_WR_FLT_DELETED
block|,
name|FW_FILTER_WR_SMT_TBL_FULL
block|,
name|FW_FILTER_WR_EINVAL
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_filter_wr
block|{
name|__be32
name|op_pkd
decl_stmt|;
name|__be32
name|len16_pkd
decl_stmt|;
name|__be64
name|r3
decl_stmt|;
name|__be32
name|tid_to_iq
decl_stmt|;
name|__be32
name|del_filter_to_l2tix
decl_stmt|;
name|__be16
name|ethtype
decl_stmt|;
name|__be16
name|ethtypem
decl_stmt|;
name|__u8
name|frag_to_ovlan_vldm
decl_stmt|;
name|__u8
name|smac_sel
decl_stmt|;
name|__be16
name|rx_chan_rx_rpl_iq
decl_stmt|;
name|__be32
name|maci_to_matchtypem
decl_stmt|;
name|__u8
name|ptcl
decl_stmt|;
name|__u8
name|ptclm
decl_stmt|;
name|__u8
name|ttyp
decl_stmt|;
name|__u8
name|ttypm
decl_stmt|;
name|__be16
name|ivlan
decl_stmt|;
name|__be16
name|ivlanm
decl_stmt|;
name|__be16
name|ovlan
decl_stmt|;
name|__be16
name|ovlanm
decl_stmt|;
name|__u8
name|lip
index|[
literal|16
index|]
decl_stmt|;
name|__u8
name|lipm
index|[
literal|16
index|]
decl_stmt|;
name|__u8
name|fip
index|[
literal|16
index|]
decl_stmt|;
name|__u8
name|fipm
index|[
literal|16
index|]
decl_stmt|;
name|__be16
name|lp
decl_stmt|;
name|__be16
name|lpm
decl_stmt|;
name|__be16
name|fp
decl_stmt|;
name|__be16
name|fpm
decl_stmt|;
name|__be16
name|r7
decl_stmt|;
name|__u8
name|sma
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_FILTER_WR_TID_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_TID_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_TID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_TID_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_TID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_TID_S)& FW_FILTER_WR_TID_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RQTYPE_S
value|11
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RQTYPE_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RQTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_RQTYPE_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RQTYPE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_RQTYPE_S)& FW_FILTER_WR_RQTYPE_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RQTYPE_F
value|FW_FILTER_WR_RQTYPE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_NOREPLY_S
value|10
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_NOREPLY_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_NOREPLY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_NOREPLY_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_NOREPLY_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_NOREPLY_S)& FW_FILTER_WR_NOREPLY_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_NOREPLY_F
value|FW_FILTER_WR_NOREPLY_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IQ_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IQ_M
value|0x3ff
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IQ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_IQ_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IQ_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_IQ_S)& FW_FILTER_WR_IQ_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DEL_FILTER_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DEL_FILTER_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DEL_FILTER_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_DEL_FILTER_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DEL_FILTER_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_DEL_FILTER_S)& FW_FILTER_WR_DEL_FILTER_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DEL_FILTER_F
value|FW_FILTER_WR_DEL_FILTER_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RPTTID_S
value|25
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RPTTID_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RPTTID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_RPTTID_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RPTTID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_RPTTID_S)& FW_FILTER_WR_RPTTID_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RPTTID_F
value|FW_FILTER_WR_RPTTID_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DROP_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DROP_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DROP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_DROP_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DROP_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_DROP_S)& FW_FILTER_WR_DROP_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DROP_F
value|FW_FILTER_WR_DROP_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DIRSTEER_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DIRSTEER_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DIRSTEER_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_DIRSTEER_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DIRSTEER_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_DIRSTEER_S)& FW_FILTER_WR_DIRSTEER_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DIRSTEER_F
value|FW_FILTER_WR_DIRSTEER_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MASKHASH_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MASKHASH_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MASKHASH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_MASKHASH_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MASKHASH_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_MASKHASH_S)& FW_FILTER_WR_MASKHASH_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MASKHASH_F
value|FW_FILTER_WR_MASKHASH_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DIRSTEERHASH_S
value|21
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DIRSTEERHASH_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DIRSTEERHASH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_DIRSTEERHASH_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DIRSTEERHASH_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_DIRSTEERHASH_S)& FW_FILTER_WR_DIRSTEERHASH_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DIRSTEERHASH_F
value|FW_FILTER_WR_DIRSTEERHASH_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_LPBK_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_LPBK_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_LPBK_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_LPBK_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_LPBK_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_LPBK_S)& FW_FILTER_WR_LPBK_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_LPBK_F
value|FW_FILTER_WR_LPBK_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DMAC_S
value|19
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DMAC_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DMAC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_DMAC_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DMAC_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_DMAC_S)& FW_FILTER_WR_DMAC_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_DMAC_F
value|FW_FILTER_WR_DMAC_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_SMAC_S
value|18
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_SMAC_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_SMAC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_SMAC_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_SMAC_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_SMAC_S)& FW_FILTER_WR_SMAC_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_SMAC_F
value|FW_FILTER_WR_SMAC_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_INSVLAN_S
value|17
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_INSVLAN_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_INSVLAN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_INSVLAN_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_INSVLAN_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_INSVLAN_S)& FW_FILTER_WR_INSVLAN_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_INSVLAN_F
value|FW_FILTER_WR_INSVLAN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RMVLAN_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RMVLAN_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RMVLAN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_RMVLAN_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RMVLAN_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_RMVLAN_S)& FW_FILTER_WR_RMVLAN_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RMVLAN_F
value|FW_FILTER_WR_RMVLAN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_HITCNTS_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_HITCNTS_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_HITCNTS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_HITCNTS_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_HITCNTS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_HITCNTS_S)& FW_FILTER_WR_HITCNTS_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_HITCNTS_F
value|FW_FILTER_WR_HITCNTS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_TXCHAN_S
value|13
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_TXCHAN_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_TXCHAN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_TXCHAN_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_TXCHAN_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_TXCHAN_S)& FW_FILTER_WR_TXCHAN_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PRIO_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PRIO_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_PRIO_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PRIO_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_PRIO_S)& FW_FILTER_WR_PRIO_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PRIO_F
value|FW_FILTER_WR_PRIO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_L2TIX_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_L2TIX_M
value|0xfff
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_L2TIX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_L2TIX_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_L2TIX_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_L2TIX_S)& FW_FILTER_WR_L2TIX_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FRAG_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FRAG_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FRAG_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_FRAG_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FRAG_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_FRAG_S)& FW_FILTER_WR_FRAG_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FRAG_F
value|FW_FILTER_WR_FRAG_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FRAGM_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FRAGM_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FRAGM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_FRAGM_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FRAGM_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_FRAGM_S)& FW_FILTER_WR_FRAGM_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FRAGM_F
value|FW_FILTER_WR_FRAGM_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IVLAN_VLD_S
value|5
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IVLAN_VLD_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IVLAN_VLD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_IVLAN_VLD_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IVLAN_VLD_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_IVLAN_VLD_S)& FW_FILTER_WR_IVLAN_VLD_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IVLAN_VLD_F
value|FW_FILTER_WR_IVLAN_VLD_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_OVLAN_VLD_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_OVLAN_VLD_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_OVLAN_VLD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_OVLAN_VLD_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_OVLAN_VLD_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_OVLAN_VLD_S)& FW_FILTER_WR_OVLAN_VLD_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_OVLAN_VLD_F
value|FW_FILTER_WR_OVLAN_VLD_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IVLAN_VLDM_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IVLAN_VLDM_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IVLAN_VLDM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_IVLAN_VLDM_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IVLAN_VLDM_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_IVLAN_VLDM_S)& FW_FILTER_WR_IVLAN_VLDM_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_IVLAN_VLDM_F
value|FW_FILTER_WR_IVLAN_VLDM_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_OVLAN_VLDM_S
value|2
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_OVLAN_VLDM_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_OVLAN_VLDM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_OVLAN_VLDM_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_OVLAN_VLDM_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_OVLAN_VLDM_S)& FW_FILTER_WR_OVLAN_VLDM_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_OVLAN_VLDM_F
value|FW_FILTER_WR_OVLAN_VLDM_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RX_CHAN_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RX_CHAN_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RX_CHAN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_RX_CHAN_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RX_CHAN_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_RX_CHAN_S)& FW_FILTER_WR_RX_CHAN_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RX_CHAN_F
value|FW_FILTER_WR_RX_CHAN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RX_RPL_IQ_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RX_RPL_IQ_M
value|0x3ff
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RX_RPL_IQ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_RX_RPL_IQ_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_RX_RPL_IQ_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_RX_RPL_IQ_S)& FW_FILTER_WR_RX_RPL_IQ_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MACI_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MACI_M
value|0x1ff
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MACI_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_MACI_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MACI_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_MACI_S)& FW_FILTER_WR_MACI_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MACIM_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MACIM_M
value|0x1ff
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MACIM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_MACIM_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MACIM_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_MACIM_S)& FW_FILTER_WR_MACIM_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FCOE_S
value|13
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FCOE_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FCOE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_FCOE_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FCOE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_FCOE_S)& FW_FILTER_WR_FCOE_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FCOE_F
value|FW_FILTER_WR_FCOE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FCOEM_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FCOEM_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FCOEM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_FCOEM_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FCOEM_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_FCOEM_S)& FW_FILTER_WR_FCOEM_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_FCOEM_F
value|FW_FILTER_WR_FCOEM_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PORT_S
value|9
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PORT_M
value|0x7
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PORT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_PORT_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PORT_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_PORT_S)& FW_FILTER_WR_PORT_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PORTM_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PORTM_M
value|0x7
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PORTM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_PORTM_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_PORTM_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_PORTM_S)& FW_FILTER_WR_PORTM_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MATCHTYPE_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MATCHTYPE_M
value|0x7
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MATCHTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_MATCHTYPE_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MATCHTYPE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_MATCHTYPE_S)& FW_FILTER_WR_MATCHTYPE_M)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MATCHTYPEM_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MATCHTYPEM_M
value|0x7
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MATCHTYPEM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FILTER_WR_MATCHTYPEM_S)
end_define

begin_define
define|#
directive|define
name|FW_FILTER_WR_MATCHTYPEM_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_FILTER_WR_MATCHTYPEM_S)& FW_FILTER_WR_MATCHTYPEM_M)
end_define

begin_struct
struct|struct
name|fw_ulptx_wr
block|{
name|__be32
name|op_to_compl
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|u64
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_tp_wr
block|{
name|__be32
name|op_to_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|u64
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_eth_tx_pkt_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|equiq_to_len16
decl_stmt|;
name|__be64
name|r3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ofld_connection_wr
block|{
name|__be32
name|op_compl
decl_stmt|;
name|__be32
name|len16_pkd
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
name|__be64
name|r2
decl_stmt|;
name|__be64
name|r3
decl_stmt|;
struct|struct
name|fw_ofld_connection_le
block|{
name|__be32
name|version_cpl
decl_stmt|;
name|__be32
name|filter
decl_stmt|;
name|__be32
name|r1
decl_stmt|;
name|__be16
name|lport
decl_stmt|;
name|__be16
name|pport
decl_stmt|;
union|union
name|fw_ofld_connection_leip
block|{
struct|struct
name|fw_ofld_connection_le_ipv4
block|{
name|__be32
name|pip
decl_stmt|;
name|__be32
name|lip
decl_stmt|;
name|__be64
name|r0
decl_stmt|;
name|__be64
name|r1
decl_stmt|;
name|__be64
name|r2
decl_stmt|;
block|}
name|ipv4
struct|;
struct|struct
name|fw_ofld_connection_le_ipv6
block|{
name|__be64
name|pip_hi
decl_stmt|;
name|__be64
name|pip_lo
decl_stmt|;
name|__be64
name|lip_hi
decl_stmt|;
name|__be64
name|lip_lo
decl_stmt|;
block|}
name|ipv6
struct|;
block|}
name|u
union|;
block|}
name|le
struct|;
struct|struct
name|fw_ofld_connection_tcb
block|{
name|__be32
name|t_state_to_astid
decl_stmt|;
name|__be16
name|cplrxdataack_cplpassacceptrpl
decl_stmt|;
name|__be16
name|rcv_adv
decl_stmt|;
name|__be32
name|rcv_nxt
decl_stmt|;
name|__be32
name|tx_max
decl_stmt|;
name|__be64
name|opt0
decl_stmt|;
name|__be32
name|opt2
decl_stmt|;
name|__be32
name|r1
decl_stmt|;
name|__be64
name|r2
decl_stmt|;
name|__be64
name|r3
decl_stmt|;
block|}
name|tcb
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_VERSION_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_VERSION_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_VERSION_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_OFLD_CONNECTION_WR_VERSION_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_VERSION_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_OFLD_CONNECTION_WR_VERSION_S)& \ 	FW_OFLD_CONNECTION_WR_VERSION_M)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_VERSION_F
define|\
value|FW_OFLD_CONNECTION_WR_VERSION_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPL_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPL_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_OFLD_CONNECTION_WR_CPL_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPL_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_OFLD_CONNECTION_WR_CPL_S)& FW_OFLD_CONNECTION_WR_CPL_M)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPL_F
value|FW_OFLD_CONNECTION_WR_CPL_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_T_STATE_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_T_STATE_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_T_STATE_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_OFLD_CONNECTION_WR_T_STATE_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_T_STATE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_OFLD_CONNECTION_WR_T_STATE_S)& \ 	FW_OFLD_CONNECTION_WR_T_STATE_M)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_RCV_SCALE_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_RCV_SCALE_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_RCV_SCALE_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_OFLD_CONNECTION_WR_RCV_SCALE_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_RCV_SCALE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_OFLD_CONNECTION_WR_RCV_SCALE_S)& \ 	FW_OFLD_CONNECTION_WR_RCV_SCALE_M)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_ASTID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_ASTID_M
value|0xffffff
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_ASTID_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_OFLD_CONNECTION_WR_ASTID_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_ASTID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_OFLD_CONNECTION_WR_ASTID_S)& FW_OFLD_CONNECTION_WR_ASTID_M)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPLRXDATAACK_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPLRXDATAACK_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPLRXDATAACK_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_OFLD_CONNECTION_WR_CPLRXDATAACK_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPLRXDATAACK_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_OFLD_CONNECTION_WR_CPLRXDATAACK_S)& \ 	FW_OFLD_CONNECTION_WR_CPLRXDATAACK_M)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPLRXDATAACK_F
define|\
value|FW_OFLD_CONNECTION_WR_CPLRXDATAACK_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL_S)& \ 	FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL_M)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL_F
define|\
value|FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL_V(1U)
end_define

begin_enum
enum|enum
name|fw_flowc_mnem
block|{
name|FW_FLOWC_MNEM_PFNVFN
block|,
comment|/* PFN [15:8] VFN [7:0] */
name|FW_FLOWC_MNEM_CH
block|,
name|FW_FLOWC_MNEM_PORT
block|,
name|FW_FLOWC_MNEM_IQID
block|,
name|FW_FLOWC_MNEM_SNDNXT
block|,
name|FW_FLOWC_MNEM_RCVNXT
block|,
name|FW_FLOWC_MNEM_SNDBUF
block|,
name|FW_FLOWC_MNEM_MSS
block|,
name|FW_FLOWC_MNEM_TXDATAPLEN_MAX
block|,
name|FW_FLOWC_MNEM_TCPSTATE
block|,
name|FW_FLOWC_MNEM_EOSTATE
block|,
name|FW_FLOWC_MNEM_SCHEDCLASS
block|,
name|FW_FLOWC_MNEM_DCBPRIO
block|,
name|FW_FLOWC_MNEM_SND_SCALE
block|,
name|FW_FLOWC_MNEM_RCV_SCALE
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_flowc_mnemval
block|{
name|u8
name|mnemonic
decl_stmt|;
name|u8
name|r4
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_flowc_wr
block|{
name|__be32
name|op_to_nparams
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|struct
name|fw_flowc_mnemval
name|mnemval
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_FLOWC_WR_NPARAMS_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_FLOWC_WR_NPARAMS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_FLOWC_WR_NPARAMS_S)
end_define

begin_struct
struct|struct
name|fw_ofld_tx_data_wr
block|{
name|__be32
name|op_to_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
name|__be32
name|tunnel_to_proxy
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_TUNNEL_S
value|19
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_TUNNEL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_OFLD_TX_DATA_WR_TUNNEL_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_SAVE_S
value|18
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_SAVE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_OFLD_TX_DATA_WR_SAVE_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_FLUSH_S
value|17
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_FLUSH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_OFLD_TX_DATA_WR_FLUSH_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_FLUSH_F
value|FW_OFLD_TX_DATA_WR_FLUSH_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_URGENT_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_URGENT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_OFLD_TX_DATA_WR_URGENT_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_MORE_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_MORE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_OFLD_TX_DATA_WR_MORE_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_SHOVE_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_SHOVE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_OFLD_TX_DATA_WR_SHOVE_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_SHOVE_F
value|FW_OFLD_TX_DATA_WR_SHOVE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_ULPMODE_S
value|10
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_ULPMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_OFLD_TX_DATA_WR_ULPMODE_S)
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_ULPSUBMODE_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_OFLD_TX_DATA_WR_ULPSUBMODE_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_OFLD_TX_DATA_WR_ULPSUBMODE_S)
end_define

begin_struct
struct|struct
name|fw_cmd_wr
block|{
name|__be32
name|op_dma
decl_stmt|;
name|__be32
name|len16_pkd
decl_stmt|;
name|__be64
name|cookie_daddr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_CMD_WR_DMA_S
value|17
end_define

begin_define
define|#
directive|define
name|FW_CMD_WR_DMA_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CMD_WR_DMA_S)
end_define

begin_struct
struct|struct
name|fw_eth_tx_pkt_vm_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|equiq_to_len16
decl_stmt|;
name|__be32
name|r3
index|[
literal|2
index|]
decl_stmt|;
name|u8
name|ethmacdst
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|ethmacsrc
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|ethtype
decl_stmt|;
name|__be16
name|vlantci
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_CMD_MAX_TIMEOUT
value|10000
end_define

begin_comment
comment|/*  * If a host driver does a HELLO and discovers that there's already a MASTER  * selected, we may have to wait for that MASTER to finish issuing RESET,  * configuration and INITIALIZE commands.  Also, there's a possibility that  * our own HELLO may get lost if it happens right as the MASTER is issuign a  * RESET command, so we need to be willing to make a few retries of our HELLO.  */
end_comment

begin_define
define|#
directive|define
name|FW_CMD_HELLO_TIMEOUT
value|(3 * FW_CMD_MAX_TIMEOUT)
end_define

begin_define
define|#
directive|define
name|FW_CMD_HELLO_RETRIES
value|3
end_define

begin_enum
enum|enum
name|fw_cmd_opcodes
block|{
name|FW_LDST_CMD
init|=
literal|0x01
block|,
name|FW_RESET_CMD
init|=
literal|0x03
block|,
name|FW_HELLO_CMD
init|=
literal|0x04
block|,
name|FW_BYE_CMD
init|=
literal|0x05
block|,
name|FW_INITIALIZE_CMD
init|=
literal|0x06
block|,
name|FW_CAPS_CONFIG_CMD
init|=
literal|0x07
block|,
name|FW_PARAMS_CMD
init|=
literal|0x08
block|,
name|FW_PFVF_CMD
init|=
literal|0x09
block|,
name|FW_IQ_CMD
init|=
literal|0x10
block|,
name|FW_EQ_MNGT_CMD
init|=
literal|0x11
block|,
name|FW_EQ_ETH_CMD
init|=
literal|0x12
block|,
name|FW_EQ_CTRL_CMD
init|=
literal|0x13
block|,
name|FW_EQ_OFLD_CMD
init|=
literal|0x21
block|,
name|FW_VI_CMD
init|=
literal|0x14
block|,
name|FW_VI_MAC_CMD
init|=
literal|0x15
block|,
name|FW_VI_RXMODE_CMD
init|=
literal|0x16
block|,
name|FW_VI_ENABLE_CMD
init|=
literal|0x17
block|,
name|FW_ACL_MAC_CMD
init|=
literal|0x18
block|,
name|FW_ACL_VLAN_CMD
init|=
literal|0x19
block|,
name|FW_VI_STATS_CMD
init|=
literal|0x1a
block|,
name|FW_PORT_CMD
init|=
literal|0x1b
block|,
name|FW_PORT_STATS_CMD
init|=
literal|0x1c
block|,
name|FW_PORT_LB_STATS_CMD
init|=
literal|0x1d
block|,
name|FW_PORT_TRACE_CMD
init|=
literal|0x1e
block|,
name|FW_PORT_TRACE_MMAP_CMD
init|=
literal|0x1f
block|,
name|FW_RSS_IND_TBL_CMD
init|=
literal|0x20
block|,
name|FW_RSS_GLB_CONFIG_CMD
init|=
literal|0x22
block|,
name|FW_RSS_VI_CONFIG_CMD
init|=
literal|0x23
block|,
name|FW_DEVLOG_CMD
init|=
literal|0x25
block|,
name|FW_CLIP_CMD
init|=
literal|0x28
block|,
name|FW_LASTC2E_CMD
init|=
literal|0x40
block|,
name|FW_ERROR_CMD
init|=
literal|0x80
block|,
name|FW_DEBUG_CMD
init|=
literal|0x81
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_cmd_cap
block|{
name|FW_CMD_CAP_PF
init|=
literal|0x01
block|,
name|FW_CMD_CAP_DMAQ
init|=
literal|0x02
block|,
name|FW_CMD_CAP_PORT
init|=
literal|0x04
block|,
name|FW_CMD_CAP_PORTPROMISC
init|=
literal|0x08
block|,
name|FW_CMD_CAP_PORTSTATS
init|=
literal|0x10
block|,
name|FW_CMD_CAP_VF
init|=
literal|0x80
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Generic command header flit0  */
end_comment

begin_struct
struct|struct
name|fw_cmd_hdr
block|{
name|__be32
name|hi
decl_stmt|;
name|__be32
name|lo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_CMD_OP_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_CMD_OP_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_CMD_OP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CMD_OP_S)
end_define

begin_define
define|#
directive|define
name|FW_CMD_OP_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_CMD_OP_S)& FW_CMD_OP_M)
end_define

begin_define
define|#
directive|define
name|FW_CMD_REQUEST_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_CMD_REQUEST_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CMD_REQUEST_S)
end_define

begin_define
define|#
directive|define
name|FW_CMD_REQUEST_F
value|FW_CMD_REQUEST_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_CMD_READ_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_CMD_READ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CMD_READ_S)
end_define

begin_define
define|#
directive|define
name|FW_CMD_READ_F
value|FW_CMD_READ_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_CMD_WRITE_S
value|21
end_define

begin_define
define|#
directive|define
name|FW_CMD_WRITE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CMD_WRITE_S)
end_define

begin_define
define|#
directive|define
name|FW_CMD_WRITE_F
value|FW_CMD_WRITE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_CMD_EXEC_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_CMD_EXEC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CMD_EXEC_S)
end_define

begin_define
define|#
directive|define
name|FW_CMD_EXEC_F
value|FW_CMD_EXEC_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_CMD_RAMASK_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_CMD_RAMASK_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CMD_RAMASK_S)
end_define

begin_define
define|#
directive|define
name|FW_CMD_RETVAL_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_CMD_RETVAL_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_CMD_RETVAL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CMD_RETVAL_S)
end_define

begin_define
define|#
directive|define
name|FW_CMD_RETVAL_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_CMD_RETVAL_S)& FW_CMD_RETVAL_M)
end_define

begin_define
define|#
directive|define
name|FW_CMD_LEN16_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_CMD_LEN16_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CMD_LEN16_S)
end_define

begin_define
define|#
directive|define
name|FW_LEN16
parameter_list|(
name|fw_struct
parameter_list|)
value|FW_CMD_LEN16_V(sizeof(fw_struct) / 16)
end_define

begin_enum
enum|enum
name|fw_ldst_addrspc
block|{
name|FW_LDST_ADDRSPC_FIRMWARE
init|=
literal|0x0001
block|,
name|FW_LDST_ADDRSPC_SGE_EGRC
init|=
literal|0x0008
block|,
name|FW_LDST_ADDRSPC_SGE_INGC
init|=
literal|0x0009
block|,
name|FW_LDST_ADDRSPC_SGE_FLMC
init|=
literal|0x000a
block|,
name|FW_LDST_ADDRSPC_SGE_CONMC
init|=
literal|0x000b
block|,
name|FW_LDST_ADDRSPC_TP_PIO
init|=
literal|0x0010
block|,
name|FW_LDST_ADDRSPC_TP_TM_PIO
init|=
literal|0x0011
block|,
name|FW_LDST_ADDRSPC_TP_MIB
init|=
literal|0x0012
block|,
name|FW_LDST_ADDRSPC_MDIO
init|=
literal|0x0018
block|,
name|FW_LDST_ADDRSPC_MPS
init|=
literal|0x0020
block|,
name|FW_LDST_ADDRSPC_FUNC
init|=
literal|0x0028
block|,
name|FW_LDST_ADDRSPC_FUNC_PCIE
init|=
literal|0x0029
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_ldst_mps_fid
block|{
name|FW_LDST_MPS_ATRB
block|,
name|FW_LDST_MPS_RPLC
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ldst_func_access_ctl
block|{
name|FW_LDST_FUNC_ACC_CTL_VIID
block|,
name|FW_LDST_FUNC_ACC_CTL_FID
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ldst_func_mod_index
block|{
name|FW_LDST_FUNC_MPS
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fw_ldst_cmd
block|{
name|__be32
name|op_to_addrspace
decl_stmt|;
name|__be32
name|cycles_to_len16
decl_stmt|;
union|union
name|fw_ldst
block|{
struct|struct
name|fw_ldst_addrval
block|{
name|__be32
name|addr
decl_stmt|;
name|__be32
name|val
decl_stmt|;
block|}
name|addrval
struct|;
struct|struct
name|fw_ldst_idctxt
block|{
name|__be32
name|physid
decl_stmt|;
name|__be32
name|msg_ctxtflush
decl_stmt|;
name|__be32
name|ctxt_data7
decl_stmt|;
name|__be32
name|ctxt_data6
decl_stmt|;
name|__be32
name|ctxt_data5
decl_stmt|;
name|__be32
name|ctxt_data4
decl_stmt|;
name|__be32
name|ctxt_data3
decl_stmt|;
name|__be32
name|ctxt_data2
decl_stmt|;
name|__be32
name|ctxt_data1
decl_stmt|;
name|__be32
name|ctxt_data0
decl_stmt|;
block|}
name|idctxt
struct|;
struct|struct
name|fw_ldst_mdio
block|{
name|__be16
name|paddr_mmd
decl_stmt|;
name|__be16
name|raddr
decl_stmt|;
name|__be16
name|vctl
decl_stmt|;
name|__be16
name|rval
decl_stmt|;
block|}
name|mdio
struct|;
struct|struct
name|fw_ldst_cim_rq
block|{
name|u8
name|req_first64
index|[
literal|8
index|]
decl_stmt|;
name|u8
name|req_second64
index|[
literal|8
index|]
decl_stmt|;
name|u8
name|resp_first64
index|[
literal|8
index|]
decl_stmt|;
name|u8
name|resp_second64
index|[
literal|8
index|]
decl_stmt|;
name|__be32
name|r3
index|[
literal|2
index|]
decl_stmt|;
block|}
name|cim_rq
struct|;
union|union
name|fw_ldst_mps
block|{
struct|struct
name|fw_ldst_mps_rplc
block|{
name|__be16
name|fid_idx
decl_stmt|;
name|__be16
name|rplcpf_pkd
decl_stmt|;
name|__be32
name|rplc255_224
decl_stmt|;
name|__be32
name|rplc223_192
decl_stmt|;
name|__be32
name|rplc191_160
decl_stmt|;
name|__be32
name|rplc159_128
decl_stmt|;
name|__be32
name|rplc127_96
decl_stmt|;
name|__be32
name|rplc95_64
decl_stmt|;
name|__be32
name|rplc63_32
decl_stmt|;
name|__be32
name|rplc31_0
decl_stmt|;
block|}
name|rplc
struct|;
struct|struct
name|fw_ldst_mps_atrb
block|{
name|__be16
name|fid_mpsid
decl_stmt|;
name|__be16
name|r2
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|r3
index|[
literal|2
index|]
decl_stmt|;
name|__be32
name|r4
decl_stmt|;
name|__be32
name|atrb
decl_stmt|;
name|__be16
name|vlan
index|[
literal|16
index|]
decl_stmt|;
block|}
name|atrb
struct|;
block|}
name|mps
union|;
struct|struct
name|fw_ldst_func
block|{
name|u8
name|access_ctl
decl_stmt|;
name|u8
name|mod_index
decl_stmt|;
name|__be16
name|ctl_id
decl_stmt|;
name|__be32
name|offset
decl_stmt|;
name|__be64
name|data0
decl_stmt|;
name|__be64
name|data1
decl_stmt|;
block|}
name|func
struct|;
struct|struct
name|fw_ldst_pcie
block|{
name|u8
name|ctrl_to_fn
decl_stmt|;
name|u8
name|bnum
decl_stmt|;
name|u8
name|r
decl_stmt|;
name|u8
name|ext_r
decl_stmt|;
name|u8
name|select_naccess
decl_stmt|;
name|u8
name|pcie_fn
decl_stmt|;
name|__be16
name|nset_pkd
decl_stmt|;
name|__be32
name|data
index|[
literal|12
index|]
decl_stmt|;
block|}
name|pcie
struct|;
struct|struct
name|fw_ldst_i2c_deprecated
block|{
name|u8
name|pid_pkd
decl_stmt|;
name|u8
name|base
decl_stmt|;
name|u8
name|boffset
decl_stmt|;
name|u8
name|data
decl_stmt|;
name|__be32
name|r9
decl_stmt|;
block|}
name|i2c_deprecated
struct|;
struct|struct
name|fw_ldst_i2c
block|{
name|u8
name|pid
decl_stmt|;
name|u8
name|did
decl_stmt|;
name|u8
name|boffset
decl_stmt|;
name|u8
name|blen
decl_stmt|;
name|__be32
name|r9
decl_stmt|;
name|__u8
name|data
index|[
literal|48
index|]
decl_stmt|;
block|}
name|i2c
struct|;
struct|struct
name|fw_ldst_le
block|{
name|__be32
name|index
decl_stmt|;
name|__be32
name|r9
decl_stmt|;
name|u8
name|val
index|[
literal|33
index|]
decl_stmt|;
name|u8
name|r11
index|[
literal|7
index|]
decl_stmt|;
block|}
name|le
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
name|FW_LDST_CMD_ADDRSPACE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_ADDRSPACE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_ADDRSPACE_S)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_MSG_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_MSG_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_MSG_S)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_CTXTFLUSH_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_CTXTFLUSH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_CTXTFLUSH_S)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_CTXTFLUSH_F
value|FW_LDST_CMD_CTXTFLUSH_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_PADDR_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_PADDR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_PADDR_S)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_MMD_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_MMD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_MMD_S)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_FID_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_FID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_FID_S)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_IDX_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_IDX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_IDX_S)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_RPLCPF_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_RPLCPF_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_RPLCPF_S)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_LC_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_LC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_LC_S)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_LC_F
value|FW_LDST_CMD_LC_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_FN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_FN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_FN_S)
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_NACCESS_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_LDST_CMD_NACCESS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_LDST_CMD_NACCESS_S)
end_define

begin_struct
struct|struct
name|fw_reset_cmd
block|{
name|__be32
name|op_to_write
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be32
name|val
decl_stmt|;
name|__be32
name|halt_pkd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_RESET_CMD_HALT_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_RESET_CMD_HALT_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_RESET_CMD_HALT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RESET_CMD_HALT_S)
end_define

begin_define
define|#
directive|define
name|FW_RESET_CMD_HALT_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RESET_CMD_HALT_S)& FW_RESET_CMD_HALT_M)
end_define

begin_define
define|#
directive|define
name|FW_RESET_CMD_HALT_F
value|FW_RESET_CMD_HALT_V(1U)
end_define

begin_enum
enum|enum
name|fw_hellow_cmd
block|{
name|fw_hello_cmd_stage_os
init|=
literal|0x0
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fw_hello_cmd
block|{
name|__be32
name|op_to_write
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be32
name|err_to_clearinit
decl_stmt|;
name|__be32
name|fwrev
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_HELLO_CMD_ERR_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_ERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_HELLO_CMD_ERR_S)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_ERR_F
value|FW_HELLO_CMD_ERR_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_INIT_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_INIT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_HELLO_CMD_INIT_S)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_INIT_F
value|FW_HELLO_CMD_INIT_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MASTERDIS_S
value|29
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MASTERDIS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_HELLO_CMD_MASTERDIS_S)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MASTERFORCE_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MASTERFORCE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_HELLO_CMD_MASTERFORCE_S)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MBMASTER_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MBMASTER_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MBMASTER_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_HELLO_CMD_MBMASTER_S)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MBMASTER_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_HELLO_CMD_MBMASTER_S)& FW_HELLO_CMD_MBMASTER_M)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MBASYNCNOTINT_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MBASYNCNOTINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_HELLO_CMD_MBASYNCNOTINT_S)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MBASYNCNOT_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_MBASYNCNOT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_HELLO_CMD_MBASYNCNOT_S)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_STAGE_S
value|17
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_STAGE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_HELLO_CMD_STAGE_S)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_CLEARINIT_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_CLEARINIT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_HELLO_CMD_CLEARINIT_S)
end_define

begin_define
define|#
directive|define
name|FW_HELLO_CMD_CLEARINIT_F
value|FW_HELLO_CMD_CLEARINIT_V(1U)
end_define

begin_struct
struct|struct
name|fw_bye_cmd
block|{
name|__be32
name|op_to_write
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be64
name|r3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_initialize_cmd
block|{
name|__be32
name|op_to_write
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be64
name|r3
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fw_caps_config_hm
block|{
name|FW_CAPS_CONFIG_HM_PCIE
init|=
literal|0x00000001
block|,
name|FW_CAPS_CONFIG_HM_PL
init|=
literal|0x00000002
block|,
name|FW_CAPS_CONFIG_HM_SGE
init|=
literal|0x00000004
block|,
name|FW_CAPS_CONFIG_HM_CIM
init|=
literal|0x00000008
block|,
name|FW_CAPS_CONFIG_HM_ULPTX
init|=
literal|0x00000010
block|,
name|FW_CAPS_CONFIG_HM_TP
init|=
literal|0x00000020
block|,
name|FW_CAPS_CONFIG_HM_ULPRX
init|=
literal|0x00000040
block|,
name|FW_CAPS_CONFIG_HM_PMRX
init|=
literal|0x00000080
block|,
name|FW_CAPS_CONFIG_HM_PMTX
init|=
literal|0x00000100
block|,
name|FW_CAPS_CONFIG_HM_MC
init|=
literal|0x00000200
block|,
name|FW_CAPS_CONFIG_HM_LE
init|=
literal|0x00000400
block|,
name|FW_CAPS_CONFIG_HM_MPS
init|=
literal|0x00000800
block|,
name|FW_CAPS_CONFIG_HM_XGMAC
init|=
literal|0x00001000
block|,
name|FW_CAPS_CONFIG_HM_CPLSWITCH
init|=
literal|0x00002000
block|,
name|FW_CAPS_CONFIG_HM_T4DBG
init|=
literal|0x00004000
block|,
name|FW_CAPS_CONFIG_HM_MI
init|=
literal|0x00008000
block|,
name|FW_CAPS_CONFIG_HM_I2CM
init|=
literal|0x00010000
block|,
name|FW_CAPS_CONFIG_HM_NCSI
init|=
literal|0x00020000
block|,
name|FW_CAPS_CONFIG_HM_SMB
init|=
literal|0x00040000
block|,
name|FW_CAPS_CONFIG_HM_MA
init|=
literal|0x00080000
block|,
name|FW_CAPS_CONFIG_HM_EDRAM
init|=
literal|0x00100000
block|,
name|FW_CAPS_CONFIG_HM_PMU
init|=
literal|0x00200000
block|,
name|FW_CAPS_CONFIG_HM_UART
init|=
literal|0x00400000
block|,
name|FW_CAPS_CONFIG_HM_SF
init|=
literal|0x00800000
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_caps_config_nbm
block|{
name|FW_CAPS_CONFIG_NBM_IPMI
init|=
literal|0x00000001
block|,
name|FW_CAPS_CONFIG_NBM_NCSI
init|=
literal|0x00000002
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_caps_config_link
block|{
name|FW_CAPS_CONFIG_LINK_PPP
init|=
literal|0x00000001
block|,
name|FW_CAPS_CONFIG_LINK_QFC
init|=
literal|0x00000002
block|,
name|FW_CAPS_CONFIG_LINK_DCBX
init|=
literal|0x00000004
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_caps_config_switch
block|{
name|FW_CAPS_CONFIG_SWITCH_INGRESS
init|=
literal|0x00000001
block|,
name|FW_CAPS_CONFIG_SWITCH_EGRESS
init|=
literal|0x00000002
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_caps_config_nic
block|{
name|FW_CAPS_CONFIG_NIC
init|=
literal|0x00000001
block|,
name|FW_CAPS_CONFIG_NIC_VM
init|=
literal|0x00000002
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_caps_config_ofld
block|{
name|FW_CAPS_CONFIG_OFLD
init|=
literal|0x00000001
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_caps_config_rdma
block|{
name|FW_CAPS_CONFIG_RDMA_RDDP
init|=
literal|0x00000001
block|,
name|FW_CAPS_CONFIG_RDMA_RDMAC
init|=
literal|0x00000002
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_caps_config_iscsi
block|{
name|FW_CAPS_CONFIG_ISCSI_INITIATOR_PDU
init|=
literal|0x00000001
block|,
name|FW_CAPS_CONFIG_ISCSI_TARGET_PDU
init|=
literal|0x00000002
block|,
name|FW_CAPS_CONFIG_ISCSI_INITIATOR_CNXOFLD
init|=
literal|0x00000004
block|,
name|FW_CAPS_CONFIG_ISCSI_TARGET_CNXOFLD
init|=
literal|0x00000008
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_caps_config_fcoe
block|{
name|FW_CAPS_CONFIG_FCOE_INITIATOR
init|=
literal|0x00000001
block|,
name|FW_CAPS_CONFIG_FCOE_TARGET
init|=
literal|0x00000002
block|,
name|FW_CAPS_CONFIG_FCOE_CTRL_OFLD
init|=
literal|0x00000004
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_memtype_cf
block|{
name|FW_MEMTYPE_CF_EDC0
init|=
literal|0x0
block|,
name|FW_MEMTYPE_CF_EDC1
init|=
literal|0x1
block|,
name|FW_MEMTYPE_CF_EXTMEM
init|=
literal|0x2
block|,
name|FW_MEMTYPE_CF_FLASH
init|=
literal|0x4
block|,
name|FW_MEMTYPE_CF_INTERNAL
init|=
literal|0x5
block|,
name|FW_MEMTYPE_CF_EXTMEM1
init|=
literal|0x6
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_caps_config_cmd
block|{
name|__be32
name|op_to_write
decl_stmt|;
name|__be32
name|cfvalid_to_len16
decl_stmt|;
name|__be32
name|r2
decl_stmt|;
name|__be32
name|hwmbitmap
decl_stmt|;
name|__be16
name|nbmcaps
decl_stmt|;
name|__be16
name|linkcaps
decl_stmt|;
name|__be16
name|switchcaps
decl_stmt|;
name|__be16
name|r3
decl_stmt|;
name|__be16
name|niccaps
decl_stmt|;
name|__be16
name|ofldcaps
decl_stmt|;
name|__be16
name|rdmacaps
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__be16
name|iscsicaps
decl_stmt|;
name|__be16
name|fcoecaps
decl_stmt|;
name|__be32
name|cfcsum
decl_stmt|;
name|__be32
name|finiver
decl_stmt|;
name|__be32
name|finicsum
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_CAPS_CONFIG_CMD_CFVALID_S
value|27
end_define

begin_define
define|#
directive|define
name|FW_CAPS_CONFIG_CMD_CFVALID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CAPS_CONFIG_CMD_CFVALID_S)
end_define

begin_define
define|#
directive|define
name|FW_CAPS_CONFIG_CMD_CFVALID_F
value|FW_CAPS_CONFIG_CMD_CFVALID_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_CAPS_CONFIG_CMD_MEMTYPE_CF_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_CAPS_CONFIG_CMD_MEMTYPE_CF_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_CAPS_CONFIG_CMD_MEMTYPE_CF_S)
end_define

begin_define
define|#
directive|define
name|FW_CAPS_CONFIG_CMD_MEMADDR64K_CF_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_CAPS_CONFIG_CMD_MEMADDR64K_CF_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_CAPS_CONFIG_CMD_MEMADDR64K_CF_S)
end_define

begin_comment
comment|/*  * params command mnemonics  */
end_comment

begin_enum
enum|enum
name|fw_params_mnem
block|{
name|FW_PARAMS_MNEM_DEV
init|=
literal|1
block|,
comment|/* device params */
name|FW_PARAMS_MNEM_PFVF
init|=
literal|2
block|,
comment|/* function params */
name|FW_PARAMS_MNEM_REG
init|=
literal|3
block|,
comment|/* limited register access */
name|FW_PARAMS_MNEM_DMAQ
init|=
literal|4
block|,
comment|/* dma queue params */
name|FW_PARAMS_MNEM_CHNET
init|=
literal|5
block|,
comment|/* chnet params */
name|FW_PARAMS_MNEM_LAST
block|}
enum|;
end_enum

begin_comment
comment|/*  * device parameters  */
end_comment

begin_enum
enum|enum
name|fw_params_param_dev
block|{
name|FW_PARAMS_PARAM_DEV_CCLK
init|=
literal|0x00
block|,
comment|/* chip core clock in khz */
name|FW_PARAMS_PARAM_DEV_PORTVEC
init|=
literal|0x01
block|,
comment|/* the port vector */
name|FW_PARAMS_PARAM_DEV_NTID
init|=
literal|0x02
block|,
comment|/* reads the number of TIDs 						 * allocated by the device's 						 * Lookup Engine 						 */
name|FW_PARAMS_PARAM_DEV_FLOWC_BUFFIFO_SZ
init|=
literal|0x03
block|,
name|FW_PARAMS_PARAM_DEV_INTVER_NIC
init|=
literal|0x04
block|,
name|FW_PARAMS_PARAM_DEV_INTVER_VNIC
init|=
literal|0x05
block|,
name|FW_PARAMS_PARAM_DEV_INTVER_OFLD
init|=
literal|0x06
block|,
name|FW_PARAMS_PARAM_DEV_INTVER_RI
init|=
literal|0x07
block|,
name|FW_PARAMS_PARAM_DEV_INTVER_ISCSIPDU
init|=
literal|0x08
block|,
name|FW_PARAMS_PARAM_DEV_INTVER_ISCSI
init|=
literal|0x09
block|,
name|FW_PARAMS_PARAM_DEV_INTVER_FCOE
init|=
literal|0x0A
block|,
name|FW_PARAMS_PARAM_DEV_FWREV
init|=
literal|0x0B
block|,
name|FW_PARAMS_PARAM_DEV_TPREV
init|=
literal|0x0C
block|,
name|FW_PARAMS_PARAM_DEV_CF
init|=
literal|0x0D
block|,
name|FW_PARAMS_PARAM_DEV_PHYFW
init|=
literal|0x0F
block|,
name|FW_PARAMS_PARAM_DEV_DIAG
init|=
literal|0x11
block|,
name|FW_PARAMS_PARAM_DEV_MAXORDIRD_QP
init|=
literal|0x13
block|,
comment|/* max supported QP IRD/ORD */
name|FW_PARAMS_PARAM_DEV_MAXIRD_ADAPTER
init|=
literal|0x14
block|,
comment|/* max supported adap IRD */
name|FW_PARAMS_PARAM_DEV_ULPTX_MEMWRITE_DSGL
init|=
literal|0x17
block|,
name|FW_PARAMS_PARAM_DEV_FWCACHE
init|=
literal|0x18
block|, }
enum|;
end_enum

begin_comment
comment|/*  * physical and virtual function parameters  */
end_comment

begin_enum
enum|enum
name|fw_params_param_pfvf
block|{
name|FW_PARAMS_PARAM_PFVF_RWXCAPS
init|=
literal|0x00
block|,
name|FW_PARAMS_PARAM_PFVF_ROUTE_START
init|=
literal|0x01
block|,
name|FW_PARAMS_PARAM_PFVF_ROUTE_END
init|=
literal|0x02
block|,
name|FW_PARAMS_PARAM_PFVF_CLIP_START
init|=
literal|0x03
block|,
name|FW_PARAMS_PARAM_PFVF_CLIP_END
init|=
literal|0x04
block|,
name|FW_PARAMS_PARAM_PFVF_FILTER_START
init|=
literal|0x05
block|,
name|FW_PARAMS_PARAM_PFVF_FILTER_END
init|=
literal|0x06
block|,
name|FW_PARAMS_PARAM_PFVF_SERVER_START
init|=
literal|0x07
block|,
name|FW_PARAMS_PARAM_PFVF_SERVER_END
init|=
literal|0x08
block|,
name|FW_PARAMS_PARAM_PFVF_TDDP_START
init|=
literal|0x09
block|,
name|FW_PARAMS_PARAM_PFVF_TDDP_END
init|=
literal|0x0A
block|,
name|FW_PARAMS_PARAM_PFVF_ISCSI_START
init|=
literal|0x0B
block|,
name|FW_PARAMS_PARAM_PFVF_ISCSI_END
init|=
literal|0x0C
block|,
name|FW_PARAMS_PARAM_PFVF_STAG_START
init|=
literal|0x0D
block|,
name|FW_PARAMS_PARAM_PFVF_STAG_END
init|=
literal|0x0E
block|,
name|FW_PARAMS_PARAM_PFVF_RQ_START
init|=
literal|0x1F
block|,
name|FW_PARAMS_PARAM_PFVF_RQ_END
init|=
literal|0x10
block|,
name|FW_PARAMS_PARAM_PFVF_PBL_START
init|=
literal|0x11
block|,
name|FW_PARAMS_PARAM_PFVF_PBL_END
init|=
literal|0x12
block|,
name|FW_PARAMS_PARAM_PFVF_L2T_START
init|=
literal|0x13
block|,
name|FW_PARAMS_PARAM_PFVF_L2T_END
init|=
literal|0x14
block|,
name|FW_PARAMS_PARAM_PFVF_SQRQ_START
init|=
literal|0x15
block|,
name|FW_PARAMS_PARAM_PFVF_SQRQ_END
init|=
literal|0x16
block|,
name|FW_PARAMS_PARAM_PFVF_CQ_START
init|=
literal|0x17
block|,
name|FW_PARAMS_PARAM_PFVF_CQ_END
init|=
literal|0x18
block|,
name|FW_PARAMS_PARAM_PFVF_SCHEDCLASS_ETH
init|=
literal|0x20
block|,
name|FW_PARAMS_PARAM_PFVF_VIID
init|=
literal|0x24
block|,
name|FW_PARAMS_PARAM_PFVF_CPMASK
init|=
literal|0x25
block|,
name|FW_PARAMS_PARAM_PFVF_OCQ_START
init|=
literal|0x26
block|,
name|FW_PARAMS_PARAM_PFVF_OCQ_END
init|=
literal|0x27
block|,
name|FW_PARAMS_PARAM_PFVF_CONM_MAP
init|=
literal|0x28
block|,
name|FW_PARAMS_PARAM_PFVF_IQFLINT_START
init|=
literal|0x29
block|,
name|FW_PARAMS_PARAM_PFVF_IQFLINT_END
init|=
literal|0x2A
block|,
name|FW_PARAMS_PARAM_PFVF_EQ_START
init|=
literal|0x2B
block|,
name|FW_PARAMS_PARAM_PFVF_EQ_END
init|=
literal|0x2C
block|,
name|FW_PARAMS_PARAM_PFVF_ACTIVE_FILTER_START
init|=
literal|0x2D
block|,
name|FW_PARAMS_PARAM_PFVF_ACTIVE_FILTER_END
init|=
literal|0x2E
block|,
name|FW_PARAMS_PARAM_PFVF_ETHOFLD_END
init|=
literal|0x30
block|,
name|FW_PARAMS_PARAM_PFVF_CPLFW4MSG_ENCAP
init|=
literal|0x31
block|}
enum|;
end_enum

begin_comment
comment|/*  * dma queue parameters  */
end_comment

begin_enum
enum|enum
name|fw_params_param_dmaq
block|{
name|FW_PARAMS_PARAM_DMAQ_IQ_DCAEN_DCACPU
init|=
literal|0x00
block|,
name|FW_PARAMS_PARAM_DMAQ_IQ_INTCNTTHRESH
init|=
literal|0x01
block|,
name|FW_PARAMS_PARAM_DMAQ_EQ_CMPLIQID_MNGT
init|=
literal|0x10
block|,
name|FW_PARAMS_PARAM_DMAQ_EQ_CMPLIQID_CTRL
init|=
literal|0x11
block|,
name|FW_PARAMS_PARAM_DMAQ_EQ_SCHEDCLASS_ETH
init|=
literal|0x12
block|,
name|FW_PARAMS_PARAM_DMAQ_EQ_DCBPRIO_ETH
init|=
literal|0x13
block|,
name|FW_PARAMS_PARAM_DMAQ_CONM_CTXT
init|=
literal|0x20
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_params_param_dev_phyfw
block|{
name|FW_PARAMS_PARAM_DEV_PHYFW_DOWNLOAD
init|=
literal|0x00
block|,
name|FW_PARAMS_PARAM_DEV_PHYFW_VERSION
init|=
literal|0x01
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_params_param_dev_diag
block|{
name|FW_PARAM_DEV_DIAG_TMP
init|=
literal|0x00
block|,
name|FW_PARAM_DEV_DIAG_VDD
init|=
literal|0x01
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_params_param_dev_fwcache
block|{
name|FW_PARAM_DEV_FWCACHE_FLUSH
init|=
literal|0x00
block|,
name|FW_PARAM_DEV_FWCACHE_FLUSHINV
init|=
literal|0x01
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|FW_PARAMS_MNEM_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_MNEM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PARAMS_MNEM_S)
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_X_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_X_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PARAMS_PARAM_X_S)
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_Y_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_Y_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_Y_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PARAMS_PARAM_Y_S)
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_Y_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_PARAMS_PARAM_Y_S)&\ 		FW_PARAMS_PARAM_Y_M)
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_Z_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_Z_M
value|0xffu
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_Z_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PARAMS_PARAM_Z_S)
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_Z_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_PARAMS_PARAM_Z_S)&\ 		FW_PARAMS_PARAM_Z_M)
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_XYZ_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_XYZ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PARAMS_PARAM_XYZ_S)
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_YZ_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_PARAM_YZ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PARAMS_PARAM_YZ_S)
end_define

begin_struct
struct|struct
name|fw_params_cmd
block|{
name|__be32
name|op_to_vfn
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
struct|struct
name|fw_params_param
block|{
name|__be32
name|mnem
decl_stmt|;
name|__be32
name|val
decl_stmt|;
block|}
name|param
index|[
literal|7
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_PARAMS_CMD_PFN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_CMD_PFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PARAMS_CMD_PFN_S)
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_CMD_VFN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PARAMS_CMD_VFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PARAMS_CMD_VFN_S)
end_define

begin_struct
struct|struct
name|fw_pfvf_cmd
block|{
name|__be32
name|op_to_vfn
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be32
name|niqflint_niq
decl_stmt|;
name|__be32
name|type_to_neq
decl_stmt|;
name|__be32
name|tc_to_nexactf
decl_stmt|;
name|__be32
name|r_caps_to_nethctrl
decl_stmt|;
name|__be16
name|nricq
decl_stmt|;
name|__be16
name|nriqp
decl_stmt|;
name|__be32
name|r4
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_PFVF_CMD_PFN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_PFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_PFN_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_VFN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_VFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_VFN_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NIQFLINT_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NIQFLINT_M
value|0xfff
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NIQFLINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_NIQFLINT_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NIQFLINT_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PFVF_CMD_NIQFLINT_S)& FW_PFVF_CMD_NIQFLINT_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NIQ_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NIQ_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NIQ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_NIQ_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NIQ_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PFVF_CMD_NIQ_S)& FW_PFVF_CMD_NIQ_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_TYPE_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_TYPE_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_TYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_TYPE_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_TYPE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PFVF_CMD_TYPE_S)& FW_PFVF_CMD_TYPE_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_TYPE_F
value|FW_PFVF_CMD_TYPE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_CMASK_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_CMASK_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_CMASK_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_CMASK_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_CMASK_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PFVF_CMD_CMASK_S)& FW_PFVF_CMD_CMASK_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_PMASK_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_PMASK_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_PMASK_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_PMASK_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_PMASK_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PFVF_CMD_PMASK_S)& FW_PFVF_CMD_PMASK_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NEQ_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NEQ_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NEQ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_NEQ_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NEQ_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PFVF_CMD_NEQ_S)& FW_PFVF_CMD_NEQ_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_TC_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_TC_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_TC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_TC_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_TC_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_PFVF_CMD_TC_S)& FW_PFVF_CMD_TC_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NVI_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NVI_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NVI_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_NVI_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NVI_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_PFVF_CMD_NVI_S)& FW_PFVF_CMD_NVI_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NEXACTF_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NEXACTF_M
value|0xffff
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NEXACTF_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_NEXACTF_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NEXACTF_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PFVF_CMD_NEXACTF_S)& FW_PFVF_CMD_NEXACTF_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_R_CAPS_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_R_CAPS_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_R_CAPS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_R_CAPS_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_R_CAPS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PFVF_CMD_R_CAPS_S)& FW_PFVF_CMD_R_CAPS_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_WX_CAPS_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_WX_CAPS_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_WX_CAPS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_WX_CAPS_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_WX_CAPS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PFVF_CMD_WX_CAPS_S)& FW_PFVF_CMD_WX_CAPS_M)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NETHCTRL_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NETHCTRL_M
value|0xffff
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NETHCTRL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PFVF_CMD_NETHCTRL_S)
end_define

begin_define
define|#
directive|define
name|FW_PFVF_CMD_NETHCTRL_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PFVF_CMD_NETHCTRL_S)& FW_PFVF_CMD_NETHCTRL_M)
end_define

begin_enum
enum|enum
name|fw_iq_type
block|{
name|FW_IQ_TYPE_FL_INT_CAP
block|,
name|FW_IQ_TYPE_NO_FL_INT_CAP
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fw_iq_cmd
block|{
name|__be32
name|op_to_vfn
decl_stmt|;
name|__be32
name|alloc_to_len16
decl_stmt|;
name|__be16
name|physiqid
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__be16
name|fl0id
decl_stmt|;
name|__be16
name|fl1id
decl_stmt|;
name|__be32
name|type_to_iqandstindex
decl_stmt|;
name|__be16
name|iqdroprss_to_iqesize
decl_stmt|;
name|__be16
name|iqsize
decl_stmt|;
name|__be64
name|iqaddr
decl_stmt|;
name|__be32
name|iqns_to_fl0congen
decl_stmt|;
name|__be16
name|fl0dcaen_to_fl0cidxfthresh
decl_stmt|;
name|__be16
name|fl0size
decl_stmt|;
name|__be64
name|fl0addr
decl_stmt|;
name|__be32
name|fl1cngchmap_to_fl1congen
decl_stmt|;
name|__be16
name|fl1dcaen_to_fl1cidxfthresh
decl_stmt|;
name|__be16
name|fl1size
decl_stmt|;
name|__be64
name|fl1addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_IQ_CMD_PFN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_PFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_PFN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_VFN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_VFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_VFN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_ALLOC_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_ALLOC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_ALLOC_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_ALLOC_F
value|FW_IQ_CMD_ALLOC_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FREE_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FREE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FREE_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FREE_F
value|FW_IQ_CMD_FREE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_MODIFY_S
value|29
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_MODIFY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_MODIFY_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_MODIFY_F
value|FW_IQ_CMD_MODIFY_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQSTART_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQSTART_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQSTART_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQSTART_F
value|FW_IQ_CMD_IQSTART_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQSTOP_S
value|27
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQSTOP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQSTOP_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQSTOP_F
value|FW_IQ_CMD_IQSTOP_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_TYPE_S
value|29
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_TYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_TYPE_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQASYNCH_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQASYNCH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQASYNCH_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_VIID_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_VIID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_VIID_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQANDST_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQANDST_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQANDST_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQANUS_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQANUS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQANUS_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQANUD_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQANUD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQANUD_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQANDSTINDEX_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQANDSTINDEX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQANDSTINDEX_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQDROPRSS_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQDROPRSS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQDROPRSS_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQDROPRSS_F
value|FW_IQ_CMD_IQDROPRSS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQGTSMODE_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQGTSMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQGTSMODE_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQGTSMODE_F
value|FW_IQ_CMD_IQGTSMODE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQPCIECH_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQPCIECH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQPCIECH_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQDCAEN_S
value|11
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQDCAEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQDCAEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQDCACPU_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQDCACPU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQDCACPU_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQINTCNTTHRESH_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQINTCNTTHRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQINTCNTTHRESH_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQO_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQO_F
value|FW_IQ_CMD_IQO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQCPRIO_S
value|2
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQCPRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQCPRIO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQESIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQESIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQESIZE_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQNS_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQNS_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQRO_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQRO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQFLINTIQHSEN_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQFLINTIQHSEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQFLINTIQHSEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQFLINTCONGEN_S
value|27
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQFLINTCONGEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQFLINTCONGEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQFLINTCONGEN_F
value|FW_IQ_CMD_IQFLINTCONGEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQFLINTISCSIC_S
value|26
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_IQFLINTISCSIC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_IQFLINTISCSIC_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CNGCHMAP_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CNGCHMAP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0CNGCHMAP_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CACHELOCK_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CACHELOCK_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0CACHELOCK_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DBP_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DBP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0DBP_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DATANS_S
value|13
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DATANS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0DATANS_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DATARO_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DATARO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0DATARO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DATARO_F
value|FW_IQ_CMD_FL0DATARO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CONGCIF_S
value|11
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CONGCIF_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0CONGCIF_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CONGCIF_F
value|FW_IQ_CMD_FL0CONGCIF_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0ONCHIP_S
value|10
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0ONCHIP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0ONCHIP_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0STATUSPGNS_S
value|9
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0STATUSPGNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0STATUSPGNS_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0STATUSPGRO_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0STATUSPGRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0STATUSPGRO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0FETCHNS_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0FETCHNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0FETCHNS_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0FETCHRO_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0FETCHRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0FETCHRO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0FETCHRO_F
value|FW_IQ_CMD_FL0FETCHRO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0HOSTFCMODE_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0HOSTFCMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0HOSTFCMODE_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CPRIO_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CPRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0CPRIO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0PADEN_S
value|2
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0PADEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0PADEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0PADEN_F
value|FW_IQ_CMD_FL0PADEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0PACKEN_S
value|1
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0PACKEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0PACKEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0PACKEN_F
value|FW_IQ_CMD_FL0PACKEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CONGEN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CONGEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0CONGEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CONGEN_F
value|FW_IQ_CMD_FL0CONGEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DCAEN_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DCAEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0DCAEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DCACPU_S
value|10
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0DCACPU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0DCACPU_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0FBMIN_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0FBMIN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0FBMIN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0FBMAX_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0FBMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0FBMAX_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CIDXFTHRESHO_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CIDXFTHRESHO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0CIDXFTHRESHO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CIDXFTHRESHO_F
value|FW_IQ_CMD_FL0CIDXFTHRESHO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CIDXFTHRESH_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL0CIDXFTHRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL0CIDXFTHRESH_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CNGCHMAP_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CNGCHMAP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1CNGCHMAP_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CACHELOCK_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CACHELOCK_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1CACHELOCK_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1DBP_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1DBP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1DBP_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1DATANS_S
value|13
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1DATANS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1DATANS_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1DATARO_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1DATARO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1DATARO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CONGCIF_S
value|11
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CONGCIF_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1CONGCIF_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1ONCHIP_S
value|10
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1ONCHIP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1ONCHIP_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1STATUSPGNS_S
value|9
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1STATUSPGNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1STATUSPGNS_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1STATUSPGRO_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1STATUSPGRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1STATUSPGRO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1FETCHNS_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1FETCHNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1FETCHNS_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1FETCHRO_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1FETCHRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1FETCHRO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1HOSTFCMODE_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1HOSTFCMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1HOSTFCMODE_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CPRIO_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CPRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1CPRIO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1PADEN_S
value|2
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1PADEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1PADEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1PADEN_F
value|FW_IQ_CMD_FL1PADEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1PACKEN_S
value|1
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1PACKEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1PACKEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1PACKEN_F
value|FW_IQ_CMD_FL1PACKEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CONGEN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CONGEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1CONGEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CONGEN_F
value|FW_IQ_CMD_FL1CONGEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1DCAEN_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1DCAEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1DCAEN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1DCACPU_S
value|10
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1DCACPU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1DCACPU_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1FBMIN_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1FBMIN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1FBMIN_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1FBMAX_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1FBMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1FBMAX_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CIDXFTHRESHO_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CIDXFTHRESHO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1CIDXFTHRESHO_S)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CIDXFTHRESHO_F
value|FW_IQ_CMD_FL1CIDXFTHRESHO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CIDXFTHRESH_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_IQ_CMD_FL1CIDXFTHRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_IQ_CMD_FL1CIDXFTHRESH_S)
end_define

begin_struct
struct|struct
name|fw_eq_eth_cmd
block|{
name|__be32
name|op_to_vfn
decl_stmt|;
name|__be32
name|alloc_to_len16
decl_stmt|;
name|__be32
name|eqid_pkd
decl_stmt|;
name|__be32
name|physeqid_pkd
decl_stmt|;
name|__be32
name|fetchszm_to_iqid
decl_stmt|;
name|__be32
name|dcaen_to_eqsize
decl_stmt|;
name|__be64
name|eqaddr
decl_stmt|;
name|__be32
name|viid_pkd
decl_stmt|;
name|__be32
name|r8_lo
decl_stmt|;
name|__be64
name|r9
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_PFN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_PFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_PFN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_VFN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_VFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_VFN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_ALLOC_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_ALLOC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_ALLOC_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_ALLOC_F
value|FW_EQ_ETH_CMD_ALLOC_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FREE_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FREE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_FREE_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FREE_F
value|FW_EQ_ETH_CMD_FREE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_MODIFY_S
value|29
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_MODIFY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_MODIFY_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_MODIFY_F
value|FW_EQ_ETH_CMD_MODIFY_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQSTART_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQSTART_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_EQSTART_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQSTART_F
value|FW_EQ_ETH_CMD_EQSTART_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQSTOP_S
value|27
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQSTOP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_EQSTOP_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQSTOP_F
value|FW_EQ_ETH_CMD_EQSTOP_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQID_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_EQID_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_EQ_ETH_CMD_EQID_S)& FW_EQ_ETH_CMD_EQID_M)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_PHYSEQID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_PHYSEQID_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_PHYSEQID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_PHYSEQID_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_PHYSEQID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_EQ_ETH_CMD_PHYSEQID_S)& FW_EQ_ETH_CMD_PHYSEQID_M)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FETCHSZM_S
value|26
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FETCHSZM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_FETCHSZM_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FETCHSZM_F
value|FW_EQ_ETH_CMD_FETCHSZM_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_STATUSPGNS_S
value|25
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_STATUSPGNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_STATUSPGNS_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_STATUSPGRO_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_STATUSPGRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_STATUSPGRO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FETCHNS_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FETCHNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_FETCHNS_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FETCHRO_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FETCHRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_FETCHRO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FETCHRO_F
value|FW_EQ_ETH_CMD_FETCHRO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_HOSTFCMODE_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_HOSTFCMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_HOSTFCMODE_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_CPRIO_S
value|19
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_CPRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_CPRIO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_ONCHIP_S
value|18
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_ONCHIP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_ONCHIP_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_PCIECHN_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_PCIECHN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_PCIECHN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_IQID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_IQID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_IQID_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_DCAEN_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_DCAEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_DCAEN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_DCACPU_S
value|26
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_DCACPU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_DCACPU_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FBMIN_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FBMIN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_FBMIN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FBMAX_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_FBMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_FBMAX_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_CIDXFTHRESHO_S
value|19
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_CIDXFTHRESHO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_CIDXFTHRESHO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_CIDXFTHRESH_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_CIDXFTHRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_CIDXFTHRESH_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQSIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_EQSIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_EQSIZE_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_AUTOEQUEQE_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_AUTOEQUEQE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_AUTOEQUEQE_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_AUTOEQUEQE_F
value|FW_EQ_ETH_CMD_AUTOEQUEQE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_VIID_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_EQ_ETH_CMD_VIID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_ETH_CMD_VIID_S)
end_define

begin_struct
struct|struct
name|fw_eq_ctrl_cmd
block|{
name|__be32
name|op_to_vfn
decl_stmt|;
name|__be32
name|alloc_to_len16
decl_stmt|;
name|__be32
name|cmpliqid_eqid
decl_stmt|;
name|__be32
name|physeqid_pkd
decl_stmt|;
name|__be32
name|fetchszm_to_iqid
decl_stmt|;
name|__be32
name|dcaen_to_eqsize
decl_stmt|;
name|__be64
name|eqaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_PFN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_PFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_PFN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_VFN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_VFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_VFN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_ALLOC_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_ALLOC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_ALLOC_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_ALLOC_F
value|FW_EQ_CTRL_CMD_ALLOC_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FREE_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FREE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_FREE_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FREE_F
value|FW_EQ_CTRL_CMD_FREE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_MODIFY_S
value|29
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_MODIFY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_MODIFY_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_MODIFY_F
value|FW_EQ_CTRL_CMD_MODIFY_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQSTART_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQSTART_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_EQSTART_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQSTART_F
value|FW_EQ_CTRL_CMD_EQSTART_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQSTOP_S
value|27
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQSTOP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_EQSTOP_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQSTOP_F
value|FW_EQ_CTRL_CMD_EQSTOP_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_CMPLIQID_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_CMPLIQID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_CMPLIQID_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQID_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_EQID_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_EQ_CTRL_CMD_EQID_S)& FW_EQ_CTRL_CMD_EQID_M)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_PHYSEQID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_PHYSEQID_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_PHYSEQID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_EQ_CTRL_CMD_PHYSEQID_S)& FW_EQ_CTRL_CMD_PHYSEQID_M)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FETCHSZM_S
value|26
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FETCHSZM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_FETCHSZM_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FETCHSZM_F
value|FW_EQ_CTRL_CMD_FETCHSZM_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_STATUSPGNS_S
value|25
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_STATUSPGNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_STATUSPGNS_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_STATUSPGNS_F
value|FW_EQ_CTRL_CMD_STATUSPGNS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_STATUSPGRO_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_STATUSPGRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_STATUSPGRO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_STATUSPGRO_F
value|FW_EQ_CTRL_CMD_STATUSPGRO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FETCHNS_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FETCHNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_FETCHNS_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FETCHNS_F
value|FW_EQ_CTRL_CMD_FETCHNS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FETCHRO_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FETCHRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_FETCHRO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FETCHRO_F
value|FW_EQ_CTRL_CMD_FETCHRO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_HOSTFCMODE_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_HOSTFCMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_HOSTFCMODE_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_CPRIO_S
value|19
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_CPRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_CPRIO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_ONCHIP_S
value|18
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_ONCHIP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_ONCHIP_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_PCIECHN_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_PCIECHN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_PCIECHN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_IQID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_IQID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_IQID_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_DCAEN_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_DCAEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_DCAEN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_DCACPU_S
value|26
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_DCACPU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_DCACPU_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FBMIN_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FBMIN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_FBMIN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FBMAX_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_FBMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_FBMAX_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_CIDXFTHRESHO_S
value|19
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_CIDXFTHRESHO_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_EQ_CTRL_CMD_CIDXFTHRESHO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_CIDXFTHRESH_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_CIDXFTHRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_CIDXFTHRESH_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQSIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_CTRL_CMD_EQSIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_CTRL_CMD_EQSIZE_S)
end_define

begin_struct
struct|struct
name|fw_eq_ofld_cmd
block|{
name|__be32
name|op_to_vfn
decl_stmt|;
name|__be32
name|alloc_to_len16
decl_stmt|;
name|__be32
name|eqid_pkd
decl_stmt|;
name|__be32
name|physeqid_pkd
decl_stmt|;
name|__be32
name|fetchszm_to_iqid
decl_stmt|;
name|__be32
name|dcaen_to_eqsize
decl_stmt|;
name|__be64
name|eqaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_PFN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_PFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_PFN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_VFN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_VFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_VFN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_ALLOC_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_ALLOC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_ALLOC_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_ALLOC_F
value|FW_EQ_OFLD_CMD_ALLOC_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FREE_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FREE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_FREE_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FREE_F
value|FW_EQ_OFLD_CMD_FREE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_MODIFY_S
value|29
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_MODIFY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_MODIFY_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_MODIFY_F
value|FW_EQ_OFLD_CMD_MODIFY_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQSTART_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQSTART_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_EQSTART_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQSTART_F
value|FW_EQ_OFLD_CMD_EQSTART_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQSTOP_S
value|27
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQSTOP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_EQSTOP_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQSTOP_F
value|FW_EQ_OFLD_CMD_EQSTOP_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQID_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_EQID_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_EQ_OFLD_CMD_EQID_S)& FW_EQ_OFLD_CMD_EQID_M)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_PHYSEQID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_PHYSEQID_M
value|0xfffff
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_PHYSEQID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_EQ_OFLD_CMD_PHYSEQID_S)& FW_EQ_OFLD_CMD_PHYSEQID_M)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FETCHSZM_S
value|26
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FETCHSZM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_FETCHSZM_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_STATUSPGNS_S
value|25
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_STATUSPGNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_STATUSPGNS_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_STATUSPGRO_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_STATUSPGRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_STATUSPGRO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FETCHNS_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FETCHNS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_FETCHNS_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FETCHRO_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FETCHRO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_FETCHRO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FETCHRO_F
value|FW_EQ_OFLD_CMD_FETCHRO_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_HOSTFCMODE_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_HOSTFCMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_HOSTFCMODE_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_CPRIO_S
value|19
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_CPRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_CPRIO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_ONCHIP_S
value|18
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_ONCHIP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_ONCHIP_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_PCIECHN_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_PCIECHN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_PCIECHN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_IQID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_IQID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_IQID_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_DCAEN_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_DCAEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_DCAEN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_DCACPU_S
value|26
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_DCACPU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_DCACPU_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FBMIN_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FBMIN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_FBMIN_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FBMAX_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_FBMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_FBMAX_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_CIDXFTHRESHO_S
value|19
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_CIDXFTHRESHO_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_EQ_OFLD_CMD_CIDXFTHRESHO_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_CIDXFTHRESH_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_CIDXFTHRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_CIDXFTHRESH_S)
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQSIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_EQ_OFLD_CMD_EQSIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_EQ_OFLD_CMD_EQSIZE_S)
end_define

begin_comment
comment|/*  * Macros for VIID parsing:  * VIID - [10:8] PFN, [7] VI Valid, [6:0] VI number  */
end_comment

begin_define
define|#
directive|define
name|FW_VIID_PFN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_VIID_PFN_M
value|0x7
end_define

begin_define
define|#
directive|define
name|FW_VIID_PFN_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_VIID_PFN_S)& FW_VIID_PFN_M)
end_define

begin_define
define|#
directive|define
name|FW_VIID_VIVLD_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_VIID_VIVLD_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_VIID_VIVLD_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_VIID_VIVLD_S)& FW_VIID_VIVLD_M)
end_define

begin_define
define|#
directive|define
name|FW_VIID_VIN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_VIID_VIN_M
value|0x7F
end_define

begin_define
define|#
directive|define
name|FW_VIID_VIN_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_VIID_VIN_S)& FW_VIID_VIN_M)
end_define

begin_struct
struct|struct
name|fw_vi_cmd
block|{
name|__be32
name|op_to_vfn
decl_stmt|;
name|__be32
name|alloc_to_len16
decl_stmt|;
name|__be16
name|type_viid
decl_stmt|;
name|u8
name|mac
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|portid_pkd
decl_stmt|;
name|u8
name|nmac
decl_stmt|;
name|u8
name|nmac0
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|rsssize_pkd
decl_stmt|;
name|u8
name|nmac1
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|idsiiq_pkd
decl_stmt|;
name|u8
name|nmac2
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|idseiq_pkd
decl_stmt|;
name|u8
name|nmac3
index|[
literal|6
index|]
decl_stmt|;
name|__be64
name|r9
decl_stmt|;
name|__be64
name|r10
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_VI_CMD_PFN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_PFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_CMD_PFN_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_VFN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_VFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_CMD_VFN_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_ALLOC_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_ALLOC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_CMD_ALLOC_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_ALLOC_F
value|FW_VI_CMD_ALLOC_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_FREE_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_FREE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_CMD_FREE_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_FREE_F
value|FW_VI_CMD_FREE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_VIID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_VIID_M
value|0xfff
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_VIID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_CMD_VIID_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_VIID_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FW_VI_CMD_VIID_S)& FW_VI_CMD_VIID_M)
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_PORTID_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_PORTID_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_PORTID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_CMD_PORTID_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_PORTID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_VI_CMD_PORTID_S)& FW_VI_CMD_PORTID_M)
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_RSSSIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_RSSSIZE_M
value|0x7ff
end_define

begin_define
define|#
directive|define
name|FW_VI_CMD_RSSSIZE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_VI_CMD_RSSSIZE_S)& FW_VI_CMD_RSSSIZE_M)
end_define

begin_comment
comment|/* Special VI_MAC command index ids */
end_comment

begin_define
define|#
directive|define
name|FW_VI_MAC_ADD_MAC
value|0x3FF
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_ADD_PERSIST_MAC
value|0x3FE
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_MAC_BASED_FREE
value|0x3FD
end_define

begin_define
define|#
directive|define
name|FW_CLS_TCAM_NUM_ENTRIES
value|336
end_define

begin_enum
enum|enum
name|fw_vi_mac_smac
block|{
name|FW_VI_MAC_MPS_TCAM_ENTRY
block|,
name|FW_VI_MAC_MPS_TCAM_ONLY
block|,
name|FW_VI_MAC_SMT_ONLY
block|,
name|FW_VI_MAC_SMT_AND_MPSTCAM
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_vi_mac_result
block|{
name|FW_VI_MAC_R_SUCCESS
block|,
name|FW_VI_MAC_R_F_NONEXISTENT_NOMEM
block|,
name|FW_VI_MAC_R_SMAC_FAIL
block|,
name|FW_VI_MAC_R_F_ACL_CHECK
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fw_vi_mac_cmd
block|{
name|__be32
name|op_to_viid
decl_stmt|;
name|__be32
name|freemacs_to_len16
decl_stmt|;
union|union
name|fw_vi_mac
block|{
struct|struct
name|fw_vi_mac_exact
block|{
name|__be16
name|valid_to_idx
decl_stmt|;
name|u8
name|macaddr
index|[
literal|6
index|]
decl_stmt|;
block|}
name|exact
index|[
literal|7
index|]
struct|;
struct|struct
name|fw_vi_mac_hash
block|{
name|__be64
name|hashvec
decl_stmt|;
block|}
name|hash
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
name|FW_VI_MAC_CMD_VIID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_VIID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_MAC_CMD_VIID_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_FREEMACS_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_FREEMACS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_MAC_CMD_FREEMACS_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_HASHVECEN_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_HASHVECEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_MAC_CMD_HASHVECEN_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_HASHVECEN_F
value|FW_VI_MAC_CMD_HASHVECEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_HASHUNIEN_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_HASHUNIEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_MAC_CMD_HASHUNIEN_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_VALID_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_VALID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_MAC_CMD_VALID_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_VALID_F
value|FW_VI_MAC_CMD_VALID_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_PRIO_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_PRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_MAC_CMD_PRIO_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_SMAC_RESULT_S
value|10
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_SMAC_RESULT_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_SMAC_RESULT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_MAC_CMD_SMAC_RESULT_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_SMAC_RESULT_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_VI_MAC_CMD_SMAC_RESULT_S)& FW_VI_MAC_CMD_SMAC_RESULT_M)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_IDX_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_IDX_M
value|0x3ff
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_IDX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_MAC_CMD_IDX_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_MAC_CMD_IDX_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_VI_MAC_CMD_IDX_S)& FW_VI_MAC_CMD_IDX_M)
end_define

begin_define
define|#
directive|define
name|FW_RXMODE_MTU_NO_CHG
value|65535
end_define

begin_struct
struct|struct
name|fw_vi_rxmode_cmd
block|{
name|__be32
name|op_to_viid
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be32
name|mtu_to_vlanexen
decl_stmt|;
name|__be32
name|r4_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_VIID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_VIID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_RXMODE_CMD_VIID_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_MTU_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_MTU_M
value|0xffff
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_MTU_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_RXMODE_CMD_MTU_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_PROMISCEN_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_PROMISCEN_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_PROMISCEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_RXMODE_CMD_PROMISCEN_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_ALLMULTIEN_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_ALLMULTIEN_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_ALLMULTIEN_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_VI_RXMODE_CMD_ALLMULTIEN_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_BROADCASTEN_S
value|10
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_BROADCASTEN_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_BROADCASTEN_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_VI_RXMODE_CMD_BROADCASTEN_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_VLANEXEN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_VLANEXEN_M
value|0x3
end_define

begin_define
define|#
directive|define
name|FW_VI_RXMODE_CMD_VLANEXEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_RXMODE_CMD_VLANEXEN_S)
end_define

begin_struct
struct|struct
name|fw_vi_enable_cmd
block|{
name|__be32
name|op_to_viid
decl_stmt|;
name|__be32
name|ien_to_len16
decl_stmt|;
name|__be16
name|blinkdur
decl_stmt|;
name|__be16
name|r3
decl_stmt|;
name|__be32
name|r4
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_VIID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_VIID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_ENABLE_CMD_VIID_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_IEN_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_IEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_ENABLE_CMD_IEN_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_EEN_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_EEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_ENABLE_CMD_EEN_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_LED_S
value|29
end_define

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_LED_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_ENABLE_CMD_LED_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_LED_F
value|FW_VI_ENABLE_CMD_LED_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_DCB_INFO_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_VI_ENABLE_CMD_DCB_INFO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_ENABLE_CMD_DCB_INFO_S)
end_define

begin_comment
comment|/* VI VF stats offset definitions */
end_comment

begin_define
define|#
directive|define
name|VI_VF_NUM_STATS
value|16
end_define

begin_enum
enum|enum
name|fw_vi_stats_vf_index
block|{
name|FW_VI_VF_STAT_TX_BCAST_BYTES_IX
block|,
name|FW_VI_VF_STAT_TX_BCAST_FRAMES_IX
block|,
name|FW_VI_VF_STAT_TX_MCAST_BYTES_IX
block|,
name|FW_VI_VF_STAT_TX_MCAST_FRAMES_IX
block|,
name|FW_VI_VF_STAT_TX_UCAST_BYTES_IX
block|,
name|FW_VI_VF_STAT_TX_UCAST_FRAMES_IX
block|,
name|FW_VI_VF_STAT_TX_DROP_FRAMES_IX
block|,
name|FW_VI_VF_STAT_TX_OFLD_BYTES_IX
block|,
name|FW_VI_VF_STAT_TX_OFLD_FRAMES_IX
block|,
name|FW_VI_VF_STAT_RX_BCAST_BYTES_IX
block|,
name|FW_VI_VF_STAT_RX_BCAST_FRAMES_IX
block|,
name|FW_VI_VF_STAT_RX_MCAST_BYTES_IX
block|,
name|FW_VI_VF_STAT_RX_MCAST_FRAMES_IX
block|,
name|FW_VI_VF_STAT_RX_UCAST_BYTES_IX
block|,
name|FW_VI_VF_STAT_RX_UCAST_FRAMES_IX
block|,
name|FW_VI_VF_STAT_RX_ERR_FRAMES_IX
block|}
enum|;
end_enum

begin_comment
comment|/* VI PF stats offset definitions */
end_comment

begin_define
define|#
directive|define
name|VI_PF_NUM_STATS
value|17
end_define

begin_enum
enum|enum
name|fw_vi_stats_pf_index
block|{
name|FW_VI_PF_STAT_TX_BCAST_BYTES_IX
block|,
name|FW_VI_PF_STAT_TX_BCAST_FRAMES_IX
block|,
name|FW_VI_PF_STAT_TX_MCAST_BYTES_IX
block|,
name|FW_VI_PF_STAT_TX_MCAST_FRAMES_IX
block|,
name|FW_VI_PF_STAT_TX_UCAST_BYTES_IX
block|,
name|FW_VI_PF_STAT_TX_UCAST_FRAMES_IX
block|,
name|FW_VI_PF_STAT_TX_OFLD_BYTES_IX
block|,
name|FW_VI_PF_STAT_TX_OFLD_FRAMES_IX
block|,
name|FW_VI_PF_STAT_RX_BYTES_IX
block|,
name|FW_VI_PF_STAT_RX_FRAMES_IX
block|,
name|FW_VI_PF_STAT_RX_BCAST_BYTES_IX
block|,
name|FW_VI_PF_STAT_RX_BCAST_FRAMES_IX
block|,
name|FW_VI_PF_STAT_RX_MCAST_BYTES_IX
block|,
name|FW_VI_PF_STAT_RX_MCAST_FRAMES_IX
block|,
name|FW_VI_PF_STAT_RX_UCAST_BYTES_IX
block|,
name|FW_VI_PF_STAT_RX_UCAST_FRAMES_IX
block|,
name|FW_VI_PF_STAT_RX_ERR_FRAMES_IX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fw_vi_stats_cmd
block|{
name|__be32
name|op_to_viid
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
union|union
name|fw_vi_stats
block|{
struct|struct
name|fw_vi_stats_ctl
block|{
name|__be16
name|nstats_ix
decl_stmt|;
name|__be16
name|r6
decl_stmt|;
name|__be32
name|r7
decl_stmt|;
name|__be64
name|stat0
decl_stmt|;
name|__be64
name|stat1
decl_stmt|;
name|__be64
name|stat2
decl_stmt|;
name|__be64
name|stat3
decl_stmt|;
name|__be64
name|stat4
decl_stmt|;
name|__be64
name|stat5
decl_stmt|;
block|}
name|ctl
struct|;
struct|struct
name|fw_vi_stats_pf
block|{
name|__be64
name|tx_bcast_bytes
decl_stmt|;
name|__be64
name|tx_bcast_frames
decl_stmt|;
name|__be64
name|tx_mcast_bytes
decl_stmt|;
name|__be64
name|tx_mcast_frames
decl_stmt|;
name|__be64
name|tx_ucast_bytes
decl_stmt|;
name|__be64
name|tx_ucast_frames
decl_stmt|;
name|__be64
name|tx_offload_bytes
decl_stmt|;
name|__be64
name|tx_offload_frames
decl_stmt|;
name|__be64
name|rx_pf_bytes
decl_stmt|;
name|__be64
name|rx_pf_frames
decl_stmt|;
name|__be64
name|rx_bcast_bytes
decl_stmt|;
name|__be64
name|rx_bcast_frames
decl_stmt|;
name|__be64
name|rx_mcast_bytes
decl_stmt|;
name|__be64
name|rx_mcast_frames
decl_stmt|;
name|__be64
name|rx_ucast_bytes
decl_stmt|;
name|__be64
name|rx_ucast_frames
decl_stmt|;
name|__be64
name|rx_err_frames
decl_stmt|;
block|}
name|pf
struct|;
struct|struct
name|fw_vi_stats_vf
block|{
name|__be64
name|tx_bcast_bytes
decl_stmt|;
name|__be64
name|tx_bcast_frames
decl_stmt|;
name|__be64
name|tx_mcast_bytes
decl_stmt|;
name|__be64
name|tx_mcast_frames
decl_stmt|;
name|__be64
name|tx_ucast_bytes
decl_stmt|;
name|__be64
name|tx_ucast_frames
decl_stmt|;
name|__be64
name|tx_drop_frames
decl_stmt|;
name|__be64
name|tx_offload_bytes
decl_stmt|;
name|__be64
name|tx_offload_frames
decl_stmt|;
name|__be64
name|rx_bcast_bytes
decl_stmt|;
name|__be64
name|rx_bcast_frames
decl_stmt|;
name|__be64
name|rx_mcast_bytes
decl_stmt|;
name|__be64
name|rx_mcast_frames
decl_stmt|;
name|__be64
name|rx_ucast_bytes
decl_stmt|;
name|__be64
name|rx_ucast_frames
decl_stmt|;
name|__be64
name|rx_err_frames
decl_stmt|;
block|}
name|vf
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
name|FW_VI_STATS_CMD_VIID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_VI_STATS_CMD_VIID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_STATS_CMD_VIID_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_STATS_CMD_NSTATS_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_VI_STATS_CMD_NSTATS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_STATS_CMD_NSTATS_S)
end_define

begin_define
define|#
directive|define
name|FW_VI_STATS_CMD_IX_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_VI_STATS_CMD_IX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_VI_STATS_CMD_IX_S)
end_define

begin_struct
struct|struct
name|fw_acl_mac_cmd
block|{
name|__be32
name|op_to_vfn
decl_stmt|;
name|__be32
name|en_to_len16
decl_stmt|;
name|u8
name|nmac
decl_stmt|;
name|u8
name|r3
index|[
literal|7
index|]
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|u8
name|macaddr0
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|r5
decl_stmt|;
name|u8
name|macaddr1
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|r6
decl_stmt|;
name|u8
name|macaddr2
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|r7
decl_stmt|;
name|u8
name|macaddr3
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_ACL_MAC_CMD_PFN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_ACL_MAC_CMD_PFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_ACL_MAC_CMD_PFN_S)
end_define

begin_define
define|#
directive|define
name|FW_ACL_MAC_CMD_VFN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_ACL_MAC_CMD_VFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_ACL_MAC_CMD_VFN_S)
end_define

begin_define
define|#
directive|define
name|FW_ACL_MAC_CMD_EN_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_ACL_MAC_CMD_EN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_ACL_MAC_CMD_EN_S)
end_define

begin_struct
struct|struct
name|fw_acl_vlan_cmd
block|{
name|__be32
name|op_to_vfn
decl_stmt|;
name|__be32
name|en_to_len16
decl_stmt|;
name|u8
name|nvlan
decl_stmt|;
name|u8
name|dropnovlan_fm
decl_stmt|;
name|u8
name|r3_lo
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|vlanid
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_ACL_VLAN_CMD_PFN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_ACL_VLAN_CMD_PFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_ACL_VLAN_CMD_PFN_S)
end_define

begin_define
define|#
directive|define
name|FW_ACL_VLAN_CMD_VFN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_ACL_VLAN_CMD_VFN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_ACL_VLAN_CMD_VFN_S)
end_define

begin_define
define|#
directive|define
name|FW_ACL_VLAN_CMD_EN_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_ACL_VLAN_CMD_EN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_ACL_VLAN_CMD_EN_S)
end_define

begin_define
define|#
directive|define
name|FW_ACL_VLAN_CMD_DROPNOVLAN_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_ACL_VLAN_CMD_DROPNOVLAN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_ACL_VLAN_CMD_DROPNOVLAN_S)
end_define

begin_define
define|#
directive|define
name|FW_ACL_VLAN_CMD_FM_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_ACL_VLAN_CMD_FM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_ACL_VLAN_CMD_FM_S)
end_define

begin_enum
enum|enum
name|fw_port_cap
block|{
name|FW_PORT_CAP_SPEED_100M
init|=
literal|0x0001
block|,
name|FW_PORT_CAP_SPEED_1G
init|=
literal|0x0002
block|,
name|FW_PORT_CAP_SPEED_25G
init|=
literal|0x0004
block|,
name|FW_PORT_CAP_SPEED_10G
init|=
literal|0x0008
block|,
name|FW_PORT_CAP_SPEED_40G
init|=
literal|0x0010
block|,
name|FW_PORT_CAP_SPEED_100G
init|=
literal|0x0020
block|,
name|FW_PORT_CAP_FC_RX
init|=
literal|0x0040
block|,
name|FW_PORT_CAP_FC_TX
init|=
literal|0x0080
block|,
name|FW_PORT_CAP_ANEG
init|=
literal|0x0100
block|,
name|FW_PORT_CAP_MDIX
init|=
literal|0x0200
block|,
name|FW_PORT_CAP_MDIAUTO
init|=
literal|0x0400
block|,
name|FW_PORT_CAP_FEC
init|=
literal|0x0800
block|,
name|FW_PORT_CAP_TECHKR
init|=
literal|0x1000
block|,
name|FW_PORT_CAP_TECHKX4
init|=
literal|0x2000
block|,
name|FW_PORT_CAP_802_3_PAUSE
init|=
literal|0x4000
block|,
name|FW_PORT_CAP_802_3_ASM_DIR
init|=
literal|0x8000
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|FW_PORT_CAP_SPEED_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PORT_CAP_SPEED_M
value|0x3f
end_define

begin_define
define|#
directive|define
name|FW_PORT_CAP_SPEED_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CAP_SPEED_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CAP_SPEED_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PORT_CAP_SPEED_S)& FW_PORT_CAP_SPEED_M)
end_define

begin_enum
enum|enum
name|fw_port_mdi
block|{
name|FW_PORT_CAP_MDI_UNCHANGED
block|,
name|FW_PORT_CAP_MDI_AUTO
block|,
name|FW_PORT_CAP_MDI_F_STRAIGHT
block|,
name|FW_PORT_CAP_MDI_F_CROSSOVER
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|FW_PORT_CAP_MDI_S
value|9
end_define

begin_define
define|#
directive|define
name|FW_PORT_CAP_MDI_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CAP_MDI_S)
end_define

begin_enum
enum|enum
name|fw_port_action
block|{
name|FW_PORT_ACTION_L1_CFG
init|=
literal|0x0001
block|,
name|FW_PORT_ACTION_L2_CFG
init|=
literal|0x0002
block|,
name|FW_PORT_ACTION_GET_PORT_INFO
init|=
literal|0x0003
block|,
name|FW_PORT_ACTION_L2_PPP_CFG
init|=
literal|0x0004
block|,
name|FW_PORT_ACTION_L2_DCB_CFG
init|=
literal|0x0005
block|,
name|FW_PORT_ACTION_DCB_READ_TRANS
init|=
literal|0x0006
block|,
name|FW_PORT_ACTION_DCB_READ_RECV
init|=
literal|0x0007
block|,
name|FW_PORT_ACTION_DCB_READ_DET
init|=
literal|0x0008
block|,
name|FW_PORT_ACTION_LOW_PWR_TO_NORMAL
init|=
literal|0x0010
block|,
name|FW_PORT_ACTION_L1_LOW_PWR_EN
init|=
literal|0x0011
block|,
name|FW_PORT_ACTION_L2_WOL_MODE_EN
init|=
literal|0x0012
block|,
name|FW_PORT_ACTION_LPBK_TO_NORMAL
init|=
literal|0x0020
block|,
name|FW_PORT_ACTION_L1_LPBK
init|=
literal|0x0021
block|,
name|FW_PORT_ACTION_L1_PMA_LPBK
init|=
literal|0x0022
block|,
name|FW_PORT_ACTION_L1_PCS_LPBK
init|=
literal|0x0023
block|,
name|FW_PORT_ACTION_L1_PHYXS_CSIDE_LPBK
init|=
literal|0x0024
block|,
name|FW_PORT_ACTION_L1_PHYXS_ESIDE_LPBK
init|=
literal|0x0025
block|,
name|FW_PORT_ACTION_PHY_RESET
init|=
literal|0x0040
block|,
name|FW_PORT_ACTION_PMA_RESET
init|=
literal|0x0041
block|,
name|FW_PORT_ACTION_PCS_RESET
init|=
literal|0x0042
block|,
name|FW_PORT_ACTION_PHYXS_RESET
init|=
literal|0x0043
block|,
name|FW_PORT_ACTION_DTEXS_REEST
init|=
literal|0x0044
block|,
name|FW_PORT_ACTION_AN_RESET
init|=
literal|0x0045
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_port_l2cfg_ctlbf
block|{
name|FW_PORT_L2_CTLBF_OVLAN0
init|=
literal|0x01
block|,
name|FW_PORT_L2_CTLBF_OVLAN1
init|=
literal|0x02
block|,
name|FW_PORT_L2_CTLBF_OVLAN2
init|=
literal|0x04
block|,
name|FW_PORT_L2_CTLBF_OVLAN3
init|=
literal|0x08
block|,
name|FW_PORT_L2_CTLBF_IVLAN
init|=
literal|0x10
block|,
name|FW_PORT_L2_CTLBF_TXIPG
init|=
literal|0x20
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_port_dcb_versions
block|{
name|FW_PORT_DCB_VER_UNKNOWN
block|,
name|FW_PORT_DCB_VER_CEE1D0
block|,
name|FW_PORT_DCB_VER_CEE1D01
block|,
name|FW_PORT_DCB_VER_IEEE
block|,
name|FW_PORT_DCB_VER_AUTO
init|=
literal|7
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_port_dcb_cfg
block|{
name|FW_PORT_DCB_CFG_PG
init|=
literal|0x01
block|,
name|FW_PORT_DCB_CFG_PFC
init|=
literal|0x02
block|,
name|FW_PORT_DCB_CFG_APPL
init|=
literal|0x04
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_port_dcb_cfg_rc
block|{
name|FW_PORT_DCB_CFG_SUCCESS
init|=
literal|0x0
block|,
name|FW_PORT_DCB_CFG_ERROR
init|=
literal|0x1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_port_dcb_type
block|{
name|FW_PORT_DCB_TYPE_PGID
init|=
literal|0x00
block|,
name|FW_PORT_DCB_TYPE_PGRATE
init|=
literal|0x01
block|,
name|FW_PORT_DCB_TYPE_PRIORATE
init|=
literal|0x02
block|,
name|FW_PORT_DCB_TYPE_PFC
init|=
literal|0x03
block|,
name|FW_PORT_DCB_TYPE_APP_ID
init|=
literal|0x04
block|,
name|FW_PORT_DCB_TYPE_CONTROL
init|=
literal|0x05
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_port_dcb_feature_state
block|{
name|FW_PORT_DCB_FEATURE_STATE_PENDING
init|=
literal|0x0
block|,
name|FW_PORT_DCB_FEATURE_STATE_SUCCESS
init|=
literal|0x1
block|,
name|FW_PORT_DCB_FEATURE_STATE_ERROR
init|=
literal|0x2
block|,
name|FW_PORT_DCB_FEATURE_STATE_TIMEOUT
init|=
literal|0x3
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_port_cmd
block|{
name|__be32
name|op_to_portid
decl_stmt|;
name|__be32
name|action_to_len16
decl_stmt|;
union|union
name|fw_port
block|{
struct|struct
name|fw_port_l1cfg
block|{
name|__be32
name|rcap
decl_stmt|;
name|__be32
name|r
decl_stmt|;
block|}
name|l1cfg
struct|;
struct|struct
name|fw_port_l2cfg
block|{
name|__u8
name|ctlbf
decl_stmt|;
name|__u8
name|ovlan3_to_ivlan0
decl_stmt|;
name|__be16
name|ivlantype
decl_stmt|;
name|__be16
name|txipg_force_pinfo
decl_stmt|;
name|__be16
name|mtu
decl_stmt|;
name|__be16
name|ovlan0mask
decl_stmt|;
name|__be16
name|ovlan0type
decl_stmt|;
name|__be16
name|ovlan1mask
decl_stmt|;
name|__be16
name|ovlan1type
decl_stmt|;
name|__be16
name|ovlan2mask
decl_stmt|;
name|__be16
name|ovlan2type
decl_stmt|;
name|__be16
name|ovlan3mask
decl_stmt|;
name|__be16
name|ovlan3type
decl_stmt|;
block|}
name|l2cfg
struct|;
struct|struct
name|fw_port_info
block|{
name|__be32
name|lstatus_to_modtype
decl_stmt|;
name|__be16
name|pcap
decl_stmt|;
name|__be16
name|acap
decl_stmt|;
name|__be16
name|mtu
decl_stmt|;
name|__u8
name|cbllen
decl_stmt|;
name|__u8
name|auxlinfo
decl_stmt|;
name|__u8
name|dcbxdis_pkd
decl_stmt|;
name|__u8
name|r8_lo
decl_stmt|;
name|__be16
name|lpacap
decl_stmt|;
name|__be64
name|r9
decl_stmt|;
block|}
name|info
struct|;
struct|struct
name|fw_port_diags
block|{
name|__u8
name|diagop
decl_stmt|;
name|__u8
name|r
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|diagval
decl_stmt|;
block|}
name|diags
struct|;
union|union
name|fw_port_dcb
block|{
struct|struct
name|fw_port_dcb_pgid
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|apply_pkd
decl_stmt|;
name|__u8
name|r10_lo
index|[
literal|2
index|]
decl_stmt|;
name|__be32
name|pgid
decl_stmt|;
name|__be64
name|r11
decl_stmt|;
block|}
name|pgid
struct|;
struct|struct
name|fw_port_dcb_pgrate
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|apply_pkd
decl_stmt|;
name|__u8
name|r10_lo
index|[
literal|5
index|]
decl_stmt|;
name|__u8
name|num_tcs_supported
decl_stmt|;
name|__u8
name|pgrate
index|[
literal|8
index|]
decl_stmt|;
name|__u8
name|tsa
index|[
literal|8
index|]
decl_stmt|;
block|}
name|pgrate
struct|;
struct|struct
name|fw_port_dcb_priorate
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|apply_pkd
decl_stmt|;
name|__u8
name|r10_lo
index|[
literal|6
index|]
decl_stmt|;
name|__u8
name|strict_priorate
index|[
literal|8
index|]
decl_stmt|;
block|}
name|priorate
struct|;
struct|struct
name|fw_port_dcb_pfc
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|pfcen
decl_stmt|;
name|__u8
name|r10
index|[
literal|5
index|]
decl_stmt|;
name|__u8
name|max_pfc_tcs
decl_stmt|;
name|__be64
name|r11
decl_stmt|;
block|}
name|pfc
struct|;
struct|struct
name|fw_port_app_priority
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|r10
index|[
literal|2
index|]
decl_stmt|;
name|__u8
name|idx
decl_stmt|;
name|__u8
name|user_prio_map
decl_stmt|;
name|__u8
name|sel_field
decl_stmt|;
name|__be16
name|protocolid
decl_stmt|;
name|__be64
name|r12
decl_stmt|;
block|}
name|app_priority
struct|;
struct|struct
name|fw_port_dcb_control
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|all_syncd_pkd
decl_stmt|;
name|__be16
name|dcb_version_to_app_state
decl_stmt|;
name|__be32
name|r11
decl_stmt|;
name|__be64
name|r12
decl_stmt|;
block|}
name|control
struct|;
block|}
name|dcb
union|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_PORT_CMD_READ_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_READ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_READ_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_READ_F
value|FW_PORT_CMD_READ_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_PORTID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_PORTID_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_PORTID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_PORTID_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_PORTID_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PORT_CMD_PORTID_S)& FW_PORT_CMD_PORTID_M)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_ACTION_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_ACTION_M
value|0xffff
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_ACTION_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_ACTION_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_ACTION_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PORT_CMD_ACTION_S)& FW_PORT_CMD_ACTION_M)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_OVLAN3_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_OVLAN3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_OVLAN3_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_OVLAN2_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_OVLAN2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_OVLAN2_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_OVLAN1_S
value|5
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_OVLAN1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_OVLAN1_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_OVLAN0_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_OVLAN0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_OVLAN0_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_IVLAN0_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_IVLAN0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_IVLAN0_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_TXIPG_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_TXIPG_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_TXIPG_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LSTATUS_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LSTATUS_M
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LSTATUS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_LSTATUS_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LSTATUS_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PORT_CMD_LSTATUS_S)& FW_PORT_CMD_LSTATUS_M)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LSTATUS_F
value|FW_PORT_CMD_LSTATUS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LSPEED_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LSPEED_M
value|0x3f
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LSPEED_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_LSPEED_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LSPEED_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PORT_CMD_LSPEED_S)& FW_PORT_CMD_LSPEED_M)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_TXPAUSE_S
value|23
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_TXPAUSE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_TXPAUSE_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_TXPAUSE_F
value|FW_PORT_CMD_TXPAUSE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_RXPAUSE_S
value|22
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_RXPAUSE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_RXPAUSE_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_RXPAUSE_F
value|FW_PORT_CMD_RXPAUSE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_MDIOCAP_S
value|21
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_MDIOCAP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_MDIOCAP_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_MDIOCAP_F
value|FW_PORT_CMD_MDIOCAP_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_MDIOADDR_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_MDIOADDR_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_MDIOADDR_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PORT_CMD_MDIOADDR_S)& FW_PORT_CMD_MDIOADDR_M)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LPTXPAUSE_S
value|15
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LPTXPAUSE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_LPTXPAUSE_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LPTXPAUSE_F
value|FW_PORT_CMD_LPTXPAUSE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LPRXPAUSE_S
value|14
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LPRXPAUSE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_LPRXPAUSE_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LPRXPAUSE_F
value|FW_PORT_CMD_LPRXPAUSE_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_PTYPE_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_PTYPE_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_PTYPE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PORT_CMD_PTYPE_S)& FW_PORT_CMD_PTYPE_M)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LINKDNRC_S
value|5
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LINKDNRC_M
value|0x7
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_LINKDNRC_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PORT_CMD_LINKDNRC_S)& FW_PORT_CMD_LINKDNRC_M)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_MODTYPE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_MODTYPE_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_MODTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_MODTYPE_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_MODTYPE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PORT_CMD_MODTYPE_S)& FW_PORT_CMD_MODTYPE_M)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_DCBXDIS_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_DCBXDIS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_DCBXDIS_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_DCBXDIS_F
value|FW_PORT_CMD_DCBXDIS_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_APPLY_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_APPLY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_APPLY_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_APPLY_F
value|FW_PORT_CMD_APPLY_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_ALL_SYNCD_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_ALL_SYNCD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_PORT_CMD_ALL_SYNCD_S)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_ALL_SYNCD_F
value|FW_PORT_CMD_ALL_SYNCD_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_DCB_VERSION_S
value|12
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_DCB_VERSION_M
value|0x7
end_define

begin_define
define|#
directive|define
name|FW_PORT_CMD_DCB_VERSION_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_PORT_CMD_DCB_VERSION_S)& FW_PORT_CMD_DCB_VERSION_M)
end_define

begin_enum
enum|enum
name|fw_port_type
block|{
name|FW_PORT_TYPE_FIBER_XFI
block|,
name|FW_PORT_TYPE_FIBER_XAUI
block|,
name|FW_PORT_TYPE_BT_SGMII
block|,
name|FW_PORT_TYPE_BT_XFI
block|,
name|FW_PORT_TYPE_BT_XAUI
block|,
name|FW_PORT_TYPE_KX4
block|,
name|FW_PORT_TYPE_CX4
block|,
name|FW_PORT_TYPE_KX
block|,
name|FW_PORT_TYPE_KR
block|,
name|FW_PORT_TYPE_SFP
block|,
name|FW_PORT_TYPE_BP_AP
block|,
name|FW_PORT_TYPE_BP4_AP
block|,
name|FW_PORT_TYPE_QSFP_10G
block|,
name|FW_PORT_TYPE_QSA
block|,
name|FW_PORT_TYPE_QSFP
block|,
name|FW_PORT_TYPE_BP40_BA
block|,
name|FW_PORT_TYPE_KR4_100G
block|,
name|FW_PORT_TYPE_CR4_QSFP
block|,
name|FW_PORT_TYPE_CR_QSFP
block|,
name|FW_PORT_TYPE_CR2_QSFP
block|,
name|FW_PORT_TYPE_SFP28
block|,
name|FW_PORT_TYPE_NONE
init|=
name|FW_PORT_CMD_PTYPE_M
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_port_module_type
block|{
name|FW_PORT_MOD_TYPE_NA
block|,
name|FW_PORT_MOD_TYPE_LR
block|,
name|FW_PORT_MOD_TYPE_SR
block|,
name|FW_PORT_MOD_TYPE_ER
block|,
name|FW_PORT_MOD_TYPE_TWINAX_PASSIVE
block|,
name|FW_PORT_MOD_TYPE_TWINAX_ACTIVE
block|,
name|FW_PORT_MOD_TYPE_LRM
block|,
name|FW_PORT_MOD_TYPE_ERROR
init|=
name|FW_PORT_CMD_MODTYPE_M
operator|-
literal|3
block|,
name|FW_PORT_MOD_TYPE_UNKNOWN
init|=
name|FW_PORT_CMD_MODTYPE_M
operator|-
literal|2
block|,
name|FW_PORT_MOD_TYPE_NOTSUPPORTED
init|=
name|FW_PORT_CMD_MODTYPE_M
operator|-
literal|1
block|,
name|FW_PORT_MOD_TYPE_NONE
init|=
name|FW_PORT_CMD_MODTYPE_M
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_port_mod_sub_type
block|{
name|FW_PORT_MOD_SUB_TYPE_NA
block|,
name|FW_PORT_MOD_SUB_TYPE_MV88E114X
init|=
literal|0x1
block|,
name|FW_PORT_MOD_SUB_TYPE_TN8022
init|=
literal|0x2
block|,
name|FW_PORT_MOD_SUB_TYPE_AQ1202
init|=
literal|0x3
block|,
name|FW_PORT_MOD_SUB_TYPE_88x3120
init|=
literal|0x4
block|,
name|FW_PORT_MOD_SUB_TYPE_BCM84834
init|=
literal|0x5
block|,
name|FW_PORT_MOD_SUB_TYPE_BT_VSC8634
init|=
literal|0x8
block|,
comment|/* The following will never been in the VPD.  They are TWINAX cable 	 * lengths decoded from SFP+ module i2c PROMs.  These should 	 * almost certainly go somewhere else ... 	 */
name|FW_PORT_MOD_SUB_TYPE_TWINAX_1
init|=
literal|0x9
block|,
name|FW_PORT_MOD_SUB_TYPE_TWINAX_3
init|=
literal|0xA
block|,
name|FW_PORT_MOD_SUB_TYPE_TWINAX_5
init|=
literal|0xB
block|,
name|FW_PORT_MOD_SUB_TYPE_TWINAX_7
init|=
literal|0xC
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_port_stats_tx_index
block|{
name|FW_STAT_TX_PORT_BYTES_IX
init|=
literal|0
block|,
name|FW_STAT_TX_PORT_FRAMES_IX
block|,
name|FW_STAT_TX_PORT_BCAST_IX
block|,
name|FW_STAT_TX_PORT_MCAST_IX
block|,
name|FW_STAT_TX_PORT_UCAST_IX
block|,
name|FW_STAT_TX_PORT_ERROR_IX
block|,
name|FW_STAT_TX_PORT_64B_IX
block|,
name|FW_STAT_TX_PORT_65B_127B_IX
block|,
name|FW_STAT_TX_PORT_128B_255B_IX
block|,
name|FW_STAT_TX_PORT_256B_511B_IX
block|,
name|FW_STAT_TX_PORT_512B_1023B_IX
block|,
name|FW_STAT_TX_PORT_1024B_1518B_IX
block|,
name|FW_STAT_TX_PORT_1519B_MAX_IX
block|,
name|FW_STAT_TX_PORT_DROP_IX
block|,
name|FW_STAT_TX_PORT_PAUSE_IX
block|,
name|FW_STAT_TX_PORT_PPP0_IX
block|,
name|FW_STAT_TX_PORT_PPP1_IX
block|,
name|FW_STAT_TX_PORT_PPP2_IX
block|,
name|FW_STAT_TX_PORT_PPP3_IX
block|,
name|FW_STAT_TX_PORT_PPP4_IX
block|,
name|FW_STAT_TX_PORT_PPP5_IX
block|,
name|FW_STAT_TX_PORT_PPP6_IX
block|,
name|FW_STAT_TX_PORT_PPP7_IX
block|,
name|FW_NUM_PORT_TX_STATS
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_port_stat_rx_index
block|{
name|FW_STAT_RX_PORT_BYTES_IX
init|=
literal|0
block|,
name|FW_STAT_RX_PORT_FRAMES_IX
block|,
name|FW_STAT_RX_PORT_BCAST_IX
block|,
name|FW_STAT_RX_PORT_MCAST_IX
block|,
name|FW_STAT_RX_PORT_UCAST_IX
block|,
name|FW_STAT_RX_PORT_MTU_ERROR_IX
block|,
name|FW_STAT_RX_PORT_MTU_CRC_ERROR_IX
block|,
name|FW_STAT_RX_PORT_CRC_ERROR_IX
block|,
name|FW_STAT_RX_PORT_LEN_ERROR_IX
block|,
name|FW_STAT_RX_PORT_SYM_ERROR_IX
block|,
name|FW_STAT_RX_PORT_64B_IX
block|,
name|FW_STAT_RX_PORT_65B_127B_IX
block|,
name|FW_STAT_RX_PORT_128B_255B_IX
block|,
name|FW_STAT_RX_PORT_256B_511B_IX
block|,
name|FW_STAT_RX_PORT_512B_1023B_IX
block|,
name|FW_STAT_RX_PORT_1024B_1518B_IX
block|,
name|FW_STAT_RX_PORT_1519B_MAX_IX
block|,
name|FW_STAT_RX_PORT_PAUSE_IX
block|,
name|FW_STAT_RX_PORT_PPP0_IX
block|,
name|FW_STAT_RX_PORT_PPP1_IX
block|,
name|FW_STAT_RX_PORT_PPP2_IX
block|,
name|FW_STAT_RX_PORT_PPP3_IX
block|,
name|FW_STAT_RX_PORT_PPP4_IX
block|,
name|FW_STAT_RX_PORT_PPP5_IX
block|,
name|FW_STAT_RX_PORT_PPP6_IX
block|,
name|FW_STAT_RX_PORT_PPP7_IX
block|,
name|FW_STAT_RX_PORT_LESS_64B_IX
block|,
name|FW_STAT_RX_PORT_MAC_ERROR_IX
block|,
name|FW_NUM_PORT_RX_STATS
block|}
enum|;
end_enum

begin_comment
comment|/* port stats */
end_comment

begin_define
define|#
directive|define
name|FW_NUM_PORT_STATS
value|(FW_NUM_PORT_TX_STATS + FW_NUM_PORT_RX_STATS)
end_define

begin_struct
struct|struct
name|fw_port_stats_cmd
block|{
name|__be32
name|op_to_portid
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
union|union
name|fw_port_stats
block|{
struct|struct
name|fw_port_stats_ctl
block|{
name|u8
name|nstats_bg_bm
decl_stmt|;
name|u8
name|tx_ix
decl_stmt|;
name|__be16
name|r6
decl_stmt|;
name|__be32
name|r7
decl_stmt|;
name|__be64
name|stat0
decl_stmt|;
name|__be64
name|stat1
decl_stmt|;
name|__be64
name|stat2
decl_stmt|;
name|__be64
name|stat3
decl_stmt|;
name|__be64
name|stat4
decl_stmt|;
name|__be64
name|stat5
decl_stmt|;
block|}
name|ctl
struct|;
struct|struct
name|fw_port_stats_all
block|{
name|__be64
name|tx_bytes
decl_stmt|;
name|__be64
name|tx_frames
decl_stmt|;
name|__be64
name|tx_bcast
decl_stmt|;
name|__be64
name|tx_mcast
decl_stmt|;
name|__be64
name|tx_ucast
decl_stmt|;
name|__be64
name|tx_error
decl_stmt|;
name|__be64
name|tx_64b
decl_stmt|;
name|__be64
name|tx_65b_127b
decl_stmt|;
name|__be64
name|tx_128b_255b
decl_stmt|;
name|__be64
name|tx_256b_511b
decl_stmt|;
name|__be64
name|tx_512b_1023b
decl_stmt|;
name|__be64
name|tx_1024b_1518b
decl_stmt|;
name|__be64
name|tx_1519b_max
decl_stmt|;
name|__be64
name|tx_drop
decl_stmt|;
name|__be64
name|tx_pause
decl_stmt|;
name|__be64
name|tx_ppp0
decl_stmt|;
name|__be64
name|tx_ppp1
decl_stmt|;
name|__be64
name|tx_ppp2
decl_stmt|;
name|__be64
name|tx_ppp3
decl_stmt|;
name|__be64
name|tx_ppp4
decl_stmt|;
name|__be64
name|tx_ppp5
decl_stmt|;
name|__be64
name|tx_ppp6
decl_stmt|;
name|__be64
name|tx_ppp7
decl_stmt|;
name|__be64
name|rx_bytes
decl_stmt|;
name|__be64
name|rx_frames
decl_stmt|;
name|__be64
name|rx_bcast
decl_stmt|;
name|__be64
name|rx_mcast
decl_stmt|;
name|__be64
name|rx_ucast
decl_stmt|;
name|__be64
name|rx_mtu_error
decl_stmt|;
name|__be64
name|rx_mtu_crc_error
decl_stmt|;
name|__be64
name|rx_crc_error
decl_stmt|;
name|__be64
name|rx_len_error
decl_stmt|;
name|__be64
name|rx_sym_error
decl_stmt|;
name|__be64
name|rx_64b
decl_stmt|;
name|__be64
name|rx_65b_127b
decl_stmt|;
name|__be64
name|rx_128b_255b
decl_stmt|;
name|__be64
name|rx_256b_511b
decl_stmt|;
name|__be64
name|rx_512b_1023b
decl_stmt|;
name|__be64
name|rx_1024b_1518b
decl_stmt|;
name|__be64
name|rx_1519b_max
decl_stmt|;
name|__be64
name|rx_pause
decl_stmt|;
name|__be64
name|rx_ppp0
decl_stmt|;
name|__be64
name|rx_ppp1
decl_stmt|;
name|__be64
name|rx_ppp2
decl_stmt|;
name|__be64
name|rx_ppp3
decl_stmt|;
name|__be64
name|rx_ppp4
decl_stmt|;
name|__be64
name|rx_ppp5
decl_stmt|;
name|__be64
name|rx_ppp6
decl_stmt|;
name|__be64
name|rx_ppp7
decl_stmt|;
name|__be64
name|rx_less_64b
decl_stmt|;
name|__be64
name|rx_bg_drop
decl_stmt|;
name|__be64
name|rx_bg_trunc
decl_stmt|;
block|}
name|all
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* port loopback stats */
end_comment

begin_define
define|#
directive|define
name|FW_NUM_LB_STATS
value|16
end_define

begin_enum
enum|enum
name|fw_port_lb_stats_index
block|{
name|FW_STAT_LB_PORT_BYTES_IX
block|,
name|FW_STAT_LB_PORT_FRAMES_IX
block|,
name|FW_STAT_LB_PORT_BCAST_IX
block|,
name|FW_STAT_LB_PORT_MCAST_IX
block|,
name|FW_STAT_LB_PORT_UCAST_IX
block|,
name|FW_STAT_LB_PORT_ERROR_IX
block|,
name|FW_STAT_LB_PORT_64B_IX
block|,
name|FW_STAT_LB_PORT_65B_127B_IX
block|,
name|FW_STAT_LB_PORT_128B_255B_IX
block|,
name|FW_STAT_LB_PORT_256B_511B_IX
block|,
name|FW_STAT_LB_PORT_512B_1023B_IX
block|,
name|FW_STAT_LB_PORT_1024B_1518B_IX
block|,
name|FW_STAT_LB_PORT_1519B_MAX_IX
block|,
name|FW_STAT_LB_PORT_DROP_FRAMES_IX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fw_port_lb_stats_cmd
block|{
name|__be32
name|op_to_lbport
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
union|union
name|fw_port_lb_stats
block|{
struct|struct
name|fw_port_lb_stats_ctl
block|{
name|u8
name|nstats_bg_bm
decl_stmt|;
name|u8
name|ix_pkd
decl_stmt|;
name|__be16
name|r6
decl_stmt|;
name|__be32
name|r7
decl_stmt|;
name|__be64
name|stat0
decl_stmt|;
name|__be64
name|stat1
decl_stmt|;
name|__be64
name|stat2
decl_stmt|;
name|__be64
name|stat3
decl_stmt|;
name|__be64
name|stat4
decl_stmt|;
name|__be64
name|stat5
decl_stmt|;
block|}
name|ctl
struct|;
struct|struct
name|fw_port_lb_stats_all
block|{
name|__be64
name|tx_bytes
decl_stmt|;
name|__be64
name|tx_frames
decl_stmt|;
name|__be64
name|tx_bcast
decl_stmt|;
name|__be64
name|tx_mcast
decl_stmt|;
name|__be64
name|tx_ucast
decl_stmt|;
name|__be64
name|tx_error
decl_stmt|;
name|__be64
name|tx_64b
decl_stmt|;
name|__be64
name|tx_65b_127b
decl_stmt|;
name|__be64
name|tx_128b_255b
decl_stmt|;
name|__be64
name|tx_256b_511b
decl_stmt|;
name|__be64
name|tx_512b_1023b
decl_stmt|;
name|__be64
name|tx_1024b_1518b
decl_stmt|;
name|__be64
name|tx_1519b_max
decl_stmt|;
name|__be64
name|rx_lb_drop
decl_stmt|;
name|__be64
name|rx_lb_trunc
decl_stmt|;
block|}
name|all
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_rss_ind_tbl_cmd
block|{
name|__be32
name|op_to_viid
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be16
name|niqid
decl_stmt|;
name|__be16
name|startidx
decl_stmt|;
name|__be32
name|r3
decl_stmt|;
name|__be32
name|iq0_to_iq2
decl_stmt|;
name|__be32
name|iq3_to_iq5
decl_stmt|;
name|__be32
name|iq6_to_iq8
decl_stmt|;
name|__be32
name|iq9_to_iq11
decl_stmt|;
name|__be32
name|iq12_to_iq14
decl_stmt|;
name|__be32
name|iq15_to_iq17
decl_stmt|;
name|__be32
name|iq18_to_iq20
decl_stmt|;
name|__be32
name|iq21_to_iq23
decl_stmt|;
name|__be32
name|iq24_to_iq26
decl_stmt|;
name|__be32
name|iq27_to_iq29
decl_stmt|;
name|__be32
name|iq30_iq31
decl_stmt|;
name|__be32
name|r15_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_RSS_IND_TBL_CMD_VIID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RSS_IND_TBL_CMD_VIID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RSS_IND_TBL_CMD_VIID_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_IND_TBL_CMD_IQ0_S
value|20
end_define

begin_define
define|#
directive|define
name|FW_RSS_IND_TBL_CMD_IQ0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RSS_IND_TBL_CMD_IQ0_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_IND_TBL_CMD_IQ1_S
value|10
end_define

begin_define
define|#
directive|define
name|FW_RSS_IND_TBL_CMD_IQ1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RSS_IND_TBL_CMD_IQ1_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_IND_TBL_CMD_IQ2_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RSS_IND_TBL_CMD_IQ2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RSS_IND_TBL_CMD_IQ2_S)
end_define

begin_struct
struct|struct
name|fw_rss_glb_config_cmd
block|{
name|__be32
name|op_to_write
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
union|union
name|fw_rss_glb_config
block|{
struct|struct
name|fw_rss_glb_config_manual
block|{
name|__be32
name|mode_pkd
decl_stmt|;
name|__be32
name|r3
decl_stmt|;
name|__be64
name|r4
decl_stmt|;
name|__be64
name|r5
decl_stmt|;
block|}
name|manual
struct|;
struct|struct
name|fw_rss_glb_config_basicvirtual
block|{
name|__be32
name|mode_pkd
decl_stmt|;
name|__be32
name|synmapen_to_hashtoeplitz
decl_stmt|;
name|__be64
name|r8
decl_stmt|;
name|__be64
name|r9
decl_stmt|;
block|}
name|basicvirtual
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
name|FW_RSS_GLB_CONFIG_CMD_MODE_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_MODE_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_MODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RSS_GLB_CONFIG_CMD_MODE_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_MODE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RSS_GLB_CONFIG_CMD_MODE_S)& FW_RSS_GLB_CONFIG_CMD_MODE_M)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_MODE_MANUAL
value|0
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_MODE_BASICVIRTUAL
value|1
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYNMAPEN_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYNMAPEN_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_GLB_CONFIG_CMD_SYNMAPEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYNMAPEN_F
define|\
value|FW_RSS_GLB_CONFIG_CMD_SYNMAPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6_S
value|7
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6_F
define|\
value|FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6_S
value|6
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6_F
define|\
value|FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4_S
value|5
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4_F
define|\
value|FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4_F
define|\
value|FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_OFDMAPEN_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_OFDMAPEN_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_GLB_CONFIG_CMD_OFDMAPEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_OFDMAPEN_F
define|\
value|FW_RSS_GLB_CONFIG_CMD_OFDMAPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_TNLMAPEN_S
value|2
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_TNLMAPEN_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_GLB_CONFIG_CMD_TNLMAPEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_TNLMAPEN_F
define|\
value|FW_RSS_GLB_CONFIG_CMD_TNLMAPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_TNLALLLKP_S
value|1
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_TNLALLLKP_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_GLB_CONFIG_CMD_TNLALLLKP_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_TNLALLLKP_F
define|\
value|FW_RSS_GLB_CONFIG_CMD_TNLALLLKP_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ_F
define|\
value|FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ_V(1U)
end_define

begin_struct
struct|struct
name|fw_rss_vi_config_cmd
block|{
name|__be32
name|op_to_viid
decl_stmt|;
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_VIID
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
name|__be32
name|retval_len16
decl_stmt|;
union|union
name|fw_rss_vi_config
block|{
struct|struct
name|fw_rss_vi_config_manual
block|{
name|__be64
name|r3
decl_stmt|;
name|__be64
name|r4
decl_stmt|;
name|__be64
name|r5
decl_stmt|;
block|}
name|manual
struct|;
struct|struct
name|fw_rss_vi_config_basicvirtual
block|{
name|__be32
name|r6
decl_stmt|;
name|__be32
name|defaultq_to_udpen
decl_stmt|;
name|__be64
name|r9
decl_stmt|;
name|__be64
name|r10
decl_stmt|;
block|}
name|basicvirtual
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
name|FW_RSS_VI_CONFIG_CMD_VIID_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_VIID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RSS_VI_CONFIG_CMD_VIID_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_DEFAULTQ_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_DEFAULTQ_M
value|0x3ff
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_DEFAULTQ_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_VI_CONFIG_CMD_DEFAULTQ_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_DEFAULTQ_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_RSS_VI_CONFIG_CMD_DEFAULTQ_S)& \ 	 FW_RSS_VI_CONFIG_CMD_DEFAULTQ_M)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN_S
value|4
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN_F
define|\
value|FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_S
value|3
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_F
define|\
value|FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN_S
value|2
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN_F
define|\
value|FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_S
value|1
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_F
define|\
value|FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_UDPEN_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_UDPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_RSS_VI_CONFIG_CMD_UDPEN_S)
end_define

begin_define
define|#
directive|define
name|FW_RSS_VI_CONFIG_CMD_UDPEN_F
value|FW_RSS_VI_CONFIG_CMD_UDPEN_V(1U)
end_define

begin_struct
struct|struct
name|fw_clip_cmd
block|{
name|__be32
name|op_to_write
decl_stmt|;
name|__be32
name|alloc_to_len16
decl_stmt|;
name|__be64
name|ip_hi
decl_stmt|;
name|__be64
name|ip_lo
decl_stmt|;
name|__be32
name|r4
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_CLIP_CMD_ALLOC_S
value|31
end_define

begin_define
define|#
directive|define
name|FW_CLIP_CMD_ALLOC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CLIP_CMD_ALLOC_S)
end_define

begin_define
define|#
directive|define
name|FW_CLIP_CMD_ALLOC_F
value|FW_CLIP_CMD_ALLOC_V(1U)
end_define

begin_define
define|#
directive|define
name|FW_CLIP_CMD_FREE_S
value|30
end_define

begin_define
define|#
directive|define
name|FW_CLIP_CMD_FREE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FW_CLIP_CMD_FREE_S)
end_define

begin_define
define|#
directive|define
name|FW_CLIP_CMD_FREE_F
value|FW_CLIP_CMD_FREE_V(1U)
end_define

begin_enum
enum|enum
name|fw_error_type
block|{
name|FW_ERROR_TYPE_EXCEPTION
init|=
literal|0x0
block|,
name|FW_ERROR_TYPE_HWMODULE
init|=
literal|0x1
block|,
name|FW_ERROR_TYPE_WR
init|=
literal|0x2
block|,
name|FW_ERROR_TYPE_ACL
init|=
literal|0x3
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_error_cmd
block|{
name|__be32
name|op_to_type
decl_stmt|;
name|__be32
name|len16_pkd
decl_stmt|;
union|union
name|fw_error
block|{
struct|struct
name|fw_error_exception
block|{
name|__be32
name|info
index|[
literal|6
index|]
decl_stmt|;
block|}
name|exception
struct|;
struct|struct
name|fw_error_hwmodule
block|{
name|__be32
name|regaddr
decl_stmt|;
name|__be32
name|regval
decl_stmt|;
block|}
name|hwmodule
struct|;
struct|struct
name|fw_error_wr
block|{
name|__be16
name|cidx
decl_stmt|;
name|__be16
name|pfn_vfn
decl_stmt|;
name|__be32
name|eqid
decl_stmt|;
name|u8
name|wrhdr
index|[
literal|16
index|]
decl_stmt|;
block|}
name|wr
struct|;
struct|struct
name|fw_error_acl
block|{
name|__be16
name|cidx
decl_stmt|;
name|__be16
name|pfn_vfn
decl_stmt|;
name|__be32
name|eqid
decl_stmt|;
name|__be16
name|mv_pkd
decl_stmt|;
name|u8
name|val
index|[
literal|6
index|]
decl_stmt|;
name|__be64
name|r4
decl_stmt|;
block|}
name|acl
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_debug_cmd
block|{
name|__be32
name|op_type
decl_stmt|;
name|__be32
name|len16_pkd
decl_stmt|;
union|union
name|fw_debug
block|{
struct|struct
name|fw_debug_assert
block|{
name|__be32
name|fcid
decl_stmt|;
name|__be32
name|line
decl_stmt|;
name|__be32
name|x
decl_stmt|;
name|__be32
name|y
decl_stmt|;
name|u8
name|filename_0_7
index|[
literal|8
index|]
decl_stmt|;
name|u8
name|filename_8_15
index|[
literal|8
index|]
decl_stmt|;
name|__be64
name|r3
decl_stmt|;
block|}
name|assert
struct|;
struct|struct
name|fw_debug_prt
block|{
name|__be16
name|dprtstridx
decl_stmt|;
name|__be16
name|r3
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|dprtstrparam0
decl_stmt|;
name|__be32
name|dprtstrparam1
decl_stmt|;
name|__be32
name|dprtstrparam2
decl_stmt|;
name|__be32
name|dprtstrparam3
decl_stmt|;
block|}
name|prt
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
name|FW_DEBUG_CMD_TYPE_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_DEBUG_CMD_TYPE_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_DEBUG_CMD_TYPE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_DEBUG_CMD_TYPE_S)& FW_DEBUG_CMD_TYPE_M)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_ERR_S
value|31
end_define

begin_define
define|#
directive|define
name|PCIE_FW_ERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCIE_FW_ERR_S)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_ERR_F
value|PCIE_FW_ERR_V(1U)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_INIT_S
value|30
end_define

begin_define
define|#
directive|define
name|PCIE_FW_INIT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCIE_FW_INIT_S)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_INIT_F
value|PCIE_FW_INIT_V(1U)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_HALT_S
value|29
end_define

begin_define
define|#
directive|define
name|PCIE_FW_HALT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCIE_FW_HALT_S)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_HALT_F
value|PCIE_FW_HALT_V(1U)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_EVAL_S
value|24
end_define

begin_define
define|#
directive|define
name|PCIE_FW_EVAL_M
value|0x7
end_define

begin_define
define|#
directive|define
name|PCIE_FW_EVAL_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PCIE_FW_EVAL_S)& PCIE_FW_EVAL_M)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_MASTER_VLD_S
value|15
end_define

begin_define
define|#
directive|define
name|PCIE_FW_MASTER_VLD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCIE_FW_MASTER_VLD_S)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_MASTER_VLD_F
value|PCIE_FW_MASTER_VLD_V(1U)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_MASTER_S
value|12
end_define

begin_define
define|#
directive|define
name|PCIE_FW_MASTER_M
value|0x7
end_define

begin_define
define|#
directive|define
name|PCIE_FW_MASTER_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCIE_FW_MASTER_S)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_MASTER_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PCIE_FW_MASTER_S)& PCIE_FW_MASTER_M)
end_define

begin_struct
struct|struct
name|fw_hdr
block|{
name|u8
name|ver
decl_stmt|;
name|u8
name|chip
decl_stmt|;
comment|/* terminator chip type */
name|__be16
name|len512
decl_stmt|;
comment|/* bin length in units of 512-bytes */
name|__be32
name|fw_ver
decl_stmt|;
comment|/* firmware version */
name|__be32
name|tp_microcode_ver
decl_stmt|;
name|u8
name|intfver_nic
decl_stmt|;
name|u8
name|intfver_vnic
decl_stmt|;
name|u8
name|intfver_ofld
decl_stmt|;
name|u8
name|intfver_ri
decl_stmt|;
name|u8
name|intfver_iscsipdu
decl_stmt|;
name|u8
name|intfver_iscsi
decl_stmt|;
name|u8
name|intfver_fcoepdu
decl_stmt|;
name|u8
name|intfver_fcoe
decl_stmt|;
name|__u32
name|reserved2
decl_stmt|;
name|__u32
name|reserved3
decl_stmt|;
name|__u32
name|reserved4
decl_stmt|;
name|__be32
name|flags
decl_stmt|;
name|__be32
name|reserved6
index|[
literal|23
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fw_hdr_chip
block|{
name|FW_HDR_CHIP_T4
block|,
name|FW_HDR_CHIP_T5
block|,
name|FW_HDR_CHIP_T6
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MAJOR_S
value|24
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MAJOR_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MAJOR_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_HDR_FW_VER_MAJOR_S)
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MAJOR_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_HDR_FW_VER_MAJOR_S)& FW_HDR_FW_VER_MAJOR_M)
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MINOR_S
value|16
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MINOR_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MINOR_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_HDR_FW_VER_MINOR_S)
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MINOR_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_HDR_FW_VER_MINOR_S)& FW_HDR_FW_VER_MINOR_M)
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MICRO_S
value|8
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MICRO_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MICRO_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_HDR_FW_VER_MICRO_S)
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_MICRO_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_HDR_FW_VER_MICRO_S)& FW_HDR_FW_VER_MICRO_M)
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_BUILD_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_BUILD_M
value|0xff
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_BUILD_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< FW_HDR_FW_VER_BUILD_S)
end_define

begin_define
define|#
directive|define
name|FW_HDR_FW_VER_BUILD_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_HDR_FW_VER_BUILD_S)& FW_HDR_FW_VER_BUILD_M)
end_define

begin_enum
enum|enum
name|fw_hdr_intfver
block|{
name|FW_HDR_INTFVER_NIC
init|=
literal|0x00
block|,
name|FW_HDR_INTFVER_VNIC
init|=
literal|0x00
block|,
name|FW_HDR_INTFVER_OFLD
init|=
literal|0x00
block|,
name|FW_HDR_INTFVER_RI
init|=
literal|0x00
block|,
name|FW_HDR_INTFVER_ISCSIPDU
init|=
literal|0x00
block|,
name|FW_HDR_INTFVER_ISCSI
init|=
literal|0x00
block|,
name|FW_HDR_INTFVER_FCOEPDU
init|=
literal|0x00
block|,
name|FW_HDR_INTFVER_FCOE
init|=
literal|0x00
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_hdr_flags
block|{
name|FW_HDR_FLAGS_RESET_HALT
init|=
literal|0x00000001
block|, }
enum|;
end_enum

begin_comment
comment|/* length of the formatting string  */
end_comment

begin_define
define|#
directive|define
name|FW_DEVLOG_FMT_LEN
value|192
end_define

begin_comment
comment|/* maximum number of the formatting string parameters */
end_comment

begin_define
define|#
directive|define
name|FW_DEVLOG_FMT_PARAMS_NUM
value|8
end_define

begin_comment
comment|/* priority levels */
end_comment

begin_enum
enum|enum
name|fw_devlog_level
block|{
name|FW_DEVLOG_LEVEL_EMERG
init|=
literal|0x0
block|,
name|FW_DEVLOG_LEVEL_CRIT
init|=
literal|0x1
block|,
name|FW_DEVLOG_LEVEL_ERR
init|=
literal|0x2
block|,
name|FW_DEVLOG_LEVEL_NOTICE
init|=
literal|0x3
block|,
name|FW_DEVLOG_LEVEL_INFO
init|=
literal|0x4
block|,
name|FW_DEVLOG_LEVEL_DEBUG
init|=
literal|0x5
block|,
name|FW_DEVLOG_LEVEL_MAX
init|=
literal|0x5
block|, }
enum|;
end_enum

begin_comment
comment|/* facilities that may send a log message */
end_comment

begin_enum
enum|enum
name|fw_devlog_facility
block|{
name|FW_DEVLOG_FACILITY_CORE
init|=
literal|0x00
block|,
name|FW_DEVLOG_FACILITY_CF
init|=
literal|0x01
block|,
name|FW_DEVLOG_FACILITY_SCHED
init|=
literal|0x02
block|,
name|FW_DEVLOG_FACILITY_TIMER
init|=
literal|0x04
block|,
name|FW_DEVLOG_FACILITY_RES
init|=
literal|0x06
block|,
name|FW_DEVLOG_FACILITY_HW
init|=
literal|0x08
block|,
name|FW_DEVLOG_FACILITY_FLR
init|=
literal|0x10
block|,
name|FW_DEVLOG_FACILITY_DMAQ
init|=
literal|0x12
block|,
name|FW_DEVLOG_FACILITY_PHY
init|=
literal|0x14
block|,
name|FW_DEVLOG_FACILITY_MAC
init|=
literal|0x16
block|,
name|FW_DEVLOG_FACILITY_PORT
init|=
literal|0x18
block|,
name|FW_DEVLOG_FACILITY_VI
init|=
literal|0x1A
block|,
name|FW_DEVLOG_FACILITY_FILTER
init|=
literal|0x1C
block|,
name|FW_DEVLOG_FACILITY_ACL
init|=
literal|0x1E
block|,
name|FW_DEVLOG_FACILITY_TM
init|=
literal|0x20
block|,
name|FW_DEVLOG_FACILITY_QFC
init|=
literal|0x22
block|,
name|FW_DEVLOG_FACILITY_DCB
init|=
literal|0x24
block|,
name|FW_DEVLOG_FACILITY_ETH
init|=
literal|0x26
block|,
name|FW_DEVLOG_FACILITY_OFLD
init|=
literal|0x28
block|,
name|FW_DEVLOG_FACILITY_RI
init|=
literal|0x2A
block|,
name|FW_DEVLOG_FACILITY_ISCSI
init|=
literal|0x2C
block|,
name|FW_DEVLOG_FACILITY_FCOE
init|=
literal|0x2E
block|,
name|FW_DEVLOG_FACILITY_FOISCSI
init|=
literal|0x30
block|,
name|FW_DEVLOG_FACILITY_FOFCOE
init|=
literal|0x32
block|,
name|FW_DEVLOG_FACILITY_CHNET
init|=
literal|0x34
block|,
name|FW_DEVLOG_FACILITY_MAX
init|=
literal|0x34
block|, }
enum|;
end_enum

begin_comment
comment|/* log message format */
end_comment

begin_struct
struct|struct
name|fw_devlog_e
block|{
name|__be64
name|timestamp
decl_stmt|;
name|__be32
name|seqno
decl_stmt|;
name|__be16
name|reserved1
decl_stmt|;
name|__u8
name|level
decl_stmt|;
name|__u8
name|facility
decl_stmt|;
name|__u8
name|fmt
index|[
name|FW_DEVLOG_FMT_LEN
index|]
decl_stmt|;
name|__be32
name|params
index|[
name|FW_DEVLOG_FMT_PARAMS_NUM
index|]
decl_stmt|;
name|__be32
name|reserved3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_devlog_cmd
block|{
name|__be32
name|op_to_write
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__u8
name|level
decl_stmt|;
name|__u8
name|r2
index|[
literal|7
index|]
decl_stmt|;
name|__be32
name|memtype_devlog_memaddr16_devlog
decl_stmt|;
name|__be32
name|memsize_devlog
decl_stmt|;
name|__be32
name|r3
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_DEVLOG_CMD_MEMTYPE_DEVLOG_S
value|28
end_define

begin_define
define|#
directive|define
name|FW_DEVLOG_CMD_MEMTYPE_DEVLOG_M
value|0xf
end_define

begin_define
define|#
directive|define
name|FW_DEVLOG_CMD_MEMTYPE_DEVLOG_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_DEVLOG_CMD_MEMTYPE_DEVLOG_S)& \ 	 FW_DEVLOG_CMD_MEMTYPE_DEVLOG_M)
end_define

begin_define
define|#
directive|define
name|FW_DEVLOG_CMD_MEMADDR16_DEVLOG_S
value|0
end_define

begin_define
define|#
directive|define
name|FW_DEVLOG_CMD_MEMADDR16_DEVLOG_M
value|0xfffffff
end_define

begin_define
define|#
directive|define
name|FW_DEVLOG_CMD_MEMADDR16_DEVLOG_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> FW_DEVLOG_CMD_MEMADDR16_DEVLOG_S)& \ 	 FW_DEVLOG_CMD_MEMADDR16_DEVLOG_M)
end_define

begin_comment
comment|/* P C I E   F W   P F 7   R E G I S T E R */
end_comment

begin_comment
comment|/* PF7 stores the Firmware Device Log parameters which allows Host Drivers to  * access the "devlog" which needing to contact firmware.  The encoding is  * mostly the same as that returned by the DEVLOG command except for the size  * which is encoded as the number of entries in multiples-1 of 128 here rather  * than the memory size as is done in the DEVLOG command.  Thus, 0 means 128  * and 15 means 2048.  This of course in turn constrains the allowed values  * for the devlog size ...  */
end_comment

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG
value|7
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_NENTRIES128_S
value|28
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_NENTRIES128_M
value|0xf
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_NENTRIES128_V
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< PCIE_FW_PF_DEVLOG_NENTRIES128_S)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_NENTRIES128_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> PCIE_FW_PF_DEVLOG_NENTRIES128_S)& \ 	 PCIE_FW_PF_DEVLOG_NENTRIES128_M)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_ADDR16_S
value|4
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_ADDR16_M
value|0xffffff
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_ADDR16_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCIE_FW_PF_DEVLOG_ADDR16_S)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_ADDR16_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> PCIE_FW_PF_DEVLOG_ADDR16_S)& PCIE_FW_PF_DEVLOG_ADDR16_M)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_MEMTYPE_S
value|0
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_MEMTYPE_M
value|0xf
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_MEMTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCIE_FW_PF_DEVLOG_MEMTYPE_S)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_DEVLOG_MEMTYPE_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> PCIE_FW_PF_DEVLOG_MEMTYPE_S)& PCIE_FW_PF_DEVLOG_MEMTYPE_M)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _T4FW_INTERFACE_H_ */
end_comment

end_unit


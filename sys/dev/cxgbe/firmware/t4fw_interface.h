begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2017 Chelsio Communications, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
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

begin_comment
comment|/******************************************************************************  *   R E T U R N   V A L U E S  ********************************/
end_comment

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

begin_comment
comment|/******************************************************************************  *   M E M O R Y   T Y P E s  ******************************/
end_comment

begin_enum
enum|enum
name|fw_memtype
block|{
name|FW_MEMTYPE_EDC0
init|=
literal|0x0
block|,
name|FW_MEMTYPE_EDC1
init|=
literal|0x1
block|,
name|FW_MEMTYPE_EXTMEM
init|=
literal|0x2
block|,
name|FW_MEMTYPE_FLASH
init|=
literal|0x4
block|,
name|FW_MEMTYPE_INTERNAL
init|=
literal|0x5
block|,
name|FW_MEMTYPE_EXTMEM1
init|=
literal|0x6
block|, }
enum|;
end_enum

begin_comment
comment|/******************************************************************************  *   W O R K   R E Q U E S T s  ********************************/
end_comment

begin_enum
enum|enum
name|fw_wr_opcodes
block|{
name|FW_FRAG_WR
init|=
literal|0x1d
block|,
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
name|FW_ETH_TX_PKT2_WR
init|=
literal|0x44
block|,
name|FW_ETH_TX_PKTS_WR
init|=
literal|0x09
block|,
name|FW_ETH_TX_PKTS2_WR
init|=
literal|0x78
block|,
name|FW_ETH_TX_EO_WR
init|=
literal|0x1c
block|,
name|FW_EQ_FLUSH_WR
init|=
literal|0x1b
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
name|FW_RI_FR_NSMR_TPTE_WR
init|=
literal|0x20
block|,
name|FW_RI_INV_LSTAG_WR
init|=
literal|0x1a
block|,
name|FW_RI_SEND_IMMEDIATE_WR
init|=
literal|0x15
block|,
name|FW_RI_ATOMIC_WR
init|=
literal|0x16
block|,
name|FW_RI_WR
init|=
literal|0x0d
block|,
name|FW_CHNET_IFCONF_WR
init|=
literal|0x6b
block|,
name|FW_RDEV_WR
init|=
literal|0x38
block|,
name|FW_FOISCSI_NODE_WR
init|=
literal|0x60
block|,
name|FW_FOISCSI_CTRL_WR
init|=
literal|0x6a
block|,
name|FW_FOISCSI_CHAP_WR
init|=
literal|0x6c
block|,
name|FW_FCOE_ELS_CT_WR
init|=
literal|0x30
block|,
name|FW_SCSI_WRITE_WR
init|=
literal|0x31
block|,
name|FW_SCSI_READ_WR
init|=
literal|0x32
block|,
name|FW_SCSI_CMD_WR
init|=
literal|0x33
block|,
name|FW_SCSI_ABRT_CLS_WR
init|=
literal|0x34
block|,
name|FW_SCSI_TGT_ACC_WR
init|=
literal|0x35
block|,
name|FW_SCSI_TGT_XMIT_WR
init|=
literal|0x36
block|,
name|FW_SCSI_TGT_RSP_WR
init|=
literal|0x37
block|,
name|FW_POFCOE_TCB_WR
init|=
literal|0x42
block|,
name|FW_POFCOE_ULPTX_WR
init|=
literal|0x43
block|,
name|FW_ISCSI_TX_DATA_WR
init|=
literal|0x45
block|,
name|FW_PTP_TX_PKT_WR
init|=
literal|0x46
block|,
name|FW_TLSTX_DATA_WR
init|=
literal|0x68
block|,
name|FW_TLS_KEYCTX_TX_WR
init|=
literal|0x69
block|,
name|FW_CRYPTO_LOOKASIDE_WR
init|=
literal|0x6d
block|,
name|FW_COiSCSI_TGT_WR
init|=
literal|0x70
block|,
name|FW_COiSCSI_TGT_CONN_WR
init|=
literal|0x71
block|,
name|FW_COiSCSI_TGT_XMIT_WR
init|=
literal|0x72
block|,
name|FW_ISNS_WR
init|=
literal|0x75
block|,
name|FW_ISNS_XMIT_WR
init|=
literal|0x76
block|,
name|FW_FILTER2_WR
init|=
literal|0x77
block|,
name|FW_LASTC2E_WR
init|=
literal|0x80
block|}
enum|;
end_enum

begin_comment
comment|/*  * Generic work request header flit0  */
end_comment

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
comment|/*	work request opcode (hi)  */
end_comment

begin_define
define|#
directive|define
name|S_FW_WR_OP
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_WR_OP
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_WR_OP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WR_OP)
end_define

begin_define
define|#
directive|define
name|G_FW_WR_OP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_WR_OP)& M_FW_WR_OP)
end_define

begin_comment
comment|/*	atomic flag (hi) - firmware encapsulates CPLs in CPL_BARRIER  */
end_comment

begin_define
define|#
directive|define
name|S_FW_WR_ATOMIC
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_WR_ATOMIC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_WR_ATOMIC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WR_ATOMIC)
end_define

begin_define
define|#
directive|define
name|G_FW_WR_ATOMIC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_WR_ATOMIC)& M_FW_WR_ATOMIC)
end_define

begin_define
define|#
directive|define
name|F_FW_WR_ATOMIC
value|V_FW_WR_ATOMIC(1U)
end_define

begin_comment
comment|/*	flush flag (hi) - firmware flushes flushable work request buffered  *			      in the flow context.  */
end_comment

begin_define
define|#
directive|define
name|S_FW_WR_FLUSH
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_WR_FLUSH
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_WR_FLUSH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WR_FLUSH)
end_define

begin_define
define|#
directive|define
name|G_FW_WR_FLUSH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_WR_FLUSH)& M_FW_WR_FLUSH)
end_define

begin_define
define|#
directive|define
name|F_FW_WR_FLUSH
value|V_FW_WR_FLUSH(1U)
end_define

begin_comment
comment|/*	completion flag (hi) - firmware generates a cpl_fw6_ack  */
end_comment

begin_define
define|#
directive|define
name|S_FW_WR_COMPL
value|21
end_define

begin_define
define|#
directive|define
name|M_FW_WR_COMPL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_WR_COMPL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WR_COMPL)
end_define

begin_define
define|#
directive|define
name|G_FW_WR_COMPL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_WR_COMPL)& M_FW_WR_COMPL)
end_define

begin_define
define|#
directive|define
name|F_FW_WR_COMPL
value|V_FW_WR_COMPL(1U)
end_define

begin_comment
comment|/*	work request immediate data lengh (hi)  */
end_comment

begin_define
define|#
directive|define
name|S_FW_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_WR_IMMDLEN)& M_FW_WR_IMMDLEN)
end_define

begin_comment
comment|/*	egress queue status update to associated ingress queue entry (lo)  */
end_comment

begin_define
define|#
directive|define
name|S_FW_WR_EQUIQ
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_WR_EQUIQ
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_WR_EQUIQ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WR_EQUIQ)
end_define

begin_define
define|#
directive|define
name|G_FW_WR_EQUIQ
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_WR_EQUIQ)& M_FW_WR_EQUIQ)
end_define

begin_define
define|#
directive|define
name|F_FW_WR_EQUIQ
value|V_FW_WR_EQUIQ(1U)
end_define

begin_comment
comment|/*	egress queue status update to egress queue status entry (lo)  */
end_comment

begin_define
define|#
directive|define
name|S_FW_WR_EQUEQ
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_WR_EQUEQ
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_WR_EQUEQ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WR_EQUEQ)
end_define

begin_define
define|#
directive|define
name|G_FW_WR_EQUEQ
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_WR_EQUEQ)& M_FW_WR_EQUEQ)
end_define

begin_define
define|#
directive|define
name|F_FW_WR_EQUEQ
value|V_FW_WR_EQUEQ(1U)
end_define

begin_comment
comment|/*	flow context identifier (lo)  */
end_comment

begin_define
define|#
directive|define
name|S_FW_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_WR_FLOWID)& M_FW_WR_FLOWID)
end_define

begin_comment
comment|/*	length in units of 16-bytes (lo)  */
end_comment

begin_define
define|#
directive|define
name|S_FW_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_WR_LEN16)& M_FW_WR_LEN16)
end_define

begin_struct
struct|struct
name|fw_frag_wr
block|{
name|__be32
name|op_to_fragoff16
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|r4
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_FRAG_WR_EOF
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_FRAG_WR_EOF
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FRAG_WR_EOF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FRAG_WR_EOF)
end_define

begin_define
define|#
directive|define
name|G_FW_FRAG_WR_EOF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_FRAG_WR_EOF)& M_FW_FRAG_WR_EOF)
end_define

begin_define
define|#
directive|define
name|F_FW_FRAG_WR_EOF
value|V_FW_FRAG_WR_EOF(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FRAG_WR_FRAGOFF16
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_FRAG_WR_FRAGOFF16
value|0x7f
end_define

begin_define
define|#
directive|define
name|V_FW_FRAG_WR_FRAGOFF16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FRAG_WR_FRAGOFF16)
end_define

begin_define
define|#
directive|define
name|G_FW_FRAG_WR_FRAGOFF16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FRAG_WR_FRAGOFF16)& M_FW_FRAG_WR_FRAGOFF16)
end_define

begin_comment
comment|/* valid filter configurations for compressed tuple  * Encodings: TPL - Compressed TUPLE for filter in addition to 4-tuple  * FR - FRAGMENT, FC - FCoE, MT - MPS MATCH TYPE, M - MPS MATCH,  * E - Ethertype, P - Port, PR - Protocol, T - TOS, IV - Inner VLAN,  * OV - Outer VLAN/VNIC_ID, */
end_comment

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_M_E_P_FC
value|0x3C3
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_M_PR_T_FC
value|0x3B3
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_M_IV_P_FC
value|0x38B
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_M_OV_P_FC
value|0x387
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_E_PR_T
value|0x370
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_E_PR_P_FC
value|0X363
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_E_T_P_FC
value|0X353
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

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_T_IV_P_FC
value|0X31B
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_MT_T_OV_P_FC
value|0X317
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_M_E_PR_FC
value|0X2E1
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_M_E_T_FC
value|0X2D1
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_M_PR_IV_FC
value|0X2A9
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_M_PR_OV_FC
value|0X2A5
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_M_T_IV_FC
value|0X299
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_M_T_OV_FC
value|0X295
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_E_PR_T_P
value|0X272
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_E_PR_T_FC
value|0X271
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_E_IV_FC
value|0X249
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_E_OV_FC
value|0X245
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_PR_T_IV_FC
value|0X239
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_PR_T_OV_FC
value|0X235
end_define

begin_define
define|#
directive|define
name|HW_TPL_FR_IV_OV_FC
value|0X20D
end_define

begin_define
define|#
directive|define
name|HW_TPL_MT_M_E_PR
value|0X1E0
end_define

begin_define
define|#
directive|define
name|HW_TPL_MT_M_E_T
value|0X1D0
end_define

begin_define
define|#
directive|define
name|HW_TPL_MT_E_PR_T_FC
value|0X171
end_define

begin_define
define|#
directive|define
name|HW_TPL_MT_E_IV
value|0X148
end_define

begin_define
define|#
directive|define
name|HW_TPL_MT_E_OV
value|0X144
end_define

begin_define
define|#
directive|define
name|HW_TPL_MT_PR_T_IV
value|0X138
end_define

begin_define
define|#
directive|define
name|HW_TPL_MT_PR_T_OV
value|0X134
end_define

begin_define
define|#
directive|define
name|HW_TPL_M_E_PR_P
value|0X0E2
end_define

begin_define
define|#
directive|define
name|HW_TPL_M_E_T_P
value|0X0D2
end_define

begin_define
define|#
directive|define
name|HW_TPL_E_PR_T_P_FC
value|0X073
end_define

begin_define
define|#
directive|define
name|HW_TPL_E_IV_P
value|0X04A
end_define

begin_define
define|#
directive|define
name|HW_TPL_E_OV_P
value|0X046
end_define

begin_define
define|#
directive|define
name|HW_TPL_PR_T_IV_P
value|0X03A
end_define

begin_define
define|#
directive|define
name|HW_TPL_PR_T_OV_P
value|0X036
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

begin_enum
enum|enum
name|fw_filter_wr_nat_mode
block|{
name|FW_FILTER_WR_NATMODE_NONE
init|=
literal|0
block|,
name|FW_FILTER_WR_NATMODE_DIP
block|,
name|FW_FILTER_WR_NATMODE_DIPDP
block|,
name|FW_FILTER_WR_NATMODE_DIPDPSIP
block|,
name|FW_FILTER_WR_NATMODE_DIPDPSP
block|,
name|FW_FILTER_WR_NATMODE_SIPSP
block|,
name|FW_FILTER_WR_NATMODE_DIPSIPSP
block|,
name|FW_FILTER_WR_NATMODE_FOURTUPLE
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

begin_struct
struct|struct
name|fw_filter2_wr
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
name|__u8
name|r8_hi
index|[
literal|2
index|]
decl_stmt|;
name|__u8
name|filter_type_swapmac
decl_stmt|;
name|__u8
name|natmode_to_ulp_type
decl_stmt|;
name|__be16
name|newlport
decl_stmt|;
name|__be16
name|newfport
decl_stmt|;
name|__u8
name|newlip
index|[
literal|16
index|]
decl_stmt|;
name|__u8
name|newfip
index|[
literal|16
index|]
decl_stmt|;
name|__be32
name|natseqcheck
decl_stmt|;
name|__be32
name|dip_hit_vni
decl_stmt|;
name|__be64
name|r10
decl_stmt|;
name|__be64
name|r11
decl_stmt|;
name|__be64
name|r12
decl_stmt|;
name|__be64
name|r13
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_TID
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_TID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_TID)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_TID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_TID)& M_FW_FILTER_WR_TID)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_RQTYPE
value|11
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_RQTYPE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_RQTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_RQTYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_RQTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_RQTYPE)& M_FW_FILTER_WR_RQTYPE)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_RQTYPE
value|V_FW_FILTER_WR_RQTYPE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_NOREPLY
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_NOREPLY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_NOREPLY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_NOREPLY)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_NOREPLY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_NOREPLY)& M_FW_FILTER_WR_NOREPLY)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_NOREPLY
value|V_FW_FILTER_WR_NOREPLY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_IQ
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_IQ
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_IQ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_IQ)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_IQ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_IQ)& M_FW_FILTER_WR_IQ)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_DEL_FILTER
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_DEL_FILTER
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_DEL_FILTER
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_DEL_FILTER)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_DEL_FILTER
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_DEL_FILTER)& M_FW_FILTER_WR_DEL_FILTER)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_DEL_FILTER
value|V_FW_FILTER_WR_DEL_FILTER(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_RPTTID
value|25
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_RPTTID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_RPTTID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_RPTTID)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_RPTTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_RPTTID)& M_FW_FILTER_WR_RPTTID)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_RPTTID
value|V_FW_FILTER_WR_RPTTID(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_DROP
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_DROP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_DROP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_DROP)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_DROP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_DROP)& M_FW_FILTER_WR_DROP)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_DROP
value|V_FW_FILTER_WR_DROP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_DIRSTEER
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_DIRSTEER
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_DIRSTEER
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_DIRSTEER)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_DIRSTEER
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_DIRSTEER)& M_FW_FILTER_WR_DIRSTEER)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_DIRSTEER
value|V_FW_FILTER_WR_DIRSTEER(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_MASKHASH
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_MASKHASH
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_MASKHASH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_MASKHASH)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_MASKHASH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_MASKHASH)& M_FW_FILTER_WR_MASKHASH)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_MASKHASH
value|V_FW_FILTER_WR_MASKHASH(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_DIRSTEERHASH
value|21
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_DIRSTEERHASH
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_DIRSTEERHASH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_DIRSTEERHASH)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_DIRSTEERHASH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_DIRSTEERHASH)& M_FW_FILTER_WR_DIRSTEERHASH)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_DIRSTEERHASH
value|V_FW_FILTER_WR_DIRSTEERHASH(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_LPBK
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_LPBK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_LPBK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_LPBK)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_LPBK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_LPBK)& M_FW_FILTER_WR_LPBK)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_LPBK
value|V_FW_FILTER_WR_LPBK(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_DMAC
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_DMAC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_DMAC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_DMAC)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_DMAC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_DMAC)& M_FW_FILTER_WR_DMAC)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_DMAC
value|V_FW_FILTER_WR_DMAC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_SMAC
value|18
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_SMAC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_SMAC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_SMAC)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_SMAC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_SMAC)& M_FW_FILTER_WR_SMAC)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_SMAC
value|V_FW_FILTER_WR_SMAC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_INSVLAN
value|17
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_INSVLAN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_INSVLAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_INSVLAN)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_INSVLAN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_INSVLAN)& M_FW_FILTER_WR_INSVLAN)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_INSVLAN
value|V_FW_FILTER_WR_INSVLAN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_RMVLAN
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_RMVLAN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_RMVLAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_RMVLAN)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_RMVLAN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_RMVLAN)& M_FW_FILTER_WR_RMVLAN)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_RMVLAN
value|V_FW_FILTER_WR_RMVLAN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_HITCNTS
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_HITCNTS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_HITCNTS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_HITCNTS)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_HITCNTS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_HITCNTS)& M_FW_FILTER_WR_HITCNTS)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_HITCNTS
value|V_FW_FILTER_WR_HITCNTS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_TXCHAN
value|13
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_TXCHAN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_TXCHAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_TXCHAN)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_TXCHAN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_TXCHAN)& M_FW_FILTER_WR_TXCHAN)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_PRIO
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_PRIO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_PRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_PRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_PRIO)& M_FW_FILTER_WR_PRIO)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_PRIO
value|V_FW_FILTER_WR_PRIO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_L2TIX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_L2TIX
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_L2TIX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_L2TIX)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_L2TIX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_L2TIX)& M_FW_FILTER_WR_L2TIX)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_FRAG
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_FRAG
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_FRAG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_FRAG)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_FRAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_FRAG)& M_FW_FILTER_WR_FRAG)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_FRAG
value|V_FW_FILTER_WR_FRAG(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_FRAGM
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_FRAGM
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_FRAGM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_FRAGM)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_FRAGM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_FRAGM)& M_FW_FILTER_WR_FRAGM)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_FRAGM
value|V_FW_FILTER_WR_FRAGM(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_IVLAN_VLD
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_IVLAN_VLD
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_IVLAN_VLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_IVLAN_VLD)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_IVLAN_VLD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_IVLAN_VLD)& M_FW_FILTER_WR_IVLAN_VLD)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_IVLAN_VLD
value|V_FW_FILTER_WR_IVLAN_VLD(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_OVLAN_VLD
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_OVLAN_VLD
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_OVLAN_VLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_OVLAN_VLD)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_OVLAN_VLD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_OVLAN_VLD)& M_FW_FILTER_WR_OVLAN_VLD)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_OVLAN_VLD
value|V_FW_FILTER_WR_OVLAN_VLD(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_IVLAN_VLDM
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_IVLAN_VLDM
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_IVLAN_VLDM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_IVLAN_VLDM)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_IVLAN_VLDM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_IVLAN_VLDM)& M_FW_FILTER_WR_IVLAN_VLDM)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_IVLAN_VLDM
value|V_FW_FILTER_WR_IVLAN_VLDM(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_OVLAN_VLDM
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_OVLAN_VLDM
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_OVLAN_VLDM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_OVLAN_VLDM)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_OVLAN_VLDM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_OVLAN_VLDM)& M_FW_FILTER_WR_OVLAN_VLDM)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_OVLAN_VLDM
value|V_FW_FILTER_WR_OVLAN_VLDM(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_RX_CHAN
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_RX_CHAN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_RX_CHAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_RX_CHAN)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_RX_CHAN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_RX_CHAN)& M_FW_FILTER_WR_RX_CHAN)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_RX_CHAN
value|V_FW_FILTER_WR_RX_CHAN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_RX_RPL_IQ
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_RX_RPL_IQ
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_RX_RPL_IQ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_RX_RPL_IQ)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_RX_RPL_IQ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_RX_RPL_IQ)& M_FW_FILTER_WR_RX_RPL_IQ)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER2_WR_FILTER_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER2_WR_FILTER_TYPE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER2_WR_FILTER_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER2_WR_FILTER_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER2_WR_FILTER_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER2_WR_FILTER_TYPE)& M_FW_FILTER2_WR_FILTER_TYPE)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER2_WR_FILTER_TYPE
value|V_FW_FILTER2_WR_FILTER_TYPE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER2_WR_SWAPMAC
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER2_WR_SWAPMAC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER2_WR_SWAPMAC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER2_WR_SWAPMAC)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER2_WR_SWAPMAC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER2_WR_SWAPMAC)& M_FW_FILTER2_WR_SWAPMAC)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER2_WR_SWAPMAC
value|V_FW_FILTER2_WR_SWAPMAC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER2_WR_NATMODE
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER2_WR_NATMODE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER2_WR_NATMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER2_WR_NATMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER2_WR_NATMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER2_WR_NATMODE)& M_FW_FILTER2_WR_NATMODE)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER2_WR_NATFLAGCHECK
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER2_WR_NATFLAGCHECK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER2_WR_NATFLAGCHECK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER2_WR_NATFLAGCHECK)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER2_WR_NATFLAGCHECK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER2_WR_NATFLAGCHECK)& M_FW_FILTER2_WR_NATFLAGCHECK)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER2_WR_NATFLAGCHECK
value|V_FW_FILTER2_WR_NATFLAGCHECK(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER2_WR_ULP_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER2_WR_ULP_TYPE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER2_WR_ULP_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER2_WR_ULP_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER2_WR_ULP_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER2_WR_ULP_TYPE)& M_FW_FILTER2_WR_ULP_TYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER2_WR_DIP_HIT
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER2_WR_DIP_HIT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER2_WR_DIP_HIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER2_WR_DIP_HIT)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER2_WR_DIP_HIT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER2_WR_DIP_HIT)& M_FW_FILTER2_WR_DIP_HIT)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER2_WR_DIP_HIT
value|V_FW_FILTER2_WR_DIP_HIT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER2_WR_VNI
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER2_WR_VNI
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER2_WR_VNI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER2_WR_VNI)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER2_WR_VNI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER2_WR_VNI)& M_FW_FILTER2_WR_VNI)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_MACI
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_MACI
value|0x1ff
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_MACI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_MACI)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_MACI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_MACI)& M_FW_FILTER_WR_MACI)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_MACIM
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_MACIM
value|0x1ff
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_MACIM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_MACIM)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_MACIM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_MACIM)& M_FW_FILTER_WR_MACIM)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_FCOE
value|13
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_FCOE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_FCOE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_FCOE)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_FCOE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_FCOE)& M_FW_FILTER_WR_FCOE)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_FCOE
value|V_FW_FILTER_WR_FCOE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_FCOEM
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_FCOEM
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_FCOEM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_FCOEM)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_FCOEM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_FCOEM)& M_FW_FILTER_WR_FCOEM)
end_define

begin_define
define|#
directive|define
name|F_FW_FILTER_WR_FCOEM
value|V_FW_FILTER_WR_FCOEM(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_PORT
value|9
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_PORT
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_PORT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_PORT)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_PORT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_PORT)& M_FW_FILTER_WR_PORT)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_PORTM
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_PORTM
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_PORTM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_PORTM)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_PORTM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_PORTM)& M_FW_FILTER_WR_PORTM)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_MATCHTYPE
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_MATCHTYPE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_MATCHTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_MATCHTYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_MATCHTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_MATCHTYPE)& M_FW_FILTER_WR_MATCHTYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_FILTER_WR_MATCHTYPEM
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FILTER_WR_MATCHTYPEM
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_FILTER_WR_MATCHTYPEM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FILTER_WR_MATCHTYPEM)
end_define

begin_define
define|#
directive|define
name|G_FW_FILTER_WR_MATCHTYPEM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FILTER_WR_MATCHTYPEM)& M_FW_FILTER_WR_MATCHTYPEM)
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
name|__u64
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
name|__u64
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

begin_define
define|#
directive|define
name|S_FW_ETH_TX_PKT_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_PKT_WR_IMMDLEN
value|0x1ff
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_PKT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ETH_TX_PKT_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_PKT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_PKT_WR_IMMDLEN)& M_FW_ETH_TX_PKT_WR_IMMDLEN)
end_define

begin_struct
struct|struct
name|fw_eth_tx_pkt2_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|equiq_to_len16
decl_stmt|;
name|__be32
name|r3
decl_stmt|;
name|__be32
name|L4ChkDisable_to_IpHdrLen
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_ETH_TX_PKT2_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_PKT2_WR_IMMDLEN
value|0x1ff
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_PKT2_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ETH_TX_PKT2_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_PKT2_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_PKT2_WR_IMMDLEN)& M_FW_ETH_TX_PKT2_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_ETH_TX_PKT2_WR_L4CHKDISABLE
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_PKT2_WR_L4CHKDISABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_PKT2_WR_L4CHKDISABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_ETH_TX_PKT2_WR_L4CHKDISABLE)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_PKT2_WR_L4CHKDISABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_PKT2_WR_L4CHKDISABLE)& \      M_FW_ETH_TX_PKT2_WR_L4CHKDISABLE)
end_define

begin_define
define|#
directive|define
name|F_FW_ETH_TX_PKT2_WR_L4CHKDISABLE
define|\
value|V_FW_ETH_TX_PKT2_WR_L4CHKDISABLE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_ETH_TX_PKT2_WR_L3CHKDISABLE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_PKT2_WR_L3CHKDISABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_PKT2_WR_L3CHKDISABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_ETH_TX_PKT2_WR_L3CHKDISABLE)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_PKT2_WR_L3CHKDISABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_PKT2_WR_L3CHKDISABLE)& \      M_FW_ETH_TX_PKT2_WR_L3CHKDISABLE)
end_define

begin_define
define|#
directive|define
name|F_FW_ETH_TX_PKT2_WR_L3CHKDISABLE
define|\
value|V_FW_ETH_TX_PKT2_WR_L3CHKDISABLE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_ETH_TX_PKT2_WR_IVLAN
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_PKT2_WR_IVLAN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_PKT2_WR_IVLAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ETH_TX_PKT2_WR_IVLAN)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_PKT2_WR_IVLAN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_PKT2_WR_IVLAN)& M_FW_ETH_TX_PKT2_WR_IVLAN)
end_define

begin_define
define|#
directive|define
name|F_FW_ETH_TX_PKT2_WR_IVLAN
value|V_FW_ETH_TX_PKT2_WR_IVLAN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_ETH_TX_PKT2_WR_IVLANTAG
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_PKT2_WR_IVLANTAG
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_PKT2_WR_IVLANTAG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ETH_TX_PKT2_WR_IVLANTAG)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_PKT2_WR_IVLANTAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_PKT2_WR_IVLANTAG)& M_FW_ETH_TX_PKT2_WR_IVLANTAG)
end_define

begin_define
define|#
directive|define
name|S_FW_ETH_TX_PKT2_WR_CHKTYPE
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_PKT2_WR_CHKTYPE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_PKT2_WR_CHKTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ETH_TX_PKT2_WR_CHKTYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_PKT2_WR_CHKTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_PKT2_WR_CHKTYPE)& M_FW_ETH_TX_PKT2_WR_CHKTYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_ETH_TX_PKT2_WR_IPHDRLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_PKT2_WR_IPHDRLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_PKT2_WR_IPHDRLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ETH_TX_PKT2_WR_IPHDRLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_PKT2_WR_IPHDRLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_PKT2_WR_IPHDRLEN)& M_FW_ETH_TX_PKT2_WR_IPHDRLEN)
end_define

begin_struct
struct|struct
name|fw_eth_tx_pkts_wr
block|{
name|__be32
name|op_pkd
decl_stmt|;
name|__be32
name|equiq_to_len16
decl_stmt|;
name|__be32
name|r3
decl_stmt|;
name|__be16
name|plen
decl_stmt|;
name|__u8
name|npkt
decl_stmt|;
name|__u8
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_PTP_TX_PKT_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PTP_TX_PKT_WR_IMMDLEN
value|0x1ff
end_define

begin_define
define|#
directive|define
name|V_FW_PTP_TX_PKT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PTP_TX_PKT_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_PTP_TX_PKT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PTP_TX_PKT_WR_IMMDLEN)& M_FW_PTP_TX_PKT_WR_IMMDLEN)
end_define

begin_struct
struct|struct
name|fw_eth_tx_pkt_ptp_wr
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

begin_enum
enum|enum
name|fw_eth_tx_eo_type
block|{
name|FW_ETH_TX_EO_TYPE_UDPSEG
block|,
name|FW_ETH_TX_EO_TYPE_TCPSEG
block|,
name|FW_ETH_TX_EO_TYPE_NVGRESEG
block|,
name|FW_ETH_TX_EO_TYPE_VXLANSEG
block|,
name|FW_ETH_TX_EO_TYPE_GENEVESEG
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_eth_tx_eo_wr
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
union|union
name|fw_eth_tx_eo
block|{
struct|struct
name|fw_eth_tx_eo_udpseg
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|ethlen
decl_stmt|;
name|__be16
name|iplen
decl_stmt|;
name|__u8
name|udplen
decl_stmt|;
name|__u8
name|rtplen
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__be16
name|mss
decl_stmt|;
name|__be16
name|schedpktsize
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
block|}
name|udpseg
struct|;
struct|struct
name|fw_eth_tx_eo_tcpseg
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|ethlen
decl_stmt|;
name|__be16
name|iplen
decl_stmt|;
name|__u8
name|tcplen
decl_stmt|;
name|__u8
name|tsclk_tsoff
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__be16
name|mss
decl_stmt|;
name|__be16
name|r5
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
block|}
name|tcpseg
struct|;
struct|struct
name|fw_eth_tx_eo_nvgreseg
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|iphdroffout
decl_stmt|;
name|__be16
name|grehdroff
decl_stmt|;
name|__be16
name|iphdroffin
decl_stmt|;
name|__be16
name|tcphdroffin
decl_stmt|;
name|__be16
name|mss
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
block|}
name|nvgreseg
struct|;
struct|struct
name|fw_eth_tx_eo_vxlanseg
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|iphdroffout
decl_stmt|;
name|__be16
name|vxlanhdroff
decl_stmt|;
name|__be16
name|iphdroffin
decl_stmt|;
name|__be16
name|tcphdroffin
decl_stmt|;
name|__be16
name|mss
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
block|}
name|vxlanseg
struct|;
struct|struct
name|fw_eth_tx_eo_geneveseg
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|iphdroffout
decl_stmt|;
name|__be16
name|genevehdroff
decl_stmt|;
name|__be16
name|iphdroffin
decl_stmt|;
name|__be16
name|tcphdroffin
decl_stmt|;
name|__be16
name|mss
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
block|}
name|geneveseg
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
name|S_FW_ETH_TX_EO_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_EO_WR_IMMDLEN
value|0x1ff
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_EO_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ETH_TX_EO_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_EO_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_EO_WR_IMMDLEN)& M_FW_ETH_TX_EO_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_ETH_TX_EO_WR_TSCLK
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_EO_WR_TSCLK
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_EO_WR_TSCLK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ETH_TX_EO_WR_TSCLK)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_EO_WR_TSCLK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_EO_WR_TSCLK)& M_FW_ETH_TX_EO_WR_TSCLK)
end_define

begin_define
define|#
directive|define
name|S_FW_ETH_TX_EO_WR_TSOFF
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ETH_TX_EO_WR_TSOFF
value|0x3f
end_define

begin_define
define|#
directive|define
name|V_FW_ETH_TX_EO_WR_TSOFF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ETH_TX_EO_WR_TSOFF)
end_define

begin_define
define|#
directive|define
name|G_FW_ETH_TX_EO_WR_TSOFF
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ETH_TX_EO_WR_TSOFF)& M_FW_ETH_TX_EO_WR_TSOFF)
end_define

begin_struct
struct|struct
name|fw_eq_flush_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
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
name|S_FW_OFLD_CONNECTION_WR_VERSION
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_CONNECTION_WR_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_CONNECTION_WR_VERSION
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_OFLD_CONNECTION_WR_VERSION)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_CONNECTION_WR_VERSION
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_CONNECTION_WR_VERSION)& \      M_FW_OFLD_CONNECTION_WR_VERSION)
end_define

begin_define
define|#
directive|define
name|F_FW_OFLD_CONNECTION_WR_VERSION
value|V_FW_OFLD_CONNECTION_WR_VERSION(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_OFLD_CONNECTION_WR_CPL
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_CONNECTION_WR_CPL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_CONNECTION_WR_CPL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_OFLD_CONNECTION_WR_CPL)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_CONNECTION_WR_CPL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_CONNECTION_WR_CPL)& M_FW_OFLD_CONNECTION_WR_CPL)
end_define

begin_define
define|#
directive|define
name|F_FW_OFLD_CONNECTION_WR_CPL
value|V_FW_OFLD_CONNECTION_WR_CPL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_OFLD_CONNECTION_WR_T_STATE
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_CONNECTION_WR_T_STATE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_CONNECTION_WR_T_STATE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_OFLD_CONNECTION_WR_T_STATE)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_CONNECTION_WR_T_STATE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_CONNECTION_WR_T_STATE)& \      M_FW_OFLD_CONNECTION_WR_T_STATE)
end_define

begin_define
define|#
directive|define
name|S_FW_OFLD_CONNECTION_WR_RCV_SCALE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_CONNECTION_WR_RCV_SCALE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_CONNECTION_WR_RCV_SCALE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_OFLD_CONNECTION_WR_RCV_SCALE)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_CONNECTION_WR_RCV_SCALE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_CONNECTION_WR_RCV_SCALE)& \      M_FW_OFLD_CONNECTION_WR_RCV_SCALE)
end_define

begin_define
define|#
directive|define
name|S_FW_OFLD_CONNECTION_WR_ASTID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_CONNECTION_WR_ASTID
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_CONNECTION_WR_ASTID
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_OFLD_CONNECTION_WR_ASTID)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_CONNECTION_WR_ASTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_CONNECTION_WR_ASTID)& M_FW_OFLD_CONNECTION_WR_ASTID)
end_define

begin_define
define|#
directive|define
name|S_FW_OFLD_CONNECTION_WR_CPLRXDATAACK
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_CONNECTION_WR_CPLRXDATAACK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_CONNECTION_WR_CPLRXDATAACK
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_OFLD_CONNECTION_WR_CPLRXDATAACK)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_CONNECTION_WR_CPLRXDATAACK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_CONNECTION_WR_CPLRXDATAACK)& \      M_FW_OFLD_CONNECTION_WR_CPLRXDATAACK)
end_define

begin_define
define|#
directive|define
name|F_FW_OFLD_CONNECTION_WR_CPLRXDATAACK
define|\
value|V_FW_OFLD_CONNECTION_WR_CPLRXDATAACK(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL)& \      M_FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL)
end_define

begin_define
define|#
directive|define
name|F_FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL
define|\
value|V_FW_OFLD_CONNECTION_WR_CPLPASSACCEPTRPL(1U)
end_define

begin_enum
enum|enum
name|fw_flowc_mnem_tcpstate
block|{
name|FW_FLOWC_MNEM_TCPSTATE_CLOSED
init|=
literal|0
block|,
comment|/* illegal */
name|FW_FLOWC_MNEM_TCPSTATE_LISTEN
init|=
literal|1
block|,
comment|/* illegal */
name|FW_FLOWC_MNEM_TCPSTATE_SYNSENT
init|=
literal|2
block|,
comment|/* illegal */
name|FW_FLOWC_MNEM_TCPSTATE_SYNRECEIVED
init|=
literal|3
block|,
comment|/* illegal */
name|FW_FLOWC_MNEM_TCPSTATE_ESTABLISHED
init|=
literal|4
block|,
comment|/* default */
name|FW_FLOWC_MNEM_TCPSTATE_CLOSEWAIT
init|=
literal|5
block|,
comment|/* got peer close already */
name|FW_FLOWC_MNEM_TCPSTATE_FINWAIT1
init|=
literal|6
block|,
comment|/* haven't gotten ACK for FIN and 					      * will resend FIN - equiv ESTAB 					      */
name|FW_FLOWC_MNEM_TCPSTATE_CLOSING
init|=
literal|7
block|,
comment|/* haven't gotten ACK for FIN and 					      * will resend FIN but have 					      * received FIN 					      */
name|FW_FLOWC_MNEM_TCPSTATE_LASTACK
init|=
literal|8
block|,
comment|/* haven't gotten ACK for FIN and 					      * will resend FIN but have 					      * received FIN 					      */
name|FW_FLOWC_MNEM_TCPSTATE_FINWAIT2
init|=
literal|9
block|,
comment|/* sent FIN and got FIN + ACK, 					      * waiting for FIN 					      */
name|FW_FLOWC_MNEM_TCPSTATE_TIMEWAIT
init|=
literal|10
block|,
comment|/* not expected */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_flowc_mnem_eostate
block|{
name|FW_FLOWC_MNEM_EOSTATE_CLOSED
init|=
literal|0
block|,
comment|/* illegal */
name|FW_FLOWC_MNEM_EOSTATE_ESTABLISHED
init|=
literal|1
block|,
comment|/* default */
name|FW_FLOWC_MNEM_EOSTATE_CLOSING
init|=
literal|2
block|,
comment|/* graceful close, after sending 					      * outstanding payload 					      */
name|FW_FLOWC_MNEM_EOSTATE_ABORTING
init|=
literal|3
block|,
comment|/* immediate close, after 					      * discarding outstanding payload 					      */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_flowc_mnem
block|{
name|FW_FLOWC_MNEM_PFNVFN
init|=
literal|0
block|,
comment|/* PFN [15:8] VFN [7:0] */
name|FW_FLOWC_MNEM_CH
init|=
literal|1
block|,
name|FW_FLOWC_MNEM_PORT
init|=
literal|2
block|,
name|FW_FLOWC_MNEM_IQID
init|=
literal|3
block|,
name|FW_FLOWC_MNEM_SNDNXT
init|=
literal|4
block|,
name|FW_FLOWC_MNEM_RCVNXT
init|=
literal|5
block|,
name|FW_FLOWC_MNEM_SNDBUF
init|=
literal|6
block|,
name|FW_FLOWC_MNEM_MSS
init|=
literal|7
block|,
name|FW_FLOWC_MNEM_TXDATAPLEN_MAX
init|=
literal|8
block|,
name|FW_FLOWC_MNEM_TCPSTATE
init|=
literal|9
block|,
name|FW_FLOWC_MNEM_EOSTATE
init|=
literal|10
block|,
name|FW_FLOWC_MNEM_SCHEDCLASS
init|=
literal|11
block|,
name|FW_FLOWC_MNEM_DCBPRIO
init|=
literal|12
block|,
name|FW_FLOWC_MNEM_SND_SCALE
init|=
literal|13
block|,
name|FW_FLOWC_MNEM_RCV_SCALE
init|=
literal|14
block|,
name|FW_FLOWC_MNEM_ULP_MODE
init|=
literal|15
block|,
name|FW_FLOWC_MNEM_MAX
init|=
literal|16
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_flowc_mnemval
block|{
name|__u8
name|mnemonic
decl_stmt|;
name|__u8
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
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
name|struct
name|fw_flowc_mnemval
name|mnemval
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_FLOWC_WR_NPARAMS
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FLOWC_WR_NPARAMS
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_FLOWC_WR_NPARAMS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FLOWC_WR_NPARAMS)
end_define

begin_define
define|#
directive|define
name|G_FW_FLOWC_WR_NPARAMS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FLOWC_WR_NPARAMS)& M_FW_FLOWC_WR_NPARAMS)
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
name|lsodisable_to_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_OFLD_TX_DATA_WR_LSODISABLE
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_TX_DATA_WR_LSODISABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_TX_DATA_WR_LSODISABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_OFLD_TX_DATA_WR_LSODISABLE)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_TX_DATA_WR_LSODISABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_TX_DATA_WR_LSODISABLE)& \      M_FW_OFLD_TX_DATA_WR_LSODISABLE)
end_define

begin_define
define|#
directive|define
name|F_FW_OFLD_TX_DATA_WR_LSODISABLE
value|V_FW_OFLD_TX_DATA_WR_LSODISABLE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_OFLD_TX_DATA_WR_ALIGNPLD
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_TX_DATA_WR_ALIGNPLD
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_TX_DATA_WR_ALIGNPLD
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_OFLD_TX_DATA_WR_ALIGNPLD)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_TX_DATA_WR_ALIGNPLD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_TX_DATA_WR_ALIGNPLD)& M_FW_OFLD_TX_DATA_WR_ALIGNPLD)
end_define

begin_define
define|#
directive|define
name|F_FW_OFLD_TX_DATA_WR_ALIGNPLD
value|V_FW_OFLD_TX_DATA_WR_ALIGNPLD(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_OFLD_TX_DATA_WR_ALIGNPLDSHOVE
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_TX_DATA_WR_ALIGNPLDSHOVE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_TX_DATA_WR_ALIGNPLDSHOVE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_OFLD_TX_DATA_WR_ALIGNPLDSHOVE)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_TX_DATA_WR_ALIGNPLDSHOVE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_TX_DATA_WR_ALIGNPLDSHOVE)& \      M_FW_OFLD_TX_DATA_WR_ALIGNPLDSHOVE)
end_define

begin_define
define|#
directive|define
name|F_FW_OFLD_TX_DATA_WR_ALIGNPLDSHOVE
define|\
value|V_FW_OFLD_TX_DATA_WR_ALIGNPLDSHOVE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_OFLD_TX_DATA_WR_FLAGS
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_OFLD_TX_DATA_WR_FLAGS
value|0xfffffff
end_define

begin_define
define|#
directive|define
name|V_FW_OFLD_TX_DATA_WR_FLAGS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_OFLD_TX_DATA_WR_FLAGS)
end_define

begin_define
define|#
directive|define
name|G_FW_OFLD_TX_DATA_WR_FLAGS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_OFLD_TX_DATA_WR_FLAGS)& M_FW_OFLD_TX_DATA_WR_FLAGS)
end_define

begin_comment
comment|/* Use fw_ofld_tx_data_wr structure */
end_comment

begin_define
define|#
directive|define
name|S_FW_ISCSI_TX_DATA_WR_FLAGS_HI
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_ISCSI_TX_DATA_WR_FLAGS_HI
value|0x3fffff
end_define

begin_define
define|#
directive|define
name|V_FW_ISCSI_TX_DATA_WR_FLAGS_HI
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_ISCSI_TX_DATA_WR_FLAGS_HI)
end_define

begin_define
define|#
directive|define
name|G_FW_ISCSI_TX_DATA_WR_FLAGS_HI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ISCSI_TX_DATA_WR_FLAGS_HI)& M_FW_ISCSI_TX_DATA_WR_FLAGS_HI)
end_define

begin_define
define|#
directive|define
name|S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_ISO
value|9
end_define

begin_define
define|#
directive|define
name|M_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_ISO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_ISO
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_ISO)
end_define

begin_define
define|#
directive|define
name|G_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_ISO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_ISO)& \      M_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_ISO)
end_define

begin_define
define|#
directive|define
name|F_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_ISO
define|\
value|V_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_ISO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_PI
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_PI
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_PI
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_PI)
end_define

begin_define
define|#
directive|define
name|G_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_PI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_PI)& \      M_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_PI)
end_define

begin_define
define|#
directive|define
name|F_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_PI
define|\
value|V_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_PI(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_DCRC
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_DCRC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_DCRC
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_DCRC)
end_define

begin_define
define|#
directive|define
name|G_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_DCRC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_DCRC)& \      M_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_DCRC)
end_define

begin_define
define|#
directive|define
name|F_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_DCRC
define|\
value|V_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_DCRC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_HCRC
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_HCRC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_HCRC
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_HCRC)
end_define

begin_define
define|#
directive|define
name|G_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_HCRC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_HCRC)& \      M_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_HCRC)
end_define

begin_define
define|#
directive|define
name|F_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_HCRC
define|\
value|V_FW_ISCSI_TX_DATA_WR_ULPSUBMODE_HCRC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_ISCSI_TX_DATA_WR_FLAGS_LO
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ISCSI_TX_DATA_WR_FLAGS_LO
value|0x3f
end_define

begin_define
define|#
directive|define
name|V_FW_ISCSI_TX_DATA_WR_FLAGS_LO
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_ISCSI_TX_DATA_WR_FLAGS_LO)
end_define

begin_define
define|#
directive|define
name|G_FW_ISCSI_TX_DATA_WR_FLAGS_LO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ISCSI_TX_DATA_WR_FLAGS_LO)& M_FW_ISCSI_TX_DATA_WR_FLAGS_LO)
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
name|S_FW_CMD_WR_DMA
value|17
end_define

begin_define
define|#
directive|define
name|M_FW_CMD_WR_DMA
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_CMD_WR_DMA
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CMD_WR_DMA)
end_define

begin_define
define|#
directive|define
name|G_FW_CMD_WR_DMA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_CMD_WR_DMA)& M_FW_CMD_WR_DMA)
end_define

begin_define
define|#
directive|define
name|F_FW_CMD_WR_DMA
value|V_FW_CMD_WR_DMA(1U)
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
name|__u8
name|ethmacdst
index|[
literal|6
index|]
decl_stmt|;
name|__u8
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

begin_comment
comment|/******************************************************************************  *   R I   W O R K   R E Q U E S T s  **************************************/
end_comment

begin_enum
enum|enum
name|fw_ri_wr_opcode
block|{
name|FW_RI_RDMA_WRITE
init|=
literal|0x0
block|,
comment|/* IETF RDMAP v1.0 ... */
name|FW_RI_READ_REQ
init|=
literal|0x1
block|,
name|FW_RI_READ_RESP
init|=
literal|0x2
block|,
name|FW_RI_SEND
init|=
literal|0x3
block|,
name|FW_RI_SEND_WITH_INV
init|=
literal|0x4
block|,
name|FW_RI_SEND_WITH_SE
init|=
literal|0x5
block|,
name|FW_RI_SEND_WITH_SE_INV
init|=
literal|0x6
block|,
name|FW_RI_TERMINATE
init|=
literal|0x7
block|,
name|FW_RI_RDMA_INIT
init|=
literal|0x8
block|,
comment|/* CHELSIO RI specific ... */
name|FW_RI_BIND_MW
init|=
literal|0x9
block|,
name|FW_RI_FAST_REGISTER
init|=
literal|0xa
block|,
name|FW_RI_LOCAL_INV
init|=
literal|0xb
block|,
name|FW_RI_QP_MODIFY
init|=
literal|0xc
block|,
name|FW_RI_BYPASS
init|=
literal|0xd
block|,
name|FW_RI_RECEIVE
init|=
literal|0xe
block|,
if|#
directive|if
literal|0
block|FW_RI_SEND_IMMEDIATE		= 0x8, 	FW_RI_SEND_IMMEDIATE_WITH_SE	= 0x9, 	FW_RI_ATOMIC_REQUEST		= 0xa, 	FW_RI_ATOMIC_RESPONSE		= 0xb,  	FW_RI_BIND_MW			= 0xc,
comment|/* CHELSIO RI specific ... */
block|FW_RI_FAST_REGISTER		= 0xd, 	FW_RI_LOCAL_INV			= 0xe,
endif|#
directive|endif
name|FW_RI_SGE_EC_CR_RETURN
init|=
literal|0xf
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_wr_flags
block|{
name|FW_RI_COMPLETION_FLAG
init|=
literal|0x01
block|,
name|FW_RI_NOTIFICATION_FLAG
init|=
literal|0x02
block|,
name|FW_RI_SOLICITED_EVENT_FLAG
init|=
literal|0x04
block|,
name|FW_RI_READ_FENCE_FLAG
init|=
literal|0x08
block|,
name|FW_RI_LOCAL_FENCE_FLAG
init|=
literal|0x10
block|,
name|FW_RI_RDMA_READ_INVALIDATE
init|=
literal|0x20
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_mpa_attrs
block|{
name|FW_RI_MPA_RX_MARKER_ENABLE
init|=
literal|0x01
block|,
name|FW_RI_MPA_TX_MARKER_ENABLE
init|=
literal|0x02
block|,
name|FW_RI_MPA_CRC_ENABLE
init|=
literal|0x04
block|,
name|FW_RI_MPA_IETF_ENABLE
init|=
literal|0x08
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_qp_caps
block|{
name|FW_RI_QP_RDMA_READ_ENABLE
init|=
literal|0x01
block|,
name|FW_RI_QP_RDMA_WRITE_ENABLE
init|=
literal|0x02
block|,
name|FW_RI_QP_BIND_ENABLE
init|=
literal|0x04
block|,
name|FW_RI_QP_FAST_REGISTER_ENABLE
init|=
literal|0x08
block|,
name|FW_RI_QP_STAG0_ENABLE
init|=
literal|0x10
block|,
name|FW_RI_QP_RDMA_READ_REQ_0B_ENABLE
init|=
literal|0x80
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_addr_type
block|{
name|FW_RI_ZERO_BASED_TO
init|=
literal|0x00
block|,
name|FW_RI_VA_BASED_TO
init|=
literal|0x01
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_mem_perms
block|{
name|FW_RI_MEM_ACCESS_REM_WRITE
init|=
literal|0x01
block|,
name|FW_RI_MEM_ACCESS_REM_READ
init|=
literal|0x02
block|,
name|FW_RI_MEM_ACCESS_REM
init|=
literal|0x03
block|,
name|FW_RI_MEM_ACCESS_LOCAL_WRITE
init|=
literal|0x04
block|,
name|FW_RI_MEM_ACCESS_LOCAL_READ
init|=
literal|0x08
block|,
name|FW_RI_MEM_ACCESS_LOCAL
init|=
literal|0x0C
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_stag_type
block|{
name|FW_RI_STAG_NSMR
init|=
literal|0x00
block|,
name|FW_RI_STAG_SMR
init|=
literal|0x01
block|,
name|FW_RI_STAG_MW
init|=
literal|0x02
block|,
name|FW_RI_STAG_MW_RELAXED
init|=
literal|0x03
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_data_op
block|{
name|FW_RI_DATA_IMMD
init|=
literal|0x81
block|,
name|FW_RI_DATA_DSGL
init|=
literal|0x82
block|,
name|FW_RI_DATA_ISGL
init|=
literal|0x83
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_sgl_depth
block|{
name|FW_RI_SGL_DEPTH_MAX_SQ
init|=
literal|16
block|,
name|FW_RI_SGL_DEPTH_MAX_RQ
init|=
literal|4
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_cqe_err
block|{
name|FW_RI_CQE_ERR_SUCCESS
init|=
literal|0x00
block|,
comment|/* success, no error detected */
name|FW_RI_CQE_ERR_STAG
init|=
literal|0x01
block|,
comment|/* STAG invalid */
name|FW_RI_CQE_ERR_PDID
init|=
literal|0x02
block|,
comment|/* PDID mismatch */
name|FW_RI_CQE_ERR_QPID
init|=
literal|0x03
block|,
comment|/* QPID mismatch */
name|FW_RI_CQE_ERR_ACCESS
init|=
literal|0x04
block|,
comment|/* Invalid access right */
name|FW_RI_CQE_ERR_WRAP
init|=
literal|0x05
block|,
comment|/* Wrap error */
name|FW_RI_CQE_ERR_BOUND
init|=
literal|0x06
block|,
comment|/* base and bounds violation */
name|FW_RI_CQE_ERR_INVALIDATE_SHARED_MR
init|=
literal|0x07
block|,
comment|/* attempt to invalidate a SMR */
name|FW_RI_CQE_ERR_INVALIDATE_MR_WITH_MW_BOUND
init|=
literal|0x08
block|,
comment|/* attempt to invalidate a MR w MW */
name|FW_RI_CQE_ERR_ECC
init|=
literal|0x09
block|,
comment|/* ECC error detected */
name|FW_RI_CQE_ERR_ECC_PSTAG
init|=
literal|0x0A
block|,
comment|/* ECC error detected when reading the PSTAG for a MW Invalidate */
name|FW_RI_CQE_ERR_PBL_ADDR_BOUND
init|=
literal|0x0B
block|,
comment|/* pbl address out of bound : software error */
name|FW_RI_CQE_ERR_CRC
init|=
literal|0x10
block|,
comment|/* CRC error */
name|FW_RI_CQE_ERR_MARKER
init|=
literal|0x11
block|,
comment|/* Marker error */
name|FW_RI_CQE_ERR_PDU_LEN_ERR
init|=
literal|0x12
block|,
comment|/* invalid PDU length */
name|FW_RI_CQE_ERR_OUT_OF_RQE
init|=
literal|0x13
block|,
comment|/* out of RQE */
name|FW_RI_CQE_ERR_DDP_VERSION
init|=
literal|0x14
block|,
comment|/* wrong DDP version */
name|FW_RI_CQE_ERR_RDMA_VERSION
init|=
literal|0x15
block|,
comment|/* wrong RDMA version */
name|FW_RI_CQE_ERR_OPCODE
init|=
literal|0x16
block|,
comment|/* invalid rdma opcode */
name|FW_RI_CQE_ERR_DDP_QUEUE_NUM
init|=
literal|0x17
block|,
comment|/* invalid ddp queue number */
name|FW_RI_CQE_ERR_MSN
init|=
literal|0x18
block|,
comment|/* MSN error */
name|FW_RI_CQE_ERR_TBIT
init|=
literal|0x19
block|,
comment|/* tag bit not set correctly */
name|FW_RI_CQE_ERR_MO
init|=
literal|0x1A
block|,
comment|/* MO not zero for TERMINATE or READ_REQ */
name|FW_RI_CQE_ERR_MSN_GAP
init|=
literal|0x1B
block|,
comment|/* */
name|FW_RI_CQE_ERR_MSN_RANGE
init|=
literal|0x1C
block|,
comment|/* */
name|FW_RI_CQE_ERR_IRD_OVERFLOW
init|=
literal|0x1D
block|,
comment|/* */
name|FW_RI_CQE_ERR_RQE_ADDR_BOUND
init|=
literal|0x1E
block|,
comment|/*  RQE address out of bound : software error */
name|FW_RI_CQE_ERR_INTERNAL_ERR
init|=
literal|0x1F
comment|/* internel error (opcode mismatch) */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fw_ri_dsge_pair
block|{
name|__be32
name|len
index|[
literal|2
index|]
decl_stmt|;
name|__be64
name|addr
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_dsgl
block|{
name|__u8
name|op
decl_stmt|;
name|__u8
name|r1
decl_stmt|;
name|__be16
name|nsge
decl_stmt|;
name|__be32
name|len0
decl_stmt|;
name|__be64
name|addr0
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
name|struct
name|fw_ri_dsge_pair
name|sge
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_sge
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

begin_struct
struct|struct
name|fw_ri_isgl
block|{
name|__u8
name|op
decl_stmt|;
name|__u8
name|r1
decl_stmt|;
name|__be16
name|nsge
decl_stmt|;
name|__be32
name|r2
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
name|struct
name|fw_ri_sge
name|sge
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_immd
block|{
name|__u8
name|op
decl_stmt|;
name|__u8
name|r1
decl_stmt|;
name|__be16
name|r2
decl_stmt|;
name|__be32
name|immdlen
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
name|__u8
name|data
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_tpte
block|{
name|__be32
name|valid_to_pdid
decl_stmt|;
name|__be32
name|locread_to_qpid
decl_stmt|;
name|__be32
name|nosnoop_pbladdr
decl_stmt|;
name|__be32
name|len_lo
decl_stmt|;
name|__be32
name|va_hi
decl_stmt|;
name|__be32
name|va_lo_fbo
decl_stmt|;
name|__be32
name|dca_mwbcnt_pstag
decl_stmt|;
name|__be32
name|len_hi
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_VALID
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_VALID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_VALID)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_VALID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_VALID)& M_FW_RI_TPTE_VALID)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_TPTE_VALID
value|V_FW_RI_TPTE_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_STAGKEY
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_STAGKEY
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_STAGKEY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_STAGKEY)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_STAGKEY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_STAGKEY)& M_FW_RI_TPTE_STAGKEY)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_STAGSTATE
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_STAGSTATE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_STAGSTATE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_STAGSTATE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_STAGSTATE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_STAGSTATE)& M_FW_RI_TPTE_STAGSTATE)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_TPTE_STAGSTATE
value|V_FW_RI_TPTE_STAGSTATE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_STAGTYPE
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_STAGTYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_STAGTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_STAGTYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_STAGTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_STAGTYPE)& M_FW_RI_TPTE_STAGTYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_PDID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_PDID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_PDID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_PDID)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_PDID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_PDID)& M_FW_RI_TPTE_PDID)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_PERM
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_PERM
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_PERM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_PERM)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_PERM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_PERM)& M_FW_RI_TPTE_PERM)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_REMINVDIS
value|27
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_REMINVDIS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_REMINVDIS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_REMINVDIS)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_REMINVDIS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_REMINVDIS)& M_FW_RI_TPTE_REMINVDIS)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_TPTE_REMINVDIS
value|V_FW_RI_TPTE_REMINVDIS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_ADDRTYPE
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_ADDRTYPE
value|1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_ADDRTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_ADDRTYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_ADDRTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_ADDRTYPE)& M_FW_RI_TPTE_ADDRTYPE)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_TPTE_ADDRTYPE
value|V_FW_RI_TPTE_ADDRTYPE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_MWBINDEN
value|25
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_MWBINDEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_MWBINDEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_MWBINDEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_MWBINDEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_MWBINDEN)& M_FW_RI_TPTE_MWBINDEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_TPTE_MWBINDEN
value|V_FW_RI_TPTE_MWBINDEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_PS
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_PS
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_PS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_PS)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_PS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_PS)& M_FW_RI_TPTE_PS)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_QPID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_QPID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_QPID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_QPID)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_QPID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_QPID)& M_FW_RI_TPTE_QPID)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_NOSNOOP
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_NOSNOOP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_NOSNOOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_NOSNOOP)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_NOSNOOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_NOSNOOP)& M_FW_RI_TPTE_NOSNOOP)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_TPTE_NOSNOOP
value|V_FW_RI_TPTE_NOSNOOP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_PBLADDR
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_PBLADDR
value|0x1fffffff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_PBLADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_PBLADDR)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_PBLADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_PBLADDR)& M_FW_RI_TPTE_PBLADDR)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_DCA
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_DCA
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_DCA
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_TPTE_DCA)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_DCA
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_DCA)& M_FW_RI_TPTE_DCA)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_TPTE_MWBCNT_PSTAG
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_TPTE_MWBCNT_PSTAG
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_TPTE_MWBCNT_PSTAT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RI_TPTE_MWBCNT_PSTAG)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_TPTE_MWBCNT_PSTAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_TPTE_MWBCNT_PSTAG)& M_FW_RI_TPTE_MWBCNT_PSTAG)
end_define

begin_enum
enum|enum
name|fw_ri_cqe_rxtx
block|{
name|FW_RI_CQE_RXTX_RX
init|=
literal|0x0
block|,
name|FW_RI_CQE_RXTX_TX
init|=
literal|0x1
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_ri_cqe
block|{
union|union
name|fw_ri_rxtx
block|{
struct|struct
name|fw_ri_scqe
block|{
name|__be32
name|qpid_n_stat_rxtx_type
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
name|__be32
name|stag
decl_stmt|;
name|__be32
name|wrid
decl_stmt|;
block|}
name|scqe
struct|;
struct|struct
name|fw_ri_rcqe
block|{
name|__be32
name|qpid_n_stat_rxtx_type
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
name|__be32
name|stag
decl_stmt|;
name|__be32
name|msn
decl_stmt|;
block|}
name|rcqe
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
name|S_FW_RI_CQE_QPID
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_RI_CQE_QPID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_CQE_QPID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_CQE_QPID)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_CQE_QPID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_CQE_QPID)&  M_FW_RI_CQE_QPID)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_CQE_NOTIFY
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RI_CQE_NOTIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_CQE_NOTIFY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_CQE_NOTIFY)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_CQE_NOTIFY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_CQE_NOTIFY)&  M_FW_RI_CQE_NOTIFY)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_CQE_STATUS
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_RI_CQE_STATUS
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_RI_CQE_STATUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_CQE_STATUS)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_CQE_STATUS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_CQE_STATUS)&  M_FW_RI_CQE_STATUS)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_CQE_RXTX
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_RI_CQE_RXTX
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_CQE_RXTX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_CQE_RXTX)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_CQE_RXTX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_CQE_RXTX)&  M_FW_RI_CQE_RXTX)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_CQE_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_CQE_TYPE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_RI_CQE_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_CQE_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_CQE_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_CQE_TYPE)&  M_FW_RI_CQE_TYPE)
end_define

begin_enum
enum|enum
name|fw_ri_res_type
block|{
name|FW_RI_RES_TYPE_SQ
block|,
name|FW_RI_RES_TYPE_RQ
block|,
name|FW_RI_RES_TYPE_CQ
block|,
name|FW_RI_RES_TYPE_SRQ
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_res_op
block|{
name|FW_RI_RES_OP_WRITE
block|,
name|FW_RI_RES_OP_RESET
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_ri_res
block|{
union|union
name|fw_ri_restype
block|{
struct|struct
name|fw_ri_res_sqrq
block|{
name|__u8
name|restype
decl_stmt|;
name|__u8
name|op
decl_stmt|;
name|__be16
name|r3
decl_stmt|;
name|__be32
name|eqid
decl_stmt|;
name|__be32
name|r4
index|[
literal|2
index|]
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
name|sqrq
struct|;
struct|struct
name|fw_ri_res_cq
block|{
name|__u8
name|restype
decl_stmt|;
name|__u8
name|op
decl_stmt|;
name|__be16
name|r3
decl_stmt|;
name|__be32
name|iqid
decl_stmt|;
name|__be32
name|r4
index|[
literal|2
index|]
decl_stmt|;
name|__be32
name|iqandst_to_iqandstindex
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
name|iqns_iqro
decl_stmt|;
name|__be32
name|r6_lo
decl_stmt|;
name|__be64
name|r7
decl_stmt|;
block|}
name|cq
struct|;
struct|struct
name|fw_ri_res_srq
block|{
name|__u8
name|restype
decl_stmt|;
name|__u8
name|op
decl_stmt|;
name|__be16
name|r3
decl_stmt|;
name|__be32
name|eqid
decl_stmt|;
name|__be32
name|r4
index|[
literal|2
index|]
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
name|srqid
decl_stmt|;
name|__be32
name|pdid
decl_stmt|;
name|__be32
name|hwsrqsize
decl_stmt|;
name|__be32
name|hwsrqaddr
decl_stmt|;
block|}
name|srq
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_res_wr
block|{
name|__be32
name|op_nres
decl_stmt|;
name|__be32
name|len16_pkd
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
name|struct
name|fw_ri_res
name|res
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_VFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_VFN)& M_FW_RI_RES_WR_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_NRES
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_NRES
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_NRES
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_NRES)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_NRES
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_NRES)& M_FW_RI_RES_WR_NRES)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_FETCHSZM
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_FETCHSZM
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_FETCHSZM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_FETCHSZM)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_FETCHSZM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_FETCHSZM)& M_FW_RI_RES_WR_FETCHSZM)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_FETCHSZM
value|V_FW_RI_RES_WR_FETCHSZM(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_STATUSPGNS
value|25
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_STATUSPGNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_STATUSPGNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_STATUSPGNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_STATUSPGNS)& M_FW_RI_RES_WR_STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_STATUSPGNS
value|V_FW_RI_RES_WR_STATUSPGNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_STATUSPGRO
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_STATUSPGRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_STATUSPGRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_STATUSPGRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_STATUSPGRO)& M_FW_RI_RES_WR_STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_STATUSPGRO
value|V_FW_RI_RES_WR_STATUSPGRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_FETCHNS
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_FETCHNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_FETCHNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_FETCHNS)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_FETCHNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_FETCHNS)& M_FW_RI_RES_WR_FETCHNS)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_FETCHNS
value|V_FW_RI_RES_WR_FETCHNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_FETCHRO
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_FETCHRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_FETCHRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_FETCHRO)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_FETCHRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_FETCHRO)& M_FW_RI_RES_WR_FETCHRO)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_FETCHRO
value|V_FW_RI_RES_WR_FETCHRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_HOSTFCMODE
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_HOSTFCMODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_HOSTFCMODE)& M_FW_RI_RES_WR_HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_CPRIO
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_CPRIO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_CPRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_CPRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_CPRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_CPRIO)& M_FW_RI_RES_WR_CPRIO)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_CPRIO
value|V_FW_RI_RES_WR_CPRIO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_ONCHIP
value|18
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_ONCHIP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_ONCHIP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_ONCHIP)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_ONCHIP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_ONCHIP)& M_FW_RI_RES_WR_ONCHIP)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_ONCHIP
value|V_FW_RI_RES_WR_ONCHIP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_PCIECHN
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_PCIECHN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_PCIECHN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_PCIECHN)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_PCIECHN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_PCIECHN)& M_FW_RI_RES_WR_PCIECHN)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQID
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQID)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQID)& M_FW_RI_RES_WR_IQID)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_DCAEN
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_DCAEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_DCAEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_DCAEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_DCAEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_DCAEN)& M_FW_RI_RES_WR_DCAEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_DCAEN
value|V_FW_RI_RES_WR_DCAEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_DCACPU
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_DCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_DCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_DCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_DCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_DCACPU)& M_FW_RI_RES_WR_DCACPU)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_FBMIN
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_FBMIN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_FBMIN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_FBMIN)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_FBMIN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_FBMIN)& M_FW_RI_RES_WR_FBMIN)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_FBMAX
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_FBMAX
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_FBMAX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_FBMAX)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_FBMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_FBMAX)& M_FW_RI_RES_WR_FBMAX)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_CIDXFTHRESHO
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_CIDXFTHRESHO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_CIDXFTHRESHO)& M_FW_RI_RES_WR_CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_CIDXFTHRESHO
value|V_FW_RI_RES_WR_CIDXFTHRESHO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_CIDXFTHRESH
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_CIDXFTHRESH
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_CIDXFTHRESH)& M_FW_RI_RES_WR_CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_EQSIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_EQSIZE
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_EQSIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_EQSIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_EQSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_EQSIZE)& M_FW_RI_RES_WR_EQSIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQANDST
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQANDST
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQANDST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQANDST)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQANDST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQANDST)& M_FW_RI_RES_WR_IQANDST)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_IQANDST
value|V_FW_RI_RES_WR_IQANDST(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQANUS
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQANUS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQANUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQANUS)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQANUS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQANUS)& M_FW_RI_RES_WR_IQANUS)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_IQANUS
value|V_FW_RI_RES_WR_IQANUS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQANUD
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQANUD
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQANUD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQANUD)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQANUD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQANUD)& M_FW_RI_RES_WR_IQANUD)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQANDSTINDEX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQANDSTINDEX
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQANDSTINDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQANDSTINDEX)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQANDSTINDEX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQANDSTINDEX)& M_FW_RI_RES_WR_IQANDSTINDEX)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQDROPRSS
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQDROPRSS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQDROPRSS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQDROPRSS)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQDROPRSS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQDROPRSS)& M_FW_RI_RES_WR_IQDROPRSS)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_IQDROPRSS
value|V_FW_RI_RES_WR_IQDROPRSS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQGTSMODE
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQGTSMODE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQGTSMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQGTSMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQGTSMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQGTSMODE)& M_FW_RI_RES_WR_IQGTSMODE)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_IQGTSMODE
value|V_FW_RI_RES_WR_IQGTSMODE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQPCIECH
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQPCIECH
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQPCIECH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQPCIECH)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQPCIECH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQPCIECH)& M_FW_RI_RES_WR_IQPCIECH)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQDCAEN
value|11
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQDCAEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQDCAEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQDCAEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQDCAEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQDCAEN)& M_FW_RI_RES_WR_IQDCAEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_IQDCAEN
value|V_FW_RI_RES_WR_IQDCAEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQDCACPU
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQDCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQDCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQDCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQDCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQDCACPU)& M_FW_RI_RES_WR_IQDCACPU)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQINTCNTTHRESH
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQINTCNTTHRESH
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQINTCNTTHRESH
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RI_RES_WR_IQINTCNTTHRESH)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQINTCNTTHRESH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQINTCNTTHRESH)& M_FW_RI_RES_WR_IQINTCNTTHRESH)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQO
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQO)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQO)& M_FW_RI_RES_WR_IQO)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_IQO
value|V_FW_RI_RES_WR_IQO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQCPRIO
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQCPRIO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQCPRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQCPRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQCPRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQCPRIO)& M_FW_RI_RES_WR_IQCPRIO)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_IQCPRIO
value|V_FW_RI_RES_WR_IQCPRIO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQESIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQESIZE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQESIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQESIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQESIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQESIZE)& M_FW_RI_RES_WR_IQESIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQNS
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQNS)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQNS)& M_FW_RI_RES_WR_IQNS)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_IQNS
value|V_FW_RI_RES_WR_IQNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_RES_WR_IQRO
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_RI_RES_WR_IQRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_RES_WR_IQRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_RES_WR_IQRO)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_RES_WR_IQRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_RES_WR_IQRO)& M_FW_RI_RES_WR_IQRO)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_RES_WR_IQRO
value|V_FW_RI_RES_WR_IQRO(1U)
end_define

begin_struct
struct|struct
name|fw_ri_rdma_write_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be64
name|r2
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
name|__be32
name|stag_sink
decl_stmt|;
name|__be64
name|to_sink
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
union|union
block|{
name|struct
name|fw_ri_immd
name|immd_src
index|[
literal|0
index|]
decl_stmt|;
name|struct
name|fw_ri_isgl
name|isgl_src
index|[
literal|0
index|]
decl_stmt|;
block|}
name|u
union|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_send_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be32
name|sendop_pkd
decl_stmt|;
name|__be32
name|stag_inv
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
name|__be32
name|r3
decl_stmt|;
name|__be64
name|r4
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
union|union
block|{
name|struct
name|fw_ri_immd
name|immd_src
index|[
literal|0
index|]
decl_stmt|;
name|struct
name|fw_ri_isgl
name|isgl_src
index|[
literal|0
index|]
decl_stmt|;
block|}
name|u
union|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_RI_SEND_WR_SENDOP
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_SEND_WR_SENDOP
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_RI_SEND_WR_SENDOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_SEND_WR_SENDOP)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_SEND_WR_SENDOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_SEND_WR_SENDOP)& M_FW_RI_SEND_WR_SENDOP)
end_define

begin_struct
struct|struct
name|fw_ri_rdma_read_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be64
name|r2
decl_stmt|;
name|__be32
name|stag_sink
decl_stmt|;
name|__be32
name|to_sink_hi
decl_stmt|;
name|__be32
name|to_sink_lo
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
name|__be32
name|stag_src
decl_stmt|;
name|__be32
name|to_src_hi
decl_stmt|;
name|__be32
name|to_src_lo
decl_stmt|;
name|__be32
name|r5
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_recv_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|r1
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r2
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|struct
name|fw_ri_isgl
name|isgl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_bind_mw_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__u8
name|qpbinde_to_dcacpu
decl_stmt|;
name|__u8
name|pgsz_shift
decl_stmt|;
name|__u8
name|addr_type
decl_stmt|;
name|__u8
name|mem_perms
decl_stmt|;
name|__be32
name|stag_mr
decl_stmt|;
name|__be32
name|stag_mw
decl_stmt|;
name|__be32
name|r3
decl_stmt|;
name|__be64
name|len_mw
decl_stmt|;
name|__be64
name|va_fbo
decl_stmt|;
name|__be64
name|r4
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_RI_BIND_MW_WR_QPBINDE
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_RI_BIND_MW_WR_QPBINDE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_BIND_MW_WR_QPBINDE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_BIND_MW_WR_QPBINDE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_BIND_MW_WR_QPBINDE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_BIND_MW_WR_QPBINDE)& M_FW_RI_BIND_MW_WR_QPBINDE)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_BIND_MW_WR_QPBINDE
value|V_FW_RI_BIND_MW_WR_QPBINDE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_BIND_MW_WR_NS
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_RI_BIND_MW_WR_NS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_BIND_MW_WR_NS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_BIND_MW_WR_NS)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_BIND_MW_WR_NS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_BIND_MW_WR_NS)& M_FW_RI_BIND_MW_WR_NS)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_BIND_MW_WR_NS
value|V_FW_RI_BIND_MW_WR_NS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_BIND_MW_WR_DCACPU
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_BIND_MW_WR_DCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_RI_BIND_MW_WR_DCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_BIND_MW_WR_DCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_BIND_MW_WR_DCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_BIND_MW_WR_DCACPU)& M_FW_RI_BIND_MW_WR_DCACPU)
end_define

begin_struct
struct|struct
name|fw_ri_fr_nsmr_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__u8
name|qpbinde_to_dcacpu
decl_stmt|;
name|__u8
name|pgsz_shift
decl_stmt|;
name|__u8
name|addr_type
decl_stmt|;
name|__u8
name|mem_perms
decl_stmt|;
name|__be32
name|stag
decl_stmt|;
name|__be32
name|len_hi
decl_stmt|;
name|__be32
name|len_lo
decl_stmt|;
name|__be32
name|va_hi
decl_stmt|;
name|__be32
name|va_lo_fbo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_RI_FR_NSMR_WR_QPBINDE
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_RI_FR_NSMR_WR_QPBINDE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_FR_NSMR_WR_QPBINDE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_FR_NSMR_WR_QPBINDE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_FR_NSMR_WR_QPBINDE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_FR_NSMR_WR_QPBINDE)& M_FW_RI_FR_NSMR_WR_QPBINDE)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_FR_NSMR_WR_QPBINDE
value|V_FW_RI_FR_NSMR_WR_QPBINDE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_FR_NSMR_WR_NS
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_RI_FR_NSMR_WR_NS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_FR_NSMR_WR_NS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_FR_NSMR_WR_NS)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_FR_NSMR_WR_NS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_FR_NSMR_WR_NS)& M_FW_RI_FR_NSMR_WR_NS)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_FR_NSMR_WR_NS
value|V_FW_RI_FR_NSMR_WR_NS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_FR_NSMR_WR_DCACPU
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_FR_NSMR_WR_DCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_RI_FR_NSMR_WR_DCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_FR_NSMR_WR_DCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_FR_NSMR_WR_DCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_FR_NSMR_WR_DCACPU)& M_FW_RI_FR_NSMR_WR_DCACPU)
end_define

begin_struct
struct|struct
name|fw_ri_fr_nsmr_tpte_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be32
name|r2
decl_stmt|;
name|__be32
name|stag
decl_stmt|;
name|struct
name|fw_ri_tpte
name|tpte
decl_stmt|;
name|__be64
name|pbl
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_inv_lstag_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be32
name|r2
decl_stmt|;
name|__be32
name|stag_inv
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ri_send_immediate_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be32
name|sendimmop_pkd
decl_stmt|;
name|__be32
name|r3
decl_stmt|;
name|__be32
name|plen
decl_stmt|;
name|__be32
name|r4
decl_stmt|;
name|__be64
name|r5
decl_stmt|;
ifndef|#
directive|ifndef
name|C99_NOT_SUPPORTED
name|struct
name|fw_ri_immd
name|immd_src
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_RI_SEND_IMMEDIATE_WR_SENDIMMOP
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_SEND_IMMEDIATE_WR_SENDIMMOP
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_RI_SEND_IMMEDIATE_WR_SENDIMMOP
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RI_SEND_IMMEDIATE_WR_SENDIMMOP)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_SEND_IMMEDIATE_WR_SENDIMMOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_SEND_IMMEDIATE_WR_SENDIMMOP)& \      M_FW_RI_SEND_IMMEDIATE_WR_SENDIMMOP)
end_define

begin_enum
enum|enum
name|fw_ri_atomic_op
block|{
name|FW_RI_ATOMIC_OP_FETCHADD
block|,
name|FW_RI_ATOMIC_OP_SWAP
block|,
name|FW_RI_ATOMIC_OP_CMDSWAP
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_ri_atomic_wr
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u16
name|wrid
decl_stmt|;
name|__u8
name|r1
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|len16
decl_stmt|;
name|__be32
name|atomicop_pkd
decl_stmt|;
name|__be64
name|r3
decl_stmt|;
name|__be32
name|aopcode_pkd
decl_stmt|;
name|__be32
name|reqid
decl_stmt|;
name|__be32
name|stag
decl_stmt|;
name|__be32
name|to_hi
decl_stmt|;
name|__be32
name|to_lo
decl_stmt|;
name|__be32
name|addswap_data_hi
decl_stmt|;
name|__be32
name|addswap_data_lo
decl_stmt|;
name|__be32
name|addswap_mask_hi
decl_stmt|;
name|__be32
name|addswap_mask_lo
decl_stmt|;
name|__be32
name|compare_data_hi
decl_stmt|;
name|__be32
name|compare_data_lo
decl_stmt|;
name|__be32
name|compare_mask_hi
decl_stmt|;
name|__be32
name|compare_mask_lo
decl_stmt|;
name|__be32
name|r5
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_RI_ATOMIC_WR_ATOMICOP
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_ATOMIC_WR_ATOMICOP
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_RI_ATOMIC_WR_ATOMICOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_ATOMIC_WR_ATOMICOP)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_ATOMIC_WR_ATOMICOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_ATOMIC_WR_ATOMICOP)& M_FW_RI_ATOMIC_WR_ATOMICOP)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_ATOMIC_WR_AOPCODE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_ATOMIC_WR_AOPCODE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_RI_ATOMIC_WR_AOPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_ATOMIC_WR_AOPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_ATOMIC_WR_AOPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_ATOMIC_WR_AOPCODE)& M_FW_RI_ATOMIC_WR_AOPCODE)
end_define

begin_enum
enum|enum
name|fw_ri_type
block|{
name|FW_RI_TYPE_INIT
block|,
name|FW_RI_TYPE_FINI
block|,
name|FW_RI_TYPE_TERMINATE
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_init_p2ptype
block|{
name|FW_RI_INIT_P2PTYPE_RDMA_WRITE
init|=
name|FW_RI_RDMA_WRITE
block|,
name|FW_RI_INIT_P2PTYPE_READ_REQ
init|=
name|FW_RI_READ_REQ
block|,
name|FW_RI_INIT_P2PTYPE_SEND
init|=
name|FW_RI_SEND
block|,
name|FW_RI_INIT_P2PTYPE_SEND_WITH_INV
init|=
name|FW_RI_SEND_WITH_INV
block|,
name|FW_RI_INIT_P2PTYPE_SEND_WITH_SE
init|=
name|FW_RI_SEND_WITH_SE
block|,
name|FW_RI_INIT_P2PTYPE_SEND_WITH_SE_INV
init|=
name|FW_RI_SEND_WITH_SE_INV
block|,
name|FW_RI_INIT_P2PTYPE_DISABLED
init|=
literal|0xf
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_ri_init_rqeqid_srq
block|{
name|FW_RI_INIT_RQEQID_SRQ
init|=
literal|1
operator|<<
literal|31
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_ri_wr
block|{
name|__be32
name|op_compl
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
union|union
name|fw_ri
block|{
struct|struct
name|fw_ri_init
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|mpareqbit_p2ptype
decl_stmt|;
name|__u8
name|r4
index|[
literal|2
index|]
decl_stmt|;
name|__u8
name|mpa_attrs
decl_stmt|;
name|__u8
name|qp_caps
decl_stmt|;
name|__be16
name|nrqe
decl_stmt|;
name|__be32
name|pdid
decl_stmt|;
name|__be32
name|qpid
decl_stmt|;
name|__be32
name|sq_eqid
decl_stmt|;
name|__be32
name|rq_eqid
decl_stmt|;
name|__be32
name|scqid
decl_stmt|;
name|__be32
name|rcqid
decl_stmt|;
name|__be32
name|ord_max
decl_stmt|;
name|__be32
name|ird_max
decl_stmt|;
name|__be32
name|iss
decl_stmt|;
name|__be32
name|irs
decl_stmt|;
name|__be32
name|hwrqsize
decl_stmt|;
name|__be32
name|hwrqaddr
decl_stmt|;
name|__be64
name|r5
decl_stmt|;
union|union
name|fw_ri_init_p2p
block|{
name|struct
name|fw_ri_rdma_write_wr
name|write
decl_stmt|;
name|struct
name|fw_ri_rdma_read_wr
name|read
decl_stmt|;
name|struct
name|fw_ri_send_wr
name|send
decl_stmt|;
block|}
name|u
union|;
block|}
name|init
struct|;
struct|struct
name|fw_ri_fini
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|r3
index|[
literal|7
index|]
decl_stmt|;
name|__be64
name|r4
decl_stmt|;
block|}
name|fini
struct|;
struct|struct
name|fw_ri_terminate
block|{
name|__u8
name|type
decl_stmt|;
name|__u8
name|r3
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|immdlen
decl_stmt|;
name|__u8
name|termmsg
index|[
literal|40
index|]
decl_stmt|;
block|}
name|terminate
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
name|S_FW_RI_WR_MPAREQBIT
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_RI_WR_MPAREQBIT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_WR_MPAREQBIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_WR_MPAREQBIT)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_WR_MPAREQBIT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_WR_MPAREQBIT)& M_FW_RI_WR_MPAREQBIT)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_WR_MPAREQBIT
value|V_FW_RI_WR_MPAREQBIT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_WR_0BRRBIT
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_RI_WR_0BRRBIT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RI_WR_0BRRBIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_WR_0BRRBIT)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_WR_0BRRBIT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_WR_0BRRBIT)& M_FW_RI_WR_0BRRBIT)
end_define

begin_define
define|#
directive|define
name|F_FW_RI_WR_0BRRBIT
value|V_FW_RI_WR_0BRRBIT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RI_WR_P2PTYPE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RI_WR_P2PTYPE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_RI_WR_P2PTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RI_WR_P2PTYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_RI_WR_P2PTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RI_WR_P2PTYPE)& M_FW_RI_WR_P2PTYPE)
end_define

begin_comment
comment|/******************************************************************************  *  F O i S C S I   W O R K R E Q U E S T s  *********************************************/
end_comment

begin_define
define|#
directive|define
name|FW_FOISCSI_NAME_MAX_LEN
value|224
end_define

begin_define
define|#
directive|define
name|FW_FOISCSI_ALIAS_MAX_LEN
value|224
end_define

begin_define
define|#
directive|define
name|FW_FOISCSI_CHAP_SEC_MAX_LEN
value|128
end_define

begin_define
define|#
directive|define
name|FW_FOISCSI_INIT_NODE_MAX
value|8
end_define

begin_enum
enum|enum
name|fw_chnet_ifconf_wr_subop
block|{
name|FW_CHNET_IFCONF_WR_SUBOP_NONE
init|=
literal|0
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_IPV4_SET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_IPV4_GET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_VLAN_IPV4_SET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_VLAN_IPV4_GET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_IPV6_SET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_IPV6_GET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_VLAN_SET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_VLAN_GET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_MTU_SET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_MTU_GET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_DHCP_SET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_DHCP_GET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_DHCPV6_SET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_DHCPV6_GET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_LINKLOCAL_ADDR_SET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_RA_BASED_ADDR_SET
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_ADDR_EXPIRED
block|,
name|FW_CHNET_IFCONF_WR_SUBOP_MAX
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_chnet_ifconf_wr
block|{
name|__be32
name|op_compl
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be32
name|if_flowid
decl_stmt|;
name|__u8
name|idx
decl_stmt|;
name|__u8
name|subop
decl_stmt|;
name|__u8
name|retval
decl_stmt|;
name|__u8
name|r2
decl_stmt|;
name|__be64
name|r3
decl_stmt|;
struct|struct
name|fw_chnet_ifconf_params
block|{
name|__be32
name|r0
decl_stmt|;
name|__be16
name|vlanid
decl_stmt|;
name|__be16
name|mtu
decl_stmt|;
union|union
name|fw_chnet_ifconf_addr_type
block|{
struct|struct
name|fw_chnet_ifconf_ipv4
block|{
name|__be32
name|addr
decl_stmt|;
name|__be32
name|mask
decl_stmt|;
name|__be32
name|router
decl_stmt|;
name|__be32
name|r0
decl_stmt|;
name|__be64
name|r1
decl_stmt|;
block|}
name|ipv4
struct|;
struct|struct
name|fw_chnet_ifconf_ipv6
block|{
name|__u8
name|prefix_len
decl_stmt|;
name|__u8
name|r0
decl_stmt|;
name|__be16
name|r1
decl_stmt|;
name|__be32
name|r2
decl_stmt|;
name|__be64
name|addr_hi
decl_stmt|;
name|__be64
name|addr_lo
decl_stmt|;
name|__be64
name|router_hi
decl_stmt|;
name|__be64
name|router_lo
decl_stmt|;
block|}
name|ipv6
struct|;
block|}
name|in_attr
union|;
block|}
name|param
struct|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fw_foiscsi_node_type
block|{
name|FW_FOISCSI_NODE_TYPE_INITIATOR
init|=
literal|0
block|,
name|FW_FOISCSI_NODE_TYPE_TARGET
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_foiscsi_session_type
block|{
name|FW_FOISCSI_SESSION_TYPE_DISCOVERY
init|=
literal|0
block|,
name|FW_FOISCSI_SESSION_TYPE_NORMAL
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_foiscsi_auth_policy
block|{
name|FW_FOISCSI_AUTH_POLICY_ONEWAY
init|=
literal|0
block|,
name|FW_FOISCSI_AUTH_POLICY_MUTUAL
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_foiscsi_auth_method
block|{
name|FW_FOISCSI_AUTH_METHOD_NONE
init|=
literal|0
block|,
name|FW_FOISCSI_AUTH_METHOD_CHAP
block|,
name|FW_FOISCSI_AUTH_METHOD_CHAP_FST
block|,
name|FW_FOISCSI_AUTH_METHOD_CHAP_SEC
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_foiscsi_digest_type
block|{
name|FW_FOISCSI_DIGEST_TYPE_NONE
init|=
literal|0
block|,
name|FW_FOISCSI_DIGEST_TYPE_CRC32
block|,
name|FW_FOISCSI_DIGEST_TYPE_CRC32_FST
block|,
name|FW_FOISCSI_DIGEST_TYPE_CRC32_SEC
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_foiscsi_wr_subop
block|{
name|FW_FOISCSI_WR_SUBOP_ADD
init|=
literal|1
block|,
name|FW_FOISCSI_WR_SUBOP_DEL
init|=
literal|2
block|,
name|FW_FOISCSI_WR_SUBOP_MOD
init|=
literal|4
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_foiscsi_ctrl_state
block|{
name|FW_FOISCSI_CTRL_STATE_FREE
init|=
literal|0
block|,
name|FW_FOISCSI_CTRL_STATE_ONLINE
init|=
literal|1
block|,
name|FW_FOISCSI_CTRL_STATE_FAILED
block|,
name|FW_FOISCSI_CTRL_STATE_IN_RECOVERY
block|,
name|FW_FOISCSI_CTRL_STATE_REDIRECT
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_rdev_wr
block|{
name|__be32
name|op_to_immdlen
decl_stmt|;
name|__be32
name|alloc_to_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__u8
name|protocol
decl_stmt|;
name|__u8
name|event_cause
decl_stmt|;
name|__u8
name|cur_state
decl_stmt|;
name|__u8
name|prev_state
decl_stmt|;
name|__be32
name|flags_to_assoc_flowid
decl_stmt|;
union|union
name|rdev_entry
block|{
struct|struct
name|fcoe_rdev_entry
block|{
name|__be32
name|flowid
decl_stmt|;
name|__u8
name|protocol
decl_stmt|;
name|__u8
name|event_cause
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u8
name|rjt_reason
decl_stmt|;
name|__u8
name|cur_login_st
decl_stmt|;
name|__u8
name|prev_login_st
decl_stmt|;
name|__be16
name|rcv_fr_sz
decl_stmt|;
name|__u8
name|rd_xfer_rdy_to_rport_type
decl_stmt|;
name|__u8
name|vft_to_qos
decl_stmt|;
name|__u8
name|org_proc_assoc_to_acc_rsp_code
decl_stmt|;
name|__u8
name|enh_disc_to_tgt
decl_stmt|;
name|__u8
name|wwnn
index|[
literal|8
index|]
decl_stmt|;
name|__u8
name|wwpn
index|[
literal|8
index|]
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__u8
name|fc_oui
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|r_id
index|[
literal|3
index|]
decl_stmt|;
block|}
name|fcoe_rdev
struct|;
struct|struct
name|iscsi_rdev_entry
block|{
name|__be32
name|flowid
decl_stmt|;
name|__u8
name|protocol
decl_stmt|;
name|__u8
name|event_cause
decl_stmt|;
name|__u8
name|flags
decl_stmt|;
name|__u8
name|r3
decl_stmt|;
name|__be16
name|iscsi_opts
decl_stmt|;
name|__be16
name|tcp_opts
decl_stmt|;
name|__be16
name|ip_opts
decl_stmt|;
name|__be16
name|max_rcv_len
decl_stmt|;
name|__be16
name|max_snd_len
decl_stmt|;
name|__be16
name|first_brst_len
decl_stmt|;
name|__be16
name|max_brst_len
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__be16
name|def_time2wait
decl_stmt|;
name|__be16
name|def_time2ret
decl_stmt|;
name|__be16
name|nop_out_intrvl
decl_stmt|;
name|__be16
name|non_scsi_to
decl_stmt|;
name|__be16
name|isid
decl_stmt|;
name|__be16
name|tsid
decl_stmt|;
name|__be16
name|port
decl_stmt|;
name|__be16
name|tpgt
decl_stmt|;
name|__u8
name|r5
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
block|}
name|iscsi_rdev
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
name|S_FW_RDEV_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_IMMDLEN)& M_FW_RDEV_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_ALLOC
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_ALLOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_ALLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_ALLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_ALLOC)& M_FW_RDEV_WR_ALLOC)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_ALLOC
value|V_FW_RDEV_WR_ALLOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_FREE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_FREE)& M_FW_RDEV_WR_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_FREE
value|V_FW_RDEV_WR_FREE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_MODIFY
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_MODIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_MODIFY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_MODIFY)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_MODIFY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_MODIFY)& M_FW_RDEV_WR_MODIFY)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_MODIFY
value|V_FW_RDEV_WR_MODIFY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_FLOWID)& M_FW_RDEV_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_LEN16)& M_FW_RDEV_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_FLAGS
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_FLAGS
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_FLAGS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_FLAGS)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_FLAGS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_FLAGS)& M_FW_RDEV_WR_FLAGS)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_GET_NEXT
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_GET_NEXT
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_GET_NEXT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_GET_NEXT)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_GET_NEXT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_GET_NEXT)& M_FW_RDEV_WR_GET_NEXT)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_ASSOC_FLOWID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_ASSOC_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_ASSOC_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_ASSOC_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_ASSOC_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_ASSOC_FLOWID)& M_FW_RDEV_WR_ASSOC_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_RJT
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_RJT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_RJT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_RJT)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_RJT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_RDEV_WR_RJT)& M_FW_RDEV_WR_RJT)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_RJT
value|V_FW_RDEV_WR_RJT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_REASON
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_REASON
value|0x7f
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_REASON
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_REASON)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_REASON
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_REASON)& M_FW_RDEV_WR_REASON)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_RD_XFER_RDY
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_RD_XFER_RDY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_RD_XFER_RDY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_RD_XFER_RDY)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_RD_XFER_RDY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_RD_XFER_RDY)& M_FW_RDEV_WR_RD_XFER_RDY)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_RD_XFER_RDY
value|V_FW_RDEV_WR_RD_XFER_RDY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_WR_XFER_RDY
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_WR_XFER_RDY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_WR_XFER_RDY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_WR_XFER_RDY)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_WR_XFER_RDY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_WR_XFER_RDY)& M_FW_RDEV_WR_WR_XFER_RDY)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_WR_XFER_RDY
value|V_FW_RDEV_WR_WR_XFER_RDY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_FC_SP
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_FC_SP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_FC_SP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_FC_SP)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_FC_SP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_FC_SP)& M_FW_RDEV_WR_FC_SP)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_FC_SP
value|V_FW_RDEV_WR_FC_SP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_RPORT_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_RPORT_TYPE
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_RPORT_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_RPORT_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_RPORT_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_RPORT_TYPE)& M_FW_RDEV_WR_RPORT_TYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_VFT
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_VFT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_VFT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_VFT)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_VFT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_RDEV_WR_VFT)& M_FW_RDEV_WR_VFT)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_VFT
value|V_FW_RDEV_WR_VFT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_NPIV
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_NPIV
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_NPIV
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_NPIV)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_NPIV
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_NPIV)& M_FW_RDEV_WR_NPIV)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_NPIV
value|V_FW_RDEV_WR_NPIV(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_CLASS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_CLASS
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_CLASS)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_CLASS)& M_FW_RDEV_WR_CLASS)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_SEQ_DEL
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_SEQ_DEL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_SEQ_DEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_SEQ_DEL)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_SEQ_DEL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_SEQ_DEL)& M_FW_RDEV_WR_SEQ_DEL)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_SEQ_DEL
value|V_FW_RDEV_WR_SEQ_DEL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_PRIO_PREEMP
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_PRIO_PREEMP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_PRIO_PREEMP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_PRIO_PREEMP)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_PRIO_PREEMP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_PRIO_PREEMP)& M_FW_RDEV_WR_PRIO_PREEMP)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_PRIO_PREEMP
value|V_FW_RDEV_WR_PRIO_PREEMP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_PREF
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_PREF
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_PREF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_PREF)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_PREF
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_PREF)& M_FW_RDEV_WR_PREF)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_PREF
value|V_FW_RDEV_WR_PREF(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_QOS
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_QOS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_QOS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_QOS)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_QOS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_RDEV_WR_QOS)& M_FW_RDEV_WR_QOS)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_QOS
value|V_FW_RDEV_WR_QOS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_ORG_PROC_ASSOC
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_ORG_PROC_ASSOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_ORG_PROC_ASSOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_ORG_PROC_ASSOC)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_ORG_PROC_ASSOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_ORG_PROC_ASSOC)& M_FW_RDEV_WR_ORG_PROC_ASSOC)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_ORG_PROC_ASSOC
value|V_FW_RDEV_WR_ORG_PROC_ASSOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_RSP_PROC_ASSOC
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_RSP_PROC_ASSOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_RSP_PROC_ASSOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_RSP_PROC_ASSOC)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_RSP_PROC_ASSOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_RSP_PROC_ASSOC)& M_FW_RDEV_WR_RSP_PROC_ASSOC)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_RSP_PROC_ASSOC
value|V_FW_RDEV_WR_RSP_PROC_ASSOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_IMAGE_PAIR
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_IMAGE_PAIR
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_IMAGE_PAIR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_IMAGE_PAIR)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_IMAGE_PAIR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_IMAGE_PAIR)& M_FW_RDEV_WR_IMAGE_PAIR)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_IMAGE_PAIR
value|V_FW_RDEV_WR_IMAGE_PAIR(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_ACC_RSP_CODE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_ACC_RSP_CODE
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_ACC_RSP_CODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_ACC_RSP_CODE)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_ACC_RSP_CODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_ACC_RSP_CODE)& M_FW_RDEV_WR_ACC_RSP_CODE)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_ENH_DISC
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_ENH_DISC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_ENH_DISC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_ENH_DISC)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_ENH_DISC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_ENH_DISC)& M_FW_RDEV_WR_ENH_DISC)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_ENH_DISC
value|V_FW_RDEV_WR_ENH_DISC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_REC
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_REC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_REC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_REC)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_REC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_RDEV_WR_REC)& M_FW_RDEV_WR_REC)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_REC
value|V_FW_RDEV_WR_REC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_TASK_RETRY_ID
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_TASK_RETRY_ID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_TASK_RETRY_ID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_TASK_RETRY_ID)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_TASK_RETRY_ID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_TASK_RETRY_ID)& M_FW_RDEV_WR_TASK_RETRY_ID)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_TASK_RETRY_ID
value|V_FW_RDEV_WR_TASK_RETRY_ID(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_RETRY
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_RETRY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_RETRY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_RETRY)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_RETRY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_RETRY)& M_FW_RDEV_WR_RETRY)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_RETRY
value|V_FW_RDEV_WR_RETRY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_CONF_CMPL
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_CONF_CMPL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_CONF_CMPL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_CONF_CMPL)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_CONF_CMPL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_CONF_CMPL)& M_FW_RDEV_WR_CONF_CMPL)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_CONF_CMPL
value|V_FW_RDEV_WR_CONF_CMPL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_DATA_OVLY
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_DATA_OVLY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_DATA_OVLY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_DATA_OVLY)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_DATA_OVLY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RDEV_WR_DATA_OVLY)& M_FW_RDEV_WR_DATA_OVLY)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_DATA_OVLY
value|V_FW_RDEV_WR_DATA_OVLY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_INI
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_INI
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_INI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_INI)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_INI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_RDEV_WR_INI)& M_FW_RDEV_WR_INI)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_INI
value|V_FW_RDEV_WR_INI(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RDEV_WR_TGT
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RDEV_WR_TGT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RDEV_WR_TGT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RDEV_WR_TGT)
end_define

begin_define
define|#
directive|define
name|G_FW_RDEV_WR_TGT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_RDEV_WR_TGT)& M_FW_RDEV_WR_TGT)
end_define

begin_define
define|#
directive|define
name|F_FW_RDEV_WR_TGT
value|V_FW_RDEV_WR_TGT(1U)
end_define

begin_struct
struct|struct
name|fw_foiscsi_node_wr
block|{
name|__be32
name|op_to_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
name|__u8
name|subop
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|alias_len
decl_stmt|;
name|__u8
name|iqn_len
decl_stmt|;
name|__be32
name|node_flowid
decl_stmt|;
name|__be16
name|nodeid
decl_stmt|;
name|__be16
name|login_retry
decl_stmt|;
name|__be16
name|retry_timeout
decl_stmt|;
name|__be16
name|r3
decl_stmt|;
name|__u8
name|iqn
index|[
literal|224
index|]
decl_stmt|;
name|__u8
name|alias
index|[
literal|224
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_FOISCSI_NODE_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_NODE_WR_IMMDLEN
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_NODE_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FOISCSI_NODE_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_NODE_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_NODE_WR_IMMDLEN)& M_FW_FOISCSI_NODE_WR_IMMDLEN)
end_define

begin_struct
struct|struct
name|fw_foiscsi_ctrl_wr
block|{
name|__be32
name|op_compl
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
name|__u8
name|subop
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|ctrl_state
decl_stmt|;
name|__u8
name|io_state
decl_stmt|;
name|__be32
name|node_id
decl_stmt|;
name|__be32
name|ctrl_id
decl_stmt|;
name|__be32
name|io_id
decl_stmt|;
struct|struct
name|fw_foiscsi_sess_attr
block|{
name|__be32
name|sess_type_to_erl
decl_stmt|;
name|__be16
name|max_conn
decl_stmt|;
name|__be16
name|max_r2t
decl_stmt|;
name|__be16
name|time2wait
decl_stmt|;
name|__be16
name|time2retain
decl_stmt|;
name|__be32
name|max_burst
decl_stmt|;
name|__be32
name|first_burst
decl_stmt|;
name|__be32
name|r1
decl_stmt|;
block|}
name|sess_attr
struct|;
struct|struct
name|fw_foiscsi_conn_attr
block|{
name|__be32
name|hdigest_to_ddp_pgsz
decl_stmt|;
name|__be32
name|max_rcv_dsl
decl_stmt|;
name|__be32
name|ping_tmo
decl_stmt|;
name|__be16
name|dst_port
decl_stmt|;
name|__be16
name|src_port
decl_stmt|;
union|union
name|fw_foiscsi_conn_attr_addr
block|{
struct|struct
name|fw_foiscsi_conn_attr_ipv6
block|{
name|__be64
name|dst_addr
index|[
literal|2
index|]
decl_stmt|;
name|__be64
name|src_addr
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ipv6_addr
struct|;
struct|struct
name|fw_foiscsi_conn_attr_ipv4
block|{
name|__be32
name|dst_addr
decl_stmt|;
name|__be32
name|src_addr
decl_stmt|;
block|}
name|ipv4_addr
struct|;
block|}
name|u
union|;
block|}
name|conn_attr
struct|;
name|__u8
name|tgt_name_len
decl_stmt|;
name|__u8
name|r3
index|[
literal|7
index|]
decl_stmt|;
name|__u8
name|tgt_name
index|[
name|FW_FOISCSI_NAME_MAX_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_SESS_TYPE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_SESS_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_SESS_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_FOISCSI_CTRL_WR_SESS_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_SESS_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_SESS_TYPE)& M_FW_FOISCSI_CTRL_WR_SESS_TYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_SEQ_INORDER
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_SEQ_INORDER
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_SEQ_INORDER
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_FOISCSI_CTRL_WR_SEQ_INORDER)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_SEQ_INORDER
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_SEQ_INORDER)& \      M_FW_FOISCSI_CTRL_WR_SEQ_INORDER)
end_define

begin_define
define|#
directive|define
name|F_FW_FOISCSI_CTRL_WR_SEQ_INORDER
define|\
value|V_FW_FOISCSI_CTRL_WR_SEQ_INORDER(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_PDU_INORDER
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_PDU_INORDER
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_PDU_INORDER
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_FOISCSI_CTRL_WR_PDU_INORDER)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_PDU_INORDER
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_PDU_INORDER)& \      M_FW_FOISCSI_CTRL_WR_PDU_INORDER)
end_define

begin_define
define|#
directive|define
name|F_FW_FOISCSI_CTRL_WR_PDU_INORDER
define|\
value|V_FW_FOISCSI_CTRL_WR_PDU_INORDER(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_IMMD_DATA_EN
value|27
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_IMMD_DATA_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_IMMD_DATA_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_FOISCSI_CTRL_WR_IMMD_DATA_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_IMMD_DATA_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_IMMD_DATA_EN)& \      M_FW_FOISCSI_CTRL_WR_IMMD_DATA_EN)
end_define

begin_define
define|#
directive|define
name|F_FW_FOISCSI_CTRL_WR_IMMD_DATA_EN
define|\
value|V_FW_FOISCSI_CTRL_WR_IMMD_DATA_EN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_INIT_R2T_EN
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_INIT_R2T_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_INIT_R2T_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_FOISCSI_CTRL_WR_INIT_R2T_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_INIT_R2T_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_INIT_R2T_EN)& \      M_FW_FOISCSI_CTRL_WR_INIT_R2T_EN)
end_define

begin_define
define|#
directive|define
name|F_FW_FOISCSI_CTRL_WR_INIT_R2T_EN
define|\
value|V_FW_FOISCSI_CTRL_WR_INIT_R2T_EN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_ERL
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_ERL
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_ERL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FOISCSI_CTRL_WR_ERL)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_ERL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_ERL)& M_FW_FOISCSI_CTRL_WR_ERL)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_HDIGEST
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_HDIGEST
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_HDIGEST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FOISCSI_CTRL_WR_HDIGEST)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_HDIGEST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_HDIGEST)& M_FW_FOISCSI_CTRL_WR_HDIGEST)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_DDIGEST
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_DDIGEST
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_DDIGEST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FOISCSI_CTRL_WR_DDIGEST)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_DDIGEST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_DDIGEST)& M_FW_FOISCSI_CTRL_WR_DDIGEST)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_AUTH_METHOD
value|25
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_AUTH_METHOD
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_AUTH_METHOD
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_FOISCSI_CTRL_WR_AUTH_METHOD)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_AUTH_METHOD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_AUTH_METHOD)& \      M_FW_FOISCSI_CTRL_WR_AUTH_METHOD)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_AUTH_POLICY
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_AUTH_POLICY
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_AUTH_POLICY
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_FOISCSI_CTRL_WR_AUTH_POLICY)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_AUTH_POLICY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_AUTH_POLICY)& \      M_FW_FOISCSI_CTRL_WR_AUTH_POLICY)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_DDP_PGSZ
value|21
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_DDP_PGSZ
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_DDP_PGSZ
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_FOISCSI_CTRL_WR_DDP_PGSZ)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_DDP_PGSZ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_DDP_PGSZ)& M_FW_FOISCSI_CTRL_WR_DDP_PGSZ)
end_define

begin_define
define|#
directive|define
name|S_FW_FOISCSI_CTRL_WR_IPV6
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_FOISCSI_CTRL_WR_IPV6
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FOISCSI_CTRL_WR_IPV6
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FOISCSI_CTRL_WR_IPV6)
end_define

begin_define
define|#
directive|define
name|G_FW_FOISCSI_CTRL_WR_IPV6
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FOISCSI_CTRL_WR_IPV6)& M_FW_FOISCSI_CTRL_WR_IPV6)
end_define

begin_define
define|#
directive|define
name|F_FW_FOISCSI_CTRL_WR_IPV6
value|V_FW_FOISCSI_CTRL_WR_IPV6(1U)
end_define

begin_struct
struct|struct
name|fw_foiscsi_chap_wr
block|{
name|__be32
name|op_compl
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|id_len
decl_stmt|;
name|__u8
name|sec_len
decl_stmt|;
name|__u8
name|node_type
decl_stmt|;
name|__be16
name|node_id
decl_stmt|;
name|__u8
name|r3
index|[
literal|2
index|]
decl_stmt|;
name|__u8
name|chap_id
index|[
name|FW_FOISCSI_NAME_MAX_LEN
index|]
decl_stmt|;
name|__u8
name|chap_sec
index|[
name|FW_FOISCSI_CHAP_SEC_MAX_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/******************************************************************************  *  C O i S C S I  W O R K R E Q U E S T S  ********************************************/
end_comment

begin_enum
enum|enum
name|fw_chnet_addr_type
block|{
name|FW_CHNET_ADDD_TYPE_NONE
init|=
literal|0
block|,
name|FW_CHNET_ADDR_TYPE_IPV4
block|,
name|FW_CHNET_ADDR_TYPE_IPV6
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_msg_wr_type
block|{
name|FW_MSG_WR_TYPE_RPL
init|=
literal|0
block|,
name|FW_MSG_WR_TYPE_ERR
block|,
name|FW_MSG_WR_TYPE_PLD
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_coiscsi_tgt_wr
block|{
name|__be32
name|op_compl
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
name|__u8
name|subop
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__be32
name|flags
decl_stmt|;
struct|struct
name|fw_coiscsi_tgt_conn_attr
block|{
name|__be32
name|in_tid
decl_stmt|;
name|__be16
name|in_port
decl_stmt|;
name|__u8
name|in_type
decl_stmt|;
name|__u8
name|r6
decl_stmt|;
union|union
name|fw_coiscsi_tgt_conn_attr_addr
block|{
struct|struct
name|fw_coiscsi_tgt_conn_attr_in_addr
block|{
name|__be32
name|addr
decl_stmt|;
name|__be32
name|r7
decl_stmt|;
name|__be32
name|r8
index|[
literal|2
index|]
decl_stmt|;
block|}
name|in_addr
struct|;
struct|struct
name|fw_coiscsi_tgt_conn_attr_in_addr6
block|{
name|__be64
name|addr
index|[
literal|2
index|]
decl_stmt|;
block|}
name|in_addr6
struct|;
block|}
name|u
union|;
block|}
name|conn_attr
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_coiscsi_tgt_conn_wr
block|{
name|__be32
name|op_compl
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
name|__u8
name|subop
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__be16
name|iq_id
decl_stmt|;
name|__be32
name|in_stid
decl_stmt|;
name|__be32
name|io_id
decl_stmt|;
name|__be32
name|flags
decl_stmt|;
struct|struct
name|fw_coiscsi_tgt_conn_tcp
block|{
name|__be16
name|in_sport
decl_stmt|;
name|__be16
name|in_dport
decl_stmt|;
name|__be32
name|r4
decl_stmt|;
union|union
name|fw_coiscsi_tgt_conn_tcp_addr
block|{
struct|struct
name|fw_coiscsi_tgt_conn_tcp_in_addr
block|{
name|__be32
name|saddr
decl_stmt|;
name|__be32
name|daddr
decl_stmt|;
block|}
name|in_addr
struct|;
struct|struct
name|fw_coiscsi_tgt_conn_tcp_in_addr6
block|{
name|__be64
name|saddr
index|[
literal|2
index|]
decl_stmt|;
name|__be64
name|daddr
index|[
literal|2
index|]
decl_stmt|;
block|}
name|in_addr6
struct|;
block|}
name|u
union|;
block|}
name|conn_tcp
struct|;
struct|struct
name|fw_coiscsi_tgt_conn_iscsi
block|{
name|__be32
name|hdigest_to_ddp_pgsz
decl_stmt|;
name|__be32
name|tgt_id
decl_stmt|;
name|__be16
name|max_r2t
decl_stmt|;
name|__be16
name|r5
decl_stmt|;
name|__be32
name|max_burst
decl_stmt|;
name|__be32
name|max_rdsl
decl_stmt|;
name|__be32
name|max_tdsl
decl_stmt|;
name|__be32
name|nxt_sn
decl_stmt|;
name|__be32
name|r6
decl_stmt|;
block|}
name|conn_iscsi
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_coiscsi_tgt_xmit_wr
block|{
name|__be32
name|op_to_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be16
name|iq_id
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__be32
name|datasn
decl_stmt|;
name|__be32
name|t_xfer_len
decl_stmt|;
name|__be32
name|flags
decl_stmt|;
name|__be32
name|tag
decl_stmt|;
name|__be32
name|tidx
decl_stmt|;
name|__be32
name|r5
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
name|S_FW_COiSCSI_TGT_XMIT_WR_DDGST
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_COiSCSI_TGT_XMIT_WR_DDGST
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_COiSCSI_TGT_XMIT_WR_DDGST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_COiSCSI_TGT_XMIT_WR_DDGST)
end_define

begin_define
define|#
directive|define
name|G_FW_COiSCSI_TGT_XMIT_WR_DDGST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_COiSCSI_TGT_XMIT_WR_DDGST)& M_FW_COiSCSI_TGT_XMIT_WR_DDGST)
end_define

begin_define
define|#
directive|define
name|F_FW_COiSCSI_TGT_XMIT_WR_DDGST
value|V_FW_COiSCSI_TGT_XMIT_WR_DDGST(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_COiSCSI_TGT_XMIT_WR_HDGST
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_COiSCSI_TGT_XMIT_WR_HDGST
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_COiSCSI_TGT_XMIT_WR_HDGST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_COiSCSI_TGT_XMIT_WR_HDGST)
end_define

begin_define
define|#
directive|define
name|G_FW_COiSCSI_TGT_XMIT_WR_HDGST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_COiSCSI_TGT_XMIT_WR_HDGST)& M_FW_COiSCSI_TGT_XMIT_WR_HDGST)
end_define

begin_define
define|#
directive|define
name|F_FW_COiSCSI_TGT_XMIT_WR_HDGST
value|V_FW_COiSCSI_TGT_XMIT_WR_HDGST(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_COiSCSI_TGT_XMIT_WR_DDP
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_COiSCSI_TGT_XMIT_WR_DDP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_COiSCSI_TGT_XMIT_WR_DDP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_COiSCSI_TGT_XMIT_WR_DDP)
end_define

begin_define
define|#
directive|define
name|G_FW_COiSCSI_TGT_XMIT_WR_DDP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_COiSCSI_TGT_XMIT_WR_DDP)& M_FW_COiSCSI_TGT_XMIT_WR_DDP)
end_define

begin_define
define|#
directive|define
name|F_FW_COiSCSI_TGT_XMIT_WR_DDP
value|V_FW_COiSCSI_TGT_XMIT_WR_DDP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_COiSCSI_TGT_XMIT_WR_ABORT
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_COiSCSI_TGT_XMIT_WR_ABORT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_COiSCSI_TGT_XMIT_WR_ABORT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_COiSCSI_TGT_XMIT_WR_ABORT)
end_define

begin_define
define|#
directive|define
name|G_FW_COiSCSI_TGT_XMIT_WR_ABORT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_COiSCSI_TGT_XMIT_WR_ABORT)& M_FW_COiSCSI_TGT_XMIT_WR_ABORT)
end_define

begin_define
define|#
directive|define
name|F_FW_COiSCSI_TGT_XMIT_WR_ABORT
value|V_FW_COiSCSI_TGT_XMIT_WR_ABORT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_COiSCSI_TGT_XMIT_WR_FINAL
value|18
end_define

begin_define
define|#
directive|define
name|M_FW_COiSCSI_TGT_XMIT_WR_FINAL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_COiSCSI_TGT_XMIT_WR_FINAL
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_COiSCSI_TGT_XMIT_WR_FINAL)
end_define

begin_define
define|#
directive|define
name|G_FW_COiSCSI_TGT_XMIT_WR_FINAL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_COiSCSI_TGT_XMIT_WR_FINAL)& M_FW_COiSCSI_TGT_XMIT_WR_FINAL)
end_define

begin_define
define|#
directive|define
name|F_FW_COiSCSI_TGT_XMIT_WR_FINAL
value|V_FW_COiSCSI_TGT_XMIT_WR_FINAL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_COiSCSI_TGT_XMIT_WR_PADLEN
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_COiSCSI_TGT_XMIT_WR_PADLEN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_COiSCSI_TGT_XMIT_WR_PADLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_COiSCSI_TGT_XMIT_WR_PADLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_COiSCSI_TGT_XMIT_WR_PADLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_COiSCSI_TGT_XMIT_WR_PADLEN)& \      M_FW_COiSCSI_TGT_XMIT_WR_PADLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_COiSCSI_TGT_XMIT_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_COiSCSI_TGT_XMIT_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_COiSCSI_TGT_XMIT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_COiSCSI_TGT_XMIT_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_COiSCSI_TGT_XMIT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_COiSCSI_TGT_XMIT_WR_IMMDLEN)& \      M_FW_COiSCSI_TGT_XMIT_WR_IMMDLEN)
end_define

begin_struct
struct|struct
name|fw_isns_wr
block|{
name|__be32
name|op_compl
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
name|__u8
name|subop
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__be16
name|iq_id
decl_stmt|;
name|__be32
name|r4
decl_stmt|;
struct|struct
name|fw_tcp_conn_attr
block|{
name|__be32
name|in_tid
decl_stmt|;
name|__be16
name|in_port
decl_stmt|;
name|__u8
name|in_type
decl_stmt|;
name|__u8
name|r6
decl_stmt|;
union|union
name|fw_tcp_conn_attr_addr
block|{
struct|struct
name|fw_tcp_conn_attr_in_addr
block|{
name|__be32
name|addr
decl_stmt|;
name|__be32
name|r7
decl_stmt|;
name|__be32
name|r8
index|[
literal|2
index|]
decl_stmt|;
block|}
name|in_addr
struct|;
struct|struct
name|fw_tcp_conn_attr_in_addr6
block|{
name|__be64
name|addr
index|[
literal|2
index|]
decl_stmt|;
block|}
name|in_addr6
struct|;
block|}
name|u
union|;
block|}
name|conn_attr
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_isns_xmit_wr
block|{
name|__be32
name|op_to_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be16
name|iq_id
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__be32
name|xfer_len
decl_stmt|;
name|__be64
name|r5
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_ISNS_XMIT_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ISNS_XMIT_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_ISNS_XMIT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ISNS_XMIT_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_ISNS_XMIT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ISNS_XMIT_WR_IMMDLEN)& M_FW_ISNS_XMIT_WR_IMMDLEN)
end_define

begin_comment
comment|/******************************************************************************  *  F O F C O E   W O R K R E Q U E S T s  *******************************************/
end_comment

begin_struct
struct|struct
name|fw_fcoe_els_ct_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__u8
name|tmo_val
decl_stmt|;
name|__u8
name|els_ct_type
decl_stmt|;
name|__u8
name|ctl_pri
decl_stmt|;
name|__u8
name|cp_en_class
decl_stmt|;
name|__be16
name|xfer_cnt
decl_stmt|;
name|__u8
name|fl_to_sp
decl_stmt|;
name|__u8
name|l_id
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|r5
decl_stmt|;
name|__u8
name|r_id
index|[
literal|3
index|]
decl_stmt|;
name|__be64
name|rsp_dmaaddr
decl_stmt|;
name|__be32
name|rsp_dmalen
decl_stmt|;
name|__be32
name|r6
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_FCOE_ELS_CT_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_ELS_CT_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_ELS_CT_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_ELS_CT_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_ELS_CT_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_ELS_CT_WR_OPCODE)& M_FW_FCOE_ELS_CT_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_ELS_CT_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_ELS_CT_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_ELS_CT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_ELS_CT_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_ELS_CT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_ELS_CT_WR_IMMDLEN)& M_FW_FCOE_ELS_CT_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_ELS_CT_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_ELS_CT_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_ELS_CT_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_ELS_CT_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_ELS_CT_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_ELS_CT_WR_FLOWID)& M_FW_FCOE_ELS_CT_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_ELS_CT_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_ELS_CT_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_ELS_CT_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_ELS_CT_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_ELS_CT_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_ELS_CT_WR_LEN16)& M_FW_FCOE_ELS_CT_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_ELS_CT_WR_CP_EN
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_ELS_CT_WR_CP_EN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_ELS_CT_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_ELS_CT_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_ELS_CT_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_ELS_CT_WR_CP_EN)& M_FW_FCOE_ELS_CT_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_ELS_CT_WR_CLASS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_ELS_CT_WR_CLASS
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_ELS_CT_WR_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_ELS_CT_WR_CLASS)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_ELS_CT_WR_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_ELS_CT_WR_CLASS)& M_FW_FCOE_ELS_CT_WR_CLASS)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_ELS_CT_WR_FL
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_ELS_CT_WR_FL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_ELS_CT_WR_FL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_ELS_CT_WR_FL)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_ELS_CT_WR_FL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_ELS_CT_WR_FL)& M_FW_FCOE_ELS_CT_WR_FL)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_ELS_CT_WR_FL
value|V_FW_FCOE_ELS_CT_WR_FL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_ELS_CT_WR_NPIV
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_ELS_CT_WR_NPIV
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_ELS_CT_WR_NPIV
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_ELS_CT_WR_NPIV)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_ELS_CT_WR_NPIV
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_ELS_CT_WR_NPIV)& M_FW_FCOE_ELS_CT_WR_NPIV)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_ELS_CT_WR_NPIV
value|V_FW_FCOE_ELS_CT_WR_NPIV(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_ELS_CT_WR_SP
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_ELS_CT_WR_SP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_ELS_CT_WR_SP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_ELS_CT_WR_SP)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_ELS_CT_WR_SP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_ELS_CT_WR_SP)& M_FW_FCOE_ELS_CT_WR_SP)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_ELS_CT_WR_SP
value|V_FW_FCOE_ELS_CT_WR_SP(1U)
end_define

begin_comment
comment|/******************************************************************************  *  S C S I   W O R K R E Q U E S T s   (FOiSCSI and FCOE unified data path)  *****************************************************************************/
end_comment

begin_struct
struct|struct
name|fw_scsi_write_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__u8
name|tmo_val
decl_stmt|;
name|__u8
name|use_xfer_cnt
decl_stmt|;
union|union
name|fw_scsi_write_priv
block|{
struct|struct
name|fcoe_write_priv
block|{
name|__u8
name|ctl_pri
decl_stmt|;
name|__u8
name|cp_en_class
decl_stmt|;
name|__u8
name|r3_lo
index|[
literal|2
index|]
decl_stmt|;
block|}
name|fcoe
struct|;
struct|struct
name|iscsi_write_priv
block|{
name|__u8
name|r3
index|[
literal|4
index|]
decl_stmt|;
block|}
name|iscsi
struct|;
block|}
name|u
union|;
name|__be32
name|xfer_cnt
decl_stmt|;
name|__be32
name|ini_xfer_cnt
decl_stmt|;
name|__be64
name|rsp_dmaaddr
decl_stmt|;
name|__be32
name|rsp_dmalen
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
name|S_FW_SCSI_WRITE_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_WRITE_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_WRITE_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_WRITE_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_WRITE_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_WRITE_WR_OPCODE)& M_FW_SCSI_WRITE_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_WRITE_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_WRITE_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_WRITE_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_WRITE_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_WRITE_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_WRITE_WR_IMMDLEN)& M_FW_SCSI_WRITE_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_WRITE_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_WRITE_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_WRITE_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_WRITE_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_WRITE_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_WRITE_WR_FLOWID)& M_FW_SCSI_WRITE_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_WRITE_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_WRITE_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_WRITE_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_WRITE_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_WRITE_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_WRITE_WR_LEN16)& M_FW_SCSI_WRITE_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_WRITE_WR_CP_EN
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_WRITE_WR_CP_EN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_WRITE_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_WRITE_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_WRITE_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_WRITE_WR_CP_EN)& M_FW_SCSI_WRITE_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_WRITE_WR_CLASS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_WRITE_WR_CLASS
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_WRITE_WR_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_WRITE_WR_CLASS)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_WRITE_WR_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_WRITE_WR_CLASS)& M_FW_SCSI_WRITE_WR_CLASS)
end_define

begin_struct
struct|struct
name|fw_scsi_read_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__u8
name|tmo_val
decl_stmt|;
name|__u8
name|use_xfer_cnt
decl_stmt|;
union|union
name|fw_scsi_read_priv
block|{
struct|struct
name|fcoe_read_priv
block|{
name|__u8
name|ctl_pri
decl_stmt|;
name|__u8
name|cp_en_class
decl_stmt|;
name|__u8
name|r3_lo
index|[
literal|2
index|]
decl_stmt|;
block|}
name|fcoe
struct|;
struct|struct
name|iscsi_read_priv
block|{
name|__u8
name|r3
index|[
literal|4
index|]
decl_stmt|;
block|}
name|iscsi
struct|;
block|}
name|u
union|;
name|__be32
name|xfer_cnt
decl_stmt|;
name|__be32
name|ini_xfer_cnt
decl_stmt|;
name|__be64
name|rsp_dmaaddr
decl_stmt|;
name|__be32
name|rsp_dmalen
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
name|S_FW_SCSI_READ_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_READ_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_READ_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_READ_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_READ_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_READ_WR_OPCODE)& M_FW_SCSI_READ_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_READ_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_READ_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_READ_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_READ_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_READ_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_READ_WR_IMMDLEN)& M_FW_SCSI_READ_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_READ_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_READ_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_READ_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_READ_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_READ_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_READ_WR_FLOWID)& M_FW_SCSI_READ_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_READ_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_READ_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_READ_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_READ_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_READ_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_READ_WR_LEN16)& M_FW_SCSI_READ_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_READ_WR_CP_EN
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_READ_WR_CP_EN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_READ_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_READ_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_READ_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_READ_WR_CP_EN)& M_FW_SCSI_READ_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_READ_WR_CLASS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_READ_WR_CLASS
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_READ_WR_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_READ_WR_CLASS)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_READ_WR_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_READ_WR_CLASS)& M_FW_SCSI_READ_WR_CLASS)
end_define

begin_struct
struct|struct
name|fw_scsi_cmd_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__u8
name|tmo_val
decl_stmt|;
name|__u8
name|r3
decl_stmt|;
union|union
name|fw_scsi_cmd_priv
block|{
struct|struct
name|fcoe_cmd_priv
block|{
name|__u8
name|ctl_pri
decl_stmt|;
name|__u8
name|cp_en_class
decl_stmt|;
name|__u8
name|r4_lo
index|[
literal|2
index|]
decl_stmt|;
block|}
name|fcoe
struct|;
struct|struct
name|iscsi_cmd_priv
block|{
name|__u8
name|r4
index|[
literal|4
index|]
decl_stmt|;
block|}
name|iscsi
struct|;
block|}
name|u
union|;
name|__u8
name|r5
index|[
literal|8
index|]
decl_stmt|;
name|__be64
name|rsp_dmaaddr
decl_stmt|;
name|__be32
name|rsp_dmalen
decl_stmt|;
name|__be32
name|r6
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_SCSI_CMD_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_CMD_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_CMD_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_CMD_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_CMD_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_CMD_WR_OPCODE)& M_FW_SCSI_CMD_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_CMD_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_CMD_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_CMD_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_CMD_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_CMD_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_CMD_WR_IMMDLEN)& M_FW_SCSI_CMD_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_CMD_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_CMD_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_CMD_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_CMD_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_CMD_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_CMD_WR_FLOWID)& M_FW_SCSI_CMD_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_CMD_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_CMD_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_CMD_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_CMD_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_CMD_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_CMD_WR_LEN16)& M_FW_SCSI_CMD_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_CMD_WR_CP_EN
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_CMD_WR_CP_EN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_CMD_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_CMD_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_CMD_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_CMD_WR_CP_EN)& M_FW_SCSI_CMD_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_CMD_WR_CLASS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_CMD_WR_CLASS
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_CMD_WR_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_CMD_WR_CLASS)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_CMD_WR_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_CMD_WR_CLASS)& M_FW_SCSI_CMD_WR_CLASS)
end_define

begin_struct
struct|struct
name|fw_scsi_abrt_cls_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__u8
name|tmo_val
decl_stmt|;
name|__u8
name|sub_opcode_to_chk_all_io
decl_stmt|;
name|__u8
name|r3
index|[
literal|4
index|]
decl_stmt|;
name|__be64
name|t_cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_SCSI_ABRT_CLS_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_ABRT_CLS_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_ABRT_CLS_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_ABRT_CLS_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_ABRT_CLS_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_ABRT_CLS_WR_OPCODE)& M_FW_SCSI_ABRT_CLS_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_ABRT_CLS_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_ABRT_CLS_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_ABRT_CLS_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_SCSI_ABRT_CLS_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_ABRT_CLS_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_ABRT_CLS_WR_IMMDLEN)& M_FW_SCSI_ABRT_CLS_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_ABRT_CLS_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_ABRT_CLS_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_ABRT_CLS_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_ABRT_CLS_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_ABRT_CLS_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_ABRT_CLS_WR_FLOWID)& M_FW_SCSI_ABRT_CLS_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_ABRT_CLS_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_ABRT_CLS_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_ABRT_CLS_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_ABRT_CLS_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_ABRT_CLS_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_ABRT_CLS_WR_LEN16)& M_FW_SCSI_ABRT_CLS_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_ABRT_CLS_WR_SUB_OPCODE
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_ABRT_CLS_WR_SUB_OPCODE
value|0x3f
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_ABRT_CLS_WR_SUB_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_SCSI_ABRT_CLS_WR_SUB_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_ABRT_CLS_WR_SUB_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_ABRT_CLS_WR_SUB_OPCODE)& \      M_FW_SCSI_ABRT_CLS_WR_SUB_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_ABRT_CLS_WR_UNSOL
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_ABRT_CLS_WR_UNSOL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_ABRT_CLS_WR_UNSOL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_ABRT_CLS_WR_UNSOL)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_ABRT_CLS_WR_UNSOL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_ABRT_CLS_WR_UNSOL)& M_FW_SCSI_ABRT_CLS_WR_UNSOL)
end_define

begin_define
define|#
directive|define
name|F_FW_SCSI_ABRT_CLS_WR_UNSOL
value|V_FW_SCSI_ABRT_CLS_WR_UNSOL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_ABRT_CLS_WR_CHK_ALL_IO
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_ABRT_CLS_WR_CHK_ALL_IO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_ABRT_CLS_WR_CHK_ALL_IO
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_SCSI_ABRT_CLS_WR_CHK_ALL_IO)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_ABRT_CLS_WR_CHK_ALL_IO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_ABRT_CLS_WR_CHK_ALL_IO)& \      M_FW_SCSI_ABRT_CLS_WR_CHK_ALL_IO)
end_define

begin_define
define|#
directive|define
name|F_FW_SCSI_ABRT_CLS_WR_CHK_ALL_IO
define|\
value|V_FW_SCSI_ABRT_CLS_WR_CHK_ALL_IO(1U)
end_define

begin_struct
struct|struct
name|fw_scsi_tgt_acc_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__u8
name|r3
decl_stmt|;
name|__u8
name|use_burst_len
decl_stmt|;
union|union
name|fw_scsi_tgt_acc_priv
block|{
struct|struct
name|fcoe_tgt_acc_priv
block|{
name|__u8
name|ctl_pri
decl_stmt|;
name|__u8
name|cp_en_class
decl_stmt|;
name|__u8
name|r4_lo
index|[
literal|2
index|]
decl_stmt|;
block|}
name|fcoe
struct|;
struct|struct
name|iscsi_tgt_acc_priv
block|{
name|__u8
name|r4
index|[
literal|4
index|]
decl_stmt|;
block|}
name|iscsi
struct|;
block|}
name|u
union|;
name|__be32
name|burst_len
decl_stmt|;
name|__be32
name|rel_off
decl_stmt|;
name|__be64
name|r5
decl_stmt|;
name|__be32
name|r6
decl_stmt|;
name|__be32
name|tot_xfer_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_ACC_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_ACC_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_ACC_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_ACC_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_ACC_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_ACC_WR_OPCODE)& M_FW_SCSI_TGT_ACC_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_ACC_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_ACC_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_ACC_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_ACC_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_ACC_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_ACC_WR_IMMDLEN)& M_FW_SCSI_TGT_ACC_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_ACC_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_ACC_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_ACC_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_ACC_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_ACC_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_ACC_WR_FLOWID)& M_FW_SCSI_TGT_ACC_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_ACC_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_ACC_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_ACC_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_ACC_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_ACC_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_ACC_WR_LEN16)& M_FW_SCSI_TGT_ACC_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_ACC_WR_CP_EN
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_ACC_WR_CP_EN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_ACC_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_ACC_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_ACC_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_ACC_WR_CP_EN)& M_FW_SCSI_TGT_ACC_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_ACC_WR_CLASS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_ACC_WR_CLASS
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_ACC_WR_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_ACC_WR_CLASS)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_ACC_WR_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_ACC_WR_CLASS)& M_FW_SCSI_TGT_ACC_WR_CLASS)
end_define

begin_struct
struct|struct
name|fw_scsi_tgt_xmit_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__u8
name|auto_rsp
decl_stmt|;
name|__u8
name|use_xfer_cnt
decl_stmt|;
union|union
name|fw_scsi_tgt_xmit_priv
block|{
struct|struct
name|fcoe_tgt_xmit_priv
block|{
name|__u8
name|ctl_pri
decl_stmt|;
name|__u8
name|cp_en_class
decl_stmt|;
name|__u8
name|r3_lo
index|[
literal|2
index|]
decl_stmt|;
block|}
name|fcoe
struct|;
struct|struct
name|iscsi_tgt_xmit_priv
block|{
name|__u8
name|r3
index|[
literal|4
index|]
decl_stmt|;
block|}
name|iscsi
struct|;
block|}
name|u
union|;
name|__be32
name|xfer_cnt
decl_stmt|;
name|__be32
name|r4
decl_stmt|;
name|__be64
name|r5
decl_stmt|;
name|__be32
name|r6
decl_stmt|;
name|__be32
name|tot_xfer_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_XMIT_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_XMIT_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_XMIT_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_XMIT_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_XMIT_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_XMIT_WR_OPCODE)& M_FW_SCSI_TGT_XMIT_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_XMIT_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_XMIT_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_XMIT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_SCSI_TGT_XMIT_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_XMIT_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_XMIT_WR_IMMDLEN)& M_FW_SCSI_TGT_XMIT_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_XMIT_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_XMIT_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_XMIT_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_XMIT_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_XMIT_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_XMIT_WR_FLOWID)& M_FW_SCSI_TGT_XMIT_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_XMIT_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_XMIT_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_XMIT_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_XMIT_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_XMIT_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_XMIT_WR_LEN16)& M_FW_SCSI_TGT_XMIT_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_XMIT_WR_CP_EN
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_XMIT_WR_CP_EN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_XMIT_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_XMIT_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_XMIT_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_XMIT_WR_CP_EN)& M_FW_SCSI_TGT_XMIT_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_XMIT_WR_CLASS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_XMIT_WR_CLASS
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_XMIT_WR_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_XMIT_WR_CLASS)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_XMIT_WR_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_XMIT_WR_CLASS)& M_FW_SCSI_TGT_XMIT_WR_CLASS)
end_define

begin_struct
struct|struct
name|fw_scsi_tgt_rsp_wr
block|{
name|__be32
name|op_immdlen
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__u8
name|r3
index|[
literal|2
index|]
decl_stmt|;
union|union
name|fw_scsi_tgt_rsp_priv
block|{
struct|struct
name|fcoe_tgt_rsp_priv
block|{
name|__u8
name|ctl_pri
decl_stmt|;
name|__u8
name|cp_en_class
decl_stmt|;
name|__u8
name|r4_lo
index|[
literal|2
index|]
decl_stmt|;
block|}
name|fcoe
struct|;
struct|struct
name|iscsi_tgt_rsp_priv
block|{
name|__u8
name|r4
index|[
literal|4
index|]
decl_stmt|;
block|}
name|iscsi
struct|;
block|}
name|u
union|;
name|__u8
name|r5
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_RSP_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_RSP_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_RSP_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_RSP_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_RSP_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_RSP_WR_OPCODE)& M_FW_SCSI_TGT_RSP_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_RSP_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_RSP_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_RSP_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_RSP_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_RSP_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_RSP_WR_IMMDLEN)& M_FW_SCSI_TGT_RSP_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_RSP_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_RSP_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_RSP_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_RSP_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_RSP_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_RSP_WR_FLOWID)& M_FW_SCSI_TGT_RSP_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_RSP_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_RSP_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_RSP_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_RSP_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_RSP_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_RSP_WR_LEN16)& M_FW_SCSI_TGT_RSP_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_RSP_WR_CP_EN
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_RSP_WR_CP_EN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_RSP_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_RSP_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_RSP_WR_CP_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_RSP_WR_CP_EN)& M_FW_SCSI_TGT_RSP_WR_CP_EN)
end_define

begin_define
define|#
directive|define
name|S_FW_SCSI_TGT_RSP_WR_CLASS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_SCSI_TGT_RSP_WR_CLASS
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_SCSI_TGT_RSP_WR_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_SCSI_TGT_RSP_WR_CLASS)
end_define

begin_define
define|#
directive|define
name|G_FW_SCSI_TGT_RSP_WR_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_SCSI_TGT_RSP_WR_CLASS)& M_FW_SCSI_TGT_RSP_WR_CLASS)
end_define

begin_struct
struct|struct
name|fw_pofcoe_tcb_wr
block|{
name|__be32
name|op_compl
decl_stmt|;
name|__be32
name|equiq_to_len16
decl_stmt|;
name|__be32
name|r4
decl_stmt|;
name|__be32
name|xfer_len
decl_stmt|;
name|__be32
name|tid_to_port
decl_stmt|;
name|__be16
name|x_id
decl_stmt|;
name|__be16
name|vlan_id
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
name|__be32
name|s_id
decl_stmt|;
name|__be32
name|d_id
decl_stmt|;
name|__be32
name|tag
decl_stmt|;
name|__be16
name|r6
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_POFCOE_TCB_WR_TID
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_POFCOE_TCB_WR_TID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_POFCOE_TCB_WR_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_POFCOE_TCB_WR_TID)
end_define

begin_define
define|#
directive|define
name|G_FW_POFCOE_TCB_WR_TID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_POFCOE_TCB_WR_TID)& M_FW_POFCOE_TCB_WR_TID)
end_define

begin_define
define|#
directive|define
name|S_FW_POFCOE_TCB_WR_ALLOC
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_POFCOE_TCB_WR_ALLOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_POFCOE_TCB_WR_ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_POFCOE_TCB_WR_ALLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_POFCOE_TCB_WR_ALLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_POFCOE_TCB_WR_ALLOC)& M_FW_POFCOE_TCB_WR_ALLOC)
end_define

begin_define
define|#
directive|define
name|F_FW_POFCOE_TCB_WR_ALLOC
value|V_FW_POFCOE_TCB_WR_ALLOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_POFCOE_TCB_WR_FREE
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_POFCOE_TCB_WR_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_POFCOE_TCB_WR_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_POFCOE_TCB_WR_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_POFCOE_TCB_WR_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_POFCOE_TCB_WR_FREE)& M_FW_POFCOE_TCB_WR_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_POFCOE_TCB_WR_FREE
value|V_FW_POFCOE_TCB_WR_FREE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_POFCOE_TCB_WR_PORT
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_POFCOE_TCB_WR_PORT
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_POFCOE_TCB_WR_PORT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_POFCOE_TCB_WR_PORT)
end_define

begin_define
define|#
directive|define
name|G_FW_POFCOE_TCB_WR_PORT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_POFCOE_TCB_WR_PORT)& M_FW_POFCOE_TCB_WR_PORT)
end_define

begin_struct
struct|struct
name|fw_pofcoe_ulptx_wr
block|{
name|__be32
name|op_pkd
decl_stmt|;
name|__be32
name|equiq_to_len16
decl_stmt|;
name|__u64
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*******************************************************************  *  T10 DIF related definition  *******************************************************************/
end_comment

begin_struct
struct|struct
name|fw_tx_pi_header
block|{
name|__be16
name|op_to_inline
decl_stmt|;
name|__u8
name|pi_interval_tag_type
decl_stmt|;
name|__u8
name|num_pi
decl_stmt|;
name|__be32
name|pi_start4_pi_end4
decl_stmt|;
name|__u8
name|tag_gen_enabled_pkd
decl_stmt|;
name|__u8
name|num_pi_dsg
decl_stmt|;
name|__be16
name|app_tag
decl_stmt|;
name|__be32
name|ref_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_OP
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_OP
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_OP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TX_PI_HEADER_OP)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_OP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_OP)& M_FW_TX_PI_HEADER_OP)
end_define

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_ULPTXMORE
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_ULPTXMORE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_ULPTXMORE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TX_PI_HEADER_ULPTXMORE)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_ULPTXMORE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_ULPTXMORE)& M_FW_TX_PI_HEADER_ULPTXMORE)
end_define

begin_define
define|#
directive|define
name|F_FW_TX_PI_HEADER_ULPTXMORE
value|V_FW_TX_PI_HEADER_ULPTXMORE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_PI_CONTROL
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_PI_CONTROL
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_PI_CONTROL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TX_PI_HEADER_PI_CONTROL)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_PI_CONTROL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_PI_CONTROL)& M_FW_TX_PI_HEADER_PI_CONTROL)
end_define

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_GUARD_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_GUARD_TYPE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_GUARD_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TX_PI_HEADER_GUARD_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_GUARD_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_GUARD_TYPE)& M_FW_TX_PI_HEADER_GUARD_TYPE)
end_define

begin_define
define|#
directive|define
name|F_FW_TX_PI_HEADER_GUARD_TYPE
value|V_FW_TX_PI_HEADER_GUARD_TYPE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_VALIDATE
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_VALIDATE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_VALIDATE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TX_PI_HEADER_VALIDATE)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_VALIDATE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_VALIDATE)& M_FW_TX_PI_HEADER_VALIDATE)
end_define

begin_define
define|#
directive|define
name|F_FW_TX_PI_HEADER_VALIDATE
value|V_FW_TX_PI_HEADER_VALIDATE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_INLINE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_INLINE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_INLINE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TX_PI_HEADER_INLINE)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_INLINE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_INLINE)& M_FW_TX_PI_HEADER_INLINE)
end_define

begin_define
define|#
directive|define
name|F_FW_TX_PI_HEADER_INLINE
value|V_FW_TX_PI_HEADER_INLINE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_PI_INTERVAL
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_PI_INTERVAL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_PI_INTERVAL
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TX_PI_HEADER_PI_INTERVAL)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_PI_INTERVAL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_PI_INTERVAL)& M_FW_TX_PI_HEADER_PI_INTERVAL)
end_define

begin_define
define|#
directive|define
name|F_FW_TX_PI_HEADER_PI_INTERVAL
value|V_FW_TX_PI_HEADER_PI_INTERVAL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_TAG_TYPE
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_TAG_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_TAG_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TX_PI_HEADER_TAG_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_TAG_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_TAG_TYPE)& M_FW_TX_PI_HEADER_TAG_TYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_PI_START4
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_PI_START4
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_PI_START4
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TX_PI_HEADER_PI_START4)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_PI_START4
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_PI_START4)& M_FW_TX_PI_HEADER_PI_START4)
end_define

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_PI_END4
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_PI_END4
value|0x3fffff
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_PI_END4
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TX_PI_HEADER_PI_END4)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_PI_END4
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_PI_END4)& M_FW_TX_PI_HEADER_PI_END4)
end_define

begin_define
define|#
directive|define
name|S_FW_TX_PI_HEADER_TAG_GEN_ENABLED
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_TX_PI_HEADER_TAG_GEN_ENABLED
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_TX_PI_HEADER_TAG_GEN_ENABLED
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TX_PI_HEADER_TAG_GEN_ENABLED)
end_define

begin_define
define|#
directive|define
name|G_FW_TX_PI_HEADER_TAG_GEN_ENABLED
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TX_PI_HEADER_TAG_GEN_ENABLED)& \      M_FW_TX_PI_HEADER_TAG_GEN_ENABLED)
end_define

begin_enum
enum|enum
name|fw_pi_error_type
block|{
name|FW_PI_ERROR_GUARD_CHECK_FAILED
init|=
literal|0
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_pi_error
block|{
name|__be32
name|err_type_pkd
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
name|__be16
name|r2
decl_stmt|;
name|__be16
name|app_tag
decl_stmt|;
name|__be32
name|ref_tag
decl_stmt|;
name|__be32
name|pisc
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_PI_ERROR_ERR_TYPE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_PI_ERROR_ERR_TYPE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PI_ERROR_ERR_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PI_ERROR_ERR_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_PI_ERROR_ERR_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PI_ERROR_ERR_TYPE)& M_FW_PI_ERROR_ERR_TYPE)
end_define

begin_struct
struct|struct
name|fw_tlstx_data_wr
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
name|lsodisable_to_flags
decl_stmt|;
name|__be32
name|r5
decl_stmt|;
name|__be32
name|ctxloc_to_exp
decl_stmt|;
name|__be16
name|mfs
decl_stmt|;
name|__be16
name|adjustedplen_pkd
decl_stmt|;
name|__be16
name|expinplenmax_pkd
decl_stmt|;
name|__u8
name|pdusinplenmax_pkd
decl_stmt|;
name|__u8
name|r10
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_OPCODE)& M_FW_TLSTX_DATA_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_COMPL
value|21
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_COMPL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_COMPL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_COMPL)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_COMPL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_COMPL)& M_FW_TLSTX_DATA_WR_COMPL)
end_define

begin_define
define|#
directive|define
name|F_FW_TLSTX_DATA_WR_COMPL
value|V_FW_TLSTX_DATA_WR_COMPL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_IMMDLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_IMMDLEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_IMMDLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_IMMDLEN)& M_FW_TLSTX_DATA_WR_IMMDLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_FLOWID)& M_FW_TLSTX_DATA_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_LEN16)& M_FW_TLSTX_DATA_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_LSODISABLE
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_LSODISABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_LSODISABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLSTX_DATA_WR_LSODISABLE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_LSODISABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_LSODISABLE)& M_FW_TLSTX_DATA_WR_LSODISABLE)
end_define

begin_define
define|#
directive|define
name|F_FW_TLSTX_DATA_WR_LSODISABLE
value|V_FW_TLSTX_DATA_WR_LSODISABLE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_ALIGNPLD
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_ALIGNPLD
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_ALIGNPLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_ALIGNPLD)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_ALIGNPLD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_ALIGNPLD)& M_FW_TLSTX_DATA_WR_ALIGNPLD)
end_define

begin_define
define|#
directive|define
name|F_FW_TLSTX_DATA_WR_ALIGNPLD
value|V_FW_TLSTX_DATA_WR_ALIGNPLD(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_ALIGNPLDSHOVE
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_ALIGNPLDSHOVE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_ALIGNPLDSHOVE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLSTX_DATA_WR_ALIGNPLDSHOVE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_ALIGNPLDSHOVE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_ALIGNPLDSHOVE)& \      M_FW_TLSTX_DATA_WR_ALIGNPLDSHOVE)
end_define

begin_define
define|#
directive|define
name|F_FW_TLSTX_DATA_WR_ALIGNPLDSHOVE
value|V_FW_TLSTX_DATA_WR_ALIGNPLDSHOVE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_FLAGS
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_FLAGS
value|0xfffffff
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_FLAGS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_FLAGS)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_FLAGS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_FLAGS)& M_FW_TLSTX_DATA_WR_FLAGS)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_CTXLOC
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_CTXLOC
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_CTXLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_CTXLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_CTXLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_CTXLOC)& M_FW_TLSTX_DATA_WR_CTXLOC)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_IVDSGL
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_IVDSGL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_IVDSGL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_IVDSGL)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_IVDSGL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_IVDSGL)& M_FW_TLSTX_DATA_WR_IVDSGL)
end_define

begin_define
define|#
directive|define
name|F_FW_TLSTX_DATA_WR_IVDSGL
value|V_FW_TLSTX_DATA_WR_IVDSGL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_KEYSIZE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_KEYSIZE
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_KEYSIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_KEYSIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_KEYSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_KEYSIZE)& M_FW_TLSTX_DATA_WR_KEYSIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_NUMIVS
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_NUMIVS
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_NUMIVS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_NUMIVS)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_NUMIVS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_NUMIVS)& M_FW_TLSTX_DATA_WR_NUMIVS)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_EXP
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_EXP
value|0x3fff
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_EXP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLSTX_DATA_WR_EXP)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_EXP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_EXP)& M_FW_TLSTX_DATA_WR_EXP)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_ADJUSTEDPLEN
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_ADJUSTEDPLEN
value|0x7fff
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_ADJUSTEDPLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLSTX_DATA_WR_ADJUSTEDPLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_ADJUSTEDPLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_ADJUSTEDPLEN)& \      M_FW_TLSTX_DATA_WR_ADJUSTEDPLEN)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_EXPINPLENMAX
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_EXPINPLENMAX
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_EXPINPLENMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLSTX_DATA_WR_EXPINPLENMAX)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_EXPINPLENMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_EXPINPLENMAX)& \      M_FW_TLSTX_DATA_WR_EXPINPLENMAX)
end_define

begin_define
define|#
directive|define
name|S_FW_TLSTX_DATA_WR_PDUSINPLENMAX
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_TLSTX_DATA_WR_PDUSINPLENMAX
value|0x3f
end_define

begin_define
define|#
directive|define
name|V_FW_TLSTX_DATA_WR_PDUSINPLENMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLSTX_DATA_WR_PDUSINPLENMAX)
end_define

begin_define
define|#
directive|define
name|G_FW_TLSTX_DATA_WR_PDUSINPLENMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLSTX_DATA_WR_PDUSINPLENMAX)& \      M_FW_TLSTX_DATA_WR_PDUSINPLENMAX)
end_define

begin_struct
struct|struct
name|fw_tls_keyctx_tx_wr
block|{
name|__be32
name|op_to_compl
decl_stmt|;
name|__be32
name|flowid_len16
decl_stmt|;
union|union
name|fw_key_ctx
block|{
struct|struct
name|fw_tx_keyctx_hdr
block|{
name|__u8
name|ctxlen
decl_stmt|;
name|__u8
name|r2
decl_stmt|;
name|__be16
name|dualck_to_txvalid
decl_stmt|;
name|__u8
name|txsalt
index|[
literal|4
index|]
decl_stmt|;
name|__be64
name|r5
decl_stmt|;
block|}
name|txhdr
struct|;
struct|struct
name|fw_rx_keyctx_hdr
block|{
name|__u8
name|flitcnt_hmacctrl
decl_stmt|;
name|__u8
name|protover_ciphmode
decl_stmt|;
name|__u8
name|authmode_to_rxvalid
decl_stmt|;
name|__u8
name|ivpresent_to_rxmk_size
decl_stmt|;
name|__u8
name|rxsalt
index|[
literal|4
index|]
decl_stmt|;
name|__be64
name|ivinsert_to_authinsrt
decl_stmt|;
block|}
name|rxhdr
struct|;
struct|struct
name|fw_keyctx_clear
block|{
name|__be32
name|tx_key
decl_stmt|;
name|__be32
name|rx_key
decl_stmt|;
block|}
name|kctx_clr
struct|;
block|}
name|u
union|;
struct|struct
name|keys
block|{
name|__u8
name|edkey
index|[
literal|32
index|]
decl_stmt|;
name|__u8
name|ipad
index|[
literal|64
index|]
decl_stmt|;
name|__u8
name|opad
index|[
literal|64
index|]
decl_stmt|;
block|}
name|keys
struct|;
name|__u8
name|reneg_to_write_rx
decl_stmt|;
name|__u8
name|protocol
decl_stmt|;
name|__be16
name|mfs
decl_stmt|;
name|__be32
name|ftid
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_OPCODE)& M_FW_TLS_KEYCTX_TX_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_ATOMIC
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_ATOMIC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_ATOMIC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_ATOMIC)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_ATOMIC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_ATOMIC)& M_FW_TLS_KEYCTX_TX_WR_ATOMIC)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_ATOMIC
value|V_FW_TLS_KEYCTX_TX_WR_ATOMIC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_FLUSH
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_FLUSH
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_FLUSH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_FLUSH)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_FLUSH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_FLUSH)& M_FW_TLS_KEYCTX_TX_WR_FLUSH)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_FLUSH
value|V_FW_TLS_KEYCTX_TX_WR_FLUSH(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_COMPL
value|21
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_COMPL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_COMPL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_COMPL)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_COMPL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_COMPL)& M_FW_TLS_KEYCTX_TX_WR_COMPL)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_COMPL
value|V_FW_TLS_KEYCTX_TX_WR_COMPL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_FLOWID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_FLOWID)& M_FW_TLS_KEYCTX_TX_WR_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_LEN16)& M_FW_TLS_KEYCTX_TX_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_DUALCK
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_DUALCK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_DUALCK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_DUALCK)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_DUALCK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_DUALCK)& M_FW_TLS_KEYCTX_TX_WR_DUALCK)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_DUALCK
value|V_FW_TLS_KEYCTX_TX_WR_DUALCK(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_TXOPAD_PRESENT
value|11
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_TXOPAD_PRESENT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_TXOPAD_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_TXOPAD_PRESENT)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_TXOPAD_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_TXOPAD_PRESENT)& \      M_FW_TLS_KEYCTX_TX_WR_TXOPAD_PRESENT)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_TXOPAD_PRESENT
define|\
value|V_FW_TLS_KEYCTX_TX_WR_TXOPAD_PRESENT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_SALT_PRESENT
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_SALT_PRESENT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_SALT_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_SALT_PRESENT)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_SALT_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_SALT_PRESENT)& \      M_FW_TLS_KEYCTX_TX_WR_SALT_PRESENT)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_SALT_PRESENT
define|\
value|V_FW_TLS_KEYCTX_TX_WR_SALT_PRESENT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_TXCK_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_TXCK_SIZE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_TXCK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_TXCK_SIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_TXCK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_TXCK_SIZE)& \      M_FW_TLS_KEYCTX_TX_WR_TXCK_SIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_TXMK_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_TXMK_SIZE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_TXMK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_TXMK_SIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_TXMK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_TXMK_SIZE)& \      M_FW_TLS_KEYCTX_TX_WR_TXMK_SIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_TXVALID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_TXVALID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_TXVALID
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_TXVALID)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_TXVALID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_TXVALID)& M_FW_TLS_KEYCTX_TX_WR_TXVALID)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_TXVALID
value|V_FW_TLS_KEYCTX_TX_WR_TXVALID(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_FLITCNT
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_FLITCNT
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_FLITCNT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_FLITCNT)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_FLITCNT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_FLITCNT)& M_FW_TLS_KEYCTX_TX_WR_FLITCNT)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_HMACCTRL
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_HMACCTRL
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_HMACCTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_HMACCTRL)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_HMACCTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_HMACCTRL)& M_FW_TLS_KEYCTX_TX_WR_HMACCTRL)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_PROTOVER
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_PROTOVER
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_PROTOVER
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_PROTOVER)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_PROTOVER
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_PROTOVER)& M_FW_TLS_KEYCTX_TX_WR_PROTOVER)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_CIPHMODE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_CIPHMODE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_CIPHMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_CIPHMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_CIPHMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_CIPHMODE)& M_FW_TLS_KEYCTX_TX_WR_CIPHMODE)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_AUTHMODE
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_AUTHMODE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_AUTHMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_AUTHMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_AUTHMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_AUTHMODE)& M_FW_TLS_KEYCTX_TX_WR_AUTHMODE)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_CIPHAUTHSEQCTRL
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_CIPHAUTHSEQCTRL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_CIPHAUTHSEQCTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_CIPHAUTHSEQCTRL)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_CIPHAUTHSEQCTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_CIPHAUTHSEQCTRL)& \      M_FW_TLS_KEYCTX_TX_WR_CIPHAUTHSEQCTRL)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_CIPHAUTHSEQCTRL
define|\
value|V_FW_TLS_KEYCTX_TX_WR_CIPHAUTHSEQCTRL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_SEQNUMCTRL
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_SEQNUMCTRL
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_SEQNUMCTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_SEQNUMCTRL)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_SEQNUMCTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_SEQNUMCTRL)& \      M_FW_TLS_KEYCTX_TX_WR_SEQNUMCTRL)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_RXVALID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_RXVALID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_RXVALID
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_RXVALID)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_RXVALID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_RXVALID)& M_FW_TLS_KEYCTX_TX_WR_RXVALID)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_RXVALID
value|V_FW_TLS_KEYCTX_TX_WR_RXVALID(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_IVPRESENT
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_IVPRESENT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_IVPRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_IVPRESENT)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_IVPRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_IVPRESENT)& \      M_FW_TLS_KEYCTX_TX_WR_IVPRESENT)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_IVPRESENT
value|V_FW_TLS_KEYCTX_TX_WR_IVPRESENT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_RXOPAD_PRESENT
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_RXOPAD_PRESENT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_RXOPAD_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_RXOPAD_PRESENT)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_RXOPAD_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_RXOPAD_PRESENT)& \      M_FW_TLS_KEYCTX_TX_WR_RXOPAD_PRESENT)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_RXOPAD_PRESENT
define|\
value|V_FW_TLS_KEYCTX_TX_WR_RXOPAD_PRESENT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_RXCK_SIZE
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_RXCK_SIZE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_RXCK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_RXCK_SIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_RXCK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_RXCK_SIZE)& \      M_FW_TLS_KEYCTX_TX_WR_RXCK_SIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_RXMK_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_RXMK_SIZE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_RXMK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_RXMK_SIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_RXMK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_RXMK_SIZE)& \      M_FW_TLS_KEYCTX_TX_WR_RXMK_SIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_IVINSERT
value|55
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_IVINSERT
value|0x1ffULL
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_IVINSERT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_IVINSERT)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_IVINSERT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_IVINSERT)& M_FW_TLS_KEYCTX_TX_WR_IVINSERT)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_AADSTRTOFST
value|47
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_AADSTRTOFST
value|0xffULL
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_AADSTRTOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_AADSTRTOFST)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_AADSTRTOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_AADSTRTOFST)& \      M_FW_TLS_KEYCTX_TX_WR_AADSTRTOFST)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_AADSTOPOFST
value|39
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_AADSTOPOFST
value|0xffULL
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_AADSTOPOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_AADSTOPOFST)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_AADSTOPOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_AADSTOPOFST)& \      M_FW_TLS_KEYCTX_TX_WR_AADSTOPOFST)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_CIPHERSRTOFST
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_CIPHERSRTOFST
value|0x1ffULL
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_CIPHERSRTOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_CIPHERSRTOFST)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_CIPHERSRTOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_CIPHERSRTOFST)& \      M_FW_TLS_KEYCTX_TX_WR_CIPHERSRTOFST)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_CIPHERSTOPOFST
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_CIPHERSTOPOFST
value|0x7f
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_CIPHERSTOPOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_CIPHERSTOPOFST)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_CIPHERSTOPOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_CIPHERSTOPOFST)& \      M_FW_TLS_KEYCTX_TX_WR_CIPHERSTOPOFST)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_AUTHSRTOFST
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_AUTHSRTOFST
value|0x1ff
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_AUTHSRTOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_AUTHSRTOFST)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_AUTHSRTOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_AUTHSRTOFST)& \      M_FW_TLS_KEYCTX_TX_WR_AUTHSRTOFST)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_AUTHSTOPOFST
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_AUTHSTOPOFST
value|0x7f
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_AUTHSTOPOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_AUTHSTOPOFST)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_AUTHSTOPOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_AUTHSTOPOFST)& \      M_FW_TLS_KEYCTX_TX_WR_AUTHSTOPOFST)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_AUTHINSRT
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_AUTHINSRT
value|0x7f
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_AUTHINSRT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_AUTHINSRT)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_AUTHINSRT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_AUTHINSRT)& \      M_FW_TLS_KEYCTX_TX_WR_AUTHINSRT)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_RENEG
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_RENEG
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_RENEG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_RENEG)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_RENEG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_RENEG)& M_FW_TLS_KEYCTX_TX_WR_RENEG)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_RENEG
value|V_FW_TLS_KEYCTX_TX_WR_RENEG(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_DELETE_TX
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_DELETE_TX
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_DELETE_TX
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_DELETE_TX)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_DELETE_TX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_DELETE_TX)& \      M_FW_TLS_KEYCTX_TX_WR_DELETE_TX)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_DELETE_TX
value|V_FW_TLS_KEYCTX_TX_WR_DELETE_TX(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_DELETE_RX
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_DELETE_RX
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_DELETE_RX
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_DELETE_RX)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_DELETE_RX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_DELETE_RX)& \      M_FW_TLS_KEYCTX_TX_WR_DELETE_RX)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_DELETE_RX
value|V_FW_TLS_KEYCTX_TX_WR_DELETE_RX(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_WRITE_TX
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_WRITE_TX
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_WRITE_TX
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_WRITE_TX)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_WRITE_TX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_WRITE_TX)& M_FW_TLS_KEYCTX_TX_WR_WRITE_TX)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_WRITE_TX
value|V_FW_TLS_KEYCTX_TX_WR_WRITE_TX(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_TLS_KEYCTX_TX_WR_WRITE_RX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_TLS_KEYCTX_TX_WR_WRITE_RX
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_TLS_KEYCTX_TX_WR_WRITE_RX
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_TLS_KEYCTX_TX_WR_WRITE_RX)
end_define

begin_define
define|#
directive|define
name|G_FW_TLS_KEYCTX_TX_WR_WRITE_RX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_TLS_KEYCTX_TX_WR_WRITE_RX)& M_FW_TLS_KEYCTX_TX_WR_WRITE_RX)
end_define

begin_define
define|#
directive|define
name|F_FW_TLS_KEYCTX_TX_WR_WRITE_RX
value|V_FW_TLS_KEYCTX_TX_WR_WRITE_RX(1U)
end_define

begin_struct
struct|struct
name|fw_crypto_lookaside_wr
block|{
name|__be32
name|op_to_cctx_size
decl_stmt|;
name|__be32
name|len16_pkd
decl_stmt|;
name|__be32
name|session_id
decl_stmt|;
name|__be32
name|rx_chid_to_rx_q_id
decl_stmt|;
name|__be32
name|key_addr
decl_stmt|;
name|__be32
name|pld_size_hash_size
decl_stmt|;
name|__be64
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_OPCODE)& \      M_FW_CRYPTO_LOOKASIDE_WR_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_COMPL
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_COMPL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_COMPL
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_COMPL)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_COMPL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_COMPL)& \      M_FW_CRYPTO_LOOKASIDE_WR_COMPL)
end_define

begin_define
define|#
directive|define
name|F_FW_CRYPTO_LOOKASIDE_WR_COMPL
value|V_FW_CRYPTO_LOOKASIDE_WR_COMPL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_IMM_LEN
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_IMM_LEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_IMM_LEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_IMM_LEN)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_IMM_LEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_IMM_LEN)& \      M_FW_CRYPTO_LOOKASIDE_WR_IMM_LEN)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_CCTX_LOC
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_CCTX_LOC
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_CCTX_LOC
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_CCTX_LOC)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_CCTX_LOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_CCTX_LOC)& \      M_FW_CRYPTO_LOOKASIDE_WR_CCTX_LOC)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_CCTX_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_CCTX_SIZE
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_CCTX_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_CCTX_SIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_CCTX_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_CCTX_SIZE)& \      M_FW_CRYPTO_LOOKASIDE_WR_CCTX_SIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_LEN16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_LEN16)& \      M_FW_CRYPTO_LOOKASIDE_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_RX_CHID
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_RX_CHID
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_RX_CHID
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_RX_CHID)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_RX_CHID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_RX_CHID)& \      M_FW_CRYPTO_LOOKASIDE_WR_RX_CHID)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_LCB
value|27
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_LCB
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_LCB
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_LCB)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_LCB
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_LCB)& M_FW_CRYPTO_LOOKASIDE_WR_LCB)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_PHASH
value|25
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_PHASH
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_PHASH
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_PHASH)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_PHASH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_PHASH)& \      M_FW_CRYPTO_LOOKASIDE_WR_PHASH)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_IV
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_IV
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_IV
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_IV)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_IV
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_IV)& M_FW_CRYPTO_LOOKASIDE_WR_IV)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_FQIDX
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_FQIDX
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_FQIDX
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_FQIDX)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_FQIDX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_FQIDX)&\ 	  M_FW_CRYPTO_LOOKASIDE_WR_FQIDX)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_TX_CH
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_TX_CH
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_TX_CH
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_TX_CH)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_TX_CH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_TX_CH)& \      M_FW_CRYPTO_LOOKASIDE_WR_TX_CH)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_RX_Q_ID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_RX_Q_ID
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_RX_Q_ID
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_RX_Q_ID)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_RX_Q_ID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_RX_Q_ID)& \      M_FW_CRYPTO_LOOKASIDE_WR_RX_Q_ID)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_PLD_SIZE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_PLD_SIZE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_PLD_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_PLD_SIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_PLD_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_PLD_SIZE)& \      M_FW_CRYPTO_LOOKASIDE_WR_PLD_SIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_CRYPTO_LOOKASIDE_WR_HASH_SIZE
value|17
end_define

begin_define
define|#
directive|define
name|M_FW_CRYPTO_LOOKASIDE_WR_HASH_SIZE
value|0x7f
end_define

begin_define
define|#
directive|define
name|V_FW_CRYPTO_LOOKASIDE_WR_HASH_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CRYPTO_LOOKASIDE_WR_HASH_SIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_CRYPTO_LOOKASIDE_WR_HASH_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CRYPTO_LOOKASIDE_WR_HASH_SIZE)& \      M_FW_CRYPTO_LOOKASIDE_WR_HASH_SIZE)
end_define

begin_comment
comment|/******************************************************************************  *  C O M M A N D s  *********************/
end_comment

begin_comment
comment|/*  * The maximum length of time, in miliseconds, that we expect any firmware  * command to take to execute and return a reply to the host.  The RESET  * and INITIALIZE commands can take a fair amount of time to execute but  * most execute in far less time than this maximum.  This constant is used  * by host software to determine how long to wait for a firmware command  * reply before declaring the firmware as dead/unreachable ...  */
end_comment

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
name|FW_VI_STATS_CMD
init|=
literal|0x1a
block|,
name|FW_ACL_MAC_CMD
init|=
literal|0x18
block|,
name|FW_ACL_VLAN_CMD
init|=
literal|0x19
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
name|FW_SCHED_CMD
init|=
literal|0x24
block|,
name|FW_DEVLOG_CMD
init|=
literal|0x25
block|,
name|FW_WATCHDOG_CMD
init|=
literal|0x27
block|,
name|FW_CLIP_CMD
init|=
literal|0x28
block|,
name|FW_CHNET_IFACE_CMD
init|=
literal|0x26
block|,
name|FW_FCOE_RES_INFO_CMD
init|=
literal|0x31
block|,
name|FW_FCOE_LINK_CMD
init|=
literal|0x32
block|,
name|FW_FCOE_VNP_CMD
init|=
literal|0x33
block|,
name|FW_FCOE_SPARAMS_CMD
init|=
literal|0x35
block|,
name|FW_FCOE_STATS_CMD
init|=
literal|0x37
block|,
name|FW_FCOE_FCF_CMD
init|=
literal|0x38
block|,
name|FW_DCB_IEEE_CMD
init|=
literal|0x3a
block|,
name|FW_DIAG_CMD
init|=
literal|0x3d
block|,
name|FW_PTP_CMD
init|=
literal|0x3e
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
name|S_FW_CMD_OP
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_CMD_OP
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_CMD_OP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CMD_OP)
end_define

begin_define
define|#
directive|define
name|G_FW_CMD_OP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_CMD_OP)& M_FW_CMD_OP)
end_define

begin_define
define|#
directive|define
name|S_FW_CMD_REQUEST
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_CMD_REQUEST
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_CMD_REQUEST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CMD_REQUEST)
end_define

begin_define
define|#
directive|define
name|G_FW_CMD_REQUEST
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_CMD_REQUEST)& M_FW_CMD_REQUEST)
end_define

begin_define
define|#
directive|define
name|F_FW_CMD_REQUEST
value|V_FW_CMD_REQUEST(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_CMD_READ
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_CMD_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_CMD_READ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CMD_READ)
end_define

begin_define
define|#
directive|define
name|G_FW_CMD_READ
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_CMD_READ)& M_FW_CMD_READ)
end_define

begin_define
define|#
directive|define
name|F_FW_CMD_READ
value|V_FW_CMD_READ(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_CMD_WRITE
value|21
end_define

begin_define
define|#
directive|define
name|M_FW_CMD_WRITE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_CMD_WRITE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CMD_WRITE)
end_define

begin_define
define|#
directive|define
name|G_FW_CMD_WRITE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_CMD_WRITE)& M_FW_CMD_WRITE)
end_define

begin_define
define|#
directive|define
name|F_FW_CMD_WRITE
value|V_FW_CMD_WRITE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_CMD_EXEC
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_CMD_EXEC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_CMD_EXEC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CMD_EXEC)
end_define

begin_define
define|#
directive|define
name|G_FW_CMD_EXEC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_CMD_EXEC)& M_FW_CMD_EXEC)
end_define

begin_define
define|#
directive|define
name|F_FW_CMD_EXEC
value|V_FW_CMD_EXEC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_CMD_RAMASK
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_CMD_RAMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_CMD_RAMASK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CMD_RAMASK)
end_define

begin_define
define|#
directive|define
name|G_FW_CMD_RAMASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_CMD_RAMASK)& M_FW_CMD_RAMASK)
end_define

begin_define
define|#
directive|define
name|S_FW_CMD_RETVAL
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_CMD_RETVAL
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_CMD_RETVAL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CMD_RETVAL)
end_define

begin_define
define|#
directive|define
name|G_FW_CMD_RETVAL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_CMD_RETVAL)& M_FW_CMD_RETVAL)
end_define

begin_define
define|#
directive|define
name|S_FW_CMD_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_CMD_LEN16
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_CMD_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CMD_LEN16)
end_define

begin_define
define|#
directive|define
name|G_FW_CMD_LEN16
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_CMD_LEN16)& M_FW_CMD_LEN16)
end_define

begin_define
define|#
directive|define
name|FW_LEN16
parameter_list|(
name|fw_struct
parameter_list|)
value|V_FW_CMD_LEN16(sizeof(fw_struct) / 16)
end_define

begin_comment
comment|/*  *	address spaces  */
end_comment

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
block|,
name|FW_LDST_ADDRSPC_FUNC_I2C
init|=
literal|0x002A
block|,
comment|/* legacy */
name|FW_LDST_ADDRSPC_LE
init|=
literal|0x0030
block|,
name|FW_LDST_ADDRSPC_I2C
init|=
literal|0x0038
block|,
name|FW_LDST_ADDRSPC_PCIE_CFGS
init|=
literal|0x0040
block|,
name|FW_LDST_ADDRSPC_PCIE_DBG
init|=
literal|0x0041
block|,
name|FW_LDST_ADDRSPC_PCIE_PHY
init|=
literal|0x0042
block|,
name|FW_LDST_ADDRSPC_CIM_Q
init|=
literal|0x0048
block|, }
enum|;
end_enum

begin_comment
comment|/*  *	MDIO VSC8634 register access control field  */
end_comment

begin_enum
enum|enum
name|fw_ldst_mdio_vsc8634_aid
block|{
name|FW_LDST_MDIO_VS_STANDARD
block|,
name|FW_LDST_MDIO_VS_EXTENDED
block|,
name|FW_LDST_MDIO_VS_GPIO
block|}
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
name|__u8
name|req_first64
index|[
literal|8
index|]
decl_stmt|;
name|__u8
name|req_second64
index|[
literal|8
index|]
decl_stmt|;
name|__u8
name|resp_first64
index|[
literal|8
index|]
decl_stmt|;
name|__u8
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
name|__u8
name|access_ctl
decl_stmt|;
name|__u8
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
name|__u8
name|ctrl_to_fn
decl_stmt|;
name|__u8
name|bnum
decl_stmt|;
name|__u8
name|r
decl_stmt|;
name|__u8
name|ext_r
decl_stmt|;
name|__u8
name|select_naccess
decl_stmt|;
name|__u8
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
name|__u8
name|pid_pkd
decl_stmt|;
name|__u8
name|base
decl_stmt|;
name|__u8
name|boffset
decl_stmt|;
name|__u8
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
name|__u8
name|pid
decl_stmt|;
name|__u8
name|did
decl_stmt|;
name|__u8
name|boffset
decl_stmt|;
name|__u8
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
name|__u8
name|val
index|[
literal|33
index|]
decl_stmt|;
name|__u8
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
name|S_FW_LDST_CMD_ADDRSPACE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_ADDRSPACE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_ADDRSPACE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_ADDRSPACE)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_ADDRSPACE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_ADDRSPACE)& M_FW_LDST_CMD_ADDRSPACE)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_CYCLES
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_CYCLES
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_CYCLES
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_CYCLES)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_CYCLES
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_CYCLES)& M_FW_LDST_CMD_CYCLES)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_MSG
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_MSG
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_MSG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_MSG)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_MSG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_MSG)& M_FW_LDST_CMD_MSG)
end_define

begin_define
define|#
directive|define
name|F_FW_LDST_CMD_MSG
value|V_FW_LDST_CMD_MSG(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_CTXTFLUSH
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_CTXTFLUSH
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_CTXTFLUSH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_CTXTFLUSH)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_CTXTFLUSH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_CTXTFLUSH)& M_FW_LDST_CMD_CTXTFLUSH)
end_define

begin_define
define|#
directive|define
name|F_FW_LDST_CMD_CTXTFLUSH
value|V_FW_LDST_CMD_CTXTFLUSH(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_PADDR
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_PADDR
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_PADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_PADDR)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_PADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_PADDR)& M_FW_LDST_CMD_PADDR)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_MMD
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_MMD
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_MMD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_MMD)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_MMD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_MMD)& M_FW_LDST_CMD_MMD)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_FID
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_FID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_FID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_FID)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_FID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_FID)& M_FW_LDST_CMD_FID)
end_define

begin_define
define|#
directive|define
name|F_FW_LDST_CMD_FID
value|V_FW_LDST_CMD_FID(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_IDX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_IDX
value|0x7fff
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_IDX)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_IDX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_IDX)& M_FW_LDST_CMD_IDX)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_RPLCPF
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_RPLCPF
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_RPLCPF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_RPLCPF)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_RPLCPF
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_RPLCPF)& M_FW_LDST_CMD_RPLCPF)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_MPSID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_MPSID
value|0x7fff
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_MPSID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_MPSID)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_MPSID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_MPSID)& M_FW_LDST_CMD_MPSID)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_CTRL
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_CTRL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_CTRL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_CTRL)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_CTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_CTRL)& M_FW_LDST_CMD_CTRL)
end_define

begin_define
define|#
directive|define
name|F_FW_LDST_CMD_CTRL
value|V_FW_LDST_CMD_CTRL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_LC
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_LC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_LC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_LC)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_LC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_LC)& M_FW_LDST_CMD_LC)
end_define

begin_define
define|#
directive|define
name|F_FW_LDST_CMD_LC
value|V_FW_LDST_CMD_LC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_AI
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_AI
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_AI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_AI)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_AI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_AI)& M_FW_LDST_CMD_AI)
end_define

begin_define
define|#
directive|define
name|F_FW_LDST_CMD_AI
value|V_FW_LDST_CMD_AI(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_FN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_FN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_FN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_FN)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_FN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_FN)& M_FW_LDST_CMD_FN)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_SELECT
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_SELECT
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_SELECT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_SELECT)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_SELECT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_SELECT)& M_FW_LDST_CMD_SELECT)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_NACCESS
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_NACCESS
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_NACCESS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_NACCESS)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_NACCESS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_NACCESS)& M_FW_LDST_CMD_NACCESS)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_NSET
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_NSET
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_NSET
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_NSET)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_NSET
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_NSET)& M_FW_LDST_CMD_NSET)
end_define

begin_define
define|#
directive|define
name|S_FW_LDST_CMD_PID
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_LDST_CMD_PID
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_LDST_CMD_PID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_LDST_CMD_PID)
end_define

begin_define
define|#
directive|define
name|G_FW_LDST_CMD_PID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_LDST_CMD_PID)& M_FW_LDST_CMD_PID)
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
name|S_FW_RESET_CMD_HALT
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_RESET_CMD_HALT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RESET_CMD_HALT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RESET_CMD_HALT)
end_define

begin_define
define|#
directive|define
name|G_FW_RESET_CMD_HALT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RESET_CMD_HALT)& M_FW_RESET_CMD_HALT)
end_define

begin_define
define|#
directive|define
name|F_FW_RESET_CMD_HALT
value|V_FW_RESET_CMD_HALT(1U)
end_define

begin_enum
enum|enum
block|{
name|FW_HELLO_CMD_STAGE_OS
init|=
literal|0
block|,
name|FW_HELLO_CMD_STAGE_PREOS0
init|=
literal|1
block|,
name|FW_HELLO_CMD_STAGE_PREOS1
init|=
literal|2
block|,
name|FW_HELLO_CMD_STAGE_POSTOS
init|=
literal|3
block|, }
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
name|S_FW_HELLO_CMD_ERR
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_HELLO_CMD_ERR
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_HELLO_CMD_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_HELLO_CMD_ERR)
end_define

begin_define
define|#
directive|define
name|G_FW_HELLO_CMD_ERR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HELLO_CMD_ERR)& M_FW_HELLO_CMD_ERR)
end_define

begin_define
define|#
directive|define
name|F_FW_HELLO_CMD_ERR
value|V_FW_HELLO_CMD_ERR(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_HELLO_CMD_INIT
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_HELLO_CMD_INIT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_HELLO_CMD_INIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_HELLO_CMD_INIT)
end_define

begin_define
define|#
directive|define
name|G_FW_HELLO_CMD_INIT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HELLO_CMD_INIT)& M_FW_HELLO_CMD_INIT)
end_define

begin_define
define|#
directive|define
name|F_FW_HELLO_CMD_INIT
value|V_FW_HELLO_CMD_INIT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_HELLO_CMD_MASTERDIS
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_HELLO_CMD_MASTERDIS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_HELLO_CMD_MASTERDIS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_HELLO_CMD_MASTERDIS)
end_define

begin_define
define|#
directive|define
name|G_FW_HELLO_CMD_MASTERDIS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HELLO_CMD_MASTERDIS)& M_FW_HELLO_CMD_MASTERDIS)
end_define

begin_define
define|#
directive|define
name|F_FW_HELLO_CMD_MASTERDIS
value|V_FW_HELLO_CMD_MASTERDIS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_HELLO_CMD_MASTERFORCE
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_HELLO_CMD_MASTERFORCE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_HELLO_CMD_MASTERFORCE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_HELLO_CMD_MASTERFORCE)
end_define

begin_define
define|#
directive|define
name|G_FW_HELLO_CMD_MASTERFORCE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HELLO_CMD_MASTERFORCE)& M_FW_HELLO_CMD_MASTERFORCE)
end_define

begin_define
define|#
directive|define
name|F_FW_HELLO_CMD_MASTERFORCE
value|V_FW_HELLO_CMD_MASTERFORCE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_HELLO_CMD_MBMASTER
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_HELLO_CMD_MBMASTER
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_HELLO_CMD_MBMASTER
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_HELLO_CMD_MBMASTER)
end_define

begin_define
define|#
directive|define
name|G_FW_HELLO_CMD_MBMASTER
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HELLO_CMD_MBMASTER)& M_FW_HELLO_CMD_MBMASTER)
end_define

begin_define
define|#
directive|define
name|S_FW_HELLO_CMD_MBASYNCNOTINT
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_HELLO_CMD_MBASYNCNOTINT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_HELLO_CMD_MBASYNCNOTINT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_HELLO_CMD_MBASYNCNOTINT)
end_define

begin_define
define|#
directive|define
name|G_FW_HELLO_CMD_MBASYNCNOTINT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HELLO_CMD_MBASYNCNOTINT)& M_FW_HELLO_CMD_MBASYNCNOTINT)
end_define

begin_define
define|#
directive|define
name|F_FW_HELLO_CMD_MBASYNCNOTINT
value|V_FW_HELLO_CMD_MBASYNCNOTINT(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_HELLO_CMD_MBASYNCNOT
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_HELLO_CMD_MBASYNCNOT
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_HELLO_CMD_MBASYNCNOT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_HELLO_CMD_MBASYNCNOT)
end_define

begin_define
define|#
directive|define
name|G_FW_HELLO_CMD_MBASYNCNOT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HELLO_CMD_MBASYNCNOT)& M_FW_HELLO_CMD_MBASYNCNOT)
end_define

begin_define
define|#
directive|define
name|S_FW_HELLO_CMD_STAGE
value|17
end_define

begin_define
define|#
directive|define
name|M_FW_HELLO_CMD_STAGE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_HELLO_CMD_STAGE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_HELLO_CMD_STAGE)
end_define

begin_define
define|#
directive|define
name|G_FW_HELLO_CMD_STAGE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HELLO_CMD_STAGE)& M_FW_HELLO_CMD_STAGE)
end_define

begin_define
define|#
directive|define
name|S_FW_HELLO_CMD_CLEARINIT
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_HELLO_CMD_CLEARINIT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_HELLO_CMD_CLEARINIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_HELLO_CMD_CLEARINIT)
end_define

begin_define
define|#
directive|define
name|G_FW_HELLO_CMD_CLEARINIT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HELLO_CMD_CLEARINIT)& M_FW_HELLO_CMD_CLEARINIT)
end_define

begin_define
define|#
directive|define
name|F_FW_HELLO_CMD_CLEARINIT
value|V_FW_HELLO_CMD_CLEARINIT(1U)
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

begin_comment
comment|/*  * The VF Register Map.  *  * The Scatter Gather Engine (SGE), Multiport Support module (MPS), PIO Local  * bus module (PL) and CPU Interface Module (CIM) components are mapped via  * the Slice to Module Map Table (see below) in the Physical Function Register  * Map.  The Mail Box Data (MBDATA) range is mapped via the PCI-E Mailbox Base  * and Offset registers in the PF Register Map.  The MBDATA base address is  * quite constrained as it determines the Mailbox Data addresses for both PFs  * and VFs, and therefore must fit in both the VF and PF Register Maps without  * overlapping other registers.  */
end_comment

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
name|FW_T6VF_MBDATA_BASE_ADDR
value|0x0280
end_define

begin_comment
comment|/* aligned to mbox size 128B */
end_comment

begin_define
define|#
directive|define
name|FW_T4VF_CIM_BASE_ADDR
value|0x0300
end_define

begin_define
define|#
directive|define
name|FW_T4VF_REGMAP_START
value|0x0000
end_define

begin_define
define|#
directive|define
name|FW_T4VF_REGMAP_SIZE
value|0x0400
end_define

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
block|,
name|FW_CAPS_CONFIG_NIC_IDS
init|=
literal|0x00000004
block|,
name|FW_CAPS_CONFIG_NIC_UM
init|=
literal|0x00000008
block|,
name|FW_CAPS_CONFIG_NIC_UM_ISGL
init|=
literal|0x00000010
block|,
name|FW_CAPS_CONFIG_NIC_HASHFILTER
init|=
literal|0x00000020
block|,
name|FW_CAPS_CONFIG_NIC_ETHOFLD
init|=
literal|0x00000040
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_caps_config_toe
block|{
name|FW_CAPS_CONFIG_TOE
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
block|,
name|FW_CAPS_CONFIG_ISCSI_INITIATOR_SSNOFLD
init|=
literal|0x00000010
block|,
name|FW_CAPS_CONFIG_ISCSI_TARGET_SSNOFLD
init|=
literal|0x00000020
block|,
name|FW_CAPS_CONFIG_ISCSI_T10DIF
init|=
literal|0x00000040
block|,
name|FW_CAPS_CONFIG_ISCSI_INITIATOR_CMDOFLD
init|=
literal|0x00000080
block|,
name|FW_CAPS_CONFIG_ISCSI_TARGET_CMDOFLD
init|=
literal|0x00000100
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_caps_config_crypto
block|{
name|FW_CAPS_CONFIG_CRYPTO_LOOKASIDE
init|=
literal|0x00000001
block|,
name|FW_CAPS_CONFIG_TLSKEYS
init|=
literal|0x00000002
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
block|,
name|FW_CAPS_CONFIG_POFCOE_INITIATOR
init|=
literal|0x00000008
block|,
name|FW_CAPS_CONFIG_POFCOE_TARGET
init|=
literal|0x00000010
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_memtype_cf
block|{
name|FW_MEMTYPE_CF_EDC0
init|=
name|FW_MEMTYPE_EDC0
block|,
name|FW_MEMTYPE_CF_EDC1
init|=
name|FW_MEMTYPE_EDC1
block|,
name|FW_MEMTYPE_CF_EXTMEM
init|=
name|FW_MEMTYPE_EXTMEM
block|,
name|FW_MEMTYPE_CF_FLASH
init|=
name|FW_MEMTYPE_FLASH
block|,
name|FW_MEMTYPE_CF_INTERNAL
init|=
name|FW_MEMTYPE_INTERNAL
block|,
name|FW_MEMTYPE_CF_EXTMEM1
init|=
name|FW_MEMTYPE_EXTMEM1
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
name|toecaps
decl_stmt|;
name|__be16
name|rdmacaps
decl_stmt|;
name|__be16
name|cryptocaps
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
name|S_FW_CAPS_CONFIG_CMD_CFVALID
value|27
end_define

begin_define
define|#
directive|define
name|M_FW_CAPS_CONFIG_CMD_CFVALID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_CAPS_CONFIG_CMD_CFVALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CAPS_CONFIG_CMD_CFVALID)
end_define

begin_define
define|#
directive|define
name|G_FW_CAPS_CONFIG_CMD_CFVALID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CAPS_CONFIG_CMD_CFVALID)& M_FW_CAPS_CONFIG_CMD_CFVALID)
end_define

begin_define
define|#
directive|define
name|F_FW_CAPS_CONFIG_CMD_CFVALID
value|V_FW_CAPS_CONFIG_CMD_CFVALID(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_CAPS_CONFIG_CMD_MEMTYPE_CF
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_CAPS_CONFIG_CMD_MEMTYPE_CF
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_CAPS_CONFIG_CMD_MEMTYPE_CF
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CAPS_CONFIG_CMD_MEMTYPE_CF)
end_define

begin_define
define|#
directive|define
name|G_FW_CAPS_CONFIG_CMD_MEMTYPE_CF
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CAPS_CONFIG_CMD_MEMTYPE_CF)& \      M_FW_CAPS_CONFIG_CMD_MEMTYPE_CF)
end_define

begin_define
define|#
directive|define
name|S_FW_CAPS_CONFIG_CMD_MEMADDR64K_CF
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_CAPS_CONFIG_CMD_MEMADDR64K_CF
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_CAPS_CONFIG_CMD_MEMADDR64K_CF
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_CAPS_CONFIG_CMD_MEMADDR64K_CF)
end_define

begin_define
define|#
directive|define
name|G_FW_CAPS_CONFIG_CMD_MEMADDR64K_CF
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CAPS_CONFIG_CMD_MEMADDR64K_CF)& \      M_FW_CAPS_CONFIG_CMD_MEMADDR64K_CF)
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
name|FW_PARAMS_PARAM_DEV_INTFVER_NIC
init|=
literal|0x04
block|,
name|FW_PARAMS_PARAM_DEV_INTFVER_VNIC
init|=
literal|0x05
block|,
name|FW_PARAMS_PARAM_DEV_INTFVER_OFLD
init|=
literal|0x06
block|,
name|FW_PARAMS_PARAM_DEV_INTFVER_RI
init|=
literal|0x07
block|,
name|FW_PARAMS_PARAM_DEV_INTFVER_ISCSIPDU
init|=
literal|0x08
block|,
name|FW_PARAMS_PARAM_DEV_INTFVER_ISCSI
init|=
literal|0x09
block|,
name|FW_PARAMS_PARAM_DEV_INTFVER_FCOE
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
name|FW_PARAMS_PARAM_DEV_BYPASS
init|=
literal|0x0E
block|,
name|FW_PARAMS_PARAM_DEV_PHYFW
init|=
literal|0x0F
block|,
name|FW_PARAMS_PARAM_DEV_LOAD
init|=
literal|0x10
block|,
name|FW_PARAMS_PARAM_DEV_DIAG
init|=
literal|0x11
block|,
name|FW_PARAMS_PARAM_DEV_UCLK
init|=
literal|0x12
block|,
comment|/* uP clock in khz */
name|FW_PARAMS_PARAM_DEV_MAXORDIRD_QP
init|=
literal|0x13
block|,
comment|/* max supported QP IRD/ORD 						 */
name|FW_PARAMS_PARAM_DEV_MAXIRD_ADAPTER
init|=
literal|0x14
block|,
comment|/* max supported ADAPTER IRD 						 */
name|FW_PARAMS_PARAM_DEV_INTFVER_FCOEPDU
init|=
literal|0x15
block|,
name|FW_PARAMS_PARAM_DEV_MCINIT
init|=
literal|0x16
block|,
name|FW_PARAMS_PARAM_DEV_ULPTX_MEMWRITE_DSGL
init|=
literal|0x17
block|,
name|FW_PARAMS_PARAM_DEV_FWCACHE
init|=
literal|0x18
block|,
name|FW_PARAMS_PARAM_DEV_RSSINFO
init|=
literal|0x19
block|,
name|FW_PARAMS_PARAM_DEV_SCFGREV
init|=
literal|0x1A
block|,
name|FW_PARAMS_PARAM_DEV_VPDREV
init|=
literal|0x1B
block|,
name|FW_PARAMS_PARAM_DEV_RI_FR_NSMR_TPTE_WR
init|=
literal|0x1C
block|,
name|FW_PARAMS_PARAM_DEV_FILTER2_WR
init|=
literal|0x1D
block|,
name|FW_PARAMS_PARAM_DEV_MPSBGMAP
init|=
literal|0x1E
block|,
name|FW_PARAMS_PARAM_DEV_TPCHMAP
init|=
literal|0x1F
block|, }
enum|;
end_enum

begin_comment
comment|/*  * dev bypass parameters; actions and modes  */
end_comment

begin_enum
enum|enum
name|fw_params_param_dev_bypass
block|{
comment|/* actions 	 */
name|FW_PARAMS_PARAM_DEV_BYPASS_PFAIL
init|=
literal|0x00
block|,
name|FW_PARAMS_PARAM_DEV_BYPASS_CURRENT
init|=
literal|0x01
block|,
comment|/* modes 	 */
name|FW_PARAMS_PARAM_DEV_BYPASS_NORMAL
init|=
literal|0x00
block|,
name|FW_PARAMS_PARAM_DEV_BYPASS_DROP
init|=
literal|0x1
block|,
name|FW_PARAMS_PARAM_DEV_BYPASS_BYPASS
init|=
literal|0x2
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
name|FW_PARAMS_PARAM_PFVF_SRQ_START
init|=
literal|0x19
block|,
name|FW_PARAMS_PARAM_PFVF_SRQ_END
init|=
literal|0x1A
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
name|FW_PARAMS_PARAM_PFVF_ETHOFLD_START
init|=
literal|0x2F
block|,
name|FW_PARAMS_PARAM_PFVF_ETHOFLD_END
init|=
literal|0x30
block|,
name|FW_PARAMS_PARAM_PFVF_CPLFW4MSG_ENCAP
init|=
literal|0x31
block|,
name|FW_PARAMS_PARAM_PFVF_HPFILTER_START
init|=
literal|0x32
block|,
name|FW_PARAMS_PARAM_PFVF_HPFILTER_END
init|=
literal|0x33
block|,
name|FW_PARAMS_PARAM_PFVF_TLS_START
init|=
literal|0x34
block|,
name|FW_PARAMS_PARAM_PFVF_TLS_END
init|=
literal|0x35
block|,
name|FW_PARAMS_PARAM_PFVF_RAWF_START
init|=
literal|0x36
block|,
name|FW_PARAMS_PARAM_PFVF_RAWF_END
init|=
literal|0x37
block|,
name|FW_PARAMS_PARAM_PFVF_RSSKEYINFO
init|=
literal|0x38
block|,
name|FW_PARAMS_PARAM_PFVF_NCRYPTO_LOOKASIDE
init|=
literal|0x39
block|, }
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
name|FW_PARAMS_PARAM_DMAQ_IQ_INTIDX
init|=
literal|0x02
block|,
name|FW_PARAMS_PARAM_DMAQ_IQ_DCA
init|=
literal|0x03
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
name|FW_PARAMS_PARAM_DMAQ_EQ_DCA
init|=
literal|0x14
block|,
name|FW_PARAMS_PARAM_DMAQ_CONM_CTXT
init|=
literal|0x20
block|,
name|FW_PARAMS_PARAM_DMAQ_FLM_DCA
init|=
literal|0x30
block|}
enum|;
end_enum

begin_comment
comment|/*  * chnet parameters  */
end_comment

begin_enum
enum|enum
name|fw_params_param_chnet
block|{
name|FW_PARAMS_PARAM_CHNET_FLAGS
init|=
literal|0x00
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_params_param_chnet_flags
block|{
name|FW_PARAMS_PARAM_CHNET_FLAGS_ENABLE_IPV6
init|=
literal|0x1
block|,
name|FW_PARAMS_PARAM_CHNET_FLAGS_ENABLE_DAD
init|=
literal|0x2
block|,
name|FW_PARAMS_PARAM_CHNET_FLAGS_ENABLE_MLDV2
init|=
literal|0x4
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|S_FW_PARAMS_MNEM
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_MNEM
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_MNEM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PARAMS_MNEM)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_MNEM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_MNEM)& M_FW_PARAMS_MNEM)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_PARAM_X
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_PARAM_X
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_PARAM_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PARAMS_PARAM_X)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_PARAM_X
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_PARAM_X)& M_FW_PARAMS_PARAM_X)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_PARAM_Y
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_PARAM_Y
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_PARAM_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PARAMS_PARAM_Y)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_PARAM_Y
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_PARAM_Y)& M_FW_PARAMS_PARAM_Y)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_PARAM_Z
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_PARAM_Z
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_PARAM_Z
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PARAMS_PARAM_Z)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_PARAM_Z
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_PARAM_Z)& M_FW_PARAMS_PARAM_Z)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_PARAM_XYZ
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_PARAM_XYZ
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_PARAM_XYZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PARAMS_PARAM_XYZ)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_PARAM_XYZ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_PARAM_XYZ)& M_FW_PARAMS_PARAM_XYZ)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_PARAM_YZ
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_PARAM_YZ
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_PARAM_YZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PARAMS_PARAM_YZ)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_PARAM_YZ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_PARAM_YZ)& M_FW_PARAMS_PARAM_YZ)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_PARAM_DMAQ_DCA_TPHINTEN
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_PARAM_DMAQ_DCA_TPHINTEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_PARAM_DMAQ_DCA_TPHINTEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PARAMS_PARAM_DMAQ_DCA_TPHINTEN)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_PARAM_DMAQ_DCA_TPHINTEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_PARAM_DMAQ_DCA_TPHINTEN)& \ 	M_FW_PARAMS_PARAM_DMAQ_DCA_TPHINTEN)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_PARAM_DMAQ_DCA_TPHINT
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_PARAM_DMAQ_DCA_TPHINT
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_PARAM_DMAQ_DCA_TPHINT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PARAMS_PARAM_DMAQ_DCA_TPHINT)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_PARAM_DMAQ_DCA_TPHINT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_PARAM_DMAQ_DCA_TPHINT)& \ 	M_FW_PARAMS_PARAM_DMAQ_DCA_TPHINT)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_PARAM_DMAQ_DCA_ST
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_PARAM_DMAQ_DCA_ST
value|0x7ff
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_PARAM_DMAQ_DCA_ST
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PARAMS_PARAM_DMAQ_DCA_ST)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_PARAM_DMAQ_DCA_ST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_PARAM_DMAQ_DCA_ST)& M_FW_PARAMS_PARAM_DMAQ_DCA_ST)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_PARAM_DMAQ_INTIDX_QTYPE
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_PARAM_DMAQ_INTIDX_QTYPE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_PARAM_DMAQ_INTIDX_QTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PARAMS_PARAM_DMAQ_INTIDX_QTYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_PARAM_DMAQ_INTIDX_QTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_PARAM_DMAQ_INTIDX_QTYPE)& \      M_FW_PARAMS_PARAM_DMAQ_INTIDX_QTYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_PARAM_DMAQ_INTIDX_INTIDX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_PARAM_DMAQ_INTIDX_INTIDX
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_PARAM_DMAQ_INTIDX_INTIDX
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PARAMS_PARAM_DMAQ_INTIDX_INTIDX)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_PARAM_DMAQ_INTIDX_INTIDX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_PARAM_DMAQ_INTIDX_INTIDX)& \      M_FW_PARAMS_PARAM_DMAQ_INTIDX_INTIDX)
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
name|S_FW_PARAMS_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PARAMS_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_CMD_PFN)& M_FW_PARAMS_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_PARAMS_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PARAMS_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PARAMS_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PARAMS_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_PARAMS_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PARAMS_CMD_VFN)& M_FW_PARAMS_CMD_VFN)
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
name|S_FW_PFVF_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_PFN)& M_FW_PFVF_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_VFN)& M_FW_PFVF_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_NIQFLINT
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_NIQFLINT
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_NIQFLINT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_NIQFLINT)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_NIQFLINT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_NIQFLINT)& M_FW_PFVF_CMD_NIQFLINT)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_NIQ
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_NIQ
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_NIQ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_NIQ)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_NIQ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_NIQ)& M_FW_PFVF_CMD_NIQ)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_TYPE
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_TYPE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_TYPE)& M_FW_PFVF_CMD_TYPE)
end_define

begin_define
define|#
directive|define
name|F_FW_PFVF_CMD_TYPE
value|V_FW_PFVF_CMD_TYPE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_CMASK
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_CMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_CMASK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_CMASK)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_CMASK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_CMASK)& M_FW_PFVF_CMD_CMASK)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_PMASK
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_PMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_PMASK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_PMASK)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_PMASK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_PMASK)& M_FW_PFVF_CMD_PMASK)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_NEQ
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_NEQ
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_NEQ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_NEQ)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_NEQ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_NEQ)& M_FW_PFVF_CMD_NEQ)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_TC
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_TC
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_TC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_TC)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_TC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_TC)& M_FW_PFVF_CMD_TC)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_NVI
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_NVI
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_NVI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_NVI)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_NVI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_NVI)& M_FW_PFVF_CMD_NVI)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_NEXACTF
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_NEXACTF
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_NEXACTF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_NEXACTF)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_NEXACTF
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_NEXACTF)& M_FW_PFVF_CMD_NEXACTF)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_R_CAPS
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_R_CAPS
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_R_CAPS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_R_CAPS)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_R_CAPS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_R_CAPS)& M_FW_PFVF_CMD_R_CAPS)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_WX_CAPS
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_WX_CAPS
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_WX_CAPS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_WX_CAPS)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_WX_CAPS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_WX_CAPS)& M_FW_PFVF_CMD_WX_CAPS)
end_define

begin_define
define|#
directive|define
name|S_FW_PFVF_CMD_NETHCTRL
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PFVF_CMD_NETHCTRL
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_PFVF_CMD_NETHCTRL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PFVF_CMD_NETHCTRL)
end_define

begin_define
define|#
directive|define
name|G_FW_PFVF_CMD_NETHCTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PFVF_CMD_NETHCTRL)& M_FW_PFVF_CMD_NETHCTRL)
end_define

begin_comment
comment|/*  *	ingress queue type; the first 1K ingress queues can have associated 0,  *	1 or 2 free lists and an interrupt, all other ingress queues lack these  *	capabilities  */
end_comment

begin_enum
enum|enum
name|fw_iq_type
block|{
name|FW_IQ_TYPE_FL_INT_CAP
block|,
name|FW_IQ_TYPE_NO_FL_INT_CAP
block|,
name|FW_IQ_TYPE_VF_CQ
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
name|S_FW_IQ_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_PFN)& M_FW_IQ_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_VFN)& M_FW_IQ_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_ALLOC
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_ALLOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_ALLOC)& M_FW_IQ_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_ALLOC
value|V_FW_IQ_CMD_ALLOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FREE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FREE)& M_FW_IQ_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FREE
value|V_FW_IQ_CMD_FREE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_MODIFY
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_MODIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_MODIFY)& M_FW_IQ_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_MODIFY
value|V_FW_IQ_CMD_MODIFY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQSTART
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQSTART
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQSTART
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQSTART)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQSTART
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQSTART)& M_FW_IQ_CMD_IQSTART)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQSTART
value|V_FW_IQ_CMD_IQSTART(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQSTOP
value|27
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQSTOP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQSTOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQSTOP)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQSTOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQSTOP)& M_FW_IQ_CMD_IQSTOP)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQSTOP
value|V_FW_IQ_CMD_IQSTOP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_TYPE
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_TYPE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_TYPE)& M_FW_IQ_CMD_TYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQASYNCH
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQASYNCH
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQASYNCH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQASYNCH)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQASYNCH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQASYNCH)& M_FW_IQ_CMD_IQASYNCH)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQASYNCH
value|V_FW_IQ_CMD_IQASYNCH(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_VIID
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_VIID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_VIID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_VIID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_VIID)& M_FW_IQ_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQANDST
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQANDST
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQANDST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQANDST)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQANDST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQANDST)& M_FW_IQ_CMD_IQANDST)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQANDST
value|V_FW_IQ_CMD_IQANDST(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQANUS
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQANUS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQANUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQANUS)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQANUS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQANUS)& M_FW_IQ_CMD_IQANUS)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQANUS
value|V_FW_IQ_CMD_IQANUS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQANUD
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQANUD
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQANUD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQANUD)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQANUD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQANUD)& M_FW_IQ_CMD_IQANUD)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQANDSTINDEX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQANDSTINDEX
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQANDSTINDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQANDSTINDEX)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQANDSTINDEX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQANDSTINDEX)& M_FW_IQ_CMD_IQANDSTINDEX)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQDROPRSS
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQDROPRSS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQDROPRSS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQDROPRSS)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQDROPRSS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQDROPRSS)& M_FW_IQ_CMD_IQDROPRSS)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQDROPRSS
value|V_FW_IQ_CMD_IQDROPRSS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQGTSMODE
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQGTSMODE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQGTSMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQGTSMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQGTSMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQGTSMODE)& M_FW_IQ_CMD_IQGTSMODE)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQGTSMODE
value|V_FW_IQ_CMD_IQGTSMODE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQPCIECH
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQPCIECH
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQPCIECH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQPCIECH)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQPCIECH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQPCIECH)& M_FW_IQ_CMD_IQPCIECH)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQDCAEN
value|11
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQDCAEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQDCAEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQDCAEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQDCAEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQDCAEN)& M_FW_IQ_CMD_IQDCAEN)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQDCAEN
value|V_FW_IQ_CMD_IQDCAEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQDCACPU
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQDCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQDCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQDCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQDCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQDCACPU)& M_FW_IQ_CMD_IQDCACPU)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQINTCNTTHRESH
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQINTCNTTHRESH
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQINTCNTTHRESH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQINTCNTTHRESH)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQINTCNTTHRESH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQINTCNTTHRESH)& M_FW_IQ_CMD_IQINTCNTTHRESH)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQO
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQO)& M_FW_IQ_CMD_IQO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQO
value|V_FW_IQ_CMD_IQO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQCPRIO
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQCPRIO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQCPRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQCPRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQCPRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQCPRIO)& M_FW_IQ_CMD_IQCPRIO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQCPRIO
value|V_FW_IQ_CMD_IQCPRIO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQESIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQESIZE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQESIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQESIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQESIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQESIZE)& M_FW_IQ_CMD_IQESIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQNS
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQNS)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQNS)& M_FW_IQ_CMD_IQNS)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQNS
value|V_FW_IQ_CMD_IQNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQRO
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQRO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQRO)& M_FW_IQ_CMD_IQRO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQRO
value|V_FW_IQ_CMD_IQRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQFLINTIQHSEN
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQFLINTIQHSEN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQFLINTIQHSEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQFLINTIQHSEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQFLINTIQHSEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQFLINTIQHSEN)& M_FW_IQ_CMD_IQFLINTIQHSEN)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQFLINTCONGEN
value|27
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQFLINTCONGEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQFLINTCONGEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQFLINTCONGEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQFLINTCONGEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQFLINTCONGEN)& M_FW_IQ_CMD_IQFLINTCONGEN)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQFLINTCONGEN
value|V_FW_IQ_CMD_IQFLINTCONGEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_IQFLINTISCSIC
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_IQFLINTISCSIC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_IQFLINTISCSIC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_IQFLINTISCSIC)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_IQFLINTISCSIC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_IQFLINTISCSIC)& M_FW_IQ_CMD_IQFLINTISCSIC)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_IQFLINTISCSIC
value|V_FW_IQ_CMD_IQFLINTISCSIC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0CNGCHMAP
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0CNGCHMAP
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0CNGCHMAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0CNGCHMAP)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0CNGCHMAP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0CNGCHMAP)& M_FW_IQ_CMD_FL0CNGCHMAP)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0CONGDROP
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0CONGDROP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0CONGDROP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0CONGDROP)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0CONGDROP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0CONGDROP)& M_FW_IQ_CMD_FL0CONGDROP)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0CONGDROP
value|V_FW_IQ_CMD_FL0CONGDROP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0CACHELOCK
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0CACHELOCK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0CACHELOCK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0CACHELOCK)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0CACHELOCK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0CACHELOCK)& M_FW_IQ_CMD_FL0CACHELOCK)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0CACHELOCK
value|V_FW_IQ_CMD_FL0CACHELOCK(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0DBP
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0DBP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0DBP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0DBP)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0DBP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0DBP)& M_FW_IQ_CMD_FL0DBP)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0DBP
value|V_FW_IQ_CMD_FL0DBP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0DATANS
value|13
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0DATANS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0DATANS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0DATANS)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0DATANS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0DATANS)& M_FW_IQ_CMD_FL0DATANS)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0DATANS
value|V_FW_IQ_CMD_FL0DATANS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0DATARO
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0DATARO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0DATARO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0DATARO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0DATARO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0DATARO)& M_FW_IQ_CMD_FL0DATARO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0DATARO
value|V_FW_IQ_CMD_FL0DATARO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0CONGCIF
value|11
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0CONGCIF
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0CONGCIF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0CONGCIF)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0CONGCIF
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0CONGCIF)& M_FW_IQ_CMD_FL0CONGCIF)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0CONGCIF
value|V_FW_IQ_CMD_FL0CONGCIF(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0ONCHIP
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0ONCHIP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0ONCHIP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0ONCHIP)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0ONCHIP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0ONCHIP)& M_FW_IQ_CMD_FL0ONCHIP)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0ONCHIP
value|V_FW_IQ_CMD_FL0ONCHIP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0STATUSPGNS
value|9
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0STATUSPGNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0STATUSPGNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0STATUSPGNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0STATUSPGNS)& M_FW_IQ_CMD_FL0STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0STATUSPGNS
value|V_FW_IQ_CMD_FL0STATUSPGNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0STATUSPGRO
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0STATUSPGRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0STATUSPGRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0STATUSPGRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0STATUSPGRO)& M_FW_IQ_CMD_FL0STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0STATUSPGRO
value|V_FW_IQ_CMD_FL0STATUSPGRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0FETCHNS
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0FETCHNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0FETCHNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0FETCHNS)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0FETCHNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0FETCHNS)& M_FW_IQ_CMD_FL0FETCHNS)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0FETCHNS
value|V_FW_IQ_CMD_FL0FETCHNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0FETCHRO
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0FETCHRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0FETCHRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0FETCHRO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0FETCHRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0FETCHRO)& M_FW_IQ_CMD_FL0FETCHRO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0FETCHRO
value|V_FW_IQ_CMD_FL0FETCHRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0HOSTFCMODE
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0HOSTFCMODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0HOSTFCMODE)& M_FW_IQ_CMD_FL0HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0CPRIO
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0CPRIO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0CPRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0CPRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0CPRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0CPRIO)& M_FW_IQ_CMD_FL0CPRIO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0CPRIO
value|V_FW_IQ_CMD_FL0CPRIO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0PADEN
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0PADEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0PADEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0PADEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0PADEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0PADEN)& M_FW_IQ_CMD_FL0PADEN)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0PADEN
value|V_FW_IQ_CMD_FL0PADEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0PACKEN
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0PACKEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0PACKEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0PACKEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0PACKEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0PACKEN)& M_FW_IQ_CMD_FL0PACKEN)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0PACKEN
value|V_FW_IQ_CMD_FL0PACKEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0CONGEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0CONGEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0CONGEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0CONGEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0CONGEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0CONGEN)& M_FW_IQ_CMD_FL0CONGEN)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0CONGEN
value|V_FW_IQ_CMD_FL0CONGEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0DCAEN
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0DCAEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0DCAEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0DCAEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0DCAEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0DCAEN)& M_FW_IQ_CMD_FL0DCAEN)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0DCAEN
value|V_FW_IQ_CMD_FL0DCAEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0DCACPU
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0DCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0DCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0DCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0DCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0DCACPU)& M_FW_IQ_CMD_FL0DCACPU)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0FBMIN
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0FBMIN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0FBMIN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0FBMIN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0FBMIN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0FBMIN)& M_FW_IQ_CMD_FL0FBMIN)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0FBMAX
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0FBMAX
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0FBMAX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0FBMAX)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0FBMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0FBMAX)& M_FW_IQ_CMD_FL0FBMAX)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0CIDXFTHRESHO
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0CIDXFTHRESHO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0CIDXFTHRESHO)& M_FW_IQ_CMD_FL0CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL0CIDXFTHRESHO
value|V_FW_IQ_CMD_FL0CIDXFTHRESHO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL0CIDXFTHRESH
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL0CIDXFTHRESH
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL0CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL0CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL0CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL0CIDXFTHRESH)& M_FW_IQ_CMD_FL0CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1CNGCHMAP
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1CNGCHMAP
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1CNGCHMAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1CNGCHMAP)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1CNGCHMAP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1CNGCHMAP)& M_FW_IQ_CMD_FL1CNGCHMAP)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1CONGDROP
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1CONGDROP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1CONGDROP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1CONGDROP)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1CONGDROP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1CONGDROP)& M_FW_IQ_CMD_FL1CONGDROP)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1CONGDROP
value|V_FW_IQ_CMD_FL1CONGDROP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1CACHELOCK
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1CACHELOCK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1CACHELOCK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1CACHELOCK)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1CACHELOCK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1CACHELOCK)& M_FW_IQ_CMD_FL1CACHELOCK)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1CACHELOCK
value|V_FW_IQ_CMD_FL1CACHELOCK(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1DBP
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1DBP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1DBP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1DBP)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1DBP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1DBP)& M_FW_IQ_CMD_FL1DBP)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1DBP
value|V_FW_IQ_CMD_FL1DBP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1DATANS
value|13
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1DATANS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1DATANS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1DATANS)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1DATANS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1DATANS)& M_FW_IQ_CMD_FL1DATANS)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1DATANS
value|V_FW_IQ_CMD_FL1DATANS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1DATARO
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1DATARO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1DATARO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1DATARO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1DATARO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1DATARO)& M_FW_IQ_CMD_FL1DATARO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1DATARO
value|V_FW_IQ_CMD_FL1DATARO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1CONGCIF
value|11
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1CONGCIF
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1CONGCIF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1CONGCIF)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1CONGCIF
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1CONGCIF)& M_FW_IQ_CMD_FL1CONGCIF)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1CONGCIF
value|V_FW_IQ_CMD_FL1CONGCIF(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1ONCHIP
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1ONCHIP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1ONCHIP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1ONCHIP)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1ONCHIP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1ONCHIP)& M_FW_IQ_CMD_FL1ONCHIP)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1ONCHIP
value|V_FW_IQ_CMD_FL1ONCHIP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1STATUSPGNS
value|9
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1STATUSPGNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1STATUSPGNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1STATUSPGNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1STATUSPGNS)& M_FW_IQ_CMD_FL1STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1STATUSPGNS
value|V_FW_IQ_CMD_FL1STATUSPGNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1STATUSPGRO
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1STATUSPGRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1STATUSPGRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1STATUSPGRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1STATUSPGRO)& M_FW_IQ_CMD_FL1STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1STATUSPGRO
value|V_FW_IQ_CMD_FL1STATUSPGRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1FETCHNS
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1FETCHNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1FETCHNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1FETCHNS)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1FETCHNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1FETCHNS)& M_FW_IQ_CMD_FL1FETCHNS)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1FETCHNS
value|V_FW_IQ_CMD_FL1FETCHNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1FETCHRO
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1FETCHRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1FETCHRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1FETCHRO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1FETCHRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1FETCHRO)& M_FW_IQ_CMD_FL1FETCHRO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1FETCHRO
value|V_FW_IQ_CMD_FL1FETCHRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1HOSTFCMODE
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1HOSTFCMODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1HOSTFCMODE)& M_FW_IQ_CMD_FL1HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1CPRIO
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1CPRIO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1CPRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1CPRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1CPRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1CPRIO)& M_FW_IQ_CMD_FL1CPRIO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1CPRIO
value|V_FW_IQ_CMD_FL1CPRIO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1PADEN
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1PADEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1PADEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1PADEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1PADEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1PADEN)& M_FW_IQ_CMD_FL1PADEN)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1PADEN
value|V_FW_IQ_CMD_FL1PADEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1PACKEN
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1PACKEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1PACKEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1PACKEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1PACKEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1PACKEN)& M_FW_IQ_CMD_FL1PACKEN)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1PACKEN
value|V_FW_IQ_CMD_FL1PACKEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1CONGEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1CONGEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1CONGEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1CONGEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1CONGEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1CONGEN)& M_FW_IQ_CMD_FL1CONGEN)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1CONGEN
value|V_FW_IQ_CMD_FL1CONGEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1DCAEN
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1DCAEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1DCAEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1DCAEN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1DCAEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1DCAEN)& M_FW_IQ_CMD_FL1DCAEN)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1DCAEN
value|V_FW_IQ_CMD_FL1DCAEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1DCACPU
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1DCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1DCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1DCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1DCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1DCACPU)& M_FW_IQ_CMD_FL1DCACPU)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1FBMIN
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1FBMIN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1FBMIN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1FBMIN)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1FBMIN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1FBMIN)& M_FW_IQ_CMD_FL1FBMIN)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1FBMAX
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1FBMAX
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1FBMAX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1FBMAX)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1FBMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1FBMAX)& M_FW_IQ_CMD_FL1FBMAX)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1CIDXFTHRESHO
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1CIDXFTHRESHO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1CIDXFTHRESHO)& M_FW_IQ_CMD_FL1CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|F_FW_IQ_CMD_FL1CIDXFTHRESHO
value|V_FW_IQ_CMD_FL1CIDXFTHRESHO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_IQ_CMD_FL1CIDXFTHRESH
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_IQ_CMD_FL1CIDXFTHRESH
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_IQ_CMD_FL1CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_IQ_CMD_FL1CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|G_FW_IQ_CMD_FL1CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_IQ_CMD_FL1CIDXFTHRESH)& M_FW_IQ_CMD_FL1CIDXFTHRESH)
end_define

begin_struct
struct|struct
name|fw_eq_mngt_cmd
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
name|S_FW_EQ_MNGT_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_PFN)& M_FW_EQ_MNGT_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_VFN)& M_FW_EQ_MNGT_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_ALLOC
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_ALLOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_ALLOC)& M_FW_EQ_MNGT_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_ALLOC
value|V_FW_EQ_MNGT_CMD_ALLOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_FREE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_FREE)& M_FW_EQ_MNGT_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_FREE
value|V_FW_EQ_MNGT_CMD_FREE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_MODIFY
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_MODIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_MODIFY)& M_FW_EQ_MNGT_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_MODIFY
value|V_FW_EQ_MNGT_CMD_MODIFY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_EQSTART
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_EQSTART
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_EQSTART
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_EQSTART)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_EQSTART
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_EQSTART)& M_FW_EQ_MNGT_CMD_EQSTART)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_EQSTART
value|V_FW_EQ_MNGT_CMD_EQSTART(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_EQSTOP
value|27
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_EQSTOP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_EQSTOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_EQSTOP)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_EQSTOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_EQSTOP)& M_FW_EQ_MNGT_CMD_EQSTOP)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_EQSTOP
value|V_FW_EQ_MNGT_CMD_EQSTOP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_CMPLIQID
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_CMPLIQID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_CMPLIQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_CMPLIQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_CMPLIQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_CMPLIQID)& M_FW_EQ_MNGT_CMD_CMPLIQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_EQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_EQID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_EQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_EQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_EQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_EQID)& M_FW_EQ_MNGT_CMD_EQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_PHYSEQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_PHYSEQID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_PHYSEQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_PHYSEQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_PHYSEQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_PHYSEQID)& M_FW_EQ_MNGT_CMD_PHYSEQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_FETCHSZM
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_FETCHSZM
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_FETCHSZM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_FETCHSZM)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_FETCHSZM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_FETCHSZM)& M_FW_EQ_MNGT_CMD_FETCHSZM)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_FETCHSZM
value|V_FW_EQ_MNGT_CMD_FETCHSZM(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_STATUSPGNS
value|25
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_STATUSPGNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_STATUSPGNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_STATUSPGNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_STATUSPGNS)& M_FW_EQ_MNGT_CMD_STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_STATUSPGNS
value|V_FW_EQ_MNGT_CMD_STATUSPGNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_STATUSPGRO
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_STATUSPGRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_STATUSPGRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_STATUSPGRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_STATUSPGRO)& M_FW_EQ_MNGT_CMD_STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_STATUSPGRO
value|V_FW_EQ_MNGT_CMD_STATUSPGRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_FETCHNS
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_FETCHNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_FETCHNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_FETCHNS)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_FETCHNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_FETCHNS)& M_FW_EQ_MNGT_CMD_FETCHNS)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_FETCHNS
value|V_FW_EQ_MNGT_CMD_FETCHNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_FETCHRO
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_FETCHRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_FETCHRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_FETCHRO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_FETCHRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_FETCHRO)& M_FW_EQ_MNGT_CMD_FETCHRO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_FETCHRO
value|V_FW_EQ_MNGT_CMD_FETCHRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_HOSTFCMODE
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_HOSTFCMODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_HOSTFCMODE)& M_FW_EQ_MNGT_CMD_HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_CPRIO
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_CPRIO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_CPRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_CPRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_CPRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_CPRIO)& M_FW_EQ_MNGT_CMD_CPRIO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_CPRIO
value|V_FW_EQ_MNGT_CMD_CPRIO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_ONCHIP
value|18
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_ONCHIP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_ONCHIP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_ONCHIP)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_ONCHIP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_ONCHIP)& M_FW_EQ_MNGT_CMD_ONCHIP)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_ONCHIP
value|V_FW_EQ_MNGT_CMD_ONCHIP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_PCIECHN
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_PCIECHN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_PCIECHN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_PCIECHN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_PCIECHN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_PCIECHN)& M_FW_EQ_MNGT_CMD_PCIECHN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_IQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_IQID
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_IQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_IQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_IQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_IQID)& M_FW_EQ_MNGT_CMD_IQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_DCAEN
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_DCAEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_DCAEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_DCAEN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_DCAEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_DCAEN)& M_FW_EQ_MNGT_CMD_DCAEN)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_DCAEN
value|V_FW_EQ_MNGT_CMD_DCAEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_DCACPU
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_DCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_DCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_DCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_DCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_DCACPU)& M_FW_EQ_MNGT_CMD_DCACPU)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_FBMIN
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_FBMIN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_FBMIN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_FBMIN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_FBMIN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_FBMIN)& M_FW_EQ_MNGT_CMD_FBMIN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_FBMAX
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_FBMAX
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_FBMAX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_FBMAX)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_FBMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_FBMAX)& M_FW_EQ_MNGT_CMD_FBMAX)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_CIDXFTHRESHO
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_CIDXFTHRESHO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_EQ_MNGT_CMD_CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_CIDXFTHRESHO)& M_FW_EQ_MNGT_CMD_CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_MNGT_CMD_CIDXFTHRESHO
value|V_FW_EQ_MNGT_CMD_CIDXFTHRESHO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_CIDXFTHRESH
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_CIDXFTHRESH
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_CIDXFTHRESH)& M_FW_EQ_MNGT_CMD_CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_MNGT_CMD_EQSIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_MNGT_CMD_EQSIZE
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_MNGT_CMD_EQSIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_MNGT_CMD_EQSIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_MNGT_CMD_EQSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_MNGT_CMD_EQSIZE)& M_FW_EQ_MNGT_CMD_EQSIZE)
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
name|autoequiqe_to_viid
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
name|S_FW_EQ_ETH_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_PFN)& M_FW_EQ_ETH_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_VFN)& M_FW_EQ_ETH_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_ALLOC
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_ALLOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_ALLOC)& M_FW_EQ_ETH_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_ALLOC
value|V_FW_EQ_ETH_CMD_ALLOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_FREE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_FREE)& M_FW_EQ_ETH_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_FREE
value|V_FW_EQ_ETH_CMD_FREE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_MODIFY
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_MODIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_MODIFY)& M_FW_EQ_ETH_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_MODIFY
value|V_FW_EQ_ETH_CMD_MODIFY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_EQSTART
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_EQSTART
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_EQSTART
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_EQSTART)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_EQSTART
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_EQSTART)& M_FW_EQ_ETH_CMD_EQSTART)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_EQSTART
value|V_FW_EQ_ETH_CMD_EQSTART(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_EQSTOP
value|27
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_EQSTOP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_EQSTOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_EQSTOP)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_EQSTOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_EQSTOP)& M_FW_EQ_ETH_CMD_EQSTOP)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_EQSTOP
value|V_FW_EQ_ETH_CMD_EQSTOP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_EQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_EQID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_EQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_EQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_EQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_EQID)& M_FW_EQ_ETH_CMD_EQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_PHYSEQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_PHYSEQID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_PHYSEQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_PHYSEQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_PHYSEQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_PHYSEQID)& M_FW_EQ_ETH_CMD_PHYSEQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_FETCHSZM
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_FETCHSZM
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_FETCHSZM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_FETCHSZM)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_FETCHSZM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_FETCHSZM)& M_FW_EQ_ETH_CMD_FETCHSZM)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_FETCHSZM
value|V_FW_EQ_ETH_CMD_FETCHSZM(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_STATUSPGNS
value|25
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_STATUSPGNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_STATUSPGNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_STATUSPGNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_STATUSPGNS)& M_FW_EQ_ETH_CMD_STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_STATUSPGNS
value|V_FW_EQ_ETH_CMD_STATUSPGNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_STATUSPGRO
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_STATUSPGRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_STATUSPGRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_STATUSPGRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_STATUSPGRO)& M_FW_EQ_ETH_CMD_STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_STATUSPGRO
value|V_FW_EQ_ETH_CMD_STATUSPGRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_FETCHNS
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_FETCHNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_FETCHNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_FETCHNS)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_FETCHNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_FETCHNS)& M_FW_EQ_ETH_CMD_FETCHNS)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_FETCHNS
value|V_FW_EQ_ETH_CMD_FETCHNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_FETCHRO
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_FETCHRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_FETCHRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_FETCHRO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_FETCHRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_FETCHRO)& M_FW_EQ_ETH_CMD_FETCHRO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_FETCHRO
value|V_FW_EQ_ETH_CMD_FETCHRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_HOSTFCMODE
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_HOSTFCMODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_HOSTFCMODE)& M_FW_EQ_ETH_CMD_HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_CPRIO
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_CPRIO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_CPRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_CPRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_CPRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_CPRIO)& M_FW_EQ_ETH_CMD_CPRIO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_CPRIO
value|V_FW_EQ_ETH_CMD_CPRIO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_ONCHIP
value|18
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_ONCHIP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_ONCHIP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_ONCHIP)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_ONCHIP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_ONCHIP)& M_FW_EQ_ETH_CMD_ONCHIP)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_ONCHIP
value|V_FW_EQ_ETH_CMD_ONCHIP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_PCIECHN
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_PCIECHN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_PCIECHN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_PCIECHN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_PCIECHN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_PCIECHN)& M_FW_EQ_ETH_CMD_PCIECHN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_IQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_IQID
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_IQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_IQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_IQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_IQID)& M_FW_EQ_ETH_CMD_IQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_DCAEN
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_DCAEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_DCAEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_DCAEN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_DCAEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_DCAEN)& M_FW_EQ_ETH_CMD_DCAEN)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_DCAEN
value|V_FW_EQ_ETH_CMD_DCAEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_DCACPU
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_DCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_DCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_DCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_DCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_DCACPU)& M_FW_EQ_ETH_CMD_DCACPU)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_FBMIN
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_FBMIN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_FBMIN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_FBMIN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_FBMIN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_FBMIN)& M_FW_EQ_ETH_CMD_FBMIN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_FBMAX
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_FBMAX
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_FBMAX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_FBMAX)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_FBMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_FBMAX)& M_FW_EQ_ETH_CMD_FBMAX)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_CIDXFTHRESHO
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_CIDXFTHRESHO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_CIDXFTHRESHO)& M_FW_EQ_ETH_CMD_CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_CIDXFTHRESHO
value|V_FW_EQ_ETH_CMD_CIDXFTHRESHO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_CIDXFTHRESH
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_CIDXFTHRESH
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_CIDXFTHRESH)& M_FW_EQ_ETH_CMD_CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_EQSIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_EQSIZE
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_EQSIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_EQSIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_EQSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_EQSIZE)& M_FW_EQ_ETH_CMD_EQSIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_AUTOEQUIQE
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_AUTOEQUIQE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_AUTOEQUIQE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_AUTOEQUIQE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_AUTOEQUIQE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_AUTOEQUIQE)& M_FW_EQ_ETH_CMD_AUTOEQUIQE)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_AUTOEQUIQE
value|V_FW_EQ_ETH_CMD_AUTOEQUIQE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_AUTOEQUEQE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_AUTOEQUEQE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_AUTOEQUEQE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_AUTOEQUEQE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_AUTOEQUEQE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_AUTOEQUEQE)& M_FW_EQ_ETH_CMD_AUTOEQUEQE)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_ETH_CMD_AUTOEQUEQE
value|V_FW_EQ_ETH_CMD_AUTOEQUEQE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_ETH_CMD_VIID
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_ETH_CMD_VIID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_ETH_CMD_VIID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_ETH_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_ETH_CMD_VIID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_ETH_CMD_VIID)& M_FW_EQ_ETH_CMD_VIID)
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
name|S_FW_EQ_CTRL_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_PFN)& M_FW_EQ_CTRL_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_VFN)& M_FW_EQ_CTRL_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_ALLOC
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_ALLOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_ALLOC)& M_FW_EQ_CTRL_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_ALLOC
value|V_FW_EQ_CTRL_CMD_ALLOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_FREE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_FREE)& M_FW_EQ_CTRL_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_FREE
value|V_FW_EQ_CTRL_CMD_FREE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_MODIFY
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_MODIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_MODIFY)& M_FW_EQ_CTRL_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_MODIFY
value|V_FW_EQ_CTRL_CMD_MODIFY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_EQSTART
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_EQSTART
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_EQSTART
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_EQSTART)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_EQSTART
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_EQSTART)& M_FW_EQ_CTRL_CMD_EQSTART)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_EQSTART
value|V_FW_EQ_CTRL_CMD_EQSTART(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_EQSTOP
value|27
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_EQSTOP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_EQSTOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_EQSTOP)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_EQSTOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_EQSTOP)& M_FW_EQ_CTRL_CMD_EQSTOP)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_EQSTOP
value|V_FW_EQ_CTRL_CMD_EQSTOP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_CMPLIQID
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_CMPLIQID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_CMPLIQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_CMPLIQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_CMPLIQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_CMPLIQID)& M_FW_EQ_CTRL_CMD_CMPLIQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_EQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_EQID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_EQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_EQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_EQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_EQID)& M_FW_EQ_CTRL_CMD_EQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_PHYSEQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_PHYSEQID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_PHYSEQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_PHYSEQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_PHYSEQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_PHYSEQID)& M_FW_EQ_CTRL_CMD_PHYSEQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_FETCHSZM
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_FETCHSZM
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_FETCHSZM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_FETCHSZM)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_FETCHSZM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_FETCHSZM)& M_FW_EQ_CTRL_CMD_FETCHSZM)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_FETCHSZM
value|V_FW_EQ_CTRL_CMD_FETCHSZM(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_STATUSPGNS
value|25
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_STATUSPGNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_STATUSPGNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_STATUSPGNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_STATUSPGNS)& M_FW_EQ_CTRL_CMD_STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_STATUSPGNS
value|V_FW_EQ_CTRL_CMD_STATUSPGNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_STATUSPGRO
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_STATUSPGRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_STATUSPGRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_STATUSPGRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_STATUSPGRO)& M_FW_EQ_CTRL_CMD_STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_STATUSPGRO
value|V_FW_EQ_CTRL_CMD_STATUSPGRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_FETCHNS
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_FETCHNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_FETCHNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_FETCHNS)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_FETCHNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_FETCHNS)& M_FW_EQ_CTRL_CMD_FETCHNS)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_FETCHNS
value|V_FW_EQ_CTRL_CMD_FETCHNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_FETCHRO
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_FETCHRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_FETCHRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_FETCHRO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_FETCHRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_FETCHRO)& M_FW_EQ_CTRL_CMD_FETCHRO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_FETCHRO
value|V_FW_EQ_CTRL_CMD_FETCHRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_HOSTFCMODE
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_HOSTFCMODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_HOSTFCMODE)& M_FW_EQ_CTRL_CMD_HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_CPRIO
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_CPRIO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_CPRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_CPRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_CPRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_CPRIO)& M_FW_EQ_CTRL_CMD_CPRIO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_CPRIO
value|V_FW_EQ_CTRL_CMD_CPRIO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_ONCHIP
value|18
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_ONCHIP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_ONCHIP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_ONCHIP)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_ONCHIP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_ONCHIP)& M_FW_EQ_CTRL_CMD_ONCHIP)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_ONCHIP
value|V_FW_EQ_CTRL_CMD_ONCHIP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_PCIECHN
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_PCIECHN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_PCIECHN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_PCIECHN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_PCIECHN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_PCIECHN)& M_FW_EQ_CTRL_CMD_PCIECHN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_IQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_IQID
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_IQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_IQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_IQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_IQID)& M_FW_EQ_CTRL_CMD_IQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_DCAEN
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_DCAEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_DCAEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_DCAEN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_DCAEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_DCAEN)& M_FW_EQ_CTRL_CMD_DCAEN)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_DCAEN
value|V_FW_EQ_CTRL_CMD_DCAEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_DCACPU
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_DCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_DCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_DCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_DCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_DCACPU)& M_FW_EQ_CTRL_CMD_DCACPU)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_FBMIN
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_FBMIN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_FBMIN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_FBMIN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_FBMIN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_FBMIN)& M_FW_EQ_CTRL_CMD_FBMIN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_FBMAX
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_FBMAX
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_FBMAX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_FBMAX)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_FBMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_FBMAX)& M_FW_EQ_CTRL_CMD_FBMAX)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_CIDXFTHRESHO
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_CIDXFTHRESHO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_EQ_CTRL_CMD_CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_CIDXFTHRESHO)& M_FW_EQ_CTRL_CMD_CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_CTRL_CMD_CIDXFTHRESHO
value|V_FW_EQ_CTRL_CMD_CIDXFTHRESHO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_CIDXFTHRESH
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_CIDXFTHRESH
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_CIDXFTHRESH)& M_FW_EQ_CTRL_CMD_CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_CTRL_CMD_EQSIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_CTRL_CMD_EQSIZE
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_CTRL_CMD_EQSIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_CTRL_CMD_EQSIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_CTRL_CMD_EQSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_CTRL_CMD_EQSIZE)& M_FW_EQ_CTRL_CMD_EQSIZE)
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
name|S_FW_EQ_OFLD_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_PFN)& M_FW_EQ_OFLD_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_VFN)& M_FW_EQ_OFLD_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_ALLOC
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_ALLOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_ALLOC)& M_FW_EQ_OFLD_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_ALLOC
value|V_FW_EQ_OFLD_CMD_ALLOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_FREE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_FREE)& M_FW_EQ_OFLD_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_FREE
value|V_FW_EQ_OFLD_CMD_FREE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_MODIFY
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_MODIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_MODIFY)& M_FW_EQ_OFLD_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_MODIFY
value|V_FW_EQ_OFLD_CMD_MODIFY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_EQSTART
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_EQSTART
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_EQSTART
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_EQSTART)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_EQSTART
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_EQSTART)& M_FW_EQ_OFLD_CMD_EQSTART)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_EQSTART
value|V_FW_EQ_OFLD_CMD_EQSTART(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_EQSTOP
value|27
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_EQSTOP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_EQSTOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_EQSTOP)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_EQSTOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_EQSTOP)& M_FW_EQ_OFLD_CMD_EQSTOP)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_EQSTOP
value|V_FW_EQ_OFLD_CMD_EQSTOP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_EQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_EQID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_EQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_EQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_EQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_EQID)& M_FW_EQ_OFLD_CMD_EQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_PHYSEQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_PHYSEQID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_PHYSEQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_PHYSEQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_PHYSEQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_PHYSEQID)& M_FW_EQ_OFLD_CMD_PHYSEQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_FETCHSZM
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_FETCHSZM
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_FETCHSZM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_FETCHSZM)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_FETCHSZM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_FETCHSZM)& M_FW_EQ_OFLD_CMD_FETCHSZM)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_FETCHSZM
value|V_FW_EQ_OFLD_CMD_FETCHSZM(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_STATUSPGNS
value|25
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_STATUSPGNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_STATUSPGNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_STATUSPGNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_STATUSPGNS)& M_FW_EQ_OFLD_CMD_STATUSPGNS)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_STATUSPGNS
value|V_FW_EQ_OFLD_CMD_STATUSPGNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_STATUSPGRO
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_STATUSPGRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_STATUSPGRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_STATUSPGRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_STATUSPGRO)& M_FW_EQ_OFLD_CMD_STATUSPGRO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_STATUSPGRO
value|V_FW_EQ_OFLD_CMD_STATUSPGRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_FETCHNS
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_FETCHNS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_FETCHNS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_FETCHNS)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_FETCHNS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_FETCHNS)& M_FW_EQ_OFLD_CMD_FETCHNS)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_FETCHNS
value|V_FW_EQ_OFLD_CMD_FETCHNS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_FETCHRO
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_FETCHRO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_FETCHRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_FETCHRO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_FETCHRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_FETCHRO)& M_FW_EQ_OFLD_CMD_FETCHRO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_FETCHRO
value|V_FW_EQ_OFLD_CMD_FETCHRO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_HOSTFCMODE
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_HOSTFCMODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_HOSTFCMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_HOSTFCMODE)& M_FW_EQ_OFLD_CMD_HOSTFCMODE)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_CPRIO
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_CPRIO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_CPRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_CPRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_CPRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_CPRIO)& M_FW_EQ_OFLD_CMD_CPRIO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_CPRIO
value|V_FW_EQ_OFLD_CMD_CPRIO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_ONCHIP
value|18
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_ONCHIP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_ONCHIP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_ONCHIP)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_ONCHIP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_ONCHIP)& M_FW_EQ_OFLD_CMD_ONCHIP)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_ONCHIP
value|V_FW_EQ_OFLD_CMD_ONCHIP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_PCIECHN
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_PCIECHN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_PCIECHN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_PCIECHN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_PCIECHN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_PCIECHN)& M_FW_EQ_OFLD_CMD_PCIECHN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_IQID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_IQID
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_IQID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_IQID)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_IQID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_IQID)& M_FW_EQ_OFLD_CMD_IQID)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_DCAEN
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_DCAEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_DCAEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_DCAEN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_DCAEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_DCAEN)& M_FW_EQ_OFLD_CMD_DCAEN)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_DCAEN
value|V_FW_EQ_OFLD_CMD_DCAEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_DCACPU
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_DCACPU
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_DCACPU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_DCACPU)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_DCACPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_DCACPU)& M_FW_EQ_OFLD_CMD_DCACPU)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_FBMIN
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_FBMIN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_FBMIN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_FBMIN)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_FBMIN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_FBMIN)& M_FW_EQ_OFLD_CMD_FBMIN)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_FBMAX
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_FBMAX
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_FBMAX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_FBMAX)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_FBMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_FBMAX)& M_FW_EQ_OFLD_CMD_FBMAX)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_CIDXFTHRESHO
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_CIDXFTHRESHO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_EQ_OFLD_CMD_CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_CIDXFTHRESHO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_CIDXFTHRESHO)& M_FW_EQ_OFLD_CMD_CIDXFTHRESHO)
end_define

begin_define
define|#
directive|define
name|F_FW_EQ_OFLD_CMD_CIDXFTHRESHO
value|V_FW_EQ_OFLD_CMD_CIDXFTHRESHO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_CIDXFTHRESH
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_CIDXFTHRESH
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_CIDXFTHRESH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_CIDXFTHRESH)& M_FW_EQ_OFLD_CMD_CIDXFTHRESH)
end_define

begin_define
define|#
directive|define
name|S_FW_EQ_OFLD_CMD_EQSIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_EQ_OFLD_CMD_EQSIZE
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_EQ_OFLD_CMD_EQSIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_EQ_OFLD_CMD_EQSIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_EQ_OFLD_CMD_EQSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_EQ_OFLD_CMD_EQSIZE)& M_FW_EQ_OFLD_CMD_EQSIZE)
end_define

begin_comment
comment|/* Macros for VIID parsing:    VIID - [10:8] PFN, [7] VI Valid, [6:0] VI number */
end_comment

begin_define
define|#
directive|define
name|S_FW_VIID_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_VIID_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_VIID_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VIID_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_VIID_PFN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_VIID_PFN)& M_FW_VIID_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_VIID_VIVLD
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_VIID_VIVLD
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VIID_VIVLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VIID_VIVLD)
end_define

begin_define
define|#
directive|define
name|G_FW_VIID_VIVLD
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_VIID_VIVLD)& M_FW_VIID_VIVLD)
end_define

begin_define
define|#
directive|define
name|S_FW_VIID_VIN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VIID_VIN
value|0x7F
end_define

begin_define
define|#
directive|define
name|V_FW_VIID_VIN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VIID_VIN)
end_define

begin_define
define|#
directive|define
name|G_FW_VIID_VIN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_VIID_VIN)& M_FW_VIID_VIN)
end_define

begin_enum
enum|enum
name|fw_vi_func
block|{
name|FW_VI_FUNC_ETH
block|,
name|FW_VI_FUNC_OFLD
block|,
name|FW_VI_FUNC_IWARP
block|,
name|FW_VI_FUNC_OPENISCSI
block|,
name|FW_VI_FUNC_OPENFCOE
block|,
name|FW_VI_FUNC_FOISCSI
block|,
name|FW_VI_FUNC_FOFCOE
block|,
name|FW_VI_FUNC_FW
block|, }
enum|;
end_enum

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
name|type_to_viid
decl_stmt|;
name|__u8
name|mac
index|[
literal|6
index|]
decl_stmt|;
name|__u8
name|portid_pkd
decl_stmt|;
name|__u8
name|nmac
decl_stmt|;
name|__u8
name|nmac0
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|norss_rsssize
decl_stmt|;
name|__u8
name|nmac1
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|idsiiq_pkd
decl_stmt|;
name|__u8
name|nmac2
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|idseiq_pkd
decl_stmt|;
name|__u8
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
name|S_FW_VI_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_PFN)& M_FW_VI_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_VFN)& M_FW_VI_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_ALLOC
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_ALLOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_ALLOC)& M_FW_VI_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_CMD_ALLOC
value|V_FW_VI_CMD_ALLOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_FREE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_FREE)& M_FW_VI_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_CMD_FREE
value|V_FW_VI_CMD_FREE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_TYPE
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_TYPE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_TYPE)& M_FW_VI_CMD_TYPE)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_CMD_TYPE
value|V_FW_VI_CMD_TYPE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_FUNC
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_FUNC
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_FUNC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_FUNC)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_FUNC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_FUNC)& M_FW_VI_CMD_FUNC)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_VIID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_VIID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_VIID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_VIID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_VIID)& M_FW_VI_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_PORTID
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_PORTID
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_PORTID)& M_FW_VI_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_NORSS
value|11
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_NORSS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_NORSS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_NORSS)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_NORSS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_NORSS)& M_FW_VI_CMD_NORSS)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_CMD_NORSS
value|V_FW_VI_CMD_NORSS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_RSSSIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_RSSSIZE
value|0x7ff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_RSSSIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_RSSSIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_RSSSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_RSSSIZE)& M_FW_VI_CMD_RSSSIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_IDSIIQ
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_IDSIIQ
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_IDSIIQ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_IDSIIQ)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_IDSIIQ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_IDSIIQ)& M_FW_VI_CMD_IDSIIQ)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_CMD_IDSEIQ
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_CMD_IDSEIQ
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_CMD_IDSEIQ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_CMD_IDSEIQ)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_CMD_IDSEIQ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_CMD_IDSEIQ)& M_FW_VI_CMD_IDSEIQ)
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

begin_enum
enum|enum
name|fw_vi_mac_entry_types
block|{
name|FW_VI_MAC_TYPE_EXACTMAC
block|,
name|FW_VI_MAC_TYPE_HASHVEC
block|,
name|FW_VI_MAC_TYPE_RAW
block|, }
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
name|__u8
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
struct|struct
name|fw_vi_mac_raw
block|{
name|__be32
name|raw_idx_pkd
decl_stmt|;
name|__be32
name|data0_pkd
decl_stmt|;
name|__be32
name|data1
index|[
literal|2
index|]
decl_stmt|;
name|__be64
name|data0m_pkd
decl_stmt|;
name|__be32
name|data1m
index|[
literal|2
index|]
decl_stmt|;
block|}
name|raw
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
name|S_FW_VI_MAC_CMD_VIID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_MAC_CMD_VIID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_MAC_CMD_VIID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_MAC_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_MAC_CMD_VIID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_MAC_CMD_VIID)& M_FW_VI_MAC_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_MAC_CMD_FREEMACS
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_VI_MAC_CMD_FREEMACS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_MAC_CMD_FREEMACS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_MAC_CMD_FREEMACS)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_MAC_CMD_FREEMACS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_MAC_CMD_FREEMACS)& M_FW_VI_MAC_CMD_FREEMACS)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_MAC_CMD_FREEMACS
value|V_FW_VI_MAC_CMD_FREEMACS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_MAC_CMD_ENTRY_TYPE
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_VI_MAC_CMD_ENTRY_TYPE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_VI_MAC_CMD_ENTRY_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_MAC_CMD_ENTRY_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_MAC_CMD_ENTRY_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_MAC_CMD_ENTRY_TYPE)& M_FW_VI_MAC_CMD_ENTRY_TYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_MAC_CMD_HASHUNIEN
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_VI_MAC_CMD_HASHUNIEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_MAC_CMD_HASHUNIEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_MAC_CMD_HASHUNIEN)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_MAC_CMD_HASHUNIEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_MAC_CMD_HASHUNIEN)& M_FW_VI_MAC_CMD_HASHUNIEN)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_MAC_CMD_HASHUNIEN
value|V_FW_VI_MAC_CMD_HASHUNIEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_MAC_CMD_VALID
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_VI_MAC_CMD_VALID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_MAC_CMD_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_MAC_CMD_VALID)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_MAC_CMD_VALID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_MAC_CMD_VALID)& M_FW_VI_MAC_CMD_VALID)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_MAC_CMD_VALID
value|V_FW_VI_MAC_CMD_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_MAC_CMD_PRIO
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_VI_MAC_CMD_PRIO
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_VI_MAC_CMD_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_MAC_CMD_PRIO)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_MAC_CMD_PRIO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_MAC_CMD_PRIO)& M_FW_VI_MAC_CMD_PRIO)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_MAC_CMD_SMAC_RESULT
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_VI_MAC_CMD_SMAC_RESULT
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_VI_MAC_CMD_SMAC_RESULT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_MAC_CMD_SMAC_RESULT)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_MAC_CMD_SMAC_RESULT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_MAC_CMD_SMAC_RESULT)& M_FW_VI_MAC_CMD_SMAC_RESULT)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_MAC_CMD_IDX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_MAC_CMD_IDX
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_MAC_CMD_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_MAC_CMD_IDX)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_MAC_CMD_IDX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_MAC_CMD_IDX)& M_FW_VI_MAC_CMD_IDX)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_MAC_CMD_RAW_IDX
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_VI_MAC_CMD_RAW_IDX
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_MAC_CMD_RAW_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_MAC_CMD_RAW_IDX)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_MAC_CMD_RAW_IDX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_MAC_CMD_RAW_IDX)& M_FW_VI_MAC_CMD_RAW_IDX)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_MAC_CMD_DATA0
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_MAC_CMD_DATA0
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_MAC_CMD_DATA0
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_MAC_CMD_DATA0)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_MAC_CMD_DATA0
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_MAC_CMD_DATA0)& M_FW_VI_MAC_CMD_DATA0)
end_define

begin_comment
comment|/* T4 max MTU supported */
end_comment

begin_define
define|#
directive|define
name|T4_MAX_MTU_SUPPORTED
value|9600
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
name|S_FW_VI_RXMODE_CMD_VIID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_RXMODE_CMD_VIID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_RXMODE_CMD_VIID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_RXMODE_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_RXMODE_CMD_VIID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_RXMODE_CMD_VIID)& M_FW_VI_RXMODE_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_RXMODE_CMD_MTU
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_VI_RXMODE_CMD_MTU
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_RXMODE_CMD_MTU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_RXMODE_CMD_MTU)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_RXMODE_CMD_MTU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_RXMODE_CMD_MTU)& M_FW_VI_RXMODE_CMD_MTU)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_RXMODE_CMD_PROMISCEN
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_VI_RXMODE_CMD_PROMISCEN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_VI_RXMODE_CMD_PROMISCEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_RXMODE_CMD_PROMISCEN)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_RXMODE_CMD_PROMISCEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_RXMODE_CMD_PROMISCEN)& M_FW_VI_RXMODE_CMD_PROMISCEN)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_RXMODE_CMD_ALLMULTIEN
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_VI_RXMODE_CMD_ALLMULTIEN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_VI_RXMODE_CMD_ALLMULTIEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_VI_RXMODE_CMD_ALLMULTIEN)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_RXMODE_CMD_ALLMULTIEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_RXMODE_CMD_ALLMULTIEN)& M_FW_VI_RXMODE_CMD_ALLMULTIEN)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_RXMODE_CMD_BROADCASTEN
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_VI_RXMODE_CMD_BROADCASTEN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_VI_RXMODE_CMD_BROADCASTEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_VI_RXMODE_CMD_BROADCASTEN)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_RXMODE_CMD_BROADCASTEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_RXMODE_CMD_BROADCASTEN)& M_FW_VI_RXMODE_CMD_BROADCASTEN)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_RXMODE_CMD_VLANEXEN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_VI_RXMODE_CMD_VLANEXEN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_VI_RXMODE_CMD_VLANEXEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_RXMODE_CMD_VLANEXEN)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_RXMODE_CMD_VLANEXEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_RXMODE_CMD_VLANEXEN)& M_FW_VI_RXMODE_CMD_VLANEXEN)
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
name|S_FW_VI_ENABLE_CMD_VIID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_ENABLE_CMD_VIID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_ENABLE_CMD_VIID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_ENABLE_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_ENABLE_CMD_VIID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_ENABLE_CMD_VIID)& M_FW_VI_ENABLE_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_ENABLE_CMD_IEN
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_VI_ENABLE_CMD_IEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_ENABLE_CMD_IEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_ENABLE_CMD_IEN)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_ENABLE_CMD_IEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_ENABLE_CMD_IEN)& M_FW_VI_ENABLE_CMD_IEN)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_ENABLE_CMD_IEN
value|V_FW_VI_ENABLE_CMD_IEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_ENABLE_CMD_EEN
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_VI_ENABLE_CMD_EEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_ENABLE_CMD_EEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_ENABLE_CMD_EEN)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_ENABLE_CMD_EEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_ENABLE_CMD_EEN)& M_FW_VI_ENABLE_CMD_EEN)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_ENABLE_CMD_EEN
value|V_FW_VI_ENABLE_CMD_EEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_ENABLE_CMD_LED
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_VI_ENABLE_CMD_LED
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_ENABLE_CMD_LED
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_ENABLE_CMD_LED)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_ENABLE_CMD_LED
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_ENABLE_CMD_LED)& M_FW_VI_ENABLE_CMD_LED)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_ENABLE_CMD_LED
value|V_FW_VI_ENABLE_CMD_LED(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_ENABLE_CMD_DCB_INFO
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_VI_ENABLE_CMD_DCB_INFO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_VI_ENABLE_CMD_DCB_INFO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_ENABLE_CMD_DCB_INFO)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_ENABLE_CMD_DCB_INFO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_ENABLE_CMD_DCB_INFO)& M_FW_VI_ENABLE_CMD_DCB_INFO)
end_define

begin_define
define|#
directive|define
name|F_FW_VI_ENABLE_CMD_DCB_INFO
value|V_FW_VI_ENABLE_CMD_DCB_INFO(1U)
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
name|S_FW_VI_STATS_CMD_VIID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_STATS_CMD_VIID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_VI_STATS_CMD_VIID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_STATS_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_STATS_CMD_VIID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_STATS_CMD_VIID)& M_FW_VI_STATS_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_STATS_CMD_NSTATS
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_VI_STATS_CMD_NSTATS
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_VI_STATS_CMD_NSTATS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_STATS_CMD_NSTATS)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_STATS_CMD_NSTATS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_STATS_CMD_NSTATS)& M_FW_VI_STATS_CMD_NSTATS)
end_define

begin_define
define|#
directive|define
name|S_FW_VI_STATS_CMD_IX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VI_STATS_CMD_IX
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_VI_STATS_CMD_IX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VI_STATS_CMD_IX)
end_define

begin_define
define|#
directive|define
name|G_FW_VI_STATS_CMD_IX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VI_STATS_CMD_IX)& M_FW_VI_STATS_CMD_IX)
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
name|__u8
name|nmac
decl_stmt|;
name|__u8
name|r3
index|[
literal|7
index|]
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__u8
name|macaddr0
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|r5
decl_stmt|;
name|__u8
name|macaddr1
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|r6
decl_stmt|;
name|__u8
name|macaddr2
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|r7
decl_stmt|;
name|__u8
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
name|S_FW_ACL_MAC_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_ACL_MAC_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_ACL_MAC_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ACL_MAC_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_ACL_MAC_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ACL_MAC_CMD_PFN)& M_FW_ACL_MAC_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_ACL_MAC_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ACL_MAC_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_ACL_MAC_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ACL_MAC_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_ACL_MAC_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ACL_MAC_CMD_VFN)& M_FW_ACL_MAC_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_ACL_MAC_CMD_EN
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_ACL_MAC_CMD_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ACL_MAC_CMD_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ACL_MAC_CMD_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_ACL_MAC_CMD_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ACL_MAC_CMD_EN)& M_FW_ACL_MAC_CMD_EN)
end_define

begin_define
define|#
directive|define
name|F_FW_ACL_MAC_CMD_EN
value|V_FW_ACL_MAC_CMD_EN(1U)
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
name|__u8
name|nvlan
decl_stmt|;
name|__u8
name|dropnovlan_fm
decl_stmt|;
name|__u8
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
name|S_FW_ACL_VLAN_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_ACL_VLAN_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_ACL_VLAN_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ACL_VLAN_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_ACL_VLAN_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ACL_VLAN_CMD_PFN)& M_FW_ACL_VLAN_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_ACL_VLAN_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ACL_VLAN_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_ACL_VLAN_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ACL_VLAN_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_ACL_VLAN_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ACL_VLAN_CMD_VFN)& M_FW_ACL_VLAN_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_ACL_VLAN_CMD_EN
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_ACL_VLAN_CMD_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ACL_VLAN_CMD_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ACL_VLAN_CMD_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_ACL_VLAN_CMD_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ACL_VLAN_CMD_EN)& M_FW_ACL_VLAN_CMD_EN)
end_define

begin_define
define|#
directive|define
name|F_FW_ACL_VLAN_CMD_EN
value|V_FW_ACL_VLAN_CMD_EN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_ACL_VLAN_CMD_DROPNOVLAN
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_ACL_VLAN_CMD_DROPNOVLAN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ACL_VLAN_CMD_DROPNOVLAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ACL_VLAN_CMD_DROPNOVLAN)
end_define

begin_define
define|#
directive|define
name|G_FW_ACL_VLAN_CMD_DROPNOVLAN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ACL_VLAN_CMD_DROPNOVLAN)& M_FW_ACL_VLAN_CMD_DROPNOVLAN)
end_define

begin_define
define|#
directive|define
name|F_FW_ACL_VLAN_CMD_DROPNOVLAN
value|V_FW_ACL_VLAN_CMD_DROPNOVLAN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_ACL_VLAN_CMD_FM
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_ACL_VLAN_CMD_FM
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ACL_VLAN_CMD_FM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ACL_VLAN_CMD_FM)
end_define

begin_define
define|#
directive|define
name|G_FW_ACL_VLAN_CMD_FM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ACL_VLAN_CMD_FM)& M_FW_ACL_VLAN_CMD_FM)
end_define

begin_define
define|#
directive|define
name|F_FW_ACL_VLAN_CMD_FM
value|V_FW_ACL_VLAN_CMD_FM(1U)
end_define

begin_comment
comment|/* port capabilities bitmap */
end_comment

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
name|FW_PORT_CAP_FEC_RS
init|=
literal|0x0800
block|,
name|FW_PORT_CAP_FEC_BASER_RS
init|=
literal|0x1000
block|,
name|FW_PORT_CAP_FEC_RESERVED
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
name|S_FW_PORT_CAP_SPEED
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CAP_SPEED
value|0x3f
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CAP_SPEED
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CAP_SPEED)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CAP_SPEED
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CAP_SPEED)& M_FW_PORT_CAP_SPEED)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CAP_FC
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CAP_FC
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CAP_FC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CAP_FC)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CAP_FC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CAP_FC)& M_FW_PORT_CAP_FC)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CAP_ANEG
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CAP_ANEG
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CAP_ANEG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CAP_ANEG)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CAP_ANEG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CAP_ANEG)& M_FW_PORT_CAP_ANEG)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CAP_FEC
value|11
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CAP_FEC
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CAP_FEC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CAP_FEC)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CAP_FEC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CAP_FEC)& M_FW_PORT_CAP_FEC)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CAP_802_3
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CAP_802_3
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CAP_802_3
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CAP_802_3)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CAP_802_3
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CAP_802_3)& M_FW_PORT_CAP_802_3)
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
name|S_FW_PORT_CAP_MDI
value|9
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CAP_MDI
value|3
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CAP_MDI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CAP_MDI)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CAP_MDI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FW_PORT_CAP_MDI)& M_FW_PORT_CAP_MDI)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_AUXLINFO_KX4
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_AUXLINFO_KX4
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_AUXLINFO_KX4
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_AUXLINFO_KX4)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_AUXLINFO_KX4
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_AUXLINFO_KX4)& M_FW_PORT_AUXLINFO_KX4)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_AUXLINFO_KX4
value|V_FW_PORT_AUXLINFO_KX4(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_AUXLINFO_KR
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_AUXLINFO_KR
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_AUXLINFO_KR
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_AUXLINFO_KR)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_AUXLINFO_KR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_AUXLINFO_KR)& M_FW_PORT_AUXLINFO_KR)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_AUXLINFO_KR
value|V_FW_PORT_AUXLINFO_KR(1U)
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
name|FW_PORT_ACTION_LPBK_SS_ASIC
init|=
literal|0x0022
block|,
name|FW_PORT_ACTION_LPBK_WS_ASIC
init|=
literal|0x0023
block|,
name|FW_PORT_ACTION_LPBK_WS_EXT_PHY
init|=
literal|0x0025
block|,
name|FW_PORT_ACTION_LPBK_SS_EXT
init|=
literal|0x0026
block|,
name|FW_PORT_ACTION_DIAGNOSTICS
init|=
literal|0x0027
block|,
name|FW_PORT_ACTION_LPBK_SS_EXT_PHY
init|=
literal|0x0028
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
block|,  }
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
block|,
name|FW_PORT_L2_CTLBF_MTU
init|=
literal|0x40
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fw_dcb_app_tlv_sf
block|{
name|FW_DCB_APP_SF_ETHERTYPE
block|,
name|FW_DCB_APP_SF_SOCKET_TCP
block|,
name|FW_DCB_APP_SF_SOCKET_UDP
block|,
name|FW_DCB_APP_SF_SOCKET_ALL
block|, }
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

begin_enum
enum|enum
name|fw_port_diag_ops
block|{
name|FW_PORT_DIAGS_TEMP
init|=
literal|0x00
block|,
name|FW_PORT_DIAGS_TX_POWER
init|=
literal|0x01
block|,
name|FW_PORT_DIAGS_RX_POWER
init|=
literal|0x02
block|,
name|FW_PORT_DIAGS_TX_DIS
init|=
literal|0x03
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
name|S_FW_PORT_CMD_READ
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_READ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_READ)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_READ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_READ)& M_FW_PORT_CMD_READ)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_READ
value|V_FW_PORT_CMD_READ(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_PORTID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_PORTID
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_PORTID)& M_FW_PORT_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_ACTION
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_ACTION
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_ACTION
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_ACTION)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_ACTION
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_ACTION)& M_FW_PORT_CMD_ACTION)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_OVLAN3
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_OVLAN3
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_OVLAN3
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_OVLAN3)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_OVLAN3
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_OVLAN3)& M_FW_PORT_CMD_OVLAN3)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_OVLAN3
value|V_FW_PORT_CMD_OVLAN3(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_OVLAN2
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_OVLAN2
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_OVLAN2
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_OVLAN2)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_OVLAN2
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_OVLAN2)& M_FW_PORT_CMD_OVLAN2)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_OVLAN2
value|V_FW_PORT_CMD_OVLAN2(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_OVLAN1
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_OVLAN1
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_OVLAN1
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_OVLAN1)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_OVLAN1
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_OVLAN1)& M_FW_PORT_CMD_OVLAN1)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_OVLAN1
value|V_FW_PORT_CMD_OVLAN1(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_OVLAN0
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_OVLAN0
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_OVLAN0
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_OVLAN0)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_OVLAN0
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_OVLAN0)& M_FW_PORT_CMD_OVLAN0)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_OVLAN0
value|V_FW_PORT_CMD_OVLAN0(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_IVLAN0
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_IVLAN0
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_IVLAN0
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_IVLAN0)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_IVLAN0
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_IVLAN0)& M_FW_PORT_CMD_IVLAN0)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_IVLAN0
value|V_FW_PORT_CMD_IVLAN0(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_TXIPG
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_TXIPG
value|0x1fff
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_TXIPG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_TXIPG)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_TXIPG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_TXIPG)& M_FW_PORT_CMD_TXIPG)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_FORCE_PINFO
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_FORCE_PINFO
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_FORCE_PINFO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_FORCE_PINFO)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_FORCE_PINFO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_FORCE_PINFO)& M_FW_PORT_CMD_FORCE_PINFO)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_FORCE_PINFO
value|V_FW_PORT_CMD_FORCE_PINFO(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_LSTATUS
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_LSTATUS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_LSTATUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_LSTATUS)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_LSTATUS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_LSTATUS)& M_FW_PORT_CMD_LSTATUS)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_LSTATUS
value|V_FW_PORT_CMD_LSTATUS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_LSPEED
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_LSPEED
value|0x3f
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_LSPEED
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_LSPEED)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_LSPEED
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_LSPEED)& M_FW_PORT_CMD_LSPEED)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_TXPAUSE
value|23
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_TXPAUSE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_TXPAUSE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_TXPAUSE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_TXPAUSE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_TXPAUSE)& M_FW_PORT_CMD_TXPAUSE)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_TXPAUSE
value|V_FW_PORT_CMD_TXPAUSE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_RXPAUSE
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_RXPAUSE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_RXPAUSE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_RXPAUSE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_RXPAUSE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_RXPAUSE)& M_FW_PORT_CMD_RXPAUSE)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_RXPAUSE
value|V_FW_PORT_CMD_RXPAUSE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_MDIOCAP
value|21
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_MDIOCAP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_MDIOCAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_MDIOCAP)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_MDIOCAP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_MDIOCAP)& M_FW_PORT_CMD_MDIOCAP)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_MDIOCAP
value|V_FW_PORT_CMD_MDIOCAP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_MDIOADDR
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_MDIOADDR
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_MDIOADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_MDIOADDR)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_MDIOADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_MDIOADDR)& M_FW_PORT_CMD_MDIOADDR)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_LPTXPAUSE
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_LPTXPAUSE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_LPTXPAUSE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_LPTXPAUSE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_LPTXPAUSE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_LPTXPAUSE)& M_FW_PORT_CMD_LPTXPAUSE)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_LPTXPAUSE
value|V_FW_PORT_CMD_LPTXPAUSE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_LPRXPAUSE
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_LPRXPAUSE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_LPRXPAUSE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_LPRXPAUSE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_LPRXPAUSE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_LPRXPAUSE)& M_FW_PORT_CMD_LPRXPAUSE)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_LPRXPAUSE
value|V_FW_PORT_CMD_LPRXPAUSE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_PTYPE
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_PTYPE
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_PTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_PTYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_PTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_PTYPE)& M_FW_PORT_CMD_PTYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_LINKDNRC
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_LINKDNRC
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_LINKDNRC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_LINKDNRC)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_LINKDNRC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_LINKDNRC)& M_FW_PORT_CMD_LINKDNRC)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_MODTYPE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_MODTYPE
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_MODTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_MODTYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_MODTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_MODTYPE)& M_FW_PORT_CMD_MODTYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_DCBXDIS
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_DCBXDIS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_DCBXDIS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_DCBXDIS)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_DCBXDIS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_DCBXDIS)& M_FW_PORT_CMD_DCBXDIS)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_DCBXDIS
value|V_FW_PORT_CMD_DCBXDIS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_APPLY
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_APPLY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_APPLY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_APPLY)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_APPLY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_APPLY)& M_FW_PORT_CMD_APPLY)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_APPLY
value|V_FW_PORT_CMD_APPLY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_ALL_SYNCD
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_ALL_SYNCD
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_ALL_SYNCD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_ALL_SYNCD)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_ALL_SYNCD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_ALL_SYNCD)& M_FW_PORT_CMD_ALL_SYNCD)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_CMD_ALL_SYNCD
value|V_FW_PORT_CMD_ALL_SYNCD(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_DCB_VERSION
value|12
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_DCB_VERSION
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_DCB_VERSION
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_DCB_VERSION)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_DCB_VERSION
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_DCB_VERSION)& M_FW_PORT_CMD_DCB_VERSION)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_PFC_STATE
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_PFC_STATE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_PFC_STATE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_PFC_STATE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_PFC_STATE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_PFC_STATE)& M_FW_PORT_CMD_PFC_STATE)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_ETS_STATE
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_ETS_STATE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_ETS_STATE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_ETS_STATE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_ETS_STATE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_ETS_STATE)& M_FW_PORT_CMD_ETS_STATE)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_CMD_APP_STATE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_CMD_APP_STATE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_CMD_APP_STATE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_CMD_APP_STATE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_CMD_APP_STATE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_CMD_APP_STATE)& M_FW_PORT_CMD_APP_STATE)
end_define

begin_comment
comment|/*  *	These are configured into the VPD and hence tools that generate  *	VPD may use this enumeration.  *	extPHY	#lanes	T4_I2C	extI2C	BP_Eq	BP_ANEG	Speed  *  *	REMEMBER:  *	    Update the Common Code t4_hw.c:t4_get_port_type_description()  *	    with any new Firmware Port Technology Types!  */
end_comment

begin_enum
enum|enum
name|fw_port_type
block|{
name|FW_PORT_TYPE_FIBER_XFI
init|=
literal|0
block|,
comment|/* Y, 1, N, Y, N, N, 10G */
name|FW_PORT_TYPE_FIBER_XAUI
init|=
literal|1
block|,
comment|/* Y, 4, N, Y, N, N, 10G */
name|FW_PORT_TYPE_BT_SGMII
init|=
literal|2
block|,
comment|/* Y, 1, No, No, No, No, 1G/100M */
name|FW_PORT_TYPE_BT_XFI
init|=
literal|3
block|,
comment|/* Y, 1, No, No, No, No, 10G/1G/100M */
name|FW_PORT_TYPE_BT_XAUI
init|=
literal|4
block|,
comment|/* Y, 4, No, No, No, No, 10G/1G/100M */
name|FW_PORT_TYPE_KX4
init|=
literal|5
block|,
comment|/* No, 4, No, No, Yes, Yes, 10G */
name|FW_PORT_TYPE_CX4
init|=
literal|6
block|,
comment|/* No, 4, No, No, No, No, 10G */
name|FW_PORT_TYPE_KX
init|=
literal|7
block|,
comment|/* No, 1, No, No, Yes, No, 1G */
name|FW_PORT_TYPE_KR
init|=
literal|8
block|,
comment|/* No, 1, No, No, Yes, Yes, 10G */
name|FW_PORT_TYPE_SFP
init|=
literal|9
block|,
comment|/* No, 1, Yes, No, No, No, 10G */
name|FW_PORT_TYPE_BP_AP
init|=
literal|10
block|,
comment|/* No, 1, No, No, Yes, Yes, 10G, BP ANGE */
name|FW_PORT_TYPE_BP4_AP
init|=
literal|11
block|,
comment|/* No, 4, No, No, Yes, Yes, 10G, BP ANGE */
name|FW_PORT_TYPE_QSFP_10G
init|=
literal|12
block|,
comment|/* No, 1, Yes, No, No, No, 10G */
name|FW_PORT_TYPE_QSA
init|=
literal|13
block|,
comment|/* No, 1, Yes, No, No, No, 10G */
name|FW_PORT_TYPE_QSFP
init|=
literal|14
block|,
comment|/* No, 4, Yes, No, No, No, 40G */
name|FW_PORT_TYPE_BP40_BA
init|=
literal|15
block|,
comment|/* No, 4, No, No, Yes, Yes, 40G/10G/1G, BP ANGE */
name|FW_PORT_TYPE_KR4_100G
init|=
literal|16
block|,
comment|/* No, 4, 100G/40G/25G, Backplane */
name|FW_PORT_TYPE_CR4_QSFP
init|=
literal|17
block|,
comment|/* No, 4, 100G/40G/25G */
name|FW_PORT_TYPE_CR_QSFP
init|=
literal|18
block|,
comment|/* No, 1, 25G Spider cable */
name|FW_PORT_TYPE_CR2_QSFP
init|=
literal|19
block|,
comment|/* No, 2, 50G */
name|FW_PORT_TYPE_SFP28
init|=
literal|20
block|,
comment|/* No, 1, 25G/10G/1G */
name|FW_PORT_TYPE_KR_SFP28
init|=
literal|21
block|,
comment|/* No, 1, 25G/10G/1G using Backplane */
name|FW_PORT_TYPE_NONE
init|=
name|M_FW_PORT_CMD_PTYPE
block|}
enum|;
end_enum

begin_comment
comment|/* These are read from module's EEPROM and determined once the    module is inserted. */
end_comment

begin_enum
enum|enum
name|fw_port_module_type
block|{
name|FW_PORT_MOD_TYPE_NA
init|=
literal|0x0
block|,
name|FW_PORT_MOD_TYPE_LR
init|=
literal|0x1
block|,
name|FW_PORT_MOD_TYPE_SR
init|=
literal|0x2
block|,
name|FW_PORT_MOD_TYPE_ER
init|=
literal|0x3
block|,
name|FW_PORT_MOD_TYPE_TWINAX_PASSIVE
init|=
literal|0x4
block|,
name|FW_PORT_MOD_TYPE_TWINAX_ACTIVE
init|=
literal|0x5
block|,
name|FW_PORT_MOD_TYPE_LRM
init|=
literal|0x6
block|,
name|FW_PORT_MOD_TYPE_ERROR
init|=
name|M_FW_PORT_CMD_MODTYPE
operator|-
literal|3
block|,
name|FW_PORT_MOD_TYPE_UNKNOWN
init|=
name|M_FW_PORT_CMD_MODTYPE
operator|-
literal|2
block|,
name|FW_PORT_MOD_TYPE_NOTSUPPORTED
init|=
name|M_FW_PORT_CMD_MODTYPE
operator|-
literal|1
block|,
name|FW_PORT_MOD_TYPE_NONE
init|=
name|M_FW_PORT_CMD_MODTYPE
block|}
enum|;
end_enum

begin_comment
comment|/* used by FW and tools may use this to generate VPD */
end_comment

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
name|FW_PORT_MOD_SUB_TYPE_BCM5482
init|=
literal|0x6
block|,
name|FW_PORT_MOD_SUB_TYPE_BCM84856
init|=
literal|0x7
block|,
name|FW_PORT_MOD_SUB_TYPE_BT_VSC8634
init|=
literal|0x8
block|,
comment|/* 	 * The following will never been in the VPD.  They are TWINAX cable 	 * lengths decoded from SFP+ module i2c PROMs.  These should almost 	 * certainly go somewhere else ... 	 */
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

begin_comment
comment|/* link down reason codes (3b) */
end_comment

begin_enum
enum|enum
name|fw_port_link_dn_rc
block|{
name|FW_PORT_LINK_DN_RC_NONE
block|,
name|FW_PORT_LINK_DN_RC_REMFLT
block|,
comment|/* Remote fault detected */
name|FW_PORT_LINK_DN_ANEG_F
block|,
comment|/* Auto-negotiation fault */
name|FW_PORT_LINK_DN_RESERVED3
block|,
name|FW_PORT_LINK_DN_OVERHEAT
block|,
comment|/* Port overheated */
name|FW_PORT_LINK_DN_UNKNOWN
block|,
comment|/* Unable to determine reason */
name|FW_PORT_LINK_DN_RX_LOS
block|,
comment|/* No RX signal detected */
name|FW_PORT_LINK_DN_RESERVED7
block|}
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
value|(FW_NUM_PORT_TX_STATS + \                                  FW_NUM_PORT_RX_STATS)
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
name|__u8
name|nstats_bg_bm
decl_stmt|;
name|__u8
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

begin_define
define|#
directive|define
name|S_FW_PORT_STATS_CMD_NSTATS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_STATS_CMD_NSTATS
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_STATS_CMD_NSTATS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_STATS_CMD_NSTATS)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_STATS_CMD_NSTATS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_STATS_CMD_NSTATS)& M_FW_PORT_STATS_CMD_NSTATS)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_STATS_CMD_BG_BM
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_STATS_CMD_BG_BM
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_STATS_CMD_BG_BM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_STATS_CMD_BG_BM)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_STATS_CMD_BG_BM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_STATS_CMD_BG_BM)& M_FW_PORT_STATS_CMD_BG_BM)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_STATS_CMD_TX
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_STATS_CMD_TX
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_STATS_CMD_TX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_STATS_CMD_TX)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_STATS_CMD_TX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_STATS_CMD_TX)& M_FW_PORT_STATS_CMD_TX)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_STATS_CMD_TX
value|V_FW_PORT_STATS_CMD_TX(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_STATS_CMD_IX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_STATS_CMD_IX
value|0x3f
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_STATS_CMD_IX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_STATS_CMD_IX)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_STATS_CMD_IX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_STATS_CMD_IX)& M_FW_PORT_STATS_CMD_IX)
end_define

begin_comment
comment|/* port loopback stats */
end_comment

begin_define
define|#
directive|define
name|FW_NUM_LB_STATS
value|14
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
name|__u8
name|nstats_bg_bm
decl_stmt|;
name|__u8
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

begin_define
define|#
directive|define
name|S_FW_PORT_LB_STATS_CMD_LBPORT
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_LB_STATS_CMD_LBPORT
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_LB_STATS_CMD_LBPORT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_LB_STATS_CMD_LBPORT)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_LB_STATS_CMD_LBPORT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_LB_STATS_CMD_LBPORT)& M_FW_PORT_LB_STATS_CMD_LBPORT)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_LB_STATS_CMD_NSTATS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_LB_STATS_CMD_NSTATS
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_LB_STATS_CMD_NSTATS
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_LB_STATS_CMD_NSTATS)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_LB_STATS_CMD_NSTATS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_LB_STATS_CMD_NSTATS)& M_FW_PORT_LB_STATS_CMD_NSTATS)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_LB_STATS_CMD_BG_BM
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_LB_STATS_CMD_BG_BM
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_LB_STATS_CMD_BG_BM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_LB_STATS_CMD_BG_BM)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_LB_STATS_CMD_BG_BM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_LB_STATS_CMD_BG_BM)& M_FW_PORT_LB_STATS_CMD_BG_BM)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_LB_STATS_CMD_IX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_LB_STATS_CMD_IX
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_LB_STATS_CMD_IX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_LB_STATS_CMD_IX)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_LB_STATS_CMD_IX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_LB_STATS_CMD_IX)& M_FW_PORT_LB_STATS_CMD_IX)
end_define

begin_comment
comment|/* Trace related defines */
end_comment

begin_define
define|#
directive|define
name|FW_TRACE_CAPTURE_MAX_SINGLE_FLT_MODE
value|10240
end_define

begin_define
define|#
directive|define
name|FW_TRACE_CAPTURE_MAX_MULTI_FLT_MODE
value|2560
end_define

begin_struct
struct|struct
name|fw_port_trace_cmd
block|{
name|__be32
name|op_to_portid
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be16
name|traceen_to_pciech
decl_stmt|;
name|__be16
name|qnum
decl_stmt|;
name|__be32
name|r5
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_CMD_PORTID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_CMD_PORTID
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_TRACE_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_CMD_PORTID)& M_FW_PORT_TRACE_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_CMD_TRACEEN
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_CMD_TRACEEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_CMD_TRACEEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_TRACE_CMD_TRACEEN)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_CMD_TRACEEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_CMD_TRACEEN)& M_FW_PORT_TRACE_CMD_TRACEEN)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_TRACE_CMD_TRACEEN
value|V_FW_PORT_TRACE_CMD_TRACEEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_CMD_FLTMODE
value|14
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_CMD_FLTMODE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_CMD_FLTMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_TRACE_CMD_FLTMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_CMD_FLTMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_CMD_FLTMODE)& M_FW_PORT_TRACE_CMD_FLTMODE)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_TRACE_CMD_FLTMODE
value|V_FW_PORT_TRACE_CMD_FLTMODE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_CMD_DUPLEN
value|13
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_CMD_DUPLEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_CMD_DUPLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_TRACE_CMD_DUPLEN)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_CMD_DUPLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_CMD_DUPLEN)& M_FW_PORT_TRACE_CMD_DUPLEN)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_TRACE_CMD_DUPLEN
value|V_FW_PORT_TRACE_CMD_DUPLEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_CMD_RUNTFLTSIZE
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_CMD_RUNTFLTSIZE
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_CMD_RUNTFLTSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_TRACE_CMD_RUNTFLTSIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_CMD_RUNTFLTSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_CMD_RUNTFLTSIZE)& \      M_FW_PORT_TRACE_CMD_RUNTFLTSIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_CMD_PCIECH
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_CMD_PCIECH
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_CMD_PCIECH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_TRACE_CMD_PCIECH)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_CMD_PCIECH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_CMD_PCIECH)& M_FW_PORT_TRACE_CMD_PCIECH)
end_define

begin_struct
struct|struct
name|fw_port_trace_mmap_cmd
block|{
name|__be32
name|op_to_portid
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be32
name|fid_to_skipoffset
decl_stmt|;
name|__be32
name|minpktsize_capturemax
decl_stmt|;
name|__u8
name|map
index|[
literal|224
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_MMAP_CMD_PORTID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_MMAP_CMD_PORTID
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_MMAP_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_TRACE_MMAP_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_MMAP_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_MMAP_CMD_PORTID)& \      M_FW_PORT_TRACE_MMAP_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_MMAP_CMD_FID
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_MMAP_CMD_FID
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_MMAP_CMD_FID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PORT_TRACE_MMAP_CMD_FID)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_MMAP_CMD_FID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_MMAP_CMD_FID)& M_FW_PORT_TRACE_MMAP_CMD_FID)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_MMAP_CMD_MMAPEN
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_MMAP_CMD_MMAPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_MMAP_CMD_MMAPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_TRACE_MMAP_CMD_MMAPEN)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_MMAP_CMD_MMAPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_MMAP_CMD_MMAPEN)& \      M_FW_PORT_TRACE_MMAP_CMD_MMAPEN)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_TRACE_MMAP_CMD_MMAPEN
value|V_FW_PORT_TRACE_MMAP_CMD_MMAPEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_MMAP_CMD_DCMAPEN
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_MMAP_CMD_DCMAPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_MMAP_CMD_DCMAPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_TRACE_MMAP_CMD_DCMAPEN)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_MMAP_CMD_DCMAPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_MMAP_CMD_DCMAPEN)& \      M_FW_PORT_TRACE_MMAP_CMD_DCMAPEN)
end_define

begin_define
define|#
directive|define
name|F_FW_PORT_TRACE_MMAP_CMD_DCMAPEN
value|V_FW_PORT_TRACE_MMAP_CMD_DCMAPEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_MMAP_CMD_SKIPLENGTH
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_MMAP_CMD_SKIPLENGTH
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_MMAP_CMD_SKIPLENGTH
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_TRACE_MMAP_CMD_SKIPLENGTH)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_MMAP_CMD_SKIPLENGTH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_MMAP_CMD_SKIPLENGTH)& \      M_FW_PORT_TRACE_MMAP_CMD_SKIPLENGTH)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_MMAP_CMD_SKIPOFFSET
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_MMAP_CMD_SKIPOFFSET
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_MMAP_CMD_SKIPOFFSET
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_TRACE_MMAP_CMD_SKIPOFFSET)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_MMAP_CMD_SKIPOFFSET
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_MMAP_CMD_SKIPOFFSET)& \      M_FW_PORT_TRACE_MMAP_CMD_SKIPOFFSET)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_MMAP_CMD_MINPKTSIZE
value|18
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_MMAP_CMD_MINPKTSIZE
value|0x3fff
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_MMAP_CMD_MINPKTSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_TRACE_MMAP_CMD_MINPKTSIZE)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_MMAP_CMD_MINPKTSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_MMAP_CMD_MINPKTSIZE)& \      M_FW_PORT_TRACE_MMAP_CMD_MINPKTSIZE)
end_define

begin_define
define|#
directive|define
name|S_FW_PORT_TRACE_MMAP_CMD_CAPTUREMAX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PORT_TRACE_MMAP_CMD_CAPTUREMAX
value|0x3fff
end_define

begin_define
define|#
directive|define
name|V_FW_PORT_TRACE_MMAP_CMD_CAPTUREMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_PORT_TRACE_MMAP_CMD_CAPTUREMAX)
end_define

begin_define
define|#
directive|define
name|G_FW_PORT_TRACE_MMAP_CMD_CAPTUREMAX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PORT_TRACE_MMAP_CMD_CAPTUREMAX)& \      M_FW_PORT_TRACE_MMAP_CMD_CAPTUREMAX)
end_define

begin_enum
enum|enum
name|fw_ptp_subop
block|{
comment|/* none */
name|FW_PTP_SC_INIT_TIMER
init|=
literal|0x00
block|,
name|FW_PTP_SC_TX_TYPE
init|=
literal|0x01
block|,
comment|/* init */
name|FW_PTP_SC_RXTIME_STAMP
init|=
literal|0x08
block|,
name|FW_PTP_SC_RDRX_TYPE
init|=
literal|0x09
block|,
comment|/* ts */
name|FW_PTP_SC_ADJ_FREQ
init|=
literal|0x10
block|,
name|FW_PTP_SC_ADJ_TIME
init|=
literal|0x11
block|,
name|FW_PTP_SC_ADJ_FTIME
init|=
literal|0x12
block|,
name|FW_PTP_SC_WALL_CLOCK
init|=
literal|0x13
block|,
name|FW_PTP_SC_GET_TIME
init|=
literal|0x14
block|,
name|FW_PTP_SC_SET_TIME
init|=
literal|0x15
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_ptp_cmd
block|{
name|__be32
name|op_to_portid
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
union|union
name|fw_ptp
block|{
struct|struct
name|fw_ptp_sc
block|{
name|__u8
name|sc
decl_stmt|;
name|__u8
name|r3
index|[
literal|7
index|]
decl_stmt|;
block|}
name|scmd
struct|;
struct|struct
name|fw_ptp_init
block|{
name|__u8
name|sc
decl_stmt|;
name|__u8
name|txchan
decl_stmt|;
name|__be16
name|absid
decl_stmt|;
name|__be16
name|mode
decl_stmt|;
name|__be16
name|r3
decl_stmt|;
block|}
name|init
struct|;
struct|struct
name|fw_ptp_ts
block|{
name|__u8
name|sc
decl_stmt|;
name|__u8
name|sign
decl_stmt|;
name|__be16
name|r3
decl_stmt|;
name|__be32
name|ppb
decl_stmt|;
name|__be64
name|tm
decl_stmt|;
block|}
name|ts
struct|;
block|}
name|u
union|;
name|__be64
name|r3
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_PTP_CMD_PORTID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_PTP_CMD_PORTID
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_PTP_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_PTP_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|G_FW_PTP_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_PTP_CMD_PORTID)& M_FW_PTP_CMD_PORTID)
end_define

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
name|S_FW_RSS_IND_TBL_CMD_VIID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_VIID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_VIID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_VIID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_VIID)& M_FW_RSS_IND_TBL_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ0
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ0
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ0
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ0)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ0
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ0)& M_FW_RSS_IND_TBL_CMD_IQ0)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ1
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ1
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ1
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ1)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ1
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ1)& M_FW_RSS_IND_TBL_CMD_IQ1)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ2
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ2
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ2
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ2)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ2
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ2)& M_FW_RSS_IND_TBL_CMD_IQ2)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ3
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ3
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ3
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ3)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ3
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ3)& M_FW_RSS_IND_TBL_CMD_IQ3)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ4
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ4
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ4
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ4)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ4
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ4)& M_FW_RSS_IND_TBL_CMD_IQ4)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ5
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ5
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ5
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ5)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ5
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ5)& M_FW_RSS_IND_TBL_CMD_IQ5)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ6
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ6
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ6
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ6)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ6
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ6)& M_FW_RSS_IND_TBL_CMD_IQ6)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ7
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ7
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ7
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ7)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ7
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ7)& M_FW_RSS_IND_TBL_CMD_IQ7)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ8
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ8
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ8
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ8)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ8
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ8)& M_FW_RSS_IND_TBL_CMD_IQ8)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ9
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ9
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ9
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ9)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ9
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ9)& M_FW_RSS_IND_TBL_CMD_IQ9)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ10
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ10
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ10
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ10)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ10
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ10)& M_FW_RSS_IND_TBL_CMD_IQ10)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ11
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ11
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ11
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ11)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ11
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ11)& M_FW_RSS_IND_TBL_CMD_IQ11)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ12
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ12
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ12
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ12)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ12
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ12)& M_FW_RSS_IND_TBL_CMD_IQ12)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ13
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ13
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ13
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ13)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ13
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ13)& M_FW_RSS_IND_TBL_CMD_IQ13)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ14
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ14
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ14
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ14)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ14
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ14)& M_FW_RSS_IND_TBL_CMD_IQ14)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ15
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ15
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ15
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ15)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ15
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ15)& M_FW_RSS_IND_TBL_CMD_IQ15)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ16
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ16
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ16)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ16)& M_FW_RSS_IND_TBL_CMD_IQ16)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ17
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ17
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ17
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ17)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ17
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ17)& M_FW_RSS_IND_TBL_CMD_IQ17)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ18
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ18
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ18
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ18)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ18
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ18)& M_FW_RSS_IND_TBL_CMD_IQ18)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ19
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ19
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ19
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ19)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ19
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ19)& M_FW_RSS_IND_TBL_CMD_IQ19)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ20
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ20
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ20
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ20)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ20
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ20)& M_FW_RSS_IND_TBL_CMD_IQ20)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ21
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ21
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ21
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ21)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ21
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ21)& M_FW_RSS_IND_TBL_CMD_IQ21)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ22
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ22
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ22
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ22)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ22
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ22)& M_FW_RSS_IND_TBL_CMD_IQ22)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ23
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ23
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ23
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ23)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ23
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ23)& M_FW_RSS_IND_TBL_CMD_IQ23)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ24
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ24
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ24
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ24)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ24
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ24)& M_FW_RSS_IND_TBL_CMD_IQ24)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ25
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ25
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ25
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ25)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ25
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ25)& M_FW_RSS_IND_TBL_CMD_IQ25)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ26
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ26
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ26
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ26)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ26
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ26)& M_FW_RSS_IND_TBL_CMD_IQ26)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ27
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ27
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ27
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ27)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ27
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ27)& M_FW_RSS_IND_TBL_CMD_IQ27)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ28
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ28
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ28
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ28)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ28
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ28)& M_FW_RSS_IND_TBL_CMD_IQ28)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ29
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ29
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ29
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ29)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ29
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ29)& M_FW_RSS_IND_TBL_CMD_IQ29)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ30
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ30
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ30
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ30)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ30
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ30)& M_FW_RSS_IND_TBL_CMD_IQ30)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_IND_TBL_CMD_IQ31
value|10
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_IND_TBL_CMD_IQ31
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_IND_TBL_CMD_IQ31
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_IND_TBL_CMD_IQ31)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_IND_TBL_CMD_IQ31
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_IND_TBL_CMD_IQ31)& M_FW_RSS_IND_TBL_CMD_IQ31)
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
name|mode_keymode
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
name|S_FW_RSS_GLB_CONFIG_CMD_MODE
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_MODE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_MODE)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_MODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_MODE)& M_FW_RSS_GLB_CONFIG_CMD_MODE)
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
name|FW_RSS_GLB_CONFIG_CMD_MODE_MAX
value|1
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_GLB_CONFIG_CMD_KEYMODE
value|26
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_KEYMODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_KEYMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_KEYMODE)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_KEYMODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_KEYMODE)& \      M_FW_RSS_GLB_CONFIG_CMD_KEYMODE)
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_KEYMODE_GLBKEY
value|0
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_KEYMODE_GLBVF_KEY
value|1
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_KEYMODE_PFVF_KEY
value|2
end_define

begin_define
define|#
directive|define
name|FW_RSS_GLB_CONFIG_CMD_KEYMODE_IDXVF_KEY
value|3
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_GLB_CONFIG_CMD_SYNMAPEN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_SYNMAPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_SYNMAPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_SYNMAPEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_SYNMAPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_SYNMAPEN)& \      M_FW_RSS_GLB_CONFIG_CMD_SYNMAPEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_GLB_CONFIG_CMD_SYNMAPEN
value|V_FW_RSS_GLB_CONFIG_CMD_SYNMAPEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6)& \      M_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6
define|\
value|V_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV6(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6)& \      M_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6
define|\
value|V_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV6(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4)& \      M_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4
define|\
value|V_FW_RSS_GLB_CONFIG_CMD_SYN4TUPENIPV4(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4)& \      M_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4
define|\
value|V_FW_RSS_GLB_CONFIG_CMD_SYN2TUPENIPV4(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_GLB_CONFIG_CMD_OFDMAPEN
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_OFDMAPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_OFDMAPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_OFDMAPEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_OFDMAPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_OFDMAPEN)& \      M_FW_RSS_GLB_CONFIG_CMD_OFDMAPEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_GLB_CONFIG_CMD_OFDMAPEN
value|V_FW_RSS_GLB_CONFIG_CMD_OFDMAPEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_GLB_CONFIG_CMD_TNLMAPEN
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_TNLMAPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_TNLMAPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_TNLMAPEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_TNLMAPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_TNLMAPEN)& \      M_FW_RSS_GLB_CONFIG_CMD_TNLMAPEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_GLB_CONFIG_CMD_TNLMAPEN
value|V_FW_RSS_GLB_CONFIG_CMD_TNLMAPEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_GLB_CONFIG_CMD_TNLALLLKP
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_TNLALLLKP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_TNLALLLKP
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_TNLALLLKP)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_TNLALLLKP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_TNLALLLKP)& \      M_FW_RSS_GLB_CONFIG_CMD_TNLALLLKP)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_GLB_CONFIG_CMD_TNLALLLKP
define|\
value|V_FW_RSS_GLB_CONFIG_CMD_TNLALLLKP(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ)& \      M_FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ
define|\
value|V_FW_RSS_GLB_CONFIG_CMD_HASHTOEPLITZ(1U)
end_define

begin_struct
struct|struct
name|fw_rss_vi_config_cmd
block|{
name|__be32
name|op_to_viid
decl_stmt|;
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
name|__be32
name|secretkeyidx_pkd
decl_stmt|;
name|__be32
name|secretkeyxor
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
name|S_FW_RSS_VI_CONFIG_CMD_VIID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_VI_CONFIG_CMD_VIID
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_VI_CONFIG_CMD_VIID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_VI_CONFIG_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_VI_CONFIG_CMD_VIID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_VI_CONFIG_CMD_VIID)& M_FW_RSS_VI_CONFIG_CMD_VIID)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_VI_CONFIG_CMD_DEFAULTQ
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_VI_CONFIG_CMD_DEFAULTQ
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_VI_CONFIG_CMD_DEFAULTQ
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_VI_CONFIG_CMD_DEFAULTQ)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_VI_CONFIG_CMD_DEFAULTQ
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_VI_CONFIG_CMD_DEFAULTQ)& \      M_FW_RSS_VI_CONFIG_CMD_DEFAULTQ)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN)& \      M_FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN
define|\
value|V_FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN)& \      M_FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN
define|\
value|V_FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN)& \      M_FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN
define|\
value|V_FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN
value|1
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN)& \      M_FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN
define|\
value|V_FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_VI_CONFIG_CMD_UDPEN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_VI_CONFIG_CMD_UDPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_VI_CONFIG_CMD_UDPEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_RSS_VI_CONFIG_CMD_UDPEN)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_VI_CONFIG_CMD_UDPEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_VI_CONFIG_CMD_UDPEN)& M_FW_RSS_VI_CONFIG_CMD_UDPEN)
end_define

begin_define
define|#
directive|define
name|F_FW_RSS_VI_CONFIG_CMD_UDPEN
value|V_FW_RSS_VI_CONFIG_CMD_UDPEN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_RSS_VI_CONFIG_CMD_SECRETKEYIDX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_RSS_VI_CONFIG_CMD_SECRETKEYIDX
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_RSS_VI_CONFIG_CMD_SECRETKEYIDX
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_RSS_VI_CONFIG_CMD_SECRETKEYIDX)
end_define

begin_define
define|#
directive|define
name|G_FW_RSS_VI_CONFIG_CMD_SECRETKEYIDX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_RSS_VI_CONFIG_CMD_SECRETKEYIDX)& \      M_FW_RSS_VI_CONFIG_CMD_SECRETKEYIDX)
end_define

begin_enum
enum|enum
name|fw_sched_sc
block|{
name|FW_SCHED_SC_CONFIG
init|=
literal|0
block|,
name|FW_SCHED_SC_PARAMS
init|=
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_sched_type
block|{
name|FW_SCHED_TYPE_PKTSCHED
init|=
literal|0
block|,
name|FW_SCHED_TYPE_STREAMSCHED
init|=
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_sched_params_level
block|{
name|FW_SCHED_PARAMS_LEVEL_CL_RL
init|=
literal|0
block|,
name|FW_SCHED_PARAMS_LEVEL_CL_WRR
init|=
literal|1
block|,
name|FW_SCHED_PARAMS_LEVEL_CH_RL
init|=
literal|2
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_sched_params_mode
block|{
name|FW_SCHED_PARAMS_MODE_CLASS
init|=
literal|0
block|,
name|FW_SCHED_PARAMS_MODE_FLOW
init|=
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_sched_params_unit
block|{
name|FW_SCHED_PARAMS_UNIT_BITRATE
init|=
literal|0
block|,
name|FW_SCHED_PARAMS_UNIT_PKTRATE
init|=
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_sched_params_rate
block|{
name|FW_SCHED_PARAMS_RATE_REL
init|=
literal|0
block|,
name|FW_SCHED_PARAMS_RATE_ABS
init|=
literal|1
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_sched_cmd
block|{
name|__be32
name|op_to_write
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
union|union
name|fw_sched
block|{
struct|struct
name|fw_sched_config
block|{
name|__u8
name|sc
decl_stmt|;
name|__u8
name|type
decl_stmt|;
name|__u8
name|minmaxen
decl_stmt|;
name|__u8
name|r3
index|[
literal|5
index|]
decl_stmt|;
name|__u8
name|nclasses
index|[
literal|4
index|]
decl_stmt|;
name|__be32
name|r4
decl_stmt|;
block|}
name|config
struct|;
struct|struct
name|fw_sched_params
block|{
name|__u8
name|sc
decl_stmt|;
name|__u8
name|type
decl_stmt|;
name|__u8
name|level
decl_stmt|;
name|__u8
name|mode
decl_stmt|;
name|__u8
name|unit
decl_stmt|;
name|__u8
name|rate
decl_stmt|;
name|__u8
name|ch
decl_stmt|;
name|__u8
name|cl
decl_stmt|;
name|__be32
name|min
decl_stmt|;
name|__be32
name|max
decl_stmt|;
name|__be16
name|weight
decl_stmt|;
name|__be16
name|pktsize
decl_stmt|;
name|__be16
name|burstsize
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
block|}
name|params
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	length of the formatting string  */
end_comment

begin_define
define|#
directive|define
name|FW_DEVLOG_FMT_LEN
value|192
end_define

begin_comment
comment|/*  *	maximum number of the formatting string parameters  */
end_comment

begin_define
define|#
directive|define
name|FW_DEVLOG_FMT_PARAMS_NUM
value|8
end_define

begin_comment
comment|/*  *	priority levels  */
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
comment|/*  *	facilities that may send a log message  */
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
name|FW_DEVLOG_FACILITY_COiSCSI
init|=
literal|0x36
block|,
name|FW_DEVLOG_FACILITY_MAX
init|=
literal|0x38
block|, }
enum|;
end_enum

begin_comment
comment|/*  *	log message format  */
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
name|S_FW_DEVLOG_CMD_MEMTYPE_DEVLOG
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_DEVLOG_CMD_MEMTYPE_DEVLOG
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_DEVLOG_CMD_MEMTYPE_DEVLOG
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_DEVLOG_CMD_MEMTYPE_DEVLOG)
end_define

begin_define
define|#
directive|define
name|G_FW_DEVLOG_CMD_MEMTYPE_DEVLOG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DEVLOG_CMD_MEMTYPE_DEVLOG)& M_FW_DEVLOG_CMD_MEMTYPE_DEVLOG)
end_define

begin_define
define|#
directive|define
name|S_FW_DEVLOG_CMD_MEMADDR16_DEVLOG
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_DEVLOG_CMD_MEMADDR16_DEVLOG
value|0xfffffff
end_define

begin_define
define|#
directive|define
name|V_FW_DEVLOG_CMD_MEMADDR16_DEVLOG
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_DEVLOG_CMD_MEMADDR16_DEVLOG)
end_define

begin_define
define|#
directive|define
name|G_FW_DEVLOG_CMD_MEMADDR16_DEVLOG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DEVLOG_CMD_MEMADDR16_DEVLOG)& \      M_FW_DEVLOG_CMD_MEMADDR16_DEVLOG)
end_define

begin_enum
enum|enum
name|fw_watchdog_actions
block|{
name|FW_WATCHDOG_ACTION_SHUTDOWN
init|=
literal|0
block|,
name|FW_WATCHDOG_ACTION_FLR
init|=
literal|1
block|,
name|FW_WATCHDOG_ACTION_BYPASS
init|=
literal|2
block|,
name|FW_WATCHDOG_ACTION_TMPCHK
init|=
literal|3
block|,
name|FW_WATCHDOG_ACTION_PAUSEOFF
init|=
literal|4
block|,
name|FW_WATCHDOG_ACTION_MAX
init|=
literal|5
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|FW_WATCHDOG_MAX_TIMEOUT_SECS
value|60
end_define

begin_struct
struct|struct
name|fw_watchdog_cmd
block|{
name|__be32
name|op_to_vfn
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be32
name|timeout
decl_stmt|;
name|__be32
name|action
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_WATCHDOG_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_WATCHDOG_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_WATCHDOG_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WATCHDOG_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_WATCHDOG_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_WATCHDOG_CMD_PFN)& M_FW_WATCHDOG_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_WATCHDOG_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_WATCHDOG_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_WATCHDOG_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_WATCHDOG_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_WATCHDOG_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_WATCHDOG_CMD_VFN)& M_FW_WATCHDOG_CMD_VFN)
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
name|S_FW_CLIP_CMD_ALLOC
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_CLIP_CMD_ALLOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_CLIP_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CLIP_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_CLIP_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CLIP_CMD_ALLOC)& M_FW_CLIP_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|F_FW_CLIP_CMD_ALLOC
value|V_FW_CLIP_CMD_ALLOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_CLIP_CMD_FREE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_CLIP_CMD_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_CLIP_CMD_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CLIP_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_CLIP_CMD_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CLIP_CMD_FREE)& M_FW_CLIP_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_CLIP_CMD_FREE
value|V_FW_CLIP_CMD_FREE(1U)
end_define

begin_comment
comment|/******************************************************************************  *   F O i S C S I   C O M M A N D s  **************************************/
end_comment

begin_define
define|#
directive|define
name|FW_CHNET_IFACE_ADDR_MAX
value|3
end_define

begin_enum
enum|enum
name|fw_chnet_iface_cmd_subop
block|{
name|FW_CHNET_IFACE_CMD_SUBOP_NOOP
init|=
literal|0
block|,
name|FW_CHNET_IFACE_CMD_SUBOP_LINK_UP
block|,
name|FW_CHNET_IFACE_CMD_SUBOP_LINK_DOWN
block|,
name|FW_CHNET_IFACE_CMD_SUBOP_MTU_SET
block|,
name|FW_CHNET_IFACE_CMD_SUBOP_MTU_GET
block|,
name|FW_CHNET_IFACE_CMD_SUBOP_MAX
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_chnet_iface_cmd
block|{
name|__be32
name|op_to_portid
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__u8
name|subop
decl_stmt|;
name|__u8
name|r2
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|ifid_ifstate
decl_stmt|;
name|__be16
name|mtu
decl_stmt|;
name|__be16
name|vlanid
decl_stmt|;
name|__be32
name|r3
decl_stmt|;
name|__be16
name|r4
decl_stmt|;
name|__u8
name|mac
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
name|S_FW_CHNET_IFACE_CMD_PORTID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_CHNET_IFACE_CMD_PORTID
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_CHNET_IFACE_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CHNET_IFACE_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|G_FW_CHNET_IFACE_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CHNET_IFACE_CMD_PORTID)& M_FW_CHNET_IFACE_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|S_FW_CHNET_IFACE_CMD_IFID
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_CHNET_IFACE_CMD_IFID
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_FW_CHNET_IFACE_CMD_IFID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CHNET_IFACE_CMD_IFID)
end_define

begin_define
define|#
directive|define
name|G_FW_CHNET_IFACE_CMD_IFID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CHNET_IFACE_CMD_IFID)& M_FW_CHNET_IFACE_CMD_IFID)
end_define

begin_define
define|#
directive|define
name|S_FW_CHNET_IFACE_CMD_IFSTATE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_CHNET_IFACE_CMD_IFSTATE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_CHNET_IFACE_CMD_IFSTATE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_CHNET_IFACE_CMD_IFSTATE)
end_define

begin_define
define|#
directive|define
name|G_FW_CHNET_IFACE_CMD_IFSTATE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_CHNET_IFACE_CMD_IFSTATE)& M_FW_CHNET_IFACE_CMD_IFSTATE)
end_define

begin_struct
struct|struct
name|fw_fcoe_res_info_cmd
block|{
name|__be32
name|op_to_read
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be16
name|e_d_tov
decl_stmt|;
name|__be16
name|r_a_tov_seq
decl_stmt|;
name|__be16
name|r_a_tov_els
decl_stmt|;
name|__be16
name|r_r_tov
decl_stmt|;
name|__be32
name|max_xchgs
decl_stmt|;
name|__be32
name|max_ssns
decl_stmt|;
name|__be32
name|used_xchgs
decl_stmt|;
name|__be32
name|used_ssns
decl_stmt|;
name|__be32
name|max_fcfs
decl_stmt|;
name|__be32
name|max_vnps
decl_stmt|;
name|__be32
name|used_fcfs
decl_stmt|;
name|__be32
name|used_vnps
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_fcoe_link_cmd
block|{
name|__be32
name|op_to_portid
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be32
name|sub_opcode_fcfi
decl_stmt|;
name|__u8
name|r3
decl_stmt|;
name|__u8
name|lstatus
decl_stmt|;
name|__be16
name|flags
decl_stmt|;
name|__u8
name|r4
decl_stmt|;
name|__u8
name|set_vlan
decl_stmt|;
name|__be16
name|vlan_id
decl_stmt|;
name|__be32
name|vnpi_pkd
decl_stmt|;
name|__be16
name|r6
decl_stmt|;
name|__u8
name|phy_mac
index|[
literal|6
index|]
decl_stmt|;
name|__u8
name|vnport_wwnn
index|[
literal|8
index|]
decl_stmt|;
name|__u8
name|vnport_wwpn
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_FCOE_LINK_CMD_PORTID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_LINK_CMD_PORTID
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_LINK_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_LINK_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_LINK_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_LINK_CMD_PORTID)& M_FW_FCOE_LINK_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_LINK_CMD_SUB_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_LINK_CMD_SUB_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_LINK_CMD_SUB_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_FCOE_LINK_CMD_SUB_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_LINK_CMD_SUB_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_LINK_CMD_SUB_OPCODE)& M_FW_FCOE_LINK_CMD_SUB_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_LINK_CMD_FCFI
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_LINK_CMD_FCFI
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_LINK_CMD_FCFI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_LINK_CMD_FCFI)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_LINK_CMD_FCFI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_LINK_CMD_FCFI)& M_FW_FCOE_LINK_CMD_FCFI)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_LINK_CMD_VNPI
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_LINK_CMD_VNPI
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_LINK_CMD_VNPI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_LINK_CMD_VNPI)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_LINK_CMD_VNPI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_LINK_CMD_VNPI)& M_FW_FCOE_LINK_CMD_VNPI)
end_define

begin_struct
struct|struct
name|fw_fcoe_vnp_cmd
block|{
name|__be32
name|op_to_fcfi
decl_stmt|;
name|__be32
name|alloc_to_len16
decl_stmt|;
name|__be32
name|gen_wwn_to_vnpi
decl_stmt|;
name|__be32
name|vf_id
decl_stmt|;
name|__be16
name|iqid
decl_stmt|;
name|__u8
name|vnport_mac
index|[
literal|6
index|]
decl_stmt|;
name|__u8
name|vnport_wwnn
index|[
literal|8
index|]
decl_stmt|;
name|__u8
name|vnport_wwpn
index|[
literal|8
index|]
decl_stmt|;
name|__u8
name|cmn_srv_parms
index|[
literal|16
index|]
decl_stmt|;
name|__u8
name|clsp_word_0_1
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_FCOE_VNP_CMD_FCFI
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_VNP_CMD_FCFI
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_VNP_CMD_FCFI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_VNP_CMD_FCFI)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_VNP_CMD_FCFI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_VNP_CMD_FCFI)& M_FW_FCOE_VNP_CMD_FCFI)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_VNP_CMD_ALLOC
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_VNP_CMD_ALLOC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_VNP_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_VNP_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_VNP_CMD_ALLOC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_VNP_CMD_ALLOC)& M_FW_FCOE_VNP_CMD_ALLOC)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_VNP_CMD_ALLOC
value|V_FW_FCOE_VNP_CMD_ALLOC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_VNP_CMD_FREE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_VNP_CMD_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_VNP_CMD_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_VNP_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_VNP_CMD_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_VNP_CMD_FREE)& M_FW_FCOE_VNP_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_VNP_CMD_FREE
value|V_FW_FCOE_VNP_CMD_FREE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_VNP_CMD_MODIFY
value|29
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_VNP_CMD_MODIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_VNP_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_VNP_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_VNP_CMD_MODIFY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_VNP_CMD_MODIFY)& M_FW_FCOE_VNP_CMD_MODIFY)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_VNP_CMD_MODIFY
value|V_FW_FCOE_VNP_CMD_MODIFY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_VNP_CMD_GEN_WWN
value|22
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_VNP_CMD_GEN_WWN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_VNP_CMD_GEN_WWN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_VNP_CMD_GEN_WWN)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_VNP_CMD_GEN_WWN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_VNP_CMD_GEN_WWN)& M_FW_FCOE_VNP_CMD_GEN_WWN)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_VNP_CMD_GEN_WWN
value|V_FW_FCOE_VNP_CMD_GEN_WWN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_VNP_CMD_PERSIST
value|21
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_VNP_CMD_PERSIST
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_VNP_CMD_PERSIST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_VNP_CMD_PERSIST)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_VNP_CMD_PERSIST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_VNP_CMD_PERSIST)& M_FW_FCOE_VNP_CMD_PERSIST)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_VNP_CMD_PERSIST
value|V_FW_FCOE_VNP_CMD_PERSIST(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_VNP_CMD_VFID_EN
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_VNP_CMD_VFID_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_VNP_CMD_VFID_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_VNP_CMD_VFID_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_VNP_CMD_VFID_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_VNP_CMD_VFID_EN)& M_FW_FCOE_VNP_CMD_VFID_EN)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_VNP_CMD_VFID_EN
value|V_FW_FCOE_VNP_CMD_VFID_EN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_VNP_CMD_VNPI
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_VNP_CMD_VNPI
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_VNP_CMD_VNPI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_VNP_CMD_VNPI)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_VNP_CMD_VNPI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_VNP_CMD_VNPI)& M_FW_FCOE_VNP_CMD_VNPI)
end_define

begin_struct
struct|struct
name|fw_fcoe_sparams_cmd
block|{
name|__be32
name|op_to_portid
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__u8
name|r3
index|[
literal|7
index|]
decl_stmt|;
name|__u8
name|cos
decl_stmt|;
name|__u8
name|lport_wwnn
index|[
literal|8
index|]
decl_stmt|;
name|__u8
name|lport_wwpn
index|[
literal|8
index|]
decl_stmt|;
name|__u8
name|cmn_srv_parms
index|[
literal|16
index|]
decl_stmt|;
name|__u8
name|cls_srv_parms
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
name|S_FW_FCOE_SPARAMS_CMD_PORTID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_SPARAMS_CMD_PORTID
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_SPARAMS_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_SPARAMS_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_SPARAMS_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_SPARAMS_CMD_PORTID)& M_FW_FCOE_SPARAMS_CMD_PORTID)
end_define

begin_struct
struct|struct
name|fw_fcoe_stats_cmd
block|{
name|__be32
name|op_to_flowid
decl_stmt|;
name|__be32
name|free_to_len16
decl_stmt|;
union|union
name|fw_fcoe_stats
block|{
struct|struct
name|fw_fcoe_stats_ctl
block|{
name|__u8
name|nstats_port
decl_stmt|;
name|__u8
name|port_valid_ix
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
name|fw_fcoe_port_stats
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
name|port_stats
struct|;
struct|struct
name|fw_fcoe_fcf_stats
block|{
name|__be32
name|fip_tx_bytes
decl_stmt|;
name|__be32
name|fip_tx_fr
decl_stmt|;
name|__be64
name|fcf_ka
decl_stmt|;
name|__be64
name|mcast_adv_rcvd
decl_stmt|;
name|__be16
name|ucast_adv_rcvd
decl_stmt|;
name|__be16
name|sol_sent
decl_stmt|;
name|__be16
name|vlan_req
decl_stmt|;
name|__be16
name|vlan_rpl
decl_stmt|;
name|__be16
name|clr_vlink
decl_stmt|;
name|__be16
name|link_down
decl_stmt|;
name|__be16
name|link_up
decl_stmt|;
name|__be16
name|logo
decl_stmt|;
name|__be16
name|flogi_req
decl_stmt|;
name|__be16
name|flogi_rpl
decl_stmt|;
name|__be16
name|fdisc_req
decl_stmt|;
name|__be16
name|fdisc_rpl
decl_stmt|;
name|__be16
name|fka_prd_chg
decl_stmt|;
name|__be16
name|fc_map_chg
decl_stmt|;
name|__be16
name|vfid_chg
decl_stmt|;
name|__u8
name|no_fka_req
decl_stmt|;
name|__u8
name|no_vnp
decl_stmt|;
block|}
name|fcf_stats
struct|;
struct|struct
name|fw_fcoe_pcb_stats
block|{
name|__be64
name|tx_bytes
decl_stmt|;
name|__be64
name|tx_frames
decl_stmt|;
name|__be64
name|rx_bytes
decl_stmt|;
name|__be64
name|rx_frames
decl_stmt|;
name|__be32
name|vnp_ka
decl_stmt|;
name|__be32
name|unsol_els_rcvd
decl_stmt|;
name|__be64
name|unsol_cmd_rcvd
decl_stmt|;
name|__be16
name|implicit_logo
decl_stmt|;
name|__be16
name|flogi_inv_sparm
decl_stmt|;
name|__be16
name|fdisc_inv_sparm
decl_stmt|;
name|__be16
name|flogi_rjt
decl_stmt|;
name|__be16
name|fdisc_rjt
decl_stmt|;
name|__be16
name|no_ssn
decl_stmt|;
name|__be16
name|mac_flt_fail
decl_stmt|;
name|__be16
name|inv_fr_rcvd
decl_stmt|;
block|}
name|pcb_stats
struct|;
struct|struct
name|fw_fcoe_scb_stats
block|{
name|__be64
name|tx_bytes
decl_stmt|;
name|__be64
name|tx_frames
decl_stmt|;
name|__be64
name|rx_bytes
decl_stmt|;
name|__be64
name|rx_frames
decl_stmt|;
name|__be32
name|host_abrt_req
decl_stmt|;
name|__be32
name|adap_auto_abrt
decl_stmt|;
name|__be32
name|adap_abrt_rsp
decl_stmt|;
name|__be32
name|host_ios_req
decl_stmt|;
name|__be16
name|ssn_offl_ios
decl_stmt|;
name|__be16
name|ssn_not_rdy_ios
decl_stmt|;
name|__u8
name|rx_data_ddp_err
decl_stmt|;
name|__u8
name|ddp_flt_set_err
decl_stmt|;
name|__be16
name|rx_data_fr_err
decl_stmt|;
name|__u8
name|bad_st_abrt_req
decl_stmt|;
name|__u8
name|no_io_abrt_req
decl_stmt|;
name|__u8
name|abort_tmo
decl_stmt|;
name|__u8
name|abort_tmo_2
decl_stmt|;
name|__be32
name|abort_req
decl_stmt|;
name|__u8
name|no_ppod_res_tmo
decl_stmt|;
name|__u8
name|bp_tmo
decl_stmt|;
name|__u8
name|adap_auto_cls
decl_stmt|;
name|__u8
name|no_io_cls_req
decl_stmt|;
name|__be32
name|host_cls_req
decl_stmt|;
name|__be64
name|unsol_cmd_rcvd
decl_stmt|;
name|__be32
name|plogi_req_rcvd
decl_stmt|;
name|__be32
name|prli_req_rcvd
decl_stmt|;
name|__be16
name|logo_req_rcvd
decl_stmt|;
name|__be16
name|prlo_req_rcvd
decl_stmt|;
name|__be16
name|plogi_rjt_rcvd
decl_stmt|;
name|__be16
name|prli_rjt_rcvd
decl_stmt|;
name|__be32
name|adisc_req_rcvd
decl_stmt|;
name|__be32
name|rscn_rcvd
decl_stmt|;
name|__be32
name|rrq_req_rcvd
decl_stmt|;
name|__be32
name|unsol_els_rcvd
decl_stmt|;
name|__u8
name|adisc_rjt_rcvd
decl_stmt|;
name|__u8
name|scr_rjt
decl_stmt|;
name|__u8
name|ct_rjt
decl_stmt|;
name|__u8
name|inval_bls_rcvd
decl_stmt|;
name|__be32
name|ba_rjt_rcvd
decl_stmt|;
block|}
name|scb_stats
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
name|S_FW_FCOE_STATS_CMD_FLOWID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_STATS_CMD_FLOWID
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_STATS_CMD_FLOWID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_STATS_CMD_FLOWID)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_STATS_CMD_FLOWID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_STATS_CMD_FLOWID)& M_FW_FCOE_STATS_CMD_FLOWID)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_STATS_CMD_FREE
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_STATS_CMD_FREE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_STATS_CMD_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_STATS_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_STATS_CMD_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_STATS_CMD_FREE)& M_FW_FCOE_STATS_CMD_FREE)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_STATS_CMD_FREE
value|V_FW_FCOE_STATS_CMD_FREE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_STATS_CMD_NSTATS
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_STATS_CMD_NSTATS
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_STATS_CMD_NSTATS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_STATS_CMD_NSTATS)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_STATS_CMD_NSTATS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_STATS_CMD_NSTATS)& M_FW_FCOE_STATS_CMD_NSTATS)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_STATS_CMD_PORT
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_STATS_CMD_PORT
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_STATS_CMD_PORT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_STATS_CMD_PORT)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_STATS_CMD_PORT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_STATS_CMD_PORT)& M_FW_FCOE_STATS_CMD_PORT)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_STATS_CMD_PORT_VALID
value|7
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_STATS_CMD_PORT_VALID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_STATS_CMD_PORT_VALID
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_FCOE_STATS_CMD_PORT_VALID)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_STATS_CMD_PORT_VALID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_STATS_CMD_PORT_VALID)& M_FW_FCOE_STATS_CMD_PORT_VALID)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_STATS_CMD_PORT_VALID
value|V_FW_FCOE_STATS_CMD_PORT_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_STATS_CMD_IX
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_STATS_CMD_IX
value|0x3f
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_STATS_CMD_IX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_STATS_CMD_IX)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_STATS_CMD_IX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_STATS_CMD_IX)& M_FW_FCOE_STATS_CMD_IX)
end_define

begin_struct
struct|struct
name|fw_fcoe_fcf_cmd
block|{
name|__be32
name|op_to_fcfi
decl_stmt|;
name|__be32
name|retval_len16
decl_stmt|;
name|__be16
name|priority_pkd
decl_stmt|;
name|__u8
name|mac
index|[
literal|6
index|]
decl_stmt|;
name|__u8
name|name_id
index|[
literal|8
index|]
decl_stmt|;
name|__u8
name|fabric
index|[
literal|8
index|]
decl_stmt|;
name|__be16
name|vf_id
decl_stmt|;
name|__be16
name|max_fcoe_size
decl_stmt|;
name|__u8
name|vlan_id
decl_stmt|;
name|__u8
name|fc_map
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|fka_adv
decl_stmt|;
name|__be32
name|r6
decl_stmt|;
name|__u8
name|r7_hi
decl_stmt|;
name|__u8
name|fpma_to_portid
decl_stmt|;
name|__u8
name|spma_mac
index|[
literal|6
index|]
decl_stmt|;
name|__be64
name|r8
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_FW_FCOE_FCF_CMD_FCFI
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_FCF_CMD_FCFI
value|0xfffff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_FCF_CMD_FCFI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_FCF_CMD_FCFI)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_FCF_CMD_FCFI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_FCF_CMD_FCFI)& M_FW_FCOE_FCF_CMD_FCFI)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_FCF_CMD_PRIORITY
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_FCF_CMD_PRIORITY
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_FCF_CMD_PRIORITY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_FCF_CMD_PRIORITY)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_FCF_CMD_PRIORITY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_FCF_CMD_PRIORITY)& M_FW_FCOE_FCF_CMD_PRIORITY)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_FCF_CMD_FPMA
value|6
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_FCF_CMD_FPMA
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_FCF_CMD_FPMA
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_FCF_CMD_FPMA)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_FCF_CMD_FPMA
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_FCF_CMD_FPMA)& M_FW_FCOE_FCF_CMD_FPMA)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_FCF_CMD_FPMA
value|V_FW_FCOE_FCF_CMD_FPMA(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_FCF_CMD_SPMA
value|5
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_FCF_CMD_SPMA
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_FCF_CMD_SPMA
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_FCF_CMD_SPMA)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_FCF_CMD_SPMA
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_FCF_CMD_SPMA)& M_FW_FCOE_FCF_CMD_SPMA)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_FCF_CMD_SPMA
value|V_FW_FCOE_FCF_CMD_SPMA(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_FCF_CMD_LOGIN
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_FCF_CMD_LOGIN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_FCF_CMD_LOGIN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_FCF_CMD_LOGIN)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_FCF_CMD_LOGIN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_FCF_CMD_LOGIN)& M_FW_FCOE_FCF_CMD_LOGIN)
end_define

begin_define
define|#
directive|define
name|F_FW_FCOE_FCF_CMD_LOGIN
value|V_FW_FCOE_FCF_CMD_LOGIN(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_FCOE_FCF_CMD_PORTID
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_FCOE_FCF_CMD_PORTID
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_FCOE_FCF_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_FCOE_FCF_CMD_PORTID)
end_define

begin_define
define|#
directive|define
name|G_FW_FCOE_FCF_CMD_PORTID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_FCOE_FCF_CMD_PORTID)& M_FW_FCOE_FCF_CMD_PORTID)
end_define

begin_comment
comment|/******************************************************************************  *   E R R O R   a n d   D E B U G   C O M M A N D s  ******************************************************/
end_comment

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

begin_enum
enum|enum
name|fw_dcb_ieee_locations
block|{
name|FW_IEEE_LOC_LOCAL
block|,
name|FW_IEEE_LOC_PEER
block|,
name|FW_IEEE_LOC_OPERATIONAL
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_dcb_ieee_cmd
block|{
name|__be32
name|op_to_location
decl_stmt|;
name|__be32
name|changed_to_len16
decl_stmt|;
union|union
name|fw_dcbx_stats
block|{
struct|struct
name|fw_dcbx_pfc_stats_ieee
block|{
name|__be32
name|pfc_mbc_pkd
decl_stmt|;
name|__be32
name|pfc_willing_to_pfc_en
decl_stmt|;
block|}
name|dcbx_pfc_stats
struct|;
struct|struct
name|fw_dcbx_ets_stats_ieee
block|{
name|__be32
name|cbs_to_ets_max_tc
decl_stmt|;
name|__be32
name|pg_table
decl_stmt|;
name|__u8
name|pg_percent
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
name|dcbx_ets_stats
struct|;
struct|struct
name|fw_dcbx_app_stats_ieee
block|{
name|__be32
name|num_apps_pkd
decl_stmt|;
name|__be32
name|r6
decl_stmt|;
name|__be32
name|app
index|[
literal|4
index|]
decl_stmt|;
block|}
name|dcbx_app_stats
struct|;
struct|struct
name|fw_dcbx_control
block|{
name|__be32
name|multi_peer_invalidated
decl_stmt|;
name|__be32
name|r5_lo
decl_stmt|;
block|}
name|dcbx_control
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
name|S_FW_DCB_IEEE_CMD_PORT
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_PORT
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_PORT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_PORT)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_PORT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_PORT)& M_FW_DCB_IEEE_CMD_PORT)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_FEATURE
value|2
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_FEATURE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_FEATURE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_FEATURE)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_FEATURE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_FEATURE)& M_FW_DCB_IEEE_CMD_FEATURE)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_LOCATION
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_LOCATION
value|0x3
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_LOCATION
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_LOCATION)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_LOCATION
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_LOCATION)& M_FW_DCB_IEEE_CMD_LOCATION)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_CHANGED
value|20
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_CHANGED
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_CHANGED
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_CHANGED)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_CHANGED
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_CHANGED)& M_FW_DCB_IEEE_CMD_CHANGED)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_CHANGED
value|V_FW_DCB_IEEE_CMD_CHANGED(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_RECEIVED
value|19
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_RECEIVED
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_RECEIVED
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_RECEIVED)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_RECEIVED
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_RECEIVED)& M_FW_DCB_IEEE_CMD_RECEIVED)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_RECEIVED
value|V_FW_DCB_IEEE_CMD_RECEIVED(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_APPLY
value|18
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_APPLY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_APPLY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_APPLY)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_APPLY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_APPLY)& M_FW_DCB_IEEE_CMD_APPLY)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_APPLY
value|V_FW_DCB_IEEE_CMD_APPLY(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_DISABLED
value|17
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_DISABLED
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_DISABLED
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_DISABLED)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_DISABLED
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_DISABLED)& M_FW_DCB_IEEE_CMD_DISABLED)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_DISABLED
value|V_FW_DCB_IEEE_CMD_DISABLED(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_MORE
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_MORE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_MORE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_MORE)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_MORE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_MORE)& M_FW_DCB_IEEE_CMD_MORE)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_MORE
value|V_FW_DCB_IEEE_CMD_MORE(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_PFC_MBC
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_PFC_MBC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_PFC_MBC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_PFC_MBC)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_PFC_MBC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_PFC_MBC)& M_FW_DCB_IEEE_CMD_PFC_MBC)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_PFC_MBC
value|V_FW_DCB_IEEE_CMD_PFC_MBC(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_PFC_WILLING
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_PFC_WILLING
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_PFC_WILLING
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_DCB_IEEE_CMD_PFC_WILLING)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_PFC_WILLING
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_PFC_WILLING)& M_FW_DCB_IEEE_CMD_PFC_WILLING)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_PFC_WILLING
value|V_FW_DCB_IEEE_CMD_PFC_WILLING(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_PFC_MAX_TC
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_PFC_MAX_TC
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_PFC_MAX_TC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_PFC_MAX_TC)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_PFC_MAX_TC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_PFC_MAX_TC)& M_FW_DCB_IEEE_CMD_PFC_MAX_TC)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_PFC_EN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_PFC_EN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_PFC_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_PFC_EN)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_PFC_EN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_PFC_EN)& M_FW_DCB_IEEE_CMD_PFC_EN)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_CBS
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_CBS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_CBS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_CBS)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_CBS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_CBS)& M_FW_DCB_IEEE_CMD_CBS)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_CBS
value|V_FW_DCB_IEEE_CMD_CBS(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_ETS_WILLING
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_ETS_WILLING
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_ETS_WILLING
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_DCB_IEEE_CMD_ETS_WILLING)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_ETS_WILLING
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_ETS_WILLING)& M_FW_DCB_IEEE_CMD_ETS_WILLING)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_ETS_WILLING
value|V_FW_DCB_IEEE_CMD_ETS_WILLING(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_ETS_MAX_TC
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_ETS_MAX_TC
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_ETS_MAX_TC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_ETS_MAX_TC)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_ETS_MAX_TC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_ETS_MAX_TC)& M_FW_DCB_IEEE_CMD_ETS_MAX_TC)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_NUM_APPS
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_NUM_APPS
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_NUM_APPS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_NUM_APPS)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_NUM_APPS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_NUM_APPS)& M_FW_DCB_IEEE_CMD_NUM_APPS)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_MULTI_PEER
value|31
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_MULTI_PEER
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_MULTI_PEER
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_MULTI_PEER)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_MULTI_PEER
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_MULTI_PEER)& M_FW_DCB_IEEE_CMD_MULTI_PEER)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_MULTI_PEER
value|V_FW_DCB_IEEE_CMD_MULTI_PEER(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_INVALIDATED
value|30
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_INVALIDATED
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_INVALIDATED
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_DCB_IEEE_CMD_INVALIDATED)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_INVALIDATED
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_INVALIDATED)& M_FW_DCB_IEEE_CMD_INVALIDATED)
end_define

begin_define
define|#
directive|define
name|F_FW_DCB_IEEE_CMD_INVALIDATED
value|V_FW_DCB_IEEE_CMD_INVALIDATED(1U)
end_define

begin_comment
comment|/* Hand-written */
end_comment

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_APP_PROTOCOL
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_APP_PROTOCOL
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_APP_PROTOCOL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_APP_PROTOCOL)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_APP_PROTOCOL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_APP_PROTOCOL)& M_FW_DCB_IEEE_CMD_APP_PROTOCOL)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_APP_SELECT
value|3
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_APP_SELECT
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_APP_SELECT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_APP_SELECT)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_APP_SELECT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_APP_SELECT)& M_FW_DCB_IEEE_CMD_APP_SELECT)
end_define

begin_define
define|#
directive|define
name|S_FW_DCB_IEEE_CMD_APP_PRIORITY
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_DCB_IEEE_CMD_APP_PRIORITY
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_DCB_IEEE_CMD_APP_PRIORITY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DCB_IEEE_CMD_APP_PRIORITY)
end_define

begin_define
define|#
directive|define
name|G_FW_DCB_IEEE_CMD_APP_PRIORITY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DCB_IEEE_CMD_APP_PRIORITY)& M_FW_DCB_IEEE_CMD_APP_PRIORITY)
end_define

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
name|__u8
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
name|__u8
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

begin_define
define|#
directive|define
name|S_FW_ERROR_CMD_FATAL
value|4
end_define

begin_define
define|#
directive|define
name|M_FW_ERROR_CMD_FATAL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ERROR_CMD_FATAL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ERROR_CMD_FATAL)
end_define

begin_define
define|#
directive|define
name|G_FW_ERROR_CMD_FATAL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ERROR_CMD_FATAL)& M_FW_ERROR_CMD_FATAL)
end_define

begin_define
define|#
directive|define
name|F_FW_ERROR_CMD_FATAL
value|V_FW_ERROR_CMD_FATAL(1U)
end_define

begin_define
define|#
directive|define
name|S_FW_ERROR_CMD_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ERROR_CMD_TYPE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_FW_ERROR_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ERROR_CMD_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_ERROR_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ERROR_CMD_TYPE)& M_FW_ERROR_CMD_TYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_ERROR_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_ERROR_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_ERROR_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ERROR_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_ERROR_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ERROR_CMD_PFN)& M_FW_ERROR_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_ERROR_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ERROR_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_ERROR_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ERROR_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_ERROR_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ERROR_CMD_VFN)& M_FW_ERROR_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_ERROR_CMD_PFN
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_ERROR_CMD_PFN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_FW_ERROR_CMD_PFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ERROR_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|G_FW_ERROR_CMD_PFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ERROR_CMD_PFN)& M_FW_ERROR_CMD_PFN)
end_define

begin_define
define|#
directive|define
name|S_FW_ERROR_CMD_VFN
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_ERROR_CMD_VFN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_ERROR_CMD_VFN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ERROR_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|G_FW_ERROR_CMD_VFN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ERROR_CMD_VFN)& M_FW_ERROR_CMD_VFN)
end_define

begin_define
define|#
directive|define
name|S_FW_ERROR_CMD_MV
value|15
end_define

begin_define
define|#
directive|define
name|M_FW_ERROR_CMD_MV
value|0x1
end_define

begin_define
define|#
directive|define
name|V_FW_ERROR_CMD_MV
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_ERROR_CMD_MV)
end_define

begin_define
define|#
directive|define
name|G_FW_ERROR_CMD_MV
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_ERROR_CMD_MV)& M_FW_ERROR_CMD_MV)
end_define

begin_define
define|#
directive|define
name|F_FW_ERROR_CMD_MV
value|V_FW_ERROR_CMD_MV(1U)
end_define

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
name|__u8
name|filename_0_7
index|[
literal|8
index|]
decl_stmt|;
name|__u8
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
name|S_FW_DEBUG_CMD_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_DEBUG_CMD_TYPE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_DEBUG_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DEBUG_CMD_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_DEBUG_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DEBUG_CMD_TYPE)& M_FW_DEBUG_CMD_TYPE)
end_define

begin_enum
enum|enum
name|fw_diag_cmd_type
block|{
name|FW_DIAG_CMD_TYPE_OFLDIAG
init|=
literal|0
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_diag_cmd_ofldiag_op
block|{
name|FW_DIAG_CMD_OFLDIAG_TEST_NONE
init|=
literal|0
block|,
name|FW_DIAG_CMD_OFLDIAG_TEST_START
block|,
name|FW_DIAG_CMD_OFLDIAG_TEST_STOP
block|,
name|FW_DIAG_CMD_OFLDIAG_TEST_STATUS
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|fw_diag_cmd_ofldiag_status
block|{
name|FW_DIAG_CMD_OFLDIAG_STATUS_IDLE
init|=
literal|0
block|,
name|FW_DIAG_CMD_OFLDIAG_STATUS_RUNNING
block|,
name|FW_DIAG_CMD_OFLDIAG_STATUS_FAILED
block|,
name|FW_DIAG_CMD_OFLDIAG_STATUS_PASSED
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|fw_diag_cmd
block|{
name|__be32
name|op_type
decl_stmt|;
name|__be32
name|len16_pkd
decl_stmt|;
union|union
name|fw_diag_test
block|{
struct|struct
name|fw_diag_test_ofldiag
block|{
name|__u8
name|test_op
decl_stmt|;
name|__u8
name|r3
decl_stmt|;
name|__be16
name|test_status
decl_stmt|;
name|__be32
name|duration
decl_stmt|;
block|}
name|ofldiag
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
name|S_FW_DIAG_CMD_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_DIAG_CMD_TYPE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_DIAG_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_DIAG_CMD_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_DIAG_CMD_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_DIAG_CMD_TYPE)& M_FW_DIAG_CMD_TYPE)
end_define

begin_comment
comment|/******************************************************************************  *   P C I E   F W   R E G I S T E R  **************************************/
end_comment

begin_enum
enum|enum
name|pcie_fw_eval
block|{
name|PCIE_FW_EVAL_CRASH
init|=
literal|0
block|,
name|PCIE_FW_EVAL_PREP
init|=
literal|1
block|,
name|PCIE_FW_EVAL_CONF
init|=
literal|2
block|,
name|PCIE_FW_EVAL_INIT
init|=
literal|3
block|,
name|PCIE_FW_EVAL_UNEXPECTEDEVENT
init|=
literal|4
block|,
name|PCIE_FW_EVAL_OVERHEAT
init|=
literal|5
block|,
name|PCIE_FW_EVAL_DEVICESHUTDOWN
init|=
literal|6
block|, }
enum|;
end_enum

begin_comment
comment|/**  *	Register definitions for the PCIE_FW register which the firmware uses  *	to retain status across RESETs.  This register should be considered  *	as a READ-ONLY register for Host Software and only to be used to  *	track firmware initialization/error state, etc.  */
end_comment

begin_define
define|#
directive|define
name|S_PCIE_FW_ERR
value|31
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_ERR
value|0x1
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_ERR)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_ERR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PCIE_FW_ERR)& M_PCIE_FW_ERR)
end_define

begin_define
define|#
directive|define
name|F_PCIE_FW_ERR
value|V_PCIE_FW_ERR(1U)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_INIT
value|30
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_INIT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_INIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_INIT)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_INIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PCIE_FW_INIT)& M_PCIE_FW_INIT)
end_define

begin_define
define|#
directive|define
name|F_PCIE_FW_INIT
value|V_PCIE_FW_INIT(1U)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_HALT
value|29
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_HALT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_HALT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_HALT)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_HALT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PCIE_FW_HALT)& M_PCIE_FW_HALT)
end_define

begin_define
define|#
directive|define
name|F_PCIE_FW_HALT
value|V_PCIE_FW_HALT(1U)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_EVAL
value|24
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_EVAL
value|0x7
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_EVAL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_EVAL)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_EVAL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PCIE_FW_EVAL)& M_PCIE_FW_EVAL)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_STAGE
value|21
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_STAGE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_STAGE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_STAGE)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_STAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PCIE_FW_STAGE)& M_PCIE_FW_STAGE)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_ASYNCNOT_VLD
value|20
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_ASYNCNOT_VLD
value|0x1
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_ASYNCNOT_VLD
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_PCIE_FW_ASYNCNOT_VLD)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_ASYNCNOT_VLD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_PCIE_FW_ASYNCNOT_VLD)& M_PCIE_FW_ASYNCNOT_VLD)
end_define

begin_define
define|#
directive|define
name|F_PCIE_FW_ASYNCNOT_VLD
value|V_PCIE_FW_ASYNCNOT_VLD(1U)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_ASYNCNOTINT
value|19
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_ASYNCNOTINT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_ASYNCNOTINT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_PCIE_FW_ASYNCNOTINT)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_ASYNCNOTINT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_PCIE_FW_ASYNCNOTINT)& M_PCIE_FW_ASYNCNOTINT)
end_define

begin_define
define|#
directive|define
name|F_PCIE_FW_ASYNCNOTINT
value|V_PCIE_FW_ASYNCNOTINT(1U)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_ASYNCNOT
value|16
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_ASYNCNOT
value|0x7
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_ASYNCNOT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_ASYNCNOT)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_ASYNCNOT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_PCIE_FW_ASYNCNOT)& M_PCIE_FW_ASYNCNOT)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_MASTER_VLD
value|15
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_MASTER_VLD
value|0x1
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_MASTER_VLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_MASTER_VLD)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_MASTER_VLD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_PCIE_FW_MASTER_VLD)& M_PCIE_FW_MASTER_VLD)
end_define

begin_define
define|#
directive|define
name|F_PCIE_FW_MASTER_VLD
value|V_PCIE_FW_MASTER_VLD(1U)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_MASTER
value|12
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_MASTER
value|0x7
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_MASTER
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_MASTER)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_MASTER
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PCIE_FW_MASTER)& M_PCIE_FW_MASTER)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_RESET_VLD
value|11
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_RESET_VLD
value|0x1
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_RESET_VLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_RESET_VLD)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_RESET_VLD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_PCIE_FW_RESET_VLD)& M_PCIE_FW_RESET_VLD)
end_define

begin_define
define|#
directive|define
name|F_PCIE_FW_RESET_VLD
value|V_PCIE_FW_RESET_VLD(1U)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_RESET
value|8
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_RESET
value|0x7
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_RESET
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_RESET)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_RESET
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_PCIE_FW_RESET)& M_PCIE_FW_RESET)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_REGISTERED
value|0
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_REGISTERED
value|0xff
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_REGISTERED
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_REGISTERED)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_REGISTERED
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_PCIE_FW_REGISTERED)& M_PCIE_FW_REGISTERED)
end_define

begin_comment
comment|/******************************************************************************  *   P C I E   F W   P F 0   R E G I S T E R  **********************************************/
end_comment

begin_comment
comment|/*  *	this register is available as 32-bit of persistent storage (across  *	PL_RST based chip-reset) for boot drivers (i.e. firmware and driver  *	will not write it)  */
end_comment

begin_comment
comment|/******************************************************************************  *   P C I E   F W   P F 7   R E G I S T E R  **********************************************/
end_comment

begin_comment
comment|/*  * PF7 stores the Firmware Device Log parameters which allows Host Drivers to  * access the "devlog" which needing to contact firmware.  The encoding is  * mostly the same as that returned by the DEVLOG command except for the size  * which is encoded as the number of entries in multiples-1 of 128 here rather  * than the memory size as is done in the DEVLOG command.  Thus, 0 means 128  * and 15 means 2048.  This of course in turn constrains the allowed values  * for the devlog size ...  */
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
name|S_PCIE_FW_PF_DEVLOG_NENTRIES128
value|28
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_PF_DEVLOG_NENTRIES128
value|0xf
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_PF_DEVLOG_NENTRIES128
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_PCIE_FW_PF_DEVLOG_NENTRIES128)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_PF_DEVLOG_NENTRIES128
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_PCIE_FW_PF_DEVLOG_NENTRIES128)& \ 	 M_PCIE_FW_PF_DEVLOG_NENTRIES128)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_PF_DEVLOG_ADDR16
value|4
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_PF_DEVLOG_ADDR16
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_PF_DEVLOG_ADDR16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_PF_DEVLOG_ADDR16)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_PF_DEVLOG_ADDR16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_PCIE_FW_PF_DEVLOG_ADDR16)& M_PCIE_FW_PF_DEVLOG_ADDR16)
end_define

begin_define
define|#
directive|define
name|S_PCIE_FW_PF_DEVLOG_MEMTYPE
value|0
end_define

begin_define
define|#
directive|define
name|M_PCIE_FW_PF_DEVLOG_MEMTYPE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_PCIE_FW_PF_DEVLOG_MEMTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PCIE_FW_PF_DEVLOG_MEMTYPE)
end_define

begin_define
define|#
directive|define
name|G_PCIE_FW_PF_DEVLOG_MEMTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_PCIE_FW_PF_DEVLOG_MEMTYPE)& M_PCIE_FW_PF_DEVLOG_MEMTYPE)
end_define

begin_comment
comment|/******************************************************************************  *   B I N A R Y   H E A D E R   F O R M A T  **********************************************/
end_comment

begin_comment
comment|/*  *	firmware binary header format  */
end_comment

begin_struct
struct|struct
name|fw_hdr
block|{
name|__u8
name|ver
decl_stmt|;
name|__u8
name|chip
decl_stmt|;
comment|/* terminator chip family */
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
comment|/* tcp processor microcode version */
name|__u8
name|intfver_nic
decl_stmt|;
name|__u8
name|intfver_vnic
decl_stmt|;
name|__u8
name|intfver_ofld
decl_stmt|;
name|__u8
name|intfver_ri
decl_stmt|;
name|__u8
name|intfver_iscsipdu
decl_stmt|;
name|__u8
name|intfver_iscsi
decl_stmt|;
name|__u8
name|intfver_fcoepdu
decl_stmt|;
name|__u8
name|intfver_fcoe
decl_stmt|;
name|__u32
name|reserved2
decl_stmt|;
name|__u32
name|reserved3
decl_stmt|;
name|__be32
name|magic
decl_stmt|;
comment|/* runtime or bootstrap fw */
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
name|S_FW_HDR_FW_VER_MAJOR
value|24
end_define

begin_define
define|#
directive|define
name|M_FW_HDR_FW_VER_MAJOR
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_HDR_FW_VER_MAJOR
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_HDR_FW_VER_MAJOR)
end_define

begin_define
define|#
directive|define
name|G_FW_HDR_FW_VER_MAJOR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HDR_FW_VER_MAJOR)& M_FW_HDR_FW_VER_MAJOR)
end_define

begin_define
define|#
directive|define
name|S_FW_HDR_FW_VER_MINOR
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_HDR_FW_VER_MINOR
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_HDR_FW_VER_MINOR
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_HDR_FW_VER_MINOR)
end_define

begin_define
define|#
directive|define
name|G_FW_HDR_FW_VER_MINOR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HDR_FW_VER_MINOR)& M_FW_HDR_FW_VER_MINOR)
end_define

begin_define
define|#
directive|define
name|S_FW_HDR_FW_VER_MICRO
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_HDR_FW_VER_MICRO
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_HDR_FW_VER_MICRO
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_HDR_FW_VER_MICRO)
end_define

begin_define
define|#
directive|define
name|G_FW_HDR_FW_VER_MICRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HDR_FW_VER_MICRO)& M_FW_HDR_FW_VER_MICRO)
end_define

begin_define
define|#
directive|define
name|S_FW_HDR_FW_VER_BUILD
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_HDR_FW_VER_BUILD
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FW_HDR_FW_VER_BUILD
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_FW_HDR_FW_VER_BUILD)
end_define

begin_define
define|#
directive|define
name|G_FW_HDR_FW_VER_BUILD
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_HDR_FW_VER_BUILD)& M_FW_HDR_FW_VER_BUILD)
end_define

begin_enum
enum|enum
block|{
name|T4FW_VERSION_MAJOR
init|=
literal|0x01
block|,
name|T4FW_VERSION_MINOR
init|=
literal|0x10
block|,
name|T4FW_VERSION_MICRO
init|=
literal|0x2d
block|,
name|T4FW_VERSION_BUILD
init|=
literal|0x00
block|,
name|T5FW_VERSION_MAJOR
init|=
literal|0x01
block|,
name|T5FW_VERSION_MINOR
init|=
literal|0x10
block|,
name|T5FW_VERSION_MICRO
init|=
literal|0x2d
block|,
name|T5FW_VERSION_BUILD
init|=
literal|0x00
block|,
name|T6FW_VERSION_MAJOR
init|=
literal|0x01
block|,
name|T6FW_VERSION_MINOR
init|=
literal|0x10
block|,
name|T6FW_VERSION_MICRO
init|=
literal|0x2d
block|,
name|T6FW_VERSION_BUILD
init|=
literal|0x00
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* T4 	 */
name|T4FW_HDR_INTFVER_NIC
init|=
literal|0x00
block|,
name|T4FW_HDR_INTFVER_VNIC
init|=
literal|0x00
block|,
name|T4FW_HDR_INTFVER_OFLD
init|=
literal|0x00
block|,
name|T4FW_HDR_INTFVER_RI
init|=
literal|0x00
block|,
name|T4FW_HDR_INTFVER_ISCSIPDU
init|=
literal|0x00
block|,
name|T4FW_HDR_INTFVER_ISCSI
init|=
literal|0x00
block|,
name|T4FW_HDR_INTFVER_FCOEPDU
init|=
literal|0x00
block|,
name|T4FW_HDR_INTFVER_FCOE
init|=
literal|0x00
block|,
comment|/* T5 	 */
name|T5FW_HDR_INTFVER_NIC
init|=
literal|0x00
block|,
name|T5FW_HDR_INTFVER_VNIC
init|=
literal|0x00
block|,
name|T5FW_HDR_INTFVER_OFLD
init|=
literal|0x00
block|,
name|T5FW_HDR_INTFVER_RI
init|=
literal|0x00
block|,
name|T5FW_HDR_INTFVER_ISCSIPDU
init|=
literal|0x00
block|,
name|T5FW_HDR_INTFVER_ISCSI
init|=
literal|0x00
block|,
name|T5FW_HDR_INTFVER_FCOEPDU
init|=
literal|0x00
block|,
name|T5FW_HDR_INTFVER_FCOE
init|=
literal|0x00
block|,
comment|/* T6 	 */
name|T6FW_HDR_INTFVER_NIC
init|=
literal|0x00
block|,
name|T6FW_HDR_INTFVER_VNIC
init|=
literal|0x00
block|,
name|T6FW_HDR_INTFVER_OFLD
init|=
literal|0x00
block|,
name|T6FW_HDR_INTFVER_RI
init|=
literal|0x00
block|,
name|T6FW_HDR_INTFVER_ISCSIPDU
init|=
literal|0x00
block|,
name|T6FW_HDR_INTFVER_ISCSI
init|=
literal|0x00
block|,
name|T6FW_HDR_INTFVER_FCOEPDU
init|=
literal|0x00
block|,
name|T6FW_HDR_INTFVER_FCOE
init|=
literal|0x00
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|FW_HDR_MAGIC_RUNTIME
init|=
literal|0x00000000
block|,
name|FW_HDR_MAGIC_BOOTSTRAP
init|=
literal|0x626f6f74
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
comment|/*  *	External PHY firmware binary header format  */
end_comment

begin_struct
struct|struct
name|fw_ephy_hdr
block|{
name|__u8
name|ver
decl_stmt|;
name|__u8
name|reserved
decl_stmt|;
name|__be16
name|len512
decl_stmt|;
comment|/* bin length in units of 512-bytes */
name|__be32
name|magic
decl_stmt|;
name|__be16
name|vendor_id
decl_stmt|;
name|__be16
name|device_id
decl_stmt|;
name|__be32
name|version
decl_stmt|;
name|__be32
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|FW_EPHY_HDR_MAGIC
init|=
literal|0x65706879
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _T4FW_INTERFACE_H_ */
end_comment

end_unit


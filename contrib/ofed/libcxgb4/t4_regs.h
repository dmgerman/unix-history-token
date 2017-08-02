begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is part of the Chelsio T4 Ethernet driver for Linux.  *  * Copyright (c) 2003-2014 Chelsio Communications, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|__T4_REGS_H
end_define

begin_define
define|#
directive|define
name|MYPF_BASE
value|0x1b000
end_define

begin_define
define|#
directive|define
name|MYPF_REG
parameter_list|(
name|reg_addr
parameter_list|)
value|(MYPF_BASE + (reg_addr))
end_define

begin_define
define|#
directive|define
name|PF0_BASE
value|0x1e000
end_define

begin_define
define|#
directive|define
name|PF0_REG
parameter_list|(
name|reg_addr
parameter_list|)
value|(PF0_BASE + (reg_addr))
end_define

begin_define
define|#
directive|define
name|PF_STRIDE
value|0x400
end_define

begin_define
define|#
directive|define
name|PF_BASE
parameter_list|(
name|idx
parameter_list|)
value|(PF0_BASE + (idx) * PF_STRIDE)
end_define

begin_define
define|#
directive|define
name|PF_REG
parameter_list|(
name|idx
parameter_list|,
name|reg
parameter_list|)
value|(PF_BASE(idx) + (reg))
end_define

begin_define
define|#
directive|define
name|MYPORT_BASE
value|0x1c000
end_define

begin_define
define|#
directive|define
name|MYPORT_REG
parameter_list|(
name|reg_addr
parameter_list|)
value|(MYPORT_BASE + (reg_addr))
end_define

begin_define
define|#
directive|define
name|PORT0_BASE
value|0x20000
end_define

begin_define
define|#
directive|define
name|PORT0_REG
parameter_list|(
name|reg_addr
parameter_list|)
value|(PORT0_BASE + (reg_addr))
end_define

begin_define
define|#
directive|define
name|PORT_STRIDE
value|0x2000
end_define

begin_define
define|#
directive|define
name|PORT_BASE
parameter_list|(
name|idx
parameter_list|)
value|(PORT0_BASE + (idx) * PORT_STRIDE)
end_define

begin_define
define|#
directive|define
name|PORT_REG
parameter_list|(
name|idx
parameter_list|,
name|reg
parameter_list|)
value|(PORT_BASE(idx) + (reg))
end_define

begin_define
define|#
directive|define
name|EDC_STRIDE
value|(EDC_1_BASE_ADDR - EDC_0_BASE_ADDR)
end_define

begin_define
define|#
directive|define
name|EDC_REG
parameter_list|(
name|reg
parameter_list|,
name|idx
parameter_list|)
value|(reg + EDC_STRIDE * idx)
end_define

begin_define
define|#
directive|define
name|PCIE_MEM_ACCESS_REG
parameter_list|(
name|reg_addr
parameter_list|,
name|idx
parameter_list|)
value|((reg_addr) + (idx) * 8)
end_define

begin_define
define|#
directive|define
name|PCIE_MAILBOX_REG
parameter_list|(
name|reg_addr
parameter_list|,
name|idx
parameter_list|)
value|((reg_addr) + (idx) * 8)
end_define

begin_define
define|#
directive|define
name|MC_BIST_STATUS_REG
parameter_list|(
name|reg_addr
parameter_list|,
name|idx
parameter_list|)
value|((reg_addr) + (idx) * 4)
end_define

begin_define
define|#
directive|define
name|EDC_BIST_STATUS_REG
parameter_list|(
name|reg_addr
parameter_list|,
name|idx
parameter_list|)
value|((reg_addr) + (idx) * 4)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_REG
parameter_list|(
name|reg_addr
parameter_list|,
name|idx
parameter_list|)
value|((reg_addr) + (idx) * 4)
end_define

begin_define
define|#
directive|define
name|SGE_PF_KDOORBELL_A
value|0x0
end_define

begin_define
define|#
directive|define
name|QID_S
value|15
end_define

begin_define
define|#
directive|define
name|QID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< QID_S)
end_define

begin_define
define|#
directive|define
name|DBPRIO_S
value|14
end_define

begin_define
define|#
directive|define
name|DBPRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DBPRIO_S)
end_define

begin_define
define|#
directive|define
name|DBPRIO_F
value|DBPRIO_V(1U)
end_define

begin_define
define|#
directive|define
name|PIDX_S
value|0
end_define

begin_define
define|#
directive|define
name|PIDX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PIDX_S)
end_define

begin_define
define|#
directive|define
name|SGE_VF_KDOORBELL_A
value|0x0
end_define

begin_define
define|#
directive|define
name|DBTYPE_S
value|13
end_define

begin_define
define|#
directive|define
name|DBTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DBTYPE_S)
end_define

begin_define
define|#
directive|define
name|DBTYPE_F
value|DBTYPE_V(1U)
end_define

begin_define
define|#
directive|define
name|PIDX_T5_S
value|0
end_define

begin_define
define|#
directive|define
name|PIDX_T5_M
value|0x1fffU
end_define

begin_define
define|#
directive|define
name|PIDX_T5_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PIDX_T5_S)
end_define

begin_define
define|#
directive|define
name|PIDX_T5_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PIDX_T5_S)& PIDX_T5_M)
end_define

begin_define
define|#
directive|define
name|SGE_PF_GTS_A
value|0x4
end_define

begin_define
define|#
directive|define
name|INGRESSQID_S
value|16
end_define

begin_define
define|#
directive|define
name|INGRESSQID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< INGRESSQID_S)
end_define

begin_define
define|#
directive|define
name|TIMERREG_S
value|13
end_define

begin_define
define|#
directive|define
name|TIMERREG_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIMERREG_S)
end_define

begin_define
define|#
directive|define
name|SEINTARM_S
value|12
end_define

begin_define
define|#
directive|define
name|SEINTARM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SEINTARM_S)
end_define

begin_define
define|#
directive|define
name|CIDXINC_S
value|0
end_define

begin_define
define|#
directive|define
name|CIDXINC_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|CIDXINC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CIDXINC_S)
end_define

begin_define
define|#
directive|define
name|SGE_CONTROL_A
value|0x1008
end_define

begin_define
define|#
directive|define
name|SGE_CONTROL2_A
value|0x1124
end_define

begin_define
define|#
directive|define
name|RXPKTCPLMODE_S
value|18
end_define

begin_define
define|#
directive|define
name|RXPKTCPLMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RXPKTCPLMODE_S)
end_define

begin_define
define|#
directive|define
name|RXPKTCPLMODE_F
value|RXPKTCPLMODE_V(1U)
end_define

begin_define
define|#
directive|define
name|EGRSTATUSPAGESIZE_S
value|17
end_define

begin_define
define|#
directive|define
name|EGRSTATUSPAGESIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EGRSTATUSPAGESIZE_S)
end_define

begin_define
define|#
directive|define
name|EGRSTATUSPAGESIZE_F
value|EGRSTATUSPAGESIZE_V(1U)
end_define

begin_define
define|#
directive|define
name|PKTSHIFT_S
value|10
end_define

begin_define
define|#
directive|define
name|PKTSHIFT_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|PKTSHIFT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PKTSHIFT_S)
end_define

begin_define
define|#
directive|define
name|PKTSHIFT_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PKTSHIFT_S)& PKTSHIFT_M)
end_define

begin_define
define|#
directive|define
name|INGPCIEBOUNDARY_S
value|7
end_define

begin_define
define|#
directive|define
name|INGPCIEBOUNDARY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< INGPCIEBOUNDARY_S)
end_define

begin_define
define|#
directive|define
name|INGPADBOUNDARY_S
value|4
end_define

begin_define
define|#
directive|define
name|INGPADBOUNDARY_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|INGPADBOUNDARY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< INGPADBOUNDARY_S)
end_define

begin_define
define|#
directive|define
name|INGPADBOUNDARY_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> INGPADBOUNDARY_S)& INGPADBOUNDARY_M)
end_define

begin_define
define|#
directive|define
name|EGRPCIEBOUNDARY_S
value|1
end_define

begin_define
define|#
directive|define
name|EGRPCIEBOUNDARY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EGRPCIEBOUNDARY_S)
end_define

begin_define
define|#
directive|define
name|INGPACKBOUNDARY_S
value|16
end_define

begin_define
define|#
directive|define
name|INGPACKBOUNDARY_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|INGPACKBOUNDARY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< INGPACKBOUNDARY_S)
end_define

begin_define
define|#
directive|define
name|INGPACKBOUNDARY_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> INGPACKBOUNDARY_S) \& INGPACKBOUNDARY_M)
end_define

begin_define
define|#
directive|define
name|VFIFO_ENABLE_S
value|10
end_define

begin_define
define|#
directive|define
name|VFIFO_ENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFIFO_ENABLE_S)
end_define

begin_define
define|#
directive|define
name|VFIFO_ENABLE_F
value|VFIFO_ENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|SGE_DBVFIFO_BADDR_A
value|0x1138
end_define

begin_define
define|#
directive|define
name|DBVFIFO_SIZE_S
value|6
end_define

begin_define
define|#
directive|define
name|DBVFIFO_SIZE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|DBVFIFO_SIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> DBVFIFO_SIZE_S)& DBVFIFO_SIZE_M)
end_define

begin_define
define|#
directive|define
name|T6_DBVFIFO_SIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|T6_DBVFIFO_SIZE_M
value|0x1fffU
end_define

begin_define
define|#
directive|define
name|T6_DBVFIFO_SIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T6_DBVFIFO_SIZE_S)& T6_DBVFIFO_SIZE_M)
end_define

begin_define
define|#
directive|define
name|GLOBALENABLE_S
value|0
end_define

begin_define
define|#
directive|define
name|GLOBALENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< GLOBALENABLE_S)
end_define

begin_define
define|#
directive|define
name|GLOBALENABLE_F
value|GLOBALENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|SGE_HOST_PAGE_SIZE_A
value|0x100c
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF7_S
value|28
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF7_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF7_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HOSTPAGESIZEPF7_S)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF7_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HOSTPAGESIZEPF7_S)& HOSTPAGESIZEPF7_M)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF6_S
value|24
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF6_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF6_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HOSTPAGESIZEPF6_S)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF6_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HOSTPAGESIZEPF6_S)& HOSTPAGESIZEPF6_M)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF5_S
value|20
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF5_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF5_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HOSTPAGESIZEPF5_S)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF5_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HOSTPAGESIZEPF5_S)& HOSTPAGESIZEPF5_M)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF4_S
value|16
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF4_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF4_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HOSTPAGESIZEPF4_S)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF4_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HOSTPAGESIZEPF4_S)& HOSTPAGESIZEPF4_M)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF3_S
value|12
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF3_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HOSTPAGESIZEPF3_S)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF3_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HOSTPAGESIZEPF3_S)& HOSTPAGESIZEPF3_M)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF2_S
value|8
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF2_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HOSTPAGESIZEPF2_S)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF2_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HOSTPAGESIZEPF2_S)& HOSTPAGESIZEPF2_M)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF1_S
value|4
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF1_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HOSTPAGESIZEPF1_S)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HOSTPAGESIZEPF1_S)& HOSTPAGESIZEPF1_M)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF0_S
value|0
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF0_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HOSTPAGESIZEPF0_S)
end_define

begin_define
define|#
directive|define
name|HOSTPAGESIZEPF0_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HOSTPAGESIZEPF0_S)& HOSTPAGESIZEPF0_M)
end_define

begin_define
define|#
directive|define
name|SGE_EGRESS_QUEUES_PER_PAGE_PF_A
value|0x1010
end_define

begin_define
define|#
directive|define
name|SGE_EGRESS_QUEUES_PER_PAGE_VF_A
value|0x1014
end_define

begin_define
define|#
directive|define
name|QUEUESPERPAGEPF1_S
value|4
end_define

begin_define
define|#
directive|define
name|QUEUESPERPAGEPF0_S
value|0
end_define

begin_define
define|#
directive|define
name|QUEUESPERPAGEPF0_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|QUEUESPERPAGEPF0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< QUEUESPERPAGEPF0_S)
end_define

begin_define
define|#
directive|define
name|QUEUESPERPAGEPF0_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> QUEUESPERPAGEPF0_S)& QUEUESPERPAGEPF0_M)
end_define

begin_define
define|#
directive|define
name|SGE_INT_CAUSE1_A
value|0x1024
end_define

begin_define
define|#
directive|define
name|SGE_INT_CAUSE2_A
value|0x1030
end_define

begin_define
define|#
directive|define
name|SGE_INT_CAUSE3_A
value|0x103c
end_define

begin_define
define|#
directive|define
name|ERR_FLM_DBP_S
value|31
end_define

begin_define
define|#
directive|define
name|ERR_FLM_DBP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_FLM_DBP_S)
end_define

begin_define
define|#
directive|define
name|ERR_FLM_DBP_F
value|ERR_FLM_DBP_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_FLM_IDMA1_S
value|30
end_define

begin_define
define|#
directive|define
name|ERR_FLM_IDMA1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_FLM_IDMA1_S)
end_define

begin_define
define|#
directive|define
name|ERR_FLM_IDMA1_F
value|ERR_FLM_IDMA1_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_FLM_IDMA0_S
value|29
end_define

begin_define
define|#
directive|define
name|ERR_FLM_IDMA0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_FLM_IDMA0_S)
end_define

begin_define
define|#
directive|define
name|ERR_FLM_IDMA0_F
value|ERR_FLM_IDMA0_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_FLM_HINT_S
value|28
end_define

begin_define
define|#
directive|define
name|ERR_FLM_HINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_FLM_HINT_S)
end_define

begin_define
define|#
directive|define
name|ERR_FLM_HINT_F
value|ERR_FLM_HINT_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR3_S
value|27
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_PCIE_ERROR3_S)
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR3_F
value|ERR_PCIE_ERROR3_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR2_S
value|26
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_PCIE_ERROR2_S)
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR2_F
value|ERR_PCIE_ERROR2_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR1_S
value|25
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_PCIE_ERROR1_S)
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR1_F
value|ERR_PCIE_ERROR1_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR0_S
value|24
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_PCIE_ERROR0_S)
end_define

begin_define
define|#
directive|define
name|ERR_PCIE_ERROR0_F
value|ERR_PCIE_ERROR0_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_CPL_EXCEED_IQE_SIZE_S
value|22
end_define

begin_define
define|#
directive|define
name|ERR_CPL_EXCEED_IQE_SIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_CPL_EXCEED_IQE_SIZE_S)
end_define

begin_define
define|#
directive|define
name|ERR_CPL_EXCEED_IQE_SIZE_F
value|ERR_CPL_EXCEED_IQE_SIZE_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_INVALID_CIDX_INC_S
value|21
end_define

begin_define
define|#
directive|define
name|ERR_INVALID_CIDX_INC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_INVALID_CIDX_INC_S)
end_define

begin_define
define|#
directive|define
name|ERR_INVALID_CIDX_INC_F
value|ERR_INVALID_CIDX_INC_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_CPL_OPCODE_0_S
value|19
end_define

begin_define
define|#
directive|define
name|ERR_CPL_OPCODE_0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_CPL_OPCODE_0_S)
end_define

begin_define
define|#
directive|define
name|ERR_CPL_OPCODE_0_F
value|ERR_CPL_OPCODE_0_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_DROPPED_DB_S
value|18
end_define

begin_define
define|#
directive|define
name|ERR_DROPPED_DB_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_DROPPED_DB_S)
end_define

begin_define
define|#
directive|define
name|ERR_DROPPED_DB_F
value|ERR_DROPPED_DB_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_DATA_CPL_ON_HIGH_QID1_S
value|17
end_define

begin_define
define|#
directive|define
name|ERR_DATA_CPL_ON_HIGH_QID1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_DATA_CPL_ON_HIGH_QID1_S)
end_define

begin_define
define|#
directive|define
name|ERR_DATA_CPL_ON_HIGH_QID1_F
value|ERR_DATA_CPL_ON_HIGH_QID1_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_DATA_CPL_ON_HIGH_QID0_S
value|16
end_define

begin_define
define|#
directive|define
name|ERR_DATA_CPL_ON_HIGH_QID0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_DATA_CPL_ON_HIGH_QID0_S)
end_define

begin_define
define|#
directive|define
name|ERR_DATA_CPL_ON_HIGH_QID0_F
value|ERR_DATA_CPL_ON_HIGH_QID0_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX3_S
value|15
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_BAD_DB_PIDX3_S)
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX3_F
value|ERR_BAD_DB_PIDX3_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX2_S
value|14
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_BAD_DB_PIDX2_S)
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX2_F
value|ERR_BAD_DB_PIDX2_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX1_S
value|13
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_BAD_DB_PIDX1_S)
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX1_F
value|ERR_BAD_DB_PIDX1_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX0_S
value|12
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_BAD_DB_PIDX0_S)
end_define

begin_define
define|#
directive|define
name|ERR_BAD_DB_PIDX0_F
value|ERR_BAD_DB_PIDX0_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_ING_CTXT_PRIO_S
value|10
end_define

begin_define
define|#
directive|define
name|ERR_ING_CTXT_PRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_ING_CTXT_PRIO_S)
end_define

begin_define
define|#
directive|define
name|ERR_ING_CTXT_PRIO_F
value|ERR_ING_CTXT_PRIO_V(1U)
end_define

begin_define
define|#
directive|define
name|ERR_EGR_CTXT_PRIO_S
value|9
end_define

begin_define
define|#
directive|define
name|ERR_EGR_CTXT_PRIO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERR_EGR_CTXT_PRIO_S)
end_define

begin_define
define|#
directive|define
name|ERR_EGR_CTXT_PRIO_F
value|ERR_EGR_CTXT_PRIO_V(1U)
end_define

begin_define
define|#
directive|define
name|DBFIFO_HP_INT_S
value|8
end_define

begin_define
define|#
directive|define
name|DBFIFO_HP_INT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DBFIFO_HP_INT_S)
end_define

begin_define
define|#
directive|define
name|DBFIFO_HP_INT_F
value|DBFIFO_HP_INT_V(1U)
end_define

begin_define
define|#
directive|define
name|DBFIFO_LP_INT_S
value|7
end_define

begin_define
define|#
directive|define
name|DBFIFO_LP_INT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DBFIFO_LP_INT_S)
end_define

begin_define
define|#
directive|define
name|DBFIFO_LP_INT_F
value|DBFIFO_LP_INT_V(1U)
end_define

begin_define
define|#
directive|define
name|INGRESS_SIZE_ERR_S
value|5
end_define

begin_define
define|#
directive|define
name|INGRESS_SIZE_ERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< INGRESS_SIZE_ERR_S)
end_define

begin_define
define|#
directive|define
name|INGRESS_SIZE_ERR_F
value|INGRESS_SIZE_ERR_V(1U)
end_define

begin_define
define|#
directive|define
name|EGRESS_SIZE_ERR_S
value|4
end_define

begin_define
define|#
directive|define
name|EGRESS_SIZE_ERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EGRESS_SIZE_ERR_S)
end_define

begin_define
define|#
directive|define
name|EGRESS_SIZE_ERR_F
value|EGRESS_SIZE_ERR_V(1U)
end_define

begin_define
define|#
directive|define
name|SGE_INT_ENABLE3_A
value|0x1040
end_define

begin_define
define|#
directive|define
name|SGE_FL_BUFFER_SIZE0_A
value|0x1044
end_define

begin_define
define|#
directive|define
name|SGE_FL_BUFFER_SIZE1_A
value|0x1048
end_define

begin_define
define|#
directive|define
name|SGE_FL_BUFFER_SIZE2_A
value|0x104c
end_define

begin_define
define|#
directive|define
name|SGE_FL_BUFFER_SIZE3_A
value|0x1050
end_define

begin_define
define|#
directive|define
name|SGE_FL_BUFFER_SIZE4_A
value|0x1054
end_define

begin_define
define|#
directive|define
name|SGE_FL_BUFFER_SIZE5_A
value|0x1058
end_define

begin_define
define|#
directive|define
name|SGE_FL_BUFFER_SIZE6_A
value|0x105c
end_define

begin_define
define|#
directive|define
name|SGE_FL_BUFFER_SIZE7_A
value|0x1060
end_define

begin_define
define|#
directive|define
name|SGE_FL_BUFFER_SIZE8_A
value|0x1064
end_define

begin_define
define|#
directive|define
name|SGE_IMSG_CTXT_BADDR_A
value|0x1088
end_define

begin_define
define|#
directive|define
name|SGE_FLM_CACHE_BADDR_A
value|0x108c
end_define

begin_define
define|#
directive|define
name|SGE_INGRESS_RX_THRESHOLD_A
value|0x10a0
end_define

begin_define
define|#
directive|define
name|THRESHOLD_0_S
value|24
end_define

begin_define
define|#
directive|define
name|THRESHOLD_0_M
value|0x3fU
end_define

begin_define
define|#
directive|define
name|THRESHOLD_0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< THRESHOLD_0_S)
end_define

begin_define
define|#
directive|define
name|THRESHOLD_0_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> THRESHOLD_0_S)& THRESHOLD_0_M)
end_define

begin_define
define|#
directive|define
name|THRESHOLD_1_S
value|16
end_define

begin_define
define|#
directive|define
name|THRESHOLD_1_M
value|0x3fU
end_define

begin_define
define|#
directive|define
name|THRESHOLD_1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< THRESHOLD_1_S)
end_define

begin_define
define|#
directive|define
name|THRESHOLD_1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> THRESHOLD_1_S)& THRESHOLD_1_M)
end_define

begin_define
define|#
directive|define
name|THRESHOLD_2_S
value|8
end_define

begin_define
define|#
directive|define
name|THRESHOLD_2_M
value|0x3fU
end_define

begin_define
define|#
directive|define
name|THRESHOLD_2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< THRESHOLD_2_S)
end_define

begin_define
define|#
directive|define
name|THRESHOLD_2_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> THRESHOLD_2_S)& THRESHOLD_2_M)
end_define

begin_define
define|#
directive|define
name|THRESHOLD_3_S
value|0
end_define

begin_define
define|#
directive|define
name|THRESHOLD_3_M
value|0x3fU
end_define

begin_define
define|#
directive|define
name|THRESHOLD_3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< THRESHOLD_3_S)
end_define

begin_define
define|#
directive|define
name|THRESHOLD_3_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> THRESHOLD_3_S)& THRESHOLD_3_M)
end_define

begin_define
define|#
directive|define
name|SGE_CONM_CTRL_A
value|0x1094
end_define

begin_define
define|#
directive|define
name|EGRTHRESHOLD_S
value|8
end_define

begin_define
define|#
directive|define
name|EGRTHRESHOLD_M
value|0x3fU
end_define

begin_define
define|#
directive|define
name|EGRTHRESHOLD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EGRTHRESHOLD_S)
end_define

begin_define
define|#
directive|define
name|EGRTHRESHOLD_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EGRTHRESHOLD_S)& EGRTHRESHOLD_M)
end_define

begin_define
define|#
directive|define
name|EGRTHRESHOLDPACKING_S
value|14
end_define

begin_define
define|#
directive|define
name|EGRTHRESHOLDPACKING_M
value|0x3fU
end_define

begin_define
define|#
directive|define
name|EGRTHRESHOLDPACKING_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EGRTHRESHOLDPACKING_S)
end_define

begin_define
define|#
directive|define
name|EGRTHRESHOLDPACKING_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> EGRTHRESHOLDPACKING_S)& EGRTHRESHOLDPACKING_M)
end_define

begin_define
define|#
directive|define
name|T6_EGRTHRESHOLDPACKING_S
value|16
end_define

begin_define
define|#
directive|define
name|T6_EGRTHRESHOLDPACKING_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|T6_EGRTHRESHOLDPACKING_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> T6_EGRTHRESHOLDPACKING_S)& T6_EGRTHRESHOLDPACKING_M)
end_define

begin_define
define|#
directive|define
name|SGE_TIMESTAMP_LO_A
value|0x1098
end_define

begin_define
define|#
directive|define
name|SGE_TIMESTAMP_HI_A
value|0x109c
end_define

begin_define
define|#
directive|define
name|TSOP_S
value|28
end_define

begin_define
define|#
directive|define
name|TSOP_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|TSOP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TSOP_S)
end_define

begin_define
define|#
directive|define
name|TSOP_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TSOP_S)& TSOP_M)
end_define

begin_define
define|#
directive|define
name|TSVAL_S
value|0
end_define

begin_define
define|#
directive|define
name|TSVAL_M
value|0xfffffffU
end_define

begin_define
define|#
directive|define
name|TSVAL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TSVAL_S)
end_define

begin_define
define|#
directive|define
name|TSVAL_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TSVAL_S)& TSVAL_M)
end_define

begin_define
define|#
directive|define
name|SGE_DBFIFO_STATUS_A
value|0x10a4
end_define

begin_define
define|#
directive|define
name|SGE_DBVFIFO_SIZE_A
value|0x113c
end_define

begin_define
define|#
directive|define
name|HP_INT_THRESH_S
value|28
end_define

begin_define
define|#
directive|define
name|HP_INT_THRESH_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HP_INT_THRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HP_INT_THRESH_S)
end_define

begin_define
define|#
directive|define
name|LP_INT_THRESH_S
value|12
end_define

begin_define
define|#
directive|define
name|LP_INT_THRESH_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|LP_INT_THRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< LP_INT_THRESH_S)
end_define

begin_define
define|#
directive|define
name|SGE_DOORBELL_CONTROL_A
value|0x10a8
end_define

begin_define
define|#
directive|define
name|NOCOALESCE_S
value|26
end_define

begin_define
define|#
directive|define
name|NOCOALESCE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< NOCOALESCE_S)
end_define

begin_define
define|#
directive|define
name|NOCOALESCE_F
value|NOCOALESCE_V(1U)
end_define

begin_define
define|#
directive|define
name|ENABLE_DROP_S
value|13
end_define

begin_define
define|#
directive|define
name|ENABLE_DROP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ENABLE_DROP_S)
end_define

begin_define
define|#
directive|define
name|ENABLE_DROP_F
value|ENABLE_DROP_V(1U)
end_define

begin_define
define|#
directive|define
name|SGE_TIMER_VALUE_0_AND_1_A
value|0x10b8
end_define

begin_define
define|#
directive|define
name|TIMERVALUE0_S
value|16
end_define

begin_define
define|#
directive|define
name|TIMERVALUE0_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|TIMERVALUE0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIMERVALUE0_S)
end_define

begin_define
define|#
directive|define
name|TIMERVALUE0_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TIMERVALUE0_S)& TIMERVALUE0_M)
end_define

begin_define
define|#
directive|define
name|TIMERVALUE1_S
value|0
end_define

begin_define
define|#
directive|define
name|TIMERVALUE1_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|TIMERVALUE1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIMERVALUE1_S)
end_define

begin_define
define|#
directive|define
name|TIMERVALUE1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TIMERVALUE1_S)& TIMERVALUE1_M)
end_define

begin_define
define|#
directive|define
name|SGE_TIMER_VALUE_2_AND_3_A
value|0x10bc
end_define

begin_define
define|#
directive|define
name|TIMERVALUE2_S
value|16
end_define

begin_define
define|#
directive|define
name|TIMERVALUE2_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|TIMERVALUE2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIMERVALUE2_S)
end_define

begin_define
define|#
directive|define
name|TIMERVALUE2_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TIMERVALUE2_S)& TIMERVALUE2_M)
end_define

begin_define
define|#
directive|define
name|TIMERVALUE3_S
value|0
end_define

begin_define
define|#
directive|define
name|TIMERVALUE3_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|TIMERVALUE3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIMERVALUE3_S)
end_define

begin_define
define|#
directive|define
name|TIMERVALUE3_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TIMERVALUE3_S)& TIMERVALUE3_M)
end_define

begin_define
define|#
directive|define
name|SGE_TIMER_VALUE_4_AND_5_A
value|0x10c0
end_define

begin_define
define|#
directive|define
name|TIMERVALUE4_S
value|16
end_define

begin_define
define|#
directive|define
name|TIMERVALUE4_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|TIMERVALUE4_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIMERVALUE4_S)
end_define

begin_define
define|#
directive|define
name|TIMERVALUE4_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TIMERVALUE4_S)& TIMERVALUE4_M)
end_define

begin_define
define|#
directive|define
name|TIMERVALUE5_S
value|0
end_define

begin_define
define|#
directive|define
name|TIMERVALUE5_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|TIMERVALUE5_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIMERVALUE5_S)
end_define

begin_define
define|#
directive|define
name|TIMERVALUE5_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TIMERVALUE5_S)& TIMERVALUE5_M)
end_define

begin_define
define|#
directive|define
name|SGE_DEBUG_INDEX_A
value|0x10cc
end_define

begin_define
define|#
directive|define
name|SGE_DEBUG_DATA_HIGH_A
value|0x10d0
end_define

begin_define
define|#
directive|define
name|SGE_DEBUG_DATA_LOW_A
value|0x10d4
end_define

begin_define
define|#
directive|define
name|SGE_DEBUG_DATA_LOW_INDEX_2_A
value|0x12c8
end_define

begin_define
define|#
directive|define
name|SGE_DEBUG_DATA_LOW_INDEX_3_A
value|0x12cc
end_define

begin_define
define|#
directive|define
name|SGE_DEBUG_DATA_HIGH_INDEX_10_A
value|0x12a8
end_define

begin_define
define|#
directive|define
name|SGE_INGRESS_QUEUES_PER_PAGE_PF_A
value|0x10f4
end_define

begin_define
define|#
directive|define
name|SGE_INGRESS_QUEUES_PER_PAGE_VF_A
value|0x10f8
end_define

begin_define
define|#
directive|define
name|SGE_ERROR_STATS_A
value|0x1100
end_define

begin_define
define|#
directive|define
name|UNCAPTURED_ERROR_S
value|18
end_define

begin_define
define|#
directive|define
name|UNCAPTURED_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UNCAPTURED_ERROR_S)
end_define

begin_define
define|#
directive|define
name|UNCAPTURED_ERROR_F
value|UNCAPTURED_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|ERROR_QID_VALID_S
value|17
end_define

begin_define
define|#
directive|define
name|ERROR_QID_VALID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ERROR_QID_VALID_S)
end_define

begin_define
define|#
directive|define
name|ERROR_QID_VALID_F
value|ERROR_QID_VALID_V(1U)
end_define

begin_define
define|#
directive|define
name|ERROR_QID_S
value|0
end_define

begin_define
define|#
directive|define
name|ERROR_QID_M
value|0x1ffffU
end_define

begin_define
define|#
directive|define
name|ERROR_QID_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> ERROR_QID_S)& ERROR_QID_M)
end_define

begin_define
define|#
directive|define
name|HP_INT_THRESH_S
value|28
end_define

begin_define
define|#
directive|define
name|HP_INT_THRESH_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HP_INT_THRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HP_INT_THRESH_S)
end_define

begin_define
define|#
directive|define
name|HP_COUNT_S
value|16
end_define

begin_define
define|#
directive|define
name|HP_COUNT_M
value|0x7ffU
end_define

begin_define
define|#
directive|define
name|HP_COUNT_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HP_COUNT_S)& HP_COUNT_M)
end_define

begin_define
define|#
directive|define
name|LP_INT_THRESH_S
value|12
end_define

begin_define
define|#
directive|define
name|LP_INT_THRESH_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|LP_INT_THRESH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< LP_INT_THRESH_S)
end_define

begin_define
define|#
directive|define
name|LP_COUNT_S
value|0
end_define

begin_define
define|#
directive|define
name|LP_COUNT_M
value|0x7ffU
end_define

begin_define
define|#
directive|define
name|LP_COUNT_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> LP_COUNT_S)& LP_COUNT_M)
end_define

begin_define
define|#
directive|define
name|LP_INT_THRESH_T5_S
value|18
end_define

begin_define
define|#
directive|define
name|LP_INT_THRESH_T5_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|LP_INT_THRESH_T5_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< LP_INT_THRESH_T5_S)
end_define

begin_define
define|#
directive|define
name|LP_COUNT_T5_S
value|0
end_define

begin_define
define|#
directive|define
name|LP_COUNT_T5_M
value|0x3ffffU
end_define

begin_define
define|#
directive|define
name|LP_COUNT_T5_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> LP_COUNT_T5_S)& LP_COUNT_T5_M)
end_define

begin_define
define|#
directive|define
name|SGE_DOORBELL_CONTROL_A
value|0x10a8
end_define

begin_define
define|#
directive|define
name|SGE_STAT_TOTAL_A
value|0x10e4
end_define

begin_define
define|#
directive|define
name|SGE_STAT_MATCH_A
value|0x10e8
end_define

begin_define
define|#
directive|define
name|SGE_STAT_CFG_A
value|0x10ec
end_define

begin_define
define|#
directive|define
name|STATMODE_S
value|2
end_define

begin_define
define|#
directive|define
name|STATMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< STATMODE_S)
end_define

begin_define
define|#
directive|define
name|STATSOURCE_T5_S
value|9
end_define

begin_define
define|#
directive|define
name|STATSOURCE_T5_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|STATSOURCE_T5_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< STATSOURCE_T5_S)
end_define

begin_define
define|#
directive|define
name|STATSOURCE_T5_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> STATSOURCE_T5_S)& STATSOURCE_T5_M)
end_define

begin_define
define|#
directive|define
name|T6_STATMODE_S
value|0
end_define

begin_define
define|#
directive|define
name|T6_STATMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T6_STATMODE_S)
end_define

begin_define
define|#
directive|define
name|SGE_DBFIFO_STATUS2_A
value|0x1118
end_define

begin_define
define|#
directive|define
name|HP_INT_THRESH_T5_S
value|10
end_define

begin_define
define|#
directive|define
name|HP_INT_THRESH_T5_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HP_INT_THRESH_T5_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HP_INT_THRESH_T5_S)
end_define

begin_define
define|#
directive|define
name|HP_COUNT_T5_S
value|0
end_define

begin_define
define|#
directive|define
name|HP_COUNT_T5_M
value|0x3ffU
end_define

begin_define
define|#
directive|define
name|HP_COUNT_T5_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HP_COUNT_T5_S)& HP_COUNT_T5_M)
end_define

begin_define
define|#
directive|define
name|ENABLE_DROP_S
value|13
end_define

begin_define
define|#
directive|define
name|ENABLE_DROP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ENABLE_DROP_S)
end_define

begin_define
define|#
directive|define
name|ENABLE_DROP_F
value|ENABLE_DROP_V(1U)
end_define

begin_define
define|#
directive|define
name|DROPPED_DB_S
value|0
end_define

begin_define
define|#
directive|define
name|DROPPED_DB_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DROPPED_DB_S)
end_define

begin_define
define|#
directive|define
name|DROPPED_DB_F
value|DROPPED_DB_V(1U)
end_define

begin_define
define|#
directive|define
name|SGE_CTXT_CMD_A
value|0x11fc
end_define

begin_define
define|#
directive|define
name|SGE_DBQ_CTXT_BADDR_A
value|0x1084
end_define

begin_comment
comment|/* registers for module PCIE */
end_comment

begin_define
define|#
directive|define
name|PCIE_PF_CFG_A
value|0x40
end_define

begin_define
define|#
directive|define
name|AIVEC_S
value|4
end_define

begin_define
define|#
directive|define
name|AIVEC_M
value|0x3ffU
end_define

begin_define
define|#
directive|define
name|AIVEC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< AIVEC_S)
end_define

begin_define
define|#
directive|define
name|PCIE_PF_CLI_A
value|0x44
end_define

begin_define
define|#
directive|define
name|PCIE_INT_CAUSE_A
value|0x3004
end_define

begin_define
define|#
directive|define
name|UNXSPLCPLERR_S
value|29
end_define

begin_define
define|#
directive|define
name|UNXSPLCPLERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UNXSPLCPLERR_S)
end_define

begin_define
define|#
directive|define
name|UNXSPLCPLERR_F
value|UNXSPLCPLERR_V(1U)
end_define

begin_define
define|#
directive|define
name|PCIEPINT_S
value|28
end_define

begin_define
define|#
directive|define
name|PCIEPINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCIEPINT_S)
end_define

begin_define
define|#
directive|define
name|PCIEPINT_F
value|PCIEPINT_V(1U)
end_define

begin_define
define|#
directive|define
name|PCIESINT_S
value|27
end_define

begin_define
define|#
directive|define
name|PCIESINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCIESINT_S)
end_define

begin_define
define|#
directive|define
name|PCIESINT_F
value|PCIESINT_V(1U)
end_define

begin_define
define|#
directive|define
name|RPLPERR_S
value|26
end_define

begin_define
define|#
directive|define
name|RPLPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RPLPERR_S)
end_define

begin_define
define|#
directive|define
name|RPLPERR_F
value|RPLPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|RXWRPERR_S
value|25
end_define

begin_define
define|#
directive|define
name|RXWRPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RXWRPERR_S)
end_define

begin_define
define|#
directive|define
name|RXWRPERR_F
value|RXWRPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|RXCPLPERR_S
value|24
end_define

begin_define
define|#
directive|define
name|RXCPLPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RXCPLPERR_S)
end_define

begin_define
define|#
directive|define
name|RXCPLPERR_F
value|RXCPLPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|PIOTAGPERR_S
value|23
end_define

begin_define
define|#
directive|define
name|PIOTAGPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PIOTAGPERR_S)
end_define

begin_define
define|#
directive|define
name|PIOTAGPERR_F
value|PIOTAGPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MATAGPERR_S
value|22
end_define

begin_define
define|#
directive|define
name|MATAGPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MATAGPERR_S)
end_define

begin_define
define|#
directive|define
name|MATAGPERR_F
value|MATAGPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|INTXCLRPERR_S
value|21
end_define

begin_define
define|#
directive|define
name|INTXCLRPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< INTXCLRPERR_S)
end_define

begin_define
define|#
directive|define
name|INTXCLRPERR_F
value|INTXCLRPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|FIDPERR_S
value|20
end_define

begin_define
define|#
directive|define
name|FIDPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FIDPERR_S)
end_define

begin_define
define|#
directive|define
name|FIDPERR_F
value|FIDPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|CFGSNPPERR_S
value|19
end_define

begin_define
define|#
directive|define
name|CFGSNPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CFGSNPPERR_S)
end_define

begin_define
define|#
directive|define
name|CFGSNPPERR_F
value|CFGSNPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|HRSPPERR_S
value|18
end_define

begin_define
define|#
directive|define
name|HRSPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HRSPPERR_S)
end_define

begin_define
define|#
directive|define
name|HRSPPERR_F
value|HRSPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|HREQPERR_S
value|17
end_define

begin_define
define|#
directive|define
name|HREQPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HREQPERR_S)
end_define

begin_define
define|#
directive|define
name|HREQPERR_F
value|HREQPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|HCNTPERR_S
value|16
end_define

begin_define
define|#
directive|define
name|HCNTPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HCNTPERR_S)
end_define

begin_define
define|#
directive|define
name|HCNTPERR_F
value|HCNTPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|DRSPPERR_S
value|15
end_define

begin_define
define|#
directive|define
name|DRSPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DRSPPERR_S)
end_define

begin_define
define|#
directive|define
name|DRSPPERR_F
value|DRSPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|DREQPERR_S
value|14
end_define

begin_define
define|#
directive|define
name|DREQPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DREQPERR_S)
end_define

begin_define
define|#
directive|define
name|DREQPERR_F
value|DREQPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|DCNTPERR_S
value|13
end_define

begin_define
define|#
directive|define
name|DCNTPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DCNTPERR_S)
end_define

begin_define
define|#
directive|define
name|DCNTPERR_F
value|DCNTPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|CRSPPERR_S
value|12
end_define

begin_define
define|#
directive|define
name|CRSPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CRSPPERR_S)
end_define

begin_define
define|#
directive|define
name|CRSPPERR_F
value|CRSPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|CREQPERR_S
value|11
end_define

begin_define
define|#
directive|define
name|CREQPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CREQPERR_S)
end_define

begin_define
define|#
directive|define
name|CREQPERR_F
value|CREQPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|CCNTPERR_S
value|10
end_define

begin_define
define|#
directive|define
name|CCNTPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CCNTPERR_S)
end_define

begin_define
define|#
directive|define
name|CCNTPERR_F
value|CCNTPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|TARTAGPERR_S
value|9
end_define

begin_define
define|#
directive|define
name|TARTAGPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TARTAGPERR_S)
end_define

begin_define
define|#
directive|define
name|TARTAGPERR_F
value|TARTAGPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|PIOREQPERR_S
value|8
end_define

begin_define
define|#
directive|define
name|PIOREQPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PIOREQPERR_S)
end_define

begin_define
define|#
directive|define
name|PIOREQPERR_F
value|PIOREQPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|PIOCPLPERR_S
value|7
end_define

begin_define
define|#
directive|define
name|PIOCPLPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PIOCPLPERR_S)
end_define

begin_define
define|#
directive|define
name|PIOCPLPERR_F
value|PIOCPLPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSIXDIPERR_S
value|6
end_define

begin_define
define|#
directive|define
name|MSIXDIPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSIXDIPERR_S)
end_define

begin_define
define|#
directive|define
name|MSIXDIPERR_F
value|MSIXDIPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSIXDATAPERR_S
value|5
end_define

begin_define
define|#
directive|define
name|MSIXDATAPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSIXDATAPERR_S)
end_define

begin_define
define|#
directive|define
name|MSIXDATAPERR_F
value|MSIXDATAPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSIXADDRHPERR_S
value|4
end_define

begin_define
define|#
directive|define
name|MSIXADDRHPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSIXADDRHPERR_S)
end_define

begin_define
define|#
directive|define
name|MSIXADDRHPERR_F
value|MSIXADDRHPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSIXADDRLPERR_S
value|3
end_define

begin_define
define|#
directive|define
name|MSIXADDRLPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSIXADDRLPERR_S)
end_define

begin_define
define|#
directive|define
name|MSIXADDRLPERR_F
value|MSIXADDRLPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSIDATAPERR_S
value|2
end_define

begin_define
define|#
directive|define
name|MSIDATAPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSIDATAPERR_S)
end_define

begin_define
define|#
directive|define
name|MSIDATAPERR_F
value|MSIDATAPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSIADDRHPERR_S
value|1
end_define

begin_define
define|#
directive|define
name|MSIADDRHPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSIADDRHPERR_S)
end_define

begin_define
define|#
directive|define
name|MSIADDRHPERR_F
value|MSIADDRHPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSIADDRLPERR_S
value|0
end_define

begin_define
define|#
directive|define
name|MSIADDRLPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSIADDRLPERR_S)
end_define

begin_define
define|#
directive|define
name|MSIADDRLPERR_F
value|MSIADDRLPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|READRSPERR_S
value|29
end_define

begin_define
define|#
directive|define
name|READRSPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< READRSPERR_S)
end_define

begin_define
define|#
directive|define
name|READRSPERR_F
value|READRSPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|TRGT1GRPPERR_S
value|28
end_define

begin_define
define|#
directive|define
name|TRGT1GRPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TRGT1GRPPERR_S)
end_define

begin_define
define|#
directive|define
name|TRGT1GRPPERR_F
value|TRGT1GRPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|IPSOTPERR_S
value|27
end_define

begin_define
define|#
directive|define
name|IPSOTPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IPSOTPERR_S)
end_define

begin_define
define|#
directive|define
name|IPSOTPERR_F
value|IPSOTPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|IPRETRYPERR_S
value|26
end_define

begin_define
define|#
directive|define
name|IPRETRYPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IPRETRYPERR_S)
end_define

begin_define
define|#
directive|define
name|IPRETRYPERR_F
value|IPRETRYPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|IPRXDATAGRPPERR_S
value|25
end_define

begin_define
define|#
directive|define
name|IPRXDATAGRPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IPRXDATAGRPPERR_S)
end_define

begin_define
define|#
directive|define
name|IPRXDATAGRPPERR_F
value|IPRXDATAGRPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|IPRXHDRGRPPERR_S
value|24
end_define

begin_define
define|#
directive|define
name|IPRXHDRGRPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IPRXHDRGRPPERR_S)
end_define

begin_define
define|#
directive|define
name|IPRXHDRGRPPERR_F
value|IPRXHDRGRPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MAGRPPERR_S
value|22
end_define

begin_define
define|#
directive|define
name|MAGRPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MAGRPPERR_S)
end_define

begin_define
define|#
directive|define
name|MAGRPPERR_F
value|MAGRPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|VFIDPERR_S
value|21
end_define

begin_define
define|#
directive|define
name|VFIDPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFIDPERR_S)
end_define

begin_define
define|#
directive|define
name|VFIDPERR_F
value|VFIDPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|HREQWRPERR_S
value|16
end_define

begin_define
define|#
directive|define
name|HREQWRPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HREQWRPERR_S)
end_define

begin_define
define|#
directive|define
name|HREQWRPERR_F
value|HREQWRPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|DREQWRPERR_S
value|13
end_define

begin_define
define|#
directive|define
name|DREQWRPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DREQWRPERR_S)
end_define

begin_define
define|#
directive|define
name|DREQWRPERR_F
value|DREQWRPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|CREQRDPERR_S
value|11
end_define

begin_define
define|#
directive|define
name|CREQRDPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CREQRDPERR_S)
end_define

begin_define
define|#
directive|define
name|CREQRDPERR_F
value|CREQRDPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSTTAGQPERR_S
value|10
end_define

begin_define
define|#
directive|define
name|MSTTAGQPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSTTAGQPERR_S)
end_define

begin_define
define|#
directive|define
name|MSTTAGQPERR_F
value|MSTTAGQPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|PIOREQGRPPERR_S
value|8
end_define

begin_define
define|#
directive|define
name|PIOREQGRPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PIOREQGRPPERR_S)
end_define

begin_define
define|#
directive|define
name|PIOREQGRPPERR_F
value|PIOREQGRPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|PIOCPLGRPPERR_S
value|7
end_define

begin_define
define|#
directive|define
name|PIOCPLGRPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PIOCPLGRPPERR_S)
end_define

begin_define
define|#
directive|define
name|PIOCPLGRPPERR_F
value|PIOCPLGRPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSIXSTIPERR_S
value|2
end_define

begin_define
define|#
directive|define
name|MSIXSTIPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSIXSTIPERR_S)
end_define

begin_define
define|#
directive|define
name|MSIXSTIPERR_F
value|MSIXSTIPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSTTIMEOUTPERR_S
value|1
end_define

begin_define
define|#
directive|define
name|MSTTIMEOUTPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSTTIMEOUTPERR_S)
end_define

begin_define
define|#
directive|define
name|MSTTIMEOUTPERR_F
value|MSTTIMEOUTPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MSTGRPPERR_S
value|0
end_define

begin_define
define|#
directive|define
name|MSTGRPPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSTGRPPERR_S)
end_define

begin_define
define|#
directive|define
name|MSTGRPPERR_F
value|MSTGRPPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|PCIE_NONFAT_ERR_A
value|0x3010
end_define

begin_define
define|#
directive|define
name|PCIE_CFG_SPACE_REQ_A
value|0x3060
end_define

begin_define
define|#
directive|define
name|PCIE_CFG_SPACE_DATA_A
value|0x3064
end_define

begin_define
define|#
directive|define
name|PCIE_MEM_ACCESS_BASE_WIN_A
value|0x3068
end_define

begin_define
define|#
directive|define
name|PCIEOFST_S
value|10
end_define

begin_define
define|#
directive|define
name|PCIEOFST_M
value|0x3fffffU
end_define

begin_define
define|#
directive|define
name|PCIEOFST_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PCIEOFST_S)& PCIEOFST_M)
end_define

begin_define
define|#
directive|define
name|BIR_S
value|8
end_define

begin_define
define|#
directive|define
name|BIR_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|BIR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BIR_S)
end_define

begin_define
define|#
directive|define
name|BIR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> BIR_S)& BIR_M)
end_define

begin_define
define|#
directive|define
name|WINDOW_S
value|0
end_define

begin_define
define|#
directive|define
name|WINDOW_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|WINDOW_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< WINDOW_S)
end_define

begin_define
define|#
directive|define
name|WINDOW_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> WINDOW_S)& WINDOW_M)
end_define

begin_define
define|#
directive|define
name|PCIE_MEM_ACCESS_OFFSET_A
value|0x306c
end_define

begin_define
define|#
directive|define
name|ENABLE_S
value|30
end_define

begin_define
define|#
directive|define
name|ENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ENABLE_S)
end_define

begin_define
define|#
directive|define
name|ENABLE_F
value|ENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|LOCALCFG_S
value|28
end_define

begin_define
define|#
directive|define
name|LOCALCFG_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< LOCALCFG_S)
end_define

begin_define
define|#
directive|define
name|LOCALCFG_F
value|LOCALCFG_V(1U)
end_define

begin_define
define|#
directive|define
name|FUNCTION_S
value|12
end_define

begin_define
define|#
directive|define
name|FUNCTION_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FUNCTION_S)
end_define

begin_define
define|#
directive|define
name|REGISTER_S
value|0
end_define

begin_define
define|#
directive|define
name|REGISTER_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< REGISTER_S)
end_define

begin_define
define|#
directive|define
name|T6_ENABLE_S
value|31
end_define

begin_define
define|#
directive|define
name|T6_ENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T6_ENABLE_S)
end_define

begin_define
define|#
directive|define
name|T6_ENABLE_F
value|T6_ENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|PFNUM_S
value|0
end_define

begin_define
define|#
directive|define
name|PFNUM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PFNUM_S)
end_define

begin_define
define|#
directive|define
name|PCIE_FW_A
value|0x30b8
end_define

begin_define
define|#
directive|define
name|PCIE_FW_PF_A
value|0x30bc
end_define

begin_define
define|#
directive|define
name|PCIE_CORE_UTL_SYSTEM_BUS_AGENT_STATUS_A
value|0x5908
end_define

begin_define
define|#
directive|define
name|RNPP_S
value|31
end_define

begin_define
define|#
directive|define
name|RNPP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RNPP_S)
end_define

begin_define
define|#
directive|define
name|RNPP_F
value|RNPP_V(1U)
end_define

begin_define
define|#
directive|define
name|RPCP_S
value|29
end_define

begin_define
define|#
directive|define
name|RPCP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RPCP_S)
end_define

begin_define
define|#
directive|define
name|RPCP_F
value|RPCP_V(1U)
end_define

begin_define
define|#
directive|define
name|RCIP_S
value|27
end_define

begin_define
define|#
directive|define
name|RCIP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RCIP_S)
end_define

begin_define
define|#
directive|define
name|RCIP_F
value|RCIP_V(1U)
end_define

begin_define
define|#
directive|define
name|RCCP_S
value|26
end_define

begin_define
define|#
directive|define
name|RCCP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RCCP_S)
end_define

begin_define
define|#
directive|define
name|RCCP_F
value|RCCP_V(1U)
end_define

begin_define
define|#
directive|define
name|RFTP_S
value|23
end_define

begin_define
define|#
directive|define
name|RFTP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RFTP_S)
end_define

begin_define
define|#
directive|define
name|RFTP_F
value|RFTP_V(1U)
end_define

begin_define
define|#
directive|define
name|PTRP_S
value|20
end_define

begin_define
define|#
directive|define
name|PTRP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PTRP_S)
end_define

begin_define
define|#
directive|define
name|PTRP_F
value|PTRP_V(1U)
end_define

begin_define
define|#
directive|define
name|PCIE_CORE_UTL_PCI_EXPRESS_PORT_STATUS_A
value|0x59a4
end_define

begin_define
define|#
directive|define
name|TPCP_S
value|30
end_define

begin_define
define|#
directive|define
name|TPCP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TPCP_S)
end_define

begin_define
define|#
directive|define
name|TPCP_F
value|TPCP_V(1U)
end_define

begin_define
define|#
directive|define
name|TNPP_S
value|29
end_define

begin_define
define|#
directive|define
name|TNPP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TNPP_S)
end_define

begin_define
define|#
directive|define
name|TNPP_F
value|TNPP_V(1U)
end_define

begin_define
define|#
directive|define
name|TFTP_S
value|28
end_define

begin_define
define|#
directive|define
name|TFTP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TFTP_S)
end_define

begin_define
define|#
directive|define
name|TFTP_F
value|TFTP_V(1U)
end_define

begin_define
define|#
directive|define
name|TCAP_S
value|27
end_define

begin_define
define|#
directive|define
name|TCAP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TCAP_S)
end_define

begin_define
define|#
directive|define
name|TCAP_F
value|TCAP_V(1U)
end_define

begin_define
define|#
directive|define
name|TCIP_S
value|26
end_define

begin_define
define|#
directive|define
name|TCIP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TCIP_S)
end_define

begin_define
define|#
directive|define
name|TCIP_F
value|TCIP_V(1U)
end_define

begin_define
define|#
directive|define
name|RCAP_S
value|25
end_define

begin_define
define|#
directive|define
name|RCAP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RCAP_S)
end_define

begin_define
define|#
directive|define
name|RCAP_F
value|RCAP_V(1U)
end_define

begin_define
define|#
directive|define
name|PLUP_S
value|23
end_define

begin_define
define|#
directive|define
name|PLUP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PLUP_S)
end_define

begin_define
define|#
directive|define
name|PLUP_F
value|PLUP_V(1U)
end_define

begin_define
define|#
directive|define
name|PLDN_S
value|22
end_define

begin_define
define|#
directive|define
name|PLDN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PLDN_S)
end_define

begin_define
define|#
directive|define
name|PLDN_F
value|PLDN_V(1U)
end_define

begin_define
define|#
directive|define
name|OTDD_S
value|21
end_define

begin_define
define|#
directive|define
name|OTDD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OTDD_S)
end_define

begin_define
define|#
directive|define
name|OTDD_F
value|OTDD_V(1U)
end_define

begin_define
define|#
directive|define
name|GTRP_S
value|20
end_define

begin_define
define|#
directive|define
name|GTRP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< GTRP_S)
end_define

begin_define
define|#
directive|define
name|GTRP_F
value|GTRP_V(1U)
end_define

begin_define
define|#
directive|define
name|RDPE_S
value|18
end_define

begin_define
define|#
directive|define
name|RDPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RDPE_S)
end_define

begin_define
define|#
directive|define
name|RDPE_F
value|RDPE_V(1U)
end_define

begin_define
define|#
directive|define
name|TDCE_S
value|17
end_define

begin_define
define|#
directive|define
name|TDCE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TDCE_S)
end_define

begin_define
define|#
directive|define
name|TDCE_F
value|TDCE_V(1U)
end_define

begin_define
define|#
directive|define
name|TDUE_S
value|16
end_define

begin_define
define|#
directive|define
name|TDUE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TDUE_S)
end_define

begin_define
define|#
directive|define
name|TDUE_F
value|TDUE_V(1U)
end_define

begin_comment
comment|/* registers for module MC */
end_comment

begin_define
define|#
directive|define
name|MC_INT_CAUSE_A
value|0x7518
end_define

begin_define
define|#
directive|define
name|MC_P_INT_CAUSE_A
value|0x41318
end_define

begin_define
define|#
directive|define
name|ECC_UE_INT_CAUSE_S
value|2
end_define

begin_define
define|#
directive|define
name|ECC_UE_INT_CAUSE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ECC_UE_INT_CAUSE_S)
end_define

begin_define
define|#
directive|define
name|ECC_UE_INT_CAUSE_F
value|ECC_UE_INT_CAUSE_V(1U)
end_define

begin_define
define|#
directive|define
name|ECC_CE_INT_CAUSE_S
value|1
end_define

begin_define
define|#
directive|define
name|ECC_CE_INT_CAUSE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ECC_CE_INT_CAUSE_S)
end_define

begin_define
define|#
directive|define
name|ECC_CE_INT_CAUSE_F
value|ECC_CE_INT_CAUSE_V(1U)
end_define

begin_define
define|#
directive|define
name|PERR_INT_CAUSE_S
value|0
end_define

begin_define
define|#
directive|define
name|PERR_INT_CAUSE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PERR_INT_CAUSE_S)
end_define

begin_define
define|#
directive|define
name|PERR_INT_CAUSE_F
value|PERR_INT_CAUSE_V(1U)
end_define

begin_define
define|#
directive|define
name|MC_ECC_STATUS_A
value|0x751c
end_define

begin_define
define|#
directive|define
name|MC_P_ECC_STATUS_A
value|0x4131c
end_define

begin_define
define|#
directive|define
name|ECC_CECNT_S
value|16
end_define

begin_define
define|#
directive|define
name|ECC_CECNT_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|ECC_CECNT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ECC_CECNT_S)
end_define

begin_define
define|#
directive|define
name|ECC_CECNT_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> ECC_CECNT_S)& ECC_CECNT_M)
end_define

begin_define
define|#
directive|define
name|ECC_UECNT_S
value|0
end_define

begin_define
define|#
directive|define
name|ECC_UECNT_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|ECC_UECNT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ECC_UECNT_S)
end_define

begin_define
define|#
directive|define
name|ECC_UECNT_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> ECC_UECNT_S)& ECC_UECNT_M)
end_define

begin_define
define|#
directive|define
name|MC_BIST_CMD_A
value|0x7600
end_define

begin_define
define|#
directive|define
name|START_BIST_S
value|31
end_define

begin_define
define|#
directive|define
name|START_BIST_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< START_BIST_S)
end_define

begin_define
define|#
directive|define
name|START_BIST_F
value|START_BIST_V(1U)
end_define

begin_define
define|#
directive|define
name|BIST_CMD_GAP_S
value|8
end_define

begin_define
define|#
directive|define
name|BIST_CMD_GAP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BIST_CMD_GAP_S)
end_define

begin_define
define|#
directive|define
name|BIST_OPCODE_S
value|0
end_define

begin_define
define|#
directive|define
name|BIST_OPCODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BIST_OPCODE_S)
end_define

begin_define
define|#
directive|define
name|MC_BIST_CMD_ADDR_A
value|0x7604
end_define

begin_define
define|#
directive|define
name|MC_BIST_CMD_LEN_A
value|0x7608
end_define

begin_define
define|#
directive|define
name|MC_BIST_DATA_PATTERN_A
value|0x760c
end_define

begin_define
define|#
directive|define
name|MC_BIST_STATUS_RDATA_A
value|0x7688
end_define

begin_comment
comment|/* registers for module MA */
end_comment

begin_define
define|#
directive|define
name|MA_EDRAM0_BAR_A
value|0x77c0
end_define

begin_define
define|#
directive|define
name|EDRAM0_BASE_S
value|16
end_define

begin_define
define|#
directive|define
name|EDRAM0_BASE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|EDRAM0_BASE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EDRAM0_BASE_S)& EDRAM0_BASE_M)
end_define

begin_define
define|#
directive|define
name|EDRAM0_SIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|EDRAM0_SIZE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|EDRAM0_SIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EDRAM0_SIZE_S)
end_define

begin_define
define|#
directive|define
name|EDRAM0_SIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EDRAM0_SIZE_S)& EDRAM0_SIZE_M)
end_define

begin_define
define|#
directive|define
name|MA_EDRAM1_BAR_A
value|0x77c4
end_define

begin_define
define|#
directive|define
name|EDRAM1_BASE_S
value|16
end_define

begin_define
define|#
directive|define
name|EDRAM1_BASE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|EDRAM1_BASE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EDRAM1_BASE_S)& EDRAM1_BASE_M)
end_define

begin_define
define|#
directive|define
name|EDRAM1_SIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|EDRAM1_SIZE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|EDRAM1_SIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EDRAM1_SIZE_S)
end_define

begin_define
define|#
directive|define
name|EDRAM1_SIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EDRAM1_SIZE_S)& EDRAM1_SIZE_M)
end_define

begin_define
define|#
directive|define
name|MA_EXT_MEMORY_BAR_A
value|0x77c8
end_define

begin_define
define|#
directive|define
name|EXT_MEM_BASE_S
value|16
end_define

begin_define
define|#
directive|define
name|EXT_MEM_BASE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|EXT_MEM_BASE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EXT_MEM_BASE_S)
end_define

begin_define
define|#
directive|define
name|EXT_MEM_BASE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EXT_MEM_BASE_S)& EXT_MEM_BASE_M)
end_define

begin_define
define|#
directive|define
name|EXT_MEM_SIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|EXT_MEM_SIZE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|EXT_MEM_SIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EXT_MEM_SIZE_S)
end_define

begin_define
define|#
directive|define
name|EXT_MEM_SIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EXT_MEM_SIZE_S)& EXT_MEM_SIZE_M)
end_define

begin_define
define|#
directive|define
name|MA_EXT_MEMORY1_BAR_A
value|0x7808
end_define

begin_define
define|#
directive|define
name|EXT_MEM1_BASE_S
value|16
end_define

begin_define
define|#
directive|define
name|EXT_MEM1_BASE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|EXT_MEM1_BASE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EXT_MEM1_BASE_S)& EXT_MEM1_BASE_M)
end_define

begin_define
define|#
directive|define
name|EXT_MEM1_SIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|EXT_MEM1_SIZE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|EXT_MEM1_SIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EXT_MEM1_SIZE_S)
end_define

begin_define
define|#
directive|define
name|EXT_MEM1_SIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EXT_MEM1_SIZE_S)& EXT_MEM1_SIZE_M)
end_define

begin_define
define|#
directive|define
name|MA_EXT_MEMORY0_BAR_A
value|0x77c8
end_define

begin_define
define|#
directive|define
name|EXT_MEM0_BASE_S
value|16
end_define

begin_define
define|#
directive|define
name|EXT_MEM0_BASE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|EXT_MEM0_BASE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EXT_MEM0_BASE_S)& EXT_MEM0_BASE_M)
end_define

begin_define
define|#
directive|define
name|EXT_MEM0_SIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|EXT_MEM0_SIZE_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|EXT_MEM0_SIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EXT_MEM0_SIZE_S)
end_define

begin_define
define|#
directive|define
name|EXT_MEM0_SIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> EXT_MEM0_SIZE_S)& EXT_MEM0_SIZE_M)
end_define

begin_define
define|#
directive|define
name|MA_TARGET_MEM_ENABLE_A
value|0x77d8
end_define

begin_define
define|#
directive|define
name|EXT_MEM_ENABLE_S
value|2
end_define

begin_define
define|#
directive|define
name|EXT_MEM_ENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EXT_MEM_ENABLE_S)
end_define

begin_define
define|#
directive|define
name|EXT_MEM_ENABLE_F
value|EXT_MEM_ENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|EDRAM1_ENABLE_S
value|1
end_define

begin_define
define|#
directive|define
name|EDRAM1_ENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EDRAM1_ENABLE_S)
end_define

begin_define
define|#
directive|define
name|EDRAM1_ENABLE_F
value|EDRAM1_ENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|EDRAM0_ENABLE_S
value|0
end_define

begin_define
define|#
directive|define
name|EDRAM0_ENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EDRAM0_ENABLE_S)
end_define

begin_define
define|#
directive|define
name|EDRAM0_ENABLE_F
value|EDRAM0_ENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|EXT_MEM1_ENABLE_S
value|4
end_define

begin_define
define|#
directive|define
name|EXT_MEM1_ENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EXT_MEM1_ENABLE_S)
end_define

begin_define
define|#
directive|define
name|EXT_MEM1_ENABLE_F
value|EXT_MEM1_ENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|EXT_MEM0_ENABLE_S
value|2
end_define

begin_define
define|#
directive|define
name|EXT_MEM0_ENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EXT_MEM0_ENABLE_S)
end_define

begin_define
define|#
directive|define
name|EXT_MEM0_ENABLE_F
value|EXT_MEM0_ENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|MA_INT_CAUSE_A
value|0x77e0
end_define

begin_define
define|#
directive|define
name|MEM_PERR_INT_CAUSE_S
value|1
end_define

begin_define
define|#
directive|define
name|MEM_PERR_INT_CAUSE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MEM_PERR_INT_CAUSE_S)
end_define

begin_define
define|#
directive|define
name|MEM_PERR_INT_CAUSE_F
value|MEM_PERR_INT_CAUSE_V(1U)
end_define

begin_define
define|#
directive|define
name|MEM_WRAP_INT_CAUSE_S
value|0
end_define

begin_define
define|#
directive|define
name|MEM_WRAP_INT_CAUSE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MEM_WRAP_INT_CAUSE_S)
end_define

begin_define
define|#
directive|define
name|MEM_WRAP_INT_CAUSE_F
value|MEM_WRAP_INT_CAUSE_V(1U)
end_define

begin_define
define|#
directive|define
name|MA_INT_WRAP_STATUS_A
value|0x77e4
end_define

begin_define
define|#
directive|define
name|MEM_WRAP_ADDRESS_S
value|4
end_define

begin_define
define|#
directive|define
name|MEM_WRAP_ADDRESS_M
value|0xfffffffU
end_define

begin_define
define|#
directive|define
name|MEM_WRAP_ADDRESS_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> MEM_WRAP_ADDRESS_S)& MEM_WRAP_ADDRESS_M)
end_define

begin_define
define|#
directive|define
name|MEM_WRAP_CLIENT_NUM_S
value|0
end_define

begin_define
define|#
directive|define
name|MEM_WRAP_CLIENT_NUM_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|MEM_WRAP_CLIENT_NUM_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> MEM_WRAP_CLIENT_NUM_S)& MEM_WRAP_CLIENT_NUM_M)
end_define

begin_define
define|#
directive|define
name|MA_PARITY_ERROR_STATUS_A
value|0x77f4
end_define

begin_define
define|#
directive|define
name|MA_PARITY_ERROR_STATUS1_A
value|0x77f4
end_define

begin_define
define|#
directive|define
name|MA_PARITY_ERROR_STATUS2_A
value|0x7804
end_define

begin_comment
comment|/* registers for module EDC_0 */
end_comment

begin_define
define|#
directive|define
name|EDC_0_BASE_ADDR
value|0x7900
end_define

begin_define
define|#
directive|define
name|EDC_BIST_CMD_A
value|0x7904
end_define

begin_define
define|#
directive|define
name|EDC_BIST_CMD_ADDR_A
value|0x7908
end_define

begin_define
define|#
directive|define
name|EDC_BIST_CMD_LEN_A
value|0x790c
end_define

begin_define
define|#
directive|define
name|EDC_BIST_DATA_PATTERN_A
value|0x7910
end_define

begin_define
define|#
directive|define
name|EDC_BIST_STATUS_RDATA_A
value|0x7928
end_define

begin_define
define|#
directive|define
name|EDC_INT_CAUSE_A
value|0x7978
end_define

begin_define
define|#
directive|define
name|ECC_UE_PAR_S
value|5
end_define

begin_define
define|#
directive|define
name|ECC_UE_PAR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ECC_UE_PAR_S)
end_define

begin_define
define|#
directive|define
name|ECC_UE_PAR_F
value|ECC_UE_PAR_V(1U)
end_define

begin_define
define|#
directive|define
name|ECC_CE_PAR_S
value|4
end_define

begin_define
define|#
directive|define
name|ECC_CE_PAR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ECC_CE_PAR_S)
end_define

begin_define
define|#
directive|define
name|ECC_CE_PAR_F
value|ECC_CE_PAR_V(1U)
end_define

begin_define
define|#
directive|define
name|PERR_PAR_CAUSE_S
value|3
end_define

begin_define
define|#
directive|define
name|PERR_PAR_CAUSE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PERR_PAR_CAUSE_S)
end_define

begin_define
define|#
directive|define
name|PERR_PAR_CAUSE_F
value|PERR_PAR_CAUSE_V(1U)
end_define

begin_define
define|#
directive|define
name|EDC_ECC_STATUS_A
value|0x797c
end_define

begin_comment
comment|/* registers for module EDC_1 */
end_comment

begin_define
define|#
directive|define
name|EDC_1_BASE_ADDR
value|0x7980
end_define

begin_comment
comment|/* registers for module CIM */
end_comment

begin_define
define|#
directive|define
name|CIM_BOOT_CFG_A
value|0x7b00
end_define

begin_define
define|#
directive|define
name|CIM_SDRAM_BASE_ADDR_A
value|0x7b14
end_define

begin_define
define|#
directive|define
name|CIM_SDRAM_ADDR_SIZE_A
value|0x7b18
end_define

begin_define
define|#
directive|define
name|CIM_EXTMEM2_BASE_ADDR_A
value|0x7b1c
end_define

begin_define
define|#
directive|define
name|CIM_EXTMEM2_ADDR_SIZE_A
value|0x7b20
end_define

begin_define
define|#
directive|define
name|CIM_PF_MAILBOX_CTRL_SHADOW_COPY_A
value|0x290
end_define

begin_define
define|#
directive|define
name|BOOTADDR_M
value|0xffffff00U
end_define

begin_define
define|#
directive|define
name|UPCRST_S
value|0
end_define

begin_define
define|#
directive|define
name|UPCRST_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPCRST_S)
end_define

begin_define
define|#
directive|define
name|UPCRST_F
value|UPCRST_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_PF_MAILBOX_DATA_A
value|0x240
end_define

begin_define
define|#
directive|define
name|CIM_PF_MAILBOX_CTRL_A
value|0x280
end_define

begin_define
define|#
directive|define
name|MBMSGVALID_S
value|3
end_define

begin_define
define|#
directive|define
name|MBMSGVALID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MBMSGVALID_S)
end_define

begin_define
define|#
directive|define
name|MBMSGVALID_F
value|MBMSGVALID_V(1U)
end_define

begin_define
define|#
directive|define
name|MBINTREQ_S
value|2
end_define

begin_define
define|#
directive|define
name|MBINTREQ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MBINTREQ_S)
end_define

begin_define
define|#
directive|define
name|MBINTREQ_F
value|MBINTREQ_V(1U)
end_define

begin_define
define|#
directive|define
name|MBOWNER_S
value|0
end_define

begin_define
define|#
directive|define
name|MBOWNER_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|MBOWNER_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MBOWNER_S)
end_define

begin_define
define|#
directive|define
name|MBOWNER_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> MBOWNER_S)& MBOWNER_M)
end_define

begin_define
define|#
directive|define
name|CIM_PF_HOST_INT_ENABLE_A
value|0x288
end_define

begin_define
define|#
directive|define
name|MBMSGRDYINTEN_S
value|19
end_define

begin_define
define|#
directive|define
name|MBMSGRDYINTEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MBMSGRDYINTEN_S)
end_define

begin_define
define|#
directive|define
name|MBMSGRDYINTEN_F
value|MBMSGRDYINTEN_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_PF_HOST_INT_CAUSE_A
value|0x28c
end_define

begin_define
define|#
directive|define
name|MBMSGRDYINT_S
value|19
end_define

begin_define
define|#
directive|define
name|MBMSGRDYINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MBMSGRDYINT_S)
end_define

begin_define
define|#
directive|define
name|MBMSGRDYINT_F
value|MBMSGRDYINT_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_HOST_INT_CAUSE_A
value|0x7b2c
end_define

begin_define
define|#
directive|define
name|TIEQOUTPARERRINT_S
value|20
end_define

begin_define
define|#
directive|define
name|TIEQOUTPARERRINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIEQOUTPARERRINT_S)
end_define

begin_define
define|#
directive|define
name|TIEQOUTPARERRINT_F
value|TIEQOUTPARERRINT_V(1U)
end_define

begin_define
define|#
directive|define
name|TIEQINPARERRINT_S
value|19
end_define

begin_define
define|#
directive|define
name|TIEQINPARERRINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIEQINPARERRINT_S)
end_define

begin_define
define|#
directive|define
name|TIEQINPARERRINT_F
value|TIEQINPARERRINT_V(1U)
end_define

begin_define
define|#
directive|define
name|PREFDROPINT_S
value|1
end_define

begin_define
define|#
directive|define
name|PREFDROPINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PREFDROPINT_S)
end_define

begin_define
define|#
directive|define
name|PREFDROPINT_F
value|PREFDROPINT_V(1U)
end_define

begin_define
define|#
directive|define
name|UPACCNONZERO_S
value|0
end_define

begin_define
define|#
directive|define
name|UPACCNONZERO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPACCNONZERO_S)
end_define

begin_define
define|#
directive|define
name|UPACCNONZERO_F
value|UPACCNONZERO_V(1U)
end_define

begin_define
define|#
directive|define
name|MBHOSTPARERR_S
value|18
end_define

begin_define
define|#
directive|define
name|MBHOSTPARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MBHOSTPARERR_S)
end_define

begin_define
define|#
directive|define
name|MBHOSTPARERR_F
value|MBHOSTPARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MBUPPARERR_S
value|17
end_define

begin_define
define|#
directive|define
name|MBUPPARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MBUPPARERR_S)
end_define

begin_define
define|#
directive|define
name|MBUPPARERR_F
value|MBUPPARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|IBQTP0PARERR_S
value|16
end_define

begin_define
define|#
directive|define
name|IBQTP0PARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IBQTP0PARERR_S)
end_define

begin_define
define|#
directive|define
name|IBQTP0PARERR_F
value|IBQTP0PARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|IBQTP1PARERR_S
value|15
end_define

begin_define
define|#
directive|define
name|IBQTP1PARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IBQTP1PARERR_S)
end_define

begin_define
define|#
directive|define
name|IBQTP1PARERR_F
value|IBQTP1PARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|IBQULPPARERR_S
value|14
end_define

begin_define
define|#
directive|define
name|IBQULPPARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IBQULPPARERR_S)
end_define

begin_define
define|#
directive|define
name|IBQULPPARERR_F
value|IBQULPPARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|IBQSGELOPARERR_S
value|13
end_define

begin_define
define|#
directive|define
name|IBQSGELOPARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IBQSGELOPARERR_S)
end_define

begin_define
define|#
directive|define
name|IBQSGELOPARERR_F
value|IBQSGELOPARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|IBQSGEHIPARERR_S
value|12
end_define

begin_define
define|#
directive|define
name|IBQSGEHIPARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IBQSGEHIPARERR_S)
end_define

begin_define
define|#
directive|define
name|IBQSGEHIPARERR_F
value|IBQSGEHIPARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|IBQNCSIPARERR_S
value|11
end_define

begin_define
define|#
directive|define
name|IBQNCSIPARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IBQNCSIPARERR_S)
end_define

begin_define
define|#
directive|define
name|IBQNCSIPARERR_F
value|IBQNCSIPARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|OBQULP0PARERR_S
value|10
end_define

begin_define
define|#
directive|define
name|OBQULP0PARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OBQULP0PARERR_S)
end_define

begin_define
define|#
directive|define
name|OBQULP0PARERR_F
value|OBQULP0PARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|OBQULP1PARERR_S
value|9
end_define

begin_define
define|#
directive|define
name|OBQULP1PARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OBQULP1PARERR_S)
end_define

begin_define
define|#
directive|define
name|OBQULP1PARERR_F
value|OBQULP1PARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|OBQULP2PARERR_S
value|8
end_define

begin_define
define|#
directive|define
name|OBQULP2PARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OBQULP2PARERR_S)
end_define

begin_define
define|#
directive|define
name|OBQULP2PARERR_F
value|OBQULP2PARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|OBQULP3PARERR_S
value|7
end_define

begin_define
define|#
directive|define
name|OBQULP3PARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OBQULP3PARERR_S)
end_define

begin_define
define|#
directive|define
name|OBQULP3PARERR_F
value|OBQULP3PARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|OBQSGEPARERR_S
value|6
end_define

begin_define
define|#
directive|define
name|OBQSGEPARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OBQSGEPARERR_S)
end_define

begin_define
define|#
directive|define
name|OBQSGEPARERR_F
value|OBQSGEPARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|OBQNCSIPARERR_S
value|5
end_define

begin_define
define|#
directive|define
name|OBQNCSIPARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OBQNCSIPARERR_S)
end_define

begin_define
define|#
directive|define
name|OBQNCSIPARERR_F
value|OBQNCSIPARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_HOST_UPACC_INT_CAUSE_A
value|0x7b34
end_define

begin_define
define|#
directive|define
name|EEPROMWRINT_S
value|30
end_define

begin_define
define|#
directive|define
name|EEPROMWRINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EEPROMWRINT_S)
end_define

begin_define
define|#
directive|define
name|EEPROMWRINT_F
value|EEPROMWRINT_V(1U)
end_define

begin_define
define|#
directive|define
name|TIMEOUTMAINT_S
value|29
end_define

begin_define
define|#
directive|define
name|TIMEOUTMAINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIMEOUTMAINT_S)
end_define

begin_define
define|#
directive|define
name|TIMEOUTMAINT_F
value|TIMEOUTMAINT_V(1U)
end_define

begin_define
define|#
directive|define
name|TIMEOUTINT_S
value|28
end_define

begin_define
define|#
directive|define
name|TIMEOUTINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TIMEOUTINT_S)
end_define

begin_define
define|#
directive|define
name|TIMEOUTINT_F
value|TIMEOUTINT_V(1U)
end_define

begin_define
define|#
directive|define
name|RSPOVRLOOKUPINT_S
value|27
end_define

begin_define
define|#
directive|define
name|RSPOVRLOOKUPINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RSPOVRLOOKUPINT_S)
end_define

begin_define
define|#
directive|define
name|RSPOVRLOOKUPINT_F
value|RSPOVRLOOKUPINT_V(1U)
end_define

begin_define
define|#
directive|define
name|REQOVRLOOKUPINT_S
value|26
end_define

begin_define
define|#
directive|define
name|REQOVRLOOKUPINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< REQOVRLOOKUPINT_S)
end_define

begin_define
define|#
directive|define
name|REQOVRLOOKUPINT_F
value|REQOVRLOOKUPINT_V(1U)
end_define

begin_define
define|#
directive|define
name|BLKWRPLINT_S
value|25
end_define

begin_define
define|#
directive|define
name|BLKWRPLINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BLKWRPLINT_S)
end_define

begin_define
define|#
directive|define
name|BLKWRPLINT_F
value|BLKWRPLINT_V(1U)
end_define

begin_define
define|#
directive|define
name|BLKRDPLINT_S
value|24
end_define

begin_define
define|#
directive|define
name|BLKRDPLINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BLKRDPLINT_S)
end_define

begin_define
define|#
directive|define
name|BLKRDPLINT_F
value|BLKRDPLINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SGLWRPLINT_S
value|23
end_define

begin_define
define|#
directive|define
name|SGLWRPLINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGLWRPLINT_S)
end_define

begin_define
define|#
directive|define
name|SGLWRPLINT_F
value|SGLWRPLINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SGLRDPLINT_S
value|22
end_define

begin_define
define|#
directive|define
name|SGLRDPLINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGLRDPLINT_S)
end_define

begin_define
define|#
directive|define
name|SGLRDPLINT_F
value|SGLRDPLINT_V(1U)
end_define

begin_define
define|#
directive|define
name|BLKWRCTLINT_S
value|21
end_define

begin_define
define|#
directive|define
name|BLKWRCTLINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BLKWRCTLINT_S)
end_define

begin_define
define|#
directive|define
name|BLKWRCTLINT_F
value|BLKWRCTLINT_V(1U)
end_define

begin_define
define|#
directive|define
name|BLKRDCTLINT_S
value|20
end_define

begin_define
define|#
directive|define
name|BLKRDCTLINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BLKRDCTLINT_S)
end_define

begin_define
define|#
directive|define
name|BLKRDCTLINT_F
value|BLKRDCTLINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SGLWRCTLINT_S
value|19
end_define

begin_define
define|#
directive|define
name|SGLWRCTLINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGLWRCTLINT_S)
end_define

begin_define
define|#
directive|define
name|SGLWRCTLINT_F
value|SGLWRCTLINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SGLRDCTLINT_S
value|18
end_define

begin_define
define|#
directive|define
name|SGLRDCTLINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGLRDCTLINT_S)
end_define

begin_define
define|#
directive|define
name|SGLRDCTLINT_F
value|SGLRDCTLINT_V(1U)
end_define

begin_define
define|#
directive|define
name|BLKWREEPROMINT_S
value|17
end_define

begin_define
define|#
directive|define
name|BLKWREEPROMINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BLKWREEPROMINT_S)
end_define

begin_define
define|#
directive|define
name|BLKWREEPROMINT_F
value|BLKWREEPROMINT_V(1U)
end_define

begin_define
define|#
directive|define
name|BLKRDEEPROMINT_S
value|16
end_define

begin_define
define|#
directive|define
name|BLKRDEEPROMINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BLKRDEEPROMINT_S)
end_define

begin_define
define|#
directive|define
name|BLKRDEEPROMINT_F
value|BLKRDEEPROMINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SGLWREEPROMINT_S
value|15
end_define

begin_define
define|#
directive|define
name|SGLWREEPROMINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGLWREEPROMINT_S)
end_define

begin_define
define|#
directive|define
name|SGLWREEPROMINT_F
value|SGLWREEPROMINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SGLRDEEPROMINT_S
value|14
end_define

begin_define
define|#
directive|define
name|SGLRDEEPROMINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGLRDEEPROMINT_S)
end_define

begin_define
define|#
directive|define
name|SGLRDEEPROMINT_F
value|SGLRDEEPROMINT_V(1U)
end_define

begin_define
define|#
directive|define
name|BLKWRFLASHINT_S
value|13
end_define

begin_define
define|#
directive|define
name|BLKWRFLASHINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BLKWRFLASHINT_S)
end_define

begin_define
define|#
directive|define
name|BLKWRFLASHINT_F
value|BLKWRFLASHINT_V(1U)
end_define

begin_define
define|#
directive|define
name|BLKRDFLASHINT_S
value|12
end_define

begin_define
define|#
directive|define
name|BLKRDFLASHINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BLKRDFLASHINT_S)
end_define

begin_define
define|#
directive|define
name|BLKRDFLASHINT_F
value|BLKRDFLASHINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SGLWRFLASHINT_S
value|11
end_define

begin_define
define|#
directive|define
name|SGLWRFLASHINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGLWRFLASHINT_S)
end_define

begin_define
define|#
directive|define
name|SGLWRFLASHINT_F
value|SGLWRFLASHINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SGLRDFLASHINT_S
value|10
end_define

begin_define
define|#
directive|define
name|SGLRDFLASHINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGLRDFLASHINT_S)
end_define

begin_define
define|#
directive|define
name|SGLRDFLASHINT_F
value|SGLRDFLASHINT_V(1U)
end_define

begin_define
define|#
directive|define
name|BLKWRBOOTINT_S
value|9
end_define

begin_define
define|#
directive|define
name|BLKWRBOOTINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BLKWRBOOTINT_S)
end_define

begin_define
define|#
directive|define
name|BLKWRBOOTINT_F
value|BLKWRBOOTINT_V(1U)
end_define

begin_define
define|#
directive|define
name|BLKRDBOOTINT_S
value|8
end_define

begin_define
define|#
directive|define
name|BLKRDBOOTINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BLKRDBOOTINT_S)
end_define

begin_define
define|#
directive|define
name|BLKRDBOOTINT_F
value|BLKRDBOOTINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SGLWRBOOTINT_S
value|7
end_define

begin_define
define|#
directive|define
name|SGLWRBOOTINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGLWRBOOTINT_S)
end_define

begin_define
define|#
directive|define
name|SGLWRBOOTINT_F
value|SGLWRBOOTINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SGLRDBOOTINT_S
value|6
end_define

begin_define
define|#
directive|define
name|SGLRDBOOTINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGLRDBOOTINT_S)
end_define

begin_define
define|#
directive|define
name|SGLRDBOOTINT_F
value|SGLRDBOOTINT_V(1U)
end_define

begin_define
define|#
directive|define
name|ILLWRBEINT_S
value|5
end_define

begin_define
define|#
directive|define
name|ILLWRBEINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ILLWRBEINT_S)
end_define

begin_define
define|#
directive|define
name|ILLWRBEINT_F
value|ILLWRBEINT_V(1U)
end_define

begin_define
define|#
directive|define
name|ILLRDBEINT_S
value|4
end_define

begin_define
define|#
directive|define
name|ILLRDBEINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ILLRDBEINT_S)
end_define

begin_define
define|#
directive|define
name|ILLRDBEINT_F
value|ILLRDBEINT_V(1U)
end_define

begin_define
define|#
directive|define
name|ILLRDINT_S
value|3
end_define

begin_define
define|#
directive|define
name|ILLRDINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ILLRDINT_S)
end_define

begin_define
define|#
directive|define
name|ILLRDINT_F
value|ILLRDINT_V(1U)
end_define

begin_define
define|#
directive|define
name|ILLWRINT_S
value|2
end_define

begin_define
define|#
directive|define
name|ILLWRINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ILLWRINT_S)
end_define

begin_define
define|#
directive|define
name|ILLWRINT_F
value|ILLWRINT_V(1U)
end_define

begin_define
define|#
directive|define
name|ILLTRANSINT_S
value|1
end_define

begin_define
define|#
directive|define
name|ILLTRANSINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ILLTRANSINT_S)
end_define

begin_define
define|#
directive|define
name|ILLTRANSINT_F
value|ILLTRANSINT_V(1U)
end_define

begin_define
define|#
directive|define
name|RSVDSPACEINT_S
value|0
end_define

begin_define
define|#
directive|define
name|RSVDSPACEINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RSVDSPACEINT_S)
end_define

begin_define
define|#
directive|define
name|RSVDSPACEINT_F
value|RSVDSPACEINT_V(1U)
end_define

begin_comment
comment|/* registers for module TP */
end_comment

begin_define
define|#
directive|define
name|DBGLAWHLF_S
value|23
end_define

begin_define
define|#
directive|define
name|DBGLAWHLF_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DBGLAWHLF_S)
end_define

begin_define
define|#
directive|define
name|DBGLAWHLF_F
value|DBGLAWHLF_V(1U)
end_define

begin_define
define|#
directive|define
name|DBGLAWPTR_S
value|16
end_define

begin_define
define|#
directive|define
name|DBGLAWPTR_M
value|0x7fU
end_define

begin_define
define|#
directive|define
name|DBGLAWPTR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> DBGLAWPTR_S)& DBGLAWPTR_M)
end_define

begin_define
define|#
directive|define
name|DBGLAENABLE_S
value|12
end_define

begin_define
define|#
directive|define
name|DBGLAENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DBGLAENABLE_S)
end_define

begin_define
define|#
directive|define
name|DBGLAENABLE_F
value|DBGLAENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|DBGLARPTR_S
value|0
end_define

begin_define
define|#
directive|define
name|DBGLARPTR_M
value|0x7fU
end_define

begin_define
define|#
directive|define
name|DBGLARPTR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DBGLARPTR_S)
end_define

begin_define
define|#
directive|define
name|TP_DBG_LA_DATAL_A
value|0x7ed8
end_define

begin_define
define|#
directive|define
name|TP_DBG_LA_CONFIG_A
value|0x7ed4
end_define

begin_define
define|#
directive|define
name|TP_OUT_CONFIG_A
value|0x7d04
end_define

begin_define
define|#
directive|define
name|TP_GLOBAL_CONFIG_A
value|0x7d08
end_define

begin_define
define|#
directive|define
name|TP_CMM_TCB_BASE_A
value|0x7d10
end_define

begin_define
define|#
directive|define
name|TP_CMM_MM_BASE_A
value|0x7d14
end_define

begin_define
define|#
directive|define
name|TP_CMM_TIMER_BASE_A
value|0x7d18
end_define

begin_define
define|#
directive|define
name|TP_PMM_TX_BASE_A
value|0x7d20
end_define

begin_define
define|#
directive|define
name|TP_PMM_RX_BASE_A
value|0x7d28
end_define

begin_define
define|#
directive|define
name|TP_PMM_RX_PAGE_SIZE_A
value|0x7d2c
end_define

begin_define
define|#
directive|define
name|TP_PMM_RX_MAX_PAGE_A
value|0x7d30
end_define

begin_define
define|#
directive|define
name|TP_PMM_TX_PAGE_SIZE_A
value|0x7d34
end_define

begin_define
define|#
directive|define
name|TP_PMM_TX_MAX_PAGE_A
value|0x7d38
end_define

begin_define
define|#
directive|define
name|TP_CMM_MM_MAX_PSTRUCT_A
value|0x7e6c
end_define

begin_define
define|#
directive|define
name|PMRXNUMCHN_S
value|31
end_define

begin_define
define|#
directive|define
name|PMRXNUMCHN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PMRXNUMCHN_S)
end_define

begin_define
define|#
directive|define
name|PMRXNUMCHN_F
value|PMRXNUMCHN_V(1U)
end_define

begin_define
define|#
directive|define
name|PMTXNUMCHN_S
value|30
end_define

begin_define
define|#
directive|define
name|PMTXNUMCHN_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|PMTXNUMCHN_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PMTXNUMCHN_S)& PMTXNUMCHN_M)
end_define

begin_define
define|#
directive|define
name|PMTXMAXPAGE_S
value|0
end_define

begin_define
define|#
directive|define
name|PMTXMAXPAGE_M
value|0x1fffffU
end_define

begin_define
define|#
directive|define
name|PMTXMAXPAGE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PMTXMAXPAGE_S)& PMTXMAXPAGE_M)
end_define

begin_define
define|#
directive|define
name|PMRXMAXPAGE_S
value|0
end_define

begin_define
define|#
directive|define
name|PMRXMAXPAGE_M
value|0x1fffffU
end_define

begin_define
define|#
directive|define
name|PMRXMAXPAGE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PMRXMAXPAGE_S)& PMRXMAXPAGE_M)
end_define

begin_define
define|#
directive|define
name|DBGLAMODE_S
value|14
end_define

begin_define
define|#
directive|define
name|DBGLAMODE_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|DBGLAMODE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> DBGLAMODE_S)& DBGLAMODE_M)
end_define

begin_define
define|#
directive|define
name|FIVETUPLELOOKUP_S
value|17
end_define

begin_define
define|#
directive|define
name|FIVETUPLELOOKUP_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|FIVETUPLELOOKUP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FIVETUPLELOOKUP_S)
end_define

begin_define
define|#
directive|define
name|FIVETUPLELOOKUP_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FIVETUPLELOOKUP_S)& FIVETUPLELOOKUP_M)
end_define

begin_define
define|#
directive|define
name|TP_PARA_REG2_A
value|0x7d68
end_define

begin_define
define|#
directive|define
name|MAXRXDATA_S
value|16
end_define

begin_define
define|#
directive|define
name|MAXRXDATA_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|MAXRXDATA_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> MAXRXDATA_S)& MAXRXDATA_M)
end_define

begin_define
define|#
directive|define
name|TP_TIMER_RESOLUTION_A
value|0x7d90
end_define

begin_define
define|#
directive|define
name|TIMERRESOLUTION_S
value|16
end_define

begin_define
define|#
directive|define
name|TIMERRESOLUTION_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|TIMERRESOLUTION_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TIMERRESOLUTION_S)& TIMERRESOLUTION_M)
end_define

begin_define
define|#
directive|define
name|TIMESTAMPRESOLUTION_S
value|8
end_define

begin_define
define|#
directive|define
name|TIMESTAMPRESOLUTION_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|TIMESTAMPRESOLUTION_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> TIMESTAMPRESOLUTION_S)& TIMESTAMPRESOLUTION_M)
end_define

begin_define
define|#
directive|define
name|DELAYEDACKRESOLUTION_S
value|0
end_define

begin_define
define|#
directive|define
name|DELAYEDACKRESOLUTION_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|DELAYEDACKRESOLUTION_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> DELAYEDACKRESOLUTION_S)& DELAYEDACKRESOLUTION_M)
end_define

begin_define
define|#
directive|define
name|TP_SHIFT_CNT_A
value|0x7dc0
end_define

begin_define
define|#
directive|define
name|TP_RXT_MIN_A
value|0x7d98
end_define

begin_define
define|#
directive|define
name|TP_RXT_MAX_A
value|0x7d9c
end_define

begin_define
define|#
directive|define
name|TP_PERS_MIN_A
value|0x7da0
end_define

begin_define
define|#
directive|define
name|TP_PERS_MAX_A
value|0x7da4
end_define

begin_define
define|#
directive|define
name|TP_KEEP_IDLE_A
value|0x7da8
end_define

begin_define
define|#
directive|define
name|TP_KEEP_INTVL_A
value|0x7dac
end_define

begin_define
define|#
directive|define
name|TP_INIT_SRTT_A
value|0x7db0
end_define

begin_define
define|#
directive|define
name|TP_DACK_TIMER_A
value|0x7db4
end_define

begin_define
define|#
directive|define
name|TP_FINWAIT2_TIMER_A
value|0x7db8
end_define

begin_define
define|#
directive|define
name|INITSRTT_S
value|0
end_define

begin_define
define|#
directive|define
name|INITSRTT_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|INITSRTT_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> INITSRTT_S)& INITSRTT_M)
end_define

begin_define
define|#
directive|define
name|PERSMAX_S
value|0
end_define

begin_define
define|#
directive|define
name|PERSMAX_M
value|0x3fffffffU
end_define

begin_define
define|#
directive|define
name|PERSMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PERSMAX_S)
end_define

begin_define
define|#
directive|define
name|PERSMAX_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PERSMAX_S)& PERSMAX_M)
end_define

begin_define
define|#
directive|define
name|SYNSHIFTMAX_S
value|24
end_define

begin_define
define|#
directive|define
name|SYNSHIFTMAX_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|SYNSHIFTMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SYNSHIFTMAX_S)
end_define

begin_define
define|#
directive|define
name|SYNSHIFTMAX_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> SYNSHIFTMAX_S)& SYNSHIFTMAX_M)
end_define

begin_define
define|#
directive|define
name|RXTSHIFTMAXR1_S
value|20
end_define

begin_define
define|#
directive|define
name|RXTSHIFTMAXR1_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|RXTSHIFTMAXR1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RXTSHIFTMAXR1_S)
end_define

begin_define
define|#
directive|define
name|RXTSHIFTMAXR1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> RXTSHIFTMAXR1_S)& RXTSHIFTMAXR1_M)
end_define

begin_define
define|#
directive|define
name|RXTSHIFTMAXR2_S
value|16
end_define

begin_define
define|#
directive|define
name|RXTSHIFTMAXR2_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|RXTSHIFTMAXR2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RXTSHIFTMAXR2_S)
end_define

begin_define
define|#
directive|define
name|RXTSHIFTMAXR2_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> RXTSHIFTMAXR2_S)& RXTSHIFTMAXR2_M)
end_define

begin_define
define|#
directive|define
name|PERSHIFTBACKOFFMAX_S
value|12
end_define

begin_define
define|#
directive|define
name|PERSHIFTBACKOFFMAX_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|PERSHIFTBACKOFFMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PERSHIFTBACKOFFMAX_S)
end_define

begin_define
define|#
directive|define
name|PERSHIFTBACKOFFMAX_G
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> PERSHIFTBACKOFFMAX_S)& PERSHIFTBACKOFFMAX_M)
end_define

begin_define
define|#
directive|define
name|PERSHIFTMAX_S
value|8
end_define

begin_define
define|#
directive|define
name|PERSHIFTMAX_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|PERSHIFTMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PERSHIFTMAX_S)
end_define

begin_define
define|#
directive|define
name|PERSHIFTMAX_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PERSHIFTMAX_S)& PERSHIFTMAX_M)
end_define

begin_define
define|#
directive|define
name|KEEPALIVEMAXR1_S
value|4
end_define

begin_define
define|#
directive|define
name|KEEPALIVEMAXR1_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|KEEPALIVEMAXR1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< KEEPALIVEMAXR1_S)
end_define

begin_define
define|#
directive|define
name|KEEPALIVEMAXR1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> KEEPALIVEMAXR1_S)& KEEPALIVEMAXR1_M)
end_define

begin_define
define|#
directive|define
name|KEEPALIVEMAXR2_S
value|0
end_define

begin_define
define|#
directive|define
name|KEEPALIVEMAXR2_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|KEEPALIVEMAXR2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< KEEPALIVEMAXR2_S)
end_define

begin_define
define|#
directive|define
name|KEEPALIVEMAXR2_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> KEEPALIVEMAXR2_S)& KEEPALIVEMAXR2_M)
end_define

begin_define
define|#
directive|define
name|ROWINDEX_S
value|16
end_define

begin_define
define|#
directive|define
name|ROWINDEX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ROWINDEX_S)
end_define

begin_define
define|#
directive|define
name|TP_CCTRL_TABLE_A
value|0x7ddc
end_define

begin_define
define|#
directive|define
name|TP_MTU_TABLE_A
value|0x7de4
end_define

begin_define
define|#
directive|define
name|MTUINDEX_S
value|24
end_define

begin_define
define|#
directive|define
name|MTUINDEX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MTUINDEX_S)
end_define

begin_define
define|#
directive|define
name|MTUWIDTH_S
value|16
end_define

begin_define
define|#
directive|define
name|MTUWIDTH_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|MTUWIDTH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MTUWIDTH_S)
end_define

begin_define
define|#
directive|define
name|MTUWIDTH_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> MTUWIDTH_S)& MTUWIDTH_M)
end_define

begin_define
define|#
directive|define
name|MTUVALUE_S
value|0
end_define

begin_define
define|#
directive|define
name|MTUVALUE_M
value|0x3fffU
end_define

begin_define
define|#
directive|define
name|MTUVALUE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MTUVALUE_S)
end_define

begin_define
define|#
directive|define
name|MTUVALUE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> MTUVALUE_S)& MTUVALUE_M)
end_define

begin_define
define|#
directive|define
name|TP_RSS_LKP_TABLE_A
value|0x7dec
end_define

begin_define
define|#
directive|define
name|TP_CMM_MM_RX_FLST_BASE_A
value|0x7e60
end_define

begin_define
define|#
directive|define
name|TP_CMM_MM_TX_FLST_BASE_A
value|0x7e64
end_define

begin_define
define|#
directive|define
name|TP_CMM_MM_PS_FLST_BASE_A
value|0x7e68
end_define

begin_define
define|#
directive|define
name|LKPTBLROWVLD_S
value|31
end_define

begin_define
define|#
directive|define
name|LKPTBLROWVLD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< LKPTBLROWVLD_S)
end_define

begin_define
define|#
directive|define
name|LKPTBLROWVLD_F
value|LKPTBLROWVLD_V(1U)
end_define

begin_define
define|#
directive|define
name|LKPTBLQUEUE1_S
value|10
end_define

begin_define
define|#
directive|define
name|LKPTBLQUEUE1_M
value|0x3ffU
end_define

begin_define
define|#
directive|define
name|LKPTBLQUEUE1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> LKPTBLQUEUE1_S)& LKPTBLQUEUE1_M)
end_define

begin_define
define|#
directive|define
name|LKPTBLQUEUE0_S
value|0
end_define

begin_define
define|#
directive|define
name|LKPTBLQUEUE0_M
value|0x3ffU
end_define

begin_define
define|#
directive|define
name|LKPTBLQUEUE0_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> LKPTBLQUEUE0_S)& LKPTBLQUEUE0_M)
end_define

begin_define
define|#
directive|define
name|TP_PIO_ADDR_A
value|0x7e40
end_define

begin_define
define|#
directive|define
name|TP_PIO_DATA_A
value|0x7e44
end_define

begin_define
define|#
directive|define
name|TP_MIB_INDEX_A
value|0x7e50
end_define

begin_define
define|#
directive|define
name|TP_MIB_DATA_A
value|0x7e54
end_define

begin_define
define|#
directive|define
name|TP_INT_CAUSE_A
value|0x7e74
end_define

begin_define
define|#
directive|define
name|FLMTXFLSTEMPTY_S
value|30
end_define

begin_define
define|#
directive|define
name|FLMTXFLSTEMPTY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FLMTXFLSTEMPTY_S)
end_define

begin_define
define|#
directive|define
name|FLMTXFLSTEMPTY_F
value|FLMTXFLSTEMPTY_V(1U)
end_define

begin_define
define|#
directive|define
name|TP_TX_ORATE_A
value|0x7ebc
end_define

begin_define
define|#
directive|define
name|OFDRATE3_S
value|24
end_define

begin_define
define|#
directive|define
name|OFDRATE3_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|OFDRATE3_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> OFDRATE3_S)& OFDRATE3_M)
end_define

begin_define
define|#
directive|define
name|OFDRATE2_S
value|16
end_define

begin_define
define|#
directive|define
name|OFDRATE2_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|OFDRATE2_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> OFDRATE2_S)& OFDRATE2_M)
end_define

begin_define
define|#
directive|define
name|OFDRATE1_S
value|8
end_define

begin_define
define|#
directive|define
name|OFDRATE1_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|OFDRATE1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> OFDRATE1_S)& OFDRATE1_M)
end_define

begin_define
define|#
directive|define
name|OFDRATE0_S
value|0
end_define

begin_define
define|#
directive|define
name|OFDRATE0_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|OFDRATE0_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> OFDRATE0_S)& OFDRATE0_M)
end_define

begin_define
define|#
directive|define
name|TP_TX_TRATE_A
value|0x7ed0
end_define

begin_define
define|#
directive|define
name|TNLRATE3_S
value|24
end_define

begin_define
define|#
directive|define
name|TNLRATE3_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|TNLRATE3_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TNLRATE3_S)& TNLRATE3_M)
end_define

begin_define
define|#
directive|define
name|TNLRATE2_S
value|16
end_define

begin_define
define|#
directive|define
name|TNLRATE2_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|TNLRATE2_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TNLRATE2_S)& TNLRATE2_M)
end_define

begin_define
define|#
directive|define
name|TNLRATE1_S
value|8
end_define

begin_define
define|#
directive|define
name|TNLRATE1_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|TNLRATE1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TNLRATE1_S)& TNLRATE1_M)
end_define

begin_define
define|#
directive|define
name|TNLRATE0_S
value|0
end_define

begin_define
define|#
directive|define
name|TNLRATE0_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|TNLRATE0_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TNLRATE0_S)& TNLRATE0_M)
end_define

begin_define
define|#
directive|define
name|TP_VLAN_PRI_MAP_A
value|0x140
end_define

begin_define
define|#
directive|define
name|FRAGMENTATION_S
value|9
end_define

begin_define
define|#
directive|define
name|FRAGMENTATION_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FRAGMENTATION_S)
end_define

begin_define
define|#
directive|define
name|FRAGMENTATION_F
value|FRAGMENTATION_V(1U)
end_define

begin_define
define|#
directive|define
name|MPSHITTYPE_S
value|8
end_define

begin_define
define|#
directive|define
name|MPSHITTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MPSHITTYPE_S)
end_define

begin_define
define|#
directive|define
name|MPSHITTYPE_F
value|MPSHITTYPE_V(1U)
end_define

begin_define
define|#
directive|define
name|MACMATCH_S
value|7
end_define

begin_define
define|#
directive|define
name|MACMATCH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MACMATCH_S)
end_define

begin_define
define|#
directive|define
name|MACMATCH_F
value|MACMATCH_V(1U)
end_define

begin_define
define|#
directive|define
name|ETHERTYPE_S
value|6
end_define

begin_define
define|#
directive|define
name|ETHERTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ETHERTYPE_S)
end_define

begin_define
define|#
directive|define
name|ETHERTYPE_F
value|ETHERTYPE_V(1U)
end_define

begin_define
define|#
directive|define
name|PROTOCOL_S
value|5
end_define

begin_define
define|#
directive|define
name|PROTOCOL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PROTOCOL_S)
end_define

begin_define
define|#
directive|define
name|PROTOCOL_F
value|PROTOCOL_V(1U)
end_define

begin_define
define|#
directive|define
name|TOS_S
value|4
end_define

begin_define
define|#
directive|define
name|TOS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TOS_S)
end_define

begin_define
define|#
directive|define
name|TOS_F
value|TOS_V(1U)
end_define

begin_define
define|#
directive|define
name|VLAN_S
value|3
end_define

begin_define
define|#
directive|define
name|VLAN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VLAN_S)
end_define

begin_define
define|#
directive|define
name|VLAN_F
value|VLAN_V(1U)
end_define

begin_define
define|#
directive|define
name|VNIC_ID_S
value|2
end_define

begin_define
define|#
directive|define
name|VNIC_ID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VNIC_ID_S)
end_define

begin_define
define|#
directive|define
name|VNIC_ID_F
value|VNIC_ID_V(1U)
end_define

begin_define
define|#
directive|define
name|PORT_S
value|1
end_define

begin_define
define|#
directive|define
name|PORT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PORT_S)
end_define

begin_define
define|#
directive|define
name|PORT_F
value|PORT_V(1U)
end_define

begin_define
define|#
directive|define
name|FCOE_S
value|0
end_define

begin_define
define|#
directive|define
name|FCOE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FCOE_S)
end_define

begin_define
define|#
directive|define
name|FCOE_F
value|FCOE_V(1U)
end_define

begin_define
define|#
directive|define
name|FILTERMODE_S
value|15
end_define

begin_define
define|#
directive|define
name|FILTERMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FILTERMODE_S)
end_define

begin_define
define|#
directive|define
name|FILTERMODE_F
value|FILTERMODE_V(1U)
end_define

begin_define
define|#
directive|define
name|FCOEMASK_S
value|14
end_define

begin_define
define|#
directive|define
name|FCOEMASK_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FCOEMASK_S)
end_define

begin_define
define|#
directive|define
name|FCOEMASK_F
value|FCOEMASK_V(1U)
end_define

begin_define
define|#
directive|define
name|TP_INGRESS_CONFIG_A
value|0x141
end_define

begin_define
define|#
directive|define
name|VNIC_S
value|11
end_define

begin_define
define|#
directive|define
name|VNIC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VNIC_S)
end_define

begin_define
define|#
directive|define
name|VNIC_F
value|VNIC_V(1U)
end_define

begin_define
define|#
directive|define
name|CSUM_HAS_PSEUDO_HDR_S
value|10
end_define

begin_define
define|#
directive|define
name|CSUM_HAS_PSEUDO_HDR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CSUM_HAS_PSEUDO_HDR_S)
end_define

begin_define
define|#
directive|define
name|CSUM_HAS_PSEUDO_HDR_F
value|CSUM_HAS_PSEUDO_HDR_V(1U)
end_define

begin_define
define|#
directive|define
name|TP_MIB_MAC_IN_ERR_0_A
value|0x0
end_define

begin_define
define|#
directive|define
name|TP_MIB_HDR_IN_ERR_0_A
value|0x4
end_define

begin_define
define|#
directive|define
name|TP_MIB_TCP_IN_ERR_0_A
value|0x8
end_define

begin_define
define|#
directive|define
name|TP_MIB_TCP_OUT_RST_A
value|0xc
end_define

begin_define
define|#
directive|define
name|TP_MIB_TCP_IN_SEG_HI_A
value|0x10
end_define

begin_define
define|#
directive|define
name|TP_MIB_TCP_IN_SEG_LO_A
value|0x11
end_define

begin_define
define|#
directive|define
name|TP_MIB_TCP_OUT_SEG_HI_A
value|0x12
end_define

begin_define
define|#
directive|define
name|TP_MIB_TCP_OUT_SEG_LO_A
value|0x13
end_define

begin_define
define|#
directive|define
name|TP_MIB_TCP_RXT_SEG_HI_A
value|0x14
end_define

begin_define
define|#
directive|define
name|TP_MIB_TCP_RXT_SEG_LO_A
value|0x15
end_define

begin_define
define|#
directive|define
name|TP_MIB_TNL_CNG_DROP_0_A
value|0x18
end_define

begin_define
define|#
directive|define
name|TP_MIB_OFD_CHN_DROP_0_A
value|0x1c
end_define

begin_define
define|#
directive|define
name|TP_MIB_TCP_V6IN_ERR_0_A
value|0x28
end_define

begin_define
define|#
directive|define
name|TP_MIB_TCP_V6OUT_RST_A
value|0x2c
end_define

begin_define
define|#
directive|define
name|TP_MIB_OFD_ARP_DROP_A
value|0x36
end_define

begin_define
define|#
directive|define
name|TP_MIB_CPL_IN_REQ_0_A
value|0x38
end_define

begin_define
define|#
directive|define
name|TP_MIB_CPL_OUT_RSP_0_A
value|0x3c
end_define

begin_define
define|#
directive|define
name|TP_MIB_TNL_DROP_0_A
value|0x44
end_define

begin_define
define|#
directive|define
name|TP_MIB_FCOE_DDP_0_A
value|0x48
end_define

begin_define
define|#
directive|define
name|TP_MIB_FCOE_DROP_0_A
value|0x4c
end_define

begin_define
define|#
directive|define
name|TP_MIB_FCOE_BYTE_0_HI_A
value|0x50
end_define

begin_define
define|#
directive|define
name|TP_MIB_OFD_VLN_DROP_0_A
value|0x58
end_define

begin_define
define|#
directive|define
name|TP_MIB_USM_PKTS_A
value|0x5c
end_define

begin_define
define|#
directive|define
name|TP_MIB_RQE_DFR_PKT_A
value|0x64
end_define

begin_define
define|#
directive|define
name|ULP_TX_INT_CAUSE_A
value|0x8dcc
end_define

begin_define
define|#
directive|define
name|ULP_TX_TPT_LLIMIT_A
value|0x8dd4
end_define

begin_define
define|#
directive|define
name|ULP_TX_TPT_ULIMIT_A
value|0x8dd8
end_define

begin_define
define|#
directive|define
name|ULP_TX_PBL_LLIMIT_A
value|0x8ddc
end_define

begin_define
define|#
directive|define
name|ULP_TX_PBL_ULIMIT_A
value|0x8de0
end_define

begin_define
define|#
directive|define
name|ULP_TX_ERR_TABLE_BASE_A
value|0x8e04
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH3_S
value|31
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PBL_BOUND_ERR_CH3_S)
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH3_F
value|PBL_BOUND_ERR_CH3_V(1U)
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH2_S
value|30
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PBL_BOUND_ERR_CH2_S)
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH2_F
value|PBL_BOUND_ERR_CH2_V(1U)
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH1_S
value|29
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PBL_BOUND_ERR_CH1_S)
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH1_F
value|PBL_BOUND_ERR_CH1_V(1U)
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH0_S
value|28
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PBL_BOUND_ERR_CH0_S)
end_define

begin_define
define|#
directive|define
name|PBL_BOUND_ERR_CH0_F
value|PBL_BOUND_ERR_CH0_V(1U)
end_define

begin_define
define|#
directive|define
name|PM_RX_INT_CAUSE_A
value|0x8fdc
end_define

begin_define
define|#
directive|define
name|PM_RX_STAT_CONFIG_A
value|0x8fc8
end_define

begin_define
define|#
directive|define
name|PM_RX_STAT_COUNT_A
value|0x8fcc
end_define

begin_define
define|#
directive|define
name|PM_RX_STAT_LSB_A
value|0x8fd0
end_define

begin_define
define|#
directive|define
name|PM_RX_DBG_CTRL_A
value|0x8fd0
end_define

begin_define
define|#
directive|define
name|PM_RX_DBG_DATA_A
value|0x8fd4
end_define

begin_define
define|#
directive|define
name|PM_RX_DBG_STAT_MSB_A
value|0x10013
end_define

begin_define
define|#
directive|define
name|PMRX_FRAMING_ERROR_F
value|0x003ffff0U
end_define

begin_define
define|#
directive|define
name|ZERO_E_CMD_ERROR_S
value|22
end_define

begin_define
define|#
directive|define
name|ZERO_E_CMD_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ZERO_E_CMD_ERROR_S)
end_define

begin_define
define|#
directive|define
name|ZERO_E_CMD_ERROR_F
value|ZERO_E_CMD_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|OCSPI_PAR_ERROR_S
value|3
end_define

begin_define
define|#
directive|define
name|OCSPI_PAR_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OCSPI_PAR_ERROR_S)
end_define

begin_define
define|#
directive|define
name|OCSPI_PAR_ERROR_F
value|OCSPI_PAR_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|DB_OPTIONS_PAR_ERROR_S
value|2
end_define

begin_define
define|#
directive|define
name|DB_OPTIONS_PAR_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DB_OPTIONS_PAR_ERROR_S)
end_define

begin_define
define|#
directive|define
name|DB_OPTIONS_PAR_ERROR_F
value|DB_OPTIONS_PAR_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|IESPI_PAR_ERROR_S
value|1
end_define

begin_define
define|#
directive|define
name|IESPI_PAR_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IESPI_PAR_ERROR_S)
end_define

begin_define
define|#
directive|define
name|IESPI_PAR_ERROR_F
value|IESPI_PAR_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|PMRX_E_PCMD_PAR_ERROR_S
value|0
end_define

begin_define
define|#
directive|define
name|PMRX_E_PCMD_PAR_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PMRX_E_PCMD_PAR_ERROR_S)
end_define

begin_define
define|#
directive|define
name|PMRX_E_PCMD_PAR_ERROR_F
value|PMRX_E_PCMD_PAR_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|PM_TX_INT_CAUSE_A
value|0x8ffc
end_define

begin_define
define|#
directive|define
name|PM_TX_STAT_CONFIG_A
value|0x8fe8
end_define

begin_define
define|#
directive|define
name|PM_TX_STAT_COUNT_A
value|0x8fec
end_define

begin_define
define|#
directive|define
name|PM_TX_STAT_LSB_A
value|0x8ff0
end_define

begin_define
define|#
directive|define
name|PM_TX_DBG_CTRL_A
value|0x8ff0
end_define

begin_define
define|#
directive|define
name|PM_TX_DBG_DATA_A
value|0x8ff4
end_define

begin_define
define|#
directive|define
name|PM_TX_DBG_STAT_MSB_A
value|0x1001a
end_define

begin_define
define|#
directive|define
name|PCMD_LEN_OVFL0_S
value|31
end_define

begin_define
define|#
directive|define
name|PCMD_LEN_OVFL0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCMD_LEN_OVFL0_S)
end_define

begin_define
define|#
directive|define
name|PCMD_LEN_OVFL0_F
value|PCMD_LEN_OVFL0_V(1U)
end_define

begin_define
define|#
directive|define
name|PCMD_LEN_OVFL1_S
value|30
end_define

begin_define
define|#
directive|define
name|PCMD_LEN_OVFL1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCMD_LEN_OVFL1_S)
end_define

begin_define
define|#
directive|define
name|PCMD_LEN_OVFL1_F
value|PCMD_LEN_OVFL1_V(1U)
end_define

begin_define
define|#
directive|define
name|PCMD_LEN_OVFL2_S
value|29
end_define

begin_define
define|#
directive|define
name|PCMD_LEN_OVFL2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCMD_LEN_OVFL2_S)
end_define

begin_define
define|#
directive|define
name|PCMD_LEN_OVFL2_F
value|PCMD_LEN_OVFL2_V(1U)
end_define

begin_define
define|#
directive|define
name|ZERO_C_CMD_ERROR_S
value|28
end_define

begin_define
define|#
directive|define
name|ZERO_C_CMD_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ZERO_C_CMD_ERROR_S)
end_define

begin_define
define|#
directive|define
name|ZERO_C_CMD_ERROR_F
value|ZERO_C_CMD_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|PMTX_FRAMING_ERROR_F
value|0x0ffffff0U
end_define

begin_define
define|#
directive|define
name|OESPI_PAR_ERROR_S
value|3
end_define

begin_define
define|#
directive|define
name|OESPI_PAR_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OESPI_PAR_ERROR_S)
end_define

begin_define
define|#
directive|define
name|OESPI_PAR_ERROR_F
value|OESPI_PAR_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|ICSPI_PAR_ERROR_S
value|1
end_define

begin_define
define|#
directive|define
name|ICSPI_PAR_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ICSPI_PAR_ERROR_S)
end_define

begin_define
define|#
directive|define
name|ICSPI_PAR_ERROR_F
value|ICSPI_PAR_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|PMTX_C_PCMD_PAR_ERROR_S
value|0
end_define

begin_define
define|#
directive|define
name|PMTX_C_PCMD_PAR_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PMTX_C_PCMD_PAR_ERROR_S)
end_define

begin_define
define|#
directive|define
name|PMTX_C_PCMD_PAR_ERROR_F
value|PMTX_C_PCMD_PAR_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_BYTES_L
value|0x400
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_BYTES_H
value|0x404
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_FRAMES_L
value|0x408
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_FRAMES_H
value|0x40c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_BCAST_L
value|0x410
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_BCAST_H
value|0x414
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_MCAST_L
value|0x418
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_MCAST_H
value|0x41c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_UCAST_L
value|0x420
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_UCAST_H
value|0x424
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_ERROR_L
value|0x428
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_ERROR_H
value|0x42c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_64B_L
value|0x430
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_64B_H
value|0x434
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_65B_127B_L
value|0x438
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_65B_127B_H
value|0x43c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_128B_255B_L
value|0x440
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_128B_255B_H
value|0x444
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_256B_511B_L
value|0x448
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_256B_511B_H
value|0x44c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_512B_1023B_L
value|0x450
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_512B_1023B_H
value|0x454
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_1024B_1518B_L
value|0x458
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_1024B_1518B_H
value|0x45c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_1519B_MAX_L
value|0x460
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_1519B_MAX_H
value|0x464
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_DROP_L
value|0x468
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_DROP_H
value|0x46c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PAUSE_L
value|0x470
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PAUSE_H
value|0x474
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP0_L
value|0x478
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP0_H
value|0x47c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP1_L
value|0x480
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP1_H
value|0x484
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP2_L
value|0x488
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP2_H
value|0x48c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP3_L
value|0x490
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP3_H
value|0x494
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP4_L
value|0x498
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP4_H
value|0x49c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP5_L
value|0x4a0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP5_H
value|0x4a4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP6_L
value|0x4a8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP6_H
value|0x4ac
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP7_L
value|0x4b0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_TX_PORT_PPP7_H
value|0x4b4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_BYTES_L
value|0x4c0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_BYTES_H
value|0x4c4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_FRAMES_L
value|0x4c8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_FRAMES_H
value|0x4cc
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_BCAST_L
value|0x4d0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_BCAST_H
value|0x4d4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_MCAST_L
value|0x4d8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_MCAST_H
value|0x4dc
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_UCAST_L
value|0x4e0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_UCAST_H
value|0x4e4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_ERROR_L
value|0x4e8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_ERROR_H
value|0x4ec
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_64B_L
value|0x4f0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_64B_H
value|0x4f4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_65B_127B_L
value|0x4f8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_65B_127B_H
value|0x4fc
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_128B_255B_L
value|0x500
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_128B_255B_H
value|0x504
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_256B_511B_L
value|0x508
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_256B_511B_H
value|0x50c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_512B_1023B_L
value|0x510
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_512B_1023B_H
value|0x514
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_1024B_1518B_L
value|0x518
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_1024B_1518B_H
value|0x51c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_1519B_MAX_L
value|0x520
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_1519B_MAX_H
value|0x524
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_DROP_FRAMES
value|0x528
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_LB_PORT_DROP_FRAMES_L
value|0x528
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_BYTES_L
value|0x540
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_BYTES_H
value|0x544
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_FRAMES_L
value|0x548
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_FRAMES_H
value|0x54c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_BCAST_L
value|0x550
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_BCAST_H
value|0x554
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_MCAST_L
value|0x558
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_MCAST_H
value|0x55c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_UCAST_L
value|0x560
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_UCAST_H
value|0x564
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_MTU_ERROR_L
value|0x568
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_MTU_ERROR_H
value|0x56c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_MTU_CRC_ERROR_L
value|0x570
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_MTU_CRC_ERROR_H
value|0x574
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_CRC_ERROR_L
value|0x578
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_CRC_ERROR_H
value|0x57c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_LEN_ERROR_L
value|0x580
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_LEN_ERROR_H
value|0x584
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_SYM_ERROR_L
value|0x588
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_SYM_ERROR_H
value|0x58c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_64B_L
value|0x590
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_64B_H
value|0x594
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_65B_127B_L
value|0x598
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_65B_127B_H
value|0x59c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_128B_255B_L
value|0x5a0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_128B_255B_H
value|0x5a4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_256B_511B_L
value|0x5a8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_256B_511B_H
value|0x5ac
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_512B_1023B_L
value|0x5b0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_512B_1023B_H
value|0x5b4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_1024B_1518B_L
value|0x5b8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_1024B_1518B_H
value|0x5bc
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_1519B_MAX_L
value|0x5c0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_1519B_MAX_H
value|0x5c4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PAUSE_L
value|0x5c8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PAUSE_H
value|0x5cc
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP0_L
value|0x5d0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP0_H
value|0x5d4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP1_L
value|0x5d8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP1_H
value|0x5dc
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP2_L
value|0x5e0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP2_H
value|0x5e4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP3_L
value|0x5e8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP3_H
value|0x5ec
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP4_L
value|0x5f0
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP4_H
value|0x5f4
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP5_L
value|0x5f8
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP5_H
value|0x5fc
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP6_L
value|0x600
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP6_H
value|0x604
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP7_L
value|0x608
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_PPP7_H
value|0x60c
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_LESS_64B_L
value|0x610
end_define

begin_define
define|#
directive|define
name|MPS_PORT_STAT_RX_PORT_LESS_64B_H
value|0x614
end_define

begin_define
define|#
directive|define
name|MAC_PORT_MAGIC_MACID_LO
value|0x824
end_define

begin_define
define|#
directive|define
name|MAC_PORT_MAGIC_MACID_HI
value|0x828
end_define

begin_define
define|#
directive|define
name|MAC_PORT_EPIO_DATA0_A
value|0x8c0
end_define

begin_define
define|#
directive|define
name|MAC_PORT_EPIO_DATA1_A
value|0x8c4
end_define

begin_define
define|#
directive|define
name|MAC_PORT_EPIO_DATA2_A
value|0x8c8
end_define

begin_define
define|#
directive|define
name|MAC_PORT_EPIO_DATA3_A
value|0x8cc
end_define

begin_define
define|#
directive|define
name|MAC_PORT_EPIO_OP_A
value|0x8d0
end_define

begin_define
define|#
directive|define
name|MAC_PORT_CFG2_A
value|0x818
end_define

begin_define
define|#
directive|define
name|MPS_CMN_CTL_A
value|0x9000
end_define

begin_define
define|#
directive|define
name|NUMPORTS_S
value|0
end_define

begin_define
define|#
directive|define
name|NUMPORTS_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|NUMPORTS_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> NUMPORTS_S)& NUMPORTS_M)
end_define

begin_define
define|#
directive|define
name|MPS_INT_CAUSE_A
value|0x9008
end_define

begin_define
define|#
directive|define
name|MPS_TX_INT_CAUSE_A
value|0x9408
end_define

begin_define
define|#
directive|define
name|FRMERR_S
value|15
end_define

begin_define
define|#
directive|define
name|FRMERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FRMERR_S)
end_define

begin_define
define|#
directive|define
name|FRMERR_F
value|FRMERR_V(1U)
end_define

begin_define
define|#
directive|define
name|SECNTERR_S
value|14
end_define

begin_define
define|#
directive|define
name|SECNTERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SECNTERR_S)
end_define

begin_define
define|#
directive|define
name|SECNTERR_F
value|SECNTERR_V(1U)
end_define

begin_define
define|#
directive|define
name|BUBBLE_S
value|13
end_define

begin_define
define|#
directive|define
name|BUBBLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BUBBLE_S)
end_define

begin_define
define|#
directive|define
name|BUBBLE_F
value|BUBBLE_V(1U)
end_define

begin_define
define|#
directive|define
name|TXDESCFIFO_S
value|9
end_define

begin_define
define|#
directive|define
name|TXDESCFIFO_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|TXDESCFIFO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TXDESCFIFO_S)
end_define

begin_define
define|#
directive|define
name|TXDATAFIFO_S
value|5
end_define

begin_define
define|#
directive|define
name|TXDATAFIFO_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|TXDATAFIFO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TXDATAFIFO_S)
end_define

begin_define
define|#
directive|define
name|NCSIFIFO_S
value|4
end_define

begin_define
define|#
directive|define
name|NCSIFIFO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< NCSIFIFO_S)
end_define

begin_define
define|#
directive|define
name|NCSIFIFO_F
value|NCSIFIFO_V(1U)
end_define

begin_define
define|#
directive|define
name|TPFIFO_S
value|0
end_define

begin_define
define|#
directive|define
name|TPFIFO_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|TPFIFO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TPFIFO_S)
end_define

begin_define
define|#
directive|define
name|MPS_STAT_PERR_INT_CAUSE_SRAM_A
value|0x9614
end_define

begin_define
define|#
directive|define
name|MPS_STAT_PERR_INT_CAUSE_TX_FIFO_A
value|0x9620
end_define

begin_define
define|#
directive|define
name|MPS_STAT_PERR_INT_CAUSE_RX_FIFO_A
value|0x962c
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_0_MAC_DROP_FRAME_L
value|0x9640
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_0_MAC_DROP_FRAME_H
value|0x9644
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_1_MAC_DROP_FRAME_L
value|0x9648
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_1_MAC_DROP_FRAME_H
value|0x964c
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_2_MAC_DROP_FRAME_L
value|0x9650
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_2_MAC_DROP_FRAME_H
value|0x9654
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_3_MAC_DROP_FRAME_L
value|0x9658
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_3_MAC_DROP_FRAME_H
value|0x965c
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_0_LB_DROP_FRAME_L
value|0x9660
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_0_LB_DROP_FRAME_H
value|0x9664
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_1_LB_DROP_FRAME_L
value|0x9668
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_1_LB_DROP_FRAME_H
value|0x966c
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_2_LB_DROP_FRAME_L
value|0x9670
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_2_LB_DROP_FRAME_H
value|0x9674
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_3_LB_DROP_FRAME_L
value|0x9678
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_3_LB_DROP_FRAME_H
value|0x967c
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_0_MAC_TRUNC_FRAME_L
value|0x9680
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_0_MAC_TRUNC_FRAME_H
value|0x9684
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_1_MAC_TRUNC_FRAME_L
value|0x9688
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_1_MAC_TRUNC_FRAME_H
value|0x968c
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_2_MAC_TRUNC_FRAME_L
value|0x9690
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_2_MAC_TRUNC_FRAME_H
value|0x9694
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_3_MAC_TRUNC_FRAME_L
value|0x9698
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_3_MAC_TRUNC_FRAME_H
value|0x969c
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_0_LB_TRUNC_FRAME_L
value|0x96a0
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_0_LB_TRUNC_FRAME_H
value|0x96a4
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_1_LB_TRUNC_FRAME_L
value|0x96a8
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_1_LB_TRUNC_FRAME_H
value|0x96ac
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_2_LB_TRUNC_FRAME_L
value|0x96b0
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_2_LB_TRUNC_FRAME_H
value|0x96b4
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_3_LB_TRUNC_FRAME_L
value|0x96b8
end_define

begin_define
define|#
directive|define
name|MPS_STAT_RX_BG_3_LB_TRUNC_FRAME_H
value|0x96bc
end_define

begin_define
define|#
directive|define
name|MPS_TRC_CFG_A
value|0x9800
end_define

begin_define
define|#
directive|define
name|TRCFIFOEMPTY_S
value|4
end_define

begin_define
define|#
directive|define
name|TRCFIFOEMPTY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TRCFIFOEMPTY_S)
end_define

begin_define
define|#
directive|define
name|TRCFIFOEMPTY_F
value|TRCFIFOEMPTY_V(1U)
end_define

begin_define
define|#
directive|define
name|TRCIGNOREDROPINPUT_S
value|3
end_define

begin_define
define|#
directive|define
name|TRCIGNOREDROPINPUT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TRCIGNOREDROPINPUT_S)
end_define

begin_define
define|#
directive|define
name|TRCIGNOREDROPINPUT_F
value|TRCIGNOREDROPINPUT_V(1U)
end_define

begin_define
define|#
directive|define
name|TRCKEEPDUPLICATES_S
value|2
end_define

begin_define
define|#
directive|define
name|TRCKEEPDUPLICATES_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TRCKEEPDUPLICATES_S)
end_define

begin_define
define|#
directive|define
name|TRCKEEPDUPLICATES_F
value|TRCKEEPDUPLICATES_V(1U)
end_define

begin_define
define|#
directive|define
name|TRCEN_S
value|1
end_define

begin_define
define|#
directive|define
name|TRCEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TRCEN_S)
end_define

begin_define
define|#
directive|define
name|TRCEN_F
value|TRCEN_V(1U)
end_define

begin_define
define|#
directive|define
name|TRCMULTIFILTER_S
value|0
end_define

begin_define
define|#
directive|define
name|TRCMULTIFILTER_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TRCMULTIFILTER_S)
end_define

begin_define
define|#
directive|define
name|TRCMULTIFILTER_F
value|TRCMULTIFILTER_V(1U)
end_define

begin_define
define|#
directive|define
name|MPS_TRC_RSS_CONTROL_A
value|0x9808
end_define

begin_define
define|#
directive|define
name|MPS_TRC_FILTER1_RSS_CONTROL_A
value|0x9ff4
end_define

begin_define
define|#
directive|define
name|MPS_TRC_FILTER2_RSS_CONTROL_A
value|0x9ffc
end_define

begin_define
define|#
directive|define
name|MPS_TRC_FILTER3_RSS_CONTROL_A
value|0xa004
end_define

begin_define
define|#
directive|define
name|MPS_T5_TRC_RSS_CONTROL_A
value|0xa00c
end_define

begin_define
define|#
directive|define
name|RSSCONTROL_S
value|16
end_define

begin_define
define|#
directive|define
name|RSSCONTROL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RSSCONTROL_S)
end_define

begin_define
define|#
directive|define
name|QUEUENUMBER_S
value|0
end_define

begin_define
define|#
directive|define
name|QUEUENUMBER_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< QUEUENUMBER_S)
end_define

begin_define
define|#
directive|define
name|TFINVERTMATCH_S
value|24
end_define

begin_define
define|#
directive|define
name|TFINVERTMATCH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TFINVERTMATCH_S)
end_define

begin_define
define|#
directive|define
name|TFINVERTMATCH_F
value|TFINVERTMATCH_V(1U)
end_define

begin_define
define|#
directive|define
name|TFEN_S
value|22
end_define

begin_define
define|#
directive|define
name|TFEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TFEN_S)
end_define

begin_define
define|#
directive|define
name|TFEN_F
value|TFEN_V(1U)
end_define

begin_define
define|#
directive|define
name|TFPORT_S
value|18
end_define

begin_define
define|#
directive|define
name|TFPORT_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|TFPORT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TFPORT_S)
end_define

begin_define
define|#
directive|define
name|TFPORT_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TFPORT_S)& TFPORT_M)
end_define

begin_define
define|#
directive|define
name|TFLENGTH_S
value|8
end_define

begin_define
define|#
directive|define
name|TFLENGTH_M
value|0x1fU
end_define

begin_define
define|#
directive|define
name|TFLENGTH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TFLENGTH_S)
end_define

begin_define
define|#
directive|define
name|TFLENGTH_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TFLENGTH_S)& TFLENGTH_M)
end_define

begin_define
define|#
directive|define
name|TFOFFSET_S
value|0
end_define

begin_define
define|#
directive|define
name|TFOFFSET_M
value|0x1fU
end_define

begin_define
define|#
directive|define
name|TFOFFSET_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TFOFFSET_S)
end_define

begin_define
define|#
directive|define
name|TFOFFSET_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TFOFFSET_S)& TFOFFSET_M)
end_define

begin_define
define|#
directive|define
name|T5_TFINVERTMATCH_S
value|25
end_define

begin_define
define|#
directive|define
name|T5_TFINVERTMATCH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T5_TFINVERTMATCH_S)
end_define

begin_define
define|#
directive|define
name|T5_TFINVERTMATCH_F
value|T5_TFINVERTMATCH_V(1U)
end_define

begin_define
define|#
directive|define
name|T5_TFEN_S
value|23
end_define

begin_define
define|#
directive|define
name|T5_TFEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T5_TFEN_S)
end_define

begin_define
define|#
directive|define
name|T5_TFEN_F
value|T5_TFEN_V(1U)
end_define

begin_define
define|#
directive|define
name|T5_TFPORT_S
value|18
end_define

begin_define
define|#
directive|define
name|T5_TFPORT_M
value|0x1fU
end_define

begin_define
define|#
directive|define
name|T5_TFPORT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T5_TFPORT_S)
end_define

begin_define
define|#
directive|define
name|T5_TFPORT_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T5_TFPORT_S)& T5_TFPORT_M)
end_define

begin_define
define|#
directive|define
name|MPS_TRC_FILTER_MATCH_CTL_A_A
value|0x9810
end_define

begin_define
define|#
directive|define
name|MPS_TRC_FILTER_MATCH_CTL_B_A
value|0x9820
end_define

begin_define
define|#
directive|define
name|TFMINPKTSIZE_S
value|16
end_define

begin_define
define|#
directive|define
name|TFMINPKTSIZE_M
value|0x1ffU
end_define

begin_define
define|#
directive|define
name|TFMINPKTSIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TFMINPKTSIZE_S)
end_define

begin_define
define|#
directive|define
name|TFMINPKTSIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TFMINPKTSIZE_S)& TFMINPKTSIZE_M)
end_define

begin_define
define|#
directive|define
name|TFCAPTUREMAX_S
value|0
end_define

begin_define
define|#
directive|define
name|TFCAPTUREMAX_M
value|0x3fffU
end_define

begin_define
define|#
directive|define
name|TFCAPTUREMAX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TFCAPTUREMAX_S)
end_define

begin_define
define|#
directive|define
name|TFCAPTUREMAX_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> TFCAPTUREMAX_S)& TFCAPTUREMAX_M)
end_define

begin_define
define|#
directive|define
name|MPS_TRC_FILTER0_MATCH_A
value|0x9c00
end_define

begin_define
define|#
directive|define
name|MPS_TRC_FILTER0_DONT_CARE_A
value|0x9c80
end_define

begin_define
define|#
directive|define
name|MPS_TRC_FILTER1_MATCH_A
value|0x9d00
end_define

begin_define
define|#
directive|define
name|TP_RSS_CONFIG_A
value|0x7df0
end_define

begin_define
define|#
directive|define
name|TNL4TUPENIPV6_S
value|31
end_define

begin_define
define|#
directive|define
name|TNL4TUPENIPV6_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TNL4TUPENIPV6_S)
end_define

begin_define
define|#
directive|define
name|TNL4TUPENIPV6_F
value|TNL4TUPENIPV6_V(1U)
end_define

begin_define
define|#
directive|define
name|TNL2TUPENIPV6_S
value|30
end_define

begin_define
define|#
directive|define
name|TNL2TUPENIPV6_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TNL2TUPENIPV6_S)
end_define

begin_define
define|#
directive|define
name|TNL2TUPENIPV6_F
value|TNL2TUPENIPV6_V(1U)
end_define

begin_define
define|#
directive|define
name|TNL4TUPENIPV4_S
value|29
end_define

begin_define
define|#
directive|define
name|TNL4TUPENIPV4_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TNL4TUPENIPV4_S)
end_define

begin_define
define|#
directive|define
name|TNL4TUPENIPV4_F
value|TNL4TUPENIPV4_V(1U)
end_define

begin_define
define|#
directive|define
name|TNL2TUPENIPV4_S
value|28
end_define

begin_define
define|#
directive|define
name|TNL2TUPENIPV4_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TNL2TUPENIPV4_S)
end_define

begin_define
define|#
directive|define
name|TNL2TUPENIPV4_F
value|TNL2TUPENIPV4_V(1U)
end_define

begin_define
define|#
directive|define
name|TNLTCPSEL_S
value|27
end_define

begin_define
define|#
directive|define
name|TNLTCPSEL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TNLTCPSEL_S)
end_define

begin_define
define|#
directive|define
name|TNLTCPSEL_F
value|TNLTCPSEL_V(1U)
end_define

begin_define
define|#
directive|define
name|TNLIP6SEL_S
value|26
end_define

begin_define
define|#
directive|define
name|TNLIP6SEL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TNLIP6SEL_S)
end_define

begin_define
define|#
directive|define
name|TNLIP6SEL_F
value|TNLIP6SEL_V(1U)
end_define

begin_define
define|#
directive|define
name|TNLVRTSEL_S
value|25
end_define

begin_define
define|#
directive|define
name|TNLVRTSEL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TNLVRTSEL_S)
end_define

begin_define
define|#
directive|define
name|TNLVRTSEL_F
value|TNLVRTSEL_V(1U)
end_define

begin_define
define|#
directive|define
name|TNLMAPEN_S
value|24
end_define

begin_define
define|#
directive|define
name|TNLMAPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TNLMAPEN_S)
end_define

begin_define
define|#
directive|define
name|TNLMAPEN_F
value|TNLMAPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|OFDHASHSAVE_S
value|19
end_define

begin_define
define|#
directive|define
name|OFDHASHSAVE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OFDHASHSAVE_S)
end_define

begin_define
define|#
directive|define
name|OFDHASHSAVE_F
value|OFDHASHSAVE_V(1U)
end_define

begin_define
define|#
directive|define
name|OFDVRTSEL_S
value|18
end_define

begin_define
define|#
directive|define
name|OFDVRTSEL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OFDVRTSEL_S)
end_define

begin_define
define|#
directive|define
name|OFDVRTSEL_F
value|OFDVRTSEL_V(1U)
end_define

begin_define
define|#
directive|define
name|OFDMAPEN_S
value|17
end_define

begin_define
define|#
directive|define
name|OFDMAPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OFDMAPEN_S)
end_define

begin_define
define|#
directive|define
name|OFDMAPEN_F
value|OFDMAPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|OFDLKPEN_S
value|16
end_define

begin_define
define|#
directive|define
name|OFDLKPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OFDLKPEN_S)
end_define

begin_define
define|#
directive|define
name|OFDLKPEN_F
value|OFDLKPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|SYN4TUPENIPV6_S
value|15
end_define

begin_define
define|#
directive|define
name|SYN4TUPENIPV6_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SYN4TUPENIPV6_S)
end_define

begin_define
define|#
directive|define
name|SYN4TUPENIPV6_F
value|SYN4TUPENIPV6_V(1U)
end_define

begin_define
define|#
directive|define
name|SYN2TUPENIPV6_S
value|14
end_define

begin_define
define|#
directive|define
name|SYN2TUPENIPV6_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SYN2TUPENIPV6_S)
end_define

begin_define
define|#
directive|define
name|SYN2TUPENIPV6_F
value|SYN2TUPENIPV6_V(1U)
end_define

begin_define
define|#
directive|define
name|SYN4TUPENIPV4_S
value|13
end_define

begin_define
define|#
directive|define
name|SYN4TUPENIPV4_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SYN4TUPENIPV4_S)
end_define

begin_define
define|#
directive|define
name|SYN4TUPENIPV4_F
value|SYN4TUPENIPV4_V(1U)
end_define

begin_define
define|#
directive|define
name|SYN2TUPENIPV4_S
value|12
end_define

begin_define
define|#
directive|define
name|SYN2TUPENIPV4_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SYN2TUPENIPV4_S)
end_define

begin_define
define|#
directive|define
name|SYN2TUPENIPV4_F
value|SYN2TUPENIPV4_V(1U)
end_define

begin_define
define|#
directive|define
name|SYNIP6SEL_S
value|11
end_define

begin_define
define|#
directive|define
name|SYNIP6SEL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SYNIP6SEL_S)
end_define

begin_define
define|#
directive|define
name|SYNIP6SEL_F
value|SYNIP6SEL_V(1U)
end_define

begin_define
define|#
directive|define
name|SYNVRTSEL_S
value|10
end_define

begin_define
define|#
directive|define
name|SYNVRTSEL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SYNVRTSEL_S)
end_define

begin_define
define|#
directive|define
name|SYNVRTSEL_F
value|SYNVRTSEL_V(1U)
end_define

begin_define
define|#
directive|define
name|SYNMAPEN_S
value|9
end_define

begin_define
define|#
directive|define
name|SYNMAPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SYNMAPEN_S)
end_define

begin_define
define|#
directive|define
name|SYNMAPEN_F
value|SYNMAPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|SYNLKPEN_S
value|8
end_define

begin_define
define|#
directive|define
name|SYNLKPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SYNLKPEN_S)
end_define

begin_define
define|#
directive|define
name|SYNLKPEN_F
value|SYNLKPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|CHANNELENABLE_S
value|7
end_define

begin_define
define|#
directive|define
name|CHANNELENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CHANNELENABLE_S)
end_define

begin_define
define|#
directive|define
name|CHANNELENABLE_F
value|CHANNELENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|PORTENABLE_S
value|6
end_define

begin_define
define|#
directive|define
name|PORTENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PORTENABLE_S)
end_define

begin_define
define|#
directive|define
name|PORTENABLE_F
value|PORTENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|TNLALLLOOKUP_S
value|5
end_define

begin_define
define|#
directive|define
name|TNLALLLOOKUP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TNLALLLOOKUP_S)
end_define

begin_define
define|#
directive|define
name|TNLALLLOOKUP_F
value|TNLALLLOOKUP_V(1U)
end_define

begin_define
define|#
directive|define
name|VIRTENABLE_S
value|4
end_define

begin_define
define|#
directive|define
name|VIRTENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VIRTENABLE_S)
end_define

begin_define
define|#
directive|define
name|VIRTENABLE_F
value|VIRTENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|CONGESTIONENABLE_S
value|3
end_define

begin_define
define|#
directive|define
name|CONGESTIONENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CONGESTIONENABLE_S)
end_define

begin_define
define|#
directive|define
name|CONGESTIONENABLE_F
value|CONGESTIONENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|HASHTOEPLITZ_S
value|2
end_define

begin_define
define|#
directive|define
name|HASHTOEPLITZ_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HASHTOEPLITZ_S)
end_define

begin_define
define|#
directive|define
name|HASHTOEPLITZ_F
value|HASHTOEPLITZ_V(1U)
end_define

begin_define
define|#
directive|define
name|UDPENABLE_S
value|1
end_define

begin_define
define|#
directive|define
name|UDPENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UDPENABLE_S)
end_define

begin_define
define|#
directive|define
name|UDPENABLE_F
value|UDPENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|DISABLE_S
value|0
end_define

begin_define
define|#
directive|define
name|DISABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DISABLE_S)
end_define

begin_define
define|#
directive|define
name|DISABLE_F
value|DISABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|TP_RSS_CONFIG_TNL_A
value|0x7df4
end_define

begin_define
define|#
directive|define
name|MASKSIZE_S
value|28
end_define

begin_define
define|#
directive|define
name|MASKSIZE_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|MASKSIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MASKSIZE_S)
end_define

begin_define
define|#
directive|define
name|MASKSIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> MASKSIZE_S)& MASKSIZE_M)
end_define

begin_define
define|#
directive|define
name|MASKFILTER_S
value|16
end_define

begin_define
define|#
directive|define
name|MASKFILTER_M
value|0x7ffU
end_define

begin_define
define|#
directive|define
name|MASKFILTER_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MASKFILTER_S)
end_define

begin_define
define|#
directive|define
name|MASKFILTER_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> MASKFILTER_S)& MASKFILTER_M)
end_define

begin_define
define|#
directive|define
name|USEWIRECH_S
value|0
end_define

begin_define
define|#
directive|define
name|USEWIRECH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< USEWIRECH_S)
end_define

begin_define
define|#
directive|define
name|USEWIRECH_F
value|USEWIRECH_V(1U)
end_define

begin_define
define|#
directive|define
name|HASHALL_S
value|2
end_define

begin_define
define|#
directive|define
name|HASHALL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HASHALL_S)
end_define

begin_define
define|#
directive|define
name|HASHALL_F
value|HASHALL_V(1U)
end_define

begin_define
define|#
directive|define
name|HASHETH_S
value|1
end_define

begin_define
define|#
directive|define
name|HASHETH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HASHETH_S)
end_define

begin_define
define|#
directive|define
name|HASHETH_F
value|HASHETH_V(1U)
end_define

begin_define
define|#
directive|define
name|TP_RSS_CONFIG_OFD_A
value|0x7df8
end_define

begin_define
define|#
directive|define
name|RRCPLMAPEN_S
value|20
end_define

begin_define
define|#
directive|define
name|RRCPLMAPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RRCPLMAPEN_S)
end_define

begin_define
define|#
directive|define
name|RRCPLMAPEN_F
value|RRCPLMAPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|RRCPLQUEWIDTH_S
value|16
end_define

begin_define
define|#
directive|define
name|RRCPLQUEWIDTH_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|RRCPLQUEWIDTH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RRCPLQUEWIDTH_S)
end_define

begin_define
define|#
directive|define
name|RRCPLQUEWIDTH_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> RRCPLQUEWIDTH_S)& RRCPLQUEWIDTH_M)
end_define

begin_define
define|#
directive|define
name|TP_RSS_CONFIG_SYN_A
value|0x7dfc
end_define

begin_define
define|#
directive|define
name|TP_RSS_CONFIG_VRT_A
value|0x7e00
end_define

begin_define
define|#
directive|define
name|VFRDRG_S
value|25
end_define

begin_define
define|#
directive|define
name|VFRDRG_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFRDRG_S)
end_define

begin_define
define|#
directive|define
name|VFRDRG_F
value|VFRDRG_V(1U)
end_define

begin_define
define|#
directive|define
name|VFRDEN_S
value|24
end_define

begin_define
define|#
directive|define
name|VFRDEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFRDEN_S)
end_define

begin_define
define|#
directive|define
name|VFRDEN_F
value|VFRDEN_V(1U)
end_define

begin_define
define|#
directive|define
name|VFPERREN_S
value|23
end_define

begin_define
define|#
directive|define
name|VFPERREN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFPERREN_S)
end_define

begin_define
define|#
directive|define
name|VFPERREN_F
value|VFPERREN_V(1U)
end_define

begin_define
define|#
directive|define
name|KEYPERREN_S
value|22
end_define

begin_define
define|#
directive|define
name|KEYPERREN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< KEYPERREN_S)
end_define

begin_define
define|#
directive|define
name|KEYPERREN_F
value|KEYPERREN_V(1U)
end_define

begin_define
define|#
directive|define
name|DISABLEVLAN_S
value|21
end_define

begin_define
define|#
directive|define
name|DISABLEVLAN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DISABLEVLAN_S)
end_define

begin_define
define|#
directive|define
name|DISABLEVLAN_F
value|DISABLEVLAN_V(1U)
end_define

begin_define
define|#
directive|define
name|ENABLEUP0_S
value|20
end_define

begin_define
define|#
directive|define
name|ENABLEUP0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ENABLEUP0_S)
end_define

begin_define
define|#
directive|define
name|ENABLEUP0_F
value|ENABLEUP0_V(1U)
end_define

begin_define
define|#
directive|define
name|HASHDELAY_S
value|16
end_define

begin_define
define|#
directive|define
name|HASHDELAY_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|HASHDELAY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HASHDELAY_S)
end_define

begin_define
define|#
directive|define
name|HASHDELAY_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> HASHDELAY_S)& HASHDELAY_M)
end_define

begin_define
define|#
directive|define
name|VFWRADDR_S
value|8
end_define

begin_define
define|#
directive|define
name|VFWRADDR_M
value|0x7fU
end_define

begin_define
define|#
directive|define
name|VFWRADDR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFWRADDR_S)
end_define

begin_define
define|#
directive|define
name|VFWRADDR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> VFWRADDR_S)& VFWRADDR_M)
end_define

begin_define
define|#
directive|define
name|KEYMODE_S
value|6
end_define

begin_define
define|#
directive|define
name|KEYMODE_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|KEYMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< KEYMODE_S)
end_define

begin_define
define|#
directive|define
name|KEYMODE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> KEYMODE_S)& KEYMODE_M)
end_define

begin_define
define|#
directive|define
name|VFWREN_S
value|5
end_define

begin_define
define|#
directive|define
name|VFWREN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFWREN_S)
end_define

begin_define
define|#
directive|define
name|VFWREN_F
value|VFWREN_V(1U)
end_define

begin_define
define|#
directive|define
name|KEYWREN_S
value|4
end_define

begin_define
define|#
directive|define
name|KEYWREN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< KEYWREN_S)
end_define

begin_define
define|#
directive|define
name|KEYWREN_F
value|KEYWREN_V(1U)
end_define

begin_define
define|#
directive|define
name|KEYWRADDR_S
value|0
end_define

begin_define
define|#
directive|define
name|KEYWRADDR_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|KEYWRADDR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< KEYWRADDR_S)
end_define

begin_define
define|#
directive|define
name|KEYWRADDR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> KEYWRADDR_S)& KEYWRADDR_M)
end_define

begin_define
define|#
directive|define
name|KEYWRADDRX_S
value|30
end_define

begin_define
define|#
directive|define
name|KEYWRADDRX_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|KEYWRADDRX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< KEYWRADDRX_S)
end_define

begin_define
define|#
directive|define
name|KEYWRADDRX_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> KEYWRADDRX_S)& KEYWRADDRX_M)
end_define

begin_define
define|#
directive|define
name|KEYEXTEND_S
value|26
end_define

begin_define
define|#
directive|define
name|KEYEXTEND_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< KEYEXTEND_S)
end_define

begin_define
define|#
directive|define
name|KEYEXTEND_F
value|KEYEXTEND_V(1U)
end_define

begin_define
define|#
directive|define
name|LKPIDXSIZE_S
value|24
end_define

begin_define
define|#
directive|define
name|LKPIDXSIZE_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|LKPIDXSIZE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< LKPIDXSIZE_S)
end_define

begin_define
define|#
directive|define
name|LKPIDXSIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> LKPIDXSIZE_S)& LKPIDXSIZE_M)
end_define

begin_define
define|#
directive|define
name|TP_RSS_VFL_CONFIG_A
value|0x3a
end_define

begin_define
define|#
directive|define
name|TP_RSS_VFH_CONFIG_A
value|0x3b
end_define

begin_define
define|#
directive|define
name|ENABLEUDPHASH_S
value|31
end_define

begin_define
define|#
directive|define
name|ENABLEUDPHASH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ENABLEUDPHASH_S)
end_define

begin_define
define|#
directive|define
name|ENABLEUDPHASH_F
value|ENABLEUDPHASH_V(1U)
end_define

begin_define
define|#
directive|define
name|VFUPEN_S
value|30
end_define

begin_define
define|#
directive|define
name|VFUPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFUPEN_S)
end_define

begin_define
define|#
directive|define
name|VFUPEN_F
value|VFUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|VFVLNEX_S
value|28
end_define

begin_define
define|#
directive|define
name|VFVLNEX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFVLNEX_S)
end_define

begin_define
define|#
directive|define
name|VFVLNEX_F
value|VFVLNEX_V(1U)
end_define

begin_define
define|#
directive|define
name|VFPRTEN_S
value|27
end_define

begin_define
define|#
directive|define
name|VFPRTEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFPRTEN_S)
end_define

begin_define
define|#
directive|define
name|VFPRTEN_F
value|VFPRTEN_V(1U)
end_define

begin_define
define|#
directive|define
name|VFCHNEN_S
value|26
end_define

begin_define
define|#
directive|define
name|VFCHNEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFCHNEN_S)
end_define

begin_define
define|#
directive|define
name|VFCHNEN_F
value|VFCHNEN_V(1U)
end_define

begin_define
define|#
directive|define
name|DEFAULTQUEUE_S
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULTQUEUE_M
value|0x3ffU
end_define

begin_define
define|#
directive|define
name|DEFAULTQUEUE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> DEFAULTQUEUE_S)& DEFAULTQUEUE_M)
end_define

begin_define
define|#
directive|define
name|VFIP6TWOTUPEN_S
value|6
end_define

begin_define
define|#
directive|define
name|VFIP6TWOTUPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFIP6TWOTUPEN_S)
end_define

begin_define
define|#
directive|define
name|VFIP6TWOTUPEN_F
value|VFIP6TWOTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|VFIP4FOURTUPEN_S
value|5
end_define

begin_define
define|#
directive|define
name|VFIP4FOURTUPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFIP4FOURTUPEN_S)
end_define

begin_define
define|#
directive|define
name|VFIP4FOURTUPEN_F
value|VFIP4FOURTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|VFIP4TWOTUPEN_S
value|4
end_define

begin_define
define|#
directive|define
name|VFIP4TWOTUPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VFIP4TWOTUPEN_S)
end_define

begin_define
define|#
directive|define
name|VFIP4TWOTUPEN_F
value|VFIP4TWOTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|KEYINDEX_S
value|0
end_define

begin_define
define|#
directive|define
name|KEYINDEX_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|KEYINDEX_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> KEYINDEX_S)& KEYINDEX_M)
end_define

begin_define
define|#
directive|define
name|MAPENABLE_S
value|31
end_define

begin_define
define|#
directive|define
name|MAPENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MAPENABLE_S)
end_define

begin_define
define|#
directive|define
name|MAPENABLE_F
value|MAPENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|CHNENABLE_S
value|30
end_define

begin_define
define|#
directive|define
name|CHNENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CHNENABLE_S)
end_define

begin_define
define|#
directive|define
name|CHNENABLE_F
value|CHNENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|PRTENABLE_S
value|29
end_define

begin_define
define|#
directive|define
name|PRTENABLE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PRTENABLE_S)
end_define

begin_define
define|#
directive|define
name|PRTENABLE_F
value|PRTENABLE_V(1U)
end_define

begin_define
define|#
directive|define
name|UDPFOURTUPEN_S
value|28
end_define

begin_define
define|#
directive|define
name|UDPFOURTUPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UDPFOURTUPEN_S)
end_define

begin_define
define|#
directive|define
name|UDPFOURTUPEN_F
value|UDPFOURTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|IP6FOURTUPEN_S
value|27
end_define

begin_define
define|#
directive|define
name|IP6FOURTUPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IP6FOURTUPEN_S)
end_define

begin_define
define|#
directive|define
name|IP6FOURTUPEN_F
value|IP6FOURTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|IP6TWOTUPEN_S
value|26
end_define

begin_define
define|#
directive|define
name|IP6TWOTUPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IP6TWOTUPEN_S)
end_define

begin_define
define|#
directive|define
name|IP6TWOTUPEN_F
value|IP6TWOTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|IP4FOURTUPEN_S
value|25
end_define

begin_define
define|#
directive|define
name|IP4FOURTUPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IP4FOURTUPEN_S)
end_define

begin_define
define|#
directive|define
name|IP4FOURTUPEN_F
value|IP4FOURTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|IP4TWOTUPEN_S
value|24
end_define

begin_define
define|#
directive|define
name|IP4TWOTUPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IP4TWOTUPEN_S)
end_define

begin_define
define|#
directive|define
name|IP4TWOTUPEN_F
value|IP4TWOTUPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|IVFWIDTH_S
value|20
end_define

begin_define
define|#
directive|define
name|IVFWIDTH_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|IVFWIDTH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IVFWIDTH_S)
end_define

begin_define
define|#
directive|define
name|IVFWIDTH_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> IVFWIDTH_S)& IVFWIDTH_M)
end_define

begin_define
define|#
directive|define
name|CH1DEFAULTQUEUE_S
value|10
end_define

begin_define
define|#
directive|define
name|CH1DEFAULTQUEUE_M
value|0x3ffU
end_define

begin_define
define|#
directive|define
name|CH1DEFAULTQUEUE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CH1DEFAULTQUEUE_S)
end_define

begin_define
define|#
directive|define
name|CH1DEFAULTQUEUE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> CH1DEFAULTQUEUE_S)& CH1DEFAULTQUEUE_M)
end_define

begin_define
define|#
directive|define
name|CH0DEFAULTQUEUE_S
value|0
end_define

begin_define
define|#
directive|define
name|CH0DEFAULTQUEUE_M
value|0x3ffU
end_define

begin_define
define|#
directive|define
name|CH0DEFAULTQUEUE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CH0DEFAULTQUEUE_S)
end_define

begin_define
define|#
directive|define
name|CH0DEFAULTQUEUE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> CH0DEFAULTQUEUE_S)& CH0DEFAULTQUEUE_M)
end_define

begin_define
define|#
directive|define
name|VFLKPIDX_S
value|8
end_define

begin_define
define|#
directive|define
name|VFLKPIDX_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|VFLKPIDX_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> VFLKPIDX_S)& VFLKPIDX_M)
end_define

begin_define
define|#
directive|define
name|T6_VFWRADDR_S
value|8
end_define

begin_define
define|#
directive|define
name|T6_VFWRADDR_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|T6_VFWRADDR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T6_VFWRADDR_S)
end_define

begin_define
define|#
directive|define
name|T6_VFWRADDR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T6_VFWRADDR_S)& T6_VFWRADDR_M)
end_define

begin_define
define|#
directive|define
name|TP_RSS_CONFIG_CNG_A
value|0x7e04
end_define

begin_define
define|#
directive|define
name|TP_RSS_SECRET_KEY0_A
value|0x40
end_define

begin_define
define|#
directive|define
name|TP_RSS_PF0_CONFIG_A
value|0x30
end_define

begin_define
define|#
directive|define
name|TP_RSS_PF_MAP_A
value|0x38
end_define

begin_define
define|#
directive|define
name|TP_RSS_PF_MSK_A
value|0x39
end_define

begin_define
define|#
directive|define
name|PF1LKPIDX_S
value|3
end_define

begin_define
define|#
directive|define
name|PF0LKPIDX_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|PF1MSKSIZE_S
value|4
end_define

begin_define
define|#
directive|define
name|PF1MSKSIZE_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|CHNCOUNT3_S
value|31
end_define

begin_define
define|#
directive|define
name|CHNCOUNT3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CHNCOUNT3_S)
end_define

begin_define
define|#
directive|define
name|CHNCOUNT3_F
value|CHNCOUNT3_V(1U)
end_define

begin_define
define|#
directive|define
name|CHNCOUNT2_S
value|30
end_define

begin_define
define|#
directive|define
name|CHNCOUNT2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CHNCOUNT2_S)
end_define

begin_define
define|#
directive|define
name|CHNCOUNT2_F
value|CHNCOUNT2_V(1U)
end_define

begin_define
define|#
directive|define
name|CHNCOUNT1_S
value|29
end_define

begin_define
define|#
directive|define
name|CHNCOUNT1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CHNCOUNT1_S)
end_define

begin_define
define|#
directive|define
name|CHNCOUNT1_F
value|CHNCOUNT1_V(1U)
end_define

begin_define
define|#
directive|define
name|CHNCOUNT0_S
value|28
end_define

begin_define
define|#
directive|define
name|CHNCOUNT0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CHNCOUNT0_S)
end_define

begin_define
define|#
directive|define
name|CHNCOUNT0_F
value|CHNCOUNT0_V(1U)
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW3_S
value|27
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CHNUNDFLOW3_S)
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW3_F
value|CHNUNDFLOW3_V(1U)
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW2_S
value|26
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CHNUNDFLOW2_S)
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW2_F
value|CHNUNDFLOW2_V(1U)
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW1_S
value|25
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CHNUNDFLOW1_S)
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW1_F
value|CHNUNDFLOW1_V(1U)
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW0_S
value|24
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CHNUNDFLOW0_S)
end_define

begin_define
define|#
directive|define
name|CHNUNDFLOW0_F
value|CHNUNDFLOW0_V(1U)
end_define

begin_define
define|#
directive|define
name|RSTCHN3_S
value|19
end_define

begin_define
define|#
directive|define
name|RSTCHN3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RSTCHN3_S)
end_define

begin_define
define|#
directive|define
name|RSTCHN3_F
value|RSTCHN3_V(1U)
end_define

begin_define
define|#
directive|define
name|RSTCHN2_S
value|18
end_define

begin_define
define|#
directive|define
name|RSTCHN2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RSTCHN2_S)
end_define

begin_define
define|#
directive|define
name|RSTCHN2_F
value|RSTCHN2_V(1U)
end_define

begin_define
define|#
directive|define
name|RSTCHN1_S
value|17
end_define

begin_define
define|#
directive|define
name|RSTCHN1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RSTCHN1_S)
end_define

begin_define
define|#
directive|define
name|RSTCHN1_F
value|RSTCHN1_V(1U)
end_define

begin_define
define|#
directive|define
name|RSTCHN0_S
value|16
end_define

begin_define
define|#
directive|define
name|RSTCHN0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RSTCHN0_S)
end_define

begin_define
define|#
directive|define
name|RSTCHN0_F
value|RSTCHN0_V(1U)
end_define

begin_define
define|#
directive|define
name|UPDVLD_S
value|15
end_define

begin_define
define|#
directive|define
name|UPDVLD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPDVLD_S)
end_define

begin_define
define|#
directive|define
name|UPDVLD_F
value|UPDVLD_V(1U)
end_define

begin_define
define|#
directive|define
name|XOFF_S
value|14
end_define

begin_define
define|#
directive|define
name|XOFF_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< XOFF_S)
end_define

begin_define
define|#
directive|define
name|XOFF_F
value|XOFF_V(1U)
end_define

begin_define
define|#
directive|define
name|UPDCHN3_S
value|13
end_define

begin_define
define|#
directive|define
name|UPDCHN3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPDCHN3_S)
end_define

begin_define
define|#
directive|define
name|UPDCHN3_F
value|UPDCHN3_V(1U)
end_define

begin_define
define|#
directive|define
name|UPDCHN2_S
value|12
end_define

begin_define
define|#
directive|define
name|UPDCHN2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPDCHN2_S)
end_define

begin_define
define|#
directive|define
name|UPDCHN2_F
value|UPDCHN2_V(1U)
end_define

begin_define
define|#
directive|define
name|UPDCHN1_S
value|11
end_define

begin_define
define|#
directive|define
name|UPDCHN1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPDCHN1_S)
end_define

begin_define
define|#
directive|define
name|UPDCHN1_F
value|UPDCHN1_V(1U)
end_define

begin_define
define|#
directive|define
name|UPDCHN0_S
value|10
end_define

begin_define
define|#
directive|define
name|UPDCHN0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPDCHN0_S)
end_define

begin_define
define|#
directive|define
name|UPDCHN0_F
value|UPDCHN0_V(1U)
end_define

begin_define
define|#
directive|define
name|QUEUE_S
value|0
end_define

begin_define
define|#
directive|define
name|QUEUE_M
value|0x3ffU
end_define

begin_define
define|#
directive|define
name|QUEUE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< QUEUE_S)
end_define

begin_define
define|#
directive|define
name|QUEUE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> QUEUE_S)& QUEUE_M)
end_define

begin_define
define|#
directive|define
name|MPS_TRC_INT_CAUSE_A
value|0x985c
end_define

begin_define
define|#
directive|define
name|MISCPERR_S
value|8
end_define

begin_define
define|#
directive|define
name|MISCPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MISCPERR_S)
end_define

begin_define
define|#
directive|define
name|MISCPERR_F
value|MISCPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|PKTFIFO_S
value|4
end_define

begin_define
define|#
directive|define
name|PKTFIFO_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|PKTFIFO_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PKTFIFO_S)
end_define

begin_define
define|#
directive|define
name|FILTMEM_S
value|0
end_define

begin_define
define|#
directive|define
name|FILTMEM_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|FILTMEM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FILTMEM_S)
end_define

begin_define
define|#
directive|define
name|MPS_CLS_INT_CAUSE_A
value|0xd028
end_define

begin_define
define|#
directive|define
name|HASHSRAM_S
value|2
end_define

begin_define
define|#
directive|define
name|HASHSRAM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HASHSRAM_S)
end_define

begin_define
define|#
directive|define
name|HASHSRAM_F
value|HASHSRAM_V(1U)
end_define

begin_define
define|#
directive|define
name|MATCHTCAM_S
value|1
end_define

begin_define
define|#
directive|define
name|MATCHTCAM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MATCHTCAM_S)
end_define

begin_define
define|#
directive|define
name|MATCHTCAM_F
value|MATCHTCAM_V(1U)
end_define

begin_define
define|#
directive|define
name|MATCHSRAM_S
value|0
end_define

begin_define
define|#
directive|define
name|MATCHSRAM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MATCHSRAM_S)
end_define

begin_define
define|#
directive|define
name|MATCHSRAM_F
value|MATCHSRAM_V(1U)
end_define

begin_define
define|#
directive|define
name|MPS_RX_PG_RSV0_A
value|0x11010
end_define

begin_define
define|#
directive|define
name|MPS_RX_PG_RSV4_A
value|0x11020
end_define

begin_define
define|#
directive|define
name|MPS_RX_PERR_INT_CAUSE_A
value|0x11074
end_define

begin_define
define|#
directive|define
name|MPS_RX_MAC_BG_PG_CNT0_A
value|0x11208
end_define

begin_define
define|#
directive|define
name|MPS_RX_LPBK_BG_PG_CNT0_A
value|0x11218
end_define

begin_define
define|#
directive|define
name|MPS_CLS_TCAM_Y_L_A
value|0xf000
end_define

begin_define
define|#
directive|define
name|MPS_CLS_TCAM_DATA0_A
value|0xf000
end_define

begin_define
define|#
directive|define
name|MPS_CLS_TCAM_DATA1_A
value|0xf004
end_define

begin_define
define|#
directive|define
name|VIDL_S
value|16
end_define

begin_define
define|#
directive|define
name|VIDL_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|VIDL_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> VIDL_S)& VIDL_M)
end_define

begin_define
define|#
directive|define
name|DATALKPTYPE_S
value|10
end_define

begin_define
define|#
directive|define
name|DATALKPTYPE_M
value|0x3U
end_define

begin_define
define|#
directive|define
name|DATALKPTYPE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> DATALKPTYPE_S)& DATALKPTYPE_M)
end_define

begin_define
define|#
directive|define
name|DATAPORTNUM_S
value|12
end_define

begin_define
define|#
directive|define
name|DATAPORTNUM_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|DATAPORTNUM_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> DATAPORTNUM_S)& DATAPORTNUM_M)
end_define

begin_define
define|#
directive|define
name|DATADIPHIT_S
value|8
end_define

begin_define
define|#
directive|define
name|DATADIPHIT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DATADIPHIT_S)
end_define

begin_define
define|#
directive|define
name|DATADIPHIT_F
value|DATADIPHIT_V(1U)
end_define

begin_define
define|#
directive|define
name|DATAVIDH2_S
value|7
end_define

begin_define
define|#
directive|define
name|DATAVIDH2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< DATAVIDH2_S)
end_define

begin_define
define|#
directive|define
name|DATAVIDH2_F
value|DATAVIDH2_V(1U)
end_define

begin_define
define|#
directive|define
name|DATAVIDH1_S
value|0
end_define

begin_define
define|#
directive|define
name|DATAVIDH1_M
value|0x7fU
end_define

begin_define
define|#
directive|define
name|DATAVIDH1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> DATAVIDH1_S)& DATAVIDH1_M)
end_define

begin_define
define|#
directive|define
name|USED_S
value|16
end_define

begin_define
define|#
directive|define
name|USED_M
value|0x7ffU
end_define

begin_define
define|#
directive|define
name|USED_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> USED_S)& USED_M)
end_define

begin_define
define|#
directive|define
name|ALLOC_S
value|0
end_define

begin_define
define|#
directive|define
name|ALLOC_M
value|0x7ffU
end_define

begin_define
define|#
directive|define
name|ALLOC_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> ALLOC_S)& ALLOC_M)
end_define

begin_define
define|#
directive|define
name|T5_USED_S
value|16
end_define

begin_define
define|#
directive|define
name|T5_USED_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|T5_USED_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T5_USED_S)& T5_USED_M)
end_define

begin_define
define|#
directive|define
name|T5_ALLOC_S
value|0
end_define

begin_define
define|#
directive|define
name|T5_ALLOC_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|T5_ALLOC_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T5_ALLOC_S)& T5_ALLOC_M)
end_define

begin_define
define|#
directive|define
name|DMACH_S
value|0
end_define

begin_define
define|#
directive|define
name|DMACH_M
value|0xffffU
end_define

begin_define
define|#
directive|define
name|DMACH_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> DMACH_S)& DMACH_M)
end_define

begin_define
define|#
directive|define
name|MPS_CLS_TCAM_X_L_A
value|0xf008
end_define

begin_define
define|#
directive|define
name|MPS_CLS_TCAM_DATA2_CTL_A
value|0xf008
end_define

begin_define
define|#
directive|define
name|CTLCMDTYPE_S
value|31
end_define

begin_define
define|#
directive|define
name|CTLCMDTYPE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CTLCMDTYPE_S)
end_define

begin_define
define|#
directive|define
name|CTLCMDTYPE_F
value|CTLCMDTYPE_V(1U)
end_define

begin_define
define|#
directive|define
name|CTLTCAMSEL_S
value|25
end_define

begin_define
define|#
directive|define
name|CTLTCAMSEL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CTLTCAMSEL_S)
end_define

begin_define
define|#
directive|define
name|CTLTCAMINDEX_S
value|17
end_define

begin_define
define|#
directive|define
name|CTLTCAMINDEX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CTLTCAMINDEX_S)
end_define

begin_define
define|#
directive|define
name|CTLXYBITSEL_S
value|16
end_define

begin_define
define|#
directive|define
name|CTLXYBITSEL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CTLXYBITSEL_S)
end_define

begin_define
define|#
directive|define
name|MPS_CLS_TCAM_Y_L
parameter_list|(
name|idx
parameter_list|)
value|(MPS_CLS_TCAM_Y_L_A + (idx) * 16)
end_define

begin_define
define|#
directive|define
name|NUM_MPS_CLS_TCAM_Y_L_INSTANCES
value|512
end_define

begin_define
define|#
directive|define
name|MPS_CLS_TCAM_X_L
parameter_list|(
name|idx
parameter_list|)
value|(MPS_CLS_TCAM_X_L_A + (idx) * 16)
end_define

begin_define
define|#
directive|define
name|NUM_MPS_CLS_TCAM_X_L_INSTANCES
value|512
end_define

begin_define
define|#
directive|define
name|MPS_CLS_SRAM_L_A
value|0xe000
end_define

begin_define
define|#
directive|define
name|T6_MULTILISTEN0_S
value|26
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO3_S
value|23
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO3_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO3_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T6_SRAM_PRIO3_S)& T6_SRAM_PRIO3_M)
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO2_S
value|20
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO2_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO2_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T6_SRAM_PRIO2_S)& T6_SRAM_PRIO2_M)
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO1_S
value|17
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO1_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T6_SRAM_PRIO1_S)& T6_SRAM_PRIO1_M)
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO0_S
value|14
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO0_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|T6_SRAM_PRIO0_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T6_SRAM_PRIO0_S)& T6_SRAM_PRIO0_M)
end_define

begin_define
define|#
directive|define
name|T6_SRAM_VLD_S
value|13
end_define

begin_define
define|#
directive|define
name|T6_SRAM_VLD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T6_SRAM_VLD_S)
end_define

begin_define
define|#
directive|define
name|T6_SRAM_VLD_F
value|T6_SRAM_VLD_V(1U)
end_define

begin_define
define|#
directive|define
name|T6_REPLICATE_S
value|12
end_define

begin_define
define|#
directive|define
name|T6_REPLICATE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T6_REPLICATE_S)
end_define

begin_define
define|#
directive|define
name|T6_REPLICATE_F
value|T6_REPLICATE_V(1U)
end_define

begin_define
define|#
directive|define
name|T6_PF_S
value|9
end_define

begin_define
define|#
directive|define
name|T6_PF_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|T6_PF_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T6_PF_S)& T6_PF_M)
end_define

begin_define
define|#
directive|define
name|T6_VF_VALID_S
value|8
end_define

begin_define
define|#
directive|define
name|T6_VF_VALID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T6_VF_VALID_S)
end_define

begin_define
define|#
directive|define
name|T6_VF_VALID_F
value|T6_VF_VALID_V(1U)
end_define

begin_define
define|#
directive|define
name|T6_VF_S
value|0
end_define

begin_define
define|#
directive|define
name|T6_VF_M
value|0xffU
end_define

begin_define
define|#
directive|define
name|T6_VF_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T6_VF_S)& T6_VF_M)
end_define

begin_define
define|#
directive|define
name|MPS_CLS_SRAM_H_A
value|0xe004
end_define

begin_define
define|#
directive|define
name|MPS_CLS_SRAM_L
parameter_list|(
name|idx
parameter_list|)
value|(MPS_CLS_SRAM_L_A + (idx) * 8)
end_define

begin_define
define|#
directive|define
name|NUM_MPS_CLS_SRAM_L_INSTANCES
value|336
end_define

begin_define
define|#
directive|define
name|MPS_CLS_SRAM_H
parameter_list|(
name|idx
parameter_list|)
value|(MPS_CLS_SRAM_H_A + (idx) * 8)
end_define

begin_define
define|#
directive|define
name|NUM_MPS_CLS_SRAM_H_INSTANCES
value|336
end_define

begin_define
define|#
directive|define
name|MULTILISTEN0_S
value|25
end_define

begin_define
define|#
directive|define
name|REPLICATE_S
value|11
end_define

begin_define
define|#
directive|define
name|REPLICATE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< REPLICATE_S)
end_define

begin_define
define|#
directive|define
name|REPLICATE_F
value|REPLICATE_V(1U)
end_define

begin_define
define|#
directive|define
name|PF_S
value|8
end_define

begin_define
define|#
directive|define
name|PF_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|PF_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PF_S)& PF_M)
end_define

begin_define
define|#
directive|define
name|VF_VALID_S
value|7
end_define

begin_define
define|#
directive|define
name|VF_VALID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< VF_VALID_S)
end_define

begin_define
define|#
directive|define
name|VF_VALID_F
value|VF_VALID_V(1U)
end_define

begin_define
define|#
directive|define
name|VF_S
value|0
end_define

begin_define
define|#
directive|define
name|VF_M
value|0x7fU
end_define

begin_define
define|#
directive|define
name|VF_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> VF_S)& VF_M)
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO3_S
value|22
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO3_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO3_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> SRAM_PRIO3_S)& SRAM_PRIO3_M)
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO2_S
value|19
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO2_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO2_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> SRAM_PRIO2_S)& SRAM_PRIO2_M)
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO1_S
value|16
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO1_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO1_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> SRAM_PRIO1_S)& SRAM_PRIO1_M)
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO0_S
value|13
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO0_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|SRAM_PRIO0_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> SRAM_PRIO0_S)& SRAM_PRIO0_M)
end_define

begin_define
define|#
directive|define
name|SRAM_VLD_S
value|12
end_define

begin_define
define|#
directive|define
name|SRAM_VLD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SRAM_VLD_S)
end_define

begin_define
define|#
directive|define
name|SRAM_VLD_F
value|SRAM_VLD_V(1U)
end_define

begin_define
define|#
directive|define
name|PORTMAP_S
value|0
end_define

begin_define
define|#
directive|define
name|PORTMAP_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|PORTMAP_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PORTMAP_S)& PORTMAP_M)
end_define

begin_define
define|#
directive|define
name|CPL_INTR_CAUSE_A
value|0x19054
end_define

begin_define
define|#
directive|define
name|CIM_OP_MAP_PERR_S
value|5
end_define

begin_define
define|#
directive|define
name|CIM_OP_MAP_PERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CIM_OP_MAP_PERR_S)
end_define

begin_define
define|#
directive|define
name|CIM_OP_MAP_PERR_F
value|CIM_OP_MAP_PERR_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_OVFL_ERROR_S
value|4
end_define

begin_define
define|#
directive|define
name|CIM_OVFL_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CIM_OVFL_ERROR_S)
end_define

begin_define
define|#
directive|define
name|CIM_OVFL_ERROR_F
value|CIM_OVFL_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|TP_FRAMING_ERROR_S
value|3
end_define

begin_define
define|#
directive|define
name|TP_FRAMING_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TP_FRAMING_ERROR_S)
end_define

begin_define
define|#
directive|define
name|TP_FRAMING_ERROR_F
value|TP_FRAMING_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|SGE_FRAMING_ERROR_S
value|2
end_define

begin_define
define|#
directive|define
name|SGE_FRAMING_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGE_FRAMING_ERROR_S)
end_define

begin_define
define|#
directive|define
name|SGE_FRAMING_ERROR_F
value|SGE_FRAMING_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_FRAMING_ERROR_S
value|1
end_define

begin_define
define|#
directive|define
name|CIM_FRAMING_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CIM_FRAMING_ERROR_S)
end_define

begin_define
define|#
directive|define
name|CIM_FRAMING_ERROR_F
value|CIM_FRAMING_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|ZERO_SWITCH_ERROR_S
value|0
end_define

begin_define
define|#
directive|define
name|ZERO_SWITCH_ERROR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ZERO_SWITCH_ERROR_S)
end_define

begin_define
define|#
directive|define
name|ZERO_SWITCH_ERROR_F
value|ZERO_SWITCH_ERROR_V(1U)
end_define

begin_define
define|#
directive|define
name|SMB_INT_CAUSE_A
value|0x19090
end_define

begin_define
define|#
directive|define
name|MSTTXFIFOPARINT_S
value|21
end_define

begin_define
define|#
directive|define
name|MSTTXFIFOPARINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSTTXFIFOPARINT_S)
end_define

begin_define
define|#
directive|define
name|MSTTXFIFOPARINT_F
value|MSTTXFIFOPARINT_V(1U)
end_define

begin_define
define|#
directive|define
name|MSTRXFIFOPARINT_S
value|20
end_define

begin_define
define|#
directive|define
name|MSTRXFIFOPARINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MSTRXFIFOPARINT_S)
end_define

begin_define
define|#
directive|define
name|MSTRXFIFOPARINT_F
value|MSTRXFIFOPARINT_V(1U)
end_define

begin_define
define|#
directive|define
name|SLVFIFOPARINT_S
value|19
end_define

begin_define
define|#
directive|define
name|SLVFIFOPARINT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SLVFIFOPARINT_S)
end_define

begin_define
define|#
directive|define
name|SLVFIFOPARINT_F
value|SLVFIFOPARINT_V(1U)
end_define

begin_define
define|#
directive|define
name|ULP_RX_INT_CAUSE_A
value|0x19158
end_define

begin_define
define|#
directive|define
name|ULP_RX_ISCSI_LLIMIT_A
value|0x1915c
end_define

begin_define
define|#
directive|define
name|ULP_RX_ISCSI_ULIMIT_A
value|0x19160
end_define

begin_define
define|#
directive|define
name|ULP_RX_ISCSI_TAGMASK_A
value|0x19164
end_define

begin_define
define|#
directive|define
name|ULP_RX_ISCSI_PSZ_A
value|0x19168
end_define

begin_define
define|#
directive|define
name|ULP_RX_TDDP_LLIMIT_A
value|0x1916c
end_define

begin_define
define|#
directive|define
name|ULP_RX_TDDP_ULIMIT_A
value|0x19170
end_define

begin_define
define|#
directive|define
name|ULP_RX_STAG_LLIMIT_A
value|0x1917c
end_define

begin_define
define|#
directive|define
name|ULP_RX_STAG_ULIMIT_A
value|0x19180
end_define

begin_define
define|#
directive|define
name|ULP_RX_RQ_LLIMIT_A
value|0x19184
end_define

begin_define
define|#
directive|define
name|ULP_RX_RQ_ULIMIT_A
value|0x19188
end_define

begin_define
define|#
directive|define
name|ULP_RX_PBL_LLIMIT_A
value|0x1918c
end_define

begin_define
define|#
directive|define
name|ULP_RX_PBL_ULIMIT_A
value|0x19190
end_define

begin_define
define|#
directive|define
name|ULP_RX_CTX_BASE_A
value|0x19194
end_define

begin_define
define|#
directive|define
name|ULP_RX_RQUDP_LLIMIT_A
value|0x191a4
end_define

begin_define
define|#
directive|define
name|ULP_RX_RQUDP_ULIMIT_A
value|0x191a8
end_define

begin_define
define|#
directive|define
name|ULP_RX_LA_CTL_A
value|0x1923c
end_define

begin_define
define|#
directive|define
name|ULP_RX_LA_RDPTR_A
value|0x19240
end_define

begin_define
define|#
directive|define
name|ULP_RX_LA_RDDATA_A
value|0x19244
end_define

begin_define
define|#
directive|define
name|ULP_RX_LA_WRPTR_A
value|0x19248
end_define

begin_define
define|#
directive|define
name|HPZ3_S
value|24
end_define

begin_define
define|#
directive|define
name|HPZ3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HPZ3_S)
end_define

begin_define
define|#
directive|define
name|HPZ2_S
value|16
end_define

begin_define
define|#
directive|define
name|HPZ2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HPZ2_S)
end_define

begin_define
define|#
directive|define
name|HPZ1_S
value|8
end_define

begin_define
define|#
directive|define
name|HPZ1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HPZ1_S)
end_define

begin_define
define|#
directive|define
name|HPZ0_S
value|0
end_define

begin_define
define|#
directive|define
name|HPZ0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HPZ0_S)
end_define

begin_define
define|#
directive|define
name|ULP_RX_TDDP_PSZ_A
value|0x19178
end_define

begin_comment
comment|/* registers for module SF */
end_comment

begin_define
define|#
directive|define
name|SF_DATA_A
value|0x193f8
end_define

begin_define
define|#
directive|define
name|SF_OP_A
value|0x193fc
end_define

begin_define
define|#
directive|define
name|SF_BUSY_S
value|31
end_define

begin_define
define|#
directive|define
name|SF_BUSY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SF_BUSY_S)
end_define

begin_define
define|#
directive|define
name|SF_BUSY_F
value|SF_BUSY_V(1U)
end_define

begin_define
define|#
directive|define
name|SF_LOCK_S
value|4
end_define

begin_define
define|#
directive|define
name|SF_LOCK_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SF_LOCK_S)
end_define

begin_define
define|#
directive|define
name|SF_LOCK_F
value|SF_LOCK_V(1U)
end_define

begin_define
define|#
directive|define
name|SF_CONT_S
value|3
end_define

begin_define
define|#
directive|define
name|SF_CONT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SF_CONT_S)
end_define

begin_define
define|#
directive|define
name|SF_CONT_F
value|SF_CONT_V(1U)
end_define

begin_define
define|#
directive|define
name|BYTECNT_S
value|1
end_define

begin_define
define|#
directive|define
name|BYTECNT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< BYTECNT_S)
end_define

begin_define
define|#
directive|define
name|OP_S
value|0
end_define

begin_define
define|#
directive|define
name|OP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OP_S)
end_define

begin_define
define|#
directive|define
name|OP_F
value|OP_V(1U)
end_define

begin_define
define|#
directive|define
name|PL_PF_INT_CAUSE_A
value|0x3c0
end_define

begin_define
define|#
directive|define
name|PFSW_S
value|3
end_define

begin_define
define|#
directive|define
name|PFSW_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PFSW_S)
end_define

begin_define
define|#
directive|define
name|PFSW_F
value|PFSW_V(1U)
end_define

begin_define
define|#
directive|define
name|PFCIM_S
value|1
end_define

begin_define
define|#
directive|define
name|PFCIM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PFCIM_S)
end_define

begin_define
define|#
directive|define
name|PFCIM_F
value|PFCIM_V(1U)
end_define

begin_define
define|#
directive|define
name|PL_PF_INT_ENABLE_A
value|0x3c4
end_define

begin_define
define|#
directive|define
name|PL_PF_CTL_A
value|0x3c8
end_define

begin_define
define|#
directive|define
name|PL_WHOAMI_A
value|0x19400
end_define

begin_define
define|#
directive|define
name|SOURCEPF_S
value|8
end_define

begin_define
define|#
directive|define
name|SOURCEPF_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|SOURCEPF_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> SOURCEPF_S)& SOURCEPF_M)
end_define

begin_define
define|#
directive|define
name|T6_SOURCEPF_S
value|9
end_define

begin_define
define|#
directive|define
name|T6_SOURCEPF_M
value|0x7U
end_define

begin_define
define|#
directive|define
name|T6_SOURCEPF_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> T6_SOURCEPF_S)& T6_SOURCEPF_M)
end_define

begin_define
define|#
directive|define
name|PL_INT_CAUSE_A
value|0x1940c
end_define

begin_define
define|#
directive|define
name|ULP_TX_S
value|27
end_define

begin_define
define|#
directive|define
name|ULP_TX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ULP_TX_S)
end_define

begin_define
define|#
directive|define
name|ULP_TX_F
value|ULP_TX_V(1U)
end_define

begin_define
define|#
directive|define
name|SGE_S
value|26
end_define

begin_define
define|#
directive|define
name|SGE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SGE_S)
end_define

begin_define
define|#
directive|define
name|SGE_F
value|SGE_V(1U)
end_define

begin_define
define|#
directive|define
name|CPL_SWITCH_S
value|24
end_define

begin_define
define|#
directive|define
name|CPL_SWITCH_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CPL_SWITCH_S)
end_define

begin_define
define|#
directive|define
name|CPL_SWITCH_F
value|CPL_SWITCH_V(1U)
end_define

begin_define
define|#
directive|define
name|ULP_RX_S
value|23
end_define

begin_define
define|#
directive|define
name|ULP_RX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ULP_RX_S)
end_define

begin_define
define|#
directive|define
name|ULP_RX_F
value|ULP_RX_V(1U)
end_define

begin_define
define|#
directive|define
name|PM_RX_S
value|22
end_define

begin_define
define|#
directive|define
name|PM_RX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PM_RX_S)
end_define

begin_define
define|#
directive|define
name|PM_RX_F
value|PM_RX_V(1U)
end_define

begin_define
define|#
directive|define
name|PM_TX_S
value|21
end_define

begin_define
define|#
directive|define
name|PM_TX_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PM_TX_S)
end_define

begin_define
define|#
directive|define
name|PM_TX_F
value|PM_TX_V(1U)
end_define

begin_define
define|#
directive|define
name|MA_S
value|20
end_define

begin_define
define|#
directive|define
name|MA_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MA_S)
end_define

begin_define
define|#
directive|define
name|MA_F
value|MA_V(1U)
end_define

begin_define
define|#
directive|define
name|TP_S
value|19
end_define

begin_define
define|#
directive|define
name|TP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TP_S)
end_define

begin_define
define|#
directive|define
name|TP_F
value|TP_V(1U)
end_define

begin_define
define|#
directive|define
name|LE_S
value|18
end_define

begin_define
define|#
directive|define
name|LE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< LE_S)
end_define

begin_define
define|#
directive|define
name|LE_F
value|LE_V(1U)
end_define

begin_define
define|#
directive|define
name|EDC1_S
value|17
end_define

begin_define
define|#
directive|define
name|EDC1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EDC1_S)
end_define

begin_define
define|#
directive|define
name|EDC1_F
value|EDC1_V(1U)
end_define

begin_define
define|#
directive|define
name|EDC0_S
value|16
end_define

begin_define
define|#
directive|define
name|EDC0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EDC0_S)
end_define

begin_define
define|#
directive|define
name|EDC0_F
value|EDC0_V(1U)
end_define

begin_define
define|#
directive|define
name|MC_S
value|15
end_define

begin_define
define|#
directive|define
name|MC_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MC_S)
end_define

begin_define
define|#
directive|define
name|MC_F
value|MC_V(1U)
end_define

begin_define
define|#
directive|define
name|PCIE_S
value|14
end_define

begin_define
define|#
directive|define
name|PCIE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PCIE_S)
end_define

begin_define
define|#
directive|define
name|PCIE_F
value|PCIE_V(1U)
end_define

begin_define
define|#
directive|define
name|XGMAC_KR1_S
value|12
end_define

begin_define
define|#
directive|define
name|XGMAC_KR1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< XGMAC_KR1_S)
end_define

begin_define
define|#
directive|define
name|XGMAC_KR1_F
value|XGMAC_KR1_V(1U)
end_define

begin_define
define|#
directive|define
name|XGMAC_KR0_S
value|11
end_define

begin_define
define|#
directive|define
name|XGMAC_KR0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< XGMAC_KR0_S)
end_define

begin_define
define|#
directive|define
name|XGMAC_KR0_F
value|XGMAC_KR0_V(1U)
end_define

begin_define
define|#
directive|define
name|XGMAC1_S
value|10
end_define

begin_define
define|#
directive|define
name|XGMAC1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< XGMAC1_S)
end_define

begin_define
define|#
directive|define
name|XGMAC1_F
value|XGMAC1_V(1U)
end_define

begin_define
define|#
directive|define
name|XGMAC0_S
value|9
end_define

begin_define
define|#
directive|define
name|XGMAC0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< XGMAC0_S)
end_define

begin_define
define|#
directive|define
name|XGMAC0_F
value|XGMAC0_V(1U)
end_define

begin_define
define|#
directive|define
name|SMB_S
value|8
end_define

begin_define
define|#
directive|define
name|SMB_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SMB_S)
end_define

begin_define
define|#
directive|define
name|SMB_F
value|SMB_V(1U)
end_define

begin_define
define|#
directive|define
name|SF_S
value|7
end_define

begin_define
define|#
directive|define
name|SF_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SF_S)
end_define

begin_define
define|#
directive|define
name|SF_F
value|SF_V(1U)
end_define

begin_define
define|#
directive|define
name|PL_S
value|6
end_define

begin_define
define|#
directive|define
name|PL_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PL_S)
end_define

begin_define
define|#
directive|define
name|PL_F
value|PL_V(1U)
end_define

begin_define
define|#
directive|define
name|NCSI_S
value|5
end_define

begin_define
define|#
directive|define
name|NCSI_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< NCSI_S)
end_define

begin_define
define|#
directive|define
name|NCSI_F
value|NCSI_V(1U)
end_define

begin_define
define|#
directive|define
name|MPS_S
value|4
end_define

begin_define
define|#
directive|define
name|MPS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MPS_S)
end_define

begin_define
define|#
directive|define
name|MPS_F
value|MPS_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_S
value|0
end_define

begin_define
define|#
directive|define
name|CIM_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CIM_S)
end_define

begin_define
define|#
directive|define
name|CIM_F
value|CIM_V(1U)
end_define

begin_define
define|#
directive|define
name|MC1_S
value|31
end_define

begin_define
define|#
directive|define
name|MC1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MC1_S)
end_define

begin_define
define|#
directive|define
name|MC1_F
value|MC1_V(1U)
end_define

begin_define
define|#
directive|define
name|PL_INT_ENABLE_A
value|0x19410
end_define

begin_define
define|#
directive|define
name|PL_INT_MAP0_A
value|0x19414
end_define

begin_define
define|#
directive|define
name|PL_RST_A
value|0x19428
end_define

begin_define
define|#
directive|define
name|PIORST_S
value|1
end_define

begin_define
define|#
directive|define
name|PIORST_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PIORST_S)
end_define

begin_define
define|#
directive|define
name|PIORST_F
value|PIORST_V(1U)
end_define

begin_define
define|#
directive|define
name|PIORSTMODE_S
value|0
end_define

begin_define
define|#
directive|define
name|PIORSTMODE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PIORSTMODE_S)
end_define

begin_define
define|#
directive|define
name|PIORSTMODE_F
value|PIORSTMODE_V(1U)
end_define

begin_define
define|#
directive|define
name|PL_PL_INT_CAUSE_A
value|0x19430
end_define

begin_define
define|#
directive|define
name|FATALPERR_S
value|4
end_define

begin_define
define|#
directive|define
name|FATALPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< FATALPERR_S)
end_define

begin_define
define|#
directive|define
name|FATALPERR_F
value|FATALPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|PERRVFID_S
value|0
end_define

begin_define
define|#
directive|define
name|PERRVFID_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PERRVFID_S)
end_define

begin_define
define|#
directive|define
name|PERRVFID_F
value|PERRVFID_V(1U)
end_define

begin_define
define|#
directive|define
name|PL_REV_A
value|0x1943c
end_define

begin_define
define|#
directive|define
name|REV_S
value|0
end_define

begin_define
define|#
directive|define
name|REV_M
value|0xfU
end_define

begin_define
define|#
directive|define
name|REV_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< REV_S)
end_define

begin_define
define|#
directive|define
name|REV_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> REV_S)& REV_M)
end_define

begin_define
define|#
directive|define
name|T6_UNKNOWNCMD_S
value|3
end_define

begin_define
define|#
directive|define
name|T6_UNKNOWNCMD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T6_UNKNOWNCMD_S)
end_define

begin_define
define|#
directive|define
name|T6_UNKNOWNCMD_F
value|T6_UNKNOWNCMD_V(1U)
end_define

begin_define
define|#
directive|define
name|T6_LIP0_S
value|2
end_define

begin_define
define|#
directive|define
name|T6_LIP0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T6_LIP0_S)
end_define

begin_define
define|#
directive|define
name|T6_LIP0_F
value|T6_LIP0_V(1U)
end_define

begin_define
define|#
directive|define
name|T6_LIPMISS_S
value|1
end_define

begin_define
define|#
directive|define
name|T6_LIPMISS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< T6_LIPMISS_S)
end_define

begin_define
define|#
directive|define
name|T6_LIPMISS_F
value|T6_LIPMISS_V(1U)
end_define

begin_define
define|#
directive|define
name|LE_DB_CONFIG_A
value|0x19c04
end_define

begin_define
define|#
directive|define
name|LE_DB_SERVER_INDEX_A
value|0x19c18
end_define

begin_define
define|#
directive|define
name|LE_DB_SRVR_START_INDEX_A
value|0x19c18
end_define

begin_define
define|#
directive|define
name|LE_DB_ACT_CNT_IPV4_A
value|0x19c20
end_define

begin_define
define|#
directive|define
name|LE_DB_ACT_CNT_IPV6_A
value|0x19c24
end_define

begin_define
define|#
directive|define
name|LE_DB_HASH_TID_BASE_A
value|0x19c30
end_define

begin_define
define|#
directive|define
name|LE_DB_HASH_TBL_BASE_ADDR_A
value|0x19c30
end_define

begin_define
define|#
directive|define
name|LE_DB_INT_CAUSE_A
value|0x19c3c
end_define

begin_define
define|#
directive|define
name|LE_DB_TID_HASHBASE_A
value|0x19df8
end_define

begin_define
define|#
directive|define
name|T6_LE_DB_HASH_TID_BASE_A
value|0x19df8
end_define

begin_define
define|#
directive|define
name|HASHEN_S
value|20
end_define

begin_define
define|#
directive|define
name|HASHEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HASHEN_S)
end_define

begin_define
define|#
directive|define
name|HASHEN_F
value|HASHEN_V(1U)
end_define

begin_define
define|#
directive|define
name|ASLIPCOMPEN_S
value|17
end_define

begin_define
define|#
directive|define
name|ASLIPCOMPEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ASLIPCOMPEN_S)
end_define

begin_define
define|#
directive|define
name|ASLIPCOMPEN_F
value|ASLIPCOMPEN_V(1U)
end_define

begin_define
define|#
directive|define
name|REQQPARERR_S
value|16
end_define

begin_define
define|#
directive|define
name|REQQPARERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< REQQPARERR_S)
end_define

begin_define
define|#
directive|define
name|REQQPARERR_F
value|REQQPARERR_V(1U)
end_define

begin_define
define|#
directive|define
name|UNKNOWNCMD_S
value|15
end_define

begin_define
define|#
directive|define
name|UNKNOWNCMD_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UNKNOWNCMD_S)
end_define

begin_define
define|#
directive|define
name|UNKNOWNCMD_F
value|UNKNOWNCMD_V(1U)
end_define

begin_define
define|#
directive|define
name|PARITYERR_S
value|6
end_define

begin_define
define|#
directive|define
name|PARITYERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PARITYERR_S)
end_define

begin_define
define|#
directive|define
name|PARITYERR_F
value|PARITYERR_V(1U)
end_define

begin_define
define|#
directive|define
name|LIPMISS_S
value|5
end_define

begin_define
define|#
directive|define
name|LIPMISS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< LIPMISS_S)
end_define

begin_define
define|#
directive|define
name|LIPMISS_F
value|LIPMISS_V(1U)
end_define

begin_define
define|#
directive|define
name|LIP0_S
value|4
end_define

begin_define
define|#
directive|define
name|LIP0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< LIP0_S)
end_define

begin_define
define|#
directive|define
name|LIP0_F
value|LIP0_V(1U)
end_define

begin_define
define|#
directive|define
name|BASEADDR_S
value|3
end_define

begin_define
define|#
directive|define
name|BASEADDR_M
value|0x1fffffffU
end_define

begin_define
define|#
directive|define
name|BASEADDR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> BASEADDR_S)& BASEADDR_M)
end_define

begin_define
define|#
directive|define
name|TCAMINTPERR_S
value|13
end_define

begin_define
define|#
directive|define
name|TCAMINTPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TCAMINTPERR_S)
end_define

begin_define
define|#
directive|define
name|TCAMINTPERR_F
value|TCAMINTPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|SSRAMINTPERR_S
value|10
end_define

begin_define
define|#
directive|define
name|SSRAMINTPERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< SSRAMINTPERR_S)
end_define

begin_define
define|#
directive|define
name|SSRAMINTPERR_F
value|SSRAMINTPERR_V(1U)
end_define

begin_define
define|#
directive|define
name|NCSI_INT_CAUSE_A
value|0x1a0d8
end_define

begin_define
define|#
directive|define
name|CIM_DM_PRTY_ERR_S
value|8
end_define

begin_define
define|#
directive|define
name|CIM_DM_PRTY_ERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< CIM_DM_PRTY_ERR_S)
end_define

begin_define
define|#
directive|define
name|CIM_DM_PRTY_ERR_F
value|CIM_DM_PRTY_ERR_V(1U)
end_define

begin_define
define|#
directive|define
name|MPS_DM_PRTY_ERR_S
value|7
end_define

begin_define
define|#
directive|define
name|MPS_DM_PRTY_ERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MPS_DM_PRTY_ERR_S)
end_define

begin_define
define|#
directive|define
name|MPS_DM_PRTY_ERR_F
value|MPS_DM_PRTY_ERR_V(1U)
end_define

begin_define
define|#
directive|define
name|TXFIFO_PRTY_ERR_S
value|1
end_define

begin_define
define|#
directive|define
name|TXFIFO_PRTY_ERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TXFIFO_PRTY_ERR_S)
end_define

begin_define
define|#
directive|define
name|TXFIFO_PRTY_ERR_F
value|TXFIFO_PRTY_ERR_V(1U)
end_define

begin_define
define|#
directive|define
name|RXFIFO_PRTY_ERR_S
value|0
end_define

begin_define
define|#
directive|define
name|RXFIFO_PRTY_ERR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< RXFIFO_PRTY_ERR_S)
end_define

begin_define
define|#
directive|define
name|RXFIFO_PRTY_ERR_F
value|RXFIFO_PRTY_ERR_V(1U)
end_define

begin_define
define|#
directive|define
name|XGMAC_PORT_CFG2_A
value|0x1018
end_define

begin_define
define|#
directive|define
name|PATEN_S
value|18
end_define

begin_define
define|#
directive|define
name|PATEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PATEN_S)
end_define

begin_define
define|#
directive|define
name|PATEN_F
value|PATEN_V(1U)
end_define

begin_define
define|#
directive|define
name|MAGICEN_S
value|17
end_define

begin_define
define|#
directive|define
name|MAGICEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< MAGICEN_S)
end_define

begin_define
define|#
directive|define
name|MAGICEN_F
value|MAGICEN_V(1U)
end_define

begin_define
define|#
directive|define
name|XGMAC_PORT_MAGIC_MACID_LO
value|0x1024
end_define

begin_define
define|#
directive|define
name|XGMAC_PORT_MAGIC_MACID_HI
value|0x1028
end_define

begin_define
define|#
directive|define
name|XGMAC_PORT_EPIO_DATA0_A
value|0x10c0
end_define

begin_define
define|#
directive|define
name|XGMAC_PORT_EPIO_DATA1_A
value|0x10c4
end_define

begin_define
define|#
directive|define
name|XGMAC_PORT_EPIO_DATA2_A
value|0x10c8
end_define

begin_define
define|#
directive|define
name|XGMAC_PORT_EPIO_DATA3_A
value|0x10cc
end_define

begin_define
define|#
directive|define
name|XGMAC_PORT_EPIO_OP_A
value|0x10d0
end_define

begin_define
define|#
directive|define
name|EPIOWR_S
value|8
end_define

begin_define
define|#
directive|define
name|EPIOWR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< EPIOWR_S)
end_define

begin_define
define|#
directive|define
name|EPIOWR_F
value|EPIOWR_V(1U)
end_define

begin_define
define|#
directive|define
name|ADDRESS_S
value|0
end_define

begin_define
define|#
directive|define
name|ADDRESS_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< ADDRESS_S)
end_define

begin_define
define|#
directive|define
name|MAC_PORT_INT_CAUSE_A
value|0x8dc
end_define

begin_define
define|#
directive|define
name|XGMAC_PORT_INT_CAUSE_A
value|0x10dc
end_define

begin_define
define|#
directive|define
name|TP_TX_MOD_QUEUE_REQ_MAP_A
value|0x7e28
end_define

begin_define
define|#
directive|define
name|TP_TX_MOD_QUEUE_WEIGHT0_A
value|0x7e30
end_define

begin_define
define|#
directive|define
name|TP_TX_MOD_CHANNEL_WEIGHT_A
value|0x7e34
end_define

begin_define
define|#
directive|define
name|TX_MOD_QUEUE_REQ_MAP_S
value|0
end_define

begin_define
define|#
directive|define
name|TX_MOD_QUEUE_REQ_MAP_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TX_MOD_QUEUE_REQ_MAP_S)
end_define

begin_define
define|#
directive|define
name|TX_MODQ_WEIGHT3_S
value|24
end_define

begin_define
define|#
directive|define
name|TX_MODQ_WEIGHT3_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TX_MODQ_WEIGHT3_S)
end_define

begin_define
define|#
directive|define
name|TX_MODQ_WEIGHT2_S
value|16
end_define

begin_define
define|#
directive|define
name|TX_MODQ_WEIGHT2_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TX_MODQ_WEIGHT2_S)
end_define

begin_define
define|#
directive|define
name|TX_MODQ_WEIGHT1_S
value|8
end_define

begin_define
define|#
directive|define
name|TX_MODQ_WEIGHT1_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TX_MODQ_WEIGHT1_S)
end_define

begin_define
define|#
directive|define
name|TX_MODQ_WEIGHT0_S
value|0
end_define

begin_define
define|#
directive|define
name|TX_MODQ_WEIGHT0_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< TX_MODQ_WEIGHT0_S)
end_define

begin_define
define|#
directive|define
name|TP_TX_SCHED_HDR_A
value|0x23
end_define

begin_define
define|#
directive|define
name|TP_TX_SCHED_FIFO_A
value|0x24
end_define

begin_define
define|#
directive|define
name|TP_TX_SCHED_PCMD_A
value|0x25
end_define

begin_define
define|#
directive|define
name|NUM_MPS_CLS_SRAM_L_INSTANCES
value|336
end_define

begin_define
define|#
directive|define
name|NUM_MPS_T5_CLS_SRAM_L_INSTANCES
value|512
end_define

begin_define
define|#
directive|define
name|T5_PORT0_BASE
value|0x30000
end_define

begin_define
define|#
directive|define
name|T5_PORT_STRIDE
value|0x4000
end_define

begin_define
define|#
directive|define
name|T5_PORT_BASE
parameter_list|(
name|idx
parameter_list|)
value|(T5_PORT0_BASE + (idx) * T5_PORT_STRIDE)
end_define

begin_define
define|#
directive|define
name|T5_PORT_REG
parameter_list|(
name|idx
parameter_list|,
name|reg
parameter_list|)
value|(T5_PORT_BASE(idx) + (reg))
end_define

begin_define
define|#
directive|define
name|MC_0_BASE_ADDR
value|0x40000
end_define

begin_define
define|#
directive|define
name|MC_1_BASE_ADDR
value|0x48000
end_define

begin_define
define|#
directive|define
name|MC_STRIDE
value|(MC_1_BASE_ADDR - MC_0_BASE_ADDR)
end_define

begin_define
define|#
directive|define
name|MC_REG
parameter_list|(
name|reg
parameter_list|,
name|idx
parameter_list|)
value|(reg + MC_STRIDE * idx)
end_define

begin_define
define|#
directive|define
name|MC_P_BIST_CMD_A
value|0x41400
end_define

begin_define
define|#
directive|define
name|MC_P_BIST_CMD_ADDR_A
value|0x41404
end_define

begin_define
define|#
directive|define
name|MC_P_BIST_CMD_LEN_A
value|0x41408
end_define

begin_define
define|#
directive|define
name|MC_P_BIST_DATA_PATTERN_A
value|0x4140c
end_define

begin_define
define|#
directive|define
name|MC_P_BIST_STATUS_RDATA_A
value|0x41488
end_define

begin_define
define|#
directive|define
name|EDC_T50_BASE_ADDR
value|0x50000
end_define

begin_define
define|#
directive|define
name|EDC_H_BIST_CMD_A
value|0x50004
end_define

begin_define
define|#
directive|define
name|EDC_H_BIST_CMD_ADDR_A
value|0x50008
end_define

begin_define
define|#
directive|define
name|EDC_H_BIST_CMD_LEN_A
value|0x5000c
end_define

begin_define
define|#
directive|define
name|EDC_H_BIST_DATA_PATTERN_A
value|0x50010
end_define

begin_define
define|#
directive|define
name|EDC_H_BIST_STATUS_RDATA_A
value|0x50028
end_define

begin_define
define|#
directive|define
name|EDC_H_ECC_ERR_ADDR_A
value|0x50084
end_define

begin_define
define|#
directive|define
name|EDC_T51_BASE_ADDR
value|0x50800
end_define

begin_define
define|#
directive|define
name|EDC_T5_STRIDE
value|(EDC_T51_BASE_ADDR - EDC_T50_BASE_ADDR)
end_define

begin_define
define|#
directive|define
name|EDC_T5_REG
parameter_list|(
name|reg
parameter_list|,
name|idx
parameter_list|)
value|(reg + EDC_T5_STRIDE * idx)
end_define

begin_define
define|#
directive|define
name|PL_VF_REV_A
value|0x4
end_define

begin_define
define|#
directive|define
name|PL_VF_WHOAMI_A
value|0x0
end_define

begin_define
define|#
directive|define
name|PL_VF_REVISION_A
value|0x8
end_define

begin_comment
comment|/* registers for module CIM */
end_comment

begin_define
define|#
directive|define
name|CIM_HOST_ACC_CTRL_A
value|0x7b50
end_define

begin_define
define|#
directive|define
name|CIM_HOST_ACC_DATA_A
value|0x7b54
end_define

begin_define
define|#
directive|define
name|UP_UP_DBG_LA_CFG_A
value|0x140
end_define

begin_define
define|#
directive|define
name|UP_UP_DBG_LA_DATA_A
value|0x144
end_define

begin_define
define|#
directive|define
name|HOSTBUSY_S
value|17
end_define

begin_define
define|#
directive|define
name|HOSTBUSY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HOSTBUSY_S)
end_define

begin_define
define|#
directive|define
name|HOSTBUSY_F
value|HOSTBUSY_V(1U)
end_define

begin_define
define|#
directive|define
name|HOSTWRITE_S
value|16
end_define

begin_define
define|#
directive|define
name|HOSTWRITE_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< HOSTWRITE_S)
end_define

begin_define
define|#
directive|define
name|HOSTWRITE_F
value|HOSTWRITE_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_IBQ_DBG_CFG_A
value|0x7b60
end_define

begin_define
define|#
directive|define
name|IBQDBGADDR_S
value|16
end_define

begin_define
define|#
directive|define
name|IBQDBGADDR_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|IBQDBGADDR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IBQDBGADDR_S)
end_define

begin_define
define|#
directive|define
name|IBQDBGADDR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> IBQDBGADDR_S)& IBQDBGADDR_M)
end_define

begin_define
define|#
directive|define
name|IBQDBGBUSY_S
value|1
end_define

begin_define
define|#
directive|define
name|IBQDBGBUSY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IBQDBGBUSY_S)
end_define

begin_define
define|#
directive|define
name|IBQDBGBUSY_F
value|IBQDBGBUSY_V(1U)
end_define

begin_define
define|#
directive|define
name|IBQDBGEN_S
value|0
end_define

begin_define
define|#
directive|define
name|IBQDBGEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IBQDBGEN_S)
end_define

begin_define
define|#
directive|define
name|IBQDBGEN_F
value|IBQDBGEN_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_OBQ_DBG_CFG_A
value|0x7b64
end_define

begin_define
define|#
directive|define
name|OBQDBGADDR_S
value|16
end_define

begin_define
define|#
directive|define
name|OBQDBGADDR_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|OBQDBGADDR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OBQDBGADDR_S)
end_define

begin_define
define|#
directive|define
name|OBQDBGADDR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> OBQDBGADDR_S)& OBQDBGADDR_M)
end_define

begin_define
define|#
directive|define
name|OBQDBGBUSY_S
value|1
end_define

begin_define
define|#
directive|define
name|OBQDBGBUSY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OBQDBGBUSY_S)
end_define

begin_define
define|#
directive|define
name|OBQDBGBUSY_F
value|OBQDBGBUSY_V(1U)
end_define

begin_define
define|#
directive|define
name|OBQDBGEN_S
value|0
end_define

begin_define
define|#
directive|define
name|OBQDBGEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OBQDBGEN_S)
end_define

begin_define
define|#
directive|define
name|OBQDBGEN_F
value|OBQDBGEN_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_IBQ_DBG_DATA_A
value|0x7b68
end_define

begin_define
define|#
directive|define
name|CIM_OBQ_DBG_DATA_A
value|0x7b6c
end_define

begin_define
define|#
directive|define
name|CIM_DEBUGCFG_A
value|0x7b70
end_define

begin_define
define|#
directive|define
name|CIM_DEBUGSTS_A
value|0x7b74
end_define

begin_define
define|#
directive|define
name|POLADBGRDPTR_S
value|23
end_define

begin_define
define|#
directive|define
name|POLADBGRDPTR_M
value|0x1ffU
end_define

begin_define
define|#
directive|define
name|POLADBGRDPTR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< POLADBGRDPTR_S)
end_define

begin_define
define|#
directive|define
name|POLADBGWRPTR_S
value|16
end_define

begin_define
define|#
directive|define
name|POLADBGWRPTR_M
value|0x1ffU
end_define

begin_define
define|#
directive|define
name|POLADBGWRPTR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> POLADBGWRPTR_S)& POLADBGWRPTR_M)
end_define

begin_define
define|#
directive|define
name|PILADBGRDPTR_S
value|14
end_define

begin_define
define|#
directive|define
name|PILADBGRDPTR_M
value|0x1ffU
end_define

begin_define
define|#
directive|define
name|PILADBGRDPTR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< PILADBGRDPTR_S)
end_define

begin_define
define|#
directive|define
name|PILADBGWRPTR_S
value|0
end_define

begin_define
define|#
directive|define
name|PILADBGWRPTR_M
value|0x1ffU
end_define

begin_define
define|#
directive|define
name|PILADBGWRPTR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PILADBGWRPTR_S)& PILADBGWRPTR_M)
end_define

begin_define
define|#
directive|define
name|LADBGEN_S
value|12
end_define

begin_define
define|#
directive|define
name|LADBGEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< LADBGEN_S)
end_define

begin_define
define|#
directive|define
name|LADBGEN_F
value|LADBGEN_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_PO_LA_DEBUGDATA_A
value|0x7b78
end_define

begin_define
define|#
directive|define
name|CIM_PI_LA_DEBUGDATA_A
value|0x7b7c
end_define

begin_define
define|#
directive|define
name|CIM_PO_LA_MADEBUGDATA_A
value|0x7b80
end_define

begin_define
define|#
directive|define
name|CIM_PI_LA_MADEBUGDATA_A
value|0x7b84
end_define

begin_define
define|#
directive|define
name|UPDBGLARDEN_S
value|1
end_define

begin_define
define|#
directive|define
name|UPDBGLARDEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPDBGLARDEN_S)
end_define

begin_define
define|#
directive|define
name|UPDBGLARDEN_F
value|UPDBGLARDEN_V(1U)
end_define

begin_define
define|#
directive|define
name|UPDBGLAEN_S
value|0
end_define

begin_define
define|#
directive|define
name|UPDBGLAEN_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPDBGLAEN_S)
end_define

begin_define
define|#
directive|define
name|UPDBGLAEN_F
value|UPDBGLAEN_V(1U)
end_define

begin_define
define|#
directive|define
name|UPDBGLARDPTR_S
value|2
end_define

begin_define
define|#
directive|define
name|UPDBGLARDPTR_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|UPDBGLARDPTR_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPDBGLARDPTR_S)
end_define

begin_define
define|#
directive|define
name|UPDBGLAWRPTR_S
value|16
end_define

begin_define
define|#
directive|define
name|UPDBGLAWRPTR_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|UPDBGLAWRPTR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> UPDBGLAWRPTR_S)& UPDBGLAWRPTR_M)
end_define

begin_define
define|#
directive|define
name|UPDBGLACAPTPCONLY_S
value|30
end_define

begin_define
define|#
directive|define
name|UPDBGLACAPTPCONLY_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< UPDBGLACAPTPCONLY_S)
end_define

begin_define
define|#
directive|define
name|UPDBGLACAPTPCONLY_F
value|UPDBGLACAPTPCONLY_V(1U)
end_define

begin_define
define|#
directive|define
name|CIM_QUEUE_CONFIG_REF_A
value|0x7b48
end_define

begin_define
define|#
directive|define
name|CIM_QUEUE_CONFIG_CTRL_A
value|0x7b4c
end_define

begin_define
define|#
directive|define
name|CIMQSIZE_S
value|24
end_define

begin_define
define|#
directive|define
name|CIMQSIZE_M
value|0x3fU
end_define

begin_define
define|#
directive|define
name|CIMQSIZE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> CIMQSIZE_S)& CIMQSIZE_M)
end_define

begin_define
define|#
directive|define
name|CIMQBASE_S
value|16
end_define

begin_define
define|#
directive|define
name|CIMQBASE_M
value|0x3fU
end_define

begin_define
define|#
directive|define
name|CIMQBASE_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> CIMQBASE_S)& CIMQBASE_M)
end_define

begin_define
define|#
directive|define
name|QUEFULLTHRSH_S
value|0
end_define

begin_define
define|#
directive|define
name|QUEFULLTHRSH_M
value|0x1ffU
end_define

begin_define
define|#
directive|define
name|QUEFULLTHRSH_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> QUEFULLTHRSH_S)& QUEFULLTHRSH_M)
end_define

begin_define
define|#
directive|define
name|UP_IBQ_0_RDADDR_A
value|0x10
end_define

begin_define
define|#
directive|define
name|UP_IBQ_0_SHADOW_RDADDR_A
value|0x280
end_define

begin_define
define|#
directive|define
name|UP_OBQ_0_REALADDR_A
value|0x104
end_define

begin_define
define|#
directive|define
name|UP_OBQ_0_SHADOW_REALADDR_A
value|0x394
end_define

begin_define
define|#
directive|define
name|IBQRDADDR_S
value|0
end_define

begin_define
define|#
directive|define
name|IBQRDADDR_M
value|0x1fffU
end_define

begin_define
define|#
directive|define
name|IBQRDADDR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> IBQRDADDR_S)& IBQRDADDR_M)
end_define

begin_define
define|#
directive|define
name|IBQWRADDR_S
value|0
end_define

begin_define
define|#
directive|define
name|IBQWRADDR_M
value|0x1fffU
end_define

begin_define
define|#
directive|define
name|IBQWRADDR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> IBQWRADDR_S)& IBQWRADDR_M)
end_define

begin_define
define|#
directive|define
name|QUERDADDR_S
value|0
end_define

begin_define
define|#
directive|define
name|QUERDADDR_M
value|0x7fffU
end_define

begin_define
define|#
directive|define
name|QUERDADDR_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> QUERDADDR_S)& QUERDADDR_M)
end_define

begin_define
define|#
directive|define
name|QUEREMFLITS_S
value|0
end_define

begin_define
define|#
directive|define
name|QUEREMFLITS_M
value|0x7ffU
end_define

begin_define
define|#
directive|define
name|QUEREMFLITS_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> QUEREMFLITS_S)& QUEREMFLITS_M)
end_define

begin_define
define|#
directive|define
name|QUEEOPCNT_S
value|16
end_define

begin_define
define|#
directive|define
name|QUEEOPCNT_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|QUEEOPCNT_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> QUEEOPCNT_S)& QUEEOPCNT_M)
end_define

begin_define
define|#
directive|define
name|QUESOPCNT_S
value|0
end_define

begin_define
define|#
directive|define
name|QUESOPCNT_M
value|0xfffU
end_define

begin_define
define|#
directive|define
name|QUESOPCNT_G
parameter_list|(
name|x
parameter_list|)
value|(((x)>> QUESOPCNT_S)& QUESOPCNT_M)
end_define

begin_define
define|#
directive|define
name|OBQSELECT_S
value|4
end_define

begin_define
define|#
directive|define
name|OBQSELECT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< OBQSELECT_S)
end_define

begin_define
define|#
directive|define
name|OBQSELECT_F
value|OBQSELECT_V(1U)
end_define

begin_define
define|#
directive|define
name|IBQSELECT_S
value|3
end_define

begin_define
define|#
directive|define
name|IBQSELECT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< IBQSELECT_S)
end_define

begin_define
define|#
directive|define
name|IBQSELECT_F
value|IBQSELECT_V(1U)
end_define

begin_define
define|#
directive|define
name|QUENUMSELECT_S
value|0
end_define

begin_define
define|#
directive|define
name|QUENUMSELECT_V
parameter_list|(
name|x
parameter_list|)
value|((x)<< QUENUMSELECT_S)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __T4_REGS_H */
end_comment

end_unit


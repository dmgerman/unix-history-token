begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/* \file cn23xx_pf_regs.h  * \brief Host Driver: Register Address and Register Mask values for  * CN23XX devices.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CN23XX_PF_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__CN23XX_PF_REGS_H__
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_CFG_PCIE_DEVCTL
value|0x78
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_CFG_PCIE_UNCORRECT_ERR_MASK
value|0x108
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_CFG_PCIE_CORRECT_ERR_STATUS
value|0x110
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_CFG_PCIE_DEVCTL_MASK
value|0x00040000
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PCIE_SRIOV_FDL
value|0x188
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PCIE_SRIOV_FDL_BIT_POS
value|0x10
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PCIE_SRIOV_FDL_MASK
value|0xFF
end_define

begin_comment
comment|/* ##############  BAR0 Registers ################ */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_CTL_PORT_START
value|0x286E0
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PORT_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_CTL_PORT
parameter_list|(
name|p
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_CTL_PORT_START +	\ 		 ((p) * LIO_CN23XX_PORT_OFFSET))
end_define

begin_comment
comment|/* 2 scatch registers (64-bit)  */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WINDOW_CTL
value|0x282E0
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_SCRATCH1
value|0x283C0
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_SCRATCH2
value|0x283D0
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WINDOW_CTL_DEFAULT
value|0x200000ULL
end_define

begin_comment
comment|/* 1 registers (64-bit)  - SLI_CTL_STATUS */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_CTL_STATUS
value|0x28570
end_define

begin_comment
comment|/*  * SLI Packet Input Jabber Register (64 bit register)  *<31:0> for Byte count for limiting sizes of packet sizes  * that are allowed for sli packet inbound packets.  * the default value is 0xFA00(=64000).  */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_IN_JABBER
value|0x29170
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_WR_ADDR_LO
value|0x20000
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_WR_ADDR64
value|LIO_CN23XX_SLI_WIN_WR_ADDR_LO
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_RD_ADDR_LO
value|0x20010
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_RD_ADDR_HI
value|0x20014
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_RD_ADDR64
value|LIO_CN23XX_SLI_WIN_RD_ADDR_LO
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_WR_DATA_LO
value|0x20020
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_WR_DATA_HI
value|0x20024
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_WR_DATA64
value|LIO_CN23XX_SLI_WIN_WR_DATA_LO
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_RD_DATA_LO
value|0x20040
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_RD_DATA_HI
value|0x20044
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_RD_DATA64
value|LIO_CN23XX_SLI_WIN_RD_DATA_LO
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_WIN_WR_MASK_REG
value|0x20030
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_MAC_CREDIT_CNT
value|0x23D70
end_define

begin_comment
comment|/*  * 4 registers (64-bit) for mapping IOQs to MACs(PEMs)-  * SLI_PKT_MAC(0..3)_PF(0..1)_RINFO  */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_MAC_RINFO_START64
value|0x29030
end_define

begin_comment
comment|/*1 register (64-bit) to determine whether IOQs are in reset. */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_IOQ_RING_RST
value|0x291E0
end_define

begin_comment
comment|/* Each Input Queue register is at a 16-byte Offset in BAR0 */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_IQ_OFFSET
value|0x20000
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_MAC_RINFO_OFFSET
value|0x20
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PF_RINFO_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_MAC_RINFO64
parameter_list|(
name|mac
parameter_list|,
name|pf
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_MAC_RINFO_START64 +		\ 		 ((mac) * LIO_CN23XX_MAC_RINFO_OFFSET) +	\ 		 ((pf) * LIO_CN23XX_PF_RINFO_OFFSET))
end_define

begin_comment
comment|/* mask for total rings, setting TRS to base */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_MAC_CTL_RINFO_TRS
value|BIT_ULL(16)
end_define

begin_comment
comment|/* Starting bit of the TRS field in LIO_CN23XX_SLI_PKT_MAC_RINFO64 register */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_MAC_CTL_RINFO_TRS_BIT_POS
value|16
end_define

begin_comment
comment|/*###################### REQUEST QUEUE #########################*/
end_comment

begin_comment
comment|/* 64 registers for Input Queue Instr Count - SLI_PKT_IN_DONE0_CNTS */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_IN_DONE_CNTS_START64
value|0x10040
end_define

begin_comment
comment|/* 64 registers for Input Queues Start Addr - SLI_PKT0_INSTR_BADDR */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_INSTR_BADDR_START64
value|0x10010
end_define

begin_comment
comment|/* 64 registers for Input Doorbell - SLI_PKT0_INSTR_BAOFF_DBELL */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_INSTR_BADDR_DBELL_START
value|0x10020
end_define

begin_comment
comment|/* 64 registers for Input Queue size - SLI_PKT0_INSTR_FIFO_RSIZE */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_INSTR_FIFO_RSIZE_START
value|0x10030
end_define

begin_comment
comment|/*  * 64 registers (64-bit) - ES, RO, NS, Arbitration for Input Queue Data&  * gather list fetches. SLI_PKT(0..63)_INPUT_CONTROL.  */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_INPUT_CONTROL_START64
value|0x10000
end_define

begin_comment
comment|/*------- Request Queue Macros ---------*/
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_IQ_PKT_CONTROL64
parameter_list|(
name|iq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_INPUT_CONTROL_START64 +		\ 		 ((iq) * LIO_CN23XX_IQ_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_IQ_BASE_ADDR64
parameter_list|(
name|iq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_INSTR_BADDR_START64 +		\ 		 ((iq) * LIO_CN23XX_IQ_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_IQ_SIZE
parameter_list|(
name|iq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_INSTR_FIFO_RSIZE_START +		\ 		 ((iq) * LIO_CN23XX_IQ_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_IQ_DOORBELL
parameter_list|(
name|iq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_INSTR_BADDR_DBELL_START +		\ 		 ((iq) * LIO_CN23XX_IQ_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_IQ_INSTR_COUNT64
parameter_list|(
name|iq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_IN_DONE_CNTS_START64 +		\ 		 ((iq) * LIO_CN23XX_IQ_OFFSET))
end_define

begin_comment
comment|/*------------------ Masks ----------------*/
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_VF_NUM
value|BIT_ULL(32)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_MAC_NUM
value|BIT(29)
end_define

begin_comment
comment|/*  * Number of instructions to be read in one MAC read request.  * setting to Max value(4)  */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_RDSIZE
value|(3<< 25)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_IS_64B
value|BIT(24)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_RST
value|BIT(23)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_QUIET
value|BIT(28)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_RING_ENB
value|BIT(22)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_DATA_ES_64B_SWAP
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_USE_CSR
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_GATHER_ES_64B_SWAP
value|(2)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_PF_NUM_POS
value|(45)
end_define

begin_comment
comment|/* These bits[43:32] select the function number within the PF */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_MAC_NUM_POS
value|(29)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_IN_DONE_WMARK_MASK
value|(0xFFFFULL)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_IN_DONE_WMARK_BIT_POS
value|(32)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_IN_DONE_CNT_MASK
value|0x00000000FFFFFFFFULL
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_MASK
define|\
value|(LIO_CN23XX_PKT_INPUT_CTL_RDSIZE		|	\ 		 LIO_CN23XX_PKT_INPUT_CTL_DATA_ES_64B_SWAP	|	\ 		 LIO_CN23XX_PKT_INPUT_CTL_USE_CSR)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BYTE_ORDER != LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_INPUT_CTL_MASK
define|\
value|(LIO_CN23XX_PKT_INPUT_CTL_RDSIZE		|	\ 		 LIO_CN23XX_PKT_INPUT_CTL_DATA_ES_64B_SWAP	|	\ 		 LIO_CN23XX_PKT_INPUT_CTL_USE_CSR		|	\ 		 LIO_CN23XX_PKT_INPUT_CTL_GATHER_ES_64B_SWAP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER == LITTLE_ENDIAN */
end_comment

begin_comment
comment|/*############################ OUTPUT QUEUE #########################*/
end_comment

begin_comment
comment|/* 64 registers for Output queue control - SLI_PKT(0..63)_OUTPUT_CONTROL */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_OUTPUT_CONTROL_START
value|0x10050
end_define

begin_comment
comment|/* 64 registers for Output queue buffer and info size - SLI_PKT0_OUT_SIZE */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_OUT_SIZE
value|0x10060
end_define

begin_comment
comment|/* 64 registers for Output Queue Start Addr - SLI_PKT0_SLIST_BADDR */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_SLIST_BADDR_START64
value|0x10070
end_define

begin_comment
comment|/* 64 registers for Output Queue Packet Credits - SLI_PKT0_SLIST_BAOFF_DBELL */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_SLIST_BAOFF_DBELL_START
value|0x10080
end_define

begin_comment
comment|/* 64 registers for Output Queue size - SLI_PKT0_SLIST_FIFO_RSIZE */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_SLIST_FIFO_RSIZE_START
value|0x10090
end_define

begin_comment
comment|/* 64 registers for Output Queue Packet Count - SLI_PKT0_CNTS */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_CNTS_START
value|0x100B0
end_define

begin_comment
comment|/* 64 registers for Output Queue INT Levels - SLI_PKT0_INT_LEVELS */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_INT_LEVELS_START64
value|0x100A0
end_define

begin_comment
comment|/* Each Output Queue register is at a 16-byte Offset in BAR0 */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_OQ_OFFSET
value|0x20000
end_define

begin_comment
comment|/* 1 (64-bit register) for Output Queue backpressure across all rings. */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_OQ_WMARK
value|0x29180
end_define

begin_comment
comment|/* Global pkt control register */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_GBL_CONTROL
value|0x29210
end_define

begin_comment
comment|/* Backpressure enable register for PF0  */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_OUT_BP_EN_W1S
value|0x29260
end_define

begin_comment
comment|/* Backpressure enable register for PF1  */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_OUT_BP_EN2_W1S
value|0x29270
end_define

begin_comment
comment|/*------- Output Queue Macros ---------*/
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_OQ_PKT_CONTROL
parameter_list|(
name|oq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_OUTPUT_CONTROL_START +		\ 		 ((oq) * LIO_CN23XX_OQ_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_OQ_BASE_ADDR64
parameter_list|(
name|oq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_SLIST_BADDR_START64 +			\ 		 ((oq) * LIO_CN23XX_OQ_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_OQ_SIZE
parameter_list|(
name|oq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_SLIST_FIFO_RSIZE_START +		\ 		 ((oq) * LIO_CN23XX_OQ_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_OQ_BUFF_INFO_SIZE
parameter_list|(
name|oq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_OUT_SIZE +				\ 		 ((oq) * LIO_CN23XX_OQ_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_OQ_PKTS_SENT
parameter_list|(
name|oq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_CNTS_START +			\ 		 ((oq) * LIO_CN23XX_OQ_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_OQ_PKTS_CREDIT
parameter_list|(
name|oq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_SLIST_BAOFF_DBELL_START +		\ 		 ((oq) * LIO_CN23XX_OQ_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_OQ_PKT_INT_LEVELS
parameter_list|(
name|oq
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_PKT_INT_LEVELS_START64 +		\ 		 ((oq) * LIO_CN23XX_OQ_OFFSET))
end_define

begin_comment
comment|/*------------------ Masks ----------------*/
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_TENB
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_CENB
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_IPTR
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_ES
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_NSR
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_ROR
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_DPTR
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_BMODE
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_ES_P
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_NSR_P
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_ROR_P
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PKT_OUTPUT_CTL_RING_ENB
value|BIT(0)
end_define

begin_comment
comment|/*######################## MSIX TABLE #########################*/
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_MSIX_TABLE_ADDR_START
value|0x0
end_define

begin_define
define|#
directive|define
name|CN23XX_MSIX_TABLE_DATA_START
value|0x8
end_define

begin_define
define|#
directive|define
name|CN23XX_MSIX_TABLE_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|CN23XX_MSIX_TABLE_ADDR
parameter_list|(
name|idx
parameter_list|)
define|\
value|(LIO_CN23XX_MSIX_TABLE_ADDR_START +	\ 	 ((idx) * LIO_CN23XX_MSIX_TABLE_SIZE))
end_define

begin_define
define|#
directive|define
name|CN23XX_MSIX_TABLE_DATA
parameter_list|(
name|idx
parameter_list|)
define|\
value|(LIO_CN23XX_MSIX_TABLE_DATA_START +	\ 	 ((idx) * LIO_CN23XX_MSIX_TABLE_SIZE))
end_define

begin_comment
comment|/*######################## INTERRUPTS #########################*/
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_MAC_INT_OFFSET
value|0x20
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PF_INT_OFFSET
value|0x10
end_define

begin_comment
comment|/* 1 register (64-bit) for Interrupt Summary */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_INT_SUM64
value|0x27000
end_define

begin_comment
comment|/* 4 registers (64-bit) for Interrupt Enable for each Port */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_INT_ENB64
value|0x27080
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_MAC_PF_INT_SUM64
parameter_list|(
name|mac
parameter_list|,
name|pf
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_INT_SUM64 +				\ 		 ((mac) * LIO_CN23XX_MAC_INT_OFFSET) +			\ 		 ((pf) * LIO_CN23XX_PF_INT_OFFSET))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_MAC_PF_INT_ENB64
parameter_list|(
name|mac
parameter_list|,
name|pf
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_INT_ENB64 +				\ 		 ((mac) * LIO_CN23XX_MAC_INT_OFFSET) +			\ 		 ((pf) * LIO_CN23XX_PF_INT_OFFSET))
end_define

begin_comment
comment|/* 1 register (64-bit) to indicate which Output Queue reached pkt threshold */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_CNT_INT
value|0x29130
end_define

begin_comment
comment|/* 1 register (64-bit) to indicate which Output Queue reached time threshold */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_PKT_TIME_INT
value|0x29140
end_define

begin_comment
comment|/*------------------ Interrupt Masks ----------------*/
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_PO_INT
value|BIT_ULL(63)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_PI_INT
value|BIT_ULL(62)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_RESEND
value|BIT_ULL(60)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_CINT_ENB
value|BIT_ULL(48)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_MIO_INT
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_PKT_TIME
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_M0UPB0_ERR
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_M0UPWI_ERR
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_M0UNB0_ERR
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_M0UNWI_ERR
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_DMA0_FORCE
value|BIT_ULL(32)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_DMA1_FORCE
value|BIT_ULL(33)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_DMA0_TIME
value|BIT_ULL(36)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_DMA1_TIME
value|BIT_ULL(37)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_DMAPF_ERR
value|BIT_ULL(59)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_PKTPF_ERR
value|BIT_ULL(61)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_PPPF_ERR
value|BIT_ULL(63)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_DMA0_DATA
value|(LIO_CN23XX_INTR_DMA0_TIME)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_DMA1_DATA
value|(LIO_CN23XX_INTR_DMA1_TIME)
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_DMA_DATA
define|\
value|(LIO_CN23XX_INTR_DMA0_DATA | LIO_CN23XX_INTR_DMA1_DATA)
end_define

begin_comment
comment|/* By fault only TIME based */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_PKT_DATA
value|(LIO_CN23XX_INTR_PKT_TIME)
end_define

begin_comment
comment|/* Sum of interrupts for error events */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_ERR
define|\
value|(LIO_CN23XX_INTR_M0UPB0_ERR	|	\ 		 LIO_CN23XX_INTR_M0UPWI_ERR	|	\ 		 LIO_CN23XX_INTR_M0UNB0_ERR	|	\ 		 LIO_CN23XX_INTR_M0UNWI_ERR	|	\ 		 LIO_CN23XX_INTR_DMAPF_ERR	|	\ 		 LIO_CN23XX_INTR_PKTPF_ERR	|	\ 		 LIO_CN23XX_INTR_PPPF_ERR)
end_define

begin_comment
comment|/* Programmed Mask for Interrupt Sum */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_INTR_MASK
define|\
value|(LIO_CN23XX_INTR_DMA_DATA	|	\ 		 LIO_CN23XX_INTR_DMA0_FORCE	|	\ 		 LIO_CN23XX_INTR_DMA1_FORCE	|	\ 		 LIO_CN23XX_INTR_MIO_INT	|	\ 		 LIO_CN23XX_INTR_ERR)
end_define

begin_comment
comment|/* 4 Registers (64 - bit) */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_S2M_PORT_CTL_START
value|0x23D80
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_S2M_PORTX_CTL
parameter_list|(
name|port
parameter_list|)
define|\
value|(LIO_CN23XX_SLI_S2M_PORT_CTL_START +	\ 		 ((port) * 0x10))
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_SLI_MAC_NUMBER
value|0x20050
end_define

begin_comment
comment|/*  *  PEM(0..3)_BAR1_INDEX(0..15)address is defined as  *  addr = (0x00011800C0000100  |port<<24 |idx<<3 )  *  Here, port is PEM(0..3)& idx is INDEX(0..15)  */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_PEM_BAR1_INDEX_START
value|0x00011800C0000100ULL
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PEM_OFFSET
value|24
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_BAR1_INDEX_OFFSET
value|3
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_PEM_BAR1_INDEX_REG
parameter_list|(
name|port
parameter_list|,
name|idx
parameter_list|)
define|\
value|(LIO_CN23XX_PEM_BAR1_INDEX_START +		\ 		 ((port)<< LIO_CN23XX_PEM_OFFSET) +		\ 		 ((idx)<< LIO_CN23XX_BAR1_INDEX_OFFSET))
end_define

begin_comment
comment|/*############################ DPI #########################*/
end_comment

begin_comment
comment|/* 4 Registers (64-bit) */
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_DPI_SLI_PRT_CFG_START
value|0x0001df0000000900ULL
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_DPI_SLI_PRTX_CFG
parameter_list|(
name|port
parameter_list|)
define|\
value|((IO_CN23XX_DPI_SLI_PRT_CFG_START +	\ 		 ((port) * 0x8))
end_define

begin_comment
comment|/*############################ RST #########################*/
end_comment

begin_define
define|#
directive|define
name|LIO_CN23XX_RST_BOOT
value|0x0001180006001600ULL
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_RST_SOFT_RST
value|0x0001180006001680ULL
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_LMC0_RESET_CTL
value|0x0001180088000180ULL
end_define

begin_define
define|#
directive|define
name|LIO_CN23XX_LMC0_RESET_CTL_DDR3RST_MASK
value|0x0000000000000001ULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CN23XX_PF_REGS_H__ */
end_comment

end_unit


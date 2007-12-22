begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  *  * Fore HE driver for NATM  */
end_comment

begin_comment
comment|/* check configuration */
end_comment

begin_if
if|#
directive|if
name|HE_CONFIG_VPI_BITS
operator|+
name|HE_CONFIG_VCI_BITS
operator|>
literal|12
end_if

begin_error
error|#
directive|error
literal|"hatm: too many bits configured for VPI/VCI"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HE_MAX_VCCS
value|(1<< (HE_CONFIG_VPI_BITS + HE_CONFIG_VCI_BITS))
end_define

begin_define
define|#
directive|define
name|HE_VPI_MASK
value|((1<< (HE_CONFIG_VPI_BITS))-1)
end_define

begin_define
define|#
directive|define
name|HE_VCI_MASK
value|((1<< (HE_CONFIG_VCI_BITS))-1)
end_define

begin_define
define|#
directive|define
name|HE_VPI
parameter_list|(
name|CID
parameter_list|)
value|(((CID)>> HE_CONFIG_VCI_BITS)& HE_VPI_MASK)
end_define

begin_define
define|#
directive|define
name|HE_VCI
parameter_list|(
name|CID
parameter_list|)
value|((CID)& HE_VCI_MASK)
end_define

begin_define
define|#
directive|define
name|HE_CID
parameter_list|(
name|VPI
parameter_list|,
name|VCI
parameter_list|)
value|((((VPI)& HE_VPI_MASK)<< HE_CONFIG_VCI_BITS) | \ 	((VCI)& HE_VCI_MASK))
end_define

begin_comment
comment|/* GEN_CNTL_0 register */
end_comment

begin_define
define|#
directive|define
name|HE_PCIR_GEN_CNTL_0
value|0x40
end_define

begin_define
define|#
directive|define
name|HE_PCIM_CTL0_64BIT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HE_PCIM_CTL0_IGNORE_TIMEOUT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HE_PCIM_CTL0_INIT_ENB
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|HE_PCIM_CTL0_MRM
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HE_PCIM_CTL0_MRL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|HE_PCIM_CTL0_BIGENDIAN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|HE_PCIM_CTL0_INT_PROC_ENB
value|(1<< 25)
end_define

begin_comment
comment|/*  * Memory registers  */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_FLASH
value|0x00000
end_define

begin_define
define|#
directive|define
name|HE_REGO_RESET_CNTL
value|0x80000
end_define

begin_define
define|#
directive|define
name|HE_REGM_RESET_STATE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|HE_REGO_HOST_CNTL
value|0x80004
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_BUS64
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_DESC_RD64
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_DATA_RD64
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_DATA_WR64
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_PROM_SEL
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_PROM_WREN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_PROM_DATA_OUT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HE_REGS_HOST_PROM_DATA_OUT
value|10
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_PROM_DATA_IN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HE_REGS_HOST_PROM_DATA_IN
value|9
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_PROM_CLOCK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_PROM_BITS
value|(0x00001f00)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_QUICK_RD
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_QUICK_WR
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_OUTFF_ENB
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|HE_REGM_HOST_CMDFF_ENB
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HE_REGO_LB_SWAP
value|0x80008
end_define

begin_define
define|#
directive|define
name|HE_REGM_LBSWAP_RNUM
value|(0xf<< 27)
end_define

begin_define
define|#
directive|define
name|HE_REGS_LBSWAP_RNUM
value|27
end_define

begin_define
define|#
directive|define
name|HE_REGM_LBSWAP_DATA_WR_SWAP
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|HE_REGM_LBSWAP_DESC_RD_SWAP
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|HE_REGM_LBSWAP_DATA_RD_SWAP
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|HE_REGM_LBSWAP_INTR_SWAP
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|HE_REGM_LBSWAP_DESC_WR_SWAP
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|HE_REGM_LBSWAP_BIG_ENDIAN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|HE_REGM_LBSWAP_XFER_SIZE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|HE_REGO_LB_MEM_ADDR
value|0x8000C
end_define

begin_define
define|#
directive|define
name|HE_REGO_LB_MEM_DATA
value|0x80010
end_define

begin_define
define|#
directive|define
name|HE_REGO_LB_MEM_ACCESS
value|0x80014
end_define

begin_define
define|#
directive|define
name|HE_REGM_LB_MEM_HNDSHK
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|HE_REGM_LB_MEM_READ
value|0x3
end_define

begin_define
define|#
directive|define
name|HE_REGM_LB_MEM_WRITE
value|0x7
end_define

begin_define
define|#
directive|define
name|HE_REGO_SDRAM_CNTL
value|0x80018
end_define

begin_define
define|#
directive|define
name|HE_REGM_SDRAM_64BIT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|HE_REGO_INT_FIFO
value|0x8001C
end_define

begin_define
define|#
directive|define
name|HE_REGM_INT_FIFO_CLRA
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HE_REGM_INT_FIFO_CLRB
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HE_REGM_INT_FIFO_CLRC
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HE_REGM_INT_FIFO_CLRD
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|HE_REGO_ABORT_ADDR
value|0x80020
end_define

begin_define
define|#
directive|define
name|HE_REGO_IRQ0_BASE
value|0x80080
end_define

begin_define
define|#
directive|define
name|HE_REGO_IRQ_BASE
parameter_list|(
name|Q
parameter_list|)
value|(HE_REGO_IRQ0_BASE + (Q) * 0x10 + 0x00)
end_define

begin_define
define|#
directive|define
name|HE_REGM_IRQ_BASE_TAIL
value|0x3ff
end_define

begin_define
define|#
directive|define
name|HE_REGO_IRQ_HEAD
parameter_list|(
name|Q
parameter_list|)
value|(HE_REGO_IRQ0_BASE + (Q) * 0x10 + 0x04)
end_define

begin_define
define|#
directive|define
name|HE_REGS_IRQ_HEAD_SIZE
value|22
end_define

begin_define
define|#
directive|define
name|HE_REGS_IRQ_HEAD_THRESH
value|12
end_define

begin_define
define|#
directive|define
name|HE_REGS_IRQ_HEAD_HEAD
value|2
end_define

begin_define
define|#
directive|define
name|HE_REGO_IRQ_CNTL
parameter_list|(
name|Q
parameter_list|)
value|(HE_REGO_IRQ0_BASE + (Q) * 0x10 + 0x08)
end_define

begin_define
define|#
directive|define
name|HE_REGM_IRQ_A
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|HE_REGM_IRQ_B
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|HE_REGM_IRQ_C
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|HE_REGM_IRQ_D
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|HE_REGO_IRQ_DATA
parameter_list|(
name|Q
parameter_list|)
value|(HE_REGO_IRQ0_BASE + (Q) * 0x10 + 0x0C)
end_define

begin_define
define|#
directive|define
name|HE_REGO_GRP_1_0_MAP
value|0x800C0
end_define

begin_define
define|#
directive|define
name|HE_REGO_GRP_3_2_MAP
value|0x800C4
end_define

begin_define
define|#
directive|define
name|HE_REGO_GRP_5_4_MAP
value|0x800C8
end_define

begin_define
define|#
directive|define
name|HE_REGO_GRP_7_6_MAP
value|0x800CC
end_define

begin_comment
comment|/*  * Receive buffer pools  */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_G0_RBPS_S
value|0x80400
end_define

begin_define
define|#
directive|define
name|HE_REGO_G0_RBPS_T
value|0x80404
end_define

begin_define
define|#
directive|define
name|HE_REGO_G0_RBPS_QI
value|0x80408
end_define

begin_define
define|#
directive|define
name|HE_REGO_G0_RBPS_BL
value|0x8040C
end_define

begin_define
define|#
directive|define
name|HE_REGO_RBP_S
parameter_list|(
name|K
parameter_list|,
name|G
parameter_list|)
value|(HE_REGO_G0_RBPS_S + (K) * 0x10 + (G) * 0x20)
end_define

begin_define
define|#
directive|define
name|HE_REGO_RBP_T
parameter_list|(
name|K
parameter_list|,
name|G
parameter_list|)
value|(HE_REGO_G0_RBPS_T + (K) * 0x10 + (G) * 0x20)
end_define

begin_define
define|#
directive|define
name|HE_REGO_RBP_QI
parameter_list|(
name|K
parameter_list|,
name|G
parameter_list|)
value|(HE_REGO_G0_RBPS_QI + (K) * 0x10 + (G) * 0x20)
end_define

begin_define
define|#
directive|define
name|HE_REGO_RBP_BL
parameter_list|(
name|K
parameter_list|,
name|G
parameter_list|)
value|(HE_REGO_G0_RBPS_BL + (K) * 0x10 + (G) * 0x20)
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBP_HEAD
value|3
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBP_TAIL
value|3
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBP_SIZE
value|14
end_define

begin_define
define|#
directive|define
name|HE_REGM_RBP_INTR_ENB
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBP_THRESH
value|0
end_define

begin_comment
comment|/*  * Receive buffer return queues  */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_G0_RBRQ_ST
value|0x80500
end_define

begin_define
define|#
directive|define
name|HE_REGO_G0_RBRQ_H
value|0x80504
end_define

begin_define
define|#
directive|define
name|HE_REGO_G0_RBRQ_Q
value|0x80508
end_define

begin_define
define|#
directive|define
name|HE_REGO_G0_RBRQ_I
value|0x8050C
end_define

begin_define
define|#
directive|define
name|HE_REGO_RBRQ_ST
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_G0_RBRQ_ST + (G) * 0x10)
end_define

begin_define
define|#
directive|define
name|HE_REGO_RBRQ_H
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_G0_RBRQ_H + (G) * 0x10)
end_define

begin_define
define|#
directive|define
name|HE_REGO_RBRQ_Q
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_G0_RBRQ_Q + (G) * 0x10)
end_define

begin_define
define|#
directive|define
name|HE_REGO_RBRQ_I
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_G0_RBRQ_I + (G) * 0x10)
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBRQ_HEAD
value|3
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBRQ_THRESH
value|13
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBRQ_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBRQ_TIME
value|8
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBRQ_COUNT
value|0
end_define

begin_comment
comment|/*  * Intermediate queues  */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_G0_INMQ_S
value|0x80580
end_define

begin_define
define|#
directive|define
name|HE_REGO_G0_INMQ_L
value|0x80584
end_define

begin_define
define|#
directive|define
name|HE_REGO_INMQ_S
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_G0_INMQ_S + (G) * 8)
end_define

begin_define
define|#
directive|define
name|HE_REGO_INMQ_L
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_G0_INMQ_L + (G) * 8)
end_define

begin_define
define|#
directive|define
name|HE_REGO_RHCONFIG
value|0x805C0
end_define

begin_define
define|#
directive|define
name|HE_REGM_RHCONFIG_PHYENB
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HE_REGS_RHCONFIG_OAM_GID
value|7
end_define

begin_define
define|#
directive|define
name|HE_REGS_RHCONFIG_PTMR_PRE
value|0
end_define

begin_comment
comment|/*  * Transmit buffer return queues  */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_TBRQ0_B_T
value|0x80600
end_define

begin_define
define|#
directive|define
name|HE_REGO_TBRQ0_H
value|0x80604
end_define

begin_define
define|#
directive|define
name|HE_REGO_TBRQ0_S
value|0x80608
end_define

begin_define
define|#
directive|define
name|HE_REGO_TBRQ0_THRESH
value|0x8060C
end_define

begin_define
define|#
directive|define
name|HE_REGO_TBRQ_B_T
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_TBRQ0_B_T + (G) * 0x10)
end_define

begin_define
define|#
directive|define
name|HE_REGO_TBRQ_H
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_TBRQ0_H + (G) * 0x10)
end_define

begin_define
define|#
directive|define
name|HE_REGO_TBRQ_S
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_TBRQ0_S + (G) * 0x10)
end_define

begin_define
define|#
directive|define
name|HE_REGO_TBRQ_THRESH
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_TBRQ0_THRESH + (G) * 0x10)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TBRQ_HEAD
value|2
end_define

begin_comment
comment|/*  * Transmit packet descriptor ready queue  */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_TPDRQ_H
value|0x80680
end_define

begin_define
define|#
directive|define
name|HE_REGS_TPDRQ_H_H
value|3
end_define

begin_comment
comment|/* #define HE_REGM_TPDRQ_H_H	((HE_CONFIG_TPDRQ_SIZE - 1)<< 3) */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_TPDRQ_T
value|0x80684
end_define

begin_define
define|#
directive|define
name|HE_REGS_TPDRQ_T_T
value|3
end_define

begin_comment
comment|/* #define HE_REGM_TPDRQ_T_T	((HE_CONFIG_TPDRQ_SIZE - 1)<< 3) */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_TPDRQ_S
value|0x80688
end_define

begin_define
define|#
directive|define
name|HE_REGO_UBUFF_BA
value|0x8068C
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBF0_H
value|0x806C0
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBF0_T
value|0x806C4
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBF1_H
value|0x806C8
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBF1_T
value|0x806CC
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBF_H
parameter_list|(
name|N
parameter_list|)
value|(HE_REGO_RLBF0_H + (N) * 8)
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBF_T
parameter_list|(
name|N
parameter_list|)
value|(HE_REGO_RLBF0_T + (N) * 8)
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBC_H
value|0x806D0
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBC_T
value|0x806D4
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBC_H2
value|0x806D8
end_define

begin_define
define|#
directive|define
name|HE_REGO_TLBF_H
value|0x806E0
end_define

begin_define
define|#
directive|define
name|HE_REGO_TLBF_T
value|0x806E4
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBF0_C
value|0x806E8
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBF1_C
value|0x806EC
end_define

begin_define
define|#
directive|define
name|HE_REGO_RLBF_C
parameter_list|(
name|N
parameter_list|)
value|(HE_REGO_RLBF0_C + (N) * 4)
end_define

begin_define
define|#
directive|define
name|HE_REGO_RXTHRSH
value|0x806F0
end_define

begin_define
define|#
directive|define
name|HE_REGO_LITHRSH
value|0x806F4
end_define

begin_define
define|#
directive|define
name|HE_REGO_LBARB
value|0x80700
end_define

begin_define
define|#
directive|define
name|HE_REGS_LBARB_SLICE
value|28
end_define

begin_define
define|#
directive|define
name|HE_REGS_LBARB_RNUM
value|23
end_define

begin_define
define|#
directive|define
name|HE_REGS_LBARB_THPRI
value|21
end_define

begin_define
define|#
directive|define
name|HE_REGS_LBARB_RHPRI
value|19
end_define

begin_define
define|#
directive|define
name|HE_REGS_LBARB_TLPRI
value|17
end_define

begin_define
define|#
directive|define
name|HE_REGS_LBARB_RLPRI
value|15
end_define

begin_define
define|#
directive|define
name|HE_REGS_LBARB_BUS_MULT
value|8
end_define

begin_define
define|#
directive|define
name|HE_REGS_LBARB_NET_PREF
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGO_SDRAMCON
value|0x80704
end_define

begin_define
define|#
directive|define
name|HE_REGM_SDRAMCON_BANK
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|HE_REGM_SDRAMCON_WIDE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|HE_REGM_SDRAMCON_TWRWAIT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|HE_REGM_SDRAMCON_TRPWAIT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|HE_REGM_SDRAMCON_TRASWAIT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HE_REGS_SDRAMCON_REF
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGO_RCCSTAT
value|0x8070C
end_define

begin_define
define|#
directive|define
name|HE_REGM_RCCSTAT_PROG
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HE_REGO_TCMCONFIG
value|0x80740
end_define

begin_define
define|#
directive|define
name|HE_REGS_TCMCONFIG_BANK_WAIT
value|6
end_define

begin_define
define|#
directive|define
name|HE_REGS_TCMCONFIG_RW_WAIT
value|2
end_define

begin_define
define|#
directive|define
name|HE_REGS_TCMCONFIG_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGO_TSRB_BA
value|0x80744
end_define

begin_define
define|#
directive|define
name|HE_REGO_TSRC_BA
value|0x80748
end_define

begin_define
define|#
directive|define
name|HE_REGO_TMABR_BA
value|0x8074C
end_define

begin_define
define|#
directive|define
name|HE_REGO_TPD_BA
value|0x80750
end_define

begin_define
define|#
directive|define
name|HE_REGO_TSRD_BA
value|0x80758
end_define

begin_define
define|#
directive|define
name|HE_REGO_TXCONFIG
value|0x80760
end_define

begin_define
define|#
directive|define
name|HE_REGS_TXCONFIG_THRESH
value|22
end_define

begin_define
define|#
directive|define
name|HE_REGM_TXCONFIG_UTMODE
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TXCONFIG_VCI_MASK
value|17
end_define

begin_define
define|#
directive|define
name|HE_REGS_TXCONFIG_LBFREE
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGO_TXAAL5_PROTO
value|0x80764
end_define

begin_define
define|#
directive|define
name|HE_REGO_RCMCONFIG
value|0x80780
end_define

begin_define
define|#
directive|define
name|HE_REGS_RCMCONFIG_BANK_WAIT
value|6
end_define

begin_define
define|#
directive|define
name|HE_REGS_RCMCONFIG_RW_WAIT
value|2
end_define

begin_define
define|#
directive|define
name|HE_REGS_RCMCONFIG_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGO_RCMRSRB_BA
value|0x80784
end_define

begin_define
define|#
directive|define
name|HE_REGO_RCMLBM_BA
value|0x80788
end_define

begin_define
define|#
directive|define
name|HE_REGO_RCMABR_BA
value|0x8078C
end_define

begin_define
define|#
directive|define
name|HE_REGO_RCCONFIG
value|0x807C0
end_define

begin_define
define|#
directive|define
name|HE_REGS_RCCONFIG_UTDELAY
value|11
end_define

begin_define
define|#
directive|define
name|HE_REGM_RCCONFIG_WRAP_MODE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RCCONFIG_UT_MODE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RCCONFIG_RXENB
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HE_REGS_RCCONFIG_VP
value|4
end_define

begin_define
define|#
directive|define
name|HE_REGS_RCCONFIG_VC
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGO_MCC
value|0x807C4
end_define

begin_define
define|#
directive|define
name|HE_REGO_OEC
value|0x807C8
end_define

begin_define
define|#
directive|define
name|HE_REGO_DCC
value|0x807CC
end_define

begin_define
define|#
directive|define
name|HE_REGO_CEC
value|0x807D0
end_define

begin_define
define|#
directive|define
name|HE_REGO_HSP_BA
value|0x807F0
end_define

begin_define
define|#
directive|define
name|HE_REGO_LBCONFIG
value|0x807F4
end_define

begin_define
define|#
directive|define
name|HE_REGO_CON_DAT
value|0x807F8
end_define

begin_define
define|#
directive|define
name|HE_REGO_CON_CTL
value|0x807FC
end_define

begin_define
define|#
directive|define
name|HE_REGM_CON_MBOX
value|(2<< 30)
end_define

begin_define
define|#
directive|define
name|HE_REGM_CON_TCM
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|HE_REGM_CON_RCM
value|(0<< 30)
end_define

begin_define
define|#
directive|define
name|HE_REGM_CON_WE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|HE_REGM_CON_STATUS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|HE_REGM_CON_DIS3
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|HE_REGM_CON_DIS2
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|HE_REGM_CON_DIS1
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|HE_REGM_CON_DIS0
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|HE_REGS_CON_DIS
value|19
end_define

begin_define
define|#
directive|define
name|HE_REGS_CON_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGO_SUNI
value|0x80800
end_define

begin_define
define|#
directive|define
name|HE_REGO_SUNI_END
value|0x80C00
end_define

begin_define
define|#
directive|define
name|HE_REGO_END
value|0x100000
end_define

begin_comment
comment|/*  * MBOX registers  */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_CS_STPER0
value|0x000
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_STPER
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_CS_STPER0 + (G))
end_define

begin_define
define|#
directive|define
name|HE_REGN_CS_STPER
value|32
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_STTIM0
value|0x020
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_STTIM
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_CS_STTIM0 + (G))
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_TGRLD0
value|0x040
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_TGRLD
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_CS_TGRLD0 + (G))
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ERTHR0
value|0x50
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ERTHR1
value|0x51
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ERTHR2
value|0x52
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ERTHR3
value|0x53
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ERTHR4
value|0x54
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ERCTL0
value|0x55
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ERCTL1
value|0x56
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ERCTL2
value|0x57
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ERSTAT0
value|0x58
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ERSTAT1
value|0x59
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_RTCCT
value|0x60
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_RTFWC
value|0x61
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_RTFWR
value|0x62
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_RTFTC
value|0x63
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_RTATR
value|0x64
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_TFBSET
value|0x70
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_TFBADD
value|0x71
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_TFBSUB
value|0x72
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_WCRMAX
value|0x73
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_WCRMIN
value|0x74
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_WCRINC
value|0x75
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_WCRDEC
value|0x76
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_WCRCEIL
value|0x77
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_BWDCNT
value|0x78
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_OTPPER
value|0x80
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_OTWPER
value|0x81
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_OTTLIM
value|0x82
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_OTTCNT
value|0x83
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_HGRRT0
value|0x90
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_HGRRT
parameter_list|(
name|G
parameter_list|)
value|(HE_REGO_CS_HGRRT0 + (G))
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_ORPTRS
value|0xA0
end_define

begin_define
define|#
directive|define
name|HE_REGO_RCON_CLOSE
value|0x100
end_define

begin_define
define|#
directive|define
name|HE_REGO_CS_END
value|0x101
end_define

begin_define
define|#
directive|define
name|HE_REGT_CS_ERTHR
value|{						\ 	{
comment|/* 155 */
value|\ 	  { 0x000800ea, 0x000400ea, 0x000200ea },
comment|/* ERTHR0 */
value|\ 	  { 0x000C3388, 0x00063388, 0x00033388 },
comment|/* ERTHR1 */
value|\ 	  { 0x00101018, 0x00081018, 0x00041018 },
comment|/* ERTHR2 */
value|\ 	  { 0x00181dac, 0x000c1dac, 0x00061dac },
comment|/* ERTHR3 */
value|\ 	  { 0x0028051a, 0x0014051a, 0x000a051a },
comment|/* ERTHR4 */
value|\ 	}, {
comment|/* 622 */
value|\ 	  { 0x000800fa, 0x000400fa, 0x000200fa },
comment|/* ERTHR0 */
value|\ 	  { 0x000c33cb, 0x000633cb, 0x000333cb },
comment|/* ERTHR1 */
value|\ 	  { 0x0010101b, 0x0008101b, 0x0004101b },
comment|/* ERTHR2 */
value|\ 	  { 0x00181dac, 0x000c1dac, 0x00061dac },
comment|/* ERTHR3 */
value|\ 	  { 0x00280600, 0x00140600, 0x000a0600 },
comment|/* ERTHR4 */
value|\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|HE_REGT_CS_ERCTL
value|{						\ 	{ 0x0235e4b1, 0x4701, 0x64b1 },
comment|/* 155 */
value|\ 	{ 0x023de8b3, 0x1801, 0x68b3 }
comment|/* 622 */
value|\ }
end_define

begin_define
define|#
directive|define
name|HE_REGT_CS_ERSTAT
value|{						\ 	{ 0x1280, 0x64b1 },
comment|/* 155 */
value|\ 	{ 0x1280, 0x68b3 },
comment|/* 622 */
value|\ }
end_define

begin_define
define|#
directive|define
name|HE_REGT_CS_RTFWR
value|{						\ 	0xf424,
comment|/* 155 */
value|\ 	0x14585
comment|/* 622 */
value|\ }
end_define

begin_define
define|#
directive|define
name|HE_REGT_CS_RTATR
value|{						\ 	0x4680,
comment|/* 155 */
value|\ 	0x4680
comment|/* 622 */
value|\ }
end_define

begin_define
define|#
directive|define
name|HE_REGT_CS_BWALLOC
value|{						\ 	{ 0x000563b7, 0x64b1, 0x5ab1, 0xe4b1, 0xdab1, 0x64b1 },
comment|/* 155 */
value|\ 	{ 0x00159ece, 0x68b3, 0x5eb3, 0xe8b3, 0xdeb3, 0x68b3 },
comment|/* 622 */
value|\ }
end_define

begin_define
define|#
directive|define
name|HE_REGT_CS_ORCF
value|{						\ 	{ 0x6, 0x1e },
comment|/* 155 */
value|\ 	{ 0x5, 0x14 }
comment|/* 622 */
value|\ }
end_define

begin_comment
comment|/*   * TSRs - NR is relative to the starting number of the block  */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_TSRA
parameter_list|(
name|BASE
parameter_list|,
name|CID
parameter_list|,
name|NR
parameter_list|)
value|((BASE) + ((CID)<< 3) + (NR))
end_define

begin_define
define|#
directive|define
name|HE_REGO_TSRB
parameter_list|(
name|BASE
parameter_list|,
name|CID
parameter_list|,
name|NR
parameter_list|)
value|((BASE) + ((CID)<< 2) + (NR))
end_define

begin_define
define|#
directive|define
name|HE_REGO_TSRC
parameter_list|(
name|BASE
parameter_list|,
name|CID
parameter_list|,
name|NR
parameter_list|)
value|((BASE) + ((CID)<< 1) + (NR))
end_define

begin_define
define|#
directive|define
name|HE_REGO_TSRD
parameter_list|(
name|BASE
parameter_list|,
name|CID
parameter_list|)
value|((BASE) + (CID))
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_CONN_STATE
value|(7<< 28)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR0_CONN_STATE
value|28
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_USE_WMIN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_GROUP
value|(7<< 18)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR0_GROUP
value|18
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_TRAFFIC
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR0_TRAFFIC
value|16
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_TRAFFIC_CBR
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_TRAFFIC_UBR
value|1
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_TRAFFIC_ABR
value|2
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_PROT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_AAL
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR0_AAL
value|12
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_AAL_5
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_AAL_0
value|1
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_AAL_0T
value|2
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_HALT_ER
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_MARK_CI
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_MARK_ER
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_UPDATE_GER
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR0_RC
value|0xff
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR1_PCR
value|(0x7fff<< 16)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR1_PCR
value|16
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR1_MCR
value|(0x7fff<< 0)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR1_MCR
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR2_ACR
value|(0x7fff<< 16)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR2_ACR
value|16
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR3_NRM
value|(0xff<< 24)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR3_NRM
value|24
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR3_CRM
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR3_CRM
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR4_FLUSH
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR4_SESS_END
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR4_OAM_CRC10
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR4_NULL_CRC10
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR4_PROT
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR4_AAL
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR4_AAL
value|24
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR4_AAL_5
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR4_AAL_0
value|1
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR4_AAL_0T
value|2
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR9_INIT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR11_ICR
value|(0x7fff<< 16)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR11_ICR
value|16
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR11_TRM
value|(0x7<< 13)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR11_TRM
value|13
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR11_NRM
value|(0x7<< 10)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR11_NRM
value|10
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR11_ADTF
value|0x3ff
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR11_ADTF
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR13_RDF
value|(0xf<< 23)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR13_RDF
value|23
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR13_RIF
value|(0xf<< 19)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR13_RIF
value|19
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR13_CDF
value|(0x7<< 16)
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR13_CDF
value|16
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR13_CRM
value|0xffff
end_define

begin_define
define|#
directive|define
name|HE_REGS_TSR13_CRM
value|0
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR14_CBR_DELETE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|HE_REGM_TSR14_ABR_CLOSE
value|(1<< 16)
end_define

begin_comment
comment|/*  * RSRs  */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_RSRA
parameter_list|(
name|BASE
parameter_list|,
name|CID
parameter_list|,
name|NR
parameter_list|)
value|((BASE) + ((CID)<< 3) + (NR))
end_define

begin_define
define|#
directive|define
name|HE_REGO_RSRB
parameter_list|(
name|BASE
parameter_list|,
name|CID
parameter_list|,
name|NR
parameter_list|)
value|((BASE) + ((CID)<< 1) + (NR))
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_PTI7
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_RM
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_F5OAM
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_STARTPDU
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_OPEN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_PPD
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_EPD
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_TCPCS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_AAL
value|0x7
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_AAL_5
value|0x0
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_AAL_0
value|0x1
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_AAL_0T
value|0x2
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_AAL_RAW
value|0x3
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR0_AAL_RAWCRC10
value|0x4
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR1_AQI
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR1_RBPL_ONLY
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR1_GROUP
value|(7<< 16)
end_define

begin_define
define|#
directive|define
name|HE_REGS_RSR1_GROUP
value|16
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR4_AQI
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR4_GROUP
value|(7<< 27)
end_define

begin_define
define|#
directive|define
name|HE_REGS_RSR4_GROUP
value|27
end_define

begin_define
define|#
directive|define
name|HE_REGM_RSR4_RBPL_ONLY
value|(1<< 26)
end_define

begin_comment
comment|/*  * Relative to RCMABR_BA  */
end_comment

begin_define
define|#
directive|define
name|HE_REGO_CM_GQTBL
value|0x000
end_define

begin_define
define|#
directive|define
name|HE_REGL_CM_GQTBL
value|0x100
end_define

begin_define
define|#
directive|define
name|HE_REGO_CM_RGTBL
value|0x100
end_define

begin_define
define|#
directive|define
name|HE_REGL_CM_RGTBL
value|0x100
end_define

begin_define
define|#
directive|define
name|HE_REGO_CM_TNRMTBL
value|0x200
end_define

begin_define
define|#
directive|define
name|HE_REGL_CM_TNRMTBL
value|0x100
end_define

begin_define
define|#
directive|define
name|HE_REGO_CM_ORCF
value|0x300
end_define

begin_define
define|#
directive|define
name|HE_REGL_CM_ORCF
value|0x100
end_define

begin_define
define|#
directive|define
name|HE_REGO_CM_RTGTBL
value|0x400
end_define

begin_define
define|#
directive|define
name|HE_REGL_CM_RTGTBL
value|0x200
end_define

begin_define
define|#
directive|define
name|HE_REGO_CM_IRCF
value|0x600
end_define

begin_define
define|#
directive|define
name|HE_REGL_CM_IRCF
value|0x200
end_define

begin_comment
comment|/*  * Interrupt Status  */
end_comment

begin_define
define|#
directive|define
name|HE_REGM_ITYPE
value|0xf8
end_define

begin_define
define|#
directive|define
name|HE_REGM_IGROUP
value|0x07
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_TBRQ
value|(0x0<< 3)
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_TPD
value|(0x1<< 3)
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_RBPS
value|(0x2<< 3)
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_RBPL
value|(0x3<< 3)
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_RBRQ
value|(0x4<< 3)
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_RBRQT
value|(0x5<< 3)
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_PHYS
value|(0x6<< 3)
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_UNKNOWN
value|0xf8
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_ERR
value|0x80
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_PERR
value|0x81
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_ABORT
value|0x82
end_define

begin_define
define|#
directive|define
name|HE_REGM_ITYPE_INVALID
value|0xf8
end_define

begin_comment
comment|/*  * Serial EEPROM  */
end_comment

begin_define
define|#
directive|define
name|HE_EEPROM_PROD_ID
value|0x08
end_define

begin_define
define|#
directive|define
name|HE_EEPROM_PROD_ID_LEN
value|30
end_define

begin_define
define|#
directive|define
name|HE_EEPROM_REV
value|0x26
end_define

begin_define
define|#
directive|define
name|HE_EEPROM_REV_LEN
value|4
end_define

begin_define
define|#
directive|define
name|HE_EEPROM_M_SN
value|0x3A
end_define

begin_define
define|#
directive|define
name|HE_EEPROM_MEDIA
value|0x3E
end_define

begin_define
define|#
directive|define
name|HE_EEPROM_MAC
value|0x42
end_define

begin_define
define|#
directive|define
name|HE_MEDIA_UTP155
value|0x06
end_define

begin_define
define|#
directive|define
name|HE_MEDIA_MMF155
value|0x26
end_define

begin_define
define|#
directive|define
name|HE_MEDIA_MMF622
value|0x27
end_define

begin_define
define|#
directive|define
name|HE_MEDIA_SMF155
value|0x46
end_define

begin_define
define|#
directive|define
name|HE_MEDIA_SMF622
value|0x47
end_define

begin_define
define|#
directive|define
name|HE_622_CLOCK
value|66667000
end_define

begin_define
define|#
directive|define
name|HE_155_CLOCK
value|50000000
end_define

begin_comment
comment|/*  * Statistics  */
end_comment

begin_struct
struct|struct
name|fatm_statshe
block|{ }
struct|;
end_struct

begin_comment
comment|/*  * Queue entries  */
end_comment

begin_comment
comment|/* Receive Buffer Pool Queue entry */
end_comment

begin_struct
struct|struct
name|he_rbpen
block|{
name|uint32_t
name|phys
decl_stmt|;
comment|/* physical address */
name|uint32_t
name|handle
decl_stmt|;
comment|/* handle or virtual address */
block|}
struct|;
end_struct

begin_comment
comment|/* Receive Buffer Return Queue entry */
end_comment

begin_struct
struct|struct
name|he_rbrqen
block|{
name|uint32_t
name|addr
decl_stmt|;
comment|/* handle and flags */
name|uint32_t
name|len
decl_stmt|;
comment|/* length and CID */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HE_REGM_RBRQ_ADDR
value|0xFFFFFFC0
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBRQ_ADDR
value|6
end_define

begin_define
define|#
directive|define
name|HE_REGM_RBRQ_FLAGS
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|HE_REGM_RBRQ_HBUF_ERROR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RBRQ_CON_CLOSED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RBRQ_AAL5_PROT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RBRQ_END_PDU
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RBRQ_LEN_ERROR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RBRQ_CRC_ERROR
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|HE_REGM_RBRQ_CID
value|(0x1fff<< 16)
end_define

begin_define
define|#
directive|define
name|HE_REGS_RBRQ_CID
value|16
end_define

begin_define
define|#
directive|define
name|HE_REGM_RBRQ_LEN
value|0xffff
end_define

begin_comment
comment|/* Transmit Packet Descriptor Ready Queue entry */
end_comment

begin_struct
struct|struct
name|he_tpdrqen
block|{
name|uint32_t
name|tpd
decl_stmt|;
comment|/* physical address */
name|uint32_t
name|cid
decl_stmt|;
comment|/* connection id */
block|}
struct|;
end_struct

begin_comment
comment|/* Transmit buffer return queue */
end_comment

begin_struct
struct|struct
name|he_tbrqen
block|{
name|uint32_t
name|addr
decl_stmt|;
comment|/* handle and flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HE_REGM_TBRQ_ADDR
value|0xffffffc0
end_define

begin_define
define|#
directive|define
name|HE_REGM_TBRQ_FLAGS
value|0x0000000a
end_define

begin_define
define|#
directive|define
name|HE_REGM_TBRQ_EOS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HE_REGM_TBRQ_MULT
value|0x00000002
end_define

begin_struct
struct|struct
name|he_tpd
block|{
name|uint32_t
name|addr
decl_stmt|;
comment|/* handle or virtual address and flags */
name|uint32_t
name|res
decl_stmt|;
comment|/* reserved */
struct|struct
block|{
name|uint32_t
name|addr
decl_stmt|;
comment|/* buffer address */
name|uint32_t
name|len
decl_stmt|;
comment|/* buffer length and flags */
block|}
name|bufs
index|[
literal|3
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HE_REGM_TPD_ADDR
value|0xffffffC0
end_define

begin_define
define|#
directive|define
name|HE_REGS_TPD_ADDR
value|6
end_define

begin_define
define|#
directive|define
name|HE_REGM_TPD_INTR
value|0x0001
end_define

begin_define
define|#
directive|define
name|HE_REGM_TPD_CLP
value|0x0002
end_define

begin_define
define|#
directive|define
name|HE_REGM_TPD_EOS
value|0x0004
end_define

begin_define
define|#
directive|define
name|HE_REGM_TPD_PTI
value|0x0038
end_define

begin_define
define|#
directive|define
name|HE_REGS_TPD_PTI
value|3
end_define

begin_define
define|#
directive|define
name|HE_REGM_TPD_LST
value|0x80000000
end_define

begin_comment
comment|/*   * The HOST STATUS PAGE  */
end_comment

begin_struct
struct|struct
name|he_hsp
block|{
struct|struct
block|{
name|uint32_t
name|tbrq_tail
decl_stmt|;
name|uint32_t
name|res1
index|[
literal|15
index|]
decl_stmt|;
name|uint32_t
name|rbrq_tail
decl_stmt|;
name|uint32_t
name|res2
index|[
literal|15
index|]
decl_stmt|;
block|}
name|group
index|[
literal|8
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HE_MAX_PDU
value|(65535)
end_define

end_unit


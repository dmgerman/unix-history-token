begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: i80321reg.h,v 1.14 2003/12/19 10:08:11 gavan Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_XSCALE_I80321REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_XSCALE_I80321REG_H_
end_define

begin_comment
comment|/*  * Register definitions for the Intel 80321 (``Verde'') I/O processor,  * based on the XScale core.  */
end_comment

begin_comment
comment|/*  * Base i80321 memory map:  *  *	0x0000.0000 - 0x7fff.ffff	ATU Outbound Direct Addressing Window  *	0x8000.0000 - 0x9001.ffff	ATU Outbound Translation Windows  *	0x9002.0000 - 0xffff.dfff	External Memory  *	0xffff.e000 - 0xffff.e8ff	Peripheral Memory Mapped Registers  *	0xffff.e900 - 0xffff.ffff	Reserved  */
end_comment

begin_define
define|#
directive|define
name|VERDE_OUT_DIRECT_WIN_BASE
value|0x00000000UL
end_define

begin_define
define|#
directive|define
name|VERDE_OUT_DIRECT_WIN_SIZE
value|0x80000000UL
end_define

begin_define
define|#
directive|define
name|VERDE_OUT_XLATE_MEM_WIN_SIZE
value|0x04000000UL
end_define

begin_define
define|#
directive|define
name|VERDE_OUT_XLATE_IO_WIN_SIZE
value|0x00010000UL
end_define

begin_define
define|#
directive|define
name|VERDE_OUT_XLATE_MEM_WIN0_BASE
value|0x80000000UL
end_define

begin_define
define|#
directive|define
name|VERDE_OUT_XLATE_MEM_WIN1_BASE
value|0x84000000UL
end_define

begin_define
define|#
directive|define
name|VERDE_OUT_XLATE_IO_WIN0_BASE
value|0x90000000UL
end_define

begin_define
define|#
directive|define
name|VERDE_EXTMEM_BASE
value|0x90020000UL
end_define

begin_define
define|#
directive|define
name|VERDE_PMMR_BASE
value|0xffffe000UL
end_define

begin_define
define|#
directive|define
name|VERDE_PMMR_SIZE
value|0x00001700UL
end_define

begin_comment
comment|/*  * Peripheral Memory Mapped Registers.  Defined as offsets  * from the VERDE_PMMR_BASE.  */
end_comment

begin_define
define|#
directive|define
name|VERDE_ATU_BASE
value|0x0100
end_define

begin_define
define|#
directive|define
name|VERDE_ATU_SIZE
value|0x0100
end_define

begin_define
define|#
directive|define
name|VERDE_MU_BASE
value|0x0300
end_define

begin_define
define|#
directive|define
name|VERDE_MU_SIZE
value|0x0100
end_define

begin_define
define|#
directive|define
name|VERDE_DMA_BASE
value|0x0400
end_define

begin_define
define|#
directive|define
name|VERDE_DMA_BASE0
value|(VERDE_DMA_BASE + 0x00)
end_define

begin_define
define|#
directive|define
name|VERDE_DMA_BASE1
value|(VERDE_DMA_BASE + 0x40)
end_define

begin_define
define|#
directive|define
name|VERDE_DMA_SIZE
value|0x0100
end_define

begin_define
define|#
directive|define
name|VERDE_DMA_CHSIZE
value|0x0040
end_define

begin_define
define|#
directive|define
name|VERDE_MCU_BASE
value|0x0500
end_define

begin_define
define|#
directive|define
name|VERDE_MCU_SIZE
value|0x0100
end_define

begin_define
define|#
directive|define
name|VERDE_SSP_BASE
value|0x0600
end_define

begin_define
define|#
directive|define
name|VERDE_SSP_SIZE
value|0x0080
end_define

begin_define
define|#
directive|define
name|VERDE_PBIU_BASE
value|0x0680
end_define

begin_define
define|#
directive|define
name|VERDE_PBIU_SIZE
value|0x0080
end_define

begin_define
define|#
directive|define
name|VERDE_AAU_BASE
value|0x0800
end_define

begin_define
define|#
directive|define
name|VERDE_AAU_SIZE
value|0x0100
end_define

begin_define
define|#
directive|define
name|VERDE_I2C_BASE
value|0x1680
end_define

begin_define
define|#
directive|define
name|VERDE_I2C_BASE0
value|(VERDE_I2C_BASE + 0x00)
end_define

begin_define
define|#
directive|define
name|VERDE_I2C_BASE1
value|(VERDE_I2C_BASE + 0x20)
end_define

begin_define
define|#
directive|define
name|VERDE_I2C_SIZE
value|0x0080
end_define

begin_define
define|#
directive|define
name|VERDE_I2C_CHSIZE
value|0x0020
end_define

begin_comment
comment|/*  * Address Translation Unit  */
end_comment

begin_comment
comment|/* 0x00 - 0x38 -- PCI configuration space header */
end_comment

begin_define
define|#
directive|define
name|ATU_IALR0
value|0x40
end_define

begin_comment
comment|/* Inbound ATU Limit 0 */
end_comment

begin_define
define|#
directive|define
name|ATU_IATVR0
value|0x44
end_define

begin_comment
comment|/* Inbound ATU Xlate Value 0 */
end_comment

begin_define
define|#
directive|define
name|ATU_ERLR
value|0x48
end_define

begin_comment
comment|/* Expansion ROM Limit */
end_comment

begin_define
define|#
directive|define
name|ATU_ERTVR
value|0x4c
end_define

begin_comment
comment|/* Expansion ROM Xlate Value */
end_comment

begin_define
define|#
directive|define
name|ATU_IALR1
value|0x50
end_define

begin_comment
comment|/* Inbound ATU Limit 1 */
end_comment

begin_define
define|#
directive|define
name|ATU_IALR2
value|0x54
end_define

begin_comment
comment|/* Inbound ATU Limit 2 */
end_comment

begin_define
define|#
directive|define
name|ATU_IATVR2
value|0x58
end_define

begin_comment
comment|/* Inbound ATU Xlate Value 2 */
end_comment

begin_define
define|#
directive|define
name|ATU_OIOWTVR
value|0x5c
end_define

begin_comment
comment|/* Outbound I/O Window Xlate Value */
end_comment

begin_define
define|#
directive|define
name|ATU_OMWTVR0
value|0x60
end_define

begin_comment
comment|/* Outbound Mem Window Xlate Value 0 */
end_comment

begin_define
define|#
directive|define
name|ATU_OUMWTVR0
value|0x64
end_define

begin_comment
comment|/* Outbound Mem Window Xlate Value 0 Upper */
end_comment

begin_define
define|#
directive|define
name|ATU_OMWTVR1
value|0x68
end_define

begin_comment
comment|/* Outbound Mem Window Xlate Value 1 */
end_comment

begin_define
define|#
directive|define
name|ATU_OUMWTVR1
value|0x6c
end_define

begin_comment
comment|/* Outbound Mem Window Xlate Value 1 Upper */
end_comment

begin_define
define|#
directive|define
name|ATU_OUDWTVR
value|0x78
end_define

begin_comment
comment|/* Outbound Mem Direct Xlate Value Upper */
end_comment

begin_define
define|#
directive|define
name|ATU_ATUCR
value|0x80
end_define

begin_comment
comment|/* ATU Configuration */
end_comment

begin_define
define|#
directive|define
name|ATU_PCSR
value|0x84
end_define

begin_comment
comment|/* PCI Configuration and Status */
end_comment

begin_define
define|#
directive|define
name|ATU_ATUISR
value|0x88
end_define

begin_comment
comment|/* ATU Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|ATU_ATUIMR
value|0x8c
end_define

begin_comment
comment|/* ATU Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|ATU_IABAR3
value|0x90
end_define

begin_comment
comment|/* Inbound ATU Base Address 3 */
end_comment

begin_define
define|#
directive|define
name|ATU_IAUBAR3
value|0x94
end_define

begin_comment
comment|/* Inbound ATU Base Address 3 Upper */
end_comment

begin_define
define|#
directive|define
name|ATU_IALR3
value|0x98
end_define

begin_comment
comment|/* Inbound ATU Limit 3 */
end_comment

begin_define
define|#
directive|define
name|ATU_IATVR3
value|0x9c
end_define

begin_comment
comment|/* Inbound ATU Xlate Value 3 */
end_comment

begin_define
define|#
directive|define
name|ATU_OCCAR
value|0xa4
end_define

begin_comment
comment|/* Outbound Configuration Cycle Address */
end_comment

begin_define
define|#
directive|define
name|ATU_OCCDR
value|0xac
end_define

begin_comment
comment|/* Outbound Configuration Cycle Data */
end_comment

begin_define
define|#
directive|define
name|ATU_MSI_PORT
value|0xb4
end_define

begin_comment
comment|/* MSI port */
end_comment

begin_define
define|#
directive|define
name|ATU_PDSCR
value|0xbc
end_define

begin_comment
comment|/* PCI Bus Drive Strength Control */
end_comment

begin_define
define|#
directive|define
name|ATU_PCI_X_CAP_ID
value|0xe0
end_define

begin_comment
comment|/* (1) */
end_comment

begin_define
define|#
directive|define
name|ATU_PCI_X_NEXT
value|0xe1
end_define

begin_comment
comment|/* (1) */
end_comment

begin_define
define|#
directive|define
name|ATU_PCIXCMD
value|0xe2
end_define

begin_comment
comment|/* PCI-X Command Register (2) */
end_comment

begin_define
define|#
directive|define
name|ATU_PCIXSR
value|0xe4
end_define

begin_comment
comment|/* PCI-X Status Register */
end_comment

begin_define
define|#
directive|define
name|ATUCR_DRC_ALIAS
value|(1U<< 19)
end_define

begin_define
define|#
directive|define
name|ATUCR_DAU2GXEN
value|(1U<< 18)
end_define

begin_define
define|#
directive|define
name|ATUCR_P_SERR_MA
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|ATUCR_DTS
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|ATUCR_P_SERR_DIE
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|ATUCR_DAE
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|ATUCR_BIST_IE
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|ATUCR_OUT_EN
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|PCSR_DAAAPE
value|(1U<< 18)
end_define

begin_define
define|#
directive|define
name|PCSR_PCI_X_CAP
value|(3U<< 16)
end_define

begin_define
define|#
directive|define
name|PCSR_PCI_X_CAP_BORING
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|PCSR_PCI_X_CAP_66
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|PCSR_PCI_X_CAP_100
value|(2U<< 16)
end_define

begin_define
define|#
directive|define
name|PCSR_PCI_X_CAP_133
value|(3U<< 16)
end_define

begin_define
define|#
directive|define
name|PCSR_OTQB
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|PCSR_IRTQB
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|PCSR_DTV
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|PCSR_BUS66
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|PCSR_BUS64
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|PCSR_RIB
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|PCSR_RPB
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|PCSR_CCR
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|PCSR_CPR
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|ATUISR_IMW1BU
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|ATUISR_ISCEM
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|ATUISR_RSCEM
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|ATUISR_PST
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|ATUISR_P_SERR_ASRT
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|ATUISR_DPE
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|ATUISR_BIST
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|ATUISR_IBMA
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|ATUISR_P_SERR_DET
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|ATUISR_PMA
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|ATUISR_PTAM
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|ATUISR_PTAT
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|ATUISR_PMPE
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|ATUIMR_IMW1BU
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|ATUIMR_ISCEM
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|ATUIMR_RSCEM
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|ATUIMR_PST
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|ATUIMR_DPE
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|ATUIMR_P_SERR_ASRT
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|ATUIMR_PMA
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|ATUIMR_PTAM
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|ATUIMR_PTAT
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|ATUIMR_PMPE
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|ATUIMR_IE_SERR_EN
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|ATUIMR_ECC_TAE
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MOST_1
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MOST_2
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MOST_3
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MOST_4
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MOST_8
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MOST_12
value|(5<< 4)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MOST_16
value|(6<< 4)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MOST_32
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MOST_MASK
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MMRBC_512
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MMRBC_1024
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MMRBC_2048
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MMRBC_4096
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_MMRBC_MASK
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_ERO
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|PCIXCMD_DPERE
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|PCIXSR_RSCEM
value|(1U<< 29)
end_define

begin_define
define|#
directive|define
name|PCIXSR_DMCRS_MASK
value|(7<< 26)
end_define

begin_define
define|#
directive|define
name|PCIXSR_DMOST_MASK
value|(7<< 23)
end_define

begin_define
define|#
directive|define
name|PCIXSR_COMPLEX
value|(1U<< 20)
end_define

begin_define
define|#
directive|define
name|PCIXSR_USC
value|(1U<< 19)
end_define

begin_define
define|#
directive|define
name|PCIXSR_SCD
value|(1U<< 18)
end_define

begin_define
define|#
directive|define
name|PCIXSR_133_CAP
value|(1U<< 17)
end_define

begin_define
define|#
directive|define
name|PCIXSR_32PCI
value|(1U<< 16)
end_define

begin_comment
comment|/* 0 = 32, 1 = 64 */
end_comment

begin_define
define|#
directive|define
name|PCIXSR_BUSNO
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff00)>> 8)
end_define

begin_define
define|#
directive|define
name|PCIXSR_DEVNO
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf8)>> 3)
end_define

begin_define
define|#
directive|define
name|PCIXSR_FUNCNO
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
end_define

begin_comment
comment|/*  * Memory Controller Unit  */
end_comment

begin_define
define|#
directive|define
name|MCU_SDIR
value|0x00
end_define

begin_comment
comment|/* DDR SDRAM Init. Register */
end_comment

begin_define
define|#
directive|define
name|MCU_SDCR
value|0x04
end_define

begin_comment
comment|/* DDR SDRAM Control Register */
end_comment

begin_define
define|#
directive|define
name|MCU_SDBR
value|0x08
end_define

begin_comment
comment|/* SDRAM Base Register */
end_comment

begin_define
define|#
directive|define
name|MCU_SBR0
value|0x0c
end_define

begin_comment
comment|/* SDRAM Boundary 0 */
end_comment

begin_define
define|#
directive|define
name|MCU_SBR1
value|0x10
end_define

begin_comment
comment|/* SDRAM Boundary 1 */
end_comment

begin_define
define|#
directive|define
name|MCU_ECCR
value|0x34
end_define

begin_comment
comment|/* ECC Control Register */
end_comment

begin_define
define|#
directive|define
name|MCU_ELOG0
value|0x38
end_define

begin_comment
comment|/* ECC Log 0 */
end_comment

begin_define
define|#
directive|define
name|MCU_ELOG1
value|0x3c
end_define

begin_comment
comment|/* ECC Log 1 */
end_comment

begin_define
define|#
directive|define
name|MCU_ECAR0
value|0x40
end_define

begin_comment
comment|/* ECC address 0 */
end_comment

begin_define
define|#
directive|define
name|MCU_ECAR1
value|0x44
end_define

begin_comment
comment|/* ECC address 1 */
end_comment

begin_define
define|#
directive|define
name|MCU_ECTST
value|0x48
end_define

begin_comment
comment|/* ECC test register */
end_comment

begin_define
define|#
directive|define
name|MCU_MCISR
value|0x4c
end_define

begin_comment
comment|/* MCU Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|MCU_RFR
value|0x50
end_define

begin_comment
comment|/* Refresh Frequency Register */
end_comment

begin_define
define|#
directive|define
name|MCU_DBUDSR
value|0x54
end_define

begin_comment
comment|/* Data Bus Pull-up Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_DBDDSR
value|0x58
end_define

begin_comment
comment|/* Data Bus Pull-down Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_CUDSR
value|0x5c
end_define

begin_comment
comment|/* Clock Pull-up Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_CDDSR
value|0x60
end_define

begin_comment
comment|/* Clock Pull-down Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_CEUDSR
value|0x64
end_define

begin_comment
comment|/* Clock En Pull-up Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_CEDDSR
value|0x68
end_define

begin_comment
comment|/* Clock En Pull-down Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_CSUDSR
value|0x6c
end_define

begin_comment
comment|/* Chip Sel Pull-up Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_CSDDSR
value|0x70
end_define

begin_comment
comment|/* Chip Sel Pull-down Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_REUDSR
value|0x74
end_define

begin_comment
comment|/* Rx En Pull-up Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_REDDSR
value|0x78
end_define

begin_comment
comment|/* Rx En Pull-down Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_ABUDSR
value|0x7c
end_define

begin_comment
comment|/* Addr Bus Pull-up Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_ABDDSR
value|0x80
end_define

begin_comment
comment|/* Addr Bus Pull-down Drive Strength */
end_comment

begin_define
define|#
directive|define
name|MCU_DSDR
value|0x84
end_define

begin_comment
comment|/* Data Strobe Delay Register */
end_comment

begin_define
define|#
directive|define
name|MCU_REDR
value|0x88
end_define

begin_comment
comment|/* Rx Enable Delay Register */
end_comment

begin_define
define|#
directive|define
name|SDCR_DIMMTYPE
value|(1U<< 1)
end_define

begin_comment
comment|/* 0 = unbuf, 1 = reg */
end_comment

begin_define
define|#
directive|define
name|SDCR_BUSWIDTH
value|(1U<< 2)
end_define

begin_comment
comment|/* 0 = 64, 1 = 32 */
end_comment

begin_define
define|#
directive|define
name|SBRx_TECH
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|SBRx_BOUND
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|ECCR_SBERE
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|ECCR_MBERE
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|ECCR_SBECE
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|ECCR_ECCEN
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|ELOGx_SYNDROME
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|ELOGx_ERRTYPE
value|(1U<< 8)
end_define

begin_comment
comment|/* 1 = multi-bit */
end_comment

begin_define
define|#
directive|define
name|ELOGx_RW
value|(1U<< 12)
end_define

begin_comment
comment|/* 1 = write error */
end_comment

begin_comment
comment|/* 	 * Dev ID	Func		Requester 	 * 2		0		XScale core 	 * 2		1		ATU 	 * 13		0		DMA channel 0 	 * 13		1		DMA channel 1 	 * 26		0		ATU 	 */
end_comment

begin_define
define|#
directive|define
name|ELOGx_REQ_DEV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1f)
end_define

begin_define
define|#
directive|define
name|ELOGx_REQ_FUNC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|MCISR_ECC_ERR0
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|MCISR_ECC_ERR1
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|MCISR_ECC_ERRN
value|(1U<< 2)
end_define

begin_comment
comment|/*  * Timers  *  * The i80321 timer registers are available in both memory-mapped  * and coprocessor spaces.  Most of the registers are read-only  * if memory-mapped, so we access them via coprocessor space.  *  *	TMR0	cp6 c0,1	0xffffe7e0  *	TMR1	cp6 c1,1	0xffffe7e4  *	TCR0	cp6 c2,1	0xffffe7e8  *	TCR1	cp6 c3,1	0xffffe7ec  *	TRR0	cp6 c4,1	0xffffe7f0  *	TRR1	cp6 c5,1	0xffffe7f4  *	TISR	cp6 c6,1	0xffffe7f8  *	WDTCR	cp6 c7,1	0xffffe7fc  */
end_comment

begin_define
define|#
directive|define
name|TMRx_TC
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|TMRx_ENABLE
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|TMRx_RELOAD
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|TMRx_CSEL_CORE
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|TMRx_CSEL_CORE_div4
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TMRx_CSEL_CORE_div8
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|TMRx_CSEL_CORE_div16
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|TISR_TMR0
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|TISR_TMR1
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|WDTCR_ENABLE1
value|0x1e1e1e1e
end_define

begin_define
define|#
directive|define
name|WDTCR_ENABLE2
value|0xe1e1e1e1
end_define

begin_comment
comment|/*  * Interrupt Controller Unit.  *  *	INTCTL	cp6 c0,0	0xffffe7d0  *	INTSTR	cp6 c4,0	0xffffe7d4  *	IINTSRC	cp6 c8,0	0xffffe7d8  *	FINTSRC	cp6 c9,0	0xffffe7dc  *	PIRSR			0xffffe1ec  */
end_comment

begin_define
define|#
directive|define
name|ICU_PIRSR
value|0x01ec
end_define

begin_define
define|#
directive|define
name|ICU_GPOE
value|0x07c4
end_define

begin_define
define|#
directive|define
name|ICU_GPID
value|0x07c8
end_define

begin_define
define|#
directive|define
name|ICU_GPOD
value|0x07cc
end_define

begin_comment
comment|/*  * NOTE: WE USE THE `bitXX' BITS TO INDICATE PENDING SOFTWARE  * INTERRUPTS.  See i80321_icu.c  */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_HPI
value|31
end_define

begin_comment
comment|/* high priority interrupt */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_XINT0
value|27
end_define

begin_comment
comment|/* external interrupts */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_XINT
parameter_list|(
name|x
parameter_list|)
value|((x) + ICU_INT_XINT0)
end_define

begin_define
define|#
directive|define
name|ICU_INT_bit26
value|26
end_define

begin_define
define|#
directive|define
name|ICU_INT_SSP
value|25
end_define

begin_comment
comment|/* SSP serial port */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_MUE
value|24
end_define

begin_comment
comment|/* msg unit error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_AAUE
value|23
end_define

begin_comment
comment|/* AAU error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_bit22
value|22
end_define

begin_define
define|#
directive|define
name|ICU_INT_DMA1E
value|21
end_define

begin_comment
comment|/* DMA Ch 1 error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_DMA0E
value|20
end_define

begin_comment
comment|/* DMA Ch 0 error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_MCUE
value|19
end_define

begin_comment
comment|/* memory controller error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUE
value|18
end_define

begin_comment
comment|/* ATU error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_BIUE
value|17
end_define

begin_comment
comment|/* bus interface unit error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_PMU
value|16
end_define

begin_comment
comment|/* XScale PMU */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_PPM
value|15
end_define

begin_comment
comment|/* peripheral PMU */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_BIST
value|14
end_define

begin_comment
comment|/* ATU Start BIST */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_MU
value|13
end_define

begin_comment
comment|/* messaging unit */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_I2C1
value|12
end_define

begin_comment
comment|/* i2c unit 1 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_I2C0
value|11
end_define

begin_comment
comment|/* i2c unit 0 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_TMR1
value|10
end_define

begin_comment
comment|/* timer 1 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_TMR0
value|9
end_define

begin_comment
comment|/* timer 0 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_CPPM
value|8
end_define

begin_comment
comment|/* core processor PMU */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_AAU_EOC
value|7
end_define

begin_comment
comment|/* AAU end-of-chain */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_AAU_EOT
value|6
end_define

begin_comment
comment|/* AAU end-of-transfer */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_bit5
value|5
end_define

begin_define
define|#
directive|define
name|ICU_INT_bit4
value|4
end_define

begin_define
define|#
directive|define
name|ICU_INT_DMA1_EOC
value|3
end_define

begin_comment
comment|/* DMA1 end-of-chain */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_DMA1_EOT
value|2
end_define

begin_comment
comment|/* DMA1 end-of-transfer */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_DMA0_EOC
value|1
end_define

begin_comment
comment|/* DMA0 end-of-chain */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_DMA0_EOT
value|0
end_define

begin_comment
comment|/* DMA0 end-of-transfer */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_HWMASK
value|(0xffffffff& \ 					~((1<< ICU_INT_bit26) | \ 					  (1<< ICU_INT_bit22) | \ 					  (1<< ICU_INT_bit5)  | \ 					  (1<< ICU_INT_bit4)))
end_define

begin_comment
comment|/*  * SSP Serial Port  */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR0
value|0x00
end_define

begin_comment
comment|/* SSC control 0 */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1
value|0x04
end_define

begin_comment
comment|/* SSC control 1 */
end_comment

begin_define
define|#
directive|define
name|SSP_SSSR
value|0x08
end_define

begin_comment
comment|/* SSP status */
end_comment

begin_define
define|#
directive|define
name|SSP_SSITR
value|0x0c
end_define

begin_comment
comment|/* SSP interrupt test */
end_comment

begin_define
define|#
directive|define
name|SSP_SSDR
value|0x10
end_define

begin_comment
comment|/* SSP data */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR0_DSIZE
parameter_list|(
name|x
parameter_list|)
value|((x) - 1)
end_define

begin_comment
comment|/* data size: 4..16 */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR0_FRF_SPI
value|(0<< 4)
end_define

begin_comment
comment|/* Motorola Serial Periph Iface */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR0_FRF_SSP
value|(1U<< 4)
end_define

begin_comment
comment|/* TI Sync. Serial Protocol */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR0_FRF_UWIRE
value|(2U<< 4)
end_define

begin_comment
comment|/* NatSemi Microwire */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR0_FRF_rsvd
value|(3U<< 4)
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR0_ECS
value|(1U<< 6)
end_define

begin_comment
comment|/* external clock select */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR0_SSE
value|(1U<< 7)
end_define

begin_comment
comment|/* sync. serial port enable */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR0_SCR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* serial clock rate */
end_comment

begin_comment
comment|/* bit rate = 3.6864 * 10e6 / 					        (2 * (SCR + 1)) */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1_RIE
value|(1U<< 0)
end_define

begin_comment
comment|/* Rx FIFO interrupt enable */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1_TIE
value|(1U<< 1)
end_define

begin_comment
comment|/* Tx FIFO interrupt enable */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1_LBM
value|(1U<< 2)
end_define

begin_comment
comment|/* loopback mode enable */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1_SPO
value|(1U<< 3)
end_define

begin_comment
comment|/* Moto SPI SSCLK pol. (1 = high) */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1_SPH
value|(1U<< 4)
end_define

begin_comment
comment|/* Moto SPI SSCLK phase: 					    0 = inactive full at start, 						1/2 at end of frame 					    1 = inactive 1/2 at start, 						full at end of frame */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1_MWDS
value|(1U<< 5)
end_define

begin_comment
comment|/* Microwire data size: 					    0 = 8 bit 					    1 = 16 bit */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1_TFT
value|(((x) - 1)<< 6)
end_define

begin_comment
comment|/* Tx FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1_RFT
value|(((x) - 1)<< 10)
end_define

begin_comment
comment|/* Rx FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1_EFWR
value|(1U<< 14)
end_define

begin_comment
comment|/* enab. FIFO write/read */
end_comment

begin_define
define|#
directive|define
name|SSP_SSCR1_STRF
value|(1U<< 15)
end_define

begin_comment
comment|/* FIFO write/read FIFO select: 					     0 = Tx FIFO 					     1 = Rx FIFO */
end_comment

begin_define
define|#
directive|define
name|SSP_SSSR_TNF
value|(1U<< 2)
end_define

begin_comment
comment|/* Tx FIFO not full */
end_comment

begin_define
define|#
directive|define
name|SSP_SSSR_RNE
value|(1U<< 3)
end_define

begin_comment
comment|/* Rx FIFO not empty */
end_comment

begin_define
define|#
directive|define
name|SSP_SSSR_BSY
value|(1U<< 4)
end_define

begin_comment
comment|/* SSP is busy */
end_comment

begin_define
define|#
directive|define
name|SSP_SSSR_TFS
value|(1U<< 5)
end_define

begin_comment
comment|/* Tx FIFO service request */
end_comment

begin_define
define|#
directive|define
name|SSP_SSSR_RFS
value|(1U<< 6)
end_define

begin_comment
comment|/* Rx FIFO service request */
end_comment

begin_define
define|#
directive|define
name|SSP_SSSR_ROR
value|(1U<< 7)
end_define

begin_comment
comment|/* Rx FIFO overrun */
end_comment

begin_define
define|#
directive|define
name|SSP_SSSR_TFL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xf)
end_define

begin_comment
comment|/* Tx FIFO level */
end_comment

begin_define
define|#
directive|define
name|SSP_SSSR_RFL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xf)
end_define

begin_comment
comment|/* Rx FIFO level */
end_comment

begin_define
define|#
directive|define
name|SSP_SSITR_TTFS
value|(1U<< 5)
end_define

begin_comment
comment|/* Test Tx FIFO service */
end_comment

begin_define
define|#
directive|define
name|SSP_SSITR_TRFS
value|(1U<< 6)
end_define

begin_comment
comment|/* Test Rx FIFO service */
end_comment

begin_define
define|#
directive|define
name|SSP_SSITR_TROR
value|(1U<< 7)
end_define

begin_comment
comment|/* Test Rx overrun */
end_comment

begin_comment
comment|/*  * Peripheral Bus Interface Unit  */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBCR
value|0x00
end_define

begin_comment
comment|/* PBIU Control Register */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBBAR0
value|0x08
end_define

begin_comment
comment|/* PBIU Base Address Register 0 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBLR0
value|0x0c
end_define

begin_comment
comment|/* PBIU Limit Register 0 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBBAR1
value|0x10
end_define

begin_comment
comment|/* PBIU Base Address Register 1 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBLR1
value|0x14
end_define

begin_comment
comment|/* PBIU Limit Register 1 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBBAR2
value|0x18
end_define

begin_comment
comment|/* PBIU Base Address Register 2 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBLR2
value|0x1c
end_define

begin_comment
comment|/* PBIU Limit Register 2 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBBAR3
value|0x20
end_define

begin_comment
comment|/* PBIU Base Address Register 3 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBLR3
value|0x24
end_define

begin_comment
comment|/* PBIU Limit Register 3 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBBAR4
value|0x28
end_define

begin_comment
comment|/* PBIU Base Address Register 4 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBLR4
value|0x2c
end_define

begin_comment
comment|/* PBIU Limit Register 4 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBBAR5
value|0x30
end_define

begin_comment
comment|/* PBIU Base Address Register 5 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBLR5
value|0x34
end_define

begin_comment
comment|/* PBIU Limit Register 5 */
end_comment

begin_define
define|#
directive|define
name|PBIU_DSCR
value|0x38
end_define

begin_comment
comment|/* PBIU Drive Strength Control Reg. */
end_comment

begin_define
define|#
directive|define
name|PBIU_MBR0
value|0x40
end_define

begin_comment
comment|/* PBIU Memory-less Boot Reg. 0 */
end_comment

begin_define
define|#
directive|define
name|PBIU_MBR1
value|0x60
end_define

begin_comment
comment|/* PBIU Memory-less Boot Reg. 1 */
end_comment

begin_define
define|#
directive|define
name|PBIU_MBR2
value|0x64
end_define

begin_comment
comment|/* PBIU Memory-less Boot Reg. 2 */
end_comment

begin_define
define|#
directive|define
name|PBIU_PBCR_PBIEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PBIU_PBCR_PBI100
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PBIU_PBCR_PBI66
value|(2<< 1)
end_define

begin_define
define|#
directive|define
name|PBIU_PBCR_PBI33
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|PBIU_PBCR_PBBEN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_WIDTH8
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_WIDTH16
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_WIDTH32
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_ADWAIT4
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_ADWAIT8
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_ADWAIT12
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_ADWAIT16
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_ADWAIT20
value|(4<< 2)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_RCWAIT1
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_RCWAIT4
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_RCWAIT8
value|(2<< 6)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_RCWAIT12
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_RCWAIT16
value|(4<< 6)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_RCWAIT20
value|(5<< 6)
end_define

begin_define
define|#
directive|define
name|PBIU_PBARx_FWE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PBIU_BASE_MASK
value|0xfffff000U
end_define

begin_define
define|#
directive|define
name|PBIU_PBLRx_SIZE
parameter_list|(
name|x
parameter_list|)
value|(~((x) - 1))
end_define

begin_comment
comment|/*  * Messaging Unit  */
end_comment

begin_define
define|#
directive|define
name|MU_IMR0
value|0x0010
end_define

begin_comment
comment|/* MU Inbound Message Register 0 */
end_comment

begin_define
define|#
directive|define
name|MU_IMR1
value|0x0014
end_define

begin_comment
comment|/* MU Inbound Message Register 1 */
end_comment

begin_define
define|#
directive|define
name|MU_OMR0
value|0x0018
end_define

begin_comment
comment|/* MU Outbound Message Register 0 */
end_comment

begin_define
define|#
directive|define
name|MU_OMR1
value|0x001c
end_define

begin_comment
comment|/* MU Outbound Message Register 1 */
end_comment

begin_define
define|#
directive|define
name|MU_IDR
value|0x0020
end_define

begin_comment
comment|/* MU Inbound Doorbell Register */
end_comment

begin_define
define|#
directive|define
name|MU_IISR
value|0x0024
end_define

begin_comment
comment|/* MU Inbound Interrupt Status Reg */
end_comment

begin_define
define|#
directive|define
name|MU_IIMR
value|0x0028
end_define

begin_comment
comment|/* MU Inbound Interrupt Mask Reg */
end_comment

begin_define
define|#
directive|define
name|MU_ODR
value|0x002c
end_define

begin_comment
comment|/* MU Outbound Doorbell Register */
end_comment

begin_define
define|#
directive|define
name|MU_OISR
value|0x0030
end_define

begin_comment
comment|/* MU Outbound Interrupt Status Reg */
end_comment

begin_define
define|#
directive|define
name|MU_OIMR
value|0x0034
end_define

begin_comment
comment|/* MU Outbound Interrupt Mask Reg */
end_comment

begin_define
define|#
directive|define
name|MU_MUCR
value|0x0050
end_define

begin_comment
comment|/* MU Configuration Register */
end_comment

begin_define
define|#
directive|define
name|MU_QBAR
value|0x0054
end_define

begin_comment
comment|/* MU Queue Base Address Register */
end_comment

begin_define
define|#
directive|define
name|MU_IFHPR
value|0x0060
end_define

begin_comment
comment|/* MU Inbound Free Head Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|MU_IFTPR
value|0x0064
end_define

begin_comment
comment|/* MU Inbound Free Tail Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|MU_IPHPR
value|0x0068
end_define

begin_comment
comment|/* MU Inbound Post Head Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|MU_IPTPR
value|0x006c
end_define

begin_comment
comment|/* MU Inbound Post Tail Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|MU_OFHPR
value|0x0070
end_define

begin_comment
comment|/* MU Outbound Free Head Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|MU_OFTPR
value|0x0074
end_define

begin_comment
comment|/* MU Outbound Free Tail Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|MU_OPHPR
value|0x0078
end_define

begin_comment
comment|/* MU Outbound Post Head Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|MU_OPTPR
value|0x007c
end_define

begin_comment
comment|/* MU Outbound Post Tail Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|MU_IAR
value|0x0080
end_define

begin_comment
comment|/* MU Index Address Register */
end_comment

begin_define
define|#
directive|define
name|MU_IIMR_IRI
value|(1<< 6)
end_define

begin_comment
comment|/* Index Register Interrupt */
end_comment

begin_define
define|#
directive|define
name|MU_IIMR_OFQFI
value|(1<< 5)
end_define

begin_comment
comment|/* Outbound Free Queue Full Int. */
end_comment

begin_define
define|#
directive|define
name|MU_IIMR_IPQI
value|(1<< 4)
end_define

begin_comment
comment|/* Inbound Post Queue Interrupt */
end_comment

begin_define
define|#
directive|define
name|MU_IIMR_EDI
value|(1<< 3)
end_define

begin_comment
comment|/* Error Doorbell Interrupt */
end_comment

begin_define
define|#
directive|define
name|MU_IIMR_IDI
value|(1<< 2)
end_define

begin_comment
comment|/* Inbound Doorbell Interrupt */
end_comment

begin_define
define|#
directive|define
name|MU_IIMR_IM1I
value|(1<< 1)
end_define

begin_comment
comment|/* Inbound Message 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|MU_IIMR_IM0I
value|(1<< 0)
end_define

begin_comment
comment|/* Inbound Message 0 Interrupt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_XSCALE_I80321REG_H_ */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Olivier Houchard  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I83142_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|I83142_REG_H_
end_define

begin_comment
comment|/* Physical Memory Map */
end_comment

begin_comment
comment|/*  * 0x000000000 - 0x07FFFFFFF SDRAM  * 0x090100000 - 0x0901FFFFF ATUe Outbound IO Window  * 0x0F0000000 - 0x0F1FFFFFF Flash  * 0x0F2000000 - 0x0F20FFFFF PCE1  * 0x0F3000000 - 0x0FFCFFFFF Compact Flash  * 0x0FFD00000 - 0x0FFDFFFFF MMR  * 0x0FFFB0000 - 0x0FFFBFFFF ATU-X Outbound I/O Window  * 0x0FFFD0000 - 0x0FFFDFFFF ATUe Outbound I/O Window  * 0x100000000 - 0x1FFFFFFFF ATU-X outbound Memory Translation Window  * 0x2FF000000 - 0x2FFFFFFFF ATUe Outbound Memory Translation Window  */
end_comment

begin_define
define|#
directive|define
name|IOP34X_VADDR
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|IOP34X_HWADDR
value|0xffd00000
end_define

begin_define
define|#
directive|define
name|IOP34X_SIZE
value|0x100000
end_define

begin_define
define|#
directive|define
name|IOP34X_ADMA0_OFFSET
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IOP34X_ADMA1_OFFSET
value|0x00080200
end_define

begin_define
define|#
directive|define
name|IOP34X_ADMA2_OFFSET
value|0x00080400
end_define

begin_define
define|#
directive|define
name|IOP34X_ADMA_SIZE
value|0x200
end_define

begin_comment
comment|/* ADMA Registers */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_CCR
value|0x0000
end_define

begin_comment
comment|/* Channel Control Register */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_CSR
value|0x0004
end_define

begin_comment
comment|/* Channel Status Register */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_DAR
value|0x0008
end_define

begin_comment
comment|/* Descriptor Address Register */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_IPCR
value|0x0018
end_define

begin_comment
comment|/* Internal Interface Parity Ctrl Reg */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_NDAR
value|0x0024
end_define

begin_comment
comment|/* Next Descriptor Register */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_DCR
value|0x0028
end_define

begin_comment
comment|/* Descriptor Control Register */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_IE
value|(1<< 0)
end_define

begin_comment
comment|/* Interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_TR
value|(1<< 1)
end_define

begin_comment
comment|/* Transfert Direction */
end_comment

begin_comment
comment|/*  *               Source                   Destination  *  00         Host I/O Interface	Local Memory  *  01         Local Memory             Host I/O Interface  *  10         Internal Bus             Local Memory  *  11         Local Memory             Internal Bus  */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_SS
value|(1<< 3)
end_define

begin_comment
comment|/* Source selection */
end_comment

begin_comment
comment|/* 0000: Data Transfer / CRC / Memory Block Fill */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_ZRBCE
value|(1<< 7)
end_define

begin_comment
comment|/* Zero Result Buffer Check Enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_MBFE
value|(1<< 8)
end_define

begin_comment
comment|/* Memory Block Fill Enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_CGE
value|(1<< 9)
end_define

begin_comment
comment|/* CRC Generation enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_CTD
value|(1<< 10)
end_define

begin_comment
comment|/* CRC Transfer disable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_CSFD
value|(1<< 11)
end_define

begin_comment
comment|/* CRC Seed fetch disable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_SWBE
value|(1<< 12)
end_define

begin_comment
comment|/* Status write back enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_ESE
value|(1<< 13)
end_define

begin_comment
comment|/* Endian swap enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_PQUTE
value|(1<< 16)
end_define

begin_comment
comment|/* P+Q Update Transfer Enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_DXE
value|(1<< 17)
end_define

begin_comment
comment|/* Dual XOR Enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_PQTE
value|(1<< 18)
end_define

begin_comment
comment|/* P+Q Transfer Enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_PTD
value|(1<< 19)
end_define

begin_comment
comment|/* P Transfer Disable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_ROE
value|(1<< 30)
end_define

begin_comment
comment|/* Relaxed Ordering Enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ADMA_NSE
value|(1U<< 31)
end_define

begin_comment
comment|/* No Snoop Enable */
end_comment

begin_define
define|#
directive|define
name|IOP34X_PBBAR0
value|0x81588
end_define

begin_comment
comment|/* PBI Base Address Register 0 */
end_comment

begin_define
define|#
directive|define
name|IOP34X_PBBAR0_ADDRMASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|IOP34X_PBBAR1
value|0x81590
end_define

begin_define
define|#
directive|define
name|IOP34X_PCE1
value|0xF2000000
end_define

begin_define
define|#
directive|define
name|IOP34X_PCE1_SIZE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IOP34X_PCE1_VADDR
value|0xF1000000
end_define

begin_define
define|#
directive|define
name|IOP34X_ESSTSR0
value|0x82188
end_define

begin_define
define|#
directive|define
name|IOP34X_CONTROLLER_ONLY
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|IOP34X_INT_SEL_PCIX
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|IOP34X_PFR
value|0x82180
end_define

begin_comment
comment|/* Processor Frequency Register */
end_comment

begin_define
define|#
directive|define
name|IOP34X_FREQ_MASK
value|((1<< 16) | (1<< 17) | (1<< 18))
end_define

begin_define
define|#
directive|define
name|IOP34X_FREQ_600
value|(0)
end_define

begin_define
define|#
directive|define
name|IOP34X_FREQ_667
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IOP34X_FREQ_800
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|IOP34X_FREQ_833
value|((1<< 17) | (1<< 16))
end_define

begin_define
define|#
directive|define
name|IOP34X_FREQ_1000
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|IOP34X_FREQ_1200
value|((1<< 16) | (1<< 18))
end_define

begin_define
define|#
directive|define
name|IOP34X_UART0_VADDR
value|IOP34X_VADDR + 0x82300
end_define

begin_define
define|#
directive|define
name|IOP34X_UART0_HWADDR
value|IOP34X_HWADDR + 0x82300
end_define

begin_define
define|#
directive|define
name|IOP34X_UART1_VADDR
value|IOP34X_VADDR + 0x82340
end_define

begin_define
define|#
directive|define
name|IOP34X_UART1_HWADDR
value|IOP34X_HWADDR + 0x82340
end_define

begin_define
define|#
directive|define
name|IOP34X_PBI_HWADDR
value|0xffd81580
end_define

begin_comment
comment|/* SDRAM Memory Controller */
end_comment

begin_define
define|#
directive|define
name|SMC_SDBR
value|0x8180c
end_define

begin_comment
comment|/* Base Register */
end_comment

begin_define
define|#
directive|define
name|SMC_SDBR_BASEADDR
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|SMC_SDBR_BASEADDR_MASK
value|((1<< 27) | (1<< 28) | (1<< 29) | (1<< 30) \     				| (1U<< 31))
end_define

begin_define
define|#
directive|define
name|SMC_SDUBR
value|0x81810
end_define

begin_comment
comment|/* Upper Base Register */
end_comment

begin_define
define|#
directive|define
name|SMC_SBSR
value|0x81814
end_define

begin_comment
comment|/* SDRAM Bank Size Register */
end_comment

begin_define
define|#
directive|define
name|SMC_SBSR_BANK_NB
value|(1<< 2)
end_define

begin_comment
comment|/* Number of DDR Banks 					   0 => 2 Banks 					   1 => 1 Bank 					   */
end_comment

begin_define
define|#
directive|define
name|SMC_SBSR_BANK_SZ
value|(1<< 27)
end_define

begin_comment
comment|/* SDRAM Bank Size : 					   0x00000 Empty 					   0x00001 128MB 					   0x00010 256MB 					   0x00100 512MB 					   0x01000 1GB 					   */
end_comment

begin_define
define|#
directive|define
name|SMC_SBSR_BANK_SZ_MASK
value|((1<< 27) | (1<< 28) | (1<< 29) | (1<< 30) \     				| (1U<< 31))
end_define

begin_comment
comment|/* Two possible addresses for ATUe depending on configuration. */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ATUE_ADDR
parameter_list|(
name|esstrsr
parameter_list|)
value|((((esstrsr)& (IOP34X_CONTROLLER_ONLY | \     IOP34X_INT_SEL_PCIX)) == (IOP34X_CONTROLLER_ONLY | IOP34X_INT_SEL_PCIX)) ? \     0xffdc8000 : 0xffdcd000)
end_define

begin_comment
comment|/* Three possible addresses for ATU-X depending on configuration. */
end_comment

begin_define
define|#
directive|define
name|IOP34X_ATUX_ADDR
parameter_list|(
name|esstrsr
parameter_list|)
value|(!((esstrsr)& IOP34X_CONTROLLER_ONLY) ? \     0xffdcc000 : !((esstrsr)& IOP34X_INT_SEL_PCIX) ? 0xffdc8000 : 0xffdcd000)
end_define

begin_define
define|#
directive|define
name|IOP34X_OIOBAR_SIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|IOP34X_PCIX_OIOBAR
value|0xfffb0000
end_define

begin_define
define|#
directive|define
name|IOP34X_PCIX_OIOBAR_VADDR
value|0xf01b0000
end_define

begin_define
define|#
directive|define
name|IOP34X_PCIX_OMBAR
value|0x100000000
end_define

begin_define
define|#
directive|define
name|IOP34X_PCIE_OIOBAR
value|0xfffd0000
end_define

begin_define
define|#
directive|define
name|IOP34X_PCIE_OIOBAR_VADDR
value|0xf01d0000
end_define

begin_define
define|#
directive|define
name|IOP34X_PCIE_OMBAR
value|0x200000000
end_define

begin_comment
comment|/* ATU Registers */
end_comment

begin_comment
comment|/* Common for ATU-X and ATUe */
end_comment

begin_define
define|#
directive|define
name|ATU_VID
value|0x0000
end_define

begin_comment
comment|/* ATU Vendor ID */
end_comment

begin_define
define|#
directive|define
name|ATU_DID
value|0x0002
end_define

begin_comment
comment|/* ATU Device ID */
end_comment

begin_define
define|#
directive|define
name|ATU_CMD
value|0x0004
end_define

begin_comment
comment|/* ATU Command Register */
end_comment

begin_define
define|#
directive|define
name|ATU_SR
value|0x0006
end_define

begin_comment
comment|/* ATU Status Register */
end_comment

begin_define
define|#
directive|define
name|ATU_RID
value|0x0008
end_define

begin_comment
comment|/* ATU Revision ID */
end_comment

begin_define
define|#
directive|define
name|ATU_CCR
value|0x0009
end_define

begin_comment
comment|/* ATU Class Code */
end_comment

begin_define
define|#
directive|define
name|ATU_CLSR
value|0x000c
end_define

begin_comment
comment|/* ATU Cacheline Size */
end_comment

begin_define
define|#
directive|define
name|ATU_LT
value|0x000d
end_define

begin_comment
comment|/* ATU Latency Timer */
end_comment

begin_define
define|#
directive|define
name|ATU_HTR
value|0x000e
end_define

begin_comment
comment|/* ATU Header Type */
end_comment

begin_define
define|#
directive|define
name|ATU_BISTR
value|0x000f
end_define

begin_comment
comment|/* ATU BIST Register */
end_comment

begin_define
define|#
directive|define
name|ATU_IABAR0
value|0x0010
end_define

begin_comment
comment|/* Inbound ATU Base Address register 0 */
end_comment

begin_define
define|#
directive|define
name|ATU_IAUBAR0
value|0x0014
end_define

begin_comment
comment|/* Inbound ATU Upper Base Address Register 0 */
end_comment

begin_define
define|#
directive|define
name|ATU_IABAR1
value|0x0018
end_define

begin_comment
comment|/* Inbound ATU Base Address Register 1 */
end_comment

begin_define
define|#
directive|define
name|ATU_IAUBAR1
value|0x001c
end_define

begin_comment
comment|/* Inbound ATU Upper Base Address Register 1 */
end_comment

begin_define
define|#
directive|define
name|ATU_IABAR2
value|0x0020
end_define

begin_comment
comment|/* Inbound ATU Base Address Register 2 */
end_comment

begin_define
define|#
directive|define
name|ATU_IAUBAR2
value|0x0024
end_define

begin_comment
comment|/* Inbound ATU Upper Base Address Register 2 */
end_comment

begin_define
define|#
directive|define
name|ATU_VSIR
value|0x002c
end_define

begin_comment
comment|/* ATU Subsystem Vendor ID Register */
end_comment

begin_define
define|#
directive|define
name|ATU_SIR
value|0x002e
end_define

begin_comment
comment|/* ATU Subsystem ID Register */
end_comment

begin_define
define|#
directive|define
name|ATU_ERBAR
value|0x0030
end_define

begin_comment
comment|/* Expansion ROM Base Address Register */
end_comment

begin_define
define|#
directive|define
name|ATU_CAPPTR
value|0x0034
end_define

begin_comment
comment|/* ATU Capabilities Pointer Register */
end_comment

begin_define
define|#
directive|define
name|ATU_ILR
value|0x003c
end_define

begin_comment
comment|/* ATU Interrupt Line Register */
end_comment

begin_define
define|#
directive|define
name|ATU_IPR
value|0x003d
end_define

begin_comment
comment|/* ATU Interrupt Pin Register */
end_comment

begin_define
define|#
directive|define
name|ATU_MGNT
value|0x003e
end_define

begin_comment
comment|/* ATU Minimum Grand Register */
end_comment

begin_define
define|#
directive|define
name|ATU_MLAT
value|0x003f
end_define

begin_comment
comment|/* ATU Maximum Latency Register */
end_comment

begin_define
define|#
directive|define
name|ATU_IALR0
value|0x0040
end_define

begin_comment
comment|/* Inbound ATU Limit Register 0 */
end_comment

begin_define
define|#
directive|define
name|ATU_IATVR0
value|0x0044
end_define

begin_comment
comment|/* Inbound ATU Translate Value Register 0 */
end_comment

begin_define
define|#
directive|define
name|ATU_IAUTVR0
value|0x0048
end_define

begin_comment
comment|/* Inbound ATU Upper Translate Value Register 0*/
end_comment

begin_define
define|#
directive|define
name|ATU_IALR1
value|0x004c
end_define

begin_comment
comment|/* Inbound ATU Limit Register 1 */
end_comment

begin_define
define|#
directive|define
name|ATU_IATVR1
value|0x0050
end_define

begin_comment
comment|/* Inbound ATU Translate Value Register 1 */
end_comment

begin_define
define|#
directive|define
name|ATU_IAUTVR1
value|0x0054
end_define

begin_comment
comment|/* Inbound ATU Upper Translate Value Register 1*/
end_comment

begin_define
define|#
directive|define
name|ATU_IALR2
value|0x0058
end_define

begin_comment
comment|/* Inbound ATU Limit Register 2 */
end_comment

begin_define
define|#
directive|define
name|ATU_IATVR2
value|0x005c
end_define

begin_comment
comment|/* Inbound ATU Translate Value Register 2 */
end_comment

begin_define
define|#
directive|define
name|ATU_IAUTVR2
value|0x0060
end_define

begin_comment
comment|/* Inbound ATU Upper Translate Value Register 2*/
end_comment

begin_define
define|#
directive|define
name|ATU_ERLR
value|0x0064
end_define

begin_comment
comment|/* Expansion ROM Limit Register */
end_comment

begin_define
define|#
directive|define
name|ATU_ERTVR
value|0x0068
end_define

begin_comment
comment|/* Expansion ROM Translater Value Register */
end_comment

begin_define
define|#
directive|define
name|ATU_ERUTVR
value|0x006c
end_define

begin_comment
comment|/* Expansion ROM Upper Translate Value Register*/
end_comment

begin_define
define|#
directive|define
name|ATU_CR
value|0x0070
end_define

begin_comment
comment|/* ATU Configuration Register */
end_comment

begin_define
define|#
directive|define
name|ATU_CR_OUT_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATU_PCSR
value|0x0074
end_define

begin_comment
comment|/* PCI Configuration and Status Register */
end_comment

begin_define
define|#
directive|define
name|PCIE_BUSNO
parameter_list|(
name|x
parameter_list|)
value|((x& 0xff000000)>> 24)
end_define

begin_define
define|#
directive|define
name|ATUX_CORE_RST
value|((1<< 30) | (1U<< 31))
end_define

begin_comment
comment|/* Core Processor Reset */
end_comment

begin_define
define|#
directive|define
name|ATUX_P_RSTOUT
value|(1<< 21)
end_define

begin_comment
comment|/* Central Resource PCI Bus Reset */
end_comment

begin_define
define|#
directive|define
name|ATUE_CORE_RST
value|((1<< 9) | (1<< 8))
end_define

begin_comment
comment|/* Core Processor Reset */
end_comment

begin_define
define|#
directive|define
name|ATU_ISR
value|0x0078
end_define

begin_comment
comment|/* ATU Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_PIE
value|(1<< 18)
end_define

begin_comment
comment|/* PCI Interface error */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_IBPR
value|(1<< 16)
end_define

begin_comment
comment|/* Internal Bus Parity Error */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_DCE
value|(1<< 14)
end_define

begin_comment
comment|/* Detected Correctable error */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_ISCE
value|(1<< 13)
end_define

begin_comment
comment|/* Initiated Split Completion Error Msg */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_RSCE
value|(1<< 12)
end_define

begin_comment
comment|/* Received Split Completion Error Msg */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_DPE
value|(1<< 9)
end_define

begin_comment
comment|/* Detected Parity Error */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_IBMA
value|(1<< 7)
end_define

begin_comment
comment|/* Internal Bus Master Abort */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_PMA
value|(1<< 3)
end_define

begin_comment
comment|/* PCI Master Abort */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_PTAM
value|(1<< 2)
end_define

begin_comment
comment|/* PCI Target Abort (Master) */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_PTAT
value|(1<< 1)
end_define

begin_comment
comment|/* PCI Target Abort (Target) */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_PMPE
value|(1<< 0)
end_define

begin_comment
comment|/* PCI Master Parity Error */
end_comment

begin_define
define|#
directive|define
name|ATUX_ISR_ERRMSK
value|(ATUX_ISR_PIE | ATUX_ISR_IBPR | ATUX_ISR_DCE | \     ATUX_ISR_ISCE | ATUX_ISR_RSCE | ATUX_ISR_DPE | ATUX_ISR_IBMA | ATUX_ISR_PMA\     | ATUX_ISR_PTAM | ATUX_ISR_PTAT | ATUX_ISR_PMPE)
end_define

begin_define
define|#
directive|define
name|ATUE_ISR_HON
value|(1<< 13)
end_define

begin_comment
comment|/* Halt on Error Interrupt */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_RSE
value|(1<< 12)
end_define

begin_comment
comment|/* Root System Error Message */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_REM
value|(1<< 11)
end_define

begin_comment
comment|/* Root Error Message */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_PIE
value|(1<< 10)
end_define

begin_comment
comment|/* PCI Interface error */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_CEM
value|(1<< 9)
end_define

begin_comment
comment|/* Correctable Error Message */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_UEM
value|(1<< 8)
end_define

begin_comment
comment|/* Uncorrectable error message */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_CRS
value|(1<< 7)
end_define

begin_comment
comment|/* Received Configuration Retry Status */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_IBMA
value|(1<< 5)
end_define

begin_comment
comment|/* Internal Bus Master Abort */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_DPE
value|(1<< 4)
end_define

begin_comment
comment|/* Detected Parity Error Interrupt */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_MAI
value|(1<< 3)
end_define

begin_comment
comment|/* Received Master Abort Interrupt */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_STAI
value|(1<< 2)
end_define

begin_comment
comment|/* Signaled Target Abort Interrupt */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_TAI
value|(1<< 1)
end_define

begin_comment
comment|/* Received Target Abort Interrupt */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_MDPE
value|(1<< 0)
end_define

begin_comment
comment|/* Master Data Parity Error Interrupt */
end_comment

begin_define
define|#
directive|define
name|ATUE_ISR_ERRMSK
value|(ATUE_ISR_HON | ATUE_ISR_RSE | ATUE_ISR_REM | \     ATUE_ISR_PIE | ATUE_ISR_CEM | ATUE_ISR_UEM | ATUE_ISR_CRS | ATUE_ISR_IBMA |\     ATUE_ISR_DPE | ATUE_ISR_MAI | ATUE_ISR_STAI | ATUE_ISR_TAI | ATUE_ISR_MDPE)
end_define

begin_define
define|#
directive|define
name|ATU_IMR
value|0x007c
end_define

begin_comment
comment|/* ATU Interrupt Mask Register */
end_comment

begin_comment
comment|/* 0x0080 - 0x008f reserved */
end_comment

begin_define
define|#
directive|define
name|ATU_VPDCID
value|0x0090
end_define

begin_comment
comment|/* VPD Capability Identifier Register */
end_comment

begin_define
define|#
directive|define
name|ATU_VPDNIP
value|0x0091
end_define

begin_comment
comment|/* VPD Next Item Pointer Register */
end_comment

begin_define
define|#
directive|define
name|ATU_VPDAR
value|0x0092
end_define

begin_comment
comment|/* VPD Address Register */
end_comment

begin_define
define|#
directive|define
name|ATU_VPDDR
value|0x0094
end_define

begin_comment
comment|/* VPD Data Register */
end_comment

begin_define
define|#
directive|define
name|ATU_PMCID
value|0x0098
end_define

begin_comment
comment|/* PM Capability Identifier Register */
end_comment

begin_define
define|#
directive|define
name|ATU_PMNIPR
value|0x0099
end_define

begin_comment
comment|/* PM Next Item Pointer Register */
end_comment

begin_define
define|#
directive|define
name|ATU_PMCR
value|0x009a
end_define

begin_comment
comment|/* ATU Power Management Capabilities Register */
end_comment

begin_define
define|#
directive|define
name|ATU_PMCSR
value|0x009c
end_define

begin_comment
comment|/* ATU Power Management Control/Status Register*/
end_comment

begin_define
define|#
directive|define
name|ATU_MSICIR
value|0x00a0
end_define

begin_comment
comment|/* MSI Capability Identifier Register */
end_comment

begin_define
define|#
directive|define
name|ATU_MSINIPR
value|0x00a1
end_define

begin_comment
comment|/* MSI Next Item Pointer Register */
end_comment

begin_define
define|#
directive|define
name|ATU_MCR
value|0x00a2
end_define

begin_comment
comment|/* Message Control Register */
end_comment

begin_define
define|#
directive|define
name|ATU_MAR
value|0x00a4
end_define

begin_comment
comment|/* Message Address Register */
end_comment

begin_define
define|#
directive|define
name|ATU_MUAR
value|0x00a8
end_define

begin_comment
comment|/* Message Upper Address Register */
end_comment

begin_define
define|#
directive|define
name|ATU_MDR
value|0x00ac
end_define

begin_comment
comment|/* Message Data Register */
end_comment

begin_define
define|#
directive|define
name|ATU_PCIXSR
value|0x00d4
end_define

begin_comment
comment|/* PCI-X Status Register */
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
name|ATU_IABAR3
value|0x0200
end_define

begin_comment
comment|/* Inbound ATU Base Address Register 3 */
end_comment

begin_define
define|#
directive|define
name|ATU_IAUBAR3
value|0x0204
end_define

begin_comment
comment|/* Inbound ATU Upper Base Address Register 3 */
end_comment

begin_define
define|#
directive|define
name|ATU_IALR3
value|0x0208
end_define

begin_comment
comment|/* Inbound ATU Limit Register 3 */
end_comment

begin_define
define|#
directive|define
name|ATU_ITVR3
value|0x020c
end_define

begin_comment
comment|/* Inbound ATU Upper Translate Value Reg 3 */
end_comment

begin_define
define|#
directive|define
name|ATU_OIOBAR
value|0x0300
end_define

begin_comment
comment|/* Outbound I/O Base Address Register */
end_comment

begin_define
define|#
directive|define
name|ATU_OIOWTVR
value|0x0304
end_define

begin_comment
comment|/* Outbound I/O Window Translate Value Reg */
end_comment

begin_define
define|#
directive|define
name|ATU_OUMBAR0
value|0x0308
end_define

begin_comment
comment|/* Outbound Upper Memory Window base addr reg 0*/
end_comment

begin_define
define|#
directive|define
name|ATU_OUMBAR_FUNC
value|(28)
end_define

begin_define
define|#
directive|define
name|ATU_OUMBAR_EN
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|ATU_OUMWTVR0
value|0x030c
end_define

begin_comment
comment|/* Outbound Upper 32bit Memory Window Translate Value Register 0 */
end_comment

begin_define
define|#
directive|define
name|ATU_OUMBAR1
value|0x0310
end_define

begin_comment
comment|/* Outbound Upper Memory Window base addr reg1*/
end_comment

begin_define
define|#
directive|define
name|ATU_OUMWTVR1
value|0x0314
end_define

begin_comment
comment|/* Outbound Upper 32bit Memory Window Translate Value Register 1 */
end_comment

begin_define
define|#
directive|define
name|ATU_OUMBAR2
value|0x0318
end_define

begin_comment
comment|/* Outbound Upper Memory Window base addr reg2*/
end_comment

begin_define
define|#
directive|define
name|ATU_OUMWTVR2
value|0x031c
end_define

begin_comment
comment|/* Outbount Upper 32bit Memory Window Translate Value Register 2 */
end_comment

begin_define
define|#
directive|define
name|ATU_OUMBAR3
value|0x0320
end_define

begin_comment
comment|/* Outbound Upper Memory Window base addr reg3*/
end_comment

begin_define
define|#
directive|define
name|ATU_OUMWTVR3
value|0x0324
end_define

begin_comment
comment|/* Outbound Upper 32bit Memory Window Translate Value Register 3 */
end_comment

begin_comment
comment|/* ATU-X specific */
end_comment

begin_define
define|#
directive|define
name|ATUX_OCCAR
value|0x0330
end_define

begin_comment
comment|/* Outbound Configuration Cycle Address Reg */
end_comment

begin_define
define|#
directive|define
name|ATUX_OCCDR
value|0x0334
end_define

begin_comment
comment|/* Outbound Configuration Cycle Data Reg */
end_comment

begin_define
define|#
directive|define
name|ATUX_OCCFN
value|0x0338
end_define

begin_comment
comment|/* Outbound Configuration Cycle Function Number*/
end_comment

begin_comment
comment|/* ATUe specific */
end_comment

begin_define
define|#
directive|define
name|ATUE_OCCAR
value|0x032c
end_define

begin_comment
comment|/* Outbound Configuration Cycle Address Reg */
end_comment

begin_define
define|#
directive|define
name|ATUE_OCCDR
value|0x0330
end_define

begin_comment
comment|/* Outbound Configuration Cycle Data Reg */
end_comment

begin_define
define|#
directive|define
name|ATUE_OCCFN
value|0x0334
end_define

begin_comment
comment|/* Outbound Configuration Cycle Function Number*/
end_comment

begin_comment
comment|/* Interrupts */
end_comment

begin_comment
comment|/* IINTRSRC0 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ADMA0_EOT
value|(0)
end_define

begin_comment
comment|/* ADMA 0 End of transfer */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ADMA0_EOC
value|(1)
end_define

begin_comment
comment|/* ADMA 0 End of Chain */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ADMA1_EOT
value|(2)
end_define

begin_comment
comment|/* ADMA 1 End of transfer */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ADMA1_EOC
value|(3)
end_define

begin_comment
comment|/* ADMA 1 End of chain */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ADMA2_EOT
value|(4)
end_define

begin_comment
comment|/* ADMA 2 End of transfer */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ADMA2_EOC
value|(5)
end_define

begin_comment
comment|/* ADMA 2 end of chain */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_WDOG
value|(6)
end_define

begin_comment
comment|/* Watchdog timer */
end_comment

begin_comment
comment|/* 7 Reserved */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_TIMER0
value|(8)
end_define

begin_comment
comment|/* Timer 0 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_TIMER1
value|(9)
end_define

begin_comment
comment|/* Timer 1 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_I2C0
value|(10)
end_define

begin_comment
comment|/* I2C bus interface 0 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_I2C1
value|(11)
end_define

begin_comment
comment|/* I2C bus interface 1 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_MU
value|(12)
end_define

begin_comment
comment|/* Message Unit */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_MU_IPQ
value|(13)
end_define

begin_comment
comment|/* Message unit inbound post queue */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUE_IM
value|(14)
end_define

begin_comment
comment|/* ATU-E inbound message */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATU_BIST
value|(15)
end_define

begin_comment
comment|/* ATU/Start BIST */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_PMC
value|(16)
end_define

begin_comment
comment|/* PMC */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_PMU
value|(17)
end_define

begin_comment
comment|/* PMU */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_PC
value|(18)
end_define

begin_comment
comment|/* Processor cache */
end_comment

begin_comment
comment|/* 19-23 Reserved */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_XINT0
value|(24)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT1
value|(25)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT2
value|(26)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT3
value|(27)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT4
value|(28)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT5
value|(29)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT6
value|(30)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT7
value|(31)
end_define

begin_comment
comment|/* IINTSRC1 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_XINT8
value|(32)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT9
value|(33)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT10
value|(34)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT11
value|(35)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT12
value|(36)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT13
value|(37)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT14
value|(38)
end_define

begin_define
define|#
directive|define
name|ICU_INT_XINT15
value|(39)
end_define

begin_comment
comment|/* 40-50 reserved */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_UART0
value|(51)
end_define

begin_comment
comment|/* UART 0 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_UART1
value|(52)
end_define

begin_comment
comment|/* UART 1 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_PBIUE
value|(53)
end_define

begin_comment
comment|/* Peripheral bus interface unit error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUCRW
value|(54)
end_define

begin_comment
comment|/* ATU Configuration register write */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUE
value|(55)
end_define

begin_comment
comment|/* ATU error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_MCUE
value|(56)
end_define

begin_comment
comment|/* Memory controller unit error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ADMA0E
value|(57)
end_define

begin_comment
comment|/* ADMA Channel 0 error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ADMA1E
value|(58)
end_define

begin_comment
comment|/* ADMA Channel 1 error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ADMA2E
value|(59)
end_define

begin_comment
comment|/* ADMA Channel 2 error */
end_comment

begin_comment
comment|/* 60-61 reserved */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_MUE
value|(62)
end_define

begin_comment
comment|/* Messaging Unit Error */
end_comment

begin_comment
comment|/* 63 reserved */
end_comment

begin_comment
comment|/* IINTSRC2 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_IP
value|(64)
end_define

begin_comment
comment|/* Inter-processor */
end_comment

begin_comment
comment|/* 65-93 reserved */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_SIBBE
value|(94)
end_define

begin_comment
comment|/* South internal bus bridge error */
end_comment

begin_comment
comment|/* 95 reserved */
end_comment

begin_comment
comment|/* IINTSRC3 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_I2C2
value|(96)
end_define

begin_comment
comment|/* I2C bus interface 2 */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUE_BIST
value|(97)
end_define

begin_comment
comment|/* ATU-E/Start BIST */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUE_CRW
value|(98)
end_define

begin_comment
comment|/* ATU-E Configuration register write */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUEE
value|(99)
end_define

begin_comment
comment|/* ATU-E Error */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_IMU
value|(100)
end_define

begin_comment
comment|/* IMU */
end_comment

begin_comment
comment|/* 101-106 reserved */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUE_MA
value|(107)
end_define

begin_comment
comment|/* ATUE Interrupt message A */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUE_MB
value|(108)
end_define

begin_comment
comment|/* ATUE Interrupt message B */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUE_MC
value|(109)
end_define

begin_comment
comment|/* ATUE Interrupt message C */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_ATUE_MD
value|(110)
end_define

begin_comment
comment|/* ATUE Interrupt message D */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_MU_MSIX_TW
value|(111)
end_define

begin_comment
comment|/* MU MSI-X Table write */
end_comment

begin_comment
comment|/* 112 reserved */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_IMSI
value|(113)
end_define

begin_comment
comment|/* Inbound MSI */
end_comment

begin_comment
comment|/* 114-126 reserved */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_HPI
value|(127)
end_define

begin_comment
comment|/* HPI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I81342_REG_H_ */
end_comment

end_unit


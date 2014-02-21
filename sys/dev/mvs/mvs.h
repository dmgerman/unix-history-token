begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Alexander Motin<mav@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"mvs_if.h"
end_include

begin_comment
comment|/* Chip registers */
end_comment

begin_define
define|#
directive|define
name|CHIP_PCIEIC
value|0x1900
end_define

begin_comment
comment|/* PCIe Interrupt Cause */
end_comment

begin_define
define|#
directive|define
name|CHIP_PCIEIM
value|0x1910
end_define

begin_comment
comment|/* PCIe Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|CHIP_PCIIC
value|0x1d58
end_define

begin_comment
comment|/* PCI Interrupt Cause */
end_comment

begin_define
define|#
directive|define
name|CHIP_PCIIM
value|0x1d5c
end_define

begin_comment
comment|/* PCI Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|CHIP_MIC
value|0x1d60
end_define

begin_comment
comment|/* Main Interrupt Cause */
end_comment

begin_define
define|#
directive|define
name|CHIP_MIM
value|0x1d64
end_define

begin_comment
comment|/* Main Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|CHIP_SOC_MIC
value|0x20
end_define

begin_comment
comment|/* SoC Main Interrupt Cause */
end_comment

begin_define
define|#
directive|define
name|CHIP_SOC_MIM
value|0x24
end_define

begin_comment
comment|/* SoC Main Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|IC_ERR_IRQ
value|(1<< 0)
end_define

begin_comment
comment|/* shift by (2 * port #) */
end_comment

begin_define
define|#
directive|define
name|IC_DONE_IRQ
value|(1<< 1)
end_define

begin_comment
comment|/* shift by (2 * port #) */
end_comment

begin_define
define|#
directive|define
name|IC_HC0
value|0x000001ff
end_define

begin_comment
comment|/* bits 0-8 = HC0 */
end_comment

begin_define
define|#
directive|define
name|IC_HC_SHIFT
value|9
end_define

begin_comment
comment|/* HC1 shift */
end_comment

begin_define
define|#
directive|define
name|IC_HC1
value|(IC_HC0<< IC_HC_SHIFT)
end_define

begin_comment
comment|/* 9-17 = HC1 */
end_comment

begin_define
define|#
directive|define
name|IC_ERR_HC0
value|0x00000055
end_define

begin_comment
comment|/* HC0 ERR_IRQ */
end_comment

begin_define
define|#
directive|define
name|IC_DONE_HC0
value|0x000000aa
end_define

begin_comment
comment|/* HC0 DONE_IRQ */
end_comment

begin_define
define|#
directive|define
name|IC_ERR_HC1
value|(IC_ERR_HC0<< IC_HC_SHIFT)
end_define

begin_comment
comment|/* HC1 ERR_IRQ */
end_comment

begin_define
define|#
directive|define
name|IC_DONE_HC1
value|(IC_DONE_HC0<< IC_HC_SHIFT)
end_define

begin_comment
comment|/* HC1 DONE_IRQ */
end_comment

begin_define
define|#
directive|define
name|IC_HC0_COAL_DONE
value|(1<< 8)
end_define

begin_comment
comment|/* HC0 IRQ coalescing */
end_comment

begin_define
define|#
directive|define
name|IC_HC1_COAL_DONE
value|(1<< 17)
end_define

begin_comment
comment|/* HC1 IRQ coalescing */
end_comment

begin_define
define|#
directive|define
name|IC_PCI_ERR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|IC_TRAN_COAL_LO_DONE
value|(1<< 19)
end_define

begin_comment
comment|/* transaction coalescing */
end_comment

begin_define
define|#
directive|define
name|IC_TRAN_COAL_HI_DONE
value|(1<< 20)
end_define

begin_comment
comment|/* transaction coalescing */
end_comment

begin_define
define|#
directive|define
name|IC_ALL_PORTS_COAL_DONE
value|(1<< 21)
end_define

begin_comment
comment|/* GEN_II(E) IRQ coalescing */
end_comment

begin_define
define|#
directive|define
name|IC_GPIO_INT
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|IC_SELF_INT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|IC_TWSI_INT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|IC_MAIN_RSVD
value|(0xfe000000)
end_define

begin_comment
comment|/* bits 31-25 */
end_comment

begin_define
define|#
directive|define
name|IC_MAIN_RSVD_5
value|(0xfff10000)
end_define

begin_comment
comment|/* bits 31-19 */
end_comment

begin_define
define|#
directive|define
name|IC_MAIN_RSVD_SOC
value|(0xfffffec0)
end_define

begin_comment
comment|/* bits 31-9, 7-6 */
end_comment

begin_define
define|#
directive|define
name|CHIP_SOC_LED
value|0x2C
end_define

begin_comment
comment|/* SoC LED Configuration */
end_comment

begin_comment
comment|/* Additional mask for SoC devices with less than 4 channels */
end_comment

begin_define
define|#
directive|define
name|CHIP_SOC_HC0_MASK
parameter_list|(
name|num
parameter_list|)
value|(0xff>> ((4 - (num)) * 2))
end_define

begin_comment
comment|/* Chip CCC registers */
end_comment

begin_define
define|#
directive|define
name|CHIP_ICC
value|0x18008
end_define

begin_define
define|#
directive|define
name|CHIP_ICC_ALL_PORTS
value|(1<< 4)
end_define

begin_comment
comment|/* all ports irq event */
end_comment

begin_define
define|#
directive|define
name|CHIP_ICT
value|0x180cc
end_define

begin_define
define|#
directive|define
name|CHIP_ITT
value|0x180d0
end_define

begin_define
define|#
directive|define
name|CHIP_TRAN_COAL_CAUSE_LO
value|0x18088
end_define

begin_define
define|#
directive|define
name|CHIP_TRAN_COAL_CAUSE_HI
value|0x1808c
end_define

begin_comment
comment|/* Host Controller registers */
end_comment

begin_define
define|#
directive|define
name|HC_SIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|HC_OFFSET
value|0x20000
end_define

begin_define
define|#
directive|define
name|HC_BASE
parameter_list|(
name|hc
parameter_list|)
value|((hc) * HC_SIZE + HC_OFFSET)
end_define

begin_define
define|#
directive|define
name|HC_CFG
value|0x0
end_define

begin_comment
comment|/* Configuration */
end_comment

begin_define
define|#
directive|define
name|HC_CFG_TIMEOUT_MASK
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|HC_CFG_NODMABS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HC_CFG_NOEDMABS
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HC_CFG_NOPRDBS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HC_CFG_TIMEOUTEN
value|(1<< 16)
end_define

begin_comment
comment|/* Timer Enable */
end_comment

begin_define
define|#
directive|define
name|HC_CFG_COALDIS
parameter_list|(
name|p
parameter_list|)
value|(1<< ((p) + 24))
end_define

begin_comment
comment|/* Coalescing Disable*/
end_comment

begin_define
define|#
directive|define
name|HC_RQOP
value|0x4
end_define

begin_comment
comment|/* Request Queue Out-Pointer */
end_comment

begin_define
define|#
directive|define
name|HC_RQIP
value|0x8
end_define

begin_comment
comment|/* Response Queue In-Pointer */
end_comment

begin_define
define|#
directive|define
name|HC_ICT
value|0xc
end_define

begin_comment
comment|/* Interrupt Coalescing Threshold */
end_comment

begin_define
define|#
directive|define
name|HC_ICT_SAICOALT_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_ITT
value|0x10
end_define

begin_comment
comment|/* Interrupt Time Threshold */
end_comment

begin_define
define|#
directive|define
name|HC_ITT_SAITMTH_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|HC_IC
value|0x14
end_define

begin_comment
comment|/* Interrupt Cause */
end_comment

begin_define
define|#
directive|define
name|HC_IC_DONE
parameter_list|(
name|p
parameter_list|)
value|(1<< (p))
end_define

begin_comment
comment|/* SaCrpb/DMA Done */
end_comment

begin_define
define|#
directive|define
name|HC_IC_COAL
value|(1<< 4)
end_define

begin_comment
comment|/* Intr Coalescing */
end_comment

begin_define
define|#
directive|define
name|HC_IC_DEV
parameter_list|(
name|p
parameter_list|)
value|(1<< ((p) + 8))
end_define

begin_comment
comment|/* Device Intr */
end_comment

begin_comment
comment|/* Port registers */
end_comment

begin_define
define|#
directive|define
name|PORT_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|PORT_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|PORT_BASE
parameter_list|(
name|hc
parameter_list|)
value|((hc) * PORT_SIZE + PORT_OFFSET)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG
value|0x0
end_define

begin_comment
comment|/* Configuration */
end_comment

begin_define
define|#
directive|define
name|EDMA_CFG_RESERVED
value|(0x1f<< 0)
end_define

begin_comment
comment|/* Queue len ? */
end_comment

begin_define
define|#
directive|define
name|EDMA_CFG_ESATANATVCMDQUE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_ERDBSZ
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_EQUE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_ERDBSZEXT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_RESERVED2
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_EWRBUFFERLEN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_EDEVERR
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_EEDMAFBS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_ECUTTHROUGHEN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_EEARLYCOMPLETIONEN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_EEDMAQUELEN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_EHOSTQUEUECACHEEN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_EMASKRXPM
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_RESUMEDIS
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|EDMA_CFG_EDMAFBS
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|EDMA_T
value|0x4
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|EDMA_IEC
value|0x8
end_define

begin_comment
comment|/* Interrupt Error Cause */
end_comment

begin_define
define|#
directive|define
name|EDMA_IEM
value|0xc
end_define

begin_comment
comment|/* Interrupt Error Mask */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_EDEVERR
value|(1<< 2)
end_define

begin_comment
comment|/* EDMA Device Error */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_EDEVDIS
value|(1<< 3)
end_define

begin_comment
comment|/* EDMA Dev Disconn */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_EDEVCON
value|(1<< 4)
end_define

begin_comment
comment|/* EDMA Dev Conn */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_SERRINT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|EDMA_IE_ESELFDIS
value|(1<< 7)
end_define

begin_comment
comment|/* EDMA Self Disable */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_ETRANSINT
value|(1<< 8)
end_define

begin_comment
comment|/* Transport Layer */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_EIORDYERR
value|(1<< 12)
end_define

begin_comment
comment|/* EDMA IORdy Error */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_LINKXERR_SATACRC
value|(1<< 0)
end_define

begin_comment
comment|/* SATA CRC error */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_LINKXERR_INTERNALFIFO
value|(1<< 1)
end_define

begin_comment
comment|/* internal FIFO err */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_LINKXERR_LINKLAYERRESET
value|(1<< 2)
end_define

begin_comment
comment|/* Link Layer is reset by the reception of SYNC primitive from device */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_LINKXERR_OTHERERRORS
value|(1<< 3)
end_define

begin_comment
comment|/* 	 * Link state errors, coding errors, or running disparity errors occur 	 * during FIS reception. 	 */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_LINKTXERR_FISTXABORTED
value|(1<< 4)
end_define

begin_comment
comment|/* FIS Tx is aborted */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_LINKCTLRXERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 13)
end_define

begin_comment
comment|/* Link Ctrl Recv Err */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_LINKDATARXERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 17)
end_define

begin_comment
comment|/* Link Data Recv Err */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_LINKCTLTXERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 21)
end_define

begin_comment
comment|/* Link Ctrl Tx Error */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_LINKDATATXERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 26)
end_define

begin_comment
comment|/* Link Data Tx Error */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_TRANSPROTERR
value|(1U<< 31)
end_define

begin_comment
comment|/* Transport Proto E */
end_comment

begin_define
define|#
directive|define
name|EDMA_IE_TRANSIENT
value|(EDMA_IE_LINKCTLRXERR(0x0b) | \ 					 EDMA_IE_LINKCTLTXERR(0x1f))
end_define

begin_comment
comment|/* Non-fatal Errors */
end_comment

begin_define
define|#
directive|define
name|EDMA_REQQBAH
value|0x10
end_define

begin_comment
comment|/* Request Queue Base Address High */
end_comment

begin_define
define|#
directive|define
name|EDMA_REQQIP
value|0x14
end_define

begin_comment
comment|/* Request Queue In-Pointer */
end_comment

begin_define
define|#
directive|define
name|EDMA_REQQOP
value|0x18
end_define

begin_comment
comment|/* Request Queue Out-Pointer */
end_comment

begin_define
define|#
directive|define
name|EDMA_REQQP_ERQQP_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|EDMA_REQQP_ERQQP_MASK
value|0x000003e0
end_define

begin_define
define|#
directive|define
name|EDMA_REQQP_ERQQBAP_MASK
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|EDMA_REQQP_ERQQBA_MASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|EDMA_RESQBAH
value|0x1c
end_define

begin_comment
comment|/* Response Queue Base Address High */
end_comment

begin_define
define|#
directive|define
name|EDMA_RESQIP
value|0x20
end_define

begin_comment
comment|/* Response Queue In-Pointer */
end_comment

begin_define
define|#
directive|define
name|EDMA_RESQOP
value|0x24
end_define

begin_comment
comment|/* Response Queue Out-Pointer */
end_comment

begin_define
define|#
directive|define
name|EDMA_RESQP_ERPQP_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|EDMA_RESQP_ERPQP_MASK
value|0x000000f8
end_define

begin_define
define|#
directive|define
name|EDMA_RESQP_ERPQBAP_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|EDMA_RESQP_ERPQBA_MASK
value|0xfffffc00
end_define

begin_define
define|#
directive|define
name|EDMA_CMD
value|0x28
end_define

begin_comment
comment|/* Command */
end_comment

begin_define
define|#
directive|define
name|EDMA_CMD_EENEDMA
value|(1<< 0)
end_define

begin_comment
comment|/* Enable EDMA */
end_comment

begin_define
define|#
directive|define
name|EDMA_CMD_EDSEDMA
value|(1<< 1)
end_define

begin_comment
comment|/* Disable EDMA */
end_comment

begin_define
define|#
directive|define
name|EDMA_CMD_EATARST
value|(1<< 2)
end_define

begin_comment
comment|/* ATA Device Reset */
end_comment

begin_define
define|#
directive|define
name|EDMA_CMD_EEDMAFRZ
value|(1<< 4)
end_define

begin_comment
comment|/* EDMA Freeze */
end_comment

begin_define
define|#
directive|define
name|EDMA_TC
value|0x2c
end_define

begin_comment
comment|/* Test Control */
end_comment

begin_define
define|#
directive|define
name|EDMA_S
value|0x30
end_define

begin_comment
comment|/* Status */
end_comment

begin_define
define|#
directive|define
name|EDMA_S_EDEVQUETAG
parameter_list|(
name|s
parameter_list|)
value|((s)& 0x0000001f)
end_define

begin_define
define|#
directive|define
name|EDMA_S_EDEVDIR_WRITE
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|EDMA_S_EDEVDIR_READ
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|EDMA_S_ECACHEEMPTY
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|EDMA_S_EDMAIDLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|EDMA_S_ESTATE
parameter_list|(
name|s
parameter_list|)
value|(((s)& 0x0000ff00)>> 8)
end_define

begin_define
define|#
directive|define
name|EDMA_S_EIOID
parameter_list|(
name|s
parameter_list|)
value|(((s)& 0x003f0000)>> 16)
end_define

begin_define
define|#
directive|define
name|EDMA_IORT
value|0x34
end_define

begin_comment
comment|/* IORdy Timeout */
end_comment

begin_define
define|#
directive|define
name|EDMA_CDT
value|0x40
end_define

begin_comment
comment|/* Command Delay Threshold */
end_comment

begin_define
define|#
directive|define
name|EDMA_HC
value|0x60
end_define

begin_comment
comment|/* Halt Condition */
end_comment

begin_define
define|#
directive|define
name|EDMA_UNKN_RESD
value|0x6C
end_define

begin_comment
comment|/* Unknown register */
end_comment

begin_define
define|#
directive|define
name|EDMA_CQDCQOS
parameter_list|(
name|x
parameter_list|)
value|(0x90 + ((x)<< 2)
end_define

begin_comment
comment|/* NCQ Done/TCQ Outstanding Status */
end_comment

begin_comment
comment|/* ATA register defines */
end_comment

begin_define
define|#
directive|define
name|ATA_DATA
value|0x100
end_define

begin_comment
comment|/* (RW) data */
end_comment

begin_define
define|#
directive|define
name|ATA_FEATURE
value|0x104
end_define

begin_comment
comment|/* (W) feature */
end_comment

begin_define
define|#
directive|define
name|ATA_F_DMA
value|0x01
end_define

begin_comment
comment|/* enable DMA */
end_comment

begin_define
define|#
directive|define
name|ATA_F_OVL
value|0x02
end_define

begin_comment
comment|/* enable overlap */
end_comment

begin_define
define|#
directive|define
name|ATA_ERROR
value|0x104
end_define

begin_comment
comment|/* (R) error */
end_comment

begin_define
define|#
directive|define
name|ATA_E_ILI
value|0x01
end_define

begin_comment
comment|/* illegal length */
end_comment

begin_define
define|#
directive|define
name|ATA_E_NM
value|0x02
end_define

begin_comment
comment|/* no media */
end_comment

begin_define
define|#
directive|define
name|ATA_E_ABORT
value|0x04
end_define

begin_comment
comment|/* command aborted */
end_comment

begin_define
define|#
directive|define
name|ATA_E_MCR
value|0x08
end_define

begin_comment
comment|/* media change request */
end_comment

begin_define
define|#
directive|define
name|ATA_E_IDNF
value|0x10
end_define

begin_comment
comment|/* ID not found */
end_comment

begin_define
define|#
directive|define
name|ATA_E_MC
value|0x20
end_define

begin_comment
comment|/* media changed */
end_comment

begin_define
define|#
directive|define
name|ATA_E_UNC
value|0x40
end_define

begin_comment
comment|/* uncorrectable data */
end_comment

begin_define
define|#
directive|define
name|ATA_E_ICRC
value|0x80
end_define

begin_comment
comment|/* UDMA crc error */
end_comment

begin_define
define|#
directive|define
name|ATA_E_ATAPI_SENSE_MASK
value|0xf0
end_define

begin_comment
comment|/* ATAPI sense key mask */
end_comment

begin_define
define|#
directive|define
name|ATA_COUNT
value|0x108
end_define

begin_comment
comment|/* (W) sector count */
end_comment

begin_define
define|#
directive|define
name|ATA_IREASON
value|0x108
end_define

begin_comment
comment|/* (R) interrupt reason */
end_comment

begin_define
define|#
directive|define
name|ATA_I_CMD
value|0x01
end_define

begin_comment
comment|/* cmd (1) | data (0) */
end_comment

begin_define
define|#
directive|define
name|ATA_I_IN
value|0x02
end_define

begin_comment
comment|/* read (1) | write (0) */
end_comment

begin_define
define|#
directive|define
name|ATA_I_RELEASE
value|0x04
end_define

begin_comment
comment|/* released bus (1) */
end_comment

begin_define
define|#
directive|define
name|ATA_I_TAGMASK
value|0xf8
end_define

begin_comment
comment|/* tag mask */
end_comment

begin_define
define|#
directive|define
name|ATA_SECTOR
value|0x10c
end_define

begin_comment
comment|/* (RW) sector # */
end_comment

begin_define
define|#
directive|define
name|ATA_CYL_LSB
value|0x110
end_define

begin_comment
comment|/* (RW) cylinder# LSB */
end_comment

begin_define
define|#
directive|define
name|ATA_CYL_MSB
value|0x114
end_define

begin_comment
comment|/* (RW) cylinder# MSB */
end_comment

begin_define
define|#
directive|define
name|ATA_DRIVE
value|0x118
end_define

begin_comment
comment|/* (W) Sector/Drive/Head */
end_comment

begin_define
define|#
directive|define
name|ATA_D_LBA
value|0x40
end_define

begin_comment
comment|/* use LBA addressing */
end_comment

begin_define
define|#
directive|define
name|ATA_D_IBM
value|0xa0
end_define

begin_comment
comment|/* 512 byte sectors, ECC */
end_comment

begin_define
define|#
directive|define
name|ATA_COMMAND
value|0x11c
end_define

begin_comment
comment|/* (W) command */
end_comment

begin_define
define|#
directive|define
name|ATA_STATUS
value|0x11c
end_define

begin_comment
comment|/* (R) status */
end_comment

begin_define
define|#
directive|define
name|ATA_S_ERROR
value|0x01
end_define

begin_comment
comment|/* error */
end_comment

begin_define
define|#
directive|define
name|ATA_S_INDEX
value|0x02
end_define

begin_comment
comment|/* index */
end_comment

begin_define
define|#
directive|define
name|ATA_S_CORR
value|0x04
end_define

begin_comment
comment|/* data corrected */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DRQ
value|0x08
end_define

begin_comment
comment|/* data request */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DSC
value|0x10
end_define

begin_comment
comment|/* drive seek completed */
end_comment

begin_define
define|#
directive|define
name|ATA_S_SERVICE
value|0x10
end_define

begin_comment
comment|/* drive needs service */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DWF
value|0x20
end_define

begin_comment
comment|/* drive write fault */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DMA
value|0x20
end_define

begin_comment
comment|/* DMA ready */
end_comment

begin_define
define|#
directive|define
name|ATA_S_READY
value|0x40
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|ATA_S_BUSY
value|0x80
end_define

begin_comment
comment|/* busy */
end_comment

begin_define
define|#
directive|define
name|ATA_CONTROL
value|0x120
end_define

begin_comment
comment|/* (W) control */
end_comment

begin_define
define|#
directive|define
name|ATA_A_IDS
value|0x02
end_define

begin_comment
comment|/* disable interrupts */
end_comment

begin_define
define|#
directive|define
name|ATA_A_RESET
value|0x04
end_define

begin_comment
comment|/* RESET controller */
end_comment

begin_define
define|#
directive|define
name|ATA_A_4BIT
value|0x08
end_define

begin_comment
comment|/* 4 head bits */
end_comment

begin_define
define|#
directive|define
name|ATA_A_HOB
value|0x80
end_define

begin_comment
comment|/* High Order Byte enable */
end_comment

begin_define
define|#
directive|define
name|ATA_ALTSTAT
value|0x120
end_define

begin_comment
comment|/* (R) alternate status */
end_comment

begin_define
define|#
directive|define
name|ATAPI_P_READ
value|(ATA_S_DRQ | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_WRITE
value|(ATA_S_DRQ)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_CMDOUT
value|(ATA_S_DRQ | ATA_I_CMD)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_DONEDRQ
value|(ATA_S_DRQ | ATA_I_CMD | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_DONE
value|(ATA_I_CMD | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_ABORT
value|0
end_define

begin_comment
comment|/* Basic DMA Registers */
end_comment

begin_define
define|#
directive|define
name|DMA_C
value|0x224
end_define

begin_comment
comment|/* Basic DMA Command */
end_comment

begin_define
define|#
directive|define
name|DMA_C_START
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DMA_C_READ
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DMA_C_DREGIONVALID
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DMA_C_DREGIONLAST
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|DMA_C_CONTFROMPREV
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|DMA_C_DRBC
parameter_list|(
name|n
parameter_list|)
value|(((n)& 0xffff)<< 16)
end_define

begin_define
define|#
directive|define
name|DMA_S
value|0x228
end_define

begin_comment
comment|/* Basic DMA Status */
end_comment

begin_define
define|#
directive|define
name|DMA_S_ACT
value|(1<< 0)
end_define

begin_comment
comment|/* Active */
end_comment

begin_define
define|#
directive|define
name|DMA_S_ERR
value|(1<< 1)
end_define

begin_comment
comment|/* Error */
end_comment

begin_define
define|#
directive|define
name|DMA_S_PAUSED
value|(1<< 2)
end_define

begin_comment
comment|/* Paused */
end_comment

begin_define
define|#
directive|define
name|DMA_S_LAST
value|(1<< 3)
end_define

begin_comment
comment|/* Last */
end_comment

begin_define
define|#
directive|define
name|DMA_DTLBA
value|0x22c
end_define

begin_comment
comment|/* Descriptor Table Low Base Address */
end_comment

begin_define
define|#
directive|define
name|DMA_DTLBA_MASK
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|DMA_DTHBA
value|0x230
end_define

begin_comment
comment|/* Descriptor Table High Base Address */
end_comment

begin_define
define|#
directive|define
name|DMA_DRLA
value|0x234
end_define

begin_comment
comment|/* Data Region Low Address */
end_comment

begin_define
define|#
directive|define
name|DMA_DRHA
value|0x238
end_define

begin_comment
comment|/* Data Region High Address */
end_comment

begin_comment
comment|/* Serial-ATA Registers */
end_comment

begin_define
define|#
directive|define
name|SATA_SS
value|0x300
end_define

begin_comment
comment|/* SStatus */
end_comment

begin_define
define|#
directive|define
name|SATA_SS_DET_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|SATA_SS_DET_NO_DEVICE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SATA_SS_DET_DEV_PRESENT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SATA_SS_DET_PHY_ONLINE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|SATA_SS_DET_PHY_OFFLINE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SATA_SS_SPD_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|SATA_SS_SPD_NO_SPEED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SATA_SS_SPD_GEN1
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SATA_SS_SPD_GEN2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SATA_SS_SPD_GEN3
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SATA_SS_IPM_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|SATA_SS_IPM_NO_DEVICE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SATA_SS_IPM_ACTIVE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SATA_SS_IPM_PARTIAL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SATA_SS_IPM_SLUMBER
value|0x00000600
end_define

begin_define
define|#
directive|define
name|SATA_SE
value|0x304
end_define

begin_comment
comment|/* SError */
end_comment

begin_define
define|#
directive|define
name|SATA_SEIM
value|0x340
end_define

begin_comment
comment|/* SError Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|SATA_SE_DATA_CORRECTED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SATA_SE_COMM_CORRECTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SATA_SE_DATA_ERR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SATA_SE_COMM_ERR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SATA_SE_PROT_ERR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SATA_SE_HOST_ERR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SATA_SE_PHY_CHANGED
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SATA_SE_PHY_IERROR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SATA_SE_COMM_WAKE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SATA_SE_DECODE_ERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SATA_SE_PARITY_ERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SATA_SE_CRC_ERR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SATA_SE_HANDSHAKE_ERR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SATA_SE_LINKSEQ_ERR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SATA_SE_TRANSPORT_ERR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SATA_SE_UNKNOWN_FIS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SATA_SC
value|0x308
end_define

begin_comment
comment|/* SControl */
end_comment

begin_define
define|#
directive|define
name|SATA_SC_DET_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|SATA_SC_DET_IDLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SATA_SC_DET_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SATA_SC_DET_DISABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SATA_SC_SPD_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|SATA_SC_SPD_NO_SPEED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SATA_SC_SPD_SPEED_GEN1
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SATA_SC_SPD_SPEED_GEN2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SATA_SC_SPD_SPEED_GEN3
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SATA_SC_IPM_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|SATA_SC_IPM_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SATA_SC_IPM_DIS_PARTIAL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SATA_SC_IPM_DIS_SLUMBER
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SATA_SC_SPM_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|SATA_SC_SPM_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SATA_SC_SPM_PARTIAL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SATA_SC_SPM_SLUMBER
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SATA_SC_SPM_ACTIVE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SATA_LTM
value|0x30c
end_define

begin_comment
comment|/* LTMode */
end_comment

begin_define
define|#
directive|define
name|SATA_PHYM3
value|0x310
end_define

begin_comment
comment|/* PHY Mode 3 */
end_comment

begin_define
define|#
directive|define
name|SATA_PHYM4
value|0x314
end_define

begin_comment
comment|/* PHY Mode 4 */
end_comment

begin_define
define|#
directive|define
name|SATA_PHYM1
value|0x32c
end_define

begin_comment
comment|/* PHY Mode 1 */
end_comment

begin_define
define|#
directive|define
name|SATA_PHYM2
value|0x330
end_define

begin_comment
comment|/* PHY Mode 2 */
end_comment

begin_define
define|#
directive|define
name|SATA_BISTC
value|0x334
end_define

begin_comment
comment|/* BIST Control */
end_comment

begin_define
define|#
directive|define
name|SATA_BISTDW1
value|0x338
end_define

begin_comment
comment|/* BIST DW1 */
end_comment

begin_define
define|#
directive|define
name|SATA_BISTDW2
value|0x33c
end_define

begin_comment
comment|/* BIST DW2 */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICFG
value|0x050
end_define

begin_comment
comment|/* Serial-ATA Interface Configuration */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKCNF_20MHZ
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKCNF_25MHZ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKCNF_30MHZ
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKCNF_40MHZ
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKCNF_MASK
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKDIV_1
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKDIV_2
value|(1<< 2)
end_define

begin_comment
comment|/* Used 20 or 25MHz */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKDIV_4
value|(2<< 2)
end_define

begin_comment
comment|/* Used 40MHz */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKDIV_3
value|(3<< 2)
end_define

begin_comment
comment|/* Used 30MHz */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKDIV_MASK
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKFEEDDIV_50
value|(0<< 4)
end_define

begin_comment
comment|/* or 100, when Gen2En is 1 */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKFEEDDIV_60
value|(1<< 4)
end_define

begin_comment
comment|/* or 120. Used 25MHz */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKFEEDDIV_75
value|(2<< 4)
end_define

begin_comment
comment|/* or 150. Used 20MHz */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKFEEDDIV_90
value|(3<< 4)
end_define

begin_comment
comment|/* or 180 */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICFG_REFCLKFEEDDIV_MASK
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_PHYSSCEN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_GEN2EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_COMMEN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_PHYSHUTDOWN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_TARGETMODE
value|(1<< 10)
end_define

begin_comment
comment|/* 1 = Initiator */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICFG_COMCHANNEL
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_IGNOREBSY
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_LINKRSTEN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICFG_CMDRETXDS
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICTL
value|0x344
end_define

begin_comment
comment|/* Serial-ATA Interface Control */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAICTL_PMPTX_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|SATA_SATAICTL_PMPTX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SATA_SATAICTL_VUM
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICTL_VUS
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICTL_EDMAACT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICTL_CLEARSTAT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|SATA_SATAICTL_SRST
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|SATA_SATAITC
value|0x348
end_define

begin_comment
comment|/* Serial-ATA Interface Test Control */
end_comment

begin_define
define|#
directive|define
name|SATA_SATAIS
value|0x34c
end_define

begin_comment
comment|/* Serial-ATA Interface Status */
end_comment

begin_define
define|#
directive|define
name|SATA_VU
value|0x35c
end_define

begin_comment
comment|/* Vendor Unique */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC
value|0x360
end_define

begin_comment
comment|/* FIS Configuration */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4RDYEN_B0
value|(1<< 0)
end_define

begin_comment
comment|/* Device to Host FIS */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4RDYEN_B1
value|(1<< 1)
end_define

begin_comment
comment|/* SDB FIS rcv with<N>bit 0 */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4RDYEN_B2
value|(1<< 2)
end_define

begin_comment
comment|/* DMA Activate FIS */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4RDYEN_B3
value|(1<< 3)
end_define

begin_comment
comment|/* DMA Setup FIS */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4RDYEN_B4
value|(1<< 4)
end_define

begin_comment
comment|/* Data FIS first DW */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4RDYEN_B5
value|(1<< 5)
end_define

begin_comment
comment|/* Data FIS entire FIS */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4HOSTRDYEN_B0
value|(1<< 8)
end_define

begin_comment
comment|/* Device to Host FIS with<ERR> or<DF> */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4HOSTRDYEN_B1
value|(1<< 9)
end_define

begin_comment
comment|/* SDB FIS rcv with<N>bit */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4HOSTRDYEN_B2
value|(1<< 10)
end_define

begin_comment
comment|/* SDB FIS rcv with<ERR> */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4HOSTRDYEN_B3
value|(1<< 11)
end_define

begin_comment
comment|/* BIST Acivate FIS */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4HOSTRDYEN_B4
value|(1<< 12)
end_define

begin_comment
comment|/* PIO Setup FIS */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4HOSTRDYEN_B5
value|(1<< 13)
end_define

begin_comment
comment|/* Data FIS with Link error */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4HOSTRDYEN_B6
value|(1<< 14)
end_define

begin_comment
comment|/* Unrecognized FIS type */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISWAIT4HOSTRDYEN_B7
value|(1<< 15)
end_define

begin_comment
comment|/* Any FIS */
end_comment

begin_define
define|#
directive|define
name|SATA_FISC_FISDMAACTIVATESYNCRESP
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SATA_FISC_FISUNRECTYPECONT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|SATA_FISIC
value|0x364
end_define

begin_comment
comment|/* FIS Interrupt Cause */
end_comment

begin_define
define|#
directive|define
name|SATA_FISIM
value|0x368
end_define

begin_comment
comment|/* FIS Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|SATA_FISDW0
value|0x370
end_define

begin_comment
comment|/* FIS DW0 */
end_comment

begin_define
define|#
directive|define
name|SATA_FISDW1
value|0x374
end_define

begin_comment
comment|/* FIS DW1 */
end_comment

begin_define
define|#
directive|define
name|SATA_FISDW2
value|0x378
end_define

begin_comment
comment|/* FIS DW2 */
end_comment

begin_define
define|#
directive|define
name|SATA_FISDW3
value|0x37c
end_define

begin_comment
comment|/* FIS DW3 */
end_comment

begin_define
define|#
directive|define
name|SATA_FISDW4
value|0x380
end_define

begin_comment
comment|/* FIS DW4 */
end_comment

begin_define
define|#
directive|define
name|SATA_FISDW5
value|0x384
end_define

begin_comment
comment|/* FIS DW5 */
end_comment

begin_define
define|#
directive|define
name|SATA_FISDW6
value|0x388
end_define

begin_comment
comment|/* FIS DW6 */
end_comment

begin_define
define|#
directive|define
name|SATA_PHYM9_GEN2
value|0x398
end_define

begin_define
define|#
directive|define
name|SATA_PHYM9_GEN1
value|0x39c
end_define

begin_define
define|#
directive|define
name|SATA_PHYCFG_OFS
value|0x3a0
end_define

begin_comment
comment|/* 65nm SoCs only */
end_comment

begin_define
define|#
directive|define
name|MVS_MAX_PORTS
value|8
end_define

begin_define
define|#
directive|define
name|MVS_MAX_SLOTS
value|32
end_define

begin_comment
comment|/* Pessimistic prognosis on number of required S/G entries */
end_comment

begin_define
define|#
directive|define
name|MVS_SG_ENTRIES
value|(btoc(MAXPHYS) + 1)
end_define

begin_comment
comment|/* EDMA Command Request Block (CRQB) Data */
end_comment

begin_struct
struct|struct
name|mvs_crqb
block|{
name|uint32_t
name|cprdbl
decl_stmt|;
comment|/* cPRD Desriptor Table Base Low Address */
name|uint32_t
name|cprdbh
decl_stmt|;
comment|/* cPRD Desriptor Table Base High Address */
name|uint16_t
name|ctrlflg
decl_stmt|;
comment|/* Control Flags */
define|#
directive|define
name|MVS_CRQB_READ
value|0x0001
define|#
directive|define
name|MVS_CRQB_TAG_MASK
value|0x003e
define|#
directive|define
name|MVS_CRQB_TAG_SHIFT
value|1
define|#
directive|define
name|MVS_CRQB_PMP_MASK
value|0xf000
define|#
directive|define
name|MVS_CRQB_PMP_SHIFT
value|12
name|uint8_t
name|cmd
index|[
literal|22
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mvs_crqb_gen2e
block|{
name|uint32_t
name|cprdbl
decl_stmt|;
comment|/* cPRD Desriptor Table Base Low Address */
name|uint32_t
name|cprdbh
decl_stmt|;
comment|/* cPRD Desriptor Table Base High Address */
name|uint32_t
name|ctrlflg
decl_stmt|;
comment|/* Control Flags */
define|#
directive|define
name|MVS_CRQB2E_READ
value|0x00000001
define|#
directive|define
name|MVS_CRQB2E_DTAG_MASK
value|0x0000003e
define|#
directive|define
name|MVS_CRQB2E_DTAG_SHIFT
value|1
define|#
directive|define
name|MVS_CRQB2E_PMP_MASK
value|0x0000f000
define|#
directive|define
name|MVS_CRQB2E_PMP_SHIFT
value|12
define|#
directive|define
name|MVS_CRQB2E_CPRD
value|0x00010000
define|#
directive|define
name|MVS_CRQB2E_HTAG_MASK
value|0x003e0000
define|#
directive|define
name|MVS_CRQB2E_HTAG_SHIFT
value|17
name|uint32_t
name|drbc
decl_stmt|;
comment|/* Data Region Byte Count */
name|uint8_t
name|cmd
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* EDMA Phisical Region Descriptors (ePRD) Table Data Structure */
end_comment

begin_struct
struct|struct
name|mvs_eprd
block|{
name|uint32_t
name|prdbal
decl_stmt|;
comment|/* Address bits[31:1] */
name|uint32_t
name|bytecount
decl_stmt|;
comment|/* Byte Count */
define|#
directive|define
name|MVS_EPRD_MASK
value|0x0000ffff
comment|/* max 64KB */
define|#
directive|define
name|MVS_EPRD_MAX
value|(MVS_EPRD_MASK + 1)
define|#
directive|define
name|MVS_EPRD_EOF
value|0x80000000
name|uint32_t
name|prdbah
decl_stmt|;
comment|/* Address bits[63:32] */
name|uint32_t
name|resv
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Command request blocks. 32 commands. First 1Kbyte aligned. */
end_comment

begin_define
define|#
directive|define
name|MVS_CRQB_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|MVS_CRQB_SIZE
value|32
end_define

begin_comment
comment|/* sizeof(struct mvs_crqb) */
end_comment

begin_define
define|#
directive|define
name|MVS_CRQB_MASK
value|0x000003e0
end_define

begin_define
define|#
directive|define
name|MVS_CRQB_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|MVS_CRQB_TO_ADDR
parameter_list|(
name|slot
parameter_list|)
value|((slot)<< MVS_CRQB_SHIFT)
end_define

begin_define
define|#
directive|define
name|MVS_ADDR_TO_CRQB
parameter_list|(
name|addr
parameter_list|)
value|(((addr)& MVS_CRQB_MASK)>> MVS_CRQB_SHIFT)
end_define

begin_comment
comment|/* ePRD blocks. Up to 32 commands, Each 16byte aligned. */
end_comment

begin_define
define|#
directive|define
name|MVS_EPRD_OFFSET
value|(MVS_CRQB_OFFSET + MVS_CRQB_SIZE * MVS_MAX_SLOTS)
end_define

begin_define
define|#
directive|define
name|MVS_EPRD_SIZE
value|(MVS_SG_ENTRIES * 16)
end_define

begin_comment
comment|/* sizeof(struct mvs_eprd) */
end_comment

begin_comment
comment|/* Request work area. */
end_comment

begin_define
define|#
directive|define
name|MVS_WORKRQ_SIZE
value|(MVS_EPRD_OFFSET + MVS_EPRD_SIZE * MVS_MAX_SLOTS)
end_define

begin_comment
comment|/* EDMA Command Response Block (CRPB) Data */
end_comment

begin_struct
struct|struct
name|mvs_crpb
block|{
name|uint16_t
name|id
decl_stmt|;
comment|/* CRPB ID */
define|#
directive|define
name|MVS_CRPB_TAG_MASK
value|0x001F
define|#
directive|define
name|MVS_CRPB_TAG_SHIFT
value|0
name|uint16_t
name|rspflg
decl_stmt|;
comment|/* CPRB Response Flags */
define|#
directive|define
name|MVS_CRPB_EDMASTS_MASK
value|0x007F
define|#
directive|define
name|MVS_CRPB_EDMASTS_SHIFT
value|0
define|#
directive|define
name|MVS_CRPB_ATASTS_MASK
value|0xFF00
define|#
directive|define
name|MVS_CRPB_ATASTS_SHIFT
value|8
name|uint32_t
name|ts
decl_stmt|;
comment|/* CPRB Time Stamp */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Command response blocks. 32 commands. First 256byte aligned. */
end_comment

begin_define
define|#
directive|define
name|MVS_CRPB_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|MVS_CRPB_SIZE
value|sizeof(struct mvs_crpb)
end_define

begin_define
define|#
directive|define
name|MVS_CRPB_MASK
value|0x000000f8
end_define

begin_define
define|#
directive|define
name|MVS_CRPB_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|MVS_CRPB_TO_ADDR
parameter_list|(
name|slot
parameter_list|)
value|((slot)<< MVS_CRPB_SHIFT)
end_define

begin_define
define|#
directive|define
name|MVS_ADDR_TO_CRPB
parameter_list|(
name|addr
parameter_list|)
value|(((addr)& MVS_CRPB_MASK)>> MVS_CRPB_SHIFT)
end_define

begin_comment
comment|/* Request work area. */
end_comment

begin_define
define|#
directive|define
name|MVS_WORKRP_SIZE
value|(MVS_CRPB_OFFSET + MVS_CRPB_SIZE * MVS_MAX_SLOTS)
end_define

begin_comment
comment|/* misc defines */
end_comment

begin_define
define|#
directive|define
name|ATA_IRQ_RID
value|0
end_define

begin_define
define|#
directive|define
name|ATA_INTR_FLAGS
value|(INTR_MPSAFE|INTR_TYPE_BIO|INTR_ENTROPY)
end_define

begin_struct
struct|struct
name|ata_dmaslot
block|{
name|bus_dmamap_t
name|data_map
decl_stmt|;
comment|/* Data DMA map */
name|bus_addr_t
name|addr
decl_stmt|;
comment|/* Data address */
name|uint16_t
name|len
decl_stmt|;
comment|/* Data size */
block|}
struct|;
end_struct

begin_comment
comment|/* structure holding DMA related information */
end_comment

begin_struct
struct|struct
name|mvs_dma
block|{
name|bus_dma_tag_t
name|workrq_tag
decl_stmt|;
comment|/* Request workspace DMA tag */
name|bus_dmamap_t
name|workrq_map
decl_stmt|;
comment|/* Request workspace DMA map */
name|uint8_t
modifier|*
name|workrq
decl_stmt|;
comment|/* Request workspace */
name|bus_addr_t
name|workrq_bus
decl_stmt|;
comment|/* Request bus address */
name|bus_dma_tag_t
name|workrp_tag
decl_stmt|;
comment|/* Reply workspace DMA tag */
name|bus_dmamap_t
name|workrp_map
decl_stmt|;
comment|/* Reply workspace DMA map */
name|uint8_t
modifier|*
name|workrp
decl_stmt|;
comment|/* Reply workspace */
name|bus_addr_t
name|workrp_bus
decl_stmt|;
comment|/* Reply bus address */
name|bus_dma_tag_t
name|data_tag
decl_stmt|;
comment|/* Data DMA tag */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|mvs_slot_states
block|{
name|MVS_SLOT_EMPTY
block|,
name|MVS_SLOT_LOADING
block|,
name|MVS_SLOT_RUNNING
block|,
name|MVS_SLOT_EXECUTING
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mvs_slot
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* Device handle */
name|int
name|slot
decl_stmt|;
comment|/* Number of this slot */
name|int
name|tag
decl_stmt|;
comment|/* Used command tag */
name|enum
name|mvs_slot_states
name|state
decl_stmt|;
comment|/* Slot state */
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
comment|/* CCB occupying slot */
name|struct
name|ata_dmaslot
name|dma
decl_stmt|;
comment|/* DMA data of this slot */
name|struct
name|callout
name|timeout
decl_stmt|;
comment|/* Execution timeout */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mvs_device
block|{
name|int
name|revision
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|u_int
name|bytecount
decl_stmt|;
name|u_int
name|atapi
decl_stmt|;
name|u_int
name|tags
decl_stmt|;
name|u_int
name|caps
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|mvs_edma_mode
block|{
name|MVS_EDMA_UNKNOWN
block|,
name|MVS_EDMA_OFF
block|,
name|MVS_EDMA_ON
block|,
name|MVS_EDMA_QUEUED
block|,
name|MVS_EDMA_NCQ
block|, }
enum|;
end_enum

begin_comment
comment|/* structure describing an ATA channel */
end_comment

begin_struct
struct|struct
name|mvs_channel
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* Device handle */
name|int
name|unit
decl_stmt|;
comment|/* Physical channel */
name|struct
name|resource
modifier|*
name|r_mem
decl_stmt|;
comment|/* Memory of this channel */
name|struct
name|resource
modifier|*
name|r_irq
decl_stmt|;
comment|/* Interrupt of this channel */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* Interrupt handle */
name|struct
name|mvs_dma
name|dma
decl_stmt|;
comment|/* DMA data */
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|int
name|quirks
decl_stmt|;
define|#
directive|define
name|MVS_Q_GENI
value|1
define|#
directive|define
name|MVS_Q_GENII
value|2
define|#
directive|define
name|MVS_Q_GENIIE
value|4
define|#
directive|define
name|MVS_Q_SOC
value|8
define|#
directive|define
name|MVS_Q_CT
value|16
define|#
directive|define
name|MVS_Q_SOC65
value|32
name|int
name|pm_level
decl_stmt|;
comment|/* power management level */
name|struct
name|mvs_slot
name|slot
index|[
name|MVS_MAX_SLOTS
index|]
decl_stmt|;
name|union
name|ccb
modifier|*
name|hold
index|[
name|MVS_MAX_SLOTS
index|]
decl_stmt|;
name|int
name|holdtag
index|[
name|MVS_MAX_SLOTS
index|]
decl_stmt|;
comment|/* Tags used for held commands. */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* state lock */
name|int
name|devices
decl_stmt|;
comment|/* What is present */
name|int
name|pm_present
decl_stmt|;
comment|/* PM presence reported */
name|enum
name|mvs_edma_mode
name|curr_mode
decl_stmt|;
comment|/* Current EDMA mode */
name|int
name|fbs_enabled
decl_stmt|;
comment|/* FIS-based switching enabled */
name|uint32_t
name|oslots
decl_stmt|;
comment|/* Occupied slots */
name|uint32_t
name|otagspd
index|[
literal|16
index|]
decl_stmt|;
comment|/* Occupied device tags */
name|uint32_t
name|rslots
decl_stmt|;
comment|/* Running slots */
name|uint32_t
name|aslots
decl_stmt|;
comment|/* Slots with atomic commands  */
name|uint32_t
name|eslots
decl_stmt|;
comment|/* Slots in error */
name|uint32_t
name|toslots
decl_stmt|;
comment|/* Slots in timeout */
name|int
name|numrslots
decl_stmt|;
comment|/* Number of running slots */
name|int
name|numrslotspd
index|[
literal|16
index|]
decl_stmt|;
comment|/* Number of running slots per dev */
name|int
name|numpslots
decl_stmt|;
comment|/* Number of PIO slots */
name|int
name|numdslots
decl_stmt|;
comment|/* Number of DMA slots */
name|int
name|numtslots
decl_stmt|;
comment|/* Number of NCQ slots */
name|int
name|numtslotspd
index|[
literal|16
index|]
decl_stmt|;
comment|/* Number of NCQ slots per dev */
name|int
name|numhslots
decl_stmt|;
comment|/* Number of held slots */
name|int
name|recoverycmd
decl_stmt|;
comment|/* Our READ LOG active */
name|int
name|fatalerr
decl_stmt|;
comment|/* Fatal error happend */
name|int
name|lastslot
decl_stmt|;
comment|/* Last used slot */
name|int
name|taggedtarget
decl_stmt|;
comment|/* Last tagged target */
name|int
name|resetting
decl_stmt|;
comment|/* Hard-reset in progress. */
name|int
name|resetpolldiv
decl_stmt|;
comment|/* Hard-reset poll divider. */
name|int
name|out_idx
decl_stmt|;
comment|/* Next written CRQB */
name|int
name|in_idx
decl_stmt|;
comment|/* Next read CRPB */
name|u_int
name|transfersize
decl_stmt|;
comment|/* PIO transfer size */
name|u_int
name|donecount
decl_stmt|;
comment|/* PIO bytes sent/received */
name|u_int
name|basic_dma
decl_stmt|;
comment|/* Basic DMA used for ATAPI */
name|u_int
name|fake_busy
decl_stmt|;
comment|/* Fake busy bit after command submission */
name|union
name|ccb
modifier|*
name|frozen
decl_stmt|;
comment|/* Frozen command */
name|struct
name|callout
name|pm_timer
decl_stmt|;
comment|/* Power management events */
name|struct
name|callout
name|reset_timer
decl_stmt|;
comment|/* Hard-reset timeout */
name|struct
name|mvs_device
name|user
index|[
literal|16
index|]
decl_stmt|;
comment|/* User-specified settings */
name|struct
name|mvs_device
name|curr
index|[
literal|16
index|]
decl_stmt|;
comment|/* Current settings */
block|}
struct|;
end_struct

begin_comment
comment|/* structure describing a MVS controller */
end_comment

begin_struct
struct|struct
name|mvs_controller
block|{
name|device_t
name|dev
decl_stmt|;
name|int
name|r_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_mem
decl_stmt|;
name|struct
name|rman
name|sc_iomem
decl_stmt|;
struct|struct
name|mvs_controller_irq
block|{
name|struct
name|resource
modifier|*
name|r_irq
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
name|int
name|r_irq_rid
decl_stmt|;
block|}
name|irq
struct|;
name|int
name|quirks
decl_stmt|;
name|int
name|channels
decl_stmt|;
name|int
name|ccc
decl_stmt|;
comment|/* CCC timeout */
name|int
name|cccc
decl_stmt|;
comment|/* CCC commands */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* MIM access lock */
name|int
name|gmim
decl_stmt|;
comment|/* Globally wanted MIM bits */
name|int
name|pmim
decl_stmt|;
comment|/* Port wanted MIM bits */
name|int
name|mim
decl_stmt|;
comment|/* Current MIM bits */
name|int
name|msi
decl_stmt|;
comment|/* MSI enabled */
name|int
name|msia
decl_stmt|;
comment|/* MSI active */
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|argument
decl_stmt|;
block|}
name|interrupt
index|[
name|MVS_MAX_PORTS
index|]
struct|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|mvs_err_type
block|{
name|MVS_ERR_NONE
block|,
comment|/* No error */
name|MVS_ERR_INVALID
block|,
comment|/* Error detected by us before submitting. */
name|MVS_ERR_INNOCENT
block|,
comment|/* Innocent victim. */
name|MVS_ERR_TFE
block|,
comment|/* Task File Error. */
name|MVS_ERR_SATA
block|,
comment|/* SATA error. */
name|MVS_ERR_TIMEOUT
block|,
comment|/* Command execution timeout. */
name|MVS_ERR_NCQ
block|,
comment|/* NCQ command error. CCB should be put on hold 				 * until READ LOG executed to reveal error. */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mvs_intr_arg
block|{
name|void
modifier|*
name|arg
decl_stmt|;
name|u_int
name|cause
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|mvs_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* macros to hide busspace uglyness */
end_comment

begin_define
define|#
directive|define
name|ATA_INB
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_read_1((res), (offset))
end_define

begin_define
define|#
directive|define
name|ATA_INW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_read_2((res), (offset))
end_define

begin_define
define|#
directive|define
name|ATA_INL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_read_4((res), (offset))
end_define

begin_define
define|#
directive|define
name|ATA_INSW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_read_multi_2((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_INSW_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_read_multi_stream_2((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_INSL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_read_multi_4((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_INSL_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_read_multi_stream_4((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTB
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_1((res), (offset), (value))
end_define

begin_define
define|#
directive|define
name|ATA_OUTW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_2((res), (offset), (value))
end_define

begin_define
define|#
directive|define
name|ATA_OUTL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_4((res), (offset), (value));
end_define

begin_define
define|#
directive|define
name|ATA_OUTSW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_write_multi_2((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSW_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_write_multi_stream_2((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_write_multi_4((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSL_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_write_multi_stream_4((res), (offset), (addr), (count))
end_define

end_unit


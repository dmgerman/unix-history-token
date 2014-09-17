begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Berndt Walter.  All rights reserved.  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_MCIREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_MCIREG_H
end_define

begin_define
define|#
directive|define
name|MMC_MAX
value|30
end_define

begin_define
define|#
directive|define
name|MCI_CR
value|0x00
end_define

begin_comment
comment|/* MCI Control Register */
end_comment

begin_define
define|#
directive|define
name|MCI_MR
value|0x04
end_define

begin_comment
comment|/* MCI Mode Register */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR
value|0x08
end_define

begin_comment
comment|/* MCI Data Timeout Register */
end_comment

begin_define
define|#
directive|define
name|MCI_SDCR
value|0x0c
end_define

begin_comment
comment|/* MCI SD Card Register */
end_comment

begin_define
define|#
directive|define
name|MCI_ARGR
value|0x10
end_define

begin_comment
comment|/* MCI Argument Register */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR
value|0x14
end_define

begin_comment
comment|/* MCI Command Register */
end_comment

begin_define
define|#
directive|define
name|MCI_RSPR
value|0x20
end_define

begin_comment
comment|/* MCI Response Registers - 4 of them */
end_comment

begin_define
define|#
directive|define
name|MCI_RDR
value|0x30
end_define

begin_comment
comment|/* MCI Receive Data Register */
end_comment

begin_define
define|#
directive|define
name|MCI_TDR
value|0x34
end_define

begin_comment
comment|/* MCI Transmit Data Register */
end_comment

begin_define
define|#
directive|define
name|MCI_SR
value|0x40
end_define

begin_comment
comment|/* MCI Status Register */
end_comment

begin_define
define|#
directive|define
name|MCI_IER
value|0x44
end_define

begin_comment
comment|/* MCI Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|MCI_IDR
value|0x48
end_define

begin_comment
comment|/* MCI Interrupt Disable Register */
end_comment

begin_define
define|#
directive|define
name|MCI_IMR
value|0x4c
end_define

begin_comment
comment|/* MCI Interrupt Mask Register */
end_comment

begin_comment
comment|/* -------- MCI_CR : (MCI Offset: 0x0) MCI Control Register --------  */
end_comment

begin_define
define|#
directive|define
name|MCI_CR_MCIEN
value|(0x1u<<  0)
end_define

begin_comment
comment|/* (MCI) Multimedia Interface Enable */
end_comment

begin_define
define|#
directive|define
name|MCI_CR_MCIDIS
value|(0x1u<<  1)
end_define

begin_comment
comment|/* (MCI) Multimedia Interface Disable */
end_comment

begin_define
define|#
directive|define
name|MCI_CR_PWSEN
value|(0x1u<<  2)
end_define

begin_comment
comment|/* (MCI) Power Save Mode Enable */
end_comment

begin_define
define|#
directive|define
name|MCI_CR_PWSDIS
value|(0x1u<<  3)
end_define

begin_comment
comment|/* (MCI) Power Save Mode Disable */
end_comment

begin_define
define|#
directive|define
name|MCI_CR_SWRST
value|(0x1u<<  7)
end_define

begin_comment
comment|/* (MCI) Software Reset */
end_comment

begin_comment
comment|/* -------- MCI_MR : (MCI Offset: 0x4) MCI Mode Register --------  */
end_comment

begin_define
define|#
directive|define
name|MCI_MR_CLKDIV
value|(0xffu<<  0)
end_define

begin_comment
comment|/* (MCI) Clock Divider */
end_comment

begin_define
define|#
directive|define
name|MCI_MR_PWSDIV
value|(0x3fu<<  8)
end_define

begin_comment
comment|/* (MCI) Power Saving Divider */
end_comment

begin_define
define|#
directive|define
name|MCI_MR_RDPROOF
value|(0x1u<< 11)
end_define

begin_comment
comment|/* (MCI) Read Proof Enable */
end_comment

begin_define
define|#
directive|define
name|MCI_MR_WRPROOF
value|(0x1u<< 12)
end_define

begin_comment
comment|/* (MCI) Write Proof Enable */
end_comment

begin_define
define|#
directive|define
name|MCI_MR_PDCFBYTE
value|(0x1u<< 13)
end_define

begin_comment
comment|/* (MCI) PDC Force Byte Transfer */
end_comment

begin_define
define|#
directive|define
name|MCI_MR_PDCPADV
value|(0x1u<< 14)
end_define

begin_comment
comment|/* (MCI) PDC Padding Value */
end_comment

begin_define
define|#
directive|define
name|MCI_MR_PDCMODE
value|(0x1u<< 15)
end_define

begin_comment
comment|/* (MCI) PDC Oriented Mode */
end_comment

begin_define
define|#
directive|define
name|MCI_MR_BLKLEN
value|0x3fff0000ul
end_define

begin_comment
comment|/* (MCI) Data Block Length */
end_comment

begin_comment
comment|/* -------- MCI_DTOR : (MCI Offset: 0x8) MCI Data Timeout Register --------  */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR_DTOCYC
value|(0xfu<<  0)
end_define

begin_comment
comment|/* (MCI) Data Timeout Cycle Number */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR_DTOMUL
value|(0x7u<<  4)
end_define

begin_comment
comment|/* (MCI) Data Timeout Multiplier */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR_DTOMUL_1
value|(0x0u<<  4)
end_define

begin_comment
comment|/* (MCI) DTOCYC x 1 */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR_DTOMUL_16
value|(0x1u<<  4)
end_define

begin_comment
comment|/* (MCI) DTOCYC x 16 */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR_DTOMUL_128
value|(0x2u<<  4)
end_define

begin_comment
comment|/* (MCI) DTOCYC x 128 */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR_DTOMUL_256
value|(0x3u<<  4)
end_define

begin_comment
comment|/* (MCI) DTOCYC x 256 */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR_DTOMUL_1k
value|(0x4u<<  4)
end_define

begin_comment
comment|/* (MCI) DTOCYC x 1024 */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR_DTOMUL_4k
value|(0x5u<<  4)
end_define

begin_comment
comment|/* (MCI) DTOCYC x 4096 */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR_DTOMUL_64k
value|(0x6u<<  4)
end_define

begin_comment
comment|/* (MCI) DTOCYC x 65536 */
end_comment

begin_define
define|#
directive|define
name|MCI_DTOR_DTOMUL_1M
value|(0x7u<<  4)
end_define

begin_comment
comment|/* (MCI) DTOCYC x 1048576 */
end_comment

begin_comment
comment|/* -------- MCI_SDCR : (MCI Offset: 0xc) MCI SD Card Register --------  */
end_comment

begin_define
define|#
directive|define
name|MCI_SDCR_SDCSEL
value|(0x1u<<  0)
end_define

begin_comment
comment|/* (MCI) SD Card Selector */
end_comment

begin_define
define|#
directive|define
name|MCI_SDCR_SDCBUS
value|(0x1u<<  7)
end_define

begin_comment
comment|/* (MCI) SD Card Bus Width */
end_comment

begin_comment
comment|/* -------- MCI_CMDR : (MCI Offset: 0x14) MCI Command Register --------  */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_CMDNB
value|(0x1Fu<<  0)
end_define

begin_comment
comment|/* (MCI) Command Number */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_RSPTYP
value|(0x3u<<  6)
end_define

begin_comment
comment|/* (MCI) Response Type */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_RSPTYP_NO
value|(0x0u<<  6)
end_define

begin_comment
comment|/* (MCI) No response */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_RSPTYP_48
value|(0x1u<<  6)
end_define

begin_comment
comment|/* (MCI) 48-bit response */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_RSPTYP_136
value|(0x2u<<  6)
end_define

begin_comment
comment|/* (MCI) 136-bit response */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_SPCMD
value|(0x7u<<  8)
end_define

begin_comment
comment|/* (MCI) Special CMD */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_SPCMD_NONE
value|(0x0u<<  8)
end_define

begin_comment
comment|/* (MCI) Not a special CMD */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_SPCMD_INIT
value|(0x1u<<  8)
end_define

begin_comment
comment|/* (MCI) Initialization CMD */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_SPCMD_SYNC
value|(0x2u<<  8)
end_define

begin_comment
comment|/* (MCI) Synchronized CMD */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_SPCMD_IT_CMD
value|(0x4u<<  8)
end_define

begin_comment
comment|/* (MCI) Interrupt command */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_SPCMD_IT_REP
value|(0x5u<<  8)
end_define

begin_comment
comment|/* (MCI) Interrupt response */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_OPDCMD
value|(0x1u<< 11)
end_define

begin_comment
comment|/* (MCI) Open Drain Command */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_MAXLAT
value|(0x1u<< 12)
end_define

begin_comment
comment|/* (MCI) Maximum Latency for Command to respond */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_TRCMD
value|(0x3u<< 16)
end_define

begin_comment
comment|/* (MCI) Transfer CMD */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_TRCMD_NO
value|(0x0u<< 16)
end_define

begin_comment
comment|/* (MCI) No transfer */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_TRCMD_START
value|(0x1u<< 16)
end_define

begin_comment
comment|/* (MCI) Start transfer */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_TRCMD_STOP
value|(0x2u<< 16)
end_define

begin_comment
comment|/* (MCI) Stop transfer */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_TRDIR
value|(0x1u<< 18)
end_define

begin_comment
comment|/* (MCI) Transfer Direction */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_TRTYP
value|(0x3u<< 19)
end_define

begin_comment
comment|/* (MCI) Transfer Type */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_TRTYP_BLOCK
value|(0x0u<< 19)
end_define

begin_comment
comment|/* (MCI) Block Transfer type */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_TRTYP_MULTIPLE
value|(0x1u<< 19)
end_define

begin_comment
comment|/* (MCI) Multiple Block transfer type */
end_comment

begin_define
define|#
directive|define
name|MCI_CMDR_TRTYP_STREAM
value|(0x2u<< 19)
end_define

begin_comment
comment|/* (MCI) Stream transfer type */
end_comment

begin_comment
comment|/* -------- MCI_SR : (MCI Offset: 0x40) MCI Status Register --------  */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_CMDRDY
value|(0x1u<<  0)
end_define

begin_comment
comment|/* (MCI) Command Ready flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_RXRDY
value|(0x1u<<  1)
end_define

begin_comment
comment|/* (MCI) RX Ready flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_TXRDY
value|(0x1u<<  2)
end_define

begin_comment
comment|/* (MCI) TX Ready flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_BLKE
value|(0x1u<<  3)
end_define

begin_comment
comment|/* (MCI) Data Block Transfer Ended flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_DTIP
value|(0x1u<<  4)
end_define

begin_comment
comment|/* (MCI) Data Transfer in Progress flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_NOTBUSY
value|(0x1u<<  5)
end_define

begin_comment
comment|/* (MCI) Data Line Not Busy flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_ENDRX
value|(0x1u<<  6)
end_define

begin_comment
comment|/* (MCI) End of RX Buffer flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_ENDTX
value|(0x1u<<  7)
end_define

begin_comment
comment|/* (MCI) End of TX Buffer flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_RXBUFF
value|(0x1u<< 14)
end_define

begin_comment
comment|/* (MCI) RX Buffer Full flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_TXBUFE
value|(0x1u<< 15)
end_define

begin_comment
comment|/* (MCI) TX Buffer Empty flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_RINDE
value|(0x1u<< 16)
end_define

begin_comment
comment|/* (MCI) Response Index Error flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_RDIRE
value|(0x1u<< 17)
end_define

begin_comment
comment|/* (MCI) Response Direction Error flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_RCRCE
value|(0x1u<< 18)
end_define

begin_comment
comment|/* (MCI) Response CRC Error flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_RENDE
value|(0x1u<< 19)
end_define

begin_comment
comment|/* (MCI) Response End Bit Error flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_RTOE
value|(0x1u<< 20)
end_define

begin_comment
comment|/* (MCI) Response Time-out Error flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_DCRCE
value|(0x1u<< 21)
end_define

begin_comment
comment|/* (MCI) data CRC Error flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_DTOE
value|(0x1u<< 22)
end_define

begin_comment
comment|/* (MCI) Data timeout Error flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_OVRE
value|(0x1u<< 30)
end_define

begin_comment
comment|/* (MCI) Overrun flag */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_UNRE
value|(0x1u<< 31)
end_define

begin_comment
comment|/* (MCI) Underrun flag */
end_comment

begin_comment
comment|/*	TXRDY,DTIP,ENDTX,TXBUFE,RTOE */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_BITSTRING
define|\
value|"\020" \ 	"\001CMDRDY" \ 	"\002RXRDY" \ 	"\003TXRDY" \ 	"\004BLKE" \ 	"\005DTIP" \ 	"\006NOTBUSY" \ 	"\007ENDRX" \ 	"\010ENDTX" \ 	"\017RXBUFF" \ 	"\020TXBUFE" \ 	"\021RINDE" \ 	"\022RDIRE" \ 	"\023RCRCE" \ 	"\024RENDE" \ 	"\025RTOE" \ 	"\026DCRCE" \ 	"\027DTOE" \ 	"\037OVRE" \ 	"\040UNRE"
end_define

begin_comment
comment|/* -------- MCI_IER : (MCI Offset: 0x44) MCI Interrupt Enable Register --------  */
end_comment

begin_comment
comment|/* -------- MCI_IDR : (MCI Offset: 0x48) MCI Interrupt Disable Register --------  */
end_comment

begin_comment
comment|/* -------- MCI_IMR : (MCI Offset: 0x4c) MCI Interrupt Mask Register --------  */
end_comment

begin_define
define|#
directive|define
name|MCI_SR_ERROR
value|(MCI_SR_UNRE | MCI_SR_OVRE | MCI_SR_DTOE | \ 			MCI_SR_DCRCE | MCI_SR_RTOE | MCI_SR_RENDE | \ 			MCI_SR_RCRCE | MCI_SR_RDIRE | MCI_SR_RINDE)
end_define

begin_define
define|#
directive|define
name|AT91C_BUS_WIDTH_1BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|AT91C_BUS_WIDTH_4BITS
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_MCIREG_H */
end_comment

end_unit


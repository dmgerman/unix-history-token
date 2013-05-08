begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Oleksandr Rybalko under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Registers definition for Freescale i.MX515 Synchronous Serial Interface */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_STX0_REG
value|0x0000
end_define

begin_comment
comment|/* SSI TX Data Register 0 */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_STX1_REG
value|0x0004
end_define

begin_comment
comment|/* SSI TX Data Register 1 */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SRX0_REG
value|0x0008
end_define

begin_comment
comment|/* SSI RX Data Register 0 */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SRX1_REG
value|0x000C
end_define

begin_comment
comment|/* SSI RX Data Register 1 */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SCR_REG
value|0x0010
end_define

begin_comment
comment|/* SSI Control Register */
end_comment

begin_define
define|#
directive|define
name|SSI_SCR_RFR_CLK_DIS
value|(1<< 11)
end_define

begin_comment
comment|/* RX FC Disable */
end_comment

begin_define
define|#
directive|define
name|SSI_SCR_TFR_CLK_DIS
value|(1<< 10)
end_define

begin_comment
comment|/* TX FC Disable */
end_comment

begin_define
define|#
directive|define
name|SSI_SCR_CLK_IST
value|(1<< 9)
end_define

begin_comment
comment|/* Clock Idle */
end_comment

begin_define
define|#
directive|define
name|SSI_SCR_TCH_EN
value|(1<< 8)
end_define

begin_comment
comment|/* 2Chan Enable */
end_comment

begin_define
define|#
directive|define
name|SSI_SCR_SYS_CLK_EN
value|(1<< 7)
end_define

begin_comment
comment|/* System Clock En */
end_comment

begin_define
define|#
directive|define
name|SSI_SCR_MODE_NORMAL
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|SSI_SCR_MODE_I2S_MASTER
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SSI_SCR_MODE_I2S_SLAVE
value|(2<< 5)
end_define

begin_define
define|#
directive|define
name|SSI_SCR_MODE_MASK
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|SSI_SCR_SYN
value|(1<< 4)
end_define

begin_comment
comment|/* Sync Mode */
end_comment

begin_define
define|#
directive|define
name|SSI_SCR_NET
value|(1<< 3)
end_define

begin_comment
comment|/* Network Mode */
end_comment

begin_define
define|#
directive|define
name|SSI_SCR_RE
value|(1<< 2)
end_define

begin_comment
comment|/* RX Enable */
end_comment

begin_define
define|#
directive|define
name|SSI_SCR_TE
value|(1<< 1)
end_define

begin_comment
comment|/* TX Enable */
end_comment

begin_define
define|#
directive|define
name|SSI_SCR_SSIEN
value|(1<< 0)
end_define

begin_comment
comment|/* SSI Enable */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SISR_REG
value|0x0014
end_define

begin_comment
comment|/* SSI Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|SSI_SISR_RFRC
value|(1<< 24)
end_define

begin_comment
comment|/* RX Frame Complete */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_TFRC
value|(1<< 23)
end_define

begin_comment
comment|/* TX Frame Complete */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_CMDAU
value|(1<< 18)
end_define

begin_comment
comment|/* Command Address Updated */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_CMDDU
value|(1<< 17)
end_define

begin_comment
comment|/* Command Data Updated */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_RXT
value|(1<< 16)
end_define

begin_comment
comment|/* RX Tag Updated */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_RDR1
value|(1<< 15)
end_define

begin_comment
comment|/* RX Data Ready 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_RDR0
value|(1<< 14)
end_define

begin_comment
comment|/* RX Data Ready 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_TDE1
value|(1<< 13)
end_define

begin_comment
comment|/* TX Data Reg Empty 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_TDE0
value|(1<< 12)
end_define

begin_comment
comment|/* TX Data Reg Empty 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_ROE1
value|(1<< 11)
end_define

begin_comment
comment|/* RXer Overrun Error 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_ROE0
value|(1<< 10)
end_define

begin_comment
comment|/* RXer Overrun Error 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_TUE1
value|(1<< 9)
end_define

begin_comment
comment|/* TXer Underrun Error 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_TUE0
value|(1<< 8)
end_define

begin_comment
comment|/* TXer Underrun Error 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_TFS
value|(1<< 7)
end_define

begin_comment
comment|/* TX Frame Sync */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_RFS
value|(1<< 6)
end_define

begin_comment
comment|/* RX Frame Sync */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_TLS
value|(1<< 5)
end_define

begin_comment
comment|/* TX Last Time Slot */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_RLS
value|(1<< 4)
end_define

begin_comment
comment|/* RX Last Time Slot */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_RFF1
value|(1<< 3)
end_define

begin_comment
comment|/* RX FIFO Full 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_RFF0
value|(1<< 2)
end_define

begin_comment
comment|/* RX FIFO Full 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_TFE1
value|(1<< 1)
end_define

begin_comment
comment|/* TX FIFO Empty 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SIR_TFE0
value|(1<< 0)
end_define

begin_comment
comment|/* TX FIFO Empty 0 */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SIER_REG
value|0x0018
end_define

begin_comment
comment|/* SSI Interrupt Enable Register */
end_comment

begin_comment
comment|/* 24-23 Enable Bit	(See SISR) */
end_comment

begin_define
define|#
directive|define
name|SSI_SIER_RDMAE
value|(1<< 22)
end_define

begin_comment
comment|/* RX DMA Enable */
end_comment

begin_define
define|#
directive|define
name|SSI_SIER_RIE
value|(1<< 21)
end_define

begin_comment
comment|/* RX Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|SSI_SIER_TDMAE
value|(1<< 20)
end_define

begin_comment
comment|/* TX DMA Enable */
end_comment

begin_define
define|#
directive|define
name|SSI_SIER_TIE
value|(1<< 19)
end_define

begin_comment
comment|/* TX Interrupt Enable */
end_comment

begin_comment
comment|/* 18-0 Enable Bits	(See SISR) */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_STCR_REG
value|0x001C
end_define

begin_comment
comment|/* SSI TX Configuration Register */
end_comment

begin_define
define|#
directive|define
name|SSI_STCR_TXBIT0
value|(1<< 9)
end_define

begin_comment
comment|/* TX Bit 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_STCR_TFEN1
value|(1<< 8)
end_define

begin_comment
comment|/* TX FIFO Enable 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_STCR_TFEN0
value|(1<< 7)
end_define

begin_comment
comment|/* TX FIFO Enable 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_STCR_TFDIR
value|(1<< 6)
end_define

begin_comment
comment|/* TX Frame Direction */
end_comment

begin_define
define|#
directive|define
name|SSI_STCR_TXDIR
value|(1<< 5)
end_define

begin_comment
comment|/* TX Clock Direction */
end_comment

begin_define
define|#
directive|define
name|SSI_STCR_TSHFD
value|(1<< 4)
end_define

begin_comment
comment|/* TX Shift Direction */
end_comment

begin_define
define|#
directive|define
name|SSI_STCR_TSCKP
value|(1<< 3)
end_define

begin_comment
comment|/* TX Clock Polarity */
end_comment

begin_define
define|#
directive|define
name|SSI_STCR_TFSI
value|(1<< 2)
end_define

begin_comment
comment|/* TX Frame Sync Invert */
end_comment

begin_define
define|#
directive|define
name|SSI_STCR_TFSL
value|(1<< 1)
end_define

begin_comment
comment|/* TX Frame Sync Length */
end_comment

begin_define
define|#
directive|define
name|SSI_STCR_TEFS
value|(1<< 0)
end_define

begin_comment
comment|/* TX Early Frame Sync */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SRCR_REG
value|0x0020
end_define

begin_comment
comment|/* SSI RX Configuration Register */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_RXEXT
value|(1<< 10)
end_define

begin_comment
comment|/* RX Data Extension */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_RXBIT0
value|(1<< 9)
end_define

begin_comment
comment|/* RX Bit 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_RFEN1
value|(1<< 8)
end_define

begin_comment
comment|/* RX FIFO Enable 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_RFEN0
value|(1<< 7)
end_define

begin_comment
comment|/* RX FIFO Enable 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_RFDIR
value|(1<< 6)
end_define

begin_comment
comment|/* RX Frame Direction */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_RXDIR
value|(1<< 5)
end_define

begin_comment
comment|/* RX Clock Direction */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_RSHFD
value|(1<< 4)
end_define

begin_comment
comment|/* RX Shift Direction */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_RSCKP
value|(1<< 3)
end_define

begin_comment
comment|/* RX Clock Polarity */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_RFSI
value|(1<< 2)
end_define

begin_comment
comment|/* RX Frame Sync Invert */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_RFSL
value|(1<< 1)
end_define

begin_comment
comment|/* RX Frame Sync Length */
end_comment

begin_define
define|#
directive|define
name|SSI_SRCR_REFS
value|(1<< 0)
end_define

begin_comment
comment|/* RX Early Frame Sync */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_STCCR_REG
value|0x0024
end_define

begin_comment
comment|/* TX Clock Control */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SRCCR_REG
value|0x0028
end_define

begin_comment
comment|/* RX Clock Control */
end_comment

begin_define
define|#
directive|define
name|SSI_SXCCR_DIV2
value|(1<< 18)
end_define

begin_comment
comment|/* Divide By 2 */
end_comment

begin_define
define|#
directive|define
name|SSI_SXCCR_PSR
value|(1<< 17)
end_define

begin_comment
comment|/* Prescaler Range */
end_comment

begin_define
define|#
directive|define
name|SSI_SXCCR_WL_MASK
value|0x0001e000
end_define

begin_define
define|#
directive|define
name|SSI_SXCCR_WL_SHIFT
value|13
end_define

begin_comment
comment|/* Word Length Control */
end_comment

begin_define
define|#
directive|define
name|SSI_SXCCR_DC_MASK
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|SSI_SXCCR_DC_SHIFT
value|8
end_define

begin_comment
comment|/* Frame Rate Divider */
end_comment

begin_define
define|#
directive|define
name|SSI_SXCCR_PM_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|SSI_SXCCR_PM_SHIFT
value|0
end_define

begin_comment
comment|/* Prescaler Modulus */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SFCSR_REG
value|0x002C
end_define

begin_comment
comment|/* SSI FIFO Control/Status Register */
end_comment

begin_define
define|#
directive|define
name|SSI_SFCSR_RFCNT1_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|SSI_SFCSR_RFCNT1_SHIFT
value|28
end_define

begin_comment
comment|/* RX FIFO Counter 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SFCSR_TFCNT1_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|SSI_SFCSR_TFCNT1_SHIFT
value|24
end_define

begin_comment
comment|/* TX FIFO Counter 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SFCSR_RFWM1_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|SSI_SFCSR_RFWM1_SHIFT
value|20
end_define

begin_comment
comment|/* RX FIFO Full WaterMark 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SFCSR_TFWM1_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|SSI_SFCSR_TFWM1_SHIFT
value|16
end_define

begin_comment
comment|/* TX FIFO Empty WaterMark 1 */
end_comment

begin_define
define|#
directive|define
name|SSI_SFCSR_RFCNT0_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|SSI_SFCSR_RFCNT0_SHIFT
value|12
end_define

begin_comment
comment|/* RX FIFO Counter 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_SFCSR_TFCNT0_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|SSI_SFCSR_TFCNT0_SHIFT
value|8
end_define

begin_comment
comment|/* TX FIFO Counter 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_SFCSR_RFWM0_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|SSI_SFCSR_RFWM0_SHIFT
value|4
end_define

begin_comment
comment|/* RX FIFO Full WaterMark 0 */
end_comment

begin_define
define|#
directive|define
name|SSI_SFCSR_TFWM0_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|SSI_SFCSR_TFWM0_SHIFT
value|0
end_define

begin_comment
comment|/* TX FIFO Empty WaterMark 0 */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_STR_REG
value|0x0030
end_define

begin_comment
comment|/* SSI Test Register1 */
end_comment

begin_define
define|#
directive|define
name|SSI_STR_TEST
value|(1<< 15)
end_define

begin_comment
comment|/* Test Mode */
end_comment

begin_define
define|#
directive|define
name|SSI_STR_RCK2TCK
value|(1<< 14)
end_define

begin_comment
comment|/* RX<->TX Clock Loop Back */
end_comment

begin_define
define|#
directive|define
name|SSI_STR_RFS2TFS
value|(1<< 13)
end_define

begin_comment
comment|/* RX<->TX Frame Loop Back */
end_comment

begin_define
define|#
directive|define
name|SSI_STR_RXSTATE_MASK
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|SSI_STR_RXSTATE_SHIFT
value|8
end_define

begin_comment
comment|/* RXer State Machine Status */
end_comment

begin_define
define|#
directive|define
name|SSI_STR_TXD2RXD
value|(1<< 7)
end_define

begin_comment
comment|/* TX<->RX Data Loop Back */
end_comment

begin_define
define|#
directive|define
name|SSI_STR_TCK2RCK
value|(1<< 6)
end_define

begin_comment
comment|/* TX<->RX Clock Loop Back */
end_comment

begin_define
define|#
directive|define
name|SSI_STR_TFS2RFS
value|(1<< 5)
end_define

begin_comment
comment|/* TX<->RX Frame Loop Back */
end_comment

begin_define
define|#
directive|define
name|SSI_STR_TXSTATE_MASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|SSI_STR_TXSTATE_SHIFT
value|0
end_define

begin_comment
comment|/* TXer State Machine Status */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SOR_REG
value|0x0034
end_define

begin_comment
comment|/* SSI Option Register2 */
end_comment

begin_define
define|#
directive|define
name|SSI_SOR_CLKOFF
value|(1<< 6)
end_define

begin_comment
comment|/* Clock Off */
end_comment

begin_define
define|#
directive|define
name|SSI_SOR_RX_CLR
value|(1<< 5)
end_define

begin_comment
comment|/* RXer Clear */
end_comment

begin_define
define|#
directive|define
name|SSI_SOR_TX_CLR
value|(1<< 4)
end_define

begin_comment
comment|/* TXer Clear */
end_comment

begin_define
define|#
directive|define
name|SSI_SOR_INIT
value|(1<< 3)
end_define

begin_comment
comment|/* Initialize */
end_comment

begin_define
define|#
directive|define
name|SSI_SOR_WAIT_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|SSI_SOR_INIT_SHIFT
value|1
end_define

begin_comment
comment|/* Wait */
end_comment

begin_define
define|#
directive|define
name|SSI_SOR_SYNRST
value|(1<< 0)
end_define

begin_comment
comment|/* Frame Sync Reset */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SACNT_REG
value|0x0038
end_define

begin_comment
comment|/* SSI AC97 Control Register */
end_comment

begin_define
define|#
directive|define
name|SSI_SACNT_FRDIV_MASK
value|0x000007e0
end_define

begin_define
define|#
directive|define
name|SSI_SACNT_FRDIV_SHIFT
value|5
end_define

begin_comment
comment|/* Frame Rate Divider */
end_comment

begin_define
define|#
directive|define
name|SSI_SACNT_WR
value|(1<< 4)
end_define

begin_comment
comment|/* Write Command */
end_comment

begin_define
define|#
directive|define
name|SSI_SACNT_RD
value|(1<< 3)
end_define

begin_comment
comment|/* Read Command */
end_comment

begin_define
define|#
directive|define
name|SSI_SACNT_TIF
value|(1<< 2)
end_define

begin_comment
comment|/* Tag in FIFO */
end_comment

begin_define
define|#
directive|define
name|SSI_SACNT_FV
value|(1<< 1)
end_define

begin_comment
comment|/* Fixed/Variable Operation */
end_comment

begin_define
define|#
directive|define
name|SSI_SACNT_AC97EN
value|(1<< 0)
end_define

begin_comment
comment|/* AC97 Mode Enable */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SACADD_REG
value|0x003C
end_define

begin_comment
comment|/* SSI AC97 Command Address Register */
end_comment

begin_define
define|#
directive|define
name|SSI_SACADD_MASK
value|0x0007ffff
end_define

begin_define
define|#
directive|define
name|IMX51_SSI_SACDAT_REG
value|0x0040
end_define

begin_comment
comment|/* SSI AC97 Command Data Register */
end_comment

begin_define
define|#
directive|define
name|SSI_SACDAT_MASK
value|0x000fffff
end_define

begin_define
define|#
directive|define
name|IMX51_SSI_SATAG_REG
value|0x0044
end_define

begin_comment
comment|/* SSI AC97 Tag Register */
end_comment

begin_define
define|#
directive|define
name|SSI_SATAG_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|IMX51_SSI_STMSK_REG
value|0x0048
end_define

begin_comment
comment|/* SSI TX Time Slot Mask Register */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SRMSK_REG
value|0x004C
end_define

begin_comment
comment|/* SSI RX Time Slot Mask Register */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SACCST_REG
value|0x0050
end_define

begin_comment
comment|/* SSI AC97 Channel Status Register */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SACCEN_REG
value|0x0054
end_define

begin_comment
comment|/* SSI AC97 Channel Enable Register */
end_comment

begin_define
define|#
directive|define
name|IMX51_SSI_SACCDIS_REG
value|0x0058
end_define

begin_comment
comment|/* SSI AC97 Channel Disable Register */
end_comment

begin_define
define|#
directive|define
name|SSI_SAC_MASK
value|0x000003ff
end_define

begin_comment
comment|/* SACCST,SACCEN,SACCDIS */
end_comment

end_unit


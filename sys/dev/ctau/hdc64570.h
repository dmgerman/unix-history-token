begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Hitachi HD64570 serial communications adaptor registers.  *  * Copyright (C) 1996 Cronyx Engineering.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Cronyx Id: hdc64570.h,v 1.1.2.2 2003/11/12 17:31:21 rik Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Low power mode control register.  */
end_comment

begin_define
define|#
directive|define
name|HD_LPR
value|0x00
end_define

begin_comment
comment|/* low power register */
end_comment

begin_comment
comment|/*  * Interrupt control registers.  */
end_comment

begin_define
define|#
directive|define
name|HD_IVR
value|0x1a
end_define

begin_comment
comment|/* interrupt vector register */
end_comment

begin_define
define|#
directive|define
name|HD_IMVR
value|0x1c
end_define

begin_comment
comment|/* interrupt modified vector register */
end_comment

begin_define
define|#
directive|define
name|HD_ITCR
value|0x18
end_define

begin_comment
comment|/* interrupt control register */
end_comment

begin_define
define|#
directive|define
name|HD_ISR0
value|0x10
end_define

begin_comment
comment|/* interrupt status register 0, ro */
end_comment

begin_define
define|#
directive|define
name|HD_ISR1
value|0x11
end_define

begin_comment
comment|/* interrupt status register 1, ro */
end_comment

begin_define
define|#
directive|define
name|HD_ISR2
value|0x12
end_define

begin_comment
comment|/* interrupt status register 2, ro */
end_comment

begin_define
define|#
directive|define
name|HD_IER0
value|0x14
end_define

begin_comment
comment|/* interrupt enable register 0 */
end_comment

begin_define
define|#
directive|define
name|HD_IER1
value|0x15
end_define

begin_comment
comment|/* interrupt enable register 1 */
end_comment

begin_define
define|#
directive|define
name|HD_IER2
value|0x16
end_define

begin_comment
comment|/* interrupt enable register 2 */
end_comment

begin_comment
comment|/*  * Multiprotocol serial communication interface registers.  */
end_comment

begin_define
define|#
directive|define
name|HD_MD0_0
value|0x2e
end_define

begin_comment
comment|/* mode register 0 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_MD0_1
value|0x4e
end_define

begin_comment
comment|/* mode register 0 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_MD1_0
value|0x2f
end_define

begin_comment
comment|/* mode register 1 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_MD1_1
value|0x4f
end_define

begin_comment
comment|/* mode register 1 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_MD2_0
value|0x30
end_define

begin_comment
comment|/* mode register 2 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_MD2_1
value|0x50
end_define

begin_comment
comment|/* mode register 2 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_CTL_0
value|0x31
end_define

begin_comment
comment|/* control register chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_CTL_1
value|0x51
end_define

begin_comment
comment|/* control register chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_RXS_0
value|0x36
end_define

begin_comment
comment|/* RX clock source register chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_RXS_1
value|0x56
end_define

begin_comment
comment|/* RX clock source register chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_TXS_0
value|0x37
end_define

begin_comment
comment|/* TX clock source register chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_TXS_1
value|0x57
end_define

begin_comment
comment|/* TX clock source register chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_TMC_0
value|0x35
end_define

begin_comment
comment|/* time constant register chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_TMC_1
value|0x55
end_define

begin_comment
comment|/* time constant register chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_CMD_0
value|0x2c
end_define

begin_comment
comment|/* command register chan 0, wo */
end_comment

begin_define
define|#
directive|define
name|HD_CMD_1
value|0x4c
end_define

begin_comment
comment|/* command register chan 1, wo */
end_comment

begin_define
define|#
directive|define
name|HD_ST0_0
value|0x22
end_define

begin_comment
comment|/* status register 0 chan 0, ro */
end_comment

begin_define
define|#
directive|define
name|HD_ST0_1
value|0x42
end_define

begin_comment
comment|/* status register 0 chan 1, ro */
end_comment

begin_define
define|#
directive|define
name|HD_ST1_0
value|0x23
end_define

begin_comment
comment|/* status register 1 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_ST1_1
value|0x43
end_define

begin_comment
comment|/* status register 1 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_ST2_0
value|0x24
end_define

begin_comment
comment|/* status register 2 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_ST2_1
value|0x44
end_define

begin_comment
comment|/* status register 2 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_ST3_0
value|0x25
end_define

begin_comment
comment|/* status register 3 chan 0, ro */
end_comment

begin_define
define|#
directive|define
name|HD_ST3_1
value|0x45
end_define

begin_comment
comment|/* status register 3 chan 1, ro */
end_comment

begin_define
define|#
directive|define
name|HD_FST_0
value|0x26
end_define

begin_comment
comment|/* frame status register chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_FST_1
value|0x46
end_define

begin_comment
comment|/* frame status register chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_IE0_0
value|0x28
end_define

begin_comment
comment|/* interrupt enable register 0 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_IE0_1
value|0x48
end_define

begin_comment
comment|/* interrupt enable register 0 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_IE1_0
value|0x29
end_define

begin_comment
comment|/* interrupt enable register 1 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_IE1_1
value|0x49
end_define

begin_comment
comment|/* interrupt enable register 1 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_IE2_0
value|0x2a
end_define

begin_comment
comment|/* interrupt enable register 2 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_IE2_1
value|0x4a
end_define

begin_comment
comment|/* interrupt enable register 2 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_FIE_0
value|0x2b
end_define

begin_comment
comment|/* frame interrupt enable register chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_FIE_1
value|0x4b
end_define

begin_comment
comment|/* frame interrupt enable register chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_SA0_0
value|0x32
end_define

begin_comment
comment|/* sync/address register 0 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_SA0_1
value|0x52
end_define

begin_comment
comment|/* sync/address register 0 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_SA1_0
value|0x33
end_define

begin_comment
comment|/* sync/address register 1 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_SA1_1
value|0x53
end_define

begin_comment
comment|/* sync/address register 1 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_IDL_0
value|0x34
end_define

begin_comment
comment|/* idle pattern register chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_IDL_1
value|0x54
end_define

begin_comment
comment|/* idle pattern register chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_TRB_0
value|0x20
end_define

begin_comment
comment|/* TX/RX buffer register chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_TRB_1
value|0x40
end_define

begin_comment
comment|/* TX/RX buffer register chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_RRC_0
value|0x3a
end_define

begin_comment
comment|/* RX ready control register chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_RRC_1
value|0x5a
end_define

begin_comment
comment|/* RX ready control register chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_TRC0_0
value|0x38
end_define

begin_comment
comment|/* TX ready control register 0 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_TRC0_1
value|0x58
end_define

begin_comment
comment|/* TX ready control register 0 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_TRC1_0
value|0x39
end_define

begin_comment
comment|/* TX ready control register 1 chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_TRC1_1
value|0x59
end_define

begin_comment
comment|/* TX ready control register 1 chan 1 */
end_comment

begin_define
define|#
directive|define
name|HD_CST_0
value|0x3c
end_define

begin_comment
comment|/* current status register chan 0 */
end_comment

begin_define
define|#
directive|define
name|HD_CST_1
value|0x5c
end_define

begin_comment
comment|/* current status register chan 1 */
end_comment

begin_comment
comment|/*  * DMA controller registers.  */
end_comment

begin_define
define|#
directive|define
name|HD_PCR
value|0x08
end_define

begin_comment
comment|/* DMA priority control register */
end_comment

begin_define
define|#
directive|define
name|HD_DMER
value|0x09
end_define

begin_comment
comment|/* DMA master enable register */
end_comment

begin_define
define|#
directive|define
name|HD_DAR_0R
value|0x80
end_define

begin_comment
comment|/* destination address chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_DAR_0T
value|0xa0
end_define

begin_comment
comment|/* destination address chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_DAR_1R
value|0xc0
end_define

begin_comment
comment|/* destination address chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_DAR_1T
value|0xe0
end_define

begin_comment
comment|/* destination address chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_DARB_0R
value|0x82
end_define

begin_comment
comment|/* destination address B chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_DARB_0T
value|0xa2
end_define

begin_comment
comment|/* destination address B chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_DARB_1R
value|0xc2
end_define

begin_comment
comment|/* destination address B chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_DARB_1T
value|0xe2
end_define

begin_comment
comment|/* destination address B chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_SAR_0R
value|0x84
end_define

begin_comment
comment|/* source address chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_SAR_0T
value|0xa4
end_define

begin_comment
comment|/* source address chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_SAR_1R
value|0xc4
end_define

begin_comment
comment|/* source address chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_SAR_1T
value|0xe4
end_define

begin_comment
comment|/* source address chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_SARB_0R
value|0x86
end_define

begin_comment
comment|/* source address B chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_SARB_0T
value|0xa6
end_define

begin_comment
comment|/* source address B chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_SARB_1R
value|0xc6
end_define

begin_comment
comment|/* source address B chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_SARB_1T
value|0xe6
end_define

begin_comment
comment|/* source address B chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_CDA_0R
value|0x88
end_define

begin_comment
comment|/* current descriptor address chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_CDA_0T
value|0xa8
end_define

begin_comment
comment|/* current descriptor address chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_CDA_1R
value|0xc8
end_define

begin_comment
comment|/* current descriptor address chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_CDA_1T
value|0xe8
end_define

begin_comment
comment|/* current descriptor address chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_EDA_0R
value|0x8a
end_define

begin_comment
comment|/* error descriptor address chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_EDA_0T
value|0xaa
end_define

begin_comment
comment|/* error descriptor address chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_EDA_1R
value|0xca
end_define

begin_comment
comment|/* error descriptor address chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_EDA_1T
value|0xea
end_define

begin_comment
comment|/* error descriptor address chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_BFL_0R
value|0x8c
end_define

begin_comment
comment|/* receive buffer length chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_BFL_1R
value|0xcc
end_define

begin_comment
comment|/* receive buffer length chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_BCR_0R
value|0x8e
end_define

begin_comment
comment|/* byte count register chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_BCR_0T
value|0xae
end_define

begin_comment
comment|/* byte count register chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_BCR_1R
value|0xce
end_define

begin_comment
comment|/* byte count register chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_BCR_1T
value|0xee
end_define

begin_comment
comment|/* byte count register chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_DSR_0R
value|0x90
end_define

begin_comment
comment|/* DMA status register chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_DSR_0T
value|0xb0
end_define

begin_comment
comment|/* DMA status register chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_DSR_1R
value|0xd0
end_define

begin_comment
comment|/* DMA status register chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_DSR_1T
value|0xf0
end_define

begin_comment
comment|/* DMA status register chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_DMR_0R
value|0x91
end_define

begin_comment
comment|/* DMA mode register chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_DMR_0T
value|0xb1
end_define

begin_comment
comment|/* DMA mode register chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_DMR_1R
value|0xd1
end_define

begin_comment
comment|/* DMA mode register chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_DMR_1T
value|0xf1
end_define

begin_comment
comment|/* DMA mode register chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_FCT_0R
value|0x93
end_define

begin_comment
comment|/* end-of-frame intr counter chan 0rx, ro */
end_comment

begin_define
define|#
directive|define
name|HD_FCT_0T
value|0xb3
end_define

begin_comment
comment|/* end-of-frame intr counter chan 0tx, ro */
end_comment

begin_define
define|#
directive|define
name|HD_FCT_1R
value|0xd3
end_define

begin_comment
comment|/* end-of-frame intr counter chan 1rx, ro */
end_comment

begin_define
define|#
directive|define
name|HD_FCT_1T
value|0xf3
end_define

begin_comment
comment|/* end-of-frame intr counter chan 1tx, ro */
end_comment

begin_define
define|#
directive|define
name|HD_DIR_0R
value|0x94
end_define

begin_comment
comment|/* DMA interrupt enable register chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_DIR_0T
value|0xb4
end_define

begin_comment
comment|/* DMA interrupt enable register chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_DIR_1R
value|0xd4
end_define

begin_comment
comment|/* DMA interrupt enable register chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_DIR_1T
value|0xf4
end_define

begin_comment
comment|/* DMA interrupt enable register chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_DCR_0R
value|0x95
end_define

begin_comment
comment|/* DMA command register chan 0rx, wo */
end_comment

begin_define
define|#
directive|define
name|HD_DCR_0T
value|0xb5
end_define

begin_comment
comment|/* DMA command register chan 0tx, wo */
end_comment

begin_define
define|#
directive|define
name|HD_DCR_1R
value|0xd5
end_define

begin_comment
comment|/* DMA command register chan 1rx, wo */
end_comment

begin_define
define|#
directive|define
name|HD_DCR_1T
value|0xf5
end_define

begin_comment
comment|/* DMA command register chan 1tx, wo */
end_comment

begin_comment
comment|/*  * Timer registers.  */
end_comment

begin_define
define|#
directive|define
name|HD_TCNT_0R
value|0x60
end_define

begin_comment
comment|/* timer up counter chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_TCNT_0T
value|0x68
end_define

begin_comment
comment|/* timer up counter chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_TCNT_1R
value|0x70
end_define

begin_comment
comment|/* timer up counter chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_TCNT_1T
value|0x78
end_define

begin_comment
comment|/* timer up counter chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_TCONR_0R
value|0x62
end_define

begin_comment
comment|/* timer constant register chan 0rx, wo */
end_comment

begin_define
define|#
directive|define
name|HD_TCONR_0T
value|0x6a
end_define

begin_comment
comment|/* timer constant register chan 0tx, wo */
end_comment

begin_define
define|#
directive|define
name|HD_TCONR_1R
value|0x72
end_define

begin_comment
comment|/* timer constant register chan 1rx, wo */
end_comment

begin_define
define|#
directive|define
name|HD_TCONR_1T
value|0x7a
end_define

begin_comment
comment|/* timer constant register chan 1tx, wo */
end_comment

begin_define
define|#
directive|define
name|HD_TCSR_0R
value|0x64
end_define

begin_comment
comment|/* timer control/status register chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_TCSR_0T
value|0x6c
end_define

begin_comment
comment|/* timer control/status register chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_TCSR_1R
value|0x74
end_define

begin_comment
comment|/* timer control/status register chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_TCSR_1T
value|0x7c
end_define

begin_comment
comment|/* timer control/status register chan 1tx */
end_comment

begin_define
define|#
directive|define
name|HD_TEPR_0R
value|0x65
end_define

begin_comment
comment|/* timer expand prescale register chan 0rx */
end_comment

begin_define
define|#
directive|define
name|HD_TEPR_0T
value|0x6d
end_define

begin_comment
comment|/* timer expand prescale register chan 0tx */
end_comment

begin_define
define|#
directive|define
name|HD_TEPR_1R
value|0x75
end_define

begin_comment
comment|/* timer expand prescale register chan 1rx */
end_comment

begin_define
define|#
directive|define
name|HD_TEPR_1T
value|0x7d
end_define

begin_comment
comment|/* timer expand prescale register chan 1tx */
end_comment

begin_comment
comment|/*  * Wait controller registers.  */
end_comment

begin_define
define|#
directive|define
name|HD_PABR0
value|0x02
end_define

begin_comment
comment|/* physical address boundary register 0 */
end_comment

begin_define
define|#
directive|define
name|HD_PABR1
value|0x03
end_define

begin_comment
comment|/* physical address boundary register 1 */
end_comment

begin_define
define|#
directive|define
name|HD_WCRL
value|0x04
end_define

begin_comment
comment|/* wait control register L */
end_comment

begin_define
define|#
directive|define
name|HD_WCRM
value|0x05
end_define

begin_comment
comment|/* wait control register M */
end_comment

begin_define
define|#
directive|define
name|HD_WCRH
value|0x06
end_define

begin_comment
comment|/* wait control register H */
end_comment

begin_comment
comment|/*  * Interrupt modified vector register (IMVR) bits.  */
end_comment

begin_define
define|#
directive|define
name|IMVR_CHAN1
value|040
end_define

begin_comment
comment|/* channel 1 vector bit */
end_comment

begin_define
define|#
directive|define
name|IMVR_VECT_MASK
value|037
end_define

begin_comment
comment|/* interrupt reason mask */
end_comment

begin_define
define|#
directive|define
name|IMVR_RX_RDY
value|004
end_define

begin_comment
comment|/* receive buffer ready */
end_comment

begin_define
define|#
directive|define
name|IMVR_RX_INT
value|010
end_define

begin_comment
comment|/* receive status */
end_comment

begin_define
define|#
directive|define
name|IMVR_RX_DMERR
value|024
end_define

begin_comment
comment|/* receive DMA error */
end_comment

begin_define
define|#
directive|define
name|IMVR_RX_DMOK
value|026
end_define

begin_comment
comment|/* receive DMA normal end */
end_comment

begin_define
define|#
directive|define
name|IMVR_RX_TIMER
value|034
end_define

begin_comment
comment|/* timer 0/2 count match */
end_comment

begin_define
define|#
directive|define
name|IMVR_TX_RDY
value|006
end_define

begin_comment
comment|/* transmit buffer ready */
end_comment

begin_define
define|#
directive|define
name|IMVR_TX_INT
value|012
end_define

begin_comment
comment|/* transmit status */
end_comment

begin_define
define|#
directive|define
name|IMVR_TX_DMERR
value|030
end_define

begin_comment
comment|/* transmit DMA error */
end_comment

begin_define
define|#
directive|define
name|IMVR_TX_DMOK
value|032
end_define

begin_comment
comment|/* transmit DMA normal end */
end_comment

begin_define
define|#
directive|define
name|IMVR_TX_TIMER
value|036
end_define

begin_comment
comment|/* timer 1/3 count match */
end_comment

begin_comment
comment|/*  * Interrupt control register (ITCR) bits.  */
end_comment

begin_define
define|#
directive|define
name|ITCR_PRIO_DMAC
value|0x80
end_define

begin_comment
comment|/* DMA priority higher than MSCI */
end_comment

begin_define
define|#
directive|define
name|ITCR_CYCLE_VOID
value|0x00
end_define

begin_comment
comment|/* non-acknowledge cycle */
end_comment

begin_define
define|#
directive|define
name|ITCR_CYCLE_SINGLE
value|0x20
end_define

begin_comment
comment|/* single acknowledge cycle */
end_comment

begin_define
define|#
directive|define
name|ITCR_CYCLE_DOUBLE
value|0x40
end_define

begin_comment
comment|/* double acknowledge cycle */
end_comment

begin_define
define|#
directive|define
name|ITCR_VECT_MOD
value|0x10
end_define

begin_comment
comment|/* interrupt modified vector flag */
end_comment

begin_comment
comment|/*  * Interrupt status register 0 (ISR0) bits.  */
end_comment

begin_define
define|#
directive|define
name|ISR0_RX_RDY_0
value|0x01
end_define

begin_comment
comment|/* channel 0 receiver ready */
end_comment

begin_define
define|#
directive|define
name|ISR0_TX_RDY_0
value|0x02
end_define

begin_comment
comment|/* channel 0 transmitter ready */
end_comment

begin_define
define|#
directive|define
name|ISR0_RX_INT_0
value|0x04
end_define

begin_comment
comment|/* channel 0 receiver status */
end_comment

begin_define
define|#
directive|define
name|ISR0_TX_INT_0
value|0x08
end_define

begin_comment
comment|/* channel 0 transmitter status */
end_comment

begin_define
define|#
directive|define
name|ISR0_RX_RDY_1
value|0x10
end_define

begin_comment
comment|/* channel 1 receiver ready */
end_comment

begin_define
define|#
directive|define
name|ISR0_TX_RDY_1
value|0x20
end_define

begin_comment
comment|/* channel 1 transmitter ready */
end_comment

begin_define
define|#
directive|define
name|ISR0_RX_INT_1
value|0x40
end_define

begin_comment
comment|/* channel 1 receiver status */
end_comment

begin_define
define|#
directive|define
name|ISR0_TX_INT_1
value|0x80
end_define

begin_comment
comment|/* channel 1 transmitter status */
end_comment

begin_comment
comment|/*  * Interrupt status register 1 (ISR1) bits.  */
end_comment

begin_define
define|#
directive|define
name|ISR1_RX_DMERR_0
value|0x01
end_define

begin_comment
comment|/* channel 0 receive DMA error */
end_comment

begin_define
define|#
directive|define
name|ISR1_RX_DMOK_0
value|0x02
end_define

begin_comment
comment|/* channel 0 receive DMA finished */
end_comment

begin_define
define|#
directive|define
name|ISR1_TX_DMERR_0
value|0x04
end_define

begin_comment
comment|/* channel 0 transmit DMA error */
end_comment

begin_define
define|#
directive|define
name|ISR1_TX_DMOK_0
value|0x08
end_define

begin_comment
comment|/* channel 0 transmit DMA finished */
end_comment

begin_define
define|#
directive|define
name|ISR1_RX_DMERR_1
value|0x10
end_define

begin_comment
comment|/* channel 1 receive DMA error */
end_comment

begin_define
define|#
directive|define
name|ISR1_RX_DMOK_1
value|0x20
end_define

begin_comment
comment|/* channel 1 receive DMA finished */
end_comment

begin_define
define|#
directive|define
name|ISR1_TX_DMERR_1
value|0x40
end_define

begin_comment
comment|/* channel 1 transmit DMA error */
end_comment

begin_define
define|#
directive|define
name|ISR1_TX_DMOK_1
value|0x80
end_define

begin_comment
comment|/* channel 1 transmit DMA finished */
end_comment

begin_comment
comment|/*  * Interrupt status register 2 (ISR2) bits.  */
end_comment

begin_define
define|#
directive|define
name|ISR2_RX_TIMER_0
value|0x10
end_define

begin_comment
comment|/* channel 0 receive timer */
end_comment

begin_define
define|#
directive|define
name|ISR2_TX_TIMER_0
value|0x20
end_define

begin_comment
comment|/* channel 0 transmit timer */
end_comment

begin_define
define|#
directive|define
name|ISR2_RX_TIMER_1
value|0x40
end_define

begin_comment
comment|/* channel 1 receive timer */
end_comment

begin_define
define|#
directive|define
name|ISR2_TX_TIMER_1
value|0x80
end_define

begin_comment
comment|/* channel 1 transmit timer */
end_comment

begin_comment
comment|/*  * Interrupt enable register 0 (IER0) bits.  */
end_comment

begin_define
define|#
directive|define
name|IER0_RX_RDYE_0
value|0x01
end_define

begin_comment
comment|/* channel 0 receiver ready enable */
end_comment

begin_define
define|#
directive|define
name|IER0_TX_RDYE_0
value|0x02
end_define

begin_comment
comment|/* channel 0 transmitter ready enable */
end_comment

begin_define
define|#
directive|define
name|IER0_RX_INTE_0
value|0x04
end_define

begin_comment
comment|/* channel 0 receiver status enable */
end_comment

begin_define
define|#
directive|define
name|IER0_TX_INTE_0
value|0x08
end_define

begin_comment
comment|/* channel 0 transmitter status enable */
end_comment

begin_define
define|#
directive|define
name|IER0_RX_RDYE_1
value|0x10
end_define

begin_comment
comment|/* channel 1 receiver ready enable */
end_comment

begin_define
define|#
directive|define
name|IER0_TX_RDYE_1
value|0x20
end_define

begin_comment
comment|/* channel 1 transmitter ready enable */
end_comment

begin_define
define|#
directive|define
name|IER0_RX_INTE_1
value|0x40
end_define

begin_comment
comment|/* channel 1 receiver status enable */
end_comment

begin_define
define|#
directive|define
name|IER0_TX_INTE_1
value|0x80
end_define

begin_comment
comment|/* channel 1 transmitter status enable */
end_comment

begin_define
define|#
directive|define
name|IER0_MASK_0
value|0x0f
end_define

begin_comment
comment|/* channel 0 bits */
end_comment

begin_define
define|#
directive|define
name|IER0_MASK_1
value|0xf0
end_define

begin_comment
comment|/* channel 1 bits */
end_comment

begin_comment
comment|/*  * Interrupt enable register 1 (IER1) bits.  */
end_comment

begin_define
define|#
directive|define
name|IER1_RX_DMERE_0
value|0x01
end_define

begin_comment
comment|/* channel 0 receive DMA error enable */
end_comment

begin_define
define|#
directive|define
name|IER1_RX_DME_0
value|0x02
end_define

begin_comment
comment|/* channel 0 receive DMA finished enable */
end_comment

begin_define
define|#
directive|define
name|IER1_TX_DMERE_0
value|0x04
end_define

begin_comment
comment|/* channel 0 transmit DMA error enable */
end_comment

begin_define
define|#
directive|define
name|IER1_TX_DME_0
value|0x08
end_define

begin_comment
comment|/* channel 0 transmit DMA finished enable */
end_comment

begin_define
define|#
directive|define
name|IER1_RX_DMERE_1
value|0x10
end_define

begin_comment
comment|/* channel 1 receive DMA error enable */
end_comment

begin_define
define|#
directive|define
name|IER1_RX_DME_1
value|0x20
end_define

begin_comment
comment|/* channel 1 receive DMA finished enable */
end_comment

begin_define
define|#
directive|define
name|IER1_TX_DMERE_1
value|0x40
end_define

begin_comment
comment|/* channel 1 transmit DMA error enable */
end_comment

begin_define
define|#
directive|define
name|IER1_TX_DME_1
value|0x80
end_define

begin_comment
comment|/* channel 1 transmit DMA finished enable */
end_comment

begin_define
define|#
directive|define
name|IER1_MASK_0
value|0x0f
end_define

begin_comment
comment|/* channel 0 bits */
end_comment

begin_define
define|#
directive|define
name|IER1_MASK_1
value|0xf0
end_define

begin_comment
comment|/* channel 1 bits */
end_comment

begin_comment
comment|/*  * Interrupt enable register 2 (IER2) bits.  */
end_comment

begin_define
define|#
directive|define
name|IER2_RX_TME_0
value|0x10
end_define

begin_comment
comment|/* channel 0 receive timer enable */
end_comment

begin_define
define|#
directive|define
name|IER2_TX_TME_0
value|0x20
end_define

begin_comment
comment|/* channel 0 transmit timer enable */
end_comment

begin_define
define|#
directive|define
name|IER2_RX_TME_1
value|0x40
end_define

begin_comment
comment|/* channel 1 receive timer enable */
end_comment

begin_define
define|#
directive|define
name|IER2_TX_TME_1
value|0x80
end_define

begin_comment
comment|/* channel 1 transmit timer enable */
end_comment

begin_define
define|#
directive|define
name|IER2_MASK_0
value|0x30
end_define

begin_comment
comment|/* channel 0 bits */
end_comment

begin_define
define|#
directive|define
name|IER2_MASK_1
value|0xc0
end_define

begin_comment
comment|/* channel 1 bits */
end_comment

begin_comment
comment|/*  * Control register (CTL) bits.  */
end_comment

begin_define
define|#
directive|define
name|CTL_RTS_INV
value|0x01
end_define

begin_comment
comment|/* RTS control bit (inverted) */
end_comment

begin_define
define|#
directive|define
name|CTL_SYNCLD
value|0x04
end_define

begin_comment
comment|/* load SYN characters */
end_comment

begin_define
define|#
directive|define
name|CTL_BRK
value|0x08
end_define

begin_comment
comment|/* async: send break */
end_comment

begin_define
define|#
directive|define
name|CTL_IDLE_MARK
value|0
end_define

begin_comment
comment|/* HDLC: when idle, transmit mark */
end_comment

begin_define
define|#
directive|define
name|CTL_IDLE_PTRN
value|0x10
end_define

begin_comment
comment|/* HDLC: when idle, transmit an idle pattern */
end_comment

begin_define
define|#
directive|define
name|CTL_UDRN_ABORT
value|0
end_define

begin_comment
comment|/* HDLC: on underrun - abort */
end_comment

begin_define
define|#
directive|define
name|CTL_UDRN_FCS
value|0x20
end_define

begin_comment
comment|/* HDLC: on underrun - send FCS/flag */
end_comment

begin_comment
comment|/*  * Command register (CMD) values.  */
end_comment

begin_define
define|#
directive|define
name|CMD_TX_RESET
value|001
end_define

begin_comment
comment|/* reset: disable, clear buffer/status/BRK */
end_comment

begin_define
define|#
directive|define
name|CMD_TX_ENABLE
value|002
end_define

begin_comment
comment|/* transmitter enable */
end_comment

begin_define
define|#
directive|define
name|CMD_TX_DISABLE
value|003
end_define

begin_comment
comment|/* transmitter disable */
end_comment

begin_define
define|#
directive|define
name|CMD_TX_CRC_INIT
value|004
end_define

begin_comment
comment|/* initialize CRC calculator */
end_comment

begin_define
define|#
directive|define
name|CMD_TX_EOM_CHAR
value|006
end_define

begin_comment
comment|/* set end-of-message char */
end_comment

begin_define
define|#
directive|define
name|CMD_TX_ABORT
value|007
end_define

begin_comment
comment|/* abort transmission (HDLC mode) */
end_comment

begin_define
define|#
directive|define
name|CMD_TX_MPON
value|010
end_define

begin_comment
comment|/* transmit char with MP bit on (async) */
end_comment

begin_define
define|#
directive|define
name|CMD_TX_CLEAR
value|011
end_define

begin_comment
comment|/* clear the transmit buffer */
end_comment

begin_define
define|#
directive|define
name|CMD_RX_RESET
value|021
end_define

begin_comment
comment|/* reset: disable, clear buffer/status */
end_comment

begin_define
define|#
directive|define
name|CMD_RX_ENABLE
value|022
end_define

begin_comment
comment|/* receiver enable */
end_comment

begin_define
define|#
directive|define
name|CMD_RX_DISABLE
value|023
end_define

begin_comment
comment|/* receiver disable */
end_comment

begin_define
define|#
directive|define
name|CMD_RX_CRC_INIT
value|024
end_define

begin_comment
comment|/* initialize CRC calculator */
end_comment

begin_define
define|#
directive|define
name|CMD_RX_REJECT
value|025
end_define

begin_comment
comment|/* reject current message (sync mode) */
end_comment

begin_define
define|#
directive|define
name|CMD_RX_SRCH_MP
value|026
end_define

begin_comment
comment|/* skip all until the char witn MP bit on */
end_comment

begin_define
define|#
directive|define
name|CMD_NOOP
value|000
end_define

begin_comment
comment|/* continue current operation */
end_comment

begin_define
define|#
directive|define
name|CMD_CHAN_RESET
value|041
end_define

begin_comment
comment|/* init registers, disable/clear RX/TX */
end_comment

begin_define
define|#
directive|define
name|CMD_SEARCH_MODE
value|061
end_define

begin_comment
comment|/* set the ADPLL to search mode */
end_comment

begin_comment
comment|/*  * Status register 0 (ST0) bits.  */
end_comment

begin_define
define|#
directive|define
name|ST0_RX_RDY
value|0x01
end_define

begin_comment
comment|/* receiver ready */
end_comment

begin_define
define|#
directive|define
name|ST0_TX_RDY
value|0x02
end_define

begin_comment
comment|/* transmitter ready */
end_comment

begin_define
define|#
directive|define
name|ST0_RX_INT
value|0x40
end_define

begin_comment
comment|/* receiver status interrupt */
end_comment

begin_define
define|#
directive|define
name|ST0_TX_INT
value|0x80
end_define

begin_comment
comment|/* transmitter status interrupt */
end_comment

begin_comment
comment|/*  * Status register 1 (ST1) bits.  */
end_comment

begin_define
define|#
directive|define
name|ST1_CDCD
value|0x04
end_define

begin_comment
comment|/* carrier changed */
end_comment

begin_define
define|#
directive|define
name|ST1_CCTS
value|0x08
end_define

begin_comment
comment|/* CTS changed */
end_comment

begin_define
define|#
directive|define
name|ST1_IDL
value|0x40
end_define

begin_comment
comment|/* transmitter idle, ro */
end_comment

begin_define
define|#
directive|define
name|ST1_ASYNC_BRKE
value|0x01
end_define

begin_comment
comment|/* break end detected */
end_comment

begin_define
define|#
directive|define
name|ST1_ASYNC_BRKD
value|0x02
end_define

begin_comment
comment|/* break start detected */
end_comment

begin_define
define|#
directive|define
name|ST1_ASYNC_BITS
value|"\20\1brke\2brkd\3cdcd\4ccts\7idl"
end_define

begin_define
define|#
directive|define
name|ST1_HDLC_IDLD
value|0x01
end_define

begin_comment
comment|/* idle sequence start detected */
end_comment

begin_define
define|#
directive|define
name|ST1_HDLC_ABTD
value|0x02
end_define

begin_comment
comment|/* abort sequence start detected */
end_comment

begin_define
define|#
directive|define
name|ST1_HDLC_FLGD
value|0x10
end_define

begin_comment
comment|/* flag detected */
end_comment

begin_define
define|#
directive|define
name|ST1_HDLC_UDRN
value|0x80
end_define

begin_comment
comment|/* underrun detected */
end_comment

begin_define
define|#
directive|define
name|ST1_HDLC_BITS
value|"\20\1idld\2abtd\3cdcd\4ccts\5flgd\7idl\10udrn"
end_define

begin_comment
comment|/*  * Status register 2 (ST2) bits.  */
end_comment

begin_define
define|#
directive|define
name|ST2_OVRN
value|0x08
end_define

begin_comment
comment|/* overrun error detected */
end_comment

begin_define
define|#
directive|define
name|ST2_ASYNC_FRME
value|0x10
end_define

begin_comment
comment|/* framing error detected */
end_comment

begin_define
define|#
directive|define
name|ST2_ASYNC_PE
value|0x20
end_define

begin_comment
comment|/* parity error detected */
end_comment

begin_define
define|#
directive|define
name|ST2_ASYNC_PMP
value|0x40
end_define

begin_comment
comment|/* parity/MP bit = 1 */
end_comment

begin_define
define|#
directive|define
name|ST2_ASYNC_BITS
value|"\20\4ovrn\5frme\6pe\7pmp"
end_define

begin_define
define|#
directive|define
name|ST2_HDLC_CRCE
value|0x04
end_define

begin_comment
comment|/* CRC error detected */
end_comment

begin_define
define|#
directive|define
name|ST2_HDLC_RBIT
value|0x10
end_define

begin_comment
comment|/* residual bit frame detected */
end_comment

begin_define
define|#
directive|define
name|ST2_HDLC_ABT
value|0x20
end_define

begin_comment
comment|/* frame with abort end detected */
end_comment

begin_define
define|#
directive|define
name|ST2_HDLC_SHRT
value|0x40
end_define

begin_comment
comment|/* short frame detected */
end_comment

begin_define
define|#
directive|define
name|ST2_HDLC_EOM
value|0x80
end_define

begin_comment
comment|/* receive frame end detected */
end_comment

begin_define
define|#
directive|define
name|ST2_HDLC_BITS
value|"\20\3crce\4ovrn\5rbit\6abt\7shrt\10eom"
end_define

begin_comment
comment|/*  * Status register 3 (ST3) bits.  */
end_comment

begin_define
define|#
directive|define
name|ST3_RX_ENABLED
value|0x01
end_define

begin_comment
comment|/* receiver is enabled */
end_comment

begin_define
define|#
directive|define
name|ST3_TX_ENABLED
value|0x02
end_define

begin_comment
comment|/* transmitter is enabled */
end_comment

begin_define
define|#
directive|define
name|ST3_DCD_INV
value|0x04
end_define

begin_comment
comment|/* DCD input line inverted */
end_comment

begin_define
define|#
directive|define
name|ST3_CTS_INV
value|0x08
end_define

begin_comment
comment|/* CTS input line inverted */
end_comment

begin_define
define|#
directive|define
name|ST3_ASYNC_BITS
value|"\20\1rx\2tx\3nodcd\4nocts"
end_define

begin_define
define|#
directive|define
name|ST3_HDLC_SEARCH
value|0x10
end_define

begin_comment
comment|/* ADPLL search mode */
end_comment

begin_define
define|#
directive|define
name|ST3_HDLC_TX
value|0x20
end_define

begin_comment
comment|/* channel is transmitting data */
end_comment

begin_define
define|#
directive|define
name|ST3_HDLC_BITS
value|"\20\1rx\2tx\3nodcd\4nocts\5search\6txact"
end_define

begin_comment
comment|/*  * Frame status register (FST) bits, HDLC mode only.  */
end_comment

begin_define
define|#
directive|define
name|FST_CRCE
value|0x04
end_define

begin_comment
comment|/* CRC error detected */
end_comment

begin_define
define|#
directive|define
name|FST_OVRN
value|0x08
end_define

begin_comment
comment|/* overrun error detected */
end_comment

begin_define
define|#
directive|define
name|FST_RBIT
value|0x10
end_define

begin_comment
comment|/* residual bit frame detected */
end_comment

begin_define
define|#
directive|define
name|FST_ABT
value|0x20
end_define

begin_comment
comment|/* frame with abort end detected */
end_comment

begin_define
define|#
directive|define
name|FST_SHRT
value|0x40
end_define

begin_comment
comment|/* short frame detected */
end_comment

begin_define
define|#
directive|define
name|FST_EOM
value|0x80
end_define

begin_comment
comment|/* frame end flag */
end_comment

begin_define
define|#
directive|define
name|FST_EOT
value|0x01
end_define

begin_comment
comment|/* end of transfer, transmit only */
end_comment

begin_comment
comment|/*  * Interrupt enable register 0 (IE0) bits.  */
end_comment

begin_define
define|#
directive|define
name|IE0_RX_RDYE
value|0x01
end_define

begin_comment
comment|/* receiver ready interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IE0_TX_RDYE
value|0x02
end_define

begin_comment
comment|/* transmitter ready interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IE0_RX_INTE
value|0x40
end_define

begin_comment
comment|/* receiver status interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IE0_TX_INTE
value|0x80
end_define

begin_comment
comment|/* transmitter status interrupt enable */
end_comment

begin_comment
comment|/*  * Interrupt enable register 1 (IE1) bits.  */
end_comment

begin_define
define|#
directive|define
name|IE1_CDCDE
value|0x04
end_define

begin_comment
comment|/* carrier changed */
end_comment

begin_define
define|#
directive|define
name|IE1_CCTSE
value|0x08
end_define

begin_comment
comment|/* CTS changed */
end_comment

begin_define
define|#
directive|define
name|IE1_IDLE
value|0x40
end_define

begin_comment
comment|/* transmitter idle, ro */
end_comment

begin_define
define|#
directive|define
name|IE1_ASYNC_BRKEE
value|0x01
end_define

begin_comment
comment|/* break end detected */
end_comment

begin_define
define|#
directive|define
name|IE1_ASYNC_BRKDE
value|0x02
end_define

begin_comment
comment|/* break start detected */
end_comment

begin_define
define|#
directive|define
name|IE1_HDLC_IDLDE
value|0x01
end_define

begin_comment
comment|/* idle sequence start detected */
end_comment

begin_define
define|#
directive|define
name|IE1_HDLC_ABTDE
value|0x02
end_define

begin_comment
comment|/* abort sequence start detected */
end_comment

begin_define
define|#
directive|define
name|IE1_HDLC_FLGDE
value|0x10
end_define

begin_comment
comment|/* flag detected */
end_comment

begin_define
define|#
directive|define
name|IE1_HDLC_UDRNE
value|0x80
end_define

begin_comment
comment|/* underrun detected */
end_comment

begin_comment
comment|/*  * Interrupt enable register 2 (IE2) bits.  */
end_comment

begin_define
define|#
directive|define
name|IE2_OVRNE
value|0x08
end_define

begin_comment
comment|/* overrun error detected */
end_comment

begin_define
define|#
directive|define
name|IE2_ASYNC_FRMEE
value|0x10
end_define

begin_comment
comment|/* framing error detected */
end_comment

begin_define
define|#
directive|define
name|IE2_ASYNC_PEE
value|0x20
end_define

begin_comment
comment|/* parity error detected */
end_comment

begin_define
define|#
directive|define
name|IE2_ASYNC_PMPE
value|0x40
end_define

begin_comment
comment|/* parity/MP bit = 1 */
end_comment

begin_define
define|#
directive|define
name|IE2_HDLC_CRCEE
value|0x04
end_define

begin_comment
comment|/* CRC error detected */
end_comment

begin_define
define|#
directive|define
name|IE2_HDLC_RBITE
value|0x10
end_define

begin_comment
comment|/* residual bit frame detected */
end_comment

begin_define
define|#
directive|define
name|IE2_HDLC_ABTE
value|0x20
end_define

begin_comment
comment|/* frame with abort end detected */
end_comment

begin_define
define|#
directive|define
name|IE2_HDLC_SHRTE
value|0x40
end_define

begin_comment
comment|/* short frame detected */
end_comment

begin_define
define|#
directive|define
name|IE2_HDLC_EOME
value|0x80
end_define

begin_comment
comment|/* receive frame end detected */
end_comment

begin_comment
comment|/*  * Frame interrupt enable register (FIE) bits, HDLC mode only.  */
end_comment

begin_define
define|#
directive|define
name|FIE_EOMFE
value|0x80
end_define

begin_comment
comment|/* receive frame end detected */
end_comment

begin_comment
comment|/*  * Current status register (CST0,CST1) bits.  * For other bits, see ST2.  */
end_comment

begin_define
define|#
directive|define
name|CST0_CDE
value|0x0001
end_define

begin_comment
comment|/* data present on top of FIFO */
end_comment

begin_define
define|#
directive|define
name|CST1_CDE
value|0x0100
end_define

begin_comment
comment|/* data present on second stage of FIFO */
end_comment

begin_comment
comment|/*  * Receive/transmit clock source register (RXS/TXS) bits.  */
end_comment

begin_define
define|#
directive|define
name|CLK_MASK
value|0x70
end_define

begin_comment
comment|/* RXC/TXC clock input mask */
end_comment

begin_define
define|#
directive|define
name|CLK_LINE
value|0x00
end_define

begin_comment
comment|/* RXC/TXC line input */
end_comment

begin_define
define|#
directive|define
name|CLK_INT
value|0x40
end_define

begin_comment
comment|/* internal baud rate generator */
end_comment

begin_define
define|#
directive|define
name|CLK_RXS_LINE_NS
value|0x20
end_define

begin_comment
comment|/* RXC line with noise suppression */
end_comment

begin_define
define|#
directive|define
name|CLK_RXS_DPLL_INT
value|0x60
end_define

begin_comment
comment|/* ADPLL based on internal BRG */
end_comment

begin_define
define|#
directive|define
name|CLK_RXS_DPLL_LINE
value|0x70
end_define

begin_comment
comment|/* ADPLL based on RXC line */
end_comment

begin_define
define|#
directive|define
name|CLK_TXS_RECV
value|0x60
end_define

begin_comment
comment|/* receive clock */
end_comment

begin_comment
comment|/*  * DMA status register (DSR) bits.  */
end_comment

begin_define
define|#
directive|define
name|DSR_DMA_DISABLE
value|0x00
end_define

begin_comment
comment|/* disable DMA channel */
end_comment

begin_define
define|#
directive|define
name|DSR_DMA_ENABLE
value|0x02
end_define

begin_comment
comment|/* enable DMA channel */
end_comment

begin_define
define|#
directive|define
name|DSR_DMA_CONTINUE
value|0x01
end_define

begin_comment
comment|/* do not enable/disable DMA channel */
end_comment

begin_define
define|#
directive|define
name|DSR_CHAIN_COF
value|0x10
end_define

begin_comment
comment|/* counter overflow */
end_comment

begin_define
define|#
directive|define
name|DSR_CHAIN_BOF
value|0x20
end_define

begin_comment
comment|/* buffer overflow/underflow */
end_comment

begin_define
define|#
directive|define
name|DSR_CHAIN_EOM
value|0x40
end_define

begin_comment
comment|/* frame transfer completed */
end_comment

begin_define
define|#
directive|define
name|DSR_EOT
value|0x80
end_define

begin_comment
comment|/* transfer completed */
end_comment

begin_define
define|#
directive|define
name|DSR_BITS
value|"\20\1cont\2enab\5cof\6bof\7eom\10eot"
end_define

begin_comment
comment|/*  * DMA mode register (DMR) bits.  */
end_comment

begin_define
define|#
directive|define
name|DMR_CHAIN_CNTE
value|0x02
end_define

begin_comment
comment|/* enable frame interrupt counter (FCT) */
end_comment

begin_define
define|#
directive|define
name|DMR_CHAIN_NF
value|0x04
end_define

begin_comment
comment|/* multi-frame block chain */
end_comment

begin_define
define|#
directive|define
name|DMR_TMOD
value|0x10
end_define

begin_comment
comment|/* chained-block transfer mode */
end_comment

begin_comment
comment|/*  * DMA interrupt enable register (DIR) bits.  */
end_comment

begin_define
define|#
directive|define
name|DIR_CHAIN_COFE
value|0x10
end_define

begin_comment
comment|/* counter overflow */
end_comment

begin_define
define|#
directive|define
name|DIR_CHAIN_BOFE
value|0x20
end_define

begin_comment
comment|/* buffer overflow/underflow */
end_comment

begin_define
define|#
directive|define
name|DIR_CHAIN_EOME
value|0x40
end_define

begin_comment
comment|/* frame transfer completed */
end_comment

begin_define
define|#
directive|define
name|DIR_EOTE
value|0x80
end_define

begin_comment
comment|/* transfer completed */
end_comment

begin_comment
comment|/*  * DMA command register (DCR) values.  */
end_comment

begin_define
define|#
directive|define
name|DCR_ABORT
value|1
end_define

begin_comment
comment|/* software abort: initialize DMA channel */
end_comment

begin_define
define|#
directive|define
name|DCR_CLEAR
value|2
end_define

begin_comment
comment|/* clear FCT and EOM bit of DSR */
end_comment

begin_comment
comment|/*  * DMA master enable register (DME) bits.  */
end_comment

begin_define
define|#
directive|define
name|DME_ENABLE
value|0x80
end_define

begin_comment
comment|/* enable DMA master operation */
end_comment

begin_comment
comment|/*  * Timer control/status register (TCSR) bits.  */
end_comment

begin_define
define|#
directive|define
name|TCSR_ENABLE
value|0x10
end_define

begin_comment
comment|/* timer starts incrementing */
end_comment

begin_define
define|#
directive|define
name|TCSR_INTR
value|0x40
end_define

begin_comment
comment|/* timer interrupt enable */
end_comment

begin_define
define|#
directive|define
name|TCSR_MATCH
value|0x80
end_define

begin_comment
comment|/* TCNT and TCONR are equal */
end_comment

begin_comment
comment|/*  * Timer expand prescale register (TEPR) values.  */
end_comment

begin_define
define|#
directive|define
name|TEPR_1
value|0
end_define

begin_comment
comment|/* sysclk/8 */
end_comment

begin_define
define|#
directive|define
name|TEPR_2
value|1
end_define

begin_comment
comment|/* sysclk/8/2 */
end_comment

begin_define
define|#
directive|define
name|TEPR_4
value|2
end_define

begin_comment
comment|/* sysclk/8/4 */
end_comment

begin_define
define|#
directive|define
name|TEPR_8
value|3
end_define

begin_comment
comment|/* sysclk/8/8 */
end_comment

begin_define
define|#
directive|define
name|TEPR_16
value|4
end_define

begin_comment
comment|/* sysclk/8/16 */
end_comment

begin_define
define|#
directive|define
name|TEPR_32
value|5
end_define

begin_comment
comment|/* sysclk/8/32 */
end_comment

begin_define
define|#
directive|define
name|TEPR_64
value|6
end_define

begin_comment
comment|/* sysclk/8/64 */
end_comment

begin_define
define|#
directive|define
name|TEPR_128
value|7
end_define

begin_comment
comment|/* sysclk/8/128 */
end_comment

end_unit


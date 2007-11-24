begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_IF_ATEREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_IF_ATEREG_H
end_define

begin_define
define|#
directive|define
name|ETH_CTL
value|0x00
end_define

begin_comment
comment|/* EMAC Control Register */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG
value|0x04
end_define

begin_comment
comment|/* EMAC Configuration Register */
end_comment

begin_define
define|#
directive|define
name|ETH_SR
value|0x08
end_define

begin_comment
comment|/* EMAC STatus Register */
end_comment

begin_define
define|#
directive|define
name|ETH_TAR
value|0x0c
end_define

begin_comment
comment|/* EMAC Transmit Address Register */
end_comment

begin_define
define|#
directive|define
name|ETH_TCR
value|0x10
end_define

begin_comment
comment|/* EMAC Transmit Control Register */
end_comment

begin_define
define|#
directive|define
name|ETH_TSR
value|0x14
end_define

begin_comment
comment|/* EMAC Transmit Status Register */
end_comment

begin_define
define|#
directive|define
name|ETH_RBQP
value|0x18
end_define

begin_comment
comment|/* EMAC Receive Buffer Queue Pointer */
end_comment

begin_comment
comment|/*	0x1c		   reserved */
end_comment

begin_define
define|#
directive|define
name|ETH_RSR
value|0x20
end_define

begin_comment
comment|/* EMAC Receive Status Register */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR
value|0x24
end_define

begin_comment
comment|/* EMAC Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|ETH_IER
value|0x28
end_define

begin_comment
comment|/* EMAC Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|ETH_IDR
value|0x2c
end_define

begin_comment
comment|/* EMAC Interrupt Disable Register */
end_comment

begin_define
define|#
directive|define
name|ETH_IMR
value|0x30
end_define

begin_comment
comment|/* EMAC Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|ETH_MAN
value|0x34
end_define

begin_comment
comment|/* EMAC PHY Maintenance Register */
end_comment

begin_comment
comment|/*	0x38		   reserved */
end_comment

begin_comment
comment|/*	0x3c		   reserved */
end_comment

begin_define
define|#
directive|define
name|ETH_FRA
value|0x40
end_define

begin_comment
comment|/* Frames Transmitted OK Register */
end_comment

begin_define
define|#
directive|define
name|ETH_SCOL
value|0x44
end_define

begin_comment
comment|/* Single Collision Frame Register */
end_comment

begin_define
define|#
directive|define
name|ETH_MCOL
value|0x48
end_define

begin_comment
comment|/* Multiple Collision Frame Register */
end_comment

begin_define
define|#
directive|define
name|ETH_OK
value|0x4c
end_define

begin_comment
comment|/* Frames Received OK Register */
end_comment

begin_define
define|#
directive|define
name|ETH_SEQE
value|0x50
end_define

begin_comment
comment|/* Frame Check Sequence Error Reg */
end_comment

begin_define
define|#
directive|define
name|ETH_ALE
value|0x54
end_define

begin_comment
comment|/* Alignment Error Register */
end_comment

begin_define
define|#
directive|define
name|ETH_DTE
value|0x58
end_define

begin_comment
comment|/* Deferred Transmittion Frame Reg */
end_comment

begin_define
define|#
directive|define
name|ETH_LCOL
value|0x5c
end_define

begin_comment
comment|/* Late Collision Register */
end_comment

begin_define
define|#
directive|define
name|ETH_ECOL
value|0x60
end_define

begin_comment
comment|/* Excessive Collision Register */
end_comment

begin_define
define|#
directive|define
name|ETH_CSE
value|0x64
end_define

begin_comment
comment|/* Carrier Sense Error Register */
end_comment

begin_define
define|#
directive|define
name|ETH_TUE
value|0x68
end_define

begin_comment
comment|/* Transmit Underrun Error Register */
end_comment

begin_define
define|#
directive|define
name|ETH_CDE
value|0x6c
end_define

begin_comment
comment|/* Code Error Register */
end_comment

begin_define
define|#
directive|define
name|ETH_ELR
value|0x70
end_define

begin_comment
comment|/* Excessive Length Error Register */
end_comment

begin_define
define|#
directive|define
name|ETH_RJB
value|0x74
end_define

begin_comment
comment|/* Receive Jabber Register */
end_comment

begin_define
define|#
directive|define
name|ETH_USF
value|0x78
end_define

begin_comment
comment|/* Undersize Frame Register */
end_comment

begin_define
define|#
directive|define
name|ETH_SQEE
value|0x7c
end_define

begin_comment
comment|/* SQE Test Error Register */
end_comment

begin_define
define|#
directive|define
name|ETH_DRFC
value|0x80
end_define

begin_comment
comment|/* Discarded RX Frame Register */
end_comment

begin_comment
comment|/*	0x84		   reserved */
end_comment

begin_comment
comment|/*	0x88		   reserved */
end_comment

begin_comment
comment|/*	0x8c		   reserved */
end_comment

begin_define
define|#
directive|define
name|ETH_HSH
value|0x90
end_define

begin_comment
comment|/* EMAC Hash Address High [63:32] */
end_comment

begin_define
define|#
directive|define
name|ETH_HSL
value|0x94
end_define

begin_comment
comment|/* EMAC Hash Address Low [31:0] */
end_comment

begin_define
define|#
directive|define
name|ETH_SA1L
value|0x98
end_define

begin_comment
comment|/* EMAC Specific Address 1 Low */
end_comment

begin_define
define|#
directive|define
name|ETH_SA1H
value|0x9c
end_define

begin_comment
comment|/* EMAC Specific Address 1 High */
end_comment

begin_define
define|#
directive|define
name|ETH_SA2L
value|0xa0
end_define

begin_comment
comment|/* EMAC Specific Address 2 Low */
end_comment

begin_define
define|#
directive|define
name|ETH_SA2H
value|0xa4
end_define

begin_comment
comment|/* EMAC Specific Address 2 High */
end_comment

begin_define
define|#
directive|define
name|ETH_SA3L
value|0xa8
end_define

begin_comment
comment|/* EMAC Specific Address 3 Low */
end_comment

begin_define
define|#
directive|define
name|ETH_SA3H
value|0xac
end_define

begin_comment
comment|/* EMAC Specific Address 3 High */
end_comment

begin_define
define|#
directive|define
name|ETH_SA4L
value|0xb0
end_define

begin_comment
comment|/* EMAC Specific Address 4 Low */
end_comment

begin_define
define|#
directive|define
name|ETH_SA4H
value|0xb4
end_define

begin_comment
comment|/* EMAC Specific Address 4 High */
end_comment

begin_comment
comment|/* ETH_CTL */
end_comment

begin_define
define|#
directive|define
name|ETH_CTL_LB
value|(1U<< 0)
end_define

begin_comment
comment|/* LB: Loopback */
end_comment

begin_define
define|#
directive|define
name|ETH_CTL_LBL
value|(1U<< 1)
end_define

begin_comment
comment|/* LBL: Loopback Local */
end_comment

begin_define
define|#
directive|define
name|ETH_CTL_RE
value|(1U<< 2)
end_define

begin_comment
comment|/* RE: Receive Enable */
end_comment

begin_define
define|#
directive|define
name|ETH_CTL_TE
value|(1U<< 3)
end_define

begin_comment
comment|/* TE: Transmit Enable */
end_comment

begin_define
define|#
directive|define
name|ETH_CTL_MPE
value|(1U<< 4)
end_define

begin_comment
comment|/* MPE: Management Port Enable */
end_comment

begin_define
define|#
directive|define
name|ETH_CTL_CSR
value|(1U<< 5)
end_define

begin_comment
comment|/* CSR: Clear Statistics Registers */
end_comment

begin_define
define|#
directive|define
name|ETH_CTL_ISR
value|(1U<< 6)
end_define

begin_comment
comment|/* ISR: Incremenet Statistics Regs */
end_comment

begin_define
define|#
directive|define
name|ETH_CTL_WES
value|(1U<< 7)
end_define

begin_comment
comment|/* WES: Write Enable Statistics regs */
end_comment

begin_define
define|#
directive|define
name|ETH_CTL_BP
value|(1U<< 8)
end_define

begin_comment
comment|/* BP: Back Pressure */
end_comment

begin_comment
comment|/* ETH_CFG */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_SPD
value|(1U<< 0)
end_define

begin_comment
comment|/* SPD: Speed 1 == 100: 0 == 10 */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_FD
value|(1U<< 1)
end_define

begin_comment
comment|/* FD: Full duplex */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_BR
value|(1U<< 2)
end_define

begin_comment
comment|/* BR: Bit Rate (optional?) */
end_comment

begin_comment
comment|/* bit 3 reserved */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_CAF
value|(1U<< 4)
end_define

begin_comment
comment|/* CAF: Copy All Frames */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_NBC
value|(1U<< 5)
end_define

begin_comment
comment|/* NBC: No Broadcast */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_MTI
value|(1U<< 6)
end_define

begin_comment
comment|/* MTI: Multicast Hash Enable */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_UNI
value|(1U<< 7)
end_define

begin_comment
comment|/* UNI: Unicast Hash Enable */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_BIG
value|(1U<< 8)
end_define

begin_comment
comment|/* BIG: Receive 1522 Bytes */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_EAE
value|(1U<< 9)
end_define

begin_comment
comment|/* EAE: External Address Match En */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_CLK_8
value|(0U<< 10)
end_define

begin_comment
comment|/* CLK: Clock / 8 */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_CLK_16
value|(1U<< 10)
end_define

begin_comment
comment|/* CLK: Clock / 16 */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_CLK_32
value|(2U<< 10)
end_define

begin_comment
comment|/* CLK: Clock / 32 */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_CLK_64
value|(3U<< 10)
end_define

begin_comment
comment|/* CLK: Clock / 64 */
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_RTY
value|(1U<< 12)
end_define

begin_comment
comment|/* RTY: Retry Test*/
end_comment

begin_define
define|#
directive|define
name|ETH_CFG_RMII
value|(1U<< 13)
end_define

begin_comment
comment|/* RMII: Reduce MII */
end_comment

begin_comment
comment|/* ETH_SR */
end_comment

begin_define
define|#
directive|define
name|ETH_SR_LINK
value|(1U<< 0)
end_define

begin_comment
comment|/* Reserved! */
end_comment

begin_define
define|#
directive|define
name|ETH_SR_MDIO
value|(1U<< 1)
end_define

begin_comment
comment|/* MDIO pin status */
end_comment

begin_define
define|#
directive|define
name|ETH_SR_IDLE
value|(1U<< 2)
end_define

begin_comment
comment|/* IDLE (PHY logic) */
end_comment

begin_comment
comment|/* ETH_TCR */
end_comment

begin_define
define|#
directive|define
name|ETH_TCR_NCRC
value|(1U<< 15)
end_define

begin_comment
comment|/* NCRC: No CRC */
end_comment

begin_comment
comment|/* ETH_TSR */
end_comment

begin_define
define|#
directive|define
name|ETH_TSR_OVR
value|(1U<< 0)
end_define

begin_comment
comment|/* OVR: Ethernet Transmit Overrun */
end_comment

begin_define
define|#
directive|define
name|ETH_TSR_COL
value|(1U<< 1)
end_define

begin_comment
comment|/* COL: Collision Occurred */
end_comment

begin_define
define|#
directive|define
name|ETH_TSR_RLE
value|(1U<< 2)
end_define

begin_comment
comment|/* RLE: Retry Limit Exceeded */
end_comment

begin_define
define|#
directive|define
name|ETH_TSR_IDLE
value|(1U<< 3)
end_define

begin_comment
comment|/* IDLE: Transmitter Idle */
end_comment

begin_define
define|#
directive|define
name|ETH_TSR_BNQ
value|(1U<< 4)
end_define

begin_comment
comment|/* BNQ: Enet Tran Buff not Queued */
end_comment

begin_define
define|#
directive|define
name|ETH_TSR_COMP
value|(1U<< 5)
end_define

begin_comment
comment|/* COMP: Transmit Complete */
end_comment

begin_define
define|#
directive|define
name|ETH_TSR_UND
value|(1U<< 6)
end_define

begin_comment
comment|/* UND: Transmit Underrun */
end_comment

begin_define
define|#
directive|define
name|ETH_TSR_WR_MASK
value|(0x67)
end_define

begin_comment
comment|/* write 1 to clear bits */
end_comment

begin_comment
comment|/* ETH_RSR */
end_comment

begin_define
define|#
directive|define
name|ETH_RSR_BNA
value|(1U<< 0)
end_define

begin_comment
comment|/* BNA: Buffer Not Available */
end_comment

begin_define
define|#
directive|define
name|ETH_RSR_REC
value|(1U<< 1)
end_define

begin_comment
comment|/* REC: Frame Received */
end_comment

begin_define
define|#
directive|define
name|ETH_RSR_OVR
value|(1U<< 2)
end_define

begin_comment
comment|/* OVR: RX Overrun */
end_comment

begin_comment
comment|/* ETH_ISR */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_DONE
value|(1U<< 0)
end_define

begin_comment
comment|/* DONE: Management Done */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_RCOM
value|(1U<< 1)
end_define

begin_comment
comment|/* RCOM: Receive Complete */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_RBNA
value|(1U<< 2)
end_define

begin_comment
comment|/* RBNA: Receive Buffer Not Avail */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_TOVR
value|(1U<< 3)
end_define

begin_comment
comment|/* TOVR: Transmit Buffer Overrun */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_TUND
value|(1U<< 4)
end_define

begin_comment
comment|/* TUND: Transmit Buffer Underrun */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_RTRY
value|(1U<< 5)
end_define

begin_comment
comment|/* RTRY: Retry Limit */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_TBRE
value|(1U<< 6)
end_define

begin_comment
comment|/* TBRE: Trasnmit Buffer Reg empty */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_TCOM
value|(1U<< 7)
end_define

begin_comment
comment|/* TCOM: Transmit Complete */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_TIDLE
value|(1U<< 8)
end_define

begin_comment
comment|/* TIDLE: Transmit Idle */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_LINK
value|(1U<< 9)
end_define

begin_comment
comment|/* LINK: Link pin delta (optional) */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_ROVR
value|(1U<< 10)
end_define

begin_comment
comment|/* ROVR: RX Overrun */
end_comment

begin_define
define|#
directive|define
name|ETH_ISR_ABT
value|(1U<< 11)
end_define

begin_comment
comment|/* ABT: Abort */
end_comment

begin_comment
comment|/* ETH_MAN */
end_comment

begin_define
define|#
directive|define
name|ETH_MAN_BITS
value|0x40020000
end_define

begin_comment
comment|/* HIGH and CODE bits */
end_comment

begin_define
define|#
directive|define
name|ETH_MAN_READ
value|(2U<< 28)
end_define

begin_define
define|#
directive|define
name|ETH_MAN_WRITE
value|(1U<< 28)
end_define

begin_define
define|#
directive|define
name|ETH_MAN_PHYA_BIT
value|23
end_define

begin_define
define|#
directive|define
name|ETH_MAN_REGA_BIT
value|18
end_define

begin_define
define|#
directive|define
name|ETH_MAN_VALUE_MASK
value|0xffffU
end_define

begin_define
define|#
directive|define
name|ETH_MAN_REG_WR
parameter_list|(
name|phy
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|(ETH_MAN_BITS | ETH_MAN_WRITE | ((phy)<< ETH_MAN_PHYA_BIT) | \ 		((reg)<< ETH_MAN_REGA_BIT) | ((val)& ETH_MAN_VALUE_MASK))
end_define

begin_define
define|#
directive|define
name|ETH_MAN_REG_RD
parameter_list|(
name|phy
parameter_list|,
name|reg
parameter_list|)
define|\
value|(ETH_MAN_BITS | ETH_MAN_READ | ((phy)<< ETH_MAN_PHYA_BIT) | \ 		((reg)<< ETH_MAN_REGA_BIT))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|addr
decl_stmt|;
define|#
directive|define
name|ETH_CPU_OWNER
value|(1U<< 0)
define|#
directive|define
name|ETH_WRAP_BIT
value|(1U<< 1)
name|uint32_t
name|status
decl_stmt|;
define|#
directive|define
name|ETH_LEN_MASK
value|0x7ff
define|#
directive|define
name|ETH_MAC_LOCAL_4
value|(1U<< 23)
comment|/* Packet matched addr 4 */
define|#
directive|define
name|ETH_MAC_LOCAL_3
value|(1U<< 24)
comment|/* Packet matched addr 3 */
define|#
directive|define
name|ETH_MAC_LOCAL_2
value|(1U<< 25)
comment|/* Packet matched addr 2 */
define|#
directive|define
name|ETH_MAC_LOCAL_1
value|(1U<< 26)
comment|/* Packet matched addr 1 */
define|#
directive|define
name|ETH_MAC_UNK
value|(1U<< 27)
comment|/* Unkown source address RFU */
define|#
directive|define
name|ETH_MAC_EXT
value|(1U<< 28)
comment|/* External Address */
define|#
directive|define
name|ETH_MAC_UCAST
value|(1U<< 29)
comment|/* Unicast hash match */
define|#
directive|define
name|ETH_MAC_MCAST
value|(1U<< 30)
comment|/* Multicast hash match */
define|#
directive|define
name|ETH_MAC_ONES
value|(1U<< 31)
comment|/* Global all ones bcast addr */
block|}
name|eth_rx_desc_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_IF_ATEREG_H */
end_comment

end_unit


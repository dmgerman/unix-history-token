begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: yukonreg.h,v 1.2 2003/08/12 05:23:06 nate Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003 Nathan L. Binkert<binkertn@umich.edu>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* General Purpose Status Register (GPSR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_GPSR
value|0x0000
end_define

begin_define
define|#
directive|define
name|YU_GPSR_SPEED
value|0x8000
end_define

begin_comment
comment|/* speed 0 - 10Mbps, 1 - 100Mbps */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_DUPLEX
value|0x4000
end_define

begin_comment
comment|/* 0 - half duplex, 1 - full duplex */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_FCTL_TX
value|0x2000
end_define

begin_comment
comment|/* flow control */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_LINK
value|0x1000
end_define

begin_comment
comment|/* link status (down/up) */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_PAUSE
value|0x0800
end_define

begin_comment
comment|/* flow control enable/disable */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_TX_IN_PROG
value|0x0400
end_define

begin_comment
comment|/* transmit in progress */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_EXCESS_COL
value|0x0200
end_define

begin_comment
comment|/* excessive collisions occurred */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_LATE_COL
value|0x0100
end_define

begin_comment
comment|/* late collision occurred */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_MII_PHY_STC
value|0x0020
end_define

begin_comment
comment|/* MII PHY status change */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_GIG_SPEED
value|0x0010
end_define

begin_comment
comment|/* Gigabit Speed (0 - use speed bit) */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_PARTITION
value|0x0008
end_define

begin_comment
comment|/* partition mode */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_FCTL_RX
value|0x0004
end_define

begin_comment
comment|/* flow control enable/disable */
end_comment

begin_define
define|#
directive|define
name|YU_GPSR_PROMS_EN
value|0x0002
end_define

begin_comment
comment|/* promiscuous mode enable/disable */
end_comment

begin_comment
comment|/* General Purpose Control Register (GPCR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_GPCR
value|0x0004
end_define

begin_define
define|#
directive|define
name|YU_GPCR_FCTL_TX
value|0x2000
end_define

begin_comment
comment|/* Transmit flow control 802.3x */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_TXEN
value|0x1000
end_define

begin_comment
comment|/* Transmit Enable */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_RXEN
value|0x0800
end_define

begin_comment
comment|/* Receive Enable */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_LPBK
value|0x0200
end_define

begin_comment
comment|/* Loopback Enable */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_PAR
value|0x0100
end_define

begin_comment
comment|/* Partition Enable */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_GIG
value|0x0080
end_define

begin_comment
comment|/* Gigabit Speed */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_FLP
value|0x0040
end_define

begin_comment
comment|/* Force Link Pass */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_DUPLEX
value|0x0020
end_define

begin_comment
comment|/* Duplex Enable */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_FCTL_RX
value|0x0010
end_define

begin_comment
comment|/* Receive flow control 802.3x */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_SPEED
value|0x0008
end_define

begin_comment
comment|/* Port Speed */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_DPLX_EN
value|0x0004
end_define

begin_comment
comment|/* Enable Auto-Update for duplex */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_FCTL_EN
value|0x0002
end_define

begin_comment
comment|/* Enabel Auto-Update for 802.3x */
end_comment

begin_define
define|#
directive|define
name|YU_GPCR_SPEED_EN
value|0x0001
end_define

begin_comment
comment|/* Enable Auto-Update for speed */
end_comment

begin_comment
comment|/* Transmit Control Register (TCR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_TCR
value|0x0008
end_define

begin_define
define|#
directive|define
name|YU_TCR_FJ
value|0x8000
end_define

begin_comment
comment|/* force jam / flow control */
end_comment

begin_define
define|#
directive|define
name|YU_TCR_CRCD
value|0x4000
end_define

begin_comment
comment|/* insert CRC (0 - enable) */
end_comment

begin_define
define|#
directive|define
name|YU_TCR_PADD
value|0x2000
end_define

begin_comment
comment|/* pad packets to 64b (0 - enable) */
end_comment

begin_define
define|#
directive|define
name|YU_TCR_COLTH
value|0x1c00
end_define

begin_comment
comment|/* collision threshold */
end_comment

begin_comment
comment|/* Receive Control Register (RCR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_RCR
value|0x000c
end_define

begin_define
define|#
directive|define
name|YU_RCR_UFLEN
value|0x8000
end_define

begin_comment
comment|/* unicast filter enable */
end_comment

begin_define
define|#
directive|define
name|YU_RCR_MUFLEN
value|0x4000
end_define

begin_comment
comment|/* multicast filter enable */
end_comment

begin_define
define|#
directive|define
name|YU_RCR_CRCR
value|0x2000
end_define

begin_comment
comment|/* remove CRC */
end_comment

begin_define
define|#
directive|define
name|YU_RCR_PASSFC
value|0x1000
end_define

begin_comment
comment|/* pass flow control packets */
end_comment

begin_comment
comment|/* Transmit Flow Control Register (TFCR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_TFCR
value|0x0010
end_define

begin_comment
comment|/* Pause Time */
end_comment

begin_comment
comment|/* Transmit Parameter Register (TPR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_TPR
value|0x0014
end_define

begin_define
define|#
directive|define
name|YU_TPR_JAM_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 14)
end_define

begin_define
define|#
directive|define
name|YU_TPR_JAM_IPG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 9)
end_define

begin_define
define|#
directive|define
name|YU_TPR_JAM2DATA_IPG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 4)
end_define

begin_comment
comment|/* Serial Mode Register (SMR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_SMR
value|0x0018
end_define

begin_define
define|#
directive|define
name|YU_SMR_DATA_BLIND
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 11)
end_define

begin_define
define|#
directive|define
name|YU_SMR_LIMIT4
value|0x0400
end_define

begin_comment
comment|/* reset after 16 / 4 collisions */
end_comment

begin_define
define|#
directive|define
name|YU_SMR_MFL_JUMBO
value|0x0100
end_define

begin_comment
comment|/* max frame length for jumbo frames */
end_comment

begin_define
define|#
directive|define
name|YU_SMR_MFL_VLAN
value|0x0200
end_define

begin_comment
comment|/* max frame length + vlan tag */
end_comment

begin_define
define|#
directive|define
name|YU_SMR_IPG_DATA
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1f)
end_define

begin_comment
comment|/* Source Address Low #1 (SAL1) */
end_comment

begin_define
define|#
directive|define
name|YUKON_SAL1
value|0x001c
end_define

begin_comment
comment|/* SA1[15:0] */
end_comment

begin_comment
comment|/* Source Address Middle #1 (SAM1) */
end_comment

begin_define
define|#
directive|define
name|YUKON_SAM1
value|0x0020
end_define

begin_comment
comment|/* SA1[31:16] */
end_comment

begin_comment
comment|/* Source Address High #1 (SAH1) */
end_comment

begin_define
define|#
directive|define
name|YUKON_SAH1
value|0x0024
end_define

begin_comment
comment|/* SA1[47:32] */
end_comment

begin_comment
comment|/* Source Address Low #2 (SAL2) */
end_comment

begin_define
define|#
directive|define
name|YUKON_SAL2
value|0x0028
end_define

begin_comment
comment|/* SA2[15:0] */
end_comment

begin_comment
comment|/* Source Address Middle #2 (SAM2) */
end_comment

begin_define
define|#
directive|define
name|YUKON_SAM2
value|0x002c
end_define

begin_comment
comment|/* SA2[31:16] */
end_comment

begin_comment
comment|/* Source Address High #2 (SAH2) */
end_comment

begin_define
define|#
directive|define
name|YUKON_SAH2
value|0x0030
end_define

begin_comment
comment|/* SA2[47:32] */
end_comment

begin_comment
comment|/* Multicatst Address Hash Register 1 (MCAH1) */
end_comment

begin_define
define|#
directive|define
name|YUKON_MCAH1
value|0x0034
end_define

begin_comment
comment|/* Multicatst Address Hash Register 2 (MCAH2) */
end_comment

begin_define
define|#
directive|define
name|YUKON_MCAH2
value|0x0038
end_define

begin_comment
comment|/* Multicatst Address Hash Register 3 (MCAH3) */
end_comment

begin_define
define|#
directive|define
name|YUKON_MCAH3
value|0x003c
end_define

begin_comment
comment|/* Multicatst Address Hash Register 4 (MCAH4) */
end_comment

begin_define
define|#
directive|define
name|YUKON_MCAH4
value|0x0040
end_define

begin_comment
comment|/* Transmit Interrupt Register (TIR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_TIR
value|0x0044
end_define

begin_define
define|#
directive|define
name|YU_TIR_OUT_UNICAST
value|0x0001
end_define

begin_comment
comment|/* Num Unicast Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_BROADCAST
value|0x0002
end_define

begin_comment
comment|/* Num Broadcast Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_PAUSE
value|0x0004
end_define

begin_comment
comment|/* Num Pause Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_MULTICAST
value|0x0008
end_define

begin_comment
comment|/* Num Multicast Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_OCTETS
value|0x0030
end_define

begin_comment
comment|/* Num Bytes Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_64_OCTETS
value|0x0000
end_define

begin_comment
comment|/* Num Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_127_OCTETS
value|0x0000
end_define

begin_comment
comment|/* Num Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_255_OCTETS
value|0x0000
end_define

begin_comment
comment|/* Num Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_511_OCTETS
value|0x0000
end_define

begin_comment
comment|/* Num Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_1023_OCTETS
value|0x0000
end_define

begin_comment
comment|/* Num Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_1518_OCTETS
value|0x0000
end_define

begin_comment
comment|/* Num Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_MAX_OCTETS
value|0x0000
end_define

begin_comment
comment|/* Num Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_SPARE
value|0x0000
end_define

begin_comment
comment|/* Num Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_COLLISIONS
value|0x0000
end_define

begin_comment
comment|/* Num Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|YU_TIR_OUT_LATE
value|0x0000
end_define

begin_comment
comment|/* Num Packets Transmitted */
end_comment

begin_comment
comment|/* Receive Interrupt Register (RIR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_RIR
value|0x0048
end_define

begin_comment
comment|/* Transmit and Receive Interrupt Register (TRIR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_TRIR
value|0x004c
end_define

begin_comment
comment|/* Transmit Interrupt Mask Register (TIMR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_TIMR
value|0x0050
end_define

begin_comment
comment|/* Receive Interrupt Mask Register (RIMR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_RIMR
value|0x0054
end_define

begin_comment
comment|/* Transmit and Receive Interrupt Mask Register (TRIMR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_TRIMR
value|0x0058
end_define

begin_comment
comment|/* SMI Control Register (SMICR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_SMICR
value|0x0080
end_define

begin_define
define|#
directive|define
name|YU_SMICR_PHYAD
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 11)
end_define

begin_define
define|#
directive|define
name|YU_SMICR_REGAD
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 6)
end_define

begin_define
define|#
directive|define
name|YU_SMICR_OPCODE
value|0x0020
end_define

begin_comment
comment|/* opcode (0 - write, 1 - read) */
end_comment

begin_define
define|#
directive|define
name|YU_SMICR_OP_READ
value|0x0020
end_define

begin_comment
comment|/* opcode read */
end_comment

begin_define
define|#
directive|define
name|YU_SMICR_OP_WRITE
value|0x0000
end_define

begin_comment
comment|/* opcode write */
end_comment

begin_define
define|#
directive|define
name|YU_SMICR_READ_VALID
value|0x0010
end_define

begin_comment
comment|/* read valid */
end_comment

begin_define
define|#
directive|define
name|YU_SMICR_BUSY
value|0x0008
end_define

begin_comment
comment|/* busy (writing) */
end_comment

begin_comment
comment|/* SMI Data Register (SMIDR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_SMIDR
value|0x0084
end_define

begin_comment
comment|/* PHY Addres Register (PAR) */
end_comment

begin_define
define|#
directive|define
name|YUKON_PAR
value|0x0088
end_define

begin_define
define|#
directive|define
name|YU_PAR_MIB_CLR
value|0x0020
end_define

begin_comment
comment|/* MIB Counters Clear Mode */
end_comment

begin_define
define|#
directive|define
name|YU_PAR_LOAD_TSTCNT
value|0x0010
end_define

begin_comment
comment|/* Load count 0xfffffff0 into cntr */
end_comment

end_unit


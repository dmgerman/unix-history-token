begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Benno Rice.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_SMCREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_SMCREG_H_
end_define

begin_comment
comment|/* All Banks, Offset 0xe: Bank Select Register */
end_comment

begin_define
define|#
directive|define
name|BSR
value|0xe
end_define

begin_define
define|#
directive|define
name|BSR_BANK_MASK
value|0x0007
end_define

begin_comment
comment|/* Which bank is currently selected */
end_comment

begin_define
define|#
directive|define
name|BSR_IDENTIFY
value|0x3300
end_define

begin_comment
comment|/* Static value for identification */
end_comment

begin_define
define|#
directive|define
name|BSR_IDENTIFY_MASK
value|0xff00
end_define

begin_comment
comment|/* Bank 0, Offset 0x0: Transmit Control Register */
end_comment

begin_define
define|#
directive|define
name|TCR
value|0x0
end_define

begin_define
define|#
directive|define
name|TCR_TXENA
value|0x0001
end_define

begin_comment
comment|/* Enable/disable transmitter */
end_comment

begin_define
define|#
directive|define
name|TCR_LOOP
value|0x0002
end_define

begin_comment
comment|/* Put the PHY into loopback mode */
end_comment

begin_define
define|#
directive|define
name|TCR_FORCOL
value|0x0004
end_define

begin_comment
comment|/* Force a collision */
end_comment

begin_define
define|#
directive|define
name|TCR_PAD_EN
value|0x0080
end_define

begin_comment
comment|/* Pad TX frames to 64 bytes */
end_comment

begin_define
define|#
directive|define
name|TCR_NOCRC
value|0x0100
end_define

begin_comment
comment|/* Disable/enable CRC */
end_comment

begin_define
define|#
directive|define
name|TCR_MON_CSN
value|0x0400
end_define

begin_comment
comment|/* Monitor carrier signal */
end_comment

begin_define
define|#
directive|define
name|TCR_FDUPLX
value|0x0800
end_define

begin_comment
comment|/* Enable/disable full duplex */
end_comment

begin_define
define|#
directive|define
name|TCR_STP_SQET
value|0x1000
end_define

begin_comment
comment|/* Stop TX on signal quality error */
end_comment

begin_define
define|#
directive|define
name|TCR_EPH_LOOP
value|0x2000
end_define

begin_comment
comment|/* Internal loopback */
end_comment

begin_define
define|#
directive|define
name|TCR_SWFDUP
value|0x8000
end_define

begin_comment
comment|/* Switched full duplex */
end_comment

begin_comment
comment|/* Bank 0, Offset 0x2: EPH Status Register */
end_comment

begin_define
define|#
directive|define
name|EPHSR
value|0x2
end_define

begin_define
define|#
directive|define
name|EPHSR_TX_SUC
value|0x0001
end_define

begin_comment
comment|/* Last TX was successful */
end_comment

begin_define
define|#
directive|define
name|EPHSR_SNGLCOL
value|0x0002
end_define

begin_comment
comment|/* Single collision on last TX */
end_comment

begin_define
define|#
directive|define
name|EPHSR_MULCOL
value|0x0004
end_define

begin_comment
comment|/* Multiple collisions on last TX */
end_comment

begin_define
define|#
directive|define
name|EPHSR_LTX_MULT
value|0x0008
end_define

begin_comment
comment|/* Last TX was multicast */
end_comment

begin_define
define|#
directive|define
name|EPHSR_16COL
value|0x0010
end_define

begin_comment
comment|/* 16 collisions on last TX */
end_comment

begin_define
define|#
directive|define
name|EPHSR_SQET
value|0x0020
end_define

begin_comment
comment|/* Signal quality error test */
end_comment

begin_define
define|#
directive|define
name|EPHSR_LTX_BRD
value|0x0040
end_define

begin_comment
comment|/* Last TX was broadcast */
end_comment

begin_define
define|#
directive|define
name|EPHSR_TX_DEFR
value|0x0080
end_define

begin_comment
comment|/* Transmit deferred */
end_comment

begin_define
define|#
directive|define
name|EPHSR_LATCOL
value|0x0200
end_define

begin_comment
comment|/* Late collision on last TX */
end_comment

begin_define
define|#
directive|define
name|EPHSR_LOST_CARR
value|0x0400
end_define

begin_comment
comment|/* Lost carrier sense */
end_comment

begin_define
define|#
directive|define
name|EPHSR_EXC_DEF
value|0x0800
end_define

begin_comment
comment|/* Excessive deferral */
end_comment

begin_define
define|#
directive|define
name|EPHSR_CTR_ROL
value|0x1000
end_define

begin_comment
comment|/* Counter rollover */
end_comment

begin_define
define|#
directive|define
name|EPHSR_LINK_OK
value|0x4000
end_define

begin_comment
comment|/* Inverse of nLNK pin */
end_comment

begin_define
define|#
directive|define
name|EPHSR_TXUNRN
value|0x8000
end_define

begin_comment
comment|/* Transmit underrun */
end_comment

begin_comment
comment|/* Bank 0, Offset 0x4: Receive Control Register */
end_comment

begin_define
define|#
directive|define
name|RCR
value|0x4
end_define

begin_define
define|#
directive|define
name|RCR_RX_ABORT
value|0x0001
end_define

begin_comment
comment|/* RX aborted */
end_comment

begin_define
define|#
directive|define
name|RCR_PRMS
value|0x0002
end_define

begin_comment
comment|/* Enable/disable promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|RCR_ALMUL
value|0x0004
end_define

begin_comment
comment|/* Accept all multicast frames */
end_comment

begin_define
define|#
directive|define
name|RCR_RXEN
value|0x0100
end_define

begin_comment
comment|/* Enable/disable receiver */
end_comment

begin_define
define|#
directive|define
name|RCR_STRIP_CRC
value|0x0200
end_define

begin_comment
comment|/* Strip CRC from RX packets */
end_comment

begin_define
define|#
directive|define
name|RCR_ABORT_ENB
value|0x2000
end_define

begin_comment
comment|/* Abort RX on collision */
end_comment

begin_define
define|#
directive|define
name|RCR_FILT_CAR
value|0x4000
end_define

begin_comment
comment|/* Filter leading 12 bits of carrier */
end_comment

begin_define
define|#
directive|define
name|RCR_SOFT_RST
value|0x8000
end_define

begin_comment
comment|/* Software reset */
end_comment

begin_comment
comment|/* Bank 0, Offset 0x6: Counter Register */
end_comment

begin_define
define|#
directive|define
name|ECR
value|0x6
end_define

begin_define
define|#
directive|define
name|ECR_SNGLCOL_MASK
value|0x000f
end_define

begin_comment
comment|/* Single collisions */
end_comment

begin_define
define|#
directive|define
name|ECR_SNGLCOL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ECR_MULCOL_MASK
value|0x00f0
end_define

begin_comment
comment|/* Multiple collisions */
end_comment

begin_define
define|#
directive|define
name|ECR_MULCOL_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ECR_TX_DEFR_MASK
value|0x0f00
end_define

begin_comment
comment|/* Transmit deferrals */
end_comment

begin_define
define|#
directive|define
name|ECR_TX_DEFR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ECR_EXC_DEF_MASK
value|0xf000
end_define

begin_comment
comment|/* Excessive deferrals */
end_comment

begin_define
define|#
directive|define
name|ECR_EXC_DEF_SHIFT
value|12
end_define

begin_comment
comment|/* Bank 0, Offset 0x8: Memory Information Register */
end_comment

begin_define
define|#
directive|define
name|MIR
value|0x8
end_define

begin_define
define|#
directive|define
name|MIR_SIZE_MASK
value|0x00ff
end_define

begin_comment
comment|/* Memory size (2k pages) */
end_comment

begin_define
define|#
directive|define
name|MIR_SIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MIR_FREE_MASK
value|0xff00
end_define

begin_comment
comment|/* Memory free (2k pages) */
end_comment

begin_define
define|#
directive|define
name|MIR_FREE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MIR_PAGE_SIZE
value|2048
end_define

begin_comment
comment|/* Bank 0, Offset 0xa: Receive/PHY Control Reigster */
end_comment

begin_define
define|#
directive|define
name|RPCR
value|0xa
end_define

begin_define
define|#
directive|define
name|RPCR_ANEG
value|0x0800
end_define

begin_comment
comment|/* Put PHY in autonegotiation mode */
end_comment

begin_define
define|#
directive|define
name|RPCR_DPLX
value|0x1000
end_define

begin_comment
comment|/* Put PHY in full-duplex mode */
end_comment

begin_define
define|#
directive|define
name|RPCR_SPEED
value|0x2000
end_define

begin_comment
comment|/* Manual speed selection */
end_comment

begin_define
define|#
directive|define
name|RPCR_LSA_MASK
value|0x00e0
end_define

begin_comment
comment|/* Select LED A function */
end_comment

begin_define
define|#
directive|define
name|RPCR_LSA_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|RPCR_LSB_MASK
value|0x001c
end_define

begin_comment
comment|/* Select LED B function */
end_comment

begin_define
define|#
directive|define
name|RPCR_LSB_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|RPCR_LED_LINK_ANY
value|0x0
end_define

begin_comment
comment|/* 10baseT or 100baseTX link detected */
end_comment

begin_define
define|#
directive|define
name|RPCR_LED_LINK_10
value|0x2
end_define

begin_comment
comment|/* 10baseT link detected */
end_comment

begin_define
define|#
directive|define
name|RPCR_LED_LINK_FDX
value|0x3
end_define

begin_comment
comment|/* Full-duplex link detected */
end_comment

begin_define
define|#
directive|define
name|RPCR_LED_LINK_100
value|0x5
end_define

begin_comment
comment|/* 100baseTX link detected */
end_comment

begin_define
define|#
directive|define
name|RPCR_LED_ACT_ANY
value|0x4
end_define

begin_comment
comment|/* TX or RX activity detected */
end_comment

begin_define
define|#
directive|define
name|RPCR_LED_ACT_RX
value|0x6
end_define

begin_comment
comment|/* RX activity detected */
end_comment

begin_define
define|#
directive|define
name|RPCR_LED_ACT_TX
value|0x7
end_define

begin_comment
comment|/* TX activity detected */
end_comment

begin_comment
comment|/* Bank 1, Offset 0x0: Configuration Register */
end_comment

begin_define
define|#
directive|define
name|CR
value|0x0
end_define

begin_define
define|#
directive|define
name|CR_EXT_PHY
value|0x0200
end_define

begin_comment
comment|/* Enable/disable external PHY */
end_comment

begin_define
define|#
directive|define
name|CR_GPCNTRL
value|0x0400
end_define

begin_comment
comment|/* Inverse drives nCNTRL pin */
end_comment

begin_define
define|#
directive|define
name|CR_NO_WAIT
value|0x1000
end_define

begin_comment
comment|/* Do not request additional waits */
end_comment

begin_define
define|#
directive|define
name|CR_EPH_POWER_EN
value|0x8000
end_define

begin_comment
comment|/* Disable/enable low power mode */
end_comment

begin_comment
comment|/* Bank 1, Offset 0x2: Base Address Register */
end_comment

begin_define
define|#
directive|define
name|BAR
value|0x2
end_define

begin_define
define|#
directive|define
name|BAR_HIGH_MASK
value|0xe000
end_define

begin_define
define|#
directive|define
name|BAR_LOW_MASK
value|0x1f00
end_define

begin_define
define|#
directive|define
name|BAR_LOW_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BAR_ADDRESS
parameter_list|(
name|val
parameter_list|)
define|\
value|((val& BAR_HIGH_MASK) | ((val& BAR_LOW_MASK)>> BAR_LOW_SHIFT))
end_define

begin_comment
comment|/* Bank 1, Offsets 0x4: Individual Address Registers */
end_comment

begin_define
define|#
directive|define
name|IAR0
value|0x4
end_define

begin_define
define|#
directive|define
name|IAR1
value|0x5
end_define

begin_define
define|#
directive|define
name|IAR2
value|0x6
end_define

begin_define
define|#
directive|define
name|IAR3
value|0x7
end_define

begin_define
define|#
directive|define
name|IAR4
value|0x8
end_define

begin_define
define|#
directive|define
name|IAR5
value|0x9
end_define

begin_comment
comment|/* Bank 1, Offset 0xa: General Purpose Register */
end_comment

begin_define
define|#
directive|define
name|GPR
value|0xa
end_define

begin_comment
comment|/* Bank 1, Offset 0xc: Control Register */
end_comment

begin_define
define|#
directive|define
name|CTR
value|0xa
end_define

begin_define
define|#
directive|define
name|CTR_STORE
value|0x0001
end_define

begin_comment
comment|/* Store registers to EEPROM */
end_comment

begin_define
define|#
directive|define
name|CTR_RELOAD
value|0x0002
end_define

begin_comment
comment|/* Reload registers from EEPROM */
end_comment

begin_define
define|#
directive|define
name|CTR_EEPROM_SELECT
value|0x0004
end_define

begin_comment
comment|/* Select registers to store/reload */
end_comment

begin_define
define|#
directive|define
name|CTR_TE_ENABLE
value|0x0020
end_define

begin_comment
comment|/* TX error causes EPH interrupt */
end_comment

begin_define
define|#
directive|define
name|CTR_CR_ENABLE
value|0x0040
end_define

begin_comment
comment|/* Ctr rollover causes EPH interrupt */
end_comment

begin_define
define|#
directive|define
name|CTR_LE_ENABLE
value|0x0080
end_define

begin_comment
comment|/* Link error causes EPH interrupt */
end_comment

begin_define
define|#
directive|define
name|CTR_AUTO_RELEASE
value|0x0800
end_define

begin_comment
comment|/* Automatically release TX packets */
end_comment

begin_define
define|#
directive|define
name|CTR_RCV_BAD
value|0x4000
end_define

begin_comment
comment|/* Receive/discard bad CRC packets */
end_comment

begin_comment
comment|/* Bank 2, Offset 0x0: MMU Command Register */
end_comment

begin_define
define|#
directive|define
name|MMUCR
value|0x0
end_define

begin_define
define|#
directive|define
name|MMUCR_BUSY
value|0x0001
end_define

begin_comment
comment|/* MMU is busy */
end_comment

begin_define
define|#
directive|define
name|MMUCR_CMD_NOOP
value|(0<<5)
end_define

begin_comment
comment|/* No operation */
end_comment

begin_define
define|#
directive|define
name|MMUCR_CMD_TX_ALLOC
value|(1<<5)
end_define

begin_comment
comment|/* Alloc TX memory (256b chunks) */
end_comment

begin_define
define|#
directive|define
name|MMUCR_CMD_MMU_RESET
value|(2<<5)
end_define

begin_comment
comment|/* Reset MMU */
end_comment

begin_define
define|#
directive|define
name|MMUCR_CMD_REMOVE
value|(3<<5)
end_define

begin_comment
comment|/* Remove frame from RX FIFO */
end_comment

begin_define
define|#
directive|define
name|MMUCR_CMD_RELEASE
value|(4<<5)
end_define

begin_comment
comment|/* Remove and release from RX FIFO */
end_comment

begin_define
define|#
directive|define
name|MMUCR_CMD_RELEASE_PKT
value|(5<<5)
end_define

begin_comment
comment|/* Release packet specified in PNR */
end_comment

begin_define
define|#
directive|define
name|MMUCR_CMD_ENQUEUE
value|(6<<5)
end_define

begin_comment
comment|/* Enqueue packet for TX */
end_comment

begin_define
define|#
directive|define
name|MMUCR_CMD_TX_RESET
value|(7<<5)
end_define

begin_comment
comment|/* Reset TX FIFOs */
end_comment

begin_comment
comment|/* Bank 2, Offset 0x2: Packet Number Register */
end_comment

begin_define
define|#
directive|define
name|PNR
value|0x2
end_define

begin_define
define|#
directive|define
name|PNR_MASK
value|0x3fff
end_define

begin_comment
comment|/* Bank 2, Offset 0x3: Allocation Result Register */
end_comment

begin_define
define|#
directive|define
name|ARR
value|0x3
end_define

begin_define
define|#
directive|define
name|ARR_FAILED
value|0x8000
end_define

begin_comment
comment|/* Last allocation request failed */
end_comment

begin_define
define|#
directive|define
name|ARR_MASK
value|0x3000
end_define

begin_comment
comment|/* Bank 2, Offset 0x4: FIFO Ports Register */
end_comment

begin_define
define|#
directive|define
name|FIFO_TX
value|0x4
end_define

begin_define
define|#
directive|define
name|FIFO_RX
value|0x5
end_define

begin_define
define|#
directive|define
name|FIFO_EMPTY
value|0x80
end_define

begin_comment
comment|/* FIFO empty */
end_comment

begin_define
define|#
directive|define
name|FIFO_PACKET_MASK
value|0x3f
end_define

begin_comment
comment|/* Packet number mask */
end_comment

begin_comment
comment|/* Bank 2, Offset 0x6: Pointer Register */
end_comment

begin_define
define|#
directive|define
name|PTR
value|0x6
end_define

begin_define
define|#
directive|define
name|PTR_MASK
value|0x07ff
end_define

begin_comment
comment|/* Address accessible within TX/RX */
end_comment

begin_define
define|#
directive|define
name|PTR_NOT_EMPTY
value|0x0800
end_define

begin_comment
comment|/* Write Data FIFO not empty */
end_comment

begin_define
define|#
directive|define
name|PTR_ETEN
value|0x1000
end_define

begin_comment
comment|/* Enable early TX underrun detection */
end_comment

begin_define
define|#
directive|define
name|PTR_READ
value|0x2000
end_define

begin_comment
comment|/* Set read/write */
end_comment

begin_define
define|#
directive|define
name|PTR_AUTO_INCR
value|0x4000
end_define

begin_comment
comment|/* Auto increment on read/write */
end_comment

begin_define
define|#
directive|define
name|PTR_RCV
value|0x8000
end_define

begin_comment
comment|/* Read/write to/from RX/TX */
end_comment

begin_comment
comment|/* Bank 2, Offset 0x8: Data Registers */
end_comment

begin_define
define|#
directive|define
name|DATA0
value|0x8
end_define

begin_define
define|#
directive|define
name|DATA1
value|0xa
end_define

begin_comment
comment|/* Bank 2, Offset 0xc: Interrupt Status Registers */
end_comment

begin_define
define|#
directive|define
name|IST
value|0xc
end_define

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|ACK
value|0xc
end_define

begin_comment
comment|/* write only */
end_comment

begin_define
define|#
directive|define
name|MSK
value|0xd
end_define

begin_define
define|#
directive|define
name|RCV_INT
value|0x0001
end_define

begin_comment
comment|/* RX */
end_comment

begin_define
define|#
directive|define
name|TX_INT
value|0x0002
end_define

begin_comment
comment|/* TX */
end_comment

begin_define
define|#
directive|define
name|TX_EMPTY_INT
value|0x0004
end_define

begin_comment
comment|/* TX empty */
end_comment

begin_define
define|#
directive|define
name|ALLOC_INT
value|0x0008
end_define

begin_comment
comment|/* Allocation complete */
end_comment

begin_define
define|#
directive|define
name|RX_OVRN_INT
value|0x0010
end_define

begin_comment
comment|/* RX overrun */
end_comment

begin_define
define|#
directive|define
name|EPH_INT
value|0x0020
end_define

begin_comment
comment|/* EPH interrupt */
end_comment

begin_define
define|#
directive|define
name|ERCV_INT
value|0x0040
end_define

begin_comment
comment|/* Early RX */
end_comment

begin_define
define|#
directive|define
name|MD_INT
value|0x0080
end_define

begin_comment
comment|/* MII */
end_comment

begin_define
define|#
directive|define
name|IST_PRINTF
value|"\20\01RCV\02TX\03TX_EMPTY\04ALLOC" \ 				"\05RX_OVRN\06EPH\07ERCV\10MD"
end_define

begin_comment
comment|/* Bank 3, Offset 0x0: Multicast Table Registers */
end_comment

begin_define
define|#
directive|define
name|MT
value|0x0
end_define

begin_comment
comment|/* Bank 3, Offset 0x8: Management Interface */
end_comment

begin_define
define|#
directive|define
name|MGMT
value|0x8
end_define

begin_define
define|#
directive|define
name|MGMT_MDO
value|0x0001
end_define

begin_comment
comment|/* MII management output */
end_comment

begin_define
define|#
directive|define
name|MGMT_MDI
value|0x0002
end_define

begin_comment
comment|/* MII management input */
end_comment

begin_define
define|#
directive|define
name|MGMT_MCLK
value|0x0004
end_define

begin_comment
comment|/* MII management clock */
end_comment

begin_define
define|#
directive|define
name|MGMT_MDOE
value|0x0008
end_define

begin_comment
comment|/* MII management output enable */
end_comment

begin_define
define|#
directive|define
name|MGMT_MSK_CRS100
value|0x4000
end_define

begin_comment
comment|/* Disable CRS100 detection during TX */
end_comment

begin_comment
comment|/* Bank 3, Offset 0xa: Revision Register */
end_comment

begin_define
define|#
directive|define
name|REV
value|0xa
end_define

begin_define
define|#
directive|define
name|REV_CHIP_MASK
value|0x00f0
end_define

begin_comment
comment|/* Chip ID */
end_comment

begin_define
define|#
directive|define
name|REV_CHIP_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|REV_REV_MASK
value|0x000f
end_define

begin_comment
comment|/* Revision ID */
end_comment

begin_define
define|#
directive|define
name|REV_REV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|REV_CHIP_9192
value|3
end_define

begin_define
define|#
directive|define
name|REV_CHIP_9194
value|4
end_define

begin_define
define|#
directive|define
name|REV_CHIP_9195
value|5
end_define

begin_define
define|#
directive|define
name|REV_CHIP_9196
value|6
end_define

begin_define
define|#
directive|define
name|REV_CHIP_91100
value|7
end_define

begin_define
define|#
directive|define
name|REV_CHIP_91100FD
value|8
end_define

begin_define
define|#
directive|define
name|REV_CHIP_91110FD
value|9
end_define

begin_comment
comment|/* Bank 3, Offset 0xc: Early RCV Register */
end_comment

begin_define
define|#
directive|define
name|ERCV
value|0xc
end_define

begin_define
define|#
directive|define
name|ERCV_THRESHOLD_MASK
value|0x001f
end_define

begin_comment
comment|/* ERCV int threshold (64b chunks) */
end_comment

begin_define
define|#
directive|define
name|ERCV_RCV_DISCARD
value|0x0080
end_define

begin_comment
comment|/* Discard packet being received */
end_comment

begin_comment
comment|/* Control Byte */
end_comment

begin_define
define|#
directive|define
name|CTRL_CRC
value|0x10
end_define

begin_comment
comment|/* Frame has CRC */
end_comment

begin_define
define|#
directive|define
name|CTRL_ODD
value|0x20
end_define

begin_comment
comment|/* Frame has odd byte count */
end_comment

begin_comment
comment|/* Receive Frame Status */
end_comment

begin_define
define|#
directive|define
name|RX_MULTCAST
value|0x0001
end_define

begin_comment
comment|/* Frame was multicast */
end_comment

begin_define
define|#
directive|define
name|RX_HASH_MASK
value|0x007e
end_define

begin_comment
comment|/* Hash value for multicast */
end_comment

begin_define
define|#
directive|define
name|RX_HASH_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|RX_TOOSHORT
value|0x0400
end_define

begin_comment
comment|/* Frame was too short */
end_comment

begin_define
define|#
directive|define
name|RX_TOOLNG
value|0x0800
end_define

begin_comment
comment|/* Frame was too long */
end_comment

begin_define
define|#
directive|define
name|RX_ODDFRM
value|0x1000
end_define

begin_comment
comment|/* Frame has odd number of bytes */
end_comment

begin_define
define|#
directive|define
name|RX_BADCRC
value|0x2000
end_define

begin_comment
comment|/* Frame failed CRC */
end_comment

begin_define
define|#
directive|define
name|RX_BROADCAST
value|0x4000
end_define

begin_comment
comment|/* Frame was broadcast */
end_comment

begin_define
define|#
directive|define
name|RX_ALGNERR
value|0x8000
end_define

begin_comment
comment|/* Frame had alignment error */
end_comment

begin_define
define|#
directive|define
name|RX_LEN_MASK
value|0x07ff
end_define

begin_comment
comment|/* Length of status word + byte count + control bytes for packets */
end_comment

begin_define
define|#
directive|define
name|PKT_CTRL_DATA_LEN
value|6
end_define

begin_comment
comment|/* Number of times to spin on TX allocations */
end_comment

begin_define
define|#
directive|define
name|TX_ALLOC_WAIT_TIME
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_SMCREG_H_ */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Stuart Walsh  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS 'AS IS' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BFE_H
end_ifndef

begin_define
define|#
directive|define
name|_BFE_H
end_define

begin_comment
comment|/* PCI registers */
end_comment

begin_define
define|#
directive|define
name|BFE_PCI_MEMLO
value|0x10
end_define

begin_define
define|#
directive|define
name|BFE_PCI_MEMHIGH
value|0x14
end_define

begin_define
define|#
directive|define
name|BFE_PCI_INTLINE
value|0x3C
end_define

begin_comment
comment|/* Register layout. */
end_comment

begin_define
define|#
directive|define
name|BFE_DEVCTRL
value|0x00000000
end_define

begin_comment
comment|/* Device Control */
end_comment

begin_define
define|#
directive|define
name|BFE_PFE
value|0x00000080
end_define

begin_comment
comment|/* Pattern Filtering Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_IPP
value|0x00000400
end_define

begin_comment
comment|/* Internal EPHY Present */
end_comment

begin_define
define|#
directive|define
name|BFE_EPR
value|0x00008000
end_define

begin_comment
comment|/* EPHY Reset */
end_comment

begin_define
define|#
directive|define
name|BFE_PME
value|0x00001000
end_define

begin_comment
comment|/* PHY Mode Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_PMCE
value|0x00002000
end_define

begin_comment
comment|/* PHY Mode Clocks Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_PADDR
value|0x0007c000
end_define

begin_comment
comment|/* PHY Address */
end_comment

begin_define
define|#
directive|define
name|BFE_PADDR_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|BFE_BIST_STAT
value|0x0000000C
end_define

begin_comment
comment|/* Built-In Self-Test Status */
end_comment

begin_define
define|#
directive|define
name|BFE_WKUP_LEN
value|0x00000010
end_define

begin_comment
comment|/* Wakeup Length */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT
value|0x00000020
end_define

begin_comment
comment|/* Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_PME
value|0x00000040
end_define

begin_comment
comment|/* Power Management Event */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_TO
value|0x00000080
end_define

begin_comment
comment|/* General Purpose Timeout */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_DSCE
value|0x00000400
end_define

begin_comment
comment|/* Descriptor Error */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_DATAE
value|0x00000800
end_define

begin_comment
comment|/* Data Error */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_DPE
value|0x00001000
end_define

begin_comment
comment|/* Descr. Protocol Error */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_RDU
value|0x00002000
end_define

begin_comment
comment|/* Receive Descr. Underflow */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_RFO
value|0x00004000
end_define

begin_comment
comment|/* Receive FIFO Overflow */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_TFU
value|0x00008000
end_define

begin_comment
comment|/* Transmit FIFO Underflow */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_RX
value|0x00010000
end_define

begin_comment
comment|/* RX Interrupt */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_TX
value|0x01000000
end_define

begin_comment
comment|/* TX Interrupt */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_EMAC
value|0x04000000
end_define

begin_comment
comment|/* EMAC Interrupt */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_MII_WRITE
value|0x08000000
end_define

begin_comment
comment|/* MII Write Interrupt */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_MII_READ
value|0x10000000
end_define

begin_comment
comment|/* MII Read Interrupt */
end_comment

begin_define
define|#
directive|define
name|BFE_ISTAT_ERRORS
value|(BFE_ISTAT_DSCE | BFE_ISTAT_DATAE | BFE_ISTAT_DPE |\ 	BFE_ISTAT_RDU | BFE_ISTAT_RFO | BFE_ISTAT_TFU)
end_define

begin_define
define|#
directive|define
name|BFE_IMASK
value|0x00000024
end_define

begin_comment
comment|/* Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_IMASK_DEF
value|(BFE_ISTAT_ERRORS | BFE_ISTAT_TO | BFE_ISTAT_RX | \ 	BFE_ISTAT_TX)
end_define

begin_define
define|#
directive|define
name|BFE_MAC_CTRL
value|0x000000A8
end_define

begin_comment
comment|/* MAC Control */
end_comment

begin_define
define|#
directive|define
name|BFE_CTRL_CRC32_ENAB
value|0x00000001
end_define

begin_comment
comment|/* CRC32 Generation Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_CTRL_PDOWN
value|0x00000004
end_define

begin_comment
comment|/* Onchip EPHY Powerdown */
end_comment

begin_define
define|#
directive|define
name|BFE_CTRL_EDET
value|0x00000008
end_define

begin_comment
comment|/* Onchip EPHY Energy Detected */
end_comment

begin_define
define|#
directive|define
name|BFE_CTRL_LED
value|0x000000e0
end_define

begin_comment
comment|/* Onchip EPHY LED Control */
end_comment

begin_define
define|#
directive|define
name|BFE_CTRL_LED_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|BFE_RCV_LAZY
value|0x00000100
end_define

begin_comment
comment|/* Lazy Interrupt Control */
end_comment

begin_define
define|#
directive|define
name|BFE_LAZY_TO_MASK
value|0x00ffffff
end_define

begin_comment
comment|/* Timeout */
end_comment

begin_define
define|#
directive|define
name|BFE_LAZY_FC_MASK
value|0xff000000
end_define

begin_comment
comment|/* Frame Count */
end_comment

begin_define
define|#
directive|define
name|BFE_LAZY_FC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BFE_DMATX_CTRL
value|0x00000200
end_define

begin_comment
comment|/* DMA TX Control */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_CTRL_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_CTRL_SUSPEND
value|0x00000002
end_define

begin_comment
comment|/* Suepend Request */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_CTRL_LPBACK
value|0x00000004
end_define

begin_comment
comment|/* Loopback Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_CTRL_FAIRPRI
value|0x00000008
end_define

begin_comment
comment|/* Fair Priority */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_CTRL_FLUSH
value|0x00000010
end_define

begin_comment
comment|/* Flush Request */
end_comment

begin_define
define|#
directive|define
name|BFE_DMATX_ADDR
value|0x00000204
end_define

begin_comment
comment|/* DMA TX Descriptor Ring Address */
end_comment

begin_define
define|#
directive|define
name|BFE_DMATX_PTR
value|0x00000208
end_define

begin_comment
comment|/* DMA TX Last Posted Descriptor */
end_comment

begin_define
define|#
directive|define
name|BFE_DMATX_STAT
value|0x0000020C
end_define

begin_comment
comment|/* DMA TX Current Active Desc. + Status */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_CDMASK
value|0x00000fff
end_define

begin_comment
comment|/* Current Descriptor Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_SMASK
value|0x0000f000
end_define

begin_comment
comment|/* State Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_DISABLE
value|0x00000000
end_define

begin_comment
comment|/* State Disabled */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_SACTIVE
value|0x00001000
end_define

begin_comment
comment|/* State Active */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_SIDLE
value|0x00002000
end_define

begin_comment
comment|/* State Idle Wait */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_STOPPED
value|0x00003000
end_define

begin_comment
comment|/* State Stopped */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_SSUSP
value|0x00004000
end_define

begin_comment
comment|/* State Suspend Pending */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_EMASK
value|0x000f0000
end_define

begin_comment
comment|/* Error Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_ENONE
value|0x00000000
end_define

begin_comment
comment|/* Error None */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_EDPE
value|0x00010000
end_define

begin_comment
comment|/* Error Desc. Protocol Error */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_EDFU
value|0x00020000
end_define

begin_comment
comment|/* Error Data FIFO Underrun */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_EBEBR
value|0x00030000
end_define

begin_comment
comment|/* Error Bus Error on Buffer Read */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_EBEDA
value|0x00040000
end_define

begin_comment
comment|/* Error Bus Error on Desc. Access */
end_comment

begin_define
define|#
directive|define
name|BFE_STAT_FLUSHED
value|0x00100000
end_define

begin_comment
comment|/* Flushed */
end_comment

begin_define
define|#
directive|define
name|BFE_DMARX_CTRL
value|0x00000210
end_define

begin_comment
comment|/* DMA RX Control */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_CTRL_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_CTRL_ROMASK
value|0x000000fe
end_define

begin_comment
comment|/* Receive Offset Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_CTRL_ROSHIFT
value|1
end_define

begin_comment
comment|/* Receive Offset Shift */
end_comment

begin_define
define|#
directive|define
name|BFE_DMARX_ADDR
value|0x00000214
end_define

begin_comment
comment|/* DMA RX Descriptor Ring Address */
end_comment

begin_define
define|#
directive|define
name|BFE_DMARX_PTR
value|0x00000218
end_define

begin_comment
comment|/* DMA RX Last Posted Descriptor */
end_comment

begin_define
define|#
directive|define
name|BFE_DMARX_STAT
value|0x0000021C
end_define

begin_comment
comment|/* DMA RX Current Active Desc. + Status */
end_comment

begin_define
define|#
directive|define
name|BFE_RXCONF
value|0x00000400
end_define

begin_comment
comment|/* EMAC RX Config */
end_comment

begin_define
define|#
directive|define
name|BFE_RXCONF_DBCAST
value|0x00000001
end_define

begin_comment
comment|/* Disable Broadcast */
end_comment

begin_define
define|#
directive|define
name|BFE_RXCONF_ALLMULTI
value|0x00000002
end_define

begin_comment
comment|/* Accept All Multicast */
end_comment

begin_define
define|#
directive|define
name|BFE_RXCONF_NORXTX
value|0x00000004
end_define

begin_comment
comment|/* Receive Disable While Transmitting */
end_comment

begin_define
define|#
directive|define
name|BFE_RXCONF_PROMISC
value|0x00000008
end_define

begin_comment
comment|/* Promiscuous Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_RXCONF_LPBACK
value|0x00000010
end_define

begin_comment
comment|/* Loopback Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_RXCONF_FLOW
value|0x00000020
end_define

begin_comment
comment|/* Flow Control Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_RXCONF_ACCEPT
value|0x00000040
end_define

begin_comment
comment|/* Accept Unicast Flow Control Frame */
end_comment

begin_define
define|#
directive|define
name|BFE_RXCONF_RFILT
value|0x00000080
end_define

begin_comment
comment|/* Reject Filter */
end_comment

begin_define
define|#
directive|define
name|BFE_RXMAXLEN
value|0x00000404
end_define

begin_comment
comment|/* EMAC RX Max Packet Length */
end_comment

begin_define
define|#
directive|define
name|BFE_TXMAXLEN
value|0x00000408
end_define

begin_comment
comment|/* EMAC TX Max Packet Length */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_CTRL
value|0x00000410
end_define

begin_comment
comment|/* EMAC MDIO Control */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_MAXF_MASK
value|0x0000007f
end_define

begin_comment
comment|/* MDC Frequency */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_PREAMBLE
value|0x00000080
end_define

begin_comment
comment|/* MII Preamble Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_DATA
value|0x00000414
end_define

begin_comment
comment|/* EMAC MDIO Data */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_DATA_DATA
value|0x0000ffff
end_define

begin_comment
comment|/* R/W Data */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_TA_MASK
value|0x00030000
end_define

begin_comment
comment|/* Turnaround Value */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_TA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BFE_MDIO_TA_VALID
value|2
end_define

begin_define
define|#
directive|define
name|BFE_MDIO_RA_MASK
value|0x007c0000
end_define

begin_comment
comment|/* Register Address */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_PMD_MASK
value|0x0f800000
end_define

begin_comment
comment|/* Physical Media Device */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_OP_MASK
value|0x30000000
end_define

begin_comment
comment|/* Opcode */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_SB_MASK
value|0xc0000000
end_define

begin_comment
comment|/* Start Bits */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_SB_START
value|0x40000000
end_define

begin_comment
comment|/* Start Of Frame */
end_comment

begin_define
define|#
directive|define
name|BFE_MDIO_RA_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|BFE_MDIO_PMD_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|BFE_MDIO_OP_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|BFE_MDIO_OP_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|BFE_MDIO_OP_READ
value|2
end_define

begin_define
define|#
directive|define
name|BFE_MDIO_SB_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|BFE_EMAC_IMASK
value|0x00000418
end_define

begin_comment
comment|/* EMAC Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_EMAC_ISTAT
value|0x0000041C
end_define

begin_comment
comment|/* EMAC Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|BFE_EMAC_INT_MII
value|0x00000001
end_define

begin_comment
comment|/* MII MDIO Interrupt */
end_comment

begin_define
define|#
directive|define
name|BFE_EMAC_INT_MIB
value|0x00000002
end_define

begin_comment
comment|/* MIB Interrupt */
end_comment

begin_define
define|#
directive|define
name|BFE_EMAC_INT_FLOW
value|0x00000003
end_define

begin_comment
comment|/* Flow Control Interrupt */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_DATA_LO
value|0x00000420
end_define

begin_comment
comment|/* EMAC CAM Data Low */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_DATA_HI
value|0x00000424
end_define

begin_comment
comment|/* EMAC CAM Data High */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_HI_VALID
value|0x00010000
end_define

begin_comment
comment|/* Valid Bit */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_CTRL
value|0x00000428
end_define

begin_comment
comment|/* EMAC CAM Control */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* CAM Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_MSEL
value|0x00000002
end_define

begin_comment
comment|/* Mask Select */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_READ
value|0x00000004
end_define

begin_comment
comment|/* Read */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_WRITE
value|0x00000008
end_define

begin_comment
comment|/* Read */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_INDEX_MASK
value|0x003f0000
end_define

begin_comment
comment|/* Index Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_BUSY
value|0x80000000
end_define

begin_comment
comment|/* CAM Busy */
end_comment

begin_define
define|#
directive|define
name|BFE_CAM_INDEX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BFE_ENET_CTRL
value|0x0000042C
end_define

begin_comment
comment|/* EMAC ENET Control */
end_comment

begin_define
define|#
directive|define
name|BFE_ENET_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* EMAC Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_ENET_DISABLE
value|0x00000002
end_define

begin_comment
comment|/* EMAC Disable */
end_comment

begin_define
define|#
directive|define
name|BFE_ENET_SRST
value|0x00000004
end_define

begin_comment
comment|/* EMAC Soft Reset */
end_comment

begin_define
define|#
directive|define
name|BFE_ENET_EPSEL
value|0x00000008
end_define

begin_comment
comment|/* External PHY Select */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_CTRL
value|0x00000430
end_define

begin_comment
comment|/* EMAC TX Control */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_DUPLEX
value|0x00000001
end_define

begin_comment
comment|/* Full Duplex */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_FMODE
value|0x00000002
end_define

begin_comment
comment|/* Flow Mode */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_SBENAB
value|0x00000004
end_define

begin_comment
comment|/* Single Backoff Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_SMALL_SLOT
value|0x00000008
end_define

begin_comment
comment|/* Small Slottime */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_WMARK
value|0x00000434
end_define

begin_comment
comment|/* EMAC TX Watermark */
end_comment

begin_define
define|#
directive|define
name|BFE_MIB_CTRL
value|0x00000438
end_define

begin_comment
comment|/* EMAC MIB Control */
end_comment

begin_define
define|#
directive|define
name|BFE_MIB_CLR_ON_READ
value|0x00000001
end_define

begin_comment
comment|/* Autoclear on Read */
end_comment

begin_comment
comment|/* Status registers */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_GOOD_O
value|0x00000500
end_define

begin_comment
comment|/* MIB TX Good Octets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_GOOD_P
value|0x00000504
end_define

begin_comment
comment|/* MIB TX Good Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_O
value|0x00000508
end_define

begin_comment
comment|/* MIB TX Octets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_P
value|0x0000050C
end_define

begin_comment
comment|/* MIB TX Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_BCAST
value|0x00000510
end_define

begin_comment
comment|/* MIB TX Broadcast Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_MCAST
value|0x00000514
end_define

begin_comment
comment|/* MIB TX Multicast Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_64
value|0x00000518
end_define

begin_comment
comment|/* MIB TX<= 64 byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_65_127
value|0x0000051C
end_define

begin_comment
comment|/* MIB TX 65 to 127 byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_128_255
value|0x00000520
end_define

begin_comment
comment|/* MIB TX 128 to 255 byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_256_511
value|0x00000524
end_define

begin_comment
comment|/* MIB TX 256 to 511 byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_512_1023
value|0x00000528
end_define

begin_comment
comment|/* MIB TX 512 to 1023 byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_1024_MAX
value|0x0000052C
end_define

begin_comment
comment|/* MIB TX 1024 to max byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_JABBER
value|0x00000530
end_define

begin_comment
comment|/* MIB TX Jabber Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_OSIZE
value|0x00000534
end_define

begin_comment
comment|/* MIB TX Oversize Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_FRAG
value|0x00000538
end_define

begin_comment
comment|/* MIB TX Fragment Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_URUNS
value|0x0000053C
end_define

begin_comment
comment|/* MIB TX Underruns */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_TCOLS
value|0x00000540
end_define

begin_comment
comment|/* MIB TX Total Collisions */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_SCOLS
value|0x00000544
end_define

begin_comment
comment|/* MIB TX Single Collisions */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_MCOLS
value|0x00000548
end_define

begin_comment
comment|/* MIB TX Multiple Collisions */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_ECOLS
value|0x0000054C
end_define

begin_comment
comment|/* MIB TX Excessive Collisions */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_LCOLS
value|0x00000550
end_define

begin_comment
comment|/* MIB TX Late Collisions */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_DEFERED
value|0x00000554
end_define

begin_comment
comment|/* MIB TX Defered Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_CLOST
value|0x00000558
end_define

begin_comment
comment|/* MIB TX Carrier Lost */
end_comment

begin_define
define|#
directive|define
name|BFE_TX_PAUSE
value|0x0000055C
end_define

begin_comment
comment|/* MIB TX Pause Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_GOOD_O
value|0x00000580
end_define

begin_comment
comment|/* MIB RX Good Octets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_GOOD_P
value|0x00000584
end_define

begin_comment
comment|/* MIB RX Good Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_O
value|0x00000588
end_define

begin_comment
comment|/* MIB RX Octets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_P
value|0x0000058C
end_define

begin_comment
comment|/* MIB RX Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_BCAST
value|0x00000590
end_define

begin_comment
comment|/* MIB RX Broadcast Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_MCAST
value|0x00000594
end_define

begin_comment
comment|/* MIB RX Multicast Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_64
value|0x00000598
end_define

begin_comment
comment|/* MIB RX<= 64 byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_65_127
value|0x0000059C
end_define

begin_comment
comment|/* MIB RX 65 to 127 byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_128_255
value|0x000005A0
end_define

begin_comment
comment|/* MIB RX 128 to 255 byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_256_511
value|0x000005A4
end_define

begin_comment
comment|/* MIB RX 256 to 511 byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_512_1023
value|0x000005A8
end_define

begin_comment
comment|/* MIB RX 512 to 1023 byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_1024_MAX
value|0x000005AC
end_define

begin_comment
comment|/* MIB RX 1024 to max byte Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_JABBER
value|0x000005B0
end_define

begin_comment
comment|/* MIB RX Jabber Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_OSIZE
value|0x000005B4
end_define

begin_comment
comment|/* MIB RX Oversize Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_FRAG
value|0x000005B8
end_define

begin_comment
comment|/* MIB RX Fragment Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_MISS
value|0x000005BC
end_define

begin_comment
comment|/* MIB RX Missed Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_CRCA
value|0x000005C0
end_define

begin_comment
comment|/* MIB RX CRC Align Errors */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_USIZE
value|0x000005C4
end_define

begin_comment
comment|/* MIB RX Undersize Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_CRC
value|0x000005C8
end_define

begin_comment
comment|/* MIB RX CRC Errors */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_ALIGN
value|0x000005CC
end_define

begin_comment
comment|/* MIB RX Align Errors */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_SYM
value|0x000005D0
end_define

begin_comment
comment|/* MIB RX Symbol Errors */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_PAUSE
value|0x000005D4
end_define

begin_comment
comment|/* MIB RX Pause Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_NPAUSE
value|0x000005D8
end_define

begin_comment
comment|/* MIB RX Non-Pause Packets */
end_comment

begin_define
define|#
directive|define
name|BFE_SBIMSTATE
value|0x00000F90
end_define

begin_comment
comment|/* BFE_SB Initiator Agent State */
end_comment

begin_define
define|#
directive|define
name|BFE_PC
value|0x0000000f
end_define

begin_comment
comment|/* Pipe Count */
end_comment

begin_define
define|#
directive|define
name|BFE_AP_MASK
value|0x00000030
end_define

begin_comment
comment|/* Arbitration Priority */
end_comment

begin_define
define|#
directive|define
name|BFE_AP_BOTH
value|0x00000000
end_define

begin_comment
comment|/* Use both timeslices and token */
end_comment

begin_define
define|#
directive|define
name|BFE_AP_TS
value|0x00000010
end_define

begin_comment
comment|/* Use timeslices only */
end_comment

begin_define
define|#
directive|define
name|BFE_AP_TK
value|0x00000020
end_define

begin_comment
comment|/* Use token only */
end_comment

begin_define
define|#
directive|define
name|BFE_AP_RSV
value|0x00000030
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|BFE_IBE
value|0x00020000
end_define

begin_comment
comment|/* In Band Error */
end_comment

begin_define
define|#
directive|define
name|BFE_TO
value|0x00040000
end_define

begin_comment
comment|/* Timeout */
end_comment

begin_comment
comment|/* Seems the bcm440x has a fairly generic core, we only need be concerned with  * a couple of these  */
end_comment

begin_define
define|#
directive|define
name|BFE_SBINTVEC
value|0x00000F94
end_define

begin_comment
comment|/* BFE_SB Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_INTVEC_PCI
value|0x00000001
end_define

begin_comment
comment|/* Enable interrupts for PCI */
end_comment

begin_define
define|#
directive|define
name|BFE_INTVEC_ENET0
value|0x00000002
end_define

begin_comment
comment|/* Enable interrupts for enet 0 */
end_comment

begin_define
define|#
directive|define
name|BFE_INTVEC_ILINE20
value|0x00000004
end_define

begin_comment
comment|/* Enable interrupts for iline20 */
end_comment

begin_define
define|#
directive|define
name|BFE_INTVEC_CODEC
value|0x00000008
end_define

begin_comment
comment|/* Enable interrupts for v90 codec */
end_comment

begin_define
define|#
directive|define
name|BFE_INTVEC_USB
value|0x00000010
end_define

begin_comment
comment|/* Enable interrupts for usb */
end_comment

begin_define
define|#
directive|define
name|BFE_INTVEC_EXTIF
value|0x00000020
end_define

begin_comment
comment|/* Enable interrupts for external i/f */
end_comment

begin_define
define|#
directive|define
name|BFE_INTVEC_ENET1
value|0x00000040
end_define

begin_comment
comment|/* Enable interrupts for enet 1 */
end_comment

begin_define
define|#
directive|define
name|BFE_SBTMSLOW
value|0x00000F98
end_define

begin_comment
comment|/* BFE_SB Target State Low */
end_comment

begin_define
define|#
directive|define
name|BFE_RESET
value|0x00000001
end_define

begin_comment
comment|/* Reset */
end_comment

begin_define
define|#
directive|define
name|BFE_REJECT
value|0x00000002
end_define

begin_comment
comment|/* Reject */
end_comment

begin_define
define|#
directive|define
name|BFE_CLOCK
value|0x00010000
end_define

begin_comment
comment|/* Clock Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_FGC
value|0x00020000
end_define

begin_comment
comment|/* Force Gated Clocks On */
end_comment

begin_define
define|#
directive|define
name|BFE_PE
value|0x40000000
end_define

begin_comment
comment|/* Power Management Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_BE
value|0x80000000
end_define

begin_comment
comment|/* BIST Enable */
end_comment

begin_define
define|#
directive|define
name|BFE_SBTMSHIGH
value|0x00000F9C
end_define

begin_comment
comment|/* BFE_SB Target State High */
end_comment

begin_define
define|#
directive|define
name|BFE_SERR
value|0x00000001
end_define

begin_comment
comment|/* S-error */
end_comment

begin_define
define|#
directive|define
name|BFE_INT
value|0x00000002
end_define

begin_comment
comment|/* Interrupt */
end_comment

begin_define
define|#
directive|define
name|BFE_BUSY
value|0x00000004
end_define

begin_comment
comment|/* Busy */
end_comment

begin_define
define|#
directive|define
name|BFE_GCR
value|0x20000000
end_define

begin_comment
comment|/* Gated Clock Request */
end_comment

begin_define
define|#
directive|define
name|BFE_BISTF
value|0x40000000
end_define

begin_comment
comment|/* BIST Failed */
end_comment

begin_define
define|#
directive|define
name|BFE_BISTD
value|0x80000000
end_define

begin_comment
comment|/* BIST Done */
end_comment

begin_define
define|#
directive|define
name|BFE_SBBWA0
value|0x00000FA0
end_define

begin_comment
comment|/* BFE_SB Bandwidth Allocation Table 0 */
end_comment

begin_define
define|#
directive|define
name|BFE_TAB0_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* Lookup Table 0 */
end_comment

begin_define
define|#
directive|define
name|BFE_TAB1_MASK
value|0xffff0000
end_define

begin_comment
comment|/* Lookup Table 0 */
end_comment

begin_define
define|#
directive|define
name|BFE_TAB0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BFE_TAB1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BFE_SBIMCFGLOW
value|0x00000FA8
end_define

begin_comment
comment|/* BFE_SB Initiator Configuration Low */
end_comment

begin_define
define|#
directive|define
name|BFE_STO_MASK
value|0x00000003
end_define

begin_comment
comment|/* Service Timeout */
end_comment

begin_define
define|#
directive|define
name|BFE_RTO_MASK
value|0x00000030
end_define

begin_comment
comment|/* Request Timeout */
end_comment

begin_define
define|#
directive|define
name|BFE_CID_MASK
value|0x00ff0000
end_define

begin_comment
comment|/* Connection ID */
end_comment

begin_define
define|#
directive|define
name|BFE_RTO_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BFE_CID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BFE_SBIMCFGHIGH
value|0x00000FAC
end_define

begin_comment
comment|/* BFE_SB Initiator Configuration High */
end_comment

begin_define
define|#
directive|define
name|BFE_IEM_MASK
value|0x0000000c
end_define

begin_comment
comment|/* Inband Error Mode */
end_comment

begin_define
define|#
directive|define
name|BFE_TEM_MASK
value|0x00000030
end_define

begin_comment
comment|/* Timeout Error Mode */
end_comment

begin_define
define|#
directive|define
name|BFE_BEM_MASK
value|0x000000c0
end_define

begin_comment
comment|/* Bus Error Mode */
end_comment

begin_define
define|#
directive|define
name|BFE_TEM_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BFE_BEM_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|BFE_SBTMCFGLOW
value|0x00000FB8
end_define

begin_comment
comment|/* BFE_SB Target Configuration Low */
end_comment

begin_define
define|#
directive|define
name|BFE_LOW_CD_MASK
value|0x000000ff
end_define

begin_comment
comment|/* Clock Divide Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_LOW_CO_MASK
value|0x0000f800
end_define

begin_comment
comment|/* Clock Offset Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_LOW_IF_MASK
value|0x00fc0000
end_define

begin_comment
comment|/* Interrupt Flags Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_LOW_IM_MASK
value|0x03000000
end_define

begin_comment
comment|/* Interrupt Mode Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_LOW_CO_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|BFE_LOW_IF_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|BFE_LOW_IM_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BFE_SBTMCFGHIGH
value|0x00000FBC
end_define

begin_comment
comment|/* BFE_SB Target Configuration High */
end_comment

begin_define
define|#
directive|define
name|BFE_HIGH_BM_MASK
value|0x00000003
end_define

begin_comment
comment|/* Busy Mode */
end_comment

begin_define
define|#
directive|define
name|BFE_HIGH_RM_MASK
value|0x0000000C
end_define

begin_comment
comment|/* Retry Mode */
end_comment

begin_define
define|#
directive|define
name|BFE_HIGH_SM_MASK
value|0x00000030
end_define

begin_comment
comment|/* Stop Mode */
end_comment

begin_define
define|#
directive|define
name|BFE_HIGH_EM_MASK
value|0x00000300
end_define

begin_comment
comment|/* Error Mode */
end_comment

begin_define
define|#
directive|define
name|BFE_HIGH_IM_MASK
value|0x00000c00
end_define

begin_comment
comment|/* Interrupt Mode */
end_comment

begin_define
define|#
directive|define
name|BFE_HIGH_RM_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|BFE_HIGH_SM_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BFE_HIGH_EM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BFE_HIGH_IM_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|BFE_SBBCFG
value|0x00000FC0
end_define

begin_comment
comment|/* BFE_SB Broadcast Configuration */
end_comment

begin_define
define|#
directive|define
name|BFE_LAT_MASK
value|0x00000003
end_define

begin_comment
comment|/* BFE_SB Latency */
end_comment

begin_define
define|#
directive|define
name|BFE_MAX0_MASK
value|0x000f0000
end_define

begin_comment
comment|/* MAX Counter 0 */
end_comment

begin_define
define|#
directive|define
name|BFE_MAX1_MASK
value|0x00f00000
end_define

begin_comment
comment|/* MAX Counter 1 */
end_comment

begin_define
define|#
directive|define
name|BFE_MAX0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BFE_MAX1_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BFE_SBBSTATE
value|0x00000FC8
end_define

begin_comment
comment|/* BFE_SB Broadcast State */
end_comment

begin_define
define|#
directive|define
name|BFE_SBBSTATE_SRD
value|0x00000001
end_define

begin_comment
comment|/* ST Reg Disable */
end_comment

begin_define
define|#
directive|define
name|BFE_SBBSTATE_HRD
value|0x00000002
end_define

begin_comment
comment|/* Hold Reg Disable */
end_comment

begin_define
define|#
directive|define
name|BFE_SBACTCNFG
value|0x00000FD8
end_define

begin_comment
comment|/* BFE_SB Activate Configuration */
end_comment

begin_define
define|#
directive|define
name|BFE_SBFLAGST
value|0x00000FE8
end_define

begin_comment
comment|/* BFE_SB Current BFE_SBFLAGS */
end_comment

begin_define
define|#
directive|define
name|BFE_SBIDLOW
value|0x00000FF8
end_define

begin_comment
comment|/* BFE_SB Identification Low */
end_comment

begin_define
define|#
directive|define
name|BFE_CS_MASK
value|0x00000003
end_define

begin_comment
comment|/* Config Space Mask */
end_comment

begin_define
define|#
directive|define
name|BFE_AR_MASK
value|0x00000038
end_define

begin_comment
comment|/* Num Address Ranges Supported */
end_comment

begin_define
define|#
directive|define
name|BFE_SYNCH
value|0x00000040
end_define

begin_comment
comment|/* Sync */
end_comment

begin_define
define|#
directive|define
name|BFE_INIT
value|0x00000080
end_define

begin_comment
comment|/* Initiator */
end_comment

begin_define
define|#
directive|define
name|BFE_MINLAT_MASK
value|0x00000f00
end_define

begin_comment
comment|/* Minimum Backplane Latency */
end_comment

begin_define
define|#
directive|define
name|BFE_MAXLAT_MASK
value|0x0000f000
end_define

begin_comment
comment|/* Maximum Backplane Latency */
end_comment

begin_define
define|#
directive|define
name|BFE_FIRST
value|0x00010000
end_define

begin_comment
comment|/* This Initiator is First */
end_comment

begin_define
define|#
directive|define
name|BFE_CW_MASK
value|0x000c0000
end_define

begin_comment
comment|/* Cycle Counter Width */
end_comment

begin_define
define|#
directive|define
name|BFE_TP_MASK
value|0x00f00000
end_define

begin_comment
comment|/* Target Ports */
end_comment

begin_define
define|#
directive|define
name|BFE_IP_MASK
value|0x0f000000
end_define

begin_comment
comment|/* Initiator Ports */
end_comment

begin_define
define|#
directive|define
name|BFE_AR_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|BFE_MINLAT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BFE_MAXLAT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BFE_CW_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|BFE_TP_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BFE_IP_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BFE_SBIDHIGH
value|0x00000FFC
end_define

begin_comment
comment|/* BFE_SB Identification High */
end_comment

begin_define
define|#
directive|define
name|BFE_RC_MASK
value|0x0000000f
end_define

begin_comment
comment|/* Revision Code */
end_comment

begin_define
define|#
directive|define
name|BFE_CC_MASK
value|0x0000fff0
end_define

begin_comment
comment|/* Core Code */
end_comment

begin_define
define|#
directive|define
name|BFE_VC_MASK
value|0xffff0000
end_define

begin_comment
comment|/* Vendor Code */
end_comment

begin_define
define|#
directive|define
name|BFE_CC_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BFE_VC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BFE_CORE_ILINE20
value|0x801
end_define

begin_define
define|#
directive|define
name|BFE_CORE_SDRAM
value|0x803
end_define

begin_define
define|#
directive|define
name|BFE_CORE_PCI
value|0x804
end_define

begin_define
define|#
directive|define
name|BFE_CORE_MIPS
value|0x805
end_define

begin_define
define|#
directive|define
name|BFE_CORE_ENET
value|0x806
end_define

begin_define
define|#
directive|define
name|BFE_CORE_CODEC
value|0x807
end_define

begin_define
define|#
directive|define
name|BFE_CORE_USB
value|0x808
end_define

begin_define
define|#
directive|define
name|BFE_CORE_ILINE100
value|0x80a
end_define

begin_define
define|#
directive|define
name|BFE_CORE_EXTIF
value|0x811
end_define

begin_comment
comment|/* SSB PCI config space registers.  */
end_comment

begin_define
define|#
directive|define
name|BFE_BAR0_WIN
value|0x80
end_define

begin_define
define|#
directive|define
name|BFE_BAR1_WIN
value|0x84
end_define

begin_define
define|#
directive|define
name|BFE_SPROM_CONTROL
value|0x88
end_define

begin_define
define|#
directive|define
name|BFE_BAR1_CONTROL
value|0x8c
end_define

begin_comment
comment|/* SSB core and hsot control registers.  */
end_comment

begin_define
define|#
directive|define
name|BFE_SSB_CONTROL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BFE_SSB_ARBCONTROL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BFE_SSB_ISTAT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BFE_SSB_IMASK
value|0x00000024
end_define

begin_define
define|#
directive|define
name|BFE_SSB_MBOX
value|0x00000028
end_define

begin_define
define|#
directive|define
name|BFE_SSB_BCAST_ADDR
value|0x00000050
end_define

begin_define
define|#
directive|define
name|BFE_SSB_BCAST_DATA
value|0x00000054
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_TRANS_0
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_TRANS_1
value|0x00000104
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_TRANS_2
value|0x00000108
end_define

begin_define
define|#
directive|define
name|BFE_SSB_SPROM
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_MEM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_IO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_CFG0
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_CFG1
value|0x00000003
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_PREF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_BURST
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_MASK0
value|0xfc000000
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_MASK1
value|0xfc000000
end_define

begin_define
define|#
directive|define
name|BFE_SSB_PCI_MASK2
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|BFE_DESC_LEN
value|0x00001fff
end_define

begin_define
define|#
directive|define
name|BFE_DESC_CMASK
value|0x0ff00000
end_define

begin_comment
comment|/* Core specific bits */
end_comment

begin_define
define|#
directive|define
name|BFE_DESC_EOT
value|0x10000000
end_define

begin_comment
comment|/* End of Table */
end_comment

begin_define
define|#
directive|define
name|BFE_DESC_IOC
value|0x20000000
end_define

begin_comment
comment|/* Interrupt On Completion */
end_comment

begin_define
define|#
directive|define
name|BFE_DESC_EOF
value|0x40000000
end_define

begin_comment
comment|/* End of Frame */
end_comment

begin_define
define|#
directive|define
name|BFE_DESC_SOF
value|0x80000000
end_define

begin_comment
comment|/* Start of Frame */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_CP_THRESHOLD
value|256
end_define

begin_define
define|#
directive|define
name|BFE_RX_HEADER_LEN
value|28
end_define

begin_define
define|#
directive|define
name|BFE_RX_FLAG_OFIFO
value|0x00000001
end_define

begin_comment
comment|/* FIFO Overflow */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_FLAG_CRCERR
value|0x00000002
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_FLAG_SERR
value|0x00000004
end_define

begin_comment
comment|/* Receive Symbol Error */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_FLAG_ODD
value|0x00000008
end_define

begin_comment
comment|/* Frame has odd number of nibbles */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_FLAG_LARGE
value|0x00000010
end_define

begin_comment
comment|/* Frame is> RX MAX Length */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_FLAG_MCAST
value|0x00000020
end_define

begin_comment
comment|/* Dest is Multicast Address */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_FLAG_BCAST
value|0x00000040
end_define

begin_comment
comment|/* Dest is Broadcast Address */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_FLAG_MISS
value|0x00000080
end_define

begin_comment
comment|/* Received due to promisc mode */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_FLAG_LAST
value|0x00000800
end_define

begin_comment
comment|/* Last buffer in frame */
end_comment

begin_define
define|#
directive|define
name|BFE_RX_FLAG_ERRORS
value|(BFE_RX_FLAG_ODD | BFE_RX_FLAG_SERR |           \ 	BFE_RX_FLAG_CRCERR | BFE_RX_FLAG_OFIFO)
end_define

begin_define
define|#
directive|define
name|BFE_MCAST_TBL_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|BFE_PCI_DMA
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BFE_REG_PCI
value|0x18002000
end_define

begin_define
define|#
directive|define
name|BCOM_VENDORID
value|0x14E4
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM4401
value|0x4401
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM4401B0
value|0x170c
end_define

begin_define
define|#
directive|define
name|PCI_SETBIT
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
define|\
value|pci_write_config(dev, reg, (pci_read_config(dev, reg, s) | (x)), s)
end_define

begin_define
define|#
directive|define
name|PCI_CLRBIT
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
define|\
value|pci_write_config(dev, reg, (pci_read_config(dev, reg, s)& ~(x)), s)
end_define

begin_define
define|#
directive|define
name|BFE_RX_RING_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|BFE_TX_RING_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|BFE_LINK_DOWN
value|5
end_define

begin_define
define|#
directive|define
name|BFE_TX_LIST_CNT
value|128
end_define

begin_define
define|#
directive|define
name|BFE_RX_LIST_CNT
value|128
end_define

begin_define
define|#
directive|define
name|BFE_TX_LIST_SIZE
value|BFE_TX_LIST_CNT * sizeof(struct bfe_desc)
end_define

begin_define
define|#
directive|define
name|BFE_RX_LIST_SIZE
value|BFE_RX_LIST_CNT * sizeof(struct bfe_desc)
end_define

begin_define
define|#
directive|define
name|BFE_RX_OFFSET
value|30
end_define

begin_define
define|#
directive|define
name|BFE_TX_QLEN
value|256
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->bfe_btag, sc->bfe_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->bfe_btag, sc->bfe_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|BFE_OR
parameter_list|(
name|sc
parameter_list|,
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_4(sc, name, CSR_READ_4(sc, name) | val)
end_define

begin_define
define|#
directive|define
name|BFE_AND
parameter_list|(
name|sc
parameter_list|,
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_4(sc, name, CSR_READ_4(sc, name)& val)
end_define

begin_define
define|#
directive|define
name|BFE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->bfe_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|BFE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->bfe_mtx)
end_define

begin_define
define|#
directive|define
name|BFE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->bfe_mtx)
end_define

begin_define
define|#
directive|define
name|BFE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = ((x) == ((y)-1)) ? 0 : (x)+1
end_define

begin_struct
struct|struct
name|bfe_data
block|{
name|struct
name|mbuf
modifier|*
name|bfe_mbuf
decl_stmt|;
name|bus_dmamap_t
name|bfe_map
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bfe_desc
block|{
name|u_int32_t
name|bfe_ctrl
decl_stmt|;
name|u_int32_t
name|bfe_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bfe_rxheader
block|{
name|u_int16_t
name|len
decl_stmt|;
name|u_int16_t
name|flags
decl_stmt|;
name|u_int16_t
name|pad
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bfe_hw_stats
block|{
name|u_int32_t
name|tx_good_octets
decl_stmt|,
name|tx_good_pkts
decl_stmt|,
name|tx_octets
decl_stmt|;
name|u_int32_t
name|tx_pkts
decl_stmt|,
name|tx_broadcast_pkts
decl_stmt|,
name|tx_multicast_pkts
decl_stmt|;
name|u_int32_t
name|tx_len_64
decl_stmt|,
name|tx_len_65_to_127
decl_stmt|,
name|tx_len_128_to_255
decl_stmt|;
name|u_int32_t
name|tx_len_256_to_511
decl_stmt|,
name|tx_len_512_to_1023
decl_stmt|,
name|tx_len_1024_to_max
decl_stmt|;
name|u_int32_t
name|tx_jabber_pkts
decl_stmt|,
name|tx_oversize_pkts
decl_stmt|,
name|tx_fragment_pkts
decl_stmt|;
name|u_int32_t
name|tx_underruns
decl_stmt|,
name|tx_total_cols
decl_stmt|,
name|tx_single_cols
decl_stmt|;
name|u_int32_t
name|tx_multiple_cols
decl_stmt|,
name|tx_excessive_cols
decl_stmt|,
name|tx_late_cols
decl_stmt|;
name|u_int32_t
name|tx_defered
decl_stmt|,
name|tx_carrier_lost
decl_stmt|,
name|tx_pause_pkts
decl_stmt|;
name|u_int32_t
name|__pad1
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|rx_good_octets
decl_stmt|,
name|rx_good_pkts
decl_stmt|,
name|rx_octets
decl_stmt|;
name|u_int32_t
name|rx_pkts
decl_stmt|,
name|rx_broadcast_pkts
decl_stmt|,
name|rx_multicast_pkts
decl_stmt|;
name|u_int32_t
name|rx_len_64
decl_stmt|,
name|rx_len_65_to_127
decl_stmt|,
name|rx_len_128_to_255
decl_stmt|;
name|u_int32_t
name|rx_len_256_to_511
decl_stmt|,
name|rx_len_512_to_1023
decl_stmt|,
name|rx_len_1024_to_max
decl_stmt|;
name|u_int32_t
name|rx_jabber_pkts
decl_stmt|,
name|rx_oversize_pkts
decl_stmt|,
name|rx_fragment_pkts
decl_stmt|;
name|u_int32_t
name|rx_missed_pkts
decl_stmt|,
name|rx_crc_align_errs
decl_stmt|,
name|rx_undersize
decl_stmt|;
name|u_int32_t
name|rx_crc_errs
decl_stmt|,
name|rx_align_errs
decl_stmt|,
name|rx_symbol_errs
decl_stmt|;
name|u_int32_t
name|rx_pause_pkts
decl_stmt|,
name|rx_nonpause_pkts
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bfe_softc
block|{
name|struct
name|ifnet
modifier|*
name|bfe_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|bfe_dev
decl_stmt|;
name|device_t
name|bfe_miibus
decl_stmt|;
name|bus_space_handle_t
name|bfe_bhandle
decl_stmt|;
name|vm_offset_t
name|bfe_vhandle
decl_stmt|;
name|bus_space_tag_t
name|bfe_btag
decl_stmt|;
name|bus_dma_tag_t
name|bfe_tag
decl_stmt|;
name|bus_dma_tag_t
name|bfe_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|bfe_tx_tag
decl_stmt|,
name|bfe_rx_tag
decl_stmt|;
name|bus_dmamap_t
name|bfe_tx_map
decl_stmt|,
name|bfe_rx_map
decl_stmt|;
name|void
modifier|*
name|bfe_intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|bfe_irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|bfe_res
decl_stmt|;
name|struct
name|callout_handle
name|bfe_stat_ch
decl_stmt|;
name|struct
name|bfe_hw_stats
name|bfe_hwstats
decl_stmt|;
name|struct
name|bfe_desc
modifier|*
name|bfe_tx_list
decl_stmt|,
modifier|*
name|bfe_rx_list
decl_stmt|;
name|struct
name|bfe_data
name|bfe_tx_ring
index|[
name|BFE_TX_LIST_CNT
index|]
decl_stmt|;
comment|/* XXX */
name|struct
name|bfe_data
name|bfe_rx_ring
index|[
name|BFE_RX_LIST_CNT
index|]
decl_stmt|;
comment|/* XXX */
name|struct
name|mtx
name|bfe_mtx
decl_stmt|;
name|u_int32_t
name|bfe_flags
decl_stmt|;
name|u_int32_t
name|bfe_imask
decl_stmt|;
name|u_int32_t
name|bfe_dma_offset
decl_stmt|;
name|u_int32_t
name|bfe_tx_cnt
decl_stmt|,
name|bfe_tx_cons
decl_stmt|,
name|bfe_tx_prod
decl_stmt|;
name|u_int32_t
name|bfe_rx_cnt
decl_stmt|,
name|bfe_rx_prod
decl_stmt|,
name|bfe_rx_cons
decl_stmt|;
name|u_int32_t
name|bfe_tx_dma
decl_stmt|,
name|bfe_rx_dma
decl_stmt|;
name|u_int32_t
name|bfe_link
decl_stmt|;
name|u_int8_t
name|bfe_phyaddr
decl_stmt|;
comment|/* Address of the card's PHY */
name|u_int8_t
name|bfe_mdc_port
decl_stmt|;
name|u_int8_t
name|bfe_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|bfe_core_unit
decl_stmt|;
name|u_int8_t
name|bfe_up
decl_stmt|;
name|u_char
name|bfe_enaddr
index|[
literal|6
index|]
decl_stmt|;
name|int
name|bfe_if_flags
decl_stmt|;
name|char
modifier|*
name|bfe_vpd_prodname
decl_stmt|;
name|char
modifier|*
name|bfe_vpd_readonly
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bfe_type
block|{
name|u_int16_t
name|bfe_vid
decl_stmt|;
name|u_int16_t
name|bfe_did
decl_stmt|;
name|char
modifier|*
name|bfe_name
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BFE_H */
end_comment

end_unit


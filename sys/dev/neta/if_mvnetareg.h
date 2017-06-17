begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017 Stormshield.  * Copyright (c) 2017 Semihalf.  * Copyright (c) 2015 Internet Initiative Japan Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_MVNETAREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_MVNETAREG_H_
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_error
error|#
directive|error
literal|"BIG ENDIAN not supported"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MVNETA_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|MVNETA_NWINDOW
value|6
end_define

begin_define
define|#
directive|define
name|MVNETA_NREMAP
value|4
end_define

begin_define
define|#
directive|define
name|MVNETA_MAX_QUEUE_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|MVNETA_RX_QNUM_MAX
value|1
end_define

begin_comment
comment|/* XXX: Currently multi-queue can be used on the Tx side only */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MVNETA_MULTIQUEUE
end_ifdef

begin_define
define|#
directive|define
name|MVNETA_TX_QNUM_MAX
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MVNETA_TX_QNUM_MAX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MVNETA_TX_QNUM_MAX
operator|&
operator|(
name|MVNETA_TX_QNUM_MAX
operator|-
literal|1
operator|)
operator|!=
literal|0
end_if

begin_error
error|#
directive|error
literal|"MVNETA_TX_QNUM_MAX Should be a power of 2"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MVNETA_RX_QNUM_MAX
operator|&
operator|(
name|MVNETA_RX_QNUM_MAX
operator|-
literal|1
operator|)
operator|!=
literal|0
end_if

begin_error
error|#
directive|error
literal|"MVNETA_RX_QNUM_MAX Should be a power of 2"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MVNETA_QUEUE
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_define
define|#
directive|define
name|MVNETA_QUEUE_ALL
value|0xff
end_define

begin_define
define|#
directive|define
name|MVNETA_TX_QUEUE_ALL
value|((1<<MVNETA_TX_QNUM_MAX)-1)
end_define

begin_define
define|#
directive|define
name|MVNETA_RX_QUEUE_ALL
value|((1<<MVNETA_RX_QNUM_MAX)-1)
end_define

begin_comment
comment|/*  * Ethernet Unit Registers  *  GbE0 BASE 0x00007.0000 SIZE 0x4000  *  GbE1 BASE 0x00007.4000 SIZE 0x4000  *  * TBD: reasonable bus space submapping....  */
end_comment

begin_comment
comment|/* Address Decoder Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_BASEADDR
parameter_list|(
name|n
parameter_list|)
value|(0x2200 + ((n)<< 3))
end_define

begin_comment
comment|/* Base Address */
end_comment

begin_define
define|#
directive|define
name|MVNETA_S
parameter_list|(
name|n
parameter_list|)
value|(0x2204 + ((n)<< 3))
end_define

begin_comment
comment|/* Size */
end_comment

begin_define
define|#
directive|define
name|MVNETA_HA
parameter_list|(
name|n
parameter_list|)
value|(0x2280 + ((n)<< 2))
end_define

begin_comment
comment|/* High Address Remap */
end_comment

begin_define
define|#
directive|define
name|MVNETA_BARE
value|0x2290
end_define

begin_comment
comment|/* Base Address Enable */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EPAP
value|0x2294
end_define

begin_comment
comment|/* Ethernet Port Access Protect */
end_comment

begin_comment
comment|/* Global Miscellaneous Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PHYADDR
value|0x2000
end_define

begin_define
define|#
directive|define
name|MVNETA_SMI
value|0x2004
end_define

begin_define
define|#
directive|define
name|MVNETA_EUDA
value|0x2008
end_define

begin_comment
comment|/* Ethernet Unit Default Address */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EUDID
value|0x200c
end_define

begin_comment
comment|/* Ethernet Unit Default ID */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MBUS_CONF
value|0x2010
end_define

begin_comment
comment|/* MBUS configuration */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MBUS_RETRY_EN
value|0x20
end_define

begin_comment
comment|/* MBUS transactions retry enable */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EUIC
value|0x2080
end_define

begin_comment
comment|/* Ethernet Unit Interrupt Cause */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EUIM
value|0x2084
end_define

begin_comment
comment|/* Ethernet Unit Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EUEA
value|0x2094
end_define

begin_comment
comment|/* Ethernet Unit Error Address */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EUIAE
value|0x2098
end_define

begin_comment
comment|/* Ethernet Unit Internal Addr Error */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EUC
value|0x20b0
end_define

begin_comment
comment|/* Ethernet Unit Control */
end_comment

begin_comment
comment|/* Miscellaneous Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_SDC
value|0x241c
end_define

begin_comment
comment|/* SDMA Configuration */
end_comment

begin_comment
comment|/* Networking Controller Miscellaneous Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PACC
value|0x2500
end_define

begin_comment
comment|/* Port Acceleration Mode */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PV
value|0x25bc
end_define

begin_comment
comment|/* Port Version */
end_comment

begin_comment
comment|/* Rx DMA Hardware Parser Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EVLANE
value|0x2410
end_define

begin_comment
comment|/* VLAN EtherType */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MACAL
value|0x2414
end_define

begin_comment
comment|/* MAC Address Low */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MACAH
value|0x2418
end_define

begin_comment
comment|/* MAC Address High */
end_comment

begin_define
define|#
directive|define
name|MVNETA_NDSCP
value|7
end_define

begin_define
define|#
directive|define
name|MVNETA_DSCP
parameter_list|(
name|n
parameter_list|)
value|(0x2420 + ((n)<< 2))
end_define

begin_define
define|#
directive|define
name|MVNETA_VPT2P
value|0x2440
end_define

begin_comment
comment|/* VLAN Priority Tag to Priority */
end_comment

begin_define
define|#
directive|define
name|MVNETA_ETP
value|0x24bc
end_define

begin_comment
comment|/* Ethernet Type Priority */
end_comment

begin_define
define|#
directive|define
name|MVNETA_NDFSMT
value|64
end_define

begin_define
define|#
directive|define
name|MVNETA_DFSMT
parameter_list|(
name|n
parameter_list|)
value|(0x3400 + ((n)<< 2))
end_define

begin_comment
comment|/* Destination Address Filter Special Multicast Table */
end_comment

begin_define
define|#
directive|define
name|MVNETA_NDFOMT
value|64
end_define

begin_define
define|#
directive|define
name|MVNETA_DFOMT
parameter_list|(
name|n
parameter_list|)
value|(0x3500 + ((n)<< 2))
end_define

begin_comment
comment|/* Destination Address Filter Other Multicast Table */
end_comment

begin_define
define|#
directive|define
name|MVNETA_NDFUT
value|4
end_define

begin_define
define|#
directive|define
name|MVNETA_DFUT
parameter_list|(
name|n
parameter_list|)
value|(0x3600 + ((n)<< 2))
end_define

begin_comment
comment|/* Destination Address Filter Unicast Table */
end_comment

begin_comment
comment|/* Rx DMA Miscellaneous Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMFS
value|0x247c
end_define

begin_comment
comment|/* Port Rx Minimal Frame Size */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PDFC
value|0x2484
end_define

begin_comment
comment|/* Port Rx Discard Frame Counter */
end_comment

begin_define
define|#
directive|define
name|MVNETA_POFC
value|0x2488
end_define

begin_comment
comment|/* Port Overrun Frame Counter */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RQC
value|0x2680
end_define

begin_comment
comment|/* Receive Queue Command */
end_comment

begin_comment
comment|/* Rx DMA Networking Controller Miscellaneous Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXC
parameter_list|(
name|q
parameter_list|)
value|(0x1400 + ((q)<< 2))
end_define

begin_comment
comment|/*Port RX queues Config*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXSNP
parameter_list|(
name|q
parameter_list|)
value|(0x1420 + ((q)<< 2))
end_define

begin_comment
comment|/* Port RX queues Snoop */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXDQA
parameter_list|(
name|q
parameter_list|)
value|(0x1480 + ((q)<< 2))
end_define

begin_comment
comment|/*P RXqueues desc Q Addr*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXDQS
parameter_list|(
name|q
parameter_list|)
value|(0x14a0 + ((q)<< 2))
end_define

begin_comment
comment|/*P RXqueues desc Q Size*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXDQTH
parameter_list|(
name|q
parameter_list|)
value|(0x14c0 + ((q)<< 2))
end_define

begin_comment
comment|/*P RXqueues desc Q Thrs*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXS
parameter_list|(
name|q
parameter_list|)
value|(0x14e0 + ((q)<< 2))
end_define

begin_comment
comment|/*Port RX queues Status */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXSU
parameter_list|(
name|q
parameter_list|)
value|(0x1500 + ((q)<< 2))
end_define

begin_comment
comment|/*P RXqueues Stat Update*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXDI
parameter_list|(
name|q
parameter_list|)
value|(0x1520 + ((q)<< 2))
end_define

begin_comment
comment|/*P RXqueues Stat Update*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXINIT
value|0x1cc0
end_define

begin_comment
comment|/* Port RX Initialization */
end_comment

begin_comment
comment|/* Rx DMA Wake on LAN Registers	0x3690 - 0x36b8 */
end_comment

begin_comment
comment|/* Tx DMA Miscellaneous Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQC
value|0x2448
end_define

begin_comment
comment|/* Transmit Queue Command */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQC_1
value|0x24e4
end_define

begin_define
define|#
directive|define
name|MVNETA_PXTFTT
value|0x2478
end_define

begin_comment
comment|/* Port Tx FIFO Threshold */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TXBADFCS
value|0x3cc0
end_define

begin_comment
comment|/*Tx Bad FCS Transmitted Pckts Counter*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_TXDROPPED
value|0x3cc4
end_define

begin_comment
comment|/* Tx Dropped Packets Counter */
end_comment

begin_comment
comment|/* Tx DMA Networking Controller Miscellaneous Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXDQA
parameter_list|(
name|q
parameter_list|)
value|(0x3c00 + ((q)<< 2))
end_define

begin_comment
comment|/*P TXqueues desc Q Addr*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXDQS
parameter_list|(
name|q
parameter_list|)
value|(0x3c20 + ((q)<< 2))
end_define

begin_comment
comment|/*P TXqueues desc Q Size*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXS
parameter_list|(
name|q
parameter_list|)
value|(0x3c40 + ((q)<< 2))
end_define

begin_comment
comment|/* Port TX queues Status*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXSU
parameter_list|(
name|q
parameter_list|)
value|(0x3c60 + ((q)<< 2))
end_define

begin_comment
comment|/*P TXqueues Stat Update*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXDI
parameter_list|(
name|q
parameter_list|)
value|(0x3c80 + ((q)<< 2))
end_define

begin_comment
comment|/* P TXqueues Desc Index*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_TXTBC
parameter_list|(
name|q
parameter_list|)
value|(0x3ca0 + ((q)<< 2))
end_define

begin_comment
comment|/* TX Trans-ed Buf Count*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXINIT
value|0x3cf0
end_define

begin_comment
comment|/* Port TX Initialization */
end_comment

begin_comment
comment|/* Tx DMA Packet Modification Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_NMH
value|15
end_define

begin_define
define|#
directive|define
name|MVNETA_TXMH
parameter_list|(
name|n
parameter_list|)
value|(0x3d44 + ((n)<< 2))
end_define

begin_define
define|#
directive|define
name|MVNETA_TXMTU
value|0x3d88
end_define

begin_comment
comment|/* Tx DMA Queue Arbiter Registers (Version 1) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQFPC_V1
value|0x24dc
end_define

begin_comment
comment|/* Transmit Queue Fixed Priority Cfg */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQTBC_V1
value|0x24e0
end_define

begin_comment
comment|/* Transmit Queue Token-Bucket Cfg */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MTU_V1
value|0x24e8
end_define

begin_comment
comment|/* MTU */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMTBS_V1
value|0x24ec
end_define

begin_comment
comment|/* Port Max Token-Bucket Size */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQTBCOUNT_V1
parameter_list|(
name|q
parameter_list|)
value|(0x2700 + ((q)<< 4))
end_define

begin_comment
comment|/* Transmit Queue Token-Bucket Counter */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQTBCONFIG_V1
parameter_list|(
name|q
parameter_list|)
value|(0x2704 + ((q)<< 4))
end_define

begin_comment
comment|/* Transmit Queue Token-Bucket Configuration */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTTBC_V1
value|0x2740
end_define

begin_comment
comment|/* Port Transmit Backet Counter */
end_comment

begin_comment
comment|/* Tx DMA Queue Arbiter Registers (Version 3) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQC1_V3
value|0x3e00
end_define

begin_comment
comment|/* Transmit Queue Command1 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQFPC_V3
value|0x3e04
end_define

begin_comment
comment|/* Transmit Queue Fixed Priority Cfg */
end_comment

begin_define
define|#
directive|define
name|MVNETA_BRC_V3
value|0x3e08
end_define

begin_comment
comment|/* Basic Refill No of Clocks */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MTU_V3
value|0x3e0c
end_define

begin_comment
comment|/* MTU */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PREFILL_V3
value|0x3e10
end_define

begin_comment
comment|/* Port Backet Refill */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMTBS_V3
value|0x3e14
end_define

begin_comment
comment|/* Port Max Token-Bucket Size */
end_comment

begin_define
define|#
directive|define
name|MVNETA_QREFILL_V3
parameter_list|(
name|q
parameter_list|)
value|(0x3e20 + ((q)<< 2))
end_define

begin_comment
comment|/* Transmit Queue Refill */
end_comment

begin_define
define|#
directive|define
name|MVNETA_QMTBS_V3
parameter_list|(
name|q
parameter_list|)
value|(0x3e40 + ((q)<< 2))
end_define

begin_comment
comment|/* Transmit Queue Max Token-Bucket Size */
end_comment

begin_define
define|#
directive|define
name|MVNETA_QTTBC_V3
parameter_list|(
name|q
parameter_list|)
value|(0x3e60 + ((q)<< 2))
end_define

begin_comment
comment|/* Transmit Queue Token-Bucket Counter */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQAC_V3
parameter_list|(
name|q
parameter_list|)
value|(0x3e80 + ((q)<< 2))
end_define

begin_comment
comment|/* Transmit Queue Arbiter Cfg */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQIPG_V3
parameter_list|(
name|q
parameter_list|)
value|(0x3ea0 + ((q)<< 2))
end_define

begin_comment
comment|/* Transmit Queue IPG(valid q=2..3) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_HITKNINLOPKT_V3
value|0x3eb0
end_define

begin_comment
comment|/* High Token in Low Packet */
end_comment

begin_define
define|#
directive|define
name|MVNETA_HITKNINASYNCPKT_V3
value|0x3eb4
end_define

begin_comment
comment|/* High Token in Async Packet */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LOTKNINASYNCPKT_V3
value|0x3eb8
end_define

begin_comment
comment|/* Low Token in Async Packet */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TS_V3
value|0x3ebc
end_define

begin_comment
comment|/* Token Speed */
end_comment

begin_comment
comment|/* RX_TX DMA Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PXC
value|0x2400
end_define

begin_comment
comment|/* Port Configuration */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PXCX
value|0x2404
end_define

begin_comment
comment|/* Port Configuration Extend */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MH
value|0x2454
end_define

begin_comment
comment|/* Marvell Header */
end_comment

begin_comment
comment|/* Serial(SMI/MII) Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSC0
value|0x243c
end_define

begin_comment
comment|/* Port Serial Control0 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PS0
value|0x2444
end_define

begin_comment
comment|/* Ethernet Port Status */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSERDESCFG
value|0x24a0
end_define

begin_comment
comment|/* Serdes Configuration */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSERDESSTS
value|0x24a4
end_define

begin_comment
comment|/* Serdes Status */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSOMSCD
value|0x24f4
end_define

begin_comment
comment|/* One mS Clock Divider */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSPFCCD
value|0x24f8
end_define

begin_comment
comment|/* Periodic Flow Control Clock Divider*/
end_comment

begin_comment
comment|/* Gigabit Ethernet MAC Serial Parameters Configuration Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSPC
value|0x2c14
end_define

begin_comment
comment|/* Port Serial Parameters Config */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSP1C
value|0x2c94
end_define

begin_comment
comment|/* Port Serial Parameters 1 Config */
end_comment

begin_comment
comment|/* Gigabit Ethernet Auto-Negotiation Configuration Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PANC
value|0x2c0c
end_define

begin_comment
comment|/* Port Auto-Negotiation Configuration*/
end_comment

begin_comment
comment|/* Gigabit Ethernet MAC Control Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC0
value|0x2c00
end_define

begin_comment
comment|/* Port MAC Control 0 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC1
value|0x2c04
end_define

begin_comment
comment|/* Port MAC Control 1 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC2
value|0x2c08
end_define

begin_comment
comment|/* Port MAC Control 2 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC3
value|0x2c48
end_define

begin_comment
comment|/* Port MAC Control 3 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_CCFCPST
parameter_list|(
name|p
parameter_list|)
value|(0x2c58 + ((p)<< 2))
end_define

begin_comment
comment|/*CCFC Port Speed Timerp*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC4
value|0x2c90
end_define

begin_comment
comment|/* Port MAC Control 4 */
end_comment

begin_comment
comment|/* Gigabit Ethernet MAC Interrupt Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PIC
value|0x2c20
end_define

begin_define
define|#
directive|define
name|MVNETA_PIM
value|0x2c24
end_define

begin_comment
comment|/* Gigabit Ethernet Low Power Idle  Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIC0
value|0x2cc0
end_define

begin_comment
comment|/* LowPowerIdle control 0 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIC1
value|0x2cc4
end_define

begin_comment
comment|/* LPI control 1 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIC2
value|0x2cc8
end_define

begin_comment
comment|/* LPI control 2 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIS
value|0x2ccc
end_define

begin_comment
comment|/* LPI status */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIC
value|0x2cd0
end_define

begin_comment
comment|/* LPI counter */
end_comment

begin_comment
comment|/* Gigabit Ethernet MAC PRBS Check Status Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PPRBSS
value|0x2c38
end_define

begin_comment
comment|/* Port PRBS Status */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PPRBSEC
value|0x2c3c
end_define

begin_comment
comment|/* Port PRBS Error Counter */
end_comment

begin_comment
comment|/* Gigabit Ethernet MAC Status Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSR
value|0x2c10
end_define

begin_comment
comment|/* Port Status Register0 */
end_comment

begin_comment
comment|/* Networking Controller Interrupt Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PCP2Q
parameter_list|(
name|cpu
parameter_list|)
value|(0x2540 + ((cpu)<< 2))
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXITTH
parameter_list|(
name|q
parameter_list|)
value|(0x2580 + ((q)<< 2))
end_define

begin_comment
comment|/* Port Rx Interrupt Threshold */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXTIC
value|0x25a0
end_define

begin_comment
comment|/*Port RX_TX Threshold Interrupt Cause*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXTIM
value|0x25a4
end_define

begin_comment
comment|/*Port RX_TX Threshold Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXIC
value|0x25a8
end_define

begin_comment
comment|/* Port RX_TX Interrupt Cause */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXIM
value|0x25ac
end_define

begin_comment
comment|/* Port RX_TX Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMIC
value|0x25b0
end_define

begin_comment
comment|/* Port Misc Interrupt Cause */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMIM
value|0x25b4
end_define

begin_comment
comment|/* Port Misc Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PIE
value|0x25b8
end_define

begin_comment
comment|/* Port Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSNPCFG
value|0x25e4
end_define

begin_comment
comment|/* Port Snoop Config */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSNPCFG_DESCSNP_MASK
value|(0x3<< 4)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSNPCFG_BUFSNP_MASK
value|(0x3<< 8)
end_define

begin_comment
comment|/* Miscellaneous Interrupt Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PEUIAE
value|0x2494
end_define

begin_comment
comment|/* Port Internal Address Error */
end_comment

begin_comment
comment|/* SGMII PHY Registers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PPLLC
value|0x2e04
end_define

begin_comment
comment|/* Power and PLL Control */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TESTC0
value|0x2e54
end_define

begin_comment
comment|/* PHY Test Control 0 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TESTPRBSEC0
value|0x2e7c
end_define

begin_comment
comment|/* PHY Test PRBS Error Counter 0 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TESTPRBSEC1
value|0x2e80
end_define

begin_comment
comment|/* PHY Test PRBS Error Counter 1 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TESTOOB0
value|0x2e84
end_define

begin_comment
comment|/* PHY Test OOB 0 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_DLE
value|0x2e8c
end_define

begin_comment
comment|/* Digital Loopback Enable */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RCS
value|0x2f18
end_define

begin_comment
comment|/* Reference Clock Select */
end_comment

begin_define
define|#
directive|define
name|MVNETA_COMPHYC
value|0x2f18
end_define

begin_comment
comment|/* COMPHY Control */
end_comment

begin_comment
comment|/*  * Ethernet MAC MIB Registers  *  GbE0 BASE 0x00007.3000  *  GbE1 BASE 0x00007.7000  */
end_comment

begin_comment
comment|/* MAC MIB Counters			0x3000 - 0x307c */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PORTMIB_BASE
value|0x3000
end_define

begin_define
define|#
directive|define
name|MVNETA_PORTMIB_SIZE
value|0x0080
end_define

begin_define
define|#
directive|define
name|MVNETA_PORTMIB_NOCOUNTER
value|30
end_define

begin_comment
comment|/* Rx */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_GOOD_OCT
value|0x00
end_define

begin_comment
comment|/* 64bit */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_BAD_OCT
value|0x08
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_GOOD_FRAME
value|0x10
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_BAD_FRAME
value|0x14
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_BCAST_FRAME
value|0x18
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_MCAST_FRAME
value|0x1c
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_FRAME64_OCT
value|0x20
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_FRAME127_OCT
value|0x24
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_FRAME255_OCT
value|0x28
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_FRAME511_OCT
value|0x2c
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_FRAME1023_OCT
value|0x30
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_RX_FRAMEMAX_OCT
value|0x34
end_define

begin_comment
comment|/* Tx */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MIB_TX_MAC_TRNS_ERR
value|0x0c
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_TX_GOOD_OCT
value|0x38
end_define

begin_comment
comment|/* 64bit */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MIB_TX_GOOD_FRAME
value|0x40
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_TX_EXCES_COL
value|0x44
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_TX_MCAST_FRAME
value|0x48
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_TX_BCAST_FRAME
value|0x4c
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_TX_MAC_CTL_ERR
value|0x50
end_define

begin_comment
comment|/* Flow Control */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MIB_FC_SENT
value|0x54
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_FC_GOOD
value|0x58
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_FC_BAD
value|0x5c
end_define

begin_comment
comment|/* Packet Processing */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MIB_PKT_UNDERSIZE
value|0x60
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_PKT_FRAGMENT
value|0x64
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_PKT_OVERSIZE
value|0x68
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_PKT_JABBER
value|0x6c
end_define

begin_comment
comment|/* MAC Layer Errors */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MIB_MAC_RX_ERR
value|0x70
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_MAC_CRC_ERR
value|0x74
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_MAC_COL
value|0x78
end_define

begin_define
define|#
directive|define
name|MVNETA_MIB_MAC_LATE_COL
value|0x7c
end_define

begin_comment
comment|/* END OF REGISTER NUMBERS */
end_comment

begin_comment
comment|/*  *  * Register Formats  *  */
end_comment

begin_comment
comment|/*  * Address Decoder Registers  */
end_comment

begin_comment
comment|/* Base Address (MVNETA_BASEADDR) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_BASEADDR_TARGET
parameter_list|(
name|target
parameter_list|)
value|((target)& 0xf)
end_define

begin_define
define|#
directive|define
name|MVNETA_BASEADDR_ATTR
parameter_list|(
name|attr
parameter_list|)
value|(((attr)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_BASEADDR_BASE
parameter_list|(
name|base
parameter_list|)
value|((base)& 0xffff0000)
end_define

begin_comment
comment|/* Size (MVNETA_S) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_S_SIZE
parameter_list|(
name|size
parameter_list|)
value|(((size) - 1)& 0xffff0000)
end_define

begin_comment
comment|/* Base Address Enable (MVNETA_BARE) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_BARE_EN_MASK
value|((1<< MVNETA_NWINDOW) - 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_BARE_EN
parameter_list|(
name|win
parameter_list|)
value|((1<< (win))& MVNETA_BARE_EN_MASK)
end_define

begin_comment
comment|/* Ethernet Port Access Protect (MVNETA_EPAP) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EPAP_AC_NAC
value|0x0
end_define

begin_comment
comment|/* No access allowed */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EPAP_AC_RO
value|0x1
end_define

begin_comment
comment|/* Read Only */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EPAP_AC_FA
value|0x3
end_define

begin_comment
comment|/* Full access (r/w) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EPAP_EPAR
parameter_list|(
name|win
parameter_list|,
name|ac
parameter_list|)
value|((ac)<< ((win) * 2))
end_define

begin_comment
comment|/*  * Global Miscellaneous Registers  */
end_comment

begin_comment
comment|/* PHY Address (MVNETA_PHYADDR) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PHYADDR_PHYAD
parameter_list|(
name|phy
parameter_list|)
value|((phy)& 0x1f)
end_define

begin_define
define|#
directive|define
name|MVNETA_PHYADDR_GET_PHYAD
parameter_list|(
name|reg
parameter_list|)
value|((reg)& 0x1f)
end_define

begin_comment
comment|/* SMI register fields (MVNETA_SMI) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_SMI_DATA_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|MVNETA_SMI_PHYAD
parameter_list|(
name|phy
parameter_list|)
value|(((phy)& 0x1f)<< 16)
end_define

begin_define
define|#
directive|define
name|MVNETA_SMI_REGAD
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& 0x1f)<< 21)
end_define

begin_define
define|#
directive|define
name|MVNETA_SMI_OPCODE_WRITE
value|(0<< 26)
end_define

begin_define
define|#
directive|define
name|MVNETA_SMI_OPCODE_READ
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|MVNETA_SMI_READVALID
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|MVNETA_SMI_BUSY
value|(1<< 28)
end_define

begin_comment
comment|/* Ethernet Unit Default ID (MVNETA_EUDID) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EUDID_DIDR_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|MVNETA_EUDID_DIDR
parameter_list|(
name|id
parameter_list|)
value|((id)& 0x0f)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUDID_DATTR_MASK
value|0x00000ff0
end_define

begin_define
define|#
directive|define
name|MVNETA_EUDID_DATTR
parameter_list|(
name|attr
parameter_list|)
value|(((attr)& 0xff)<< 4)
end_define

begin_comment
comment|/* Ethernet Unit Interrupt Cause (MVNETA_EUIC) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EUIC_ETHERINTSUM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUIC_PARITY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUIC_ADDRVIOL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUIC_ADDRVNOMATCH
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUIC_SMIDONE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUIC_COUNTWA
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUIC_INTADDRERR
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUIC_PORT0DPERR
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUIC_TOPDPERR
value|(1<< 12)
end_define

begin_comment
comment|/* Ethernet Unit Internal Addr Error (MVNETA_EUIAE) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EUIAE_INTADDR_MASK
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|MVNETA_EUIAE_INTADDR
parameter_list|(
name|addr
parameter_list|)
value|((addr)& 0x1ff)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUIAE_GET_INTADDR
parameter_list|(
name|addr
parameter_list|)
value|((addr)& 0x1ff)
end_define

begin_comment
comment|/* Ethernet Unit Control (MVNETA_EUC) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_EUC_POLLING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUC_PORTRESET
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|MVNETA_EUC_RAMSINITIALIZATIONCOMPLETED
value|(1<< 25)
end_define

begin_comment
comment|/*  * Miscellaneous Registers  */
end_comment

begin_comment
comment|/* SDMA Configuration (MVNETA_SDC) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_SDC_RXBSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_RXBSZ_MASK
value|MVNETA_SDC_RXBSZ(7)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_RXBSZ_1_64BITWORDS
value|MVNETA_SDC_RXBSZ(0)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_RXBSZ_2_64BITWORDS
value|MVNETA_SDC_RXBSZ(1)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_RXBSZ_4_64BITWORDS
value|MVNETA_SDC_RXBSZ(2)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_RXBSZ_8_64BITWORDS
value|MVNETA_SDC_RXBSZ(3)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_RXBSZ_16_64BITWORDS
value|MVNETA_SDC_RXBSZ(4)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_BLMR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_BLMT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_SWAPMODE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_TXBSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 22)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_TXBSZ_MASK
value|MVNETA_SDC_TXBSZ(7)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_TXBSZ_1_64BITWORDS
value|MVNETA_SDC_TXBSZ(0)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_TXBSZ_2_64BITWORDS
value|MVNETA_SDC_TXBSZ(1)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_TXBSZ_4_64BITWORDS
value|MVNETA_SDC_TXBSZ(2)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_TXBSZ_8_64BITWORDS
value|MVNETA_SDC_TXBSZ(3)
end_define

begin_define
define|#
directive|define
name|MVNETA_SDC_TXBSZ_16_64BITWORDS
value|MVNETA_SDC_TXBSZ(4)
end_define

begin_comment
comment|/*  * Networking Controller Miscellaneous Registers  */
end_comment

begin_comment
comment|/* Port Acceleration Mode (MVNETA_PACC) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PACC_ACCELERATIONMODE_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MVNETA_PACC_ACCELERATIONMODE_EDM
value|0x1
end_define

begin_comment
comment|/* Enhanced Desc Mode */
end_comment

begin_comment
comment|/* Port Version (MVNETA_PV) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PV_VERSION_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|MVNETA_PV_VERSION
parameter_list|(
name|v
parameter_list|)
value|((v)& 0xff)
end_define

begin_define
define|#
directive|define
name|MVNETA_PV_GET_VERSION
parameter_list|(
name|reg
parameter_list|)
value|((reg)& 0xff)
end_define

begin_comment
comment|/*  * Rx DMA Hardware Parser Registers  */
end_comment

begin_comment
comment|/* Ether Type Priority (MVNETA_ETP) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_ETP_ETHERTYPEPRIEN
value|(1<< 0)
end_define

begin_comment
comment|/* EtherType Prio Ena */
end_comment

begin_define
define|#
directive|define
name|MVNETA_ETP_ETHERTYPEPRIFRSTEN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_ETP_ETHERTYPEPRIQ
value|(0x7<< 2)
end_define

begin_comment
comment|/*EtherType Prio Queue*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_ETP_ETHERTYPEPRIVAL
value|(0xffff<< 5)
end_define

begin_comment
comment|/*EtherType Prio Value*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_ETP_FORCEUNICSTHIT
value|(1<< 21)
end_define

begin_comment
comment|/* Force Unicast hit */
end_comment

begin_comment
comment|/* Destination Address Filter Registers (MVNETA_DF{SM,OM,U}T) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_DF
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
value|((x)<< (8 * (n)))
end_define

begin_define
define|#
directive|define
name|MVNETA_DF_PASS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_DF_QUEUE
parameter_list|(
name|q
parameter_list|)
value|((q)<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_DF_QUEUE_ALL
value|((MVNETA_RX_QNUM_MAX-1)<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_DF_QUEUE_MASK
value|((MVNETA_RX_QNUM_MAX-1)<< 1)
end_define

begin_comment
comment|/*  * Rx DMA Miscellaneous Registers  */
end_comment

begin_comment
comment|/* Port Rx Minimal Frame Size (MVNETA_PMFS) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMFS_RXMFS
parameter_list|(
name|rxmfs
parameter_list|)
value|(((rxmfs) - 40)& 0x7c)
end_define

begin_comment
comment|/* Receive Queue Command (MVNETA_RQC) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RQC_EN_MASK
value|(0xff<< 0)
end_define

begin_comment
comment|/* Enable Q */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RQC_ENQ
parameter_list|(
name|q
parameter_list|)
value|(1<< (0 + (q)))
end_define

begin_define
define|#
directive|define
name|MVNETA_RQC_EN
parameter_list|(
name|n
parameter_list|)
value|((n)<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_RQC_DIS_MASK
value|(0xff<< 8)
end_define

begin_comment
comment|/* Disable Q */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RQC_DISQ
parameter_list|(
name|q
parameter_list|)
value|(1<< (8 + (q)))
end_define

begin_define
define|#
directive|define
name|MVNETA_RQC_DIS
parameter_list|(
name|n
parameter_list|)
value|((n)<< 8)
end_define

begin_comment
comment|/*  * Rx DMA Networking Controller Miscellaneous Registers  */
end_comment

begin_comment
comment|/* Port RX queues Configuration (MVNETA_PRXC) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXC_PACKETOFFSET
parameter_list|(
name|o
parameter_list|)
value|(((o)& 0xf)<< 8)
end_define

begin_comment
comment|/* Port RX queues Snoop (MVNETA_PRXSNP) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXSNP_SNOOPNOOFBYTES
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0x3fff)<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXSNP_L2DEPOSITNOOFBYTES
parameter_list|(
name|b
parameter_list|)
value|(((b)& 0x3fff)<< 16)
end_define

begin_comment
comment|/* Port RX queues Descriptors Queue Size (MVNETA_PRXDQS) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXDQS_DESCRIPTORSQUEUESIZE
parameter_list|(
name|s
parameter_list|)
value|(((s)& 0x3fff)<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXDQS_BUFFERSIZE
parameter_list|(
name|s
parameter_list|)
value|(((s)& 0x1fff)<< 19)
end_define

begin_comment
comment|/* Port RX queues Descriptors Queue Threshold (MVNETA_PRXDQTH) */
end_comment

begin_comment
comment|/* Occupied Descriptors Threshold */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXDQTH_ODT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3fff)<< 0)
end_define

begin_comment
comment|/* Non Occupied Descriptors Threshold */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXDQTH_NODT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3fff)<< 16)
end_define

begin_comment
comment|/* Port RX queues Status (MVNETA_PRXS) */
end_comment

begin_comment
comment|/* Occupied Descriptors Counter */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXS_ODC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3fff)<< 0)
end_define

begin_comment
comment|/* Non Occupied Descriptors Counter */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXS_NODC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3fff)<< 16)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXS_GET_ODC
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 0)& 0x3fff)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXS_GET_NODC
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 16)& 0x3fff)
end_define

begin_comment
comment|/* Port RX queues Status Update (MVNETA_PRXSU) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXSU_NOOFPROCESSEDDESCRIPTORS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXSU_NOOFNEWDESCRIPTORS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 16)
end_define

begin_comment
comment|/* Port RX Initialization (MVNETA_PRXINIT) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXINIT_RXDMAINIT
value|(1<< 0)
end_define

begin_comment
comment|/*  * Tx DMA Miscellaneous Registers  */
end_comment

begin_comment
comment|/* Transmit Queue Command (MVNETA_TQC) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQC_EN_MASK
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_TQC_ENQ
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 0))
end_define

begin_comment
comment|/* Enable Q */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQC_EN
parameter_list|(
name|n
parameter_list|)
value|((n)<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_TQC_DIS_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_TQC_DISQ
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 8))
end_define

begin_comment
comment|/* Disable Q */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQC_DIS
parameter_list|(
name|n
parameter_list|)
value|((n)<< 8)
end_define

begin_comment
comment|/*  * Tx DMA Networking Controller Miscellaneous Registers  */
end_comment

begin_comment
comment|/* Port TX queues Descriptors Queue Size (MVNETA_PTXDQS) */
end_comment

begin_comment
comment|/* Descriptors Queue Size */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXDQS_DQS_MASK
value|(0x3fff<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PTXDQS_DQS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3fff)<< 0)
end_define

begin_comment
comment|/* Transmitted Buffer Threshold */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXDQS_TBT_MASK
value|(0x3fff<< 16)
end_define

begin_define
define|#
directive|define
name|MVNETA_PTXDQS_TBT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3fff)<< 16)
end_define

begin_comment
comment|/* Port TX queues Status (MVNETA_PTXS) */
end_comment

begin_comment
comment|/* Transmitted Buffer Counter */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXS_TBC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3fff)<< 16)
end_define

begin_define
define|#
directive|define
name|MVNETA_PTXS_GET_TBC
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 16)& 0x3fff)
end_define

begin_comment
comment|/* Pending Descriptors Counter */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXS_PDC
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3fff)
end_define

begin_define
define|#
directive|define
name|MVNETA_PTXS_GET_PDC
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3fff)
end_define

begin_comment
comment|/* Port TX queues Status Update (MVNETA_PTXSU) */
end_comment

begin_comment
comment|/* Number Of Written Descriptors */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXSU_NOWD
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_comment
comment|/* Number Of Released Buffers */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXSU_NORB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 16)
end_define

begin_comment
comment|/* TX Transmitted Buffers Counter (MVNETA_TXTBC) */
end_comment

begin_comment
comment|/* Transmitted Buffers Counter */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TXTBC_TBC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3fff)<< 16)
end_define

begin_comment
comment|/* Port TX Initialization (MVNETA_PTXINIT) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PTXINIT_TXDMAINIT
value|(1<< 0)
end_define

begin_comment
comment|/*  * Tx DMA Queue Arbiter Registers (Version 1 )  */
end_comment

begin_comment
comment|/* Transmit Queue Fixed Priority Configuration */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TQFPC_EN
parameter_list|(
name|q
parameter_list|)
value|(1<< (q))
end_define

begin_comment
comment|/*  * RX_TX DMA Registers  */
end_comment

begin_comment
comment|/* Port Configuration (MVNETA_PXC) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PXC_UPM
value|(1<< 0)
end_define

begin_comment
comment|/* Uni Promisc mode */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PXC_RXQ
parameter_list|(
name|q
parameter_list|)
value|((q)<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_RXQ_MASK
value|MVNETA_PXC_RXQ(7)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_RXQARP
parameter_list|(
name|q
parameter_list|)
value|((q)<< 4)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_RXQARP_MASK
value|MVNETA_PXC_RXQARP(7)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_RB
value|(1<< 7)
end_define

begin_comment
comment|/* Rej mode of MAC */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PXC_RBIP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_RBARP
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_AMNOTXES
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_RBARPF
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_TCPCAPEN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_UDPCAPEN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_TCPQ
parameter_list|(
name|q
parameter_list|)
value|((q)<< 16)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_TCPQ_MASK
value|MVNETA_PXC_TCPQ(7)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_UDPQ
parameter_list|(
name|q
parameter_list|)
value|((q)<< 19)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_UDPQ_MASK
value|MVNETA_PXC_UDPQ(7)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_BPDUQ
parameter_list|(
name|q
parameter_list|)
value|((q)<< 22)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_BPDUQ_MASK
value|MVNETA_PXC_BPDUQ(7)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXC_RXCS
value|(1<< 25)
end_define

begin_comment
comment|/* Port Configuration Extend (MVNETA_PXCX) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PXCX_SPAN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_PXCX_TXCRCDIS
value|(1<< 3)
end_define

begin_comment
comment|/* Marvell Header (MVNETA_MH) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MH_MHEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_MH_DAPREFIX
value|(0x3<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_MH_SPID
value|(0xf<< 4)
end_define

begin_define
define|#
directive|define
name|MVNETA_MH_MHMASK
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_MH_MHMASK_8QUEUES
value|(0x0<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_MH_MHMASK_4QUEUES
value|(0x1<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_MH_MHMASK_2QUEUES
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_MH_DSAEN_MASK
value|(0x3<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_MH_DSAEN_DISABLE
value|(0x0<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_MH_DSAEN_NONEXTENDED
value|(0x1<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_MH_DSAEN_EXTENDED
value|(0x2<< 10)
end_define

begin_comment
comment|/*  * Serial(SMI/MII) Registers  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSOMSCD_ENABLE
value|(1UL<<31)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSERDESCFG_QSGMII
value|(0x0667)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSERDESCFG_SGMII
value|(0x0cc7)
end_define

begin_comment
comment|/* Port Seiral Control0 (MVNETA_PSC0) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSC0_FORCE_FC_MASK
value|(0x3<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_FORCE_FC
parameter_list|(
name|fc
parameter_list|)
value|(((fc)& 0x3)<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_FORCE_FC_PAUSE
value|MVNETA_PSC0_FORCE_FC(0x1)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_FORCE_FC_NO_PAUSE
value|MVNETA_PSC0_FORCE_FC(0x0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_FORCE_BP_MASK
value|(0x3<< 7)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_FORCE_BP
parameter_list|(
name|fc
parameter_list|)
value|(((fc)& 0x3)<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_FORCE_BP_JAM
value|MVNETA_PSC0_FORCE_BP(0x1)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_FORCE_BP_NO_JAM
value|MVNETA_PSC0_FORCE_BP(0x0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_DTE_ADV
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_IGN_RXERR
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_IGN_COLLISION
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSC0_IGN_CARRIER
value|(1<< 30)
end_define

begin_comment
comment|/* Ethernet Port Status0 (MVNETA_PS0) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PS0_TXINPROG
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PS0_TXFIFOEMP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_PS0_RXFIFOEMPTY
value|(1<< 16)
end_define

begin_comment
comment|/*  * Gigabit Ethernet MAC Serial Parameters Configuration Registers  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSPC_MUST_SET
value|(1<< 3 | 1<< 4 | 1<< 5 | 0x23<< 6)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSP1C_MUST_SET
value|(1<< 0 | 1<< 1 | 1<< 2)
end_define

begin_comment
comment|/*  * Gigabit Ethernet Auto-Negotiation Configuration Registers  */
end_comment

begin_comment
comment|/* Port Auto-Negotiation Configuration (MVNETA_PANC) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PANC_FORCELINKFAIL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_FORCELINKPASS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_INBANDANEN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_INBANDANBYPASSEN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_INBANDRESTARTAN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_SETMIISPEED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_SETGMIISPEED
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_ANSPEEDEN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_SETFCEN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_PAUSEADV
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_ANFCEN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_SETFULLDX
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_ANDUPLEXEN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|MVNETA_PANC_MUSTSET
value|(1<< 15)
end_define

begin_comment
comment|/*  * Gigabit Ethernet MAC Control Registers  */
end_comment

begin_comment
comment|/* Port MAC Control 0 (MVNETA_PMACC0) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC0_PORTEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC0_PORTTYPE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC0_FRAMESIZELIMIT
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 1)<< 2)& 0x7ffc)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC0_FRAMESIZELIMIT_MASK
value|(0x7ffc)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC0_MUSTSET
value|(1<< 15)
end_define

begin_comment
comment|/* Port MAC Control 1 (MVNETA_PMACC1) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC1_PCSLB
value|(1<< 6)
end_define

begin_comment
comment|/* Port MAC Control 2 (MVNETA_PMACC2) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC2_INBANDANMODE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC2_PCSEN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC2_PCSEN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC2_RGMIIEN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC2_PADDINGDIS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC2_PORTMACRESET
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC2_PRBSCHECKEN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC2_PRBSGENEN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMACC2_SDTT_MASK
value|(3<< 12)
end_define

begin_comment
comment|/* Select Data To Transmit */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC2_SDTT_RM
value|(0<< 12)
end_define

begin_comment
comment|/* Regular Mode */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC2_SDTT_PRBS
value|(1<< 12)
end_define

begin_comment
comment|/* PRBS Mode */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC2_SDTT_ZC
value|(2<< 12)
end_define

begin_comment
comment|/* Zero Constant */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC2_SDTT_OC
value|(3<< 12)
end_define

begin_comment
comment|/* One Constant */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC2_MUSTSET
value|(3<< 14)
end_define

begin_comment
comment|/* Port MAC Control 3 (MVNETA_PMACC3) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMACC3_IPG_MASK
value|0x7f80
end_define

begin_comment
comment|/*  * Gigabit Ethernet MAC Interrupt Registers  */
end_comment

begin_comment
comment|/* Port Interrupt Cause/Mask (MVNETA_PIC/MVNETA_PIM) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_INTSUM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PI_LSC
value|(1<< 1)
end_define

begin_comment
comment|/* LinkStatus Change */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_ACOP
value|(1<< 2)
end_define

begin_comment
comment|/* AnCompleted OnPort */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_AOOR
value|(1<< 5)
end_define

begin_comment
comment|/* AddressOut Of Range */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_SSC
value|(1<< 6)
end_define

begin_comment
comment|/* SyncStatus Change */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_PRBSEOP
value|(1<< 7)
end_define

begin_comment
comment|/* QSGMII PRBS error */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_MIBCWA
value|(1<< 15)
end_define

begin_comment
comment|/* MIB counter wrap around */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_QSGMIIPRBSE
value|(1<< 10)
end_define

begin_comment
comment|/* QSGMII PRBS error */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_PCSRXPRLPI
value|(1<< 11)
end_define

begin_comment
comment|/* PCS Rx path received LPI*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_PCSTXPRLPI
value|(1<< 12)
end_define

begin_comment
comment|/* PCS Tx path received LPI*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_MACRXPRLPI
value|(1<< 13)
end_define

begin_comment
comment|/* MAC Rx path received LPI*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PI_MIBCCD
value|(1<< 14)
end_define

begin_comment
comment|/* MIB counters copy done */
end_comment

begin_comment
comment|/*  * Gigabit Ethernet MAC Low Power Idle Registers  */
end_comment

begin_comment
comment|/* LPI Control 0 (MVNETA_LPIC0) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIC0_LILIMIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_LPIC0_TSLIMIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_comment
comment|/* LPI Control 1 (MVNETA_LPIC1) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIC1_LPIRE
value|(1<< 0)
end_define

begin_comment
comment|/* LPI request enable */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIC1_LPIRF
value|(1<< 1)
end_define

begin_comment
comment|/* LPI request force */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIC1_LPIMM
value|(1<< 2)
end_define

begin_comment
comment|/* LPI manual mode */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIC1_TWLIMIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfff)<< 4)
end_define

begin_comment
comment|/* LPI Control 2 (MVNETA_LPIC2) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIC2_MUSTSET
value|0x17d
end_define

begin_comment
comment|/* LPI Status (MVNETA_LPIS) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIS_PCSRXPLPIS
value|(1<< 0)
end_define

begin_comment
comment|/* PCS Rx path LPI status */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIS_PCSTXPLPIS
value|(1<< 1)
end_define

begin_comment
comment|/* PCS Tx path LPI status */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIS_MACRXPLPIS
value|(1<< 2)
end_define

begin_comment
comment|/* MAC Rx path LP idle status */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIS_MACTXPLPWS
value|(1<< 3)
end_define

begin_comment
comment|/* MAC Tx path LP wait status */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPIS_MACTXPLPIS
value|(1<< 4)
end_define

begin_comment
comment|/* MAC Tx path LP idle status */
end_comment

begin_comment
comment|/*  * Gigabit Ethernet MAC PRBS Check Status Registers  */
end_comment

begin_comment
comment|/* Port PRBS Status (MVNETA_PPRBSS) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PPRBSS_PRBSCHECKLOCKED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PPRBSS_PRBSCHECKRDY
value|(1<< 1)
end_define

begin_comment
comment|/*  * Gigabit Ethernet MAC Status Registers  */
end_comment

begin_comment
comment|/* Port Status Register (MVNETA_PSR) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSR_LINKUP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSR_GMIISPEED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSR_MIISPEED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSR_FULLDX
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSR_RXFCEN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSR_TXFCEN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSR_PRP
value|(1<< 6)
end_define

begin_comment
comment|/* Port Rx Pause */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSR_PTP
value|(1<< 7)
end_define

begin_comment
comment|/* Port Tx Pause */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSR_PDP
value|(1<< 8)
end_define

begin_comment
comment|/*Port is Doing Back-Pressure*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSR_SYNCFAIL10MS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSR_ANDONE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|MVNETA_PSR_IBANBA
value|(1<< 12)
end_define

begin_comment
comment|/* InBand AutoNeg BypassAct */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PSR_SYNCOK
value|(1<< 14)
end_define

begin_comment
comment|/*  * Networking Controller Interrupt Registers  */
end_comment

begin_comment
comment|/* Port CPU to Queue */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MAXCPU
value|2
end_define

begin_define
define|#
directive|define
name|MVNETA_PCP2Q_TXQEN
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 8))
end_define

begin_define
define|#
directive|define
name|MVNETA_PCP2Q_TXQEN_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_PCP2Q_RXQEN
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 0))
end_define

begin_define
define|#
directive|define
name|MVNETA_PCP2Q_RXQEN_MASK
value|(0xff<< 0)
end_define

begin_comment
comment|/* Port RX_TX Interrupt Threshold */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXITTH_RITT
parameter_list|(
name|t
parameter_list|)
value|((t)& 0xffffff)
end_define

begin_comment
comment|/* Port RX_TX Threshold Interrupt Cause/Mask (MVNETA_PRXTXTIC/MVNETA_PRXTXTIM) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_TBTCQ
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 0))
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_TBTCQ_MASK
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_GET_TBTCQ
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 0)& 0xff)
end_define

begin_comment
comment|/* Tx Buffer Threshold Cross Queue*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_RBICTAPQ
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 8))
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_RBICTAPQ_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_GET_RBICTAPQ
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 8)& 0xff)
end_define

begin_comment
comment|/* Rx Buffer Int. Coaleasing Th. Pri. Alrt Q */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_RDTAQ
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 16))
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_RDTAQ_MASK
value|(0xff<< 16)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_GET_RDTAQ
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 16)& 0xff)
end_define

begin_comment
comment|/* Rx Descriptor Threshold Alert Queue*/
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_PRXTXICSUMMARY
value|(1<< 29)
end_define

begin_comment
comment|/* PRXTXI summary */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_PTXERRORSUMMARY
value|(1<< 30)
end_define

begin_comment
comment|/* PTEXERROR summary */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXTI_PMISCICSUMMARY
value|(1UL<< 31)
end_define

begin_comment
comment|/* PMISCIC summary */
end_comment

begin_comment
comment|/* Port RX_TX Interrupt Cause/Mask (MVNETA_PRXTXIC/MVNETA_PRXTXIM) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_TBRQ
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 0))
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_TBRQ_MASK
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_GET_TBRQ
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 0)& 0xff)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_RPQ
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 8))
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_RPQ_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_GET_RPQ
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_RREQ
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 16))
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_RREQ_MASK
value|(0xff<< 16)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_GET_RREQ
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_PRXTXTHICSUMMARY
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_PTXERRORSUMMARY
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|MVNETA_PRXTXI_PMISCICSUMMARY
value|(1UL<< 31)
end_define

begin_comment
comment|/* Port Misc Interrupt Cause/Mask (MVNETA_PMIC/MVNETA_PMIM) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMI_PHYSTATUSCHNG
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMI_LINKCHANGE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMI_IAE
value|(1<< 7)
end_define

begin_comment
comment|/* Internal Address Error */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMI_RXOVERRUN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMI_RXCRCERROR
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMI_RXLARGEPACKET
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMI_TXUNDRN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMI_PRBSERROR
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMI_PSCSYNCCHANGE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|MVNETA_PMI_SRSE
value|(1<< 14)
end_define

begin_comment
comment|/* SerdesRealignSyncError */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMI_TREQ
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 24))
end_define

begin_comment
comment|/* TxResourceErrorQ */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PMI_TREQ_MASK
value|(0xff<< 24)
end_define

begin_comment
comment|/* TxResourceErrorQ */
end_comment

begin_comment
comment|/* Port Interrupt Enable (MVNETA_PIE) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PIE_RXPKTINTRPTENB
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 0))
end_define

begin_define
define|#
directive|define
name|MVNETA_PIE_TXPKTINTRPTENB
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q) + 8))
end_define

begin_define
define|#
directive|define
name|MVNETA_PIE_RXPKTINTRPTENB_MASK
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PIE_TXPKTINTRPTENB_MASK
value|(0xff<< 8)
end_define

begin_comment
comment|/*  * Miscellaneous Interrupt Registers  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PEUIAE_ADDR_MASK
value|(0x3fff)
end_define

begin_define
define|#
directive|define
name|MVNETA_PEUIAE_ADDR
parameter_list|(
name|addr
parameter_list|)
value|((addr)& 0x3fff)
end_define

begin_define
define|#
directive|define
name|MVNETA_PEUIAE_GET_ADDR
parameter_list|(
name|reg
parameter_list|)
value|((reg)& 0x3fff)
end_define

begin_comment
comment|/*  * SGMII PHY Registers  */
end_comment

begin_comment
comment|/* Power and PLL Control (MVNETA_PPLLC) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PPLLC_REF_FREF_SEL_MASK
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_PPLLC_PHY_MODE_MASK
value|(7<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_PPLLC_PHY_MODE_SATA
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_PPLLC_PHY_MODE_SAS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MVNETA_PPLLC_PLL_LOCK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MVNETA_PPLLC_PU_DFE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_PPLLC_PU_TX_INTP
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|MVNETA_PPLLC_PU_TX
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|MVNETA_PPLLC_PU_RX
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|MVNETA_PPLLC_PU_PLL
value|(1<< 14)
end_define

begin_comment
comment|/* Digital Loopback Enable (MVNETA_DLE) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_DLE_LOCAL_SEL_BITS_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_DLE_LOCAL_SEL_BITS_10BITS
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_DLE_LOCAL_SEL_BITS_20BITS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_DLE_LOCAL_SEL_BITS_40BITS
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|MVNETA_DLE_LOCAL_RXPHER_TO_TX_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|MVNETA_DLE_LOCAL_ANA_TX2RX_LPBK_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|MVNETA_DLE_LOCAL_DIG_TX2RX_LPBK_EN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|MVNETA_DLE_LOCAL_DIG_RX2TX_LPBK_EN
value|(1<< 15)
end_define

begin_comment
comment|/* Reference Clock Select (MVNETA_RCS) */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RCS_REFCLK_SEL
value|(1<< 10)
end_define

begin_comment
comment|/*  * DMA descriptors  */
end_comment

begin_struct
struct|struct
name|mvneta_tx_desc
block|{
comment|/* LITTLE_ENDIAN */
name|uint32_t
name|command
decl_stmt|;
comment|/* off 0x00: commands */
name|uint16_t
name|l4ichk
decl_stmt|;
comment|/* initial checksum */
name|uint16_t
name|bytecnt
decl_stmt|;
comment|/* 0ff 0x04: buffer byte count */
name|uint32_t
name|bufptr_pa
decl_stmt|;
comment|/* off 0x08: buffer ptr(PA) */
name|uint32_t
name|flags
decl_stmt|;
comment|/* off 0x0c: flags */
name|uint32_t
name|reserved0
decl_stmt|;
comment|/* off 0x10 */
name|uint32_t
name|reserved1
decl_stmt|;
comment|/* off 0x14 */
name|uint32_t
name|reserved2
decl_stmt|;
comment|/* off 0x18 */
name|uint32_t
name|reserved3
decl_stmt|;
comment|/* off 0x1c */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mvneta_rx_desc
block|{
comment|/* LITTLE_ENDIAN */
name|uint32_t
name|status
decl_stmt|;
comment|/* status and flags */
name|uint16_t
name|reserved0
decl_stmt|;
name|uint16_t
name|bytecnt
decl_stmt|;
comment|/* buffer byte count */
name|uint32_t
name|bufptr_pa
decl_stmt|;
comment|/* packet buffer pointer */
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|bufptr_va
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint16_t
name|l4chk
decl_stmt|;
comment|/* L4 checksum */
name|uint32_t
name|reserved3
decl_stmt|;
name|uint32_t
name|reserved4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Received packet command header:  *  network controller => software  * the controller parse the packet and set some flags.  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_IPV4_FRAGMENT
value|(1UL<< 31)
end_define

begin_comment
comment|/* Fragment Indicator */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_L4_CHECKSUM_OK
value|(1<< 30)
end_define

begin_comment
comment|/* L4 Checksum */
end_comment

begin_comment
comment|/* bit 29 reserved */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_U
value|(1<< 28)
end_define

begin_comment
comment|/* Unknown Destination */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_F
value|(1<< 27)
end_define

begin_comment
comment|/* First buffer */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_L
value|(1<< 26)
end_define

begin_comment
comment|/* Last buffer */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_IP_HEADER_OK
value|(1<< 25)
end_define

begin_comment
comment|/* IP Header is OK */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_L3_IP
value|(1<< 24)
end_define

begin_comment
comment|/* IP Type 0:IP6 1:IP4 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_L2_EV2
value|(1<< 23)
end_define

begin_comment
comment|/* Ethernet v2 frame */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_L4_MASK
value|(3<< 21)
end_define

begin_comment
comment|/* L4 Type */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_L4_TCP
value|(0x00<< 21)
end_define

begin_define
define|#
directive|define
name|MVNETA_RX_L4_UDP
value|(0x01<< 21)
end_define

begin_define
define|#
directive|define
name|MVNETA_RX_L4_OTH
value|(0x10<< 21)
end_define

begin_define
define|#
directive|define
name|MVNETA_RX_BPDU
value|(1<< 20)
end_define

begin_comment
comment|/* BPDU frame */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_VLAN
value|(1<< 19)
end_define

begin_comment
comment|/* VLAN tag found */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_EC_MASK
value|(3<< 17)
end_define

begin_comment
comment|/* Error code */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_EC_CE
value|(0x00<< 17)
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_EC_OR
value|(0x01<< 17)
end_define

begin_comment
comment|/* FIFO overrun */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_EC_MF
value|(0x10<< 17)
end_define

begin_comment
comment|/* Max. frame len */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_EC_RE
value|(0x11<< 17)
end_define

begin_comment
comment|/* Resource error */
end_comment

begin_define
define|#
directive|define
name|MVNETA_RX_ES
value|(1<< 16)
end_define

begin_comment
comment|/* Error summary */
end_comment

begin_comment
comment|/* bit 15:0 reserved */
end_comment

begin_comment
comment|/*  * Transmit packet command header:  *  software => network controller  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L4_CHECKSUM_MASK
value|(0x3<< 30)
end_define

begin_comment
comment|/* Do L4 Checksum */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L4_CHECKSUM_FRAG
value|(0x0<< 30)
end_define

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L4_CHECKSUM_NOFRAG
value|(0x1<< 30)
end_define

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L4_CHECKSUM_NONE
value|(0x2<< 30)
end_define

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_PACKET_OFFSET_MASK
value|(0x7f<< 23)
end_define

begin_comment
comment|/* Payload offset */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_W_PACKET_OFFSET
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x7f)<< 23)
end_define

begin_comment
comment|/* bit 22 reserved */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_F
value|(1<< 21)
end_define

begin_comment
comment|/* First buffer */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L
value|(1<< 20)
end_define

begin_comment
comment|/* Last buffer */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_PADDING
value|(1<< 19)
end_define

begin_comment
comment|/* Pad short frame */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_IP4_CHECKSUM
value|(1<< 18)
end_define

begin_comment
comment|/* Do IPv4 Checksum */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L3_IP4
value|(0<< 17)
end_define

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L3_IP6
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L4_TCP
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L4_UDP
value|(1<< 16)
end_define

begin_comment
comment|/* bit 15:13 reserved */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_IP_HEADER_LEN_MASK
value|(0x1f<< 8)
end_define

begin_comment
comment|/* IP header len>> 2 */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_IP_HEADER_LEN
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x1f)<< 8)
end_define

begin_comment
comment|/* bit 7 reserved */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L3_OFFSET_MASK
value|(0x7f<< 0)
end_define

begin_comment
comment|/* offset of L3 hdr. */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_CMD_L3_OFFSET
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x7f)<< 0)
end_define

begin_comment
comment|/*  * Transmit packet extra attributes  * and error status returned from network controller.  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_F_DSA_TAG
value|(3<< 30)
end_define

begin_comment
comment|/* DSA Tag */
end_comment

begin_comment
comment|/* bit 29:8 reserved */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_F_MH_SEL
value|(0xf<< 4)
end_define

begin_comment
comment|/* Marvell Header */
end_comment

begin_comment
comment|/* bit 3 reserved */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_F_EC_MASK
value|(3<< 1)
end_define

begin_comment
comment|/* Error code */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_F_EC_LC
value|(0x00<< 1)
end_define

begin_comment
comment|/* Late Collision */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_F_EC_UR
value|(0x01<< 1)
end_define

begin_comment
comment|/* Underrun */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_F_EC_RL
value|(0x10<< 1)
end_define

begin_comment
comment|/* Excess. Collision */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_F_EC_RESERVED
value|(0x11<< 1)
end_define

begin_define
define|#
directive|define
name|MVNETA_TX_F_ES
value|(1<< 0)
end_define

begin_comment
comment|/* Error summary */
end_comment

begin_define
define|#
directive|define
name|MVNETA_ERROR_SUMMARY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MVNETA_BUFFER_OWNED_MASK
value|(1UL<< 31)
end_define

begin_define
define|#
directive|define
name|MVNETA_BUFFER_OWNED_BY_HOST
value|(0UL<< 31)
end_define

begin_define
define|#
directive|define
name|MVNETA_BUFFER_OWNED_BY_DMA
value|(1UL<< 31)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_MVNETAREG_H_ */
end_comment

end_unit


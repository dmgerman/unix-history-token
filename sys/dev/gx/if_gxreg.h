begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000,2001 Jonathan Lemon  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Intel vendor ID  */
end_comment

begin_define
define|#
directive|define
name|INTEL_VENDORID
value|0x8086
end_define

begin_comment
comment|/*  * Intel gigabit ethernet device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_WISEMAN
value|0x1000
end_define

begin_define
define|#
directive|define
name|DEVICEID_LIVINGOOD_FIBER
value|0x1001
end_define

begin_define
define|#
directive|define
name|DEVICEID_LIVINGOOD_COPPER
value|0x1004
end_define

begin_define
define|#
directive|define
name|DEVICEID_CORDOVA_COPPER
value|0x1008
end_define

begin_define
define|#
directive|define
name|DEVICEID_CORDOVA_FIBER
value|0x1009
end_define

begin_define
define|#
directive|define
name|DEVICEID_CORDOVA2_COPPER
value|0x100D
end_define

begin_comment
comment|/*  * chip register offsets. These are memory mapped registers  * which can be accessed with the CSR_READ_4()/CSR_WRITE_4() macros.  * Each register must be accessed using 32 bit operations.  */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL
value|0x0000
end_define

begin_comment
comment|/* control register */
end_comment

begin_define
define|#
directive|define
name|GX_STATUS
value|0x0008
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|GX_EEPROM_CTRL
value|0x0010
end_define

begin_comment
comment|/* EEPROM/Flash control/data */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_EXT
value|0x0018
end_define

begin_comment
comment|/* extended device control */
end_comment

begin_define
define|#
directive|define
name|GX_MDIC
value|0x0020
end_define

begin_comment
comment|/* MDI control */
end_comment

begin_define
define|#
directive|define
name|GX_FLOW_CTRL_BASE
value|0x0028
end_define

begin_comment
comment|/* flow control address low/high */
end_comment

begin_define
define|#
directive|define
name|GX_FLOW_CTRL_TYPE
value|0x0030
end_define

begin_comment
comment|/* flow control type */
end_comment

begin_define
define|#
directive|define
name|GX_VET
value|0x0038
end_define

begin_comment
comment|/* VLAN ethertype */
end_comment

begin_define
define|#
directive|define
name|GX_RX_ADDR_BASE
value|0x0040
end_define

begin_comment
comment|/* 16 pairs of receive address low/high */
end_comment

begin_define
define|#
directive|define
name|GX_INT_READ
value|0x00C0
end_define

begin_comment
comment|/* read interrupts */
end_comment

begin_define
define|#
directive|define
name|GX_INT_FORCE
value|0x00C8
end_define

begin_comment
comment|/* force an interrupt */
end_comment

begin_define
define|#
directive|define
name|GX_INT_MASK_SET
value|0x00D0
end_define

begin_comment
comment|/* interrupt mask set/read */
end_comment

begin_define
define|#
directive|define
name|GX_INT_MASK_CLR
value|0x00D8
end_define

begin_comment
comment|/* interrupt mask clear */
end_comment

begin_define
define|#
directive|define
name|GX_RX_CONTROL
value|0x0100
end_define

begin_comment
comment|/* RX control */
end_comment

begin_comment
comment|/* 82542 and older 82543 chips */
end_comment

begin_define
define|#
directive|define
name|GX_RX_OLD_INTR_DELAY
value|0x0108
end_define

begin_comment
comment|/* RX delay timer */
end_comment

begin_define
define|#
directive|define
name|GX_RX_OLD_RING_BASE
value|0x0110
end_define

begin_comment
comment|/* RX descriptor base address */
end_comment

begin_define
define|#
directive|define
name|GX_RX_OLD_RING_LEN
value|0x0118
end_define

begin_comment
comment|/* RX descriptor length */
end_comment

begin_define
define|#
directive|define
name|GX_RX_OLD_RING_HEAD
value|0x0120
end_define

begin_comment
comment|/* RX descriptor head */
end_comment

begin_define
define|#
directive|define
name|GX_RX_OLD_RING_TAIL
value|0x0128
end_define

begin_comment
comment|/* RX descriptor tail */
end_comment

begin_comment
comment|/* 82542 and older 82543 chips */
end_comment

begin_define
define|#
directive|define
name|GX_OLD_FCRTH
value|0x0160
end_define

begin_comment
comment|/* flow control rcv threshhold high */
end_comment

begin_define
define|#
directive|define
name|GX_OLD_FCRTL
value|0x0168
end_define

begin_comment
comment|/* flow control rcv threshhold low */
end_comment

begin_define
define|#
directive|define
name|GX_FCTTV
value|0x0170
end_define

begin_comment
comment|/* flow control xmit timer value */
end_comment

begin_define
define|#
directive|define
name|GX_TX_CONFIG
value|0x0178
end_define

begin_comment
comment|/* xmit configuration (tbi mode) */
end_comment

begin_define
define|#
directive|define
name|GX_RX_CONFIG
value|0x0180
end_define

begin_comment
comment|/* recv configuration word */
end_comment

begin_define
define|#
directive|define
name|GX_MULTICAST_BASE
value|0x0200
end_define

begin_comment
comment|/* multicast table array base */
end_comment

begin_define
define|#
directive|define
name|GX_TX_CONTROL
value|0x0400
end_define

begin_comment
comment|/* TX control */
end_comment

begin_define
define|#
directive|define
name|GX_TX_IPG
value|0x0410
end_define

begin_comment
comment|/* TX interpacket gap */
end_comment

begin_comment
comment|/* 82542 and older 82543 chips */
end_comment

begin_define
define|#
directive|define
name|GX_TX_OLD_RING_BASE
value|0x0420
end_define

begin_comment
comment|/* TX descriptor base address */
end_comment

begin_define
define|#
directive|define
name|GX_TX_OLD_RING_LEN
value|0x0428
end_define

begin_comment
comment|/* TX descriptor length */
end_comment

begin_define
define|#
directive|define
name|GX_TX_OLD_RING_HEAD
value|0x0430
end_define

begin_comment
comment|/* TX descriptor head */
end_comment

begin_define
define|#
directive|define
name|GX_TX_OLD_RING_TAIL
value|0x0438
end_define

begin_comment
comment|/* TX descriptor tail */
end_comment

begin_define
define|#
directive|define
name|GX_TX_OLD_INTR_DELAY
value|0x0440
end_define

begin_comment
comment|/* TX interrupt delay value */
end_comment

begin_define
define|#
directive|define
name|GX_TBT
value|0x0448
end_define

begin_comment
comment|/* TX burst timer */
end_comment

begin_define
define|#
directive|define
name|GX_AIT
value|0x0458
end_define

begin_comment
comment|/* adaptive IFS throttle */
end_comment

begin_define
define|#
directive|define
name|GX_VFTA_BASE
value|0x0600
end_define

begin_comment
comment|/* VLAN filter table array base */
end_comment

begin_define
define|#
directive|define
name|GX_PKT_BUFFER_ALLOC
value|0x1000
end_define

begin_comment
comment|/* Packet buffer allocation */
end_comment

begin_define
define|#
directive|define
name|GX_ERT
value|0x2000
end_define

begin_comment
comment|/* Early receive threshold */
end_comment

begin_define
define|#
directive|define
name|GX_RX_OLD_DMA_CTRL
value|0x2028
end_define

begin_comment
comment|/* RX descriptor control */
end_comment

begin_comment
comment|/* newer 82543 chips */
end_comment

begin_define
define|#
directive|define
name|GX_FCRTH
value|0x2160
end_define

begin_comment
comment|/* flow control rcv threshhold high */
end_comment

begin_define
define|#
directive|define
name|GX_FCRTL
value|0x2168
end_define

begin_comment
comment|/* flow control rcv threshhold low */
end_comment

begin_comment
comment|/* newer 82543 chips */
end_comment

begin_define
define|#
directive|define
name|GX_RX_RING_BASE
value|0x2800
end_define

begin_comment
comment|/* RX descriptor base address */
end_comment

begin_define
define|#
directive|define
name|GX_RX_RING_LEN
value|0x2808
end_define

begin_comment
comment|/* RX descriptor length */
end_comment

begin_define
define|#
directive|define
name|GX_RX_RING_HEAD
value|0x2810
end_define

begin_comment
comment|/* RX descriptor head */
end_comment

begin_define
define|#
directive|define
name|GX_RX_RING_TAIL
value|0x2818
end_define

begin_comment
comment|/* RX descriptor tail */
end_comment

begin_define
define|#
directive|define
name|GX_RX_INTR_DELAY
value|0x2820
end_define

begin_comment
comment|/* RX delay timer */
end_comment

begin_define
define|#
directive|define
name|GX_RX_DMA_CTRL
value|0x2820
end_define

begin_comment
comment|/* RX descriptor control */
end_comment

begin_define
define|#
directive|define
name|GX_EARLY_TX_THRESH
value|0x3000
end_define

begin_comment
comment|/* early transmit threshold */
end_comment

begin_define
define|#
directive|define
name|GX_TX_OLD_DMA_CTRL
value|0x3028
end_define

begin_comment
comment|/* TX descriptor control */
end_comment

begin_comment
comment|/* newer 82543 chips */
end_comment

begin_define
define|#
directive|define
name|GX_TX_RING_BASE
value|0x3800
end_define

begin_comment
comment|/* TX descriptor base address */
end_comment

begin_define
define|#
directive|define
name|GX_TX_RING_LEN
value|0x3808
end_define

begin_comment
comment|/* TX descriptor length */
end_comment

begin_define
define|#
directive|define
name|GX_TX_RING_HEAD
value|0x3810
end_define

begin_comment
comment|/* TX descriptor head */
end_comment

begin_define
define|#
directive|define
name|GX_TX_RING_TAIL
value|0x3818
end_define

begin_comment
comment|/* TX descriptor tail */
end_comment

begin_define
define|#
directive|define
name|GX_TX_INTR_DELAY
value|0x3820
end_define

begin_comment
comment|/* TX interrupt delay value */
end_comment

begin_define
define|#
directive|define
name|GX_TX_DMA_CTRL
value|0x3828
end_define

begin_comment
comment|/* TX descriptor control */
end_comment

begin_define
define|#
directive|define
name|GX_CRCERRS
value|0x4000
end_define

begin_comment
comment|/* CRC error count */
end_comment

begin_define
define|#
directive|define
name|GX_ALGNERRC
value|0x4004
end_define

begin_comment
comment|/* alignment error count */
end_comment

begin_define
define|#
directive|define
name|GX_SYMERRS
value|0x4008
end_define

begin_comment
comment|/* symbol error count */
end_comment

begin_define
define|#
directive|define
name|GX_RXERRC
value|0x400C
end_define

begin_comment
comment|/* RX error count */
end_comment

begin_define
define|#
directive|define
name|GX_MPC
value|0x4010
end_define

begin_comment
comment|/* missed packets count */
end_comment

begin_define
define|#
directive|define
name|GX_SCC
value|0x4014
end_define

begin_comment
comment|/* single collision count */
end_comment

begin_define
define|#
directive|define
name|GX_ECOL
value|0x4018
end_define

begin_comment
comment|/* excessive collision count */
end_comment

begin_define
define|#
directive|define
name|GX_MCC
value|0x401C
end_define

begin_comment
comment|/* multiple collision count */
end_comment

begin_define
define|#
directive|define
name|GX_LATECOL
value|0x4020
end_define

begin_comment
comment|/* late collision count */
end_comment

begin_define
define|#
directive|define
name|GX_COLC
value|0x4020
end_define

begin_comment
comment|/* collision count */
end_comment

begin_define
define|#
directive|define
name|GX_TUC
value|0x402C
end_define

begin_comment
comment|/* transmit underrun count */
end_comment

begin_define
define|#
directive|define
name|GX_DC
value|0x4030
end_define

begin_comment
comment|/* defer count */
end_comment

begin_define
define|#
directive|define
name|GX_TNCRS
value|0x4034
end_define

begin_comment
comment|/* transmit - no CRS */
end_comment

begin_define
define|#
directive|define
name|GX_SEC
value|0x4038
end_define

begin_comment
comment|/* sequence error count */
end_comment

begin_define
define|#
directive|define
name|GX_CEXTERR
value|0x403C
end_define

begin_comment
comment|/* carrier extension error count */
end_comment

begin_define
define|#
directive|define
name|GX_RLEC
value|0x4040
end_define

begin_comment
comment|/* receive length error count */
end_comment

begin_define
define|#
directive|define
name|GX_RDMAUC
value|0x4044
end_define

begin_comment
comment|/* receive DMA underrun count */
end_comment

begin_define
define|#
directive|define
name|GX_XONRXC
value|0x4048
end_define

begin_comment
comment|/* XON received count */
end_comment

begin_define
define|#
directive|define
name|GX_XONTXC
value|0x404C
end_define

begin_comment
comment|/* XON transmitted count */
end_comment

begin_define
define|#
directive|define
name|GX_XOFFRXC
value|0x4050
end_define

begin_comment
comment|/* XOFF received count */
end_comment

begin_define
define|#
directive|define
name|GX_XOFFTXC
value|0x4054
end_define

begin_comment
comment|/* XOFF transmitted count */
end_comment

begin_define
define|#
directive|define
name|GX_FCRUC
value|0x4058
end_define

begin_comment
comment|/* FC received unsupported count */
end_comment

begin_define
define|#
directive|define
name|GX_PRC64
value|0x405C
end_define

begin_comment
comment|/* packets rcvd (64 bytes) */
end_comment

begin_define
define|#
directive|define
name|GX_PRC127
value|0x4060
end_define

begin_comment
comment|/* packets rcvd (65 - 127 bytes) */
end_comment

begin_define
define|#
directive|define
name|GX_PRC255
value|0x4064
end_define

begin_comment
comment|/* packets rcvd (128 - 255 bytes) */
end_comment

begin_define
define|#
directive|define
name|GX_PRC511
value|0x4068
end_define

begin_comment
comment|/* packets rcvd (256 - 511 bytes) */
end_comment

begin_define
define|#
directive|define
name|GX_PRC1023
value|0x406C
end_define

begin_comment
comment|/* packets rcvd (512 - 1023 bytes) */
end_comment

begin_define
define|#
directive|define
name|GX_PRC1522
value|0x4070
end_define

begin_comment
comment|/* packets rcvd (1023 - 1522 bytes) */
end_comment

begin_define
define|#
directive|define
name|GX_GPRC
value|0x4074
end_define

begin_comment
comment|/* good packets received */
end_comment

begin_define
define|#
directive|define
name|GX_BPRC
value|0x4078
end_define

begin_comment
comment|/* broadcast packets received */
end_comment

begin_define
define|#
directive|define
name|GX_MPRC
value|0x407C
end_define

begin_comment
comment|/* multicast packets received */
end_comment

begin_define
define|#
directive|define
name|GX_GPTC
value|0x4080
end_define

begin_comment
comment|/* good packets transmitted */
end_comment

begin_define
define|#
directive|define
name|GX_GORC
value|0x4088
end_define

begin_comment
comment|/* good octets received (low/high) */
end_comment

begin_define
define|#
directive|define
name|GX_GOTC
value|0x4090
end_define

begin_comment
comment|/* good octets transmitted (low/high) */
end_comment

begin_define
define|#
directive|define
name|GX_RNBC
value|0x40A0
end_define

begin_comment
comment|/* receive no buffers count */
end_comment

begin_define
define|#
directive|define
name|GX_RUC
value|0x40A4
end_define

begin_comment
comment|/* receive undersize count */
end_comment

begin_define
define|#
directive|define
name|GX_RFC
value|0x40A8
end_define

begin_comment
comment|/* receive fragment count */
end_comment

begin_define
define|#
directive|define
name|GX_ROC
value|0x40AC
end_define

begin_comment
comment|/* receive oversize count */
end_comment

begin_define
define|#
directive|define
name|GX_RJC
value|0x40B0
end_define

begin_comment
comment|/* receive jabber count */
end_comment

begin_define
define|#
directive|define
name|GX_TOR
value|0x40C0
end_define

begin_comment
comment|/* total octets received (low/high) */
end_comment

begin_define
define|#
directive|define
name|GX_TOT
value|0x40C8
end_define

begin_comment
comment|/* total octets transmitted (low/high) */
end_comment

begin_define
define|#
directive|define
name|GX_TPR
value|0x40D0
end_define

begin_comment
comment|/* total packets received */
end_comment

begin_define
define|#
directive|define
name|GX_TPT
value|0x40D4
end_define

begin_comment
comment|/* total packets transmitted */
end_comment

begin_define
define|#
directive|define
name|GX_PTC64
value|0x40D8
end_define

begin_comment
comment|/* packets transmitted (64 B) */
end_comment

begin_define
define|#
directive|define
name|GX_PTC127
value|0x40DC
end_define

begin_comment
comment|/* packets xmitted (65 - 127 B) */
end_comment

begin_define
define|#
directive|define
name|GX_PTC255
value|0x40E0
end_define

begin_comment
comment|/* packets xmitted (128 - 255 B) */
end_comment

begin_define
define|#
directive|define
name|GX_PTC511
value|0x40E4
end_define

begin_comment
comment|/* packets xmitted (256 - 511 B) */
end_comment

begin_define
define|#
directive|define
name|GX_PTC1023
value|0x40E8
end_define

begin_comment
comment|/* packets xmitted (512 - 1023 B) */
end_comment

begin_define
define|#
directive|define
name|GX_PTC1522
value|0x40EC
end_define

begin_comment
comment|/* packets xmitted (1023 - 1522 B) */
end_comment

begin_define
define|#
directive|define
name|GX_MPTC
value|0x40F0
end_define

begin_comment
comment|/* multicast packets transmitted */
end_comment

begin_define
define|#
directive|define
name|GX_BPTC
value|0x40F4
end_define

begin_comment
comment|/* broadcast packets transmitted */
end_comment

begin_define
define|#
directive|define
name|GX_TSCTC
value|0x40F8
end_define

begin_comment
comment|/* TCP segmentation context xmitted */
end_comment

begin_define
define|#
directive|define
name|GX_TSCTFC
value|0x40FC
end_define

begin_comment
comment|/* TCP segmentation context fail */
end_comment

begin_define
define|#
directive|define
name|GX_RX_CSUM_CONTROL
value|0x5000
end_define

begin_comment
comment|/* receive checksum control */
end_comment

begin_define
define|#
directive|define
name|GX_RDFH
value|0x8000
end_define

begin_comment
comment|/* RX data fifo head */
end_comment

begin_define
define|#
directive|define
name|GX_RDFT
value|0x8008
end_define

begin_comment
comment|/* RX data fifo tail */
end_comment

begin_define
define|#
directive|define
name|GX_TDFH
value|0x8010
end_define

begin_comment
comment|/* TX data fifo head */
end_comment

begin_define
define|#
directive|define
name|GX_TDFT
value|0x8018
end_define

begin_comment
comment|/* TX data fifo tail */
end_comment

begin_define
define|#
directive|define
name|GX_RBM_BASE
value|0x10000
end_define

begin_comment
comment|/* packet buffer memory */
end_comment

begin_comment
comment|/* GX_RX_CSUM_CONTROL */
end_comment

begin_define
define|#
directive|define
name|GX_CSUM_START_MASK
value|0x000ff
end_define

begin_define
define|#
directive|define
name|GX_CSUM_IP
value|0x00100
end_define

begin_define
define|#
directive|define
name|GX_CSUM_TCP
value|0x00200
end_define

begin_comment
comment|/* GX_CTRL register */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_DUPLEX
value|0x00000001
end_define

begin_comment
comment|/* full duplex */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_BIGENDIAN
value|0x00000002
end_define

begin_comment
comment|/* 1 == big endian */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_PCI_PRIORITY
value|0x00000004
end_define

begin_comment
comment|/* 1 == fairness */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_LINK_RESET
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GX_CTRL_TEST_MODE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GX_CTRL_AUTOSPEED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GX_CTRL_SET_LINK_UP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GX_CTRL_INVERT_LOS
value|0x00000080
end_define

begin_comment
comment|/* invert loss of signal */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_SPEEDMASK
value|0x00000300
end_define

begin_comment
comment|/* 2 bits */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_FORCESPEED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|GX_CTRL_FORCEDUPLEX
value|0x00001000
end_define

begin_define
define|#
directive|define
name|GX_CTRL_GPIO_0
value|0x00040000
end_define

begin_comment
comment|/* Software defined pin #0 */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_GPIO_1
value|0x00080000
end_define

begin_comment
comment|/* Software defined pin #1 */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_GPIO_2
value|0x00100000
end_define

begin_comment
comment|/* Software defined pin #2 */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_GPIO_3
value|0x00200000
end_define

begin_comment
comment|/* Software defined pin #3 */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_GPIO_DIR_0
value|0x00400000
end_define

begin_comment
comment|/* Pin is Input(0)/Output(1) */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_GPIO_DIR_1
value|0x00800000
end_define

begin_comment
comment|/* Pin is Input(0)/Output(1) */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_GPIO_DIR_2
value|0x01000000
end_define

begin_comment
comment|/* Pin is Input(0)/Output(1) */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_GPIO_DIR_3
value|0x02000000
end_define

begin_comment
comment|/* Pin is Input(0)/Output(1) */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_DEVICE_RESET
value|0x04000000
end_define

begin_define
define|#
directive|define
name|GX_CTRL_RX_FLOWCTRL
value|0x08000000
end_define

begin_comment
comment|/* RX flowcontrol enable */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_TX_FLOWCTRL
value|0x10000000
end_define

begin_comment
comment|/* TX flowcontrol enable */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_VLAN_ENABLE
value|0x40000000
end_define

begin_comment
comment|/* GX_STATUS register */
end_comment

begin_define
define|#
directive|define
name|GX_STAT_DUPLEX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GX_STAT_LINKUP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GX_STAT_XMITCLK_OK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GX_STAT_RECVCLK_OK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GX_STAT_XMIT_OFF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GX_STAT_TBIMODE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GX_STAT_SPEED_MASK
value|0x000000C0
end_define

begin_comment
comment|/* 2 bits, not valid w/TBI */
end_comment

begin_define
define|#
directive|define
name|GX_STAT_AUTOSPEED_MASK
value|0x00000300
end_define

begin_comment
comment|/* 2 bits, not valid w/TBI */
end_comment

begin_define
define|#
directive|define
name|GX_STAT_MTXCLK_OK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|GX_STAT_PCI66
value|0x00000800
end_define

begin_define
define|#
directive|define
name|GX_STAT_BUS64
value|0x00001000
end_define

begin_define
define|#
directive|define
name|GX_SPEED_10MB
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GX_SPEED_100MB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GX_SPEED_1000MB
value|0x00000080
end_define

begin_comment
comment|/* GX_EEPROM_CTRL register */
end_comment

begin_define
define|#
directive|define
name|GX_EE_CLOCK
value|0x0001
end_define

begin_comment
comment|/* software clock */
end_comment

begin_define
define|#
directive|define
name|GX_EE_SELECT
value|0x0002
end_define

begin_comment
comment|/* chip select */
end_comment

begin_define
define|#
directive|define
name|GX_EE_DATA_IN
value|0x0004
end_define

begin_define
define|#
directive|define
name|GX_EE_DATA_OUT
value|0x0008
end_define

begin_define
define|#
directive|define
name|GX_EE_FLASH_CTRL
value|0x0030
end_define

begin_comment
comment|/* 0x02 == enable writes */
end_comment

begin_comment
comment|/* serial EEPROM opcodes */
end_comment

begin_define
define|#
directive|define
name|GX_EE_OPC_WRITE
value|0x5
end_define

begin_define
define|#
directive|define
name|GX_EE_OPC_READ
value|0x6
end_define

begin_define
define|#
directive|define
name|GX_EE_OPC_ERASE
value|0x7
end_define

begin_define
define|#
directive|define
name|GX_EE_OPC_SIZE
value|3
end_define

begin_comment
comment|/* bits of opcode */
end_comment

begin_define
define|#
directive|define
name|GX_EE_ADDR_SIZE
value|6
end_define

begin_comment
comment|/* bits of address */
end_comment

begin_comment
comment|/* EEPROM map offsets */
end_comment

begin_define
define|#
directive|define
name|GX_EEMAP_MAC
value|0x00
end_define

begin_comment
comment|/* station address (6 bytes) */
end_comment

begin_define
define|#
directive|define
name|GX_EEMAP_INIT1
value|0x0A
end_define

begin_comment
comment|/* init control (2 bytes) */
end_comment

begin_comment
comment|/* GX_CTRL_EXT register */
end_comment

begin_define
define|#
directive|define
name|GX_CTRLX_GPIO_4
value|0x00000010
end_define

begin_comment
comment|/* Software defined pin #4 */
end_comment

begin_define
define|#
directive|define
name|GX_CTRLX_GPIO_5
value|0x00000020
end_define

begin_comment
comment|/* Software defined pin #5 */
end_comment

begin_define
define|#
directive|define
name|GX_CTRLX_GPIO_6
value|0x00000040
end_define

begin_comment
comment|/* Software defined pin #6 */
end_comment

begin_define
define|#
directive|define
name|GX_CTRLX_GPIO_7
value|0x00000080
end_define

begin_comment
comment|/* Software defined pin #7 */
end_comment

begin_define
define|#
directive|define
name|GX_CTRLX_GPIO_DIR_4
value|0x00000100
end_define

begin_comment
comment|/* Pin is Input(0)/Output(1) */
end_comment

begin_define
define|#
directive|define
name|GX_CTRLX_GPIO_DIR_5
value|0x00000200
end_define

begin_comment
comment|/* Pin is Input(0)/Output(1) */
end_comment

begin_define
define|#
directive|define
name|GX_CTRLX_GPIO_DIR_6
value|0x00000400
end_define

begin_comment
comment|/* Pin is Input(0)/Output(1) */
end_comment

begin_define
define|#
directive|define
name|GX_CTRLX_GPIO_DIR_7
value|0x00000800
end_define

begin_comment
comment|/* Pin is Input(0)/Output(1) */
end_comment

begin_define
define|#
directive|define
name|GX_CTRLX_EEPROM_RESET
value|0x00002000
end_define

begin_comment
comment|/* PCI_RST type EEPROM reset */
end_comment

begin_define
define|#
directive|define
name|GX_CTRLX_SPEED_BYPASS
value|0x00008000
end_define

begin_comment
comment|/* use CTRL.SPEED setting */
end_comment

begin_comment
comment|/*  * Defines for MII/GMII PHY.  *  * GPIO bits 0-3 are controlled by GX_CTRL, 4-7 by GX_CTRL_EXT.  */
end_comment

begin_define
define|#
directive|define
name|GX_CTRL_GPIO_DIR
value|(GX_CTRL_GPIO_DIR_3)
end_define

begin_define
define|#
directive|define
name|GX_CTRL_GPIO_DIR_MASK
value|(GX_CTRL_GPIO_DIR_0 | GX_CTRL_GPIO_DIR_1 | \ 				 GX_CTRL_GPIO_DIR_2 | GX_CTRL_GPIO_DIR_3)
end_define

begin_define
define|#
directive|define
name|GX_CTRL_PHY_IO
value|GX_CTRL_GPIO_2
end_define

begin_define
define|#
directive|define
name|GX_CTRL_PHY_IO_DIR
value|GX_CTRL_GPIO_DIR_2
end_define

begin_define
define|#
directive|define
name|GX_CTRL_PHY_CLK
value|GX_CTRL_GPIO_3
end_define

begin_define
define|#
directive|define
name|GX_CTRLX_GPIO_DIR
value|(GX_CTRLX_GPIO_DIR_4)
end_define

begin_define
define|#
directive|define
name|GX_CTRLX_GPIO_DIR_MASK
value|(GX_CTRLX_GPIO_DIR_4 | GX_CTRLX_GPIO_DIR_5 | \ 				 GX_CTRLX_GPIO_DIR_6 | GX_CTRLX_GPIO_DIR_7)
end_define

begin_define
define|#
directive|define
name|GX_CTRLX_PHY_RESET
value|GX_CTRLX_GPIO_4
end_define

begin_define
define|#
directive|define
name|GX_PHY_PREAMBLE
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|GX_PHY_PREAMBLE_LEN
value|32
end_define

begin_define
define|#
directive|define
name|GX_PHY_SOF
value|0x01
end_define

begin_define
define|#
directive|define
name|GX_PHY_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|GX_PHY_OP_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|GX_PHY_OP_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|GX_PHY_READ_LEN
value|14
end_define

begin_define
define|#
directive|define
name|GX_PHY_WRITE_LEN
value|32
end_define

begin_comment
comment|/* GX_RX_ADDR registers */
end_comment

begin_define
define|#
directive|define
name|GX_RA_VALID
value|0x80000000
end_define

begin_comment
comment|/* GX_TX_CONFIG register */
end_comment

begin_define
define|#
directive|define
name|GX_TXCFG_AUTONEG
value|0x80000000
end_define

begin_define
define|#
directive|define
name|GX_TXCFG_SWCONFIG
value|0x80000000
end_define

begin_comment
comment|/* GX_RX_CONFIG register */
end_comment

begin_define
define|#
directive|define
name|GX_RXCFG_INVALID
value|0x08000000
end_define

begin_comment
comment|/* GX_RX_CONTROL register */
end_comment

begin_define
define|#
directive|define
name|GX_RXC_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GX_RXC_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GX_RXC_STORE_BAD_PKT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GX_RXC_UNI_PROMISC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GX_RXC_MULTI_PROMISC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GX_RXC_LONG_PKT_ENABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GX_RXC_LOOPBACK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|GX_RXC_RX_THOLD_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|GX_RXC_MCAST_OFF_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|GX_RXC_BCAST_ACCEPT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|GX_RXC_RX_BSIZE_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|GX_RXC_VLAN_ENABLE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|GX_RXC_CFI_ENABLE
value|0x00080000
end_define

begin_comment
comment|/* canonical form enable */
end_comment

begin_define
define|#
directive|define
name|GX_RXC_CFI
value|0x00100000
end_define

begin_define
define|#
directive|define
name|GX_RXC_DISCARD_PAUSE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|GX_RXC_PASS_MAC
value|0x00800000
end_define

begin_define
define|#
directive|define
name|GX_RXC_RX_BSIZE_SCALE
value|0x02000000
end_define

begin_comment
comment|/* multiply BSIZE by 16 */
end_comment

begin_define
define|#
directive|define
name|GX_RXC_STRIP_ETHERCRC
value|0x04000000
end_define

begin_comment
comment|/* bits for GX_RXC_RX_THOLD */
end_comment

begin_define
define|#
directive|define
name|GX_RXC_RX_THOLD_HALF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GX_RXC_RX_THOLD_QUARTER
value|0x00000100
end_define

begin_define
define|#
directive|define
name|GX_RXC_RX_THOLD_EIGHTH
value|0x00000200
end_define

begin_comment
comment|/* bits for GX_RXC_RX_BSIZE_MASK */
end_comment

begin_define
define|#
directive|define
name|GX_RXC_RX_BSIZE_2K
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GX_RXC_RX_BSIZE_1K
value|0x00010000
end_define

begin_define
define|#
directive|define
name|GX_RXC_RX_BSIZE_512
value|0x00020000
end_define

begin_define
define|#
directive|define
name|GX_RXC_RX_BSIZE_256
value|0x00030000
end_define

begin_comment
comment|/* GX_TX_CONTROL register */
end_comment

begin_define
define|#
directive|define
name|GX_TXC_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GX_TXC_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GX_TXC_PAD_SHORT_PKTS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GX_TXC_COLL_RETRY_MASK
value|0x00000FF0
end_define

begin_define
define|#
directive|define
name|GX_TXC_COLL_TIME_MASK
value|0x003FF000
end_define

begin_define
define|#
directive|define
name|GX_TXC_XMIT_XOFF
value|0x00400000
end_define

begin_define
define|#
directive|define
name|GX_TXC_PKT_BURST_ENABLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|GX_TXC_REXMT_LATE_COLL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|GX_TXC_NO_REXMT_UNDERRN
value|0x02000000
end_define

begin_comment
comment|/* bits for GX_TXC_COLL_RETRY_MASK */
end_comment

begin_define
define|#
directive|define
name|GX_TXC_COLL_RETRY_16
value|0x000000F0
end_define

begin_comment
comment|/* 16 attempts at retransmit */
end_comment

begin_comment
comment|/* bits for GX_TXC_COLL_TIME_MASK */
end_comment

begin_define
define|#
directive|define
name|GX_TXC_COLL_TIME_HDX
value|0x00200000
end_define

begin_define
define|#
directive|define
name|GX_TXC_COLL_TIME_FDX
value|0x00040000
end_define

begin_comment
comment|/* GX_INT bits */
end_comment

begin_define
define|#
directive|define
name|GX_INT_XMIT_DONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GX_INT_XMIT_EMPTY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GX_INT_LINK_CHANGE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GX_INT_RCV_SEQ_ERR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GX_INT_RCV_THOLD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GX_INT_RCV_OVERRUN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GX_INT_RCV_TIMER
value|0x00000080
end_define

begin_define
define|#
directive|define
name|GX_INT_MDIO_DONE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|GX_INT_C_SETS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|GX_INT_GPI_MASK
value|0x00007800
end_define

begin_define
define|#
directive|define
name|GX_INT_ALL
define|\
value|(GX_INT_XMIT_DONE | GX_INT_XMIT_EMPTY | GX_INT_LINK_CHANGE | \ 	GX_INT_RCV_SEQ_ERR | GX_INT_RCV_THOLD | GX_INT_RCV_OVERRUN | \ 	GX_INT_RCV_TIMER | GX_INT_MDIO_DONE | GX_INT_C_SETS | GX_INT_GPI_MASK)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|GX_INT_WANTED
define|\
value|(GX_INT_XMIT_DONE |
comment|/*GX_INT_XMIT_EMPTY |*/
value|GX_INT_LINK_CHANGE | \ 	GX_INT_RCV_SEQ_ERR | GX_INT_RCV_THOLD | GX_INT_RCV_OVERRUN | \ 	GX_INT_RCV_TIMER | GX_INT_C_SETS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GX_INT_WANTED
define|\
value|(GX_INT_XMIT_DONE | GX_INT_RCV_THOLD | GX_INT_RCV_TIMER | \ 	GX_INT_LINK_CHANGE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCI space */
end_comment

begin_define
define|#
directive|define
name|GX_PCI_VENDOR_ID
value|0x0000
end_define

begin_define
define|#
directive|define
name|GX_PCI_DEVICE_ID
value|0x0002
end_define

begin_define
define|#
directive|define
name|GX_PCI_COMMAND
value|0x0004
end_define

begin_define
define|#
directive|define
name|GX_PCI_STATUS
value|0x0006
end_define

begin_define
define|#
directive|define
name|GX_PCI_REVID
value|0x0008
end_define

begin_define
define|#
directive|define
name|GX_PCI_CLASSCODE
value|0x0009
end_define

begin_define
define|#
directive|define
name|GX_PCI_CACHELEN
value|0x000C
end_define

begin_define
define|#
directive|define
name|GX_PCI_LATENCY_TIMER
value|0x000D
end_define

begin_define
define|#
directive|define
name|GX_PCI_HEADER_TYPE
value|0x000E
end_define

begin_define
define|#
directive|define
name|GX_PCI_LOMEM
value|0x0010
end_define

begin_define
define|#
directive|define
name|GX_PCI_SUBVEN_ID
value|0x002C
end_define

begin_define
define|#
directive|define
name|GX_PCI_SYBSYS_ID
value|0x002E
end_define

begin_define
define|#
directive|define
name|GX_PCI_BIOSROM
value|0x0030
end_define

begin_define
define|#
directive|define
name|GX_PCI_CAPABILITY_PTR
value|0x0034
end_define

begin_define
define|#
directive|define
name|GX_PCI_INTLINE
value|0x003C
end_define

begin_define
define|#
directive|define
name|GX_PCI_INTPIN
value|0x003D
end_define

begin_define
define|#
directive|define
name|GX_PCI_MINGNT
value|0x003E
end_define

begin_define
define|#
directive|define
name|GX_PCI_MINLAT
value|0x003F
end_define

begin_comment
comment|/* generic TX descriptor */
end_comment

begin_struct
struct|struct
name|gx_tx_desc
block|{
name|u_int64_t
label|:
literal|64
expr_stmt|;
name|u_int16_t
label|:
literal|16
expr_stmt|;
name|u_int8_t
label|:
literal|4
operator|,
name|tx_type
operator|:
literal|4
operator|,
name|u_int8_t
operator|:
literal|5
operator|,
name|tx_extended
operator|:
literal|1
operator|,
operator|:
literal|2
expr_stmt|;
name|u_int32_t
label|:
literal|32
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* legacy TX descriptor */
end_comment

begin_struct
struct|struct
name|gx_tx_desc_old
block|{
name|u_int64_t
name|tx_addr
decl_stmt|;
name|u_int16_t
name|tx_len
decl_stmt|;
name|u_int8_t
name|tx_csum_offset
decl_stmt|;
name|u_int8_t
name|tx_command
decl_stmt|;
name|u_int8_t
name|tx_status
decl_stmt|;
name|u_int8_t
name|tx_csum_start
decl_stmt|;
name|u_int16_t
name|tx_vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GX_TXOLD_END_OF_PKT
value|0x01
end_define

begin_comment
comment|/* end of packet */
end_comment

begin_define
define|#
directive|define
name|GX_TXOLD_ETHER_CRC
value|0x02
end_define

begin_comment
comment|/* insert ethernet CRC */
end_comment

begin_define
define|#
directive|define
name|GX_TXOLD_INSERT_CSUM
value|0x04
end_define

begin_comment
comment|/* insert checksum */
end_comment

begin_define
define|#
directive|define
name|GX_TXOLD_REPORT_STATUS
value|0x08
end_define

begin_comment
comment|/* report packet status */
end_comment

begin_define
define|#
directive|define
name|GX_TXOLD_REPORT_SENT
value|0x10
end_define

begin_comment
comment|/* report packet sent */
end_comment

begin_define
define|#
directive|define
name|GX_TXOLD_EXTENSION
value|0x20
end_define

begin_comment
comment|/* extended format */
end_comment

begin_define
define|#
directive|define
name|GX_TXOLD_VLAN_ENABLE
value|0x40
end_define

begin_comment
comment|/* use vlan */
end_comment

begin_define
define|#
directive|define
name|GX_TXOLD_INT_DELAY
value|0x80
end_define

begin_comment
comment|/* delay interrupt */
end_comment

begin_comment
comment|/* bits for tx_status */
end_comment

begin_define
define|#
directive|define
name|GX_TXSTAT_DONE
value|0x01
end_define

begin_comment
comment|/* descriptor done */
end_comment

begin_define
define|#
directive|define
name|GX_TXSTAT_EXCESS_COLL
value|0x02
end_define

begin_comment
comment|/* excess collisions */
end_comment

begin_define
define|#
directive|define
name|GX_TXSTAT_LATE_COLL
value|0x04
end_define

begin_comment
comment|/* late collision */
end_comment

begin_define
define|#
directive|define
name|GX_TXSTAT_UNDERRUN
value|0x08
end_define

begin_comment
comment|/* transmit underrun */
end_comment

begin_comment
comment|/* TX descriptor for checksum offloading context */
end_comment

begin_struct
struct|struct
name|gx_tx_desc_ctx
block|{
name|u_int8_t
name|tx_ip_csum_start
decl_stmt|;
name|u_int8_t
name|tx_ip_csum_offset
decl_stmt|;
name|u_int16_t
name|tx_ip_csum_end
decl_stmt|;
name|u_int8_t
name|tx_tcp_csum_start
decl_stmt|;
name|u_int8_t
name|tx_tcp_csum_offset
decl_stmt|;
name|u_int16_t
name|tx_tcp_csum_end
decl_stmt|;
name|u_int32_t
name|tx_len
range|:
literal|20
decl_stmt|,
name|tx_type
range|:
literal|4
decl_stmt|,
name|tx_command
range|:
literal|8
decl_stmt|;
name|u_int8_t
name|tx_status
decl_stmt|;
name|u_int8_t
name|tx_hdrlen
decl_stmt|;
name|u_int16_t
name|tx_mss
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GX_TXCTX_TCP_PKT
value|0x01
end_define

begin_comment
comment|/* its a TCP packet */
end_comment

begin_define
define|#
directive|define
name|GX_TXCTX_IP_PKT
value|0x02
end_define

begin_comment
comment|/* its an IP packet */
end_comment

begin_define
define|#
directive|define
name|GX_TXCTX_TCP_SEG_EN
value|0x04
end_define

begin_comment
comment|/* TCP segmentation enable */
end_comment

begin_define
define|#
directive|define
name|GX_TXCTX_REPORT_STATUS
value|0x08
end_define

begin_comment
comment|/* report packet status */
end_comment

begin_define
define|#
directive|define
name|GX_TXCTX_EXTENSION
value|0x20
end_define

begin_comment
comment|/* extended format */
end_comment

begin_define
define|#
directive|define
name|GX_TXCTX_INT_DELAY
value|0x80
end_define

begin_comment
comment|/* delay interrupt */
end_comment

begin_comment
comment|/* TX descriptor for data */
end_comment

begin_struct
struct|struct
name|gx_tx_desc_data
block|{
name|u_int64_t
name|tx_addr
decl_stmt|;
name|u_int32_t
name|tx_len
range|:
literal|20
decl_stmt|,
name|tx_type
range|:
literal|4
decl_stmt|,
name|tx_command
range|:
literal|8
decl_stmt|;
name|u_int8_t
name|tx_status
decl_stmt|;
name|u_int8_t
name|tx_options
decl_stmt|;
name|u_int16_t
name|tx_vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GX_TXTCP_END_OF_PKT
value|0x01
end_define

begin_comment
comment|/* end of packet */
end_comment

begin_define
define|#
directive|define
name|GX_TXTCP_ETHER_CRC
value|0x02
end_define

begin_comment
comment|/* insert ethernet CRC */
end_comment

begin_define
define|#
directive|define
name|GX_TXTCP_TCP_SEG_EN
value|0x04
end_define

begin_comment
comment|/* TCP segmentation enable */
end_comment

begin_define
define|#
directive|define
name|GX_TXTCP_REPORT_STATUS
value|0x08
end_define

begin_comment
comment|/* report packet status */
end_comment

begin_define
define|#
directive|define
name|GX_TXTCP_REPORT_SENT
value|0x10
end_define

begin_comment
comment|/* report packet sent */
end_comment

begin_define
define|#
directive|define
name|GX_TXTCP_EXTENSION
value|0x20
end_define

begin_comment
comment|/* extended format */
end_comment

begin_define
define|#
directive|define
name|GX_TXTCP_VLAN_ENABLE
value|0x40
end_define

begin_comment
comment|/* use vlan */
end_comment

begin_define
define|#
directive|define
name|GX_TXTCP_INT_DELAY
value|0x80
end_define

begin_comment
comment|/* delay interrupt */
end_comment

begin_comment
comment|/* bits for tx_options */
end_comment

begin_define
define|#
directive|define
name|GX_TXTCP_OPT_IP_CSUM
value|0x01
end_define

begin_comment
comment|/* insert IP checksum */
end_comment

begin_define
define|#
directive|define
name|GX_TXTCP_OPT_TCP_CSUM
value|0x02
end_define

begin_comment
comment|/* insert UDP/TCP checksum */
end_comment

begin_comment
comment|/* RX descriptor data structure */
end_comment

begin_struct
struct|struct
name|gx_rx_desc
block|{
name|u_int64_t
name|rx_addr
decl_stmt|;
name|u_int16_t
name|rx_len
decl_stmt|;
name|u_int16_t
name|rx_csum
decl_stmt|;
name|u_int16_t
name|rx_staterr
decl_stmt|;
comment|/* status + error fields */
name|u_int16_t
name|rx_special
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* bits for rx_status portion of rx_staterr */
end_comment

begin_define
define|#
directive|define
name|GX_RXSTAT_COMPLETED
value|0x01
end_define

begin_comment
comment|/* completed */
end_comment

begin_define
define|#
directive|define
name|GX_RXSTAT_END_OF_PACKET
value|0x02
end_define

begin_comment
comment|/* end of this packet */
end_comment

begin_define
define|#
directive|define
name|GX_RXSTAT_IGNORE_CSUM
value|0x04
end_define

begin_comment
comment|/* ignore computed checksum */
end_comment

begin_define
define|#
directive|define
name|GX_RXSTAT_VLAN_PKT
value|0x08
end_define

begin_comment
comment|/* matched vlan */
end_comment

begin_define
define|#
directive|define
name|GX_RXSTAT_HAS_TCP_CSUM
value|0x20
end_define

begin_comment
comment|/* TCP checksum calculated */
end_comment

begin_define
define|#
directive|define
name|GX_RXSTAT_HAS_IP_CSUM
value|0x40
end_define

begin_comment
comment|/* IP checksum calculated */
end_comment

begin_define
define|#
directive|define
name|GX_RXSTAT_INEXACT_MATCH
value|0x80
end_define

begin_comment
comment|/* must check address */
end_comment

begin_comment
comment|/* bits for rx_error portion of rx_staterr */
end_comment

begin_define
define|#
directive|define
name|GX_RXERR_CRC
value|0x0100
end_define

begin_comment
comment|/* CRC or alignment error */
end_comment

begin_define
define|#
directive|define
name|GX_RXERR_SYMBOL
value|0x0200
end_define

begin_comment
comment|/* symbol error */
end_comment

begin_define
define|#
directive|define
name|GX_RXERR_SEQUENCE
value|0x0400
end_define

begin_comment
comment|/* sequence error */
end_comment

begin_define
define|#
directive|define
name|GX_RXERR_CARRIER
value|0x1000
end_define

begin_comment
comment|/* carrier extension error */
end_comment

begin_define
define|#
directive|define
name|GX_RXERR_TCP_CSUM
value|0x2000
end_define

begin_comment
comment|/* TCP/UDP checksum error */
end_comment

begin_define
define|#
directive|define
name|GX_RXERR_IP_CSUM
value|0x4000
end_define

begin_comment
comment|/* IP checksum error */
end_comment

begin_define
define|#
directive|define
name|GX_RXERR_RX_DATA
value|0x8000
end_define

begin_comment
comment|/* RX data error */
end_comment

begin_comment
comment|/* drop packet on these errors */
end_comment

begin_define
define|#
directive|define
name|GX_INPUT_ERROR
define|\
value|(GX_RXERR_CRC | GX_RXERR_SYMBOL | GX_RXERR_SEQUENCE | \ 	GX_RXERR_CARRIER | GX_RXERR_RX_DATA)
end_define

end_unit


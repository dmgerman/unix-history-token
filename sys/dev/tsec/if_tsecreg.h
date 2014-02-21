begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008-2009 Semihalf, Piotr Ziecik  * Copyright (C) 2006-2007 Semihalf, Piotr Kruszynski  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_ID
value|0x000
end_define

begin_comment
comment|/* Controller ID register #1. */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_ID2
value|0x004
end_define

begin_comment
comment|/* Controller ID register #2. */
end_comment

begin_comment
comment|/* TSEC General Control and Status Registers */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IEVENT
value|0x010
end_define

begin_comment
comment|/* Interrupt event register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IMASK
value|0x014
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_EDIS
value|0x018
end_define

begin_comment
comment|/* Error disabled register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_ECNTRL
value|0x020
end_define

begin_comment
comment|/* Ethernet control register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MINFLR
value|0x024
end_define

begin_comment
comment|/* Minimum frame length register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_PTV
value|0x028
end_define

begin_comment
comment|/* Pause time value register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_DMACTRL
value|0x02c
end_define

begin_comment
comment|/* DMA control register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_TBIPA
value|0x030
end_define

begin_comment
comment|/* TBI PHY address register */
end_comment

begin_comment
comment|/* TSEC FIFO Control and Status Registers */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_FIFO_PAUSE_CTRL
value|0x04c
end_define

begin_comment
comment|/* FIFO pause control register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_FIFO_TX_THR
value|0x08c
end_define

begin_comment
comment|/* FIFO transmit threshold register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_FIFO_TX_STARVE
value|0x098
end_define

begin_comment
comment|/* FIFO transmit starve register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_FIFO_TX_STARVE_SHUTOFF
value|0x09c
end_define

begin_comment
comment|/* FIFO transmit starve shutoff 					       * register */
end_comment

begin_comment
comment|/* TSEC Transmit Control and Status Registers */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_TCTRL
value|0x100
end_define

begin_comment
comment|/* Transmit control register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_TSTAT
value|0x104
end_define

begin_comment
comment|/* Transmit Status Register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_TBDLEN
value|0x10c
end_define

begin_comment
comment|/* TxBD data length register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_TXIC
value|0x110
end_define

begin_comment
comment|/* Transmit interrupt coalescing 				       * configuration register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_CTBPTR
value|0x124
end_define

begin_comment
comment|/* Current TxBD pointer register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_TBPTR
value|0x184
end_define

begin_comment
comment|/* TxBD pointer register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_TBASE
value|0x204
end_define

begin_comment
comment|/* TxBD base address register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_OSTBD
value|0x2b0
end_define

begin_comment
comment|/* Out-of-sequence TxBD register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_OSTBDP
value|0x2b4
end_define

begin_comment
comment|/* Out-of-sequence Tx data buffer pointer 				       * register */
end_comment

begin_comment
comment|/* TSEC Receive Control and Status Registers */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_RCTRL
value|0x300
end_define

begin_comment
comment|/* Receive control register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_RSTAT
value|0x304
end_define

begin_comment
comment|/* Receive status register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_RBDLEN
value|0x30c
end_define

begin_comment
comment|/* RxBD data length register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_RXIC
value|0x310
end_define

begin_comment
comment|/* Receive interrupt coalescing 				       * configuration register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_CRBPTR
value|0x324
end_define

begin_comment
comment|/* Current RxBD pointer register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MRBLR
value|0x340
end_define

begin_comment
comment|/* Maximum receive buffer length register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_RBPTR
value|0x384
end_define

begin_comment
comment|/* RxBD pointer register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_RBASE
value|0x404
end_define

begin_comment
comment|/* RxBD base address register */
end_comment

begin_comment
comment|/* TSEC MAC Registers */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MACCFG1
value|0x500
end_define

begin_comment
comment|/* MAC configuration 1 register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MACCFG2
value|0x504
end_define

begin_comment
comment|/* MAC configuration 2 register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IPGIFG
value|0x508
end_define

begin_comment
comment|/* Inter-packet gap/inter-frame gap 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_HAFDUP
value|0x50c
end_define

begin_comment
comment|/* Half-duplex register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MAXFRM
value|0x510
end_define

begin_comment
comment|/* Maximum frame length register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MIIBASE
value|0x520
end_define

begin_comment
comment|/* MII Management base, rest offsets */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MIIMCFG
value|0x0
end_define

begin_comment
comment|/* MII Management configuration register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MIIMCOM
value|0x4
end_define

begin_comment
comment|/* MII Management command register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MIIMADD
value|0x8
end_define

begin_comment
comment|/* MII Management address register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MIIMCON
value|0xc
end_define

begin_comment
comment|/* MII Management control register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MIIMSTAT
value|0x10
end_define

begin_comment
comment|/* MII Management status register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MIIMIND
value|0x14
end_define

begin_comment
comment|/* MII Management indicator register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IFSTAT
value|0x53c
end_define

begin_comment
comment|/* Interface status register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MACSTNADDR1
value|0x540
end_define

begin_comment
comment|/* Station address register, part 1 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MACSTNADDR2
value|0x544
end_define

begin_comment
comment|/* Station address register, part 2 */
end_comment

begin_comment
comment|/* TSEC Transmit and Receive Counters */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TR64
value|0x680
end_define

begin_comment
comment|/* Transmit and receive 64-byte 				       * frame counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TR127
value|0x684
end_define

begin_comment
comment|/* Transmit and receive 65-127 byte 				       * frame counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TR255
value|0x688
end_define

begin_comment
comment|/* Transmit and receive 128-255 byte 				       * frame counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TR511
value|0x68c
end_define

begin_comment
comment|/* Transmit and receive 256-511 byte 				       * frame counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TR1K
value|0x690
end_define

begin_comment
comment|/* Transmit and receive 512-1023 byte 				       * frame counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TRMAX
value|0x694
end_define

begin_comment
comment|/* Transmit and receive 1024-1518 byte 				       * frame counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TRMGV
value|0x698
end_define

begin_comment
comment|/* Transmit and receive 1519-1522 byte 				       * good VLAN frame counter register */
end_comment

begin_comment
comment|/* TSEC Receive Counters */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RBYT
value|0x69c
end_define

begin_comment
comment|/* Receive byte counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RPKT
value|0x6a0
end_define

begin_comment
comment|/* Receive packet counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RFCS
value|0x6a4
end_define

begin_comment
comment|/* Receive FCS error counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RMCA
value|0x6a8
end_define

begin_comment
comment|/* Receive multicast packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RBCA
value|0x6ac
end_define

begin_comment
comment|/* Receive broadcast packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RXCF
value|0x6b0
end_define

begin_comment
comment|/* Receive control frame packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RXPF
value|0x6b4
end_define

begin_comment
comment|/* Receive pause frame packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RXUO
value|0x6b8
end_define

begin_comment
comment|/* Receive unknown OP code counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RALN
value|0x6bc
end_define

begin_comment
comment|/* Receive alignment error counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RFLR
value|0x6c0
end_define

begin_comment
comment|/* Receive frame length error counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RCDE
value|0x6c4
end_define

begin_comment
comment|/* Receive code error counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RCSE
value|0x6c8
end_define

begin_comment
comment|/* Receive carrier sense error counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RUND
value|0x6cc
end_define

begin_comment
comment|/* Receive undersize packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_ROVR
value|0x6d0
end_define

begin_comment
comment|/* Receive oversize packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RFRG
value|0x6d4
end_define

begin_comment
comment|/* Receive fragments counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RJBR
value|0x6d8
end_define

begin_comment
comment|/* Receive jabber counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_RDRP
value|0x6dc
end_define

begin_comment
comment|/* Receive drop counter register */
end_comment

begin_comment
comment|/* TSEC Transmit Counters */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TBYT
value|0x6e0
end_define

begin_comment
comment|/* Transmit byte counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TPKT
value|0x6e4
end_define

begin_comment
comment|/* Transmit packet counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TMCA
value|0x6e8
end_define

begin_comment
comment|/* Transmit multicast packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TBCA
value|0x6ec
end_define

begin_comment
comment|/* Transmit broadcast packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TXPF
value|0x6f0
end_define

begin_comment
comment|/* Transmit PAUSE control frame counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TDFR
value|0x6f4
end_define

begin_comment
comment|/* Transmit deferral packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TEDF
value|0x6f8
end_define

begin_comment
comment|/* Transmit excessive deferral packet 				       * counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TSCL
value|0x6fc
end_define

begin_comment
comment|/* Transmit single collision packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TMCL
value|0x700
end_define

begin_comment
comment|/* Transmit multiple collision packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TLCL
value|0x704
end_define

begin_comment
comment|/* Transmit late collision packet counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TXCL
value|0x708
end_define

begin_comment
comment|/* Transmit excessive collision packet 				       * counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TNCL
value|0x70c
end_define

begin_comment
comment|/* Transmit total collision counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TDRP
value|0x714
end_define

begin_comment
comment|/* Transmit drop frame counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TJBR
value|0x718
end_define

begin_comment
comment|/* Transmit jabber frame counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TFCS
value|0x71c
end_define

begin_comment
comment|/* Transmit FCS error counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TXCF
value|0x720
end_define

begin_comment
comment|/* Transmit control frame counter register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TOVR
value|0x724
end_define

begin_comment
comment|/* Transmit oversize frame counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TUND
value|0x728
end_define

begin_comment
comment|/* Transmit undersize frame counter 				       * register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_TFRG
value|0x72c
end_define

begin_comment
comment|/* Transmit fragments frame counter 				       * register */
end_comment

begin_comment
comment|/* TSEC General Registers */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_CAR1
value|0x730
end_define

begin_comment
comment|/* Carry register one register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_CAR2
value|0x734
end_define

begin_comment
comment|/* Carry register two register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_CAM1
value|0x738
end_define

begin_comment
comment|/* Carry register one mask register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_MON_CAM2
value|0x73c
end_define

begin_comment
comment|/* Carry register two mask register */
end_comment

begin_comment
comment|/* TSEC Hash Function Registers */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IADDR0
value|0x800
end_define

begin_comment
comment|/* Indivdual address register 0 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IADDR1
value|0x804
end_define

begin_comment
comment|/* Indivdual address register 1 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IADDR2
value|0x808
end_define

begin_comment
comment|/* Indivdual address register 2 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IADDR3
value|0x80c
end_define

begin_comment
comment|/* Indivdual address register 3 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IADDR4
value|0x810
end_define

begin_comment
comment|/* Indivdual address register 4 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IADDR5
value|0x814
end_define

begin_comment
comment|/* Indivdual address register 5 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IADDR6
value|0x818
end_define

begin_comment
comment|/* Indivdual address register 6 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IADDR7
value|0x81c
end_define

begin_comment
comment|/* Indivdual address register 7 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_GADDR0
value|0x880
end_define

begin_comment
comment|/* Group address register 0 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_GADDR1
value|0x884
end_define

begin_comment
comment|/* Group address register 1 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_GADDR2
value|0x888
end_define

begin_comment
comment|/* Group address register 2 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_GADDR3
value|0x88c
end_define

begin_comment
comment|/* Group address register 3 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_GADDR4
value|0x890
end_define

begin_comment
comment|/* Group address register 4 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_GADDR5
value|0x894
end_define

begin_comment
comment|/* Group address register 5 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_GADDR6
value|0x898
end_define

begin_comment
comment|/* Group address register 6 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_GADDR7
value|0x89c
end_define

begin_comment
comment|/* Group address register 7 */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_IADDR
parameter_list|(
name|n
parameter_list|)
value|(TSEC_REG_IADDR0 + (n<< 2))
end_define

begin_define
define|#
directive|define
name|TSEC_REG_GADDR
parameter_list|(
name|n
parameter_list|)
value|(TSEC_REG_GADDR0 + (n<< 2))
end_define

begin_comment
comment|/* TSEC attribute registers */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_ATTR
value|0xbf8
end_define

begin_comment
comment|/* Attributes Register */
end_comment

begin_define
define|#
directive|define
name|TSEC_REG_ATTRELI
value|0xbfc
end_define

begin_comment
comment|/* Attributes EL& EI register */
end_comment

begin_comment
comment|/* Size of TSEC registers area */
end_comment

begin_define
define|#
directive|define
name|TSEC_IO_SIZE
value|0x1000
end_define

begin_comment
comment|/* reg bits */
end_comment

begin_define
define|#
directive|define
name|TSEC_FIFO_PAUSE_CTRL_EN
value|0x0002
end_define

begin_define
define|#
directive|define
name|TSEC_DMACTRL_TDSEN
value|0x00000080
end_define

begin_comment
comment|/* Tx Data snoop enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_DMACTRL_TBDSEN
value|0x00000040
end_define

begin_comment
comment|/* TxBD snoop enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_DMACTRL_GRS
value|0x00000010
end_define

begin_comment
comment|/* Graceful receive stop */
end_comment

begin_define
define|#
directive|define
name|TSEC_DMACTRL_GTS
value|0x00000008
end_define

begin_comment
comment|/* Graceful transmit stop */
end_comment

begin_define
define|#
directive|define
name|DMACTRL_WWR
value|0x00000002
end_define

begin_comment
comment|/* Write with response */
end_comment

begin_define
define|#
directive|define
name|DMACTRL_WOP
value|0x00000001
end_define

begin_comment
comment|/* Wait or poll */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_VLEX
value|0x00002000
end_define

begin_comment
comment|/* Enable automatic VLAN tag 						    * extraction and deletion 						    * from Ethernet frames */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_IPCSEN
value|0x00000200
end_define

begin_comment
comment|/* IP Checksum verification enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_TUCSEN
value|0x00000100
end_define

begin_comment
comment|/* TCP or UDP Checksum verification enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_PRSDEP
value|0x000000C0
end_define

begin_comment
comment|/* Parser control */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCRTL_PRSFM
value|0x00000020
end_define

begin_comment
comment|/* FIFO-mode parsing */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_BC_REJ
value|0x00000010
end_define

begin_comment
comment|/* Broadcast frame reject */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_PROM
value|0x00000008
end_define

begin_comment
comment|/* Promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_RSF
value|0x00000004
end_define

begin_comment
comment|/* Receive short frame mode */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_PRSDEP_PARSER_OFF
value|0x00000000
end_define

begin_comment
comment|/* Parser Disabled */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_PRSDEP_PARSE_L2
value|0x00000040
end_define

begin_comment
comment|/* Parse L2 */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_PRSDEP_PARSE_L23
value|0x00000080
end_define

begin_comment
comment|/* Parse L2 and L3 */
end_comment

begin_define
define|#
directive|define
name|TSEC_RCTRL_PRSDEP_PARSE_L234
value|0x000000C0
end_define

begin_comment
comment|/* Parse L2, L3 and L4 */
end_comment

begin_define
define|#
directive|define
name|TSEC_TCTRL_IPCSEN
value|0x00004000
end_define

begin_comment
comment|/* IP header checksum generation enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_TCTRL_TUCSEN
value|0x00002000
end_define

begin_comment
comment|/* TCP/UDP header checksum generation enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_TSTAT_THLT
value|0x80000000
end_define

begin_comment
comment|/* Transmit halt */
end_comment

begin_define
define|#
directive|define
name|TSEC_RSTAT_QHLT
value|0x00800000
end_define

begin_comment
comment|/* RxBD queue is halted */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_BABR
value|0x80000000
end_define

begin_comment
comment|/* Babbling receive error */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_RXC
value|0x40000000
end_define

begin_comment
comment|/* Receive control interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_BSY
value|0x20000000
end_define

begin_comment
comment|/* Busy condition interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_EBERR
value|0x10000000
end_define

begin_comment
comment|/* Ethernet bus error */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_MSRO
value|0x04000000
end_define

begin_comment
comment|/* MSTAT Register Overflow */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_GTSC
value|0x02000000
end_define

begin_comment
comment|/* Graceful transmit stop complete */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_BABT
value|0x01000000
end_define

begin_comment
comment|/* Babbling transmit error */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_TXC
value|0x00800000
end_define

begin_comment
comment|/* Transmit control interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_TXE
value|0x00400000
end_define

begin_comment
comment|/* Transmit error */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_TXB
value|0x00200000
end_define

begin_comment
comment|/* Transmit buffer */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_TXF
value|0x00100000
end_define

begin_comment
comment|/* Transmit frame interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_LC
value|0x00040000
end_define

begin_comment
comment|/* Late collision */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_CRL
value|0x00020000
end_define

begin_comment
comment|/* Collision retry limit/excessive 						    * defer abort */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_XFUN
value|0x00010000
end_define

begin_comment
comment|/* Transmit FIFO underrun */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_RXB
value|0x00008000
end_define

begin_comment
comment|/* Receive buffer */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_MMRD
value|0x00000400
end_define

begin_comment
comment|/* MII management read completion */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_MMWR
value|0x00000200
end_define

begin_comment
comment|/* MII management write completion */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_GRSC
value|0x00000100
end_define

begin_comment
comment|/* Graceful receive stop complete */
end_comment

begin_define
define|#
directive|define
name|TSEC_IEVENT_RXF
value|0x00000080
end_define

begin_comment
comment|/* Receive frame interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_BREN
value|0x80000000
end_define

begin_comment
comment|/* Babbling receiver interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_RXCEN
value|0x40000000
end_define

begin_comment
comment|/* Receive control interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_BSYEN
value|0x20000000
end_define

begin_comment
comment|/* Busy interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_EBERREN
value|0x10000000
end_define

begin_comment
comment|/* Ethernet controller bus error */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_MSROEN
value|0x04000000
end_define

begin_comment
comment|/* MSTAT register overflow interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_GTSCEN
value|0x02000000
end_define

begin_comment
comment|/* Graceful transmit stop complete interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_BTEN
value|0x01000000
end_define

begin_comment
comment|/* Babbling transmitter interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_TXCEN
value|0x00800000
end_define

begin_comment
comment|/* Transmit control interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_TXEEN
value|0x00400000
end_define

begin_comment
comment|/* Transmit error interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_TXBEN
value|0x00200000
end_define

begin_comment
comment|/* Transmit buffer interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_TXFEN
value|0x00100000
end_define

begin_comment
comment|/* Transmit frame interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_LCEN
value|0x00040000
end_define

begin_comment
comment|/* Late collision */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_CRLEN
value|0x00020000
end_define

begin_comment
comment|/* Collision retry limit/excessive defer */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_XFUNEN
value|0x00010000
end_define

begin_comment
comment|/* Transmit FIFO underrun */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_RXBEN
value|0x00008000
end_define

begin_comment
comment|/* Receive buffer interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_MMRD
value|0x00000400
end_define

begin_comment
comment|/* MII management read completion */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_MMWR
value|0x00000200
end_define

begin_comment
comment|/* MII management write completion */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_GRSCEN
value|0x00000100
end_define

begin_comment
comment|/* Graceful receive stop complete interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_IMASK_RXFEN
value|0x00000080
end_define

begin_comment
comment|/* Receive frame interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_ATTR_ELCWT
value|0x00004000
end_define

begin_comment
comment|/* Write extracted data to L2 cache */
end_comment

begin_define
define|#
directive|define
name|TSEC_ATTR_BDLWT
value|0x00000800
end_define

begin_comment
comment|/* Write buffer descriptor to L2 cache */
end_comment

begin_define
define|#
directive|define
name|TSEC_ATTR_RDSEN
value|0x00000080
end_define

begin_comment
comment|/* Rx data snoop enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_ATTR_RBDSEN
value|0x00000040
end_define

begin_comment
comment|/* RxBD snoop enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_SOFT_RESET
value|0x80000000
end_define

begin_comment
comment|/* Soft reset */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_RESET_RX_MC
value|0x00080000
end_define

begin_comment
comment|/* Reset receive MAC control block */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_RESET_TX_MC
value|0x00040000
end_define

begin_comment
comment|/* Reset transmit MAC control block */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_RESET_RX_FUN
value|0x00020000
end_define

begin_comment
comment|/* Reset receive function block */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_RESET_TX_FUN
value|0x00010000
end_define

begin_comment
comment|/* Reset transmit function block */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_LOOPBACK
value|0x00000100
end_define

begin_comment
comment|/* Loopback */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_RX_FLOW
value|0x00000020
end_define

begin_comment
comment|/* Receive flow */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_TX_FLOW
value|0x00000010
end_define

begin_comment
comment|/* Transmit flow */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_SYNCD_RX_EN
value|0x00000008
end_define

begin_comment
comment|/* Receive enable synchronized 						    * to the receive stream (Read-only) */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_RX_EN
value|0x00000004
end_define

begin_comment
comment|/* Receive enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_SYNCD_TX_EN
value|0x00000002
end_define

begin_comment
comment|/* Transmit enable synchronized 						    * to the transmit stream (Read-only) */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG1_TX_EN
value|0x00000001
end_define

begin_comment
comment|/* Transmit enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG2_PRECNT
value|0x00007000
end_define

begin_comment
comment|/* Preamble Length (0x7) */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG2_IF
value|0x00000300
end_define

begin_comment
comment|/* Determines the type of interface 						    * to which the MAC is connected */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG2_MII
value|0x00000100
end_define

begin_comment
comment|/* Nibble mode (MII) */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG2_GMII
value|0x00000200
end_define

begin_comment
comment|/* Byte mode (GMII/TBI) */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG2_HUGEFRAME
value|0x00000020
end_define

begin_comment
comment|/* Huge frame enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG2_LENGTHCHECK
value|0x00000010
end_define

begin_comment
comment|/* Length check */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG2_PADCRC
value|0x00000004
end_define

begin_comment
comment|/* Pad and append CRC */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG2_CRCEN
value|0x00000002
end_define

begin_comment
comment|/* CRC enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_MACCFG2_FULLDUPLEX
value|0x00000001
end_define

begin_comment
comment|/* Full duplex configure */
end_comment

begin_define
define|#
directive|define
name|TSEC_ECNTRL_STEN
value|0x00001000
end_define

begin_comment
comment|/* Statistics enabled */
end_comment

begin_define
define|#
directive|define
name|TSEC_ECNTRL_GMIIM
value|0x00000040
end_define

begin_comment
comment|/* GMII I/F mode */
end_comment

begin_define
define|#
directive|define
name|TSEC_ECNTRL_TBIM
value|0x00000020
end_define

begin_comment
comment|/* Ten-bit I/F mode */
end_comment

begin_define
define|#
directive|define
name|TSEC_ECNTRL_R100M
value|0x00000008
end_define

begin_comment
comment|/* RGMII/RMII 100 mode */
end_comment

begin_define
define|#
directive|define
name|TSEC_ECNTRL_RMM
value|0x00000004
end_define

begin_comment
comment|/* Reduced-pin mode */
end_comment

begin_define
define|#
directive|define
name|TSEC_ECNTRL_SGMIIM
value|0x00000002
end_define

begin_comment
comment|/* Serial GMII mode */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCFG_RESETMGMT
value|0x80000000
end_define

begin_comment
comment|/* Reset management */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCFG_NOPRE
value|0x00000010
end_define

begin_comment
comment|/* Preamble suppress */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCFG_CLKDIV28
value|0x00000007
end_define

begin_comment
comment|/* source clock divided by 28 */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCFG_CLKDIV20
value|0x00000006
end_define

begin_comment
comment|/* source clock divided by 20 */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCFG_CLKDIV14
value|0x00000005
end_define

begin_comment
comment|/* source clock divided by 14 */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCFG_CLKDIV10
value|0x00000004
end_define

begin_comment
comment|/* source clock divided by 10 */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCFG_CLKDIV8
value|0x00000003
end_define

begin_comment
comment|/* source clock divided by 8 */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCFG_CLKDIV6
value|0x00000002
end_define

begin_comment
comment|/* source clock divided by 6 */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCFG_CLKDIV4
value|0x00000001
end_define

begin_comment
comment|/* source clock divided by 4 */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMIND_NOTVALID
value|0x00000004
end_define

begin_comment
comment|/* Not valid */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMIND_SCAN
value|0x00000002
end_define

begin_comment
comment|/* Scan in progress */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMIND_BUSY
value|0x00000001
end_define

begin_comment
comment|/* Busy */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCOM_SCANCYCLE
value|0x00000002
end_define

begin_comment
comment|/* Scan cycle */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIIMCOM_READCYCLE
value|0x00000001
end_define

begin_comment
comment|/* Read cycle */
end_comment

begin_comment
comment|/* Transmit Data Buffer Descriptor (TxBD) Field Descriptions */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_R
value|0x8000
end_define

begin_comment
comment|/* Ready */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_PADCRC
value|0x4000
end_define

begin_comment
comment|/* PAD/CRC */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_W
value|0x2000
end_define

begin_comment
comment|/* Wrap */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_I
value|0x1000
end_define

begin_comment
comment|/* Interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_L
value|0x0800
end_define

begin_comment
comment|/* Last in frame */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_TC
value|0x0400
end_define

begin_comment
comment|/* Tx CRC */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_DEF
value|0x0200
end_define

begin_comment
comment|/* Defer indication */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_TO1
value|0x0100
end_define

begin_comment
comment|/* Transmit software ownership */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_HFE
value|0x0080
end_define

begin_comment
comment|/* Huge frame enable (written by user) */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_LC
value|0x0080
end_define

begin_comment
comment|/* Late collision (written by TSEC) */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_RL
value|0x0040
end_define

begin_comment
comment|/* Retransmission Limit */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_TOE
value|0x0002
end_define

begin_comment
comment|/* TCP/IP Offload Enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_UN
value|0x0002
end_define

begin_comment
comment|/* Underrun */
end_comment

begin_define
define|#
directive|define
name|TSEC_TXBD_TXTRUNC
value|0x0001
end_define

begin_comment
comment|/* TX truncation */
end_comment

begin_comment
comment|/* Receive Data Buffer Descriptor (RxBD) Field Descriptions */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_E
value|0x8000
end_define

begin_comment
comment|/* Empty */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_RO1
value|0x4000
end_define

begin_comment
comment|/* Receive software ownership bit */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_W
value|0x2000
end_define

begin_comment
comment|/* Wrap */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_I
value|0x1000
end_define

begin_comment
comment|/* Interrupt */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_L
value|0x0800
end_define

begin_comment
comment|/* Last in frame */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_F
value|0x0400
end_define

begin_comment
comment|/* First in frame */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_M
value|0x0100
end_define

begin_comment
comment|/* Miss - The frame was received because 					* of promiscuous mode. */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_B
value|0x0080
end_define

begin_comment
comment|/* Broadcast */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_MC
value|0x0040
end_define

begin_comment
comment|/* Multicast */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_LG
value|0x0020
end_define

begin_comment
comment|/* Large - Rx frame length violation */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_NO
value|0x0010
end_define

begin_comment
comment|/* Rx non-octet aligned frame */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_SH
value|0x0008
end_define

begin_comment
comment|/* Short frame */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_CR
value|0x0004
end_define

begin_comment
comment|/* Rx CRC error */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_OV
value|0x0002
end_define

begin_comment
comment|/* Overrun */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_TR
value|0x0001
end_define

begin_comment
comment|/* Truncation */
end_comment

begin_define
define|#
directive|define
name|TSEC_RXBD_ZEROONINIT
value|(TSEC_RXBD_TR | TSEC_RXBD_OV | TSEC_RXBD_CR |  \ 		TSEC_RXBD_SH | TSEC_RXBD_NO | TSEC_RXBD_LG | TSEC_RXBD_MC | \ 		TSEC_RXBD_B | TSEC_RXBD_M)
end_define

begin_define
define|#
directive|define
name|TSEC_TXBUFFER_ALIGNMENT
value|64
end_define

begin_define
define|#
directive|define
name|TSEC_RXBUFFER_ALIGNMENT
value|64
end_define

begin_comment
comment|/* Transmit Path Off-Load Frame Control Block flags */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_FCB_VLAN
value|0x8000
end_define

begin_comment
comment|/* VLAN control word valid */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_FCB_L3_IS_IP
value|0x4000
end_define

begin_comment
comment|/* Layer 3 header is an IP header */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_FCB_L3_IS_IP6
value|0x2000
end_define

begin_comment
comment|/* IP header is IP version 6 */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_FCB_L4_IS_TCP_UDP
value|0x1000
end_define

begin_comment
comment|/* Layer 4 header is a TCP or UDP header */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_FCB_L4_IS_UDP
value|0x0800
end_define

begin_comment
comment|/* UDP protocol at layer 4 */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_FCB_CSUM_IP
value|0x0400
end_define

begin_comment
comment|/* Checksum IP header enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_FCB_CSUM_TCP_UDP
value|0x0200
end_define

begin_comment
comment|/* Checksum TCP or UDP header enable */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_FCB_FLAG_NO_PH_CSUM
value|0x0100
end_define

begin_comment
comment|/* Disable pseudo-header checksum */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_FCB_FLAG_PTP
value|0x0001
end_define

begin_comment
comment|/* This is a PTP packet */
end_comment

begin_comment
comment|/* Receive Path Off-Load Frame Control Block flags */
end_comment

begin_define
define|#
directive|define
name|TSEC_RX_FCB_VLAN
value|0x8000
end_define

begin_comment
comment|/* VLAN tag recognized */
end_comment

begin_define
define|#
directive|define
name|TSEC_RX_FCB_IP_FOUND
value|0x4000
end_define

begin_comment
comment|/* IP header found at layer 3 */
end_comment

begin_define
define|#
directive|define
name|TSEC_RX_FCB_IP6_FOUND
value|0x2000
end_define

begin_comment
comment|/* IP version 6 header found at layer 3 */
end_comment

begin_define
define|#
directive|define
name|TSEC_RX_FCB_TCP_UDP_FOUND
value|0x1000
end_define

begin_comment
comment|/* TCP or UDP header found at layer 4 */
end_comment

begin_define
define|#
directive|define
name|TSEC_RX_FCB_IP_CSUM
value|0x0800
end_define

begin_comment
comment|/* IPv4 header checksum checked */
end_comment

begin_define
define|#
directive|define
name|TSEC_RX_FCB_TCP_UDP_CSUM
value|0x0400
end_define

begin_comment
comment|/* TCP or UDP header checksum checked */
end_comment

begin_define
define|#
directive|define
name|TSEC_RX_FCB_IP_CSUM_ERROR
value|0x0200
end_define

begin_comment
comment|/* IPv4 header checksum verification error */
end_comment

begin_define
define|#
directive|define
name|TSEC_RX_FCB_TCP_UDP_CSUM_ERROR
value|0x0100
end_define

begin_comment
comment|/* TCP or UDP header checksum verification error */
end_comment

begin_define
define|#
directive|define
name|TSEC_RX_FCB_PARSE_ERROR
value|0x000C
end_define

begin_comment
comment|/* Parse error */
end_comment

end_unit


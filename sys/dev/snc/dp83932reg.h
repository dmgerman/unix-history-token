begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: dp83932reg.h,v 1.2 1999/02/12 05:50:13 kmatsuda Exp $	*/
end_comment

begin_comment
comment|/*      $NetBSD: if_snreg.h,v 1.4 1997/06/15 20:20:12 scottr Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1991   Algorithmics Ltd (http://www.algor.co.uk)  * You may use, copy, and modify this program so long as you retain the  * copyright line.  */
end_comment

begin_comment
comment|/*  * if_snreg.h -- National Semiconductor DP8393X (SONIC) register defs  */
end_comment

begin_comment
comment|/*  * SONIC registers as seen by the processor  */
end_comment

begin_define
define|#
directive|define
name|SNCR_CR
value|0x00
end_define

begin_comment
comment|/* Command */
end_comment

begin_define
define|#
directive|define
name|SNCR_DCR
value|0x01
end_define

begin_comment
comment|/* Data Configuration */
end_comment

begin_define
define|#
directive|define
name|SNCR_RCR
value|0x02
end_define

begin_comment
comment|/* Receive Control */
end_comment

begin_define
define|#
directive|define
name|SNCR_TCR
value|0x03
end_define

begin_comment
comment|/* Transmit Control */
end_comment

begin_define
define|#
directive|define
name|SNCR_IMR
value|0x04
end_define

begin_comment
comment|/* Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|SNCR_ISR
value|0x05
end_define

begin_comment
comment|/* Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|SNCR_UTDA
value|0x06
end_define

begin_comment
comment|/* Upper Transmit Descriptor Address */
end_comment

begin_define
define|#
directive|define
name|SNCR_CTDA
value|0x07
end_define

begin_comment
comment|/* Current Transmit Descriptor Address */
end_comment

begin_define
define|#
directive|define
name|SNCR_TPS
value|0x08
end_define

begin_comment
comment|/* Transmit Packet Size */
end_comment

begin_define
define|#
directive|define
name|SNCR_TFC
value|0x09
end_define

begin_comment
comment|/* Transmit Fragment Count */
end_comment

begin_define
define|#
directive|define
name|SNCR_TSA0
value|0x0a
end_define

begin_comment
comment|/* Transmit Start Address 0 */
end_comment

begin_define
define|#
directive|define
name|SNCR_TSA1
value|0x0b
end_define

begin_comment
comment|/* Transmit Start Address 1 */
end_comment

begin_define
define|#
directive|define
name|SNCR_TFS
value|0x0c
end_define

begin_comment
comment|/* Transmit Fragment Size */
end_comment

begin_define
define|#
directive|define
name|SNCR_URDA
value|0x0d
end_define

begin_comment
comment|/* Upper Receive Descriptor Address */
end_comment

begin_define
define|#
directive|define
name|SNCR_CRDA
value|0x0e
end_define

begin_comment
comment|/* Current Receive Descriptor Address */
end_comment

begin_define
define|#
directive|define
name|SNCR_CRBA0
value|0x0f
end_define

begin_comment
comment|/* Current Receive Buffer Address 0 */
end_comment

begin_define
define|#
directive|define
name|SNCR_CRBA1
value|0x10
end_define

begin_comment
comment|/* Current Receive Buffer Address 1 */
end_comment

begin_define
define|#
directive|define
name|SNCR_RBWC0
value|0x11
end_define

begin_comment
comment|/* Remaining Buffer Word Count 0 */
end_comment

begin_define
define|#
directive|define
name|SNCR_RBWC1
value|0x12
end_define

begin_comment
comment|/* Remaining Buffer Word Count 1 */
end_comment

begin_define
define|#
directive|define
name|SNCR_EOBC
value|0x13
end_define

begin_comment
comment|/* End Of Buffer Word Count */
end_comment

begin_define
define|#
directive|define
name|SNCR_URRA
value|0x14
end_define

begin_comment
comment|/* Upper Receive Resource Address */
end_comment

begin_define
define|#
directive|define
name|SNCR_RSA
value|0x15
end_define

begin_comment
comment|/* Resource Start Address */
end_comment

begin_define
define|#
directive|define
name|SNCR_REA
value|0x16
end_define

begin_comment
comment|/* Resource End Address */
end_comment

begin_define
define|#
directive|define
name|SNCR_RRP
value|0x17
end_define

begin_comment
comment|/* Resource Read Pointer */
end_comment

begin_define
define|#
directive|define
name|SNCR_RWP
value|0x18
end_define

begin_comment
comment|/* Resource Write Pointer */
end_comment

begin_define
define|#
directive|define
name|SNCR_TRBA0
value|0x19
end_define

begin_comment
comment|/* Temporary Receive Buffer Address 0 */
end_comment

begin_define
define|#
directive|define
name|SNCR_TRBA1
value|0x1a
end_define

begin_comment
comment|/* Temporary Receive Buffer Address 1 */
end_comment

begin_define
define|#
directive|define
name|SNCR_TBWC0
value|0x1b
end_define

begin_comment
comment|/* Temporary Buffer Word Count 0 */
end_comment

begin_define
define|#
directive|define
name|SNCR_TBWC1
value|0x1c
end_define

begin_comment
comment|/* Temporary Buffer Word Count 1 */
end_comment

begin_define
define|#
directive|define
name|SNCR_ADDR0
value|0x1d
end_define

begin_comment
comment|/* Address Generator 0 */
end_comment

begin_define
define|#
directive|define
name|SNCR_ADDR1
value|0x1e
end_define

begin_comment
comment|/* Address Generator 1 */
end_comment

begin_define
define|#
directive|define
name|SNCR_LLFA
value|0x1f
end_define

begin_comment
comment|/* Last Link Field Address */
end_comment

begin_define
define|#
directive|define
name|SNCR_TTDA
value|0x20
end_define

begin_comment
comment|/* Temp Transmit Descriptor Address */
end_comment

begin_define
define|#
directive|define
name|SNCR_CEP
value|0x21
end_define

begin_comment
comment|/* CAM Entry Pointer */
end_comment

begin_define
define|#
directive|define
name|SNCR_CAP2
value|0x22
end_define

begin_comment
comment|/* CAM Address Port 2 */
end_comment

begin_define
define|#
directive|define
name|SNCR_CAP1
value|0x23
end_define

begin_comment
comment|/* CAM Address Port 1 */
end_comment

begin_define
define|#
directive|define
name|SNCR_CAP0
value|0x24
end_define

begin_comment
comment|/* CAM Address Port 0 */
end_comment

begin_define
define|#
directive|define
name|SNCR_CE
value|0x25
end_define

begin_comment
comment|/* CAM Enable */
end_comment

begin_define
define|#
directive|define
name|SNCR_CDP
value|0x26
end_define

begin_comment
comment|/* CAM Descriptor Pointer */
end_comment

begin_define
define|#
directive|define
name|SNCR_CDC
value|0x27
end_define

begin_comment
comment|/* CAM Descriptor Count */
end_comment

begin_define
define|#
directive|define
name|SNCR_SR
value|0x28
end_define

begin_comment
comment|/* Silicon Revision */
end_comment

begin_define
define|#
directive|define
name|SNCR_WT0
value|0x29
end_define

begin_comment
comment|/* Watchdog Timer 0 */
end_comment

begin_define
define|#
directive|define
name|SNCR_WT1
value|0x2a
end_define

begin_comment
comment|/* Watchdog Timer 1 */
end_comment

begin_define
define|#
directive|define
name|SNCR_RSC
value|0x2b
end_define

begin_comment
comment|/* Receive Sequence Counter */
end_comment

begin_define
define|#
directive|define
name|SNCR_CRCT
value|0x2c
end_define

begin_comment
comment|/* CRC Error Tally */
end_comment

begin_define
define|#
directive|define
name|SNCR_FAET
value|0x2d
end_define

begin_comment
comment|/* FAE Tally */
end_comment

begin_define
define|#
directive|define
name|SNCR_MPT
value|0x2e
end_define

begin_comment
comment|/* Missed Packet Tally */
end_comment

begin_define
define|#
directive|define
name|SNCR_MDT
value|0x2f
end_define

begin_comment
comment|/* Maximum Deferral Timer */
end_comment

begin_define
define|#
directive|define
name|SNCR_RTC
value|0x30
end_define

begin_comment
comment|/* Receive Test Control */
end_comment

begin_define
define|#
directive|define
name|SNCR_TTC
value|0x31
end_define

begin_comment
comment|/* Transmit Test Control */
end_comment

begin_define
define|#
directive|define
name|SNCR_DTC
value|0x32
end_define

begin_comment
comment|/* DMA Test Control */
end_comment

begin_define
define|#
directive|define
name|SNCR_CC0
value|0x33
end_define

begin_comment
comment|/* CAM Comparison 0 */
end_comment

begin_define
define|#
directive|define
name|SNCR_CC1
value|0x34
end_define

begin_comment
comment|/* CAM Comparison 1 */
end_comment

begin_define
define|#
directive|define
name|SNCR_CC2
value|0x35
end_define

begin_comment
comment|/* CAM Comparison 2 */
end_comment

begin_define
define|#
directive|define
name|SNCR_CM
value|0x36
end_define

begin_comment
comment|/* CAM Match */
end_comment

begin_define
define|#
directive|define
name|SNCR_RES1
value|0x37
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|SNCR_RES2
value|0x38
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|SNCR_RBC
value|0x39
end_define

begin_comment
comment|/* Receiver Byte Count */
end_comment

begin_define
define|#
directive|define
name|SNCR_RES3
value|0x3a
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|SNCR_TBO
value|0x3b
end_define

begin_comment
comment|/* Transmitter Backoff Counter */
end_comment

begin_define
define|#
directive|define
name|SNCR_TRC
value|0x3c
end_define

begin_comment
comment|/* Transmitter Random Counter */
end_comment

begin_define
define|#
directive|define
name|SNCR_TBM
value|0x3d
end_define

begin_comment
comment|/* Transmitter Backoff Mask */
end_comment

begin_define
define|#
directive|define
name|SNCR_RES4
value|0x3e
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|SNCR_DCR2
value|0x3f
end_define

begin_comment
comment|/* Data Configuration 2 (AVF) */
end_comment

begin_define
define|#
directive|define
name|SNC_NREGS
value|0x40
end_define

begin_comment
comment|/*  * Register Interpretations  */
end_comment

begin_comment
comment|/*  * The command register is used for issuing commands to the SONIC.  * With the exception of CR_RST, the bit is reset when the operation  * completes.  */
end_comment

begin_define
define|#
directive|define
name|CR_LCAM
value|0x0200
end_define

begin_comment
comment|/* load CAM with descriptor at s_cdp */
end_comment

begin_define
define|#
directive|define
name|CR_RRRA
value|0x0100
end_define

begin_comment
comment|/* read next RRA descriptor at s_rrp */
end_comment

begin_define
define|#
directive|define
name|CR_RST
value|0x0080
end_define

begin_comment
comment|/* software reset */
end_comment

begin_define
define|#
directive|define
name|CR_ST
value|0x0020
end_define

begin_comment
comment|/* start timer */
end_comment

begin_define
define|#
directive|define
name|CR_STP
value|0x0010
end_define

begin_comment
comment|/* stop timer */
end_comment

begin_define
define|#
directive|define
name|CR_RXEN
value|0x0008
end_define

begin_comment
comment|/* receiver enable */
end_comment

begin_define
define|#
directive|define
name|CR_RXDIS
value|0x0004
end_define

begin_comment
comment|/* receiver disable */
end_comment

begin_define
define|#
directive|define
name|CR_TXP
value|0x0002
end_define

begin_comment
comment|/* transmit packets */
end_comment

begin_define
define|#
directive|define
name|CR_HTX
value|0x0001
end_define

begin_comment
comment|/* halt transmission */
end_comment

begin_comment
comment|/*  * The data configuration register establishes the SONIC's bus cycle  * operation.  This register can only be accessed when the SONIC is in  * reset mode (s_cr.CR_RST is set.)  */
end_comment

begin_define
define|#
directive|define
name|DCR_EXBUS
value|0x8000
end_define

begin_comment
comment|/* extended bus mode (AVF) */
end_comment

begin_define
define|#
directive|define
name|DCR_LBR
value|0x2000
end_define

begin_comment
comment|/* latched bus retry */
end_comment

begin_define
define|#
directive|define
name|DCR_PO1
value|0x1000
end_define

begin_comment
comment|/* programmable output 1 */
end_comment

begin_define
define|#
directive|define
name|DCR_PO0
value|0x0800
end_define

begin_comment
comment|/* programmable output 0 */
end_comment

begin_define
define|#
directive|define
name|DCR_STERM
value|0x0400
end_define

begin_comment
comment|/* synchronous termination */
end_comment

begin_define
define|#
directive|define
name|DCR_USR1
value|0x0200
end_define

begin_comment
comment|/* reflects USR1 input pin */
end_comment

begin_define
define|#
directive|define
name|DCR_USR0
value|0x0100
end_define

begin_comment
comment|/* reflects USR0 input pin */
end_comment

begin_define
define|#
directive|define
name|DCR_WC1
value|0x0080
end_define

begin_comment
comment|/* wait state control 1 */
end_comment

begin_define
define|#
directive|define
name|DCR_WC0
value|0x0040
end_define

begin_comment
comment|/* wait state control 0 */
end_comment

begin_define
define|#
directive|define
name|DCR_DW
value|0x0020
end_define

begin_comment
comment|/* data width select */
end_comment

begin_define
define|#
directive|define
name|DCR_BMS
value|0x0010
end_define

begin_comment
comment|/* DMA block mode select */
end_comment

begin_define
define|#
directive|define
name|DCR_RFT1
value|0x0008
end_define

begin_comment
comment|/* receive FIFO threshold control 1 */
end_comment

begin_define
define|#
directive|define
name|DCR_RFT0
value|0x0004
end_define

begin_comment
comment|/* receive FIFO threshold control 0 */
end_comment

begin_define
define|#
directive|define
name|DCR_TFT1
value|0x0002
end_define

begin_comment
comment|/* transmit FIFO threshold control 1 */
end_comment

begin_define
define|#
directive|define
name|DCR_TFT0
value|0x0001
end_define

begin_comment
comment|/* transmit FIFO threshold control 0 */
end_comment

begin_comment
comment|/* data configuration register aliases */
end_comment

begin_define
define|#
directive|define
name|DCR_SYNC
value|DCR_STERM
end_define

begin_comment
comment|/* synchronous (memory cycle 2 clocks) */
end_comment

begin_define
define|#
directive|define
name|DCR_ASYNC
value|0
end_define

begin_comment
comment|/* asynchronous (memory cycle 3 clocks) */
end_comment

begin_define
define|#
directive|define
name|DCR_WAIT0
value|0
end_define

begin_comment
comment|/* 0 wait states added */
end_comment

begin_define
define|#
directive|define
name|DCR_WAIT1
value|DCR_WC0
end_define

begin_comment
comment|/* 1 wait state added */
end_comment

begin_define
define|#
directive|define
name|DCR_WAIT2
value|DCR_WC1
end_define

begin_comment
comment|/* 2 wait states added */
end_comment

begin_define
define|#
directive|define
name|DCR_WAIT3
value|(DCR_WC1|DCR_WC0)
end_define

begin_comment
comment|/* 3 wait states added */
end_comment

begin_define
define|#
directive|define
name|DCR_DW16
value|0
end_define

begin_comment
comment|/* use 16-bit DMA accesses */
end_comment

begin_define
define|#
directive|define
name|DCR_DW32
value|DCR_DW
end_define

begin_comment
comment|/* use 32-bit DMA accesses */
end_comment

begin_define
define|#
directive|define
name|DCR_DMAEF
value|0
end_define

begin_comment
comment|/* DMA until TX/RX FIFO has emptied/filled */
end_comment

begin_define
define|#
directive|define
name|DCR_DMABLOCK
value|DCR_BMS
end_define

begin_comment
comment|/* DMA until RX/TX threshold crossed */
end_comment

begin_define
define|#
directive|define
name|DCR_RFT4
value|0
end_define

begin_comment
comment|/* receive threshold 4 bytes */
end_comment

begin_define
define|#
directive|define
name|DCR_RFT8
value|DCR_RFT0
end_define

begin_comment
comment|/* receive threshold 8 bytes */
end_comment

begin_define
define|#
directive|define
name|DCR_RFT16
value|DCR_RFT1
end_define

begin_comment
comment|/* receive threshold 16 bytes */
end_comment

begin_define
define|#
directive|define
name|DCR_RFT24
value|(DCR_RFT1|DCR_RFT0)
end_define

begin_comment
comment|/* receive threshold 24 bytes */
end_comment

begin_define
define|#
directive|define
name|DCR_TFT8
value|0
end_define

begin_comment
comment|/* transmit threshold 8 bytes */
end_comment

begin_define
define|#
directive|define
name|DCR_TFT16
value|DCR_TFT0
end_define

begin_comment
comment|/* transmit threshold 16 bytes */
end_comment

begin_define
define|#
directive|define
name|DCR_TFT24
value|DCR_TFT1
end_define

begin_comment
comment|/* transmit threshold 24 bytes */
end_comment

begin_define
define|#
directive|define
name|DCR_TFT28
value|(DCR_TFT1|DCR_TFT0)
end_define

begin_comment
comment|/* transmit threshold 28 bytes */
end_comment

begin_comment
comment|/*  * The receive control register is used to filter incoming packets and  * provides status information on packets received.  * The contents of the register are copied into the RXpkt.status field  * when a packet is received. RCR_MC - RCR_PRX are then reset.  */
end_comment

begin_define
define|#
directive|define
name|RCR_ERR
value|0x8000
end_define

begin_comment
comment|/* accept packets with CRC errors */
end_comment

begin_define
define|#
directive|define
name|RCR_RNT
value|0x4000
end_define

begin_comment
comment|/* accept runt (length< 64) packets */
end_comment

begin_define
define|#
directive|define
name|RCR_BRD
value|0x2000
end_define

begin_comment
comment|/* accept broadcast packets */
end_comment

begin_define
define|#
directive|define
name|RCR_PRO
value|0x1000
end_define

begin_comment
comment|/* accept all physical address packets */
end_comment

begin_define
define|#
directive|define
name|RCR_AMC
value|0x0800
end_define

begin_comment
comment|/* accept all multicast packets */
end_comment

begin_define
define|#
directive|define
name|RCR_LB1
value|0x0400
end_define

begin_comment
comment|/* loopback control 1 */
end_comment

begin_define
define|#
directive|define
name|RCR_LB0
value|0x0200
end_define

begin_comment
comment|/* loopback control 0 */
end_comment

begin_define
define|#
directive|define
name|RCR_MC
value|0x0100
end_define

begin_comment
comment|/* multicast packet received */
end_comment

begin_define
define|#
directive|define
name|RCR_BC
value|0x0080
end_define

begin_comment
comment|/* broadcast packet received */
end_comment

begin_define
define|#
directive|define
name|RCR_LPKT
value|0x0040
end_define

begin_comment
comment|/* last packet in RBA (RBWC< EOBC) */
end_comment

begin_define
define|#
directive|define
name|RCR_CRS
value|0x0020
end_define

begin_comment
comment|/* carrier sense activity */
end_comment

begin_define
define|#
directive|define
name|RCR_COL
value|0x0010
end_define

begin_comment
comment|/* collision activity */
end_comment

begin_define
define|#
directive|define
name|RCR_CRC
value|0x0008
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|RCR_FAE
value|0x0004
end_define

begin_comment
comment|/* frame alignment error */
end_comment

begin_define
define|#
directive|define
name|RCR_LBK
value|0x0002
end_define

begin_comment
comment|/* loopback packet received */
end_comment

begin_define
define|#
directive|define
name|RCR_PRX
value|0x0001
end_define

begin_comment
comment|/* packet received without errors */
end_comment

begin_comment
comment|/* receiver control register aliases */
end_comment

begin_comment
comment|/* the loopback control bits provide the following options */
end_comment

begin_define
define|#
directive|define
name|RCR_LBNONE
value|0
end_define

begin_comment
comment|/* no loopback - normal operation */
end_comment

begin_define
define|#
directive|define
name|RCR_LBMAC
value|RCR_LB0
end_define

begin_comment
comment|/* MAC loopback */
end_comment

begin_define
define|#
directive|define
name|RCR_LBENDEC
value|RCR_LB1
end_define

begin_comment
comment|/* ENDEC loopback */
end_comment

begin_define
define|#
directive|define
name|RCR_LBTRANS
value|(RCR_LB1|RCR_LB0)
end_define

begin_comment
comment|/* transceiver loopback */
end_comment

begin_comment
comment|/*  * The transmit control register controls the SONIC's transmit operations.  * TCR_PINT - TCR_EXDIS are loaded from the TXpkt.config field at the  * start of transmission.  TCR_EXD-TCR_PTX are cleared at the beginning  * of transmission and updated when the transmission is completed.  */
end_comment

begin_define
define|#
directive|define
name|TCR_PINT
value|0x8000
end_define

begin_comment
comment|/* interrupt when transmission starts */
end_comment

begin_define
define|#
directive|define
name|TCR_POWC
value|0x4000
end_define

begin_comment
comment|/* program out of window collision timer */
end_comment

begin_define
define|#
directive|define
name|TCR_CRCI
value|0x2000
end_define

begin_comment
comment|/* transmit packet without 4 byte FCS */
end_comment

begin_define
define|#
directive|define
name|TCR_EXDIS
value|0x1000
end_define

begin_comment
comment|/* disable excessive deferral timer */
end_comment

begin_define
define|#
directive|define
name|TCR_EXD
value|0x0400
end_define

begin_comment
comment|/* excessive deferrals occurred (>3.2ms) */
end_comment

begin_define
define|#
directive|define
name|TCR_DEF
value|0x0200
end_define

begin_comment
comment|/* deferred transmissions occurred */
end_comment

begin_define
define|#
directive|define
name|TCR_NCRS
value|0x0100
end_define

begin_comment
comment|/* carrier not present during transmission */
end_comment

begin_define
define|#
directive|define
name|TCR_CRSL
value|0x0080
end_define

begin_comment
comment|/* carrier lost during transmission */
end_comment

begin_define
define|#
directive|define
name|TCR_EXC
value|0x0040
end_define

begin_comment
comment|/* excessive collisions (>16) detected */
end_comment

begin_define
define|#
directive|define
name|TCR_OWC
value|0x0020
end_define

begin_comment
comment|/* out of window (bad) collision occurred */
end_comment

begin_define
define|#
directive|define
name|TCR_PMB
value|0x0008
end_define

begin_comment
comment|/* packet monitored bad - the tansmitted                                  * packet had a bad source address or CRC */
end_comment

begin_define
define|#
directive|define
name|TCR_FU
value|0x0004
end_define

begin_comment
comment|/* FIFO underrun (memory access failed) */
end_comment

begin_define
define|#
directive|define
name|TCR_BCM
value|0x0002
end_define

begin_comment
comment|/* byte count mismatch (TXpkt.pkt_size                                  * != sum(TXpkt.frag_size) */
end_comment

begin_define
define|#
directive|define
name|TCR_PTX
value|0x0001
end_define

begin_comment
comment|/* packet transmitted without errors */
end_comment

begin_define
define|#
directive|define
name|TCR_NC
value|0xf000
end_define

begin_comment
comment|/* after transmission, # of colls */
end_comment

begin_comment
comment|/* transmit control register aliases */
end_comment

begin_define
define|#
directive|define
name|TCR_OWCSFD
value|0
end_define

begin_comment
comment|/* start after start of frame delimiter */
end_comment

begin_define
define|#
directive|define
name|TCR_OWCPRE
value|TCR_POWC
end_define

begin_comment
comment|/* start after first bit of preamble */
end_comment

begin_comment
comment|/*  * The interrupt mask register masks the interrupts that  * are generated from the interrupt status register.  * All reserved bits should be written with 0.  */
end_comment

begin_define
define|#
directive|define
name|IMR_BREN
value|0x4000
end_define

begin_comment
comment|/* bus retry occurred enable */
end_comment

begin_define
define|#
directive|define
name|IMR_HBLEN
value|0x2000
end_define

begin_comment
comment|/* heartbeat lost enable */
end_comment

begin_define
define|#
directive|define
name|IMR_LCDEN
value|0x1000
end_define

begin_comment
comment|/* load CAM done interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IMR_PINTEN
value|0x0800
end_define

begin_comment
comment|/* programmable interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IMR_PRXEN
value|0x0400
end_define

begin_comment
comment|/* packet received enable */
end_comment

begin_define
define|#
directive|define
name|IMR_PTXEN
value|0x0200
end_define

begin_comment
comment|/* packet transmitted enable */
end_comment

begin_define
define|#
directive|define
name|IMR_TXEREN
value|0x0100
end_define

begin_comment
comment|/* transmit error enable */
end_comment

begin_define
define|#
directive|define
name|IMR_TCEN
value|0x0080
end_define

begin_comment
comment|/* timer complete enable */
end_comment

begin_define
define|#
directive|define
name|IMR_RDEEN
value|0x0040
end_define

begin_comment
comment|/* receive descriptors exhausted enable */
end_comment

begin_define
define|#
directive|define
name|IMR_RBEEN
value|0x0020
end_define

begin_comment
comment|/* receive buffers exhausted enable */
end_comment

begin_define
define|#
directive|define
name|IMR_RBAEEN
value|0x0010
end_define

begin_comment
comment|/* receive buffer area exceeded enable */
end_comment

begin_define
define|#
directive|define
name|IMR_CRCEN
value|0x0008
end_define

begin_comment
comment|/* CRC tally counter rollover enable */
end_comment

begin_define
define|#
directive|define
name|IMR_FAEEN
value|0x0004
end_define

begin_comment
comment|/* FAE tally counter rollover enable */
end_comment

begin_define
define|#
directive|define
name|IMR_MPEN
value|0x0002
end_define

begin_comment
comment|/* MP tally counter rollover enable */
end_comment

begin_define
define|#
directive|define
name|IMR_RFOEN
value|0x0001
end_define

begin_comment
comment|/* receive FIFO overrun enable */
end_comment

begin_comment
comment|/*  * The interrupt status register indicates the source of an interrupt when  * the INT pin goes active.  The interrupt is acknowledged by writing  * the appropriate bit(s) in this register.  */
end_comment

begin_define
define|#
directive|define
name|ISR_ALL
value|0x7fff
end_define

begin_comment
comment|/* all interrupts */
end_comment

begin_define
define|#
directive|define
name|ISR_BR
value|0x4000
end_define

begin_comment
comment|/* bus retry occurred */
end_comment

begin_define
define|#
directive|define
name|ISR_HBL
value|0x2000
end_define

begin_comment
comment|/* CD heartbeat lost */
end_comment

begin_define
define|#
directive|define
name|ISR_LCD
value|0x1000
end_define

begin_comment
comment|/* load CAM command has completed */
end_comment

begin_define
define|#
directive|define
name|ISR_PINT
value|0x0800
end_define

begin_comment
comment|/* programmed interrupt from TXpkt.config */
end_comment

begin_define
define|#
directive|define
name|ISR_PKTRX
value|0x0400
end_define

begin_comment
comment|/* packet received */
end_comment

begin_define
define|#
directive|define
name|ISR_TXDN
value|0x0200
end_define

begin_comment
comment|/* no remaining packets to be transmitted */
end_comment

begin_define
define|#
directive|define
name|ISR_TXER
value|0x0100
end_define

begin_comment
comment|/* packet transmission caused error */
end_comment

begin_define
define|#
directive|define
name|ISR_TC
value|0x0080
end_define

begin_comment
comment|/* timer complete */
end_comment

begin_define
define|#
directive|define
name|ISR_RDE
value|0x0040
end_define

begin_comment
comment|/* receive descriptors exhausted */
end_comment

begin_define
define|#
directive|define
name|ISR_RBE
value|0x0020
end_define

begin_comment
comment|/* receive buffers exhausted */
end_comment

begin_define
define|#
directive|define
name|ISR_RBAE
value|0x0010
end_define

begin_comment
comment|/* receive buffer area exceeded */
end_comment

begin_define
define|#
directive|define
name|ISR_CRC
value|0x0008
end_define

begin_comment
comment|/* CRC tally counter rollover */
end_comment

begin_define
define|#
directive|define
name|ISR_FAE
value|0x0004
end_define

begin_comment
comment|/* FAE tally counter rollover */
end_comment

begin_define
define|#
directive|define
name|ISR_MP
value|0x0002
end_define

begin_comment
comment|/* MP tally counter rollover */
end_comment

begin_define
define|#
directive|define
name|ISR_RFO
value|0x0001
end_define

begin_comment
comment|/* receive FIFO overrun */
end_comment

begin_comment
comment|/*  * The second data configuration register allows additional user defined  * pins to be controlled.  These bits are only available if s_dcr.DCR_EXBUS  * is set.  */
end_comment

begin_define
define|#
directive|define
name|DCR2_EXPO3
value|0x8000
end_define

begin_comment
comment|/* EXUSR3 output */
end_comment

begin_define
define|#
directive|define
name|DCR2_EXPO2
value|0x4000
end_define

begin_comment
comment|/* EXUSR2 output */
end_comment

begin_define
define|#
directive|define
name|DCR2_EXPO1
value|0x2000
end_define

begin_comment
comment|/* EXUSR1 output */
end_comment

begin_define
define|#
directive|define
name|DCR2_EXPO0
value|0x1000
end_define

begin_comment
comment|/* EXUSR0 output */
end_comment

begin_define
define|#
directive|define
name|DCR2_HD
value|0x0800
end_define

begin_comment
comment|/* heart beat disable (83934/83936) */
end_comment

begin_define
define|#
directive|define
name|DCR2_JD
value|0x0200
end_define

begin_comment
comment|/* TPI jabber timer disable (83934/83936) */
end_comment

begin_define
define|#
directive|define
name|DCR2_AUTO
value|0x0100
end_define

begin_comment
comment|/* AUI/TPI auto selection (83934/83936) */
end_comment

begin_define
define|#
directive|define
name|DCR2_XWRAP
value|0x0040
end_define

begin_comment
comment|/* TPI transceiver loopback (83934/83936) */
end_comment

begin_define
define|#
directive|define
name|DCR2_FD
value|0x0020
end_define

begin_comment
comment|/* full duplex (83936) */
end_comment

begin_define
define|#
directive|define
name|DCR2_PHL
value|0x0010
end_define

begin_comment
comment|/* extend HOLD signal by 1/2 clock */
end_comment

begin_define
define|#
directive|define
name|DCR2_LRDY
value|0x0008
end_define

begin_comment
comment|/* set latched ready mode */
end_comment

begin_define
define|#
directive|define
name|DCR2_PCM
value|0x0004
end_define

begin_comment
comment|/* packet compress on match */
end_comment

begin_define
define|#
directive|define
name|DCR2_PCNM
value|0x0002
end_define

begin_comment
comment|/* packet compress on mismatch */
end_comment

begin_define
define|#
directive|define
name|DCR2_RJM
value|0x0001
end_define

begin_comment
comment|/* reject on match */
end_comment

end_unit


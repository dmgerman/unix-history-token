begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 Myson Technology Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Written by: yen_cw@myson.com.tw  available at: http://www.myson.com.tw/  *  * $FreeBSD$  *  * Myson MTD80x register definitions.  *  */
end_comment

begin_define
define|#
directive|define
name|MY_PAR0
value|0x0
end_define

begin_comment
comment|/* physical address 0-3 */
end_comment

begin_define
define|#
directive|define
name|MY_PAR1
value|0x04
end_define

begin_comment
comment|/* physical address 4-5 */
end_comment

begin_define
define|#
directive|define
name|MY_MAR0
value|0x08
end_define

begin_comment
comment|/* multicast address 0-3 */
end_comment

begin_define
define|#
directive|define
name|MY_MAR1
value|0x0C
end_define

begin_comment
comment|/* multicast address 4-7 */
end_comment

begin_define
define|#
directive|define
name|MY_FAR0
value|0x10
end_define

begin_comment
comment|/* flow-control address 0-3 */
end_comment

begin_define
define|#
directive|define
name|MY_FAR1
value|0x14
end_define

begin_comment
comment|/* flow-control address 4-5 */
end_comment

begin_define
define|#
directive|define
name|MY_TCRRCR
value|0x18
end_define

begin_comment
comment|/* receive& transmit configuration */
end_comment

begin_define
define|#
directive|define
name|MY_BCR
value|0x1C
end_define

begin_comment
comment|/* bus command */
end_comment

begin_define
define|#
directive|define
name|MY_TXPDR
value|0x20
end_define

begin_comment
comment|/* transmit polling demand */
end_comment

begin_define
define|#
directive|define
name|MY_RXPDR
value|0x24
end_define

begin_comment
comment|/* receive polling demand */
end_comment

begin_define
define|#
directive|define
name|MY_RXCWP
value|0x28
end_define

begin_comment
comment|/* receive current word pointer */
end_comment

begin_define
define|#
directive|define
name|MY_TXLBA
value|0x2C
end_define

begin_comment
comment|/* transmit list base address */
end_comment

begin_define
define|#
directive|define
name|MY_RXLBA
value|0x30
end_define

begin_comment
comment|/* receive list base address */
end_comment

begin_define
define|#
directive|define
name|MY_ISR
value|0x34
end_define

begin_comment
comment|/* interrupt status */
end_comment

begin_define
define|#
directive|define
name|MY_IMR
value|0x38
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|MY_FTH
value|0x3C
end_define

begin_comment
comment|/* flow control high/low threshold */
end_comment

begin_define
define|#
directive|define
name|MY_MANAGEMENT
value|0x40
end_define

begin_comment
comment|/* bootrom/eeprom and mii management */
end_comment

begin_define
define|#
directive|define
name|MY_TALLY
value|0x44
end_define

begin_comment
comment|/* tally counters for crc and mpa */
end_comment

begin_define
define|#
directive|define
name|MY_TSR
value|0x48
end_define

begin_comment
comment|/* tally counter for transmit status */
end_comment

begin_define
define|#
directive|define
name|MY_PHYBASE
value|0x4c
end_define

begin_comment
comment|/*  * Receive Configuration Register  */
end_comment

begin_define
define|#
directive|define
name|MY_RXRUN
value|0x00008000
end_define

begin_comment
comment|/* receive running status */
end_comment

begin_define
define|#
directive|define
name|MY_EIEN
value|0x00004000
end_define

begin_comment
comment|/* early interrupt enable */
end_comment

begin_define
define|#
directive|define
name|MY_RFCEN
value|0x00002000
end_define

begin_comment
comment|/* receive flow control packet enable */
end_comment

begin_define
define|#
directive|define
name|MY_NDFA
value|0x00001000
end_define

begin_comment
comment|/* not defined flow control address */
end_comment

begin_define
define|#
directive|define
name|MY_RBLEN
value|0x00000800
end_define

begin_comment
comment|/* receive burst length enable */
end_comment

begin_define
define|#
directive|define
name|MY_RPBLE1
value|0x00000000
end_define

begin_comment
comment|/* 1 word */
end_comment

begin_define
define|#
directive|define
name|MY_RPBLE4
value|0x00000100
end_define

begin_comment
comment|/* 4 words */
end_comment

begin_define
define|#
directive|define
name|MY_RPBLE8
value|0x00000200
end_define

begin_comment
comment|/* 8 words */
end_comment

begin_define
define|#
directive|define
name|MY_RPBLE16
value|0x00000300
end_define

begin_comment
comment|/* 16 words */
end_comment

begin_define
define|#
directive|define
name|MY_RPBLE32
value|0x00000400
end_define

begin_comment
comment|/* 32 words */
end_comment

begin_define
define|#
directive|define
name|MY_RPBLE64
value|0x00000500
end_define

begin_comment
comment|/* 64 words */
end_comment

begin_define
define|#
directive|define
name|MY_RPBLE128
value|0x00000600
end_define

begin_comment
comment|/* 128 words */
end_comment

begin_define
define|#
directive|define
name|MY_RPBLE512
value|0x00000700
end_define

begin_comment
comment|/* 512 words */
end_comment

begin_define
define|#
directive|define
name|MY_PROM
value|0x000000080
end_define

begin_comment
comment|/* promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|MY_AB
value|0x000000040
end_define

begin_comment
comment|/* accept broadcast */
end_comment

begin_define
define|#
directive|define
name|MY_AM
value|0x000000020
end_define

begin_comment
comment|/* accept mutlicast */
end_comment

begin_define
define|#
directive|define
name|MY_ARP
value|0x000000008
end_define

begin_comment
comment|/* receive runt pkt */
end_comment

begin_define
define|#
directive|define
name|MY_ALP
value|0x000000004
end_define

begin_comment
comment|/* receive long pkt */
end_comment

begin_define
define|#
directive|define
name|MY_SEP
value|0x000000002
end_define

begin_comment
comment|/* receive error pkt */
end_comment

begin_define
define|#
directive|define
name|MY_RE
value|0x000000001
end_define

begin_comment
comment|/* receive enable */
end_comment

begin_comment
comment|/*  * Transmit Configuration Register  */
end_comment

begin_define
define|#
directive|define
name|MY_TXRUN
value|0x04000000
end_define

begin_comment
comment|/* transmit running status */
end_comment

begin_define
define|#
directive|define
name|MY_Enhanced
value|0x02000000
end_define

begin_comment
comment|/* transmit enhanced mode */
end_comment

begin_define
define|#
directive|define
name|MY_TFCEN
value|0x01000000
end_define

begin_comment
comment|/* tx flow control packet enable */
end_comment

begin_define
define|#
directive|define
name|MY_TFT64
value|0x00000000
end_define

begin_comment
comment|/* 64 bytes */
end_comment

begin_define
define|#
directive|define
name|MY_TFT32
value|0x00200000
end_define

begin_comment
comment|/* 32 bytes */
end_comment

begin_define
define|#
directive|define
name|MY_TFT128
value|0x00400000
end_define

begin_comment
comment|/* 128 bytes */
end_comment

begin_define
define|#
directive|define
name|MY_TFT256
value|0x00600000
end_define

begin_comment
comment|/* 256 bytes */
end_comment

begin_define
define|#
directive|define
name|MY_TFT512
value|0x00800000
end_define

begin_comment
comment|/* 512 bytes */
end_comment

begin_define
define|#
directive|define
name|MY_TFT768
value|0x00A00000
end_define

begin_comment
comment|/* 768 bytes */
end_comment

begin_define
define|#
directive|define
name|MY_TFT1024
value|0x00C00000
end_define

begin_comment
comment|/* 1024 bytes */
end_comment

begin_define
define|#
directive|define
name|MY_TFTSF
value|0x00E00000
end_define

begin_comment
comment|/* store and forward */
end_comment

begin_define
define|#
directive|define
name|MY_FD
value|0x00100000
end_define

begin_comment
comment|/* full duplex mode */
end_comment

begin_define
define|#
directive|define
name|MY_PS10
value|0x00080000
end_define

begin_comment
comment|/* port speed is 10M */
end_comment

begin_define
define|#
directive|define
name|MY_TE
value|0x00040000
end_define

begin_comment
comment|/* transmit enable */
end_comment

begin_define
define|#
directive|define
name|MY_PS1000
value|0x00010000
end_define

begin_comment
comment|/* port speed is 1000M */
end_comment

begin_comment
comment|/*  * Bus Command Register  */
end_comment

begin_define
define|#
directive|define
name|MY_PROG
value|0x00000200
end_define

begin_comment
comment|/* programming */
end_comment

begin_define
define|#
directive|define
name|MY_RLE
value|0x00000100
end_define

begin_comment
comment|/* read line command enable */
end_comment

begin_define
define|#
directive|define
name|MY_RME
value|0x00000080
end_define

begin_comment
comment|/* read multiple command enable */
end_comment

begin_define
define|#
directive|define
name|MY_WIE
value|0x00000040
end_define

begin_comment
comment|/* write and invalidate cmd enable */
end_comment

begin_define
define|#
directive|define
name|MY_PBL1
value|0x00000000
end_define

begin_comment
comment|/* 1 dword */
end_comment

begin_define
define|#
directive|define
name|MY_PBL4
value|0x00000008
end_define

begin_comment
comment|/* 4 dwords */
end_comment

begin_define
define|#
directive|define
name|MY_PBL8
value|0x00000010
end_define

begin_comment
comment|/* 8 dwords */
end_comment

begin_define
define|#
directive|define
name|MY_PBL16
value|0x00000018
end_define

begin_comment
comment|/* 16 dwords */
end_comment

begin_define
define|#
directive|define
name|MY_PBL32
value|0x00000020
end_define

begin_comment
comment|/* 32 dwords */
end_comment

begin_define
define|#
directive|define
name|MY_PBL64
value|0x00000028
end_define

begin_comment
comment|/* 64 dwords */
end_comment

begin_define
define|#
directive|define
name|MY_PBL128
value|0x00000030
end_define

begin_comment
comment|/* 128 dwords */
end_comment

begin_define
define|#
directive|define
name|MY_PBL512
value|0x00000038
end_define

begin_comment
comment|/* 512 dwords */
end_comment

begin_define
define|#
directive|define
name|MY_ABR
value|0x00000004
end_define

begin_comment
comment|/* arbitration rule */
end_comment

begin_define
define|#
directive|define
name|MY_BLS
value|0x00000002
end_define

begin_comment
comment|/* big/little endian select */
end_comment

begin_define
define|#
directive|define
name|MY_SWR
value|0x00000001
end_define

begin_comment
comment|/* software reset */
end_comment

begin_comment
comment|/*  * Transmit Poll Demand Register  */
end_comment

begin_define
define|#
directive|define
name|MY_TxPollDemand
value|0x1
end_define

begin_comment
comment|/*  * Receive Poll Demand Register  */
end_comment

begin_define
define|#
directive|define
name|MY_RxPollDemand
value|0x01
end_define

begin_comment
comment|/*  * Interrupt Status Register  */
end_comment

begin_define
define|#
directive|define
name|MY_RFCON
value|0x00020000
end_define

begin_comment
comment|/* receive flow control xon packet */
end_comment

begin_define
define|#
directive|define
name|MY_RFCOFF
value|0x00010000
end_define

begin_comment
comment|/* receive flow control xoff packet */
end_comment

begin_define
define|#
directive|define
name|MY_LSCStatus
value|0x00008000
end_define

begin_comment
comment|/* link status change */
end_comment

begin_define
define|#
directive|define
name|MY_ANCStatus
value|0x00004000
end_define

begin_comment
comment|/* autonegotiation completed */
end_comment

begin_define
define|#
directive|define
name|MY_FBE
value|0x00002000
end_define

begin_comment
comment|/* fatal bus error */
end_comment

begin_define
define|#
directive|define
name|MY_FBEMask
value|0x00001800
end_define

begin_define
define|#
directive|define
name|MY_ParityErr
value|0x00000000
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|MY_MasterErr
value|0x00000800
end_define

begin_comment
comment|/* master error */
end_comment

begin_define
define|#
directive|define
name|MY_TargetErr
value|0x00001000
end_define

begin_comment
comment|/* target abort */
end_comment

begin_define
define|#
directive|define
name|MY_TUNF
value|0x00000400
end_define

begin_comment
comment|/* transmit underflow */
end_comment

begin_define
define|#
directive|define
name|MY_ROVF
value|0x00000200
end_define

begin_comment
comment|/* receive overflow */
end_comment

begin_define
define|#
directive|define
name|MY_ETI
value|0x00000100
end_define

begin_comment
comment|/* transmit early int */
end_comment

begin_define
define|#
directive|define
name|MY_ERI
value|0x00000080
end_define

begin_comment
comment|/* receive early int */
end_comment

begin_define
define|#
directive|define
name|MY_CNTOVF
value|0x00000040
end_define

begin_comment
comment|/* counter overflow */
end_comment

begin_define
define|#
directive|define
name|MY_RBU
value|0x00000020
end_define

begin_comment
comment|/* receive buffer unavailable */
end_comment

begin_define
define|#
directive|define
name|MY_TBU
value|0x00000010
end_define

begin_comment
comment|/* transmit buffer unavilable */
end_comment

begin_define
define|#
directive|define
name|MY_TI
value|0x00000008
end_define

begin_comment
comment|/* transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|MY_RI
value|0x00000004
end_define

begin_comment
comment|/* receive interrupt */
end_comment

begin_define
define|#
directive|define
name|MY_RxErr
value|0x00000002
end_define

begin_comment
comment|/* receive error */
end_comment

begin_comment
comment|/*  * Interrupt Mask Register  */
end_comment

begin_define
define|#
directive|define
name|MY_MRFCON
value|0x00020000
end_define

begin_comment
comment|/* receive flow control xon packet */
end_comment

begin_define
define|#
directive|define
name|MY_MRFCOFF
value|0x00010000
end_define

begin_comment
comment|/* receive flow control xoff packet */
end_comment

begin_define
define|#
directive|define
name|MY_MLSCStatus
value|0x00008000
end_define

begin_comment
comment|/* link status change */
end_comment

begin_define
define|#
directive|define
name|MY_MANCStatus
value|0x00004000
end_define

begin_comment
comment|/* autonegotiation completed */
end_comment

begin_define
define|#
directive|define
name|MY_MFBE
value|0x00002000
end_define

begin_comment
comment|/* fatal bus error */
end_comment

begin_define
define|#
directive|define
name|MY_MFBEMask
value|0x00001800
end_define

begin_define
define|#
directive|define
name|MY_MTUNF
value|0x00000400
end_define

begin_comment
comment|/* transmit underflow */
end_comment

begin_define
define|#
directive|define
name|MY_MROVF
value|0x00000200
end_define

begin_comment
comment|/* receive overflow */
end_comment

begin_define
define|#
directive|define
name|MY_METI
value|0x00000100
end_define

begin_comment
comment|/* transmit early int */
end_comment

begin_define
define|#
directive|define
name|MY_MERI
value|0x00000080
end_define

begin_comment
comment|/* receive early int */
end_comment

begin_define
define|#
directive|define
name|MY_MCNTOVF
value|0x00000040
end_define

begin_comment
comment|/* counter overflow */
end_comment

begin_define
define|#
directive|define
name|MY_MRBU
value|0x00000020
end_define

begin_comment
comment|/* receive buffer unavailable */
end_comment

begin_define
define|#
directive|define
name|MY_MTBU
value|0x00000010
end_define

begin_comment
comment|/* transmit buffer unavilable */
end_comment

begin_define
define|#
directive|define
name|MY_MTI
value|0x00000008
end_define

begin_comment
comment|/* transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|MY_MRI
value|0x00000004
end_define

begin_comment
comment|/* receive interrupt */
end_comment

begin_define
define|#
directive|define
name|MY_MRxErr
value|0x00000002
end_define

begin_comment
comment|/* receive error */
end_comment

begin_comment
comment|/* 90/1/18 delete */
end_comment

begin_comment
comment|/* #define MY_INTRS MY_FBE|MY_MRBU|MY_TBU|MY_MTI|MY_MRI|MY_METI */
end_comment

begin_define
define|#
directive|define
name|MY_INTRS
value|MY_MRBU|MY_TBU|MY_MTI|MY_MRI|MY_METI
end_define

begin_comment
comment|/*  * Flow Control High/Low Threshold Register  */
end_comment

begin_define
define|#
directive|define
name|MY_FCHTShift
value|16
end_define

begin_comment
comment|/* flow control high threshold */
end_comment

begin_define
define|#
directive|define
name|MY_FCLTShift
value|0
end_define

begin_comment
comment|/* flow control low threshold */
end_comment

begin_comment
comment|/*  * BootROM/EEPROM/MII Management Register  */
end_comment

begin_define
define|#
directive|define
name|MY_MASK_MIIR_MII_READ
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MY_MASK_MIIR_MII_WRITE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MY_MASK_MIIR_MII_MDO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MY_MASK_MIIR_MII_MDI
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MY_MASK_MIIR_MII_MDC
value|0x00000001
end_define

begin_comment
comment|/*  * Tally Counter for CRC and MPA  */
end_comment

begin_define
define|#
directive|define
name|MY_TCOVF
value|0x80000000
end_define

begin_comment
comment|/* crc tally counter overflow */
end_comment

begin_define
define|#
directive|define
name|MY_CRCMask
value|0x7fff0000
end_define

begin_comment
comment|/* crc number: bit 16-30 */
end_comment

begin_define
define|#
directive|define
name|MY_CRCShift
value|16
end_define

begin_define
define|#
directive|define
name|MY_TMOVF
value|0x00008000
end_define

begin_comment
comment|/* mpa tally counter overflow */
end_comment

begin_define
define|#
directive|define
name|MY_MPAMask
value|0x00007fff
end_define

begin_comment
comment|/* mpa number: bit 0-14 */
end_comment

begin_define
define|#
directive|define
name|MY_MPAShift
value|0
end_define

begin_comment
comment|/*  * Tally Counters for transmit status  */
end_comment

begin_define
define|#
directive|define
name|MY_AbortMask
value|0xff000000
end_define

begin_comment
comment|/* transmit abort number */
end_comment

begin_define
define|#
directive|define
name|MY_AbortShift
value|24
end_define

begin_define
define|#
directive|define
name|MY_LColMask
value|0x00ff0000
end_define

begin_comment
comment|/* transmit late collisions */
end_comment

begin_define
define|#
directive|define
name|MY_LColShift
value|16
end_define

begin_define
define|#
directive|define
name|MY_NCRMask
value|0x0000ffff
end_define

begin_comment
comment|/* transmit retry number */
end_comment

begin_define
define|#
directive|define
name|MY_NCRShift
value|0
end_define

begin_comment
comment|/*  * Myson TX/RX descriptor structure.  */
end_comment

begin_struct
struct|struct
name|my_desc
block|{
name|u_int32_t
name|my_status
decl_stmt|;
name|u_int32_t
name|my_ctl
decl_stmt|;
name|u_int32_t
name|my_data
decl_stmt|;
name|u_int32_t
name|my_next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * for tx/rx descriptors  */
end_comment

begin_define
define|#
directive|define
name|MY_OWNByNIC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MY_OWNByDriver
value|0x0
end_define

begin_comment
comment|/*  * receive descriptor 0  */
end_comment

begin_define
define|#
directive|define
name|MY_RXOWN
value|0x80000000
end_define

begin_comment
comment|/* own bit */
end_comment

begin_define
define|#
directive|define
name|MY_FLNGMASK
value|0x0fff0000
end_define

begin_comment
comment|/* frame length */
end_comment

begin_define
define|#
directive|define
name|MY_FLNGShift
value|16
end_define

begin_define
define|#
directive|define
name|MY_MARSTATUS
value|0x00004000
end_define

begin_comment
comment|/* multicast address received */
end_comment

begin_define
define|#
directive|define
name|MY_BARSTATUS
value|0x00002000
end_define

begin_comment
comment|/* broadcast address received */
end_comment

begin_define
define|#
directive|define
name|MY_PHYSTATUS
value|0x00001000
end_define

begin_comment
comment|/* physical address received */
end_comment

begin_define
define|#
directive|define
name|MY_RXFSD
value|0x00000800
end_define

begin_comment
comment|/* first descriptor */
end_comment

begin_define
define|#
directive|define
name|MY_RXLSD
value|0x00000400
end_define

begin_comment
comment|/* last descriptor */
end_comment

begin_define
define|#
directive|define
name|MY_ES
value|0x00000080
end_define

begin_comment
comment|/* error summary */
end_comment

begin_define
define|#
directive|define
name|MY_RUNT
value|0x00000040
end_define

begin_comment
comment|/* runt packet received */
end_comment

begin_define
define|#
directive|define
name|MY_LONG
value|0x00000020
end_define

begin_comment
comment|/* long packet received */
end_comment

begin_define
define|#
directive|define
name|MY_FAE
value|0x00000010
end_define

begin_comment
comment|/* frame align error */
end_comment

begin_define
define|#
directive|define
name|MY_CRC
value|0x00000008
end_define

begin_comment
comment|/* crc error */
end_comment

begin_define
define|#
directive|define
name|MY_RXER
value|0x00000004
end_define

begin_comment
comment|/* receive error */
end_comment

begin_define
define|#
directive|define
name|MY_RDES0CHECK
value|0x000078fc
end_define

begin_comment
comment|/* only check MAR, BAR, PHY, ES, RUNT,                                            LONG, FAE, CRC and RXER bits */
end_comment

begin_comment
comment|/*  * receive descriptor 1  */
end_comment

begin_define
define|#
directive|define
name|MY_RXIC
value|0x00800000
end_define

begin_comment
comment|/* interrupt control */
end_comment

begin_define
define|#
directive|define
name|MY_RBSMASK
value|0x000007ff
end_define

begin_comment
comment|/* receive buffer size */
end_comment

begin_define
define|#
directive|define
name|MY_RBSShift
value|0
end_define

begin_comment
comment|/*  * transmit descriptor 0  */
end_comment

begin_define
define|#
directive|define
name|MY_TXERR
value|0x00008000
end_define

begin_comment
comment|/* transmit error */
end_comment

begin_define
define|#
directive|define
name|MY_JABTO
value|0x00004000
end_define

begin_comment
comment|/* jabber timeout */
end_comment

begin_define
define|#
directive|define
name|MY_CSL
value|0x00002000
end_define

begin_comment
comment|/* carrier sense lost */
end_comment

begin_define
define|#
directive|define
name|MY_LC
value|0x00001000
end_define

begin_comment
comment|/* late collision */
end_comment

begin_define
define|#
directive|define
name|MY_EC
value|0x00000800
end_define

begin_comment
comment|/* excessive collision */
end_comment

begin_define
define|#
directive|define
name|MY_UDF
value|0x00000400
end_define

begin_comment
comment|/* fifo underflow */
end_comment

begin_define
define|#
directive|define
name|MY_DFR
value|0x00000200
end_define

begin_comment
comment|/* deferred */
end_comment

begin_define
define|#
directive|define
name|MY_HF
value|0x00000100
end_define

begin_comment
comment|/* heartbeat fail */
end_comment

begin_define
define|#
directive|define
name|MY_NCRMASK
value|0x000000ff
end_define

begin_comment
comment|/* collision retry count */
end_comment

begin_define
define|#
directive|define
name|MY_NCRShift
value|0
end_define

begin_comment
comment|/*  * tx descriptor 1  */
end_comment

begin_define
define|#
directive|define
name|MY_TXIC
value|0x80000000
end_define

begin_comment
comment|/* interrupt control */
end_comment

begin_define
define|#
directive|define
name|MY_ETIControl
value|0x40000000
end_define

begin_comment
comment|/* early transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|MY_TXLD
value|0x20000000
end_define

begin_comment
comment|/* last descriptor */
end_comment

begin_define
define|#
directive|define
name|MY_TXFD
value|0x10000000
end_define

begin_comment
comment|/* first descriptor */
end_comment

begin_define
define|#
directive|define
name|MY_CRCDisable
value|0x00000000
end_define

begin_comment
comment|/* crc control */
end_comment

begin_define
define|#
directive|define
name|MY_CRCEnable
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MY_PADDisable
value|0x00000000
end_define

begin_comment
comment|/* padding control */
end_comment

begin_define
define|#
directive|define
name|MY_PADEnable
value|0x04000000
end_define

begin_define
define|#
directive|define
name|MY_RetryTxLC
value|0x02000000
end_define

begin_comment
comment|/* retry late collision */
end_comment

begin_define
define|#
directive|define
name|MY_PKTShift
value|11
end_define

begin_comment
comment|/* transmit pkt size */
end_comment

begin_define
define|#
directive|define
name|MY_TBSMASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|MY_TBSShift
value|0
end_define

begin_comment
comment|/* transmit buffer size */
end_comment

begin_define
define|#
directive|define
name|MY_MAXFRAGS
value|1
end_define

begin_define
define|#
directive|define
name|MY_RX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|MY_TX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|MY_MIN_FRAMELEN
value|60
end_define

begin_comment
comment|/*  * A transmit 'super descriptor' is actually MY_MAXFRAGS regular  * descriptors clumped together. The idea here is to emulate the  * multi-fragment descriptor layout found in devices such as the  * Texas Instruments ThunderLAN and 3Com boomerang and cylone chips.  * The advantage to using this scheme is that it avoids buffer copies.  * The disadvantage is that there's a certain amount of overhead due  * to the fact that each 'fragment' is 16 bytes long. In my tests,  * this limits top speed to about 10.5MB/sec. It should be more like  * 11.5MB/sec. However, the upshot is that you can achieve better  * results on slower machines: a Pentium 200 can pump out packets at  * same speed as a PII 400.  */
end_comment

begin_struct
struct|struct
name|my_txdesc
block|{
name|struct
name|my_desc
name|my_frag
index|[
name|MY_MAXFRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MY_TXSTATUS
parameter_list|(
name|x
parameter_list|)
value|x->my_ptr->my_frag[x->my_lastdesc].my_status
end_define

begin_define
define|#
directive|define
name|MY_TXCTL
parameter_list|(
name|x
parameter_list|)
value|x->my_ptr->my_frag[x->my_lastdesc].my_ctl
end_define

begin_define
define|#
directive|define
name|MY_TXDATA
parameter_list|(
name|x
parameter_list|)
value|x->my_ptr->my_frag[x->my_lastdesc].my_data
end_define

begin_define
define|#
directive|define
name|MY_TXNEXT
parameter_list|(
name|x
parameter_list|)
value|x->my_ptr->my_frag[x->my_lastdesc].my_next
end_define

begin_define
define|#
directive|define
name|MY_TXOWN
parameter_list|(
name|x
parameter_list|)
value|x->my_ptr->my_frag[0].my_status
end_define

begin_define
define|#
directive|define
name|MY_UNSENT
value|0x1234
end_define

begin_struct
struct|struct
name|my_list_data
block|{
name|struct
name|my_desc
name|my_rx_list
index|[
name|MY_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|my_txdesc
name|my_tx_list
index|[
name|MY_TX_LIST_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|my_chain
block|{
name|struct
name|my_txdesc
modifier|*
name|my_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|my_mbuf
decl_stmt|;
name|struct
name|my_chain
modifier|*
name|my_nextdesc
decl_stmt|;
name|u_int8_t
name|my_lastdesc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|my_chain_onefrag
block|{
name|struct
name|my_desc
modifier|*
name|my_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|my_mbuf
decl_stmt|;
name|struct
name|my_chain_onefrag
modifier|*
name|my_nextdesc
decl_stmt|;
name|u_int8_t
name|my_rlast
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|my_chain_data
block|{
name|struct
name|my_chain_onefrag
name|my_rx_chain
index|[
name|MY_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|my_chain
name|my_tx_chain
index|[
name|MY_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|my_chain_onefrag
modifier|*
name|my_rx_head
decl_stmt|;
name|struct
name|my_chain
modifier|*
name|my_tx_head
decl_stmt|;
name|struct
name|my_chain
modifier|*
name|my_tx_tail
decl_stmt|;
name|struct
name|my_chain
modifier|*
name|my_tx_free
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|my_type
block|{
name|u_int16_t
name|my_vid
decl_stmt|;
name|u_int16_t
name|my_did
decl_stmt|;
name|char
modifier|*
name|my_name
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MY_FLAG_FORCEDELAY
value|1
end_define

begin_define
define|#
directive|define
name|MY_FLAG_SCHEDDELAY
value|2
end_define

begin_define
define|#
directive|define
name|MY_FLAG_DELAYTIMEO
value|3
end_define

begin_struct
struct|struct
name|my_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* interface info */
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
comment|/* media info */
name|bus_space_handle_t
name|my_bhandle
decl_stmt|;
name|bus_space_tag_t
name|my_btag
decl_stmt|;
name|struct
name|my_type
modifier|*
name|my_info
decl_stmt|;
comment|/* adapter info */
name|struct
name|my_type
modifier|*
name|my_pinfo
decl_stmt|;
comment|/* phy info */
name|struct
name|resource
modifier|*
name|my_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|my_irq
decl_stmt|;
name|void
modifier|*
name|my_intrhand
decl_stmt|;
name|u_int8_t
name|my_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|my_phy_addr
decl_stmt|;
comment|/* PHY address */
name|u_int8_t
name|my_tx_pend
decl_stmt|;
comment|/* TX pending */
name|u_int8_t
name|my_want_auto
decl_stmt|;
name|u_int8_t
name|my_autoneg
decl_stmt|;
name|u_int16_t
name|my_txthresh
decl_stmt|;
name|u_int8_t
name|my_stats_no_timeout
decl_stmt|;
name|caddr_t
name|my_ldata_ptr
decl_stmt|;
name|struct
name|my_list_data
modifier|*
name|my_ldata
decl_stmt|;
name|struct
name|my_chain_data
name|my_cdata
decl_stmt|;
name|device_t
name|my_miibus
decl_stmt|;
name|struct
name|callout_handle
name|my_stat_ch
decl_stmt|;
comment|/* Add by Surfer 2001/12/2 */
name|struct
name|mtx
name|my_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Add by Surfer 2001/12/2 */
end_comment

begin_define
define|#
directive|define
name|MY_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->my_mtx)
end_define

begin_define
define|#
directive|define
name|MY_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->my_mtx)
end_define

begin_comment
comment|/*  * register space access macros  */
end_comment

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
value|bus_space_write_4(sc->my_btag, sc->my_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2(sc->my_btag, sc->my_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1(sc->my_btag, sc->my_bhandle, reg, val)
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
value|bus_space_read_4(sc->my_btag, sc->my_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2(sc->my_btag, sc->my_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1(sc->my_btag, sc->my_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|MY_TIMEOUT
value|1000
end_define

begin_comment
comment|/*  * General constants that are fun to know.  *  * MYSON PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|MYSONVENDORID
value|0x1516
end_define

begin_comment
comment|/*  * MYSON device IDs.  */
end_comment

begin_define
define|#
directive|define
name|MTD800ID
value|0x0800
end_define

begin_define
define|#
directive|define
name|MTD803ID
value|0x0803
end_define

begin_define
define|#
directive|define
name|MTD891ID
value|0x0891
end_define

begin_comment
comment|/*  * ST+OP+PHYAD+REGAD+TA  */
end_comment

begin_define
define|#
directive|define
name|MY_OP_READ
value|0x6000
end_define

begin_comment
comment|/* ST:01+OP:10+PHYAD+REGAD+TA:Z0 */
end_comment

begin_define
define|#
directive|define
name|MY_OP_WRITE
value|0x5002
end_define

begin_comment
comment|/* ST:01+OP:01+PHYAD+REGAD+TA:10 */
end_comment

begin_comment
comment|/*  * Constansts for Myson PHY  */
end_comment

begin_define
define|#
directive|define
name|MysonPHYID0
value|0x0300
end_define

begin_comment
comment|/*  * Constansts for Seeq 80225 PHY  */
end_comment

begin_define
define|#
directive|define
name|SeeqPHYID0
value|0x0016
end_define

begin_define
define|#
directive|define
name|SEEQ_MIIRegister18
value|18
end_define

begin_define
define|#
directive|define
name|SEEQ_SPD_DET_100
value|0x80
end_define

begin_define
define|#
directive|define
name|SEEQ_DPLX_DET_FULL
value|0x40
end_define

begin_comment
comment|/*  * Constansts for Ahdoc 101 PHY  */
end_comment

begin_define
define|#
directive|define
name|AhdocPHYID0
value|0x0022
end_define

begin_define
define|#
directive|define
name|AHDOC_DiagnosticReg
value|18
end_define

begin_define
define|#
directive|define
name|AHDOC_DPLX_FULL
value|0x0800
end_define

begin_define
define|#
directive|define
name|AHDOC_Speed_100
value|0x0400
end_define

begin_comment
comment|/*  * Constansts for Marvell 88E1000/88E1000S PHY and LevelOne PHY  */
end_comment

begin_define
define|#
directive|define
name|MarvellPHYID0
value|0x0141
end_define

begin_define
define|#
directive|define
name|LevelOnePHYID0
value|0x0013
end_define

begin_define
define|#
directive|define
name|Marvell_SpecificStatus
value|17
end_define

begin_define
define|#
directive|define
name|Marvell_Speed1000
value|0x8000
end_define

begin_define
define|#
directive|define
name|Marvell_Speed100
value|0x4000
end_define

begin_define
define|#
directive|define
name|Marvell_FullDuplex
value|0x2000
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers. Note: some are only available on  * the 3c905B, in particular those that related to power management.  */
end_comment

begin_define
define|#
directive|define
name|MY_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|MY_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|MY_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|MY_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|MY_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|MY_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|MY_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|MY_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|MY_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|MY_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|MY_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|MY_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|MY_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|MY_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|MY_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|MY_PCI_EEPROM_DATA
value|0x4C
end_define

begin_define
define|#
directive|define
name|PHY_UNKNOWN
value|3
end_define

begin_define
define|#
directive|define
name|MY_PHYADDR_MIN
value|0x00
end_define

begin_define
define|#
directive|define
name|MY_PHYADDR_MAX
value|0x1F
end_define

begin_define
define|#
directive|define
name|PHY_BMCR
value|0x00
end_define

begin_define
define|#
directive|define
name|PHY_BMSR
value|0x01
end_define

begin_define
define|#
directive|define
name|PHY_VENID
value|0x02
end_define

begin_define
define|#
directive|define
name|PHY_DEVID
value|0x03
end_define

begin_define
define|#
directive|define
name|PHY_ANAR
value|0x04
end_define

begin_define
define|#
directive|define
name|PHY_LPAR
value|0x05
end_define

begin_define
define|#
directive|define
name|PHY_ANEXP
value|0x06
end_define

begin_define
define|#
directive|define
name|PHY_NPTR
value|0x07
end_define

begin_define
define|#
directive|define
name|PHY_LPNPR
value|0x08
end_define

begin_define
define|#
directive|define
name|PHY_1000CR
value|0x09
end_define

begin_define
define|#
directive|define
name|PHY_1000SR
value|0x0a
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_NEXTPAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD0
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_TLRFLT
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD1
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD2
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD3
value|0x0400
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BT4
value|0x0200L
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BTXFULL
value|0x0100
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BTXHALF
value|0x0080
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_10BTFULL
value|0x0040
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_10BTHALF
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO4
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO3
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO2
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO1
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO0
value|0x0001
end_define

begin_define
define|#
directive|define
name|PHY_1000SR_1000BTXFULL
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHY_1000SR_1000BTXHALF
value|0x0400
end_define

begin_comment
comment|/*  * These are the register definitions for the PHY (physical layer  * interface chip).  */
end_comment

begin_comment
comment|/*  * PHY BMCR Basic Mode Control Register  */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_LOOPBK
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_SPEEDSEL
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_AUTONEGENBL
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD0
value|0x0800
end_define

begin_comment
comment|/* write as zero */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_ISOLATE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_AUTONEGRSTR
value|0x0200
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_COLLTEST
value|0x0080
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_1000
value|0x0040
end_define

begin_comment
comment|/* only used for Marvell PHY */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD2
value|0x0020
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD3
value|0x0010
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD4
value|0x0008
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD5
value|0x0004
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD6
value|0x0002
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD7
value|0x0001
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_comment
comment|/*  * RESET: 1 == software reset, 0 == normal operation  * Resets status and control registers to default values.  * Relatches all hardware config values.  *  * LOOPBK: 1 == loopback operation enabled, 0 == normal operation  *  * SPEEDSEL: 1 == 100Mb/s, 0 == 10Mb/s  * Link speed is selected byt his bit or if auto-negotiation if bit  * 12 (AUTONEGENBL) is set (in which case the value of this register  * is ignored).  *  * AUTONEGENBL: 1 == Autonegotiation enabled, 0 == Autonegotiation disabled  * Bits 8 and 13 are ignored when autoneg is set, otherwise bits 8 and 13  * determine speed and mode. Should be cleared and then set if PHY configured  * for no autoneg on startup.  *  * ISOLATE: 1 == isolate PHY from MII, 0 == normal operation  *  * AUTONEGRSTR: 1 == restart autonegotiation, 0 = normal operation  *  * DUPLEX: 1 == full duplex mode, 0 == half duplex mode  *  * COLLTEST: 1 == collision test enabled, 0 == normal operation  */
end_comment

begin_comment
comment|/*  * PHY, BMSR Basic Mode Status Register  */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_100BT4
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_100BTXFULL
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_100BTXHALF
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_10BTFULL
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_10BTHALF
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD1
value|0x0400
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD2
value|0x0200
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD3
value|0x0100
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD4
value|0x0080
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_MFPRESUP
value|0x0040
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_AUTONEGCOMP
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_REMFAULT
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_CANAUTONEG
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_LINKSTAT
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_JABBER
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_EXTENDED
value|0x0001
end_define

end_unit


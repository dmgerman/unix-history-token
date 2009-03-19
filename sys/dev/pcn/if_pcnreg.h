begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Berkeley Software Design, Inc.  * Copyright (c) 1997, 1998, 1999, 2000  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * I/O map in 16-bit mode. To switch to 32-bit mode,  * you need to perform a 32-bit write to the RDP register  * (writing a 0 is recommended).  */
end_comment

begin_define
define|#
directive|define
name|PCN_IO16_APROM00
value|0x00
end_define

begin_define
define|#
directive|define
name|PCN_IO16_APROM01
value|0x02
end_define

begin_define
define|#
directive|define
name|PCN_IO16_APROM02
value|0x04
end_define

begin_define
define|#
directive|define
name|PCN_IO16_APROM03
value|0x06
end_define

begin_define
define|#
directive|define
name|PCN_IO16_APROM04
value|0x08
end_define

begin_define
define|#
directive|define
name|PCN_IO16_APROM05
value|0x0A
end_define

begin_define
define|#
directive|define
name|PCN_IO16_APROM06
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCN_IO16_APROM07
value|0x0E
end_define

begin_define
define|#
directive|define
name|PCN_IO16_RDP
value|0x10
end_define

begin_define
define|#
directive|define
name|PCN_IO16_RAP
value|0x12
end_define

begin_define
define|#
directive|define
name|PCN_IO16_RESET
value|0x14
end_define

begin_define
define|#
directive|define
name|PCN_IO16_BDP
value|0x16
end_define

begin_comment
comment|/*  * I/O map in 32-bit mode.  */
end_comment

begin_define
define|#
directive|define
name|PCN_IO32_APROM00
value|0x00
end_define

begin_define
define|#
directive|define
name|PCN_IO32_APROM01
value|0x04
end_define

begin_define
define|#
directive|define
name|PCN_IO32_APROM02
value|0x08
end_define

begin_define
define|#
directive|define
name|PCN_IO32_APROM03
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCN_IO32_RDP
value|0x10
end_define

begin_define
define|#
directive|define
name|PCN_IO32_RAP
value|0x14
end_define

begin_define
define|#
directive|define
name|PCN_IO32_RESET
value|0x18
end_define

begin_define
define|#
directive|define
name|PCN_IO32_BDP
value|0x1C
end_define

begin_comment
comment|/*  * CSR registers  */
end_comment

begin_define
define|#
directive|define
name|PCN_CSR_CSR
value|0x00
end_define

begin_define
define|#
directive|define
name|PCN_CSR_IAB0
value|0x01
end_define

begin_define
define|#
directive|define
name|PCN_CSR_IAB1
value|0x02
end_define

begin_define
define|#
directive|define
name|PCN_CSR_IMR
value|0x03
end_define

begin_define
define|#
directive|define
name|PCN_CSR_TFEAT
value|0x04
end_define

begin_define
define|#
directive|define
name|PCN_CSR_EXTCTL1
value|0x05
end_define

begin_define
define|#
directive|define
name|PCN_CSR_DTBLLEN
value|0x06
end_define

begin_define
define|#
directive|define
name|PCN_CSR_EXTCTL2
value|0x07
end_define

begin_define
define|#
directive|define
name|PCN_CSR_MAR0
value|0x08
end_define

begin_define
define|#
directive|define
name|PCN_CSR_MAR1
value|0x09
end_define

begin_define
define|#
directive|define
name|PCN_CSR_MAR2
value|0x0A
end_define

begin_define
define|#
directive|define
name|PCN_CSR_MAR3
value|0x0B
end_define

begin_define
define|#
directive|define
name|PCN_CSR_PAR0
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCN_CSR_PAR1
value|0x0D
end_define

begin_define
define|#
directive|define
name|PCN_CSR_PAR2
value|0x0E
end_define

begin_define
define|#
directive|define
name|PCN_CSR_MODE
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCN_CSR_RXADDR0
value|0x18
end_define

begin_define
define|#
directive|define
name|PCN_CSR_RXADDR1
value|0x19
end_define

begin_define
define|#
directive|define
name|PCN_CSR_TXADDR0
value|0x1E
end_define

begin_define
define|#
directive|define
name|PCN_CSR_TXADDR1
value|0x1F
end_define

begin_define
define|#
directive|define
name|PCN_CSR_TXPOLL
value|0x2F
end_define

begin_define
define|#
directive|define
name|PCN_CSR_RXPOLL
value|0x31
end_define

begin_define
define|#
directive|define
name|PCN_CSR_RXRINGLEN
value|0x4C
end_define

begin_define
define|#
directive|define
name|PCN_CSR_TXRINGLEN
value|0x4E
end_define

begin_define
define|#
directive|define
name|PCN_CSR_DMACTL
value|0x50
end_define

begin_define
define|#
directive|define
name|PCN_CSR_BUSTIMER
value|0x52
end_define

begin_define
define|#
directive|define
name|PCN_CSR_MEMERRTIMEO
value|0x64
end_define

begin_define
define|#
directive|define
name|PCN_CSR_ONNOWMISC
value|0x74
end_define

begin_define
define|#
directive|define
name|PCN_CSR_ADVFEAT
value|0x7A
end_define

begin_define
define|#
directive|define
name|PCN_CSR_MACCFG
value|0x7D
end_define

begin_define
define|#
directive|define
name|PCN_CSR_CHIPID0
value|0x58
end_define

begin_define
define|#
directive|define
name|PCN_CSR_CHIPID1
value|0x59
end_define

begin_comment
comment|/*  * Control and status register (CSR0)  */
end_comment

begin_define
define|#
directive|define
name|PCN_CSR_INIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCN_CSR_START
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCN_CSR_STOP
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCN_CSR_TX
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCN_CSR_TXON
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCN_CSR_RXON
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCN_CSR_INTEN
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCN_CSR_INTR
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCN_CSR_IDONE
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCN_CSR_TINT
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCN_CSR_RINT
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCN_CSR_MERR
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCN_CSR_MISS
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCN_CSR_CERR
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCN_CSR_ERR
value|0x8000
end_define

begin_comment
comment|/*  * Interrupt masks and deferral control (CSR3)  */
end_comment

begin_define
define|#
directive|define
name|PCN_IMR_BSWAP
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCN_IMR_ENMBA
value|0x0008
end_define

begin_comment
comment|/* enable modified backoff alg */
end_comment

begin_define
define|#
directive|define
name|PCN_IMR_DXMT2PD
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCN_IMR_LAPPEN
value|0x0020
end_define

begin_comment
comment|/* lookahead packet processing enb */
end_comment

begin_define
define|#
directive|define
name|PCN_IMR_DXSUFLO
value|0x0040
end_define

begin_comment
comment|/* disable TX stop on underflow */
end_comment

begin_define
define|#
directive|define
name|PCN_IMR_IDONE
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCN_IMR_TINT
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCN_IMR_RINT
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCN_IMR_MERR
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCN_IMR_MISS
value|0x1000
end_define

begin_comment
comment|/*  * Test and features control (CSR4)  */
end_comment

begin_define
define|#
directive|define
name|PCN_TFEAT_TXSTRTMASK
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCN_TFEAT_TXSTRT
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCN_TFEAT_RXCCOFLOWM
value|0x0010
end_define

begin_comment
comment|/* Rx collision counter oflow */
end_comment

begin_define
define|#
directive|define
name|PCN_TFEAT_RXCCOFLOW
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCN_TFEAT_UINT
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCN_TFEAT_UINTREQ
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCN_TFEAT_MISSOFLOWM
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCN_TFEAT_MISSOFLOW
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCN_TFEAT_STRIP_FCS
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCN_TFEAT_PAD_TX
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCN_TFEAT_TXDPOLL
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCN_TFEAT_DMAPLUS
value|0x4000
end_define

begin_comment
comment|/*  * Extended control and interrupt 1 (CSR5)  */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_SPND
value|0x0001
end_define

begin_comment
comment|/* suspend */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_MPMODE
value|0x0002
end_define

begin_comment
comment|/* magic packet mode */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_MPENB
value|0x0004
end_define

begin_comment
comment|/* magic packet enable */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_MPINTEN
value|0x0008
end_define

begin_comment
comment|/* magic packet interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_MPINT
value|0x0010
end_define

begin_comment
comment|/* magic packet interrupt */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_MPPLBA
value|0x0020
end_define

begin_comment
comment|/* magic packet phys. logical bcast */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_EXDEFEN
value|0x0040
end_define

begin_comment
comment|/* excessive deferral interrupt enb. */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_EXDEF
value|0x0080
end_define

begin_comment
comment|/* excessive deferral interrupt */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_SINTEN
value|0x0400
end_define

begin_comment
comment|/* system interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_SINT
value|0x0800
end_define

begin_comment
comment|/* system interrupt */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_LTINTEN
value|0x4000
end_define

begin_comment
comment|/* last TX interrupt enb */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL1_TXOKINTD
value|0x8000
end_define

begin_comment
comment|/* TX OK interrupt disable */
end_comment

begin_comment
comment|/*  * RX/TX descriptor len (CSR6)  */
end_comment

begin_define
define|#
directive|define
name|PCN_DTBLLEN_RLEN
value|0x0F00
end_define

begin_define
define|#
directive|define
name|PCN_DTBLLEN_TLEN
value|0xF000
end_define

begin_comment
comment|/*  * Extended control and interrupt 2 (CSR7)  */
end_comment

begin_define
define|#
directive|define
name|PCN_EXTCTL2_MIIPDTINTE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_MIIPDTINT
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_MCCIINTE
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_MCCIINT
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_MCCINTE
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_MCCINT
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_MAPINTE
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_MAPINT
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_MREINTE
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_MREINT
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_STINTE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_STINT
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_RXDPOLL
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_RDMD
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_RXFRTG
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCN_EXTCTL2_FASTSPNDE
value|0x8000
end_define

begin_comment
comment|/*  * Mode (CSR15)  */
end_comment

begin_define
define|#
directive|define
name|PCN_MODE_RXD
value|0x0001
end_define

begin_comment
comment|/* RX disable */
end_comment

begin_define
define|#
directive|define
name|PCN_MODE_TXD
value|0x0002
end_define

begin_comment
comment|/* TX disable */
end_comment

begin_define
define|#
directive|define
name|PCN_MODE_LOOP
value|0x0004
end_define

begin_comment
comment|/* loopback enable */
end_comment

begin_define
define|#
directive|define
name|PCN_MODE_TXCRCD
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCN_MODE_FORCECOLL
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCN_MODE_RETRYD
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCN_MODE_INTLOOP
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCN_MODE_PORTSEL
value|0x0180
end_define

begin_define
define|#
directive|define
name|PCN_MODE_RXVPAD
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCN_MODE_RXNOBROAD
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCN_MODE_PROMISC
value|0x8000
end_define

begin_comment
comment|/* Settings for PCN_MODE_PORTSEL when ASEL (BCR2[1]) is 0 */
end_comment

begin_define
define|#
directive|define
name|PCN_PORT_AUI
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCN_PORT_10BASET
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCN_PORT_GPSI
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCN_PORT_MII
value|0x0180
end_define

begin_comment
comment|/*  * Chip ID values.  */
end_comment

begin_comment
comment|/* CSR88-89: Chip ID masks */
end_comment

begin_define
define|#
directive|define
name|AMD_MASK
value|0x003
end_define

begin_define
define|#
directive|define
name|PART_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|Am79C971
value|0x2623
end_define

begin_define
define|#
directive|define
name|Am79C972
value|0x2624
end_define

begin_define
define|#
directive|define
name|Am79C973
value|0x2625
end_define

begin_define
define|#
directive|define
name|Am79C978
value|0x2626
end_define

begin_define
define|#
directive|define
name|Am79C975
value|0x2627
end_define

begin_define
define|#
directive|define
name|Am79C976
value|0x2628
end_define

begin_comment
comment|/*  * Advanced feature control (CSR122)  */
end_comment

begin_define
define|#
directive|define
name|PCN_AFC_RXALIGN
value|0x0001
end_define

begin_comment
comment|/*  * BCR (bus control) registers  */
end_comment

begin_define
define|#
directive|define
name|PCN_BCR_MMRA
value|0x00
end_define

begin_comment
comment|/* Master Mode Read Active */
end_comment

begin_define
define|#
directive|define
name|PCN_BCR_MMW
value|0x01
end_define

begin_comment
comment|/* Master Mode Write Active */
end_comment

begin_define
define|#
directive|define
name|PCN_BCR_MISCCFG
value|0x02
end_define

begin_define
define|#
directive|define
name|PCN_BCR_LED0
value|0x04
end_define

begin_define
define|#
directive|define
name|PCN_BCR_LED1
value|0x05
end_define

begin_define
define|#
directive|define
name|PCN_BCR_LED2
value|0x06
end_define

begin_define
define|#
directive|define
name|PCN_BCR_LED3
value|0x07
end_define

begin_define
define|#
directive|define
name|PCN_BCR_DUPLEX
value|0x09
end_define

begin_define
define|#
directive|define
name|PCN_BCR_BUSCTL
value|0x12
end_define

begin_define
define|#
directive|define
name|PCN_BCR_EECTL
value|0x13
end_define

begin_define
define|#
directive|define
name|PCN_BCR_SSTYLE
value|0x14
end_define

begin_define
define|#
directive|define
name|PCN_BCR_PCILAT
value|0x16
end_define

begin_define
define|#
directive|define
name|PCN_BCR_PCISUBVENID
value|0x17
end_define

begin_define
define|#
directive|define
name|PCN_BCR_PCISUBSYSID
value|0x18
end_define

begin_define
define|#
directive|define
name|PCN_BCR_SRAMSIZE
value|0x19
end_define

begin_define
define|#
directive|define
name|PCN_BCR_SRAMBOUND
value|0x1A
end_define

begin_define
define|#
directive|define
name|PCN_BCR_SRAMCTL
value|0x1B
end_define

begin_define
define|#
directive|define
name|PCN_BCR_MIICTL
value|0x20
end_define

begin_define
define|#
directive|define
name|PCN_BCR_MIIADDR
value|0x21
end_define

begin_define
define|#
directive|define
name|PCN_BCR_MIIDATA
value|0x22
end_define

begin_define
define|#
directive|define
name|PCN_BCR_PCIVENID
value|0x23
end_define

begin_define
define|#
directive|define
name|PCN_BCR_PCIPCAP
value|0x24
end_define

begin_define
define|#
directive|define
name|PCN_BCR_DATA0
value|0x25
end_define

begin_define
define|#
directive|define
name|PCN_BCR_DATA1
value|0x26
end_define

begin_define
define|#
directive|define
name|PCN_BCR_DATA2
value|0x27
end_define

begin_define
define|#
directive|define
name|PCN_BCR_DATA3
value|0x28
end_define

begin_define
define|#
directive|define
name|PCN_BCR_DATA4
value|0x29
end_define

begin_define
define|#
directive|define
name|PCN_BCR_DATA5
value|0x2A
end_define

begin_define
define|#
directive|define
name|PCN_BCR_DATA6
value|0x2B
end_define

begin_define
define|#
directive|define
name|PCN_BCR_DATA7
value|0x2C
end_define

begin_define
define|#
directive|define
name|PCN_BCR_ONNOWPAT0
value|0x2D
end_define

begin_define
define|#
directive|define
name|PCN_BCR_ONNOWPAT1
value|0x2E
end_define

begin_define
define|#
directive|define
name|PCN_BCR_ONNOWPAT2
value|0x2F
end_define

begin_define
define|#
directive|define
name|PCN_BCR_PHYSEL
value|0x31
end_define

begin_comment
comment|/*  * Miscellaneous Configuration (BCR2)  */
end_comment

begin_define
define|#
directive|define
name|PCN_MISC_TMAULOOP
value|1<<14
end_define

begin_comment
comment|/* T-MAU Loopback packet enable. */
end_comment

begin_define
define|#
directive|define
name|PCN_MISC_LEDPE
value|1<<12
end_define

begin_comment
comment|/* LED Program Enable */
end_comment

begin_define
define|#
directive|define
name|PCN_MISC_APROMWE
value|1<<8
end_define

begin_comment
comment|/* Address PROM Write Enable */
end_comment

begin_define
define|#
directive|define
name|PCN_MISC_INTLEVEL
value|1<<7
end_define

begin_comment
comment|/* Interrupt level */
end_comment

begin_define
define|#
directive|define
name|PCN_MISC_EADISEL
value|1<<3
end_define

begin_comment
comment|/* EADI Select */
end_comment

begin_define
define|#
directive|define
name|PCN_MISC_AWAKE
value|1<<2
end_define

begin_comment
comment|/* Power saving mode select */
end_comment

begin_define
define|#
directive|define
name|PCN_MISC_ASEL
value|1<<1
end_define

begin_comment
comment|/* Auto Select */
end_comment

begin_define
define|#
directive|define
name|PCN_MISC_XMAUSEL
value|1<<0
end_define

begin_comment
comment|/* Reserved. */
end_comment

begin_comment
comment|/*  * Full duplex control (BCR9)  */
end_comment

begin_define
define|#
directive|define
name|PCN_DUPLEX_FDEN
value|0x0001
end_define

begin_comment
comment|/* Full-duplex enable */
end_comment

begin_define
define|#
directive|define
name|PCN_DUPLEX_AUI
value|0x0002
end_define

begin_comment
comment|/* AUI full-duplex */
end_comment

begin_define
define|#
directive|define
name|PCN_DUPLEX_FDRPAD
value|0x0004
end_define

begin_comment
comment|/* Full-duplex runt pkt accept dis. */
end_comment

begin_comment
comment|/*  * Burst and bus control register (BCR18)  */
end_comment

begin_define
define|#
directive|define
name|PCN_BUSCTL_BWRITE
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCN_BUSCTL_BREAD
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCN_BUSCTL_DWIO
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCN_BUSCTL_EXTREQ
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCN_BUSCTL_MEMCMD
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCN_BUSCTL_NOUFLOW
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCN_BUSCTL_ROMTMG
value|0xF000
end_define

begin_comment
comment|/*  * EEPROM control (BCR19)  */
end_comment

begin_define
define|#
directive|define
name|PCN_EECTL_EDATA
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCN_EECTL_ECLK
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCN_EECTL_EECS
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCN_EECTL_EEN
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCN_EECTL_EEDET
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCN_EECTL_PREAD
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCN_EECTL_PVALID
value|0x8000
end_define

begin_comment
comment|/*  * Software style (BCR20)  */
end_comment

begin_define
define|#
directive|define
name|PCN_SSTYLE_APERREN
value|0x0400
end_define

begin_comment
comment|/* advanced parity error checking */
end_comment

begin_define
define|#
directive|define
name|PCN_SSTYLE_SSIZE32
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCN_SSTYLE_SWSTYLE
value|0x00FF
end_define

begin_define
define|#
directive|define
name|PCN_SWSTYLE_LANCE
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCN_SWSTYLE_PCNETPCI
value|0x0102
end_define

begin_define
define|#
directive|define
name|PCN_SWSTYLE_PCNETPCI_BURST
value|0x0103
end_define

begin_comment
comment|/*  * MII control and status (BCR32)  */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_MIILP
value|0x0002
end_define

begin_comment
comment|/* MII internal loopback */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_XPHYSP
value|0x0008
end_define

begin_comment
comment|/* external PHY speed */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_XPHYFD
value|0x0010
end_define

begin_comment
comment|/* external PHY full duplex */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_XPHYANE
value|0x0020
end_define

begin_comment
comment|/* external phy auto-neg enable */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_XPHYRST
value|0x0040
end_define

begin_comment
comment|/* external PHY reset */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_DANAS
value|0x0080
end_define

begin_comment
comment|/* disable auto-neg auto-setup */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_APDW
value|0x0700
end_define

begin_comment
comment|/* auto-poll dwell time */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_APEP
value|0x0100
end_define

begin_comment
comment|/* auto-poll external PHY */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_FMDC
value|0x3000
end_define

begin_comment
comment|/* data clock speed */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_MIIPD
value|0x4000
end_define

begin_comment
comment|/* PHY detect */
end_comment

begin_define
define|#
directive|define
name|PCN_MIICTL_ANTST
value|0x8000
end_define

begin_comment
comment|/* Manufacturing test */
end_comment

begin_comment
comment|/*  * MII address register (BCR33)  */
end_comment

begin_define
define|#
directive|define
name|PCN_MIIADDR_REGAD
value|0x001F
end_define

begin_define
define|#
directive|define
name|PCN_MIIADDR_PHYAD
value|0x03E0
end_define

begin_comment
comment|/* addresses of internal PHYs */
end_comment

begin_define
define|#
directive|define
name|PCN_PHYAD_100BTX
value|30
end_define

begin_define
define|#
directive|define
name|PCN_PHYAD_10BT
value|31
end_define

begin_comment
comment|/*  * MII data register (BCR34)  */
end_comment

begin_define
define|#
directive|define
name|PCN_MIIDATA_MIIMD
value|0xFFFF
end_define

begin_comment
comment|/*  * PHY selection (BCR49) (HomePNA NIC only)  */
end_comment

begin_define
define|#
directive|define
name|PCN_PHYSEL_PHYSEL
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCN_PHYSEL_DEFAULT
value|0x0300
end_define

begin_define
define|#
directive|define
name|PCN_PHYSEL_PCNET
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCN_PHY_10BT
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCN_PHY_HOMEPNA
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCN_PHY_EXTERNAL
value|0x0002
end_define

begin_struct
struct|struct
name|pcn_rx_desc
block|{
name|u_int16_t
name|pcn_rxlen
decl_stmt|;
name|u_int16_t
name|pcn_rsvd0
decl_stmt|;
name|u_int16_t
name|pcn_bufsz
decl_stmt|;
name|u_int16_t
name|pcn_rxstat
decl_stmt|;
name|u_int32_t
name|pcn_rbaddr
decl_stmt|;
name|u_int32_t
name|pcn_uspace
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCN_RXSTAT_BPE
value|0x0080
end_define

begin_comment
comment|/* bus parity error */
end_comment

begin_define
define|#
directive|define
name|PCN_RXSTAT_ENP
value|0x0100
end_define

begin_comment
comment|/* end of packet */
end_comment

begin_define
define|#
directive|define
name|PCN_RXSTAT_STP
value|0x0200
end_define

begin_comment
comment|/* start of packet */
end_comment

begin_define
define|#
directive|define
name|PCN_RXSTAT_BUFF
value|0x0400
end_define

begin_comment
comment|/* buffer error */
end_comment

begin_define
define|#
directive|define
name|PCN_RXSTAT_CRC
value|0x0800
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|PCN_RXSTAT_OFLOW
value|0x1000
end_define

begin_comment
comment|/* rx overrun */
end_comment

begin_define
define|#
directive|define
name|PCN_RXSTAT_FRAM
value|0x2000
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|PCN_RXSTAT_ERR
value|0x4000
end_define

begin_comment
comment|/* error summary */
end_comment

begin_define
define|#
directive|define
name|PCN_RXSTAT_OWN
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCN_RXLEN_MBO
value|0xF000
end_define

begin_define
define|#
directive|define
name|PCN_RXLEN_BUFSZ
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|PCN_OWN_RXDESC
parameter_list|(
name|x
parameter_list|)
value|(((x)->pcn_rxstat& PCN_RXSTAT_OWN) == 0)
end_define

begin_struct
struct|struct
name|pcn_tx_desc
block|{
name|u_int32_t
name|pcn_txstat
decl_stmt|;
name|u_int32_t
name|pcn_txctl
decl_stmt|;
name|u_int32_t
name|pcn_tbaddr
decl_stmt|;
name|u_int32_t
name|pcn_uspace
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCN_TXSTAT_TRC
value|0x0000000F
end_define

begin_comment
comment|/* transmit retries */
end_comment

begin_define
define|#
directive|define
name|PCN_TXSTAT_RTRY
value|0x04000000
end_define

begin_comment
comment|/* retry */
end_comment

begin_define
define|#
directive|define
name|PCN_TXSTAT_LCAR
value|0x08000000
end_define

begin_comment
comment|/* lost carrier */
end_comment

begin_define
define|#
directive|define
name|PCN_TXSTAT_LCOL
value|0x10000000
end_define

begin_comment
comment|/* late collision */
end_comment

begin_define
define|#
directive|define
name|PCN_TXSTAT_EXDEF
value|0x20000000
end_define

begin_comment
comment|/* excessive deferrals */
end_comment

begin_define
define|#
directive|define
name|PCN_TXSTAT_UFLOW
value|0x40000000
end_define

begin_comment
comment|/* transmit underrun */
end_comment

begin_define
define|#
directive|define
name|PCN_TXSTAT_BUFF
value|0x80000000
end_define

begin_comment
comment|/* buffer error */
end_comment

begin_define
define|#
directive|define
name|PCN_TXCTL_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PCN_TXCTL_ERR
value|0x40000000
end_define

begin_comment
comment|/* error summary */
end_comment

begin_define
define|#
directive|define
name|PCN_TXCTL_ADD_FCS
value|0x20000000
end_define

begin_comment
comment|/* add FCS to pkt */
end_comment

begin_define
define|#
directive|define
name|PCN_TXCTL_MORE_LTINT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PCN_TXCTL_ONE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PCN_TXCTL_DEF
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PCN_TXCTL_STP
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PCN_TXCTL_ENP
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PCN_TXCTL_BPE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|PCN_TXCTL_MBO
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|PCN_TXCTL_BUFSZ
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|PCN_OWN_TXDESC
parameter_list|(
name|x
parameter_list|)
value|(((x)->pcn_txctl& PCN_TXCTL_OWN) == 0)
end_define

begin_define
define|#
directive|define
name|PCN_RX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|PCN_TX_LIST_CNT
value|256
end_define

begin_struct
struct|struct
name|pcn_list_data
block|{
name|struct
name|pcn_rx_desc
name|pcn_rx_list
index|[
name|PCN_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|pcn_tx_desc
name|pcn_tx_list
index|[
name|PCN_TX_LIST_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcn_ring_data
block|{
name|struct
name|mbuf
modifier|*
name|pcn_rx_chain
index|[
name|PCN_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|pcn_tx_chain
index|[
name|PCN_TX_LIST_CNT
index|]
decl_stmt|;
name|int
name|pcn_rx_prod
decl_stmt|;
name|int
name|pcn_tx_prod
decl_stmt|;
name|int
name|pcn_tx_cons
decl_stmt|;
name|int
name|pcn_tx_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * AMD PCI vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|PCN_VENDORID
value|0x1022
end_define

begin_comment
comment|/*  * AMD PCnet/PCI device IDs  */
end_comment

begin_define
define|#
directive|define
name|PCN_DEVICEID_PCNET
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCN_DEVICEID_HOME
value|0x2001
end_define

begin_struct
struct|struct
name|pcn_type
block|{
name|u_int16_t
name|pcn_vid
decl_stmt|;
name|u_int16_t
name|pcn_did
decl_stmt|;
specifier|const
name|char
modifier|*
name|pcn_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcn_softc
block|{
name|struct
name|ifnet
modifier|*
name|pcn_ifp
decl_stmt|;
name|bus_space_handle_t
name|pcn_bhandle
decl_stmt|;
name|bus_space_tag_t
name|pcn_btag
decl_stmt|;
name|struct
name|resource
modifier|*
name|pcn_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|pcn_irq
decl_stmt|;
name|void
modifier|*
name|pcn_intrhand
decl_stmt|;
name|device_t
name|pcn_miibus
decl_stmt|;
name|u_int8_t
name|pcn_link
decl_stmt|;
name|int8_t
name|pcn_extphyaddr
decl_stmt|;
name|int8_t
name|pcn_inst_10bt
decl_stmt|;
name|int
name|pcn_if_flags
decl_stmt|;
name|int
name|pcn_type
decl_stmt|;
name|struct
name|pcn_list_data
modifier|*
name|pcn_ldata
decl_stmt|;
name|struct
name|pcn_ring_data
name|pcn_cdata
decl_stmt|;
name|struct
name|callout
name|pcn_stat_callout
decl_stmt|;
name|struct
name|mtx
name|pcn_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCN_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->pcn_mtx)
end_define

begin_define
define|#
directive|define
name|PCN_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->pcn_mtx)
end_define

begin_define
define|#
directive|define
name|PCN_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->pcn_mtx, MA_OWNED)
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
value|bus_space_write_4(sc->pcn_btag, sc->pcn_bhandle, reg, val)
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
value|bus_space_read_4(sc->pcn_btag, sc->pcn_bhandle, reg)
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
value|bus_space_write_2(sc->pcn_btag, sc->pcn_bhandle, reg, val)
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
value|bus_space_read_2(sc->pcn_btag, sc->pcn_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|PCN_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|PCN_RXLEN
value|1536
end_define

begin_define
define|#
directive|define
name|PCN_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|PCN_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers.  */
end_comment

begin_define
define|#
directive|define
name|PCN_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|PCN_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|PCN_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|PCN_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|PCN_PCI_REVID
value|0x08
end_define

begin_define
define|#
directive|define
name|PCN_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|PCN_PCI_CACHELEN
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCN_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|PCN_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|PCN_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|PCN_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|PCN_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|PCN_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|PCN_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|PCN_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|PCN_PCI_MINLAT
value|0x3F
end_define

begin_define
define|#
directive|define
name|PCN_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|PCN_PCI_EEPROM_DATA
value|0x4C
end_define

begin_comment
comment|/* power management registers */
end_comment

begin_define
define|#
directive|define
name|PCN_PCI_CAPID
value|0x50
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCN_PCI_NEXTPTR
value|0x51
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCN_PCI_PWRMGMTCAP
value|0x52
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|PCN_PCI_PWRMGMTCTRL
value|0x54
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|PCN_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCN_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCN_PSTATE_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCN_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCN_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCN_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCN_PME_STATUS
value|0x8000
end_define

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)if_lereg.h	7.2 (Berkeley) %G%  *  * from: $Header: if_lereg.h,v 1.6 92/11/26 02:28:12 torek Exp $  */
end_comment

begin_define
define|#
directive|define
name|LEMTU
value|1518
end_define

begin_define
define|#
directive|define
name|LEMINSIZE
value|60
end_define

begin_comment
comment|/* should be 64 if mode DTCR is set */
end_comment

begin_define
define|#
directive|define
name|LERBUF
value|8
end_define

begin_define
define|#
directive|define
name|LERBUFLOG2
value|3
end_define

begin_define
define|#
directive|define
name|LE_RLEN
value|(LERBUFLOG2<< 13)
end_define

begin_define
define|#
directive|define
name|LETBUF
value|1
end_define

begin_define
define|#
directive|define
name|LETBUFLOG2
value|0
end_define

begin_define
define|#
directive|define
name|LE_TLEN
value|(LETBUFLOG2<< 13)
end_define

begin_comment
comment|/* Local Area Network Controller for Ethernet (LANCE) registers */
end_comment

begin_struct
struct|struct
name|lereg1
block|{
name|u_short
name|ler1_rdp
decl_stmt|;
comment|/* register data port */
name|u_short
name|ler1_rap
decl_stmt|;
comment|/* register address port */
block|}
struct|;
end_struct

begin_comment
comment|/* register addresses */
end_comment

begin_define
define|#
directive|define
name|LE_CSR0
value|0
end_define

begin_comment
comment|/* Control and status register */
end_comment

begin_define
define|#
directive|define
name|LE_CSR1
value|1
end_define

begin_comment
comment|/* low address of init block */
end_comment

begin_define
define|#
directive|define
name|LE_CSR2
value|2
end_define

begin_comment
comment|/* high address of init block */
end_comment

begin_define
define|#
directive|define
name|LE_CSR3
value|3
end_define

begin_comment
comment|/* Bus master and control */
end_comment

begin_comment
comment|/* Control and status register 0 (csr0) */
end_comment

begin_define
define|#
directive|define
name|LE_C0_ERR
value|0x8000
end_define

begin_comment
comment|/* error summary */
end_comment

begin_define
define|#
directive|define
name|LE_C0_BABL
value|0x4000
end_define

begin_comment
comment|/* transmitter timeout error */
end_comment

begin_define
define|#
directive|define
name|LE_C0_CERR
value|0x2000
end_define

begin_comment
comment|/* collision */
end_comment

begin_define
define|#
directive|define
name|LE_C0_MISS
value|0x1000
end_define

begin_comment
comment|/* missed a packet */
end_comment

begin_define
define|#
directive|define
name|LE_C0_MERR
value|0x0800
end_define

begin_comment
comment|/* memory error */
end_comment

begin_define
define|#
directive|define
name|LE_C0_RINT
value|0x0400
end_define

begin_comment
comment|/* receiver interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C0_TINT
value|0x0200
end_define

begin_comment
comment|/* transmitter interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C0_IDON
value|0x0100
end_define

begin_comment
comment|/* initalization done */
end_comment

begin_define
define|#
directive|define
name|LE_C0_INTR
value|0x0080
end_define

begin_comment
comment|/* interrupt condition */
end_comment

begin_define
define|#
directive|define
name|LE_C0_INEA
value|0x0040
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|LE_C0_RXON
value|0x0020
end_define

begin_comment
comment|/* receiver on */
end_comment

begin_define
define|#
directive|define
name|LE_C0_TXON
value|0x0010
end_define

begin_comment
comment|/* transmitter on */
end_comment

begin_define
define|#
directive|define
name|LE_C0_TDMD
value|0x0008
end_define

begin_comment
comment|/* transmit demand */
end_comment

begin_define
define|#
directive|define
name|LE_C0_STOP
value|0x0004
end_define

begin_comment
comment|/* disable all external activity */
end_comment

begin_define
define|#
directive|define
name|LE_C0_STRT
value|0x0002
end_define

begin_comment
comment|/* enable external activity */
end_comment

begin_define
define|#
directive|define
name|LE_C0_INIT
value|0x0001
end_define

begin_comment
comment|/* begin initalization */
end_comment

begin_define
define|#
directive|define
name|LE_C0_BITS
define|\
value|"\20\20ERR\17BABL\16CERR\15MISS\14MERR\13RINT\ \12TINT\11IDON\10INTR\07INEA\06RXON\05TXON\04TDMD\03STOP\02STRT\01INIT"
end_define

begin_comment
comment|/* Control and status register 3 (csr3) */
end_comment

begin_define
define|#
directive|define
name|LE_C3_BSWP
value|0x4
end_define

begin_comment
comment|/* byte swap */
end_comment

begin_define
define|#
directive|define
name|LE_C3_ACON
value|0x2
end_define

begin_comment
comment|/* ALE control, eh? */
end_comment

begin_define
define|#
directive|define
name|LE_C3_BCON
value|0x1
end_define

begin_comment
comment|/* byte control */
end_comment

begin_comment
comment|/*  * Current size is 13,758 bytes with 8 x 1518 receive buffers and  * 1 x 1518 transmit buffer.  */
end_comment

begin_struct
struct|struct
name|lereg2
block|{
comment|/* initialization block */
name|u_short
name|ler2_mode
decl_stmt|;
comment|/* +0x0000: mode */
name|u_char
name|ler2_padr
index|[
literal|6
index|]
decl_stmt|;
comment|/* +0x0002: physical address */
name|u_long
name|ler2_ladrf
index|[
literal|2
index|]
decl_stmt|;
comment|/* +0x0008: logical address filter */
name|u_short
name|ler2_rdra
decl_stmt|;
comment|/* +0x0010: receive descriptor addr */
name|u_short
name|ler2_rlen
decl_stmt|;
comment|/* +0x0012: rda high and ring size */
name|u_short
name|ler2_tdra
decl_stmt|;
comment|/* +0x0014: transmit descriptor addr */
name|u_short
name|ler2_tlen
decl_stmt|;
comment|/* +0x0016: tda high and ring size */
comment|/* receive message descriptors. bits/hadr are byte order dependent. */
struct|struct
name|lermd
block|{
comment|/* +0x0018 */
name|u_short
name|rmd0
decl_stmt|;
comment|/* low address of packet */
name|u_char
name|rmd1_bits
decl_stmt|;
comment|/* descriptor bits */
name|u_char
name|rmd1_hadr
decl_stmt|;
comment|/* high address of packet */
name|short
name|rmd2
decl_stmt|;
comment|/* buffer byte count */
name|u_short
name|rmd3
decl_stmt|;
comment|/* message byte count */
block|}
name|ler2_rmd
index|[
name|LERBUF
index|]
struct|;
comment|/* transmit message descriptors */
struct|struct
name|letmd
block|{
comment|/* +0x0058 */
name|u_short
name|tmd0
decl_stmt|;
comment|/* low address of packet */
name|u_char
name|tmd1_bits
decl_stmt|;
comment|/* descriptor bits */
name|u_char
name|tmd1_hadr
decl_stmt|;
comment|/* high address of packet */
name|short
name|tmd2
decl_stmt|;
comment|/* buffer byte count */
name|u_short
name|tmd3
decl_stmt|;
comment|/* transmit error bits */
block|}
name|ler2_tmd
index|[
name|LETBUF
index|]
struct|;
name|char
name|ler2_rbuf
index|[
name|LERBUF
index|]
index|[
name|LEMTU
index|]
decl_stmt|;
comment|/* +0x0060 */
name|char
name|ler2_tbuf
index|[
name|LETBUF
index|]
index|[
name|LEMTU
index|]
decl_stmt|;
comment|/* +0x2fd0 */
block|}
struct|;
end_struct

begin_comment
comment|/* Initialzation block (mode) */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_PROM
value|0x8000
end_define

begin_comment
comment|/* promiscuous mode */
end_comment

begin_comment
comment|/*			0x7f80		   reserved, must be zero */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_INTL
value|0x0040
end_define

begin_comment
comment|/* internal loopback */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DRTY
value|0x0020
end_define

begin_comment
comment|/* disable retry */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_COLL
value|0x0010
end_define

begin_comment
comment|/* force a collision */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DTCR
value|0x0008
end_define

begin_comment
comment|/* disable transmit CRC */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_LOOP
value|0x0004
end_define

begin_comment
comment|/* loopback mode */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DTX
value|0x0002
end_define

begin_comment
comment|/* disable transmitter */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DRX
value|0x0001
end_define

begin_comment
comment|/* disable receiver */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_NORMAL
value|0
end_define

begin_comment
comment|/* none of the above */
end_comment

begin_comment
comment|/* Receive message descriptor 1 (rmd1_bits) */
end_comment

begin_define
define|#
directive|define
name|LE_R1_OWN
value|0x80
end_define

begin_comment
comment|/* LANCE owns the packet */
end_comment

begin_define
define|#
directive|define
name|LE_R1_ERR
value|0x40
end_define

begin_comment
comment|/* error summary */
end_comment

begin_define
define|#
directive|define
name|LE_R1_FRAM
value|0x20
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|LE_R1_OFLO
value|0x10
end_define

begin_comment
comment|/* overflow error */
end_comment

begin_define
define|#
directive|define
name|LE_R1_CRC
value|0x08
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|LE_R1_BUFF
value|0x04
end_define

begin_comment
comment|/* buffer error */
end_comment

begin_define
define|#
directive|define
name|LE_R1_STP
value|0x02
end_define

begin_comment
comment|/* start of packet */
end_comment

begin_define
define|#
directive|define
name|LE_R1_ENP
value|0x01
end_define

begin_comment
comment|/* end of packet */
end_comment

begin_define
define|#
directive|define
name|LE_R1_BITS
define|\
value|"\20\10OWN\7ERR\6FRAM\5OFLO\4CRC\3BUFF\2STP\1ENP"
end_define

begin_comment
comment|/* Transmit message descriptor 1 (tmd1_bits) */
end_comment

begin_define
define|#
directive|define
name|LE_T1_OWN
value|0x80
end_define

begin_comment
comment|/* LANCE owns the packet */
end_comment

begin_define
define|#
directive|define
name|LE_T1_ERR
value|0x40
end_define

begin_comment
comment|/* error summary */
end_comment

begin_define
define|#
directive|define
name|LE_T1_MORE
value|0x10
end_define

begin_comment
comment|/* multiple collisions */
end_comment

begin_define
define|#
directive|define
name|LE_T1_ONE
value|0x08
end_define

begin_comment
comment|/* single collision */
end_comment

begin_define
define|#
directive|define
name|LE_T1_DEF
value|0x04
end_define

begin_comment
comment|/* defferred transmit */
end_comment

begin_define
define|#
directive|define
name|LE_T1_STP
value|0x02
end_define

begin_comment
comment|/* start of packet */
end_comment

begin_define
define|#
directive|define
name|LE_T1_ENP
value|0x01
end_define

begin_comment
comment|/* end of packet */
end_comment

begin_define
define|#
directive|define
name|LE_T1_BITS
define|\
value|"\20\10OWN\7ERR\6RES\5MORE\4ONE\3DEF\2STP\1ENP"
end_define

begin_comment
comment|/* Transmit message descriptor 3 (tmd3) */
end_comment

begin_define
define|#
directive|define
name|LE_T3_BUFF
value|0x8000
end_define

begin_comment
comment|/* buffer error */
end_comment

begin_define
define|#
directive|define
name|LE_T3_UFLO
value|0x4000
end_define

begin_comment
comment|/* underflow error */
end_comment

begin_define
define|#
directive|define
name|LE_T3_LCOL
value|0x1000
end_define

begin_comment
comment|/* late collision */
end_comment

begin_define
define|#
directive|define
name|LE_T3_LCAR
value|0x0800
end_define

begin_comment
comment|/* loss of carrier */
end_comment

begin_define
define|#
directive|define
name|LE_T3_RTRY
value|0x0400
end_define

begin_comment
comment|/* retry error */
end_comment

begin_define
define|#
directive|define
name|LE_T3_TDR_MASK
value|0x03ff
end_define

begin_comment
comment|/* time domain reflectometry counter */
end_comment

begin_define
define|#
directive|define
name|LE_T3_BITS
define|\
value|"\20\20BUFF\17UFLO\16RES\15LCOL\14LCAR\13RTRY"
end_define

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: am7990reg.h,v 1.4 1997/03/27 21:01:49 veego Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1995 Charles M. Hannum.  All rights reserved.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_lereg.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_define
define|#
directive|define
name|LEBLEN
value|1536
end_define

begin_comment
comment|/* ETHERMTU + header + CRC */
end_comment

begin_define
define|#
directive|define
name|LEMINSIZE
value|60
end_define

begin_comment
comment|/* should be 64 if mode DTCR is set */
end_comment

begin_comment
comment|/*  * Receive message descriptor  */
end_comment

begin_struct
struct|struct
name|lermd
block|{
name|u_int16_t
name|rmd0
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int8_t
name|rmd1_bits
decl_stmt|;
name|u_int8_t
name|rmd1_hadr
decl_stmt|;
else|#
directive|else
name|u_int8_t
name|rmd1_hadr
decl_stmt|;
name|u_int8_t
name|rmd1_bits
decl_stmt|;
endif|#
directive|endif
name|int16_t
name|rmd2
decl_stmt|;
name|u_int16_t
name|rmd3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transmit message descriptor  */
end_comment

begin_struct
struct|struct
name|letmd
block|{
name|u_int16_t
name|tmd0
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int8_t
name|tmd1_bits
decl_stmt|;
name|u_int8_t
name|tmd1_hadr
decl_stmt|;
else|#
directive|else
name|u_int8_t
name|tmd1_hadr
decl_stmt|;
name|u_int8_t
name|tmd1_bits
decl_stmt|;
endif|#
directive|endif
name|int16_t
name|tmd2
decl_stmt|;
name|u_int16_t
name|tmd3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Initialization block  */
end_comment

begin_struct
struct|struct
name|leinit
block|{
name|u_int16_t
name|init_mode
decl_stmt|;
comment|/* +0x0000 */
name|u_int16_t
name|init_padr
index|[
literal|3
index|]
decl_stmt|;
comment|/* +0x0002 */
name|u_int16_t
name|init_ladrf
index|[
literal|4
index|]
decl_stmt|;
comment|/* +0x0008 */
name|u_int16_t
name|init_rdra
decl_stmt|;
comment|/* +0x0010 */
name|u_int16_t
name|init_rlen
decl_stmt|;
comment|/* +0x0012 */
name|u_int16_t
name|init_tdra
decl_stmt|;
comment|/* +0x0014 */
name|u_int16_t
name|init_tlen
decl_stmt|;
comment|/* +0x0016 */
name|int16_t
name|pad0
index|[
literal|4
index|]
decl_stmt|;
comment|/* Pad to 16 shorts */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LE_INITADDR
parameter_list|(
name|sc
parameter_list|)
value|(sc->sc_initaddr)
end_define

begin_define
define|#
directive|define
name|LE_RMDADDR
parameter_list|(
name|sc
parameter_list|,
name|bix
parameter_list|)
value|(sc->sc_rmdaddr + sizeof(struct lermd) * (bix))
end_define

begin_define
define|#
directive|define
name|LE_TMDADDR
parameter_list|(
name|sc
parameter_list|,
name|bix
parameter_list|)
value|(sc->sc_tmdaddr + sizeof(struct letmd) * (bix))
end_define

begin_define
define|#
directive|define
name|LE_RBUFADDR
parameter_list|(
name|sc
parameter_list|,
name|bix
parameter_list|)
value|(sc->sc_rbufaddr[bix])
end_define

begin_define
define|#
directive|define
name|LE_TBUFADDR
parameter_list|(
name|sc
parameter_list|,
name|bix
parameter_list|)
value|(sc->sc_tbufaddr[bix])
end_define

begin_comment
comment|/* register addresses */
end_comment

begin_define
define|#
directive|define
name|LE_CSR0
value|0x0000
end_define

begin_comment
comment|/* Control and status register */
end_comment

begin_define
define|#
directive|define
name|LE_CSR1
value|0x0001
end_define

begin_comment
comment|/* low address of init block */
end_comment

begin_define
define|#
directive|define
name|LE_CSR2
value|0x0002
end_define

begin_comment
comment|/* high address of init block */
end_comment

begin_define
define|#
directive|define
name|LE_CSR3
value|0x0003
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
value|0x0004
end_define

begin_comment
comment|/* byte swap */
end_comment

begin_define
define|#
directive|define
name|LE_C3_ACON
value|0x0002
end_define

begin_comment
comment|/* ALE control, eh? */
end_comment

begin_define
define|#
directive|define
name|LE_C3_BCON
value|0x0001
end_define

begin_comment
comment|/* byte control */
end_comment

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

begin_comment
comment|/* 0x4000 - 0x0080 are not available on LANCE 7990 */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DRCVBC
value|0x4000
end_define

begin_comment
comment|/* disable receive brodcast */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DRCVPA
value|0x2000
end_define

begin_comment
comment|/* disable physical address detection */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DLNKTST
value|0x1000
end_define

begin_comment
comment|/* disable link status */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DAPC
value|0x0800
end_define

begin_comment
comment|/* disable automatic polarity correction */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_MENDECL
value|0x0400
end_define

begin_comment
comment|/* MENDEC loopback mode */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_LRTTSEL
value|0x0200
end_define

begin_comment
comment|/* lower receice threshold / 					   transmit mode selection */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_PSEL1
value|0x0100
end_define

begin_comment
comment|/* port selection bit1 */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_PSEL0
value|0x0080
end_define

begin_comment
comment|/* port selection bit0 */
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
name|LE_XMD2_ONES
value|0xf000
end_define

begin_define
define|#
directive|define
name|LE_T3_BITS
define|\
value|"\20\20BUFF\17UFLO\16RES\15LCOL\14LCAR\13RTRY"
end_define

begin_comment
comment|/*  * PCnet-ISA defines which are not available on LANCE 7990  */
end_comment

begin_comment
comment|/* (ISA) Bus Configuration Registers */
end_comment

begin_define
define|#
directive|define
name|LE_BCR_MSRDA
value|0x0000
end_define

begin_define
define|#
directive|define
name|LE_BCR_MSWRA
value|0x0001
end_define

begin_define
define|#
directive|define
name|LE_BCR_MC
value|0x0002
end_define

begin_define
define|#
directive|define
name|LE_BCR_LED1
value|0x0005
end_define

begin_define
define|#
directive|define
name|LE_BCR_LED2
value|0x0006
end_define

begin_define
define|#
directive|define
name|LE_BCR_LED3
value|0x0007
end_define

begin_comment
comment|/* Bus configurations bits (MC) */
end_comment

begin_define
define|#
directive|define
name|LE_MC_EADISEL
value|0x0008
end_define

begin_comment
comment|/* EADI selection */
end_comment

begin_define
define|#
directive|define
name|LE_MC_AWAKE
value|0x0004
end_define

begin_comment
comment|/* auto-wake */
end_comment

begin_define
define|#
directive|define
name|LE_MC_ASEL
value|0x0002
end_define

begin_comment
comment|/* auto selection */
end_comment

begin_define
define|#
directive|define
name|LE_MC_XMAUSEL
value|0x0001
end_define

begin_comment
comment|/* external MAU selection */
end_comment

begin_comment
comment|/* LED bis (LED[123]) */
end_comment

begin_define
define|#
directive|define
name|LE_LED_LEDOUT
value|0x8000
end_define

begin_define
define|#
directive|define
name|LE_LED_PSE
value|0x0080
end_define

begin_define
define|#
directive|define
name|LE_LED_XMTE
value|0x0010
end_define

begin_define
define|#
directive|define
name|LE_LED_PVPE
value|0x0008
end_define

begin_define
define|#
directive|define
name|LE_LED_PCVE
value|0x0004
end_define

begin_define
define|#
directive|define
name|LE_LED_JABE
value|0x0002
end_define

begin_define
define|#
directive|define
name|LE_LED_COLE
value|0x0001
end_define

end_unit


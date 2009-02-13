begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: am7990reg.h,v 1.11 2005/12/11 12:21:25 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Charles M. Hannum.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_lereg.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_LE_AM7990REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_LE_AM7990REG_H_
end_define

begin_comment
comment|/*  * Receive message descriptor  */
end_comment

begin_struct
struct|struct
name|lermd
block|{
name|uint16_t
name|rmd0
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint8_t
name|rmd1_bits
decl_stmt|;
name|uint8_t
name|rmd1_hadr
decl_stmt|;
else|#
directive|else
name|uint8_t
name|rmd1_hadr
decl_stmt|;
name|uint8_t
name|rmd1_bits
decl_stmt|;
endif|#
directive|endif
name|int16_t
name|rmd2
decl_stmt|;
name|uint16_t
name|rmd3
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Transmit message descriptor  */
end_comment

begin_struct
struct|struct
name|letmd
block|{
name|uint16_t
name|tmd0
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint8_t
name|tmd1_bits
decl_stmt|;
name|uint8_t
name|tmd1_hadr
decl_stmt|;
else|#
directive|else
name|uint8_t
name|tmd1_hadr
decl_stmt|;
name|uint8_t
name|tmd1_bits
decl_stmt|;
endif|#
directive|endif
name|int16_t
name|tmd2
decl_stmt|;
name|uint16_t
name|tmd3
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Initialization block  */
end_comment

begin_struct
struct|struct
name|leinit
block|{
name|uint16_t
name|init_mode
decl_stmt|;
comment|/* +0x0000 */
name|uint16_t
name|init_padr
index|[
literal|3
index|]
decl_stmt|;
comment|/* +0x0002 */
name|uint16_t
name|init_ladrf
index|[
literal|4
index|]
decl_stmt|;
comment|/* +0x0008 */
name|uint16_t
name|init_rdra
decl_stmt|;
comment|/* +0x0010 */
name|uint16_t
name|init_rlen
decl_stmt|;
comment|/* +0x0012 */
name|uint16_t
name|init_tdra
decl_stmt|;
comment|/* +0x0014 */
name|uint16_t
name|init_tlen
decl_stmt|;
comment|/* +0x0016 */
name|int16_t
name|pad0
index|[
literal|4
index|]
decl_stmt|;
comment|/* Pad to 16 shorts. */
block|}
name|__packed
struct|;
end_struct

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
comment|/* deferred transmit */
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
comment|/*  * PCnet-ISA defines which are not available on LANCE 7990.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_LE_AM7990REG_H_ */
end_comment

end_unit


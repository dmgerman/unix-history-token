begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: am79900reg.h,v 1.8 2005/12/11 12:21:25 christos Exp $	*/
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
name|_DEV_LE_AM79900REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_LE_AM79900REG_H_
end_define

begin_comment
comment|/*  * Receive message descriptor  */
end_comment

begin_struct
struct|struct
name|lermd
block|{
name|uint32_t
name|rmd0
decl_stmt|;
name|uint32_t
name|rmd1
decl_stmt|;
name|uint32_t
name|rmd2
decl_stmt|;
name|int32_t
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
name|uint32_t
name|tmd0
decl_stmt|;
name|uint32_t
name|tmd1
decl_stmt|;
name|uint32_t
name|tmd2
decl_stmt|;
name|int32_t
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
name|uint32_t
name|init_mode
decl_stmt|;
comment|/* +0x0000 */
name|uint32_t
name|init_padr
index|[
literal|2
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
name|uint32_t
name|init_rdra
decl_stmt|;
comment|/* +0x0010 */
name|uint32_t
name|init_tdra
decl_stmt|;
comment|/* +0x0014 */
name|int32_t
name|pad
decl_stmt|;
comment|/* Pad to 8 ints. */
block|}
struct|;
end_struct

begin_comment
comment|/* Receive message descriptor 1 (rmd1_bits) */
end_comment

begin_define
define|#
directive|define
name|LE_R1_OWN
value|(1U<< 31)
end_define

begin_comment
comment|/* LANCE owns the packet */
end_comment

begin_define
define|#
directive|define
name|LE_R1_ERR
value|(1U<< 30)
end_define

begin_comment
comment|/* error summary */
end_comment

begin_define
define|#
directive|define
name|LE_R1_FRAM
value|(1U<< 29)
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|LE_R1_OFLO
value|(1U<< 28)
end_define

begin_comment
comment|/* overflow error */
end_comment

begin_define
define|#
directive|define
name|LE_R1_CRC
value|(1U<< 27)
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|LE_R1_BUFF
value|(1U<< 26)
end_define

begin_comment
comment|/* buffer error */
end_comment

begin_define
define|#
directive|define
name|LE_R1_STP
value|(1U<< 25)
end_define

begin_comment
comment|/* start of packet */
end_comment

begin_define
define|#
directive|define
name|LE_R1_ENP
value|(1U<< 24)
end_define

begin_comment
comment|/* end of packet */
end_comment

begin_define
define|#
directive|define
name|LE_R1_ONES
value|(0xfU<< 12)
end_define

begin_comment
comment|/* must be ones */
end_comment

begin_define
define|#
directive|define
name|LE_R1_BCNT_MASK
value|(0xfff)
end_define

begin_comment
comment|/* byte count mask */
end_comment

begin_define
define|#
directive|define
name|LE_R1_BITS
define|\
value|"\20\40OWN\37ERR\36FRAM\35OFLO\34CRC\33BUFF\32STP\31ENP"
end_define

begin_comment
comment|/* Transmit message descriptor 1 (tmd1_bits) */
end_comment

begin_define
define|#
directive|define
name|LE_T1_OWN
value|(1U<< 31)
end_define

begin_comment
comment|/* LANCE owns the packet */
end_comment

begin_define
define|#
directive|define
name|LE_T1_ERR
value|(1U<< 30)
end_define

begin_comment
comment|/* error summary */
end_comment

begin_define
define|#
directive|define
name|LE_T1_ADD_FCS
value|(1U<< 29)
end_define

begin_comment
comment|/* add FCS (PCnet-PCI) */
end_comment

begin_define
define|#
directive|define
name|LE_T1_NO_FCS
value|(1U<< 29)
end_define

begin_comment
comment|/* no FCS (ILACC) */
end_comment

begin_define
define|#
directive|define
name|LE_T1_MORE
value|(1U<< 28)
end_define

begin_comment
comment|/* multiple collisions */
end_comment

begin_define
define|#
directive|define
name|LE_T1_LTINT
value|(1U<< 28)
end_define

begin_comment
comment|/* transmit interrupt (if LTINTEN) */
end_comment

begin_define
define|#
directive|define
name|LE_T1_ONE
value|(1U<< 27)
end_define

begin_comment
comment|/* single collision */
end_comment

begin_define
define|#
directive|define
name|LE_T1_DEF
value|(1U<< 26)
end_define

begin_comment
comment|/* deferred transmit */
end_comment

begin_define
define|#
directive|define
name|LE_T1_STP
value|(1U<< 25)
end_define

begin_comment
comment|/* start of packet */
end_comment

begin_define
define|#
directive|define
name|LE_T1_ENP
value|(1U<< 24)
end_define

begin_comment
comment|/* end of packet */
end_comment

begin_define
define|#
directive|define
name|LE_T1_ONES
value|(0xfU<< 12)
end_define

begin_comment
comment|/* must be ones */
end_comment

begin_define
define|#
directive|define
name|LE_T1_BCNT_MASK
value|(0xfff)
end_define

begin_comment
comment|/* byte count mask */
end_comment

begin_define
define|#
directive|define
name|LE_T1_BITS
define|\
value|"\20\40OWN\37ERR\36RES\35MORE\34ONE\33DEF\32STP\31ENP"
end_define

begin_comment
comment|/* Transmit message descriptor 3 (tmd3) */
end_comment

begin_define
define|#
directive|define
name|LE_T2_BUFF
value|(1U<< 31)
end_define

begin_comment
comment|/* buffer error */
end_comment

begin_define
define|#
directive|define
name|LE_T2_UFLO
value|(1U<< 30)
end_define

begin_comment
comment|/* underflow error */
end_comment

begin_define
define|#
directive|define
name|LE_T2_EXDEF
value|(1U<< 29)
end_define

begin_comment
comment|/* excessive defferral */
end_comment

begin_define
define|#
directive|define
name|LE_T2_LCOL
value|(1U<< 28)
end_define

begin_comment
comment|/* late collision */
end_comment

begin_define
define|#
directive|define
name|LE_T2_LCAR
value|(1U<< 27)
end_define

begin_comment
comment|/* loss of carrier */
end_comment

begin_define
define|#
directive|define
name|LE_T2_RTRY
value|(1U<< 26)
end_define

begin_comment
comment|/* retry error */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|LE_T3_TDR_MASK
value|0x03ff
end_define

begin_comment
comment|/* time domain reflectometry counter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LE_T3_BITS
define|\
value|"\12\40BUFF\37UFLO\35LCOL\34LCAR\33RTRY"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_LE_AM7990REG_H_ */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tp_tpdu.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_TP_TPDU_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_TP_TPDU_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * ARGO TP  *  * $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/tp_tpdu.h,v $  *  * This ghastly set of macros makes it possible to  * refer to tpdu structures without going mad.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_comment
comment|/*  * Definitions for byte order,  * according to byte significance from low address to high.  */
end_comment

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* least-significant byte first (vax) */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* most-significant byte first (IBM, net) */
end_comment

begin_define
define|#
directive|define
name|PDP_ENDIAN
value|3412
end_define

begin_comment
comment|/* LSB first in word, MSW first in long (pdp) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* mc68000, tahoe, most others */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER */
end_comment

begin_comment
comment|/* This much of a tpdu is the same for all types of tpdus  (except  * DT tpdus in class 0; their exceptions are handled by the data  * structure below  */
end_comment

begin_struct
struct|struct
name|tpdu_fixed
block|{
name|u_char
name|_tpduf_li
range|:
literal|8
decl_stmt|,
comment|/* length indicator */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|_tpduf_cdt
range|:
literal|4
decl_stmt|,
comment|/* credit */
name|_tpduf_type
range|:
literal|4
decl_stmt|;
comment|/* type of tpdu (DT, CR, etc.) */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|_tpduf_type
label|:
literal|4
operator|,
comment|/* type of tpdu (DT, CR, etc.) */
name|_tpduf_cdt
operator|:
literal|4
expr_stmt|;
comment|/* credit */
endif|#
directive|endif
name|u_short
name|_tpduf_dref
decl_stmt|;
comment|/* destination ref; not in DT in class 0 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tpdu_li
value|_tpduf._tpduf_li
end_define

begin_define
define|#
directive|define
name|tpdu_type
value|_tpduf._tpduf_type
end_define

begin_define
define|#
directive|define
name|tpdu_cdt
value|_tpduf._tpduf_cdt
end_define

begin_define
define|#
directive|define
name|tpdu_dref
value|_tpduf._tpduf_dref
end_define

begin_struct
struct|struct
name|tp0du
block|{
name|u_char
name|_tp0_li
decl_stmt|,
name|_tp0_cdt_type
decl_stmt|,
comment|/* same as in tpdu_fixed */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|_tp0_eot
range|:
literal|1
decl_stmt|,
comment|/* eot */
name|_tp0_mbz
range|:
literal|7
decl_stmt|,
comment|/* must be zero */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|_tp0_mbz
range|:
literal|7
decl_stmt|,
comment|/* must be zero */
name|_tp0_eot
range|:
literal|1
decl_stmt|,
comment|/* eot */
endif|#
directive|endif
name|_tp0_notused
range|:
literal|8
decl_stmt|;
comment|/* data begins on this octet */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tp0du_eot
value|_tp0_eot
end_define

begin_define
define|#
directive|define
name|tp0du_mbz
value|_tp0_mbz
end_define

begin_comment
comment|/*  * This is used when the extended format seqence numbers are  * being sent and received.  */
end_comment

begin_comment
comment|/* 				 * the seqeot field is an int that overlays the seq 				 * and eot fields, this allows the htonl operation 				 * to be applied to the entire 32 bit quantity, and 				 * simplifies the structure definitions. 				 */
end_comment

begin_union
union|union
name|seq_type
block|{
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|unsigned
name|int
name|st_eot
range|:
literal|1
decl_stmt|,
comment|/* end-of-tsdu */
name|st_seq
range|:
literal|31
decl_stmt|;
comment|/* 31 bit sequence number */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|unsigned
name|int
name|st_seq
range|:
literal|31
decl_stmt|,
comment|/* 31 bit sequence number */
name|st_eot
range|:
literal|1
decl_stmt|;
comment|/* end-of-tsdu */
endif|#
directive|endif
block|}
name|st
struct|;
name|unsigned
name|int
name|s_seqeot
decl_stmt|;
define|#
directive|define
name|s_eot
value|st.st_eot
define|#
directive|define
name|s_seq
value|st.st_seq
block|}
union|;
end_union

begin_comment
comment|/* Then most tpdu types have a portion that is always present but  * differs among the tpdu types :  */
end_comment

begin_union
union|union
name|tpdu_fixed_rest
block|{
struct|struct
block|{
name|u_short
name|_tpdufr_sref
decl_stmt|,
comment|/* source reference */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|_tpdufr_class
range|:
literal|4
decl_stmt|,
comment|/* class [ ISO 8073 13.3.3.e ] */
name|_tpdufr_opt
range|:
literal|4
decl_stmt|,
comment|/* options [ ISO 8073 13.3.3.e ] */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|_tpdufr_opt
range|:
literal|4
decl_stmt|,
comment|/* options [ ISO 8073 13.3.3.e ] */
name|_tpdufr_class
range|:
literal|4
decl_stmt|,
comment|/* class [ ISO 8073 13.3.3.e ] */
endif|#
directive|endif
name|_tpdufr_xx
range|:
literal|8
decl_stmt|;
comment|/* unused */
block|}
name|CRCC
struct|;
define|#
directive|define
name|tpdu_CRli
value|_tpduf._tpduf_li
define|#
directive|define
name|tpdu_CRtype
value|_tpduf._tpduf_type
define|#
directive|define
name|tpdu_CRcdt
value|_tpduf._tpduf_cdt
define|#
directive|define
name|tpdu_CRdref_0
value|_tpduf._tpduf_dref
define|#
directive|define
name|tpdu_CRsref
value|_tpdufr.CRCC._tpdufr_sref
define|#
directive|define
name|tpdu_sref
value|_tpdufr.CRCC._tpdufr_sref
define|#
directive|define
name|tpdu_CRclass
value|_tpdufr.CRCC._tpdufr_class
define|#
directive|define
name|tpdu_CRoptions
value|_tpdufr.CRCC._tpdufr_opt
define|#
directive|define
name|tpdu_CCli
value|_tpduf._tpduf_li
define|#
directive|define
name|tpdu_CCtype
value|_tpduf._tpduf_type
define|#
directive|define
name|tpdu_CCcdt
value|_tpduf._tpduf_cdt
define|#
directive|define
name|tpdu_CCdref
value|_tpduf._tpduf_dref
define|#
directive|define
name|tpdu_CCsref
value|_tpdufr.CRCC._tpdufr_sref
define|#
directive|define
name|tpdu_CCclass
value|_tpdufr.CRCC._tpdufr_class
define|#
directive|define
name|tpdu_CCoptions
value|_tpdufr.CRCC._tpdufr_opt
comment|/* OPTIONS and ADDL OPTIONS bits */
define|#
directive|define
name|TPO_USE_EFC
value|0x1
define|#
directive|define
name|TPO_XTD_FMT
value|0x2
define|#
directive|define
name|TPAO_USE_TXPD
value|0x1
define|#
directive|define
name|TPAO_NO_CSUM
value|0x2
define|#
directive|define
name|TPAO_USE_RCC
value|0x4
define|#
directive|define
name|TPAO_USE_NXPD
value|0x8
struct|struct
block|{
name|unsigned
name|short
name|_tpdufr_sref
decl_stmt|;
comment|/* source reference */
name|unsigned
name|char
name|_tpdufr_reason
decl_stmt|;
comment|/* [ ISO 8073 13.5.3.d ] */
block|}
name|DR
struct|;
define|#
directive|define
name|tpdu_DRli
value|_tpduf._tpduf_li
define|#
directive|define
name|tpdu_DRtype
value|_tpduf._tpduf_type
define|#
directive|define
name|tpdu_DRdref
value|_tpduf._tpduf_dref
define|#
directive|define
name|tpdu_DRsref
value|_tpdufr.DR._tpdufr_sref
define|#
directive|define
name|tpdu_DRreason
value|_tpdufr.DR._tpdufr_reason
name|unsigned
name|short
name|_tpdufr_sref
decl_stmt|;
comment|/* source reference */
define|#
directive|define
name|tpdu_DCli
value|_tpduf._tpduf_li
define|#
directive|define
name|tpdu_DCtype
value|_tpduf._tpduf_type
define|#
directive|define
name|tpdu_DCdref
value|_tpduf._tpduf_dref
define|#
directive|define
name|tpdu_DCsref
value|_tpdufr._tpdufr_sref
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|unsigned
name|char
name|_tpdufr_eot
range|:
literal|1
decl_stmt|,
comment|/* end-of-tsdu */
name|_tpdufr_seq
range|:
literal|7
decl_stmt|;
comment|/* 7 bit sequence number */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|unsigned
name|char
name|_tpdufr_seq
range|:
literal|7
decl_stmt|,
comment|/* 7 bit sequence number */
name|_tpdufr_eot
range|:
literal|1
decl_stmt|;
comment|/* end-of-tsdu */
endif|#
directive|endif
block|}
name|SEQEOT
struct|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|unsigned
name|int
name|_tpdufr_Xeot
range|:
literal|1
decl_stmt|,
comment|/* end-of-tsdu */
name|_tpdufr_Xseq
range|:
literal|31
decl_stmt|;
comment|/* 31 bit sequence number */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|unsigned
name|int
name|_tpdufr_Xseq
range|:
literal|31
decl_stmt|,
comment|/* 31 bit sequence number */
name|_tpdufr_Xeot
range|:
literal|1
decl_stmt|;
comment|/* end-of-tsdu */
endif|#
directive|endif
block|}
name|SEQEOT31
struct|;
name|unsigned
name|int
name|_tpdufr_Xseqeot
decl_stmt|;
define|#
directive|define
name|tpdu_seqeotX
value|_tpdufr._tpdufr_Xseqeot
define|#
directive|define
name|tpdu_DTli
value|_tpduf._tpduf_li
define|#
directive|define
name|tpdu_DTtype
value|_tpduf._tpduf_type
define|#
directive|define
name|tpdu_DTdref
value|_tpduf._tpduf_dref
define|#
directive|define
name|tpdu_DTseq
value|_tpdufr.SEQEOT._tpdufr_seq
define|#
directive|define
name|tpdu_DTeot
value|_tpdufr.SEQEOT._tpdufr_eot
define|#
directive|define
name|tpdu_DTseqX
value|_tpdufr.SEQEOT31._tpdufr_Xseq
define|#
directive|define
name|tpdu_DTeotX
value|_tpdufr.SEQEOT31._tpdufr_Xeot
define|#
directive|define
name|tpdu_XPDli
value|_tpduf._tpduf_li
define|#
directive|define
name|tpdu_XPDtype
value|_tpduf._tpduf_type
define|#
directive|define
name|tpdu_XPDdref
value|_tpduf._tpduf_dref
define|#
directive|define
name|tpdu_XPDseq
value|_tpdufr.SEQEOT._tpdufr_seq
define|#
directive|define
name|tpdu_XPDeot
value|_tpdufr.SEQEOT._tpdufr_eot
define|#
directive|define
name|tpdu_XPDseqX
value|_tpdufr.SEQEOT31._tpdufr_Xseq
define|#
directive|define
name|tpdu_XPDeotX
value|_tpdufr.SEQEOT31._tpdufr_Xeot
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|unsigned
name|_tpdufr_yrseq0
range|:
literal|1
decl_stmt|,
comment|/* always zero */
name|_tpdufr_yrseq
range|:
literal|31
decl_stmt|;
comment|/* [ ISO 8073 13.9.3.d ] */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|unsigned
name|_tpdufr_yrseq
range|:
literal|31
decl_stmt|,
comment|/* [ ISO 8073 13.9.3.d ] */
name|_tpdufr_yrseq0
range|:
literal|1
decl_stmt|;
comment|/* always zero */
endif|#
directive|endif
name|unsigned
name|short
name|_tpdufr_cdt
decl_stmt|;
comment|/* [ ISO 8073 13.9.3.b ] */
block|}
name|AK31
struct|;
define|#
directive|define
name|tpdu_AKli
value|_tpduf._tpduf_li
define|#
directive|define
name|tpdu_AKtype
value|_tpduf._tpduf_type
define|#
directive|define
name|tpdu_AKdref
value|_tpduf._tpduf_dref
define|#
directive|define
name|tpdu_AKseq
value|_tpdufr.SEQEOT._tpdufr_seq
define|#
directive|define
name|tpdu_AKseqX
value|_tpdufr.AK31._tpdufr_yrseq
comment|/* location of cdt depends on size of seq. numbers */
define|#
directive|define
name|tpdu_AKcdt
value|_tpduf._tpduf_cdt
define|#
directive|define
name|tpdu_AKcdtX
value|_tpdufr.AK31._tpdufr_cdt
define|#
directive|define
name|tpdu_XAKli
value|_tpduf._tpduf_li
define|#
directive|define
name|tpdu_XAKtype
value|_tpduf._tpduf_type
define|#
directive|define
name|tpdu_XAKdref
value|_tpduf._tpduf_dref
define|#
directive|define
name|tpdu_XAKseq
value|_tpdufr.SEQEOT._tpdufr_seq
define|#
directive|define
name|tpdu_XAKseqX
value|_tpdufr.SEQEOT31._tpdufr_Xseq
name|unsigned
name|char
name|_tpdu_ERreason
decl_stmt|;
comment|/* [ ISO 8073 13.12.3.c ] */
define|#
directive|define
name|tpdu_ERli
value|_tpduf._tpduf_li
define|#
directive|define
name|tpdu_ERtype
value|_tpduf._tpduf_type
define|#
directive|define
name|tpdu_ERdref
value|_tpduf._tpduf_dref
define|#
directive|define
name|tpdu_ERreason
value|_tpdufr._tpdu_ERreason
block|}
union|;
end_union

begin_struct
struct|struct
name|tpdu
block|{
name|struct
name|tpdu_fixed
name|_tpduf
decl_stmt|;
name|union
name|tpdu_fixed_rest
name|_tpdufr
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit


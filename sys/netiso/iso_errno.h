begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)iso_errno.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_ISO_ERRNO_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_ISO_ERRNO_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_define
define|#
directive|define
name|ISO_ERROR_MASK
value|0x8000
end_define

begin_define
define|#
directive|define
name|BSD_ERROR_MASK
value|0x0000
end_define

begin_define
define|#
directive|define
name|TP_ERROR_MASK
value|0x8800
end_define

begin_comment
comment|/* transport layer */
end_comment

begin_define
define|#
directive|define
name|CONL_ERROR_MASK
value|0x8400
end_define

begin_comment
comment|/* co network layer */
end_comment

begin_define
define|#
directive|define
name|CLNL_ERROR_MASK
value|0x8200
end_define

begin_comment
comment|/* cl network layer */
end_comment

begin_define
define|#
directive|define
name|TP_ERROR_SNDC
value|0x10000
end_define

begin_comment
comment|/* kludge to force DC's on certain errors */
end_comment

begin_define
define|#
directive|define
name|E_CO_NOERROR
value|(CONL_ERROR_MASK | 0x0)
end_define

begin_comment
comment|/* no add'l info */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                          Transport Layer                                   */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|E_TP_DR_NO_REAS
value|(TP_ERROR_MASK | 0x0)
end_define

begin_comment
comment|/* dr reason not specified*/
end_comment

begin_define
define|#
directive|define
name|E_TP_CONGEST
value|(TP_ERROR_MASK | 0x1)
end_define

begin_comment
comment|/* dr reason congestion */
end_comment

begin_define
define|#
directive|define
name|E_TP_NO_SESSION
value|(TP_ERROR_MASK | 0x2)
end_define

begin_comment
comment|/* dr reason no sess ent */
end_comment

begin_define
define|#
directive|define
name|E_TP_ADDR_UNK
value|(TP_ERROR_MASK | 0x3)
end_define

begin_comment
comment|/* dr reason addr unknown */
end_comment

begin_define
define|#
directive|define
name|E_TP_ER_NO_REAS
value|(TP_ERROR_MASK | 0x40)
end_define

begin_comment
comment|/* er reas not specified */
end_comment

begin_define
define|#
directive|define
name|E_TP_INV_PCODE
value|(TP_ERROR_MASK | 0x41)
end_define

begin_comment
comment|/* er reas invalid parm code */
end_comment

begin_define
define|#
directive|define
name|E_TP_INV_TPDU
value|(TP_ERROR_MASK | 0x42)
end_define

begin_comment
comment|/* er reas invalid tpdu type */
end_comment

begin_define
define|#
directive|define
name|E_TP_INV_PVAL
value|(TP_ERROR_MASK | 0x43)
end_define

begin_comment
comment|/* er reas invalid parm value*/
end_comment

begin_define
define|#
directive|define
name|E_TP_NORMAL_DISC
value|(TP_ERROR_MASK | 0x80)
end_define

begin_comment
comment|/* dr reas normal disc */
end_comment

begin_define
define|#
directive|define
name|E_TP_CONGEST_2
value|(TP_ERROR_MASK | 0x81)
end_define

begin_comment
comment|/* dr reason congestion */
end_comment

begin_define
define|#
directive|define
name|E_TP_NEGOT_FAILED
value|(TP_ERROR_MASK | 0x82)
end_define

begin_comment
comment|/* dr negotiation failed */
end_comment

begin_define
define|#
directive|define
name|E_TP_DUPL_SRCREF
value|(TP_ERROR_MASK | 0x83)
end_define

begin_comment
comment|/* dr duplicate src ref */
end_comment

begin_define
define|#
directive|define
name|E_TP_MISM_REFS
value|(TP_ERROR_MASK | 0x84)
end_define

begin_comment
comment|/* dr mismatched references*/
end_comment

begin_define
define|#
directive|define
name|E_TP_PROTO_ERR
value|(TP_ERROR_MASK | 0x85)
end_define

begin_comment
comment|/* dr protocol error*/
end_comment

begin_comment
comment|/* 0x86 not used */
end_comment

begin_define
define|#
directive|define
name|E_TP_REF_OVERFLOW
value|(TP_ERROR_MASK | 0x87)
end_define

begin_comment
comment|/* dr reference overflow */
end_comment

begin_define
define|#
directive|define
name|E_TP_NO_CR_ON_NC
value|(TP_ERROR_MASK | 0x88)
end_define

begin_comment
comment|/* dr cr refused on this nc */
end_comment

begin_comment
comment|/* 0x89 not used */
end_comment

begin_define
define|#
directive|define
name|E_TP_LENGTH_INVAL
value|(TP_ERROR_MASK | 0x8a)
end_define

begin_comment
comment|/* dr inval length in hdr*/
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                   Connection Less Network Layer                            */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* #define E_CLNL_???	(CLNL_ERROR_MASK | 0x1)	  explanation */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*               Connection Oriented Network Layer                            */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/* see p. 149 of ISO 8208 */
end_comment

begin_define
define|#
directive|define
name|E_CO_NOERROR
value|(CONL_ERROR_MASK | 0x0)
end_define

begin_comment
comment|/* no add'l info */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PS
value|(CONL_ERROR_MASK | 0x1)
end_define

begin_comment
comment|/* invalid p(s) */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PR
value|(CONL_ERROR_MASK | 0x2)
end_define

begin_comment
comment|/* invalid p(r) */
end_comment

begin_comment
comment|/* dot dot dot */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_TYPE
value|(CONL_ERROR_MASK | 0x10)
end_define

begin_comment
comment|/* packet type invalid*/
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_R1
value|(CONL_ERROR_MASK | 0x11)
end_define

begin_comment
comment|/* for state r1 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_R2
value|(CONL_ERROR_MASK | 0x12)
end_define

begin_comment
comment|/* for state r2 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_R3
value|(CONL_ERROR_MASK | 0x13)
end_define

begin_comment
comment|/* for state r3 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_P1
value|(CONL_ERROR_MASK | 0x14)
end_define

begin_comment
comment|/* for state p1 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_P2
value|(CONL_ERROR_MASK | 0x15)
end_define

begin_comment
comment|/* for state p2 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_P3
value|(CONL_ERROR_MASK | 0x16)
end_define

begin_comment
comment|/* for state p3 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_P4
value|(CONL_ERROR_MASK | 0x17)
end_define

begin_comment
comment|/* for state p4 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_P5
value|(CONL_ERROR_MASK | 0x18)
end_define

begin_comment
comment|/* for state p5 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_P6
value|(CONL_ERROR_MASK | 0x19)
end_define

begin_comment
comment|/* for state p6 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_P7
value|(CONL_ERROR_MASK | 0x1a)
end_define

begin_comment
comment|/* for state p7 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_D1
value|(CONL_ERROR_MASK | 0x1b)
end_define

begin_comment
comment|/* for state d1 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_D2
value|(CONL_ERROR_MASK | 0x1c)
end_define

begin_comment
comment|/* for state d2 */
end_comment

begin_define
define|#
directive|define
name|E_CO_INV_PKT_D3
value|(CONL_ERROR_MASK | 0x1d)
end_define

begin_comment
comment|/* for state d3 */
end_comment

begin_comment
comment|/* dot dot dot */
end_comment

begin_define
define|#
directive|define
name|E_CO_PKT_NOT_ALWD
value|(CONL_ERROR_MASK | 0x20)
end_define

begin_comment
comment|/* packet not allowed */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_UNIDENT
value|(CONL_ERROR_MASK | 0x21)
end_define

begin_comment
comment|/* unidentifiable pkt */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_ONEWAY
value|(CONL_ERROR_MASK | 0x22)
end_define

begin_comment
comment|/* call on 1-way lc */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_PVC
value|(CONL_ERROR_MASK | 0x23)
end_define

begin_comment
comment|/* inv pkt type on a pvc */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_UNASSLC
value|(CONL_ERROR_MASK | 0x24)
end_define

begin_comment
comment|/* pkt on unassigned lc */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_REJECT
value|(CONL_ERROR_MASK | 0x25)
end_define

begin_comment
comment|/* REJ not subscribed to*/
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_SHORT
value|(CONL_ERROR_MASK | 0x26)
end_define

begin_comment
comment|/* pkt too short */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_LONG
value|(CONL_ERROR_MASK | 0x27)
end_define

begin_comment
comment|/* pkt too long */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_INVGFI
value|(CONL_ERROR_MASK | 0x28)
end_define

begin_comment
comment|/* inv gen format id */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_NZLCI
value|(CONL_ERROR_MASK | 0x29)
end_define

begin_comment
unit|\
comment|/* restart or reg pkt with nonzero logical channel identifier */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_FACIL
value|(CONL_ERROR_MASK | 0x2a)
end_define

begin_comment
unit|\
comment|/* pkt type not compat with facility */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_UINTCON
value|(CONL_ERROR_MASK | 0x2b)
end_define

begin_comment
comment|/* unauthor intrpt conf */
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_UINTRPT
value|(CONL_ERROR_MASK | 0x2c)
end_define

begin_comment
comment|/* unauthorized intrpt	*/
end_comment

begin_define
define|#
directive|define
name|E_CO_PNA_UREJECT
value|(CONL_ERROR_MASK | 0x2d)
end_define

begin_comment
comment|/* unauthorized reject  */
end_comment

begin_define
define|#
directive|define
name|E_CO_TMR_EXP
value|(CONL_ERROR_MASK | 0x30)
end_define

begin_comment
comment|/* timer expired */
end_comment

begin_define
define|#
directive|define
name|E_CO_TMR_CALR
value|(CONL_ERROR_MASK | 0x31)
end_define

begin_comment
comment|/* inc. call or call req */
end_comment

begin_define
define|#
directive|define
name|E_CO_TMR_CLRI
value|(CONL_ERROR_MASK | 0x32)
end_define

begin_comment
comment|/* clear indication */
end_comment

begin_define
define|#
directive|define
name|E_CO_TMR_RSTI
value|(CONL_ERROR_MASK | 0x33)
end_define

begin_comment
comment|/* reset indication */
end_comment

begin_define
define|#
directive|define
name|E_CO_TMR_RRTI
value|(CONL_ERROR_MASK | 0x34)
end_define

begin_comment
comment|/* restart indication */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_PROB
value|(CONL_ERROR_MASK | 0x40)
end_define

begin_comment
unit|\
comment|/* call setup, clear, or registration problem  */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_CODE
value|(CONL_ERROR_MASK | 0x41)
end_define

begin_comment
comment|/* code not allowed */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_PARM
value|(CONL_ERROR_MASK | 0x42)
end_define

begin_comment
comment|/* parameter not allowed */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_ICDA
value|(CONL_ERROR_MASK | 0x43)
end_define

begin_comment
comment|/* invalid called addr */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_ICGA
value|(CONL_ERROR_MASK | 0x44)
end_define

begin_comment
comment|/* invalid calling addr */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_ILEN
value|(CONL_ERROR_MASK | 0x45)
end_define

begin_comment
comment|/* invalid facil length */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_IBAR
value|(CONL_ERROR_MASK | 0x46)
end_define

begin_comment
comment|/* incoming call barred */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_NOLC
value|(CONL_ERROR_MASK | 0x47)
end_define

begin_comment
comment|/* no logical chan avail*/
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_COLL
value|(CONL_ERROR_MASK | 0x48)
end_define

begin_comment
comment|/* call collision */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_DUPF
value|(CONL_ERROR_MASK | 0x49)
end_define

begin_comment
comment|/* dupl facil requested */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_NZAL
value|(CONL_ERROR_MASK | 0x4a)
end_define

begin_comment
comment|/* non-zero addr length */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_NZFL
value|(CONL_ERROR_MASK | 0x4b)
end_define

begin_comment
comment|/* non-zero facil length */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_EFNP
value|(CONL_ERROR_MASK | 0x4c)
end_define

begin_comment
unit|\
comment|/* expected facil not provided */
end_comment

begin_define
define|#
directive|define
name|E_CO_REG_ICCITT
value|(CONL_ERROR_MASK | 0x4d)
end_define

begin_comment
unit|\
comment|/* invalid CCITT-specified  DTE facil */
end_comment

begin_define
define|#
directive|define
name|E_CO_MISC
value|(CONL_ERROR_MASK | 0x50)
end_define

begin_comment
comment|/* miscellaneous */
end_comment

begin_define
define|#
directive|define
name|E_CO_MISC_CAUSE
value|(CONL_ERROR_MASK | 0x51)
end_define

begin_comment
comment|/* improper cause code */
end_comment

begin_define
define|#
directive|define
name|E_CO_MISC_ALIGN
value|(CONL_ERROR_MASK | 0x52)
end_define

begin_comment
comment|/* not octet-aligned */
end_comment

begin_define
define|#
directive|define
name|E_CO_MISC_IQBS
value|(CONL_ERROR_MASK | 0x53)
end_define

begin_comment
unit|\
comment|/* inconsistent Q bit settings */
end_comment

begin_define
define|#
directive|define
name|E_CO_INTL
value|(CONL_ERROR_MASK | 0x70)
end_define

begin_comment
comment|/* international problem */
end_comment

begin_define
define|#
directive|define
name|E_CO_IREMNWK
value|(CONL_ERROR_MASK | 0x71)
end_define

begin_comment
comment|/* remote network problem */
end_comment

begin_define
define|#
directive|define
name|E_CO_INPROTO
value|(CONL_ERROR_MASK | 0x72)
end_define

begin_comment
comment|/* int'l protocol problem */
end_comment

begin_define
define|#
directive|define
name|E_CO_ILINKDWN
value|(CONL_ERROR_MASK | 0x73)
end_define

begin_comment
comment|/* int'l link down */
end_comment

begin_define
define|#
directive|define
name|E_CO_ILINKBSY
value|(CONL_ERROR_MASK | 0x74)
end_define

begin_comment
comment|/* int'l link busy */
end_comment

begin_define
define|#
directive|define
name|E_CO_IXNETFAC
value|(CONL_ERROR_MASK | 0x75)
end_define

begin_comment
comment|/* transit netwk facil */
end_comment

begin_define
define|#
directive|define
name|E_CO_IRNETFAC
value|(CONL_ERROR_MASK | 0x76)
end_define

begin_comment
comment|/* remote netwk facil */
end_comment

begin_define
define|#
directive|define
name|E_CO_IROUTING
value|(CONL_ERROR_MASK | 0x77)
end_define

begin_comment
comment|/* int'l routing prob */
end_comment

begin_define
define|#
directive|define
name|E_CO_ITMPRTG
value|(CONL_ERROR_MASK | 0x78)
end_define

begin_comment
comment|/* temporary routing prob */
end_comment

begin_define
define|#
directive|define
name|E_CO_IUNKDNIC
value|(CONL_ERROR_MASK | 0x79)
end_define

begin_comment
comment|/* unknown called DNIC */
end_comment

begin_define
define|#
directive|define
name|E_CO_IMAINT
value|(CONL_ERROR_MASK | 0x7a)
end_define

begin_comment
comment|/* maintenance action */
end_comment

begin_define
define|#
directive|define
name|E_CO_TIMO
value|(CONL_ERROR_MASK | 0x90)
end_define

begin_comment
unit|\
comment|/* timer expired or retransmission count surpassed */
end_comment

begin_define
define|#
directive|define
name|E_CO_TIM_INTRP
value|(CONL_ERROR_MASK | 0x91)
end_define

begin_comment
comment|/* for interrupt */
end_comment

begin_define
define|#
directive|define
name|E_CO_TIM_DATA
value|(CONL_ERROR_MASK | 0x92)
end_define

begin_comment
comment|/*  for data */
end_comment

begin_define
define|#
directive|define
name|E_CO_TIM_REJ
value|(CONL_ERROR_MASK | 0x93)
end_define

begin_comment
comment|/*  for reject */
end_comment

begin_define
define|#
directive|define
name|E_CO_DTE_SPEC
value|(CONL_ERROR_MASK | 0xa0)
end_define

begin_comment
comment|/* DTE-specific */
end_comment

begin_define
define|#
directive|define
name|E_CO_DTE_OK
value|(CONL_ERROR_MASK | 0xa1)
end_define

begin_comment
comment|/* DTE operational */
end_comment

begin_define
define|#
directive|define
name|E_CO_DTE_NOK
value|(CONL_ERROR_MASK | 0xa2)
end_define

begin_comment
comment|/* DTE not operational */
end_comment

begin_define
define|#
directive|define
name|E_CO_DTE_RSRC
value|(CONL_ERROR_MASK | 0xa3)
end_define

begin_comment
comment|/* DTE resource constraint*/
end_comment

begin_define
define|#
directive|define
name|E_CO_DTE_FSLCT
value|(CONL_ERROR_MASK | 0xa4)
end_define

begin_comment
comment|/* fast select not subsc */
end_comment

begin_define
define|#
directive|define
name|E_CO_DTE_PFPKT
value|(CONL_ERROR_MASK | 0xa5)
end_define

begin_comment
comment|/* partially full pkt */
end_comment

begin_define
define|#
directive|define
name|E_CO_DTE_DBIT
value|(CONL_ERROR_MASK | 0xa6)
end_define

begin_comment
comment|/* D-bit proc not supp */
end_comment

begin_define
define|#
directive|define
name|E_CO_DTE_RCCON
value|(CONL_ERROR_MASK | 0xa7)
end_define

begin_comment
comment|/* reg/canell confirmed */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_NSP
value|(CONL_ERROR_MASK | 0xe0)
end_define

begin_comment
comment|/* OSI net svc problem */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_DISCT
value|(CONL_ERROR_MASK | 0xe1)
end_define

begin_comment
comment|/* disconnect transient */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_DISCP
value|(CONL_ERROR_MASK | 0xe2)
end_define

begin_comment
comment|/* disconnect permanent */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_REJT
value|(CONL_ERROR_MASK | 0xe3)
end_define

begin_comment
comment|/* reject transient */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_REJP
value|(CONL_ERROR_MASK | 0xe4)
end_define

begin_comment
comment|/* reject permanent */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_QOST
value|(CONL_ERROR_MASK | 0xe5)
end_define

begin_comment
comment|/* reject QOS transient */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_QOSP
value|(CONL_ERROR_MASK | 0xe6)
end_define

begin_comment
comment|/* reject QOS permanent */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_NSAPT
value|(CONL_ERROR_MASK | 0xe7)
end_define

begin_comment
comment|/* NSAP unreach transient */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_NSAPP
value|(CONL_ERROR_MASK | 0xe8)
end_define

begin_comment
comment|/* NSAP unreach permanent */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_RESET
value|(CONL_ERROR_MASK | 0xe9)
end_define

begin_comment
comment|/* reset no reason */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_CONGEST
value|(CONL_ERROR_MASK | 0xea)
end_define

begin_comment
comment|/* reset congestion */
end_comment

begin_define
define|#
directive|define
name|E_CO_OSI_UNSAP
value|(CONL_ERROR_MASK | 0xeb)
end_define

begin_comment
comment|/* unknown NSAP permanent */
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_INIT
value|(CONL_ERROR_MASK | 0xf0)
end_define

begin_comment
comment|/* higher level initiated*/
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_DISCN
value|(CONL_ERROR_MASK | 0xf1)
end_define

begin_comment
comment|/* disconnect normal */
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_DISCA
value|(CONL_ERROR_MASK | 0xf2)
end_define

begin_comment
comment|/* disconnect abnormal */
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_DISCI
value|(CONL_ERROR_MASK | 0xf3)
end_define

begin_comment
comment|/* disconnect incompatible*/
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_REJT
value|(CONL_ERROR_MASK | 0xf4)
end_define

begin_comment
comment|/* reject transient */
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_REJP
value|(CONL_ERROR_MASK | 0xf5)
end_define

begin_comment
comment|/* reject permanent */
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_QOST
value|(CONL_ERROR_MASK | 0xf6)
end_define

begin_comment
comment|/* reject QOS transient */
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_QOSP
value|(CONL_ERROR_MASK | 0xf7)
end_define

begin_comment
comment|/* reject QOS permanent */
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_REJI
value|(CONL_ERROR_MASK | 0xf8)
end_define

begin_comment
comment|/* reject incompatible  */
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_PROTOID
value|(CONL_ERROR_MASK | 0xf9)
end_define

begin_comment
comment|/* unrecog proto id  */
end_comment

begin_define
define|#
directive|define
name|E_CO_HLI_RESYNC
value|(CONL_ERROR_MASK | 0xfa)
end_define

begin_comment
comment|/* reset - user resync */
end_comment

begin_comment
comment|/* Cause on 8208 CLEAR field */
end_comment

begin_define
define|#
directive|define
name|E_CO_NUMBERBUSY
value|(CONL_ERROR_MASK | 0x101)
end_define

begin_comment
comment|/* Number busy */
end_comment

begin_define
define|#
directive|define
name|E_CO_INVFACREQ
value|(CONL_ERROR_MASK | 0x103)
end_define

begin_comment
comment|/* invalid facil req */
end_comment

begin_define
define|#
directive|define
name|E_CO_NETCONGEST
value|(CONL_ERROR_MASK | 0x105)
end_define

begin_comment
comment|/* Network congestion */
end_comment

begin_define
define|#
directive|define
name|E_CO_OUTOFORDER
value|(CONL_ERROR_MASK | 0x109)
end_define

begin_comment
comment|/* Out of order */
end_comment

begin_define
define|#
directive|define
name|E_CO_ACCESSBAR
value|(CONL_ERROR_MASK | 0x10b)
end_define

begin_comment
comment|/* access barred */
end_comment

begin_define
define|#
directive|define
name|E_CO_NOTOBTAIN
value|(CONL_ERROR_MASK | 0x10d)
end_define

begin_comment
comment|/* not obtainable */
end_comment

begin_define
define|#
directive|define
name|E_CO_REMPROCERR
value|(CONL_ERROR_MASK | 0x111)
end_define

begin_comment
comment|/* Remote procedure err */
end_comment

begin_define
define|#
directive|define
name|E_CO_LOCPROCERR
value|(CONL_ERROR_MASK | 0x113)
end_define

begin_comment
comment|/* Local procedure err */
end_comment

begin_define
define|#
directive|define
name|E_CO_RPOAOOO
value|(CONL_ERROR_MASK | 0x115)
end_define

begin_comment
comment|/* RPOA out of order */
end_comment

begin_define
define|#
directive|define
name|E_CO_NOREVCHG
value|(CONL_ERROR_MASK | 0x119)
end_define

begin_comment
comment|/* Revs chg not accepted*/
end_comment

begin_define
define|#
directive|define
name|E_CO_INCOMPAT
value|(CONL_ERROR_MASK | 0x121)
end_define

begin_comment
comment|/* Incompatible dest */
end_comment

begin_define
define|#
directive|define
name|E_CO_NOFASTSEL
value|(CONL_ERROR_MASK | 0x129)
end_define

begin_comment
comment|/* Fast select accpt not subscribed */
end_comment

begin_define
define|#
directive|define
name|E_CO_NOSHIP
value|(CONL_ERROR_MASK | 0x139)
end_define

begin_comment
comment|/* ship absent */
end_comment

begin_define
define|#
directive|define
name|E_CO_GWPROCERR
value|(CONL_ERROR_MASK | 0x1c1)
end_define

begin_comment
comment|/* Gateway-detected err*/
end_comment

begin_define
define|#
directive|define
name|E_CO_GWCONGEST
value|(CONL_ERROR_MASK | 0x1c3)
end_define

begin_comment
comment|/* Gateway congestion*/
end_comment

begin_comment
comment|/* ARGO only */
end_comment

begin_define
define|#
directive|define
name|E_CO_QFULL
value|(CONL_ERROR_MASK | 0x100)
end_define

begin_comment
comment|/* dropped packet - queue full*/
end_comment

begin_define
define|#
directive|define
name|E_CO_AIWP
value|(CONL_ERROR_MASK | 0x102)
end_define

begin_comment
comment|/* addr incompat w/proto */
end_comment

begin_define
define|#
directive|define
name|E_CO_CHAN
value|(CONL_ERROR_MASK | 0x104)
end_define

begin_comment
comment|/* bad channel number */
end_comment

begin_comment
comment|/* ARGO only; driver specific */
end_comment

begin_define
define|#
directive|define
name|E_CO_NORESOURCES
value|(CONL_ERROR_MASK | 0x1b0)
end_define

begin_comment
comment|/* eicon clogged  */
end_comment

begin_define
define|#
directive|define
name|E_CO_PDNDOWN
value|(CONL_ERROR_MASK | 0x1b1)
end_define

begin_comment
comment|/* physical net down */
end_comment

begin_define
define|#
directive|define
name|E_CO_DRVRCLRESET
value|(CONL_ERROR_MASK | 0x1b2)
end_define

begin_comment
comment|/* driver clear/reset */
end_comment

begin_define
define|#
directive|define
name|E_CO_PDNCLRESET
value|(CONL_ERROR_MASK | 0x1b3)
end_define

begin_comment
comment|/* PDN clear/reset */
end_comment

begin_define
define|#
directive|define
name|E_CO_DTECLRESET
value|(CONL_ERROR_MASK | 0x1b4)
end_define

begin_comment
comment|/* board clear/reset */
end_comment

begin_define
define|#
directive|define
name|E_CO_UNKCLRESET
value|(CONL_ERROR_MASK | 0x1b5)
end_define

begin_comment
comment|/* unexpected clr/rst */
end_comment

begin_define
define|#
directive|define
name|CONL_ERROR_MAX
value|0x1c3
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tp_param.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_TP_PARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_TP_PARAM_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * ARGO TP  *  * $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/tp_param.h,v $  *  */
end_comment

begin_comment
comment|/******************************************************  * compile time parameters that can be changed  *****************************************************/
end_comment

begin_define
define|#
directive|define
name|TP_CLASSES_IMPLEMENTED
value|0x11
end_define

begin_comment
comment|/* zero and 4 */
end_comment

begin_define
define|#
directive|define
name|TP_DECBIT_CLEAR_COUNT
value|3
end_define

begin_comment
comment|/*#define 	N_TPREF				100 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|N_TPREF
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TP_SOCKBUFSIZE
value|((u_long)4096)
end_define

begin_define
define|#
directive|define
name|TP0_SOCKBUFSIZE
value|((u_long)512)
end_define

begin_define
define|#
directive|define
name|MAX_TSAP_SEL_LEN
value|64
end_define

begin_comment
comment|/* maximum tpdu size we'll accept: */
end_comment

begin_define
define|#
directive|define
name|TP_TPDUSIZE
value|0xc
end_define

begin_comment
comment|/* 4096 octets for classes 1-4*/
end_comment

begin_define
define|#
directive|define
name|TP0_TPDUSIZE
value|0xb
end_define

begin_comment
comment|/* 2048 octets for class 0 */
end_comment

begin_define
define|#
directive|define
name|TP_DFL_TPDUSIZE
value|0x7
end_define

begin_comment
comment|/* 128 octets default */
end_comment

begin_comment
comment|/* NOTE: don't ever negotiate 8192 because could get 	 * wraparound in checksumming 	 * (No mtu is likely to be larger than 4K anyway...) 	 */
end_comment

begin_define
define|#
directive|define
name|TP_NRETRANS
value|12
end_define

begin_comment
comment|/* TCP_MAXRXTSHIFT + 1 */
end_comment

begin_define
define|#
directive|define
name|TP_MAXRXTSHIFT
value|6
end_define

begin_comment
comment|/* factor of 64 */
end_comment

begin_define
define|#
directive|define
name|TP_MAXPORT
value|0xefff
end_define

begin_comment
comment|/* ALPHA: to be used in the context: gain= 1/(2**alpha), or  * put another way, gaintimes(x) (x)>>alpha (forgetting the case alpha==0)  */
end_comment

begin_define
define|#
directive|define
name|TP_RTT_ALPHA
value|3
end_define

begin_define
define|#
directive|define
name|TP_RTV_ALPHA
value|2
end_define

begin_define
define|#
directive|define
name|TP_REXMTVAL
parameter_list|(
name|tpcb
parameter_list|)
define|\
value|((tp_rttadd + (tpcb)->tp_rtt + ((tpcb)->tp_rtv)<< 2) / tp_rttdiv)
end_define

begin_define
define|#
directive|define
name|TP_RANGESET
parameter_list|(
name|tv
parameter_list|,
name|value
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((tv = value)> (max) ? (tv = max) : (tv< min ? tv = min : tv))
end_define

begin_comment
comment|/*  * not sure how to treat data on disconnect  */
end_comment

begin_define
define|#
directive|define
name|T_CONN_DATA
value|0x1
end_define

begin_define
define|#
directive|define
name|T_DISCONNECT
value|0x2
end_define

begin_define
define|#
directive|define
name|T_DISC_DATA
value|0x4
end_define

begin_define
define|#
directive|define
name|T_XDATA
value|0x8
end_define

begin_define
define|#
directive|define
name|ISO_CLNS
value|0
end_define

begin_define
define|#
directive|define
name|IN_CLNS
value|1
end_define

begin_define
define|#
directive|define
name|ISO_CONS
value|2
end_define

begin_define
define|#
directive|define
name|ISO_COSNS
value|3
end_define

begin_define
define|#
directive|define
name|TP_MAX_NETSERVICES
value|3
end_define

begin_comment
comment|/* Indices into tp stats ackreason[i] */
end_comment

begin_define
define|#
directive|define
name|_ACK_DONT_
value|0
end_define

begin_define
define|#
directive|define
name|_ACK_STRAT_EACH_
value|0x1
end_define

begin_define
define|#
directive|define
name|_ACK_STRAT_FULLWIN_
value|0x2
end_define

begin_define
define|#
directive|define
name|_ACK_DUP_
value|0x3
end_define

begin_define
define|#
directive|define
name|_ACK_EOT_
value|0x4
end_define

begin_define
define|#
directive|define
name|_ACK_REORDER_
value|0x5
end_define

begin_define
define|#
directive|define
name|_ACK_USRRCV_
value|0x6
end_define

begin_define
define|#
directive|define
name|_ACK_FCC_
value|0x7
end_define

begin_define
define|#
directive|define
name|_ACK_NUM_REASONS_
value|0x8
end_define

begin_comment
comment|/* masks for use in tp_stash() */
end_comment

begin_define
define|#
directive|define
name|ACK_DONT
value|0
end_define

begin_define
define|#
directive|define
name|ACK_STRAT_EACH
value|(1<< _ACK_STRAT_EACH_)
end_define

begin_define
define|#
directive|define
name|ACK_STRAT_FULLWIN
value|(1<< _ACK_STRAT_FULLWIN_)
end_define

begin_define
define|#
directive|define
name|ACK_DUP
value|(1<< _ACK_DUP_)
end_define

begin_define
define|#
directive|define
name|ACK_EOT
value|(1<< _ACK_EOT_)
end_define

begin_define
define|#
directive|define
name|ACK_REORDER
value|(1<< _ACK_REORDER_)
end_define

begin_comment
comment|/******************************************************  * constants used in the protocol  *****************************************************/
end_comment

begin_define
define|#
directive|define
name|TP_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|TP_MAX_HEADER_LEN
value|256
end_define

begin_define
define|#
directive|define
name|TP_MIN_TPDUSIZE
value|0x7
end_define

begin_comment
comment|/* 128 octets */
end_comment

begin_define
define|#
directive|define
name|TP_MAX_TPDUSIZE
value|0xd
end_define

begin_comment
comment|/* 8192 octets */
end_comment

begin_define
define|#
directive|define
name|TP_MAX_XPD_DATA
value|0x10
end_define

begin_comment
comment|/* 16 octets */
end_comment

begin_define
define|#
directive|define
name|TP_MAX_CC_DATA
value|0x20
end_define

begin_comment
comment|/* 32 octets */
end_comment

begin_define
define|#
directive|define
name|TP_MAX_CR_DATA
value|TP_MAX_CC_DATA
end_define

begin_define
define|#
directive|define
name|TP_MAX_DR_DATA
value|0x40
end_define

begin_comment
comment|/* 64 octets */
end_comment

begin_define
define|#
directive|define
name|TP_XTD_FMT_BIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TP_XTD_FMT_MASK
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|TP_NML_FMT_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|TP_NML_FMT_MASK
value|0x7f
end_define

begin_comment
comment|/*  * values for the tpdu_type field, 2nd byte in a tpdu  */
end_comment

begin_define
define|#
directive|define
name|TP_MIN_TPDUTYPE
value|0x1
end_define

begin_define
define|#
directive|define
name|XPD_TPDU_type
value|0x1
end_define

begin_define
define|#
directive|define
name|XAK_TPDU_type
value|0x2
end_define

begin_define
define|#
directive|define
name|GR_TPDU_type
value|0x3
end_define

begin_define
define|#
directive|define
name|AK_TPDU_type
value|0x6
end_define

begin_define
define|#
directive|define
name|ER_TPDU_type
value|0x7
end_define

begin_define
define|#
directive|define
name|DR_TPDU_type
value|0x8
end_define

begin_define
define|#
directive|define
name|DC_TPDU_type
value|0xc
end_define

begin_define
define|#
directive|define
name|CC_TPDU_type
value|0xd
end_define

begin_define
define|#
directive|define
name|CR_TPDU_type
value|0xe
end_define

begin_define
define|#
directive|define
name|DT_TPDU_type
value|0xf
end_define

begin_define
define|#
directive|define
name|TP_MAX_TPDUTYPE
value|0xf
end_define

begin_comment
comment|/*  * identifiers for the variable-length options in tpdus  */
end_comment

begin_define
define|#
directive|define
name|TPP_acktime
value|0x85
end_define

begin_define
define|#
directive|define
name|TPP_residER
value|0x86
end_define

begin_define
define|#
directive|define
name|TPP_priority
value|0x87
end_define

begin_define
define|#
directive|define
name|TPP_transdelay
value|0x88
end_define

begin_define
define|#
directive|define
name|TPP_throughput
value|0x89
end_define

begin_define
define|#
directive|define
name|TPP_subseq
value|0x8a
end_define

begin_define
define|#
directive|define
name|TPP_flow_cntl_conf
value|0x8c
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|TPP_addl_info
value|0xe0
end_define

begin_define
define|#
directive|define
name|TPP_tpdu_size
value|0xc0
end_define

begin_define
define|#
directive|define
name|TPP_calling_sufx
value|0xc1
end_define

begin_define
define|#
directive|define
name|TPP_invalid_tpdu
value|0xc1
end_define

begin_comment
comment|/* the bozos used a value twice */
end_comment

begin_define
define|#
directive|define
name|TPP_called_sufx
value|0xc2
end_define

begin_define
define|#
directive|define
name|TPP_checksum
value|0xc3
end_define

begin_define
define|#
directive|define
name|TPP_vers
value|0xc4
end_define

begin_define
define|#
directive|define
name|TPP_security
value|0xc5
end_define

begin_define
define|#
directive|define
name|TPP_addl_opt
value|0xc6
end_define

begin_define
define|#
directive|define
name|TPP_alt_class
value|0xc7
end_define

begin_define
define|#
directive|define
name|TPP_perf_meas
value|0xc8
end_define

begin_comment
comment|/* local item : perf meas on, svp */
end_comment

begin_define
define|#
directive|define
name|TPP_ptpdu_size
value|0xf0
end_define

begin_comment
comment|/* preferred TPDU size */
end_comment

begin_define
define|#
directive|define
name|TPP_inact_time
value|0xf2
end_define

begin_comment
comment|/* inactivity time exchanged */
end_comment

begin_comment
comment|/******************************************************  * Some fundamental data types  *****************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRUE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FALSE */
end_comment

begin_define
define|#
directive|define
name|TP_LOCAL
value|22
end_define

begin_define
define|#
directive|define
name|TP_FOREIGN
value|33
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|EOK
end_ifndef

begin_define
define|#
directive|define
name|EOK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EOK */
end_comment

begin_define
define|#
directive|define
name|TP_CLASS_0
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TP_CLASS_1
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|TP_CLASS_2
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|TP_CLASS_3
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|TP_CLASS_4
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|TP_FORCE
value|0x1
end_define

begin_define
define|#
directive|define
name|TP_STRICT
value|0x2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MNULL
end_ifndef

begin_define
define|#
directive|define
name|MNULL
value|(struct mbuf *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MNULL */
end_comment

begin_comment
comment|/* if ../sys/mbuf.h gets MT_types up to 0x40, these will 	 * have to be changed: 	 */
end_comment

begin_define
define|#
directive|define
name|MT_XPD
value|0x44
end_define

begin_define
define|#
directive|define
name|MT_EOT
value|0x40
end_define

begin_define
define|#
directive|define
name|TP_ENOREF
value|0x80000000
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|SeqNum
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|RefNum
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ProtoHook
typedef|;
end_typedef

begin_comment
comment|/******************************************************  * Macro used all over, for driver  *****************************************************/
end_comment

begin_define
define|#
directive|define
name|DoEvent
parameter_list|(
name|x
parameter_list|)
define|\
value|((E.ev_number=(x)),(tp_driver(tpcb,&E)))
end_define

begin_comment
comment|/******************************************************  * Some macros used all over, for timestamping  *****************************************************/
end_comment

begin_define
define|#
directive|define
name|GET_CUR_TIME
parameter_list|(
name|tvalp
parameter_list|)
value|((*tvalp) = time)
end_define

begin_define
define|#
directive|define
name|GET_TIME_SINCE
parameter_list|(
name|oldtvalp
parameter_list|,
name|diffp
parameter_list|)
value|{\ 	(diffp)->tv_sec = time.tv_sec - (oldtvalp)->tv_sec;\ 	(diffp)->tv_usec = time.tv_usec - (oldtvalp)->tv_usec;\ 	if( (diffp)->tv_usec<0 ) {\ 		(diffp)->tv_sec --;\ 		(diffp)->tv_usec = 1000000 - (diffp)->tv_usec;\ 	}\ }
end_define

begin_comment
comment|/******************************************************  * Some macros used for address families  *****************************************************/
end_comment

begin_define
define|#
directive|define
name|satosiso
parameter_list|(
name|ADDR
parameter_list|)
value|((struct sockaddr_iso *)(ADDR))
end_define

begin_define
define|#
directive|define
name|satosin
parameter_list|(
name|ADDR
parameter_list|)
value|((struct sockaddr_in *)(ADDR))
end_define

begin_comment
comment|/******************************************************  * Macro used for changing types of mbufs  *****************************************************/
end_comment

begin_define
define|#
directive|define
name|CHANGE_MTYPE
parameter_list|(
name|m
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|if((m)->m_type != TYPE) { \ 		mbstat.m_mtypes[(m)->m_type]--; mbstat.m_mtypes[TYPE]++; \ 		(m)->m_type = TYPE; \ 	}
end_define

begin_comment
comment|/******************************************************  * Macros used for adding options to a tpdu header and for  * parsing the headers.  * Options are variable-length and must be bcopy-d because on the  * RT your assignments must be N-word aligned for objects of length  * N.  Such a drag.  *****************************************************/
end_comment

begin_struct
struct|struct
name|tp_vbp
block|{
name|u_char
name|tpv_code
decl_stmt|;
name|char
name|tpv_len
decl_stmt|;
name|char
name|tpv_val
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|vbptr
parameter_list|(
name|x
parameter_list|)
value|((struct tp_vbp *)(x))
end_define

begin_define
define|#
directive|define
name|vbval
parameter_list|(
name|x
parameter_list|,
name|type
parameter_list|)
value|(*((type *)&(((struct tp_vbp *)(x))->tpv_val)))
end_define

begin_define
define|#
directive|define
name|vbcode
parameter_list|(
name|x
parameter_list|)
value|(vbptr(x)->tpv_code)
end_define

begin_define
define|#
directive|define
name|vblen
parameter_list|(
name|x
parameter_list|)
value|(vbptr(x)->tpv_len)
end_define

begin_define
define|#
directive|define
name|vb_putval
parameter_list|(
name|dst
parameter_list|,
name|type
parameter_list|,
name|src
parameter_list|)
define|\
value|bcopy((caddr_t)&(src),(caddr_t)&(((struct tp_vbp *)(dst))->tpv_val),\ 	sizeof(type))
end_define

begin_define
define|#
directive|define
name|vb_getval
parameter_list|(
name|src
parameter_list|,
name|type
parameter_list|,
name|dst
parameter_list|)
define|\
value|bcopy((caddr_t)&(((struct tp_vbp *)(src))->tpv_val),(caddr_t)&(dst),sizeof(type))
end_define

begin_define
define|#
directive|define
name|ADDOPTION
parameter_list|(
name|type
parameter_list|,
name|DU
parameter_list|,
name|len
parameter_list|,
name|src
parameter_list|)
define|\
value|{	register caddr_t P;\ 	P = (caddr_t)(DU) + (int)((DU)->tpdu_li);\ 	vbptr(P)->tpv_code = type;\ 	vbptr(P)->tpv_len = len;\ 	bcopy((caddr_t)&src, (caddr_t)&(vbptr(P)->tpv_val), (unsigned)len);\ 	DU->tpdu_li += len+2;
comment|/* 1 for code, 1 for length */
value|\ }
end_define

begin_comment
comment|/******************************************************  * Macro for the local credit:  * uses max transmission unit for the ll  * (as modified by the max TPDU size negotiated)  *****************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARGO_DEBUG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCAL_CREDIT_EXPAND
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOCAL_CREDIT
parameter_list|(
name|tpcb
parameter_list|)
value|tp_local_credit(tpcb)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCAL_CREDIT
parameter_list|(
name|tpcb
parameter_list|)
value|{ if (tpcb->tp_rsycnt == 0) {\     register struct sockbuf *xxsb =&((tpcb)->tp_sock->so_rcv);\     register int xxi = sbspace(xxsb);\     xxi = (xxi<0) ? 0 : ((xxi) / (tpcb)->tp_l_tpdusize);\     xxi = min(xxi, (tpcb)->tp_maxlcredit); \     if (!(tpcb->tp_cebit_off)) { \         (tpcb)->tp_lcredit = ROUND((tpcb)->tp_win_recv); \         if (xxi< (tpcb)->tp_lcredit) { \             (tpcb)->tp_lcredit = xxi; \         } \     } else \         (tpcb)->tp_lcredit = xxi; \ } }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARGO_DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|tp_rttadd
decl_stmt|,
name|tp_rttdiv
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_define
define|#
directive|define
name|printf
value|logpri(LOG_DEBUG),addlog
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|tp_NSTATES
end_ifndef

begin_include
include|#
directive|include
file|<netiso/tp_states.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_events.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|ATTR
end_undef

begin_define
define|#
directive|define
name|ATTR
parameter_list|(
name|X
parameter_list|)
value|ev_union.EV_ ## X
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC__) || defined(__cplusplus) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tp_NSTATES  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


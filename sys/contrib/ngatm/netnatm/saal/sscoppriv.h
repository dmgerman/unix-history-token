begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/saal/sscoppriv.h,v 1.4 2004/07/08 08:22:17 brandt Exp $  *  * Private SSCOP definitions.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<netgraph/atm/sscop/ng_sscop_cust.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|"sscopcust.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Argh. BSDi */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BYTE_ORDER
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_error
error|#
directive|error
literal|"_BYTE_ORDER not defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_BYTE_ORDER
value|BYTE_ORDER
end_define

begin_define
define|#
directive|define
name|_LITTLE_ENDIAN
value|LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|_BIG_ENDIAN
value|BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PDU trailer  */
end_comment

begin_union
union|union
name|pdu
block|{
name|u_int
name|sscop_null
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
name|u_int
name|pl
range|:
literal|2
decl_stmt|;
comment|/* pad length */
name|u_int
label|:
literal|1
expr_stmt|;
comment|/* reserved field */
name|u_int
name|s
range|:
literal|1
decl_stmt|;
comment|/* source */
name|u_int
name|type
range|:
literal|4
decl_stmt|;
comment|/* PDU type */
name|u_int
name|ns
range|:
literal|24
decl_stmt|;
comment|/* sequence number */
else|#
directive|else
name|u_int
name|ns
range|:
literal|24
decl_stmt|;
comment|/* sequence number */
name|u_int
name|type
range|:
literal|4
decl_stmt|;
comment|/* PDU type */
name|u_int
name|s
range|:
literal|1
decl_stmt|;
comment|/* source */
name|u_int
label|:
literal|1
expr_stmt|;
comment|/* reserved field */
name|u_int
name|pl
range|:
literal|2
decl_stmt|;
comment|/* pad length */
endif|#
directive|endif
block|}
name|ss
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|sscop_pl
value|ss.pl
end_define

begin_define
define|#
directive|define
name|sscop_s
value|ss.s
end_define

begin_define
define|#
directive|define
name|sscop_type
value|ss.type
end_define

begin_define
define|#
directive|define
name|sscop_ns
value|ss.ns
end_define

begin_comment
comment|/*  * seqno list entry format  */
end_comment

begin_union
union|union
name|seqno
block|{
name|u_int
name|sscop_null
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
name|u_int
label|:
literal|8
expr_stmt|;
comment|/* pad */
name|u_int
name|n
range|:
literal|24
decl_stmt|;
comment|/* seqno */
else|#
directive|else
name|u_int
name|n
range|:
literal|24
decl_stmt|;
comment|/* seqno */
name|u_int
label|:
literal|8
expr_stmt|;
comment|/* pad */
endif|#
directive|endif
block|}
name|ss
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|sscop_n
value|ss.n
end_define

begin_comment
comment|/*  * Begin pdu  */
end_comment

begin_union
union|union
name|bgn
block|{
name|u_int
name|sscop_null
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
name|u_int
label|:
literal|24
expr_stmt|;
comment|/* reserved */
name|u_int
name|bgns
range|:
literal|8
decl_stmt|;
comment|/* VT_MR */
else|#
directive|else
name|u_int
name|bgns
range|:
literal|8
decl_stmt|;
comment|/* VT_MR */
name|u_int
label|:
literal|24
expr_stmt|;
comment|/* reserved */
endif|#
directive|endif
block|}
name|ss
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|sscop_bgns
value|ss.bgns
end_define

begin_comment
comment|/*  * pdu types  */
end_comment

begin_enum
enum|enum
name|pdu_type
block|{
name|PDU_BGN
init|=
literal|0x1
block|,
comment|/* request initialization */
name|PDU_BGAK
init|=
literal|0x2
block|,
comment|/* request acknowledgement */
name|PDU_END
init|=
literal|0x3
block|,
comment|/* disconnect command */
name|PDU_ENDAK
init|=
literal|0x4
block|,
comment|/* disconnect acknowledgement */
name|PDU_RS
init|=
literal|0x5
block|,
comment|/* resynchronisation command */
name|PDU_RSAK
init|=
literal|0x6
block|,
comment|/* resynchronisation acknowledgement */
name|PDU_BGREJ
init|=
literal|0x7
block|,
comment|/* connection reject */
name|PDU_SD
init|=
literal|0x8
block|,
comment|/* sequenced connection-mode data */
name|PDU_ER
init|=
literal|0x9
block|,
comment|/* recovery command */
name|PDU_POLL
init|=
literal|0xa
block|,
comment|/* xmit state info with req. for recv state */
name|PDU_STAT
init|=
literal|0xb
block|,
comment|/* solicited receiver state info */
name|PDU_USTAT
init|=
literal|0xc
block|,
comment|/* unsolicited receiver state info */
name|PDU_UD
init|=
literal|0xd
block|,
comment|/* unumbered user data */
name|PDU_MD
init|=
literal|0xe
block|,
comment|/* unumbered management data */
name|PDU_ERAK
init|=
literal|0xf
block|,
comment|/* recovery acknowledgement */
block|}
enum|;
end_enum

begin_comment
comment|/*  * These are all signals, that are used by SSCOP. Don't change the order or  * number without also changing the associated tables.  */
end_comment

begin_enum
enum|enum
name|sscop_sigtype
block|{
comment|/* received PDU's */
name|SIG_BGN
block|,
comment|/* request initialization */
name|SIG_BGAK
block|,
comment|/* request acknowledgement */
name|SIG_END
block|,
comment|/* disconnect command */
name|SIG_ENDAK
block|,
comment|/* disconnect acknowledgement */
name|SIG_RS
block|,
comment|/* resynchronisation command */
name|SIG_RSAK
block|,
comment|/* resynchronisation acknowledgement */
name|SIG_BGREJ
block|,
comment|/* connection reject */
name|SIG_SD
block|,
comment|/* sequenced connection-mode data */
name|SIG_ER
block|,
comment|/* recovery command */
name|SIG_POLL
block|,
comment|/* xmitter state info with req for recv state */
name|SIG_STAT
block|,
comment|/* solicited receiver state info */
name|SIG_USTAT
block|,
comment|/* unsolicited receiver state info */
name|SIG_UD
block|,
comment|/* unumbered user data */
name|SIG_MD
block|,
comment|/* unumbered management data */
name|SIG_ERAK
block|,
comment|/* recovery acknoledgement */
comment|/* timer expiry */
name|SIG_T_CC
block|,
comment|/* CC timer */
name|SIG_T_POLL
block|,
comment|/* POLL timer */
name|SIG_T_KA
block|,
comment|/* KEEP ALIVE timer */
name|SIG_T_NR
block|,
comment|/* NO RESPONSE timer */
name|SIG_T_IDLE
block|,
comment|/* IDLE timer */
comment|/* user originated signals */
name|SIG_PDU_Q
block|,
comment|/* PDU enqueued pseudosignal */
name|SIG_USER_DATA
block|,
comment|/* user data request */
name|SIG_ESTAB_REQ
block|,
comment|/* establish connection request */
name|SIG_ESTAB_RESP
block|,
comment|/* establish connection response */
name|SIG_RELEASE_REQ
block|,
comment|/* release connection request */
name|SIG_RECOVER
block|,
comment|/* automatic recover response */
name|SIG_SYNC_REQ
block|,
comment|/* resynchronisation request */
name|SIG_SYNC_RESP
block|,
comment|/* resynchronisation response */
name|SIG_UDATA
block|,
comment|/* UDATA request */
name|SIG_MDATA
block|,
comment|/* MDATA request */
name|SIG_UPDU_Q
block|,
comment|/* UDATA PDU enqueued pseudosignal */
name|SIG_MPDU_Q
block|,
comment|/* MDATA PDU enqueued pseudosignal */
name|SIG_RETRIEVE
block|,
comment|/* RETRIEVE */
comment|/* number of signals */
name|SIG_NUM
block|}
enum|;
end_enum

begin_comment
comment|/*  * This is a message as contained in a sscop message queue. It holds a pointer  * to the real message.  */
end_comment

begin_struct
struct|struct
name|sscop_msg
block|{
name|sscop_msgq_link_t
name|link
decl_stmt|;
name|u_int
name|seqno
decl_stmt|;
comment|/* seq no */
name|u_int
name|poll_seqno
decl_stmt|;
comment|/* poll seqno (for messages in xmit buffer) */
name|u_int
name|rexmit
decl_stmt|;
comment|/* in retransmission queue? */
name|struct
name|SSCOP_MBUF_T
modifier|*
name|m
decl_stmt|;
comment|/* the message */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure is used to hold signals in the signal queue  */
end_comment

begin_struct
struct|struct
name|sscop_sig
block|{
name|sscop_sigq_link_t
name|link
decl_stmt|;
comment|/* next signal */
name|enum
name|sscop_sigtype
name|sig
decl_stmt|;
comment|/* THE signal */
name|struct
name|sscop_msg
modifier|*
name|msg
decl_stmt|;
comment|/* signal argument (message) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure holds the entire sscop state  */
end_comment

begin_struct
struct|struct
name|sscop
block|{
name|enum
name|sscop_state
name|state
decl_stmt|;
comment|/* current state */
specifier|const
name|struct
name|sscop_funcs
modifier|*
name|funcs
decl_stmt|;
comment|/* send state */
name|u_int
name|vt_s
decl_stmt|;
comment|/* seqno for next pdu first time transmitted */
name|u_int
name|vt_ps
decl_stmt|;
comment|/* current poll seqno */
name|u_int
name|vt_a
decl_stmt|;
comment|/* next expected in-sequence sd pdu */
name|u_int
name|vt_pa
decl_stmt|;
comment|/* poll seqno of next stat pdu */
name|u_int
name|vt_ms
decl_stmt|;
comment|/* maximum allowed send sd seqno */
name|u_int
name|vt_pd
decl_stmt|;
comment|/* poll data state */
name|u_int
name|vt_cc
decl_stmt|;
comment|/* connection control state */
name|u_int
name|vt_sq
decl_stmt|;
comment|/* transmitter connection sequence */
comment|/* receive state */
name|u_int
name|vr_r
decl_stmt|;
comment|/* receive state */
name|u_int
name|vr_h
decl_stmt|;
comment|/* highes expected state */
name|u_int
name|vr_mr
decl_stmt|;
comment|/* maximum acceptable */
name|u_int
name|vr_sq
decl_stmt|;
comment|/* receiver connection state */
comment|/* timers */
name|sscop_timer_t
name|t_cc
decl_stmt|;
comment|/* timer_CC */
name|sscop_timer_t
name|t_nr
decl_stmt|;
comment|/* timer_NO_RESPONSE */
name|sscop_timer_t
name|t_ka
decl_stmt|;
comment|/* timer KEEP_ALIVE */
name|sscop_timer_t
name|t_poll
decl_stmt|;
comment|/* timer_POLL */
name|sscop_timer_t
name|t_idle
decl_stmt|;
comment|/* idle timer */
comment|/* maximum values */
name|u_int
name|maxj
decl_stmt|;
comment|/* maximum uu-info */
name|u_int
name|maxk
decl_stmt|;
comment|/* maximum info */
name|u_int
name|maxcc
decl_stmt|;
comment|/* maximum number of bgn, end, er and rs */
name|u_int
name|maxpd
decl_stmt|;
comment|/* maximum value of vt_pd */
name|u_int
name|maxstat
decl_stmt|;
comment|/* maximum length of list */
name|u_int
name|timercc
decl_stmt|;
comment|/* connection control timer */
name|u_int
name|timerka
decl_stmt|;
comment|/* keep alive timer */
name|u_int
name|timernr
decl_stmt|;
comment|/* no response timer */
name|u_int
name|timerpoll
decl_stmt|;
comment|/* polling */
name|u_int
name|timeridle
decl_stmt|;
comment|/* idle timer */
name|u_int
name|robustness
decl_stmt|;
comment|/* atmf/97-0216 robustness enhancement */
name|u_int
name|poll_after_rex
decl_stmt|;
comment|/* optional POLL after re-transmission */
name|u_int
name|mr
decl_stmt|;
comment|/* initial window */
comment|/* 	 * buffers and queues. 	 * All expect the xq hold SD PDUs. 	 */
name|sscop_msgq_head_t
name|xq
decl_stmt|;
comment|/* xmit queue (input from user before xmit) */
name|sscop_msgq_head_t
name|uxq
decl_stmt|;
comment|/* UD xmit queue */
name|sscop_msgq_head_t
name|mxq
decl_stmt|;
comment|/* MD xmit queue */
name|sscop_msgq_head_t
name|xbuf
decl_stmt|;
comment|/* transmission buffer (SD PDUs transmitted) */
name|int
name|rxq
decl_stmt|;
comment|/* number of PDUs in retransmission queue */
name|sscop_msgq_head_t
name|rbuf
decl_stmt|;
comment|/* receive buffer (SD PDUs) */
name|int
name|last_end_src
decl_stmt|;
comment|/* source field from last xmitted end pdu */
name|int
name|clear_buffers
decl_stmt|;
comment|/* flag */
name|int
name|credit
decl_stmt|;
comment|/* send window not closed */
name|u_int
name|ll_busy
decl_stmt|;
comment|/* lower layer busy */
name|u_int
name|rs_mr
decl_stmt|;
comment|/* N(MR) in last RS PDU */
name|u_int
name|rs_sq
decl_stmt|;
comment|/* N(SQ) in last RS PDU */
name|struct
name|SSCOP_MBUF_T
modifier|*
name|uu_bgn
decl_stmt|;
comment|/* last UU data */
name|struct
name|SSCOP_MBUF_T
modifier|*
name|uu_bgak
decl_stmt|;
comment|/*  ... */
name|struct
name|SSCOP_MBUF_T
modifier|*
name|uu_bgrej
decl_stmt|;
comment|/*  ... */
name|struct
name|SSCOP_MBUF_T
modifier|*
name|uu_end
decl_stmt|;
comment|/*  ... */
name|struct
name|SSCOP_MBUF_T
modifier|*
name|uu_rs
decl_stmt|;
comment|/*  ... */
comment|/* signal queues */
name|sscop_sigq_head_t
name|sigs
decl_stmt|;
comment|/* saved signals */
name|sscop_sigq_head_t
name|saved_sigs
decl_stmt|;
comment|/* saved signals */
name|int
name|in_sig
decl_stmt|;
comment|/* in signal handler */
comment|/* debugging */
name|u_int
name|debug
decl_stmt|;
comment|/* AA interface */
name|void
modifier|*
name|aarg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Default values for SSCOP  */
end_comment

begin_enum
enum|enum
block|{
name|MAXK
init|=
literal|4096
block|,
name|MAXMAXK
init|=
literal|65528
block|,
name|MAXJ
init|=
literal|4096
block|,
name|MAXMAXJ
init|=
literal|65524
block|,
name|MAXCC
init|=
literal|4
block|,
name|MAXSTAT
init|=
literal|67
block|,
name|MAXPD
init|=
literal|25
block|,
name|MAXMR
init|=
literal|128
block|,
comment|/* ??? */
name|TIMERCC
init|=
literal|1000
block|,
name|TIMERKA
init|=
literal|2000
block|,
name|TIMERNR
init|=
literal|7000
block|,
name|TIMERPOLL
init|=
literal|750
block|,
name|TIMERIDLE
init|=
literal|15000
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Sequence number arithmetic  */
end_comment

begin_define
define|#
directive|define
name|SEQNO_DIFF
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|(((A)< (B)) ? ((A) + (1<<24) - (B)) : ((A) - (B)))
end_define

begin_comment
comment|/*  * Debugging  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SSCOP_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|VERBOSE
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|F
parameter_list|)
value|if ((S)->debug& (M)) (S)->funcs->verbose F
end_define

begin_define
define|#
directive|define
name|VERBERR
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|F
parameter_list|)
value|if ((S)->debug& (M)) (S)->funcs->verbose F
end_define

begin_define
define|#
directive|define
name|ISVERBOSE
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|)
value|((S)->debug& (M))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VERBOSE
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|F
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VERBERR
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|,
name|F
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ISVERBOSE
parameter_list|(
name|S
parameter_list|,
name|M
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit


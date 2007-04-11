begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp_timer.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TCP_TIMER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TCP_TIMER_H_
end_define

begin_comment
comment|/*  * The TCPT_REXMT timer is used to force retransmissions.  * The TCP has the TCPT_REXMT timer set whenever segments  * have been sent for which ACKs are expected but not yet  * received.  If an ACK is received which advances tp->snd_una,  * then the retransmit timer is cleared (if there are no more  * outstanding segments) or reset to the base value (if there  * are more ACKs expected).  Whenever the retransmit timer goes off,  * we retransmit one unacknowledged segment, and do a backoff  * on the retransmit timer.  *  * The TCPT_PERSIST timer is used to keep window size information  * flowing even if the window goes shut.  If all previous transmissions  * have been acknowledged (so that there are no retransmissions in progress),  * and the window is too small to bother sending anything, then we start  * the TCPT_PERSIST timer.  When it expires, if the window is nonzero,  * we go to transmit state.  Otherwise, at intervals send a single byte  * into the peer's window to force him to update our window information.  * We do this at most as often as TCPT_PERSMIN time intervals,  * but no more frequently than the current estimate of round-trip  * packet time.  The TCPT_PERSIST timer is cleared whenever we receive  * a window update from the peer.  *  * The TCPT_KEEP timer is used to keep connections alive.  If an  * connection is idle (no segments received) for TCPTV_KEEP_INIT amount of time,  * but not yet established, then we drop the connection.  Once the connection  * is established, if the connection is idle for TCPTV_KEEP_IDLE time  * (and keepalives have been enabled on the socket), we begin to probe  * the connection.  We force the peer to send us a segment by sending:  *<SEQ=SND.UNA-1><ACK=RCV.NXT><CTL=ACK>  * This segment is (deliberately) outside the window, and should elicit  * an ack segment in response from the peer.  If, despite the TCPT_KEEP  * initiated segments we cannot elicit a response from a peer in TCPT_MAXIDLE  * amount of time probing, then we drop the connection.  */
end_comment

begin_comment
comment|/*  * Time constants.  */
end_comment

begin_define
define|#
directive|define
name|TCPTV_MSL
value|( 30*hz)
end_define

begin_comment
comment|/* max seg lifetime (hah!) */
end_comment

begin_define
define|#
directive|define
name|TCPTV_SRTTBASE
value|0
end_define

begin_comment
comment|/* base roundtrip time; 						   if 0, no idea yet */
end_comment

begin_define
define|#
directive|define
name|TCPTV_RTOBASE
value|(  3*hz)
end_define

begin_comment
comment|/* assumed RTO if no info */
end_comment

begin_define
define|#
directive|define
name|TCPTV_SRTTDFLT
value|(  3*hz)
end_define

begin_comment
comment|/* assumed RTT if no info */
end_comment

begin_define
define|#
directive|define
name|TCPTV_PERSMIN
value|(  5*hz)
end_define

begin_comment
comment|/* retransmit persistence */
end_comment

begin_define
define|#
directive|define
name|TCPTV_PERSMAX
value|( 60*hz)
end_define

begin_comment
comment|/* maximum persist interval */
end_comment

begin_define
define|#
directive|define
name|TCPTV_KEEP_INIT
value|( 75*hz)
end_define

begin_comment
comment|/* initial connect keepalive */
end_comment

begin_define
define|#
directive|define
name|TCPTV_KEEP_IDLE
value|(120*60*hz)
end_define

begin_comment
comment|/* dflt time before probing */
end_comment

begin_define
define|#
directive|define
name|TCPTV_KEEPINTVL
value|( 75*hz)
end_define

begin_comment
comment|/* default probe interval */
end_comment

begin_define
define|#
directive|define
name|TCPTV_KEEPCNT
value|8
end_define

begin_comment
comment|/* max probes before drop */
end_comment

begin_define
define|#
directive|define
name|TCPTV_INFLIGHT_RTTTHRESH
value|(10*hz/1000)
end_define

begin_comment
comment|/* below which inflight 						   disengages, in msec */
end_comment

begin_define
define|#
directive|define
name|TCPTV_FINWAIT2_TIMEOUT
value|(60*hz)
end_define

begin_comment
comment|/* FIN_WAIT_2 timeout if no receiver */
end_comment

begin_comment
comment|/*  * Minimum retransmit timer is 3 ticks, for algorithmic stability.  * TCPT_RANGESET() will add another TCPTV_CPU_VAR to deal with  * the expected worst-case processing variances by the kernels  * representing the end points.  Such variances do not always show  * up in the srtt because the timestamp is often calculated at  * the interface rather then at the TCP layer.  This value is  * typically 50ms.  However, it is also possible that delayed  * acks (typically 100ms) could create issues so we set the slop  * to 200ms to try to cover it.  Note that, properly speaking,  * delayed-acks should not create a major issue for interactive  * environments which 'P'ush the last segment, at least as  * long as implementations do the required 'at least one ack  * for every two packets' for the non-interactive streaming case.  * (maybe the RTO calculation should use 2*RTT instead of RTT  * to handle the ack-every-other-packet case).  *  * The prior minimum of 1*hz (1 second) badly breaks throughput on any  * networks faster then a modem that has minor (e.g. 1%) packet loss.  */
end_comment

begin_define
define|#
directive|define
name|TCPTV_MIN
value|( 3 )
end_define

begin_comment
comment|/* minimum allowable value */
end_comment

begin_define
define|#
directive|define
name|TCPTV_CPU_VAR
value|( hz/5 )
end_define

begin_comment
comment|/* cpu variance allowed (200ms) */
end_comment

begin_define
define|#
directive|define
name|TCPTV_REXMTMAX
value|( 64*hz)
end_define

begin_comment
comment|/* max allowable REXMT value */
end_comment

begin_define
define|#
directive|define
name|TCPTV_TWTRUNC
value|8
end_define

begin_comment
comment|/* RTO factor to truncate TW */
end_comment

begin_define
define|#
directive|define
name|TCP_LINGERTIME
value|120
end_define

begin_comment
comment|/* linger at most 2 minutes */
end_comment

begin_define
define|#
directive|define
name|TCP_MAXRXTSHIFT
value|12
end_define

begin_comment
comment|/* maximum retransmits */
end_comment

begin_define
define|#
directive|define
name|TCPTV_DELACK
value|(hz / PR_FASTHZ / 2)
end_define

begin_comment
comment|/* 100ms timeout */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TCPTIMERS
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|tcptimers
index|[]
init|=
block|{
literal|"REXMT"
block|,
literal|"PERSIST"
block|,
literal|"KEEP"
block|,
literal|"2MSL"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Force a time value to be in a certain range.  */
end_comment

begin_define
define|#
directive|define
name|TCPT_RANGESET
parameter_list|(
name|tv
parameter_list|,
name|value
parameter_list|,
name|tvmin
parameter_list|,
name|tvmax
parameter_list|)
value|do { \ 	(tv) = (value) + tcp_rexmit_slop; \ 	if ((u_long)(tv)< (u_long)(tvmin)) \ 		(tv) = (tvmin); \ 	if ((u_long)(tv)> (u_long)(tvmax)) \ 		(tv) = (tvmax); \ } while(0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|tcp_timer
block|{
name|struct
name|callout
name|tt_timer
decl_stmt|;
name|int
name|tt_nextc
decl_stmt|;
comment|/* next callout time in time_uptime */
name|int
name|tt_active
decl_stmt|;
comment|/* engaged callouts */
define|#
directive|define
name|TT_DELACK
value|0x01
define|#
directive|define
name|TT_REXMT
value|0x02
define|#
directive|define
name|TT_PERSIST
value|0x04
define|#
directive|define
name|TT_KEEP
value|0x08
define|#
directive|define
name|TT_2MSL
value|0x10
name|int
name|tt_delack
decl_stmt|;
name|int
name|tt_rexmt
decl_stmt|;
name|int
name|tt_persist
decl_stmt|;
name|int
name|tt_keep
decl_stmt|;
name|int
name|tt_2msl
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|tcp_keepinit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time to establish connection */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcp_keepidle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time before keepalive probes begin */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcp_keepintvl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time between keepalive probes */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcp_maxidle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time to drop after starting probes */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcp_delacktime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time before sending a delayed ACK */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcp_maxpersistidle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_rexmit_min
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_rexmit_slop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_msl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_ttl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time to live for TCP segs */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcp_backoff
index|[]
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|tcptw
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|tcp_finwait2_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_fast_finwait2_recycle
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|tcp_timer_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcptw
modifier|*
name|tcp_timer_2msl_tw
parameter_list|(
name|int
name|_reuse
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX temporary */
end_comment

begin_function_decl
name|void
name|tcp_timer_2msl_reset
parameter_list|(
name|struct
name|tcptw
modifier|*
name|_tw
parameter_list|,
name|int
name|rearm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_timer_2msl_stop
parameter_list|(
name|struct
name|tcptw
modifier|*
name|_tw
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_TCP_TIMER_H_ */
end_comment

end_unit


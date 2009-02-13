begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1995, Mike Mitchell  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)spx_timer.h  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_SPX_TIMER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_SPX_TIMER_H_
end_define

begin_comment
comment|/*  * Definitions of the SPX timers.  These timers are counted  * down PR_SLOWHZ times a second.  */
end_comment

begin_define
define|#
directive|define
name|SPXT_REXMT
value|0
end_define

begin_comment
comment|/* retransmit */
end_comment

begin_define
define|#
directive|define
name|SPXT_PERSIST
value|1
end_define

begin_comment
comment|/* retransmit persistence */
end_comment

begin_define
define|#
directive|define
name|SPXT_KEEP
value|2
end_define

begin_comment
comment|/* keep alive */
end_comment

begin_define
define|#
directive|define
name|SPXT_2MSL
value|3
end_define

begin_comment
comment|/* 2*msl quiet time timer */
end_comment

begin_comment
comment|/*  * The SPXT_REXMT timer is used to force retransmissions.  * The SPX has the SPXT_REXMT timer set whenever segments  * have been sent for which ACKs are expected but not yet  * received.  If an ACK is received which advances tp->snd_una,  * then the retransmit timer is cleared (if there are no more  * outstanding segments) or reset to the base value (if there  * are more ACKs expected).  Whenever the retransmit timer goes off,  * we retransmit one unacknowledged segment, and do a backoff  * on the retransmit timer.  *  * The SPXT_PERSIST timer is used to keep window size information  * flowing even if the window goes shut.  If all previous transmissions  * have been acknowledged (so that there are no retransmissions in progress),  * and the window is too small to bother sending anything, then we start  * the SPXT_PERSIST timer.  When it expires, if the window is nonzero,  * we go to transmit state.  Otherwise, at intervals send a single byte  * into the peer's window to force him to update our window information.  * We do this at most as often as SPXT_PERSMIN time intervals,  * but no more frequently than the current estimate of round-trip  * packet time.  The SPXT_PERSIST timer is cleared whenever we receive  * a window update from the peer.  *  * The SPXT_KEEP timer is used to keep connections alive.  If an  * connection is idle (no segments received) for SPXTV_KEEP amount of time,  * but not yet established, then we drop the connection.  If the connection  * is established, then we force the peer to send us a segment by sending:  *<SEQ=SND.UNA-1><ACK=RCV.NXT><CTL=ACK>  * This segment is (deliberately) outside the window, and should elicit  * an ack segment in response from the peer.  If, despite the SPXT_KEEP  * initiated segments we cannot elicit a response from a peer in SPXT_MAXIDLE  * amount of time, then we drop the connection.  */
end_comment

begin_define
define|#
directive|define
name|SPX_TTL
value|30
end_define

begin_comment
comment|/* default time to live for SPX segs */
end_comment

begin_comment
comment|/*  * Time constants.  */
end_comment

begin_define
define|#
directive|define
name|SPXTV_MSL
value|( 15*PR_SLOWHZ)
end_define

begin_comment
comment|/* max seg lifetime */
end_comment

begin_define
define|#
directive|define
name|SPXTV_SRTTBASE
value|0
end_define

begin_comment
comment|/* base roundtrip time; 						   if 0, no idea yet */
end_comment

begin_define
define|#
directive|define
name|SPXTV_SRTTDFLT
value|(  3*PR_SLOWHZ)
end_define

begin_comment
comment|/* assumed RTT if no info */
end_comment

begin_define
define|#
directive|define
name|SPXTV_PERSMIN
value|(  5*PR_SLOWHZ)
end_define

begin_comment
comment|/* retransmit persistence */
end_comment

begin_define
define|#
directive|define
name|SPXTV_PERSMAX
value|( 60*PR_SLOWHZ)
end_define

begin_comment
comment|/* maximum persist interval */
end_comment

begin_define
define|#
directive|define
name|SPXTV_KEEP
value|( 75*PR_SLOWHZ)
end_define

begin_comment
comment|/* keep alive - 75 secs */
end_comment

begin_define
define|#
directive|define
name|SPXTV_MAXIDLE
value|(  8*SPXTV_KEEP)
end_define

begin_comment
comment|/* maximum allowable idle 						   time before drop conn */
end_comment

begin_define
define|#
directive|define
name|SPXTV_MIN
value|(  1*PR_SLOWHZ)
end_define

begin_comment
comment|/* minimum allowable value */
end_comment

begin_define
define|#
directive|define
name|SPXTV_REXMTMAX
value|( 64*PR_SLOWHZ)
end_define

begin_comment
comment|/* max allowable REXMT value */
end_comment

begin_define
define|#
directive|define
name|SPX_LINGERTIME
value|120
end_define

begin_comment
comment|/* linger at most 2 minutes */
end_comment

begin_define
define|#
directive|define
name|SPX_MAXRXTSHIFT
value|12
end_define

begin_comment
comment|/* maximum retransmits */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPXTIMERS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|spxtimers
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
name|SPXT_RANGESET
parameter_list|(
name|tv
parameter_list|,
name|value
parameter_list|,
name|tvmin
parameter_list|,
name|tvmax
parameter_list|)
value|{ \ 	(tv) = (value); \ 	if ((tv)< (tvmin)) \ 		(tv) = (tvmin); \ 	else if ((tv)> (tvmax)) \ 		(tv) = (tvmax); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETIPX_SPX_TIMER_H_ */
end_comment

end_unit


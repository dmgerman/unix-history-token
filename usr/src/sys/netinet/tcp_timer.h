begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)tcp_timer.h	7.7 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definitions of the TCP timers.  These timers are counted  * down PR_SLOWHZ times a second.  */
end_comment

begin_define
define|#
directive|define
name|TCPT_NTIMERS
value|4
end_define

begin_define
define|#
directive|define
name|TCPT_REXMT
value|0
end_define

begin_comment
comment|/* retransmit */
end_comment

begin_define
define|#
directive|define
name|TCPT_PERSIST
value|1
end_define

begin_comment
comment|/* retransmit persistance */
end_comment

begin_define
define|#
directive|define
name|TCPT_KEEP
value|2
end_define

begin_comment
comment|/* keep alive */
end_comment

begin_define
define|#
directive|define
name|TCPT_2MSL
value|3
end_define

begin_comment
comment|/* 2*msl quiet time timer */
end_comment

begin_comment
comment|/*  * The TCPT_REXMT timer is used to force retransmissions.  * The TCP has the TCPT_REXMT timer set whenever segments  * have been sent for which ACKs are expected but not yet  * received.  If an ACK is received which advances tp->snd_una,  * then the retransmit timer is cleared (if there are no more  * outstanding segments) or reset to the base value (if there  * are more ACKs expected).  Whenever the retransmit timer goes off,  * we retransmit one unacknowledged segment, and do a backoff  * on the retransmit timer.  *  * The TCPT_PERSIST timer is used to keep window size information  * flowing even if the window goes shut.  If all previous transmissions  * have been acknowledged (so that there are no retransmissions in progress),  * and the window is too small to bother sending anything, then we start  * the TCPT_PERSIST timer.  When it expires, if the window is nonzero,  * we go to transmit state.  Otherwise, at intervals send a single byte  * into the peer's window to force him to update our window information.  * We do this at most as often as TCPT_PERSMIN time intervals,  * but no more frequently than the current estimate of round-trip  * packet time.  The TCPT_PERSIST timer is cleared whenever we receive  * a window update from the peer.  *  * The TCPT_KEEP timer is used to keep connections alive.  If an  * connection is idle (no segments received) for TCPTV_KEEP_INIT amount of time,  * but not yet established, then we drop the connection.  Once the connection  * is established, if the connection is idle for TCPTV_KEEP_IDLE time  * (and keepalives have been enabled on the socket), we begin to probe  * the connection.  We force the peer to send us a segment by sending:  *<SEQ=SND.UNA-1><ACK=RCV.NXT><CTL=ACK>  * This segment is (deliberately) outside the window, and should elicit  * an ack segment in response from the peer.  If, despite the TCPT_KEEP  * initiated segments we cannot elicit a response from a peer in TCPT_MAXIDLE  * amount of time probing, then we drop the connection.  */
end_comment

begin_define
define|#
directive|define
name|TCP_TTL
value|60
end_define

begin_comment
comment|/* default time to live for TCP segs */
end_comment

begin_comment
comment|/*  * Time constants.  */
end_comment

begin_define
define|#
directive|define
name|TCPTV_MSL
value|( 30*PR_SLOWHZ)
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
name|TCPTV_SRTTDFLT
value|(  3*PR_SLOWHZ)
end_define

begin_comment
comment|/* assumed RTT if no info */
end_comment

begin_define
define|#
directive|define
name|TCPTV_PERSMIN
value|(  5*PR_SLOWHZ)
end_define

begin_comment
comment|/* retransmit persistance */
end_comment

begin_define
define|#
directive|define
name|TCPTV_PERSMAX
value|( 60*PR_SLOWHZ)
end_define

begin_comment
comment|/* maximum persist interval */
end_comment

begin_define
define|#
directive|define
name|TCPTV_KEEP_INIT
value|( 75*PR_SLOWHZ)
end_define

begin_comment
comment|/* initial connect keep alive */
end_comment

begin_define
define|#
directive|define
name|TCPTV_KEEP_IDLE
value|(120*60*PR_SLOWHZ)
end_define

begin_comment
comment|/* dflt time before probing */
end_comment

begin_define
define|#
directive|define
name|TCPTV_KEEPINTVL
value|( 75*PR_SLOWHZ)
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
name|TCPTV_MIN
value|(  1*PR_SLOWHZ)
end_define

begin_comment
comment|/* minimum allowable value */
end_comment

begin_define
define|#
directive|define
name|TCPTV_REXMTMAX
value|( 64*PR_SLOWHZ)
end_define

begin_comment
comment|/* max allowable REXMT value */
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

begin_ifdef
ifdef|#
directive|ifdef
name|TCPTIMERS
end_ifdef

begin_decl_stmt
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
value|{ \ 	(tv) = (value); \ 	if ((tv)< (tvmin)) \ 		(tv) = (tvmin); \ 	else if ((tv)> (tvmax)) \ 		(tv) = (tvmax); \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

end_unit


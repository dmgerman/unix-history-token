begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp_fsm.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TCP_FSM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TCP_FSM_H_
end_define

begin_comment
comment|/*  * TCP FSM state definitions.  * Per RFC793, September, 1981.  */
end_comment

begin_define
define|#
directive|define
name|TCP_NSTATES
value|11
end_define

begin_define
define|#
directive|define
name|TCPS_CLOSED
value|0
end_define

begin_comment
comment|/* closed */
end_comment

begin_define
define|#
directive|define
name|TCPS_LISTEN
value|1
end_define

begin_comment
comment|/* listening for connection */
end_comment

begin_define
define|#
directive|define
name|TCPS_SYN_SENT
value|2
end_define

begin_comment
comment|/* active, have sent syn */
end_comment

begin_define
define|#
directive|define
name|TCPS_SYN_RECEIVED
value|3
end_define

begin_comment
comment|/* have send and received syn */
end_comment

begin_comment
comment|/* states< TCPS_ESTABLISHED are those where connections not established */
end_comment

begin_define
define|#
directive|define
name|TCPS_ESTABLISHED
value|4
end_define

begin_comment
comment|/* established */
end_comment

begin_define
define|#
directive|define
name|TCPS_CLOSE_WAIT
value|5
end_define

begin_comment
comment|/* rcvd fin, waiting for close */
end_comment

begin_comment
comment|/* states> TCPS_CLOSE_WAIT are those where user has closed */
end_comment

begin_define
define|#
directive|define
name|TCPS_FIN_WAIT_1
value|6
end_define

begin_comment
comment|/* have closed, sent fin */
end_comment

begin_define
define|#
directive|define
name|TCPS_CLOSING
value|7
end_define

begin_comment
comment|/* closed xchd FIN; await FIN ACK */
end_comment

begin_define
define|#
directive|define
name|TCPS_LAST_ACK
value|8
end_define

begin_comment
comment|/* had fin and close; await FIN ACK */
end_comment

begin_comment
comment|/* states> TCPS_CLOSE_WAIT&&< TCPS_FIN_WAIT_2 await ACK of FIN */
end_comment

begin_define
define|#
directive|define
name|TCPS_FIN_WAIT_2
value|9
end_define

begin_comment
comment|/* have closed, fin is acked */
end_comment

begin_define
define|#
directive|define
name|TCPS_TIME_WAIT
value|10
end_define

begin_comment
comment|/* in 2*msl quiet wait after close */
end_comment

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_define
define|#
directive|define
name|TCP6_NSTATES
value|TCP_NSTATES
end_define

begin_define
define|#
directive|define
name|TCP6S_CLOSED
value|TCPS_CLOSED
end_define

begin_define
define|#
directive|define
name|TCP6S_LISTEN
value|TCPS_LISTEN
end_define

begin_define
define|#
directive|define
name|TCP6S_SYN_SENT
value|TCPS_SYN_SENT
end_define

begin_define
define|#
directive|define
name|TCP6S_SYN_RECEIVED
value|TCPS_SYN_RECEIVED
end_define

begin_define
define|#
directive|define
name|TCP6S_ESTABLISHED
value|TCPS_ESTABLISHED
end_define

begin_define
define|#
directive|define
name|TCP6S_CLOSE_WAIT
value|TCPS_CLOSE_WAIT
end_define

begin_define
define|#
directive|define
name|TCP6S_FIN_WAIT_1
value|TCPS_FIN_WAIT_1
end_define

begin_define
define|#
directive|define
name|TCP6S_CLOSING
value|TCPS_CLOSING
end_define

begin_define
define|#
directive|define
name|TCP6S_LAST_ACK
value|TCPS_LAST_ACK
end_define

begin_define
define|#
directive|define
name|TCP6S_FIN_WAIT_2
value|TCPS_FIN_WAIT_2
end_define

begin_define
define|#
directive|define
name|TCP6S_TIME_WAIT
value|TCPS_TIME_WAIT
end_define

begin_define
define|#
directive|define
name|TCPS_HAVERCVDSYN
parameter_list|(
name|s
parameter_list|)
value|((s)>= TCPS_SYN_RECEIVED)
end_define

begin_define
define|#
directive|define
name|TCPS_HAVEESTABLISHED
parameter_list|(
name|s
parameter_list|)
value|((s)>= TCPS_ESTABLISHED)
end_define

begin_define
define|#
directive|define
name|TCPS_HAVERCVDFIN
parameter_list|(
name|s
parameter_list|)
value|((s)>= TCPS_TIME_WAIT)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TCPOUTFLAGS
end_ifdef

begin_comment
comment|/*  * Flags used when sending segments in tcp_output.  * Basic flags (TH_RST,TH_ACK,TH_SYN,TH_FIN) are totally  * determined by state, with the proviso that TH_FIN is sent only  * if all data queued for output is included in the segment.  */
end_comment

begin_decl_stmt
specifier|static
name|u_char
name|tcp_outflags
index|[
name|TCP_NSTATES
index|]
init|=
block|{
name|TH_RST
operator||
name|TH_ACK
block|,
comment|/* 0, CLOSED */
literal|0
block|,
comment|/* 1, LISTEN */
name|TH_SYN
block|,
comment|/* 2, SYN_SENT */
name|TH_SYN
operator||
name|TH_ACK
block|,
comment|/* 3, SYN_RECEIVED */
name|TH_ACK
block|,
comment|/* 4, ESTABLISHED */
name|TH_ACK
block|,
comment|/* 5, CLOSE_WAIT */
name|TH_FIN
operator||
name|TH_ACK
block|,
comment|/* 6, FIN_WAIT_1 */
name|TH_FIN
operator||
name|TH_ACK
block|,
comment|/* 7, CLOSING */
name|TH_FIN
operator||
name|TH_ACK
block|,
comment|/* 8, LAST_ACK */
name|TH_ACK
block|,
comment|/* 9, FIN_WAIT_2 */
name|TH_ACK
block|,
comment|/* 10, TIME_WAIT */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KPROF
end_ifdef

begin_decl_stmt
name|int
name|tcp_acounts
index|[
name|TCP_NSTATES
index|]
index|[
name|PRU_NREQ
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TCPSTATES
end_ifdef

begin_decl_stmt
specifier|const
name|char
modifier|*
name|tcpstates
index|[]
init|=
block|{
literal|"CLOSED"
block|,
literal|"LISTEN"
block|,
literal|"SYN_SENT"
block|,
literal|"SYN_RCVD"
block|,
literal|"ESTABLISHED"
block|,
literal|"CLOSE_WAIT"
block|,
literal|"FIN_WAIT_1"
block|,
literal|"CLOSING"
block|,
literal|"LAST_ACK"
block|,
literal|"FIN_WAIT_2"
block|,
literal|"TIME_WAIT"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit


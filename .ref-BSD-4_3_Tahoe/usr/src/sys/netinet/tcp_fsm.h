begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)tcp_fsm.h	7.3 (Berkeley) 6/29/88  */
end_comment

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
literal|0
block|,
name|TH_SYN
block|,
name|TH_SYN
operator||
name|TH_ACK
block|,
name|TH_ACK
block|,
name|TH_ACK
block|,
name|TH_FIN
operator||
name|TH_ACK
block|,
name|TH_FIN
operator||
name|TH_ACK
block|,
name|TH_FIN
operator||
name|TH_ACK
block|,
name|TH_ACK
block|,
name|TH_ACK
block|, }
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

end_unit


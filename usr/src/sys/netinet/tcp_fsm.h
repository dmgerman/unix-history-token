begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tcp_fsm.h	4.7	81/11/24	*/
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
name|TCPS_SYN_RCVD
value|3
end_define

begin_comment
comment|/* have send and received syn */
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
name|TCPS_FIN_WAIT_1
value|5
end_define

begin_comment
comment|/* have closed, sent fin */
end_comment

begin_define
define|#
directive|define
name|TCPS_FIN_WAIT_2
value|6
end_define

begin_comment
comment|/* have closed, fin is acked */
end_comment

begin_define
define|#
directive|define
name|TCPS_TIME_WAIT
value|7
end_define

begin_comment
comment|/* in 2*msl quiet wait after close */
end_comment

begin_define
define|#
directive|define
name|TCPS_CLOSE_WAIT
value|8
end_define

begin_comment
comment|/* rcvd fin, waiting for close */
end_comment

begin_define
define|#
directive|define
name|TCPS_CLOSING
value|9
end_define

begin_comment
comment|/* closed xchd FIN; await FIN ACK */
end_comment

begin_define
define|#
directive|define
name|TCPS_LAST_ACK
value|10
end_define

begin_comment
comment|/* had fin and close; await FIN ACK */
end_comment

begin_define
define|#
directive|define
name|TCPS_HAVERCVDSYN
parameter_list|(
name|s
parameter_list|)
value|((s)>= TCPS_SYN_RCVD)
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
literal|"FIN_WAIT1"
block|,
literal|"FIN_WAIT2"
block|,
literal|"TIME_WAIT"
block|,
literal|"CLOSE_WAIT"
block|,
literal|"CLOSING"
block|,
literal|"LAST_ACK"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


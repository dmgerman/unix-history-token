begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tcp_fsm.h	4.6	81/11/18	*/
end_comment

begin_comment
comment|/*  * TCP FSM state definitions.  *  * This TCP machine has two more states than suggested in RFC 793,  * the extra states being L_SYN_RCVD and RCV_WAIT  *  * EXPLAIN THE EXTRA STATES.  */
end_comment

begin_comment
comment|/*  * States  */
end_comment

begin_define
define|#
directive|define
name|TCP_NSTATES
value|14
end_define

begin_define
define|#
directive|define
name|EFAILEC
value|-1
end_define

begin_comment
comment|/* new state for failure, internally */
end_comment

begin_define
define|#
directive|define
name|SAME
value|0
end_define

begin_comment
comment|/* no state change, internally */
end_comment

begin_define
define|#
directive|define
name|LISTEN
value|1
end_define

begin_comment
comment|/* listening for connection */
end_comment

begin_define
define|#
directive|define
name|SYN_SENT
value|2
end_define

begin_comment
comment|/* active, have sent syn */
end_comment

begin_define
define|#
directive|define
name|SYN_RCVD
value|3
end_define

begin_define
define|#
directive|define
name|L_SYN_RCVD
value|4
end_define

begin_define
define|#
directive|define
name|ESTAB
value|5
end_define

begin_comment
comment|/* established */
end_comment

begin_define
define|#
directive|define
name|FIN_W1
value|6
end_define

begin_comment
comment|/* have closed and sent fin */
end_comment

begin_define
define|#
directive|define
name|FIN_W2
value|7
end_define

begin_comment
comment|/* have closed and rcvd ack of fin */
end_comment

begin_define
define|#
directive|define
name|TIME_WAIT
value|8
end_define

begin_comment
comment|/* in 2*msl quiet wait after close */
end_comment

begin_define
define|#
directive|define
name|CLOSE_WAIT
value|9
end_define

begin_comment
comment|/* rcvd fin, waiting for close */
end_comment

begin_define
define|#
directive|define
name|CLOSING
value|10
end_define

begin_comment
comment|/* closed xchd FIN; await FIN ACK */
end_comment

begin_define
define|#
directive|define
name|LAST_ACK
value|11
end_define

begin_comment
comment|/* had fin and close; await FIN ACK */
end_comment

begin_define
define|#
directive|define
name|RCV_WAIT
value|12
end_define

begin_comment
comment|/* waiting for user to drain data */
end_comment

begin_define
define|#
directive|define
name|CLOSED
value|13
end_define

begin_comment
comment|/* closed */
end_comment

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
literal|"SAME"
block|,
literal|"LISTEN"
block|,
literal|"SYN_SENT"
block|,
literal|"SYN_RCVD"
block|,
literal|"L_SYN_RCVD"
block|,
literal|"ESTAB"
block|,
literal|"FIN_W1"
block|,
literal|"FIN_W2"
block|,
literal|"TIME_WAIT"
block|,
literal|"CLOSE_WAIT"
block|,
literal|"CLOSING"
block|,
literal|"LAST_ACK"
block|,
literal|"RCV_WAIT"
block|,
literal|"CLOSED"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tcptimers
index|[]
init|=
block|{
literal|"INIT"
block|,
literal|"REXMT"
block|,
literal|"REXMTTL"
block|,
literal|"PERSIST"
block|,
literal|"FINACK"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


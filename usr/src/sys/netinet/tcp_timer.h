begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tcp_timer.h	4.1	81/11/29	*/
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
name|TCPT_2MSL
value|1
end_define

begin_comment
comment|/* 2*msl quiet time timer */
end_comment

begin_define
define|#
directive|define
name|TCPT_PERSIST
value|2
end_define

begin_comment
comment|/* retransmit persistance */
end_comment

begin_define
define|#
directive|define
name|TCPT_KEEP
value|3
end_define

begin_comment
comment|/* keep alive */
end_comment

begin_define
define|#
directive|define
name|TCP_TTL
value|60
end_define

begin_comment
comment|/* time to live for TCP segs */
end_comment

begin_comment
comment|/*  * TCPSC constants give various timeouts in ``slow-clock'' ticks.  */
end_comment

begin_define
define|#
directive|define
name|TCPSC_MSL
value|(120*PR_SLOWHZ)
end_define

begin_comment
comment|/* max seg lifetime */
end_comment

begin_define
define|#
directive|define
name|TCPSC_REXMT
value|(  1*PR_SLOWHZ)
end_define

begin_comment
comment|/* base retransmit time */
end_comment

begin_define
define|#
directive|define
name|TCPSC_KEEP
value|(240*PR_SLOWHZ)
end_define

begin_comment
comment|/* keep alive */
end_comment

begin_define
define|#
directive|define
name|TCPSC_PERSIST
value|(  5*PR_SLOWHZ)
end_define

begin_comment
comment|/* retransmit persistance */
end_comment

begin_define
define|#
directive|define
name|TCPSC_KEEPTTL
value|(  4*TCPSC_KEEP)
end_define

begin_comment
comment|/* keep alive too long */
end_comment

begin_define
define|#
directive|define
name|TCPSC_2MSL
value|(  2*TCPSC_MSL)
end_define

begin_comment
comment|/* 2*msl quiet time timer */
end_comment

begin_define
define|#
directive|define
name|TCPSC_TOOLONG
value|(480*PR_SLOWHZ)
end_define

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
literal|"INIT"
block|,
literal|"REXMT"
block|,
literal|"REXMTTL"
block|,
literal|"KEEP"
block|,
literal|"KEEPTTL"
block|,
literal|"PERSIST"
block|,
literal|"2MSL"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fsm.h 1.4 81/10/29 */
end_comment

begin_comment
comment|/*  * TCP FSM definitions.  */
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
comment|/* pseudo-state for internal use */
end_comment

begin_define
define|#
directive|define
name|SAME
value|0
end_define

begin_define
define|#
directive|define
name|LISTEN
value|1
end_define

begin_define
define|#
directive|define
name|SYN_SENT
value|2
end_define

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

begin_define
define|#
directive|define
name|FIN_W1
value|6
end_define

begin_define
define|#
directive|define
name|FIN_W2
value|7
end_define

begin_define
define|#
directive|define
name|TIME_WAIT
value|8
end_define

begin_define
define|#
directive|define
name|CLOSE_WAIT
value|9
end_define

begin_define
define|#
directive|define
name|CLOSING1
value|10
end_define

begin_define
define|#
directive|define
name|CLOSING2
value|11
end_define

begin_define
define|#
directive|define
name|RCV_WAIT
value|12
end_define

begin_define
define|#
directive|define
name|CLOSED
value|13
end_define

begin_comment
comment|/*  * Inputs to fsm.  */
end_comment

begin_define
define|#
directive|define
name|TCP_NINPUTS
value|10
end_define

begin_define
define|#
directive|define
name|IUOPENA
value|1
end_define

begin_define
define|#
directive|define
name|INRECV
value|2
end_define

begin_define
define|#
directive|define
name|IUOPENR
value|3
end_define

begin_define
define|#
directive|define
name|IUCLOSE
value|4
end_define

begin_define
define|#
directive|define
name|ISTIMER
value|5
end_define

begin_define
define|#
directive|define
name|IURECV
value|6
end_define

begin_define
define|#
directive|define
name|IUSEND
value|7
end_define

begin_define
define|#
directive|define
name|IUABORT
value|8
end_define

begin_define
define|#
directive|define
name|INCLEAR
value|9
end_define

begin_define
define|#
directive|define
name|INSEND
value|10
end_define

begin_comment
comment|/*  * Actions  */
end_comment

begin_define
define|#
directive|define
name|BAD
value|0
end_define

begin_define
define|#
directive|define
name|LIS_CLS
value|1
end_define

begin_define
define|#
directive|define
name|LIS_NETR
value|2
end_define

begin_define
define|#
directive|define
name|SYR_NETR
value|3
end_define

begin_define
define|#
directive|define
name|SYS_CLS
value|4
end_define

begin_define
define|#
directive|define
name|SYS_NETR
value|5
end_define

begin_define
define|#
directive|define
name|CLS_OPN
value|6
end_define

begin_define
define|#
directive|define
name|EST_NETR
value|7
end_define

begin_define
define|#
directive|define
name|CL2_CLW
value|8
end_define

begin_define
define|#
directive|define
name|TIMERS
value|9
end_define

begin_define
define|#
directive|define
name|CL1_NETR
value|10
end_define

begin_define
define|#
directive|define
name|CL2_NETR
value|11
end_define

begin_define
define|#
directive|define
name|CLS_RWT
value|12
end_define

begin_define
define|#
directive|define
name|RWT_NETR
value|13
end_define

begin_define
define|#
directive|define
name|FW1_SYR
value|14
end_define

begin_define
define|#
directive|define
name|FW1_NETR
value|15
end_define

begin_define
define|#
directive|define
name|FW2_NETR
value|16
end_define

begin_define
define|#
directive|define
name|CWT_NETR
value|17
end_define

begin_define
define|#
directive|define
name|SSS_SYN
value|18
end_define

begin_define
define|#
directive|define
name|SSS_SND
value|19
end_define

begin_define
define|#
directive|define
name|SSS_RCV
value|20
end_define

begin_define
define|#
directive|define
name|CLS_NSY
value|21
end_define

begin_define
define|#
directive|define
name|CLS_SYN
value|22
end_define

begin_define
define|#
directive|define
name|CLS_ACT
value|23
end_define

begin_define
define|#
directive|define
name|NOP
value|24
end_define

begin_define
define|#
directive|define
name|CLS_ERR
value|25
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|acounts
index|[
literal|14
index|]
index|[
literal|10
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
name|TCPFSTAB
end_ifdef

begin_comment
comment|/* SHOULD FIGURE OUT HOW TO MAKE THIS READABLE! */
end_comment

begin_decl_stmt
name|char
name|tcp_fstab
index|[
name|TCP_NSTATES
index|]
index|[
name|TCP_NINPUTS
index|]
init|=
block|{
block|{
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|4
block|,
literal|0
block|,
literal|24
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|24
block|}
block|,
comment|/* CLOSED */
block|{
literal|0
block|,
literal|0
block|,
literal|2
block|,
literal|0
block|,
literal|6
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|21
block|,
literal|23
block|}
block|,
comment|/* LISTEN */
block|{
literal|0
block|,
literal|0
block|,
literal|5
block|,
literal|0
block|,
literal|6
block|,
literal|9
block|,
literal|0
block|,
literal|0
block|,
literal|21
block|,
literal|23
block|, }
block|,
comment|/* SYN_SENT */
block|{
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|14
block|,
literal|9
block|,
literal|0
block|,
literal|0
block|,
literal|21
block|,
literal|23
block|, }
block|,
comment|/* SYN_RCVD */
block|{
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|14
block|,
literal|9
block|,
literal|0
block|,
literal|0
block|,
literal|21
block|,
literal|23
block|, }
block|,
comment|/* L_SYN_RCVD */
block|{
literal|0
block|,
literal|0
block|,
literal|7
block|,
literal|0
block|,
literal|14
block|,
literal|9
block|,
literal|20
block|,
literal|19
block|,
literal|22
block|,
literal|23
block|, }
block|,
comment|/* ESTAB */
block|{
literal|0
block|,
literal|0
block|,
literal|15
block|,
literal|0
block|,
literal|24
block|,
literal|9
block|,
literal|20
block|,
literal|25
block|,
literal|22
block|,
literal|23
block|, }
block|,
comment|/* FIN_WAIT_1 */
block|{
literal|0
block|,
literal|0
block|,
literal|16
block|,
literal|0
block|,
literal|24
block|,
literal|9
block|,
literal|20
block|,
literal|24
block|,
literal|22
block|,
literal|23
block|, }
block|,
comment|/* FIN_WAIT_2 */
block|{
literal|0
block|,
literal|0
block|,
literal|18
block|,
literal|0
block|,
literal|24
block|,
literal|9
block|,
literal|20
block|,
literal|25
block|,
literal|22
block|,
literal|23
block|, }
block|,
comment|/* TIME_WAIT */
block|{
literal|0
block|,
literal|0
block|,
literal|17
block|,
literal|0
block|,
literal|8
block|,
literal|9
block|,
literal|20
block|,
literal|19
block|,
literal|22
block|,
literal|23
block|, }
block|,
comment|/* CLOSE_WAIT */
block|{
literal|0
block|,
literal|0
block|,
literal|10
block|,
literal|0
block|,
literal|25
block|,
literal|9
block|,
literal|20
block|,
literal|25
block|,
literal|22
block|,
literal|23
block|, }
block|,
comment|/* CLOSING_1 */
block|{
literal|0
block|,
literal|0
block|,
literal|11
block|,
literal|0
block|,
literal|25
block|,
literal|9
block|,
literal|20
block|,
literal|25
block|,
literal|22
block|,
literal|23
block|, }
block|,
comment|/* CLOSING_2 */
block|{
literal|0
block|,
literal|0
block|,
literal|13
block|,
literal|0
block|,
literal|25
block|,
literal|9
block|,
literal|12
block|,
literal|25
block|,
literal|22
block|,
literal|23
block|, }
block|,
comment|/* RCV_WAIT */
block|{
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|4
block|,
literal|0
block|,
literal|24
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|24
block|}
comment|/* CLOSED */
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
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|acounts
index|[
name|TCP_NSTATES
index|]
index|[
name|TCP_NINPUTS
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
literal|"CLOSING1"
block|,
literal|"CLOSING2"
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
name|tcpinputs
index|[]
init|=
block|{
literal|"BAD"
block|,
literal|"UOPENA"
block|,
literal|"NRECV"
block|,
literal|"UOPENR"
block|,
literal|"UCLOSE"
block|,
literal|"STIMER"
block|,
literal|"URECV"
block|,
literal|"USEND"
block|,
literal|"UABORT"
block|,
literal|"NCLEAR"
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
literal|""
block|,
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

begin_define
define|#
directive|define
name|TINIT
value|1
end_define

begin_define
define|#
directive|define
name|TREXMT
value|2
end_define

begin_define
define|#
directive|define
name|TREXMTTL
value|3
end_define

begin_define
define|#
directive|define
name|TPERSIST
value|4
end_define

begin_define
define|#
directive|define
name|TFINACK
value|5
end_define

end_unit


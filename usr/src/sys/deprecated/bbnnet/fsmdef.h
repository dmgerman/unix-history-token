begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: fsmdef.h,v 1.4 85/06/18 14:28:45 walsh Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRPT
end_ifndef

begin_decl_stmt
name|char
name|fstab
index|[
name|TCP_NSTATES
index|]
index|[
name|INOP
index|]
init|=
block|{
block|{
comment|/* STATE CLOSED */
comment|/* unused X unused */
literal|0
block|,
comment|/* CLOSED X from U:OPEN(await) */
literal|1
block|,
comment|/* CLOSED X from N:RECEIVE(response) */
literal|0
block|,
comment|/* CLOSED X from U:OPEN(request) */
literal|4
block|,
comment|/* user may close a socket after socket() or bind() */
comment|/* CLOSED X from U:CLOSE(request) */
literal|6
block|,
comment|/* was 0 in 4.1 */
comment|/* CLOSED X from S:TIMER(response) */
literal|24
block|,
comment|/* CLOSED X from U:RECEIVE(request) */
literal|0
block|,
comment|/* CLOSED X from U:SEND(normal) */
literal|0
block|,
comment|/* CLOSED X from U:ABORT(request) */
literal|0
block|,
comment|/* CLOSED X from N:CLEAR(indication) */
literal|24
block|, }
block|,
comment|/* STATE CLOSED */
comment|/* STATE LISTEN */
block|{
comment|/* LISTEN X unused */
literal|0
block|,
comment|/* LISTEN X from U:OPEN(await) */
literal|0
block|,
comment|/* LISTEN X from N:RECEIVE(response) */
literal|2
block|,
comment|/* LISTEN X from U:OPEN(request) */
literal|0
block|,
comment|/* LISTEN X from U:CLOSE(request) */
literal|6
block|,
comment|/* LISTEN X from S:TIMER(response) */
literal|9
block|,
comment|/* LISTEN X from U:RECEIVE(request) */
literal|24
block|,
comment|/* LISTEN X from U:SEND(normal) */
literal|24
block|,
comment|/* LISTEN X from U:ABORT(request) */
literal|21
block|,
comment|/* LISTEN X from N:CLEAR(indication) */
literal|23
block|,       }
block|,
comment|/* STATE LISTEN */
comment|/* STATE SYN_SENT */
block|{
comment|/* SYN_SENT X unused */
literal|0
block|,
comment|/* SYN_SENT X from U:OPEN(await) */
literal|0
block|,
comment|/* SYN_SENT X from N:RECEIVE(response) */
literal|5
block|,
comment|/* SYN_SENT X from U:OPEN(request) */
literal|0
block|,
comment|/* SYN_SENT X from U:CLOSE(request) */
literal|6
block|,
comment|/* SYN_SENT X from S:TIMER(response) */
literal|9
block|,
comment|/* SYN_SENT X from U:RECEIVE(request) */
literal|24
block|,
comment|/* SYN_SENT X from U:SEND(normal) */
literal|19
block|,
comment|/* was 24 in 4.1 */
comment|/* SYN_SENT X from U:ABORT(request) */
literal|21
block|,
comment|/* SYN_SENT X from N:CLEAR(indication) */
literal|23
block|, }
block|,
comment|/* STATE SYN_SENT */
comment|/* STATE SYN_RCVD */
block|{
comment|/* SYN_RCVD X unused */
literal|0
block|,
comment|/* SYN_RCVD X from U:OPEN(await) */
literal|0
block|,
comment|/* SYN_RCVD X from N:RECEIVE(response) */
literal|3
block|,
comment|/* SYN_RCVD X from U:OPEN(request) */
literal|0
block|,
comment|/* SYN_RCVD X from U:CLOSE(request) */
literal|14
block|,
comment|/* SYN_RCVD X from S:TIMER(response) */
literal|9
block|,
comment|/* SYN_RCVD X from U:RECEIVE(request) */
literal|24
block|,
comment|/* SYN_RCVD X from U:SEND(normal) */
literal|24
block|,
comment|/* SYN_RCVD X from U:ABORT(request) */
literal|21
block|,
comment|/* SYN_RCVD X from N:CLEAR(indication) */
literal|23
block|,     }
block|,
comment|/* STATE SYN_RCVD */
comment|/* STATE L_SYN_RCVD */
block|{
comment|/* L_SYN_RCVD X unused */
literal|0
block|,
comment|/* L_SYN_RCVD X from U:OPEN(await) */
literal|0
block|,
comment|/* L_SYN_RCVD X from N:RECEIVE(response) */
literal|3
block|,
comment|/* L_SYN_RCVD X from U:OPEN(request) */
literal|0
block|,
comment|/* L_SYN_RCVD X from U:CLOSE(request) */
literal|14
block|,
comment|/* L_SYN_RCVD X from S:TIMER(response) */
literal|9
block|,
comment|/* L_SYN_RCVD X from U:RECEIVE(request) */
literal|24
block|,
comment|/* L_SYN_RCVD X from U:SEND(normal) */
literal|24
block|,
comment|/* L_SYN_RCVD X from U:ABORT(request) */
literal|21
block|,
comment|/* L_SYN_RCVD X from N:CLEAR(indication) */
literal|23
block|,  }
block|,
comment|/* STATE L_SYN_RCVD */
comment|/* STATE ESTAB */
block|{
comment|/* ESTAB X unused */
literal|0
block|,
comment|/* ESTAB X from U:OPEN(await) */
literal|0
block|,
comment|/* ESTAB X from N:RECEIVE(response) */
literal|7
block|,
comment|/* ESTAB X from U:OPEN(request) */
literal|0
block|,
comment|/* ESTAB X from U:CLOSE(request) */
literal|14
block|,
comment|/* ESTAB X from S:TIMER(response) */
literal|9
block|,
comment|/* ESTAB X from U:RECEIVE(request) */
literal|20
block|,
comment|/* ESTAB X from U:SEND(normal) */
literal|19
block|,
comment|/* ESTAB X from U:ABORT(request) */
literal|22
block|,
comment|/* ESTAB X from N:CLEAR(indication) */
literal|23
block|, }
block|,
comment|/* STATE ESTAB */
comment|/* STATE FIN_WAIT_1 */
block|{
comment|/* FIN_WAIT_1 X unused */
literal|0
block|,
comment|/* FIN_WAIT_1 X from U:OPEN(await) */
literal|0
block|,
comment|/* FIN_WAIT_1 X from N:RECEIVE(response) */
literal|15
block|,
comment|/* FIN_WAIT_1 X from U:OPEN(request) */
literal|0
block|,
comment|/* FIN_WAIT_1 X from U:CLOSE(request) */
literal|24
block|,
comment|/* FIN_WAIT_1 X from S:TIMER(response) */
literal|9
block|,
comment|/* FIN_WAIT_1 X from U:RECEIVE(request) */
literal|20
block|,
comment|/* FIN_WAIT_1 X from U:SEND(normal) */
literal|25
block|,
comment|/* FIN_WAIT_1 X from U:ABORT(request) */
literal|22
block|,
comment|/* FIN_WAIT_1 X from N:CLEAR(indication) */
literal|23
block|,       }
block|,
comment|/* STATE FIN_WAIT_1 */
comment|/* STATE FIN_WAIT_2 */
block|{
comment|/* FIN_WAIT_2 X unused */
literal|0
block|,
comment|/* FIN_WAIT_2 X from U:OPEN(await) */
literal|0
block|,
comment|/* FIN_WAIT_2 X from N:RECEIVE(response) */
literal|16
block|,
comment|/* FIN_WAIT_2 X from U:OPEN(request) */
literal|0
block|,
comment|/* FIN_WAIT_2 X from U:CLOSE(request) */
literal|24
block|,
comment|/* FIN_WAIT_2 X from S:TIMER(response) */
literal|9
block|,
comment|/* FIN_WAIT_2 X from U:RECEIVE(request) */
literal|20
block|,
comment|/* FIN_WAIT_2 X from U:SEND(normal) */
literal|24
block|,
comment|/* FIN_WAIT_2 X from U:ABORT(request) */
literal|22
block|,
comment|/* FIN_WAIT_2 X from N:CLEAR(indication) */
literal|23
block|,    }
block|,
comment|/* STATE FIN_WAIT_2 */
comment|/* STATE TIME_WAIT */
block|{
comment|/* TIME_WAIT X unused */
literal|0
block|,
comment|/* TIME_WAIT X from U:OPEN(await) */
literal|0
block|,
comment|/* TIME_WAIT X from N:RECEIVE(response) */
literal|18
block|,
comment|/* TIME_WAIT X from U:OPEN(request) */
literal|0
block|,
comment|/* TIME_WAIT X from U:CLOSE(request) */
literal|24
block|,
comment|/* TIME_WAIT X from S:TIMER(response) */
literal|9
block|,
comment|/* TIME_WAIT X from U:RECEIVE(request) */
literal|20
block|,
comment|/* TIME_WAIT X from U:SEND(normal) */
literal|25
block|,
comment|/* TIME_WAIT X from U:ABORT(request) */
literal|22
block|,
comment|/* TIME_WAIT X from N:CLEAR(indication) */
literal|23
block|,   }
block|,
comment|/* STATE TIME_WAIT */
comment|/* STATE CLOSE_WAIT */
block|{
comment|/* CLOSE_WAIT X unused */
literal|0
block|,
comment|/* CLOSE_WAIT X from U:OPEN(await) */
literal|0
block|,
comment|/* CLOSE_WAIT X from N:RECEIVE(response) */
literal|17
block|,
comment|/* CLOSE_WAIT X from U:OPEN(request) */
literal|0
block|,
comment|/* CLOSE_WAIT X from U:CLOSE(request) */
literal|8
block|,
comment|/* CLOSE_WAIT X from S:TIMER(response) */
literal|9
block|,
comment|/* CLOSE_WAIT X from U:RECEIVE(request) */
literal|20
block|,
comment|/* CLOSE_WAIT X from U:SEND(normal) */
literal|19
block|,
comment|/* CLOSE_WAIT X from U:ABORT(request) */
literal|22
block|,
comment|/* CLOSE_WAIT X from N:CLEAR(indication) */
literal|23
block|,   }
block|,
comment|/* STATE CLOSE_WAIT */
comment|/* STATE CLOSING_1 */
block|{
comment|/* CLOSING_1 X unused */
literal|0
block|,
comment|/* CLOSING_1 X from U:OPEN(await) */
literal|0
block|,
comment|/* CLOSING_1 X from N:RECEIVE(response) */
literal|10
block|,
comment|/* CLOSING_1 X from U:OPEN(request) */
literal|0
block|,
comment|/* CLOSING_1 X from U:CLOSE(request) */
literal|25
block|,
comment|/* CLOSING_1 X from S:TIMER(response) */
literal|9
block|,
comment|/* CLOSING_1 X from U:RECEIVE(request) */
literal|20
block|,
comment|/* CLOSING_1 X from U:SEND(normal) */
literal|25
block|,
comment|/* CLOSING_1 X from U:ABORT(request) */
literal|22
block|,
comment|/* CLOSING_1 X from N:CLEAR(indication) */
literal|23
block|,   }
block|,
comment|/* STATE CLOSING_1 */
comment|/* STATE CLOSING_2 */
block|{
comment|/* CLOSING_2 X unused */
literal|0
block|,
comment|/* CLOSING_2 X from U:OPEN(await) */
literal|0
block|,
comment|/* CLOSING_2 X from N:RECEIVE(response) */
literal|11
block|,
comment|/* CLOSING_2 X from U:OPEN(request) */
literal|0
block|,
comment|/* CLOSING_2 X from U:CLOSE(request) */
literal|25
block|,
comment|/* CLOSING_2 X from S:TIMER(response) */
literal|9
block|,
comment|/* CLOSING_2 X from U:RECEIVE(request) */
literal|20
block|,
comment|/* CLOSING_2 X from U:SEND(normal) */
literal|25
block|,
comment|/* CLOSING_2 X from U:ABORT(request) */
literal|22
block|,
comment|/* CLOSING_2 X from N:CLEAR(indication) */
literal|23
block|,   }
block|,
comment|/* STATE CLOSING_2 */
comment|/* STATE RCV_WAIT */
block|{
comment|/* RCV_WAIT X unused */
literal|0
block|,
comment|/* RCV_WAIT X from U:OPEN(await) */
literal|0
block|,
comment|/* RCV_WAIT X from N:RECEIVE(response) */
literal|13
block|,
comment|/* RCV_WAIT X from U:OPEN(request) */
literal|0
block|,
comment|/* RCV_WAIT X from U:CLOSE(request) */
literal|25
block|,
comment|/* RCV_WAIT X from S:TIMER(response) */
literal|9
block|,
comment|/* RCV_WAIT X from U:RECEIVE(request) */
literal|12
block|,
comment|/* RCV_WAIT X from U:SEND(normal) */
literal|25
block|,
comment|/* RCV_WAIT X from U:ABORT(request) */
literal|22
block|,
comment|/* RCV_WAIT X from N:CLEAR(indication) */
literal|23
block|,   }
block|,
comment|/* STATE RCV_WAIT */
comment|/* STATE CLOSED */
block|{
comment|/* CLOSED X unused */
literal|0
block|,
comment|/* CLOSED X from U:OPEN(await) */
literal|1
block|,
comment|/* CLOSED X from N:RECEIVE(response) */
literal|0
block|,
comment|/* CLOSED X from U:OPEN(request) */
literal|4
block|,
comment|/* CLOSED X from U:CLOSE(request) */
literal|0
block|,
comment|/* CLOSED X from S:TIMER(response) */
literal|24
block|,
comment|/* CLOSED X from U:RECEIVE(request) */
literal|0
block|,
comment|/* CLOSED X from U:SEND(normal) */
literal|0
block|,
comment|/* CLOSED X from U:ABORT(request) */
literal|0
block|,
comment|/* CLOSED X from N:CLEAR(indication) */
literal|24
block|}
comment|/* STATE CLOSED */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|null
parameter_list|()
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function_decl
name|int
name|lis_cls
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lis_netr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syr_netr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sys_cls
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sys_netr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cls_opn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|est_netr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cl2_clw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|timers
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cl1_netr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cl2_netr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cls_rwt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rwt_netr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fw1_syr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fw1_netr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fw2_netr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cwt_netr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sss_syn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sss_snd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sss_rcv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cls_nsy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cls_syn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cls_act
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cls_err
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|fsactab
index|[]
function_decl|)
parameter_list|()
init|=
block|{
comment|/* 0 */
name|null
operator|,
comment|/* 1 */
function_decl|lis_cls
operator|,
comment|/* 1 */
comment|/* 2 */
function_decl|lis_netr
operator|,
comment|/* 3,4 */
comment|/* 3 */
function_decl|syr_netr
operator|,
comment|/* 5,33 */
comment|/* 4 */
function_decl|sys_cls
operator|,
comment|/* 6 */
comment|/* 5 */
function_decl|sys_netr
operator|,
comment|/* 8,9,11,32 */
comment|/* 6 */
function_decl|cls_opn
operator|,
comment|/* 10 */
comment|/* 7 */
function_decl|est_netr
operator|,
comment|/* 12,39 */
comment|/* 8 */
function_decl|cl2_clw
operator|,
comment|/* 13 */
comment|/* 9 */
function_decl|timers
operator|,
comment|/* 14,17,35,36,37,38 */
comment|/* 10 */
function_decl|cl1_netr
operator|,
comment|/* 15,18,22,23,30,39 */
comment|/* 11 */
function_decl|cl2_netr
operator|,
comment|/* 16,19,31,39 */
comment|/* 12 */
function_decl|cls_rwt
operator|,
comment|/* 20 */
comment|/* 13 */
function_decl|rwt_netr
operator|,
comment|/* 21,30 */
comment|/* 14 */
function_decl|fw1_syr
operator|,
comment|/* 24 */
comment|/* 15 */
function_decl|fw1_netr
operator|,
comment|/* 26,27,28,39 */
comment|/* 16 */
function_decl|fw2_netr
operator|,
comment|/* 29,39 */
comment|/* 17 */
function_decl|cwt_netr
operator|,
comment|/* 30,31,39 */
comment|/* 18 */
function_decl|sss_syn
operator|,
comment|/* 39 */
comment|/* 19 */
function_decl|sss_snd
operator|,
comment|/* 40,41 */
comment|/* 20 */
function_decl|sss_rcv
operator|,
comment|/* 42 */
comment|/* 21 */
function_decl|cls_nsy
operator|,
comment|/* 44 */
comment|/* 22 */
function_decl|cls_syn
operator|,
comment|/* 45 */
comment|/* 23 */
function_decl|cls_act
operator|,
comment|/* 47 ### this& INCLEAR unused on 4.2 */
comment|/* 24 */
function_decl|null
operator|,
comment|/* 25 */
function_decl|cls_err
end_function_decl

begin_endif
unit|};
endif|#
directive|endif
endif|TRPT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TCPDEBUG
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
literal|"TIMER"
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
block|,
literal|"DELACK"
block|,
literal|"NOACT"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|TCPDEBUG
end_endif

end_unit


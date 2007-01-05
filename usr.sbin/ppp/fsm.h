begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  State of machine  */
end_comment

begin_define
define|#
directive|define
name|ST_INITIAL
value|0
end_define

begin_define
define|#
directive|define
name|ST_STARTING
value|1
end_define

begin_define
define|#
directive|define
name|ST_CLOSED
value|2
end_define

begin_define
define|#
directive|define
name|ST_STOPPED
value|3
end_define

begin_define
define|#
directive|define
name|ST_CLOSING
value|4
end_define

begin_define
define|#
directive|define
name|ST_STOPPING
value|5
end_define

begin_define
define|#
directive|define
name|ST_REQSENT
value|6
end_define

begin_define
define|#
directive|define
name|ST_ACKRCVD
value|7
end_define

begin_define
define|#
directive|define
name|ST_ACKSENT
value|8
end_define

begin_define
define|#
directive|define
name|ST_OPENED
value|9
end_define

begin_define
define|#
directive|define
name|ST_MAX
value|10
end_define

begin_define
define|#
directive|define
name|ST_UNDEF
value|-1
end_define

begin_define
define|#
directive|define
name|MODE_REQ
value|0
end_define

begin_define
define|#
directive|define
name|MODE_NAK
value|1
end_define

begin_define
define|#
directive|define
name|MODE_REJ
value|2
end_define

begin_define
define|#
directive|define
name|MODE_NOP
value|3
end_define

begin_define
define|#
directive|define
name|MODE_ACK
value|4
end_define

begin_comment
comment|/* pseudo mode for ccp negotiations */
end_comment

begin_define
define|#
directive|define
name|OPEN_PASSIVE
value|-1
end_define

begin_define
define|#
directive|define
name|FSM_REQ_TIMER
value|1
end_define

begin_define
define|#
directive|define
name|FSM_TRM_TIMER
value|2
end_define

begin_define
define|#
directive|define
name|FSM_OPTLEN
value|100
end_define

begin_struct_decl
struct_decl|struct
name|fsm
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|fsm_retry
block|{
name|u_int
name|timeout
decl_stmt|;
comment|/* FSM retry frequency */
name|u_int
name|maxreq
decl_stmt|;
comment|/* Max Config REQ retries */
name|u_int
name|maxtrm
decl_stmt|;
comment|/* Max Term REQ retries */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsm_decode
block|{
name|u_char
name|ack
index|[
name|FSM_OPTLEN
index|]
decl_stmt|,
modifier|*
name|ackend
decl_stmt|;
name|u_char
name|nak
index|[
name|FSM_OPTLEN
index|]
decl_stmt|,
modifier|*
name|nakend
decl_stmt|;
name|u_char
name|rej
index|[
name|FSM_OPTLEN
index|]
decl_stmt|,
modifier|*
name|rejend
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsm_callbacks
block|{
name|int
function_decl|(
modifier|*
name|LayerUp
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
comment|/* Layer is now up (tlu) */
name|void
function_decl|(
modifier|*
name|LayerDown
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
comment|/* About to come down (tld) */
name|void
function_decl|(
modifier|*
name|LayerStart
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
comment|/* Layer about to start (tls) */
name|void
function_decl|(
modifier|*
name|LayerFinish
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
comment|/* Layer now down (tlf) */
name|void
function_decl|(
modifier|*
name|InitRestartCounter
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Set fsm timer load */
name|void
function_decl|(
modifier|*
name|SendConfigReq
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
comment|/* Send REQ please */
name|void
function_decl|(
modifier|*
name|SentTerminateReq
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
comment|/* Term REQ just sent */
name|void
function_decl|(
modifier|*
name|SendTerminateAck
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
comment|/* Send Term ACK please */
name|void
function_decl|(
modifier|*
name|DecodeConfig
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|fsm_decode
modifier|*
parameter_list|)
function_decl|;
comment|/* Deal with incoming data */
name|int
function_decl|(
modifier|*
name|RecvResetReq
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
name|fp
parameter_list|)
function_decl|;
comment|/* Reset output */
name|void
function_decl|(
modifier|*
name|RecvResetAck
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
name|fp
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
comment|/* Reset input */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsm_parent
block|{
name|void
function_decl|(
modifier|*
name|LayerStart
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
comment|/* tls */
name|void
function_decl|(
modifier|*
name|LayerUp
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
comment|/* tlu */
name|void
function_decl|(
modifier|*
name|LayerDown
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
comment|/* tld */
name|void
function_decl|(
modifier|*
name|LayerFinish
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
comment|/* tlf */
name|void
modifier|*
name|object
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|link
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|fsm
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of protocol */
name|u_short
name|proto
decl_stmt|;
comment|/* Protocol number */
name|u_short
name|min_code
decl_stmt|;
name|u_short
name|max_code
decl_stmt|;
name|int
name|open_mode
decl_stmt|;
comment|/* Delay before config REQ (-1 forever) */
name|unsigned
name|state
decl_stmt|;
comment|/* State of the machine */
name|u_char
name|reqid
decl_stmt|;
comment|/* Next request id */
name|int
name|restart
decl_stmt|;
comment|/* Restart counter value */
struct|struct
block|{
name|int
name|reqs
decl_stmt|;
comment|/* Max config REQs before a close() */
name|int
name|naks
decl_stmt|;
comment|/* Max config NAKs before a close() */
name|int
name|rejs
decl_stmt|;
comment|/* Max config REJs before a close() */
block|}
name|more
struct|;
name|struct
name|pppTimer
name|FsmTimer
decl_stmt|;
comment|/* Restart Timer */
name|struct
name|pppTimer
name|OpenTimer
decl_stmt|;
comment|/* Delay before opening */
comment|/*    * This timer times the ST_STOPPED state out after the given value    * (specified via "set stopped ...").  Although this isn't specified in the    * rfc, the rfc *does* say that "the application may use higher level    * timers to avoid deadlock". The StoppedTimer takes effect when the other    * side ABENDs rather than going into ST_ACKSENT (and sending the ACK),    * causing ppp to time out and drop into ST_STOPPED.  At this point,    * nothing will change this state :-(    */
name|struct
name|pppTimer
name|StoppedTimer
decl_stmt|;
name|int
name|LogLevel
decl_stmt|;
comment|/* The link layer active with this FSM (may be our bundle below) */
name|struct
name|link
modifier|*
name|link
decl_stmt|;
comment|/* Our high-level link */
name|struct
name|bundle
modifier|*
name|bundle
decl_stmt|;
specifier|const
name|struct
name|fsm_parent
modifier|*
name|parent
decl_stmt|;
specifier|const
name|struct
name|fsm_callbacks
modifier|*
name|fn
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsmheader
block|{
name|u_char
name|code
decl_stmt|;
comment|/* Request code */
name|u_char
name|id
decl_stmt|;
comment|/* Identification */
name|u_short
name|length
decl_stmt|;
comment|/* Length of packet */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CODE_CONFIGREQ
value|1
end_define

begin_define
define|#
directive|define
name|CODE_CONFIGACK
value|2
end_define

begin_define
define|#
directive|define
name|CODE_CONFIGNAK
value|3
end_define

begin_define
define|#
directive|define
name|CODE_CONFIGREJ
value|4
end_define

begin_define
define|#
directive|define
name|CODE_TERMREQ
value|5
end_define

begin_define
define|#
directive|define
name|CODE_TERMACK
value|6
end_define

begin_define
define|#
directive|define
name|CODE_CODEREJ
value|7
end_define

begin_define
define|#
directive|define
name|CODE_PROTOREJ
value|8
end_define

begin_define
define|#
directive|define
name|CODE_ECHOREQ
value|9
end_define

begin_comment
comment|/* Used in LCP */
end_comment

begin_define
define|#
directive|define
name|CODE_ECHOREP
value|10
end_define

begin_comment
comment|/* Used in LCP */
end_comment

begin_define
define|#
directive|define
name|CODE_DISCREQ
value|11
end_define

begin_define
define|#
directive|define
name|CODE_IDENT
value|12
end_define

begin_comment
comment|/* Used in LCP Extension */
end_comment

begin_define
define|#
directive|define
name|CODE_TIMEREM
value|13
end_define

begin_comment
comment|/* Used in LCP Extension */
end_comment

begin_define
define|#
directive|define
name|CODE_RESETREQ
value|14
end_define

begin_comment
comment|/* Used in CCP */
end_comment

begin_define
define|#
directive|define
name|CODE_RESETACK
value|15
end_define

begin_comment
comment|/* Used in CCP */
end_comment

begin_struct
struct|struct
name|fsm_opt_hdr
block|{
name|u_char
name|id
decl_stmt|;
name|u_char
name|len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_FSM_OPT_LEN
value|52
end_define

begin_struct
struct|struct
name|fsm_opt
block|{
name|struct
name|fsm_opt_hdr
name|hdr
decl_stmt|;
name|u_char
name|data
index|[
name|MAX_FSM_OPT_LEN
operator|-
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INC_FSM_OPT
parameter_list|(
name|ty
parameter_list|,
name|length
parameter_list|,
name|o
parameter_list|)
define|\
value|do {                                                  \     (o)->hdr.id = (ty);                                 \     (o)->hdr.len = (length);                            \     (o) = (struct fsm_opt *)((u_char *)(o) + (length)); \   } while (0)
end_define

begin_decl_stmt
specifier|extern
name|void
name|fsm_Init
argument_list|(
expr|struct
name|fsm
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|u_short
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
expr|struct
name|bundle
operator|*
argument_list|,
expr|struct
name|link
operator|*
argument_list|,
specifier|const
expr|struct
name|fsm_parent
operator|*
argument_list|,
expr|struct
name|fsm_callbacks
operator|*
argument_list|,
specifier|const
name|char
operator|*
specifier|const
index|[
literal|3
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|fsm_Output
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_Open
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_Up
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_Down
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_Input
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_Close
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fsm_NullRecvResetReq
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_NullRecvResetAck
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_Reopen
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm2initial
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|State2Nam
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|fsm_opt
modifier|*
name|fsm_readopt
parameter_list|(
name|u_char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_rej
parameter_list|(
name|struct
name|fsm_decode
modifier|*
parameter_list|,
specifier|const
name|struct
name|fsm_opt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_ack
parameter_list|(
name|struct
name|fsm_decode
modifier|*
parameter_list|,
specifier|const
name|struct
name|fsm_opt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_nak
parameter_list|(
name|struct
name|fsm_decode
modifier|*
parameter_list|,
specifier|const
name|struct
name|fsm_opt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fsm_opt_normalise
parameter_list|(
name|struct
name|fsm_decode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit


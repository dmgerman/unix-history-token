begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: fsm.h,v 1.14 1998/01/10 01:55:10 brian Exp $  *  *	TODO:  */
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
name|max_code
decl_stmt|;
name|int
name|open_mode
decl_stmt|;
name|int
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
name|int
name|maxconfig
decl_stmt|;
name|int
name|reqcode
decl_stmt|;
comment|/* Request code sent */
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
name|void
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
name|void
function_decl|(
modifier|*
name|InitRestartCounter
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
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
name|void
function_decl|(
modifier|*
name|SendTerminateReq
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|SendTerminateAck
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|DecodeConfig
function_decl|)
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
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
name|fsmcodedesc
block|{
name|void
function_decl|(
modifier|*
name|action
function_decl|)
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|,
name|struct
name|fsmheader
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsmconfig
block|{
name|u_char
name|type
decl_stmt|;
name|u_char
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|u_char
name|AckBuff
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|NakBuff
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|RejBuff
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|ReqBuff
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
name|ackp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
name|nakp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
name|rejp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|StateNames
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|FsmInit
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
name|FsmOutput
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|FsmOpen
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
name|FsmUp
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
name|FsmDown
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
name|FsmInput
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
name|FsmClose
parameter_list|(
name|struct
name|fsm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit


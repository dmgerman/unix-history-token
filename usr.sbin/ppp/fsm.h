begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FSM_H_
end_ifndef

begin_define
define|#
directive|define
name|_FSM_H_
end_define

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|"timeout.h"
end_include

begin_include
include|#
directive|include
file|"cdefs.h"
end_include

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
name|OPEN_ACTIVE
value|0
end_define

begin_define
define|#
directive|define
name|OPEN_PASSIVE
value|1
end_define

begin_struct
struct|struct
name|fsm
block|{
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
name|int
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
name|void
argument_list|(
argument|*LayerUp
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*LayerDown
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*LayerStart
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*LayerFinish
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*InitRestartCounter
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*SendConfigReq
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*SendTerminateReq
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*SendTerminateAck
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*DecodeConfig
argument_list|)
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
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
argument_list|(
argument|*action
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|,
expr|struct
name|fsmheader
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
expr_stmt|;
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
name|u_char
name|AckBuff
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|NakBuff
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|RejBuff
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|ReqBuff
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
modifier|*
name|ackp
decl_stmt|,
modifier|*
name|nakp
decl_stmt|,
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

begin_decl_stmt
specifier|extern
name|void
name|FsmInit
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|NewState
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmOutput
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmOpen
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmUp
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmDown
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmInput
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmRecvConfigReq
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|,
expr|struct
name|fsmheader
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmRecvConfigAck
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|,
expr|struct
name|fsmheader
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmRecvConfigNak
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|,
expr|struct
name|fsmheader
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmRecvTermReq
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|,
expr|struct
name|fsmheader
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmRecvTermAck
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
operator|,
expr|struct
name|fsmheader
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|FsmClose
name|__P
argument_list|(
operator|(
expr|struct
name|fsm
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fsm
name|LcpFsm
decl_stmt|,
name|IpcpFsm
decl_stmt|,
name|CcpFsm
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FSM_H_ */
end_comment

end_unit


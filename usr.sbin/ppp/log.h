begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOG_H_
end_define

begin_include
include|#
directive|include
file|"cdefs.h"
end_include

begin_comment
comment|/*  *  Definition of log level  */
end_comment

begin_define
define|#
directive|define
name|LOG_PHASE
value|0
end_define

begin_define
define|#
directive|define
name|LM_PHASE
value|"Phase"
end_define

begin_define
define|#
directive|define
name|LOG_CHAT
value|1
end_define

begin_define
define|#
directive|define
name|LM_CHAT
value|"Chat"
end_define

begin_define
define|#
directive|define
name|LOG_LQM
value|2
end_define

begin_define
define|#
directive|define
name|LM_LQM
value|"LQM"
end_define

begin_define
define|#
directive|define
name|LOG_LCP
value|3
end_define

begin_define
define|#
directive|define
name|LM_LCP
value|"LCP"
end_define

begin_define
define|#
directive|define
name|LOG_TCPIP
value|4
end_define

begin_define
define|#
directive|define
name|LM_TCPIP
value|"TCP/IP"
end_define

begin_define
define|#
directive|define
name|LOG_HDLC
value|5
end_define

begin_define
define|#
directive|define
name|LM_HDLC
value|"HDLC"
end_define

begin_define
define|#
directive|define
name|LOG_ASYNC
value|6
end_define

begin_define
define|#
directive|define
name|LM_ASYNC
value|"Async"
end_define

begin_define
define|#
directive|define
name|MAXLOGLEVEL
value|7
end_define

begin_decl_stmt
specifier|extern
name|int
name|loglevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|LogTimeStamp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|LogOpen
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DupLog
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|LogClose
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|logprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|,
name|LogPrintf
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|LogDumpBp
name|__P
argument_list|(
operator|(
name|int
name|level
operator|,
name|char
operator|*
name|header
operator|,
expr|struct
name|mbuf
operator|*
name|bp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|LogDumpBuff
name|__P
argument_list|(
operator|(
name|int
name|level
operator|,
name|char
operator|*
name|header
operator|,
name|u_char
operator|*
name|ptr
operator|,
name|int
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ListLog
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


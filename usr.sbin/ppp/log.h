begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id:$  *  *	TODO:  */
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

begin_function_decl
specifier|extern
name|void
name|LogTimeStamp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|LogOpen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DupLog
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogClose
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|logprintf
argument_list|()
decl_stmt|,
name|LogPrintf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|LogDumpBp
parameter_list|(
name|int
name|level
parameter_list|,
name|char
modifier|*
name|header
parameter_list|,
name|struct
name|mbuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogDumpBuff
parameter_list|(
name|int
name|level
parameter_list|,
name|char
modifier|*
name|header
parameter_list|,
name|u_char
modifier|*
name|ptr
parameter_list|,
name|int
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id$  */
end_comment

begin_define
define|#
directive|define
name|LogMIN
value|(1)
end_define

begin_define
define|#
directive|define
name|LogASYNC
value|(1)
end_define

begin_comment
comment|/* syslog(LOG_INFO, ....)	 */
end_comment

begin_define
define|#
directive|define
name|LogCARRIER
value|(2)
end_define

begin_define
define|#
directive|define
name|LogCCP
value|(3)
end_define

begin_define
define|#
directive|define
name|LogCHAT
value|(4)
end_define

begin_define
define|#
directive|define
name|LogCOMMAND
value|(5)
end_define

begin_define
define|#
directive|define
name|LogCONNECT
value|(6)
end_define

begin_define
define|#
directive|define
name|LogDEBUG
value|(7)
end_define

begin_comment
comment|/* syslog(LOG_DEBUG, ....)	 */
end_comment

begin_define
define|#
directive|define
name|LogHDLC
value|(8)
end_define

begin_define
define|#
directive|define
name|LogID0
value|(9)
end_define

begin_define
define|#
directive|define
name|LogIPCP
value|(10)
end_define

begin_define
define|#
directive|define
name|LogLCP
value|(11)
end_define

begin_define
define|#
directive|define
name|LogLINK
value|(12)
end_define

begin_define
define|#
directive|define
name|LogLQM
value|(13)
end_define

begin_define
define|#
directive|define
name|LogPHASE
value|(14)
end_define

begin_define
define|#
directive|define
name|LogTCPIP
value|(15)
end_define

begin_define
define|#
directive|define
name|LogTUN
value|(16)
end_define

begin_comment
comment|/* If set, tun%d is output with each message */
end_comment

begin_define
define|#
directive|define
name|LogMAXCONF
value|(16)
end_define

begin_define
define|#
directive|define
name|LogWARN
value|(17)
end_define

begin_comment
comment|/* Sent to VarTerm else syslog(LOG_WARNING, ) */
end_comment

begin_define
define|#
directive|define
name|LogERROR
value|(18)
end_define

begin_comment
comment|/* syslog(LOG_ERR, ....), + sent to VarTerm */
end_comment

begin_define
define|#
directive|define
name|LogALERT
value|(19)
end_define

begin_comment
comment|/* syslog(LOG_ALERT, ....)	 */
end_comment

begin_define
define|#
directive|define
name|LogMAX
value|(19)
end_define

begin_comment
comment|/* The first int arg for all of the following is one of the above values */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|LogName
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogKeep
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogKeepLocal
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogDiscard
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogDiscardLocal
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogDiscardAll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogDiscardAllLocal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LOG_KEPT_SYSLOG
value|(1)
end_define

begin_comment
comment|/* Results of LogIsKept() */
end_comment

begin_define
define|#
directive|define
name|LOG_KEPT_LOCAL
value|(2)
end_define

begin_comment
comment|/* Results of LogIsKept() */
end_comment

begin_function_decl
specifier|extern
name|int
name|LogIsKept
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogOpen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogSetTun
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogClose
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogPrintf
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogDumpBp
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LogDumpBuff
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit


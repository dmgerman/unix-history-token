begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|LogCBCP
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
name|LogDNS
value|(8)
end_define

begin_define
define|#
directive|define
name|LogFILTER
value|(9)
end_define

begin_define
define|#
directive|define
name|LogHDLC
value|(10)
end_define

begin_define
define|#
directive|define
name|LogID0
value|(11)
end_define

begin_define
define|#
directive|define
name|LogIPCP
value|(12)
end_define

begin_define
define|#
directive|define
name|LogLCP
value|(13)
end_define

begin_define
define|#
directive|define
name|LogLQM
value|(14)
end_define

begin_define
define|#
directive|define
name|LogPHASE
value|(15)
end_define

begin_define
define|#
directive|define
name|LogPHYSICAL
value|(16)
end_define

begin_comment
comment|/* syslog(LOG_INFO, ....)	 */
end_comment

begin_define
define|#
directive|define
name|LogSYNC
value|(17)
end_define

begin_comment
comment|/* syslog(LOG_INFO, ....)	 */
end_comment

begin_define
define|#
directive|define
name|LogTCPIP
value|(18)
end_define

begin_define
define|#
directive|define
name|LogTIMER
value|(19)
end_define

begin_comment
comment|/* syslog(LOG_DEBUG, ....)	 */
end_comment

begin_define
define|#
directive|define
name|LogTUN
value|(20)
end_define

begin_comment
comment|/* If set, tun%d is output with each message */
end_comment

begin_define
define|#
directive|define
name|LogWARN
value|(21)
end_define

begin_comment
comment|/* Sent to VarTerm else syslog(LOG_WARNING, ) */
end_comment

begin_define
define|#
directive|define
name|LogERROR
value|(22)
end_define

begin_comment
comment|/* syslog(LOG_ERR, ....), + sent to VarTerm */
end_comment

begin_define
define|#
directive|define
name|LogALERT
value|(23)
end_define

begin_comment
comment|/* syslog(LOG_ALERT, ....)	 */
end_comment

begin_define
define|#
directive|define
name|LogMAXCONF
value|(20)
end_define

begin_define
define|#
directive|define
name|LogMAX
value|(23)
end_define

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|prompt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|server
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|datalink
struct_decl|;
end_struct_decl

begin_comment
comment|/* The first int arg for all of the following is one of the above values */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|log_Name
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_Keep
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_KeepLocal
parameter_list|(
name|int
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_Discard
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_DiscardLocal
parameter_list|(
name|int
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_DiscardAll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_DiscardAllLocal
parameter_list|(
name|u_long
modifier|*
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
comment|/* Results of log_IsKept() */
end_comment

begin_define
define|#
directive|define
name|LOG_KEPT_LOCAL
value|(2)
end_define

begin_comment
comment|/* Results of log_IsKept() */
end_comment

begin_function_decl
specifier|extern
name|int
name|log_IsKept
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|log_IsKeptLocal
parameter_list|(
name|int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_Open
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
name|log_SetTun
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_Close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|log_Printf
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|log_WritePrompts
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|log_Printf
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
name|log_WritePrompts
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|log_DumpBp
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
name|log_DumpBuff
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

begin_function_decl
specifier|extern
name|int
name|log_ShowLevel
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|log_SetLevel
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|log_ShowWho
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|prompt
modifier|*
name|log_PromptContext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|log_PromptListChanged
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|log_RegisterPrompt
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_UnRegisterPrompt
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_DestroyPrompts
parameter_list|(
name|struct
name|server
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_DisplayPrompts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_ActivatePrompt
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_DeactivatePrompt
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_SetTtyCommandMode
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|prompt
modifier|*
name|log_PromptList
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit


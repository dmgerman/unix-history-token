begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: log.h,v 1.14 1997/10/26 01:03:06 brian Exp $  */
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
name|LogIPCP
value|(9)
end_define

begin_define
define|#
directive|define
name|LogLCP
value|(10)
end_define

begin_define
define|#
directive|define
name|LogLINK
value|(11)
end_define

begin_define
define|#
directive|define
name|LogLQM
value|(12)
end_define

begin_define
define|#
directive|define
name|LogPHASE
value|(13)
end_define

begin_define
define|#
directive|define
name|LogTCPIP
value|(14)
end_define

begin_define
define|#
directive|define
name|LogTUN
value|(15)
end_define

begin_comment
comment|/* If set, tun%d is output with each message */
end_comment

begin_define
define|#
directive|define
name|LogMAXCONF
value|(15)
end_define

begin_define
define|#
directive|define
name|LogWARN
value|(16)
end_define

begin_comment
comment|/* Sent to VarTerm else syslog(LOG_WARNING, ) */
end_comment

begin_define
define|#
directive|define
name|LogERROR
value|(17)
end_define

begin_comment
comment|/* syslog(LOG_ERR, ....), + sent to VarTerm */
end_comment

begin_define
define|#
directive|define
name|LogALERT
value|(18)
end_define

begin_comment
comment|/* syslog(LOG_ALERT, ....)	 */
end_comment

begin_define
define|#
directive|define
name|LogMAX
value|(18)
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
name|char
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
name|LogDumpBuff
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit


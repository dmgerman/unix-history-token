begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.17 $ ** **  Here be values used for communicating with the server once it is **  running. */
end_comment

begin_define
define|#
directive|define
name|SC_SEP
value|'\001'
end_define

begin_define
define|#
directive|define
name|SC_MAXFIELDS
value|6
end_define

begin_define
define|#
directive|define
name|SC_ADDHIST
value|'a'
end_define

begin_define
define|#
directive|define
name|SC_ALLOW
value|'D'
end_define

begin_define
define|#
directive|define
name|SC_BEGIN
value|'b'
end_define

begin_define
define|#
directive|define
name|SC_CANCEL
value|'c'
end_define

begin_define
define|#
directive|define
name|SC_CHANGEGROUP
value|'u'
end_define

begin_define
define|#
directive|define
name|SC_CHECKFILE
value|'d'
end_define

begin_define
define|#
directive|define
name|SC_DROP
value|'e'
end_define

begin_define
define|#
directive|define
name|SC_FLUSH
value|'f'
end_define

begin_define
define|#
directive|define
name|SC_FLUSHLOGS
value|'g'
end_define

begin_define
define|#
directive|define
name|SC_GO
value|'h'
end_define

begin_define
define|#
directive|define
name|SC_HANGUP
value|'i'
end_define

begin_define
define|#
directive|define
name|SC_MODE
value|'s'
end_define

begin_define
define|#
directive|define
name|SC_NAME
value|'j'
end_define

begin_define
define|#
directive|define
name|SC_NEWGROUP
value|'k'
end_define

begin_define
define|#
directive|define
name|SC_PARAM
value|'l'
end_define

begin_define
define|#
directive|define
name|SC_PAUSE
value|'m'
end_define

begin_define
define|#
directive|define
name|SC_READERS
value|'v'
end_define

begin_define
define|#
directive|define
name|SC_REFILE
value|'t'
end_define

begin_define
define|#
directive|define
name|SC_REJECT
value|'C'
end_define

begin_define
define|#
directive|define
name|SC_RELOAD
value|'o'
end_define

begin_define
define|#
directive|define
name|SC_RENUMBER
value|'n'
end_define

begin_define
define|#
directive|define
name|SC_RESERVE
value|'z'
end_define

begin_define
define|#
directive|define
name|SC_RMGROUP
value|'p'
end_define

begin_define
define|#
directive|define
name|SC_SEND
value|'A'
end_define

begin_define
define|#
directive|define
name|SC_SHUTDOWN
value|'q'
end_define

begin_define
define|#
directive|define
name|SC_SIGNAL
value|'B'
end_define

begin_define
define|#
directive|define
name|SC_THROTTLE
value|'r'
end_define

begin_define
define|#
directive|define
name|SC_TRACE
value|'w'
end_define

begin_define
define|#
directive|define
name|SC_XABORT
value|'x'
end_define

begin_define
define|#
directive|define
name|SC_XEXEC
value|'y'
end_define

begin_comment
comment|/* Yes, we don't want anyone to use this. */
end_comment

begin_define
define|#
directive|define
name|SC_FIRSTFREE
value|E
end_define

begin_function_decl
specifier|extern
name|void
name|ICCsettimeout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ICCopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ICCclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ICCcommand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ICCcancel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ICCgo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ICCpause
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ICCreserve
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ICCfailure
decl_stmt|;
end_decl_stmt

end_unit


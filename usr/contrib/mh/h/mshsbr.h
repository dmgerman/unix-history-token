begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mshsbr.h - definitions for msh */
end_comment

begin_struct
struct|struct
name|Cmd
block|{
name|char
name|line
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|char
modifier|*
name|args
index|[
name|MAXARGS
index|]
decl_stmt|;
name|char
modifier|*
name|redirect
decl_stmt|;
name|int
name|direction
decl_stmt|;
define|#
directive|define
name|STDIO
value|0
comment|/* regular stdoutput */
define|#
directive|define
name|CRTIO
value|1
comment|/* create  re-direct */
define|#
directive|define
name|APPIO
value|2
comment|/* append  re-direct */
define|#
directive|define
name|PIPIO
value|3
comment|/* pipe    re-direct */
name|FILE
modifier|*
name|stream
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLCMD
value|((struct Cmd *) 0)
end_define

begin_struct
struct|struct
name|Msg
block|{
name|struct
name|drop
name|m_drop
decl_stmt|;
define|#
directive|define
name|m_bboard_id
value|m_drop.d_id
define|#
directive|define
name|m_top
value|m_drop.d_size
define|#
directive|define
name|m_start
value|m_drop.d_start
define|#
directive|define
name|m_stop
value|m_drop.d_stop
name|char
modifier|*
name|m_scanl
decl_stmt|;
name|struct
name|tws
name|m_tb
decl_stmt|;
name|short
name|m_stats
decl_stmt|;
define|#
directive|define
name|CUR
value|(1<< (FFATTRSLOT + NATTRS))
ifdef|#
directive|ifdef
name|BPOP
define|#
directive|define
name|VIRTUAL
value|SELECT_EMPTY
endif|#
directive|endif
endif|BPOP
block|}
struct|;
end_struct

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* FOLDER */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fmsh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* folder instead of file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|modified
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command modified folder */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|msgs
modifier|*
name|mp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used a lot */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Msg
modifier|*
name|Msgs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Msgs[0] not used */
end_comment

begin_function_decl
name|FILE
modifier|*
name|msh_ready
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* COMMAND */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interactive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* running from a /dev/tty */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|redirected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* re-directing output */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|sp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* original stdout */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cmd_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command being run */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|myfilter
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* path to mhl.forward */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|BBoard_ID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BBoard-ID constant */
end_comment

begin_comment
comment|/* SIGNALS */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|istat
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* original SIGINT */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|qstat
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* original SIGQUIT */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interrupted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SIGINT detected */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|broken_pipe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SIGPIPE detected */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|told_to_quit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SIGQUIT detected */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD42
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|should_intr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* signal handler should interrupt call */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|sigenv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the environment pointer */
end_comment

begin_endif
endif|#
directive|endif
endif|BSD42
end_endif

begin_function_decl
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

end_unit


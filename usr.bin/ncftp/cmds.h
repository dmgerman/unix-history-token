begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cmds.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_cmd_h_
end_ifndef

begin_define
define|#
directive|define
name|_cmd_h_
end_define

begin_comment
comment|/*  $RCSfile: cmds.h,v $  *  $Revision: 14020.11 $  *  $Date: 93/07/09 10:58:19 $  */
end_comment

begin_comment
comment|/* Verbosity levels. */
end_comment

begin_define
define|#
directive|define
name|V_QUIET
value|-1
end_define

begin_define
define|#
directive|define
name|V_ERRS
value|0
end_define

begin_define
define|#
directive|define
name|V_TERSE
value|1
end_define

begin_define
define|#
directive|define
name|V_VERBOSE
value|2
end_define

begin_define
define|#
directive|define
name|V_IMPLICITCD
value|4
end_define

begin_define
define|#
directive|define
name|IS_VQUIET
value|(verbose<= V_QUIET)
end_define

begin_define
define|#
directive|define
name|IS_VERRS
value|(verbose == V_ERRS)
end_define

begin_define
define|#
directive|define
name|IS_VTERSE
value|(verbose == V_TERSE)
end_define

begin_define
define|#
directive|define
name|IS_VVERBOSE
value|(verbose == V_VERBOSE)
end_define

begin_define
define|#
directive|define
name|NOT_VQUIET
value|(verbose> V_QUIET)
end_define

begin_comment
comment|/* Open modes. */
end_comment

begin_define
define|#
directive|define
name|OPEN_A
value|1
end_define

begin_define
define|#
directive|define
name|OPEN_U
value|0
end_define

begin_define
define|#
directive|define
name|LS_FLAGS_AND_FILE
value|'\1'
end_define

begin_comment
comment|/* Possible values returned by GetDateAndTime. */
end_comment

begin_define
define|#
directive|define
name|SIZE_UNKNOWN
value|(-1L)
end_define

begin_define
define|#
directive|define
name|MDTM_UNKNOWN
value|(0L)
end_define

begin_comment
comment|/* Command result codes. */
end_comment

begin_define
define|#
directive|define
name|USAGE
value|(88)
end_define

begin_define
define|#
directive|define
name|NOERR
value|(0)
end_define

begin_define
define|#
directive|define
name|CMDERR
value|(-1)
end_define

begin_comment
comment|/*  * Format of command table.  */
end_comment

begin_struct
struct|struct
name|cmd
block|{
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* name of command */
name|char
name|c_conn
decl_stmt|;
comment|/* must be connected to use command */
name|char
name|c_hidden
decl_stmt|;
comment|/* a hidden command or alias (won't show up in help) */
name|int
function_decl|(
modifier|*
name|c_handler
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/* function to call */
name|char
modifier|*
name|c_help
decl_stmt|;
comment|/* help string */
name|char
modifier|*
name|c_usage
decl_stmt|;
comment|/* usage string or NULL, to ask the function itself. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NCMDS
value|((int) ((sizeof (cmdtab) / sizeof (struct cmd)) - 1))
end_define

begin_struct
struct|struct
name|macel
block|{
name|char
name|mac_name
index|[
literal|9
index|]
decl_stmt|;
comment|/* macro name */
name|char
modifier|*
name|mac_start
decl_stmt|;
comment|/* start of macro in macbuf */
name|char
modifier|*
name|mac_end
decl_stmt|;
comment|/* end of macro in macbuf */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|types
block|{
name|char
modifier|*
name|t_name
decl_stmt|;
name|char
modifier|*
name|t_mode
decl_stmt|;
name|int
name|t_type
decl_stmt|;
name|char
modifier|*
name|t_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lslist
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|struct
name|lslist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|settype
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_settype
parameter_list|(
name|char
modifier|*
name|typename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setbinary
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setascii
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|put
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mput
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rem_glob_one
parameter_list|(
name|char
modifier|*
name|pattern
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|mabort
name|SIG_PARAMS
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|mget
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|remglob
parameter_list|(
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setverbose
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setprompt
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setdebug
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fix_options
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|implicit_cd
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_cd
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lcd
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_delete
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mdelete
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|renamefile
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ls
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|shell
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_user
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pwd
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|makedir
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|removedir
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quote
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rmthelp
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quit
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_streams
parameter_list|(
name|int
name|wantShutDown
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|disconnect
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_up_shop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|globulize
parameter_list|(
name|char
modifier|*
modifier|*
name|cpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cdup
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syst
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|make_macro
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|macdef
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|domacro
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sizecmd
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|modtime
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lookup
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rmtstatus
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|create
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getlocalhostname
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|show_version
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PurgeLineBuffer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ShowLineBuffer
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MallocStatusCmd
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unimpl
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|GetDateSizeFromLSLine
parameter_list|(
name|char
modifier|*
name|fName
parameter_list|,
name|unsigned
name|long
modifier|*
name|mod_time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|GetDateAndSize
parameter_list|(
name|char
modifier|*
name|fName
parameter_list|,
name|unsigned
name|long
modifier|*
name|mod_time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|SetTypeByNumber
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PASSIVEMODE
end_ifdef

begin_function_decl
name|int
name|setpassive
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In util.c: */
end_comment

begin_function_decl
name|void
name|cmd_help
parameter_list|(
name|struct
name|cmd
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cmd_usage
parameter_list|(
name|struct
name|cmd
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cmd
modifier|*
name|getcmd
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _cmd_h_ */
end_comment

end_unit


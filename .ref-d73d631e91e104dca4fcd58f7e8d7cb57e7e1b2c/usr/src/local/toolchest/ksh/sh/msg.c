begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)msg.c	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *	S. R. Bourne  *	Rewritten by David Korn  *  *	AT&T Bell Laboratories  *  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_include
include|#
directive|include
file|"name.h"
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"sym.h"
end_include

begin_include
include|#
directive|include
file|"builtins.h"
end_include

begin_include
include|#
directive|include
file|"brkincr.h"
end_include

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_include
include|#
directive|include
file|"timeout.h"
end_include

begin_include
include|#
directive|include
file|"history.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MULTIBYTE
end_ifdef

begin_include
include|#
directive|include
file|"national.h"
end_include

begin_decl_stmt
specifier|const
name|MSG
name|version
init|=
literal|"@(#)Version M-06/03/86a"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|const
name|MSG
name|version
init|=
literal|"@(#)Version 06/03/86a"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIBYTE */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Bfunction
name|randnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Bfunction
name|seconds
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error messages */
end_comment

begin_decl_stmt
specifier|const
name|MSG
name|time_warn
init|=
literal|"\r\n\007shell time out in 60 seconds"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|timed_out
init|=
literal|"timed out waiting for input"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|recursive
init|=
literal|"recursive call"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|noquery
init|=
literal|"no query process"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|nohistory
init|=
literal|"no history file"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|badopt
init|=
literal|"bad option(s)"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|mailmsg
init|=
literal|"you have mail in $_"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|nospace
init|=
literal|"no space"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|synmsg
init|=
literal|"syntax error"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|parexp
init|=
literal|") expected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|argexp
init|=
literal|"argument expected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|endmatch
init|=
literal|"] missing"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|badnum
init|=
literal|"bad number"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|badcooked
init|=
literal|"cannot reset tty to cooked mode"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|badparam
init|=
literal|"parameter null or not set"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|unset
init|=
literal|"parameter not set"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|badsub
init|=
literal|"bad substitution"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|badcreate
init|=
literal|"cannot create"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|restricted
init|=
literal|"restricted"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|nofork
init|=
literal|"cannot fork: too many processes"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|pexists
init|=
literal|"process already exists"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|noswap
init|=
literal|"cannot fork: no swap space"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|piperr
init|=
literal|"cannot make pipe"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|logout
init|=
literal|"Use 'exit' to logout"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|badopen
init|=
literal|"cannot open"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|coredump
init|=
literal|" - core dumped"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|ptrace
init|=
literal|"ptrace: "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|arglist
init|=
literal|"arg list too long"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|txtbsy
init|=
literal|"text busy"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|toobig
init|=
literal|"too big"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|badexec
init|=
literal|"cannot execute"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|pwderr
init|=
literal|"cannot access parent directories"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|notfound
init|=
literal|" not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|nomorefiles
init|=
literal|"too many open files"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ELIBACC
end_ifdef

begin_comment
comment|/* shared library error messages */
end_comment

begin_decl_stmt
specifier|const
name|MSG
name|libacc
init|=
literal|"can't access a needed shared library"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|libbad
init|=
literal|"accessing a corrupted shared library"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|libscn
init|=
literal|".lib section in a.out corrupted"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|libmax
init|=
literal|"attempting to link in too many libs"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELIBACC */
end_comment

begin_decl_stmt
specifier|const
name|MSG
name|badfile
init|=
literal|"bad file unit number"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|baddir
init|=
literal|"bad directory"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|badtrap
init|=
literal|"bad trap"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|wtfailed
init|=
literal|"is read only"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|notid
init|=
literal|"invalid identifier"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|badop
init|=
literal|"unknown test operator"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|noalias
init|=
literal|" alias not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|is_reserved
init|=
literal|" is a reserved word"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|is_builtin
init|=
literal|" is a shell builtin"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|is_alias
init|=
literal|" is an alias for "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|is_function
init|=
literal|" is a function"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|is_xalias
init|=
literal|" is an exported alias for "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|is_talias
init|=
literal|" is a tracked alias for "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|is_xfunction
init|=
literal|" is an exported function"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|is_
init|=
literal|" is "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|on_
init|=
literal|"on"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|off_
init|=
literal|"off"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|divzero
init|=
literal|"division by zero"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|subscript
init|=
literal|"subscript out of range"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|argcount
init|=
literal|"bad argument count"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|fn_hdr
init|=
literal|"\n{\n"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VSH
end_ifdef

begin_decl_stmt
specifier|const
name|MSG
name|big_vi
init|=
literal|"fc -e \"${VISUAL:-${EDITOR:-vi}}\" "
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JOBS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_decl_stmt
specifier|const
name|MSG
name|j_not_tty
init|=
literal|"Warning: no access to tty; thus no job control in this shell...\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_newtty
init|=
literal|"Switching to new tty driver...\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_oldtty
init|=
literal|"Reverting to old tty driver...\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_no_start
init|=
literal|"Cannot start job control\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|MSG
name|j_Done
init|=
literal|" Done"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_amp
init|=
literal|"&\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_cpid
init|=
literal|"|&\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_space
init|=
literal|"|\n      "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_Running
init|=
literal|" Running"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_coredump
init|=
literal|"(coredump)"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_terminate
init|=
literal|"You have stopped jobs\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_running
init|=
literal|"You have running jobs\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_no_job
init|=
literal|"No such job"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_no_proc
init|=
literal|"No such process"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_perm
init|=
literal|"Permission denied"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_kill
init|=
literal|"kill: "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|kill_usage
init|=
literal|"Arguments should be jobs or process ids"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|j_no_jctl
init|=
literal|"No job control"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEVFD
end_ifdef

begin_decl_stmt
specifier|const
name|MSG
name|devfd
init|=
literal|"/dev/fd/"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* string constants */
end_comment

begin_decl_stmt
specifier|const
name|MSG
name|test_opts
init|=
literal|"rwxdcbfugkLpsnzt"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|opt_heading
init|=
literal|"Current option settings"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|nullstr
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|sptbnl
init|=
literal|" \t\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|defpath
init|=
literal|"/bin:/usr/bin:"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|defedit
init|=
literal|"/bin/ed"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|colon
init|=
literal|": "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|minus
init|=
literal|"-"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|endoffile
init|=
literal|"end of file"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|unexpected
init|=
literal|" unexpected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|unmatched
init|=
literal|" unmatched"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|unknown
init|=
literal|"<job name unknown>"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|let_syntax
init|=
literal|"arithmetic expression ending in single ')' "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|atline
init|=
literal|" at line "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|devnull
init|=
literal|"/dev/null"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|execpmsg
init|=
literal|"+ "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|supprompt
init|=
literal|"# "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|stdprompt
init|=
literal|"$ "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|profile
init|=
literal|"${HOME:-.}/.profile"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|sysprofile
init|=
literal|"/etc/profile"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|suid_profile
init|=
literal|"/etc/suid_profile"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_4_2
end_ifdef

begin_decl_stmt
specifier|const
name|MSG
name|prohibited
init|=
literal|"login setuid/setgid shells prohibited"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD_4_2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUID_EXEC
end_ifdef

begin_decl_stmt
specifier|const
name|MSG
name|suid_exec
init|=
literal|"/etc/suid_exec"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|devfdNN
init|=
literal|"/dev/fd/??"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUID_EXEC */
end_comment

begin_decl_stmt
specifier|const
name|MSG
name|histfname
init|=
literal|"/.sh_history"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|unlimited
init|=
literal|"unlimited"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ECHO_N
end_ifdef

begin_decl_stmt
specifier|const
name|MSG
name|echo_bin
init|=
literal|"/bin/echo"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|echo_opt
init|=
literal|"-R"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECHO_N */
end_comment

begin_decl_stmt
specifier|const
name|MSG
name|btest
init|=
literal|"test"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|bkill
init|=
literal|"kill"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|bset
init|=
literal|"set"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|blet
init|=
literal|"let"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|bread
init|=
literal|"read"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|dot
init|=
literal|"."
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|bltfn
init|=
literal|"function "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|intbase
init|=
literal|"base"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|setpwd
init|=
literal|"PWD=`/bin/pwd 2>/dev/null`"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|t_real
init|=
literal|"\nreal"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|t_user
init|=
literal|"user"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MSG
name|t_sys
init|=
literal|"sys"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_define
define|#
directive|define
name|NULL
value|""
end_define

begin_define
define|#
directive|define
name|nullstr
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_comment
comment|/* built in names */
end_comment

begin_decl_stmt
name|struct
name|name_value
name|node_names
index|[]
init|=
block|{
literal|"PATH"
block|,
name|NULL
block|,
literal|"PS1"
block|,
name|NULL
block|,
literal|"PS2"
block|,
literal|"> "
block|,
ifdef|#
directive|ifdef
name|apollo
literal|"IFS"
block|,
literal|" \t\n"
block|,
else|#
directive|else
literal|"IFS"
block|,
name|sptbnl
block|,
endif|#
directive|endif
comment|/* apollo */
literal|"PWD"
block|,
name|NULL
block|,
literal|"HOME"
block|,
name|NULL
block|,
literal|"MAIL"
block|,
name|NULL
block|,
literal|"REPLY"
block|,
name|NULL
block|,
literal|"SHELL"
block|,
literal|"/bin/sh"
block|,
literal|"EDITOR"
block|,
literal|"/bin/ed"
block|,
ifdef|#
directive|ifdef
name|apollo
literal|"MAILCHECK"
block|,
name|NULL
block|,
literal|"RANDOM"
block|,
name|NULL
block|,
else|#
directive|else
literal|"MAILCHECK"
block|,
operator|(
name|char
operator|*
operator|)
operator|(
operator|&
name|mailchk
operator|)
block|,
literal|"RANDOM"
block|,
operator|(
name|char
operator|*
operator|)
operator|(
operator|&
name|randnum
operator|)
block|,
endif|#
directive|endif
comment|/* apollo */
literal|"ENV"
block|,
name|NULL
block|,
literal|"HISTFILE"
block|,
name|NULL
block|,
literal|"HISTSIZE"
block|,
name|NULL
block|,
literal|"FCEDIT"
block|,
literal|"/bin/ed"
block|,
literal|"CDPATH"
block|,
name|NULL
block|,
literal|"MAILPATH"
block|,
name|NULL
block|,
literal|"PS3"
block|,
literal|"#? "
block|,
literal|"OLDPWD"
block|,
name|NULL
block|,
literal|"VISUAL"
block|,
name|NULL
block|,
literal|"COLUMNS"
block|,
name|NULL
block|,
literal|"LINES"
block|,
name|NULL
block|,
ifdef|#
directive|ifdef
name|apollo
literal|"PPID"
block|,
name|NULL
block|,
literal|"_"
block|,
name|NULL
block|,
literal|"TMOUT"
block|,
name|NULL
block|,
literal|"SECONDS"
block|,
name|NULL
block|,
else|#
directive|else
literal|"PPID"
block|,
operator|(
name|char
operator|*
operator|)
operator|(
operator|&
name|ppid
operator|)
block|,
literal|"_"
block|,
operator|(
name|char
operator|*
operator|)
operator|(
operator|&
name|lastarg
operator|)
block|,
literal|"TMOUT"
block|,
operator|(
name|char
operator|*
operator|)
operator|(
operator|&
name|timeout
operator|)
block|,
literal|"SECONDS"
block|,
operator|(
name|char
operator|*
operator|)
operator|(
operator|&
name|seconds
operator|)
block|,
endif|#
directive|endif
comment|/* apollo */
ifdef|#
directive|ifdef
name|ACCT
literal|"SHACCT"
block|,
name|NULL
block|,
endif|#
directive|endif
comment|/* ACCT */
name|nullstr
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* built in aliases - automatically exported */
end_comment

begin_decl_stmt
name|struct
name|name_value
name|alias_names
index|[]
init|=
block|{
literal|"cat"
block|,
literal|"/bin/cat"
block|,
literal|"chmod"
block|,
literal|"/bin/chmod"
block|,
literal|"cc"
block|,
literal|"/bin/cc"
block|,
literal|"cp"
block|,
literal|"/bin/cp"
block|,
literal|"date"
block|,
literal|"/bin/date"
block|,
literal|"ed"
block|,
literal|"/bin/ed"
block|,
literal|"false"
block|,
literal|"let 0"
block|,
literal|"functions"
block|,
literal|"typeset -f"
block|,
ifdef|#
directive|ifdef
name|BSD
literal|"grep"
block|,
literal|"/usr/ucb/grep"
block|,
else|#
directive|else
literal|"grep"
block|,
literal|"/bin/grep"
block|,
endif|#
directive|endif
comment|/* BSD */
literal|"hash"
block|,
literal|"alias -t"
block|,
literal|"history"
block|,
literal|"fc -l"
block|,
literal|"integer"
block|,
literal|"typeset -i"
block|,
literal|"lpr"
block|,
literal|"/usr/bin/lpr"
block|,
literal|"ls"
block|,
literal|"/bin/ls"
block|,
literal|"make"
block|,
literal|"/bin/make"
block|,
literal|"mail"
block|,
literal|"/bin/mail"
block|,
literal|"mv"
block|,
literal|"/bin/mv"
block|,
literal|"nohup"
block|,
literal|"nohup "
block|,
literal|"pr"
block|,
literal|"/bin/pr"
block|,
literal|"r"
block|,
literal|"fc -e -"
block|,
literal|"rm"
block|,
literal|"/bin/rm"
block|,
literal|"sed"
block|,
literal|"/bin/sed"
block|,
literal|"sh"
block|,
literal|"/bin/sh"
block|,
literal|"true"
block|,
literal|":"
block|,
literal|"type"
block|,
literal|"whence -v"
block|,
ifdef|#
directive|ifdef
name|BSD
literal|"vi"
block|,
literal|"/usr/ucb/vi"
block|,
else|#
directive|else
literal|"vi"
block|,
literal|"/usr/bin/vi"
block|,
endif|#
directive|endif
comment|/* BSD */
literal|"who"
block|,
literal|"/bin/who"
block|,
ifdef|#
directive|ifdef
name|JOBS
ifdef|#
directive|ifdef
name|BSD
literal|"suspend"
block|,
literal|"kill -STOP $$"
block|,
endif|#
directive|endif
comment|/* BSD */
endif|#
directive|endif
comment|/* JOBS */
name|nullstr
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tables */
end_comment

begin_decl_stmt
name|SYSTAB
name|reserved
init|=
block|{
block|{
literal|"case"
block|,
name|CASYM
block|}
block|,
block|{
literal|"do"
block|,
name|DOSYM
block|}
block|,
block|{
literal|"done"
block|,
name|ODSYM
block|}
block|,
block|{
literal|"elif"
block|,
name|EFSYM
block|}
block|,
block|{
literal|"else"
block|,
name|ELSYM
block|}
block|,
block|{
literal|"esac"
block|,
name|ESSYM
block|}
block|,
block|{
literal|"fi"
block|,
name|FISYM
block|}
block|,
block|{
literal|"for"
block|,
name|FORSYM
block|}
block|,
block|{
literal|"function"
block|,
name|PROCSYM
block|}
block|,
block|{
literal|"if"
block|,
name|IFSYM
block|}
block|,
block|{
literal|"in"
block|,
name|INSYM
block|}
block|,
block|{
literal|"select"
block|,
name|SELSYM
block|}
block|,
block|{
literal|"then"
block|,
name|THSYM
block|}
block|,
block|{
literal|"time"
block|,
name|TIMSYM
block|}
block|,
block|{
literal|"until"
block|,
name|UNSYM
block|}
block|,
block|{
literal|"while"
block|,
name|WHSYM
block|}
block|,
block|{
literal|"{"
block|,
name|BRSYM
block|}
block|,
block|{
literal|"}"
block|,
name|KTSYM
block|}
block|,
block|{
name|nullstr
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The signal numbers go in the low bits and the attributes go in the high bits  */
end_comment

begin_decl_stmt
name|SYSTAB
name|signal_names
init|=
block|{
block|{
literal|"ALRM"
block|,
operator|(
name|SIGALRM
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGCAUGHT
operator|<<
name|SIGBITS
operator|)
block|}
block|,
block|{
literal|"BUS"
block|,
operator|(
name|SIGBUS
operator|+
literal|1
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGCHLD
block|{
literal|"CHLD"
block|,
operator|(
name|SIGCHLD
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGCHLD */
ifdef|#
directive|ifdef
name|SIGCLD
block|{
literal|"CLD"
block|,
operator|(
name|SIGCLD
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGCLD */
ifdef|#
directive|ifdef
name|SIGCONT
block|{
literal|"CONT"
block|,
operator|(
name|SIGCONT
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGCONT */
block|{
literal|"EMT"
block|,
operator|(
name|SIGEMT
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"ERR"
block|,
operator|(
name|MAXTRAP
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGIGNORE
operator|<<
name|SIGBITS
operator|)
block|}
block|,
block|{
literal|"EXIT"
block|,
literal|1
operator||
operator|(
name|SIGIGNORE
operator|<<
name|SIGBITS
operator|)
block|}
block|,
block|{
literal|"FPE"
block|,
operator|(
name|SIGFPE
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"HUP"
block|,
operator|(
name|SIGHUP
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"ILL"
block|,
operator|(
name|SIGILL
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
block|{
literal|"INT"
block|,
operator|(
name|SIGINT
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGCAUGHT
operator|<<
name|SIGBITS
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGIO
block|{
literal|"IO"
block|,
operator|(
name|SIGIO
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGIO */
block|{
literal|"IOT"
block|,
operator|(
name|SIGIOT
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"KILL"
block|,
operator|(
name|SIGKILL
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGIGNORE
operator|<<
name|SIGBITS
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGPHONE
block|{
literal|"PHONE"
block|,
operator|(
name|SIGPHONE
operator|+
literal|1
operator|)
operator||
operator|(
operator|(
name|SIGNOSET
operator||
name|SIGCAUGHT
operator|)
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGPHONE */
block|{
literal|"PIPE"
block|,
operator|(
name|SIGPIPE
operator|+
literal|1
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGPOLL
block|{
literal|"POLL"
block|,
operator|(
name|SIGPOLL
operator|+
literal|1
operator|)
operator||
operator|(
operator|(
name|SIGNOSET
operator||
name|SIGCAUGHT
operator|)
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGPOLL */
ifdef|#
directive|ifdef
name|SIGPROF
block|{
literal|"PROF"
block|,
operator|(
name|SIGPROF
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGPROF */
ifdef|#
directive|ifdef
name|SIGPWR
if|#
directive|if
name|SIGPWR
operator|>
literal|0
block|{
literal|"PWR"
block|,
operator|(
name|SIGPWR
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
endif|#
directive|endif
comment|/* SIGPWR */
block|{
literal|"QUIT"
block|,
operator|(
name|SIGQUIT
operator|+
literal|1
operator|)
operator||
operator|(
operator|(
name|SIGNOSET
operator||
name|SIGCAUGHT
operator|)
operator|<<
name|SIGBITS
operator|)
block|}
block|,
block|{
literal|"SEGV"
block|,
operator|(
name|SIGSEGV
operator|+
literal|1
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGSTOP
block|{
literal|"STOP"
block|,
operator|(
name|SIGSTOP
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGSTOP */
block|{
literal|"SYS"
block|,
operator|(
name|SIGSYS
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
block|{
literal|"TERM"
block|,
operator|(
name|SIGTERM
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGCAUGHT
operator|<<
name|SIGBITS
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGTINT
block|{
literal|"TINT"
block|,
operator|(
name|SIGTINT
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGTINT */
block|{
literal|"TRAP"
block|,
operator|(
name|SIGTRAP
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGTSTP
block|{
literal|"TSTP"
block|,
operator|(
name|SIGTSTP
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGTSTP */
ifdef|#
directive|ifdef
name|SIGTTIN
block|{
literal|"TTIN"
block|,
operator|(
name|SIGTTIN
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGTTIN */
ifdef|#
directive|ifdef
name|SIGTTOU
block|{
literal|"TTOU"
block|,
operator|(
name|SIGTTOU
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGTTOU */
ifdef|#
directive|ifdef
name|SIGURG
block|{
literal|"URG"
block|,
operator|(
name|SIGURG
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGURG */
ifdef|#
directive|ifdef
name|SIGUSR1
block|{
literal|"USR1"
block|,
operator|(
name|SIGUSR1
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGUSR1 */
ifdef|#
directive|ifdef
name|SIGUSR2
block|{
literal|"USR2"
block|,
operator|(
name|SIGUSR2
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGUSR2 */
ifdef|#
directive|ifdef
name|SIGVTALRM
block|{
literal|"VTALRM"
block|,
operator|(
name|SIGVTALRM
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGVTALRM */
ifdef|#
directive|ifdef
name|SIGWINCH
block|{
literal|"WINCH"
block|,
operator|(
name|SIGWINCH
operator|+
literal|1
operator|)
operator||
operator|(
operator|(
name|SIGNOSET
operator||
name|SIGCAUGHT
operator|)
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGWINCH */
ifdef|#
directive|ifdef
name|SIGWIND
block|{
literal|"WIND"
block|,
operator|(
name|SIGWIND
operator|+
literal|1
operator|)
operator||
operator|(
operator|(
name|SIGNOSET
operator||
name|SIGCAUGHT
operator|)
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGWIND */
ifdef|#
directive|ifdef
name|SIGXCPU
block|{
literal|"XCPU"
block|,
operator|(
name|SIGXCPU
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGXCPU */
ifdef|#
directive|ifdef
name|SIGXFSZ
block|{
literal|"XFSZ"
block|,
operator|(
name|SIGXFSZ
operator|+
literal|1
operator|)
operator||
operator|(
name|SIGNOSET
operator|<<
name|SIGBITS
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGXFSZ */
block|{
name|nullstr
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYSTAB
name|sig_messages
init|=
block|{
block|{
literal|"Alarm call"
block|,
operator|(
name|SIGALRM
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"Bus error"
block|,
operator|(
name|SIGBUS
operator|+
literal|1
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGCHLD
block|{
literal|"Child stopped or terminated"
block|,
operator|(
name|SIGCHLD
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGCHLD */
ifdef|#
directive|ifdef
name|SIGCLD
block|{
literal|"Death of Child"
block|,
operator|(
name|SIGCLD
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGCLD */
ifdef|#
directive|ifdef
name|SIGCONT
block|{
literal|"Stopped process continued"
block|,
operator|(
name|SIGCONT
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGCONT */
block|{
literal|"EMT trap"
block|,
operator|(
name|SIGEMT
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"Floating exception"
block|,
operator|(
name|SIGFPE
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"Hangup"
block|,
operator|(
name|SIGHUP
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"Illegal instruction"
block|,
operator|(
name|SIGILL
operator|+
literal|1
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|JOBS
block|{
literal|"Interrupt"
block|,
operator|(
name|SIGINT
operator|+
literal|1
operator|)
block|}
block|,
else|#
directive|else
block|{
name|nullstr
block|,
operator|(
name|SIGINT
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* JOBS */
ifdef|#
directive|ifdef
name|SIGIO
block|{
literal|"IO signal"
block|,
operator|(
name|SIGIO
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGIO */
block|{
literal|"abort"
block|,
operator|(
name|SIGIOT
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"Killed"
block|,
operator|(
name|SIGKILL
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"Quit"
block|,
operator|(
name|SIGQUIT
operator|+
literal|1
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|JOBS
block|{
literal|"Broken Pipe"
block|,
operator|(
name|SIGPIPE
operator|+
literal|1
operator|)
block|}
block|,
else|#
directive|else
block|{
name|nullstr
block|,
operator|(
name|SIGPIPE
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* JOBS */
ifdef|#
directive|ifdef
name|SIGPROF
block|{
literal|"Profiling time alarm"
block|,
operator|(
name|SIGPROF
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGPROF */
ifdef|#
directive|ifdef
name|SIGPWR
if|#
directive|if
name|SIGPWR
operator|>
literal|0
block|{
literal|"Power fail"
block|,
operator|(
name|SIGPWR
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
endif|#
directive|endif
comment|/* SIGPWR */
block|{
literal|"Memory fault"
block|,
operator|(
name|SIGSEGV
operator|+
literal|1
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGSTOP
block|{
literal|"Stopped (signal)"
block|,
operator|(
name|SIGSTOP
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGSTOP */
block|{
literal|"Bad system call"
block|,
operator|(
name|SIGSYS
operator|+
literal|1
operator|)
block|}
block|,
block|{
literal|"Terminated"
block|,
operator|(
name|SIGTERM
operator|+
literal|1
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGTINT
ifdef|#
directive|ifdef
name|JOBS
block|{
literal|"Interrupt"
block|,
operator|(
name|SIGTINT
operator|+
literal|1
operator|)
block|}
block|,
else|#
directive|else
block|{
name|nullstr
block|,
operator|(
name|SIGTINT
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* JOBS */
endif|#
directive|endif
comment|/* SIGTINT */
block|{
literal|"Trace/BPT trap"
block|,
operator|(
name|SIGTRAP
operator|+
literal|1
operator|)
block|}
block|,
ifdef|#
directive|ifdef
name|SIGTSTP
block|{
literal|"Stopped"
block|,
operator|(
name|SIGTSTP
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGTSTP */
ifdef|#
directive|ifdef
name|SIGTTIN
block|{
literal|"Stopped (tty input)"
block|,
operator|(
name|SIGTTIN
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGTTIN */
ifdef|#
directive|ifdef
name|SIGTTOU
block|{
literal|"Stopped(tty output)"
block|,
operator|(
name|SIGTTOU
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGTTOU */
ifdef|#
directive|ifdef
name|SIGURG
block|{
literal|"Socket interrupt"
block|,
operator|(
name|SIGURG
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGURG */
ifdef|#
directive|ifdef
name|SIGUSR1
block|{
literal|"User signal 1"
block|,
operator|(
name|SIGUSR1
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGUSR1 */
ifdef|#
directive|ifdef
name|SIGUSR2
block|{
literal|"User signal 2"
block|,
operator|(
name|SIGUSR2
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGUSR2 */
ifdef|#
directive|ifdef
name|SIGVTALRM
block|{
literal|"Virtual time alarm"
block|,
operator|(
name|SIGVTALRM
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGVTALRM */
ifdef|#
directive|ifdef
name|SIGWINCH
block|{
literal|"Window size change"
block|,
operator|(
name|SIGWINCH
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGWINCH */
ifdef|#
directive|ifdef
name|SIGXCPU
block|{
literal|"Exceeded CPU time limit"
block|,
operator|(
name|SIGXCPU
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGXCPU */
ifdef|#
directive|ifdef
name|SIGXFSZ
block|{
literal|"Exceeded file size limit"
block|,
operator|(
name|SIGXFSZ
operator|+
literal|1
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* SIGXFSZ */
block|{
name|nullstr
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYSTAB
name|option_flags
init|=
block|{
block|{
literal|"allexport"
block|,
name|Allexp
block|}
block|,
block|{
literal|"bgnice"
block|,
name|Bgnice
block|}
block|,
block|{
literal|"emacs"
block|,
name|Emacs
block|}
block|,
block|{
literal|"errexit"
block|,
name|Errflg
block|}
block|,
block|{
literal|"gmacs"
block|,
name|Gmacs
block|}
block|,
block|{
literal|"ignoreeof"
block|,
name|Noeof
block|}
block|,
ifdef|#
directive|ifdef
name|apollo
block|{
literal|"inprocess"
block|,
name|Inproc
block|}
block|,
endif|#
directive|endif
comment|/* apollo */
block|{
literal|"interactive"
block|,
name|Intflg
block|}
block|,
block|{
literal|"keyword"
block|,
name|Keyflg
block|}
block|,
block|{
literal|"markdirs"
block|,
name|Markdir
block|}
block|,
block|{
literal|"monitor"
block|,
name|Monitor
block|}
block|,
block|{
literal|"noexec"
block|,
name|Noexec
block|}
block|,
block|{
literal|"noglob"
block|,
name|Noglob
block|}
block|,
block|{
literal|"nounset"
block|,
name|Noset
block|}
block|,
block|{
literal|"protected"
block|,
name|Privmod
block|}
block|,
block|{
literal|"restricted"
block|,
name|Rshflg
block|}
block|,
block|{
literal|"trackall"
block|,
name|Hashall
block|}
block|,
block|{
literal|"verbose"
block|,
name|Readpr
block|}
block|,
block|{
literal|"vi"
block|,
name|Editvi
block|}
block|,
block|{
literal|"viraw"
block|,
name|Viraw
block|}
block|,
block|{
literal|"xtrace"
block|,
name|Execpr
block|}
block|,
block|{
name|nullstr
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|apollo
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|limit_names
index|[]
init|=
block|{
literal|"time(seconds)   "
block|,
literal|"memory(kbytes)  "
block|,
literal|"data(kbytes)    "
block|,
literal|"stack(kbytes)   "
block|,
literal|"file(blocks)    "
block|,
literal|"coredump(blocks)"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_decl_stmt
name|SYSTAB
name|commands
init|=
block|{
block|{
literal|"."
block|,
name|SYSDOT
block|}
block|,
block|{
literal|":"
block|,
name|SYSNULL
block|}
block|,
block|{
literal|"["
block|,
name|SYSTEST
block|}
block|,
block|{
literal|"alias"
block|,
name|SYSALIAS
block|}
block|,
ifdef|#
directive|ifdef
name|JOBS
if|#
directive|if
name|BSD
operator|||
name|SXT
block|{
literal|"bg"
block|,
name|SYSBG
block|}
block|,
endif|#
directive|endif
comment|/* BSD */
endif|#
directive|endif
comment|/* JOBS */
block|{
literal|"break"
block|,
name|SYSBREAK
block|}
block|,
block|{
literal|"cd"
block|,
name|SYSCD
block|}
block|,
block|{
literal|"continue"
block|,
name|SYSCONT
block|}
block|,
block|{
literal|"echo"
block|,
name|SYSECHO
block|}
block|,
block|{
literal|"exec"
block|,
name|SYSEXEC
block|}
block|,
block|{
literal|"exit"
block|,
name|SYSEXIT
block|}
block|,
block|{
literal|"export"
block|,
name|SYSXPORT
block|}
block|,
block|{
literal|"eval"
block|,
name|SYSEVAL
block|}
block|,
block|{
literal|"fc"
block|,
name|SYSFC
block|}
block|,
ifdef|#
directive|ifdef
name|JOBS
if|#
directive|if
name|BSD
operator|||
name|SXT
block|{
literal|"fg"
block|,
name|SYSFG
block|}
block|,
endif|#
directive|endif
comment|/* BSD */
endif|#
directive|endif
comment|/* JOBS */
ifdef|#
directive|ifdef
name|apollo
block|{
literal|"inlib"
block|,
name|SYSINLIB
block|}
block|,
block|{
literal|"inprocess"
block|,
name|SYSINPROCESS
block|}
block|,
endif|#
directive|endif
comment|/* apollo */
ifdef|#
directive|ifdef
name|JOBS
block|{
literal|"jobs"
block|,
name|SYSJOBS
block|}
block|,
block|{
literal|"kill"
block|,
name|SYSKILL
block|}
block|,
endif|#
directive|endif
comment|/* JOBS */
block|{
literal|"let"
block|,
name|SYSLET
block|}
block|,
block|{
literal|"login"
block|,
name|SYSLOGIN
block|}
block|,
ifndef|#
directive|ifndef
name|BSD
block|{
literal|"newgrp"
block|,
name|SYSLOGIN
block|}
block|,
endif|#
directive|endif
comment|/* BSD */
block|{
literal|"print"
block|,
name|SYSPRINT
block|}
block|,
block|{
literal|"pwd"
block|,
name|SYSPWD
block|}
block|,
block|{
literal|"read"
block|,
name|SYSREAD
block|}
block|,
block|{
literal|"readonly"
block|,
name|SYSRDONLY
block|}
block|,
block|{
literal|"return"
block|,
name|SYSRETURN
block|}
block|,
block|{
literal|"set"
block|,
name|SYSSET
block|}
block|,
block|{
literal|"shift"
block|,
name|SYSSHFT
block|}
block|,
block|{
literal|"test"
block|,
name|SYSTEST
block|}
block|,
block|{
literal|"times"
block|,
name|SYSTIMES
block|}
block|,
block|{
literal|"trap"
block|,
name|SYSTRAP
block|}
block|,
block|{
literal|"typeset"
block|,
name|SYSTYPESET
block|}
block|,
block|{
literal|"ulimit"
block|,
name|SYSULIMIT
block|}
block|,
block|{
literal|"umask"
block|,
name|SYSUMASK
block|}
block|,
block|{
literal|"unalias"
block|,
name|SYSUNALIAS
block|}
block|,
block|{
literal|"unset"
block|,
name|SYSUNSET
block|}
block|,
block|{
literal|"wait"
block|,
name|SYSWAIT
block|}
block|,
block|{
literal|"whence"
block|,
name|SYSWHENCE
block|}
block|,
block|{
name|nullstr
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYSTAB
name|testops
init|=
block|{
block|{
literal|"!="
block|,
name|TEST_SNE
block|}
block|,
block|{
literal|"-a"
block|,
name|TEST_AND
block|}
block|,
block|{
literal|"-ef"
block|,
name|TEST_EF
block|}
block|,
block|{
literal|"-eq"
block|,
name|TEST_EQ
block|}
block|,
block|{
literal|"-ge"
block|,
name|TEST_GE
block|}
block|,
block|{
literal|"-gt"
block|,
name|TEST_GT
block|}
block|,
block|{
literal|"-le"
block|,
name|TEST_LE
block|}
block|,
block|{
literal|"-lt"
block|,
name|TEST_LT
block|}
block|,
block|{
literal|"-ne"
block|,
name|TEST_NE
block|}
block|,
block|{
literal|"-nt"
block|,
name|TEST_NT
block|}
block|,
block|{
literal|"-o"
block|,
name|TEST_OR
block|}
block|,
block|{
literal|"-ot"
block|,
name|TEST_OT
block|}
block|,
block|{
literal|"="
block|,
name|TEST_SEQ
block|}
block|,
block|{
name|nullstr
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYSTAB
name|attributes
init|=
block|{
block|{
literal|"export"
block|,
name|N_EXPORT
block|}
block|,
block|{
literal|"readonly"
block|,
name|N_RDONLY
block|}
block|,
block|{
literal|"tagged"
block|,
name|T_FORM
block|}
block|,
ifdef|#
directive|ifdef
name|apollo
block|{
literal|" filename"
block|,
name|A_FLAG
block|}
block|,
endif|#
directive|endif
comment|/* apollo */
block|{
literal|"long"
block|,
operator|(
name|L_FLAG
operator||
name|INT_GER
operator|)
block|}
block|,
block|{
literal|"unsigned"
block|,
operator|(
name|UN_SIGN
operator||
name|INT_GER
operator|)
block|}
block|,
block|{
literal|"function"
block|,
operator|(
name|BLT_NOD
operator||
name|INT_GER
operator|)
block|}
block|,
block|{
literal|"integer"
block|,
name|INT_GER
block|}
block|,
block|{
literal|"lowercase"
block|,
name|U_TO_L
block|}
block|,
block|{
literal|"zerofill"
block|,
name|Z_FILL
block|}
block|,
block|{
literal|"leftjust"
block|,
name|L_JUST
block|}
block|,
block|{
literal|"rightjust"
block|,
name|R_JUST
block|}
block|,
block|{
literal|"uppercase"
block|,
name|L_TO_U
block|}
block|,
block|{
name|nullstr
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_decl_stmt
name|int
name|tty_speeds
index|[]
init|=
block|{
literal|0
block|,
literal|50
block|,
literal|75
block|,
literal|110
block|,
literal|134
block|,
literal|150
block|,
literal|200
block|,
literal|300
block|,
literal|600
block|,
literal|1200
block|,
literal|1800
block|,
literal|2400
block|,
literal|9600
block|,
literal|19200
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MULTIBYTE
end_ifdef

begin_decl_stmt
name|char
name|int_charsize
index|[]
init|=
block|{
literal|1
block|,
name|CCS1_IN_SIZE
block|,
name|CCS2_IN_SIZE
block|,
name|CCS3_IN_SIZE
block|,
comment|/* input sizes */
literal|1
block|,
name|CCS1_OUT_SIZE
block|,
name|CCS2_OUT_SIZE
block|,
name|CCS3_OUT_SIZE
comment|/* output widths */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIBYTE */
end_comment

end_unit


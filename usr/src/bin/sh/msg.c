begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)msg.c	4.5 1/11/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	UNIX shell  *  *	S. R. Bourne  *	Bell Telephone Laboratories  *  */
end_comment

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

begin_decl_stmt
name|MSG
name|version
init|=
literal|"\nVERSION sys137	DATE 1978 Nov 6 14:29:22\n"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error messages */
end_comment

begin_decl_stmt
name|MSG
name|badopt
init|=
literal|"bad option(s)"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|mailmsg
init|=
literal|"you have mail\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|nospace
init|=
literal|"no space"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|synmsg
init|=
literal|"syntax error"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badnum
init|=
literal|"bad number"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badparam
init|=
literal|"parameter not set"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badsub
init|=
literal|"bad substitution"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badcreate
init|=
literal|"cannot create"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|illegal
init|=
literal|"illegal io"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|restricted
init|=
literal|"restricted"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|piperr
init|=
literal|"cannot make pipe"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badopen
init|=
literal|"cannot open"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|coredump
init|=
literal|" - core dumped"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|arglist
init|=
literal|"arg list too long"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|txtbsy
init|=
literal|"text busy"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|toobig
init|=
literal|"too big"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badexec
init|=
literal|"cannot execute"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|notfound
init|=
literal|"not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badfile
init|=
literal|"bad file number"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badshift
init|=
literal|"cannot shift"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|baddir
init|=
literal|"bad directory"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badtrap
init|=
literal|"bad trap"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|wtfailed
init|=
literal|"is read only"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|notid
init|=
literal|"is not an identifier"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* built in names */
end_comment

begin_decl_stmt
name|MSG
name|pathname
init|=
literal|"PATH"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|homename
init|=
literal|"HOME"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|mailname
init|=
literal|"MAIL"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|fngname
init|=
literal|"FILEMATCH"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|ifsname
init|=
literal|"IFS"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|ps1name
init|=
literal|"PS1"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|ps2name
init|=
literal|"PS2"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string constants */
end_comment

begin_decl_stmt
name|MSG
name|nullstr
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|sptbnl
init|=
literal|" \t\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|defpath
init|=
literal|":/bin:/usr/bin"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|colon
init|=
literal|": "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|minus
init|=
literal|"-"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|endoffile
init|=
literal|"end of file"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|unexpected
init|=
literal|" unexpected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|atline
init|=
literal|" at line "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|devnull
init|=
literal|"/dev/null"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|execpmsg
init|=
literal|"+ "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|readmsg
init|=
literal|"> "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|stdprompt
init|=
literal|"$ "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|supprompt
init|=
literal|"# "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|profile
init|=
literal|".profile"
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
literal|"in"
block|,
name|INSYM
block|}
block|,
block|{
literal|"esac"
block|,
name|ESSYM
block|}
block|,
block|{
literal|"case"
block|,
name|CASYM
block|}
block|,
block|{
literal|"for"
block|,
name|FORSYM
block|}
block|,
block|{
literal|"done"
block|,
name|ODSYM
block|}
block|,
block|{
literal|"if"
block|,
name|IFSYM
block|}
block|,
block|{
literal|"while"
block|,
name|WHSYM
block|}
block|,
block|{
literal|"do"
block|,
name|DOSYM
block|}
block|,
block|{
literal|"then"
block|,
name|THSYM
block|}
block|,
block|{
literal|"else"
block|,
name|ELSYM
block|}
block|,
block|{
literal|"elif"
block|,
name|EFSYM
block|}
block|,
block|{
literal|"fi"
block|,
name|FISYM
block|}
block|,
block|{
literal|"until"
block|,
name|UNSYM
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
literal|0
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|sysmsg
index|[]
init|=
block|{
literal|0
block|,
literal|"Hangup"
block|,
literal|0
block|,
comment|/* Interrupt */
literal|"Quit"
block|,
literal|"Illegal instruction"
block|,
literal|"Trace/BPT trap"
block|,
literal|"IOT trap"
block|,
literal|"EMT trap"
block|,
literal|"Floating exception"
block|,
literal|"Killed"
block|,
literal|"Bus error"
block|,
literal|"Memory fault"
block|,
literal|"Bad system call"
block|,
literal|0
block|,
comment|/* Broken pipe */
literal|"Alarm call"
block|,
literal|"Terminated"
block|,
literal|"Urgent condition"
block|,
literal|"Stopped"
block|,
literal|"Stopped from terminal"
block|,
literal|"Continued"
block|,
literal|"Child terminated"
block|,
literal|"Stopped on terminal input"
block|,
literal|"Stopped on terminal output"
block|,
literal|"Asynchronous I/O"
block|,
literal|"Exceeded cpu time limit"
block|,
literal|"Exceeded file size limit"
block|,
literal|"Virtual time alarm"
block|,
literal|"Profiling time alarm"
block|,
literal|"Window changed"
block|,
literal|"Signal 29"
block|,
literal|"User defined signal 1"
block|,
literal|"User defined signal 2"
block|,
literal|"Signal 32"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|num_sysmsg
init|=
operator|(
sizeof|sizeof
name|sysmsg
operator|/
sizeof|sizeof
name|sysmsg
index|[
literal|0
index|]
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|export
init|=
literal|"export"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|readonly
init|=
literal|"readonly"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYSTAB
name|commands
init|=
block|{
block|{
literal|"cd"
block|,
name|SYSCD
block|}
block|,
block|{
literal|"read"
block|,
name|SYSREAD
block|}
block|,
comment|/* 		{"[",		SYSTST}, */
block|{
literal|"set"
block|,
name|SYSSET
block|}
block|,
block|{
literal|":"
block|,
name|SYSNULL
block|}
block|,
block|{
literal|"trap"
block|,
name|SYSTRAP
block|}
block|,
block|{
literal|"login"
block|,
name|SYSLOGIN
block|}
block|,
block|{
literal|"wait"
block|,
name|SYSWAIT
block|}
block|,
block|{
literal|"eval"
block|,
name|SYSEVAL
block|}
block|,
block|{
literal|"."
block|,
name|SYSDOT
block|}
block|,
block|{
name|readonly
block|,
name|SYSRDONLY
block|}
block|,
block|{
name|export
block|,
name|SYSXPORT
block|}
block|,
block|{
literal|"chdir"
block|,
name|SYSCD
block|}
block|,
block|{
literal|"break"
block|,
name|SYSBREAK
block|}
block|,
block|{
literal|"continue"
block|,
name|SYSCONT
block|}
block|,
block|{
literal|"shift"
block|,
name|SYSSHFT
block|}
block|,
block|{
literal|"exit"
block|,
name|SYSEXIT
block|}
block|,
block|{
literal|"exec"
block|,
name|SYSEXEC
block|}
block|,
block|{
literal|"times"
block|,
name|SYSTIMES
block|}
block|,
block|{
literal|"umask"
block|,
name|SYSUMASK
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit


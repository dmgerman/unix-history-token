begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
block|{
block|{
literal|"in"
operator|,
name|INSYM
block|}
operator|,
block|{
literal|"esac"
operator|,
name|ESSYM
block|}
operator|,
block|{
literal|"case"
operator|,
name|CASYM
block|}
operator|,
block|{
literal|"for"
operator|,
name|FORSYM
block|}
operator|,
block|{
literal|"done"
operator|,
name|ODSYM
block|}
operator|,
block|{
literal|"if"
operator|,
name|IFSYM
block|}
operator|,
block|{
literal|"while"
operator|,
name|WHSYM
block|}
operator|,
block|{
literal|"do"
operator|,
name|DOSYM
block|}
operator|,
block|{
literal|"then"
operator|,
name|THSYM
block|}
operator|,
block|{
literal|"else"
operator|,
name|ELSYM
block|}
operator|,
block|{
literal|"elif"
operator|,
name|EFSYM
block|}
operator|,
block|{
literal|"fi"
operator|,
name|FISYM
block|}
operator|,
block|{
literal|"until"
operator|,
name|UNSYM
block|}
operator|,
block|{
literal|"{"
operator|,
name|BRSYM
block|}
operator|,
block|{
literal|"}"
operator|,
name|KTSYM
block|}
operator|,
block|{
literal|0
operator|,
literal|0
block|}
operator|,
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|STRING
name|sysmsg
index|[]
block|{
literal|0
operator|,
literal|"Hangup"
operator|,
literal|0
operator|,
comment|/* Interrupt */
literal|"Quit"
operator|,
literal|"Illegal instruction"
operator|,
literal|"Trace/BPT trap"
operator|,
literal|"IOT trap"
operator|,
literal|"EMT trap"
operator|,
literal|"Floating exception"
operator|,
literal|"Killed"
operator|,
literal|"Bus error"
operator|,
literal|"Memory fault"
operator|,
literal|"Bad system call"
operator|,
literal|0
operator|,
comment|/* Broken pipe */
literal|"Alarm call"
operator|,
literal|"Terminated"
operator|,
literal|"Signal 16"
operator|,
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
block|{
block|{
literal|"cd"
operator|,
name|SYSCD
block|}
operator|,
block|{
literal|"read"
operator|,
name|SYSREAD
block|}
operator|,
comment|/* 		{"[",		SYSTST}, */
block|{
literal|"set"
operator|,
name|SYSSET
block|}
operator|,
block|{
literal|":"
operator|,
name|SYSNULL
block|}
operator|,
block|{
literal|"trap"
operator|,
name|SYSTRAP
block|}
operator|,
block|{
literal|"login"
operator|,
name|SYSLOGIN
block|}
operator|,
block|{
literal|"wait"
operator|,
name|SYSWAIT
block|}
operator|,
block|{
literal|"eval"
operator|,
name|SYSEVAL
block|}
operator|,
block|{
literal|"."
operator|,
name|SYSDOT
block|}
operator|,
block|{
literal|"newgrp"
operator|,
name|SYSLOGIN
block|}
operator|,
block|{
name|readonly
operator|,
name|SYSRDONLY
block|}
operator|,
block|{
name|export
operator|,
name|SYSXPORT
block|}
operator|,
block|{
literal|"chdir"
operator|,
name|SYSCD
block|}
operator|,
block|{
literal|"break"
operator|,
name|SYSBREAK
block|}
operator|,
block|{
literal|"continue"
operator|,
name|SYSCONT
block|}
operator|,
block|{
literal|"shift"
operator|,
name|SYSSHFT
block|}
operator|,
block|{
literal|"exit"
operator|,
name|SYSEXIT
block|}
operator|,
block|{
literal|"exec"
operator|,
name|SYSEXEC
block|}
operator|,
block|{
literal|"times"
operator|,
name|SYSTIMES
block|}
operator|,
block|{
literal|"umask"
operator|,
name|SYSUMASK
block|}
operator|,
block|{
literal|0
operator|,
literal|0
block|}
operator|,
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit


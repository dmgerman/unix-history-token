begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

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
literal|"@(#)init.c	5.12 (Berkeley) 6/27/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"csh.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_define
define|#
directive|define
name|INF
value|1000
end_define

begin_decl_stmt
name|struct
name|biltins
name|bfunc
index|[]
init|=
block|{
literal|"@"
block|,
name|dolet
block|,
literal|0
block|,
name|INF
block|,
literal|"alias"
block|,
name|doalias
block|,
literal|0
block|,
name|INF
block|,
literal|"alloc"
block|,
name|showall
block|,
literal|0
block|,
literal|1
block|,
literal|"bg"
block|,
name|dobg
block|,
literal|0
block|,
name|INF
block|,
literal|"break"
block|,
name|dobreak
block|,
literal|0
block|,
literal|0
block|,
literal|"breaksw"
block|,
name|doswbrk
block|,
literal|0
block|,
literal|0
block|,
literal|"case"
block|,
name|dozip
block|,
literal|0
block|,
literal|1
block|,
literal|"cd"
block|,
name|dochngd
block|,
literal|0
block|,
name|INF
block|,
literal|"chdir"
block|,
name|dochngd
block|,
literal|0
block|,
name|INF
block|,
literal|"continue"
block|,
name|docontin
block|,
literal|0
block|,
literal|0
block|,
literal|"default"
block|,
name|dozip
block|,
literal|0
block|,
literal|0
block|,
literal|"dirs"
block|,
name|dodirs
block|,
literal|0
block|,
name|INF
block|,
literal|"echo"
block|,
name|doecho
block|,
literal|0
block|,
name|INF
block|,
literal|"else"
block|,
name|doelse
block|,
literal|0
block|,
name|INF
block|,
literal|"end"
block|,
name|doend
block|,
literal|0
block|,
literal|0
block|,
literal|"endif"
block|,
name|dozip
block|,
literal|0
block|,
literal|0
block|,
literal|"endsw"
block|,
name|dozip
block|,
literal|0
block|,
literal|0
block|,
literal|"eval"
block|,
name|doeval
block|,
literal|0
block|,
name|INF
block|,
literal|"exec"
block|,
name|execash
block|,
literal|1
block|,
name|INF
block|,
literal|"exit"
block|,
name|doexit
block|,
literal|0
block|,
name|INF
block|,
literal|"fg"
block|,
name|dofg
block|,
literal|0
block|,
name|INF
block|,
literal|"foreach"
block|,
name|doforeach
block|,
literal|3
block|,
name|INF
block|,
literal|"glob"
block|,
name|doglob
block|,
literal|0
block|,
name|INF
block|,
literal|"goto"
block|,
name|dogoto
block|,
literal|1
block|,
literal|1
block|,
literal|"hashstat"
block|,
name|hashstat
block|,
literal|0
block|,
literal|0
block|,
literal|"history"
block|,
name|dohist
block|,
literal|0
block|,
literal|2
block|,
literal|"if"
block|,
name|doif
block|,
literal|1
block|,
name|INF
block|,
literal|"jobs"
block|,
name|dojobs
block|,
literal|0
block|,
literal|1
block|,
literal|"kill"
block|,
name|dokill
block|,
literal|1
block|,
name|INF
block|,
literal|"limit"
block|,
name|dolimit
block|,
literal|0
block|,
literal|3
block|,
literal|"linedit"
block|,
name|doecho
block|,
literal|0
block|,
name|INF
block|,
literal|"login"
block|,
name|dologin
block|,
literal|0
block|,
literal|1
block|,
literal|"logout"
block|,
name|dologout
block|,
literal|0
block|,
literal|0
block|,
literal|"nice"
block|,
name|donice
block|,
literal|0
block|,
name|INF
block|,
literal|"nohup"
block|,
name|donohup
block|,
literal|0
block|,
name|INF
block|,
literal|"notify"
block|,
name|donotify
block|,
literal|0
block|,
name|INF
block|,
literal|"onintr"
block|,
name|doonintr
block|,
literal|0
block|,
literal|2
block|,
literal|"popd"
block|,
name|dopopd
block|,
literal|0
block|,
name|INF
block|,
literal|"pushd"
block|,
name|dopushd
block|,
literal|0
block|,
name|INF
block|,
literal|"rehash"
block|,
name|dohash
block|,
literal|0
block|,
literal|0
block|,
literal|"repeat"
block|,
name|dorepeat
block|,
literal|2
block|,
name|INF
block|,
literal|"set"
block|,
name|doset
block|,
literal|0
block|,
name|INF
block|,
literal|"setenv"
block|,
name|dosetenv
block|,
literal|0
block|,
literal|2
block|,
literal|"shift"
block|,
name|shift
block|,
literal|0
block|,
literal|1
block|,
literal|"source"
block|,
name|dosource
block|,
literal|1
block|,
literal|2
block|,
literal|"stop"
block|,
name|dostop
block|,
literal|1
block|,
name|INF
block|,
literal|"suspend"
block|,
name|dosuspend
block|,
literal|0
block|,
literal|0
block|,
literal|"switch"
block|,
name|doswitch
block|,
literal|1
block|,
name|INF
block|,
literal|"time"
block|,
name|dotime
block|,
literal|0
block|,
name|INF
block|,
literal|"umask"
block|,
name|doumask
block|,
literal|0
block|,
literal|1
block|,
literal|"unalias"
block|,
name|unalias
block|,
literal|1
block|,
name|INF
block|,
literal|"unhash"
block|,
name|dounhash
block|,
literal|0
block|,
literal|0
block|,
literal|"unlimit"
block|,
name|dounlimit
block|,
literal|0
block|,
name|INF
block|,
literal|"unset"
block|,
name|unset
block|,
literal|1
block|,
name|INF
block|,
literal|"unsetenv"
block|,
name|dounsetenv
block|,
literal|1
block|,
name|INF
block|,
literal|"wait"
block|,
name|dowait
block|,
literal|0
block|,
literal|0
block|,
literal|"while"
block|,
name|dowhile
block|,
literal|1
block|,
name|INF
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nbfunc
init|=
sizeof|sizeof
name|bfunc
operator|/
sizeof|sizeof
expr|*
name|bfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|srch
name|srchn
index|[]
init|=
block|{
literal|"@"
block|,
name|T_LET
block|,
literal|"break"
block|,
name|T_BREAK
block|,
literal|"breaksw"
block|,
name|T_BRKSW
block|,
literal|"case"
block|,
name|T_CASE
block|,
literal|"default"
block|,
name|T_DEFAULT
block|,
literal|"else"
block|,
name|T_ELSE
block|,
literal|"end"
block|,
name|T_END
block|,
literal|"endif"
block|,
name|T_ENDIF
block|,
literal|"endsw"
block|,
name|T_ENDSW
block|,
literal|"exit"
block|,
name|T_EXIT
block|,
literal|"foreach"
block|,
name|T_FOREACH
block|,
literal|"goto"
block|,
name|T_GOTO
block|,
literal|"if"
block|,
name|T_IF
block|,
literal|"label"
block|,
name|T_LABEL
block|,
literal|"set"
block|,
name|T_SET
block|,
literal|"switch"
block|,
name|T_SWITCH
block|,
literal|"while"
block|,
name|T_WHILE
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nsrchn
init|=
sizeof|sizeof
name|srchn
operator|/
sizeof|sizeof
expr|*
name|srchn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mesg
name|mesg
index|[]
init|=
block|{
comment|/*  0 */
literal|0
block|,
literal|""
block|,
comment|/*  1 */
literal|"HUP"
block|,
literal|"Hangup"
block|,
comment|/*  2 */
literal|"INT"
block|,
literal|"Interrupt"
block|,
comment|/*  3 */
literal|"QUIT"
block|,
literal|"Quit"
block|,
comment|/*  4 */
literal|"ILL"
block|,
literal|"Illegal instruction"
block|,
comment|/*  5 */
literal|"TRAP"
block|,
literal|"Trace/BPT trap"
block|,
comment|/*  6 */
literal|"IOT"
block|,
literal|"IOT trap"
block|,
comment|/*  7 */
literal|"EMT"
block|,
literal|"EMT trap"
block|,
comment|/*  8 */
literal|"FPE"
block|,
literal|"Floating exception"
block|,
comment|/*  9 */
literal|"KILL"
block|,
literal|"Killed"
block|,
comment|/* 10 */
literal|"BUS"
block|,
literal|"Bus error"
block|,
comment|/* 11 */
literal|"SEGV"
block|,
literal|"Segmentation fault"
block|,
comment|/* 12 */
literal|"SYS"
block|,
literal|"Bad system call"
block|,
comment|/* 13 */
literal|"PIPE"
block|,
literal|"Broken pipe"
block|,
comment|/* 14 */
literal|"ALRM"
block|,
literal|"Alarm clock"
block|,
comment|/* 15 */
literal|"TERM"
block|,
literal|"Terminated"
block|,
comment|/* 16 */
literal|"URG"
block|,
literal|"Urgent condition on IO channel"
block|,
comment|/* 17 */
literal|"STOP"
block|,
literal|"Suspended (signal)"
block|,
comment|/* 18 */
literal|"TSTP"
block|,
literal|"Suspended"
block|,
comment|/* 19 */
literal|"CONT"
block|,
literal|"Continued"
block|,
comment|/* 20 */
literal|"CHLD"
block|,
literal|"Child exited"
block|,
comment|/* 21 */
literal|"TTIN"
block|,
literal|"Suspended (tty input)"
block|,
comment|/* 22 */
literal|"TTOU"
block|,
literal|"Suspended (tty output)"
block|,
comment|/* 23 */
literal|"IO"
block|,
literal|"IO possible interrupt"
block|,
comment|/* 24 */
literal|"XCPU"
block|,
literal|"Cputime limit exceeded"
block|,
comment|/* 25 */
literal|"XFSZ"
block|,
literal|"Filesize limit exceeded"
block|,
comment|/* 26 */
literal|"VTALRM"
block|,
literal|"Virtual time alarm"
block|,
comment|/* 27 */
literal|"PROF"
block|,
literal|"Profiling time alarm"
block|,
comment|/* 28 */
literal|"WINCH"
block|,
literal|"Window changed"
block|,
comment|/* 29 */
literal|"INFO"
block|,
literal|"Information request"
block|,
comment|/* 30 */
literal|"USR1"
block|,
literal|"User signal 1"
block|,
comment|/* 31 */
literal|"USR2"
block|,
literal|"User signal 2"
block|,
comment|/* 32 */
literal|0
block|,
literal|"Signal 32"
block|, }
decl_stmt|;
end_decl_stmt

end_unit


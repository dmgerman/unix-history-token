begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)externs.h	1.9 (Berkeley) 5/15/88  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_define
define|#
directive|define
name|SUBBUFSIZE
value|100
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* outside this world */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* outside this world */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flushout
decl_stmt|,
comment|/* flush output */
name|connected
decl_stmt|,
comment|/* Are we connected to the other side? */
name|globalmode
decl_stmt|,
comment|/* Mode tty should be in */
name|In3270
decl_stmt|,
comment|/* Are we in 3270 mode? */
name|telnetport
decl_stmt|,
comment|/* Are we connected to the telnet port? */
name|localchars
decl_stmt|,
comment|/* we recognize interrupt/quit */
name|donelclchars
decl_stmt|,
comment|/* the user has set "localchars" */
name|showoptions
decl_stmt|,
name|net
decl_stmt|,
name|tout
decl_stmt|,
comment|/* Terminal output file descriptor */
name|crlf
decl_stmt|,
comment|/* Should '\r' be mapped to<CR><LF> (or<CR><NUL>)? */
name|autoflush
decl_stmt|,
comment|/* flush output when interrupting? */
name|autosynch
decl_stmt|,
comment|/* send interrupt characters with SYNCH? */
name|SYNCHing
decl_stmt|,
comment|/* Is the stream in telnet SYNCH mode? */
name|donebinarytoggle
decl_stmt|,
comment|/* the user has put us in binary */
name|dontlecho
decl_stmt|,
comment|/* do we suppress local echoing right now? */
name|crmod
decl_stmt|,
name|netdata
decl_stmt|,
comment|/* Print out network data flow */
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug level */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|echoc
decl_stmt|,
comment|/* Toggle local echoing */
name|escape
decl_stmt|,
comment|/* Escape to command mode */
name|doopt
index|[]
decl_stmt|,
name|dont
index|[]
decl_stmt|,
name|will
index|[]
decl_stmt|,
name|wont
index|[]
decl_stmt|,
name|hisopts
index|[]
decl_stmt|,
name|myopts
index|[]
decl_stmt|,
modifier|*
name|hostname
decl_stmt|,
comment|/* Who are we connected to? */
modifier|*
name|prompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prompt for command. */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|NetTrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where debugging output goes */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|peerdied
decl_stmt|,
name|toplevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For error conditions. */
end_comment

begin_decl_stmt
specifier|extern
name|void
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NOT43
argument_list|)
name|dosynch
argument_list|()
decl_stmt|,
endif|#
directive|endif
comment|/* !defined(NOT43) */
name|setconnmode
argument_list|()
decl_stmt|,
name|setcommandmode
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NOT43
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|dosynch
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NOT43) */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|termEofChar
decl_stmt|,
name|termEraseChar
decl_stmt|,
name|termFlushChar
decl_stmt|,
name|termIntChar
decl_stmt|,
name|termKillChar
decl_stmt|,
name|termLiteralNextChar
decl_stmt|,
name|termQuitChar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ring buffer structures which are shared */
end_comment

begin_decl_stmt
specifier|extern
name|Ring
name|netoring
decl_stmt|,
name|netiring
decl_stmt|,
name|ttyoring
decl_stmt|,
name|ttyiring
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tn3270 section */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TN3270
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|HaveInput
decl_stmt|,
comment|/* Whether an asynchronous I/O indication came in */
name|noasynch
decl_stmt|,
comment|/* Don't do signals on I/O (SIGURG, SIGIO) */
name|shell_active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Subshell is active */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Ibackp
decl_stmt|,
comment|/* Oldest byte of 3270 data */
name|Ibuf
index|[]
decl_stmt|,
comment|/* 3270 buffer */
modifier|*
name|Ifrontp
decl_stmt|,
comment|/* Where next 3270 byte goes */
name|tline
index|[]
decl_stmt|,
modifier|*
name|transcom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Transparent command */
end_comment

begin_function_decl
specifier|extern
name|int
name|settranscom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|inputAvailable
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(TN3270) */
end_comment

end_unit


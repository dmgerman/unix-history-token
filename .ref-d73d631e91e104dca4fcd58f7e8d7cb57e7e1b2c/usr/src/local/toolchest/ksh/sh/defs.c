begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)defs.c	1.1 */
end_comment

begin_comment
comment|/*  * Ksh - AT&T Bell Laboratories  * Written by David Korn  * This file defines all the  read/write shell global variables  */
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

begin_include
include|#
directive|include
file|"io.h"
end_include

begin_include
include|#
directive|include
file|"history.h"
end_include

begin_include
include|#
directive|include
file|"brkincr.h"
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
file|"jobs.h"
end_include

begin_include
include|#
directive|include
file|"edit.h"
end_include

begin_include
include|#
directive|include
file|"timeout.h"
end_include

begin_decl_stmt
name|struct
name|Amemory
modifier|*
name|alias
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|State
name|st
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BLKPTR
name|blokp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BLKPTR
name|bloktop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NAMPTR
name|bltin_nodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|brkbegin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STKPTR
name|brkend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|comdiv
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VSH
end_ifdef

begin_decl_stmt
name|struct
name|edit
name|editb
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ESH
end_ifdef

begin_decl_stmt
name|struct
name|edit
name|editb
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ESH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSH */
end_comment

begin_decl_stmt
name|jmp_buf
name|errshell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|exitval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|fixcmd
modifier|*
name|fc_fix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
modifier|*
name|freturn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ARGPTR
name|gchain
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|JOBS
end_ifdef

begin_decl_stmt
name|struct
name|jobs
name|jobstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JOBS */
end_comment

begin_decl_stmt
name|char
modifier|*
name|lastarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lastbase
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|mailchk
init|=
literal|600
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|timeout
init|=
name|TIMEOUT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|Amemory
modifier|*
name|namep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oldexit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|parent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|pcsadr
index|[
literal|12
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|pidadr
index|[
literal|12
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|ppid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|Amemory
modifier|*
name|prnames
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|savexit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STKPTR
name|stakbas
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BLKPTR
name|stakbsy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STKPTR
name|stakbot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STKPTR
name|staktop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILEBLK
name|stdfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|subshell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sysmsg
index|[
name|MAXTRAP
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|tmpout
index|[]
init|=
literal|"/tmp/shxxxxxx.aaa"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|topfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|trapcom
index|[
name|MAXTRAP
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOL
name|trapnote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOL
name|login_sh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|userid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|subflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wdnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ARGPTR
name|wdarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wdval
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NOBUF
end_ifdef

begin_decl_stmt
name|unsigned
name|char
name|_sibuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
name|_sobuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOBUF */
end_comment

end_unit


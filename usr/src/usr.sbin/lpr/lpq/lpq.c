begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1983 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)lpq.c	5.9 (Berkeley) 8/6/92"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Spool Queue examination program  *  * lpq [-l] [-Pprinter] [user...] [job...]  *  * -l long output  * -P used to identify printer as per lpr/lprm  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"lp.h"
end_include

begin_include
include|#
directive|include
file|"lp.local.h"
end_include

begin_decl_stmt
name|int
name|requ
index|[
name|MAXREQUESTS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* job number of spool entries */
end_comment

begin_decl_stmt
name|int
name|requests
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of spool requests */
end_comment

begin_decl_stmt
name|char
modifier|*
name|user
index|[
name|MAXUSERS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* users to process */
end_comment

begin_decl_stmt
name|int
name|users
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of users in user array */
end_comment

begin_decl_stmt
name|void
name|usage
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
specifier|register
name|int
name|argc
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
specifier|extern
name|int
name|optind
decl_stmt|;
name|int
name|ch
decl_stmt|,
name|lflag
decl_stmt|;
comment|/* long output option */
name|name
operator|=
operator|*
name|argv
expr_stmt|;
if|if
condition|(
name|gethostname
argument_list|(
name|host
argument_list|,
sizeof|sizeof
argument_list|(
name|host
argument_list|)
argument_list|)
condition|)
block|{
name|perror
argument_list|(
literal|"lpq: gethostname"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|openlog
argument_list|(
literal|"lpd"
argument_list|,
literal|0
argument_list|,
name|LOG_LPR
argument_list|)
expr_stmt|;
name|lflag
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"lP:"
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
switch|switch
condition|(
operator|(
name|char
operator|)
name|ch
condition|)
block|{
case|case
literal|'l'
case|:
comment|/* long output */
operator|++
name|lflag
expr_stmt|;
break|break;
case|case
literal|'P'
case|:
comment|/* printer name */
name|printer
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
default|default:
name|usage
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|printer
operator|==
name|NULL
operator|&&
operator|(
name|printer
operator|=
name|getenv
argument_list|(
literal|"PRINTER"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|printer
operator|=
name|DEFLP
expr_stmt|;
for|for
control|(
name|argc
operator|-=
name|optind
operator|,
name|argv
operator|+=
name|optind
init|;
name|argc
condition|;
operator|--
name|argc
operator|,
operator|++
name|argv
control|)
if|if
condition|(
name|isdigit
argument_list|(
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
if|if
condition|(
name|requests
operator|>=
name|MAXREQUESTS
condition|)
name|fatal
argument_list|(
literal|"too many requests"
argument_list|)
expr_stmt|;
name|requ
index|[
name|requests
operator|++
index|]
operator|=
name|atoi
argument_list|(
operator|*
name|argv
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|users
operator|>=
name|MAXUSERS
condition|)
name|fatal
argument_list|(
literal|"too many users"
argument_list|)
expr_stmt|;
name|user
index|[
name|users
operator|++
index|]
operator|=
operator|*
name|argv
expr_stmt|;
block|}
name|displayq
argument_list|(
name|lflag
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|usage
parameter_list|()
block|{
name|puts
argument_list|(
literal|"usage: lpq [-l] [-Pprinter] [user ...] [job ...]"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit


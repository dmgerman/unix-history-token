begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1983, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)lprm.c	8.1 (Berkeley) 6/6/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id$"
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
comment|/*  * lprm - remove the current user's spool entry  *  * lprm [-] [[job #] [user] ...]  *  * Using information in the lock file, lprm will kill the  * currently active daemon (if necessary), remove the associated files,  * and startup a new daemon.  Priviledged users may remove anyone's spool  * entries, otherwise one can only remove their own.  */
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
file|<pwd.h>
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
file|<string.h>
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

begin_comment
comment|/*  * Stuff for handling job specifications  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|person
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of person doing lprm */
end_comment

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
name|uid_t
name|uid
decl_stmt|,
name|euid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* real and effective user id's */
end_comment

begin_decl_stmt
specifier|static
name|char
name|luser
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for person */
end_comment

begin_decl_stmt
specifier|static
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
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|arg
decl_stmt|;
name|struct
name|passwd
modifier|*
name|p
decl_stmt|;
name|uid
operator|=
name|getuid
argument_list|()
expr_stmt|;
name|euid
operator|=
name|geteuid
argument_list|()
expr_stmt|;
name|seteuid
argument_list|(
name|uid
argument_list|)
expr_stmt|;
comment|/* be safe */
name|name
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|gethostname
argument_list|(
name|host
argument_list|,
sizeof|sizeof
argument_list|(
name|host
argument_list|)
argument_list|)
expr_stmt|;
name|openlog
argument_list|(
literal|"lpd"
argument_list|,
literal|0
argument_list|,
name|LOG_LPR
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|getpwuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|fatal
argument_list|(
literal|"Who are you?"
argument_list|)
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|p
operator|->
name|pw_name
argument_list|)
operator|>=
sizeof|sizeof
argument_list|(
name|luser
argument_list|)
condition|)
name|fatal
argument_list|(
literal|"Your name is too long"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|luser
argument_list|,
name|p
operator|->
name|pw_name
argument_list|)
expr_stmt|;
name|person
operator|=
name|luser
expr_stmt|;
while|while
condition|(
operator|--
name|argc
condition|)
block|{
if|if
condition|(
operator|(
name|arg
operator|=
operator|*
operator|++
name|argv
operator|)
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
switch|switch
condition|(
name|arg
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'P'
case|:
if|if
condition|(
name|arg
index|[
literal|2
index|]
condition|)
name|printer
operator|=
operator|&
name|arg
index|[
literal|2
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
name|argc
operator|--
expr_stmt|;
name|printer
operator|=
operator|*
operator|++
name|argv
expr_stmt|;
block|}
break|break;
case|case
literal|'\0'
case|:
if|if
condition|(
operator|!
name|users
condition|)
block|{
name|users
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
block|}
default|default:
name|usage
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|users
operator|<
literal|0
condition|)
name|usage
argument_list|()
expr_stmt|;
if|if
condition|(
name|isdigit
argument_list|(
name|arg
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
literal|"Too many requests"
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
name|arg
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
literal|"Too many users"
argument_list|)
expr_stmt|;
name|user
index|[
name|users
operator|++
index|]
operator|=
name|arg
expr_stmt|;
block|}
block|}
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
name|rmjob
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|usage
parameter_list|()
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: lprm [-] [-Pprinter] [[job #] [user] ...]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

end_unit


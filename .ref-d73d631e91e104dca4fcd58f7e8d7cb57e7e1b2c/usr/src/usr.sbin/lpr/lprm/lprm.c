begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)lprm.c	5.5 (Berkeley) %G%"
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
file|"lp.h"
end_include

begin_comment
comment|/*  * Stuff for handling job specifications  */
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
name|person
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of person doing lprm */
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

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
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
name|struct
name|direct
modifier|*
modifier|*
name|files
decl_stmt|;
name|int
name|nitems
decl_stmt|,
name|assasinated
init|=
literal|0
decl_stmt|;
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
block|}
end_function

begin_expr_stmt
specifier|static
name|usage
argument_list|()
block|{
name|printf
argument_list|(
literal|"usage: lprm [-] [-Pprinter] [[job #] [user] ...]\n"
argument_list|)
block|;
name|exit
argument_list|(
literal|2
argument_list|)
block|; }
end_expr_stmt

end_unit


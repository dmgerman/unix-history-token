begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)lpq.c	5.5 (Berkeley) 6/30/88"
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
file|"lp.h"
end_include

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

begin_function
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

begin_expr_stmt
specifier|static
name|usage
argument_list|()
block|{
name|puts
argument_list|(
literal|"usage: lpq [-l] [-Pprinter] [user ...] [job ...]"
argument_list|)
block|;
name|exit
argument_list|(
literal|1
argument_list|)
block|; }
end_expr_stmt

end_unit


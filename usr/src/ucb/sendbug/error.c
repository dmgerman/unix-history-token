begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)error.c	5.6 (Berkeley) 6/29/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<bug.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|short
name|err_redir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stderr redirected */
end_comment

begin_comment
comment|/*  * seterr --  *	redirect stderr for error processing  */
end_comment

begin_macro
name|seterr
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|freopen
argument_list|(
name|ERROR_FILE
argument_list|,
literal|"a"
argument_list|,
name|stderr
argument_list|)
condition|)
name|error
argument_list|(
literal|"can't open error file %s."
argument_list|,
name|ERROR_FILE
argument_list|)
expr_stmt|;
name|err_redir
operator|=
name|YES
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * error --  *	write errors to log file and die  */
end_comment

begin_expr_stmt
name|error
argument_list|(
name|fmt
argument_list|,
name|arg
argument_list|)
specifier|register
name|char
operator|*
name|fmt
operator|,
operator|*
name|arg
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|static
name|char
name|logmsg
index|[
name|MAXLINELEN
index|]
decl_stmt|;
comment|/* syslog message */
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|;
if|if
condition|(
name|err_redir
condition|)
block|{
comment|/* don't combine these, "fmt" may not require "arg" */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t%s\n\t"
argument_list|,
name|tmpname
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sprintf
argument_list|(
name|logmsg
argument_list|,
literal|"bugfiler: %s"
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
name|logmsg
argument_list|,
name|arg
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|METOO
name|exit
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
else|#
directive|else
name|exit
argument_list|(
name|OK
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)error.c	5.1 (Berkeley) 86/11/25"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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

begin_include
include|#
directive|include
file|<bug.h>
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|distf
decl_stmt|,
comment|/* redist temp file */
name|tmpname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary file used */
end_comment

begin_decl_stmt
name|short
name|made_dist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if dist file made */
end_comment

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
literal|"unable to open error file %s.\n"
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
name|fputc
argument_list|(
literal|'\t'
argument_list|,
name|stderr
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
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n\ttemporary file is %s.\n"
argument_list|,
name|tmpname
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|strcat
argument_list|(
name|strcpy
argument_list|(
name|logmsg
argument_list|,
literal|"bugfiler: "
argument_list|)
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
if|if
condition|(
name|made_dist
condition|)
comment|/* unlink redist file if necessary */
name|unlink
argument_list|(
name|distf
argument_list|)
expr_stmt|;
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
else|!METOO
name|exit
argument_list|(
name|OK
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|METOO
block|}
end_block

end_unit


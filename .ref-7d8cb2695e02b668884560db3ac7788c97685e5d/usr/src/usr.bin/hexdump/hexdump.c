begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#) Copyright (c) 1989 The Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)hexdump.c	5.6 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
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
file|"hexdump.h"
end_include

begin_decl_stmt
name|FS
modifier|*
name|fshead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of format strings */
end_comment

begin_decl_stmt
name|int
name|blocksize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data block size */
end_comment

begin_decl_stmt
name|int
name|exitval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* final exit value */
end_comment

begin_decl_stmt
name|int
name|length
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max bytes to read */
end_comment

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
name|FS
modifier|*
name|tfs
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|p
operator|=
name|rindex
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|'o'
argument_list|)
operator|)
operator|||
name|strcmp
argument_list|(
name|p
argument_list|,
literal|"od"
argument_list|)
condition|)
name|newsyntax
argument_list|(
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
expr_stmt|;
else|else
name|oldsyntax
argument_list|(
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
expr_stmt|;
comment|/* figure out the data block size */
for|for
control|(
name|blocksize
operator|=
literal|0
operator|,
name|tfs
operator|=
name|fshead
init|;
name|tfs
condition|;
name|tfs
operator|=
name|tfs
operator|->
name|nextfs
control|)
block|{
name|tfs
operator|->
name|bcnt
operator|=
name|size
argument_list|(
name|tfs
argument_list|)
expr_stmt|;
if|if
condition|(
name|blocksize
operator|<
name|tfs
operator|->
name|bcnt
condition|)
name|blocksize
operator|=
name|tfs
operator|->
name|bcnt
expr_stmt|;
block|}
comment|/* rewrite the rules, do syntax checking */
for|for
control|(
name|tfs
operator|=
name|fshead
init|;
name|tfs
condition|;
name|tfs
operator|=
name|tfs
operator|->
name|nextfs
control|)
name|rewrite
argument_list|(
name|tfs
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|next
argument_list|(
name|argv
argument_list|)
expr_stmt|;
name|display
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|exitval
argument_list|)
expr_stmt|;
block|}
end_function

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

begin_function
name|void
if|#
directive|if
name|__STDC__
name|err
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|err
parameter_list|(
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|ap
decl_stmt|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"hexdump: "
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)oldsyntax.c	5.1 (Berkeley) %G%"
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
file|<stdio.h>
end_include

begin_comment
comment|/*  * oldsyntax --  *	move the path names to the beginning of the argv array, and return  *	a pointer to them.  The old find syntax assumes all command arguments  *	up to the first one beginning with a '-', '(' or '!' are pathnames.  */
end_comment

begin_function
name|char
modifier|*
modifier|*
name|oldsyntax
parameter_list|(
name|argvp
parameter_list|)
name|char
modifier|*
modifier|*
modifier|*
name|argvp
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* 	 * find first '-', '(' or '!' to delimit paths; if no paths, it's 	 * an error.  Shift the array back one at the same time, creating 	 * a separate array of pathnames. 	 */
for|for
control|(
name|argv
operator|=
operator|*
name|argvp
operator|+
literal|1
init|;
condition|;
operator|++
name|argv
control|)
block|{
name|argv
index|[
operator|-
literal|1
index|]
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|argv
operator|||
operator|*
operator|*
name|argv
operator|==
literal|'-'
operator|||
operator|*
operator|*
name|argv
operator|==
literal|'!'
operator|||
operator|*
operator|*
name|argv
operator|==
literal|'('
condition|)
break|break;
block|}
if|if
condition|(
name|argv
operator|==
operator|*
name|argvp
operator|+
literal|1
condition|)
name|usage
argument_list|()
expr_stmt|;
name|argv
index|[
operator|-
literal|1
index|]
operator|=
name|NULL
expr_stmt|;
operator|*
name|argvp
operator|=
name|argv
expr_stmt|;
comment|/* move argv value */
block|}
end_function

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994 Henry Spencer.  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Henry Spencer of the University of Toronto.  *  * %sccs.include.redist.c%  *  *	@(#)regfree.c	8.2 (Berkeley) %G%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)regfree.c	8.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|"utils.h"
end_include

begin_include
include|#
directive|include
file|"regex2.h"
end_include

begin_comment
comment|/*  - regfree - free everything  = extern void regfree(regex_t *);  */
end_comment

begin_function
name|void
name|regfree
parameter_list|(
name|preg
parameter_list|)
name|regex_t
modifier|*
name|preg
decl_stmt|;
block|{
specifier|register
name|struct
name|re_guts
modifier|*
name|g
decl_stmt|;
if|if
condition|(
name|preg
operator|->
name|re_magic
operator|!=
name|MAGIC1
condition|)
comment|/* oops */
return|return;
comment|/* nice to complain, but hard */
name|g
operator|=
name|preg
operator|->
name|re_g
expr_stmt|;
if|if
condition|(
name|g
operator|==
name|NULL
operator|||
name|g
operator|->
name|magic
operator|!=
name|MAGIC2
condition|)
comment|/* oops again */
return|return;
name|preg
operator|->
name|re_magic
operator|=
literal|0
expr_stmt|;
comment|/* mark it invalid */
name|g
operator|->
name|magic
operator|=
literal|0
expr_stmt|;
comment|/* mark it invalid */
if|if
condition|(
name|g
operator|->
name|strip
operator|!=
name|NULL
condition|)
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|g
operator|->
name|strip
argument_list|)
expr_stmt|;
if|if
condition|(
name|g
operator|->
name|sets
operator|!=
name|NULL
condition|)
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|g
operator|->
name|sets
argument_list|)
expr_stmt|;
if|if
condition|(
name|g
operator|->
name|setbits
operator|!=
name|NULL
condition|)
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|g
operator|->
name|setbits
argument_list|)
expr_stmt|;
if|if
condition|(
name|g
operator|->
name|must
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|g
operator|->
name|must
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|g
argument_list|)
expr_stmt|;
block|}
end_function

end_unit


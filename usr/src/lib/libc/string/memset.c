begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)memset.c	5.6 (Berkeley) %G%"
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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|void
modifier|*
name|memset
parameter_list|(
name|dst
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
name|void
modifier|*
name|dst
decl_stmt|;
specifier|register
name|int
name|c
decl_stmt|;
specifier|register
name|size_t
name|n
decl_stmt|;
block|{
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
specifier|register
name|char
modifier|*
name|d
init|=
name|dst
decl_stmt|;
do|do
operator|*
name|d
operator|++
operator|=
name|c
expr_stmt|;
do|while
condition|(
operator|--
name|n
operator|!=
literal|0
condition|)
do|;
block|}
return|return
operator|(
name|dst
operator|)
return|;
block|}
end_function

end_unit


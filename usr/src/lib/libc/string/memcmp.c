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
literal|"@(#)memcmp.c	5.5 (Berkeley) %G%"
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/stdc.h>
end_include

begin_comment
comment|/*  * Compare memory regions.  */
end_comment

begin_function
name|int
name|memcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
specifier|const
name|void
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_decl_stmt
name|size_t
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
specifier|register
specifier|const
name|unsigned
name|char
modifier|*
name|p1
init|=
name|s1
decl_stmt|,
modifier|*
name|p2
init|=
name|s2
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|*
name|p1
operator|++
operator|!=
operator|*
name|p2
operator|++
condition|)
return|return
operator|(
operator|*
operator|--
name|p1
operator|-
operator|*
operator|--
name|p2
operator|)
return|;
block|}
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
literal|0
operator|)
return|;
block|}
end_block

end_unit


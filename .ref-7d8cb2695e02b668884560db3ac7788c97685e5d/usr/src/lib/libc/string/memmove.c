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
literal|"@(#)memmove.c	5.2 (Berkeley) %G%"
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
comment|/*  * Copy a block of memory, handling overlap.  */
end_comment

begin_function
name|void
modifier|*
name|memmove
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|length
parameter_list|)
name|void
modifier|*
name|dst
decl_stmt|;
specifier|const
name|void
modifier|*
name|src
decl_stmt|;
specifier|register
name|size_t
name|length
decl_stmt|;
block|{
name|bcopy
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|src
argument_list|,
operator|(
name|char
operator|*
operator|)
name|dst
argument_list|,
name|length
argument_list|)
expr_stmt|;
return|return
operator|(
name|dst
operator|)
return|;
block|}
end_function

end_unit


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
literal|"@(#)memcpy.c	5.5 (Berkeley) %G%"
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

begin_undef
undef|#
directive|undef
name|memcpy
end_undef

begin_comment
comment|/*  * Copy a block of memory.  */
end_comment

begin_function
name|void
modifier|*
name|memcpy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|n
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
name|size_t
name|n
decl_stmt|;
block|{
return|return
operator|(
name|memmove
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|n
argument_list|)
operator|)
return|;
block|}
end_function

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)strlen.c	5.4 (Berkeley) %G%"
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
file|<sys/stdc.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|size_t
name|strlen
parameter_list|(
name|str
parameter_list|)
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
block|{
specifier|register
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
for|for
control|(
name|s
operator|=
name|str
init|;
operator|*
name|s
condition|;
operator|++
name|s
control|)
empty_stmt|;
return|return
operator|(
name|s
operator|-
name|str
operator|)
return|;
block|}
end_function

end_unit


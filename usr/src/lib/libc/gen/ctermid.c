begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)ctermid.c	8.1 (Berkeley) %G%"
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|char
modifier|*
name|ctermid
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
specifier|static
name|char
name|def
index|[]
init|=
name|_PATH_TTY
decl_stmt|;
if|if
condition|(
name|s
condition|)
block|{
name|bcopy
argument_list|(
name|def
argument_list|,
name|s
argument_list|,
sizeof|sizeof
argument_list|(
name|_PATH_TTY
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
return|return
operator|(
name|def
operator|)
return|;
block|}
end_function

end_unit


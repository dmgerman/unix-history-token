begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)assert.c	8.1 (Berkeley) %G%"
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
file|<assert.h>
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

begin_function
name|void
name|__assert
parameter_list|(
name|file
parameter_list|,
name|line
parameter_list|,
name|failedexpr
parameter_list|)
specifier|const
name|char
modifier|*
name|file
decl_stmt|,
decl|*
name|failedexpr
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"assertion \"%s\" failed: file \"%s\", line %d\n"
argument_list|,
name|failedexpr
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_block

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)eprintf.c	5.2 (Berkeley) %G%"
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

begin_comment
comment|/* This is used by the `assert' macro.  */
end_comment

begin_function
name|void
name|__eprintf
parameter_list|(
name|string
parameter_list|,
name|line
parameter_list|,
name|filename
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|;
name|int
name|line
decl_stmt|;
name|char
modifier|*
name|filename
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|string
argument_list|,
name|line
argument_list|,
name|filename
argument_list|)
expr_stmt|;
block|}
end_function

end_unit


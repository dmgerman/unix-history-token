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

begin_expr_stmt
operator|.
name|asciz
literal|"@(#)eprintf.c	5.1 (Berkeley) %G%"
endif|#
directive|endif
comment|/* LIBC_SCCS and not lint */
include|#
directive|include
file|<stdio.h>
comment|/* This is used by the `assert' macro.  */
name|void
name|__eprintf
argument_list|(
argument|string
argument_list|,
argument|line
argument_list|,
argument|filename
argument_list|)
name|char
operator|*
name|string
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|filename
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
name|string
argument_list|,
name|line
argument_list|,
name|filename
argument_list|)
expr_stmt|;
block|}
end_block

end_unit


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
literal|"@(#)saveregs.c	5.1 (Berkeley) %G%"
endif|#
directive|endif
comment|/* LIBC_SCCS and not lint */
name|__builtin_saveregs
argument_list|()
block|{
name|abort
argument_list|()
block|; }
end_expr_stmt

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)rget.c	8.1 (Berkeley) %G%"
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
comment|/*  * Handle getc() when the buffer ran out:  * Refill, then return the first character  * in the newly-filled buffer.  */
end_comment

begin_expr_stmt
name|__srget
argument_list|(
name|fp
argument_list|)
specifier|register
name|FILE
operator|*
name|fp
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|__srefill
argument_list|(
name|fp
argument_list|)
operator|==
literal|0
condition|)
block|{
name|fp
operator|->
name|_r
operator|--
expr_stmt|;
return|return
operator|(
operator|*
name|fp
operator|->
name|_p
operator|++
operator|)
return|;
block|}
return|return
operator|(
name|EOF
operator|)
return|;
block|}
end_block

end_unit


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
literal|"@(#)fsetpos.c	8.1 (Berkeley) %G%"
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
comment|/*  * fsetpos: like fseek.  */
end_comment

begin_macro
name|fsetpos
argument_list|(
argument|iop
argument_list|,
argument|pos
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|iop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|fpos_t
modifier|*
name|pos
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|fseek
argument_list|(
name|iop
argument_list|,
operator|(
name|long
operator|)
operator|*
name|pos
argument_list|,
name|SEEK_SET
argument_list|)
operator|)
return|;
block|}
end_block

end_unit


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
literal|"@(#)putc.c	5.1 (Berkeley) %G%"
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
comment|/*  * A subroutine version of the macro putc.  */
end_comment

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_macro
name|putc
argument_list|(
argument|c
argument_list|,
argument|fp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|FILE
modifier|*
name|fp
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|__sputc
argument_list|(
name|c
argument_list|,
name|fp
argument_list|)
operator|)
return|;
block|}
end_block

end_unit


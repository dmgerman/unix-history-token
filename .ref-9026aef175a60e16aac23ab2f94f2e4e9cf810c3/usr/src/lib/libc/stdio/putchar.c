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
literal|"@(#)putchar.c	8.1 (Berkeley) %G%"
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

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_comment
comment|/*  * A subroutine version of the macro putchar  */
end_comment

begin_macro
name|putchar
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|FILE
modifier|*
name|so
init|=
name|stdout
decl_stmt|;
return|return
operator|(
name|__sputc
argument_list|(
name|c
argument_list|,
name|so
argument_list|)
operator|)
return|;
block|}
end_block

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)isatty.c	5.5 (Berkeley) %G%"
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
file|<termios.h>
end_include

begin_macro
name|isatty
argument_list|(
argument|fd
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|termios
name|t
decl_stmt|;
return|return
operator|(
name|tcgetattr
argument_list|(
name|fd
argument_list|,
operator|&
name|t
argument_list|)
operator|!=
operator|-
literal|1
operator|)
return|;
block|}
end_block

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)creat.c	8.1 (Berkeley) %G%"
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
file|<fcntl.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|creat
argument_list|(
argument|const char *path
argument_list|,
argument|mode_t mode
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|creat
argument_list|(
argument|path
argument_list|,
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mode_t
name|mode
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
return|return
operator|(
name|open
argument_list|(
name|path
argument_list|,
name|O_WRONLY
operator||
name|O_CREAT
operator||
name|O_TRUNC
argument_list|,
name|mode
argument_list|)
operator|)
return|;
block|}
end_block

end_unit


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
literal|"@(#)vprintf.c	5.5 (Berkeley) %G%"
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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|vprintf
argument_list|(
argument|fmt
argument_list|,
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|char
specifier|const
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_VA_LIST_
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|vfprintf
argument_list|(
name|stdout
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
operator|)
return|;
block|}
end_block

end_unit


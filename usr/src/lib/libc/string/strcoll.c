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
literal|"@(#)strcoll.c	5.1 (Berkeley) %G%"
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/stdc.h>
end_include

begin_comment
comment|/*  * Compare strings according to LC_COLLATE category of current locale.  */
end_comment

begin_macro
name|strcoll
argument_list|(
argument|s1
argument_list|,
argument|s2
argument_list|)
end_macro

begin_decl_stmt
specifier|const
name|char
modifier|*
name|s1
decl_stmt|,
modifier|*
name|s2
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* LC_COLLATE is unimplemented, hence always "C" */
return|return
operator|(
name|strcmp
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
operator|)
return|;
block|}
end_block

end_unit


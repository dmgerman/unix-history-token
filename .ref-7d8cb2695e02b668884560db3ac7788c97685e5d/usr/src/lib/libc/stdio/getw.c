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
literal|"@(#)getw.c	8.1 (Berkeley) %G%"
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

begin_macro
name|getw
argument_list|(
argument|fp
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|fp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|;
return|return
operator|(
name|fread
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
name|x
argument_list|,
sizeof|sizeof
argument_list|(
name|x
argument_list|)
argument_list|,
literal|1
argument_list|,
name|fp
argument_list|)
operator|==
literal|1
condition|?
name|x
else|:
name|EOF
operator|)
return|;
block|}
end_block

end_unit


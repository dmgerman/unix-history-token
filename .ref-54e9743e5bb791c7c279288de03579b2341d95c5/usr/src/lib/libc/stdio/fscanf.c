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
literal|"@(#)fscanf.c	8.1 (Berkeley) %G%"
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

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|fscanf
argument_list|(
argument|FILE *fp
argument_list|,
argument|char const *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|int
name|ret
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|fscanf
argument_list|(
argument|fp
argument_list|,
argument|fmt
argument_list|,
argument|va_alist
argument_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
modifier|*
name|fmt
decl_stmt|;
name|va_dcl
block|{
name|int
name|ret
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ret
operator|=
name|__svfscanf
argument_list|(
name|fp
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block

end_unit


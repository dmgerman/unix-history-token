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
literal|"@(#)snprintf.c	8.1 (Berkeley) %G%"
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
name|snprintf
argument_list|(
argument|char *str
argument_list|,
argument|size_t n
argument_list|,
argument|char const *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|snprintf
argument_list|(
argument|str
argument_list|,
argument|n
argument_list|,
argument|fmt
argument_list|,
argument|va_alist
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|int
name|ret
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|FILE
name|f
decl_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|n
operator|<
literal|1
condition|)
return|return
operator|(
name|EOF
operator|)
return|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|f
operator|.
name|_flags
operator|=
name|__SWR
operator||
name|__SSTR
expr_stmt|;
name|f
operator|.
name|_bf
operator|.
name|_base
operator|=
name|f
operator|.
name|_p
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|str
expr_stmt|;
name|f
operator|.
name|_bf
operator|.
name|_size
operator|=
name|f
operator|.
name|_w
operator|=
name|n
operator|-
literal|1
expr_stmt|;
name|ret
operator|=
name|vfprintf
argument_list|(
operator|&
name|f
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
operator|*
name|f
operator|.
name|_p
operator|=
literal|0
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


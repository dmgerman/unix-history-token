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
literal|"@(#)flags.c	5.1 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/*  * Return the (stdio) flags for a given mode.  Store the flags  * to be passed to an open() syscall through *optr.  * Return 0 on error.  */
end_comment

begin_expr_stmt
name|__sflags
argument_list|(
name|mode
argument_list|,
name|optr
argument_list|)
specifier|register
name|char
operator|*
name|mode
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
modifier|*
name|optr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|ret
decl_stmt|,
name|m
decl_stmt|,
name|o
decl_stmt|;
switch|switch
condition|(
operator|*
name|mode
operator|++
condition|)
block|{
case|case
literal|'r'
case|:
comment|/* open for reading */
name|ret
operator|=
name|__SRD
expr_stmt|;
name|m
operator|=
name|O_RDONLY
expr_stmt|;
name|o
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'w'
case|:
comment|/* open for writing */
name|ret
operator|=
name|__SWR
expr_stmt|;
name|m
operator|=
name|O_WRONLY
expr_stmt|;
name|o
operator|=
name|O_CREAT
operator||
name|O_TRUNC
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
comment|/* open for appending */
name|ret
operator|=
name|__SWR
expr_stmt|;
name|m
operator|=
name|O_WRONLY
expr_stmt|;
name|o
operator|=
name|O_CREAT
operator||
name|O_APPEND
expr_stmt|;
break|break;
default|default:
comment|/* illegal mode */
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* [rwa]\+ or [rwa]b\+ means read and write */
if|if
condition|(
operator|*
name|mode
operator|==
literal|'+'
operator|||
operator|(
operator|*
name|mode
operator|==
literal|'b'
operator|&&
name|mode
index|[
literal|1
index|]
operator|==
literal|'+'
operator|)
condition|)
block|{
name|ret
operator|=
name|__SRW
expr_stmt|;
name|m
operator|=
name|O_RDWR
expr_stmt|;
block|}
operator|*
name|optr
operator|=
name|m
operator||
name|o
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block

end_unit


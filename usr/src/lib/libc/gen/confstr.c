begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)confstr.c	5.1 (Berkeley) %G%"
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|size_t
name|confstr
parameter_list|(
name|name
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
name|int
name|name
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|{
switch|switch
condition|(
name|name
condition|)
block|{
case|case
name|_CS_PATH
case|:
if|if
condition|(
name|len
operator|!=
literal|0
operator|&&
name|buf
operator|!=
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|buf
argument_list|,
name|_PATH_DEFPATH
argument_list|,
name|len
operator|-
literal|1
argument_list|)
expr_stmt|;
name|buf
index|[
name|len
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
return|return
operator|(
sizeof|sizeof
argument_list|(
name|_PATH_DEFPATH
argument_list|)
operator|)
return|;
default|default:
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
comment|/* NOTREACHED */
block|}
end_function

end_unit


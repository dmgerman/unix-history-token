begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)recv.c	8.2 (Berkeley) %G%"
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
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function
name|ssize_t
name|recv
parameter_list|(
name|s
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|,
name|flags
parameter_list|)
name|int
name|s
decl_stmt|,
name|flags
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
block|{
return|return
operator|(
name|recvfrom
argument_list|(
name|s
argument_list|,
name|buf
argument_list|,
name|len
argument_list|,
name|flags
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit


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
literal|"@(#)recv.c	5.2 (Berkeley) %G%"
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
file|<stdio.h>
end_include

begin_macro
name|recv
argument_list|(
argument|s
argument_list|,
argument|buf
argument_list|,
argument|len
argument_list|,
argument|flags
argument_list|)
end_macro

begin_decl_stmt
name|int
name|s
decl_stmt|,
name|len
decl_stmt|,
name|flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_block
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
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
name|NULL
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_block

end_unit


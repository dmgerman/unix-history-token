begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)perror.c	5.3 (Berkeley) 9/30/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * Print the error indicated  * in the cerror cell.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_macro
name|perror
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|iovec
name|iov
index|[
literal|4
index|]
decl_stmt|;
specifier|register
name|struct
name|iovec
modifier|*
name|v
init|=
name|iov
decl_stmt|;
if|if
condition|(
name|s
operator|&&
operator|*
name|s
condition|)
block|{
name|v
operator|->
name|iov_base
operator|=
name|s
expr_stmt|;
name|v
operator|->
name|iov_len
operator|=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|v
operator|++
expr_stmt|;
name|v
operator|->
name|iov_base
operator|=
literal|": "
expr_stmt|;
name|v
operator|->
name|iov_len
operator|=
literal|2
expr_stmt|;
name|v
operator|++
expr_stmt|;
block|}
name|v
operator|->
name|iov_base
operator|=
name|errno
operator|<
name|sys_nerr
condition|?
name|sys_errlist
index|[
name|errno
index|]
else|:
literal|"Unknown error"
expr_stmt|;
name|v
operator|->
name|iov_len
operator|=
name|strlen
argument_list|(
name|v
operator|->
name|iov_base
argument_list|)
expr_stmt|;
name|v
operator|++
expr_stmt|;
name|v
operator|->
name|iov_base
operator|=
literal|"\n"
expr_stmt|;
name|v
operator|->
name|iov_len
operator|=
literal|1
expr_stmt|;
name|writev
argument_list|(
literal|2
argument_list|,
name|iov
argument_list|,
operator|(
name|v
operator|-
name|iov
operator|)
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit


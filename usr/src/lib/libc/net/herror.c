begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)herror.c	6.5 (Berkeley) %G%"
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
file|<sys/uio.h>
end_include

begin_decl_stmt
name|char
modifier|*
name|h_errlist
index|[]
init|=
block|{
literal|"Error 0"
block|,
literal|"Unknown host"
block|,
comment|/* 1 HOST_NOT_FOUND */
literal|"Host name lookup failure"
block|,
comment|/* 2 TRY_AGAIN */
literal|"Unknown server error"
block|,
comment|/* 3 NO_RECOVERY */
literal|"No address associated with name"
block|,
comment|/* 4 NO_ADDRESS */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|h_nerr
init|=
block|{
sizeof|sizeof
argument_list|(
name|h_errlist
argument_list|)
operator|/
expr|sizeof
operator|(
name|h_errlist
index|[
literal|0
index|]
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * herror --  *	print the error indicated by the h_errno value.  */
end_comment

begin_macro
name|herror
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
operator|(
name|u_int
operator|)
name|h_errno
operator|<
name|h_nerr
condition|?
name|h_errlist
index|[
name|h_errno
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


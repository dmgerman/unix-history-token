begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)utime.c	5.3 (Berkeley) %G%"
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
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<utime.h>
end_include

begin_macro
name|utime
argument_list|(
argument|path
argument_list|,
argument|times
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|utimbuf
modifier|*
name|times
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|timeval
name|tv
index|[
literal|2
index|]
decl_stmt|;
name|tv
index|[
literal|0
index|]
operator|.
name|tv_sec
operator|=
name|times
operator|->
name|actime
expr_stmt|;
name|tv
index|[
literal|1
index|]
operator|.
name|tv_sec
operator|=
name|times
operator|->
name|modtime
expr_stmt|;
name|tv
index|[
literal|0
index|]
operator|.
name|tv_usec
operator|=
name|tv
index|[
literal|1
index|]
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|utimes
argument_list|(
name|path
argument_list|,
name|tv
argument_list|)
operator|)
return|;
block|}
end_block

end_unit


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
literal|"@(#)utime.c	5.2 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/*  * Backwards compatible utime.  */
end_comment

begin_macro
name|utime
argument_list|(
argument|name
argument_list|,
argument|otv
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|otv
index|[]
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
name|otv
index|[
literal|0
index|]
expr_stmt|;
name|tv
index|[
literal|0
index|]
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|tv
index|[
literal|1
index|]
operator|.
name|tv_sec
operator|=
name|otv
index|[
literal|1
index|]
expr_stmt|;
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
name|name
argument_list|,
name|tv
argument_list|)
operator|)
return|;
block|}
end_block

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)mat.c	5.1 (Berkeley) 4/30/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * mat: retrieve the value in m[r, c].  * rows and cols are the size of the matrix in all these routines.  */
end_comment

begin_include
include|#
directive|include
file|"bit.h"
end_include

begin_function
name|int
name|mat
parameter_list|(
name|m
parameter_list|,
name|rows
parameter_list|,
name|cols
parameter_list|,
name|r
parameter_list|,
name|c
parameter_list|)
specifier|register
name|bitmat
name|m
decl_stmt|;
specifier|register
name|int
name|c
decl_stmt|;
name|int
name|rows
decl_stmt|,
name|cols
decl_stmt|,
name|r
decl_stmt|;
block|{
specifier|register
name|int
name|thisbyte
decl_stmt|;
name|thisbyte
operator|=
name|m
index|[
name|r
operator|*
operator|(
operator|(
name|cols
operator|+
literal|7
operator|)
operator|>>
literal|3
operator|)
operator|+
operator|(
name|c
operator|>>
literal|3
operator|)
index|]
operator|&
literal|0xff
expr_stmt|;
name|thisbyte
operator|&=
literal|0x80
operator|>>
operator|(
name|c
operator|&
literal|7
operator|)
expr_stmt|;
return|return
operator|(
name|thisbyte
operator|!=
literal|0
operator|)
return|;
block|}
end_function

end_unit


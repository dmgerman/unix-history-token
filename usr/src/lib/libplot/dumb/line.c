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
literal|"@(#)line.c	5.1 (Berkeley) 5/7/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"dumb.h"
end_include

begin_macro
name|line
argument_list|(
argument|x0
argument_list|,
argument|y0
argument_list|,
argument|x1
argument_list|,
argument|y1
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x0
decl_stmt|,
name|y0
decl_stmt|,
name|x1
decl_stmt|,
name|y1
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|scale
argument_list|(
name|x0
argument_list|,
name|y0
argument_list|)
expr_stmt|;
name|x
operator|=
name|x1
expr_stmt|;
name|y
operator|=
name|y1
expr_stmt|;
name|scale
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|currentx
operator|=
name|x0
expr_stmt|;
name|currenty
operator|=
name|y0
expr_stmt|;
name|screenmat
index|[
name|currentx
index|]
index|[
name|currenty
index|]
operator|=
literal|'*'
expr_stmt|;
name|dda_line
argument_list|(
literal|'*'
argument_list|,
name|x0
argument_list|,
name|y0
argument_list|,
name|x1
argument_list|,
name|y1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit


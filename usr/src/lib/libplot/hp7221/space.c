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
literal|"@(#)space.c	5.1 (Berkeley) 5/7/85"
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
file|"hp7221.h"
end_include

begin_macro
name|space
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
name|double
name|scalex
decl_stmt|,
name|scaley
decl_stmt|;
name|lowx
operator|=
name|x0
expr_stmt|;
name|lowy
operator|=
name|y0
expr_stmt|;
name|scalex
operator|=
name|XMAX
operator|/
call|(
name|double
call|)
argument_list|(
name|x1
operator|-
name|lowx
argument_list|)
expr_stmt|;
name|scaley
operator|=
name|YMAX
operator|/
call|(
name|double
call|)
argument_list|(
name|y1
operator|-
name|lowy
argument_list|)
expr_stmt|;
name|scale
operator|=
name|scalex
operator|<
name|scaley
condition|?
name|scalex
else|:
name|scaley
expr_stmt|;
block|}
end_block

end_unit


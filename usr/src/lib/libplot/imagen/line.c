begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)line.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"imp.h"
end_include

begin_include
include|#
directive|include
file|"imPcodes.h"
end_include

begin_decl_stmt
name|float
name|obotx
init|=
literal|0.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|oboty
init|=
literal|0.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|botx
init|=
literal|2.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|boty
init|=
literal|2.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|scalex
init|=
literal|1.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|scaley
init|=
literal|1.
decl_stmt|;
end_decl_stmt

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

begin_block
block|{
name|putch
argument_list|(
name|imP_CREATE_PATH
argument_list|)
expr_stmt|;
name|putwd
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* two coordinates follow */
name|putwd
argument_list|(
call|(
name|int
call|)
argument_list|(
operator|(
name|x0
operator|-
name|obotx
operator|)
operator|*
name|scalex
operator|+
name|botx
argument_list|)
argument_list|)
expr_stmt|;
name|putwd
argument_list|(
call|(
name|int
call|)
argument_list|(
operator|(
name|y0
operator|-
name|oboty
operator|)
operator|*
name|scaley
operator|+
name|boty
argument_list|)
argument_list|)
expr_stmt|;
name|putwd
argument_list|(
call|(
name|int
call|)
argument_list|(
operator|(
name|x1
operator|-
name|obotx
operator|)
operator|*
name|scalex
operator|+
name|botx
argument_list|)
argument_list|)
expr_stmt|;
name|putwd
argument_list|(
call|(
name|int
call|)
argument_list|(
operator|(
name|y1
operator|-
name|oboty
operator|)
operator|*
name|scaley
operator|+
name|boty
argument_list|)
argument_list|)
expr_stmt|;
name|putch
argument_list|(
name|imP_DRAW_PATH
argument_list|)
expr_stmt|;
name|putch
argument_list|(
literal|15
argument_list|)
expr_stmt|;
comment|/* "black" lines */
name|imPx
operator|=
name|x1
expr_stmt|;
name|imPy
operator|=
name|y1
expr_stmt|;
block|}
end_block

begin_macro
name|putch
argument_list|(
argument|c
argument_list|)
end_macro

begin_block
block|{
name|putc
argument_list|(
name|c
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|putwd
argument_list|(
argument|w
argument_list|)
end_macro

begin_block
block|{
name|putch
argument_list|(
name|w
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|putch
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_block

end_unit


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
literal|"@(#)drawbox.c	5.1 (Berkeley) 4/30/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Draw a box around a window.  The lower left corner of the box is at (r, c).  * Color is 1 for drawing a box, 0 for erasing.  * The box is nrow by ncol.  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|drawbox
argument_list|(
argument|r
argument_list|,
argument|c
argument_list|,
argument|color
argument_list|,
argument|nrow
argument_list|,
argument|ncol
argument_list|)
end_macro

begin_decl_stmt
name|int
name|r
decl_stmt|,
name|c
decl_stmt|,
name|color
decl_stmt|,
name|nrow
decl_stmt|,
name|ncol
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|color
condition|)
name|setset
argument_list|()
expr_stmt|;
else|else
name|setclear
argument_list|()
expr_stmt|;
name|move
argument_list|(
name|c
argument_list|,
name|r
argument_list|)
expr_stmt|;
name|draw
argument_list|(
name|c
operator|+
name|ncol
operator|-
literal|1
argument_list|,
name|r
argument_list|)
expr_stmt|;
name|draw
argument_list|(
name|c
operator|+
name|ncol
operator|-
literal|1
argument_list|,
name|r
operator|+
name|nrow
operator|-
literal|1
argument_list|)
expr_stmt|;
name|draw
argument_list|(
name|c
argument_list|,
name|r
operator|+
name|nrow
operator|-
literal|1
argument_list|)
expr_stmt|;
name|draw
argument_list|(
name|c
argument_list|,
name|r
argument_list|)
expr_stmt|;
block|}
end_block

end_unit


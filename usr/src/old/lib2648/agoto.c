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
literal|"@(#)agoto.c	5.1 (Berkeley) 4/26/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * position the alphanumeric cursor to (x, y).  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|agoto
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|mes
index|[
literal|20
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|mes
argument_list|,
literal|"\33*dE\33&a%dr%dC"
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|outstr
argument_list|(
name|mes
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * lower left corner of screen.  */
end_comment

begin_macro
name|lowleft
argument_list|()
end_macro

begin_block
block|{
name|outstr
argument_list|(
literal|"\33F"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit


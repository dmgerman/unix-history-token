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
literal|"@(#)idlok.c	5.1 (Berkeley) 6/7/85"
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
file|"curses.ext"
end_include

begin_comment
comment|/*  * idlok:  *	Turn on and off using insert/deleteln sequences for the given  *	window.  *  */
end_comment

begin_expr_stmt
name|idlok
argument_list|(
name|win
argument_list|,
name|bf
argument_list|)
specifier|register
name|WINDOW
operator|*
name|win
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|bf
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|bf
condition|)
name|win
operator|->
name|_flags
operator||=
name|_IDLINE
expr_stmt|;
else|else
name|win
operator|->
name|_flags
operator|&=
operator|~
name|_IDLINE
expr_stmt|;
block|}
end_block

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  Sendmail **  Copyright (c) 1983  Eric P. Allman **  Berkeley, California ** **  Copyright (c) 1983 Regents of the University of California. **  All rights reserved.  The Berkeley software License Agreement **  specifies the terms and conditions for redistribution. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|SccsId
index|[]
init|=
literal|"@(#)bcopy.c	5.1 (Berkeley) 6/7/85"
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
file|"useful.h"
end_include

begin_comment
comment|/* **  BCOPY -- block copy. ** **	Parameters: **		s -- source of bytes. **		d -- destination of bytes. **		l -- length of block to move. ** **	Returns: **		none. ** **	Side Effects: **		copies 's' to 'd' for 'l' bytes. ** **	Notes: **		This can be easily written in assembly language on **		machines like VAXes if performance is needed. */
end_comment

begin_comment
comment|/*VARARGS0*/
end_comment

begin_expr_stmt
name|bcopy
argument_list|(
name|s
argument_list|,
name|d
argument_list|,
name|l
argument_list|)
specifier|register
name|char
operator|*
name|s
operator|,
operator|*
name|d
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|l
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|l
operator|--
operator|>
literal|0
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  BZERO -- zero a block of memory ** **	Parameters: **		p -- location to clear. **		l -- number of bytes to clear. ** **	Returns: **		none. ** **	Side Effects: **		none. */
end_comment

begin_expr_stmt
name|bzero
argument_list|(
name|p
argument_list|,
name|l
argument_list|)
specifier|register
name|char
operator|*
name|p
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|l
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|l
operator|--
operator|>
literal|0
condition|)
operator|*
name|p
operator|++
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit


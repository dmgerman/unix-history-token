begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)scroll.c	5.4 (Berkeley) %G%"
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
file|"curses.ext"
end_include

begin_comment
comment|/*  *	This routine scrolls the window up a line.  *  */
end_comment

begin_expr_stmt
name|scroll
argument_list|(
name|win
argument_list|)
specifier|register
name|WINDOW
operator|*
name|win
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|oy
decl_stmt|,
name|ox
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|outf
argument_list|,
literal|"SCROLL(%0.2o)\n"
argument_list|,
name|win
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|win
operator|->
name|_scroll
condition|)
return|return
name|ERR
return|;
name|getyx
argument_list|(
name|win
argument_list|,
name|oy
argument_list|,
name|ox
argument_list|)
expr_stmt|;
name|wmove
argument_list|(
name|win
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|wdeleteln
argument_list|(
name|win
argument_list|)
expr_stmt|;
name|wmove
argument_list|(
name|win
argument_list|,
name|oy
argument_list|,
name|ox
argument_list|)
expr_stmt|;
if|if
condition|(
name|win
operator|==
name|curscr
condition|)
block|{
name|_putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|NONL
condition|)
name|win
operator|->
name|_curx
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|outf
argument_list|,
literal|"SCROLL: win == curscr\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_block

end_unit


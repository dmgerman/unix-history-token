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
literal|"@(#)move.c	5.5 (Berkeley) %G%"
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
comment|/*  *	This routine moves the cursor to the given point  *  */
end_comment

begin_macro
name|wmove
argument_list|(
argument|win
argument_list|,
argument|y
argument_list|,
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|reg
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|outf
argument_list|,
literal|"MOVE to (%d, %d)\n"
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|x
operator|<
literal|0
operator|||
name|y
operator|<
literal|0
condition|)
return|return
name|ERR
return|;
if|if
condition|(
name|x
operator|>=
name|win
operator|->
name|_maxx
operator|||
name|y
operator|>=
name|win
operator|->
name|_maxy
condition|)
return|return
name|ERR
return|;
name|win
operator|->
name|_curx
operator|=
name|x
expr_stmt|;
name|win
operator|->
name|_cury
operator|=
name|y
expr_stmt|;
return|return
name|OK
return|;
block|}
end_block

end_unit


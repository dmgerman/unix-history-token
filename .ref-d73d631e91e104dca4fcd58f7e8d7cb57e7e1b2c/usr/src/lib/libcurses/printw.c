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
literal|"@(#)printw.c	5.5 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * printw and friends  *  */
end_comment

begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  *	This routine implements a printf on the standard screen.  */
end_comment

begin_macro
name|printw
argument_list|(
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|buf
index|[
literal|512
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|vsprintf
argument_list|(
name|buf
argument_list|,
name|fmt
argument_list|,
operator|&
name|args
argument_list|)
expr_stmt|;
return|return
name|waddstr
argument_list|(
name|stdscr
argument_list|,
name|buf
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/*  *	This routine implements a printf on the given window.  */
end_comment

begin_macro
name|wprintw
argument_list|(
argument|win
argument_list|,
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|buf
index|[
literal|512
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|vsprintf
argument_list|(
name|buf
argument_list|,
name|fmt
argument_list|,
operator|&
name|args
argument_list|)
expr_stmt|;
return|return
name|waddstr
argument_list|(
name|win
argument_list|,
name|buf
argument_list|)
return|;
block|}
end_block

end_unit


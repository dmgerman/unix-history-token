begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)talk.h	8.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|sockt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|curses_initialized
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|invitation_waiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_line
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|xwin
block|{
name|WINDOW
modifier|*
name|x_win
decl_stmt|;
name|int
name|x_nlines
decl_stmt|;
name|int
name|x_ncols
decl_stmt|;
name|int
name|x_line
decl_stmt|;
name|int
name|x_col
decl_stmt|;
name|char
name|kill
decl_stmt|;
name|char
name|cerase
decl_stmt|;
name|char
name|werase
decl_stmt|;
block|}
name|xwin_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|xwin_t
name|my_win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xwin_t
name|his_win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|line_win
decl_stmt|;
end_decl_stmt

end_unit


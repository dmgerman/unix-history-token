begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)talk.h	5.4 (Berkeley) 6/29/88  */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_define
define|#
directive|define
name|forever
value|for(;;)
end_define

begin_function_decl
name|int
name|quit
parameter_list|()
function_decl|;
end_function_decl

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


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)talk.h	5.7 (Berkeley) 3/1/91  */
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


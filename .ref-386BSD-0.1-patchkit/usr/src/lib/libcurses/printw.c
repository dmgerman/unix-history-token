begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)printw.c	5.8 (Berkeley) 4/15/91"
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
comment|/*  * printw and friends.  *  * These routines make nonportable assumptions about varargs if __STDC__  * is not in effect.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  *	This routine implements a printf on the standard screen.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|printw
argument_list|(
argument|const char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|printw
argument_list|(
argument|fmt
argument_list|,
argument|va_alist
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|va_list
name|ap
decl_stmt|;
name|int
name|ret
decl_stmt|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ret
operator|=
name|_sprintw
argument_list|(
name|stdscr
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  *	This routine implements a printf on the given window.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|wprintw
argument_list|(
argument|WINDOW *win
argument_list|,
argument|const char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|wprintw
argument_list|(
argument|win
argument_list|,
argument|fmt
argument_list|,
argument|va_alist
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

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|va_list
name|ap
decl_stmt|;
name|int
name|ret
decl_stmt|;
ifdef|#
directive|ifdef
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ret
operator|=
name|_sprintw
argument_list|(
name|win
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  *	Internal write-buffer-to-window function.  */
end_comment

begin_function
specifier|static
name|int
name|_winwrite
parameter_list|(
name|cookie
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
name|void
modifier|*
name|cookie
decl_stmt|;
specifier|register
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|n
decl_stmt|;
block|{
specifier|register
name|WINDOW
modifier|*
name|win
init|=
operator|(
name|WINDOW
operator|*
operator|)
name|cookie
decl_stmt|;
specifier|register
name|int
name|c
init|=
name|n
decl_stmt|;
while|while
condition|(
operator|--
name|c
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|waddch
argument_list|(
name|win
argument_list|,
operator|*
name|buf
operator|++
argument_list|)
operator|==
name|ERR
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|/*  *	This routine actually executes the printf and adds it to the window.  *	It must not be declared static as it is used in mvprintw.c.  *	THIS SHOULD BE RENAMED vwprintw AND EXPORTED  */
end_comment

begin_macro
name|_sprintw
argument_list|(
argument|win
argument_list|,
argument|fmt
argument_list|,
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|va_list
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|f
decl_stmt|;
if|if
condition|(
operator|(
name|f
operator|=
name|fwopen
argument_list|(
operator|(
name|void
operator|*
operator|)
name|win
argument_list|,
name|_winwrite
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
name|ERR
return|;
operator|(
name|void
operator|)
name|vfprintf
argument_list|(
name|f
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
return|return
name|fclose
argument_list|(
name|f
argument_list|)
condition|?
name|ERR
else|:
name|OK
return|;
block|}
end_block

end_unit


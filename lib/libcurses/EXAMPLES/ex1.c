begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1992, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)ex1.c	8.1 (Berkeley) 6/4/93"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|YSIZE
value|10
end_define

begin_define
define|#
directive|define
name|XSIZE
value|20
end_define

begin_function_decl
name|int
name|quit
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|c
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|char
name|id
index|[
literal|100
index|]
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
name|initscr
argument_list|()
expr_stmt|;
comment|/* Always call initscr() first */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|quit
argument_list|)
expr_stmt|;
comment|/* Make sure wou have a 'cleanup' fn */
name|crmode
argument_list|()
expr_stmt|;
comment|/* We want cbreak mode */
name|noecho
argument_list|()
expr_stmt|;
comment|/* We want to have control of chars */
name|delwin
argument_list|(
name|stdscr
argument_list|)
expr_stmt|;
comment|/* Create our own stdscr */
name|stdscr
operator|=
name|newwin
argument_list|(
name|YSIZE
argument_list|,
name|XSIZE
argument_list|,
literal|10
argument_list|,
literal|35
argument_list|)
expr_stmt|;
name|flushok
argument_list|(
name|stdscr
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
comment|/* Enable flushing of stdout */
name|scrollok
argument_list|(
name|stdscr
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
comment|/* Enable scrolling */
name|erase
argument_list|()
expr_stmt|;
comment|/* Initially, clear the screen */
name|standout
argument_list|()
expr_stmt|;
name|move
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|c
operator|=
name|getchar
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'q'
case|:
comment|/* Quit on 'q' */
name|quit
argument_list|()
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
comment|/* Go into standout mode on 's' */
name|standout
argument_list|()
expr_stmt|;
break|break;
case|case
literal|'e'
case|:
comment|/* Exit standout mode on 'e' */
name|standend
argument_list|()
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
comment|/* Force a refresh on 'r' */
name|wrefresh
argument_list|(
name|curscr
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* By default output the character */
name|addch
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function

begin_function
name|int
name|quit
parameter_list|()
block|{
name|erase
argument_list|()
expr_stmt|;
comment|/* Terminate by erasing the screen */
name|refresh
argument_list|()
expr_stmt|;
name|endwin
argument_list|()
expr_stmt|;
comment|/* Always end with endwin() */
name|delwin
argument_list|(
name|curscr
argument_list|)
expr_stmt|;
comment|/* Return storage */
name|delwin
argument_list|(
name|stdscr
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit


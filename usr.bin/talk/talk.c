begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)talk.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1983, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|"talk.h"
end_include

begin_comment
comment|/*  * talk:	A visual form of write. Using sockets, a two way  *		connection is set up between the two people talking.  *		With the aid of curses, the screen is split into two  *		windows, and each users text is added to the window,  *		one character at a time...  *  *		Written by Kipp Hickman  *  *		Modified to run under 4.1a by Clem Cole and Peter Moore  *		Modified to run between hosts by Peter Moore, 8/19/82  *		Modified to run under 4.1c by Peter Moore 3/17/83  *		Fixed to not run with unwriteable terminals MRVM 28/12/94  */
end_comment

begin_function_decl
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|get_names
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|check_writeable
argument_list|()
expr_stmt|;
name|init_display
argument_list|()
expr_stmt|;
name|open_ctl
argument_list|()
expr_stmt|;
name|open_sockt
argument_list|()
expr_stmt|;
name|start_msgs
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|check_local
argument_list|()
condition|)
name|invite_remote
argument_list|()
expr_stmt|;
name|end_msgs
argument_list|()
expr_stmt|;
name|set_edit_chars
argument_list|()
expr_stmt|;
name|talk
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit


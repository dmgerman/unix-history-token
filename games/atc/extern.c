begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ed James.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987 by Ed James, UC Berkeley.  All rights reserved.  *  * Copy permission is hereby granted provided that this notice is  * retained on all partial or complete copies.  *  * For more info on this and all of my stuff, mail edjames@berkeley.edu.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)extern.c	8.1 (Berkeley) 5/31/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
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
file|"include.h"
end_include

begin_decl_stmt
name|char
name|GAMES
index|[]
init|=
literal|"Game_List"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|clck
decl_stmt|,
name|safe_planes
decl_stmt|,
name|start_time
decl_stmt|,
name|test_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|filein
decl_stmt|,
modifier|*
name|fileout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|C_SCREEN
name|screen
decl_stmt|,
modifier|*
name|sp
init|=
operator|&
name|screen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIST
name|air
decl_stmt|,
name|ground
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sgttyb
name|tty_start
decl_stmt|,
name|tty_new
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DISPLACEMENT
name|displacement
index|[
name|MAXDIR
index|]
init|=
block|{
block|{
literal|0
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|1
block|,
literal|0
block|}
block|,
block|{
literal|1
block|,
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|1
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|1
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit


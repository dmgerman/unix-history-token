begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Timothy C. Stoehr.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

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
literal|"@(#) Copyright (c) 1988, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)main.c	8.1 (Berkeley) 5/31/93";
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

begin_comment
comment|/*  * main.c  *  * This source herein may be modified and/or distributed by anybody who  * so desires, with the following restrictions:  *    1.)  No portion of this notice shall be removed.  *    2.)  Credit shall not be taken for the creation of this source.  *    3.)  This code is not to be traded, sold, or used for personal  *         gain or profit.  *  */
end_comment

begin_include
include|#
directive|include
file|"rogue.h"
end_include

begin_decl_stmt
specifier|extern
name|short
name|party_room
decl_stmt|;
end_decl_stmt

begin_function
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
if|if
condition|(
name|init
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
condition|)
block|{
comment|/* restored game */
goto|goto
name|PL
goto|;
block|}
for|for
control|(
init|;
condition|;
control|)
block|{
name|clear_level
argument_list|()
expr_stmt|;
name|make_level
argument_list|()
expr_stmt|;
name|put_objects
argument_list|()
expr_stmt|;
name|put_stairs
argument_list|()
expr_stmt|;
name|add_traps
argument_list|()
expr_stmt|;
name|put_mons
argument_list|()
expr_stmt|;
name|put_player
argument_list|(
name|party_room
argument_list|)
expr_stmt|;
name|print_stats
argument_list|(
name|STAT_ALL
argument_list|)
expr_stmt|;
name|PL
label|:
name|play_level
argument_list|()
expr_stmt|;
name|free_stuff
argument_list|(
operator|&
name|level_objects
argument_list|)
expr_stmt|;
name|free_stuff
argument_list|(
operator|&
name|level_monsters
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit


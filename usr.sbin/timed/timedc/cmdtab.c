begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)cmdtab.c	8.1 (Berkeley) 6/6/93";
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
file|"timedc.h"
end_include

begin_decl_stmt
name|char
name|clockdiffhelp
index|[]
init|=
literal|"measures clock differences between machines"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|helphelp
index|[]
init|=
literal|"gets help on commands"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|msitehelp
index|[]
init|=
literal|"finds location of master"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|quithelp
index|[]
init|=
literal|"exits timedc"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|testinghelp
index|[]
init|=
literal|"causes election timers to expire"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|tracinghelp
index|[]
init|=
literal|"turns tracing on or off"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cmd
name|cmdtab
index|[]
init|=
block|{
block|{
literal|"clockdiff"
block|,
name|clockdiffhelp
block|,
name|clockdiff
block|,
literal|0
block|}
block|,
block|{
literal|"election"
block|,
name|testinghelp
block|,
name|testing
block|,
literal|1
block|}
block|,
block|{
literal|"help"
block|,
name|helphelp
block|,
name|help
block|,
literal|0
block|}
block|,
block|{
literal|"msite"
block|,
name|msitehelp
block|,
name|msite
block|,
literal|0
block|}
block|,
block|{
literal|"quit"
block|,
name|quithelp
block|,
name|quit
block|,
literal|0
block|}
block|,
block|{
literal|"trace"
block|,
name|tracinghelp
block|,
name|tracing
block|,
literal|1
block|}
block|,
block|{
literal|"?"
block|,
name|helphelp
block|,
name|help
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|NCMDS
init|=
sizeof|sizeof
argument_list|(
name|cmdtab
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|cmdtab
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit


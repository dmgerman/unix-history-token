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
file|"tipconf.h"
end_include

begin_include
include|#
directive|include
file|"tip.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|shell
argument_list|()
decl_stmt|,
name|getfl
argument_list|()
decl_stmt|,
name|sendfile
argument_list|()
decl_stmt|,
name|chdirectory
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|finish
argument_list|()
decl_stmt|,
name|help
argument_list|()
decl_stmt|,
name|pipefile
argument_list|()
decl_stmt|,
name|pipeout
argument_list|()
decl_stmt|,
name|variable
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cu_take
argument_list|()
decl_stmt|,
name|cu_put
argument_list|()
decl_stmt|,
name|dollar
argument_list|()
decl_stmt|,
name|genbrk
argument_list|()
decl_stmt|,
name|suspend
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|esctable_t
name|etable
index|[]
init|=
block|{
block|{
literal|'!'
block|,
name|NORM
block|,
literal|"shell"
block|,
name|shell
block|}
block|,
block|{
literal|'<'
block|,
name|NORM
block|,
literal|"receive file from remote host"
block|,
name|getfl
block|}
block|,
block|{
literal|'>'
block|,
name|NORM
block|,
literal|"send file to remote host"
block|,
name|sendfile
block|}
block|,
block|{
literal|'t'
block|,
name|NORM
block|,
literal|"take file from remote UNIX"
block|,
name|cu_take
block|}
block|,
block|{
literal|'p'
block|,
name|NORM
block|,
literal|"put file to remote UNIX"
block|,
name|cu_put
block|}
block|,
block|{
literal|'|'
block|,
name|NORM
block|,
literal|"pipe remote file"
block|,
name|pipefile
block|}
block|,
block|{
literal|'$'
block|,
name|NORM
block|,
literal|"pipe local command to remote host"
block|,
name|pipeout
block|}
block|,
if|#
directive|if
name|CONNECT
block|{
literal|'C'
block|,
name|NORM
block|,
literal|"connect program to remote host"
block|,
name|consh
block|}
block|,
endif|#
directive|endif
block|{
literal|'c'
block|,
name|NORM
block|,
literal|"change directory"
block|,
name|chdirectory
block|}
block|,
block|{
literal|'.'
block|,
name|NORM
block|,
literal|"exit from tip"
block|,
name|finish
block|}
block|,
block|{
name|CTRL
argument_list|(
literal|'d'
argument_list|)
block|,
name|NORM
block|,
literal|"exit from tip"
block|,
name|finish
block|}
block|,
block|{
name|CTRL
argument_list|(
literal|'y'
argument_list|)
block|,
name|NORM
block|,
literal|"suspend tip (local+remote)"
block|,
name|suspend
block|}
block|,
block|{
name|CTRL
argument_list|(
literal|'z'
argument_list|)
block|,
name|NORM
block|,
literal|"suspend tip (local only)"
block|,
name|suspend
block|}
block|,
block|{
literal|'s'
block|,
name|NORM
block|,
literal|"set variable"
block|,
name|variable
block|}
block|,
block|{
literal|'?'
block|,
name|NORM
block|,
literal|"get this summary"
block|,
name|help
block|}
block|,
block|{
literal|'#'
block|,
name|NORM
block|,
literal|"send break"
block|,
name|genbrk
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)cmdtab.c	5.4 (Berkeley) 12/22/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
name|consh
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
ifdef|#
directive|ifdef
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


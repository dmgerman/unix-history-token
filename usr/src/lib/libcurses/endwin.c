begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  */
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
literal|"@(#)endwin.c	5.2 (Berkeley) %G%"
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
comment|/*  * Clean things up before exiting  *  */
end_comment

begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_macro
name|endwin
argument_list|()
end_macro

begin_block
block|{
name|resetty
argument_list|()
expr_stmt|;
name|_puts
argument_list|(
name|VE
argument_list|)
expr_stmt|;
name|_puts
argument_list|(
name|TE
argument_list|)
expr_stmt|;
if|if
condition|(
name|curscr
condition|)
block|{
if|if
condition|(
name|curscr
operator|->
name|_flags
operator|&
name|_STANDOUT
condition|)
block|{
name|_puts
argument_list|(
name|SE
argument_list|)
expr_stmt|;
name|curscr
operator|->
name|_flags
operator|&=
operator|~
name|_STANDOUT
expr_stmt|;
block|}
name|_endwin
operator|=
name|TRUE
expr_stmt|;
block|}
block|}
end_block

end_unit


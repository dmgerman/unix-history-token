begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)getstr.c	8.2 (Berkeley) %G%"
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
file|"curses.h"
end_include

begin_comment
comment|/*  * wgetstr --  *	Get a string starting at (cury, curx).  */
end_comment

begin_function
name|int
name|wgetstr
parameter_list|(
name|win
parameter_list|,
name|str
parameter_list|)
specifier|register
name|WINDOW
modifier|*
name|win
decl_stmt|;
specifier|register
name|char
modifier|*
name|str
decl_stmt|;
block|{
while|while
condition|(
operator|(
operator|*
name|str
operator|=
name|wgetch
argument_list|(
name|win
argument_list|)
operator|)
operator|!=
name|ERR
operator|&&
operator|*
name|str
operator|!=
literal|'\n'
condition|)
name|str
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|str
operator|==
name|ERR
condition|)
block|{
operator|*
name|str
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|ERR
operator|)
return|;
block|}
operator|*
name|str
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

end_unit


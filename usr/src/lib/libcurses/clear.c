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
literal|"@(#)clear.c	8.2 (Berkeley) %G%"
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
comment|/*  * wclear --  *	Clear the window.  */
end_comment

begin_function
name|int
name|wclear
parameter_list|(
name|win
parameter_list|)
specifier|register
name|WINDOW
modifier|*
name|win
decl_stmt|;
block|{
if|if
condition|(
name|werase
argument_list|(
name|win
argument_list|)
operator|==
name|OK
condition|)
block|{
name|win
operator|->
name|flags
operator||=
name|__CLEAROK
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
return|return
operator|(
name|ERR
operator|)
return|;
block|}
end_function

end_unit


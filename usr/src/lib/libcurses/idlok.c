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
literal|"@(#)idlok.c	8.2 (Berkeley) %G%"
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
comment|/*  * idlok --  *	Turn on and off using insert/deleteln sequences for the  *	given window.  */
end_comment

begin_function
name|void
name|idlok
parameter_list|(
name|win
parameter_list|,
name|bf
parameter_list|)
name|WINDOW
modifier|*
name|win
decl_stmt|;
name|int
name|bf
decl_stmt|;
block|{
if|if
condition|(
name|bf
condition|)
name|win
operator|->
name|flags
operator||=
name|__IDLINE
expr_stmt|;
else|else
name|win
operator|->
name|flags
operator|&=
operator|~
name|__IDLINE
expr_stmt|;
block|}
end_function

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)addnstr.c	8.2 (Berkeley) %G%"
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"curses.h"
end_include

begin_comment
comment|/*  * waddnstr --  *	Add a string (at most n characters) to the given window  *	starting at (_cury, _curx).  If n is negative, add the  *	entire string.  */
end_comment

begin_function
name|int
name|waddnstr
parameter_list|(
name|win
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
name|WINDOW
modifier|*
name|win
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|n
decl_stmt|;
block|{
name|size_t
name|len
decl_stmt|;
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
for|for
control|(
name|p
operator|=
name|s
operator|,
name|len
operator|=
literal|0
init|;
name|n
operator|--
operator|&&
operator|*
name|p
operator|++
condition|;
operator|++
name|len
control|)
empty_stmt|;
else|else
name|len
operator|=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|waddbytes
argument_list|(
name|win
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
operator|)
return|;
block|}
end_function

end_unit


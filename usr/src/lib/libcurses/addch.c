begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)addch.c	5.8 (Berkeley) %G%"
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
file|<curses.h>
end_include

begin_comment
comment|/*  * waddch --  *	Add the character to the current position in the given window.  *  */
end_comment

begin_function
name|int
name|waddch
parameter_list|(
name|win
parameter_list|,
name|ch
parameter_list|)
name|WINDOW
modifier|*
name|win
decl_stmt|;
name|int
name|ch
decl_stmt|;
block|{
name|__waddch
argument_list|(
name|win
argument_list|,
name|ch
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|__waddch
parameter_list|(
name|win
parameter_list|,
name|ch
parameter_list|,
name|so
parameter_list|)
name|WINDOW
modifier|*
name|win
decl_stmt|;
name|int
name|ch
decl_stmt|;
name|int
name|so
decl_stmt|;
block|{
specifier|static
name|char
name|buf
index|[
literal|2
index|]
decl_stmt|;
name|buf
index|[
literal|0
index|]
operator|=
name|ch
expr_stmt|;
return|return
operator|(
name|__waddbytes
argument_list|(
name|win
argument_list|,
name|buf
argument_list|,
literal|1
argument_list|,
name|so
argument_list|)
operator|)
return|;
block|}
end_function

end_unit


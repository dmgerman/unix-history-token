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
literal|"@(#)standout.c	8.3 (Berkeley) %G%"
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
comment|/*  * wstandout  *	Enter standout mode.  */
end_comment

begin_function
name|int
name|wstandout
parameter_list|(
name|win
parameter_list|)
name|WINDOW
modifier|*
name|win
decl_stmt|;
block|{
comment|/* 	 * If standout/standend strings, or can underline, set the 	 * screen standout bit. 	 */
if|if
condition|(
name|SO
operator|!=
name|NULL
operator|&&
name|SE
operator|!=
name|NULL
operator|||
name|UC
operator|!=
name|NULL
condition|)
name|win
operator|->
name|flags
operator||=
name|__WSTANDOUT
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * wstandend --  *	Exit standout mode.  */
end_comment

begin_function
name|int
name|wstandend
parameter_list|(
name|win
parameter_list|)
name|WINDOW
modifier|*
name|win
decl_stmt|;
block|{
name|win
operator|->
name|flags
operator|&=
operator|~
name|__WSTANDOUT
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

end_unit


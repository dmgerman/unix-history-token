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
literal|"@(#)standout.c	5.4 (Berkeley) %G%"
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
comment|/*  * routines dealing with entering and exiting standout mode  *  */
end_comment

begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  * enter standout mode  */
end_comment

begin_function
name|char
modifier|*
name|wstandout
parameter_list|(
name|win
parameter_list|)
name|reg
name|WINDOW
modifier|*
name|win
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|SO
operator|&&
operator|!
name|UC
condition|)
return|return
name|FALSE
return|;
name|win
operator|->
name|_flags
operator||=
name|_STANDOUT
expr_stmt|;
return|return
operator|(
name|SO
condition|?
name|SO
else|:
name|UC
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * exit standout mode  */
end_comment

begin_function
name|char
modifier|*
name|wstandend
parameter_list|(
name|win
parameter_list|)
name|reg
name|WINDOW
modifier|*
name|win
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|SO
operator|&&
operator|!
name|UC
condition|)
return|return
name|FALSE
return|;
name|win
operator|->
name|_flags
operator|&=
operator|~
name|_STANDOUT
expr_stmt|;
return|return
operator|(
name|SE
condition|?
name|SE
else|:
name|UC
operator|)
return|;
block|}
end_function

end_unit


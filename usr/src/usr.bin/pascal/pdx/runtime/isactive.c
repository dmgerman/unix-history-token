begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)isactive.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Decide a the given function is currently active.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"runtime.h"
end_include

begin_include
include|#
directive|include
file|"frame.rep"
end_include

begin_include
include|#
directive|include
file|"sym.h"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_function
name|BOOLEAN
name|isactive
parameter_list|(
name|f
parameter_list|)
name|SYM
modifier|*
name|f
decl_stmt|;
block|{
if|if
condition|(
name|isfinished
argument_list|(
name|process
argument_list|)
condition|)
block|{
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
else|else
block|{
if|if
condition|(
name|f
operator|==
name|program
condition|)
block|{
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
return|return
operator|(
name|findframe
argument_list|(
name|f
argument_list|)
operator|!=
name|NIL
operator|)
return|;
block|}
block|}
end_function

end_unit


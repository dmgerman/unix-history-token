begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)MAX.c 1.4 6/10/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_function
name|long
name|MAX
parameter_list|(
name|width
parameter_list|,
name|reduce
parameter_list|,
name|min
parameter_list|)
specifier|register
name|long
name|width
decl_stmt|;
comment|/* requested width */
name|long
name|reduce
decl_stmt|;
comment|/* amount of extra space required */
name|long
name|min
decl_stmt|;
comment|/* minimum amount of space needed */
block|{
if|if
condition|(
name|width
operator|<=
literal|0
condition|)
block|{
name|ERROR
argument_list|(
literal|"Non-positive format width: %D\n"
argument_list|,
name|width
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|(
name|width
operator|-=
name|reduce
operator|)
operator|>=
name|min
condition|)
return|return
name|width
return|;
return|return
name|min
return|;
block|}
end_function

end_unit


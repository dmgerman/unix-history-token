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
literal|"@(#)MAX.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_include
include|#
directive|include
file|"h01errs.h"
end_include

begin_expr_stmt
name|MAX
argument_list|(
name|width
argument_list|,
name|reduce
argument_list|,
name|min
argument_list|)
specifier|register
name|int
name|width
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* requested width */
end_comment

begin_decl_stmt
name|int
name|reduce
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* amount of extra space required */
end_comment

begin_decl_stmt
name|int
name|min
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum amount of space needed */
end_comment

begin_block
block|{
if|if
condition|(
name|width
operator|<
literal|0
condition|)
block|{
name|ERROR
argument_list|(
name|EFMTSIZE
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
end_block

end_unit


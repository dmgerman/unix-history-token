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
literal|"@(#)SUCC.c 1.1 10/29/80"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h01errs.h"
end_include

begin_macro
name|SUCC
argument_list|(
argument|value
argument_list|,
argument|lower
argument_list|,
argument|upper
argument_list|)
end_macro

begin_decl_stmt
name|int
name|value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lower
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|upper
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|value
operator|++
expr_stmt|;
if|if
condition|(
name|value
operator|<
name|lower
operator|||
name|value
operator|>
name|upper
condition|)
block|{
name|ERROR
argument_list|(
name|ERANGE
argument_list|,
name|value
argument_list|)
expr_stmt|;
return|return;
block|}
return|return
name|value
return|;
block|}
end_block

end_unit


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
literal|"@(#)SUBSC.c 1.2 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h01errs.h"
end_include

begin_function
name|long
name|SUBSC
parameter_list|(
name|i
parameter_list|,
name|lower
parameter_list|,
name|upper
parameter_list|)
name|long
name|i
decl_stmt|,
name|lower
decl_stmt|,
name|upper
decl_stmt|;
block|{
if|if
condition|(
name|i
operator|<
name|lower
operator|||
name|i
operator|>
name|upper
condition|)
block|{
name|ERROR
argument_list|(
name|ESUBSC
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
return|return
name|i
return|;
block|}
end_function

end_unit


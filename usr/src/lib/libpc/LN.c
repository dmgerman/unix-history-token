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
literal|"@(#)LN.c 1.4 6/10/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function
name|double
name|LN
parameter_list|(
name|value
parameter_list|)
name|double
name|value
decl_stmt|;
block|{
if|if
condition|(
name|value
operator|<=
literal|0
condition|)
block|{
name|ERROR
argument_list|(
literal|"Non-positive argument of %e to ln\n"
argument_list|,
name|value
argument_list|)
expr_stmt|;
return|return;
block|}
return|return
name|log
argument_list|(
name|value
argument_list|)
return|;
block|}
end_function

end_unit


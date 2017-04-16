begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=unix.Malloc %s
end_comment

begin_comment
comment|// Do not crash due to division by zero
end_comment

begin_function
name|int
name|f
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|<=
literal|0
condition|)
return|return
literal|1
operator|/
name|a
return|;
return|return
name|a
return|;
block|}
end_function

end_unit


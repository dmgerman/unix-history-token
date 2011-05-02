begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -Wunused-parameter -fdiagnostics-show-name %s 2>&1 | grep "\[warn_unused_parameter\]" | count 1
end_comment

begin_comment
comment|// RUN: %clang -Wunused-parameter -fno-diagnostics-show-name %s 2>&1 | grep "\[warn_unused_parameter\]" | count 0
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
return|return
name|argc
return|;
block|}
end_function

end_unit


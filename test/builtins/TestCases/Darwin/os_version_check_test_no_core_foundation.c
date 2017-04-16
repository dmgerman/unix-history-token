begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -o %t -mmacosx-version-min=10.5
end_comment

begin_comment
comment|// RUN: %run %t
end_comment

begin_function_decl
name|int
name|__isOSVersionAtLeast
parameter_list|(
name|int
name|Major
parameter_list|,
name|int
name|Minor
parameter_list|,
name|int
name|Subminor
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// When CoreFoundation isn't linked, we expect the system version to be 0, 0,
comment|// 0.
if|if
condition|(
name|__isOSVersionAtLeast
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit


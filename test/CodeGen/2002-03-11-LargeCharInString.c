begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s  -o /dev/null
end_comment

begin_function_decl
name|int
name|strcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test
parameter_list|(
name|char
modifier|*
name|X
parameter_list|)
block|{
comment|/* LLVM-GCC used to emit:      %.LC0 = internal global [3 x sbyte] c"\1F\FFFFFF8B\00"    */
return|return
name|strcmp
argument_list|(
name|X
argument_list|,
literal|"\037\213"
argument_list|)
return|;
block|}
end_function

end_unit


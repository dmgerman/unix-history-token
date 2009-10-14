begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

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


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -o %t -O3 %s
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t/  %run %t 1 2>&1 | FileCheck %s
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: LLVM Profile Error: Failed to write file
end_comment

end_unit


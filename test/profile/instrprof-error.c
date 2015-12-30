begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -o %t -O3 %s
end_comment

begin_comment
comment|// RUN: touch %t.profraw
end_comment

begin_comment
comment|// RUN: chmod -w %t.profraw
end_comment

begin_comment
comment|// RUN: LLVM_PROFILE_FILE=%t.profraw LLVM_PROFILE_VERBOSE_ERRORS=1 %run %t 1 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: chmod +w %t.profraw
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
comment|// CHECK: LLVM Profile: Failed to write file
end_comment

end_unit


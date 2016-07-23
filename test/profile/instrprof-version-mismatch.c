begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -o %t -O3 %s
end_comment

begin_comment
comment|// RUN: %run %t 1 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// override the version variable with a bogus version:
end_comment

begin_decl_stmt
name|unsigned
name|long
name|long
name|__llvm_profile_raw_version
init|=
literal|10000
decl_stmt|;
end_decl_stmt

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
comment|// CHECK: LLVM Profile Error: Runtime and instrumentation version mismatch
end_comment

end_unit


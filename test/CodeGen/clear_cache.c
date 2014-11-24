begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_decl_stmt
name|char
name|buffer
index|[
literal|32
index|]
init|=
literal|"This is a largely unused buffer"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// __builtin___clear_cache always maps to @llvm.clear_cache, but what
end_comment

begin_comment
comment|// each back-end produces is different, and this is tested in LLVM
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|__builtin___clear_cache
argument_list|(
name|buffer
argument_list|,
name|buffer
operator|+
literal|32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.clear_cache(i8* getelementptr {{.*}}, i8* getelementptr {{.*}} (i8* getelementptr {{.*}} 32))
return|return
literal|0
return|;
block|}
end_function

end_unit


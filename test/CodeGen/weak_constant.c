begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -emit-llvm %s -O1 -o - | FileCheck %s
end_comment

begin_comment
comment|// Check for bug compatibility with gcc.
end_comment

begin_decl_stmt
specifier|const
name|int
name|x
name|__attribute
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
init|=
literal|123
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|f
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|x
return|;
block|}
end_function

begin_function
name|int
name|g
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: ret i32 123
return|return
operator|*
name|f
argument_list|()
return|;
block|}
end_function

end_unit


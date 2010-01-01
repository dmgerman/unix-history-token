begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -verify | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @foo.p = internal global i8 0, align 32
end_comment

begin_function
name|char
modifier|*
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|char
name|p
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
decl_stmt|;
return|return
operator|&
name|p
return|;
block|}
end_function

begin_function
name|void
name|bar
parameter_list|(
name|long
name|n
parameter_list|)
block|{
comment|// CHECK: align 32
name|char
name|p
index|[
name|n
index|]
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
decl_stmt|;
block|}
end_function

end_unit


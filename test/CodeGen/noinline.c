begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Make sure -fno-inline-functions is behaving correctly.
end_comment

begin_comment
comment|// rdar://10972766
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O3 -fno-inline -fno-inline-functions -emit-llvm %s -o - | FileCheck -check-prefix=NOINLINE %s
end_comment

begin_function
specifier|inline
name|int
name|dont_inline_me
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|+
name|b
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|int
name|inline_me
argument_list|(
argument|int a
argument_list|,
argument|int b
argument_list|)
block|{
return|return
operator|(
name|a
operator|*
name|b
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|volatile
name|int
modifier|*
name|pa
init|=
operator|(
name|int
operator|*
operator|)
literal|0x1000
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// NOINLINE: @foo
comment|// NOINLINE: dont_inline_me
comment|// NOINLINE-NOT: inlinehint
name|pa
index|[
literal|0
index|]
operator|=
name|dont_inline_me
argument_list|(
name|pa
index|[
literal|1
index|]
argument_list|,
name|pa
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|// NOINLINE-NOT: inline_me
name|pa
index|[
literal|3
index|]
operator|=
name|inline_me
argument_list|(
name|pa
index|[
literal|4
index|]
argument_list|,
name|pa
index|[
literal|5
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// NOINLINE: Function Attrs: noinline
end_comment

begin_comment
comment|// NOINLINE: @dont_inline_me
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@llvm.used = .*@g0' %t
end_comment

begin_comment
comment|// RUN: grep '@llvm.used = .*@f0' %t
end_comment

begin_comment
comment|// RUN: grep '@llvm.used = .*@f1.l0' %t
end_comment

begin_decl_stmt
name|int
name|g0
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
name|f0
argument_list|(
name|void
argument_list|)
block|{ }
end_decl_stmt

begin_function
name|void
name|f1
parameter_list|()
block|{
specifier|static
name|int
name|l0
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
init|=
literal|5225
decl_stmt|;
block|}
end_function

end_unit


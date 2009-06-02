begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-pc-linux-gnu -emit-llvm -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep '@_Z2f0i' %t&&
end_comment

begin_comment
comment|// RUN: grep '@_Z2f0l' %t&&
end_comment

begin_comment
comment|// Make sure we mangle overloadable, even in C system headers.
end_comment

begin_empty
empty|# 1 "somesystemheader.h" 1 3 4
end_empty

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|__overloadable__
operator|)
argument_list|)
name|f0
argument_list|(
name|int
name|a
argument_list|)
block|{}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|__overloadable__
operator|)
argument_list|)
name|f0
argument_list|(
name|long
name|b
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// These should get merged.
end_comment

begin_expr_stmt
name|void
name|foo
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("bar");
end_asm

begin_expr_stmt
name|void
name|foo2
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("bar");
end_asm

begin_comment
comment|// RUN: grep '@"\\01foo"' %t&&
end_comment

begin_comment
comment|// RUN: grep '@"\\01bar"' %t
end_comment

begin_decl_stmt
name|int
name|nux
name|__asm__
argument_list|(
literal|"foo"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|nux2
name|__asm__
argument_list|(
literal|"foo"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test
parameter_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
name|foo2
argument_list|()
expr_stmt|;
return|return
name|nux
operator|+
name|nux2
return|;
block|}
end_function

begin_comment
comment|// Function becomes a variable.
end_comment

begin_expr_stmt
name|void
name|foo3
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("var");
end_asm

begin_function
name|void
name|test2
parameter_list|()
block|{
name|foo3
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|foo4
name|__asm__
argument_list|(
literal|"var"
argument_list|)
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Variable becomes a function
end_comment

begin_decl_stmt
specifier|extern
name|int
name|foo5
name|__asm__
argument_list|(
literal|"var2"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test3
parameter_list|()
block|{
name|foo5
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|void
name|foo6
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("var2");
end_asm

begin_function
name|void
name|foo6
parameter_list|()
block|{ }
end_function

begin_decl_stmt
name|int
name|foo7
name|__asm__
argument_list|(
literal|"foo7"
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|foo8
name|__asm__
argument_list|(
literal|"foo7"
argument_list|)
init|=
literal|42
decl_stmt|;
end_decl_stmt

end_unit


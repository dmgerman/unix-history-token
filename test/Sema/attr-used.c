begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only %s
end_comment

begin_decl_stmt
specifier|extern
name|int
name|l0
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{used attribute ignored}}
end_comment

begin_decl_stmt
name|__private_extern__
name|int
name|l1
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{used attribute ignored}}
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(used)
argument_list|)
name|s
block|{
comment|// expected-warning {{'used' attribute only applies to variable and function types}}
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|a
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
name|a
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
decl_stmt|;
name|int
name|b
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
decl_stmt|;
comment|// expected-warning {{used attribute ignored}}
block|}
end_function

end_unit


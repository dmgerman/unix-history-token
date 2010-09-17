begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify
end_comment

begin_comment
comment|// PR5692
end_comment

begin_enum_decl
enum_decl|enum
name|x
enum_decl|;
end_enum_decl

begin_comment
comment|// expected-note   {{forward declaration}}
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|y
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note   {{forward declaration}}
end_comment

begin_decl_stmt
specifier|extern
name|union
name|z
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note 2 {{forward declaration}}
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
operator|(
expr|enum
name|x
operator|)
literal|1
expr_stmt|;
comment|// expected-error {{cast to incomplete type}}
operator|(
expr|struct
name|y
operator|)
name|a
expr_stmt|;
comment|// expected-error {{cast to incomplete type}}
operator|(
expr|union
name|z
operator|)
name|b
expr_stmt|;
comment|// expected-error {{cast to incomplete type}}
operator|(
expr|union
name|z
operator|)
literal|1
expr_stmt|;
comment|// expected-error {{cast to incomplete type}}
block|}
end_function

end_unit


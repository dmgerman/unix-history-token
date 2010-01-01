begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -fsyntax-only %s -verify  */
end_comment

begin_typedef
typedef|typedef
name|void
name|Void
typedef|;
end_typedef

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|X
decl_stmt|;
name|X
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|(
argument|void a
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-error {{argument may not have 'void' type}}
name|X
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|(
name|int
argument_list|,
name|void
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-error {{must be the first and only parameter}}
name|X
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|(
name|void
argument_list|,
operator|...
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-error {{must be the first and only parameter}}
name|X
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|(
argument|Void a
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-error {{argument may not have 'void' type}}
name|X
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|(
name|int
argument_list|,
name|Void
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-error {{must be the first and only parameter}}
name|X
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|(
name|Void
argument_list|,
operator|...
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-error {{must be the first and only parameter}}
comment|// Accept these.
name|X
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|(
name|void
argument_list|)
argument_list|)
expr_stmt|;
name|X
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|(
name|Void
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// this is ok.
end_comment

begin_function
name|void
name|bar
parameter_list|(
name|Void
parameter_list|)
block|{ }
end_function

begin_function_decl
name|void
name|f
parameter_list|(
specifier|const
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{parameter must not have type qualifiers}}
end_comment

end_unit


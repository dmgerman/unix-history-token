begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wnonnull -Wnullability %s -verify
end_comment

begin_comment
comment|// rdar://19160762
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|nullability
argument_list|)
end_if

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|nullability feature should be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
modifier|*
name|_Nullable
name|foo
parameter_list|(
name|int
modifier|*
name|_Nonnull
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
modifier|*
name|_Nonnull
name|ret_nonnull
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
modifier|*
name|foo
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
modifier|*
name|_Nullable
name|foo1
parameter_list|(
name|int
modifier|*
name|_Nonnull
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_function
name|int
modifier|*
name|foo1
parameter_list|(
name|int
modifier|*
name|_Nullable
name|x
parameter_list|)
block|{
comment|// expected-warning {{nullability specifier '_Nullable' conflicts with existing specifier '_Nonnull'}}
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
modifier|*
name|_Nullable
name|foo2
parameter_list|(
name|int
modifier|*
name|_Nonnull
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
modifier|*
name|foo2
parameter_list|(
name|int
modifier|*
name|_Nonnull
name|x
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
modifier|*
name|_Nullable
name|foo3
parameter_list|(
name|int
modifier|*
name|_Nullable
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_function
name|int
modifier|*
name|foo3
parameter_list|(
name|int
modifier|*
name|_Nonnull
name|x
parameter_list|)
block|{
comment|// expected-warning {{nullability specifier '_Nonnull' conflicts with existing specifier '_Nullable'}}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|ret_nonnull
parameter_list|()
block|{
return|return
literal|0
return|;
comment|// expected-warning {{null returned from function that requires a non-null return value}}
block|}
end_function

begin_define
define|#
directive|define
name|SAFE_CALL
parameter_list|(
name|X
parameter_list|)
value|if (X) foo(X)
end_define

begin_function
name|int
name|main
parameter_list|()
block|{
name|foo
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{null passed to a callee that requires a non-null argument}}
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|foo
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// expect no diagnostic in unevaluated context.
name|SAFE_CALL
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expect no diagnostic for unreachable code.
block|}
end_function

end_unit


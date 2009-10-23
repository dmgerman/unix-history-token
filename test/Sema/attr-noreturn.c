begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -verify -fsyntax-only %s
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|fp0
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
name|f0
argument_list|(
name|void
argument_list|)
block|{
name|fatal
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// expected-warning {{function declared 'noreturn' should not return}}
end_comment

begin_comment
comment|// On K&R
end_comment

begin_function_decl
name|int
name|f1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|g0
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'noreturn' attribute only applies to function types}}
end_comment

begin_function_decl
name|int
name|f2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{attribute requires 0 argument(s)}}
end_comment

begin_function_decl
name|void
name|f3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f3
parameter_list|()
block|{
return|return;
comment|// expected-warning {{function 'f3' declared 'noreturn' should not return}}
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|error
literal|"-Winvalid-noreturn"
end_pragma

begin_function_decl
name|void
name|f4
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f4
parameter_list|()
block|{
return|return;
comment|// expected-error {{function 'f4' declared 'noreturn' should not return}}
block|}
end_function

begin_comment
comment|// PR4685
end_comment

begin_function_decl
specifier|extern
name|void
name|f5
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f5
parameter_list|(
name|unsigned
name|long
name|size
parameter_list|)
block|{    }
end_function

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|sentinel
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-warning{{'sentinel' attribute only applies to function, method or block types}}
end_comment

begin_function_decl
name|void
name|f1
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(sentinel
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f2
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(sentinel
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f3
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(sentinel
parameter_list|(
function_decl|"hello"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'sentinel' attribute requires parameter 1 to be an integer constant}}
end_comment

begin_function_decl
name|void
name|f4
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(sentinel
parameter_list|(
function_decl|1
operator|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{attribute requires 0, 1 or 2 argument(s)}}
end_comment

begin_function_decl
name|void
name|f4
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(sentinel
parameter_list|(
function_decl|-1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{parameter 1 less than zero}}
end_comment

begin_function_decl
name|void
name|f4
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(sentinel
parameter_list|(
function_decl|0
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{parameter 2 not 0 or 1}}
end_comment

begin_function_decl
name|void
name|f5
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(sentinel
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-warning{{'sentinel' attribute only supported for variadic functions}}
end_comment

begin_function_decl
name|void
name|f6
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__sentinel__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'sentinel' attribute requires named arguments}}
end_comment

end_unit


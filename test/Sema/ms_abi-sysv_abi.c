begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-pc-linux-gnu %s
end_comment

begin_comment
comment|// CC qualifier can be applied only to functions
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|ms_abi
operator|)
argument_list|)
name|var1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'ms_abi' only applies to function types; type here is 'int'}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|sysv_abi
operator|)
argument_list|)
name|var2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'sysv_abi' only applies to function types; type here is 'int'}}
end_comment

begin_comment
comment|// Different CC qualifiers are not compatible
end_comment

begin_comment
comment|// FIXME: Should say 'sysv_abi' instead of 'cdecl'
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|ms_abi
operator|,
name|sysv_abi
operator|)
argument_list|)
name|foo3
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{cdecl and ms_abi attributes are not compatible}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|ms_abi
operator|)
argument_list|)
name|foo4
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|sysv_abi
operator|)
argument_list|)
name|foo4
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{function declared 'cdecl' here was previously declared 'ms_abi'}}
end_comment

begin_function_decl
name|void
name|bar
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ms_abi
operator|,
function_decl|cdecl
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{cdecl and ms_abi attributes are not compatible}}
end_comment

begin_function_decl
name|void
name|bar2
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(sysv_abi
operator|,
function_decl|cdecl
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-error
end_comment

end_unit


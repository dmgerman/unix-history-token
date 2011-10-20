begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_comment
comment|// rdar://10095762
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|Fn_noret
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|Fn_ret
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo_noret
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

begin_function
name|void
name|test
parameter_list|()
block|{
name|Fn_noret
name|fn2
init|=
operator|&
name|foo
decl_stmt|;
comment|// expected-warning {{incompatible pointer types initializing 'Fn_noret'}}
name|Fn_noret
name|fn3
init|=
operator|&
name|foo_noret
decl_stmt|;
name|Fn_ret
name|fn4
init|=
operator|&
name|foo_noret
decl_stmt|;
name|Fn_ret
name|fn5
init|=
operator|&
name|foo
decl_stmt|;
block|}
end_function

end_unit


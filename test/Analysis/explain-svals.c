begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin10 -analyze -analyzer-checker=core.builtin,debug.ExprInspection,unix.cstring -verify %s
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|clang_analyzer_explain_int
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clang_analyzer_explain_voidp
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clang_analyzer_explain_S
parameter_list|(
name|struct
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|glob
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_1
parameter_list|(
name|int
name|param
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|clang_analyzer_explain_voidp
argument_list|(
operator|&
name|glob
argument_list|)
expr_stmt|;
comment|// expected-warning-re{{{{^pointer to global variable 'glob'$}}}}
name|clang_analyzer_explain_int
argument_list|(
name|param
argument_list|)
expr_stmt|;
comment|// expected-warning-re{{{{^argument 'param'$}}}}
name|clang_analyzer_explain_voidp
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
comment|// expected-warning-re{{{{^argument 'ptr'$}}}}
if|if
condition|(
name|param
operator|==
literal|42
condition|)
name|clang_analyzer_explain_int
argument_list|(
name|param
argument_list|)
expr_stmt|;
comment|// expected-warning-re{{{{^signed 32-bit integer '42'$}}}}
block|}
end_function

begin_function
name|void
name|test_2
parameter_list|(
name|struct
name|S
name|s
parameter_list|)
block|{
name|clang_analyzer_explain_S
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|//expected-warning-re{{{{^lazily frozen compound value of parameter 's'$}}}}
name|clang_analyzer_explain_voidp
argument_list|(
operator|&
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning-re{{{{^pointer to parameter 's'$}}}}
name|clang_analyzer_explain_int
argument_list|(
name|s
operator|.
name|z
argument_list|)
expr_stmt|;
comment|// expected-warning-re{{{{^initial value of field 'z' of parameter 's'$}}}}
block|}
end_function

end_unit


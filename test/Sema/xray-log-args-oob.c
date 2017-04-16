begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -std=c11
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(xray_log_args
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(xray_log_args(
literal|1
argument|))
argument_list|)
name|a
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// expected-warning {{'xray_log_args' attribute only applies to functions and methods}}
end_comment

begin_function_decl
name|void
name|fop
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(xray_log_args
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'xray_log_args' attribute parameter 1 is out of bounds}}
end_comment

begin_function_decl
name|void
name|foq
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(xray_log_args
parameter_list|(
function_decl|-1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'xray_log_args' attribute parameter 1 is out of bounds}}
end_comment

begin_function_decl
name|void
name|fos
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(xray_log_args
parameter_list|(
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'xray_log_args' attribute parameter 1 is out of bounds}}
end_comment

end_unit


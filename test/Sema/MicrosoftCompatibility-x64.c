begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -Wmicrosoft -verify -fms-compatibility -triple x86_64-pc-win32
end_comment

begin_comment
comment|// None of these should warn. stdcall is treated as equivalent to cdecl on
end_comment

begin_comment
comment|// x64.
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function_decl
name|int
name|__stdcall
name|f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|__cdecl
name|f
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
name|__stdcall
name|func_std
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__thiscall
name|func_this
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__fastcall
name|func_fast
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit


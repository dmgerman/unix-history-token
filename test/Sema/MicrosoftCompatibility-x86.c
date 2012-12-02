begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -Wno-unused-value -Wmicrosoft -verify -fms-compatibility -triple i386-pc-win32
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

begin_comment
comment|/* expected-note {{previous declaration is here}} */
end_comment

begin_function
name|int
name|__cdecl
name|f
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* expected-error {{function declared 'cdecl' here was previously declared 'stdcall'}} */
return|return
literal|0
return|;
block|}
end_function

end_unit


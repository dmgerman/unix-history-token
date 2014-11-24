begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-win32 -verify %s
end_comment

begin_comment
comment|// Do not report that 'foo()' is redeclared without dllimport attribute.
end_comment

begin_comment
comment|// specified.  Addresses<rdar://problem/7653912>.
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|int
name|__cdecl
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|inline
name|int
name|__cdecl
name|foo
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit


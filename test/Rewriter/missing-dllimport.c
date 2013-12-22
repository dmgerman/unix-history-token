begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -triple i686-pc-win32 -fms-extensions -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-NEG %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple i686-pc-win32 -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-POS %s
end_comment

begin_comment
comment|// Do not report that 'foo()' is redeclared without dllimport attribute with -fms-extensions
end_comment

begin_comment
comment|// specified.  Addresses<rdar://problem/7653912>.
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

begin_comment
comment|// This function is added just to trigger a diagnostic.  This way we can test how many
end_comment

begin_comment
comment|// diagnostics we expect.
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK-NEG: error: void function 'bar' should not return a value
end_comment

begin_comment
comment|// CHECK-NEG: 1 error generated
end_comment

begin_comment
comment|// CHECK-POS: warning: 'foo' redeclared without dllimport attribute: previous dllimport ignored
end_comment

begin_comment
comment|// CHECK-POS: error: void function 'bar' should not return a value
end_comment

begin_comment
comment|// CHECK-POS: 1 warning and 1 error generated
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -triple i686-pc-win32 -fms-extensions -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-NEG %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple i686-pc-win32 -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-POS %s
end_comment

begin_comment
comment|// Do not report an error with including dllimport in the typedef when -fms-extensions is specified.
end_comment

begin_comment
comment|// Addresses<rdar://problem/7653870>.
end_comment

begin_typedef
typedef|typedef
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
name|int
name|CB
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

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
comment|// CHECK-POS: warning: 'dllimport' attribute only applies to variables and functions
end_comment

begin_comment
comment|// CHECK-POS: error: void function 'bar' should not return a value
end_comment

begin_comment
comment|// CHECK-POS: 1 warning and 1 error generated
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 %s -fsyntax-only -fmessage-length 75 -o /dev/null 2>&1 | FileCheck %s -strict-whitespace
end_comment

begin_comment
comment|// Test case for the text diagnostics source column conversion crash.
end_comment

begin_comment
comment|// This test case tries to check the error diagnostic message printer, which is
end_comment

begin_comment
comment|// responsible to create the code snippet shorter than the message-length (in
end_comment

begin_comment
comment|// number of columns.)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The error diagnostic message printer should be able to handle the non-ascii
end_comment

begin_comment
comment|// characters without any segmentation fault or assertion failure.  If your
end_comment

begin_comment
comment|// changes to clang frontend crashes this case, it is likely that you are mixing
end_comment

begin_comment
comment|// column index with byte index which are two totally different concepts.
end_comment

begin_comment
comment|// NOTE: This file is encoded in UTF-8 and intentionally contains some
end_comment

begin_comment
comment|// non-ASCII characters.
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(format(printf,
literal|1
argument|,
literal|2
argument|))
argument_list|)
end_macro

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test1
parameter_list|(
name|Unknown
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î±
end_comment

begin_comment
comment|// CHECK: unknown type name 'Unknown'
end_comment

begin_comment
comment|// CHECK-NEXT: void test1(Unknown* b);  // Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±...
end_comment

begin_comment
comment|// CHECK-NEXT: {{^           \^$}}
end_comment

begin_function_decl
name|void
name|test2
parameter_list|(
name|Unknown
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î±
end_comment

begin_comment
comment|// CHECK: unknown type name 'Unknown'
end_comment

begin_comment
comment|// CHECK-NEXT: void test2(Unknown* b);  // Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î±
end_comment

begin_comment
comment|// CHECK-NEXT: {{^           \^$}}
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
comment|/* Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± */
name|printf
argument_list|(
literal|"%d"
argument_list|,
literal|"s"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:       format specifies type 'int' but the argument has type 'char *'
end_comment

begin_comment
comment|// CHECK-NEXT:   ...Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± Î±Î±Î±Î± */ printf("%d", "s");
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                                             ~~   \^~~$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                                             %s$}}
end_comment

end_unit


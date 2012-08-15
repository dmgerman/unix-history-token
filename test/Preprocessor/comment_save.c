begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -C %s | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// foo
end_comment

begin_comment
comment|// CHECK: // foo
end_comment

begin_comment
comment|/* bar */
end_comment

begin_comment
comment|// CHECK: /* bar */
end_comment

begin_if
if|#
directive|if
name|FOO
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* baz */
end_comment

begin_comment
comment|// CHECK: /* baz */
end_comment

begin_macro
name|_Pragma
argument_list|(
literal|"unknown"
argument_list|)
end_macro

begin_comment
comment|// after unknown pragma
end_comment

begin_comment
comment|// CHECK: #pragma unknown
end_comment

begin_comment
comment|// CHECK-NEXT: #
end_comment

begin_comment
comment|// CHECK-NEXT: // after unknown pragma
end_comment

begin_macro
name|_Pragma
argument_list|(
literal|"comment(\"abc\")"
argument_list|)
end_macro

begin_comment
comment|// after known pragma
end_comment

begin_comment
comment|// CHECK: #pragma comment("abc")
end_comment

begin_comment
comment|// CHECK-NEXT: #
end_comment

begin_comment
comment|// CHECK-NEXT: // after known pragma
end_comment

end_unit


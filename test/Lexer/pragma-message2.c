begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -Werror -verify %s 2>&1 | FileCheck %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|message
literal|"\\test"
end_pragma

begin_comment
comment|// expected-warning {{\test}}
end_comment

begin_comment
comment|// CHECK: #pragma message("\134test")
end_comment

begin_pragma
pragma|#
directive|pragma
name|message
name|(
literal|"\\test"
name|)
end_pragma

begin_comment
comment|// expected-warning {{\test}}
end_comment

begin_comment
comment|// CHECK: #pragma message("\134test")
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|warning
literal|"\""
literal|"te"
literal|"st"
literal|"\""
end_pragma

begin_comment
comment|// expected-warning {{"test"}}
end_comment

begin_comment
comment|// CHECK: #pragma GCC warning "\042test\042"
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|warning
name|(
literal|"\""
literal|"te"
literal|"st"
literal|"\""
name|)
end_pragma

begin_comment
comment|// expected-warning {{"test"}}
end_comment

begin_comment
comment|// CHECK: #pragma GCC warning "\042test\042"
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|error
literal|""
literal|"[	]"
literal|""
end_pragma

begin_comment
comment|// expected-error {{[	]}}
end_comment

begin_comment
comment|// CHECK: #pragma GCC error "[\011]"
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|error
name|(
literal|""
literal|"[	]"
literal|""
name|)
end_pragma

begin_comment
comment|// expected-error {{[	]}}
end_comment

begin_comment
comment|// CHECK: #pragma GCC error "[\011]"
end_comment

end_unit


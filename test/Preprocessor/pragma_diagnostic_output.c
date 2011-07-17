begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: #pragma GCC diagnostic warning "-Wall"
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|warning
literal|"-Wall"
end_pragma

begin_comment
comment|// CHECK: #pragma GCC diagnostic ignored "-Wall"
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wall"
end_pragma

begin_comment
comment|// CHECK: #pragma GCC diagnostic error "-Wall"
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|error
literal|"-Wall"
end_pragma

begin_comment
comment|// CHECK: #pragma GCC diagnostic fatal "-Wall"
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|fatal
literal|"-Wall"
end_pragma

begin_comment
comment|// CHECK: #pragma GCC diagnostic push
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|push
end_pragma

begin_comment
comment|// CHECK: #pragma GCC diagnostic pop
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|pop
end_pragma

begin_comment
comment|// CHECK: #pragma clang diagnostic warning "-Wall"
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|warning
literal|"-Wall"
end_pragma

begin_comment
comment|// CHECK: #pragma clang diagnostic ignored "-Wall"
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wall"
end_pragma

begin_comment
comment|// CHECK: #pragma clang diagnostic error "-Wall"
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|error
literal|"-Wall"
end_pragma

begin_comment
comment|// CHECK: #pragma clang diagnostic fatal "-Wall"
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|fatal
literal|"-Wall"
end_pragma

begin_comment
comment|// CHECK: #pragma clang diagnostic push
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_comment
comment|// CHECK: #pragma clang diagnostic pop
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This should warn by default.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s 2>&1 | grep "warning: foo"
end_comment

begin_comment
comment|// This should not emit anything.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -w 2>&1 | not grep diagnostic
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Wno-#warnings 2>&1 | not grep diagnostic
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Wno-cpp 2>&1 | not grep diagnostic
end_comment

begin_comment
comment|// -Werror can map all warnings to error.
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -Werror 2>&1 | grep "error: foo"
end_comment

begin_comment
comment|// -Werror can map this one warning to error.
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -Werror=#warnings 2>&1 | grep "error: foo"
end_comment

begin_comment
comment|// -Wno-error= overrides -Werror.  rdar://3158301
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Werror -Wno-error=#warnings 2>&1 | grep "warning: foo"
end_comment

begin_comment
comment|// -Wno-error overrides -Werror.  PR4715
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Werror -Wno-error 2>&1 | grep "warning: foo"
end_comment

begin_warning
warning|#
directive|warning
warning|foo
end_warning

end_unit


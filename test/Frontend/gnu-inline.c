begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c89 -fsyntax-only -x c -E -dM %s | FileCheck --check-prefix=GNU-INLINE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fsyntax-only -x c -E -dM %s | FileCheck --check-prefix=STDC-INLINE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fgnu89-inline -fsyntax-only -x c -E -dM %s | FileCheck --check-prefix=GNU-INLINE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -x c++ -E -dM %s | FileCheck --check-prefix=GNU-INLINE %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fgnu89-inline -fsyntax-only -x c++ %s 2>&1 | FileCheck --check-prefix=CXX %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fgnu89-inline -fsyntax-only -x objective-c++ %s 2>&1 | FileCheck --check-prefix=OBJCXX %s
end_comment

begin_comment
comment|// CXX: '-fgnu89-inline' not allowed with 'C++'
end_comment

begin_comment
comment|// OBJCXX: '-fgnu89-inline' not allowed with 'Objective-C++'
end_comment

begin_comment
comment|// STDC-INLINE-NOT: __GNUC_GNU_INLINE__
end_comment

begin_comment
comment|// STDC-INLINE: #define __GNUC_STDC_INLINE__ 1
end_comment

begin_comment
comment|// STDC-INLINE-NOT: __GNUC_GNU_INLINE__
end_comment

begin_comment
comment|// GNU-INLINE-NOT: __GNUC_STDC_INLINE__
end_comment

begin_comment
comment|// GNU-INLINE: #define __GNUC_GNU_INLINE__ 1
end_comment

begin_comment
comment|// GNU-INLINE-NOT: __GNUC_STDC_INLINE__
end_comment

end_unit


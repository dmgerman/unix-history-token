begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -triple x86_64-apple-macosx10.6 %s 2>&1 | FileCheck %s --check-prefix NO-TLS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -triple x86_64-apple-macosx10.7 %s 2>&1 | FileCheck %s --check-prefix TLS
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -triple arm64-apple-ios7.1 %s 2>&1 | FileCheck %s --check-prefix NO-TLS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -triple arm64-apple-ios8.0 %s 2>&1 | FileCheck %s --check-prefix TLS
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -triple thumbv7s-apple-ios8.3 %s 2>&1 | FileCheck %s --check-prefix NO-TLS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -triple thumbv7s-apple-ios9.0 %s 2>&1 | FileCheck %s --check-prefix TLS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -triple armv7-apple-ios9.0 %s 2>&1 | FileCheck %s --check-prefix TLS
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -triple thumbv7k-apple-watchos1.0 %s 2>&1 | FileCheck %s --check-prefix NO-TLS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -triple thumbv7k-apple-watchos2.0 %s 2>&1 | FileCheck %s --check-prefix TLS
end_comment

begin_decl_stmt
name|__thread
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// NO-TLS: thread-local storage is not supported for the current target
end_comment

begin_comment
comment|// TLS-NOT: thread-local storage is not supported for the current target
end_comment

begin_expr_stmt
name|wibble
expr_stmt|;
end_expr_stmt

end_unit


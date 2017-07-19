begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that TLS is correctly considered supported or unsupported for the
end_comment

begin_comment
comment|// different targets.
end_comment

begin_comment
comment|// Linux supports TLS.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -fsyntax-only %s
end_comment

begin_comment
comment|// Darwin supports TLS since 10.7.
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple x86_64-apple-darwin10 -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macos10.7.0 -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-win32 -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-win32 -fsyntax-only %s
end_comment

begin_comment
comment|// OpenBSD suppports TLS.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-openbsd -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-openbsd -fsyntax-only %s
end_comment

begin_comment
comment|// Haiku does not suppport TLS.
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple i586-pc-haiku -fsyntax-only %s
end_comment

begin_comment
comment|// Bitrig suppports TLS.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-bitrig -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv6-unknown-bitrig -fsyntax-only %s
end_comment

begin_decl_stmt
name|__thread
name|int
name|x
decl_stmt|;
end_decl_stmt

end_unit


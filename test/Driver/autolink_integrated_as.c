begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -fsyntax-only %s -no-integrated-as -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Test that the autolinking feature is disabled with *not* using the
end_comment

begin_comment
comment|// integrated assembler.
end_comment

begin_comment
comment|// CHECK: -fno-autolink
end_comment

end_unit


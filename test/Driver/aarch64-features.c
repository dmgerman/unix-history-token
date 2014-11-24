begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -### %s -fsyntax-only 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-none-linux-gnu -### %s -fsyntax-only 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// The AArch64 PCS states that chars should be unsigned.
end_comment

begin_comment
comment|// CHECK: fno-signed-char
end_comment

end_unit


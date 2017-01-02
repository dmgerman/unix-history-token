begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that -print-libgcc-file-name correctly respects -rtlib=libgcc.
end_comment

begin_comment
comment|// REQUIRES: libgcc
end_comment

begin_comment
comment|// RUN: %clang -rtlib=libgcc -print-libgcc-file-name 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LIBGCC %s
end_comment

begin_comment
comment|// CHECK-LIBGCC: libgcc.a
end_comment

end_unit


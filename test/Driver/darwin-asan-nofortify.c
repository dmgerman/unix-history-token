begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Make sure AddressSanitizer disables _FORTIFY_SOURCE on Darwin.
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=address  %s -E -dM -target x86_64-darwin | FileCheck %s
end_comment

begin_comment
comment|// CHECK: #define _FORTIFY_SOURCE 0
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -Wunused-command-line-argument -pthread -target x86_64-apple-darwin -### /dev/null -o /dev/null 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// There is nothing to do at link time to get pthread support. But do not warn.
end_comment

begin_comment
comment|// CHECK-NOT: argument unused during compilation: '-pthread'
end_comment

end_unit


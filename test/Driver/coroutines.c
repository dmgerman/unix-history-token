begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### %s 2>&1 | FileCheck -check-prefix=CHECK-NO-CORO %s
end_comment

begin_comment
comment|// RUN: %clang -fcoroutines-ts -### %s 2>&1 | FileCheck -check-prefix=CHECK-NO-CORO %s
end_comment

begin_comment
comment|// RUN: %clang -fno-coroutines-ts -### %s 2>&1 | FileCheck -check-prefix=CHECK-NO-CORO %s
end_comment

begin_comment
comment|// RUN: %clang -fno-coroutines-ts -fcoroutines-ts -### %s 2>&1 | FileCheck -check-prefix=CHECK-NO-CORO %s
end_comment

begin_comment
comment|// CHECK-NO-CORO-NOT: -fcoroutines-ts
end_comment

end_unit


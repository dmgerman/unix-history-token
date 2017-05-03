begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=0 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-0
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=edge -fsanitize-coverage=0 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-0
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-0
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-0-NOT: fsanitize-coverage-type
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-0: -fsanitize=address
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=func,trace-pc %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-FUNC
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-coverage=func,trace-pc %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-FUNC
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=leak -fsanitize-coverage=func,trace-pc %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-FUNC
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined -fsanitize-coverage=func,trace-pc %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-FUNC
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=bool -fsanitize-coverage=func,trace-pc %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-FUNC
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=dataflow -fsanitize-coverage=func,trace-pc %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-FUNC
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu                     -fsanitize-coverage=func,trace-pc %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-FUNC
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-FUNC: fsanitize-coverage-type=1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=bb %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-BB
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-BB: fsanitize-coverage-type=2
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=edge %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-EDGE
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-EDGE: fsanitize-coverage-type=3
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=edge,indirect-calls %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-FUNC_INDIR
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-FUNC_INDIR: fsanitize-coverage-type=3
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-FUNC_INDIR: fsanitize-coverage-indirect-calls
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=1 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-1
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-1: warning: argument '-fsanitize-coverage=1' is deprecated, use '-fsanitize-coverage=trace-pc-guard' instead
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=func %s -### 2>&1 | FileCheck %s --check-prefix=CHECK_FUNC_BB_EDGE_DEPRECATED
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=bb %s -### 2>&1 | FileCheck %s --check-prefix=CHECK_FUNC_BB_EDGE_DEPRECATED
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=edge %s -### 2>&1 | FileCheck %s --check-prefix=CHECK_FUNC_BB_EDGE_DEPRECATED
end_comment

begin_comment
comment|// CHECK_FUNC_BB_EDGE_DEPRECATED: warning: argument '-fsanitize-coverage=[func|bb|edge]' is deprecated, use '-fsanitize-coverage=[func|bb|edge],[trace-pc-guard|trace-pc]' instead
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=edge,indirect-calls,trace-pc,trace-cmp,trace-div,trace-gep %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-FEATURES
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-FEATURES: -fsanitize-coverage-type=3
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-FEATURES: -fsanitize-coverage-indirect-calls
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-FEATURES: -fsanitize-coverage-trace-cmp
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-FEATURES: -fsanitize-coverage-trace-div
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-FEATURES: -fsanitize-coverage-trace-gep
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-FEATURES: -fsanitize-coverage-trace-pc
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=func,edge,indirect-calls,trace-cmp -fno-sanitize-coverage=edge,indirect-calls %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-MASK
end_comment

begin_comment
comment|// CHECK-MASK: -fsanitize-coverage-type=1
end_comment

begin_comment
comment|// CHECK-MASK: -fsanitize-coverage-trace-cmp
end_comment

begin_comment
comment|// CHECK-MASK-NOT: -fsanitize-coverage-
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=foobar %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-INVALID-VALUE
end_comment

begin_comment
comment|// CHECK-INVALID-VALUE: error: unsupported argument 'foobar' to option 'fsanitize-coverage='
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=func -fsanitize-coverage=edge %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-INCOMPATIBLE
end_comment

begin_comment
comment|// CHECK-INCOMPATIBLE: error: invalid argument '-fsanitize-coverage=func' not allowed with '-fsanitize-coverage=edge'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-coverage=8bit-counters %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-8BIT
end_comment

begin_comment
comment|// CHECK-8BIT: warning: argument '-fsanitize-coverage=8bit-counters' is deprecated, use '-fsanitize-coverage=trace-pc-guard' instead
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-coverage=trace-bb %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACE-BB
end_comment

begin_comment
comment|// CHECK-TRACE-BB: warning: argument '-fsanitize-coverage=trace-bb' is deprecated, use '-fsanitize-coverage=trace-pc-guard' instead
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-coverage=trace-pc %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACE_PC_EDGE
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-coverage=edge,trace-pc %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACE_PC_EDGE
end_comment

begin_comment
comment|// CHECK-TRACE_PC_EDGE: -fsanitize-coverage-type=3
end_comment

begin_comment
comment|// CHECK-TRACE_PC_EDGE: -fsanitize-coverage-trace-pc
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-coverage=func,trace-pc %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACE_PC_FUNC
end_comment

begin_comment
comment|// CHECK-TRACE_PC_FUNC: -fsanitize-coverage-type=1
end_comment

begin_comment
comment|// CHECK-TRACE_PC_FUNC: -fsanitize-coverage-trace-pc
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-coverage=trace-pc-guard %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACE_PC_GUARD_EDGE
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-coverage=edge,trace-pc-guard %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACE_PC_GUARD_EDGE
end_comment

begin_comment
comment|// CHECK-TRACE_PC_GUARD_EDGE: -fsanitize-coverage-type=3
end_comment

begin_comment
comment|// CHECK-TRACE_PC_GUARD_EDGE: -fsanitize-coverage-trace-pc-guard
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-coverage=func,trace-pc-guard %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACE_PC_GUARD_FUNC
end_comment

begin_comment
comment|// CHECK-TRACE_PC_GUARD_FUNC: -fsanitize-coverage-type=1
end_comment

begin_comment
comment|// CHECK-TRACE_PC_GUARD_FUNC: -fsanitize-coverage-trace-pc-guard
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=trace-cmp,indirect-calls %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-TYPE-NECESSARY
end_comment

begin_comment
comment|// CHECK-NO-TYPE-NECESSARY-NOT: error:
end_comment

begin_comment
comment|// CHECK-NO-TYPE-NECESSARY: -fsanitize-coverage-indirect-calls
end_comment

begin_comment
comment|// CHECK-NO-TYPE-NECESSARY: -fsanitize-coverage-trace-cmp
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=func -fsanitize-coverage=trace-cmp %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-EXTEND-LEGACY
end_comment

begin_comment
comment|// CHECK-EXTEND-LEGACY: -fsanitize-coverage-type=1
end_comment

begin_comment
comment|// CHECK-EXTEND-LEGACY: -fsanitize-coverage-trace-cmp
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i386-pc-win32 -fsanitize=address -fsanitize-coverage=func,trace-pc-guard -c -### -- %s 2>&1 | FileCheck %s -check-prefix=CLANG-CL-COVERAGE
end_comment

begin_comment
comment|// CLANG-CL-COVERAGE-NOT: error:
end_comment

begin_comment
comment|// CLANG-CL-COVERAGE-NOT: warning:
end_comment

begin_comment
comment|// CLANG-CL-COVERAGE-NOT: argument unused
end_comment

begin_comment
comment|// CLANG-CL-COVERAGE-NOT: unknown argument
end_comment

begin_comment
comment|// CLANG-CL-COVERAGE: -fsanitize-coverage-type=1
end_comment

begin_comment
comment|// CLANG-CL-COVERAGE: -fsanitize=address
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -target amdgcn -x cl -S -emit-llvm -mcpu=kaveri -mamdgpu-debugger-abi=0.0 %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MAMDGPU-DEBUGGER-ABI-0-0 %s
end_comment

begin_comment
comment|// CHECK-MAMDGPU-DEBUGGER-ABI-0-0: the clang compiler does not support '-mamdgpu-debugger-abi=0.0'
end_comment

begin_comment
comment|// RUN: %clang -### -target amdgcn -x cl -S -emit-llvm -mcpu=kaveri -mamdgpu-debugger-abi=1.0 %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MAMDGPU-DEBUGGER-ABI-1-0 %s
end_comment

begin_comment
comment|// CHECK-MAMDGPU-DEBUGGER-ABI-1-0: "-target-feature" "+amdgpu-debugger-insert-nops" "-target-feature" "+amdgpu-debugger-reserve-regs" "-target-feature" "+amdgpu-debugger-emit-prologue"
end_comment

end_unit


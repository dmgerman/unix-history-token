begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: @t1
end_comment

begin_function
name|void
name|t1
parameter_list|()
block|{
asm|__asm__ ("mov r8w, 100;");
comment|// CHECK: call void asm sideeffect "mov r8w, 100;"
asm|__asm__ ("mov r8d, 100;");
comment|// CHECK: call void asm sideeffect "mov r8d, 100;"
asm|__asm__ ("mov r8b, 100;");
comment|// CHECK: call void asm sideeffect "mov r8b, 100;"
asm|__asm__ ("mov r9w, 100;");
comment|// CHECK: call void asm sideeffect "mov r9w, 100;"
asm|__asm__ ("mov r9d, 100;");
comment|// CHECK: call void asm sideeffect "mov r9d, 100;"
asm|__asm__ ("mov r9b, 100;");
comment|// CHECK: call void asm sideeffect "mov r9b, 100;"
asm|__asm__ ("mov r10w, 100;");
comment|// CHECK: call void asm sideeffect "mov r10w, 100;"
asm|__asm__ ("mov r10d, 100;");
comment|// CHECK: call void asm sideeffect "mov r10d, 100;"
asm|__asm__ ("mov r10b, 100;");
comment|// CHECK: call void asm sideeffect "mov r10b, 100;"
asm|__asm__ ("mov r11w, 100;");
comment|// CHECK: call void asm sideeffect "mov r11w, 100;"
asm|__asm__ ("mov r11d, 100;");
comment|// CHECK: call void asm sideeffect "mov r11d, 100;"
asm|__asm__ ("mov r11b, 100;");
comment|// CHECK: call void asm sideeffect "mov r11b, 100;"
asm|__asm__ ("mov r12w, 100;");
comment|// CHECK: call void asm sideeffect "mov r12w, 100;"
asm|__asm__ ("mov r12d, 100;");
comment|// CHECK: call void asm sideeffect "mov r12d, 100;"
asm|__asm__ ("mov r12b, 100;");
comment|// CHECK: call void asm sideeffect "mov r12b, 100;"
asm|__asm__ ("mov r13w, 100;");
comment|// CHECK: call void asm sideeffect "mov r13w, 100;"
asm|__asm__ ("mov r13d, 100;");
comment|// CHECK: call void asm sideeffect "mov r13d, 100;"
asm|__asm__ ("mov r13b, 100;");
comment|// CHECK: call void asm sideeffect "mov r13b, 100;"
asm|__asm__ ("mov r14w, 100;");
comment|// CHECK: call void asm sideeffect "mov r14w, 100;"
asm|__asm__ ("mov r14d, 100;");
comment|// CHECK: call void asm sideeffect "mov r14d, 100;"
asm|__asm__ ("mov r14b, 100;");
comment|// CHECK: call void asm sideeffect "mov r14b, 100;"
asm|__asm__ ("mov r15w, 100;");
comment|// CHECK: call void asm sideeffect "mov r15w, 100;"
asm|__asm__ ("mov r15d, 100;");
comment|// CHECK: call void asm sideeffect "mov r15d, 100;"
asm|__asm__ ("mov r15b, 100;");
comment|// CHECK: call void asm sideeffect "mov r15b, 100;"
block|}
end_function

end_unit


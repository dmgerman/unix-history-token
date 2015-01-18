begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -ffreestanding -triple x86_64-apple-darwin -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-64
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -ffreestanding -triple i386 -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-32
end_comment

begin_include
include|#
directive|include
file|<cpuid.h>
end_include

begin_comment
comment|// CHECK-64: {{.*}} call { i32, i32, i32, i32 } asm "  xchgq  %rbx,${1:q}\0A cpuid\0A xchgq %rbx,${1:q}", "={ax},=r,={cx},={dx},0,~{dirflag},~{fpsr},~{flags}"(i32 %{{[a-z0-9]+}})
end_comment

begin_comment
comment|// CHECK-64: {{.*}} call { i32, i32, i32, i32 } asm "  xchgq  %rbx,${1:q}\0A  cpuid\0A  xchgq  %rbx,${1:q}", "={ax},=r,={cx},={dx},0,2,~{dirflag},~{fpsr},~{flags}"(i32 %{{[a-z0-9]+}}, i32 %{{[a-z0-9]+}})
end_comment

begin_comment
comment|// CHECK-32: {{.*}} call { i32, i32, i32, i32 } asm "cpuid", "={ax},={bx},={cx},={dx},0,~{dirflag},~{fpsr},~{flags}"(i32 %{{[a-z0-9]+}})
end_comment

begin_comment
comment|// CHECK-32: {{.*}} call { i32, i32, i32, i32 } asm "cpuid", "={ax},={bx},={cx},={dx},0,2,~{dirflag},~{fpsr},~{flags}"(i32 %{{[a-z0-9]+}}, i32 %{{[a-z0-9]+}})
end_comment

begin_decl_stmt
name|unsigned
name|eax0
decl_stmt|,
name|ebx0
decl_stmt|,
name|ecx0
decl_stmt|,
name|edx0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|eax1
decl_stmt|,
name|ebx1
decl_stmt|,
name|ecx1
decl_stmt|,
name|edx1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_cpuid
parameter_list|(
name|unsigned
name|level
parameter_list|,
name|unsigned
name|count
parameter_list|)
block|{
name|__cpuid
argument_list|(
name|level
argument_list|,
name|eax1
argument_list|,
name|ebx1
argument_list|,
name|ecx1
argument_list|,
name|edx1
argument_list|)
expr_stmt|;
name|__cpuid_count
argument_list|(
name|level
argument_list|,
name|count
argument_list|,
name|eax0
argument_list|,
name|ebx0
argument_list|,
name|ecx0
argument_list|,
name|edx0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit


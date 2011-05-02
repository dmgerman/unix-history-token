begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -mmmx -ccc-host-triple i386-unknown-unknown -emit-llvm -S %s -o - | FileCheck %s
end_comment

begin_comment
comment|//<rdar://problem/9091220>
end_comment

begin_include
include|#
directive|include
file|<mmintrin.h>
end_include

begin_comment
comment|// CHECK: type { x86_mmx, x86_mmx, x86_mmx, x86_mmx, x86_mmx, x86_mmx, x86_mmx }
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|long
name|long
name|fill
parameter_list|)
block|{
name|__m64
name|vfill
init|=
name|_mm_cvtsi64_m64
argument_list|(
name|fill
argument_list|)
decl_stmt|;
name|__m64
name|v1
decl_stmt|,
name|v2
decl_stmt|,
name|v3
decl_stmt|,
name|v4
decl_stmt|,
name|v5
decl_stmt|,
name|v6
decl_stmt|,
name|v7
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(     "\tmovq  %7, %0\n"     "\tmovq  %7, %1\n"     "\tmovq  %7, %2\n"     "\tmovq  %7, %3\n"     "\tmovq  %7, %4\n"     "\tmovq  %7, %5\n"     "\tmovq  %7, %6"     : "=&y" (v1), "=&y" (v2), "=&y" (v3),       "=&y" (v4), "=&y" (v5), "=&y" (v6), "=y" (v7)     : "y" (vfill));
block|}
end_function

end_unit


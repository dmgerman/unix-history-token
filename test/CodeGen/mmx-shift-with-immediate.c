begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -mmmx -ccc-host-triple i386-unknown-unknown -emit-llvm -S %s -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<mmintrin.h>
end_include

begin_function
name|void
name|shift
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{
comment|// CHECK: x86_mmx @llvm.x86.mmx.pslli.w(x86_mmx %{{.*}}, i32 {{.*}})
name|_mm_slli_pi16
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// CHECK: x86_mmx @llvm.x86.mmx.pslli.d(x86_mmx %{{.*}}, i32 {{.*}})
name|_mm_slli_pi32
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// CHECK: x86_mmx @llvm.x86.mmx.pslli.q(x86_mmx %{{.*}}, i32 {{.*}})
name|_mm_slli_si64
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// CHECK: x86_mmx @llvm.x86.mmx.psrli.w(x86_mmx %{{.*}}, i32 {{.*}})
name|_mm_srli_pi16
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// CHECK: x86_mmx @llvm.x86.mmx.psrli.d(x86_mmx %{{.*}}, i32 {{.*}})
name|_mm_srli_pi32
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// CHECK: x86_mmx @llvm.x86.mmx.psrli.q(x86_mmx %{{.*}}, i32 {{.*}})
name|_mm_srli_si64
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// CHECK: x86_mmx @llvm.x86.mmx.psrai.w(x86_mmx %{{.*}}, i32 {{.*}})
name|_mm_srai_pi16
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// CHECK: x86_mmx @llvm.x86.mmx.psrai.d(x86_mmx %{{.*}}, i32 {{.*}})
name|_mm_srai_pi32
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

end_unit


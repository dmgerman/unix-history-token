begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-unknown-linux-gnu -emit-llvm -target-cpu x86-64 -o - |opt -instnamer -S |FileCheck %s --check-prefix SSE
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-unknown-linux-gnu -emit-llvm -target-cpu skylake -D AVX -o -|opt -instnamer -S  | FileCheck %s --check-prefixes AVX,SSE
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-unknown-linux-gnu -emit-llvm -target-cpu skylake-avx512 -D AVX512 -D AVX -o -|opt -instnamer -S  | FileCheck %s --check-prefixes AVX512,AVX,SSE
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-unknown-linux-gnu -emit-llvm -target-cpu knl -D AVX -D AVX512 -o - |opt -instnamer -S  | FileCheck %s --check-prefixes AVX512,AVX,SSE
end_comment

begin_typedef
typedef|typedef
name|float
name|__m128
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__m256
name|__attribute__
typedef|((
name|vector_size
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__m512
name|__attribute__
typedef|((
name|vector_size
typedef|(64)));
end_typedef

begin_comment
comment|// SSE: call<4 x float> asm "vmovhlps $1, $2, $0", "=v,v,v,~{dirflag},~{fpsr},~{flags}"(i64 %tmp,<4 x float> %tmp1)
end_comment

begin_function
name|__m128
name|testXMM
parameter_list|(
name|__m128
name|_xmm0
parameter_list|,
name|long
name|_l
parameter_list|)
block|{
asm|__asm__("vmovhlps %1, %2, %0" :"=v"(_xmm0) : "v"(_l), "v"(_xmm0));
return|return
name|_xmm0
return|;
block|}
end_function

begin_comment
comment|// AVX: call<8 x float> asm "vmovsldup $1, $0", "=v,v,~{dirflag},~{fpsr},~{flags}"(<8 x float> %tmp)
end_comment

begin_function
name|__m256
name|testYMM
parameter_list|(
name|__m256
name|_ymm0
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|AVX
asm|__asm__("vmovsldup %1, %0" :"=v"(_ymm0) : "v"(_ymm0));
endif|#
directive|endif
return|return
name|_ymm0
return|;
block|}
end_function

begin_comment
comment|// AVX512: call<16 x float> asm "vpternlogd $$0, $1, $2, $0", "=v,v,v,~{dirflag},~{fpsr},~{flags}"(<16 x float> %tmp,<16 x float> %tmp1)
end_comment

begin_function
name|__m512
name|testZMM
parameter_list|(
name|__m512
name|_zmm0
parameter_list|,
name|__m512
name|_zmm1
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|AVX512
asm|__asm__("vpternlogd $0, %1, %2, %0" :"=v"(_zmm0) : "v"(_zmm1), "v"(_zmm0));
endif|#
directive|endif
return|return
name|_zmm0
return|;
block|}
end_function

end_unit


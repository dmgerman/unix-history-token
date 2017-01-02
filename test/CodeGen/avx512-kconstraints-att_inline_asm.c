begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O0 -triple=x86_64-apple-darwin -target-cpu skylake-avx512 -emit-llvm -o - -Wall -Werror |opt -instnamer -S |FileCheck %s
end_comment

begin_comment
comment|// This test checks validity of att\gcc style inline assmebly for avx512 k and Yk constraints.
end_comment

begin_comment
comment|// Also checks mask register allows flexible type (size<= 64 bit)
end_comment

begin_function
name|void
name|mask_Yk_i8
parameter_list|(
name|char
name|msk
parameter_list|)
block|{
comment|//CHECK: vpaddb\09 %xmm1, %xmm0, %xmm1 {$0}\09
asm|asm ("vpaddb\t %%xmm1, %%xmm0, %%xmm1 %{%0%}\t"        :
comment|//output
asm|: "Yk" (msk));
comment|//inputs
block|}
end_function

begin_function
name|void
name|mask_Yk_i16
parameter_list|(
name|short
name|msk
parameter_list|)
block|{
comment|//CHECK: vpaddb\09 %xmm1, %xmm0, %xmm1 {$0}\09
asm|asm ("vpaddb\t %%xmm1, %%xmm0, %%xmm1 %{%0%}\t"        :
comment|//output
asm|:  "Yk" (msk));
comment|//inputs
block|}
end_function

begin_function
name|void
name|mask_Yk_i32
parameter_list|(
name|int
name|msk
parameter_list|)
block|{
comment|//CHECK: vpaddb\09 %xmm1, %xmm0, %xmm1 {$0}\09
asm|asm ("vpaddb\t %%xmm1, %%xmm0, %%xmm1 %{%0%}\t"        :
comment|//output
asm|:  "Yk" (msk));
comment|//inputs
block|}
end_function

begin_function
name|void
name|mask_Yk_i64
parameter_list|(
name|long
name|long
name|msk
parameter_list|)
block|{
comment|//CHECK: vpaddb\09 %xmm1, %xmm0, %xmm1 {$0}\09
asm|asm ("vpaddb\t %%xmm1, %%xmm0, %%xmm1 %{%0%}\t"        :
comment|//output
asm|:  "Yk" (msk));
comment|//inputs
block|}
end_function

begin_function
name|void
name|k_wise_op_i8
parameter_list|(
name|char
name|msk_dst
parameter_list|,
name|char
name|msk_src1
parameter_list|,
name|char
name|msk_src2
parameter_list|)
block|{
comment|//CHECK: kandw\09$2, $1, $0
asm|asm ("kandw\t%2, %1, %0"        : "=k" (msk_dst)        : "k" (msk_src1), "k" (msk_src2));
block|}
end_function

begin_function
name|void
name|k_wise_op_i16
parameter_list|(
name|short
name|msk_dst
parameter_list|,
name|short
name|msk_src1
parameter_list|,
name|short
name|msk_src2
parameter_list|)
block|{
comment|//CHECK: kandw\09$2, $1, $0
asm|asm ("kandw\t%2, %1, %0"        : "=k" (msk_dst)        : "k" (msk_src1), "k" (msk_src2));
block|}
end_function

begin_function
name|void
name|k_wise_op_i32
parameter_list|(
name|int
name|msk_dst
parameter_list|,
name|int
name|msk_src1
parameter_list|,
name|int
name|msk_src2
parameter_list|)
block|{
comment|//CHECK: kandw\09$2, $1, $0
asm|asm ("kandw\t%2, %1, %0"        : "=k" (msk_dst)        : "k" (msk_src1), "k" (msk_src2));
block|}
end_function

begin_function
name|void
name|k_wise_op_i64
parameter_list|(
name|long
name|long
name|msk_dst
parameter_list|,
name|long
name|long
name|msk_src1
parameter_list|,
name|long
name|long
name|msk_src2
parameter_list|)
block|{
comment|//CHECK: kandw\09$2, $1, $0
asm|asm ("kandw\t%2, %1, %0"        : "=k" (msk_dst)        : "k" (msk_src1), "k" (msk_src2));
block|}
end_function

end_unit


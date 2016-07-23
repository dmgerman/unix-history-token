begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -ffreestanding -triple x86_64-apple-macosx10.9.0 -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -ffreestanding -triple x86_64-apple-macosx10.9.0 -emit-llvm -o - \
end_comment

begin_comment
comment|// RUN:     -fmodules -fimplicit-module-maps -fmodules-cache-path=%t -isystem %S/Inputs/include \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

begin_comment
comment|// CHECK: @c = common global i8 0, align 16
end_comment

begin_decl_stmt
name|_MM_ALIGN16
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Make sure the last step of _mm_cvtps_pi16 converts<4 x i32> to<4 x i16> by
end_comment

begin_comment
comment|// checking that clang emits PACKSSDW instead of PACKSSWB.
end_comment

begin_comment
comment|// CHECK: define i64 @test_mm_cvtps_pi16
end_comment

begin_comment
comment|// CHECK: call x86_mmx @llvm.x86.mmx.packssdw
end_comment

begin_function
name|__m64
name|test_mm_cvtps_pi16
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
return|return
name|_mm_cvtps_pi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Make sure that including<xmmintrin.h> also makes<emmintrin.h>'s content available.
end_comment

begin_comment
comment|// This is an ugly hack for GCC compatibility.
end_comment

begin_function
name|__m128
name|test_xmmintrin_provides_emmintrin
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|_mm_add_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|__STDC_HOSTED__
end_if

begin_comment
comment|// Make sure stdlib.h symbols are accessible.
end_comment

begin_decl_stmt
name|void
modifier|*
name|p
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


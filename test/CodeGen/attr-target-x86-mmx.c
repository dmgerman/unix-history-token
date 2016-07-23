begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-linux-gnu -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Picking a cpu that doesn't have mmx or sse by default so we can enable it later.
end_comment

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// Verify that when we turn on sse that we also turn on mmx.
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"sse"
argument_list|)
operator|)
argument_list|)
name|shift
argument_list|(
name|__m64
name|a
argument_list|,
name|__m64
name|b
argument_list|,
name|int
name|c
argument_list|)
block|{
name|_mm_slli_pi16
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|_mm_slli_pi32
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|_mm_slli_si64
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|_mm_srli_pi16
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|_mm_srli_pi32
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|_mm_srli_si64
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|_mm_srai_pi16
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|_mm_srai_pi32
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK: "target-features"="+mmx,+sse,+x87"
end_comment

end_unit


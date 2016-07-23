begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-none-eabi -target-feature +neon -target-feature +vfp4 -fsyntax-only -verify %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|func
parameter_list|(
name|float32x2_t
name|v2f32
parameter_list|,
name|float32x4_t
name|v4f32
parameter_list|)
block|{
name|vfma_f32
argument_list|(
name|v2f32
argument_list|,
name|v2f32
argument_list|,
name|v2f32
argument_list|)
expr_stmt|;
name|vfmaq_f32
argument_list|(
name|v4f32
argument_list|,
name|v4f32
argument_list|,
name|v4f32
argument_list|)
expr_stmt|;
name|vfms_f32
argument_list|(
name|v2f32
argument_list|,
name|v2f32
argument_list|,
name|v2f32
argument_list|)
expr_stmt|;
name|vfmsq_f32
argument_list|(
name|v4f32
argument_list|,
name|v4f32
argument_list|,
name|v4f32
argument_list|)
expr_stmt|;
block|}
end_function

end_unit


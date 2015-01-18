begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv8 -target-cpu cortex-a57 -fsyntax-only -ffreestanding -verify %s
end_comment

begin_include
include|#
directive|include
file|<arm_acle.h>
end_include

begin_comment
comment|/*  * Memory barrier intrinsics  * Argument for dmb, dsb, isb must be compile-time constant,  * otherwise an error should be raised.  */
end_comment

begin_function
name|void
name|test_dmb_const_diag
parameter_list|(
specifier|const
name|unsigned
name|int
name|t
parameter_list|)
block|{
return|return
name|__dmb
argument_list|(
name|t
argument_list|)
return|;
comment|// expected-error-re {{argument to {{.*}} must be a constant integer}}
block|}
end_function

begin_function
name|void
name|test_dsb_const_diag
parameter_list|(
specifier|const
name|unsigned
name|int
name|t
parameter_list|)
block|{
return|return
name|__dsb
argument_list|(
name|t
argument_list|)
return|;
comment|// expected-error-re {{argument to {{.*}} must be a constant integer}}
block|}
end_function

begin_function
name|void
name|test_isb_const_diag
parameter_list|(
specifier|const
name|unsigned
name|int
name|t
parameter_list|)
block|{
return|return
name|__isb
argument_list|(
name|t
argument_list|)
return|;
comment|// expected-error-re {{argument to {{.*}} must be a constant integer}}
block|}
end_function

begin_comment
comment|/*  * Saturating intrinsics  * Second argument for SSAT and USAT intrinsics must be compile-time constant,  * otherwise an error should be raised.  */
end_comment

begin_function
name|int32_t
name|test_ssat_const_diag
parameter_list|(
name|int32_t
name|t
parameter_list|,
specifier|const
name|int32_t
name|v
parameter_list|)
block|{
return|return
name|__ssat
argument_list|(
name|t
argument_list|,
name|v
argument_list|)
return|;
comment|// expected-error-re {{argument to {{.*}} must be a constant integer}}
block|}
end_function

begin_function
name|int32_t
name|test_usat_const_diag
parameter_list|(
name|int32_t
name|t
parameter_list|,
specifier|const
name|int32_t
name|v
parameter_list|)
block|{
return|return
name|__usat
argument_list|(
name|t
argument_list|,
name|v
argument_list|)
return|;
comment|// expected-error-re {{argument to {{.*}} must be a constant integer}}
block|}
end_function

begin_comment
comment|/*  * Prefetch intrinsics  */
end_comment

begin_function
name|void
name|test_pldx_const_diag
parameter_list|(
name|int32_t
name|i
parameter_list|)
block|{
name|__pldx
argument_list|(
name|i
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error-re {{argument to {{.*}} must be a constant integer}}
block|}
end_function

begin_comment
comment|/*  * DBG intrinsic  * First argument for DBG intrinsic must be compile-time constant,  * otherwise an error should be raised.  */
end_comment

begin_function
name|void
name|test_dbg_const_diag
parameter_list|(
name|unsigned
name|int
name|t
parameter_list|)
block|{
name|__dbg
argument_list|(
name|t
argument_list|)
expr_stmt|;
comment|// expected-error-re {{argument to {{.*}} must be a constant integer}}
block|}
end_function

end_unit


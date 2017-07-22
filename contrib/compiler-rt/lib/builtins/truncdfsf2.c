begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/truncdfsf2.c - double -> single conversion ------------*- C -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_define
define|#
directive|define
name|SRC_DOUBLE
end_define

begin_define
define|#
directive|define
name|DST_SINGLE
end_define

begin_include
include|#
directive|include
file|"fp_trunc_impl.inc"
end_include

begin_function
name|COMPILER_RT_ABI
name|float
name|__truncdfsf2
parameter_list|(
name|double
name|a
parameter_list|)
block|{
return|return
name|__truncXfYf2__
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_function
name|AEABI_RTABI
name|float
name|__aeabi_d2f
parameter_list|(
name|double
name|a
parameter_list|)
block|{
return|return
name|__truncdfsf2
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit


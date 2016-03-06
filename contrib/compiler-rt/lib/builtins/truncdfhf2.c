begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/truncdfhf2.c - double -> half conversion --------------*- C -*-===//
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
name|DST_HALF
end_define

begin_include
include|#
directive|include
file|"fp_trunc_impl.inc"
end_include

begin_macro
name|ARM_EABI_FNALIAS
argument_list|(
argument|d2h
argument_list|,
argument|truncdfhf2
argument_list|)
end_macro

begin_function
name|COMPILER_RT_ABI
name|uint16_t
name|__truncdfhf2
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

end_unit


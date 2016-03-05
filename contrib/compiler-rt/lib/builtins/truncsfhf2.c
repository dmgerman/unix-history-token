begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/truncsfhf2.c - single -> half conversion --------------*- C -*-===//
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
name|SRC_SINGLE
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
argument|f2h
argument_list|,
argument|truncsfhf2
argument_list|)
end_macro

begin_comment
comment|// Use a forwarding definition and noinline to implement a poor man's alias,
end_comment

begin_comment
comment|// as there isn't a good cross-platform way of defining one.
end_comment

begin_function
name|COMPILER_RT_ABI
name|NOINLINE
name|uint16_t
name|__truncsfhf2
parameter_list|(
name|float
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

begin_function
name|COMPILER_RT_ABI
name|uint16_t
name|__gnu_f2h_ieee
parameter_list|(
name|float
name|a
parameter_list|)
block|{
return|return
name|__truncsfhf2
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit


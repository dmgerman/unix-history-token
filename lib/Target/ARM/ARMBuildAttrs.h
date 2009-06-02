begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------- ARMBuildAttrs.h - ARM Build Attributes ------------*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains enumerations and support routines for ARM build attributes
end_comment

begin_comment
comment|// as defined in ARM ABI addenda document (ABI release 2.07).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TARGET_ARMBUILDATTRS_H__
end_ifndef

begin_define
define|#
directive|define
name|__TARGET_ARMBUILDATTRS_H__
end_define

begin_decl_stmt
name|namespace
name|ARMBuildAttrs
block|{
enum|enum
block|{
name|File
init|=
literal|1
block|,
name|Section
init|=
literal|2
block|,
name|Symbol
init|=
literal|3
block|,
name|CPU_raw_name
init|=
literal|4
block|,
name|CPU_name
init|=
literal|5
block|,
name|CPU_arch
init|=
literal|6
block|,
name|CPU_arch_profile
init|=
literal|7
block|,
name|ARM_ISA_use
init|=
literal|8
block|,
name|THUMB_ISA_use
init|=
literal|9
block|,
name|VFP_arch
init|=
literal|10
block|,
name|WMMX_arch
init|=
literal|11
block|,
name|Advanced_SIMD_arch
init|=
literal|12
block|,
name|PCS_config
init|=
literal|13
block|,
name|ABI_PCS_R9_use
init|=
literal|14
block|,
name|ABI_PCS_RW_data
init|=
literal|15
block|,
name|ABI_PCS_RO_data
init|=
literal|16
block|,
name|ABI_PCS_GOT_use
init|=
literal|17
block|,
name|ABI_PCS_wchar_t
init|=
literal|18
block|,
name|ABI_FP_rounding
init|=
literal|19
block|,
name|ABI_FP_denormal
init|=
literal|20
block|,
name|ABI_FP_exceptions
init|=
literal|21
block|,
name|ABI_FP_user_exceptions
init|=
literal|22
block|,
name|ABI_FP_number_model
init|=
literal|23
block|,
name|ABI_align8_needed
init|=
literal|24
block|,
name|ABI_align8_preserved
init|=
literal|25
block|,
name|ABI_enum_size
init|=
literal|26
block|,
name|ABI_HardFP_use
init|=
literal|27
block|,
name|ABI_VFP_args
init|=
literal|28
block|,
name|ABI_WMMX_args
init|=
literal|29
block|,
name|ABI_optimization_goals
init|=
literal|30
block|,
name|ABI_FP_optimization_goals
init|=
literal|31
block|,
name|compatibility
init|=
literal|32
block|,
name|CPU_unaligned_access
init|=
literal|34
block|,
name|VFP_HP_extension
init|=
literal|36
block|,
name|ABI_FP_16bit_format
init|=
literal|38
block|,
name|nodefaults
init|=
literal|64
block|,
name|also_compatible_with
init|=
literal|65
block|,
name|T2EE_use
init|=
literal|66
block|,
name|conformance
init|=
literal|67
block|,
name|Virtualization_use
init|=
literal|68
block|,
name|MPextension_use
init|=
literal|70
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __TARGET_ARMBUILDATTRS_H__
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMBuildAttrs.h - ARM Build Attributes ------------------*- C++ -*-===//
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
comment|// as defined in ARM ABI addenda document (ABI release 2.08).
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
name|SpecialAttr
block|{
comment|// This is for the .cpu asm attr. It translates into one or more
comment|// AttrType (below) entries in the .ARM.attributes section in the ELF.
name|SEL_CPU
block|}
enum|;
enum|enum
name|AttrType
block|{
comment|// Rest correspond to ELF/.ARM.attributes
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
name|MPextension_use
init|=
literal|42
block|,
comment|// was 70, 2.08 ABI
name|DIV_use
init|=
literal|44
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
name|MPextension_use_old
init|=
literal|70
block|}
enum|;
comment|// Magic numbers for .ARM.attributes
enum|enum
name|AttrMagic
block|{
name|Format_Version
init|=
literal|0x41
block|}
enum|;
comment|// Legal Values for CPU_arch, (=6), uleb128
enum|enum
name|CPUArch
block|{
name|Pre_v4
init|=
literal|0
block|,
name|v4
init|=
literal|1
block|,
comment|// e.g. SA110
name|v4T
init|=
literal|2
block|,
comment|// e.g. ARM7TDMI
name|v5T
init|=
literal|3
block|,
comment|// e.g. ARM9TDMI
name|v5TE
init|=
literal|4
block|,
comment|// e.g. ARM946E_S
name|v5TEJ
init|=
literal|5
block|,
comment|// e.g. ARM926EJ_S
name|v6
init|=
literal|6
block|,
comment|// e.g. ARM1136J_S
name|v6KZ
init|=
literal|7
block|,
comment|// e.g. ARM1176JZ_S
name|v6T2
init|=
literal|8
block|,
comment|// e.g. ARM1156T2F_S
name|v6K
init|=
literal|9
block|,
comment|// e.g. ARM1136J_S
name|v7
init|=
literal|10
block|,
comment|// e.g. Cortex A8, Cortex M3
name|v6_M
init|=
literal|11
block|,
comment|// e.g. Cortex M1
name|v6S_M
init|=
literal|12
block|,
comment|// v6_M with the System extensions
name|v7E_M
init|=
literal|13
comment|// v7_M with DSP extensions
block|}
enum|;
enum|enum
name|CPUArchProfile
block|{
comment|// (=7), uleb128
name|Not_Applicable
init|=
literal|0
block|,
comment|// pre v7, or cross-profile code
name|ApplicationProfile
init|=
operator|(
literal|0x41
operator|)
block|,
comment|// 'A' (e.g. for Cortex A8)
name|RealTimeProfile
init|=
operator|(
literal|0x52
operator|)
block|,
comment|// 'R' (e.g. for Cortex R4)
name|MicroControllerProfile
init|=
operator|(
literal|0x4D
operator|)
block|,
comment|// 'M' (e.g. for Cortex M3)
name|SystemProfile
init|=
operator|(
literal|0x53
operator|)
comment|// 'S' Application or real-time profile
block|}
enum|;
comment|// The following have a lot of common use cases
enum|enum
block|{
comment|//ARMISAUse (=8), uleb128  and THUMBISAUse (=9), uleb128
name|Not_Allowed
init|=
literal|0
block|,
name|Allowed
init|=
literal|1
block|,
comment|// FP_arch (=10), uleb128 (formerly Tag_VFP_arch = 10)
name|AllowFPv2
init|=
literal|2
block|,
comment|// v2 FP ISA permitted (implies use of the v1 FP ISA)
name|AllowFPv3A
init|=
literal|3
block|,
comment|// v3 FP ISA permitted (implies use of the v2 FP ISA)
name|AllowFPv3B
init|=
literal|4
block|,
comment|// v3 FP ISA permitted, but only D0-D15, S0-S31
name|AllowFPv4A
init|=
literal|5
block|,
comment|// v4 FP ISA permitted (implies use of v3 FP ISA)
name|AllowFPv4B
init|=
literal|6
block|,
comment|// v4 FP ISA was permitted, but only D0-D15, S0-S31
comment|// Tag_WMMX_arch, (=11), uleb128
name|AllowThumb32
init|=
literal|2
block|,
comment|// 32-bit Thumb (implies 16-bit instructions)
comment|// Tag_WMMX_arch, (=11), uleb128
name|AllowWMMXv1
init|=
literal|2
block|,
comment|// The user permitted this entity to use WMMX v2
comment|// Tag_ABI_FP_denormal, (=20), uleb128
name|PreserveFPSign
init|=
literal|2
block|,
comment|// sign when flushed-to-zero is preserved
comment|// Tag_ABI_FP_number_model, (=23), uleb128
name|AllowRTABI
init|=
literal|2
block|,
comment|// numbers, infinities, and one quiet NaN (see [RTABI])
name|AllowIEE754
init|=
literal|3
comment|// this code to use all the IEEE 754-defined FP encodings
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


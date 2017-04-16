begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMBuildAttributes.h - ARM Build Attributes -------------*- C++ -*-===//
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
comment|// ELF for the ARM Architecture r2.09 - November 30, 2012
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// http://infocenter.arm.com/help/topic/com.arm.doc.ihi0044e/IHI0044E_aaelf.pdf
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
name|LLVM_SUPPORT_ARMBUILDATTRIBUTES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ARMBUILDATTRIBUTES_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
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
name|FP_arch
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
name|ABI_align_needed
init|=
literal|24
block|,
name|ABI_align_preserved
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
name|FP_HP_extension
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
comment|// recoded from 70 (ABI r2.08)
name|DIV_use
init|=
literal|44
block|,
name|DSP_extension
init|=
literal|46
block|,
name|also_compatible_with
init|=
literal|65
block|,
name|conformance
init|=
literal|67
block|,
name|Virtualization_use
init|=
literal|68
block|,
comment|/// Legacy Tags
name|Section
init|=
literal|2
block|,
comment|// deprecated (ABI r2.09)
name|Symbol
init|=
literal|3
block|,
comment|// deprecated (ABI r2.09)
name|ABI_align8_needed
init|=
literal|24
block|,
comment|// renamed to ABI_align_needed (ABI r2.09)
name|ABI_align8_preserved
init|=
literal|25
block|,
comment|// renamed to ABI_align_preserved (ABI r2.09)
name|nodefaults
init|=
literal|64
block|,
comment|// deprecated (ABI r2.09)
name|T2EE_use
init|=
literal|66
block|,
comment|// deprecated (ABI r2.09)
name|MPextension_use_old
init|=
literal|70
comment|// recoded to MPextension_use (ABI r2.08)
block|}
enum|;
name|StringRef
name|AttrTypeAsString
parameter_list|(
name|unsigned
name|Attr
parameter_list|,
name|bool
name|HasTagPrefix
init|=
name|true
parameter_list|)
function_decl|;
name|StringRef
name|AttrTypeAsString
parameter_list|(
name|AttrType
name|Attr
parameter_list|,
name|bool
name|HasTagPrefix
init|=
name|true
parameter_list|)
function_decl|;
name|int
name|AttrTypeFromString
parameter_list|(
name|StringRef
name|Tag
parameter_list|)
function_decl|;
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
comment|// e.g. ARM1156T2_S
name|v6K
init|=
literal|9
block|,
comment|// e.g. ARM1176JZ_S
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
block|,
comment|// v7_M with DSP extensions
name|v8_A
init|=
literal|14
block|,
comment|// v8_A AArch32
name|v8_R
init|=
literal|15
block|,
comment|// e.g. Cortex R52
name|v8_M_Base
init|=
literal|16
block|,
comment|// v8_M_Base AArch32
name|v8_M_Main
init|=
literal|17
block|,
comment|// v8_M_Main AArch32
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
name|Not_Allowed
init|=
literal|0
block|,
name|Allowed
init|=
literal|1
block|,
comment|// Tag_ARM_ISA_use (=8), uleb128
comment|// Tag_THUMB_ISA_use, (=9), uleb128
name|AllowThumb32
init|=
literal|2
block|,
comment|// 32-bit Thumb (implies 16-bit instructions)
name|AllowThumbDerived
init|=
literal|3
block|,
comment|// Thumb allowed, derived from arch/profile
comment|// Tag_FP_arch (=10), uleb128 (formerly Tag_VFP_arch = 10)
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
name|AllowFPARMv8A
init|=
literal|7
block|,
comment|// Use of the ARM v8-A FP ISA was permitted
name|AllowFPARMv8B
init|=
literal|8
block|,
comment|// Use of the ARM v8-A FP ISA was permitted, but only
comment|// D0-D15, S0-S31
comment|// Tag_WMMX_arch, (=11), uleb128
name|AllowWMMXv1
init|=
literal|1
block|,
comment|// The user permitted this entity to use WMMX v1
name|AllowWMMXv2
init|=
literal|2
block|,
comment|// The user permitted this entity to use WMMX v2
comment|// Tag_Advanced_SIMD_arch, (=12), uleb128
name|AllowNeon
init|=
literal|1
block|,
comment|// SIMDv1 was permitted
name|AllowNeon2
init|=
literal|2
block|,
comment|// SIMDv2 was permitted (Half-precision FP, MAC operations)
name|AllowNeonARMv8
init|=
literal|3
block|,
comment|// ARM v8-A SIMD was permitted
name|AllowNeonARMv8_1a
init|=
literal|4
block|,
comment|// ARM v8.1-A SIMD was permitted (RDMA)
comment|// Tag_ABI_PCS_R9_use, (=14), uleb128
name|R9IsGPR
init|=
literal|0
block|,
comment|// R9 used as v6 (just another callee-saved register)
name|R9IsSB
init|=
literal|1
block|,
comment|// R9 used as a global static base rgister
name|R9IsTLSPointer
init|=
literal|2
block|,
comment|// R9 used as a thread local storage pointer
name|R9Reserved
init|=
literal|3
block|,
comment|// R9 not used by code associated with attributed entity
comment|// Tag_ABI_PCS_RW_data, (=15), uleb128
name|AddressRWPCRel
init|=
literal|1
block|,
comment|// Address RW static data PC-relative
name|AddressRWSBRel
init|=
literal|2
block|,
comment|// Address RW static data SB-relative
name|AddressRWNone
init|=
literal|3
block|,
comment|// No RW static data permitted
comment|// Tag_ABI_PCS_RO_data, (=14), uleb128
name|AddressROPCRel
init|=
literal|1
block|,
comment|// Address RO static data PC-relative
name|AddressRONone
init|=
literal|2
block|,
comment|// No RO static data permitted
comment|// Tag_ABI_PCS_GOT_use, (=17), uleb128
name|AddressDirect
init|=
literal|1
block|,
comment|// Address imported data directly
name|AddressGOT
init|=
literal|2
block|,
comment|// Address imported data indirectly (via GOT)
comment|// Tag_ABI_PCS_wchar_t, (=18), uleb128
name|WCharProhibited
init|=
literal|0
block|,
comment|// wchar_t is not used
name|WCharWidth2Bytes
init|=
literal|2
block|,
comment|// sizeof(wchar_t) == 2
name|WCharWidth4Bytes
init|=
literal|4
block|,
comment|// sizeof(wchar_t) == 4
comment|// Tag_ABI_align_needed, (=24), uleb128
name|Align8Byte
init|=
literal|1
block|,
name|Align4Byte
init|=
literal|2
block|,
name|AlignReserved
init|=
literal|3
block|,
comment|// Tag_ABI_align_needed, (=25), uleb128
name|AlignNotPreserved
init|=
literal|0
block|,
name|AlignPreserve8Byte
init|=
literal|1
block|,
name|AlignPreserveAll
init|=
literal|2
block|,
comment|// Tag_ABI_FP_denormal, (=20), uleb128
name|PositiveZero
init|=
literal|0
block|,
name|IEEEDenormals
init|=
literal|1
block|,
name|PreserveFPSign
init|=
literal|2
block|,
comment|// sign when flushed-to-zero is preserved
comment|// Tag_ABI_FP_number_model, (=23), uleb128
name|AllowIEEENormal
init|=
literal|1
block|,
name|AllowRTABI
init|=
literal|2
block|,
comment|// numbers, infinities, and one quiet NaN (see [RTABI])
name|AllowIEEE754
init|=
literal|3
block|,
comment|// this code to use all the IEEE 754-defined FP encodings
comment|// Tag_ABI_enum_size, (=26), uleb128
name|EnumProhibited
init|=
literal|0
block|,
comment|// The user prohibited the use of enums when building
comment|// this entity.
name|EnumSmallest
init|=
literal|1
block|,
comment|// Enum is smallest container big enough to hold all
comment|// values.
name|Enum32Bit
init|=
literal|2
block|,
comment|// Enum is at least 32 bits.
name|Enum32BitABI
init|=
literal|3
block|,
comment|// Every enumeration visible across an ABI-complying
comment|// interface contains a value needing 32 bits to encode
comment|// it; other enums can be containerized.
comment|// Tag_ABI_HardFP_use, (=27), uleb128
name|HardFPImplied
init|=
literal|0
block|,
comment|// FP use should be implied by Tag_FP_arch
name|HardFPSinglePrecision
init|=
literal|1
block|,
comment|// Single-precision only
comment|// Tag_ABI_VFP_args, (=28), uleb128
name|BaseAAPCS
init|=
literal|0
block|,
name|HardFPAAPCS
init|=
literal|1
block|,
comment|// Tag_FP_HP_extension, (=36), uleb128
name|AllowHPFP
init|=
literal|1
block|,
comment|// Allow use of Half Precision FP
comment|// Tag_FP_16bit_format, (=38), uleb128
name|FP16FormatIEEE
init|=
literal|1
block|,
name|FP16VFP3
init|=
literal|2
block|,
comment|// Tag_MPextension_use, (=42), uleb128
name|AllowMP
init|=
literal|1
block|,
comment|// Allow use of MP extensions
comment|// Tag_DIV_use, (=44), uleb128
comment|// Note: AllowDIVExt must be emitted if and only if the permission to use
comment|// hardware divide cannot be conveyed using AllowDIVIfExists or DisallowDIV
name|AllowDIVIfExists
init|=
literal|0
block|,
comment|// Allow hardware divide if available in arch, or no
comment|// info exists.
name|DisallowDIV
init|=
literal|1
block|,
comment|// Hardware divide explicitly disallowed.
name|AllowDIVExt
init|=
literal|2
block|,
comment|// Allow hardware divide as optional architecture
comment|// extension above the base arch specified by
comment|// Tag_CPU_arch and Tag_CPU_arch_profile.
comment|// Tag_Virtualization_use, (=68), uleb128
name|AllowTZ
init|=
literal|1
block|,
name|AllowVirtualization
init|=
literal|2
block|,
name|AllowTZVirtualization
init|=
literal|3
block|}
enum|;
block|}
comment|// namespace ARMBuildAttrs
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


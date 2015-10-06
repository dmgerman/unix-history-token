begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TargetParser - Parser for target features ---------------*- C++ -*-===//
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
comment|// This file implements a target parser to recognise hardware features such as
end_comment

begin_comment
comment|// FPU/CPU/ARCH names as well as specific support such as HDIV, etc.
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
name|LLVM_SUPPORT_TARGETPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_TARGETPARSER_H
end_define

begin_comment
comment|// FIXME: vector is used because that's what clang uses for subtarget feature
end_comment

begin_comment
comment|// lists, but SmallVector would probably be better
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
comment|// Target specific information into their own namespaces. These should be
comment|// generated from TableGen because the information is already there, and there
comment|// is where new information about targets will be added.
comment|// FIXME: To TableGen this we need to make some table generated files available
comment|// even if the back-end is not compiled with LLVM, plus we need to create a new
comment|// back-end to TableGen to create these clean tables.
name|namespace
name|ARM
block|{
comment|// FPU names.
enum|enum
name|FPUKind
block|{
name|FK_INVALID
init|=
literal|0
block|,
name|FK_NONE
block|,
name|FK_VFP
block|,
name|FK_VFPV2
block|,
name|FK_VFPV3
block|,
name|FK_VFPV3_FP16
block|,
name|FK_VFPV3_D16
block|,
name|FK_VFPV3_D16_FP16
block|,
name|FK_VFPV3XD
block|,
name|FK_VFPV3XD_FP16
block|,
name|FK_VFPV4
block|,
name|FK_VFPV4_D16
block|,
name|FK_FPV4_SP_D16
block|,
name|FK_FPV5_D16
block|,
name|FK_FPV5_SP_D16
block|,
name|FK_FP_ARMV8
block|,
name|FK_NEON
block|,
name|FK_NEON_FP16
block|,
name|FK_NEON_VFPV4
block|,
name|FK_NEON_FP_ARMV8
block|,
name|FK_CRYPTO_NEON_FP_ARMV8
block|,
name|FK_SOFTVFP
block|,
name|FK_LAST
block|}
enum|;
comment|// FPU Version
enum|enum
name|FPUVersion
block|{
name|FV_NONE
init|=
literal|0
block|,
name|FV_VFPV2
block|,
name|FV_VFPV3
block|,
name|FV_VFPV3_FP16
block|,
name|FV_VFPV4
block|,
name|FV_VFPV5
block|}
enum|;
comment|// An FPU name implies one of three levels of Neon support:
enum|enum
name|NeonSupportLevel
block|{
name|NS_None
init|=
literal|0
block|,
comment|///< No Neon
name|NS_Neon
block|,
comment|///< Neon
name|NS_Crypto
comment|///< Neon with Crypto
block|}
enum|;
comment|// An FPU name restricts the FPU in one of three ways:
enum|enum
name|FPURestriction
block|{
name|FR_None
init|=
literal|0
block|,
comment|///< No restriction
name|FR_D16
block|,
comment|///< Only 16 D registers
name|FR_SP_D16
comment|///< Only single-precision instructions, with 16 D registers
block|}
enum|;
comment|// Arch names.
enum|enum
name|ArchKind
block|{
name|AK_INVALID
init|=
literal|0
block|,
name|AK_ARMV2
block|,
name|AK_ARMV2A
block|,
name|AK_ARMV3
block|,
name|AK_ARMV3M
block|,
name|AK_ARMV4
block|,
name|AK_ARMV4T
block|,
name|AK_ARMV5T
block|,
name|AK_ARMV5TE
block|,
name|AK_ARMV5TEJ
block|,
name|AK_ARMV6
block|,
name|AK_ARMV6K
block|,
name|AK_ARMV6T2
block|,
name|AK_ARMV6Z
block|,
name|AK_ARMV6ZK
block|,
name|AK_ARMV6M
block|,
name|AK_ARMV6SM
block|,
name|AK_ARMV7A
block|,
name|AK_ARMV7R
block|,
name|AK_ARMV7M
block|,
name|AK_ARMV7EM
block|,
name|AK_ARMV8A
block|,
name|AK_ARMV8_1A
block|,
comment|// Non-standard Arch names.
name|AK_IWMMXT
block|,
name|AK_IWMMXT2
block|,
name|AK_XSCALE
block|,
name|AK_ARMV5
block|,
name|AK_ARMV5E
block|,
name|AK_ARMV6J
block|,
name|AK_ARMV6HL
block|,
name|AK_ARMV7
block|,
name|AK_ARMV7L
block|,
name|AK_ARMV7HL
block|,
name|AK_ARMV7S
block|,
name|AK_LAST
block|}
enum|;
comment|// Arch extension modifiers for CPUs.
enum|enum
name|ArchExtKind
block|{
name|AEK_INVALID
init|=
literal|0
block|,
name|AEK_CRC
block|,
name|AEK_CRYPTO
block|,
name|AEK_FP
block|,
name|AEK_HWDIV
block|,
name|AEK_MP
block|,
name|AEK_SIMD
block|,
name|AEK_SEC
block|,
name|AEK_VIRT
block|,
comment|// Unsupported extensions.
name|AEK_OS
block|,
name|AEK_IWMMXT
block|,
name|AEK_IWMMXT2
block|,
name|AEK_MAVERICK
block|,
name|AEK_XSCALE
block|,
name|AEK_LAST
block|}
enum|;
comment|// ISA kinds.
enum|enum
name|ISAKind
block|{
name|IK_INVALID
init|=
literal|0
block|,
name|IK_ARM
block|,
name|IK_THUMB
block|,
name|IK_AARCH64
block|}
enum|;
comment|// Endianness
comment|// FIXME: BE8 vs. BE32?
enum|enum
name|EndianKind
block|{
name|EK_INVALID
init|=
literal|0
block|,
name|EK_LITTLE
block|,
name|EK_BIG
block|}
enum|;
comment|// v6/v7/v8 Profile
enum|enum
name|ProfileKind
block|{
name|PK_INVALID
init|=
literal|0
block|,
name|PK_A
block|,
name|PK_R
block|,
name|PK_M
block|}
enum|;
block|}
comment|// namespace ARM
comment|// Target Parsers, one per architecture.
name|class
name|ARMTargetParser
block|{
specifier|static
name|StringRef
name|getFPUSynonym
parameter_list|(
name|StringRef
name|FPU
parameter_list|)
function_decl|;
specifier|static
name|StringRef
name|getArchSynonym
parameter_list|(
name|StringRef
name|Arch
parameter_list|)
function_decl|;
name|public
label|:
specifier|static
name|StringRef
name|getCanonicalArchName
parameter_list|(
name|StringRef
name|Arch
parameter_list|)
function_decl|;
comment|// Information by ID
specifier|static
specifier|const
name|char
modifier|*
name|getFPUName
parameter_list|(
name|unsigned
name|FPUKind
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|getFPUVersion
parameter_list|(
name|unsigned
name|FPUKind
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|getFPUNeonSupportLevel
parameter_list|(
name|unsigned
name|FPUKind
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|getFPURestriction
parameter_list|(
name|unsigned
name|FPUKind
parameter_list|)
function_decl|;
comment|// FIXME: This should be moved to TargetTuple once it exists
specifier|static
name|bool
name|getFPUFeatures
argument_list|(
name|unsigned
name|FPUKind
argument_list|,
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|Features
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|getArchName
parameter_list|(
name|unsigned
name|ArchKind
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|getArchAttr
parameter_list|(
name|unsigned
name|ArchKind
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|getCPUAttr
parameter_list|(
name|unsigned
name|ArchKind
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|getSubArch
parameter_list|(
name|unsigned
name|ArchKind
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|getArchExtName
parameter_list|(
name|unsigned
name|ArchExtKind
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|getDefaultCPU
parameter_list|(
name|StringRef
name|Arch
parameter_list|)
function_decl|;
comment|// Parser
specifier|static
name|unsigned
name|parseFPU
parameter_list|(
name|StringRef
name|FPU
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|parseArch
parameter_list|(
name|StringRef
name|Arch
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|parseArchExt
parameter_list|(
name|StringRef
name|ArchExt
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|parseCPUArch
parameter_list|(
name|StringRef
name|CPU
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|parseArchISA
parameter_list|(
name|StringRef
name|Arch
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|parseArchEndian
parameter_list|(
name|StringRef
name|Arch
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|parseArchProfile
parameter_list|(
name|StringRef
name|Arch
parameter_list|)
function_decl|;
specifier|static
name|unsigned
name|parseArchVersion
parameter_list|(
name|StringRef
name|Arch
parameter_list|)
function_decl|;
block|}
empty_stmt|;
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


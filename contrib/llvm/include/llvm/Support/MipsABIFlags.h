begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MipsABIFlags.h - MIPS ABI flags ----------------------------------===//
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
comment|// This file defines the constants for the ABI flags structure contained
end_comment

begin_comment
comment|// in the .MIPS.abiflags section.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// https://dmz-portal.mips.com/wiki/MIPS_O32_ABI_-_FR0_and_FR1_Interlinking
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
name|LLVM_SUPPORT_MIPSABIFLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MIPSABIFLAGS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|Mips
block|{
comment|// Values for the xxx_size bytes of an ABI flags structure.
enum|enum
name|AFL_REG
block|{
name|AFL_REG_NONE
init|=
literal|0x00
block|,
comment|// No registers
name|AFL_REG_32
init|=
literal|0x01
block|,
comment|// 32-bit registers
name|AFL_REG_64
init|=
literal|0x02
block|,
comment|// 64-bit registers
name|AFL_REG_128
init|=
literal|0x03
comment|// 128-bit registers
block|}
enum|;
comment|// Masks for the ases word of an ABI flags structure.
enum|enum
name|AFL_ASE
block|{
name|AFL_ASE_DSP
init|=
literal|0x00000001
block|,
comment|// DSP ASE
name|AFL_ASE_DSPR2
init|=
literal|0x00000002
block|,
comment|// DSP R2 ASE
name|AFL_ASE_EVA
init|=
literal|0x00000004
block|,
comment|// Enhanced VA Scheme
name|AFL_ASE_MCU
init|=
literal|0x00000008
block|,
comment|// MCU (MicroController) ASE
name|AFL_ASE_MDMX
init|=
literal|0x00000010
block|,
comment|// MDMX ASE
name|AFL_ASE_MIPS3D
init|=
literal|0x00000020
block|,
comment|// MIPS-3D ASE
name|AFL_ASE_MT
init|=
literal|0x00000040
block|,
comment|// MT ASE
name|AFL_ASE_SMARTMIPS
init|=
literal|0x00000080
block|,
comment|// SmartMIPS ASE
name|AFL_ASE_VIRT
init|=
literal|0x00000100
block|,
comment|// VZ ASE
name|AFL_ASE_MSA
init|=
literal|0x00000200
block|,
comment|// MSA ASE
name|AFL_ASE_MIPS16
init|=
literal|0x00000400
block|,
comment|// MIPS16 ASE
name|AFL_ASE_MICROMIPS
init|=
literal|0x00000800
block|,
comment|// MICROMIPS ASE
name|AFL_ASE_XPA
init|=
literal|0x00001000
comment|// XPA ASE
block|}
enum|;
comment|// Values for the isa_ext word of an ABI flags structure.
enum|enum
name|AFL_EXT
block|{
name|AFL_EXT_NONE
init|=
literal|0
block|,
comment|// None
name|AFL_EXT_XLR
init|=
literal|1
block|,
comment|// RMI Xlr instruction
name|AFL_EXT_OCTEON2
init|=
literal|2
block|,
comment|// Cavium Networks Octeon2
name|AFL_EXT_OCTEONP
init|=
literal|3
block|,
comment|// Cavium Networks OcteonP
name|AFL_EXT_LOONGSON_3A
init|=
literal|4
block|,
comment|// Loongson 3A
name|AFL_EXT_OCTEON
init|=
literal|5
block|,
comment|// Cavium Networks Octeon
name|AFL_EXT_5900
init|=
literal|6
block|,
comment|// MIPS R5900 instruction
name|AFL_EXT_4650
init|=
literal|7
block|,
comment|// MIPS R4650 instruction
name|AFL_EXT_4010
init|=
literal|8
block|,
comment|// LSI R4010 instruction
name|AFL_EXT_4100
init|=
literal|9
block|,
comment|// NEC VR4100 instruction
name|AFL_EXT_3900
init|=
literal|10
block|,
comment|// Toshiba R3900 instruction
name|AFL_EXT_10000
init|=
literal|11
block|,
comment|// MIPS R10000 instruction
name|AFL_EXT_SB1
init|=
literal|12
block|,
comment|// Broadcom SB-1 instruction
name|AFL_EXT_4111
init|=
literal|13
block|,
comment|// NEC VR4111/VR4181 instruction
name|AFL_EXT_4120
init|=
literal|14
block|,
comment|// NEC VR4120 instruction
name|AFL_EXT_5400
init|=
literal|15
block|,
comment|// NEC VR5400 instruction
name|AFL_EXT_5500
init|=
literal|16
block|,
comment|// NEC VR5500 instruction
name|AFL_EXT_LOONGSON_2E
init|=
literal|17
block|,
comment|// ST Microelectronics Loongson 2E
name|AFL_EXT_LOONGSON_2F
init|=
literal|18
block|,
comment|// ST Microelectronics Loongson 2F
name|AFL_EXT_OCTEON3
init|=
literal|19
comment|// Cavium Networks Octeon3
block|}
enum|;
comment|// Values for the flags1 word of an ABI flags structure.
enum|enum
name|AFL_FLAGS1
block|{
name|AFL_FLAGS1_ODDSPREG
init|=
literal|1
block|}
enum|;
comment|// MIPS object attribute tags
enum|enum
block|{
name|Tag_GNU_MIPS_ABI_FP
init|=
literal|4
block|,
comment|// Floating-point ABI used by this object file
name|Tag_GNU_MIPS_ABI_MSA
init|=
literal|8
block|,
comment|// MSA ABI used by this object file
block|}
enum|;
comment|// Values for the fp_abi word of an ABI flags structure
comment|// and for the Tag_GNU_MIPS_ABI_FP attribute tag.
enum|enum
name|Val_GNU_MIPS_ABI_FP
block|{
name|Val_GNU_MIPS_ABI_FP_ANY
init|=
literal|0
block|,
comment|// not tagged
name|Val_GNU_MIPS_ABI_FP_DOUBLE
init|=
literal|1
block|,
comment|// hard float / -mdouble-float
name|Val_GNU_MIPS_ABI_FP_SINGLE
init|=
literal|2
block|,
comment|// hard float / -msingle-float
name|Val_GNU_MIPS_ABI_FP_SOFT
init|=
literal|3
block|,
comment|// soft float
name|Val_GNU_MIPS_ABI_FP_OLD_64
init|=
literal|4
block|,
comment|// -mips32r2 -mfp64
name|Val_GNU_MIPS_ABI_FP_XX
init|=
literal|5
block|,
comment|// -mfpxx
name|Val_GNU_MIPS_ABI_FP_64
init|=
literal|6
block|,
comment|// -mips32r2 -mfp64
name|Val_GNU_MIPS_ABI_FP_64A
init|=
literal|7
comment|// -mips32r2 -mfp64 -mno-odd-spreg
block|}
enum|;
comment|// Values for the Tag_GNU_MIPS_ABI_MSA attribute tag.
enum|enum
name|Val_GNU_MIPS_ABI_MSA
block|{
name|Val_GNU_MIPS_ABI_MSA_ANY
init|=
literal|0
block|,
comment|// not tagged
name|Val_GNU_MIPS_ABI_MSA_128
init|=
literal|1
comment|// 128-bit MSA
block|}
enum|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsFixupKinds.h - Mips Specific Fixup Entries ----------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSFIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSFIXUPKINDS_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCFixup.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|Mips
block|{
comment|// Although most of the current fixup types reflect a unique relocation
comment|// one can have multiple fixup types for a given relocation and thus need
comment|// to be uniquely named.
comment|//
comment|// This table *must* be in the same order of
comment|// MCFixupKindInfo Infos[Mips::NumTargetFixupKinds]
comment|// in MipsAsmBackend.cpp.
comment|//
enum|enum
name|Fixups
block|{
comment|// Branch fixups resulting in R_MIPS_NONE.
name|fixup_Mips_NONE
init|=
name|FirstTargetFixupKind
block|,
comment|// Branch fixups resulting in R_MIPS_16.
name|fixup_Mips_16
block|,
comment|// Pure 32 bit data fixup resulting in - R_MIPS_32.
name|fixup_Mips_32
block|,
comment|// Full 32 bit data relative data fixup resulting in - R_MIPS_REL32.
name|fixup_Mips_REL32
block|,
comment|// Jump 26 bit fixup resulting in - R_MIPS_26.
name|fixup_Mips_26
block|,
comment|// Pure upper 16 bit fixup resulting in - R_MIPS_HI16.
name|fixup_Mips_HI16
block|,
comment|// Pure lower 16 bit fixup resulting in - R_MIPS_LO16.
name|fixup_Mips_LO16
block|,
comment|// 16 bit fixup for GP offest resulting in - R_MIPS_GPREL16.
name|fixup_Mips_GPREL16
block|,
comment|// 16 bit literal fixup resulting in - R_MIPS_LITERAL.
name|fixup_Mips_LITERAL
block|,
comment|// Symbol fixup resulting in - R_MIPS_GOT16.
name|fixup_Mips_GOT
block|,
comment|// PC relative branch fixup resulting in - R_MIPS_PC16.
name|fixup_Mips_PC16
block|,
comment|// resulting in - R_MIPS_CALL16.
name|fixup_Mips_CALL16
block|,
comment|// resulting in - R_MIPS_GPREL32.
name|fixup_Mips_GPREL32
block|,
comment|// resulting in - R_MIPS_SHIFT5.
name|fixup_Mips_SHIFT5
block|,
comment|// resulting in - R_MIPS_SHIFT6.
name|fixup_Mips_SHIFT6
block|,
comment|// Pure 64 bit data fixup resulting in - R_MIPS_64.
name|fixup_Mips_64
block|,
comment|// resulting in - R_MIPS_TLS_GD.
name|fixup_Mips_TLSGD
block|,
comment|// resulting in - R_MIPS_TLS_GOTTPREL.
name|fixup_Mips_GOTTPREL
block|,
comment|// resulting in - R_MIPS_TLS_TPREL_HI16.
name|fixup_Mips_TPREL_HI
block|,
comment|// resulting in - R_MIPS_TLS_TPREL_LO16.
name|fixup_Mips_TPREL_LO
block|,
comment|// resulting in - R_MIPS_TLS_LDM.
name|fixup_Mips_TLSLDM
block|,
comment|// resulting in - R_MIPS_TLS_DTPREL_HI16.
name|fixup_Mips_DTPREL_HI
block|,
comment|// resulting in - R_MIPS_TLS_DTPREL_LO16.
name|fixup_Mips_DTPREL_LO
block|,
comment|// PC relative branch fixup resulting in - R_MIPS_PC16
name|fixup_Mips_Branch_PCRel
block|,
comment|// resulting in - R_MIPS_GPREL16/R_MIPS_SUB/R_MIPS_HI16
name|fixup_Mips_GPOFF_HI
block|,
comment|// resulting in - R_MIPS_GPREL16/R_MIPS_SUB/R_MIPS_LO16
name|fixup_Mips_GPOFF_LO
block|,
comment|// resulting in - R_MIPS_PAGE
name|fixup_Mips_GOT_PAGE
block|,
comment|// resulting in - R_MIPS_GOT_OFST
name|fixup_Mips_GOT_OFST
block|,
comment|// resulting in - R_MIPS_GOT_DISP
name|fixup_Mips_GOT_DISP
block|,
comment|// resulting in - R_MIPS_GOT_HIGHER
name|fixup_Mips_HIGHER
block|,
comment|// resulting in - R_MIPS_HIGHEST
name|fixup_Mips_HIGHEST
block|,
comment|// resulting in - R_MIPS_GOT_HI16
name|fixup_Mips_GOT_HI16
block|,
comment|// resulting in - R_MIPS_GOT_LO16
name|fixup_Mips_GOT_LO16
block|,
comment|// resulting in - R_MIPS_CALL_HI16
name|fixup_Mips_CALL_HI16
block|,
comment|// resulting in - R_MIPS_CALL_LO16
name|fixup_Mips_CALL_LO16
block|,
comment|// resulting in - R_MIPS_PC18_S3
name|fixup_MIPS_PC18_S3
block|,
comment|// resulting in - R_MIPS_PC19_S2
name|fixup_MIPS_PC19_S2
block|,
comment|// resulting in - R_MIPS_PC21_S2
name|fixup_MIPS_PC21_S2
block|,
comment|// resulting in - R_MIPS_PC26_S2
name|fixup_MIPS_PC26_S2
block|,
comment|// resulting in - R_MIPS_PCHI16
name|fixup_MIPS_PCHI16
block|,
comment|// resulting in - R_MIPS_PCLO16
name|fixup_MIPS_PCLO16
block|,
comment|// resulting in - R_MICROMIPS_26_S1
name|fixup_MICROMIPS_26_S1
block|,
comment|// resulting in - R_MICROMIPS_HI16
name|fixup_MICROMIPS_HI16
block|,
comment|// resulting in - R_MICROMIPS_LO16
name|fixup_MICROMIPS_LO16
block|,
comment|// resulting in - R_MICROMIPS_GOT16
name|fixup_MICROMIPS_GOT16
block|,
comment|// resulting in - R_MICROMIPS_PC7_S1
name|fixup_MICROMIPS_PC7_S1
block|,
comment|// resulting in - R_MICROMIPS_PC10_S1
name|fixup_MICROMIPS_PC10_S1
block|,
comment|// resulting in - R_MICROMIPS_PC16_S1
name|fixup_MICROMIPS_PC16_S1
block|,
comment|// resulting in - R_MICROMIPS_PC26_S1
name|fixup_MICROMIPS_PC26_S1
block|,
comment|// resulting in - R_MICROMIPS_PC19_S2
name|fixup_MICROMIPS_PC19_S2
block|,
comment|// resulting in - R_MICROMIPS_PC18_S3
name|fixup_MICROMIPS_PC18_S3
block|,
comment|// resulting in - R_MICROMIPS_PC21_S1
name|fixup_MICROMIPS_PC21_S1
block|,
comment|// resulting in - R_MICROMIPS_CALL16
name|fixup_MICROMIPS_CALL16
block|,
comment|// resulting in - R_MICROMIPS_GOT_DISP
name|fixup_MICROMIPS_GOT_DISP
block|,
comment|// resulting in - R_MICROMIPS_GOT_PAGE
name|fixup_MICROMIPS_GOT_PAGE
block|,
comment|// resulting in - R_MICROMIPS_GOT_OFST
name|fixup_MICROMIPS_GOT_OFST
block|,
comment|// resulting in - R_MICROMIPS_TLS_GD
name|fixup_MICROMIPS_TLS_GD
block|,
comment|// resulting in - R_MICROMIPS_TLS_LDM
name|fixup_MICROMIPS_TLS_LDM
block|,
comment|// resulting in - R_MICROMIPS_TLS_DTPREL_HI16
name|fixup_MICROMIPS_TLS_DTPREL_HI16
block|,
comment|// resulting in - R_MICROMIPS_TLS_DTPREL_LO16
name|fixup_MICROMIPS_TLS_DTPREL_LO16
block|,
comment|// resulting in - R_MICROMIPS_TLS_GOTTPREL.
name|fixup_MICROMIPS_GOTTPREL
block|,
comment|// resulting in - R_MICROMIPS_TLS_TPREL_HI16
name|fixup_MICROMIPS_TLS_TPREL_HI16
block|,
comment|// resulting in - R_MICROMIPS_TLS_TPREL_LO16
name|fixup_MICROMIPS_TLS_TPREL_LO16
block|,
comment|// resulting in - R_MIPS_SUB/R_MICROMIPS_SUB
name|fixup_Mips_SUB
block|,
name|fixup_MICROMIPS_SUB
block|,
comment|// Marker
name|LastTargetFixupKind
block|,
name|NumTargetFixupKinds
init|=
name|LastTargetFixupKind
operator|-
name|FirstTargetFixupKind
block|}
enum|;
block|}
comment|// namespace Mips
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


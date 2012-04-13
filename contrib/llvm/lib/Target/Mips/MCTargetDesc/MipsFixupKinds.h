begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_Mips_MipsFIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_Mips_MipsFIXUPKINDS_H
end_define

begin_comment
comment|//===-- Mips/MipsFixupKinds.h - Mips Specific Fixup Entries --------*- C++ -*-===//
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
enum|enum
name|Fixups
block|{
comment|// fixup_Mips_xxx - R_MIPS_NONE
name|fixup_Mips_NONE
init|=
name|FirstTargetFixupKind
block|,
comment|// fixup_Mips_xxx - R_MIPS_16.
name|fixup_Mips_16
block|,
comment|// fixup_Mips_xxx - R_MIPS_32.
name|fixup_Mips_32
block|,
comment|// fixup_Mips_xxx - R_MIPS_REL32.
name|fixup_Mips_REL32
block|,
comment|// fixup_Mips_xxx - R_MIPS_26.
name|fixup_Mips_26
block|,
comment|// fixup_Mips_xxx - R_MIPS_HI16.
name|fixup_Mips_HI16
block|,
comment|// fixup_Mips_xxx - R_MIPS_LO16.
name|fixup_Mips_LO16
block|,
comment|// fixup_Mips_xxx - R_MIPS_GPREL16.
name|fixup_Mips_GPREL16
block|,
comment|// fixup_Mips_xxx - R_MIPS_LITERAL.
name|fixup_Mips_LITERAL
block|,
comment|// fixup_Mips_xxx - R_MIPS_GOT16.
name|fixup_Mips_GOT16
block|,
comment|// fixup_Mips_xxx - R_MIPS_PC16.
name|fixup_Mips_PC16
block|,
comment|// fixup_Mips_xxx - R_MIPS_CALL16.
name|fixup_Mips_CALL16
block|,
comment|// fixup_Mips_xxx - R_MIPS_GPREL32.
name|fixup_Mips_GPREL32
block|,
comment|// fixup_Mips_xxx - R_MIPS_SHIFT5.
name|fixup_Mips_SHIFT5
block|,
comment|// fixup_Mips_xxx - R_MIPS_SHIFT6.
name|fixup_Mips_SHIFT6
block|,
comment|// fixup_Mips_xxx - R_MIPS_64.
name|fixup_Mips_64
block|,
comment|// fixup_Mips_xxx - R_MIPS_TLS_GD.
name|fixup_Mips_TLSGD
block|,
comment|// fixup_Mips_xxx - R_MIPS_TLS_GOTTPREL.
name|fixup_Mips_GOTTPREL
block|,
comment|// fixup_Mips_xxx - R_MIPS_TLS_TPREL_HI16.
name|fixup_Mips_TPREL_HI
block|,
comment|// fixup_Mips_xxx - R_MIPS_TLS_TPREL_LO16.
name|fixup_Mips_TPREL_LO
block|,
comment|// fixup_Mips_xxx - yyy. // This should become R_MIPS_PC16
name|fixup_Mips_Branch_PCRel
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
comment|// namespace llvm
block|}
end_decl_stmt

begin_comment
comment|// namespace Mips
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_Mips_MipsFIXUPKINDS_H */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LanaiFixupKinds.h - Lanai Specific Fixup Entries --------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_LANAI_MCTARGETDESC_LANAIFIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_LANAI_MCTARGETDESC_LANAIFIXUPKINDS_H
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
name|Lanai
block|{
comment|// Although most of the current fixup types reflect a unique relocation
comment|// one can have multiple fixup types for a given relocation and thus need
comment|// to be uniquely named.
comment|//
comment|// This table *must* be in the save order of
comment|// MCFixupKindInfo Infos[Lanai::NumTargetFixupKinds]
comment|// in LanaiAsmBackend.cpp.
comment|//
enum|enum
name|Fixups
block|{
comment|// Results in R_Lanai_NONE
name|FIXUP_LANAI_NONE
init|=
name|FirstTargetFixupKind
block|,
name|FIXUP_LANAI_21
block|,
comment|// 21-bit symbol relocation
name|FIXUP_LANAI_21_F
block|,
comment|// 21-bit symbol relocation, last two bits masked to 0
name|FIXUP_LANAI_25
block|,
comment|// 25-bit branch targets
name|FIXUP_LANAI_32
block|,
comment|// general 32-bit relocation
name|FIXUP_LANAI_HI16
block|,
comment|// upper 16-bits of a symbolic relocation
name|FIXUP_LANAI_LO16
block|,
comment|// lower 16-bits of a symbolic relocation
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
comment|// namespace Lanai
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_LANAI_MCTARGETDESC_LANAIFIXUPKINDS_H
end_comment

end_unit


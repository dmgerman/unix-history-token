begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZMCFixups.h - SystemZ-specific fixup entries ------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_SYSTEMZ_MCTARGETDESC_SYSTEMZMCFIXUPS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SYSTEMZ_MCTARGETDESC_SYSTEMZMCFIXUPS_H
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
name|SystemZ
block|{
enum|enum
name|FixupKind
block|{
comment|// These correspond directly to R_390_* relocations.
name|FK_390_PC16DBL
init|=
name|FirstTargetFixupKind
block|,
name|FK_390_PC32DBL
block|,
name|FK_390_PLT16DBL
block|,
name|FK_390_PLT32DBL
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
comment|// end namespace SystemZ
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


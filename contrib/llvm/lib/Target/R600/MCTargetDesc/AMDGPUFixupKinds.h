begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUFixupKinds.h - AMDGPU Specific Fixup Entries ------*- C++ -*-===//
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
name|LLVM_AMDGPUFIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AMDGPUFIXUPKINDS_H
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
name|AMDGPU
block|{
enum|enum
name|Fixups
block|{
comment|/// 16-bit PC relative fixup for SOPP branch instructions.
name|fixup_si_sopp_br
init|=
name|FirstTargetFixupKind
block|,
comment|/// fixup for global addresses with constant initializers
name|fixup_si_rodata
block|,
comment|/// fixup for offset from instruction to end of text section
name|fixup_si_end_of_text
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
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_AMDGPUFIXUPKINDS_H
end_comment

end_unit


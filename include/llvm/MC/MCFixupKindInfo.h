begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCFixupKindInfo.h - Fixup Descriptors -----------*- C++ -*-===//
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
name|LLVM_MC_MCFIXUPKINDINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCFIXUPKINDINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MCFixupKindInfo - Target independent information on a fixup kind.
struct|struct
name|MCFixupKindInfo
block|{
enum|enum
name|FixupKindFlags
block|{
comment|/// Is this fixup kind PCrelative? This is used by the assembler backend to
comment|/// evaluate fixup values in a target independent manner when possible.
name|FKF_IsPCRel
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/// Should this fixup kind force a 4-byte aligned effective PC value?
name|FKF_IsAlignedDownTo32Bits
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|}
enum|;
comment|/// A target specific name for the fixup kind. The names will be unique for
comment|/// distinct kinds on any given target.
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|/// The bit offset to write the relocation into.
name|unsigned
name|TargetOffset
decl_stmt|;
comment|/// The number of bits written by this fixup. The bits are assumed to be
comment|/// contiguous.
name|unsigned
name|TargetSize
decl_stmt|;
comment|/// Flags describing additional information on this fixup kind.
name|unsigned
name|Flags
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


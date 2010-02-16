begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCCodeEmitter.h - Instruction Encoding ----------*- C++ -*-===//
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
name|LLVM_MC_MCCODEEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCCODEEMITTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCFixup.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|/// MCFixupKindInfo - Target independent information on a fixup kind.
struct|struct
name|MCFixupKindInfo
block|{
comment|/// A target specific name for the fixup kind. The names will be unique for
comment|/// distinct kinds on any given target.
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|/// The bit offset to write the relocation into.
comment|//
comment|// FIXME: These two fields are under-specified and not general enough, but it
comment|// is covers many things, and is enough to let the AsmStreamer pretty-print
comment|// the encoding.
name|unsigned
name|TargetOffset
decl_stmt|;
comment|/// The number of bits written by this fixup. The bits are assumed to be
comment|/// contiguous.
name|unsigned
name|TargetSize
decl_stmt|;
block|}
struct|;
comment|/// MCCodeEmitter - Generic instruction encoding interface.
name|class
name|MCCodeEmitter
block|{
name|private
label|:
name|MCCodeEmitter
argument_list|(
specifier|const
name|MCCodeEmitter
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCCodeEmitter
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
comment|// Can only create subclasses.
name|MCCodeEmitter
argument_list|()
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|MCCodeEmitter
argument_list|()
expr_stmt|;
comment|/// @name Target Independent Fixup Information
comment|/// @{
comment|/// getNumFixupKinds - Get the number of target specific fixup kinds.
name|virtual
name|unsigned
name|getNumFixupKinds
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// getFixupKindInfo - Get information on a fixup kind.
name|virtual
specifier|const
name|MCFixupKindInfo
modifier|&
name|getFixupKindInfo
argument_list|(
name|MCFixupKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// EncodeInstruction - Encode the given \arg Inst to bytes on the output
comment|/// stream \arg OS.
name|virtual
name|void
name|EncodeInstruction
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|,
name|SmallVectorImpl
operator|<
name|MCFixup
operator|>
operator|&
name|Fixups
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
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


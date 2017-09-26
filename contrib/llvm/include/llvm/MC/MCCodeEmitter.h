begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/MCCodeEmitter.h - Instruction Encoding -----------*- C++ -*-===//
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCFixup
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCSubtargetInfo
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
comment|/// MCCodeEmitter - Generic instruction encoding interface.
name|class
name|MCCodeEmitter
block|{
name|protected
label|:
comment|// Can only create subclasses.
name|MCCodeEmitter
argument_list|()
expr_stmt|;
name|public
label|:
name|MCCodeEmitter
argument_list|(
specifier|const
name|MCCodeEmitter
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|MCCodeEmitter
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCCodeEmitter
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|virtual
operator|~
name|MCCodeEmitter
argument_list|()
expr_stmt|;
comment|/// Lifetime management
name|virtual
name|void
name|reset
parameter_list|()
block|{}
comment|/// EncodeInstruction - Encode the given \p Inst to bytes on the output
comment|/// stream \p OS.
name|virtual
name|void
name|encodeInstruction
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
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
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
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCCODEEMITTER_H
end_comment

end_unit


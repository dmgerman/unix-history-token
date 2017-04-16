begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MipsELFStreamer.h - ELF Object Output --------------------*- C++ -*-===//
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
comment|// This is a custom MCELFStreamer which allows us to insert some hooks before
end_comment

begin_comment
comment|// emitting data into an actual object file.
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
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSELFSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSELFSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"MipsOptionRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCELFStreamer.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmBackend
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|MipsELFStreamer
range|:
name|public
name|MCELFStreamer
block|{
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MipsOptionRecord
operator|>
block|,
literal|8
operator|>
name|MipsOptionRecords
block|;
name|MipsRegInfoRecord
operator|*
name|RegInfoRecord
block|;
name|SmallVector
operator|<
name|MCSymbol
operator|*
block|,
literal|4
operator|>
name|Labels
block|;
name|public
operator|:
name|MipsELFStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|,
name|MCAsmBackend
operator|&
name|MAB
argument_list|,
name|raw_pwrite_stream
operator|&
name|OS
argument_list|,
name|MCCodeEmitter
operator|*
name|Emitter
argument_list|)
operator|:
name|MCELFStreamer
argument_list|(
argument|Context
argument_list|,
argument|MAB
argument_list|,
argument|OS
argument_list|,
argument|Emitter
argument_list|)
block|{
name|RegInfoRecord
operator|=
name|new
name|MipsRegInfoRecord
argument_list|(
name|this
argument_list|,
name|Context
argument_list|)
block|;
name|MipsOptionRecords
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MipsRegInfoRecord
operator|>
operator|(
name|RegInfoRecord
operator|)
argument_list|)
block|;   }
comment|/// Overriding this function allows us to add arbitrary behaviour before the
comment|/// \p Inst is actually emitted. For example, we can inspect the operands and
comment|/// gather sufficient information that allows us to reason about the register
comment|/// usage for the translation unit.
name|void
name|EmitInstruction
argument_list|(
argument|const MCInst&Inst
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|,
argument|bool = false
argument_list|)
name|override
block|;
comment|/// Overriding this function allows us to record all labels that should be
comment|/// marked as microMIPS. Based on this data marking is done in
comment|/// EmitInstruction.
name|void
name|EmitLabel
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
name|override
block|;
comment|/// Overriding this function allows us to dismiss all labels that are
comment|/// candidates for marking as microMIPS when .section directive is processed.
name|void
name|SwitchSection
argument_list|(
argument|MCSection *Section
argument_list|,
argument|const MCExpr *Subsection = nullptr
argument_list|)
name|override
block|;
comment|/// Overriding this function allows us to dismiss all labels that are
comment|/// candidates for marking as microMIPS when .word directive is emitted.
name|void
name|EmitValueImpl
argument_list|(
argument|const MCExpr *Value
argument_list|,
argument|unsigned Size
argument_list|,
argument|SMLoc Loc
argument_list|)
name|override
block|;
comment|/// Emits all the option records stored up until the point it's called.
name|void
name|EmitMipsOptionRecords
argument_list|()
block|;
comment|/// Mark labels as microMIPS, if necessary for the subtarget.
name|void
name|createPendingLabelRelocs
argument_list|()
block|; }
decl_stmt|;
name|MCELFStreamer
modifier|*
name|createMipsELFStreamer
parameter_list|(
name|MCContext
modifier|&
name|Context
parameter_list|,
name|MCAsmBackend
modifier|&
name|MAB
parameter_list|,
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|MCCodeEmitter
modifier|*
name|Emitter
parameter_list|,
name|bool
name|RelaxAll
parameter_list|)
function_decl|;
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
comment|// LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSELFSTREAMER_H
end_comment

end_unit


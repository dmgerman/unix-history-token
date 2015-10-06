begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCObjectStreamer.h - MCStreamer Object File Interface ----*- C++ -*-===//
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
name|LLVM_MC_MCOBJECTSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCOBJECTSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAssembler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAssembler
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCFragment
decl_stmt|;
name|class
name|MCDataFragment
decl_stmt|;
name|class
name|MCAsmBackend
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
comment|/// \brief Streaming object file generation interface.
comment|///
comment|/// This class provides an implementation of the MCStreamer interface which is
comment|/// suitable for use with the assembler backend. Specific object file formats
comment|/// are expected to subclass this interface to implement directives specific
comment|/// to that file format or custom semantics expected by the object writer
comment|/// implementation.
name|class
name|MCObjectStreamer
range|:
name|public
name|MCStreamer
block|{
name|MCAssembler
operator|*
name|Assembler
block|;
name|MCSection
operator|::
name|iterator
name|CurInsertionPoint
block|;
name|bool
name|EmitEHFrame
block|;
name|bool
name|EmitDebugFrame
block|;
name|SmallVector
operator|<
name|MCSymbol
operator|*
block|,
literal|2
operator|>
name|PendingLabels
block|;
name|virtual
name|void
name|EmitInstToData
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
argument_list|)
operator|=
literal|0
block|;
name|void
name|EmitCFIStartProcImpl
argument_list|(
argument|MCDwarfFrameInfo&Frame
argument_list|)
name|override
block|;
name|void
name|EmitCFIEndProcImpl
argument_list|(
argument|MCDwarfFrameInfo&Frame
argument_list|)
name|override
block|;
name|protected
operator|:
name|MCObjectStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|,
name|MCAsmBackend
operator|&
name|TAB
argument_list|,
name|raw_pwrite_stream
operator|&
name|OS
argument_list|,
name|MCCodeEmitter
operator|*
name|Emitter
argument_list|)
block|;
operator|~
name|MCObjectStreamer
argument_list|()
name|override
block|;
name|public
operator|:
comment|/// state management
name|void
name|reset
argument_list|()
name|override
block|;
comment|/// Object streamers require the integrated assembler.
name|bool
name|isIntegratedAssemblerRequired
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|void
name|EmitFrames
argument_list|(
name|MCAsmBackend
operator|*
name|MAB
argument_list|)
block|;
name|void
name|EmitCFISections
argument_list|(
argument|bool EH
argument_list|,
argument|bool Debug
argument_list|)
name|override
block|;
name|protected
operator|:
name|MCFragment
operator|*
name|getCurrentFragment
argument_list|()
specifier|const
block|;
name|void
name|insert
argument_list|(
argument|MCFragment *F
argument_list|)
block|{
name|flushPendingLabels
argument_list|(
name|F
argument_list|)
block|;
name|MCSection
operator|*
name|CurSection
operator|=
name|getCurrentSectionOnly
argument_list|()
block|;
name|CurSection
operator|->
name|getFragmentList
argument_list|()
operator|.
name|insert
argument_list|(
name|CurInsertionPoint
argument_list|,
name|F
argument_list|)
block|;
name|F
operator|->
name|setParent
argument_list|(
name|CurSection
argument_list|)
block|;   }
comment|/// Get a data fragment to write into, creating a new one if the current
comment|/// fragment is not a data fragment.
name|MCDataFragment
operator|*
name|getOrCreateDataFragment
argument_list|()
block|;
name|bool
name|changeSectionImpl
argument_list|(
name|MCSection
operator|*
name|Section
argument_list|,
specifier|const
name|MCExpr
operator|*
name|Subsection
argument_list|)
block|;
comment|/// If any labels have been emitted but not assigned fragments, ensure that
comment|/// they get assigned, either to F if possible or to a new data fragment.
comment|/// Optionally, it is also possible to provide an offset \p FOffset, which
comment|/// will be used as a symbol offset within the fragment.
name|void
name|flushPendingLabels
argument_list|(
argument|MCFragment *F
argument_list|,
argument|uint64_t FOffset =
literal|0
argument_list|)
block|;
name|public
operator|:
name|void
name|visitUsedSymbol
argument_list|(
argument|const MCSymbol&Sym
argument_list|)
name|override
block|;
name|MCAssembler
operator|&
name|getAssembler
argument_list|()
block|{
return|return
operator|*
name|Assembler
return|;
block|}
comment|/// \name MCStreamer Interface
comment|/// @{
name|void
name|EmitLabel
argument_list|(
argument|MCSymbol *Symbol
argument_list|)
name|override
block|;
name|void
name|EmitAssignment
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|const MCExpr *Value
argument_list|)
name|override
block|;
name|void
name|EmitValueImpl
argument_list|(
argument|const MCExpr *Value
argument_list|,
argument|unsigned Size
argument_list|,
argument|const SMLoc&Loc = SMLoc()
argument_list|)
name|override
block|;
name|void
name|EmitULEB128Value
argument_list|(
argument|const MCExpr *Value
argument_list|)
name|override
block|;
name|void
name|EmitSLEB128Value
argument_list|(
argument|const MCExpr *Value
argument_list|)
name|override
block|;
name|void
name|EmitWeakReference
argument_list|(
argument|MCSymbol *Alias
argument_list|,
argument|const MCSymbol *Symbol
argument_list|)
name|override
block|;
name|void
name|ChangeSection
argument_list|(
argument|MCSection *Section
argument_list|,
argument|const MCExpr *Subsection
argument_list|)
name|override
block|;
name|void
name|EmitInstruction
argument_list|(
argument|const MCInst&Inst
argument_list|,
argument|const MCSubtargetInfo& STI
argument_list|)
name|override
block|;
comment|/// \brief Emit an instruction to a special fragment, because this instruction
comment|/// can change its size during relaxation.
name|virtual
name|void
name|EmitInstToFragment
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
argument_list|)
block|;
name|void
name|EmitBundleAlignMode
argument_list|(
argument|unsigned AlignPow2
argument_list|)
name|override
block|;
name|void
name|EmitBundleLock
argument_list|(
argument|bool AlignToEnd
argument_list|)
name|override
block|;
name|void
name|EmitBundleUnlock
argument_list|()
name|override
block|;
name|void
name|EmitBytes
argument_list|(
argument|StringRef Data
argument_list|)
name|override
block|;
name|void
name|EmitValueToAlignment
argument_list|(
argument|unsigned ByteAlignment
argument_list|,
argument|int64_t Value =
literal|0
argument_list|,
argument|unsigned ValueSize =
literal|1
argument_list|,
argument|unsigned MaxBytesToEmit =
literal|0
argument_list|)
name|override
block|;
name|void
name|EmitCodeAlignment
argument_list|(
argument|unsigned ByteAlignment
argument_list|,
argument|unsigned MaxBytesToEmit =
literal|0
argument_list|)
name|override
block|;
name|bool
name|EmitValueToOffset
argument_list|(
argument|const MCExpr *Offset
argument_list|,
argument|unsigned char Value
argument_list|)
name|override
block|;
name|void
name|EmitDwarfLocDirective
argument_list|(
argument|unsigned FileNo
argument_list|,
argument|unsigned Line
argument_list|,
argument|unsigned Column
argument_list|,
argument|unsigned Flags
argument_list|,
argument|unsigned Isa
argument_list|,
argument|unsigned Discriminator
argument_list|,
argument|StringRef FileName
argument_list|)
name|override
block|;
name|void
name|EmitDwarfAdvanceLineAddr
argument_list|(
argument|int64_t LineDelta
argument_list|,
argument|const MCSymbol *LastLabel
argument_list|,
argument|const MCSymbol *Label
argument_list|,
argument|unsigned PointerSize
argument_list|)
block|;
name|void
name|EmitDwarfAdvanceFrameAddr
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|LastLabel
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Label
argument_list|)
block|;
name|void
name|EmitGPRel32Value
argument_list|(
argument|const MCExpr *Value
argument_list|)
name|override
block|;
name|void
name|EmitGPRel64Value
argument_list|(
argument|const MCExpr *Value
argument_list|)
name|override
block|;
name|void
name|EmitFill
argument_list|(
argument|uint64_t NumBytes
argument_list|,
argument|uint8_t FillValue
argument_list|)
name|override
block|;
name|void
name|EmitZeros
argument_list|(
argument|uint64_t NumBytes
argument_list|)
name|override
block|;
name|void
name|FinishImpl
argument_list|()
name|override
block|;
comment|/// Emit the absolute difference between two symbols if possible.
comment|///
comment|/// Emit the absolute difference between \c Hi and \c Lo, as long as we can
comment|/// compute it.  Currently, that requires that both symbols are in the same
comment|/// data fragment.  Otherwise, do nothing and return \c false.
comment|///
comment|/// \pre Offset of \c Hi is greater than the offset \c Lo.
name|void
name|emitAbsoluteSymbolDiff
argument_list|(
argument|const MCSymbol *Hi
argument_list|,
argument|const MCSymbol *Lo
argument_list|,
argument|unsigned Size
argument_list|)
name|override
block|;
name|bool
name|mayHaveInstructions
argument_list|(
argument|MCSection&Sec
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
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


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
name|MCSectionData
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
name|TargetAsmBackend
decl_stmt|;
name|class
name|raw_ostream
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
name|MCSectionData
operator|*
name|CurSectionData
block|;
name|virtual
name|void
name|EmitInstToData
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|MCObjectStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|,
name|TargetAsmBackend
operator|&
name|TAB
argument_list|,
name|raw_ostream
operator|&
name|_OS
argument_list|,
name|MCCodeEmitter
operator|*
name|_Emitter
argument_list|)
block|;
name|MCObjectStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|,
name|TargetAsmBackend
operator|&
name|TAB
argument_list|,
name|raw_ostream
operator|&
name|_OS
argument_list|,
name|MCCodeEmitter
operator|*
name|_Emitter
argument_list|,
name|MCAssembler
operator|*
name|_Assembler
argument_list|)
block|;
operator|~
name|MCObjectStreamer
argument_list|()
block|;
name|MCSectionData
operator|*
name|getCurrentSectionData
argument_list|()
specifier|const
block|{
return|return
name|CurSectionData
return|;
block|}
name|MCFragment
operator|*
name|getCurrentFragment
argument_list|()
specifier|const
block|;
comment|/// Get a data fragment to write into, creating a new one if the current
comment|/// fragment is not a data fragment.
name|MCDataFragment
operator|*
name|getOrCreateDataFragment
argument_list|()
specifier|const
block|;
specifier|const
name|MCExpr
operator|*
name|AddValueSymbols
argument_list|(
specifier|const
name|MCExpr
operator|*
name|Value
argument_list|)
block|;
name|public
operator|:
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
comment|/// @name MCStreamer Interface
comment|/// @{
name|virtual
name|void
name|EmitLabel
argument_list|(
name|MCSymbol
operator|*
name|Symbol
argument_list|)
block|;
name|virtual
name|void
name|EmitValueImpl
argument_list|(
argument|const MCExpr *Value
argument_list|,
argument|unsigned Size
argument_list|,
argument|unsigned AddrSpace
argument_list|)
block|;
name|virtual
name|void
name|EmitULEB128Value
argument_list|(
specifier|const
name|MCExpr
operator|*
name|Value
argument_list|)
block|;
name|virtual
name|void
name|EmitSLEB128Value
argument_list|(
specifier|const
name|MCExpr
operator|*
name|Value
argument_list|)
block|;
name|virtual
name|void
name|EmitWeakReference
argument_list|(
name|MCSymbol
operator|*
name|Alias
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Symbol
argument_list|)
block|;
name|virtual
name|void
name|ChangeSection
argument_list|(
specifier|const
name|MCSection
operator|*
name|Section
argument_list|)
block|;
name|virtual
name|void
name|EmitInstruction
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|)
block|;
name|virtual
name|void
name|EmitInstToFragment
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|)
block|;
name|virtual
name|void
name|EmitValueToOffset
argument_list|(
argument|const MCExpr *Offset
argument_list|,
argument|unsigned char Value
argument_list|)
block|;
name|virtual
name|void
name|EmitDwarfAdvanceLineAddr
argument_list|(
argument|int64_t LineDelta
argument_list|,
argument|const MCSymbol *LastLabel
argument_list|,
argument|const MCSymbol *Label
argument_list|)
block|;
name|virtual
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
name|virtual
name|void
name|Finish
argument_list|()
block|;
comment|/// @}
block|}
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


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCWinCOFFStreamer.h - COFF Object File Interface ---------*- C++ -*-===//
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
name|LLVM_MC_MCWINCOFFSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCWINCOFFSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCDirectives.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCObjectStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmBackend
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
name|class
name|MCWinCOFFStreamer
range|:
name|public
name|MCObjectStreamer
block|{
name|public
operator|:
name|MCWinCOFFStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|,
name|MCAsmBackend
operator|&
name|MAB
argument_list|,
name|MCCodeEmitter
operator|&
name|CE
argument_list|,
name|raw_pwrite_stream
operator|&
name|OS
argument_list|)
block|;
comment|/// state management
name|void
name|reset
argument_list|()
name|override
block|{
name|CurSymbol
operator|=
name|nullptr
block|;
name|MCObjectStreamer
operator|::
name|reset
argument_list|()
block|;   }
comment|/// \name MCStreamer interface
comment|/// \{
name|void
name|InitSections
argument_list|(
argument|bool NoExecStack
argument_list|)
name|override
block|;
name|void
name|EmitLabel
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
name|override
block|;
name|void
name|EmitAssemblerFlag
argument_list|(
argument|MCAssemblerFlag Flag
argument_list|)
name|override
block|;
name|void
name|EmitThumbFunc
argument_list|(
argument|MCSymbol *Func
argument_list|)
name|override
block|;
name|bool
name|EmitSymbolAttribute
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|MCSymbolAttr Attribute
argument_list|)
name|override
block|;
name|void
name|EmitSymbolDesc
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|unsigned DescValue
argument_list|)
name|override
block|;
name|void
name|BeginCOFFSymbolDef
argument_list|(
argument|MCSymbol const *Symbol
argument_list|)
name|override
block|;
name|void
name|EmitCOFFSymbolStorageClass
argument_list|(
argument|int StorageClass
argument_list|)
name|override
block|;
name|void
name|EmitCOFFSymbolType
argument_list|(
argument|int Type
argument_list|)
name|override
block|;
name|void
name|EndCOFFSymbolDef
argument_list|()
name|override
block|;
name|void
name|EmitCOFFSafeSEH
argument_list|(
argument|MCSymbol const *Symbol
argument_list|)
name|override
block|;
name|void
name|EmitCOFFSectionIndex
argument_list|(
argument|MCSymbol const *Symbol
argument_list|)
name|override
block|;
name|void
name|EmitCOFFSecRel32
argument_list|(
argument|MCSymbol const *Symbol
argument_list|,
argument|uint64_t Offset
argument_list|)
name|override
block|;
name|void
name|EmitCommonSymbol
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|)
name|override
block|;
name|void
name|EmitLocalCommonSymbol
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|)
name|override
block|;
name|void
name|EmitZerofill
argument_list|(
argument|MCSection *Section
argument_list|,
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|)
name|override
block|;
name|void
name|EmitTBSSSymbol
argument_list|(
argument|MCSection *Section
argument_list|,
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|)
name|override
block|;
name|void
name|EmitIdent
argument_list|(
argument|StringRef IdentString
argument_list|)
name|override
block|;
name|void
name|EmitWinEHHandlerData
argument_list|()
name|override
block|;
name|void
name|FinishImpl
argument_list|()
name|override
block|;
comment|/// \}
name|protected
operator|:
specifier|const
name|MCSymbol
operator|*
name|CurSymbol
block|;
name|void
name|EmitInstToData
argument_list|(
argument|const MCInst&Inst
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
name|override
block|;
name|private
operator|:
name|void
name|Error
argument_list|(
argument|const Twine&Msg
argument_list|)
specifier|const
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

begin_comment
comment|// LLVM_MC_MCWINCOFFSTREAMER_H
end_comment

end_unit


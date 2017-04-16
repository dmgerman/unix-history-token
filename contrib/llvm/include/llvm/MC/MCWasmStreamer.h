begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCWasmStreamer.h - MCStreamer Wasm Object File Interface -*- C++ -*-===//
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
name|LLVM_MC_MCWASMSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCWASMSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

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

begin_include
include|#
directive|include
file|"llvm/MC/SectionKind.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmBackend
decl_stmt|;
name|class
name|MCAssembler
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MCWasmStreamer
range|:
name|public
name|MCObjectStreamer
block|{
name|public
operator|:
name|MCWasmStreamer
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
operator|:
name|MCObjectStreamer
argument_list|(
name|Context
argument_list|,
name|TAB
argument_list|,
name|OS
argument_list|,
name|Emitter
argument_list|)
block|,
name|SeenIdent
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|MCWasmStreamer
argument_list|()
name|override
block|;
comment|/// state management
name|void
name|reset
argument_list|()
name|override
block|{
name|SeenIdent
operator|=
name|false
block|;
name|MCObjectStreamer
operator|::
name|reset
argument_list|()
block|;   }
comment|/// \name MCStreamer Interface
comment|/// @{
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
name|void
name|EmitWeakReference
argument_list|(
argument|MCSymbol *Alias
argument_list|,
argument|const MCSymbol *Symbol
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
name|emitELFSize
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|const MCExpr *Value
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
argument|MCSymbol *Symbol = nullptr
argument_list|,
argument|uint64_t Size =
literal|0
argument_list|,
argument|unsigned ByteAlignment =
literal|0
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
argument|unsigned ByteAlignment =
literal|0
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
argument|SMLoc Loc = SMLoc()
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
name|EmitValueToAlignment
argument_list|(
argument|unsigned
argument_list|,
argument|int64_t
argument_list|,
argument|unsigned
argument_list|,
argument|unsigned
argument_list|)
name|override
block|;
name|void
name|FinishImpl
argument_list|()
name|override
block|;
name|private
operator|:
name|void
name|EmitInstToFragment
argument_list|(
argument|const MCInst&Inst
argument_list|,
argument|const MCSubtargetInfo&
argument_list|)
name|override
block|;
name|void
name|EmitInstToData
argument_list|(
argument|const MCInst&Inst
argument_list|,
argument|const MCSubtargetInfo&
argument_list|)
name|override
block|;
comment|/// \brief Merge the content of the fragment \p EF into the fragment \p DF.
name|void
name|mergeFragment
argument_list|(
name|MCDataFragment
operator|*
argument_list|,
name|MCDataFragment
operator|*
argument_list|)
block|;
name|bool
name|SeenIdent
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


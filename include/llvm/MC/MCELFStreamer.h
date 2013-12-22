begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCELFStreamer.h - MCStreamer ELF Object File Interface ---*- C++ -*-===//
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
name|LLVM_MC_MCELFSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCELFSTREAMER_H
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

begin_include
include|#
directive|include
file|<vector>
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
name|MCSymbol
decl_stmt|;
name|class
name|MCSymbolData
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MCELFStreamer
range|:
name|public
name|MCObjectStreamer
block|{
name|public
operator|:
name|MCELFStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|,
name|MCTargetStreamer
operator|*
name|TargetStreamer
argument_list|,
name|MCAsmBackend
operator|&
name|TAB
argument_list|,
name|raw_ostream
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
name|TargetStreamer
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
name|MCELFStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|,
name|MCTargetStreamer
operator|*
name|TargetStreamer
argument_list|,
name|MCAsmBackend
operator|&
name|TAB
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|,
name|MCCodeEmitter
operator|*
name|Emitter
argument_list|,
name|MCAssembler
operator|*
name|Assembler
argument_list|)
operator|:
name|MCObjectStreamer
argument_list|(
name|Context
argument_list|,
name|TargetStreamer
argument_list|,
name|TAB
argument_list|,
name|OS
argument_list|,
name|Emitter
argument_list|,
name|Assembler
argument_list|)
block|,
name|SeenIdent
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
operator|~
name|MCELFStreamer
argument_list|()
block|;
comment|/// @name MCStreamer Interface
comment|/// @{
name|virtual
name|void
name|InitSections
argument_list|()
block|;
name|virtual
name|void
name|InitToTextSection
argument_list|()
block|;
name|virtual
name|void
name|ChangeSection
argument_list|(
specifier|const
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
name|EmitDebugLabel
argument_list|(
name|MCSymbol
operator|*
name|Symbol
argument_list|)
block|;
name|virtual
name|void
name|EmitAssemblerFlag
argument_list|(
argument|MCAssemblerFlag Flag
argument_list|)
block|;
name|virtual
name|void
name|EmitThumbFunc
argument_list|(
name|MCSymbol
operator|*
name|Func
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
name|bool
name|EmitSymbolAttribute
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|MCSymbolAttr Attribute
argument_list|)
block|;
name|virtual
name|void
name|EmitSymbolDesc
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|unsigned DescValue
argument_list|)
block|;
name|virtual
name|void
name|EmitCommonSymbol
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|)
block|;
name|virtual
name|void
name|BeginCOFFSymbolDef
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Symbol
argument_list|)
block|;
name|virtual
name|void
name|EmitCOFFSymbolStorageClass
argument_list|(
argument|int StorageClass
argument_list|)
block|;
name|virtual
name|void
name|EmitCOFFSymbolType
argument_list|(
argument|int Type
argument_list|)
block|;
name|virtual
name|void
name|EndCOFFSymbolDef
argument_list|()
block|;
name|virtual
name|MCSymbolData
operator|&
name|getOrCreateSymbolData
argument_list|(
name|MCSymbol
operator|*
name|Symbol
argument_list|)
block|;
name|virtual
name|void
name|EmitELFSize
argument_list|(
name|MCSymbol
operator|*
name|Symbol
argument_list|,
specifier|const
name|MCExpr
operator|*
name|Value
argument_list|)
block|;
name|virtual
name|void
name|EmitLocalCommonSymbol
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|)
block|;
name|virtual
name|void
name|EmitZerofill
argument_list|(
argument|const MCSection *Section
argument_list|,
argument|MCSymbol *Symbol =
literal|0
argument_list|,
argument|uint64_t Size =
literal|0
argument_list|,
argument|unsigned ByteAlignment =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|EmitTBSSSymbol
argument_list|(
argument|const MCSection *Section
argument_list|,
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|EmitValueImpl
argument_list|(
argument|const MCExpr *Value
argument_list|,
argument|unsigned Size
argument_list|)
block|;
name|virtual
name|void
name|EmitFileDirective
argument_list|(
argument|StringRef Filename
argument_list|)
block|;
name|virtual
name|void
name|EmitIdent
argument_list|(
argument|StringRef IdentString
argument_list|)
block|;
name|virtual
name|void
name|EmitValueToAlignment
argument_list|(
name|unsigned
argument_list|,
name|int64_t
argument_list|,
name|unsigned
argument_list|,
name|unsigned
argument_list|)
block|;
name|virtual
name|void
name|Flush
argument_list|()
block|;
name|virtual
name|void
name|FinishImpl
argument_list|()
block|;
name|private
operator|:
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
name|EmitInstToData
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|)
block|;
name|virtual
name|void
name|EmitBundleAlignMode
argument_list|(
argument|unsigned AlignPow2
argument_list|)
block|;
name|virtual
name|void
name|EmitBundleLock
argument_list|(
argument|bool AlignToEnd
argument_list|)
block|;
name|virtual
name|void
name|EmitBundleUnlock
argument_list|()
block|;
name|void
name|fixSymbolsInTLSFixups
argument_list|(
specifier|const
name|MCExpr
operator|*
name|expr
argument_list|)
block|;
name|bool
name|SeenIdent
block|;    struct
name|LocalCommon
block|{
name|MCSymbolData
operator|*
name|SD
block|;
name|uint64_t
name|Size
block|;
name|unsigned
name|ByteAlignment
block|;   }
block|;
name|std
operator|::
name|vector
operator|<
name|LocalCommon
operator|>
name|LocalCommons
block|;
name|SmallPtrSet
operator|<
name|MCSymbol
operator|*
block|,
literal|16
operator|>
name|BindingExplicitlySet
block|;
name|void
name|SetSection
argument_list|(
argument|StringRef Section
argument_list|,
argument|unsigned Type
argument_list|,
argument|unsigned Flags
argument_list|,
argument|SectionKind Kind
argument_list|)
block|;
name|void
name|SetSectionData
argument_list|()
block|;
name|void
name|SetSectionText
argument_list|()
block|;
name|void
name|SetSectionBss
argument_list|()
block|; }
decl_stmt|;
name|MCELFStreamer
modifier|*
name|createARMELFStreamer
parameter_list|(
name|MCContext
modifier|&
name|Context
parameter_list|,
name|MCAsmBackend
modifier|&
name|TAB
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|MCCodeEmitter
modifier|*
name|Emitter
parameter_list|,
name|bool
name|RelaxAll
parameter_list|,
name|bool
name|NoExecStack
parameter_list|,
name|bool
name|IsThumb
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

end_unit


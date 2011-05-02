begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/MC/MCELFStreamer.h - ELF Object Output -------------------------===//
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
comment|// This file assembles .s files and emits ELF .o object files.
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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAssembler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCObjectStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSectionELF.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|TargetAsmBackend
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
argument|Context
argument_list|,
argument|TAB
argument_list|,
argument|OS
argument_list|,
argument|Emitter
argument_list|)
block|{}
name|MCELFStreamer
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
argument|Context
argument_list|,
argument|TAB
argument_list|,
argument|OS
argument_list|,
argument|Emitter
argument_list|,
argument|Assembler
argument_list|)
block|{}
operator|~
name|MCELFStreamer
argument_list|()
block|{}
comment|/// @name MCStreamer Interface
comment|/// @{
name|virtual
name|void
name|InitSections
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
name|EmitAssignment
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
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
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
argument|const MCSymbol *Symbol
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
name|virtual
name|void
name|EmitCOFFSymbolStorageClass
argument_list|(
argument|int StorageClass
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
name|virtual
name|void
name|EmitCOFFSymbolType
argument_list|(
argument|int Type
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
name|virtual
name|void
name|EndCOFFSymbolDef
argument_list|()
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
name|virtual
name|void
name|EmitELFSize
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|const MCExpr *Value
argument_list|)
block|{
name|MCSymbolData
operator|&
name|SD
operator|=
name|getAssembler
argument_list|()
operator|.
name|getOrCreateSymbolData
argument_list|(
operator|*
name|Symbol
argument_list|)
block|;
name|SD
operator|.
name|setSize
argument_list|(
name|Value
argument_list|)
block|;   }
name|virtual
name|void
name|EmitLocalCommonSymbol
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
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
argument|unsigned Size =
literal|0
argument_list|,
argument|unsigned ByteAlignment =
literal|0
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
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
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
name|virtual
name|void
name|EmitBytes
argument_list|(
argument|StringRef Data
argument_list|,
argument|unsigned AddrSpace
argument_list|)
block|;
name|virtual
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
block|;
name|virtual
name|void
name|EmitCodeAlignment
argument_list|(
argument|unsigned ByteAlignment
argument_list|,
argument|unsigned MaxBytesToEmit =
literal|0
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
name|Finish
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
name|void
name|fixSymbolsInTLSFixups
argument_list|(
specifier|const
name|MCExpr
operator|*
name|expr
argument_list|)
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
comment|/// @}
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
block|{
name|SwitchSection
argument_list|(
name|getContext
argument_list|()
operator|.
name|getELFSection
argument_list|(
name|Section
argument_list|,
name|Type
argument_list|,
name|Flags
argument_list|,
name|Kind
argument_list|)
argument_list|)
block|;   }
name|void
name|SetSectionData
argument_list|()
block|{
name|SetSection
argument_list|(
literal|".data"
argument_list|,
name|ELF
operator|::
name|SHT_PROGBITS
argument_list|,
name|ELF
operator|::
name|SHF_WRITE
operator||
name|ELF
operator|::
name|SHF_ALLOC
argument_list|,
name|SectionKind
operator|::
name|getDataRel
argument_list|()
argument_list|)
block|;
name|EmitCodeAlignment
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|)
block|;   }
name|void
name|SetSectionText
argument_list|()
block|{
name|SetSection
argument_list|(
literal|".text"
argument_list|,
name|ELF
operator|::
name|SHT_PROGBITS
argument_list|,
name|ELF
operator|::
name|SHF_EXECINSTR
operator||
name|ELF
operator|::
name|SHF_ALLOC
argument_list|,
name|SectionKind
operator|::
name|getText
argument_list|()
argument_list|)
block|;
name|EmitCodeAlignment
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|)
block|;   }
name|void
name|SetSectionBss
argument_list|()
block|{
name|SetSection
argument_list|(
literal|".bss"
argument_list|,
name|ELF
operator|::
name|SHT_NOBITS
argument_list|,
name|ELF
operator|::
name|SHF_WRITE
operator||
name|ELF
operator|::
name|SHF_ALLOC
argument_list|,
name|SectionKind
operator|::
name|getBSS
argument_list|()
argument_list|)
block|;
name|EmitCodeAlignment
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|)
block|;   }
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//===- lib/MC/MCELFStreamer.h - ELF Object Output -------------------------===//
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
comment|// This file assembles .s files and emits ELF .o object files.
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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAssembler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCObjectStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSectionELF.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|TargetAsmBackend
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
argument|Context
argument_list|,
argument|TAB
argument_list|,
argument|OS
argument_list|,
argument|Emitter
argument_list|)
block|{}
operator|~
name|MCELFStreamer
argument_list|()
block|{}
comment|/// @name MCStreamer Interface
comment|/// @{
name|virtual
name|void
name|InitSections
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
name|EmitAssignment
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
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
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
argument|const MCSymbol *Symbol
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
name|virtual
name|void
name|EmitCOFFSymbolStorageClass
argument_list|(
argument|int StorageClass
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
name|virtual
name|void
name|EmitCOFFSymbolType
argument_list|(
argument|int Type
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
name|virtual
name|void
name|EndCOFFSymbolDef
argument_list|()
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
name|virtual
name|void
name|EmitELFSize
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|const MCExpr *Value
argument_list|)
block|{
name|MCSymbolData
operator|&
name|SD
operator|=
name|getAssembler
argument_list|()
operator|.
name|getOrCreateSymbolData
argument_list|(
operator|*
name|Symbol
argument_list|)
block|;
name|SD
operator|.
name|setSize
argument_list|(
name|Value
argument_list|)
block|;   }
name|virtual
name|void
name|EmitLocalCommonSymbol
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
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
argument|unsigned Size =
literal|0
argument_list|,
argument|unsigned ByteAlignment =
literal|0
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
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
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"ELF doesn't support this directive"
argument_list|)
block|;   }
name|virtual
name|void
name|EmitBytes
argument_list|(
argument|StringRef Data
argument_list|,
argument|unsigned AddrSpace
argument_list|)
block|;
name|virtual
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
block|;
name|virtual
name|void
name|EmitCodeAlignment
argument_list|(
argument|unsigned ByteAlignment
argument_list|,
argument|unsigned MaxBytesToEmit =
literal|0
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
name|Finish
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
name|void
name|fixSymbolsInTLSFixups
argument_list|(
specifier|const
name|MCExpr
operator|*
name|expr
argument_list|)
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
comment|/// @}
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
block|{
name|SwitchSection
argument_list|(
name|getContext
argument_list|()
operator|.
name|getELFSection
argument_list|(
name|Section
argument_list|,
name|Type
argument_list|,
name|Flags
argument_list|,
name|Kind
argument_list|)
argument_list|)
block|;   }
name|void
name|SetSectionData
argument_list|()
block|{
name|SetSection
argument_list|(
literal|".data"
argument_list|,
name|ELF
operator|::
name|SHT_PROGBITS
argument_list|,
name|ELF
operator|::
name|SHF_WRITE
operator||
name|ELF
operator|::
name|SHF_ALLOC
argument_list|,
name|SectionKind
operator|::
name|getDataRel
argument_list|()
argument_list|)
block|;
name|EmitCodeAlignment
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|)
block|;   }
name|void
name|SetSectionText
argument_list|()
block|{
name|SetSection
argument_list|(
literal|".text"
argument_list|,
name|ELF
operator|::
name|SHT_PROGBITS
argument_list|,
name|ELF
operator|::
name|SHF_EXECINSTR
operator||
name|ELF
operator|::
name|SHF_ALLOC
argument_list|,
name|SectionKind
operator|::
name|getText
argument_list|()
argument_list|)
block|;
name|EmitCodeAlignment
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|)
block|;   }
name|void
name|SetSectionBss
argument_list|()
block|{
name|SetSection
argument_list|(
literal|".bss"
argument_list|,
name|ELF
operator|::
name|SHT_NOBITS
argument_list|,
name|ELF
operator|::
name|SHF_WRITE
operator||
name|ELF
operator|::
name|SHF_ALLOC
argument_list|,
name|SectionKind
operator|::
name|getBSS
argument_list|()
argument_list|)
block|;
name|EmitCodeAlignment
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|)
block|;   }
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


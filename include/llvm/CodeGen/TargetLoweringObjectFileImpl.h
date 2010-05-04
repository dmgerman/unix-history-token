begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/CodeGen/TargetLoweringObjectFileImpl.h - Object Info -*- C++ -*-==//
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
comment|// This file implements classes used to handle lowerings specific to common
end_comment

begin_comment
comment|// object file formats.
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
name|LLVM_CODEGEN_TARGETLOWERINGOBJECTFILEIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_TARGETLOWERINGOBJECTFILEIMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/SectionKind.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLoweringObjectFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSectionMachO
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetLoweringObjectFileELF
range|:
name|public
name|TargetLoweringObjectFile
block|{
name|protected
operator|:
comment|/// TLSDataSection - Section directive for Thread Local data.
comment|///
specifier|const
name|MCSection
operator|*
name|TLSDataSection
block|;
comment|// Defaults to ".tdata".
comment|/// TLSBSSSection - Section directive for Thread Local uninitialized data.
comment|/// Null if this target doesn't support a BSS section.
comment|///
specifier|const
name|MCSection
operator|*
name|TLSBSSSection
block|;
comment|// Defaults to ".tbss".
specifier|const
name|MCSection
operator|*
name|DataRelSection
block|;
specifier|const
name|MCSection
operator|*
name|DataRelLocalSection
block|;
specifier|const
name|MCSection
operator|*
name|DataRelROSection
block|;
specifier|const
name|MCSection
operator|*
name|DataRelROLocalSection
block|;
specifier|const
name|MCSection
operator|*
name|MergeableConst4Section
block|;
specifier|const
name|MCSection
operator|*
name|MergeableConst8Section
block|;
specifier|const
name|MCSection
operator|*
name|MergeableConst16Section
block|;
name|public
operator|:
name|TargetLoweringObjectFileELF
argument_list|()
block|{}
operator|~
name|TargetLoweringObjectFileELF
argument_list|()
block|{}
name|virtual
name|void
name|Initialize
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
specifier|const
name|MCSection
operator|*
name|getDataRelSection
argument_list|()
specifier|const
block|{
return|return
name|DataRelSection
return|;
block|}
comment|/// getSectionForConstant - Given a constant with the SectionKind, return a
comment|/// section that it should be placed in.
name|virtual
specifier|const
name|MCSection
operator|*
name|getSectionForConstant
argument_list|(
argument|SectionKind Kind
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|MCSection
operator|*
name|getExplicitSectionGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|MCSection
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
comment|/// getExprForDwarfGlobalReference - Return an MCExpr to use for a reference
comment|/// to the specified global variable from exception handling information.
comment|///
name|virtual
specifier|const
name|MCExpr
operator|*
name|getExprForDwarfGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|,
argument|unsigned Encoding
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
block|; }
decl_stmt|;
name|class
name|TargetLoweringObjectFileMachO
range|:
name|public
name|TargetLoweringObjectFile
block|{
specifier|const
name|MCSection
operator|*
name|CStringSection
block|;
specifier|const
name|MCSection
operator|*
name|UStringSection
block|;
specifier|const
name|MCSection
operator|*
name|TextCoalSection
block|;
specifier|const
name|MCSection
operator|*
name|ConstTextCoalSection
block|;
specifier|const
name|MCSection
operator|*
name|ConstDataCoalSection
block|;
specifier|const
name|MCSection
operator|*
name|ConstDataSection
block|;
specifier|const
name|MCSection
operator|*
name|DataCoalSection
block|;
specifier|const
name|MCSection
operator|*
name|DataCommonSection
block|;
specifier|const
name|MCSection
operator|*
name|DataBSSSection
block|;
specifier|const
name|MCSection
operator|*
name|FourByteConstantSection
block|;
specifier|const
name|MCSection
operator|*
name|EightByteConstantSection
block|;
specifier|const
name|MCSection
operator|*
name|SixteenByteConstantSection
block|;
specifier|const
name|MCSection
operator|*
name|LazySymbolPointerSection
block|;
specifier|const
name|MCSection
operator|*
name|NonLazySymbolPointerSection
block|;
name|public
operator|:
name|TargetLoweringObjectFileMachO
argument_list|()
block|{}
operator|~
name|TargetLoweringObjectFileMachO
argument_list|()
block|{}
name|virtual
name|void
name|Initialize
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
specifier|const
name|MCSection
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|MCSection
operator|*
name|getExplicitSectionGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|MCSection
operator|*
name|getSectionForConstant
argument_list|(
argument|SectionKind Kind
argument_list|)
specifier|const
block|;
comment|/// shouldEmitUsedDirectiveFor - This hook allows targets to selectively
comment|/// decide not to emit the UsedDirective for some symbols in llvm.used.
comment|/// FIXME: REMOVE this (rdar://7071300)
name|virtual
name|bool
name|shouldEmitUsedDirectiveFor
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *
argument_list|)
specifier|const
block|;
comment|/// getTextCoalSection - Return the "__TEXT,__textcoal_nt" section we put weak
comment|/// text symbols into.
specifier|const
name|MCSection
operator|*
name|getTextCoalSection
argument_list|()
specifier|const
block|{
return|return
name|TextCoalSection
return|;
block|}
comment|/// getConstTextCoalSection - Return the "__TEXT,__const_coal" section
comment|/// we put weak read-only symbols into.
specifier|const
name|MCSection
operator|*
name|getConstTextCoalSection
argument_list|()
specifier|const
block|{
return|return
name|ConstTextCoalSection
return|;
block|}
comment|/// getLazySymbolPointerSection - Return the section corresponding to
comment|/// the .lazy_symbol_pointer directive.
specifier|const
name|MCSection
operator|*
name|getLazySymbolPointerSection
argument_list|()
specifier|const
block|{
return|return
name|LazySymbolPointerSection
return|;
block|}
comment|/// getNonLazySymbolPointerSection - Return the section corresponding to
comment|/// the .non_lazy_symbol_pointer directive.
specifier|const
name|MCSection
operator|*
name|getNonLazySymbolPointerSection
argument_list|()
specifier|const
block|{
return|return
name|NonLazySymbolPointerSection
return|;
block|}
comment|/// getExprForDwarfGlobalReference - The mach-o version of this method
comment|/// defaults to returning a stub reference.
name|virtual
specifier|const
name|MCExpr
operator|*
name|getExprForDwarfGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|,
argument|unsigned Encoding
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getPersonalityEncoding
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getLSDAEncoding
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getFDEEncoding
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getTTypeEncoding
argument_list|()
specifier|const
block|; }
decl_stmt|;
name|class
name|TargetLoweringObjectFileCOFF
range|:
name|public
name|TargetLoweringObjectFile
block|{
name|mutable
name|void
operator|*
name|UniquingMap
block|;
name|public
operator|:
name|TargetLoweringObjectFileCOFF
argument_list|()
operator|:
name|UniquingMap
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|TargetLoweringObjectFileCOFF
argument_list|()
block|;
name|virtual
name|void
name|Initialize
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
specifier|const
name|MCSection
operator|*
name|getExplicitSectionGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|MCSection
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
comment|/// getCOFFSection - Return the MCSection for the specified COFF section.
comment|/// FIXME: Switch this to a semantic view eventually.
specifier|const
name|MCSection
operator|*
name|getCOFFSection
argument_list|(
argument|StringRef Name
argument_list|,
argument|bool isDirective
argument_list|,
argument|SectionKind K
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

end_unit


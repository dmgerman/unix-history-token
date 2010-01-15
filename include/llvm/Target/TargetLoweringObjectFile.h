begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetLoweringObjectFile.h - Object Info ----*- C++ -*-===//
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
name|LLVM_TARGET_TARGETLOWERINGOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETLOWERINGOBJECTFILE_H
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
name|MCContext
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetLoweringObjectFile
block|{
name|MCContext
modifier|*
name|Ctx
decl_stmt|;
name|TargetLoweringObjectFile
argument_list|(
specifier|const
name|TargetLoweringObjectFile
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetLoweringObjectFile
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
name|TargetLoweringObjectFile
argument_list|()
expr_stmt|;
comment|/// TextSection - Section directive for standard text.
comment|///
specifier|const
name|MCSection
modifier|*
name|TextSection
decl_stmt|;
comment|/// DataSection - Section directive for standard data.
comment|///
specifier|const
name|MCSection
modifier|*
name|DataSection
decl_stmt|;
comment|/// BSSSection - Section that is default initialized to zero.
specifier|const
name|MCSection
modifier|*
name|BSSSection
decl_stmt|;
comment|/// ReadOnlySection - Section that is readonly and can contain arbitrary
comment|/// initialized data.  Targets are not required to have a readonly section.
comment|/// If they don't, various bits of code will fall back to using the data
comment|/// section for constants.
specifier|const
name|MCSection
modifier|*
name|ReadOnlySection
decl_stmt|;
comment|/// StaticCtorSection - This section contains the static constructor pointer
comment|/// list.
specifier|const
name|MCSection
modifier|*
name|StaticCtorSection
decl_stmt|;
comment|/// StaticDtorSection - This section contains the static destructor pointer
comment|/// list.
specifier|const
name|MCSection
modifier|*
name|StaticDtorSection
decl_stmt|;
comment|/// LSDASection - If exception handling is supported by the target, this is
comment|/// the section the Language Specific Data Area information is emitted to.
specifier|const
name|MCSection
modifier|*
name|LSDASection
decl_stmt|;
comment|/// EHFrameSection - If exception handling is supported by the target, this is
comment|/// the section the EH Frame is emitted to.
specifier|const
name|MCSection
modifier|*
name|EHFrameSection
decl_stmt|;
comment|// Dwarf sections for debug info.  If a target supports debug info, these must
comment|// be set.
specifier|const
name|MCSection
modifier|*
name|DwarfAbbrevSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfInfoSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfLineSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfFrameSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfPubNamesSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfPubTypesSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfDebugInlineSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfStrSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfLocSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfARangesSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfRangesSection
decl_stmt|;
specifier|const
name|MCSection
modifier|*
name|DwarfMacroInfoSection
decl_stmt|;
name|public
label|:
name|MCContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Ctx
return|;
block|}
name|virtual
operator|~
name|TargetLoweringObjectFile
argument_list|()
expr_stmt|;
comment|/// Initialize - this method must be called before any actual lowering is
comment|/// done.  This specifies the current context for codegen, and gives the
comment|/// lowering implementations a chance to set up their default sections.
name|virtual
name|void
name|Initialize
parameter_list|(
name|MCContext
modifier|&
name|ctx
parameter_list|,
specifier|const
name|TargetMachine
modifier|&
name|TM
parameter_list|)
block|{
name|Ctx
operator|=
operator|&
name|ctx
expr_stmt|;
block|}
specifier|const
name|MCSection
operator|*
name|getTextSection
argument_list|()
specifier|const
block|{
return|return
name|TextSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDataSection
argument_list|()
specifier|const
block|{
return|return
name|DataSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getBSSSection
argument_list|()
specifier|const
block|{
return|return
name|BSSSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getStaticCtorSection
argument_list|()
specifier|const
block|{
return|return
name|StaticCtorSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getStaticDtorSection
argument_list|()
specifier|const
block|{
return|return
name|StaticDtorSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getLSDASection
argument_list|()
specifier|const
block|{
return|return
name|LSDASection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getEHFrameSection
argument_list|()
specifier|const
block|{
return|return
name|EHFrameSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfAbbrevSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfAbbrevSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfInfoSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfInfoSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfLineSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfLineSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfFrameSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfFrameSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfPubNamesSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfPubNamesSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfPubTypesSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfPubTypesSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfDebugInlineSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfDebugInlineSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfStrSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfStrSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfLocSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfLocSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfARangesSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfARangesSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfRangesSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfRangesSection
return|;
block|}
specifier|const
name|MCSection
operator|*
name|getDwarfMacroInfoSection
argument_list|()
specifier|const
block|{
return|return
name|DwarfMacroInfoSection
return|;
block|}
comment|/// shouldEmitUsedDirectiveFor - This hook allows targets to selectively
comment|/// decide not to emit the UsedDirective for some symbols in llvm.used.
comment|/// FIXME: REMOVE this (rdar://7071300)
name|virtual
name|bool
name|shouldEmitUsedDirectiveFor
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|Mangler
operator|*
argument_list|)
decl|const
block|{
return|return
name|GV
operator|!=
literal|0
return|;
block|}
comment|/// getSectionForConstant - Given a constant with the SectionKind, return a
comment|/// section that it should be placed in.
name|virtual
specifier|const
name|MCSection
modifier|*
name|getSectionForConstant
argument_list|(
name|SectionKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
comment|/// getKindForGlobal - Classify the specified global variable into a set of
comment|/// target independent categories embodied in SectionKind.
specifier|static
name|SectionKind
name|getKindForGlobal
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|,
specifier|const
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
comment|/// SectionForGlobal - This method computes the appropriate section to emit
comment|/// the specified global variable or function definition.  This should not
comment|/// be passed external (or available externally) globals.
specifier|const
name|MCSection
modifier|*
name|SectionForGlobal
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|SectionKind
name|Kind
argument_list|,
name|Mangler
operator|*
name|Mang
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
decl|const
decl_stmt|;
comment|/// SectionForGlobal - This method computes the appropriate section to emit
comment|/// the specified global variable or function definition.  This should not
comment|/// be passed external (or available externally) globals.
specifier|const
name|MCSection
modifier|*
name|SectionForGlobal
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|Mangler
operator|*
name|Mang
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
decl|const
block|{
return|return
name|SectionForGlobal
argument_list|(
name|GV
argument_list|,
name|getKindForGlobal
argument_list|(
name|GV
argument_list|,
name|TM
argument_list|)
argument_list|,
name|Mang
argument_list|,
name|TM
argument_list|)
return|;
block|}
comment|/// getExplicitSectionGlobal - Targets should implement this method to assign
comment|/// a section to globals with an explicit section specfied.  The
comment|/// implementation of this method can assume that GV->hasSection() is true.
name|virtual
specifier|const
name|MCSection
modifier|*
name|getExplicitSectionGlobal
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|SectionKind
name|Kind
argument_list|,
name|Mangler
operator|*
name|Mang
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// getSpecialCasedSectionGlobals - Allow the target to completely override
comment|/// section assignment of a global.
name|virtual
specifier|const
name|MCSection
modifier|*
name|getSpecialCasedSectionGlobals
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|Mangler
operator|*
name|Mang
argument_list|,
name|SectionKind
name|Kind
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
comment|/// getSymbolForDwarfGlobalReference - Return an MCExpr to use for a
comment|/// pc-relative reference to the specified global variable from exception
comment|/// handling information.  In addition to the symbol, this returns
comment|/// by-reference:
comment|///
comment|/// IsIndirect - True if the returned symbol is actually a stub that contains
comment|///    the address of the symbol, false if the symbol is the global itself.
comment|///
comment|/// IsPCRel - True if the symbol reference is already pc-relative, false if
comment|///    the caller needs to subtract off the address of the reference from the
comment|///    symbol.
comment|///
name|virtual
specifier|const
name|MCExpr
modifier|*
name|getSymbolForDwarfGlobalReference
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|Mangler
operator|*
name|Mang
argument_list|,
name|MachineModuleInfo
operator|*
name|MMI
argument_list|,
name|bool
operator|&
name|IsIndirect
argument_list|,
name|bool
operator|&
name|IsPCRel
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|virtual
specifier|const
name|MCSection
modifier|*
name|SelectSectionForGlobal
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|SectionKind
name|Kind
argument_list|,
name|Mangler
operator|*
name|Mang
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
name|class
name|TargetLoweringObjectFileELF
range|:
name|public
name|TargetLoweringObjectFile
block|{
name|mutable
name|void
operator|*
name|UniquingMap
block|;
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
name|protected
operator|:
specifier|const
name|MCSection
operator|*
name|getELFSection
argument_list|(
argument|StringRef Section
argument_list|,
argument|unsigned Type
argument_list|,
argument|unsigned Flags
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|bool IsExplicit = false
argument_list|)
specifier|const
block|;
name|public
operator|:
name|TargetLoweringObjectFileELF
argument_list|()
operator|:
name|UniquingMap
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|TargetLoweringObjectFileELF
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
block|; }
decl_stmt|;
name|class
name|TargetLoweringObjectFileMachO
range|:
name|public
name|TargetLoweringObjectFile
block|{
name|mutable
name|void
operator|*
name|UniquingMap
block|;
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
operator|:
name|UniquingMap
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|TargetLoweringObjectFileMachO
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
comment|/// getMachOSection - Return the MCSection for the specified mach-o section.
comment|/// This requires the operands to be valid.
specifier|const
name|MCSectionMachO
operator|*
name|getMachOSection
argument_list|(
argument|StringRef Segment
argument_list|,
argument|StringRef Section
argument_list|,
argument|unsigned TypeAndAttributes
argument_list|,
argument|SectionKind K
argument_list|)
specifier|const
block|{
return|return
name|getMachOSection
argument_list|(
name|Segment
argument_list|,
name|Section
argument_list|,
name|TypeAndAttributes
argument_list|,
literal|0
argument_list|,
name|K
argument_list|)
return|;
block|}
specifier|const
name|MCSectionMachO
operator|*
name|getMachOSection
argument_list|(
argument|StringRef Segment
argument_list|,
argument|StringRef Section
argument_list|,
argument|unsigned TypeAndAttributes
argument_list|,
argument|unsigned Reserved2
argument_list|,
argument|SectionKind K
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
comment|/// getSymbolForDwarfGlobalReference - The mach-o version of this method
comment|/// defaults to returning a stub reference.
name|virtual
specifier|const
name|MCExpr
operator|*
name|getSymbolForDwarfGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|,
argument|bool&IsIndirect
argument_list|,
argument|bool&IsPCRel
argument_list|)
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


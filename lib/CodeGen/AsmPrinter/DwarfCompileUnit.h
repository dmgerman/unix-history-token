begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DwarfCompileUnit.h - Dwarf Compile Unit ---*- C++ -*--===//
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
comment|// This file contains support for writing dwarf compile unit.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFCOMPILEUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFCOMPILEUNIT_H
end_define

begin_include
include|#
directive|include
file|"DwarfUnit.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Dwarf.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|DIE
decl_stmt|;
name|class
name|DwarfDebug
decl_stmt|;
name|class
name|DwarfFile
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|LexicalScope
decl_stmt|;
name|class
name|DwarfCompileUnit
range|:
name|public
name|DwarfUnit
block|{
comment|/// The attribute index of DW_AT_stmt_list in the compile unit DIE, avoiding
comment|/// the need to search for it in applyStmtList.
name|unsigned
name|stmtListIndex
block|;
comment|/// Skeleton unit associated with this unit.
name|DwarfCompileUnit
operator|*
name|Skeleton
block|;
comment|/// A label at the start of the non-dwo section related to this unit.
name|MCSymbol
operator|*
name|SectionSym
block|;
comment|/// The start of the unit within its section.
name|MCSymbol
operator|*
name|LabelBegin
block|;
comment|/// GlobalNames - A map of globally visible named entities for this unit.
name|StringMap
operator|<
specifier|const
name|DIE
operator|*
operator|>
name|GlobalNames
block|;
comment|/// GlobalTypes - A map of globally visible types for this unit.
name|StringMap
operator|<
specifier|const
name|DIE
operator|*
operator|>
name|GlobalTypes
block|;
comment|// List of range lists for a given compile unit, separate from the ranges for
comment|// the CU itself.
name|SmallVector
operator|<
name|RangeSpanList
block|,
literal|1
operator|>
name|CURangeLists
block|;
comment|// List of ranges for a given compile unit.
name|SmallVector
operator|<
name|RangeSpan
block|,
literal|2
operator|>
name|CURanges
block|;
comment|// The base address of this unit, if any. Used for relative references in
comment|// ranges/locs.
specifier|const
name|MCSymbol
operator|*
name|BaseAddress
block|;
comment|/// \brief Construct a DIE for the given DbgVariable without initializing the
comment|/// DbgVariable's DIE reference.
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>
name|constructVariableDIEImpl
argument_list|(
argument|const DbgVariable&DV
argument_list|,
argument|bool Abstract
argument_list|)
block|;
name|bool
name|isDwoUnit
argument_list|()
specifier|const
name|override
block|;
name|bool
name|includeMinimalInlineScopes
argument_list|()
specifier|const
block|;
name|public
operator|:
name|DwarfCompileUnit
argument_list|(
argument|unsigned UID
argument_list|,
argument|DICompileUnit Node
argument_list|,
argument|AsmPrinter *A
argument_list|,
argument|DwarfDebug *DW
argument_list|,
argument|DwarfFile *DWU
argument_list|)
block|;
name|DwarfCompileUnit
operator|*
name|getSkeleton
argument_list|()
specifier|const
block|{
return|return
name|Skeleton
return|;
block|}
name|void
name|initStmtList
argument_list|(
name|MCSymbol
operator|*
name|DwarfLineSectionSym
argument_list|)
block|;
comment|/// Apply the DW_AT_stmt_list from this compile unit to the specified DIE.
name|void
name|applyStmtList
argument_list|(
name|DIE
operator|&
name|D
argument_list|)
block|;
comment|/// getOrCreateGlobalVariableDIE - get or create global variable DIE.
name|DIE
operator|*
name|getOrCreateGlobalVariableDIE
argument_list|(
argument|DIGlobalVariable GV
argument_list|)
block|;
comment|/// addLabelAddress - Add a dwarf label attribute data and value using
comment|/// either DW_FORM_addr or DW_FORM_GNU_addr_index.
name|void
name|addLabelAddress
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|const MCSymbol *Label
argument_list|)
block|;
comment|/// addLocalLabelAddress - Add a dwarf label attribute data and value using
comment|/// DW_FORM_addr only.
name|void
name|addLocalLabelAddress
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|const MCSymbol *Label
argument_list|)
block|;
comment|/// addSectionDelta - Add a label delta attribute data and value.
name|void
name|addSectionDelta
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|const MCSymbol *Hi
argument_list|,
argument|const MCSymbol *Lo
argument_list|)
block|;
name|DwarfCompileUnit
operator|&
name|getCU
argument_list|()
name|override
block|{
return|return
operator|*
name|this
return|;
block|}
name|unsigned
name|getOrCreateSourceID
argument_list|(
argument|StringRef FileName
argument_list|,
argument|StringRef DirName
argument_list|)
name|override
block|;
comment|/// addRange - Add an address range to the list of ranges for this unit.
name|void
name|addRange
argument_list|(
argument|RangeSpan Range
argument_list|)
block|;
name|void
name|attachLowHighPC
argument_list|(
name|DIE
operator|&
name|D
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Begin
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|End
argument_list|)
block|;
comment|/// addSectionLabel - Add a Dwarf section label attribute data and value.
comment|///
name|void
name|addSectionLabel
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|const MCSymbol *Label
argument_list|,
argument|const MCSymbol *Sec
argument_list|)
block|;
comment|/// \brief Find DIE for the given subprogram and attach appropriate
comment|/// DW_AT_low_pc and DW_AT_high_pc attributes. If there are global
comment|/// variables in this scope then create and insert DIEs for these
comment|/// variables.
name|DIE
operator|&
name|updateSubprogramScopeDIE
argument_list|(
argument|DISubprogram SP
argument_list|)
block|;
name|void
name|constructScopeDIE
argument_list|(
name|LexicalScope
operator|*
name|Scope
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>>
operator|&
name|FinalChildren
argument_list|)
block|;
comment|/// \brief A helper function to construct a RangeSpanList for a given
comment|/// lexical scope.
name|void
name|addScopeRangeList
argument_list|(
name|DIE
operator|&
name|ScopeDIE
argument_list|,
name|SmallVector
operator|<
name|RangeSpan
argument_list|,
literal|2
operator|>
name|Range
argument_list|)
block|;
name|void
name|attachRangesOrLowHighPC
argument_list|(
name|DIE
operator|&
name|D
argument_list|,
name|SmallVector
operator|<
name|RangeSpan
argument_list|,
literal|2
operator|>
name|Ranges
argument_list|)
block|;
name|void
name|attachRangesOrLowHighPC
argument_list|(
name|DIE
operator|&
name|D
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|InsnRange
operator|>
operator|&
name|Ranges
argument_list|)
block|;
comment|/// \brief This scope represents inlined body of a function. Construct
comment|/// DIE to represent this concrete inlined copy of the function.
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>
name|constructInlinedScopeDIE
argument_list|(
name|LexicalScope
operator|*
name|Scope
argument_list|)
block|;
comment|/// \brief Construct new DW_TAG_lexical_block for this scope and
comment|/// attach DW_AT_low_pc/DW_AT_high_pc labels.
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>
name|constructLexicalScopeDIE
argument_list|(
name|LexicalScope
operator|*
name|Scope
argument_list|)
block|;
comment|/// constructVariableDIE - Construct a DIE for the given DbgVariable.
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>
name|constructVariableDIE
argument_list|(
argument|DbgVariable&DV
argument_list|,
argument|bool Abstract = false
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>
name|constructVariableDIE
argument_list|(
name|DbgVariable
operator|&
name|DV
argument_list|,
specifier|const
name|LexicalScope
operator|&
name|Scope
argument_list|,
name|DIE
operator|*
operator|&
name|ObjectPointer
argument_list|)
block|;
comment|/// A helper function to create children of a Scope DIE.
name|DIE
operator|*
name|createScopeChildrenDIE
argument_list|(
name|LexicalScope
operator|*
name|Scope
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>>
operator|&
name|Children
argument_list|,
name|unsigned
operator|*
name|ChildScopeCount
operator|=
name|nullptr
argument_list|)
block|;
comment|/// \brief Construct a DIE for this subprogram scope.
name|void
name|constructSubprogramScopeDIE
argument_list|(
name|LexicalScope
operator|*
name|Scope
argument_list|)
block|;
name|DIE
operator|*
name|createAndAddScopeChildren
argument_list|(
name|LexicalScope
operator|*
name|Scope
argument_list|,
name|DIE
operator|&
name|ScopeDIE
argument_list|)
block|;
name|void
name|constructAbstractSubprogramScopeDIE
argument_list|(
name|LexicalScope
operator|*
name|Scope
argument_list|)
block|;
comment|/// \brief Construct import_module DIE.
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>
name|constructImportedEntityDIE
argument_list|(
specifier|const
name|DIImportedEntity
operator|&
name|Module
argument_list|)
block|;
name|void
name|finishSubprogramDefinition
argument_list|(
argument|DISubprogram SP
argument_list|)
block|;
name|void
name|collectDeadVariables
argument_list|(
argument|DISubprogram SP
argument_list|)
block|;
comment|/// Set the skeleton unit associated with this unit.
name|void
name|setSkeleton
argument_list|(
argument|DwarfCompileUnit&Skel
argument_list|)
block|{
name|Skeleton
operator|=
operator|&
name|Skel
block|; }
name|MCSymbol
operator|*
name|getSectionSym
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Section
argument_list|)
block|;
return|return
name|SectionSym
return|;
block|}
comment|/// Pass in the SectionSym even though we could recreate it in every compile
comment|/// unit (type units will have actually distinct symbols once they're in
comment|/// comdat sections).
name|void
name|initSection
argument_list|(
argument|const MCSection *Section
argument_list|,
argument|MCSymbol *SectionSym
argument_list|)
block|{
name|DwarfUnit
operator|::
name|initSection
argument_list|(
name|Section
argument_list|)
block|;
name|this
operator|->
name|SectionSym
operator|=
name|SectionSym
block|;
comment|// Don't bother labeling the .dwo unit, as its offset isn't used.
if|if
condition|(
operator|!
name|Skeleton
condition|)
name|LabelBegin
operator|=
name|Asm
operator|->
name|GetTempSymbol
argument_list|(
name|Section
operator|->
name|getLabelBeginName
argument_list|()
argument_list|,
name|getUniqueID
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|unsigned
name|getLength
argument_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|+
comment|// Length field
name|getHeaderSize
argument_list|()
operator|+
name|UnitDie
operator|.
name|getSize
argument_list|()
return|;
block|}
name|void
name|emitHeader
argument_list|(
argument|const MCSymbol *ASectionSym
argument_list|)
specifier|const
name|override
block|;
name|MCSymbol
operator|*
name|getLabelBegin
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Section
argument_list|)
block|;
return|return
name|LabelBegin
return|;
block|}
comment|/// Add a new global name to the compile unit.
name|void
name|addGlobalName
argument_list|(
argument|StringRef Name
argument_list|,
argument|DIE&Die
argument_list|,
argument|DIScope Context
argument_list|)
name|override
block|;
comment|/// Add a new global type to the compile unit.
name|void
name|addGlobalType
argument_list|(
argument|DIType Ty
argument_list|,
argument|const DIE&Die
argument_list|,
argument|DIScope Context
argument_list|)
name|override
block|;
specifier|const
name|StringMap
operator|<
specifier|const
name|DIE
operator|*
operator|>
operator|&
name|getGlobalNames
argument_list|()
specifier|const
block|{
return|return
name|GlobalNames
return|;
block|}
specifier|const
name|StringMap
operator|<
specifier|const
name|DIE
operator|*
operator|>
operator|&
name|getGlobalTypes
argument_list|()
specifier|const
block|{
return|return
name|GlobalTypes
return|;
block|}
comment|/// Add DW_AT_location attribute for a DbgVariable based on provided
comment|/// MachineLocation.
name|void
name|addVariableAddress
argument_list|(
argument|const DbgVariable&DV
argument_list|,
argument|DIE&Die
argument_list|,
argument|MachineLocation Location
argument_list|)
block|;
comment|/// Add an address attribute to a die based on the location provided.
name|void
name|addAddress
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|const MachineLocation&Location
argument_list|,
argument|bool Indirect = false
argument_list|)
block|;
comment|/// Start with the address based on the location provided, and generate the
comment|/// DWARF information necessary to find the actual variable (navigating the
comment|/// extra location information encoded in the type) based on the starting
comment|/// location.  Add the DWARF information to the die.
name|void
name|addComplexAddress
argument_list|(
argument|const DbgVariable&DV
argument_list|,
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|const MachineLocation&Location
argument_list|)
block|;
comment|/// Add a Dwarf loclistptr attribute data and value.
name|void
name|addLocationList
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|unsigned Index
argument_list|)
block|;
name|void
name|applyVariableAttributes
argument_list|(
specifier|const
name|DbgVariable
operator|&
name|Var
argument_list|,
name|DIE
operator|&
name|VariableDie
argument_list|)
block|;
comment|/// Add a Dwarf expression attribute data and value.
name|void
name|addExpr
argument_list|(
argument|DIELoc&Die
argument_list|,
argument|dwarf::Form Form
argument_list|,
argument|const MCExpr *Expr
argument_list|)
block|;
name|void
name|applySubprogramAttributesToDefinition
argument_list|(
argument|DISubprogram SP
argument_list|,
argument|DIE&SPDie
argument_list|)
block|;
comment|/// getRangeLists - Get the vector of range lists.
specifier|const
name|SmallVectorImpl
operator|<
name|RangeSpanList
operator|>
operator|&
name|getRangeLists
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Skeleton
operator|?
name|Skeleton
operator|:
name|this
operator|)
operator|->
name|CURangeLists
return|;
block|}
comment|/// getRanges - Get the list of ranges for this unit.
specifier|const
name|SmallVectorImpl
operator|<
name|RangeSpan
operator|>
operator|&
name|getRanges
argument_list|()
specifier|const
block|{
return|return
name|CURanges
return|;
block|}
name|SmallVector
operator|<
name|RangeSpan
block|,
literal|2
operator|>
name|takeRanges
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|CURanges
argument_list|)
return|;
block|}
name|void
name|setBaseAddress
argument_list|(
argument|const MCSymbol *Base
argument_list|)
block|{
name|BaseAddress
operator|=
name|Base
block|; }
specifier|const
name|MCSymbol
operator|*
name|getBaseAddress
argument_list|()
specifier|const
block|{
return|return
name|BaseAddress
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


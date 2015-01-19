begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DwarfUnit.h - Dwarf Compile Unit ---*- C++ -*--===//
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
name|CODEGEN_ASMPRINTER_DWARFCOMPILEUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_ASMPRINTER_DWARFCOMPILEUNIT_H
end_define

begin_include
include|#
directive|include
file|"DIE.h"
end_include

begin_include
include|#
directive|include
file|"DwarfDebug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DIBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDwarf.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineLocation
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|ConstantInt
decl_stmt|;
name|class
name|ConstantFP
decl_stmt|;
name|class
name|DbgVariable
decl_stmt|;
name|class
name|DwarfCompileUnit
decl_stmt|;
comment|// Data structure to hold a range for range lists.
name|class
name|RangeSpan
block|{
name|public
label|:
name|RangeSpan
argument_list|(
name|MCSymbol
operator|*
name|S
argument_list|,
name|MCSymbol
operator|*
name|E
argument_list|)
operator|:
name|Start
argument_list|(
name|S
argument_list|)
operator|,
name|End
argument_list|(
argument|E
argument_list|)
block|{}
specifier|const
name|MCSymbol
operator|*
name|getStart
argument_list|()
specifier|const
block|{
return|return
name|Start
return|;
block|}
specifier|const
name|MCSymbol
operator|*
name|getEnd
argument_list|()
specifier|const
block|{
return|return
name|End
return|;
block|}
name|void
name|setEnd
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|E
parameter_list|)
block|{
name|End
operator|=
name|E
expr_stmt|;
block|}
name|private
label|:
specifier|const
name|MCSymbol
modifier|*
name|Start
decl_stmt|,
modifier|*
name|End
decl_stmt|;
block|}
empty_stmt|;
name|class
name|RangeSpanList
block|{
name|private
label|:
comment|// Index for locating within the debug_range section this particular span.
name|MCSymbol
modifier|*
name|RangeSym
decl_stmt|;
comment|// List of ranges.
name|SmallVector
operator|<
name|RangeSpan
operator|,
literal|2
operator|>
name|Ranges
expr_stmt|;
name|public
label|:
name|RangeSpanList
argument_list|(
name|MCSymbol
operator|*
name|Sym
argument_list|)
operator|:
name|RangeSym
argument_list|(
argument|Sym
argument_list|)
block|{}
name|MCSymbol
operator|*
name|getSym
argument_list|()
specifier|const
block|{
return|return
name|RangeSym
return|;
block|}
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
name|Ranges
return|;
block|}
name|void
name|addRange
parameter_list|(
name|RangeSpan
name|Range
parameter_list|)
block|{
name|Ranges
operator|.
name|push_back
argument_list|(
name|Range
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// Unit - This dwarf writer support class manages information associated
comment|/// with a source file.
name|class
name|DwarfUnit
block|{
name|protected
label|:
comment|/// UniqueID - a numeric ID unique among all CUs in the module
name|unsigned
name|UniqueID
decl_stmt|;
comment|/// Node - MDNode for the compile unit.
name|DICompileUnit
name|CUNode
decl_stmt|;
comment|/// Unit debug information entry.
name|DIE
name|UnitDie
decl_stmt|;
comment|/// Offset of the UnitDie from beginning of debug info section.
name|unsigned
name|DebugInfoOffset
decl_stmt|;
comment|/// Asm - Target of Dwarf emission.
name|AsmPrinter
modifier|*
name|Asm
decl_stmt|;
comment|// Holders for some common dwarf information.
name|DwarfDebug
modifier|*
name|DD
decl_stmt|;
name|DwarfFile
modifier|*
name|DU
decl_stmt|;
comment|/// IndexTyDie - An anonymous type for index type.  Owned by UnitDie.
name|DIE
modifier|*
name|IndexTyDie
decl_stmt|;
comment|/// MDNodeToDieMap - Tracks the mapping of unit level debug information
comment|/// variables to debug information entries.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DIE
operator|*
operator|>
name|MDNodeToDieMap
expr_stmt|;
comment|/// MDNodeToDIEEntryMap - Tracks the mapping of unit level debug information
comment|/// descriptors to debug information entries using a DIEEntry proxy.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DIEEntry
operator|*
operator|>
name|MDNodeToDIEEntryMap
expr_stmt|;
comment|/// GlobalNames - A map of globally visible named entities for this unit.
name|StringMap
operator|<
specifier|const
name|DIE
operator|*
operator|>
name|GlobalNames
expr_stmt|;
comment|/// GlobalTypes - A map of globally visible types for this unit.
name|StringMap
operator|<
specifier|const
name|DIE
operator|*
operator|>
name|GlobalTypes
expr_stmt|;
comment|/// DIEBlocks - A list of all the DIEBlocks in use.
name|std
operator|::
name|vector
operator|<
name|DIEBlock
operator|*
operator|>
name|DIEBlocks
expr_stmt|;
comment|/// DIELocs - A list of all the DIELocs in use.
name|std
operator|::
name|vector
operator|<
name|DIELoc
operator|*
operator|>
name|DIELocs
expr_stmt|;
comment|/// ContainingTypeMap - This map is used to keep track of subprogram DIEs that
comment|/// need DW_AT_containing_type attribute. This attribute points to a DIE that
comment|/// corresponds to the MDNode mapped with the subprogram DIE.
name|DenseMap
operator|<
name|DIE
operator|*
operator|,
specifier|const
name|MDNode
operator|*
operator|>
name|ContainingTypeMap
expr_stmt|;
comment|// List of ranges for a given compile unit.
name|SmallVector
operator|<
name|RangeSpan
operator|,
literal|1
operator|>
name|CURanges
expr_stmt|;
comment|// List of range lists for a given compile unit, separate from the ranges for
comment|// the CU itself.
name|SmallVector
operator|<
name|RangeSpanList
operator|,
literal|1
operator|>
name|CURangeLists
expr_stmt|;
comment|// DIEValueAllocator - All DIEValues are allocated through this allocator.
name|BumpPtrAllocator
name|DIEValueAllocator
decl_stmt|;
comment|// DIEIntegerOne - A preallocated DIEValue because 1 is used frequently.
name|DIEInteger
modifier|*
name|DIEIntegerOne
decl_stmt|;
comment|/// The section this unit will be emitted in.
specifier|const
name|MCSection
modifier|*
name|Section
decl_stmt|;
comment|/// A label at the start of the non-dwo section related to this unit.
name|MCSymbol
modifier|*
name|SectionSym
decl_stmt|;
comment|/// The start of the unit within its section.
name|MCSymbol
modifier|*
name|LabelBegin
decl_stmt|;
comment|/// The end of the unit within its section.
name|MCSymbol
modifier|*
name|LabelEnd
decl_stmt|;
comment|/// Skeleton unit associated with this unit.
name|DwarfUnit
modifier|*
name|Skeleton
decl_stmt|;
name|DwarfUnit
argument_list|(
argument|unsigned UID
argument_list|,
argument|dwarf::Tag
argument_list|,
argument|DICompileUnit CU
argument_list|,
argument|AsmPrinter *A
argument_list|,
argument|DwarfDebug *DW
argument_list|,
argument|DwarfFile *DWU
argument_list|)
empty_stmt|;
name|public
label|:
name|virtual
operator|~
name|DwarfUnit
argument_list|()
expr_stmt|;
comment|/// Set the skeleton unit associated with this unit.
name|void
name|setSkeleton
parameter_list|(
name|DwarfUnit
modifier|&
name|Skel
parameter_list|)
block|{
name|Skeleton
operator|=
operator|&
name|Skel
expr_stmt|;
block|}
comment|/// Get the skeleton unit associated with this unit.
name|DwarfUnit
operator|*
name|getSkeleton
argument_list|()
specifier|const
block|{
return|return
name|Skeleton
return|;
block|}
comment|/// Pass in the SectionSym even though we could recreate it in every compile
comment|/// unit (type units will have actually distinct symbols once they're in
comment|/// comdat sections).
name|void
name|initSection
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|Section
parameter_list|,
name|MCSymbol
modifier|*
name|SectionSym
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|this
operator|->
name|Section
argument_list|)
expr_stmt|;
name|this
operator|->
name|Section
operator|=
name|Section
expr_stmt|;
name|this
operator|->
name|SectionSym
operator|=
name|SectionSym
expr_stmt|;
name|this
operator|->
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
name|this
operator|->
name|LabelEnd
operator|=
name|Asm
operator|->
name|GetTempSymbol
argument_list|(
name|Section
operator|->
name|getLabelEndName
argument_list|()
argument_list|,
name|getUniqueID
argument_list|()
argument_list|)
expr_stmt|;
block|}
specifier|const
name|MCSection
operator|*
name|getSection
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Section
argument_list|)
block|;
return|return
name|Section
return|;
block|}
comment|/// If there's a skeleton then return the section symbol for the skeleton
comment|/// unit, otherwise return the section symbol for this unit.
name|MCSymbol
operator|*
name|getLocalSectionSym
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Skeleton
condition|)
return|return
name|Skeleton
operator|->
name|getSectionSym
argument_list|()
return|;
return|return
name|getSectionSym
argument_list|()
return|;
block|}
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
comment|/// If there's a skeleton then return the begin label for the skeleton unit,
comment|/// otherwise return the local label for this unit.
name|MCSymbol
operator|*
name|getLocalLabelBegin
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Skeleton
condition|)
return|return
name|Skeleton
operator|->
name|getLabelBegin
argument_list|()
return|;
return|return
name|getLabelBegin
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|MCSymbol
operator|*
name|getLabelEnd
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Section
argument_list|)
block|;
return|return
name|LabelEnd
return|;
block|}
end_expr_stmt

begin_comment
comment|// Accessors.
end_comment

begin_expr_stmt
name|unsigned
name|getUniqueID
argument_list|()
specifier|const
block|{
return|return
name|UniqueID
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|uint16_t
name|getLanguage
argument_list|()
specifier|const
block|{
return|return
name|CUNode
operator|.
name|getLanguage
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|DICompileUnit
name|getCUNode
argument_list|()
specifier|const
block|{
return|return
name|CUNode
return|;
block|}
end_expr_stmt

begin_function
name|DIE
modifier|&
name|getUnitDie
parameter_list|()
block|{
return|return
name|UnitDie
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getDebugInfoOffset
argument_list|()
specifier|const
block|{
return|return
name|DebugInfoOffset
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDebugInfoOffset
parameter_list|(
name|unsigned
name|DbgInfoOff
parameter_list|)
block|{
name|DebugInfoOffset
operator|=
name|DbgInfoOff
expr_stmt|;
block|}
end_function

begin_comment
comment|/// hasContent - Return true if this compile unit has something to write out.
end_comment

begin_expr_stmt
name|bool
name|hasContent
argument_list|()
specifier|const
block|{
return|return
operator|!
name|UnitDie
operator|.
name|getChildren
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// addRange - Add an address range to the list of ranges for this unit.
end_comment

begin_function_decl
name|void
name|addRange
parameter_list|(
name|RangeSpan
name|Range
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getRanges - Get the list of ranges for this unit.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|SmallVectorImpl
operator|<
name|RangeSpan
operator|>
operator|&
name|getRanges
argument_list|()
block|{
return|return
name|CURanges
return|;
block|}
end_expr_stmt

begin_comment
comment|/// addRangeList - Add an address range list to the list of range lists.
end_comment

begin_function
name|void
name|addRangeList
parameter_list|(
name|RangeSpanList
name|Ranges
parameter_list|)
block|{
name|CURangeLists
operator|.
name|push_back
argument_list|(
name|Ranges
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getRangeLists - Get the vector of range lists.
end_comment

begin_expr_stmt
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
name|CURangeLists
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SmallVectorImpl
operator|<
name|RangeSpanList
operator|>
operator|&
name|getRangeLists
argument_list|()
block|{
return|return
name|CURangeLists
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getParentContextString - Get a string containing the language specific
end_comment

begin_comment
comment|/// context for a global name.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getParentContextString
argument_list|(
argument|DIScope Context
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// addGlobalName - Add a new global entity to the compile unit.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|addGlobalName
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|DIE
modifier|&
name|Die
parameter_list|,
name|DIScope
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addAccelNamespace - Add a new name to the namespace accelerator table.
end_comment

begin_function_decl
name|void
name|addAccelNamespace
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|DIE
modifier|&
name|Die
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getDIE - Returns the debug information entry map slot for the
end_comment

begin_comment
comment|/// specified debug variable. We delegate the request to DwarfDebug
end_comment

begin_comment
comment|/// when the MDNode can be part of the type system, since DIEs for
end_comment

begin_comment
comment|/// the type system can be shared across CUs and the mappings are
end_comment

begin_comment
comment|/// kept in DwarfDebug.
end_comment

begin_decl_stmt
name|DIE
modifier|*
name|getDIE
argument_list|(
name|DIDescriptor
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getDIELoc - Returns a fresh newly allocated DIELoc.
end_comment

begin_function
name|DIELoc
modifier|*
name|getDIELoc
parameter_list|()
block|{
return|return
name|new
argument_list|(
argument|DIEValueAllocator
argument_list|)
name|DIELoc
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// insertDIE - Insert DIE into the map. We delegate the request to DwarfDebug
end_comment

begin_comment
comment|/// when the MDNode can be part of the type system, since DIEs for
end_comment

begin_comment
comment|/// the type system can be shared across CUs and the mappings are
end_comment

begin_comment
comment|/// kept in DwarfDebug.
end_comment

begin_function_decl
name|void
name|insertDIE
parameter_list|(
name|DIDescriptor
name|Desc
parameter_list|,
name|DIE
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addFlag - Add a flag that is true to the DIE.
end_comment

begin_decl_stmt
name|void
name|addFlag
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addUInt - Add an unsigned integer attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addUInt
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|Optional
operator|<
name|dwarf
operator|::
name|Form
operator|>
name|Form
argument_list|,
name|uint64_t
name|Integer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addUInt
argument_list|(
name|DIE
operator|&
name|Block
argument_list|,
name|dwarf
operator|::
name|Form
name|Form
argument_list|,
name|uint64_t
name|Integer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addSInt - Add an signed integer attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addSInt
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|Optional
operator|<
name|dwarf
operator|::
name|Form
operator|>
name|Form
argument_list|,
name|int64_t
name|Integer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addSInt
argument_list|(
name|DIELoc
operator|&
name|Die
argument_list|,
name|Optional
operator|<
name|dwarf
operator|::
name|Form
operator|>
name|Form
argument_list|,
name|int64_t
name|Integer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addString - Add a string attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addString
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
specifier|const
name|StringRef
name|Str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addLocalString - Add a string attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addLocalString
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
specifier|const
name|StringRef
name|Str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addExpr - Add a Dwarf expression attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addExpr
argument_list|(
name|DIELoc
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Form
name|Form
argument_list|,
specifier|const
name|MCExpr
operator|*
name|Expr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addLabel - Add a Dwarf label attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addLabel
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|dwarf
operator|::
name|Form
name|Form
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Label
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addLabel
argument_list|(
name|DIELoc
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Form
name|Form
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Label
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addLocationList - Add a Dwarf loclistptr attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addLocationList
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|unsigned
name|Index
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addSectionLabel - Add a Dwarf section label attribute data and value.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|addSectionLabel
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Label
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addSectionOffset - Add an offset into a section attribute data and value.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|addSectionOffset
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|uint64_t
name|Integer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addOpAddress - Add a dwarf op address data and value using the
end_comment

begin_comment
comment|/// form given and an op of either DW_FORM_addr or DW_FORM_GNU_addr_index.
end_comment

begin_function_decl
name|void
name|addOpAddress
parameter_list|(
name|DIELoc
modifier|&
name|Die
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Label
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addSectionDelta - Add a label delta attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addSectionDelta
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Hi
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Lo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addLabelDelta - Add a label delta attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addLabelDelta
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Hi
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Lo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addDIEEntry - Add a DIE attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addDIEEntry
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|DIE
operator|&
name|Entry
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addDIEEntry - Add a DIE attribute data and value.
end_comment

begin_decl_stmt
name|void
name|addDIEEntry
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|DIEEntry
operator|*
name|Entry
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|addDIETypeSignature
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
specifier|const
name|DwarfTypeUnit
modifier|&
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addBlock - Add block data.
end_comment

begin_decl_stmt
name|void
name|addBlock
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|DIELoc
operator|*
name|Block
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addBlock - Add block data.
end_comment

begin_decl_stmt
name|void
name|addBlock
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|DIEBlock
operator|*
name|Block
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addSourceLine - Add location information to specified debug information
end_comment

begin_comment
comment|/// entry.
end_comment

begin_function_decl
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|StringRef
name|File
parameter_list|,
name|StringRef
name|Directory
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
name|DIVariable
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
name|DIGlobalVariable
name|G
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
name|DISubprogram
name|SP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
name|DIType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
name|DINameSpace
name|NS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
name|DIObjCProperty
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addAddress - Add an address attribute to a die based on the location
end_comment

begin_comment
comment|/// provided.
end_comment

begin_decl_stmt
name|void
name|addAddress
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
specifier|const
name|MachineLocation
operator|&
name|Location
argument_list|,
name|bool
name|Indirect
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addConstantValue - Add constant value entry in variable DIE.
end_comment

begin_function_decl
name|void
name|addConstantValue
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
specifier|const
name|MachineOperand
modifier|&
name|MO
parameter_list|,
name|DIType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addConstantValue
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
specifier|const
name|ConstantInt
modifier|*
name|CI
parameter_list|,
name|DIType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addConstantValue
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
specifier|const
name|APInt
modifier|&
name|Val
parameter_list|,
name|DIType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addConstantValue
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
specifier|const
name|APInt
modifier|&
name|Val
parameter_list|,
name|bool
name|Unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addConstantValue
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
name|bool
name|Unsigned
parameter_list|,
name|uint64_t
name|Val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addConstantFPValue - Add constant value entry in variable DIE.
end_comment

begin_function_decl
name|void
name|addConstantFPValue
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
specifier|const
name|MachineOperand
modifier|&
name|MO
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addConstantFPValue
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|,
specifier|const
name|ConstantFP
modifier|*
name|CFP
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addTemplateParams - Add template parameters in buffer.
end_comment

begin_function_decl
name|void
name|addTemplateParams
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DIArray
name|TParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addRegisterOp - Add register operand.
end_comment

begin_function_decl
name|void
name|addRegisterOp
parameter_list|(
name|DIELoc
modifier|&
name|TheDie
parameter_list|,
name|unsigned
name|Reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addRegisterOffset - Add register offset.
end_comment

begin_function_decl
name|void
name|addRegisterOffset
parameter_list|(
name|DIELoc
modifier|&
name|TheDie
parameter_list|,
name|unsigned
name|Reg
parameter_list|,
name|int64_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addComplexAddress - Start with the address based on the location provided,
end_comment

begin_comment
comment|/// and generate the DWARF information necessary to find the actual variable
end_comment

begin_comment
comment|/// (navigating the extra location information encoded in the type) based on
end_comment

begin_comment
comment|/// the starting location.  Add the DWARF information to the die.
end_comment

begin_decl_stmt
name|void
name|addComplexAddress
argument_list|(
specifier|const
name|DbgVariable
operator|&
name|DV
argument_list|,
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
specifier|const
name|MachineLocation
operator|&
name|Location
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: Should be reformulated in terms of addComplexAddress.
end_comment

begin_comment
comment|/// addBlockByrefAddress - Start with the address based on the location
end_comment

begin_comment
comment|/// provided, and generate the DWARF information necessary to find the
end_comment

begin_comment
comment|/// actual Block variable (navigating the Block struct) based on the
end_comment

begin_comment
comment|/// starting location.  Add the DWARF information to the die.  Obsolete,
end_comment

begin_comment
comment|/// please use addComplexAddress instead.
end_comment

begin_decl_stmt
name|void
name|addBlockByrefAddress
argument_list|(
specifier|const
name|DbgVariable
operator|&
name|DV
argument_list|,
name|DIE
operator|&
name|Die
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
specifier|const
name|MachineLocation
operator|&
name|Location
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addVariableAddress - Add DW_AT_location attribute for a
end_comment

begin_comment
comment|/// DbgVariable based on provided MachineLocation.
end_comment

begin_function_decl
name|void
name|addVariableAddress
parameter_list|(
specifier|const
name|DbgVariable
modifier|&
name|DV
parameter_list|,
name|DIE
modifier|&
name|Die
parameter_list|,
name|MachineLocation
name|Location
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addType - Add a new type attribute to the specified entity. This takes
end_comment

begin_comment
comment|/// and attribute parameter because DW_AT_friend attributes are also
end_comment

begin_comment
comment|/// type references.
end_comment

begin_decl_stmt
name|void
name|addType
argument_list|(
name|DIE
operator|&
name|Entity
argument_list|,
name|DIType
name|Ty
argument_list|,
name|dwarf
operator|::
name|Attribute
name|Attribute
operator|=
name|dwarf
operator|::
name|DW_AT_type
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getOrCreateNameSpace - Create a DIE for DINameSpace.
end_comment

begin_function_decl
name|DIE
modifier|*
name|getOrCreateNameSpace
parameter_list|(
name|DINameSpace
name|NS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getOrCreateSubprogramDIE - Create new DIE using SP.
end_comment

begin_function_decl
name|DIE
modifier|*
name|getOrCreateSubprogramDIE
parameter_list|(
name|DISubprogram
name|SP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|applySubprogramAttributes
parameter_list|(
name|DISubprogram
name|SP
parameter_list|,
name|DIE
modifier|&
name|SPDie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|applySubprogramAttributesToDefinition
parameter_list|(
name|DISubprogram
name|SP
parameter_list|,
name|DIE
modifier|&
name|SPDie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|applyVariableAttributes
parameter_list|(
specifier|const
name|DbgVariable
modifier|&
name|Var
parameter_list|,
name|DIE
modifier|&
name|VariableDie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getOrCreateTypeDIE - Find existing DIE or create new DIE for the
end_comment

begin_comment
comment|/// given DIType.
end_comment

begin_function_decl
name|DIE
modifier|*
name|getOrCreateTypeDIE
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getOrCreateContextDIE - Get context owner's DIE.
end_comment

begin_function_decl
name|DIE
modifier|*
name|createTypeDIE
parameter_list|(
name|DICompositeType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getOrCreateContextDIE - Get context owner's DIE.
end_comment

begin_function_decl
name|DIE
modifier|*
name|getOrCreateContextDIE
parameter_list|(
name|DIScope
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// constructContainingTypeDIEs - Construct DIEs for types that contain
end_comment

begin_comment
comment|/// vtables.
end_comment

begin_function_decl
name|void
name|constructContainingTypeDIEs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// constructVariableDIE - Construct a DIE for the given DbgVariable.
end_comment

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// constructSubprogramArguments - Construct function argument DIEs.
end_comment

begin_function_decl
name|void
name|constructSubprogramArguments
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DIArray
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Create a DIE with the given Tag, add the DIE to its parent, and
end_comment

begin_comment
comment|/// call insertDIE if MD is not null.
end_comment

begin_function_decl
name|DIE
modifier|&
name|createAndAddDIE
parameter_list|(
name|unsigned
name|Tag
parameter_list|,
name|DIE
modifier|&
name|Parent
parameter_list|,
name|DIDescriptor
name|N
init|=
name|DIDescriptor
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Compute the size of a header for this unit, not including the initial
end_comment

begin_comment
comment|/// length field.
end_comment

begin_expr_stmt
name|virtual
name|unsigned
name|getHeaderSize
argument_list|()
specifier|const
block|{
return|return
sizeof|sizeof
argument_list|(
name|int16_t
argument_list|)
operator|+
comment|// DWARF version number
sizeof|sizeof
argument_list|(
name|int32_t
argument_list|)
operator|+
comment|// Offset Into Abbrev. Section
sizeof|sizeof
argument_list|(
name|int8_t
argument_list|)
return|;
comment|// Pointer Size (in bytes)
block|}
end_expr_stmt

begin_comment
comment|/// Emit the header for this unit, not including the initial length field.
end_comment

begin_decl_stmt
name|virtual
name|void
name|emitHeader
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|ASectionSym
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|DwarfCompileUnit
modifier|&
name|getCU
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// constructTypeDIE - Construct type DIE from DICompositeType.
end_comment

begin_function_decl
name|void
name|constructTypeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DICompositeType
name|CTy
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// getOrCreateStaticMemberDIE - Create new static data member DIE.
end_comment

begin_function_decl
name|DIE
modifier|*
name|getOrCreateStaticMemberDIE
parameter_list|(
name|DIDerivedType
name|DT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Look up the source ID with the given directory and source file names. If
end_comment

begin_comment
comment|/// none currently exists, create a new ID and insert it in the line table.
end_comment

begin_function_decl
name|virtual
name|unsigned
name|getOrCreateSourceID
parameter_list|(
name|StringRef
name|File
parameter_list|,
name|StringRef
name|Directory
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Construct a DIE for the given DbgVariable without initializing the
end_comment

begin_comment
comment|/// DbgVariable's DIE reference.
end_comment

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// constructTypeDIE - Construct basic type die from DIBasicType.
end_comment

begin_function_decl
name|void
name|constructTypeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DIBasicType
name|BTy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// constructTypeDIE - Construct derived type die from DIDerivedType.
end_comment

begin_function_decl
name|void
name|constructTypeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DIDerivedType
name|DTy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// constructSubrangeDIE - Construct subrange DIE from DISubrange.
end_comment

begin_function_decl
name|void
name|constructSubrangeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DISubrange
name|SR
parameter_list|,
name|DIE
modifier|*
name|IndexTy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// constructArrayTypeDIE - Construct array type DIE from DICompositeType.
end_comment

begin_function_decl
name|void
name|constructArrayTypeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DICompositeType
name|CTy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// constructEnumTypeDIE - Construct enum type DIE from DIEnumerator.
end_comment

begin_function_decl
name|void
name|constructEnumTypeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DICompositeType
name|CTy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// constructMemberDIE - Construct member DIE from DIDerivedType.
end_comment

begin_function_decl
name|void
name|constructMemberDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DIDerivedType
name|DT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// constructTemplateTypeParameterDIE - Construct new DIE for the given
end_comment

begin_comment
comment|/// DITemplateTypeParameter.
end_comment

begin_function_decl
name|void
name|constructTemplateTypeParameterDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DITemplateTypeParameter
name|TP
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// constructTemplateValueParameterDIE - Construct new DIE for the given
end_comment

begin_comment
comment|/// DITemplateValueParameter.
end_comment

begin_function_decl
name|void
name|constructTemplateValueParameterDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DITemplateValueParameter
name|TVP
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getLowerBoundDefault - Return the default lower bound for an array. If the
end_comment

begin_comment
comment|/// DWARF version doesn't handle the language, return -1.
end_comment

begin_expr_stmt
name|int64_t
name|getDefaultLowerBound
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getDIEEntry - Returns the debug information entry for the specified
end_comment

begin_comment
comment|/// debug variable.
end_comment

begin_decl_stmt
name|DIEEntry
modifier|*
name|getDIEEntry
argument_list|(
specifier|const
name|MDNode
operator|*
name|N
argument_list|)
decl|const
block|{
return|return
name|MDNodeToDIEEntryMap
operator|.
name|lookup
argument_list|(
name|N
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// insertDIEEntry - Insert debug information entry into the map.
end_comment

begin_function
name|void
name|insertDIEEntry
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|,
name|DIEEntry
modifier|*
name|E
parameter_list|)
block|{
name|MDNodeToDIEEntryMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|N
argument_list|,
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// getIndexTyDie - Get an anonymous type for index type.
end_comment

begin_function
name|DIE
modifier|*
name|getIndexTyDie
parameter_list|()
block|{
return|return
name|IndexTyDie
return|;
block|}
end_function

begin_comment
comment|// setIndexTyDie - Set D as anonymous type for index which can be reused
end_comment

begin_comment
comment|// later.
end_comment

begin_function
name|void
name|setIndexTyDie
parameter_list|(
name|DIE
modifier|*
name|D
parameter_list|)
block|{
name|IndexTyDie
operator|=
name|D
expr_stmt|;
block|}
end_function

begin_comment
comment|/// createDIEEntry - Creates a new DIEEntry to be a proxy for a debug
end_comment

begin_comment
comment|/// information entry.
end_comment

begin_function_decl
name|DIEEntry
modifier|*
name|createDIEEntry
parameter_list|(
name|DIE
modifier|&
name|Entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// resolve - Look in the DwarfDebug map for the MDNode that
end_comment

begin_comment
comment|/// corresponds to the reference.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|resolve
argument_list|(
argument|DIRef<T> Ref
argument_list|)
specifier|const
block|{
return|return
name|DD
operator|->
name|resolve
argument_list|(
name|Ref
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// If this is a named finished type then include it in the list of types for
end_comment

begin_comment
comment|/// the accelerator tables.
end_comment

begin_function_decl
name|void
name|updateAcceleratorTables
parameter_list|(
name|DIScope
name|Context
parameter_list|,
name|DIType
name|Ty
parameter_list|,
specifier|const
name|DIE
modifier|&
name|TyDIE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
unit|};
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
comment|/// createGlobalVariableDIE - create global variable DIE.
name|void
name|createGlobalVariableDIE
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
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DwarfTypeUnit
range|:
name|public
name|DwarfUnit
block|{
name|private
operator|:
name|uint64_t
name|TypeSignature
block|;
specifier|const
name|DIE
operator|*
name|Ty
block|;
name|DwarfCompileUnit
operator|&
name|CU
block|;
name|MCDwarfDwoLineTable
operator|*
name|SplitLineTable
block|;
name|public
operator|:
name|DwarfTypeUnit
argument_list|(
argument|unsigned UID
argument_list|,
argument|DwarfCompileUnit&CU
argument_list|,
argument|AsmPrinter *A
argument_list|,
argument|DwarfDebug *DW
argument_list|,
argument|DwarfFile *DWU
argument_list|,
argument|MCDwarfDwoLineTable *SplitLineTable = nullptr
argument_list|)
block|;
name|void
name|setTypeSignature
argument_list|(
argument|uint64_t Signature
argument_list|)
block|{
name|TypeSignature
operator|=
name|Signature
block|; }
name|uint64_t
name|getTypeSignature
argument_list|()
specifier|const
block|{
return|return
name|TypeSignature
return|;
block|}
name|void
name|setType
argument_list|(
argument|const DIE *Ty
argument_list|)
block|{
name|this
operator|->
name|Ty
operator|=
name|Ty
block|; }
comment|/// Emit the header for this unit, not including the initial length field.
name|void
name|emitHeader
argument_list|(
argument|const MCSymbol *ASectionSym
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getHeaderSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|DwarfUnit
operator|::
name|getHeaderSize
argument_list|()
operator|+
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|+
comment|// Type Signature
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
return|;
comment|// Type DIE Offset
block|}
name|void
name|initSection
argument_list|(
specifier|const
name|MCSection
operator|*
name|Section
argument_list|)
block|;
name|DwarfCompileUnit
operator|&
name|getCU
argument_list|()
name|override
block|{
return|return
name|CU
return|;
block|}
name|protected
operator|:
name|unsigned
name|getOrCreateSourceID
argument_list|(
argument|StringRef File
argument_list|,
argument|StringRef Directory
argument_list|)
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


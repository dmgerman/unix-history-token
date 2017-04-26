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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFUNIT_H
end_define

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
file|"llvm/CodeGen/DIE.h"
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
file|"llvm/MC/MCDwarf.h"
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
argument_list|,
name|SmallVector
operator|<
name|RangeSpan
argument_list|,
literal|2
operator|>
name|Ranges
argument_list|)
operator|:
name|RangeSym
argument_list|(
name|Sym
argument_list|)
operator|,
name|Ranges
argument_list|(
argument|std::move(Ranges)
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
comment|/// This dwarf writer support class manages information associated with a
comment|/// source file.
name|class
name|DwarfUnit
range|:
name|public
name|DIEUnit
block|{
name|protected
operator|:
comment|/// MDNode for the compile unit.
specifier|const
name|DICompileUnit
operator|*
name|CUNode
block|;
comment|// All DIEValues are allocated through this allocator.
name|BumpPtrAllocator
name|DIEValueAllocator
block|;
comment|/// Target of Dwarf emission.
name|AsmPrinter
operator|*
name|Asm
block|;
comment|// Holders for some common dwarf information.
name|DwarfDebug
operator|*
name|DD
block|;
name|DwarfFile
operator|*
name|DU
block|;
comment|/// An anonymous type for index type.  Owned by DIEUnit.
name|DIE
operator|*
name|IndexTyDie
block|;
comment|/// Tracks the mapping of unit level debug information variables to debug
comment|/// information entries.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
block|,
name|DIE
operator|*
operator|>
name|MDNodeToDieMap
block|;
comment|/// A list of all the DIEBlocks in use.
name|std
operator|::
name|vector
operator|<
name|DIEBlock
operator|*
operator|>
name|DIEBlocks
block|;
comment|/// A list of all the DIELocs in use.
name|std
operator|::
name|vector
operator|<
name|DIELoc
operator|*
operator|>
name|DIELocs
block|;
comment|/// This map is used to keep track of subprogram DIEs that need
comment|/// DW_AT_containing_type attribute. This attribute points to a DIE that
comment|/// corresponds to the MDNode mapped with the subprogram DIE.
name|DenseMap
operator|<
name|DIE
operator|*
block|,
specifier|const
name|DINode
operator|*
operator|>
name|ContainingTypeMap
block|;
name|DwarfUnit
argument_list|(
name|dwarf
operator|::
name|Tag
argument_list|,
specifier|const
name|DICompileUnit
operator|*
name|CU
argument_list|,
name|AsmPrinter
operator|*
name|A
argument_list|,
name|DwarfDebug
operator|*
name|DW
argument_list|,
name|DwarfFile
operator|*
name|DWU
argument_list|)
block|;
name|bool
name|applySubprogramDefinitionAttributes
argument_list|(
specifier|const
name|DISubprogram
operator|*
name|SP
argument_list|,
name|DIE
operator|&
name|SPDie
argument_list|)
block|;
name|public
operator|:
comment|// Accessors.
name|AsmPrinter
operator|*
name|getAsmPrinter
argument_list|()
specifier|const
block|{
return|return
name|Asm
return|;
block|}
name|uint16_t
name|getLanguage
argument_list|()
specifier|const
block|{
return|return
name|CUNode
operator|->
name|getSourceLanguage
argument_list|()
return|;
block|}
specifier|const
name|DICompileUnit
operator|*
name|getCUNode
argument_list|()
specifier|const
block|{
return|return
name|CUNode
return|;
block|}
comment|/// Return true if this compile unit has something to write out.
name|bool
name|hasContent
argument_list|()
specifier|const
block|{
return|return
name|getUnitDie
argument_list|()
operator|.
name|hasChildren
argument_list|()
return|;
block|}
comment|/// Get string containing language specific context for a global name.
comment|///
comment|/// Walks the metadata parent chain in a language specific manner (using the
comment|/// compile unit language) and returns it as a string. This is done at the
comment|/// metadata level because DIEs may not currently have been added to the
comment|/// parent context and walking the DIEs looking for names is more expensive
comment|/// than walking the metadata.
name|std
operator|::
name|string
name|getParentContextString
argument_list|(
argument|const DIScope *Context
argument_list|)
specifier|const
block|;
comment|/// Add a new global name to the compile unit.
name|virtual
name|void
name|addGlobalName
argument_list|(
argument|StringRef Name
argument_list|,
argument|const DIE&Die
argument_list|,
argument|const DIScope *Context
argument_list|)
operator|=
literal|0
block|;
comment|/// Add a new global type to the compile unit.
name|virtual
name|void
name|addGlobalType
argument_list|(
specifier|const
name|DIType
operator|*
name|Ty
argument_list|,
specifier|const
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|DIScope
operator|*
name|Context
argument_list|)
operator|=
literal|0
block|;
comment|/// Returns the DIE map slot for the specified debug variable.
comment|///
comment|/// We delegate the request to DwarfDebug when the MDNode can be part of the
comment|/// type system, since DIEs for the type system can be shared across CUs and
comment|/// the mappings are kept in DwarfDebug.
name|DIE
operator|*
name|getDIE
argument_list|(
argument|const DINode *D
argument_list|)
specifier|const
block|;
comment|/// Returns a fresh newly allocated DIELoc.
name|DIELoc
operator|*
name|getDIELoc
argument_list|()
block|{
return|return
name|new
argument_list|(
argument|DIEValueAllocator
argument_list|)
name|DIELoc
return|;
block|}
comment|/// Insert DIE into the map.
comment|///
comment|/// We delegate the request to DwarfDebug when the MDNode can be part of the
comment|/// type system, since DIEs for the type system can be shared across CUs and
comment|/// the mappings are kept in DwarfDebug.
name|void
name|insertDIE
argument_list|(
specifier|const
name|DINode
operator|*
name|Desc
argument_list|,
name|DIE
operator|*
name|D
argument_list|)
block|;
comment|/// Add a flag that is true to the DIE.
name|void
name|addFlag
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|)
block|;
comment|/// Add an unsigned integer attribute data and value.
name|void
name|addUInt
argument_list|(
argument|DIEValueList&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|Optional<dwarf::Form> Form
argument_list|,
argument|uint64_t Integer
argument_list|)
block|;
name|void
name|addUInt
argument_list|(
argument|DIEValueList&Block
argument_list|,
argument|dwarf::Form Form
argument_list|,
argument|uint64_t Integer
argument_list|)
block|;
comment|/// Add an signed integer attribute data and value.
name|void
name|addSInt
argument_list|(
argument|DIEValueList&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|Optional<dwarf::Form> Form
argument_list|,
argument|int64_t Integer
argument_list|)
block|;
name|void
name|addSInt
argument_list|(
argument|DIELoc&Die
argument_list|,
argument|Optional<dwarf::Form> Form
argument_list|,
argument|int64_t Integer
argument_list|)
block|;
comment|/// Add a string attribute data and value.
comment|///
comment|/// We always emit a reference to the string pool instead of immediate
comment|/// strings so that DIEs have more predictable sizes. In the case of split
comment|/// dwarf we emit an index into another table which gets us the static offset
comment|/// into the string table.
name|void
name|addString
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|StringRef Str
argument_list|)
block|;
comment|/// Add a Dwarf label attribute data and value.
name|DIEValueList
operator|::
name|value_iterator
name|addLabel
argument_list|(
argument|DIEValueList&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|dwarf::Form Form
argument_list|,
argument|const MCSymbol *Label
argument_list|)
block|;
name|void
name|addLabel
argument_list|(
argument|DIELoc&Die
argument_list|,
argument|dwarf::Form Form
argument_list|,
argument|const MCSymbol *Label
argument_list|)
block|;
comment|/// Add an offset into a section attribute data and value.
name|void
name|addSectionOffset
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|uint64_t Integer
argument_list|)
block|;
comment|/// Add a dwarf op address data and value using the form given and an
comment|/// op of either DW_FORM_addr or DW_FORM_GNU_addr_index.
name|void
name|addOpAddress
argument_list|(
name|DIELoc
operator|&
name|Die
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Label
argument_list|)
block|;
comment|/// Add a label delta attribute data and value.
name|void
name|addLabelDelta
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
comment|/// Add a DIE attribute data and value.
name|void
name|addDIEEntry
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|DIE&Entry
argument_list|)
block|;
comment|/// Add a DIE attribute data and value.
name|void
name|addDIEEntry
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|DIEEntry Entry
argument_list|)
block|;
comment|/// Add a type's DW_AT_signature and set the  declaration flag.
name|void
name|addDIETypeSignature
argument_list|(
argument|DIE&Die
argument_list|,
argument|uint64_t Signature
argument_list|)
block|;
comment|/// Add block data.
name|void
name|addBlock
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|DIELoc *Block
argument_list|)
block|;
comment|/// Add block data.
name|void
name|addBlock
argument_list|(
argument|DIE&Die
argument_list|,
argument|dwarf::Attribute Attribute
argument_list|,
argument|DIEBlock *Block
argument_list|)
block|;
comment|/// Add location information to specified debug information entry.
name|void
name|addSourceLine
argument_list|(
argument|DIE&Die
argument_list|,
argument|unsigned Line
argument_list|,
argument|StringRef File
argument_list|,
argument|StringRef Directory
argument_list|)
block|;
name|void
name|addSourceLine
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|DILocalVariable
operator|*
name|V
argument_list|)
block|;
name|void
name|addSourceLine
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|DIGlobalVariable
operator|*
name|G
argument_list|)
block|;
name|void
name|addSourceLine
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|DISubprogram
operator|*
name|SP
argument_list|)
block|;
name|void
name|addSourceLine
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|DIType
operator|*
name|Ty
argument_list|)
block|;
name|void
name|addSourceLine
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|DINamespace
operator|*
name|NS
argument_list|)
block|;
name|void
name|addSourceLine
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|DIObjCProperty
operator|*
name|Ty
argument_list|)
block|;
comment|/// Add constant value entry in variable DIE.
name|void
name|addConstantValue
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
specifier|const
name|DIType
operator|*
name|Ty
argument_list|)
block|;
name|void
name|addConstantValue
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|ConstantInt
operator|*
name|CI
argument_list|,
specifier|const
name|DIType
operator|*
name|Ty
argument_list|)
block|;
name|void
name|addConstantValue
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|APInt
operator|&
name|Val
argument_list|,
specifier|const
name|DIType
operator|*
name|Ty
argument_list|)
block|;
name|void
name|addConstantValue
argument_list|(
argument|DIE&Die
argument_list|,
argument|const APInt&Val
argument_list|,
argument|bool Unsigned
argument_list|)
block|;
name|void
name|addConstantValue
argument_list|(
argument|DIE&Die
argument_list|,
argument|bool Unsigned
argument_list|,
argument|uint64_t Val
argument_list|)
block|;
comment|/// Add constant value entry in variable DIE.
name|void
name|addConstantFPValue
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|)
block|;
name|void
name|addConstantFPValue
argument_list|(
name|DIE
operator|&
name|Die
argument_list|,
specifier|const
name|ConstantFP
operator|*
name|CFP
argument_list|)
block|;
comment|/// Add a linkage name, if it isn't empty.
name|void
name|addLinkageName
argument_list|(
argument|DIE&Die
argument_list|,
argument|StringRef LinkageName
argument_list|)
block|;
comment|/// Add template parameters in buffer.
name|void
name|addTemplateParams
argument_list|(
argument|DIE&Buffer
argument_list|,
argument|DINodeArray TParams
argument_list|)
block|;
comment|// FIXME: Should be reformulated in terms of addComplexAddress.
comment|/// Start with the address based on the location provided, and generate the
comment|/// DWARF information necessary to find the actual Block variable (navigating
comment|/// the Block struct) based on the starting location.  Add the DWARF
comment|/// information to the die.  Obsolete, please use addComplexAddress instead.
name|void
name|addBlockByrefAddress
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
comment|/// Add a new type attribute to the specified entity.
comment|///
comment|/// This takes and attribute parameter because DW_AT_friend attributes are
comment|/// also type references.
name|void
name|addType
argument_list|(
argument|DIE&Entity
argument_list|,
argument|const DIType *Ty
argument_list|,
argument|dwarf::Attribute Attribute = dwarf::DW_AT_type
argument_list|)
block|;
name|DIE
operator|*
name|getOrCreateNameSpace
argument_list|(
specifier|const
name|DINamespace
operator|*
name|NS
argument_list|)
block|;
name|DIE
operator|*
name|getOrCreateModule
argument_list|(
specifier|const
name|DIModule
operator|*
name|M
argument_list|)
block|;
name|DIE
operator|*
name|getOrCreateSubprogramDIE
argument_list|(
argument|const DISubprogram *SP
argument_list|,
argument|bool Minimal = false
argument_list|)
block|;
name|void
name|applySubprogramAttributes
argument_list|(
argument|const DISubprogram *SP
argument_list|,
argument|DIE&SPDie
argument_list|,
argument|bool SkipSPAttributes = false
argument_list|)
block|;
comment|/// Find existing DIE or create new DIE for the given type.
name|DIE
operator|*
name|getOrCreateTypeDIE
argument_list|(
specifier|const
name|MDNode
operator|*
name|N
argument_list|)
block|;
comment|/// Get context owner's DIE.
name|DIE
operator|*
name|getOrCreateContextDIE
argument_list|(
specifier|const
name|DIScope
operator|*
name|Context
argument_list|)
block|;
comment|/// Construct DIEs for types that contain vtables.
name|void
name|constructContainingTypeDIEs
argument_list|()
block|;
comment|/// Construct function argument DIEs.
name|void
name|constructSubprogramArguments
argument_list|(
argument|DIE&Buffer
argument_list|,
argument|DITypeRefArray Args
argument_list|)
block|;
comment|/// Create a DIE with the given Tag, add the DIE to its parent, and
comment|/// call insertDIE if MD is not null.
name|DIE
operator|&
name|createAndAddDIE
argument_list|(
argument|unsigned Tag
argument_list|,
argument|DIE&Parent
argument_list|,
argument|const DINode *N = nullptr
argument_list|)
block|;
comment|/// Compute the size of a header for this unit, not including the initial
comment|/// length field.
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
operator|+
comment|// Pointer Size (in bytes)
operator|(
name|DD
operator|->
name|getDwarfVersion
argument_list|()
operator|>=
literal|5
operator|?
sizeof|sizeof
argument_list|(
name|int8_t
argument_list|)
operator|:
literal|0
operator|)
return|;
comment|// DWARF v5 unit type
block|}
comment|/// Emit the header for this unit, not including the initial length field.
name|virtual
name|void
name|emitHeader
argument_list|(
argument|bool UseOffsets
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|DwarfCompileUnit
operator|&
name|getCU
argument_list|()
operator|=
literal|0
block|;
name|void
name|constructTypeDIE
argument_list|(
name|DIE
operator|&
name|Buffer
argument_list|,
specifier|const
name|DICompositeType
operator|*
name|CTy
argument_list|)
block|;
name|protected
operator|:
operator|~
name|DwarfUnit
argument_list|()
block|;
comment|/// Create new static data member DIE.
name|DIE
operator|*
name|getOrCreateStaticMemberDIE
argument_list|(
specifier|const
name|DIDerivedType
operator|*
name|DT
argument_list|)
block|;
comment|/// Look up the source ID with the given directory and source file names. If
comment|/// none currently exists, create a new ID and insert it in the line table.
name|virtual
name|unsigned
name|getOrCreateSourceID
argument_list|(
argument|StringRef File
argument_list|,
argument|StringRef Directory
argument_list|)
operator|=
literal|0
block|;
comment|/// Look in the DwarfDebug map for the MDNode that corresponds to the
comment|/// reference.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|resolve
argument_list|(
argument|TypedDINodeRef<T> Ref
argument_list|)
specifier|const
block|{
return|return
name|Ref
operator|.
name|resolve
argument_list|()
return|;
block|}
comment|/// If this is a named finished type then include it in the list of types for
comment|/// the accelerator tables.
name|void
name|updateAcceleratorTables
argument_list|(
specifier|const
name|DIScope
operator|*
name|Context
argument_list|,
specifier|const
name|DIType
operator|*
name|Ty
argument_list|,
specifier|const
name|DIE
operator|&
name|TyDIE
argument_list|)
block|;
comment|/// Emit the common part of the header for this unit.
name|void
name|emitCommonHeader
argument_list|(
argument|bool UseOffsets
argument_list|,
argument|dwarf::UnitType UT
argument_list|)
block|;
name|private
operator|:
name|void
name|constructTypeDIE
argument_list|(
name|DIE
operator|&
name|Buffer
argument_list|,
specifier|const
name|DIBasicType
operator|*
name|BTy
argument_list|)
block|;
name|void
name|constructTypeDIE
argument_list|(
name|DIE
operator|&
name|Buffer
argument_list|,
specifier|const
name|DIDerivedType
operator|*
name|DTy
argument_list|)
block|;
name|void
name|constructTypeDIE
argument_list|(
name|DIE
operator|&
name|Buffer
argument_list|,
specifier|const
name|DISubroutineType
operator|*
name|DTy
argument_list|)
block|;
name|void
name|constructSubrangeDIE
argument_list|(
name|DIE
operator|&
name|Buffer
argument_list|,
specifier|const
name|DISubrange
operator|*
name|SR
argument_list|,
name|DIE
operator|*
name|IndexTy
argument_list|)
block|;
name|void
name|constructArrayTypeDIE
argument_list|(
name|DIE
operator|&
name|Buffer
argument_list|,
specifier|const
name|DICompositeType
operator|*
name|CTy
argument_list|)
block|;
name|void
name|constructEnumTypeDIE
argument_list|(
name|DIE
operator|&
name|Buffer
argument_list|,
specifier|const
name|DICompositeType
operator|*
name|CTy
argument_list|)
block|;
name|void
name|constructMemberDIE
argument_list|(
name|DIE
operator|&
name|Buffer
argument_list|,
specifier|const
name|DIDerivedType
operator|*
name|DT
argument_list|)
block|;
name|void
name|constructTemplateTypeParameterDIE
argument_list|(
name|DIE
operator|&
name|Buffer
argument_list|,
specifier|const
name|DITemplateTypeParameter
operator|*
name|TP
argument_list|)
block|;
name|void
name|constructTemplateValueParameterDIE
argument_list|(
name|DIE
operator|&
name|Buffer
argument_list|,
specifier|const
name|DITemplateValueParameter
operator|*
name|TVP
argument_list|)
block|;
comment|/// Return the default lower bound for an array.
comment|///
comment|/// If the DWARF version doesn't handle the language, return -1.
name|int64_t
name|getDefaultLowerBound
argument_list|()
specifier|const
block|;
comment|/// Get an anonymous type for index type.
name|DIE
operator|*
name|getIndexTyDie
argument_list|()
block|;
comment|/// Set D as anonymous type for index which can be reused later.
name|void
name|setIndexTyDie
argument_list|(
argument|DIE *D
argument_list|)
block|{
name|IndexTyDie
operator|=
name|D
block|; }
name|virtual
name|bool
name|isDwoUnit
argument_list|()
specifier|const
operator|=
literal|0
block|;
specifier|const
name|MCSymbol
operator|*
name|getCrossSectionRelativeBaseAddress
argument_list|()
specifier|const
name|override
block|; }
decl_stmt|;
name|class
name|DwarfTypeUnit
name|final
range|:
name|public
name|DwarfUnit
block|{
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
name|unsigned
name|getOrCreateSourceID
argument_list|(
argument|StringRef File
argument_list|,
argument|StringRef Directory
argument_list|)
name|override
block|;
name|bool
name|isDwoUnit
argument_list|()
specifier|const
name|override
block|;
name|public
operator|:
name|DwarfTypeUnit
argument_list|(
name|DwarfCompileUnit
operator|&
name|CU
argument_list|,
name|AsmPrinter
operator|*
name|A
argument_list|,
name|DwarfDebug
operator|*
name|DW
argument_list|,
name|DwarfFile
operator|*
name|DWU
argument_list|,
name|MCDwarfDwoLineTable
operator|*
name|SplitLineTable
operator|=
name|nullptr
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
comment|/// Get context owner's DIE.
name|DIE
operator|*
name|createTypeDIE
argument_list|(
specifier|const
name|DICompositeType
operator|*
name|Ty
argument_list|)
block|;
comment|/// Emit the header for this unit, not including the initial length field.
name|void
name|emitHeader
argument_list|(
argument|bool UseOffsets
argument_list|)
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
name|addGlobalName
argument_list|(
argument|StringRef Name
argument_list|,
argument|const DIE&Die
argument_list|,
argument|const DIScope *Context
argument_list|)
name|override
block|;
name|void
name|addGlobalType
argument_list|(
argument|const DIType *Ty
argument_list|,
argument|const DIE&Die
argument_list|,
argument|const DIScope *Context
argument_list|)
name|override
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
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


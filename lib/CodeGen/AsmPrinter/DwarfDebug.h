begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DwarfDebug.h - Dwarf Debug Framework ------*- C++ -*--===//
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
comment|// This file contains support for writing dwarf debug info into asm files.
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
name|CODEGEN_ASMPRINTER_DWARFDEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_ASMPRINTER_DWARFDEBUG_H__
end_define

begin_include
include|#
directive|include
file|"DIE.h"
end_include

begin_include
include|#
directive|include
file|"DwarfPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/UniqueVector.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CompileUnit
decl_stmt|;
name|class
name|DbgConcreteScope
decl_stmt|;
name|class
name|DbgScope
decl_stmt|;
name|class
name|DbgVariable
decl_stmt|;
name|class
name|MachineFrameInfo
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|Timer
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// SrcLineInfo - This class is used to record source line correspondence.
comment|///
name|class
name|SrcLineInfo
block|{
name|unsigned
name|Line
decl_stmt|;
comment|// Source line number.
name|unsigned
name|Column
decl_stmt|;
comment|// Source column.
name|unsigned
name|SourceID
decl_stmt|;
comment|// Source ID number.
name|unsigned
name|LabelID
decl_stmt|;
comment|// Label in code ID number.
name|public
label|:
name|SrcLineInfo
argument_list|(
argument|unsigned L
argument_list|,
argument|unsigned C
argument_list|,
argument|unsigned S
argument_list|,
argument|unsigned I
argument_list|)
block|:
name|Line
argument_list|(
name|L
argument_list|)
operator|,
name|Column
argument_list|(
name|C
argument_list|)
operator|,
name|SourceID
argument_list|(
name|S
argument_list|)
operator|,
name|LabelID
argument_list|(
argument|I
argument_list|)
block|{}
comment|// Accessors
name|unsigned
name|getLine
argument_list|()
specifier|const
block|{
return|return
name|Line
return|;
block|}
name|unsigned
name|getColumn
argument_list|()
specifier|const
block|{
return|return
name|Column
return|;
block|}
name|unsigned
name|getSourceID
argument_list|()
specifier|const
block|{
return|return
name|SourceID
return|;
block|}
name|unsigned
name|getLabelID
argument_list|()
specifier|const
block|{
return|return
name|LabelID
return|;
block|}
block|}
empty_stmt|;
name|class
name|DwarfDebug
range|:
name|public
name|DwarfPrinter
block|{
comment|//===--------------------------------------------------------------------===//
comment|// Attributes used to construct specific Dwarf sections.
comment|//
comment|/// CompileUnitMap - A map of global variables representing compile units to
comment|/// compile units.
name|DenseMap
operator|<
name|Value
operator|*
block|,
name|CompileUnit
operator|*
operator|>
name|CompileUnitMap
block|;
comment|/// CompileUnits - All the compile units in this module.
comment|///
name|SmallVector
operator|<
name|CompileUnit
operator|*
block|,
literal|8
operator|>
name|CompileUnits
block|;
comment|/// ModuleCU - All DIEs are inserted in ModuleCU.
name|CompileUnit
operator|*
name|ModuleCU
block|;
comment|/// AbbreviationsSet - Used to uniquely define abbreviations.
comment|///
name|FoldingSet
operator|<
name|DIEAbbrev
operator|>
name|AbbreviationsSet
block|;
comment|/// Abbreviations - A list of all the unique abbreviations in use.
comment|///
name|std
operator|::
name|vector
operator|<
name|DIEAbbrev
operator|*
operator|>
name|Abbreviations
block|;
comment|/// DirectoryIdMap - Directory name to directory id map.
comment|///
name|StringMap
operator|<
name|unsigned
operator|>
name|DirectoryIdMap
block|;
comment|/// DirectoryNames - A list of directory names.
name|SmallVector
operator|<
name|std
operator|::
name|string
block|,
literal|8
operator|>
name|DirectoryNames
block|;
comment|/// SourceFileIdMap - Source file name to source file id map.
comment|///
name|StringMap
operator|<
name|unsigned
operator|>
name|SourceFileIdMap
block|;
comment|/// SourceFileNames - A list of source file names.
name|SmallVector
operator|<
name|std
operator|::
name|string
block|,
literal|8
operator|>
name|SourceFileNames
block|;
comment|/// SourceIdMap - Source id map, i.e. pair of directory id and source file
comment|/// id mapped to a unique id.
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
block|,
name|unsigned
operator|>
name|SourceIdMap
block|;
comment|/// SourceIds - Reverse map from source id to directory id + file id pair.
comment|///
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
block|,
literal|8
operator|>
name|SourceIds
block|;
comment|/// Lines - List of of source line correspondence.
name|std
operator|::
name|vector
operator|<
name|SrcLineInfo
operator|>
name|Lines
block|;
comment|/// DIEValues - A list of all the unique values in use.
comment|///
name|std
operator|::
name|vector
operator|<
name|DIEValue
operator|*
operator|>
name|DIEValues
block|;
comment|/// StringPool - A UniqueVector of strings used by indirect references.
comment|///
name|UniqueVector
operator|<
name|std
operator|::
name|string
operator|>
name|StringPool
block|;
comment|/// SectionMap - Provides a unique id per text section.
comment|///
name|UniqueVector
operator|<
specifier|const
name|MCSection
operator|*
operator|>
name|SectionMap
block|;
comment|/// SectionSourceLines - Tracks line numbers per text section.
comment|///
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|SrcLineInfo
operator|>
expr|>
name|SectionSourceLines
block|;
comment|/// didInitial - Flag to indicate if initial emission has been done.
comment|///
name|bool
name|didInitial
block|;
comment|/// shouldEmit - Flag to indicate if debug information should be emitted.
comment|///
name|bool
name|shouldEmit
block|;
comment|// CurrentFnDbgScope - Top level scope for the current function.
comment|//
name|DbgScope
operator|*
name|CurrentFnDbgScope
block|;
comment|/// DbgScopeMap - Tracks the scopes in the current function.
comment|///
name|DenseMap
operator|<
name|MDNode
operator|*
block|,
name|DbgScope
operator|*
operator|>
name|DbgScopeMap
block|;
comment|/// ConcreteScopes - Tracks the concrete scopees in the current function.
comment|/// These scopes are also included in DbgScopeMap.
name|DenseMap
operator|<
name|MDNode
operator|*
block|,
name|DbgScope
operator|*
operator|>
name|ConcreteScopes
block|;
comment|/// AbstractScopes - Tracks the abstract scopes a module. These scopes are
comment|/// not included DbgScopeMap.
name|DenseMap
operator|<
name|MDNode
operator|*
block|,
name|DbgScope
operator|*
operator|>
name|AbstractScopes
block|;
name|SmallVector
operator|<
name|DbgScope
operator|*
block|,
literal|4
operator|>
name|AbstractScopesList
block|;
comment|/// AbstractVariables - Collection on abstract variables.
name|DenseMap
operator|<
name|MDNode
operator|*
block|,
name|DbgVariable
operator|*
operator|>
name|AbstractVariables
block|;
comment|/// InliendSubprogramDIEs - Collection of subprgram DIEs that are marked
comment|/// (at the end of the module) as DW_AT_inline.
name|SmallPtrSet
operator|<
name|DIE
operator|*
block|,
literal|4
operator|>
name|InlinedSubprogramDIEs
block|;
name|DenseMap
operator|<
name|DIE
operator|*
block|,
name|MDNode
operator|*
operator|>
name|ContainingTypeMap
block|;
comment|/// AbstractSubprogramDIEs - Collection of abstruct subprogram DIEs.
name|SmallPtrSet
operator|<
name|DIE
operator|*
block|,
literal|4
operator|>
name|AbstractSubprogramDIEs
block|;
comment|/// TopLevelDIEs - Collection of top level DIEs.
name|SmallPtrSet
operator|<
name|DIE
operator|*
block|,
literal|4
operator|>
name|TopLevelDIEs
block|;
name|SmallVector
operator|<
name|DIE
operator|*
block|,
literal|4
operator|>
name|TopLevelDIEsVector
block|;
typedef|typedef
name|SmallVector
operator|<
name|DbgScope
operator|*
operator|,
literal|2
operator|>
name|ScopeVector
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|MachineInstr
operator|*
operator|,
name|ScopeVector
operator|>
name|InsnToDbgScopeMapTy
expr_stmt|;
comment|/// DbgScopeBeginMap - Maps instruction with a list of DbgScopes it starts.
name|InsnToDbgScopeMapTy
name|DbgScopeBeginMap
decl_stmt|;
comment|/// DbgScopeEndMap - Maps instruction with a list DbgScopes it ends.
name|InsnToDbgScopeMapTy
name|DbgScopeEndMap
decl_stmt|;
comment|/// InlineInfo - Keep track of inlined functions and their location.  This
comment|/// information is used to populate debug_inlined section.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|DIE
operator|*
operator|>
name|InlineInfoLabels
expr_stmt|;
name|DenseMap
operator|<
name|MDNode
operator|*
operator|,
name|SmallVector
operator|<
name|InlineInfoLabels
operator|,
literal|4
operator|>
expr|>
name|InlineInfo
expr_stmt|;
name|SmallVector
operator|<
name|MDNode
operator|*
operator|,
literal|4
operator|>
name|InlinedSPNodes
expr_stmt|;
comment|/// CompileUnitOffsets - A vector of the offsets of the compile units. This is
comment|/// used when calculating the "origin" of a concrete instance of an inlined
comment|/// function.
name|DenseMap
operator|<
name|CompileUnit
operator|*
operator|,
name|unsigned
operator|>
name|CompileUnitOffsets
expr_stmt|;
comment|/// DebugTimer - Timer for the Dwarf debug writer.
name|Timer
modifier|*
name|DebugTimer
decl_stmt|;
struct|struct
name|FunctionDebugFrameInfo
block|{
name|unsigned
name|Number
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|MachineMove
operator|>
name|Moves
expr_stmt|;
name|FunctionDebugFrameInfo
argument_list|(
argument|unsigned Num
argument_list|,
argument|const std::vector<MachineMove>&M
argument_list|)
block|:
name|Number
argument_list|(
name|Num
argument_list|)
operator|,
name|Moves
argument_list|(
argument|M
argument_list|)
block|{}
block|}
struct|;
name|std
operator|::
name|vector
operator|<
name|FunctionDebugFrameInfo
operator|>
name|DebugFrames
expr_stmt|;
comment|/// getSourceDirectoryAndFileIds - Return the directory and file ids that
comment|/// maps to the source id. Source id starts at 1.
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|getSourceDirectoryAndFileIds
argument_list|(
argument|unsigned SId
argument_list|)
specifier|const
block|{
return|return
name|SourceIds
index|[
name|SId
operator|-
literal|1
index|]
return|;
block|}
comment|/// getNumSourceDirectories - Return the number of source directories in the
comment|/// debug info.
name|unsigned
name|getNumSourceDirectories
argument_list|()
specifier|const
block|{
return|return
name|DirectoryNames
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// getSourceDirectoryName - Return the name of the directory corresponding
comment|/// to the id.
specifier|const
name|std
operator|::
name|string
operator|&
name|getSourceDirectoryName
argument_list|(
argument|unsigned Id
argument_list|)
specifier|const
block|{
return|return
name|DirectoryNames
index|[
name|Id
operator|-
literal|1
index|]
return|;
block|}
comment|/// getSourceFileName - Return the name of the source file corresponding
comment|/// to the id.
specifier|const
name|std
operator|::
name|string
operator|&
name|getSourceFileName
argument_list|(
argument|unsigned Id
argument_list|)
specifier|const
block|{
return|return
name|SourceFileNames
index|[
name|Id
operator|-
literal|1
index|]
return|;
block|}
comment|/// getNumSourceIds - Return the number of unique source ids.
name|unsigned
name|getNumSourceIds
argument_list|()
specifier|const
block|{
return|return
name|SourceIds
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// assignAbbrevNumber - Define a unique number for the abbreviation.
comment|///
name|void
name|assignAbbrevNumber
parameter_list|(
name|DIEAbbrev
modifier|&
name|Abbrev
parameter_list|)
function_decl|;
comment|/// createDIEEntry - Creates a new DIEEntry to be a proxy for a debug
comment|/// information entry.
name|DIEEntry
modifier|*
name|createDIEEntry
parameter_list|(
name|DIE
modifier|*
name|Entry
init|=
name|NULL
parameter_list|)
function_decl|;
comment|/// addUInt - Add an unsigned integer attribute data and value.
comment|///
name|void
name|addUInt
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
name|uint64_t
name|Integer
parameter_list|)
function_decl|;
comment|/// addSInt - Add an signed integer attribute data and value.
comment|///
name|void
name|addSInt
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
name|int64_t
name|Integer
parameter_list|)
function_decl|;
comment|/// addString - Add a string attribute data and value.
comment|///
name|void
name|addString
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
specifier|const
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// addLabel - Add a Dwarf label attribute data and value.
comment|///
name|void
name|addLabel
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
specifier|const
name|DWLabel
modifier|&
name|Label
parameter_list|)
function_decl|;
comment|/// addObjectLabel - Add an non-Dwarf label attribute data and value.
comment|///
name|void
name|addObjectLabel
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Sym
parameter_list|)
function_decl|;
comment|/// addSectionOffset - Add a section offset label attribute data and value.
comment|///
name|void
name|addSectionOffset
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
specifier|const
name|DWLabel
modifier|&
name|Label
parameter_list|,
specifier|const
name|DWLabel
modifier|&
name|Section
parameter_list|,
name|bool
name|isEH
init|=
name|false
parameter_list|,
name|bool
name|useSet
init|=
name|true
parameter_list|)
function_decl|;
comment|/// addDelta - Add a label delta attribute data and value.
comment|///
name|void
name|addDelta
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
specifier|const
name|DWLabel
modifier|&
name|Hi
parameter_list|,
specifier|const
name|DWLabel
modifier|&
name|Lo
parameter_list|)
function_decl|;
comment|/// addDIEEntry - Add a DIE attribute data and value.
comment|///
name|void
name|addDIEEntry
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
name|DIE
modifier|*
name|Entry
parameter_list|)
block|{
name|Die
operator|->
name|addValue
argument_list|(
name|Attribute
argument_list|,
name|Form
argument_list|,
name|createDIEEntry
argument_list|(
name|Entry
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// addBlock - Add block data.
comment|///
name|void
name|addBlock
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
name|DIEBlock
modifier|*
name|Block
parameter_list|)
function_decl|;
comment|/// addSourceLine - Add location information to specified debug information
comment|/// entry.
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
specifier|const
name|DIVariable
modifier|*
name|V
parameter_list|)
function_decl|;
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
specifier|const
name|DIGlobal
modifier|*
name|G
parameter_list|)
function_decl|;
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
specifier|const
name|DISubprogram
modifier|*
name|SP
parameter_list|)
function_decl|;
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
specifier|const
name|DIType
modifier|*
name|Ty
parameter_list|)
function_decl|;
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
specifier|const
name|DINameSpace
modifier|*
name|NS
parameter_list|)
function_decl|;
comment|/// addAddress - Add an address attribute to a die based on the location
comment|/// provided.
name|void
name|addAddress
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
specifier|const
name|MachineLocation
modifier|&
name|Location
parameter_list|)
function_decl|;
comment|/// addComplexAddress - Start with the address based on the location provided,
comment|/// and generate the DWARF information necessary to find the actual variable
comment|/// (navigating the extra location information encoded in the type) based on
comment|/// the starting location.  Add the DWARF information to the die.
comment|///
name|void
name|addComplexAddress
parameter_list|(
name|DbgVariable
modifier|*
modifier|&
name|DV
parameter_list|,
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
specifier|const
name|MachineLocation
modifier|&
name|Location
parameter_list|)
function_decl|;
comment|// FIXME: Should be reformulated in terms of addComplexAddress.
comment|/// addBlockByrefAddress - Start with the address based on the location
comment|/// provided, and generate the DWARF information necessary to find the
comment|/// actual Block variable (navigating the Block struct) based on the
comment|/// starting location.  Add the DWARF information to the die.  Obsolete,
comment|/// please use addComplexAddress instead.
comment|///
name|void
name|addBlockByrefAddress
parameter_list|(
name|DbgVariable
modifier|*
modifier|&
name|DV
parameter_list|,
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
specifier|const
name|MachineLocation
modifier|&
name|Location
parameter_list|)
function_decl|;
comment|/// addToContextOwner - Add Die into the list of its context owner's children.
name|void
name|addToContextOwner
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|DIDescriptor
name|Context
parameter_list|)
function_decl|;
comment|/// addType - Add a new type attribute to the specified entity.
name|void
name|addType
parameter_list|(
name|DIE
modifier|*
name|Entity
parameter_list|,
name|DIType
name|Ty
parameter_list|)
function_decl|;
comment|/// getOrCreateNameSpace - Create a DIE for DINameSpace.
name|DIE
modifier|*
name|getOrCreateNameSpace
parameter_list|(
name|DINameSpace
name|NS
parameter_list|)
function_decl|;
comment|/// getOrCreateTypeDIE - Find existing DIE or create new DIE for the
comment|/// given DIType.
name|DIE
modifier|*
name|getOrCreateTypeDIE
parameter_list|(
name|DIType
name|Ty
parameter_list|)
function_decl|;
name|void
name|addPubTypes
parameter_list|(
name|DISubprogram
name|SP
parameter_list|)
function_decl|;
comment|/// constructTypeDIE - Construct basic type die from DIBasicType.
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
comment|/// constructTypeDIE - Construct derived type die from DIDerivedType.
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
comment|/// constructTypeDIE - Construct type DIE from DICompositeType.
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
comment|/// constructSubrangeDIE - Construct subrange DIE from DISubrange.
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
comment|/// constructArrayTypeDIE - Construct array type DIE from DICompositeType.
name|void
name|constructArrayTypeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DICompositeType
modifier|*
name|CTy
parameter_list|)
function_decl|;
comment|/// constructEnumTypeDIE - Construct enum type DIE from DIEnumerator.
name|DIE
modifier|*
name|constructEnumTypeDIE
parameter_list|(
name|DIEnumerator
modifier|*
name|ETy
parameter_list|)
function_decl|;
comment|/// createGlobalVariableDIE - Create new DIE using GV.
name|DIE
modifier|*
name|createGlobalVariableDIE
parameter_list|(
specifier|const
name|DIGlobalVariable
modifier|&
name|GV
parameter_list|)
function_decl|;
comment|/// createMemberDIE - Create new member DIE.
name|DIE
modifier|*
name|createMemberDIE
parameter_list|(
specifier|const
name|DIDerivedType
modifier|&
name|DT
parameter_list|)
function_decl|;
comment|/// createSubprogramDIE - Create new DIE using SP.
name|DIE
modifier|*
name|createSubprogramDIE
parameter_list|(
specifier|const
name|DISubprogram
modifier|&
name|SP
parameter_list|,
name|bool
name|MakeDecl
init|=
name|false
parameter_list|)
function_decl|;
comment|/// findCompileUnit - Get the compile unit for the given descriptor.
comment|///
name|CompileUnit
modifier|*
name|findCompileUnit
parameter_list|(
name|DICompileUnit
name|Unit
parameter_list|)
function_decl|;
comment|/// getUpdatedDbgScope - Find or create DbgScope assicated with
comment|/// the instruction. Initialize scope and update scope hierarchy.
name|DbgScope
modifier|*
name|getUpdatedDbgScope
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|,
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|MDNode
modifier|*
name|InlinedAt
parameter_list|)
function_decl|;
comment|/// createDbgScope - Create DbgScope for the scope.
name|void
name|createDbgScope
parameter_list|(
name|MDNode
modifier|*
name|Scope
parameter_list|,
name|MDNode
modifier|*
name|InlinedAt
parameter_list|)
function_decl|;
name|DbgScope
modifier|*
name|getOrCreateAbstractScope
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// findAbstractVariable - Find abstract variable associated with Var.
name|DbgVariable
modifier|*
name|findAbstractVariable
parameter_list|(
name|DIVariable
modifier|&
name|Var
parameter_list|,
name|unsigned
name|FrameIdx
parameter_list|,
name|DILocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// updateSubprogramScopeDIE - Find DIE for the given subprogram and
comment|/// attach appropriate DW_AT_low_pc and DW_AT_high_pc attributes.
comment|/// If there are global variables in this scope then create and insert
comment|/// DIEs for these variables.
name|DIE
modifier|*
name|updateSubprogramScopeDIE
parameter_list|(
name|MDNode
modifier|*
name|SPNode
parameter_list|)
function_decl|;
comment|/// constructLexicalScope - Construct new DW_TAG_lexical_block
comment|/// for this scope and attach DW_AT_low_pc/DW_AT_high_pc labels.
name|DIE
modifier|*
name|constructLexicalScopeDIE
parameter_list|(
name|DbgScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
comment|/// constructInlinedScopeDIE - This scope represents inlined body of
comment|/// a function. Construct DIE to represent this concrete inlined copy
comment|/// of the function.
name|DIE
modifier|*
name|constructInlinedScopeDIE
parameter_list|(
name|DbgScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
comment|/// constructVariableDIE - Construct a DIE for the given DbgVariable.
name|DIE
modifier|*
name|constructVariableDIE
parameter_list|(
name|DbgVariable
modifier|*
name|DV
parameter_list|,
name|DbgScope
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// constructScopeDIE - Construct a DIE for this scope.
name|DIE
modifier|*
name|constructScopeDIE
parameter_list|(
name|DbgScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
comment|/// emitInitial - Emit initial Dwarf declarations.  This is necessary for cc
comment|/// tools to recognize the object file contains Dwarf information.
name|void
name|emitInitial
parameter_list|()
function_decl|;
comment|/// emitDIE - Recusively Emits a debug information entry.
comment|///
name|void
name|emitDIE
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|)
function_decl|;
comment|/// computeSizeAndOffset - Compute the size and offset of a DIE.
comment|///
name|unsigned
name|computeSizeAndOffset
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Offset
parameter_list|,
name|bool
name|Last
parameter_list|)
function_decl|;
comment|/// computeSizeAndOffsets - Compute the size and offset of all the DIEs.
comment|///
name|void
name|computeSizeAndOffsets
parameter_list|()
function_decl|;
comment|/// EmitDebugInfo - Emit the debug info section.
comment|///
name|void
name|emitDebugInfo
parameter_list|()
function_decl|;
comment|/// emitAbbreviations - Emit the abbreviation section.
comment|///
name|void
name|emitAbbreviations
argument_list|()
specifier|const
expr_stmt|;
comment|/// emitEndOfLineMatrix - Emit the last address of the section and the end of
comment|/// the line matrix.
comment|///
name|void
name|emitEndOfLineMatrix
parameter_list|(
name|unsigned
name|SectionEnd
parameter_list|)
function_decl|;
comment|/// emitDebugLines - Emit source line information.
comment|///
name|void
name|emitDebugLines
parameter_list|()
function_decl|;
comment|/// emitCommonDebugFrame - Emit common frame info into a debug frame section.
comment|///
name|void
name|emitCommonDebugFrame
parameter_list|()
function_decl|;
comment|/// emitFunctionDebugFrame - Emit per function frame info into a debug frame
comment|/// section.
name|void
name|emitFunctionDebugFrame
parameter_list|(
specifier|const
name|FunctionDebugFrameInfo
modifier|&
name|DebugFrameInfo
parameter_list|)
function_decl|;
comment|/// emitDebugPubNames - Emit visible names into a debug pubnames section.
comment|///
name|void
name|emitDebugPubNames
parameter_list|()
function_decl|;
comment|/// emitDebugPubTypes - Emit visible types into a debug pubtypes section.
comment|///
name|void
name|emitDebugPubTypes
parameter_list|()
function_decl|;
comment|/// emitDebugStr - Emit visible names into a debug str section.
comment|///
name|void
name|emitDebugStr
parameter_list|()
function_decl|;
comment|/// emitDebugLoc - Emit visible names into a debug loc section.
comment|///
name|void
name|emitDebugLoc
parameter_list|()
function_decl|;
comment|/// EmitDebugARanges - Emit visible names into a debug aranges section.
comment|///
name|void
name|EmitDebugARanges
parameter_list|()
function_decl|;
comment|/// emitDebugRanges - Emit visible names into a debug ranges section.
comment|///
name|void
name|emitDebugRanges
parameter_list|()
function_decl|;
comment|/// emitDebugMacInfo - Emit visible names into a debug macinfo section.
comment|///
name|void
name|emitDebugMacInfo
parameter_list|()
function_decl|;
comment|/// emitDebugInlineInfo - Emit inline info using following format.
comment|/// Section Header:
comment|/// 1. length of section
comment|/// 2. Dwarf version number
comment|/// 3. address size.
comment|///
comment|/// Entries (one "entry" for each function that was inlined):
comment|///
comment|/// 1. offset into __debug_str section for MIPS linkage name, if exists;
comment|///   otherwise offset into __debug_str for regular function name.
comment|/// 2. offset into __debug_str section for regular function name.
comment|/// 3. an unsigned LEB128 number indicating the number of distinct inlining
comment|/// instances for the function.
comment|///
comment|/// The rest of the entry consists of a {die_offset, low_pc}  pair for each
comment|/// inlined instance; the die_offset points to the inlined_subroutine die in
comment|/// the __debug_info section, and the low_pc is the starting address  for the
comment|///  inlining instance.
name|void
name|emitDebugInlineInfo
parameter_list|()
function_decl|;
comment|/// GetOrCreateSourceID - Look up the source id with the given directory and
comment|/// source file names. If none currently exists, create a new id and insert it
comment|/// in the SourceIds map. This can update DirectoryNames and SourceFileNames maps
comment|/// as well.
name|unsigned
name|GetOrCreateSourceID
parameter_list|(
name|StringRef
name|DirName
parameter_list|,
name|StringRef
name|FileName
parameter_list|)
function_decl|;
name|CompileUnit
modifier|*
name|constructCompileUnit
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
name|void
name|constructGlobalVariableDIE
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
name|void
name|constructSubprogramDIE
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|// FIXME: This should go away in favor of complex addresses.
comment|/// Find the type the programmer originally declared the variable to be
comment|/// and return that type.  Obsolete, use GetComplexAddrType instead.
comment|///
name|DIType
name|getBlockByrefType
argument_list|(
name|DIType
name|Ty
argument_list|,
name|std
operator|::
name|string
name|Name
argument_list|)
decl_stmt|;
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
name|DwarfDebug
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|AsmPrinter
operator|*
name|A
argument_list|,
specifier|const
name|MCAsmInfo
operator|*
name|T
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|DwarfDebug
argument_list|()
expr_stmt|;
comment|/// ShouldEmitDwarfDebug - Returns true if Dwarf debugging declarations should
comment|/// be emitted.
name|bool
name|ShouldEmitDwarfDebug
argument_list|()
specifier|const
block|{
return|return
name|shouldEmit
return|;
block|}
comment|/// beginModule - Emit all Dwarf sections that should come prior to the
comment|/// content.
name|void
name|beginModule
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
name|MachineModuleInfo
modifier|*
name|MMI
parameter_list|)
function_decl|;
comment|/// endModule - Emit all Dwarf sections that should come after the content.
comment|///
name|void
name|endModule
parameter_list|()
function_decl|;
comment|/// beginFunction - Gather pre-function debug information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|void
name|beginFunction
parameter_list|(
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|/// endFunction - Gather and emit post-function debug information.
comment|///
name|void
name|endFunction
parameter_list|(
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|/// recordSourceLine - Records location information and associates it with a
comment|/// label. Returns a unique label ID used to generate a label and provide
comment|/// correspondence to the source line list.
name|unsigned
name|recordSourceLine
parameter_list|(
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Col
parameter_list|,
name|MDNode
modifier|*
name|Scope
parameter_list|)
function_decl|;
comment|/// getSourceLineCount - Return the number of source lines in the debug
comment|/// info.
name|unsigned
name|getSourceLineCount
argument_list|()
specifier|const
block|{
return|return
name|Lines
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// getOrCreateSourceID - Public version of GetOrCreateSourceID. This can be
comment|/// timed. Look up the source id with the given directory and source file
comment|/// names. If none currently exists, create a new id and insert it in the
comment|/// SourceIds map. This can update DirectoryNames and SourceFileNames maps as
comment|/// well.
name|unsigned
name|getOrCreateSourceID
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|DirName
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FileName
argument_list|)
decl_stmt|;
comment|/// extractScopeInformation - Scan machine instructions in this function
comment|/// and collect DbgScopes. Return true, if atleast one scope was found.
name|bool
name|extractScopeInformation
parameter_list|(
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|/// collectVariableInfo - Populate DbgScope entries with variables' info.
name|void
name|collectVariableInfo
parameter_list|()
function_decl|;
comment|/// beginScope - Process beginning of a scope starting at Label.
name|void
name|beginScope
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|unsigned
name|Label
parameter_list|)
function_decl|;
comment|/// endScope - Prcess end of a scope.
name|void
name|endScope
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


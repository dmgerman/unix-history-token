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
name|DbgVariable
decl_stmt|;
name|class
name|DbgScope
decl_stmt|;
name|class
name|DbgConcreteScope
decl_stmt|;
name|class
name|MachineFrameInfo
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|TargetAsmInfo
decl_stmt|;
name|class
name|Timer
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// SrcLineInfo - This class is used to record source line correspondence.
comment|///
name|class
name|VISIBILITY_HIDDEN
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
name|VISIBILITY_HIDDEN
name|DwarfDebug
range|:
name|public
name|Dwarf
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
comment|/// MainCU - Some platform prefers one compile unit per .o file. In such
comment|/// cases, all dies are inserted in MainCU.
name|CompileUnit
operator|*
name|MainCU
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
comment|/// ValuesSet - Used to uniquely define values.
comment|///
name|FoldingSet
operator|<
name|DIEValue
operator|>
name|ValuesSet
block|;
comment|/// Values - A list of all the unique values in use.
comment|///
name|std
operator|::
name|vector
operator|<
name|DIEValue
operator|*
operator|>
name|Values
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
name|Section
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
comment|// FunctionDbgScope - Top level scope for the current function.
comment|//
name|DbgScope
operator|*
name|FunctionDbgScope
block|;
comment|/// DbgScopeMap - Tracks the scopes in the current function.
name|DenseMap
operator|<
name|GlobalVariable
operator|*
block|,
name|DbgScope
operator|*
operator|>
name|DbgScopeMap
block|;
comment|/// DbgAbstractScopeMap - Tracks abstract instance scopes in the current
comment|/// function.
name|DenseMap
operator|<
name|GlobalVariable
operator|*
block|,
name|DbgScope
operator|*
operator|>
name|DbgAbstractScopeMap
block|;
comment|/// DbgConcreteScopeMap - Tracks concrete instance scopes in the current
comment|/// function.
name|DenseMap
operator|<
name|GlobalVariable
operator|*
block|,
name|SmallVector
operator|<
name|DbgScope
operator|*
block|,
literal|8
operator|>
expr|>
name|DbgConcreteScopeMap
block|;
comment|/// InlineInfo - Keep track of inlined functions and their location.  This
comment|/// information is used to populate debug_inlined section.
name|DenseMap
operator|<
name|GlobalVariable
operator|*
block|,
name|SmallVector
operator|<
name|unsigned
block|,
literal|4
operator|>
expr|>
name|InlineInfo
block|;
comment|/// InlinedVariableScopes - Scopes information for the inlined subroutine
comment|/// variables.
name|DenseMap
operator|<
specifier|const
name|MachineInstr
operator|*
block|,
name|DbgScope
operator|*
operator|>
name|InlinedVariableScopes
block|;
comment|/// AbstractInstanceRootMap - Map of abstract instance roots of inlined
comment|/// functions. These are subroutine entries that contain a DW_AT_inline
comment|/// attribute.
name|DenseMap
operator|<
specifier|const
name|GlobalVariable
operator|*
block|,
name|DbgScope
operator|*
operator|>
name|AbstractInstanceRootMap
block|;
comment|/// InlinedParamMap - A map keeping track of which parameters are assigned to
comment|/// which abstract instance.
name|DenseMap
operator|<
specifier|const
name|GlobalVariable
operator|*
block|,
name|SmallSet
operator|<
specifier|const
name|GlobalVariable
operator|*
block|,
literal|32
operator|>
expr|>
name|InlinedParamMap
block|;
comment|/// AbstractInstanceRootList - List of abstract instance roots of inlined
comment|/// functions. These are subroutine entries that contain a DW_AT_inline
comment|/// attribute.
name|SmallVector
operator|<
name|DbgScope
operator|*
block|,
literal|32
operator|>
name|AbstractInstanceRootList
block|;
comment|/// LexicalScopeStack - A stack of lexical scopes. The top one is the current
comment|/// scope.
name|SmallVector
operator|<
name|DbgScope
operator|*
block|,
literal|16
operator|>
name|LexicalScopeStack
block|;
comment|/// CompileUnitOffsets - A vector of the offsets of the compile units. This is
comment|/// used when calculating the "origin" of a concrete instance of an inlined
comment|/// function.
name|DenseMap
operator|<
name|CompileUnit
operator|*
block|,
name|unsigned
operator|>
name|CompileUnitOffsets
block|;
comment|/// DebugTimer - Timer for the Dwarf debug writer.
name|Timer
operator|*
name|DebugTimer
block|;      struct
name|FunctionDebugFrameInfo
block|{
name|unsigned
name|Number
block|;
name|std
operator|::
name|vector
operator|<
name|MachineMove
operator|>
name|Moves
block|;
name|FunctionDebugFrameInfo
argument_list|(
argument|unsigned Num
argument_list|,
argument|const std::vector<MachineMove>&M
argument_list|)
operator|:
name|Number
argument_list|(
name|Num
argument_list|)
block|,
name|Moves
argument_list|(
argument|M
argument_list|)
block|{}
block|}
block|;
name|std
operator|::
name|vector
operator|<
name|FunctionDebugFrameInfo
operator|>
name|DebugFrames
block|;
comment|/// getSourceDirectoryAndFileIds - Return the directory and file ids that
comment|/// maps to the source id. Source id starts at 1.
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
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
comment|/// AssignAbbrevNumber - Define a unique number for the abbreviation.
comment|///
name|void
name|AssignAbbrevNumber
argument_list|(
name|DIEAbbrev
operator|&
name|Abbrev
argument_list|)
block|;
comment|/// CreateDIEEntry - Creates a new DIEEntry to be a proxy for a debug
comment|/// information entry.
name|DIEEntry
operator|*
name|CreateDIEEntry
argument_list|(
name|DIE
operator|*
name|Entry
operator|=
name|NULL
argument_list|)
block|;
comment|/// SetDIEEntry - Set a DIEEntry once the debug information entry is defined.
comment|///
name|void
name|SetDIEEntry
argument_list|(
name|DIEEntry
operator|*
name|Value
argument_list|,
name|DIE
operator|*
name|Entry
argument_list|)
block|;
comment|/// AddUInt - Add an unsigned integer attribute data and value.
comment|///
name|void
name|AddUInt
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Attribute
argument_list|,
argument|unsigned Form
argument_list|,
argument|uint64_t Integer
argument_list|)
block|;
comment|/// AddSInt - Add an signed integer attribute data and value.
comment|///
name|void
name|AddSInt
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Attribute
argument_list|,
argument|unsigned Form
argument_list|,
argument|int64_t Integer
argument_list|)
block|;
comment|/// AddString - Add a string attribute data and value.
comment|///
name|void
name|AddString
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Attribute
argument_list|,
argument|unsigned Form
argument_list|,
argument|const std::string&String
argument_list|)
block|;
comment|/// AddLabel - Add a Dwarf label attribute data and value.
comment|///
name|void
name|AddLabel
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Attribute
argument_list|,
argument|unsigned Form
argument_list|,
argument|const DWLabel&Label
argument_list|)
block|;
comment|/// AddObjectLabel - Add an non-Dwarf label attribute data and value.
comment|///
name|void
name|AddObjectLabel
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Attribute
argument_list|,
argument|unsigned Form
argument_list|,
argument|const std::string&Label
argument_list|)
block|;
comment|/// AddSectionOffset - Add a section offset label attribute data and value.
comment|///
name|void
name|AddSectionOffset
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Attribute
argument_list|,
argument|unsigned Form
argument_list|,
argument|const DWLabel&Label
argument_list|,
argument|const DWLabel&Section
argument_list|,
argument|bool isEH = false
argument_list|,
argument|bool useSet = true
argument_list|)
block|;
comment|/// AddDelta - Add a label delta attribute data and value.
comment|///
name|void
name|AddDelta
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Attribute
argument_list|,
argument|unsigned Form
argument_list|,
argument|const DWLabel&Hi
argument_list|,
argument|const DWLabel&Lo
argument_list|)
block|;
comment|/// AddDIEEntry - Add a DIE attribute data and value.
comment|///
name|void
name|AddDIEEntry
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Attribute
argument_list|,
argument|unsigned Form
argument_list|,
argument|DIE *Entry
argument_list|)
block|{
name|Die
operator|->
name|AddValue
argument_list|(
name|Attribute
argument_list|,
name|Form
argument_list|,
name|CreateDIEEntry
argument_list|(
name|Entry
argument_list|)
argument_list|)
block|;   }
comment|/// AddBlock - Add block data.
comment|///
name|void
name|AddBlock
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Attribute
argument_list|,
argument|unsigned Form
argument_list|,
argument|DIEBlock *Block
argument_list|)
block|;
comment|/// AddSourceLine - Add location information to specified debug information
comment|/// entry.
name|void
name|AddSourceLine
argument_list|(
name|DIE
operator|*
name|Die
argument_list|,
specifier|const
name|DIVariable
operator|*
name|V
argument_list|)
block|;
comment|/// AddSourceLine - Add location information to specified debug information
comment|/// entry.
name|void
name|AddSourceLine
argument_list|(
name|DIE
operator|*
name|Die
argument_list|,
specifier|const
name|DIGlobal
operator|*
name|G
argument_list|)
block|;
name|void
name|AddSourceLine
argument_list|(
name|DIE
operator|*
name|Die
argument_list|,
specifier|const
name|DIType
operator|*
name|Ty
argument_list|)
block|;
comment|/// AddAddress - Add an address attribute to a die based on the location
comment|/// provided.
name|void
name|AddAddress
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Attribute
argument_list|,
argument|const MachineLocation&Location
argument_list|)
block|;
comment|/// AddType - Add a new type attribute to the specified entity.
name|void
name|AddType
argument_list|(
argument|CompileUnit *DW_Unit
argument_list|,
argument|DIE *Entity
argument_list|,
argument|DIType Ty
argument_list|)
block|;
comment|/// ConstructTypeDIE - Construct basic type die from DIBasicType.
name|void
name|ConstructTypeDIE
argument_list|(
argument|CompileUnit *DW_Unit
argument_list|,
argument|DIE&Buffer
argument_list|,
argument|DIBasicType BTy
argument_list|)
block|;
comment|/// ConstructTypeDIE - Construct derived type die from DIDerivedType.
name|void
name|ConstructTypeDIE
argument_list|(
argument|CompileUnit *DW_Unit
argument_list|,
argument|DIE&Buffer
argument_list|,
argument|DIDerivedType DTy
argument_list|)
block|;
comment|/// ConstructTypeDIE - Construct type DIE from DICompositeType.
name|void
name|ConstructTypeDIE
argument_list|(
argument|CompileUnit *DW_Unit
argument_list|,
argument|DIE&Buffer
argument_list|,
argument|DICompositeType CTy
argument_list|)
block|;
comment|/// ConstructSubrangeDIE - Construct subrange DIE from DISubrange.
name|void
name|ConstructSubrangeDIE
argument_list|(
argument|DIE&Buffer
argument_list|,
argument|DISubrange SR
argument_list|,
argument|DIE *IndexTy
argument_list|)
block|;
comment|/// ConstructArrayTypeDIE - Construct array type DIE from DICompositeType.
name|void
name|ConstructArrayTypeDIE
argument_list|(
name|CompileUnit
operator|*
name|DW_Unit
argument_list|,
name|DIE
operator|&
name|Buffer
argument_list|,
name|DICompositeType
operator|*
name|CTy
argument_list|)
block|;
comment|/// ConstructEnumTypeDIE - Construct enum type DIE from DIEnumerator.
name|DIE
operator|*
name|ConstructEnumTypeDIE
argument_list|(
name|CompileUnit
operator|*
name|DW_Unit
argument_list|,
name|DIEnumerator
operator|*
name|ETy
argument_list|)
block|;
comment|/// CreateGlobalVariableDIE - Create new DIE using GV.
name|DIE
operator|*
name|CreateGlobalVariableDIE
argument_list|(
name|CompileUnit
operator|*
name|DW_Unit
argument_list|,
specifier|const
name|DIGlobalVariable
operator|&
name|GV
argument_list|)
block|;
comment|/// CreateMemberDIE - Create new member DIE.
name|DIE
operator|*
name|CreateMemberDIE
argument_list|(
name|CompileUnit
operator|*
name|DW_Unit
argument_list|,
specifier|const
name|DIDerivedType
operator|&
name|DT
argument_list|)
block|;
comment|/// CreateSubprogramDIE - Create new DIE using SP.
name|DIE
operator|*
name|CreateSubprogramDIE
argument_list|(
argument|CompileUnit *DW_Unit
argument_list|,
argument|const DISubprogram&SP
argument_list|,
argument|bool IsConstructor = false
argument_list|,
argument|bool IsInlined = false
argument_list|)
block|;
comment|/// FindCompileUnit - Get the compile unit for the given descriptor.
comment|///
name|CompileUnit
operator|&
name|FindCompileUnit
argument_list|(
argument|DICompileUnit Unit
argument_list|)
specifier|const
block|;
comment|/// CreateDbgScopeVariable - Create a new scope variable.
comment|///
name|DIE
operator|*
name|CreateDbgScopeVariable
argument_list|(
name|DbgVariable
operator|*
name|DV
argument_list|,
name|CompileUnit
operator|*
name|Unit
argument_list|)
block|;
comment|/// getOrCreateScope - Returns the scope associated with the given descriptor.
comment|///
name|DbgScope
operator|*
name|getOrCreateScope
argument_list|(
name|GlobalVariable
operator|*
name|V
argument_list|)
block|;
comment|/// ConstructDbgScope - Construct the components of a scope.
comment|///
name|void
name|ConstructDbgScope
argument_list|(
argument|DbgScope *ParentScope
argument_list|,
argument|unsigned ParentStartID
argument_list|,
argument|unsigned ParentEndID
argument_list|,
argument|DIE *ParentDie
argument_list|,
argument|CompileUnit *Unit
argument_list|)
block|;
comment|/// ConstructFunctionDbgScope - Construct the scope for the subprogram.
comment|///
name|void
name|ConstructFunctionDbgScope
argument_list|(
argument|DbgScope *RootScope
argument_list|,
argument|bool AbstractScope = false
argument_list|)
block|;
comment|/// ConstructDefaultDbgScope - Construct a default scope for the subprogram.
comment|///
name|void
name|ConstructDefaultDbgScope
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// EmitInitial - Emit initial Dwarf declarations.  This is necessary for cc
comment|/// tools to recognize the object file contains Dwarf information.
name|void
name|EmitInitial
argument_list|()
block|;
comment|/// EmitDIE - Recusively Emits a debug information entry.
comment|///
name|void
name|EmitDIE
argument_list|(
name|DIE
operator|*
name|Die
argument_list|)
block|;
comment|/// SizeAndOffsetDie - Compute the size and offset of a DIE.
comment|///
name|unsigned
name|SizeAndOffsetDie
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Offset
argument_list|,
argument|bool Last
argument_list|)
block|;
comment|/// SizeAndOffsets - Compute the size and offset of all the DIEs.
comment|///
name|void
name|SizeAndOffsets
argument_list|()
block|;
comment|/// EmitDebugInfo / EmitDebugInfoPerCU - Emit the debug info section.
comment|///
name|void
name|EmitDebugInfoPerCU
argument_list|(
name|CompileUnit
operator|*
name|Unit
argument_list|)
block|;
name|void
name|EmitDebugInfo
argument_list|()
block|;
comment|/// EmitAbbreviations - Emit the abbreviation section.
comment|///
name|void
name|EmitAbbreviations
argument_list|()
specifier|const
block|;
comment|/// EmitEndOfLineMatrix - Emit the last address of the section and the end of
comment|/// the line matrix.
comment|///
name|void
name|EmitEndOfLineMatrix
argument_list|(
argument|unsigned SectionEnd
argument_list|)
block|;
comment|/// EmitDebugLines - Emit source line information.
comment|///
name|void
name|EmitDebugLines
argument_list|()
block|;
comment|/// EmitCommonDebugFrame - Emit common frame info into a debug frame section.
comment|///
name|void
name|EmitCommonDebugFrame
argument_list|()
block|;
comment|/// EmitFunctionDebugFrame - Emit per function frame info into a debug frame
comment|/// section.
name|void
name|EmitFunctionDebugFrame
argument_list|(
specifier|const
name|FunctionDebugFrameInfo
operator|&
name|DebugFrameInfo
argument_list|)
block|;
name|void
name|EmitDebugPubNamesPerCU
argument_list|(
name|CompileUnit
operator|*
name|Unit
argument_list|)
block|;
comment|/// EmitDebugPubNames - Emit visible names into a debug pubnames section.
comment|///
name|void
name|EmitDebugPubNames
argument_list|()
block|;
comment|/// EmitDebugStr - Emit visible names into a debug str section.
comment|///
name|void
name|EmitDebugStr
argument_list|()
block|;
comment|/// EmitDebugLoc - Emit visible names into a debug loc section.
comment|///
name|void
name|EmitDebugLoc
argument_list|()
block|;
comment|/// EmitDebugARanges - Emit visible names into a debug aranges section.
comment|///
name|void
name|EmitDebugARanges
argument_list|()
block|;
comment|/// EmitDebugRanges - Emit visible names into a debug ranges section.
comment|///
name|void
name|EmitDebugRanges
argument_list|()
block|;
comment|/// EmitDebugMacInfo - Emit visible names into a debug macinfo section.
comment|///
name|void
name|EmitDebugMacInfo
argument_list|()
block|;
comment|/// EmitDebugInlineInfo - Emit inline info using following format.
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
name|EmitDebugInlineInfo
argument_list|()
block|;
comment|/// GetOrCreateSourceID - Look up the source id with the given directory and
comment|/// source file names. If none currently exists, create a new id and insert it
comment|/// in the SourceIds map. This can update DirectoryNames and SourceFileNames maps
comment|/// as well.
name|unsigned
name|GetOrCreateSourceID
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
block|;
name|void
name|ConstructCompileUnit
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
comment|/// ConstructCompileUnits - Create a compile unit DIEs.
name|void
name|ConstructCompileUnits
argument_list|()
block|;
name|bool
name|ConstructGlobalVariableDIE
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
comment|/// ConstructGlobalVariableDIEs - Create DIEs for each of the externally
comment|/// visible global variables. Return true if at least one global DIE is
comment|/// created.
name|bool
name|ConstructGlobalVariableDIEs
argument_list|()
block|;
name|bool
name|ConstructSubprogram
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
comment|/// ConstructSubprograms - Create DIEs for each of the externally visible
comment|/// subprograms. Return true if at least one subprogram DIE is created.
name|bool
name|ConstructSubprograms
argument_list|()
block|;
name|public
operator|:
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
name|TargetAsmInfo
operator|*
name|T
argument_list|)
block|;
name|virtual
operator|~
name|DwarfDebug
argument_list|()
block|;
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
comment|/// SetDebugInfo - Create global DIEs and emit initial debug info sections.
comment|/// This is inovked by the target AsmPrinter.
name|void
name|SetDebugInfo
argument_list|(
name|MachineModuleInfo
operator|*
name|mmi
argument_list|)
block|;
comment|/// BeginModule - Emit all Dwarf sections that should come prior to the
comment|/// content.
name|void
name|BeginModule
argument_list|(
argument|Module *M
argument_list|)
block|{
name|this
operator|->
name|M
operator|=
name|M
block|;   }
comment|/// EndModule - Emit all Dwarf sections that should come after the content.
comment|///
name|void
name|EndModule
argument_list|()
block|;
comment|/// BeginFunction - Gather pre-function debug information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|void
name|BeginFunction
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// EndFunction - Gather and emit post-function debug information.
comment|///
name|void
name|EndFunction
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// RecordSourceLine - Records location information and associates it with a
comment|/// label. Returns a unique label ID used to generate a label and provide
comment|/// correspondence to the source line list.
name|unsigned
name|RecordSourceLine
argument_list|(
argument|Value *V
argument_list|,
argument|unsigned Line
argument_list|,
argument|unsigned Col
argument_list|)
block|;
comment|/// RecordSourceLine - Records location information and associates it with a
comment|/// label. Returns a unique label ID used to generate a label and provide
comment|/// correspondence to the source line list.
name|unsigned
name|RecordSourceLine
argument_list|(
argument|unsigned Line
argument_list|,
argument|unsigned Col
argument_list|,
argument|DICompileUnit CU
argument_list|)
block|;
comment|/// getRecordSourceLineCount - Return the number of source lines in the debug
comment|/// info.
name|unsigned
name|getRecordSourceLineCount
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
block|;
comment|/// RecordRegionStart - Indicate the start of a region.
name|unsigned
name|RecordRegionStart
argument_list|(
name|GlobalVariable
operator|*
name|V
argument_list|)
block|;
comment|/// RecordRegionEnd - Indicate the end of a region.
name|unsigned
name|RecordRegionEnd
argument_list|(
name|GlobalVariable
operator|*
name|V
argument_list|)
block|;
comment|/// RecordVariable - Indicate the declaration of  a local variable.
name|void
name|RecordVariable
argument_list|(
argument|GlobalVariable *GV
argument_list|,
argument|unsigned FrameIndex
argument_list|,
argument|const MachineInstr *MI
argument_list|)
block|;
comment|//// RecordInlinedFnStart - Indicate the start of inlined subroutine.
name|unsigned
name|RecordInlinedFnStart
argument_list|(
argument|DISubprogram&SP
argument_list|,
argument|DICompileUnit CU
argument_list|,
argument|unsigned Line
argument_list|,
argument|unsigned Col
argument_list|)
block|;
comment|/// RecordInlinedFnEnd - Indicate the end of inlined subroutine.
name|unsigned
name|RecordInlinedFnEnd
argument_list|(
name|DISubprogram
operator|&
name|SP
argument_list|)
block|;
comment|/// RecordVariableScope - Record scope for the variable declared by
comment|/// DeclareMI. DeclareMI must describe TargetInstrInfo::DECLARE. Record scopes
comment|/// for only inlined subroutine variables. Other variables's scopes are
comment|/// determined during RecordVariable().
name|void
name|RecordVariableScope
argument_list|(
name|DIVariable
operator|&
name|DV
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|DeclareMI
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


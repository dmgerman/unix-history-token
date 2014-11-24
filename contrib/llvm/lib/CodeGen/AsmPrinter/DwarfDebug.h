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
file|"DwarfFile.h"
end_include

begin_include
include|#
directive|include
file|"AsmPrinterHandler.h"
end_include

begin_include
include|#
directive|include
file|"DIE.h"
end_include

begin_include
include|#
directive|include
file|"DbgValueHistoryCalculator.h"
end_include

begin_include
include|#
directive|include
file|"DebugLocEntry.h"
end_include

begin_include
include|#
directive|include
file|"DebugLocList.h"
end_include

begin_include
include|#
directive|include
file|"DwarfAccelTable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LexicalScopes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MachineLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|ByteStreamer
decl_stmt|;
name|class
name|ConstantInt
decl_stmt|;
name|class
name|ConstantFP
decl_stmt|;
name|class
name|DwarfCompileUnit
decl_stmt|;
name|class
name|DwarfDebug
decl_stmt|;
name|class
name|DwarfTypeUnit
decl_stmt|;
name|class
name|DwarfUnit
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// \brief This class is used to record source line correspondence.
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
name|MCSymbol
modifier|*
name|Label
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
argument|MCSymbol *label
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
name|Label
argument_list|(
argument|label
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
name|MCSymbol
operator|*
name|getLabel
argument_list|()
specifier|const
block|{
return|return
name|Label
return|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// \brief This class is used to track local variable information.
name|class
name|DbgVariable
block|{
name|DIVariable
name|Var
decl_stmt|;
comment|// Variable Descriptor.
name|DIE
modifier|*
name|TheDIE
decl_stmt|;
comment|// Variable DIE.
name|unsigned
name|DotDebugLocOffset
decl_stmt|;
comment|// Offset in DotDebugLocEntries.
specifier|const
name|MachineInstr
modifier|*
name|MInsn
decl_stmt|;
comment|// DBG_VALUE instruction of the variable.
name|int
name|FrameIndex
decl_stmt|;
name|DwarfDebug
modifier|*
name|DD
decl_stmt|;
name|public
label|:
comment|/// Construct a DbgVariable from a DIVariable.
name|DbgVariable
argument_list|(
argument|DIVariable V
argument_list|,
argument|DwarfDebug *DD
argument_list|)
block|:
name|Var
argument_list|(
name|V
argument_list|)
operator|,
name|TheDIE
argument_list|(
name|nullptr
argument_list|)
operator|,
name|DotDebugLocOffset
argument_list|(
operator|~
literal|0U
argument_list|)
operator|,
name|MInsn
argument_list|(
name|nullptr
argument_list|)
operator|,
name|FrameIndex
argument_list|(
operator|~
literal|0
argument_list|)
operator|,
name|DD
argument_list|(
argument|DD
argument_list|)
block|{}
comment|/// Construct a DbgVariable from a DEBUG_VALUE.
comment|/// AbstractVar may be NULL.
name|DbgVariable
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|DbgValue
argument_list|,
name|DwarfDebug
operator|*
name|DD
argument_list|)
operator|:
name|Var
argument_list|(
name|DbgValue
operator|->
name|getDebugVariable
argument_list|()
argument_list|)
operator|,
name|TheDIE
argument_list|(
name|nullptr
argument_list|)
operator|,
name|DotDebugLocOffset
argument_list|(
operator|~
literal|0U
argument_list|)
operator|,
name|MInsn
argument_list|(
name|DbgValue
argument_list|)
operator|,
name|FrameIndex
argument_list|(
operator|~
literal|0
argument_list|)
operator|,
name|DD
argument_list|(
argument|DD
argument_list|)
block|{}
comment|// Accessors.
name|DIVariable
name|getVariable
argument_list|()
specifier|const
block|{
return|return
name|Var
return|;
block|}
name|void
name|setDIE
parameter_list|(
name|DIE
modifier|&
name|D
parameter_list|)
block|{
name|TheDIE
operator|=
operator|&
name|D
expr_stmt|;
block|}
name|DIE
operator|*
name|getDIE
argument_list|()
specifier|const
block|{
return|return
name|TheDIE
return|;
block|}
name|void
name|setDotDebugLocOffset
parameter_list|(
name|unsigned
name|O
parameter_list|)
block|{
name|DotDebugLocOffset
operator|=
name|O
expr_stmt|;
block|}
name|unsigned
name|getDotDebugLocOffset
argument_list|()
specifier|const
block|{
return|return
name|DotDebugLocOffset
return|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Var
operator|.
name|getName
argument_list|()
return|;
block|}
specifier|const
name|MachineInstr
operator|*
name|getMInsn
argument_list|()
specifier|const
block|{
return|return
name|MInsn
return|;
block|}
name|int
name|getFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|FrameIndex
return|;
block|}
name|void
name|setFrameIndex
parameter_list|(
name|int
name|FI
parameter_list|)
block|{
name|FrameIndex
operator|=
name|FI
expr_stmt|;
block|}
comment|// Translate tag to proper Dwarf tag.
name|dwarf
operator|::
name|Tag
name|getTag
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Var
operator|.
name|getTag
argument_list|()
operator|==
name|dwarf
operator|::
name|DW_TAG_arg_variable
condition|)
return|return
name|dwarf
operator|::
name|DW_TAG_formal_parameter
return|;
return|return
name|dwarf
operator|::
name|DW_TAG_variable
return|;
block|}
comment|/// \brief Return true if DbgVariable is artificial.
name|bool
name|isArtificial
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Var
operator|.
name|isArtificial
argument_list|()
condition|)
return|return
name|true
return|;
if|if
condition|(
name|getType
argument_list|()
operator|.
name|isArtificial
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|isObjectPointer
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Var
operator|.
name|isObjectPointer
argument_list|()
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|getType
argument_list|()
operator|.
name|isObjectPointer
argument_list|()
condition|)
return|return
name|true
return|;
end_if

begin_return
return|return
name|false
return|;
end_return

begin_macro
unit|}    bool
name|variableHasComplexAddress
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
name|assert
argument_list|(
name|Var
operator|.
name|isVariable
argument_list|()
operator|&&
literal|"Invalid complex DbgVariable!"
argument_list|)
block|;
return|return
name|Var
operator|.
name|hasComplexAddress
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isBlockByrefVariable
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getNumAddrElements
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Var
operator|.
name|isVariable
argument_list|()
operator|&&
literal|"Invalid complex DbgVariable!"
argument_list|)
block|;
return|return
name|Var
operator|.
name|getNumAddrElements
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|uint64_t
name|getAddrElement
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
return|return
name|Var
operator|.
name|getAddrElement
argument_list|(
name|i
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|DIType
name|getType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

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
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Helper used to pair up a symbol and its DWARF compile unit.
end_comment

begin_struct
struct|struct
name|SymbolCU
block|{
name|SymbolCU
argument_list|(
name|DwarfCompileUnit
operator|*
name|CU
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Sym
argument_list|)
operator|:
name|Sym
argument_list|(
name|Sym
argument_list|)
operator|,
name|CU
argument_list|(
argument|CU
argument_list|)
block|{}
specifier|const
name|MCSymbol
operator|*
name|Sym
expr_stmt|;
name|DwarfCompileUnit
modifier|*
name|CU
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// \brief Collects and handles dwarf debug information.
end_comment

begin_decl_stmt
name|class
name|DwarfDebug
range|:
name|public
name|AsmPrinterHandler
block|{
comment|// Target of Dwarf emission.
name|AsmPrinter
operator|*
name|Asm
block|;
comment|// Collected machine module information.
name|MachineModuleInfo
operator|*
name|MMI
block|;
comment|// All DIEValues are allocated through this allocator.
name|BumpPtrAllocator
name|DIEValueAllocator
block|;
comment|// Handle to the compile unit used for the inline extension handling,
comment|// this is just so that the DIEValue allocator has a place to store
comment|// the particular elements.
comment|// FIXME: Store these off of DwarfDebug instead?
name|DwarfCompileUnit
operator|*
name|FirstCU
block|;
comment|// Maps MDNode with its corresponding DwarfCompileUnit.
name|MapVector
operator|<
specifier|const
name|MDNode
operator|*
block|,
name|DwarfCompileUnit
operator|*
operator|>
name|CUMap
block|;
comment|// Maps subprogram MDNode with its corresponding DwarfCompileUnit.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
block|,
name|DwarfCompileUnit
operator|*
operator|>
name|SPMap
block|;
comment|// Maps a CU DIE with its corresponding DwarfCompileUnit.
name|DenseMap
operator|<
specifier|const
name|DIE
operator|*
block|,
name|DwarfCompileUnit
operator|*
operator|>
name|CUDieMap
block|;
comment|/// Maps MDNodes for type system with the corresponding DIEs. These DIEs can
comment|/// be shared across CUs, that is why we keep the map here instead
comment|/// of in DwarfCompileUnit.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
block|,
name|DIE
operator|*
operator|>
name|MDTypeNodeToDieMap
block|;
comment|// List of all labels used in aranges generation.
name|std
operator|::
name|vector
operator|<
name|SymbolCU
operator|>
name|ArangeLabels
block|;
comment|// Size of each symbol emitted (for those symbols that have a specific size).
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
block|,
name|uint64_t
operator|>
name|SymSize
block|;
comment|// Provides a unique id per text section.
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|MCSection
operator|*
operator|,
name|SmallVector
operator|<
name|SymbolCU
operator|,
literal|8
operator|>
expr|>
name|SectionMapType
expr_stmt|;
name|SectionMapType
name|SectionMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|// List of arguments for current function.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|DbgVariable
operator|*
operator|,
literal|8
operator|>
name|CurrentFnArguments
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|LexicalScopes
name|LScopes
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Collection of abstract subprogram DIEs.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DIE
operator|*
operator|>
name|AbstractSPDies
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Collection of dbg variables of a scope.
end_comment

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|LexicalScope
operator|*
operator|,
name|SmallVector
operator|<
name|DbgVariable
operator|*
operator|,
literal|8
operator|>
expr|>
name|ScopeVariablesMap
expr_stmt|;
end_typedef

begin_decl_stmt
name|ScopeVariablesMap
name|ScopeVariables
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Collection of abstract variables.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|DbgVariable
operator|>>
name|AbstractVariables
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DbgVariable
operator|>
operator|,
literal|64
operator|>
name|ConcreteVariables
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Collection of DebugLocEntry. Stored in a linked list so that DIELocLists
end_comment

begin_comment
comment|// can refer to them in spite of insertions into this list.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|DebugLocList
operator|,
literal|4
operator|>
name|DotDebugLocEntries
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Collection of subprogram DIEs that are marked (at the end of the module)
end_comment

begin_comment
comment|// as DW_AT_inline.
end_comment

begin_expr_stmt
name|SmallPtrSet
operator|<
name|DIE
operator|*
operator|,
literal|4
operator|>
name|InlinedSubprogramDIEs
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This is a collection of subprogram MDNodes that are processed to
end_comment

begin_comment
comment|// create DIEs.
end_comment

begin_expr_stmt
name|SmallPtrSet
operator|<
specifier|const
name|MDNode
operator|*
operator|,
literal|16
operator|>
name|ProcessedSPNodes
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Maps instruction with label emitted before instruction.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|MachineInstr
operator|*
operator|,
name|MCSymbol
operator|*
operator|>
name|LabelsBeforeInsn
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Maps instruction with label emitted after instruction.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|MachineInstr
operator|*
operator|,
name|MCSymbol
operator|*
operator|>
name|LabelsAfterInsn
expr_stmt|;
end_expr_stmt

begin_comment
comment|// History of DBG_VALUE and clobber instructions for each user variable.
end_comment

begin_comment
comment|// Variables are listed in order of appearance.
end_comment

begin_decl_stmt
name|DbgValueHistoryMap
name|DbgValues
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Previous instruction's location information. This is used to determine
end_comment

begin_comment
comment|// label location to indicate scope boundries in dwarf debug info.
end_comment

begin_decl_stmt
name|DebugLoc
name|PrevInstLoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCSymbol
modifier|*
name|PrevLabel
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This location indicates end of function prologue and beginning of function
end_comment

begin_comment
comment|// body.
end_comment

begin_decl_stmt
name|DebugLoc
name|PrologEndLoc
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If nonnull, stores the current machine function we're processing.
end_comment

begin_decl_stmt
specifier|const
name|MachineFunction
modifier|*
name|CurFn
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If nonnull, stores the current machine instruction we're processing.
end_comment

begin_decl_stmt
specifier|const
name|MachineInstr
modifier|*
name|CurMI
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If nonnull, stores the section that the previous function was allocated to
end_comment

begin_comment
comment|// emitting.
end_comment

begin_decl_stmt
specifier|const
name|MCSection
modifier|*
name|PrevSection
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If nonnull, stores the CU in which the previous subprogram was contained.
end_comment

begin_decl_stmt
specifier|const
name|DwarfCompileUnit
modifier|*
name|PrevCU
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Section Symbols: these are assembler temporary labels that are emitted at
end_comment

begin_comment
comment|// the beginning of each supported dwarf section.  These are used to form
end_comment

begin_comment
comment|// section offsets and are created by EmitSectionLabels.
end_comment

begin_decl_stmt
name|MCSymbol
modifier|*
name|DwarfInfoSectionSym
decl_stmt|,
modifier|*
name|DwarfAbbrevSectionSym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCSymbol
modifier|*
name|DwarfStrSectionSym
decl_stmt|,
modifier|*
name|TextSectionSym
decl_stmt|,
modifier|*
name|DwarfDebugRangeSectionSym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCSymbol
modifier|*
name|DwarfDebugLocSectionSym
decl_stmt|,
modifier|*
name|DwarfLineSectionSym
decl_stmt|,
modifier|*
name|DwarfAddrSectionSym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCSymbol
modifier|*
name|FunctionBeginSym
decl_stmt|,
modifier|*
name|FunctionEndSym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCSymbol
modifier|*
name|DwarfInfoDWOSectionSym
decl_stmt|,
modifier|*
name|DwarfAbbrevDWOSectionSym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCSymbol
modifier|*
name|DwarfStrDWOSectionSym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCSymbol
modifier|*
name|DwarfGnuPubNamesSectionSym
decl_stmt|,
modifier|*
name|DwarfGnuPubTypesSectionSym
decl_stmt|;
end_decl_stmt

begin_comment
comment|// As an optimization, there is no need to emit an entry in the directory
end_comment

begin_comment
comment|// table for the same directory as DW_AT_comp_dir.
end_comment

begin_decl_stmt
name|StringRef
name|CompilationDir
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Counter for assigning globally unique IDs for ranges.
end_comment

begin_decl_stmt
name|unsigned
name|GlobalRangeCount
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Holder for the file specific debug information.
end_comment

begin_decl_stmt
name|DwarfFile
name|InfoHolder
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Holders for the various debug information flags that we might need to
end_comment

begin_comment
comment|// have exposed. See accessor functions below for description.
end_comment

begin_comment
comment|// Holder for imported entities.
end_comment

begin_typedef
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|MDNode
operator|*
operator|,
specifier|const
name|MDNode
operator|*
operator|>
operator|,
literal|32
operator|>
name|ImportedEntityMap
expr_stmt|;
end_typedef

begin_decl_stmt
name|ImportedEntityMap
name|ScopesWithImportedEntities
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Map from MDNodes for user-defined types to the type units that describe
end_comment

begin_comment
comment|// them.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
specifier|const
name|DwarfTypeUnit
operator|*
operator|>
name|DwarfTypeUnits
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DwarfTypeUnit
operator|>
operator|,
name|DICompositeType
operator|>
operator|,
literal|1
operator|>
name|TypeUnitsUnderConstruction
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Whether to emit the pubnames/pubtypes sections.
end_comment

begin_decl_stmt
name|bool
name|HasDwarfPubSections
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether or not to use AT_ranges for compilation units.
end_comment

begin_decl_stmt
name|bool
name|HasCURanges
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether we emitted a function into a section other than the default
end_comment

begin_comment
comment|// text.
end_comment

begin_decl_stmt
name|bool
name|UsedNonDefaultText
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Version of dwarf we're emitting.
end_comment

begin_decl_stmt
name|unsigned
name|DwarfVersion
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Maps from a type identifier to the actual MDNode.
end_comment

begin_decl_stmt
name|DITypeIdentifierMap
name|TypeIdentifierMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|// DWARF5 Experimental Options
end_comment

begin_decl_stmt
name|bool
name|HasDwarfAccelTables
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|HasSplitDwarf
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Separated Dwarf Variables
end_comment

begin_comment
comment|// In general these will all be for bits that are left in the
end_comment

begin_comment
comment|// original object file, rather than things that are meant
end_comment

begin_comment
comment|// to be in the .dwo sections.
end_comment

begin_comment
comment|// Holder for the skeleton information.
end_comment

begin_decl_stmt
name|DwarfFile
name|SkeletonHolder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Store file names for type units under fission in a line table header that
end_comment

begin_comment
comment|/// will be emitted into debug_line.dwo.
end_comment

begin_comment
comment|// FIXME: replace this with a map from comp_dir to table so that we can emit
end_comment

begin_comment
comment|// multiple tables during LTO each of which uses directory 0, referencing the
end_comment

begin_comment
comment|// comp_dir of all the type units that use it.
end_comment

begin_decl_stmt
name|MCDwarfDwoLineTable
name|SplitTypeUnitFileTable
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True iff there are multiple CUs in this module.
end_comment

begin_decl_stmt
name|bool
name|SingleCU
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AddressPool
name|AddrPool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DwarfAccelTable
name|AccelNames
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DwarfAccelTable
name|AccelObjC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DwarfAccelTable
name|AccelNamespace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DwarfAccelTable
name|AccelTypes
decl_stmt|;
end_decl_stmt

begin_function_decl
name|MCDwarfDwoLineTable
modifier|*
name|getDwoLineTable
parameter_list|(
specifier|const
name|DwarfCompileUnit
modifier|&
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addScopeVariable
parameter_list|(
name|LexicalScope
modifier|*
name|LS
parameter_list|,
name|DbgVariable
modifier|*
name|Var
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|SmallVectorImpl
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DwarfUnit
operator|>>
operator|&
name|getUnits
argument_list|()
block|{
return|return
name|InfoHolder
operator|.
name|getUnits
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Find abstract variable associated with Var.
end_comment

begin_function_decl
name|DbgVariable
modifier|*
name|getExistingAbstractVariable
parameter_list|(
specifier|const
name|DIVariable
modifier|&
name|DV
parameter_list|,
name|DIVariable
modifier|&
name|Cleansed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DbgVariable
modifier|*
name|getExistingAbstractVariable
parameter_list|(
specifier|const
name|DIVariable
modifier|&
name|DV
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|createAbstractVariable
parameter_list|(
specifier|const
name|DIVariable
modifier|&
name|DV
parameter_list|,
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ensureAbstractVariableIsCreated
parameter_list|(
specifier|const
name|DIVariable
modifier|&
name|Var
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Scope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ensureAbstractVariableIsCreatedIfScoped
parameter_list|(
specifier|const
name|DIVariable
modifier|&
name|Var
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Scope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Find DIE for the given subprogram and attach appropriate
end_comment

begin_comment
comment|/// DW_AT_low_pc and DW_AT_high_pc attributes. If there are global
end_comment

begin_comment
comment|/// variables in this scope then create and insert DIEs for these
end_comment

begin_comment
comment|/// variables.
end_comment

begin_function_decl
name|DIE
modifier|&
name|updateSubprogramScopeDIE
parameter_list|(
name|DwarfCompileUnit
modifier|&
name|SPCU
parameter_list|,
name|DISubprogram
name|SP
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief A helper function to check whether the DIE for a given Scope is
end_comment

begin_comment
comment|/// going to be null.
end_comment

begin_function_decl
name|bool
name|isLexicalScopeDIENull
parameter_list|(
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief A helper function to construct a RangeSpanList for a given
end_comment

begin_comment
comment|/// lexical scope.
end_comment

begin_decl_stmt
name|void
name|addScopeRangeList
argument_list|(
name|DwarfCompileUnit
operator|&
name|TheCU
argument_list|,
name|DIE
operator|&
name|ScopeDIE
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|InsnRange
operator|>
operator|&
name|Range
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Construct new DW_TAG_lexical_block for this scope and
end_comment

begin_comment
comment|/// attach DW_AT_low_pc/DW_AT_high_pc labels.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>
name|constructLexicalScopeDIE
argument_list|(
name|DwarfCompileUnit
operator|&
name|TheCU
argument_list|,
name|LexicalScope
operator|*
name|Scope
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief This scope represents inlined body of a function. Construct
end_comment

begin_comment
comment|/// DIE to represent this concrete inlined copy of the function.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>
name|constructInlinedScopeDIE
argument_list|(
name|DwarfCompileUnit
operator|&
name|TheCU
argument_list|,
name|LexicalScope
operator|*
name|Scope
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Construct a DIE for this scope.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|DIE
operator|>
name|constructScopeDIE
argument_list|(
name|DwarfCompileUnit
operator|&
name|TheCU
argument_list|,
name|LexicalScope
operator|*
name|Scope
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|createAndAddScopeChildren
parameter_list|(
name|DwarfCompileUnit
modifier|&
name|TheCU
parameter_list|,
name|LexicalScope
modifier|*
name|Scope
parameter_list|,
name|DIE
modifier|&
name|ScopeDIE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Construct a DIE for this abstract scope.
end_comment

begin_function_decl
name|void
name|constructAbstractSubprogramScopeDIE
parameter_list|(
name|DwarfCompileUnit
modifier|&
name|TheCU
parameter_list|,
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Construct a DIE for this subprogram scope.
end_comment

begin_function_decl
name|DIE
modifier|&
name|constructSubprogramScopeDIE
parameter_list|(
name|DwarfCompileUnit
modifier|&
name|TheCU
parameter_list|,
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// A helper function to create children of a Scope DIE.
end_comment

begin_decl_stmt
name|DIE
modifier|*
name|createScopeChildrenDIE
argument_list|(
name|DwarfCompileUnit
operator|&
name|TheCU
argument_list|,
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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit initial Dwarf sections with a label at the start of each one.
end_comment

begin_function_decl
name|void
name|emitSectionLabels
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Compute the size and offset of a DIE given an incoming Offset.
end_comment

begin_function_decl
name|unsigned
name|computeSizeAndOffset
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Compute the size and offset of all the DIEs.
end_comment

begin_function_decl
name|void
name|computeSizeAndOffsets
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Collect info for variables that were optimized out.
end_comment

begin_function_decl
name|void
name|collectDeadVariables
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finishVariableDefinitions
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finishSubprogramDefinitions
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Finish off debug information after all functions have been
end_comment

begin_comment
comment|/// processed.
end_comment

begin_function_decl
name|void
name|finalizeModuleInfo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit labels to close any remaining sections that have been left
end_comment

begin_comment
comment|/// open.
end_comment

begin_function_decl
name|void
name|endSections
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the debug info section.
end_comment

begin_function_decl
name|void
name|emitDebugInfo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the abbreviation section.
end_comment

begin_function_decl
name|void
name|emitAbbreviations
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the last address of the section and the end of
end_comment

begin_comment
comment|/// the line matrix.
end_comment

begin_function_decl
name|void
name|emitEndOfLineMatrix
parameter_list|(
name|unsigned
name|SectionEnd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit visible names into a hashed accelerator table section.
end_comment

begin_function_decl
name|void
name|emitAccelNames
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit objective C classes and categories into a hashed
end_comment

begin_comment
comment|/// accelerator table section.
end_comment

begin_function_decl
name|void
name|emitAccelObjC
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit namespace dies into a hashed accelerator table.
end_comment

begin_function_decl
name|void
name|emitAccelNamespaces
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit type dies into a hashed accelerator table.
end_comment

begin_function_decl
name|void
name|emitAccelTypes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit visible names into a debug pubnames section.
end_comment

begin_comment
comment|/// \param GnuStyle determines whether or not we want to emit
end_comment

begin_comment
comment|/// additional information into the table ala newer gcc for gdb
end_comment

begin_comment
comment|/// index.
end_comment

begin_function_decl
name|void
name|emitDebugPubNames
parameter_list|(
name|bool
name|GnuStyle
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit visible types into a debug pubtypes section.
end_comment

begin_comment
comment|/// \param GnuStyle determines whether or not we want to emit
end_comment

begin_comment
comment|/// additional information into the table ala newer gcc for gdb
end_comment

begin_comment
comment|/// index.
end_comment

begin_function_decl
name|void
name|emitDebugPubTypes
parameter_list|(
name|bool
name|GnuStyle
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|emitDebugPubSection
argument_list|(
name|bool
name|GnuStyle
argument_list|,
specifier|const
name|MCSection
operator|*
name|PSec
argument_list|,
name|StringRef
name|Name
argument_list|,
specifier|const
name|StringMap
operator|<
specifier|const
name|DIE
operator|*
operator|>
operator|&
operator|(
name|DwarfUnit
operator|::
operator|*
name|Accessor
operator|)
operator|(
operator|)
specifier|const
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit visible names into a debug str section.
end_comment

begin_function_decl
name|void
name|emitDebugStr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit visible names into a debug loc section.
end_comment

begin_function_decl
name|void
name|emitDebugLoc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit visible names into a debug loc dwo section.
end_comment

begin_function_decl
name|void
name|emitDebugLocDWO
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit visible names into a debug aranges section.
end_comment

begin_function_decl
name|void
name|emitDebugARanges
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit visible names into a debug ranges section.
end_comment

begin_function_decl
name|void
name|emitDebugRanges
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit inline info using custom format.
end_comment

begin_function_decl
name|void
name|emitDebugInlineInfo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// DWARF 5 Experimental Split Dwarf Emitters
end_comment

begin_comment
comment|/// \brief Initialize common features of skeleton units.
end_comment

begin_decl_stmt
name|void
name|initSkeletonUnit
argument_list|(
specifier|const
name|DwarfUnit
operator|&
name|U
argument_list|,
name|DIE
operator|&
name|Die
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|DwarfUnit
operator|>
name|NewU
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Construct the split debug info compile unit for the debug info
end_comment

begin_comment
comment|/// section.
end_comment

begin_function_decl
name|DwarfCompileUnit
modifier|&
name|constructSkeletonCU
parameter_list|(
specifier|const
name|DwarfCompileUnit
modifier|&
name|CU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Construct the split debug info compile unit for the debug info
end_comment

begin_comment
comment|/// section.
end_comment

begin_function_decl
name|DwarfTypeUnit
modifier|&
name|constructSkeletonTU
parameter_list|(
name|DwarfTypeUnit
modifier|&
name|TU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the debug info dwo section.
end_comment

begin_function_decl
name|void
name|emitDebugInfoDWO
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the debug abbrev dwo section.
end_comment

begin_function_decl
name|void
name|emitDebugAbbrevDWO
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the debug line dwo section.
end_comment

begin_function_decl
name|void
name|emitDebugLineDWO
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the debug str dwo section.
end_comment

begin_function_decl
name|void
name|emitDebugStrDWO
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Flags to let the linker know we have emitted new style pubnames. Only
end_comment

begin_comment
comment|/// emit it here if we don't have a skeleton CU for split dwarf.
end_comment

begin_decl_stmt
name|void
name|addGnuPubAttributes
argument_list|(
name|DwarfUnit
operator|&
name|U
argument_list|,
name|DIE
operator|&
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Create new DwarfCompileUnit for the given metadata node with tag
end_comment

begin_comment
comment|/// DW_TAG_compile_unit.
end_comment

begin_function_decl
name|DwarfCompileUnit
modifier|&
name|constructDwarfCompileUnit
parameter_list|(
name|DICompileUnit
name|DIUnit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Construct imported_module or imported_declaration DIE.
end_comment

begin_function_decl
name|void
name|constructImportedEntityDIE
parameter_list|(
name|DwarfCompileUnit
modifier|&
name|TheCU
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Construct import_module DIE.
end_comment

begin_function_decl
name|void
name|constructImportedEntityDIE
parameter_list|(
name|DwarfCompileUnit
modifier|&
name|TheCU
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|,
name|DIE
modifier|&
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Construct import_module DIE.
end_comment

begin_function_decl
name|void
name|constructImportedEntityDIE
parameter_list|(
name|DwarfCompileUnit
modifier|&
name|TheCU
parameter_list|,
specifier|const
name|DIImportedEntity
modifier|&
name|Module
parameter_list|,
name|DIE
modifier|&
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Register a source line with debug info. Returns the unique
end_comment

begin_comment
comment|/// label that was emitted and which provides correspondence to the
end_comment

begin_comment
comment|/// source line list.
end_comment

begin_function_decl
name|void
name|recordSourceLine
parameter_list|(
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Col
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Scope
parameter_list|,
name|unsigned
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Indentify instructions that are marking the beginning of or
end_comment

begin_comment
comment|/// ending of a scope.
end_comment

begin_function_decl
name|void
name|identifyScopeMarkers
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If Var is an current function argument that add it in
end_comment

begin_comment
comment|/// CurrentFnArguments list.
end_comment

begin_function_decl
name|bool
name|addCurrentFnArgument
parameter_list|(
name|DbgVariable
modifier|*
name|Var
parameter_list|,
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Populate LexicalScope entries with variables' info.
end_comment

begin_decl_stmt
name|void
name|collectVariableInfo
argument_list|(
name|SmallPtrSet
operator|<
specifier|const
name|MDNode
operator|*
argument_list|,
literal|16
operator|>
operator|&
name|ProcessedVars
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Collect variable information from the side table maintained
end_comment

begin_comment
comment|/// by MMI.
end_comment

begin_decl_stmt
name|void
name|collectVariableInfoFromMMITable
argument_list|(
name|SmallPtrSet
operator|<
specifier|const
name|MDNode
operator|*
argument_list|,
literal|16
operator|>
operator|&
name|P
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Ensure that a label will be emitted before MI.
end_comment

begin_function
name|void
name|requestLabelBeforeInsn
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
name|LabelsBeforeInsn
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|MI
argument_list|,
name|nullptr
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Return Label preceding the instruction.
end_comment

begin_function_decl
name|MCSymbol
modifier|*
name|getLabelBeforeInsn
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Ensure that a label will be emitted after MI.
end_comment

begin_function
name|void
name|requestLabelAfterInsn
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
name|LabelsAfterInsn
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|MI
argument_list|,
name|nullptr
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Return Label immediately following the instruction.
end_comment

begin_function_decl
name|MCSymbol
modifier|*
name|getLabelAfterInsn
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|attachRangesOrLowHighPC
argument_list|(
name|DwarfCompileUnit
operator|&
name|Unit
argument_list|,
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
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|attachLowHighPC
parameter_list|(
name|DwarfCompileUnit
modifier|&
name|Unit
parameter_list|,
name|DIE
modifier|&
name|D
parameter_list|,
name|MCSymbol
modifier|*
name|Begin
parameter_list|,
name|MCSymbol
modifier|*
name|End
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Main entry points.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|DwarfDebug
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|,
name|Module
operator|*
name|M
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|~
name|DwarfDebug
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|insertDIE
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|TypeMD
parameter_list|,
name|DIE
modifier|*
name|Die
parameter_list|)
block|{
name|MDTypeNodeToDieMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|TypeMD
argument_list|,
name|Die
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|DIE
modifier|*
name|getDIE
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|TypeMD
parameter_list|)
block|{
return|return
name|MDTypeNodeToDieMap
operator|.
name|lookup
argument_list|(
name|TypeMD
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Emit all Dwarf sections that should come prior to the
end_comment

begin_comment
comment|/// content.
end_comment

begin_function_decl
name|void
name|beginModule
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit all Dwarf sections that should come after the content.
end_comment

begin_expr_stmt
name|void
name|endModule
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Gather pre-function debug information.
end_comment

begin_decl_stmt
name|void
name|beginFunction
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Gather and emit post-function debug information.
end_comment

begin_decl_stmt
name|void
name|endFunction
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Process beginning of an instruction.
end_comment

begin_decl_stmt
name|void
name|beginInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Process end of an instruction.
end_comment

begin_expr_stmt
name|void
name|endInstruction
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Add a DIE to the set of types that we're going to pull into
end_comment

begin_comment
comment|/// type units.
end_comment

begin_function_decl
name|void
name|addDwarfTypeUnitType
parameter_list|(
name|DwarfCompileUnit
modifier|&
name|CU
parameter_list|,
name|StringRef
name|Identifier
parameter_list|,
name|DIE
modifier|&
name|Die
parameter_list|,
name|DICompositeType
name|CTy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add a label so that arange data can be generated for it.
end_comment

begin_function
name|void
name|addArangeLabel
parameter_list|(
name|SymbolCU
name|SCU
parameter_list|)
block|{
name|ArangeLabels
operator|.
name|push_back
argument_list|(
name|SCU
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief For symbols that have a size designated (e.g. common symbols),
end_comment

begin_comment
comment|/// this tracks that size.
end_comment

begin_function
name|void
name|setSymbolSize
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Sym
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
function|override
block|{
name|SymSize
index|[
name|Sym
index|]
operator|=
name|Size
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Recursively Emits a debug information entry.
end_comment

begin_function_decl
name|void
name|emitDIE
parameter_list|(
name|DIE
modifier|&
name|Die
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Experimental DWARF5 features.
end_comment

begin_comment
comment|/// \brief Returns whether or not to emit tables that dwarf consumers can
end_comment

begin_comment
comment|/// use to accelerate lookup.
end_comment

begin_expr_stmt
name|bool
name|useDwarfAccelTables
argument_list|()
specifier|const
block|{
return|return
name|HasDwarfAccelTables
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns whether or not to change the current debug info for the
end_comment

begin_comment
comment|/// split dwarf proposal support.
end_comment

begin_expr_stmt
name|bool
name|useSplitDwarf
argument_list|()
specifier|const
block|{
return|return
name|HasSplitDwarf
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the Dwarf Version.
end_comment

begin_expr_stmt
name|unsigned
name|getDwarfVersion
argument_list|()
specifier|const
block|{
return|return
name|DwarfVersion
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the section symbol for the .debug_loc section.
end_comment

begin_expr_stmt
name|MCSymbol
operator|*
name|getDebugLocSym
argument_list|()
specifier|const
block|{
return|return
name|DwarfDebugLocSectionSym
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the previous section that was emitted into.
end_comment

begin_expr_stmt
specifier|const
name|MCSection
operator|*
name|getPrevSection
argument_list|()
specifier|const
block|{
return|return
name|PrevSection
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the previous CU that was being updated
end_comment

begin_expr_stmt
specifier|const
name|DwarfCompileUnit
operator|*
name|getPrevCU
argument_list|()
specifier|const
block|{
return|return
name|PrevCU
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the entries for the .debug_loc section.
end_comment

begin_expr_stmt
specifier|const
name|SmallVectorImpl
operator|<
name|DebugLocList
operator|>
operator|&
name|getDebugLocEntries
argument_list|()
specifier|const
block|{
return|return
name|DotDebugLocEntries
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Emit an entry for the debug loc section. This can be used to
end_comment

begin_comment
comment|/// handle an entry that's going to be emitted into the debug loc section.
end_comment

begin_function_decl
name|void
name|emitDebugLocEntry
parameter_list|(
name|ByteStreamer
modifier|&
name|Streamer
parameter_list|,
specifier|const
name|DebugLocEntry
modifier|&
name|Entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit the location for a debug loc entry, including the size header.
end_comment

begin_function_decl
name|void
name|emitDebugLocEntryLocation
parameter_list|(
specifier|const
name|DebugLocEntry
modifier|&
name|Entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Find the MDNode for the given reference.
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
name|Ref
operator|.
name|resolve
argument_list|(
name|TypeIdentifierMap
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the TypeIdentifierMap.
end_comment

begin_expr_stmt
specifier|const
name|DITypeIdentifierMap
operator|&
name|getTypeIdentifierMap
argument_list|()
specifier|const
block|{
return|return
name|TypeIdentifierMap
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Find the DwarfCompileUnit for the given CU Die.
end_comment

begin_decl_stmt
name|DwarfCompileUnit
modifier|*
name|lookupUnit
argument_list|(
specifier|const
name|DIE
operator|*
name|CU
argument_list|)
decl|const
block|{
return|return
name|CUDieMap
operator|.
name|lookup
argument_list|(
name|CU
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// isSubprogramContext - Return true if Context is either a subprogram
end_comment

begin_comment
comment|/// or another context nested inside a subprogram.
end_comment

begin_function_decl
name|bool
name|isSubprogramContext
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addSubprogramNames
parameter_list|(
name|DISubprogram
name|SP
parameter_list|,
name|DIE
modifier|&
name|Die
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|AddressPool
modifier|&
name|getAddressPool
parameter_list|()
block|{
return|return
name|AddrPool
return|;
block|}
end_function

begin_function_decl
name|void
name|addAccelName
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

begin_function_decl
name|void
name|addAccelObjC
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

begin_function_decl
name|void
name|addAccelType
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|DIE
modifier|&
name|Die
parameter_list|,
name|char
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}; }
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


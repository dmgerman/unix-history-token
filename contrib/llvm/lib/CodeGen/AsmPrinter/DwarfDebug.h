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
file|"llvm/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LexicalScopes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MachineLocation.h"
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
file|"llvm/ADT/UniqueVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CompileUnit
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
name|MachineFrameInfo
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|DIEAbbrev
decl_stmt|;
name|class
name|DIE
decl_stmt|;
name|class
name|DIEBlock
decl_stmt|;
name|class
name|DIEEntry
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
comment|/// DotDebugLocEntry - This struct describes location entries emitted in
comment|/// .debug_loc section.
typedef|typedef
struct|struct
name|DotDebugLocEntry
block|{
specifier|const
name|MCSymbol
modifier|*
name|Begin
decl_stmt|;
specifier|const
name|MCSymbol
modifier|*
name|End
decl_stmt|;
name|MachineLocation
name|Loc
decl_stmt|;
specifier|const
name|MDNode
modifier|*
name|Variable
decl_stmt|;
name|bool
name|Merged
decl_stmt|;
name|bool
name|Constant
decl_stmt|;
enum|enum
name|EntryType
block|{
name|E_Location
block|,
name|E_Integer
block|,
name|E_ConstantFP
block|,
name|E_ConstantInt
block|}
enum|;
name|enum
name|EntryType
name|EntryKind
decl_stmt|;
union|union
block|{
name|int64_t
name|Int
decl_stmt|;
specifier|const
name|ConstantFP
modifier|*
name|CFP
decl_stmt|;
specifier|const
name|ConstantInt
modifier|*
name|CIP
decl_stmt|;
block|}
name|Constants
union|;
name|DotDebugLocEntry
argument_list|()
operator|:
name|Begin
argument_list|(
literal|0
argument_list|)
operator|,
name|End
argument_list|(
literal|0
argument_list|)
operator|,
name|Variable
argument_list|(
literal|0
argument_list|)
operator|,
name|Merged
argument_list|(
name|false
argument_list|)
operator|,
name|Constant
argument_list|(
argument|false
argument_list|)
block|{
name|Constants
operator|.
name|Int
operator|=
literal|0
block|;}
name|DotDebugLocEntry
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|B
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|E
argument_list|,
name|MachineLocation
operator|&
name|L
argument_list|,
specifier|const
name|MDNode
operator|*
name|V
argument_list|)
operator|:
name|Begin
argument_list|(
name|B
argument_list|)
operator|,
name|End
argument_list|(
name|E
argument_list|)
operator|,
name|Loc
argument_list|(
name|L
argument_list|)
operator|,
name|Variable
argument_list|(
name|V
argument_list|)
operator|,
name|Merged
argument_list|(
name|false
argument_list|)
operator|,
name|Constant
argument_list|(
argument|false
argument_list|)
block|{
name|Constants
operator|.
name|Int
operator|=
literal|0
block|;
name|EntryKind
operator|=
name|E_Location
block|; }
name|DotDebugLocEntry
argument_list|(
argument|const MCSymbol *B
argument_list|,
argument|const MCSymbol *E
argument_list|,
argument|int64_t i
argument_list|)
operator|:
name|Begin
argument_list|(
name|B
argument_list|)
operator|,
name|End
argument_list|(
name|E
argument_list|)
operator|,
name|Variable
argument_list|(
literal|0
argument_list|)
operator|,
name|Merged
argument_list|(
name|false
argument_list|)
operator|,
name|Constant
argument_list|(
argument|true
argument_list|)
block|{
name|Constants
operator|.
name|Int
operator|=
name|i
block|;
name|EntryKind
operator|=
name|E_Integer
block|; }
name|DotDebugLocEntry
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|B
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|E
argument_list|,
specifier|const
name|ConstantFP
operator|*
name|FPtr
argument_list|)
operator|:
name|Begin
argument_list|(
name|B
argument_list|)
operator|,
name|End
argument_list|(
name|E
argument_list|)
operator|,
name|Variable
argument_list|(
literal|0
argument_list|)
operator|,
name|Merged
argument_list|(
name|false
argument_list|)
operator|,
name|Constant
argument_list|(
argument|true
argument_list|)
block|{
name|Constants
operator|.
name|CFP
operator|=
name|FPtr
block|;
name|EntryKind
operator|=
name|E_ConstantFP
block|; }
name|DotDebugLocEntry
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|B
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|E
argument_list|,
specifier|const
name|ConstantInt
operator|*
name|IPtr
argument_list|)
operator|:
name|Begin
argument_list|(
name|B
argument_list|)
operator|,
name|End
argument_list|(
name|E
argument_list|)
operator|,
name|Variable
argument_list|(
literal|0
argument_list|)
operator|,
name|Merged
argument_list|(
name|false
argument_list|)
operator|,
name|Constant
argument_list|(
argument|true
argument_list|)
block|{
name|Constants
operator|.
name|CIP
operator|=
name|IPtr
block|;
name|EntryKind
operator|=
name|E_ConstantInt
block|; }
comment|/// Empty entries are also used as a trigger to emit temp label. Such
comment|/// labels are referenced is used to find debug_loc offset for a given DIE.
name|bool
name|isEmpty
argument_list|()
block|{
return|return
name|Begin
operator|==
literal|0
operator|&&
name|End
operator|==
literal|0
return|;
block|}
name|bool
name|isMerged
parameter_list|()
block|{
return|return
name|Merged
return|;
block|}
name|void
name|Merge
parameter_list|(
name|DotDebugLocEntry
modifier|*
name|Next
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|Begin
operator|&&
name|Loc
operator|==
name|Next
operator|->
name|Loc
operator|&&
name|End
operator|==
name|Next
operator|->
name|Begin
operator|)
condition|)
return|return;
name|Next
operator|->
name|Begin
operator|=
name|Begin
expr_stmt|;
name|Merged
operator|=
name|true
expr_stmt|;
block|}
name|bool
name|isLocation
argument_list|()
specifier|const
block|{
return|return
name|EntryKind
operator|==
name|E_Location
return|;
block|}
name|bool
name|isInt
argument_list|()
specifier|const
block|{
return|return
name|EntryKind
operator|==
name|E_Integer
return|;
block|}
name|bool
name|isConstantFP
argument_list|()
specifier|const
block|{
return|return
name|EntryKind
operator|==
name|E_ConstantFP
return|;
block|}
name|bool
name|isConstantInt
argument_list|()
specifier|const
block|{
return|return
name|EntryKind
operator|==
name|E_ConstantInt
return|;
block|}
name|int64_t
name|getInt
parameter_list|()
block|{
return|return
name|Constants
operator|.
name|Int
return|;
block|}
specifier|const
name|ConstantFP
modifier|*
name|getConstantFP
parameter_list|()
block|{
return|return
name|Constants
operator|.
name|CFP
return|;
block|}
specifier|const
name|ConstantInt
modifier|*
name|getConstantInt
parameter_list|()
block|{
return|return
name|Constants
operator|.
name|CIP
return|;
block|}
block|}
name|DotDebugLocEntry
typedef|;
comment|//===----------------------------------------------------------------------===//
comment|/// DbgVariable - This class is used to track local variable information.
comment|///
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
name|DbgVariable
modifier|*
name|AbsVar
decl_stmt|;
comment|// Corresponding Abstract variable, if any.
specifier|const
name|MachineInstr
modifier|*
name|MInsn
decl_stmt|;
comment|// DBG_VALUE instruction of the variable.
name|int
name|FrameIndex
decl_stmt|;
name|public
label|:
comment|// AbsVar may be NULL.
name|DbgVariable
argument_list|(
argument|DIVariable V
argument_list|,
argument|DbgVariable *AV
argument_list|)
block|:
name|Var
argument_list|(
name|V
argument_list|)
operator|,
name|TheDIE
argument_list|(
literal|0
argument_list|)
operator|,
name|DotDebugLocOffset
argument_list|(
operator|~
literal|0U
argument_list|)
operator|,
name|AbsVar
argument_list|(
name|AV
argument_list|)
operator|,
name|MInsn
argument_list|(
literal|0
argument_list|)
operator|,
name|FrameIndex
argument_list|(
argument|~
literal|0
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
modifier|*
name|D
parameter_list|)
block|{
name|TheDIE
operator|=
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
name|DbgVariable
operator|*
name|getAbstractVariable
argument_list|()
specifier|const
block|{
return|return
name|AbsVar
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
name|void
name|setMInsn
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|M
parameter_list|)
block|{
name|MInsn
operator|=
name|M
expr_stmt|;
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
name|unsigned
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
comment|/// isArtificial - Return true if DbgVariable is artificial.
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
name|Var
operator|.
name|getTag
argument_list|()
operator|==
name|dwarf
operator|::
name|DW_TAG_arg_variable
operator|&&
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
name|variableHasComplexAddress
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Var
operator|.
name|Verify
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
block|{
name|assert
argument_list|(
name|Var
operator|.
name|Verify
argument_list|()
operator|&&
literal|"Invalid complex DbgVariable!"
argument_list|)
block|;
return|return
name|Var
operator|.
name|isBlockByrefVariable
argument_list|()
return|;
block|}
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
name|Verify
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

begin_decl_stmt
unit|};
name|class
name|DwarfDebug
block|{
comment|/// Asm - Target of Dwarf emission.
name|AsmPrinter
modifier|*
name|Asm
decl_stmt|;
comment|/// MMI - Collected machine module information.
name|MachineModuleInfo
modifier|*
name|MMI
decl_stmt|;
comment|/// DIEValueAllocator - All DIEValues are allocated through this allocator.
name|BumpPtrAllocator
name|DIEValueAllocator
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Attributes used to construct specific Dwarf sections.
comment|//
name|CompileUnit
modifier|*
name|FirstCU
decl_stmt|;
comment|/// Maps MDNode with its corresponding CompileUnit.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|CompileUnit
operator|*
operator|>
name|CUMap
expr_stmt|;
comment|/// Maps subprogram MDNode with its corresponding CompileUnit.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|CompileUnit
operator|*
operator|>
name|SPMap
expr_stmt|;
comment|/// AbbreviationsSet - Used to uniquely define abbreviations.
comment|///
name|FoldingSet
operator|<
name|DIEAbbrev
operator|>
name|AbbreviationsSet
expr_stmt|;
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
expr_stmt|;
comment|/// SourceIdMap - Source id map, i.e. pair of source filename and directory,
comment|/// separated by a zero byte, mapped to a unique id.
name|StringMap
operator|<
name|unsigned
operator|,
name|BumpPtrAllocator
operator|&
operator|>
name|SourceIdMap
expr_stmt|;
comment|/// StringPool - A String->Symbol mapping of strings used by indirect
comment|/// references.
name|StringMap
operator|<
name|std
operator|::
name|pair
operator|<
name|MCSymbol
operator|*
operator|,
name|unsigned
operator|>
operator|,
name|BumpPtrAllocator
operator|&
operator|>
name|StringPool
expr_stmt|;
name|unsigned
name|NextStringPoolNumber
decl_stmt|;
comment|/// SectionMap - Provides a unique id per text section.
comment|///
name|UniqueVector
operator|<
specifier|const
name|MCSection
operator|*
operator|>
name|SectionMap
expr_stmt|;
comment|/// CurrentFnArguments - List of Arguments (DbgValues) for current function.
name|SmallVector
operator|<
name|DbgVariable
operator|*
operator|,
literal|8
operator|>
name|CurrentFnArguments
expr_stmt|;
name|LexicalScopes
name|LScopes
decl_stmt|;
comment|/// AbstractSPDies - Collection of abstract subprogram DIEs.
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
comment|/// ScopeVariables - Collection of dbg variables of a scope.
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
name|ScopeVariables
expr_stmt|;
comment|/// AbstractVariables - Collection of abstract variables.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DbgVariable
operator|*
operator|>
name|AbstractVariables
expr_stmt|;
comment|/// DotDebugLocEntries - Collection of DotDebugLocEntry.
name|SmallVector
operator|<
name|DotDebugLocEntry
operator|,
literal|4
operator|>
name|DotDebugLocEntries
expr_stmt|;
comment|/// InlinedSubprogramDIEs - Collection of subprogram DIEs that are marked
comment|/// (at the end of the module) as DW_AT_inline.
name|SmallPtrSet
operator|<
name|DIE
operator|*
operator|,
literal|4
operator|>
name|InlinedSubprogramDIEs
expr_stmt|;
comment|/// InlineInfo - Keep track of inlined functions and their location.  This
comment|/// information is used to populate the debug_inlined section.
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|MCSymbol
operator|*
operator|,
name|DIE
operator|*
operator|>
name|InlineInfoLabels
expr_stmt|;
name|DenseMap
operator|<
specifier|const
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
specifier|const
name|MDNode
operator|*
operator|,
literal|4
operator|>
name|InlinedSPNodes
expr_stmt|;
comment|// ProcessedSPNodes - This is a collection of subprogram MDNodes that
comment|// are processed to create DIEs.
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
comment|/// LabelsBeforeInsn - Maps instruction with label emitted before
comment|/// instruction.
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
comment|/// LabelsAfterInsn - Maps instruction with label emitted after
comment|/// instruction.
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
comment|/// UserVariables - Every user variable mentioned by a DBG_VALUE instruction
comment|/// in order of appearance.
name|SmallVector
operator|<
specifier|const
name|MDNode
operator|*
operator|,
literal|8
operator|>
name|UserVariables
expr_stmt|;
comment|/// DbgValues - For each user variable, keep a list of DBG_VALUE
comment|/// instructions in order. The list can also contain normal instructions that
comment|/// clobber the previous DBG_VALUE.
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|SmallVector
operator|<
specifier|const
name|MachineInstr
operator|*
operator|,
literal|4
operator|>
expr|>
name|DbgValueHistoryMap
expr_stmt|;
name|DbgValueHistoryMap
name|DbgValues
decl_stmt|;
name|SmallVector
operator|<
specifier|const
name|MCSymbol
operator|*
operator|,
literal|8
operator|>
name|DebugRangeSymbols
expr_stmt|;
comment|/// Previous instruction's location information. This is used to determine
comment|/// label location to indicate scope boundries in dwarf debug info.
name|DebugLoc
name|PrevInstLoc
decl_stmt|;
name|MCSymbol
modifier|*
name|PrevLabel
decl_stmt|;
comment|/// PrologEndLoc - This location indicates end of function prologue and
comment|/// beginning of function body.
name|DebugLoc
name|PrologEndLoc
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
comment|// Section Symbols: these are assembler temporary labels that are emitted at
comment|// the beginning of each supported dwarf section.  These are used to form
comment|// section offsets and are created by EmitSectionLabels.
name|MCSymbol
modifier|*
name|DwarfInfoSectionSym
decl_stmt|,
modifier|*
name|DwarfAbbrevSectionSym
decl_stmt|;
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
name|MCSymbol
modifier|*
name|DwarfDebugLocSectionSym
decl_stmt|;
name|MCSymbol
modifier|*
name|FunctionBeginSym
decl_stmt|,
modifier|*
name|FunctionEndSym
decl_stmt|;
comment|// As an optimization, there is no need to emit an entry in the directory
comment|// table for the same directory as DW_at_comp_dir.
name|StringRef
name|CompilationDir
decl_stmt|;
name|private
label|:
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
comment|/// findAbstractVariable - Find abstract variable associated with Var.
name|DbgVariable
modifier|*
name|findAbstractVariable
parameter_list|(
name|DIVariable
modifier|&
name|Var
parameter_list|,
name|DebugLoc
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
name|CompileUnit
modifier|*
name|SPCU
parameter_list|,
specifier|const
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
name|CompileUnit
modifier|*
name|TheCU
parameter_list|,
name|LexicalScope
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
name|CompileUnit
modifier|*
name|TheCU
parameter_list|,
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
comment|/// constructScopeDIE - Construct a DIE for this scope.
name|DIE
modifier|*
name|constructScopeDIE
parameter_list|(
name|CompileUnit
modifier|*
name|TheCU
parameter_list|,
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
comment|/// EmitSectionLabels - Emit initial Dwarf sections with a label at
comment|/// the start of each one.
name|void
name|EmitSectionLabels
parameter_list|()
function_decl|;
comment|/// emitDIE - Recursively Emits a debug information entry.
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
comment|/// emitAccelNames - Emit visible names into a hashed accelerator table
comment|/// section.
name|void
name|emitAccelNames
parameter_list|()
function_decl|;
comment|/// emitAccelObjC - Emit objective C classes and categories into a hashed
comment|/// accelerator table section.
name|void
name|emitAccelObjC
parameter_list|()
function_decl|;
comment|/// emitAccelNamespace - Emit namespace dies into a hashed accelerator
comment|/// table.
name|void
name|emitAccelNamespaces
parameter_list|()
function_decl|;
comment|/// emitAccelTypes() - Emit type dies into a hashed accelerator table.
comment|///
name|void
name|emitAccelTypes
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
comment|/// The rest of the entry consists of a {die_offset, low_pc} pair for each
comment|/// inlined instance; the die_offset points to the inlined_subroutine die in
comment|/// the __debug_info section, and the low_pc is the starting address for the
comment|/// inlining instance.
name|void
name|emitDebugInlineInfo
parameter_list|()
function_decl|;
comment|/// constructCompileUnit - Create new CompileUnit for the given
comment|/// metadata node with tag DW_TAG_compile_unit.
name|CompileUnit
modifier|*
name|constructCompileUnit
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// construct SubprogramDIE - Construct subprogram DIE.
name|void
name|constructSubprogramDIE
parameter_list|(
name|CompileUnit
modifier|*
name|TheCU
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// recordSourceLine - Register a source line with debug info. Returns the
comment|/// unique label that was emitted and which provides correspondence to
comment|/// the source line list.
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
comment|/// identifyScopeMarkers() - Indentify instructions that are marking the
comment|/// beginning of or ending of a scope.
name|void
name|identifyScopeMarkers
parameter_list|()
function_decl|;
comment|/// addCurrentFnArgument - If Var is an current function argument that add
comment|/// it in CurrentFnArguments list.
name|bool
name|addCurrentFnArgument
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|,
name|DbgVariable
modifier|*
name|Var
parameter_list|,
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
comment|/// collectVariableInfo - Populate LexicalScope entries with variables' info.
name|void
name|collectVariableInfo
argument_list|(
specifier|const
name|MachineFunction
operator|*
argument_list|,
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
comment|/// collectVariableInfoFromMMITable - Collect variable information from
comment|/// side table maintained by MMI.
name|void
name|collectVariableInfoFromMMITable
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|,
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
comment|/// requestLabelBeforeInsn - Ensure that a label will be emitted before MI.
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
operator|(
name|MCSymbol
operator|*
operator|)
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// getLabelBeforeInsn - Return Label preceding the instruction.
specifier|const
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
comment|/// requestLabelAfterInsn - Ensure that a label will be emitted after MI.
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
operator|(
name|MCSymbol
operator|*
operator|)
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// getLabelAfterInsn - Return Label immediately following the instruction.
specifier|const
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
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
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
operator|~
name|DwarfDebug
argument_list|()
expr_stmt|;
comment|/// collectInfoFromNamedMDNodes - Collect debug info from named mdnodes such
comment|/// as llvm.dbg.enum and llvm.dbg.ty
name|void
name|collectInfoFromNamedMDNodes
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// collectLegacyDebugInfo - Collect debug info using DebugInfoFinder.
comment|/// FIXME - Remove this when DragonEgg switches to DIBuilder.
name|bool
name|collectLegacyDebugInfo
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// beginModule - Emit all Dwarf sections that should come prior to the
comment|/// content.
name|void
name|beginModule
parameter_list|(
name|Module
modifier|*
name|M
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
specifier|const
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
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|/// beginInstruction - Process beginning of an instruction.
name|void
name|beginInstruction
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// endInstruction - Prcess end of an instruction.
name|void
name|endInstruction
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// GetOrCreateSourceID - Look up the source id with the given directory and
comment|/// source file names. If none currently exists, create a new id and insert it
comment|/// in the SourceIds map.
name|unsigned
name|GetOrCreateSourceID
parameter_list|(
name|StringRef
name|DirName
parameter_list|,
name|StringRef
name|FullName
parameter_list|)
function_decl|;
comment|/// getStringPool - returns the entry into the start of the pool.
name|MCSymbol
modifier|*
name|getStringPool
parameter_list|()
function_decl|;
comment|/// getStringPoolEntry - returns an entry into the string pool with the given
comment|/// string text.
name|MCSymbol
modifier|*
name|getStringPoolEntry
parameter_list|(
name|StringRef
name|Str
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


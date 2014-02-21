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
file|"llvm/ADT/SetVector.h"
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
file|"llvm/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MachineLocation.h"
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
comment|/// \brief This struct describes location entries emitted in the .debug_loc
comment|/// section.
name|class
name|DotDebugLocEntry
block|{
comment|// Begin and end symbols for the address range that this location is valid.
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
comment|// Type of entry that this represents.
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
comment|// The location in the machine frame.
name|MachineLocation
name|Loc
decl_stmt|;
comment|// The variable to which this location entry corresponds.
specifier|const
name|MDNode
modifier|*
name|Variable
decl_stmt|;
comment|// Whether this location has been merged.
name|bool
name|Merged
decl_stmt|;
name|public
label|:
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
argument|false
argument_list|)
block|{
name|Constants
operator|.
name|Int
operator|=
literal|0
block|;   }
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
block|;   }
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
argument|false
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
block|;   }
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
argument|false
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
block|;   }
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
argument|false
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
block|;   }
comment|/// \brief Empty entries are also used as a trigger to emit temp label. Such
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
argument_list|()
specifier|const
block|{
return|return
name|Constants
operator|.
name|Int
return|;
block|}
specifier|const
name|ConstantFP
operator|*
name|getConstantFP
argument_list|()
specifier|const
block|{
return|return
name|Constants
operator|.
name|CFP
return|;
block|}
specifier|const
name|ConstantInt
operator|*
name|getConstantInt
argument_list|()
specifier|const
block|{
return|return
name|Constants
operator|.
name|CIP
return|;
block|}
specifier|const
name|MDNode
operator|*
name|getVariable
argument_list|()
specifier|const
block|{
return|return
name|Variable
return|;
block|}
specifier|const
name|MCSymbol
operator|*
name|getBeginSym
argument_list|()
specifier|const
block|{
return|return
name|Begin
return|;
block|}
specifier|const
name|MCSymbol
operator|*
name|getEndSym
argument_list|()
specifier|const
block|{
return|return
name|End
return|;
block|}
name|MachineLocation
name|getLoc
argument_list|()
specifier|const
block|{
return|return
name|Loc
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
name|DwarfDebug
modifier|*
name|DD
decl_stmt|;
name|public
label|:
comment|// AbsVar may be NULL.
name|DbgVariable
argument_list|(
argument|DIVariable V
argument_list|,
argument|DbgVariable *AV
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
name|uint16_t
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
comment|/// \brief Collects and handles information specific to a particular
end_comment

begin_comment
comment|/// collection of units.
end_comment

begin_decl_stmt
name|class
name|DwarfUnits
block|{
comment|// Target of Dwarf emission, used for sizing of abbreviations.
name|AsmPrinter
modifier|*
name|Asm
decl_stmt|;
comment|// Used to uniquely define abbreviations.
name|FoldingSet
operator|<
name|DIEAbbrev
operator|>
operator|*
name|AbbreviationsSet
expr_stmt|;
comment|// A list of all the unique abbreviations in use.
name|std
operator|::
name|vector
operator|<
name|DIEAbbrev
operator|*
operator|>
operator|&
name|Abbreviations
expr_stmt|;
comment|// A pointer to all units in the section.
name|SmallVector
operator|<
name|CompileUnit
operator|*
operator|,
literal|1
operator|>
name|CUs
expr_stmt|;
comment|// Collection of strings for this unit and assorted symbols.
comment|// A String->Symbol mapping of strings used by indirect
comment|// references.
typedef|typedef
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
name|StrPool
expr_stmt|;
name|StrPool
name|StringPool
decl_stmt|;
name|unsigned
name|NextStringPoolNumber
decl_stmt|;
name|std
operator|::
name|string
name|StringPref
expr_stmt|;
comment|// Collection of addresses for this unit and assorted labels.
comment|// A Symbol->unsigned mapping of addresses used by indirect
comment|// references.
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|MCExpr
operator|*
operator|,
name|unsigned
operator|>
name|AddrPool
expr_stmt|;
name|AddrPool
name|AddressPool
decl_stmt|;
name|unsigned
name|NextAddrPoolNumber
decl_stmt|;
name|public
label|:
name|DwarfUnits
argument_list|(
name|AsmPrinter
operator|*
name|AP
argument_list|,
name|FoldingSet
operator|<
name|DIEAbbrev
operator|>
operator|*
name|AS
argument_list|,
name|std
operator|::
name|vector
operator|<
name|DIEAbbrev
operator|*
operator|>
operator|&
name|A
argument_list|,
specifier|const
name|char
operator|*
name|Pref
argument_list|,
name|BumpPtrAllocator
operator|&
name|DA
argument_list|)
operator|:
name|Asm
argument_list|(
name|AP
argument_list|)
operator|,
name|AbbreviationsSet
argument_list|(
name|AS
argument_list|)
operator|,
name|Abbreviations
argument_list|(
name|A
argument_list|)
operator|,
name|StringPool
argument_list|(
name|DA
argument_list|)
operator|,
name|NextStringPoolNumber
argument_list|(
literal|0
argument_list|)
operator|,
name|StringPref
argument_list|(
name|Pref
argument_list|)
operator|,
name|AddressPool
argument_list|()
operator|,
name|NextAddrPoolNumber
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief Compute the size and offset of a DIE given an incoming Offset.
name|unsigned
name|computeSizeAndOffset
argument_list|(
argument|DIE *Die
argument_list|,
argument|unsigned Offset
argument_list|)
expr_stmt|;
comment|/// \brief Compute the size and offset of all the DIEs.
name|void
name|computeSizeAndOffsets
parameter_list|()
function_decl|;
comment|/// \brief Define a unique number for the abbreviation.
name|void
name|assignAbbrevNumber
parameter_list|(
name|DIEAbbrev
modifier|&
name|Abbrev
parameter_list|)
function_decl|;
comment|/// \brief Add a unit to the list of CUs.
name|void
name|addUnit
parameter_list|(
name|CompileUnit
modifier|*
name|CU
parameter_list|)
block|{
name|CUs
operator|.
name|push_back
argument_list|(
name|CU
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Emit all of the units to the section listed with the given
comment|/// abbreviation section.
name|void
name|emitUnits
parameter_list|(
name|DwarfDebug
modifier|*
name|DD
parameter_list|,
specifier|const
name|MCSection
modifier|*
name|USection
parameter_list|,
specifier|const
name|MCSection
modifier|*
name|ASection
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|ASectionSym
parameter_list|)
function_decl|;
comment|/// \brief Emit all of the strings to the section given.
name|void
name|emitStrings
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|StrSection
parameter_list|,
specifier|const
name|MCSection
modifier|*
name|OffsetSection
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|StrSecSym
parameter_list|)
function_decl|;
comment|/// \brief Emit all of the addresses to the section given.
name|void
name|emitAddresses
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|AddrSection
parameter_list|)
function_decl|;
comment|/// \brief Returns the entry into the start of the pool.
name|MCSymbol
modifier|*
name|getStringPoolSym
parameter_list|()
function_decl|;
comment|/// \brief Returns an entry into the string pool with the given
comment|/// string text.
name|MCSymbol
modifier|*
name|getStringPoolEntry
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// \brief Returns the index into the string pool with the given
comment|/// string text.
name|unsigned
name|getStringPoolIndex
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// \brief Returns the string pool.
name|StrPool
modifier|*
name|getStringPool
parameter_list|()
block|{
return|return
operator|&
name|StringPool
return|;
block|}
comment|/// \brief Returns the index into the address pool with the given
comment|/// label/symbol.
name|unsigned
name|getAddrPoolIndex
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Sym
parameter_list|)
function_decl|;
name|unsigned
name|getAddrPoolIndex
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Sym
parameter_list|)
function_decl|;
comment|/// \brief Returns the address pool.
name|AddrPool
modifier|*
name|getAddrPool
parameter_list|()
block|{
return|return
operator|&
name|AddressPool
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Helper used to pair up a symbol and its DWARF compile unit.
end_comment

begin_struct
struct|struct
name|SymbolCU
block|{
name|SymbolCU
argument_list|(
name|CompileUnit
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
name|CompileUnit
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
block|{
comment|// Target of Dwarf emission.
name|AsmPrinter
modifier|*
name|Asm
decl_stmt|;
comment|// Collected machine module information.
name|MachineModuleInfo
modifier|*
name|MMI
decl_stmt|;
comment|// All DIEValues are allocated through this allocator.
name|BumpPtrAllocator
name|DIEValueAllocator
decl_stmt|;
comment|// Handle to the a compile unit used for the inline extension handling.
name|CompileUnit
modifier|*
name|FirstCU
decl_stmt|;
comment|// Maps MDNode with its corresponding CompileUnit.
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
comment|// Maps subprogram MDNode with its corresponding CompileUnit.
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
comment|// Maps a CU DIE with its corresponding CompileUnit.
name|DenseMap
operator|<
specifier|const
name|DIE
operator|*
operator|,
name|CompileUnit
operator|*
operator|>
name|CUDieMap
expr_stmt|;
comment|/// Maps MDNodes for type sysstem with the corresponding DIEs. These DIEs can
comment|/// be shared across CUs, that is why we keep the map here instead
comment|/// of in CompileUnit.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DIE
operator|*
operator|>
name|MDTypeNodeToDieMap
expr_stmt|;
comment|// Used to uniquely define abbreviations.
name|FoldingSet
operator|<
name|DIEAbbrev
operator|>
name|AbbreviationsSet
expr_stmt|;
comment|// A list of all the unique abbreviations in use.
name|std
operator|::
name|vector
operator|<
name|DIEAbbrev
operator|*
operator|>
name|Abbreviations
expr_stmt|;
comment|// Stores the current file ID for a given compile unit.
name|DenseMap
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|FileIDCUMap
expr_stmt|;
comment|// Source id map, i.e. CUID, source filename and directory,
comment|// separated by a zero byte, mapped to a unique id.
name|StringMap
operator|<
name|unsigned
operator|,
name|BumpPtrAllocator
operator|&
operator|>
name|SourceIdMap
expr_stmt|;
comment|// List of all labels used in aranges generation.
name|std
operator|::
name|vector
operator|<
name|SymbolCU
operator|>
name|ArangeLabels
expr_stmt|;
comment|// Size of each symbol emitted (for those symbols that have a specific size).
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
operator|,
name|uint64_t
operator|>
name|SymSize
expr_stmt|;
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
comment|// List of arguments for current function.
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
comment|// Collection of abstract subprogram DIEs.
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
comment|// Collection of dbg variables of a scope.
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
name|ScopeVariablesMap
name|ScopeVariables
decl_stmt|;
comment|// Collection of abstract variables.
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
comment|// Collection of DotDebugLocEntry.
name|SmallVector
operator|<
name|DotDebugLocEntry
operator|,
literal|4
operator|>
name|DotDebugLocEntries
expr_stmt|;
comment|// Collection of subprogram DIEs that are marked (at the end of the module)
comment|// as DW_AT_inline.
name|SmallPtrSet
operator|<
name|DIE
operator|*
operator|,
literal|4
operator|>
name|InlinedSubprogramDIEs
expr_stmt|;
comment|// This is a collection of subprogram MDNodes that are processed to
comment|// create DIEs.
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
comment|// Maps instruction with label emitted before instruction.
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
comment|// Maps instruction with label emitted after instruction.
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
comment|// Every user variable mentioned by a DBG_VALUE instruction in order of
comment|// appearance.
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
comment|// For each user variable, keep a list of DBG_VALUE instructions in order.
comment|// The list can also contain normal instructions that clobber the previous
comment|// DBG_VALUE.
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
comment|// Previous instruction's location information. This is used to determine
comment|// label location to indicate scope boundries in dwarf debug info.
name|DebugLoc
name|PrevInstLoc
decl_stmt|;
name|MCSymbol
modifier|*
name|PrevLabel
decl_stmt|;
comment|// This location indicates end of function prologue and beginning of function
comment|// body.
name|DebugLoc
name|PrologEndLoc
decl_stmt|;
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
decl_stmt|,
modifier|*
name|DwarfLineSectionSym
decl_stmt|,
modifier|*
name|DwarfAddrSectionSym
decl_stmt|;
name|MCSymbol
modifier|*
name|FunctionBeginSym
decl_stmt|,
modifier|*
name|FunctionEndSym
decl_stmt|;
name|MCSymbol
modifier|*
name|DwarfAbbrevDWOSectionSym
decl_stmt|,
modifier|*
name|DwarfStrDWOSectionSym
decl_stmt|;
name|MCSymbol
modifier|*
name|DwarfGnuPubNamesSectionSym
decl_stmt|,
modifier|*
name|DwarfGnuPubTypesSectionSym
decl_stmt|;
comment|// As an optimization, there is no need to emit an entry in the directory
comment|// table for the same directory as DW_AT_comp_dir.
name|StringRef
name|CompilationDir
decl_stmt|;
comment|// Counter for assigning globally unique IDs for CUs.
name|unsigned
name|GlobalCUIndexCount
decl_stmt|;
comment|// Holder for the file specific debug information.
name|DwarfUnits
name|InfoHolder
decl_stmt|;
comment|// Holders for the various debug information flags that we might need to
comment|// have exposed. See accessor functions below for description.
comment|// Holder for imported entities.
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
name|ImportedEntityMap
name|ScopesWithImportedEntities
decl_stmt|;
comment|// Holder for types that are going to be extracted out into a type unit.
name|std
operator|::
name|vector
operator|<
name|DIE
operator|*
operator|>
name|TypeUnits
expr_stmt|;
comment|// Whether to emit the pubnames/pubtypes sections.
name|bool
name|HasDwarfPubSections
decl_stmt|;
comment|// Version of dwarf we're emitting.
name|unsigned
name|DwarfVersion
decl_stmt|;
comment|// DWARF5 Experimental Options
name|bool
name|HasDwarfAccelTables
decl_stmt|;
name|bool
name|HasSplitDwarf
decl_stmt|;
comment|// Separated Dwarf Variables
comment|// In general these will all be for bits that are left in the
comment|// original object file, rather than things that are meant
comment|// to be in the .dwo sections.
comment|// The CUs left in the original object file for separated debug info.
name|SmallVector
operator|<
name|CompileUnit
operator|*
operator|,
literal|1
operator|>
name|SkeletonCUs
expr_stmt|;
comment|// Used to uniquely define abbreviations for the skeleton emission.
name|FoldingSet
operator|<
name|DIEAbbrev
operator|>
name|SkeletonAbbrevSet
expr_stmt|;
comment|// A list of all the unique abbreviations in use.
name|std
operator|::
name|vector
operator|<
name|DIEAbbrev
operator|*
operator|>
name|SkeletonAbbrevs
expr_stmt|;
comment|// Holder for the skeleton information.
name|DwarfUnits
name|SkeletonHolder
decl_stmt|;
comment|// Maps from a type identifier to the actual MDNode.
name|DITypeIdentifierMap
name|TypeIdentifierMap
decl_stmt|;
name|private
label|:
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
comment|/// \brief Find abstract variable associated with Var.
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
comment|/// \brief Find DIE for the given subprogram and attach appropriate
comment|/// DW_AT_low_pc and DW_AT_high_pc attributes. If there are global
comment|/// variables in this scope then create and insert DIEs for these
comment|/// variables.
name|DIE
modifier|*
name|updateSubprogramScopeDIE
parameter_list|(
name|CompileUnit
modifier|*
name|SPCU
parameter_list|,
name|DISubprogram
name|SP
parameter_list|)
function_decl|;
comment|/// \brief Construct new DW_TAG_lexical_block for this scope and
comment|/// attach DW_AT_low_pc/DW_AT_high_pc labels.
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
comment|/// A helper function to check whether the DIE for a given Scope is going
comment|/// to be null.
name|bool
name|isLexicalScopeDIENull
parameter_list|(
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
comment|/// \brief This scope represents inlined body of a function. Construct
comment|/// DIE to represent this concrete inlined copy of the function.
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
comment|/// \brief Construct a DIE for this scope.
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
comment|/// A helper function to create children of a Scope DIE.
name|DIE
modifier|*
name|createScopeChildrenDIE
argument_list|(
name|CompileUnit
operator|*
name|TheCU
argument_list|,
name|LexicalScope
operator|*
name|Scope
argument_list|,
name|SmallVectorImpl
operator|<
name|DIE
operator|*
operator|>
operator|&
name|Children
argument_list|)
decl_stmt|;
comment|/// \brief Emit initial Dwarf sections with a label at the start of each one.
name|void
name|emitSectionLabels
parameter_list|()
function_decl|;
comment|/// \brief Compute the size and offset of a DIE given an incoming Offset.
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
comment|/// \brief Compute the size and offset of all the DIEs.
name|void
name|computeSizeAndOffsets
parameter_list|()
function_decl|;
comment|/// \brief Attach DW_AT_inline attribute with inlined subprogram DIEs.
name|void
name|computeInlinedDIEs
parameter_list|()
function_decl|;
comment|/// \brief Collect info for variables that were optimized out.
name|void
name|collectDeadVariables
parameter_list|()
function_decl|;
comment|/// \brief Finish off debug information after all functions have been
comment|/// processed.
name|void
name|finalizeModuleInfo
parameter_list|()
function_decl|;
comment|/// \brief Emit labels to close any remaining sections that have been left
comment|/// open.
name|void
name|endSections
parameter_list|()
function_decl|;
comment|/// \brief Emit a set of abbreviations to the specific section.
name|void
name|emitAbbrevs
argument_list|(
specifier|const
name|MCSection
operator|*
argument_list|,
name|std
operator|::
name|vector
operator|<
name|DIEAbbrev
operator|*
operator|>
operator|*
argument_list|)
decl_stmt|;
comment|/// \brief Emit the debug info section.
name|void
name|emitDebugInfo
parameter_list|()
function_decl|;
comment|/// \brief Emit the abbreviation section.
name|void
name|emitAbbreviations
parameter_list|()
function_decl|;
comment|/// \brief Emit the last address of the section and the end of
comment|/// the line matrix.
name|void
name|emitEndOfLineMatrix
parameter_list|(
name|unsigned
name|SectionEnd
parameter_list|)
function_decl|;
comment|/// \brief Emit visible names into a hashed accelerator table section.
name|void
name|emitAccelNames
parameter_list|()
function_decl|;
comment|/// \brief Emit objective C classes and categories into a hashed
comment|/// accelerator table section.
name|void
name|emitAccelObjC
parameter_list|()
function_decl|;
comment|/// \brief Emit namespace dies into a hashed accelerator table.
name|void
name|emitAccelNamespaces
parameter_list|()
function_decl|;
comment|/// \brief Emit type dies into a hashed accelerator table.
name|void
name|emitAccelTypes
parameter_list|()
function_decl|;
comment|/// \brief Emit visible names into a debug pubnames section.
comment|/// \param GnuStyle determines whether or not we want to emit
comment|/// additional information into the table ala newer gcc for gdb
comment|/// index.
name|void
name|emitDebugPubNames
parameter_list|(
name|bool
name|GnuStyle
init|=
name|false
parameter_list|)
function_decl|;
comment|/// \brief Emit visible types into a debug pubtypes section.
comment|/// \param GnuStyle determines whether or not we want to emit
comment|/// additional information into the table ala newer gcc for gdb
comment|/// index.
name|void
name|emitDebugPubTypes
parameter_list|(
name|bool
name|GnuStyle
init|=
name|false
parameter_list|)
function_decl|;
comment|/// \brief Emit visible names into a debug str section.
name|void
name|emitDebugStr
parameter_list|()
function_decl|;
comment|/// \brief Emit visible names into a debug loc section.
name|void
name|emitDebugLoc
parameter_list|()
function_decl|;
comment|/// \brief Emit visible names into a debug aranges section.
name|void
name|emitDebugARanges
parameter_list|()
function_decl|;
comment|/// \brief Emit visible names into a debug ranges section.
name|void
name|emitDebugRanges
parameter_list|()
function_decl|;
comment|/// \brief Emit visible names into a debug macinfo section.
name|void
name|emitDebugMacInfo
parameter_list|()
function_decl|;
comment|/// \brief Emit inline info using custom format.
name|void
name|emitDebugInlineInfo
parameter_list|()
function_decl|;
comment|/// DWARF 5 Experimental Split Dwarf Emitters
comment|/// \brief Construct the split debug info compile unit for the debug info
comment|/// section.
name|CompileUnit
modifier|*
name|constructSkeletonCU
parameter_list|(
specifier|const
name|CompileUnit
modifier|*
name|CU
parameter_list|)
function_decl|;
comment|/// \brief Emit the local split abbreviations.
name|void
name|emitSkeletonAbbrevs
parameter_list|(
specifier|const
name|MCSection
modifier|*
parameter_list|)
function_decl|;
comment|/// \brief Emit the debug info dwo section.
name|void
name|emitDebugInfoDWO
parameter_list|()
function_decl|;
comment|/// \brief Emit the debug abbrev dwo section.
name|void
name|emitDebugAbbrevDWO
parameter_list|()
function_decl|;
comment|/// \brief Emit the debug str dwo section.
name|void
name|emitDebugStrDWO
parameter_list|()
function_decl|;
comment|/// \brief Create new CompileUnit for the given metadata node with tag
comment|/// DW_TAG_compile_unit.
name|CompileUnit
modifier|*
name|constructCompileUnit
parameter_list|(
name|DICompileUnit
name|DIUnit
parameter_list|)
function_decl|;
comment|/// \brief Construct subprogram DIE.
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
comment|/// \brief Construct imported_module or imported_declaration DIE.
name|void
name|constructImportedEntityDIE
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
comment|/// \brief Construct import_module DIE.
name|void
name|constructImportedEntityDIE
parameter_list|(
name|CompileUnit
modifier|*
name|TheCU
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|,
name|DIE
modifier|*
name|Context
parameter_list|)
function_decl|;
comment|/// \brief Construct import_module DIE.
name|void
name|constructImportedEntityDIE
parameter_list|(
name|CompileUnit
modifier|*
name|TheCU
parameter_list|,
specifier|const
name|DIImportedEntity
modifier|&
name|Module
parameter_list|,
name|DIE
modifier|*
name|Context
parameter_list|)
function_decl|;
comment|/// \brief Register a source line with debug info. Returns the unique
comment|/// label that was emitted and which provides correspondence to the
comment|/// source line list.
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
comment|/// \brief Indentify instructions that are marking the beginning of or
comment|/// ending of a scope.
name|void
name|identifyScopeMarkers
parameter_list|()
function_decl|;
comment|/// \brief If Var is an current function argument that add it in
comment|/// CurrentFnArguments list.
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
comment|/// \brief Populate LexicalScope entries with variables' info.
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
comment|/// \brief Collect variable information from the side table maintained
comment|/// by MMI.
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
comment|/// \brief Ensure that a label will be emitted before MI.
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
comment|/// \brief Return Label preceding the instruction.
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
comment|/// \brief Ensure that a label will be emitted after MI.
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
comment|/// \brief Return Label immediately following the instruction.
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
comment|/// \brief Emit all Dwarf sections that should come prior to the
comment|/// content.
name|void
name|beginModule
parameter_list|()
function_decl|;
comment|/// \brief Emit all Dwarf sections that should come after the content.
name|void
name|endModule
parameter_list|()
function_decl|;
comment|/// \brief Gather pre-function debug information.
name|void
name|beginFunction
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|/// \brief Gather and emit post-function debug information.
name|void
name|endFunction
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|/// \brief Process beginning of an instruction.
name|void
name|beginInstruction
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// \brief Process end of an instruction.
name|void
name|endInstruction
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// \brief Add a DIE to the set of types that we're going to pull into
comment|/// type units.
name|void
name|addTypeUnitType
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|)
block|{
name|TypeUnits
operator|.
name|push_back
argument_list|(
name|Die
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a label so that arange data can be generated for it.
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
comment|/// \brief For symbols that have a size designated (e.g. common symbols),
comment|/// this tracks that size.
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
block|{
name|SymSize
index|[
name|Sym
index|]
operator|=
name|Size
expr_stmt|;
block|}
comment|/// \brief Look up the source id with the given directory and source file
comment|/// names. If none currently exists, create a new id and insert it in the
comment|/// SourceIds map.
name|unsigned
name|getOrCreateSourceID
parameter_list|(
name|StringRef
name|DirName
parameter_list|,
name|StringRef
name|FullName
parameter_list|,
name|unsigned
name|CUID
parameter_list|)
function_decl|;
comment|/// \brief Recursively Emits a debug information entry.
name|void
name|emitDIE
argument_list|(
name|DIE
operator|*
name|Die
argument_list|,
name|ArrayRef
operator|<
name|DIEAbbrev
operator|*
operator|>
name|Abbrevs
argument_list|)
decl_stmt|;
comment|// Experimental DWARF5 features.
comment|/// \brief Returns whether or not to emit tables that dwarf consumers can
comment|/// use to accelerate lookup.
name|bool
name|useDwarfAccelTables
parameter_list|()
block|{
return|return
name|HasDwarfAccelTables
return|;
block|}
comment|/// \brief Returns whether or not to change the current debug info for the
comment|/// split dwarf proposal support.
name|bool
name|useSplitDwarf
parameter_list|()
block|{
return|return
name|HasSplitDwarf
return|;
block|}
comment|/// Returns the Dwarf Version.
name|unsigned
name|getDwarfVersion
argument_list|()
specifier|const
block|{
return|return
name|DwarfVersion
return|;
block|}
comment|/// Find the MDNode for the given reference.
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
comment|/// isSubprogramContext - Return true if Context is either a subprogram
comment|/// or another context nested inside a subprogram.
name|bool
name|isSubprogramContext
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|Context
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


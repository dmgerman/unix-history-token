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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFDEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFDEBUG_H
end_define

begin_include
include|#
directive|include
file|"DbgValueHistoryCalculator.h"
end_include

begin_include
include|#
directive|include
file|"DebugHandlerBase.h"
end_include

begin_include
include|#
directive|include
file|"DebugLocStream.h"
end_include

begin_include
include|#
directive|include
file|"DwarfAccelTable.h"
end_include

begin_include
include|#
directive|include
file|"DwarfFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
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
file|"llvm/CodeGen/DIE.h"
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
file|"llvm/MC/MCDwarf.h"
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
file|"llvm/Target/TargetOptions.h"
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
name|DebugLocEntry
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
comment|/// This class is used to track local variable information.
comment|///
comment|/// Variables can be created from allocas, in which case they're generated from
comment|/// the MMI table.  Such variables can have multiple expressions and frame
comment|/// indices.
comment|///
comment|/// Variables can be created from \c DBG_VALUE instructions.  Those whose
comment|/// location changes over time use \a DebugLocListIndex, while those with a
comment|/// single instruction use \a MInsn and (optionally) a single entry of \a Expr.
comment|///
comment|/// Variables that have been optimized out use none of these fields.
name|class
name|DbgVariable
block|{
specifier|const
name|DILocalVariable
modifier|*
name|Var
decl_stmt|;
comment|/// Variable Descriptor.
specifier|const
name|DILocation
modifier|*
name|IA
decl_stmt|;
comment|/// Inlined at location.
name|DIE
modifier|*
name|TheDIE
init|=
name|nullptr
decl_stmt|;
comment|/// Variable DIE.
name|unsigned
name|DebugLocListIndex
init|=
operator|~
literal|0u
decl_stmt|;
comment|/// Offset in DebugLocs.
specifier|const
name|MachineInstr
modifier|*
name|MInsn
init|=
name|nullptr
decl_stmt|;
comment|/// DBG_VALUE instruction.
struct|struct
name|FrameIndexExpr
block|{
name|int
name|FI
decl_stmt|;
specifier|const
name|DIExpression
modifier|*
name|Expr
decl_stmt|;
block|}
struct|;
name|mutable
name|SmallVector
operator|<
name|FrameIndexExpr
operator|,
literal|1
operator|>
name|FrameIndexExprs
expr_stmt|;
comment|/// Frame index + expression.
name|public
label|:
comment|/// Construct a DbgVariable.
comment|///
comment|/// Creates a variable without any DW_AT_location.  Call \a initializeMMI()
comment|/// for MMI entries, or \a initializeDbgValue() for DBG_VALUE instructions.
name|DbgVariable
argument_list|(
specifier|const
name|DILocalVariable
operator|*
name|V
argument_list|,
specifier|const
name|DILocation
operator|*
name|IA
argument_list|)
operator|:
name|Var
argument_list|(
name|V
argument_list|)
operator|,
name|IA
argument_list|(
argument|IA
argument_list|)
block|{}
comment|/// Initialize from the MMI table.
name|void
name|initializeMMI
argument_list|(
argument|const DIExpression *E
argument_list|,
argument|int FI
argument_list|)
block|{
name|assert
argument_list|(
name|FrameIndexExprs
operator|.
name|empty
argument_list|()
operator|&&
literal|"Already initialized?"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|MInsn
operator|&&
literal|"Already initialized?"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
operator|!
name|E
operator|||
name|E
operator|->
name|isValid
argument_list|()
operator|)
operator|&&
literal|"Expected valid expression"
argument_list|)
block|;
name|assert
argument_list|(
name|FI
operator|!=
name|INT_MAX
operator|&&
literal|"Expected valid index"
argument_list|)
block|;
name|FrameIndexExprs
operator|.
name|push_back
argument_list|(
block|{
name|FI
block|,
name|E
block|}
argument_list|)
block|;   }
comment|/// Initialize from a DBG_VALUE instruction.
name|void
name|initializeDbgValue
argument_list|(
argument|const MachineInstr *DbgValue
argument_list|)
block|{
name|assert
argument_list|(
name|FrameIndexExprs
operator|.
name|empty
argument_list|()
operator|&&
literal|"Already initialized?"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|MInsn
operator|&&
literal|"Already initialized?"
argument_list|)
block|;
name|assert
argument_list|(
name|Var
operator|==
name|DbgValue
operator|->
name|getDebugVariable
argument_list|()
operator|&&
literal|"Wrong variable"
argument_list|)
block|;
name|assert
argument_list|(
name|IA
operator|==
name|DbgValue
operator|->
name|getDebugLoc
argument_list|()
operator|->
name|getInlinedAt
argument_list|()
operator|&&
literal|"Wrong inlined-at"
argument_list|)
block|;
name|MInsn
operator|=
name|DbgValue
block|;
if|if
condition|(
name|auto
operator|*
name|E
operator|=
name|DbgValue
operator|->
name|getDebugExpression
argument_list|()
condition|)
if|if
condition|(
name|E
operator|->
name|getNumElements
argument_list|()
condition|)
name|FrameIndexExprs
operator|.
name|push_back
argument_list|(
block|{
literal|0
block|,
name|E
block|}
argument_list|)
expr_stmt|;
block|}
comment|// Accessors.
specifier|const
name|DILocalVariable
operator|*
name|getVariable
argument_list|()
specifier|const
block|{
return|return
name|Var
return|;
block|}
specifier|const
name|DILocation
operator|*
name|getInlinedAt
argument_list|()
specifier|const
block|{
return|return
name|IA
return|;
block|}
specifier|const
name|DIExpression
operator|*
name|getSingleExpression
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|MInsn
operator|&&
name|FrameIndexExprs
operator|.
name|size
argument_list|()
operator|<=
literal|1
argument_list|)
block|;
return|return
name|FrameIndexExprs
operator|.
name|size
argument_list|()
condition|?
name|FrameIndexExprs
index|[
literal|0
index|]
operator|.
name|Expr
else|:
name|nullptr
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
name|setDebugLocListIndex
parameter_list|(
name|unsigned
name|O
parameter_list|)
block|{
name|DebugLocListIndex
operator|=
name|O
expr_stmt|;
block|}
name|unsigned
name|getDebugLocListIndex
argument_list|()
specifier|const
block|{
return|return
name|DebugLocListIndex
return|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Var
operator|->
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
comment|/// Get the FI entries, sorted by fragment offset.
name|ArrayRef
operator|<
name|FrameIndexExpr
operator|>
name|getFrameIndexExprs
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasFrameIndexExprs
argument_list|()
specifier|const
block|{
return|return
operator|!
name|FrameIndexExprs
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|addMMIEntry
parameter_list|(
specifier|const
name|DbgVariable
modifier|&
name|V
parameter_list|)
block|{
name|assert
argument_list|(
name|DebugLocListIndex
operator|==
operator|~
literal|0U
operator|&&
operator|!
name|MInsn
operator|&&
literal|"not an MMI entry"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|V
operator|.
name|DebugLocListIndex
operator|==
operator|~
literal|0U
operator|&&
operator|!
name|V
operator|.
name|MInsn
operator|&&
literal|"not an MMI entry"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|V
operator|.
name|Var
operator|==
name|Var
operator|&&
literal|"conflicting variable"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|V
operator|.
name|IA
operator|==
name|IA
operator|&&
literal|"conflicting inlined-at location"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|FrameIndexExprs
operator|.
name|empty
argument_list|()
operator|&&
literal|"Expected an MMI entry"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|V
operator|.
name|FrameIndexExprs
operator|.
name|empty
argument_list|()
operator|&&
literal|"Expected an MMI entry"
argument_list|)
expr_stmt|;
name|FrameIndexExprs
operator|.
name|append
argument_list|(
name|V
operator|.
name|FrameIndexExprs
operator|.
name|begin
argument_list|()
argument_list|,
name|V
operator|.
name|FrameIndexExprs
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|all_of
argument_list|(
name|FrameIndexExprs
argument_list|,
index|[]
operator|(
name|FrameIndexExpr
operator|&
name|FIE
operator|)
block|{
return|return
name|FIE
operator|.
name|Expr
operator|&&
name|FIE
operator|.
name|Expr
operator|->
name|isFragment
argument_list|()
return|;
block|}
block|)
function|&&            "conflicting locations for variable"
block|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Translate tag to proper Dwarf tag.
end_comment

begin_expr_stmt
name|dwarf
operator|::
name|Tag
name|getTag
argument_list|()
specifier|const
block|{
comment|// FIXME: Why don't we just infer this tag and store it all along?
if|if
condition|(
name|Var
operator|->
name|isParameter
argument_list|()
condition|)
return|return
name|dwarf
operator|::
name|DW_TAG_formal_parameter
return|;
end_expr_stmt

begin_return
return|return
name|dwarf
operator|::
name|DW_TAG_variable
return|;
end_return

begin_comment
unit|}
comment|/// Return true if DbgVariable is artificial.
end_comment

begin_macro
unit|bool
name|isArtificial
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|Var
operator|->
name|isArtificial
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
operator|->
name|isArtificial
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
name|isObjectPointer
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|Var
operator|->
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
operator|->
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
name|hasComplexAddress
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
name|assert
argument_list|(
name|MInsn
operator|&&
literal|"Expected DBG_VALUE, not MMI variable"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|FrameIndexExprs
operator|.
name|empty
argument_list|()
operator|||
operator|(
name|FrameIndexExprs
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
name|FrameIndexExprs
index|[
literal|0
index|]
operator|.
name|Expr
operator|->
name|getNumElements
argument_list|()
operator|)
operator|)
operator|&&
literal|"Invalid Expr for DBG_VALUE"
argument_list|)
block|;
return|return
operator|!
name|FrameIndexExprs
operator|.
name|empty
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
specifier|const
name|DIType
operator|*
name|getType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
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
end_expr_stmt

begin_comment
unit|};
comment|/// Helper used to pair up a symbol and its DWARF compile unit.
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
comment|/// Collects and handles dwarf debug information.
end_comment

begin_decl_stmt
name|class
name|DwarfDebug
range|:
name|public
name|DebugHandlerBase
block|{
comment|/// All DIEValues are allocated through this allocator.
name|BumpPtrAllocator
name|DIEValueAllocator
block|;
comment|/// Maps MDNode with its corresponding DwarfCompileUnit.
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
comment|/// Maps a CU DIE with its corresponding DwarfCompileUnit.
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
comment|/// List of all labels used in aranges generation.
name|std
operator|::
name|vector
operator|<
name|SymbolCU
operator|>
name|ArangeLabels
block|;
comment|/// Size of each symbol emitted (for those symbols that have a specific size).
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
comment|/// Collection of abstract variables.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
block|,
name|std
operator|::
name|unique_ptr
operator|<
name|DbgVariable
operator|>>
name|AbstractVariables
block|;
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DbgVariable
operator|>
block|,
literal|64
operator|>
name|ConcreteVariables
block|;
comment|/// Collection of DebugLocEntry. Stored in a linked list so that DIELocLists
comment|/// can refer to them in spite of insertions into this list.
name|DebugLocStream
name|DebugLocs
block|;
comment|/// This is a collection of subprogram MDNodes that are processed to
comment|/// create DIEs.
name|SetVector
operator|<
specifier|const
name|DISubprogram
operator|*
block|,
name|SmallVector
operator|<
specifier|const
name|DISubprogram
operator|*
block|,
literal|16
operator|>
block|,
name|SmallPtrSet
operator|<
specifier|const
name|DISubprogram
operator|*
block|,
literal|16
operator|>>
name|ProcessedSPNodes
block|;
comment|/// If nonnull, stores the current machine function we're processing.
specifier|const
name|MachineFunction
operator|*
name|CurFn
block|;
comment|/// If nonnull, stores the CU in which the previous subprogram was contained.
specifier|const
name|DwarfCompileUnit
operator|*
name|PrevCU
block|;
comment|/// As an optimization, there is no need to emit an entry in the directory
comment|/// table for the same directory as DW_AT_comp_dir.
name|StringRef
name|CompilationDir
block|;
comment|/// Holder for the file specific debug information.
name|DwarfFile
name|InfoHolder
block|;
comment|/// Holders for the various debug information flags that we might need to
comment|/// have exposed. See accessor functions below for description.
comment|/// Map from MDNodes for user-defined types to their type signatures. Also
comment|/// used to keep track of which types we have emitted type units for.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
block|,
name|uint64_t
operator|>
name|TypeSignatures
block|;
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
block|,
specifier|const
name|DICompositeType
operator|*
operator|>
block|,
literal|1
operator|>
name|TypeUnitsUnderConstruction
block|;
comment|/// Whether to emit the pubnames/pubtypes sections.
name|bool
name|HasDwarfPubSections
block|;
comment|/// Whether to use the GNU TLS opcode (instead of the standard opcode).
name|bool
name|UseGNUTLSOpcode
block|;
comment|/// Whether to use DWARF 2 bitfields (instead of the DWARF 4 format).
name|bool
name|UseDWARF2Bitfields
block|;
comment|/// Whether to emit all linkage names, or just abstract subprograms.
name|bool
name|UseAllLinkageNames
block|;
comment|/// DWARF5 Experimental Options
comment|/// @{
name|bool
name|HasDwarfAccelTables
block|;
name|bool
name|HasAppleExtensionAttributes
block|;
name|bool
name|HasSplitDwarf
block|;
comment|/// Separated Dwarf Variables
comment|/// In general these will all be for bits that are left in the
comment|/// original object file, rather than things that are meant
comment|/// to be in the .dwo sections.
comment|/// Holder for the skeleton information.
name|DwarfFile
name|SkeletonHolder
block|;
comment|/// Store file names for type units under fission in a line table
comment|/// header that will be emitted into debug_line.dwo.
comment|// FIXME: replace this with a map from comp_dir to table so that we
comment|// can emit multiple tables during LTO each of which uses directory
comment|// 0, referencing the comp_dir of all the type units that use it.
name|MCDwarfDwoLineTable
name|SplitTypeUnitFileTable
block|;
comment|/// @}
comment|/// True iff there are multiple CUs in this module.
name|bool
name|SingleCU
block|;
name|bool
name|IsDarwin
block|;
name|AddressPool
name|AddrPool
block|;
name|DwarfAccelTable
name|AccelNames
block|;
name|DwarfAccelTable
name|AccelObjC
block|;
name|DwarfAccelTable
name|AccelNamespace
block|;
name|DwarfAccelTable
name|AccelTypes
block|;
comment|// Identify a debugger for "tuning" the debug info.
name|DebuggerKind
name|DebuggerTuning
block|;
comment|/// \defgroup DebuggerTuning Predicates to tune DWARF for a given debugger.
comment|///
comment|/// Returns whether we are "tuning" for a given debugger.
comment|/// Should be used only within the constructor, to set feature flags.
comment|/// @{
name|bool
name|tuneForGDB
argument_list|()
specifier|const
block|{
return|return
name|DebuggerTuning
operator|==
name|DebuggerKind
operator|::
name|GDB
return|;
block|}
name|bool
name|tuneForLLDB
argument_list|()
specifier|const
block|{
return|return
name|DebuggerTuning
operator|==
name|DebuggerKind
operator|::
name|LLDB
return|;
block|}
name|bool
name|tuneForSCE
argument_list|()
specifier|const
block|{
return|return
name|DebuggerTuning
operator|==
name|DebuggerKind
operator|::
name|SCE
return|;
block|}
comment|/// @}
name|MCDwarfDwoLineTable
operator|*
name|getDwoLineTable
argument_list|(
specifier|const
name|DwarfCompileUnit
operator|&
argument_list|)
block|;
specifier|const
name|SmallVectorImpl
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DwarfCompileUnit
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
typedef|typedef
name|DbgValueHistoryMap
operator|::
name|InlinedVariable
name|InlinedVariable
expr_stmt|;
comment|/// Find abstract variable associated with Var.
name|DbgVariable
operator|*
name|getExistingAbstractVariable
argument_list|(
argument|InlinedVariable IV
argument_list|,
argument|const DILocalVariable *&Cleansed
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|DbgVariable
modifier|*
name|getExistingAbstractVariable
parameter_list|(
name|InlinedVariable
name|IV
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|createAbstractVariable
parameter_list|(
specifier|const
name|DILocalVariable
modifier|*
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
name|InlinedVariable
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
name|InlinedVariable
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
name|DbgVariable
modifier|*
name|createConcreteVariable
parameter_list|(
name|LexicalScope
modifier|&
name|Scope
parameter_list|,
name|InlinedVariable
name|IV
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Construct a DIE for this abstract scope.
end_comment

begin_function_decl
name|void
name|constructAbstractSubprogramScopeDIE
parameter_list|(
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
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
comment|/// Finish off debug information after all functions have been
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
comment|/// Emit the debug info section.
end_comment

begin_function_decl
name|void
name|emitDebugInfo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit the abbreviation section.
end_comment

begin_function_decl
name|void
name|emitAbbreviations
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit a specified accelerator table.
end_comment

begin_function_decl
name|void
name|emitAccel
parameter_list|(
name|DwarfAccelTable
modifier|&
name|Accel
parameter_list|,
name|MCSection
modifier|*
name|Section
parameter_list|,
name|StringRef
name|TableName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit visible names into a hashed accelerator table section.
end_comment

begin_function_decl
name|void
name|emitAccelNames
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit objective C classes and categories into a hashed
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
comment|/// Emit namespace dies into a hashed accelerator table.
end_comment

begin_function_decl
name|void
name|emitAccelNamespaces
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit type dies into a hashed accelerator table.
end_comment

begin_function_decl
name|void
name|emitAccelTypes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit visible names into a debug pubnames section.
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
comment|/// Emit visible types into a debug pubtypes section.
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
name|DwarfCompileUnit
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
comment|/// Emit null-terminated strings into a debug str section.
end_comment

begin_function_decl
name|void
name|emitDebugStr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit variable locations into a debug loc section.
end_comment

begin_function_decl
name|void
name|emitDebugLoc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit variable locations into a debug loc dwo section.
end_comment

begin_function_decl
name|void
name|emitDebugLocDWO
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit address ranges into a debug aranges section.
end_comment

begin_function_decl
name|void
name|emitDebugARanges
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit address ranges into a debug ranges section.
end_comment

begin_function_decl
name|void
name|emitDebugRanges
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit macros into a debug macinfo section.
end_comment

begin_function_decl
name|void
name|emitDebugMacinfo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emitMacro
parameter_list|(
name|DIMacro
modifier|&
name|M
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emitMacroFile
parameter_list|(
name|DIMacroFile
modifier|&
name|F
parameter_list|,
name|DwarfCompileUnit
modifier|&
name|U
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|handleMacroNodes
parameter_list|(
name|DIMacroNodeArray
name|Nodes
parameter_list|,
name|DwarfCompileUnit
modifier|&
name|U
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DWARF 5 Experimental Split Dwarf Emitters
end_comment

begin_comment
comment|/// Initialize common features of skeleton units.
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
name|DwarfCompileUnit
operator|>
name|NewU
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Construct the split debug info compile unit for the debug info
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
comment|/// Emit the debug info dwo section.
end_comment

begin_function_decl
name|void
name|emitDebugInfoDWO
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit the debug abbrev dwo section.
end_comment

begin_function_decl
name|void
name|emitDebugAbbrevDWO
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit the debug line dwo section.
end_comment

begin_function_decl
name|void
name|emitDebugLineDWO
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit the debug str dwo section.
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
comment|/// Create new DwarfCompileUnit for the given metadata node with tag
end_comment

begin_comment
comment|/// DW_TAG_compile_unit.
end_comment

begin_function_decl
name|DwarfCompileUnit
modifier|&
name|constructDwarfCompileUnit
parameter_list|(
specifier|const
name|DICompileUnit
modifier|*
name|DIUnit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Construct imported_module or imported_declaration DIE.
end_comment

begin_function_decl
name|void
name|constructAndAddImportedEntityDIE
parameter_list|(
name|DwarfCompileUnit
modifier|&
name|TheCU
parameter_list|,
specifier|const
name|DIImportedEntity
modifier|*
name|N
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Register a source line with debug info. Returns the unique
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
comment|/// Populate LexicalScope entries with variables' info.
end_comment

begin_decl_stmt
name|void
name|collectVariableInfo
argument_list|(
name|DwarfCompileUnit
operator|&
name|TheCU
argument_list|,
specifier|const
name|DISubprogram
operator|*
name|SP
argument_list|,
name|DenseSet
operator|<
name|InlinedVariable
operator|>
operator|&
name|ProcessedVars
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Build the location list for all DBG_VALUEs in the
end_comment

begin_comment
comment|/// function that describe the same variable.
end_comment

begin_decl_stmt
name|void
name|buildLocationList
argument_list|(
name|SmallVectorImpl
operator|<
name|DebugLocEntry
operator|>
operator|&
name|DebugLoc
argument_list|,
specifier|const
name|DbgValueHistoryMap
operator|::
name|InstrRanges
operator|&
name|Ranges
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Collect variable information from the side table maintained by MF.
end_comment

begin_decl_stmt
name|void
name|collectVariableInfoFromMFTable
argument_list|(
name|DenseSet
operator|<
name|InlinedVariable
operator|>
operator|&
name|P
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Gather pre-function debug information.
end_comment

begin_decl_stmt
name|void
name|beginFunctionImpl
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
comment|/// Gather and emit post-function debug information.
end_comment

begin_decl_stmt
name|void
name|endFunctionImpl
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|skippedNonDebugFunction
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

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

begin_comment
comment|/// Emit all Dwarf sections that should come prior to the
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
comment|/// Emit all Dwarf sections that should come after the content.
end_comment

begin_expr_stmt
name|void
name|endModule
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Process beginning of an instruction.
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
comment|/// Perform an MD5 checksum of \p Identifier and return the lower 64 bits.
end_comment

begin_function_decl
specifier|static
name|uint64_t
name|makeTypeSignature
parameter_list|(
name|StringRef
name|Identifier
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Add a DIE to the set of types that we're going to pull into
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
specifier|const
name|DICompositeType
modifier|*
name|CTy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Add a label so that arange data can be generated for it.
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
comment|/// For symbols that have a size designated (e.g. common symbols),
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
comment|/// Returns whether we should emit all DW_AT_[MIPS_]linkage_name.
end_comment

begin_comment
comment|/// If not, we still might emit certain cases.
end_comment

begin_expr_stmt
name|bool
name|useAllLinkageNames
argument_list|()
specifier|const
block|{
return|return
name|UseAllLinkageNames
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns whether to use DW_OP_GNU_push_tls_address, instead of the
end_comment

begin_comment
comment|/// standard DW_OP_form_tls_address opcode
end_comment

begin_expr_stmt
name|bool
name|useGNUTLSOpcode
argument_list|()
specifier|const
block|{
return|return
name|UseGNUTLSOpcode
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns whether to use the DWARF2 format for bitfields instyead of the
end_comment

begin_comment
comment|/// DWARF4 format.
end_comment

begin_expr_stmt
name|bool
name|useDWARF2Bitfields
argument_list|()
specifier|const
block|{
return|return
name|UseDWARF2Bitfields
return|;
block|}
end_expr_stmt

begin_comment
comment|// Experimental DWARF5 features.
end_comment

begin_comment
comment|/// Returns whether or not to emit tables that dwarf consumers can
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

begin_expr_stmt
name|bool
name|useAppleExtensionAttributes
argument_list|()
specifier|const
block|{
return|return
name|HasAppleExtensionAttributes
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns whether or not to change the current debug info for the
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
name|uint16_t
name|getDwarfVersion
argument_list|()
specifier|const
expr_stmt|;
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

begin_function
name|void
name|setPrevCU
parameter_list|(
specifier|const
name|DwarfCompileUnit
modifier|*
name|PrevCU
parameter_list|)
block|{
name|this
operator|->
name|PrevCU
operator|=
name|PrevCU
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Returns the entries for the .debug_loc section.
end_comment

begin_expr_stmt
specifier|const
name|DebugLocStream
operator|&
name|getDebugLocs
argument_list|()
specifier|const
block|{
return|return
name|DebugLocs
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Emit an entry for the debug loc section. This can be used to
end_comment

begin_comment
comment|/// handle an entry that's going to be emitted into the debug loc section.
end_comment

begin_decl_stmt
name|void
name|emitDebugLocEntry
argument_list|(
name|ByteStreamer
operator|&
name|Streamer
argument_list|,
specifier|const
name|DebugLocStream
operator|::
name|Entry
operator|&
name|Entry
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit the location for a debug loc entry, including the size header.
end_comment

begin_decl_stmt
name|void
name|emitDebugLocEntryLocation
argument_list|(
specifier|const
name|DebugLocStream
operator|::
name|Entry
operator|&
name|Entry
argument_list|)
decl_stmt|;
end_decl_stmt

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
end_expr_stmt

begin_function_decl
name|void
name|addSubprogramNames
parameter_list|(
specifier|const
name|DISubprogram
modifier|*
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

begin_expr_stmt
specifier|const
name|MachineFunction
operator|*
name|getCurrentFunction
argument_list|()
specifier|const
block|{
return|return
name|CurFn
return|;
block|}
end_expr_stmt

begin_comment
comment|/// A helper function to check whether the DIE for a given Scope is
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
unit|}; }
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Loads.h - Local load analysis --------------------------------------===//
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
comment|// This file declares simple local analyses for load instructions.
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
name|LLVM_ANALYSIS_LOADS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOADS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DataLayout
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
comment|/// isDereferenceablePointer - Return true if this is always a dereferenceable
comment|/// pointer. If the context instruction is specified perform context-sensitive
comment|/// analysis and return true if the pointer is dereferenceable at the
comment|/// specified instruction.
name|bool
name|isDereferenceablePointer
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CtxI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Returns true if V is always a dereferenceable pointer with alignment
comment|/// greater or equal than requested. If the context instruction is specified
comment|/// performs context-sensitive analysis and returns true if the pointer is
comment|/// dereferenceable at the specified instruction.
name|bool
name|isDereferenceableAndAlignedPointer
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|unsigned
name|Align
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|CtxI
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// isSafeToLoadUnconditionally - Return true if we know that executing a load
comment|/// from this value cannot trap.
comment|///
comment|/// If DT and ScanFrom are specified this method performs context-sensitive
comment|/// analysis and returns true if it is safe to load immediately before ScanFrom.
comment|///
comment|/// If it is not obviously safe to load from the specified pointer, we do a
comment|/// quick local scan of the basic block containing ScanFrom, to determine if
comment|/// the address is already accessed.
name|bool
name|isSafeToLoadUnconditionally
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|unsigned
name|Align
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|Instruction
modifier|*
name|ScanFrom
init|=
name|nullptr
parameter_list|,
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// DefMaxInstsToScan - the default number of maximum instructions
comment|/// to scan in the block, used by FindAvailableLoadedValue().
extern|extern cl::opt<unsigned> DefMaxInstsToScan;
comment|/// \brief Scan backwards to see if we have the value of the given load
comment|/// available locally within a small number of instructions.
comment|///
comment|/// You can use this function to scan across multiple blocks: after you call
comment|/// this function, if ScanFrom points at the beginning of the block, it's safe
comment|/// to continue scanning the predecessors.
comment|///
comment|/// Note that performing load CSE requires special care to make sure the
comment|/// metadata is set appropriately.  In particular, aliasing metadata needs
comment|/// to be merged.  (This doesn't matter for store-to-load forwarding because
comment|/// the only relevant load gets deleted.)
comment|///
comment|/// \param Load The load we want to replace.
comment|/// \param ScanBB The basic block to scan. FIXME: This is redundant.
comment|/// \param [in,out] ScanFrom The location to start scanning from. When this
comment|/// function returns, it points at the last instruction scanned.
comment|/// \param MaxInstsToScan The maximum number of instructions to scan. If this
comment|/// is zero, the whole block will be scanned.
comment|/// \param AA Optional pointer to alias analysis, to make the scan more
comment|/// precise.
comment|/// \param [out] AATags The aliasing metadata for the operation which produced
comment|/// the value. FIXME: This is basically useless.
comment|/// \param [out] IsLoadCSE Whether the returned value is a load from the same
comment|/// location in memory, as opposed to the value operand of a store.
comment|///
comment|/// \returns The found value, or nullptr if no value is found.
name|Value
modifier|*
name|FindAvailableLoadedValue
argument_list|(
name|LoadInst
operator|*
name|Load
argument_list|,
name|BasicBlock
operator|*
name|ScanBB
argument_list|,
name|BasicBlock
operator|::
name|iterator
operator|&
name|ScanFrom
argument_list|,
name|unsigned
name|MaxInstsToScan
operator|=
name|DefMaxInstsToScan
argument_list|,
name|AliasAnalysis
operator|*
name|AA
operator|=
name|nullptr
argument_list|,
name|AAMDNodes
operator|*
name|AATags
operator|=
name|nullptr
argument_list|,
name|bool
operator|*
name|IsLoadCSE
operator|=
name|nullptr
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


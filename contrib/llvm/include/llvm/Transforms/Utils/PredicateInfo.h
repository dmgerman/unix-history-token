begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PredicateInfo.h - Build PredicateInfo ----------------------*-C++-*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief  This file implements the PredicateInfo analysis, which creates an Extended
end_comment

begin_comment
comment|/// SSA form for operations used in branch comparisons and llvm.assume
end_comment

begin_comment
comment|/// comparisons.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Copies of these operations are inserted into the true/false edge (and after
end_comment

begin_comment
comment|/// assumes), and information attached to the copies.  All uses of the original
end_comment

begin_comment
comment|/// operation in blocks dominated by the true/false edge (and assume), are
end_comment

begin_comment
comment|/// replaced with uses of the copies.  This enables passes to easily and sparsely
end_comment

begin_comment
comment|/// propagate condition based info into the operations that may be affected.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Example:
end_comment

begin_comment
comment|/// %cmp = icmp eq i32 %x, 50
end_comment

begin_comment
comment|/// br i1 %cmp, label %true, label %false
end_comment

begin_comment
comment|/// true:
end_comment

begin_comment
comment|/// ret i32 %x
end_comment

begin_comment
comment|/// false:
end_comment

begin_comment
comment|/// ret i32 1
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// will become
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// %cmp = icmp eq i32, %x, 50
end_comment

begin_comment
comment|/// br i1 %cmp, label %true, label %false
end_comment

begin_comment
comment|/// true:
end_comment

begin_comment
comment|/// %x.0 = call @llvm.ssa_copy.i32(i32 %x)
end_comment

begin_comment
comment|/// ret i32 %x.0
end_comment

begin_comment
comment|/// false:
end_comment

begin_comment
comment|/// ret i32 1
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Using getPredicateInfoFor on x.0 will give you the comparison it is
end_comment

begin_comment
comment|/// dominated by (the icmp), and that you are located in the true edge of that
end_comment

begin_comment
comment|/// comparison, which tells you x.0 is 50.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In order to reduce the number of copies inserted, predicateinfo is only
end_comment

begin_comment
comment|/// inserted where it would actually be live.  This means if there are no uses of
end_comment

begin_comment
comment|/// an operation dominated by the branch edges, or by an assume, the associated
end_comment

begin_comment
comment|/// predicate info is never inserted.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_UTILS_PREDICATEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_PREDICATEINFO_H
end_define

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
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AssumptionCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IntrinsicInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Use.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/User.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/PassAnalysisSupport.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/OrderedInstructions.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MemoryAccess
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
enum|enum
name|PredicateType
block|{
name|PT_Branch
block|,
name|PT_Assume
block|,
name|PT_Switch
block|}
enum|;
comment|// Base class for all predicate information we provide.
comment|// All of our predicate information has at least a comparison.
name|class
name|PredicateBase
range|:
name|public
name|ilist_node
operator|<
name|PredicateBase
operator|>
block|{
name|public
operator|:
name|PredicateType
name|Type
block|;
comment|// The original operand before we renamed it.
comment|// This can be use by passes, when destroying predicateinfo, to know
comment|// whether they can just drop the intrinsic, or have to merge metadata.
name|Value
operator|*
name|OriginalOp
block|;
name|PredicateBase
argument_list|(
specifier|const
name|PredicateBase
operator|&
argument_list|)
operator|=
name|delete
block|;
name|PredicateBase
operator|&
name|operator
operator|=
operator|(
specifier|const
name|PredicateBase
operator|&
operator|)
operator|=
name|delete
block|;
name|PredicateBase
argument_list|()
operator|=
name|delete
block|;
name|virtual
operator|~
name|PredicateBase
argument_list|()
operator|=
expr|default
block|;
name|protected
operator|:
name|PredicateBase
argument_list|(
argument|PredicateType PT
argument_list|,
argument|Value *Op
argument_list|)
operator|:
name|Type
argument_list|(
name|PT
argument_list|)
block|,
name|OriginalOp
argument_list|(
argument|Op
argument_list|)
block|{}
block|}
decl_stmt|;
name|class
name|PredicateWithCondition
range|:
name|public
name|PredicateBase
block|{
name|public
operator|:
name|Value
operator|*
name|Condition
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const PredicateBase *PB
argument_list|)
block|{
return|return
name|PB
operator|->
name|Type
operator|==
name|PT_Assume
operator|||
name|PB
operator|->
name|Type
operator|==
name|PT_Branch
operator|||
name|PB
operator|->
name|Type
operator|==
name|PT_Switch
return|;
block|}
name|protected
operator|:
name|PredicateWithCondition
argument_list|(
argument|PredicateType PT
argument_list|,
argument|Value *Op
argument_list|,
argument|Value *Condition
argument_list|)
operator|:
name|PredicateBase
argument_list|(
name|PT
argument_list|,
name|Op
argument_list|)
block|,
name|Condition
argument_list|(
argument|Condition
argument_list|)
block|{}
block|}
decl_stmt|;
comment|// Provides predicate information for assumes.  Since assumes are always true,
comment|// we simply provide the assume instruction, so you can tell your relative
comment|// position to it.
name|class
name|PredicateAssume
range|:
name|public
name|PredicateWithCondition
block|{
name|public
operator|:
name|IntrinsicInst
operator|*
name|AssumeInst
block|;
name|PredicateAssume
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
name|IntrinsicInst
operator|*
name|AssumeInst
argument_list|,
name|Value
operator|*
name|Condition
argument_list|)
operator|:
name|PredicateWithCondition
argument_list|(
name|PT_Assume
argument_list|,
name|Op
argument_list|,
name|Condition
argument_list|)
block|,
name|AssumeInst
argument_list|(
argument|AssumeInst
argument_list|)
block|{}
name|PredicateAssume
argument_list|()
operator|=
name|delete
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const PredicateBase *PB
argument_list|)
block|{
return|return
name|PB
operator|->
name|Type
operator|==
name|PT_Assume
return|;
block|}
expr|}
block|;
comment|// Mixin class for edge predicates.  The FROM block is the block where the
comment|// predicate originates, and the TO block is the block where the predicate is
comment|// valid.
name|class
name|PredicateWithEdge
operator|:
name|public
name|PredicateWithCondition
block|{
name|public
operator|:
name|BasicBlock
operator|*
name|From
block|;
name|BasicBlock
operator|*
name|To
block|;
name|PredicateWithEdge
argument_list|()
operator|=
name|delete
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const PredicateBase *PB
argument_list|)
block|{
return|return
name|PB
operator|->
name|Type
operator|==
name|PT_Branch
operator|||
name|PB
operator|->
name|Type
operator|==
name|PT_Switch
return|;
block|}
name|protected
operator|:
name|PredicateWithEdge
argument_list|(
argument|PredicateType PType
argument_list|,
argument|Value *Op
argument_list|,
argument|BasicBlock *From
argument_list|,
argument|BasicBlock *To
argument_list|,
argument|Value *Cond
argument_list|)
operator|:
name|PredicateWithCondition
argument_list|(
name|PType
argument_list|,
name|Op
argument_list|,
name|Cond
argument_list|)
block|,
name|From
argument_list|(
name|From
argument_list|)
block|,
name|To
argument_list|(
argument|To
argument_list|)
block|{}
block|}
block|;
comment|// Provides predicate information for branches.
name|class
name|PredicateBranch
operator|:
name|public
name|PredicateWithEdge
block|{
name|public
operator|:
comment|// If true, SplitBB is the true successor, otherwise it's the false successor.
name|bool
name|TrueEdge
block|;
name|PredicateBranch
argument_list|(
argument|Value *Op
argument_list|,
argument|BasicBlock *BranchBB
argument_list|,
argument|BasicBlock *SplitBB
argument_list|,
argument|Value *Condition
argument_list|,
argument|bool TakenEdge
argument_list|)
operator|:
name|PredicateWithEdge
argument_list|(
name|PT_Branch
argument_list|,
name|Op
argument_list|,
name|BranchBB
argument_list|,
name|SplitBB
argument_list|,
name|Condition
argument_list|)
block|,
name|TrueEdge
argument_list|(
argument|TakenEdge
argument_list|)
block|{}
name|PredicateBranch
argument_list|()
operator|=
name|delete
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const PredicateBase *PB
argument_list|)
block|{
return|return
name|PB
operator|->
name|Type
operator|==
name|PT_Branch
return|;
block|}
expr|}
block|;
name|class
name|PredicateSwitch
operator|:
name|public
name|PredicateWithEdge
block|{
name|public
operator|:
name|Value
operator|*
name|CaseValue
block|;
comment|// This is the switch instruction.
name|SwitchInst
operator|*
name|Switch
block|;
name|PredicateSwitch
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
name|BasicBlock
operator|*
name|SwitchBB
argument_list|,
name|BasicBlock
operator|*
name|TargetBB
argument_list|,
name|Value
operator|*
name|CaseValue
argument_list|,
name|SwitchInst
operator|*
name|SI
argument_list|)
operator|:
name|PredicateWithEdge
argument_list|(
name|PT_Switch
argument_list|,
name|Op
argument_list|,
name|SwitchBB
argument_list|,
name|TargetBB
argument_list|,
name|SI
operator|->
name|getCondition
argument_list|()
argument_list|)
block|,
name|CaseValue
argument_list|(
name|CaseValue
argument_list|)
block|,
name|Switch
argument_list|(
argument|SI
argument_list|)
block|{}
name|PredicateSwitch
argument_list|()
operator|=
name|delete
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const PredicateBase *PB
argument_list|)
block|{
return|return
name|PB
operator|->
name|Type
operator|==
name|PT_Switch
return|;
block|}
expr|}
block|;
comment|// This name is used in a few places, so kick it into their own namespace
name|namespace
name|PredicateInfoClasses
block|{ struct
name|ValueDFS
block|; }
comment|/// \brief Encapsulates PredicateInfo, including all data associated with memory
comment|/// accesses.
name|class
name|PredicateInfo
block|{
name|private
operator|:
comment|// Used to store information about each value we might rename.
expr|struct
name|ValueInfo
block|{
comment|// Information about each possible copy. During processing, this is each
comment|// inserted info. After processing, we move the uninserted ones to the
comment|// uninserted vector.
name|SmallVector
operator|<
name|PredicateBase
operator|*
block|,
literal|4
operator|>
name|Infos
block|;
name|SmallVector
operator|<
name|PredicateBase
operator|*
block|,
literal|4
operator|>
name|UninsertedInfos
block|;   }
block|;
comment|// This owns the all the predicate infos in the function, placed or not.
name|iplist
operator|<
name|PredicateBase
operator|>
name|AllInfos
block|;
name|public
operator|:
name|PredicateInfo
argument_list|(
name|Function
operator|&
argument_list|,
name|DominatorTree
operator|&
argument_list|,
name|AssumptionCache
operator|&
argument_list|)
block|;
operator|~
name|PredicateInfo
argument_list|()
block|;
name|void
name|verifyPredicateInfo
argument_list|()
specifier|const
block|;
name|void
name|dump
argument_list|()
specifier|const
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&
argument_list|)
specifier|const
block|;
specifier|const
name|PredicateBase
operator|*
name|getPredicateInfoFor
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
block|{
return|return
name|PredicateMap
operator|.
name|lookup
argument_list|(
name|V
argument_list|)
return|;
block|}
name|protected
operator|:
comment|// Used by PredicateInfo annotater, dumpers, and wrapper pass.
name|friend
name|class
name|PredicateInfoAnnotatedWriter
block|;
name|friend
name|class
name|PredicateInfoPrinterLegacyPass
block|;
name|private
operator|:
name|void
name|buildPredicateInfo
argument_list|()
block|;
name|void
name|processAssume
argument_list|(
name|IntrinsicInst
operator|*
argument_list|,
name|BasicBlock
operator|*
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Value
operator|*
operator|>
operator|&
argument_list|)
block|;
name|void
name|processBranch
argument_list|(
name|BranchInst
operator|*
argument_list|,
name|BasicBlock
operator|*
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Value
operator|*
operator|>
operator|&
argument_list|)
block|;
name|void
name|processSwitch
argument_list|(
name|SwitchInst
operator|*
argument_list|,
name|BasicBlock
operator|*
argument_list|,
name|SmallPtrSetImpl
operator|<
name|Value
operator|*
operator|>
operator|&
argument_list|)
block|;
name|void
name|renameUses
argument_list|(
name|SmallPtrSetImpl
operator|<
name|Value
operator|*
operator|>
operator|&
argument_list|)
block|;
name|using
name|ValueDFS
operator|=
name|PredicateInfoClasses
operator|::
name|ValueDFS
block|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|ValueDFS
operator|>
name|ValueDFSStack
expr_stmt|;
name|void
name|convertUsesToDFSOrdered
argument_list|(
name|Value
operator|*
argument_list|,
name|SmallVectorImpl
operator|<
name|ValueDFS
operator|>
operator|&
argument_list|)
block|;
name|Value
operator|*
name|materializeStack
argument_list|(
argument|unsigned int&
argument_list|,
argument|ValueDFSStack&
argument_list|,
argument|Value *
argument_list|)
block|;
name|bool
name|stackIsInScope
argument_list|(
argument|const ValueDFSStack&
argument_list|,
argument|const ValueDFS&
argument_list|)
specifier|const
block|;
name|void
name|popStackUntilDFSScope
argument_list|(
name|ValueDFSStack
operator|&
argument_list|,
specifier|const
name|ValueDFS
operator|&
argument_list|)
block|;
name|ValueInfo
operator|&
name|getOrCreateValueInfo
argument_list|(
name|Value
operator|*
argument_list|)
block|;
name|void
name|addInfoFor
argument_list|(
name|SmallPtrSetImpl
operator|<
name|Value
operator|*
operator|>
operator|&
name|OpsToRename
argument_list|,
name|Value
operator|*
name|Op
argument_list|,
name|PredicateBase
operator|*
name|PB
argument_list|)
block|;
specifier|const
name|ValueInfo
operator|&
name|getValueInfo
argument_list|(
argument|Value *
argument_list|)
specifier|const
block|;
name|Function
operator|&
name|F
block|;
name|DominatorTree
operator|&
name|DT
block|;
name|AssumptionCache
operator|&
name|AC
block|;
name|OrderedInstructions
name|OI
block|;
comment|// This maps from copy operands to Predicate Info. Note that it does not own
comment|// the Predicate Info, they belong to the ValueInfo structs in the ValueInfos
comment|// vector.
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
block|,
specifier|const
name|PredicateBase
operator|*
operator|>
name|PredicateMap
block|;
comment|// This stores info about each operand or comparison result we make copies
comment|// of.  The real ValueInfos start at index 1, index 0 is unused so that we can
comment|// more easily detect invalid indexing.
name|SmallVector
operator|<
name|ValueInfo
block|,
literal|32
operator|>
name|ValueInfos
block|;
comment|// This gives the index into the ValueInfos array for a given Value.  Because
comment|// 0 is not a valid Value Info index, you can use DenseMap::lookup and tell
comment|// whether it returned a valid result.
name|DenseMap
operator|<
name|Value
operator|*
block|,
name|unsigned
name|int
operator|>
name|ValueInfoNums
block|;
comment|// The set of edges along which we can only handle phi uses, due to critical
comment|// edges.
name|DenseSet
operator|<
name|std
operator|::
name|pair
operator|<
name|BasicBlock
operator|*
block|,
name|BasicBlock
operator|*
operator|>>
name|EdgeUsesOnly
block|; }
block|;
comment|// This pass does eager building and then printing of PredicateInfo. It is used
comment|// by
comment|// the tests to be able to build, dump, and verify PredicateInfo.
name|class
name|PredicateInfoPrinterLegacyPass
operator|:
name|public
name|FunctionPass
block|{
name|public
operator|:
name|PredicateInfoPrinterLegacyPass
argument_list|()
block|;
specifier|static
name|char
name|ID
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|; }
block|;
comment|/// \brief Printer pass for \c PredicateInfo.
name|class
name|PredicateInfoPrinterPass
operator|:
name|public
name|PassInfoMixin
operator|<
name|PredicateInfoPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|PredicateInfoPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|OS
argument_list|)
block|{}
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
block|;
comment|/// \brief Verifier pass for \c PredicateInfo.
block|struct
name|PredicateInfoVerifierPass
operator|:
name|PassInfoMixin
operator|<
name|PredicateInfoVerifierPass
operator|>
block|{
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_UTILS_PREDICATEINFO_H
end_comment

end_unit


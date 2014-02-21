begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- llvm/Analysis/ScalarEvolutionExpander.h - SCEV Exprs --*- C++ -*-===//
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
comment|// This file defines the classes used to generate code from scalar expressions.
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
name|LLVM_ANALYSIS_SCALAREVOLUTIONEXPANDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_SCALAREVOLUTIONEXPANDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolutionExpressions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolutionNormalization.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TargetFolder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetTransformInfo
decl_stmt|;
comment|/// Return true if the given expression is safe to expand in the sense that
comment|/// all materialized values are safe to speculate.
name|bool
name|isSafeToExpand
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
name|ScalarEvolution
modifier|&
name|SE
parameter_list|)
function_decl|;
comment|/// SCEVExpander - This class uses information about analyze scalars to
comment|/// rewrite expressions in canonical form.
comment|///
comment|/// Clients should create an instance of this class when rewriting is needed,
comment|/// and destroy it when finished to allow the release of the associated
comment|/// memory.
name|class
name|SCEVExpander
range|:
name|public
name|SCEVVisitor
operator|<
name|SCEVExpander
decl_stmt|,
name|Value
modifier|*
decl|>
block|{
name|ScalarEvolution
modifier|&
name|SE
decl_stmt|;
comment|// New instructions receive a name to identifies them with the current pass.
specifier|const
name|char
modifier|*
name|IVName
decl_stmt|;
comment|// InsertedExpressions caches Values for reuse, so must track RAUW.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|Instruction
operator|*
operator|>
operator|,
name|TrackingVH
operator|<
name|Value
operator|>
expr|>
name|InsertedExpressions
expr_stmt|;
comment|// InsertedValues only flags inserted instructions so needs no RAUW.
name|std
operator|::
name|set
operator|<
name|AssertingVH
operator|<
name|Value
operator|>
expr|>
name|InsertedValues
expr_stmt|;
name|std
operator|::
name|set
operator|<
name|AssertingVH
operator|<
name|Value
operator|>
expr|>
name|InsertedPostIncValues
expr_stmt|;
comment|/// RelevantLoops - A memoization of the "relevant" loop for a given SCEV.
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
specifier|const
name|Loop
operator|*
operator|>
name|RelevantLoops
expr_stmt|;
comment|/// PostIncLoops - Addrecs referring to any of the given loops are expanded
comment|/// in post-inc mode. For example, expanding {1,+,1}<L> in post-inc mode
comment|/// returns the add instruction that adds one to the phi for {0,+,1}<L>,
comment|/// as opposed to a new phi starting at 1. This is only supported in
comment|/// non-canonical mode.
name|PostIncLoopSet
name|PostIncLoops
decl_stmt|;
comment|/// IVIncInsertPos - When this is non-null, addrecs expanded in the
comment|/// loop it indicates should be inserted with increments at
comment|/// IVIncInsertPos.
specifier|const
name|Loop
modifier|*
name|IVIncInsertLoop
decl_stmt|;
comment|/// IVIncInsertPos - When expanding addrecs in the IVIncInsertLoop loop,
comment|/// insert the IV increment at this position.
name|Instruction
modifier|*
name|IVIncInsertPos
decl_stmt|;
comment|/// Phis that complete an IV chain. Reuse
name|std
operator|::
name|set
operator|<
name|AssertingVH
operator|<
name|PHINode
operator|>
expr|>
name|ChainedPhis
expr_stmt|;
comment|/// CanonicalMode - When true, expressions are expanded in "canonical"
comment|/// form. In particular, addrecs are expanded as arithmetic based on
comment|/// a canonical induction variable. When false, expression are expanded
comment|/// in a more literal form.
name|bool
name|CanonicalMode
decl_stmt|;
comment|/// When invoked from LSR, the expander is in "strength reduction" mode. The
comment|/// only difference is that phi's are only reused if they are already in
comment|/// "expanded" form.
name|bool
name|LSRMode
decl_stmt|;
typedef|typedef
name|IRBuilder
operator|<
name|true
operator|,
name|TargetFolder
operator|>
name|BuilderType
expr_stmt|;
name|BuilderType
name|Builder
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
specifier|const
name|char
modifier|*
name|DebugType
decl_stmt|;
endif|#
directive|endif
name|friend
block|struct
name|SCEVVisitor
operator|<
name|SCEVExpander
operator|,
name|Value
operator|*
operator|>
expr_stmt|;
name|public
label|:
comment|/// SCEVExpander - Construct a SCEVExpander in "canonical" mode.
name|explicit
name|SCEVExpander
argument_list|(
name|ScalarEvolution
operator|&
name|se
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
operator|:
name|SE
argument_list|(
name|se
argument_list|)
operator|,
name|IVName
argument_list|(
name|name
argument_list|)
operator|,
name|IVIncInsertLoop
argument_list|(
literal|0
argument_list|)
operator|,
name|IVIncInsertPos
argument_list|(
literal|0
argument_list|)
operator|,
name|CanonicalMode
argument_list|(
name|true
argument_list|)
operator|,
name|LSRMode
argument_list|(
name|false
argument_list|)
operator|,
name|Builder
argument_list|(
argument|se.getContext()
argument_list|,
argument|TargetFolder(se.TD)
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|DebugType
operator|=
literal|""
block|;
endif|#
directive|endif
block|}
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|setDebugType
argument_list|(
argument|const char* s
argument_list|)
block|{
name|DebugType
operator|=
name|s
block|; }
endif|#
directive|endif
comment|/// clear - Erase the contents of the InsertedExpressions map so that users
comment|/// trying to expand the same expression into multiple BasicBlocks or
comment|/// different places within the same BasicBlock can do so.
name|void
name|clear
argument_list|()
block|{
name|InsertedExpressions
operator|.
name|clear
argument_list|()
block|;
name|InsertedValues
operator|.
name|clear
argument_list|()
block|;
name|InsertedPostIncValues
operator|.
name|clear
argument_list|()
block|;
name|ChainedPhis
operator|.
name|clear
argument_list|()
block|;     }
comment|/// getOrInsertCanonicalInductionVariable - This method returns the
comment|/// canonical induction variable of the specified type for the specified
comment|/// loop (inserting one if there is none).  A canonical induction variable
comment|/// starts at zero and steps by one on each iteration.
name|PHINode
operator|*
name|getOrInsertCanonicalInductionVariable
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
expr_stmt|;
comment|/// getIVIncOperand - Return the induction variable increment's IV operand.
name|Instruction
modifier|*
name|getIVIncOperand
parameter_list|(
name|Instruction
modifier|*
name|IncV
parameter_list|,
name|Instruction
modifier|*
name|InsertPos
parameter_list|,
name|bool
name|allowScale
parameter_list|)
function_decl|;
comment|/// hoistIVInc - Utility for hoisting an IV increment.
name|bool
name|hoistIVInc
parameter_list|(
name|Instruction
modifier|*
name|IncV
parameter_list|,
name|Instruction
modifier|*
name|InsertPos
parameter_list|)
function_decl|;
comment|/// replaceCongruentIVs - replace congruent phis with their most canonical
comment|/// representative. Return the number of phis eliminated.
name|unsigned
name|replaceCongruentIVs
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
specifier|const
name|DominatorTree
operator|*
name|DT
argument_list|,
name|SmallVectorImpl
operator|<
name|WeakVH
operator|>
operator|&
name|DeadInsts
argument_list|,
specifier|const
name|TargetTransformInfo
operator|*
name|TTI
operator|=
name|NULL
argument_list|)
decl_stmt|;
comment|/// expandCodeFor - Insert code to directly compute the specified SCEV
comment|/// expression into the program.  The inserted code is inserted into the
comment|/// specified block.
name|Value
modifier|*
name|expandCodeFor
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|SH
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|,
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// setIVIncInsertPos - Set the current IV increment loop and position.
name|void
name|setIVIncInsertPos
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|Instruction
modifier|*
name|Pos
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|CanonicalMode
operator|&&
literal|"IV increment positions are not supported in CanonicalMode"
argument_list|)
expr_stmt|;
name|IVIncInsertLoop
operator|=
name|L
expr_stmt|;
name|IVIncInsertPos
operator|=
name|Pos
expr_stmt|;
block|}
comment|/// setPostInc - Enable post-inc expansion for addrecs referring to the
comment|/// given loops. Post-inc expansion is only supported in non-canonical
comment|/// mode.
name|void
name|setPostInc
parameter_list|(
specifier|const
name|PostIncLoopSet
modifier|&
name|L
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|CanonicalMode
operator|&&
literal|"Post-inc expansion is not supported in CanonicalMode"
argument_list|)
expr_stmt|;
name|PostIncLoops
operator|=
name|L
expr_stmt|;
block|}
comment|/// clearPostInc - Disable all post-inc expansion.
name|void
name|clearPostInc
parameter_list|()
block|{
name|PostIncLoops
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// When we change the post-inc loop set, cached expansions may no
comment|// longer be valid.
name|InsertedPostIncValues
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// disableCanonicalMode - Disable the behavior of expanding expressions in
comment|/// canonical form rather than in a more literal form. Non-canonical mode
comment|/// is useful for late optimization passes.
name|void
name|disableCanonicalMode
parameter_list|()
block|{
name|CanonicalMode
operator|=
name|false
expr_stmt|;
block|}
name|void
name|enableLSRMode
parameter_list|()
block|{
name|LSRMode
operator|=
name|true
expr_stmt|;
block|}
comment|/// clearInsertPoint - Clear the current insertion point. This is useful
comment|/// if the instruction that had been serving as the insertion point may
comment|/// have been deleted.
name|void
name|clearInsertPoint
parameter_list|()
block|{
name|Builder
operator|.
name|ClearInsertionPoint
argument_list|()
expr_stmt|;
block|}
comment|/// isInsertedInstruction - Return true if the specified instruction was
comment|/// inserted by the code rewriter.  If so, the client should not modify the
comment|/// instruction.
name|bool
name|isInsertedInstruction
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
decl|const
block|{
return|return
name|InsertedValues
operator|.
name|count
argument_list|(
name|I
argument_list|)
operator|||
name|InsertedPostIncValues
operator|.
name|count
argument_list|(
name|I
argument_list|)
return|;
block|}
name|void
name|setChainedPhi
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|)
block|{
name|ChainedPhis
operator|.
name|insert
argument_list|(
name|PN
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|SE
operator|.
name|getContext
argument_list|()
return|;
block|}
comment|/// InsertBinop - Insert the specified binary operator, doing a small amount
comment|/// of work to avoid inserting an obviously redundant operation.
name|Value
modifier|*
name|InsertBinop
argument_list|(
name|Instruction
operator|::
name|BinaryOps
name|Opcode
argument_list|,
name|Value
operator|*
name|LHS
argument_list|,
name|Value
operator|*
name|RHS
argument_list|)
decl_stmt|;
comment|/// ReuseOrCreateCast - Arange for there to be a cast of V to Ty at IP,
comment|/// reusing an existing cast if a suitable one exists, moving an existing
comment|/// cast if a suitable one exists but isn't in the right place, or
comment|/// or creating a new one.
name|Value
modifier|*
name|ReuseOrCreateCast
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|Instruction
operator|::
name|CastOps
name|Op
argument_list|,
name|BasicBlock
operator|::
name|iterator
name|IP
argument_list|)
decl_stmt|;
comment|/// InsertNoopCastOfTo - Insert a cast of V to the specified type,
comment|/// which must be possible with a noop cast, doing what we can to
comment|/// share the casts.
name|Value
modifier|*
name|InsertNoopCastOfTo
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// expandAddToGEP - Expand a SCEVAddExpr with a pointer type into a GEP
comment|/// instead of using ptrtoint+arithmetic+inttoptr.
name|Value
modifier|*
name|expandAddToGEP
parameter_list|(
specifier|const
name|SCEV
modifier|*
specifier|const
modifier|*
name|op_begin
parameter_list|,
specifier|const
name|SCEV
modifier|*
specifier|const
modifier|*
name|op_end
parameter_list|,
name|PointerType
modifier|*
name|PTy
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|,
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
name|Value
modifier|*
name|expand
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// expandCodeFor - Insert code to directly compute the specified SCEV
comment|/// expression into the program.  The inserted code is inserted into the
comment|/// SCEVExpander's current insertion point. If a type is specified, the
comment|/// result will be expanded to have that type, with a cast if necessary.
name|Value
modifier|*
name|expandCodeFor
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|SH
parameter_list|,
name|Type
modifier|*
name|Ty
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// getRelevantLoop - Determine the most "relevant" loop for the given SCEV.
specifier|const
name|Loop
modifier|*
name|getRelevantLoop
parameter_list|(
specifier|const
name|SCEV
modifier|*
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitConstant
parameter_list|(
specifier|const
name|SCEVConstant
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
operator|->
name|getValue
argument_list|()
return|;
block|}
name|Value
modifier|*
name|visitTruncateExpr
parameter_list|(
specifier|const
name|SCEVTruncateExpr
modifier|*
name|S
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitZeroExtendExpr
parameter_list|(
specifier|const
name|SCEVZeroExtendExpr
modifier|*
name|S
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitSignExtendExpr
parameter_list|(
specifier|const
name|SCEVSignExtendExpr
modifier|*
name|S
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitAddExpr
parameter_list|(
specifier|const
name|SCEVAddExpr
modifier|*
name|S
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitMulExpr
parameter_list|(
specifier|const
name|SCEVMulExpr
modifier|*
name|S
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitUDivExpr
parameter_list|(
specifier|const
name|SCEVUDivExpr
modifier|*
name|S
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitAddRecExpr
parameter_list|(
specifier|const
name|SCEVAddRecExpr
modifier|*
name|S
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitSMaxExpr
parameter_list|(
specifier|const
name|SCEVSMaxExpr
modifier|*
name|S
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitUMaxExpr
parameter_list|(
specifier|const
name|SCEVUMaxExpr
modifier|*
name|S
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitUnknown
parameter_list|(
specifier|const
name|SCEVUnknown
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
operator|->
name|getValue
argument_list|()
return|;
block|}
name|void
name|rememberInstruction
parameter_list|(
name|Value
modifier|*
name|I
parameter_list|)
function_decl|;
name|bool
name|isNormalAddRecExprPHI
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|,
name|Instruction
modifier|*
name|IncV
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
name|bool
name|isExpandedAddRecExprPHI
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|,
name|Instruction
modifier|*
name|IncV
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
name|Value
modifier|*
name|expandAddRecExprLiterally
parameter_list|(
specifier|const
name|SCEVAddRecExpr
modifier|*
parameter_list|)
function_decl|;
name|PHINode
modifier|*
name|getAddRecExprPHILiterally
parameter_list|(
specifier|const
name|SCEVAddRecExpr
modifier|*
name|Normalized
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|Type
modifier|*
name|ExpandTy
parameter_list|,
name|Type
modifier|*
name|IntTy
parameter_list|)
function_decl|;
name|Value
modifier|*
name|expandIVInc
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|,
name|Value
modifier|*
name|StepV
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|Type
modifier|*
name|ExpandTy
parameter_list|,
name|Type
modifier|*
name|IntTy
parameter_list|,
name|bool
name|useSubtract
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


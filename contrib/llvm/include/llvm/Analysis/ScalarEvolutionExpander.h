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
file|"llvm/Analysis/TargetFolder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
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
comment|/// This class uses information about analyze scalars to
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
specifier|const
name|DataLayout
modifier|&
name|DL
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
comment|/// A memoization of the "relevant" loop for a given SCEV.
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
comment|/// \brief Addrecs referring to any of the given loops are expanded
comment|/// in post-inc mode. For example, expanding {1,+,1}<L> in post-inc mode
comment|/// returns the add instruction that adds one to the phi for {0,+,1}<L>,
comment|/// as opposed to a new phi starting at 1. This is only supported in
comment|/// non-canonical mode.
name|PostIncLoopSet
name|PostIncLoops
decl_stmt|;
comment|/// \brief When this is non-null, addrecs expanded in the loop it indicates
comment|/// should be inserted with increments at IVIncInsertPos.
specifier|const
name|Loop
modifier|*
name|IVIncInsertLoop
decl_stmt|;
comment|/// \brief When expanding addrecs in the IVIncInsertLoop loop, insert the IV
comment|/// increment at this position.
name|Instruction
modifier|*
name|IVIncInsertPos
decl_stmt|;
comment|/// \brief Phis that complete an IV chain. Reuse
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
comment|/// \brief When true, expressions are expanded in "canonical" form. In
comment|/// particular, addrecs are expanded as arithmetic based on a canonical
comment|/// induction variable. When false, expression are expanded in a more
comment|/// literal form.
name|bool
name|CanonicalMode
decl_stmt|;
comment|/// \brief When invoked from LSR, the expander is in "strength reduction"
comment|/// mode. The only difference is that phi's are only reused if they are
comment|/// already in "expanded" form.
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
comment|/// \brief Construct a SCEVExpander in "canonical" mode.
name|explicit
name|SCEVExpander
argument_list|(
name|ScalarEvolution
operator|&
name|se
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
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
name|DL
argument_list|(
name|DL
argument_list|)
operator|,
name|IVName
argument_list|(
name|name
argument_list|)
operator|,
name|IVIncInsertLoop
argument_list|(
name|nullptr
argument_list|)
operator|,
name|IVIncInsertPos
argument_list|(
name|nullptr
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
argument|TargetFolder(DL)
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
comment|/// \brief Erase the contents of the InsertedExpressions map so that users
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
comment|/// \brief Return true for expressions that may incur non-trivial cost to
comment|/// evaluate at runtime.
name|bool
name|isHighCostExpansion
argument_list|(
argument|const SCEV *Expr
argument_list|,
argument|Loop *L
argument_list|)
block|{
name|SmallPtrSet
operator|<
specifier|const
name|SCEV
operator|*
block|,
literal|8
operator|>
name|Processed
block|;
return|return
name|isHighCostExpansionHelper
argument_list|(
name|Expr
argument_list|,
name|L
argument_list|,
name|Processed
argument_list|)
return|;
block|}
comment|/// \brief This method returns the canonical induction variable of the
comment|/// specified type for the specified loop (inserting one if there is none).
comment|/// A canonical induction variable starts at zero and steps by one on each
comment|/// iteration.
name|PHINode
modifier|*
name|getOrInsertCanonicalInductionVariable
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// \brief Return the induction variable increment's IV operand.
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
comment|/// \brief Utility for hoisting an IV increment.
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
comment|/// \brief replace congruent phis with their most canonical
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
name|nullptr
argument_list|)
decl_stmt|;
comment|/// \brief Insert code to directly compute the specified SCEV expression
comment|/// into the program.  The inserted code is inserted into the specified
comment|/// block.
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
comment|/// \brief Set the current IV increment loop and position.
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
comment|/// \brief Enable post-inc expansion for addrecs referring to the given
comment|/// loops. Post-inc expansion is only supported in non-canonical mode.
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
comment|/// \brief Disable all post-inc expansion.
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
comment|/// \brief Disable the behavior of expanding expressions in canonical form
comment|/// rather than in a more literal form. Non-canonical mode is useful for
comment|/// late optimization passes.
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
comment|/// \brief Clear the current insertion point. This is useful if the
comment|/// instruction that had been serving as the insertion point may have been
comment|/// deleted.
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
comment|/// \brief Return true if the specified instruction was inserted by the code
comment|/// rewriter.  If so, the client should not modify the instruction.
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
comment|/// \brief Recursive helper function for isHighCostExpansion.
name|bool
name|isHighCostExpansionHelper
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
name|Loop
operator|*
name|L
argument_list|,
name|SmallPtrSetImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Processed
argument_list|)
decl_stmt|;
comment|/// \brief Insert the specified binary operator, doing a small amount
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
comment|/// \brief Arrange for there to be a cast of V to Ty at IP, reusing an
comment|/// existing cast if a suitable one exists, moving an existing cast if a
comment|/// suitable one exists but isn't in the right place, or or creating a new
comment|/// one.
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
comment|/// \brief Insert a cast of V to the specified type, which must be possible
comment|/// with a noop cast, doing what we can to share the casts.
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
comment|/// \brief Expand a SCEVAddExpr with a pointer type into a GEP
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
comment|/// \brief Insert code to directly compute the specified SCEV expression
comment|/// into the program.  The inserted code is inserted into the SCEVExpander's
comment|/// current insertion point. If a type is specified, the result will be
comment|/// expanded to have that type, with a cast if necessary.
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
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Determine the most "relevant" loop for the given SCEV.
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
parameter_list|,
name|Type
modifier|*
modifier|&
name|TruncTy
parameter_list|,
name|bool
modifier|&
name|InvertStep
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

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/IVUsers.h - Induction Variable Users -------*- C++ -*-===//
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
comment|// This file implements bookkeeping for "interesting" users of expressions
end_comment

begin_comment
comment|// computed from induction variables.
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
name|LLVM_ANALYSIS_IVUSERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_IVUSERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolution.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Value
decl_stmt|;
struct_decl|struct
name|IVUsersOfOneStride
struct_decl|;
comment|/// IVStrideUse - Keep track of one use of a strided induction variable, where
comment|/// the stride is stored externally.  The Offset member keeps track of the
comment|/// offset from the IV, User is the actual user of the operand, and
comment|/// 'OperandValToReplace' is the operand of the User that is the use.
name|class
name|IVStrideUse
range|:
name|public
name|CallbackVH
decl_stmt|,
name|public
name|ilist_node
decl|<
name|IVStrideUse
decl|>
block|{
name|public
label|:
name|IVStrideUse
argument_list|(
name|IVUsersOfOneStride
operator|*
name|parent
argument_list|,
specifier|const
name|SCEV
operator|*
name|offset
argument_list|,
name|Instruction
operator|*
name|U
argument_list|,
name|Value
operator|*
name|O
argument_list|)
operator|:
name|CallbackVH
argument_list|(
name|U
argument_list|)
operator|,
name|Parent
argument_list|(
name|parent
argument_list|)
operator|,
name|Offset
argument_list|(
name|offset
argument_list|)
operator|,
name|OperandValToReplace
argument_list|(
name|O
argument_list|)
operator|,
name|IsUseOfPostIncrementedValue
argument_list|(
argument|false
argument_list|)
block|{   }
comment|/// getUser - Return the user instruction for this use.
name|Instruction
operator|*
name|getUser
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Instruction
operator|>
operator|(
name|getValPtr
argument_list|()
operator|)
return|;
block|}
comment|/// setUser - Assign a new user instruction for this use.
name|void
name|setUser
parameter_list|(
name|Instruction
modifier|*
name|NewUser
parameter_list|)
block|{
name|setValPtr
argument_list|(
name|NewUser
argument_list|)
expr_stmt|;
block|}
comment|/// getParent - Return a pointer to the IVUsersOfOneStride that owns
comment|/// this IVStrideUse.
name|IVUsersOfOneStride
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
comment|/// getOffset - Return the offset to add to a theoeretical induction
comment|/// variable that starts at zero and counts up by the stride to compute
comment|/// the value for the use. This always has the same type as the stride.
specifier|const
name|SCEV
operator|*
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
comment|/// setOffset - Assign a new offset to this use.
name|void
name|setOffset
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Val
parameter_list|)
block|{
name|Offset
operator|=
name|Val
expr_stmt|;
block|}
comment|/// getOperandValToReplace - Return the Value of the operand in the user
comment|/// instruction that this IVStrideUse is representing.
name|Value
operator|*
name|getOperandValToReplace
argument_list|()
specifier|const
block|{
return|return
name|OperandValToReplace
return|;
block|}
comment|/// setOperandValToReplace - Assign a new Value as the operand value
comment|/// to replace.
name|void
name|setOperandValToReplace
parameter_list|(
name|Value
modifier|*
name|Op
parameter_list|)
block|{
name|OperandValToReplace
operator|=
name|Op
expr_stmt|;
block|}
comment|/// isUseOfPostIncrementedValue - True if this should use the
comment|/// post-incremented version of this IV, not the preincremented version.
comment|/// This can only be set in special cases, such as the terminating setcc
comment|/// instruction for a loop or uses dominated by the loop.
name|bool
name|isUseOfPostIncrementedValue
argument_list|()
specifier|const
block|{
return|return
name|IsUseOfPostIncrementedValue
return|;
block|}
comment|/// setIsUseOfPostIncrmentedValue - set the flag that indicates whether
comment|/// this is a post-increment use.
name|void
name|setIsUseOfPostIncrementedValue
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|IsUseOfPostIncrementedValue
operator|=
name|Val
expr_stmt|;
block|}
name|private
label|:
comment|/// Parent - a pointer to the IVUsersOfOneStride that owns this IVStrideUse.
name|IVUsersOfOneStride
modifier|*
name|Parent
decl_stmt|;
comment|/// Offset - The offset to add to the base induction expression.
specifier|const
name|SCEV
modifier|*
name|Offset
decl_stmt|;
comment|/// OperandValToReplace - The Value of the operand in the user instruction
comment|/// that this IVStrideUse is representing.
name|WeakVH
name|OperandValToReplace
decl_stmt|;
comment|/// IsUseOfPostIncrementedValue - True if this should use the
comment|/// post-incremented version of this IV, not the preincremented version.
name|bool
name|IsUseOfPostIncrementedValue
decl_stmt|;
comment|/// Deleted - Implementation of CallbackVH virtual function to
comment|/// recieve notification when the User is deleted.
name|virtual
name|void
name|deleted
parameter_list|()
function_decl|;
block|}
empty_stmt|;
name|template
operator|<
operator|>
expr|struct
name|ilist_traits
operator|<
name|IVStrideUse
operator|>
operator|:
name|public
name|ilist_default_traits
operator|<
name|IVStrideUse
operator|>
block|{
comment|// createSentinel is used to get hold of a node that marks the end of
comment|// the list...
comment|// The sentinel is relative to this instance, so we use a non-static
comment|// method.
name|IVStrideUse
operator|*
name|createSentinel
argument_list|()
specifier|const
block|{
comment|// since i(p)lists always publicly derive from the corresponding
comment|// traits, placing a data member in this class will augment i(p)list.
comment|// But since the NodeTy is expected to publicly derive from
comment|// ilist_node<NodeTy>, there is a legal viable downcast from it
comment|// to NodeTy. We use this trick to superpose i(p)list with a "ghostly"
comment|// NodeTy, which becomes the sentinel. Dereferencing the sentinel is
comment|// forbidden (save the ilist_node<NodeTy>) so no one will ever notice
comment|// the superposition.
return|return
name|static_cast
operator|<
name|IVStrideUse
operator|*
operator|>
operator|(
operator|&
name|Sentinel
operator|)
return|;
block|}
specifier|static
name|void
name|destroySentinel
argument_list|(
argument|IVStrideUse*
argument_list|)
block|{}
name|IVStrideUse
operator|*
name|provideInitialHead
argument_list|()
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
name|IVStrideUse
operator|*
name|ensureHead
argument_list|(
argument|IVStrideUse*
argument_list|)
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
specifier|static
name|void
name|noteHead
argument_list|(
argument|IVStrideUse*
argument_list|,
argument|IVStrideUse*
argument_list|)
block|{}
name|private
operator|:
name|mutable
name|ilist_node
operator|<
name|IVStrideUse
operator|>
name|Sentinel
block|; }
expr_stmt|;
comment|/// IVUsersOfOneStride - This structure keeps track of all instructions that
comment|/// have an operand that is based on the trip count multiplied by some stride.
name|struct
name|IVUsersOfOneStride
range|:
name|public
name|ilist_node
operator|<
name|IVUsersOfOneStride
operator|>
block|{
name|private
operator|:
name|IVUsersOfOneStride
argument_list|(
specifier|const
name|IVUsersOfOneStride
operator|&
name|I
argument_list|)
block|;
comment|// do not implement
name|void
name|operator
operator|=
operator|(
specifier|const
name|IVUsersOfOneStride
operator|&
name|I
operator|)
block|;
comment|// do not implement
name|public
operator|:
name|IVUsersOfOneStride
argument_list|()
operator|:
name|Stride
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|IVUsersOfOneStride
argument_list|(
specifier|const
name|SCEV
operator|*
name|stride
argument_list|)
operator|:
name|Stride
argument_list|(
argument|stride
argument_list|)
block|{}
comment|/// Stride - The stride for all the contained IVStrideUses. This is
comment|/// a constant for affine strides.
specifier|const
name|SCEV
operator|*
name|Stride
block|;
comment|/// Users - Keep track of all of the users of this stride as well as the
comment|/// initial value and the operand that uses the IV.
name|ilist
operator|<
name|IVStrideUse
operator|>
name|Users
block|;
name|void
name|addUser
argument_list|(
argument|const SCEV *Offset
argument_list|,
argument|Instruction *User
argument_list|,
argument|Value *Operand
argument_list|)
block|{
name|Users
operator|.
name|push_back
argument_list|(
argument|new IVStrideUse(this, Offset, User, Operand)
argument_list|)
block|;   }
name|void
name|removeUser
argument_list|(
argument|IVStrideUse *User
argument_list|)
block|{
name|Users
operator|.
name|erase
argument_list|(
name|User
argument_list|)
block|;   }
block|}
decl_stmt|;
name|class
name|IVUsers
range|:
name|public
name|LoopPass
block|{
name|friend
name|class
name|IVStrideUserVH
block|;
name|Loop
operator|*
name|L
block|;
name|LoopInfo
operator|*
name|LI
block|;
name|DominatorTree
operator|*
name|DT
block|;
name|ScalarEvolution
operator|*
name|SE
block|;
name|SmallPtrSet
operator|<
name|Instruction
operator|*
block|,
literal|16
operator|>
name|Processed
block|;
comment|/// IVUses - A list of all tracked IV uses of induction variable expressions
comment|/// we are interested in.
name|ilist
operator|<
name|IVUsersOfOneStride
operator|>
name|IVUses
block|;
name|public
operator|:
comment|/// IVUsesByStride - A mapping from the strides in StrideOrder to the
comment|/// uses in IVUses.
name|std
operator|::
name|map
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|IVUsersOfOneStride
operator|*
operator|>
name|IVUsesByStride
block|;
comment|/// StrideOrder - An ordering of the keys in IVUsesByStride that is stable:
comment|/// We use this to iterate over the IVUsesByStride collection without being
comment|/// dependent on random ordering of pointers in the process.
name|SmallVector
operator|<
specifier|const
name|SCEV
operator|*
block|,
literal|16
operator|>
name|StrideOrder
block|;
name|private
operator|:
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|runOnLoop
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|LPPassManager
operator|&
name|LPM
argument_list|)
block|;
name|virtual
name|void
name|releaseMemory
argument_list|()
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass ID, replacement for typeid
name|IVUsers
argument_list|()
block|;
comment|/// AddUsersIfInteresting - Inspect the specified Instruction.  If it is a
comment|/// reducible SCEV, recursively add its users to the IVUsesByStride set and
comment|/// return true.  Otherwise, return false.
name|bool
name|AddUsersIfInteresting
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
block|;
name|void
name|AddUser
argument_list|(
specifier|const
name|SCEV
operator|*
name|Stride
argument_list|,
specifier|const
name|SCEV
operator|*
name|Offset
argument_list|,
name|Instruction
operator|*
name|User
argument_list|,
name|Value
operator|*
name|Operand
argument_list|)
block|;
comment|/// getReplacementExpr - Return a SCEV expression which computes the
comment|/// value of the OperandValToReplace of the given IVStrideUse.
specifier|const
name|SCEV
operator|*
name|getReplacementExpr
argument_list|(
argument|const IVStrideUse&U
argument_list|)
specifier|const
block|;
comment|/// getCanonicalExpr - Return a SCEV expression which computes the
comment|/// value of the SCEV of the given IVStrideUse, ignoring the
comment|/// isUseOfPostIncrementedValue flag.
specifier|const
name|SCEV
operator|*
name|getCanonicalExpr
argument_list|(
argument|const IVStrideUse&U
argument_list|)
specifier|const
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module* =
literal|0
argument_list|)
specifier|const
block|;
comment|/// dump - This method is used for debugging.
name|void
name|dump
argument_list|()
specifier|const
block|; }
decl_stmt|;
name|Pass
modifier|*
name|createIVUsersPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


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
name|LLVM_ANALYSIS_SCALAREVOLUTION_EXPANDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_SCALAREVOLUTION_EXPANDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolutionExpressions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/IRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TargetFolder.h"
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
comment|/// SCEVExpander - This class uses information about analyze scalars to
comment|/// rewrite expressions in canonical form.
comment|///
comment|/// Clients should create an instance of this class when rewriting is needed,
comment|/// and destroy it when finished to allow the release of the associated
comment|/// memory.
name|struct
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
name|AssertingVH
operator|<
name|Value
operator|>
expr|>
name|InsertedExpressions
expr_stmt|;
name|std
operator|::
name|set
operator|<
name|Value
operator|*
operator|>
name|InsertedValues
expr_stmt|;
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
name|explicit
name|SCEVExpander
argument_list|(
name|ScalarEvolution
operator|&
name|se
argument_list|)
operator|:
name|SE
argument_list|(
name|se
argument_list|)
operator|,
name|Builder
argument_list|(
argument|se.getContext()
argument_list|,
argument|TargetFolder(se.TD)
argument_list|)
block|{}
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
block|; }
comment|/// getOrInsertCanonicalInductionVariable - This method returns the
comment|/// canonical induction variable of the specified type for the specified
comment|/// loop (inserting one if there is none).  A canonical induction variable
comment|/// starts at zero and steps by one on each iteration.
name|Value
operator|*
name|getOrInsertCanonicalInductionVariable
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
expr_stmt|;
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
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|,
name|Instruction
modifier|*
name|IP
parameter_list|)
block|{
name|Builder
operator|.
name|SetInsertPoint
argument_list|(
name|IP
operator|->
name|getParent
argument_list|()
argument_list|,
name|IP
argument_list|)
expr_stmt|;
return|return
name|expandCodeFor
argument_list|(
name|SH
argument_list|,
name|Ty
argument_list|)
return|;
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
specifier|const
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
specifier|const
name|PointerType
modifier|*
name|PTy
parameter_list|,
specifier|const
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
specifier|const
name|Type
modifier|*
name|Ty
init|=
literal|0
parameter_list|)
function_decl|;
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
return|;
block|}
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
name|visitFieldOffsetExpr
parameter_list|(
specifier|const
name|SCEVFieldOffsetExpr
modifier|*
name|S
parameter_list|)
function_decl|;
name|Value
modifier|*
name|visitAllocSizeExpr
parameter_list|(
specifier|const
name|SCEVAllocSizeExpr
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
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


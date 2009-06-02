begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PromoteMemToReg.h - Promote Allocas to Scalars -----------*- C++ -*-===//
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
comment|// This file exposes an interface to promote alloca instructions to SSA
end_comment

begin_comment
comment|// registers, by using the SSA construction algorithm.
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
name|TRANSFORMS_UTILS_PROMOTEMEMTOREG_H
end_ifndef

begin_define
define|#
directive|define
name|TRANSFORMS_UTILS_PROMOTEMEMTOREG_H
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AllocaInst
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|DominanceFrontier
decl_stmt|;
name|class
name|AliasSetTracker
decl_stmt|;
comment|/// isAllocaPromotable - Return true if this alloca is legal for promotion.
comment|/// This is true if there are only loads and stores to the alloca...
comment|///
name|bool
name|isAllocaPromotable
parameter_list|(
specifier|const
name|AllocaInst
modifier|*
name|AI
parameter_list|)
function_decl|;
comment|/// PromoteMemToReg - Promote the specified list of alloca instructions into
comment|/// scalar registers, inserting PHI nodes as appropriate.  This function makes
comment|/// use of DominanceFrontier information.  This function does not modify the CFG
comment|/// of the function at all.  All allocas must be from the same function.
comment|///
comment|/// If AST is specified, the specified tracker is updated to reflect changes
comment|/// made to the IR.
comment|///
name|void
name|PromoteMemToReg
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|AllocaInst
operator|*
operator|>
operator|&
name|Allocas
argument_list|,
name|DominatorTree
operator|&
name|DT
argument_list|,
name|DominanceFrontier
operator|&
name|DF
argument_list|,
name|AliasSetTracker
operator|*
name|AST
operator|=
literal|0
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


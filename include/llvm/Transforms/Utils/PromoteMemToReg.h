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
name|LLVM_TRANSFORMS_UTILS_PROMOTEMEMTOREG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_PROMOTEMEMTOREG_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|class
name|AllocaInst
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|AliasSetTracker
decl_stmt|;
name|class
name|AssumptionCache
decl_stmt|;
comment|/// \brief Return true if this alloca is legal for promotion.
comment|///
comment|/// This is true if there are only loads, stores, and lifetime markers
comment|/// (transitively) using this alloca. This also enforces that there is only
comment|/// ever one layer of bitcasts or GEPs between the alloca and the lifetime
comment|/// markers.
name|bool
name|isAllocaPromotable
parameter_list|(
specifier|const
name|AllocaInst
modifier|*
name|AI
parameter_list|)
function_decl|;
comment|/// \brief Promote the specified list of alloca instructions into scalar
comment|/// registers, inserting PHI nodes as appropriate.
comment|///
comment|/// This function makes use of DominanceFrontier information.  This function
comment|/// does not modify the CFG of the function at all.  All allocas must be from
comment|/// the same function.
comment|///
name|void
name|PromoteMemToReg
argument_list|(
name|ArrayRef
operator|<
name|AllocaInst
operator|*
operator|>
name|Allocas
argument_list|,
name|DominatorTree
operator|&
name|DT
argument_list|,
name|AssumptionCache
operator|*
name|AC
operator|=
name|nullptr
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


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FunctionAttrs.h - Compute function attrs --------------------------===//
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
comment|/// \file
end_comment

begin_comment
comment|/// Provides passes for computing function attributes based on interprocedural
end_comment

begin_comment
comment|/// analyses.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_IPO_FUNCTIONATTRS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_FUNCTIONATTRS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/CGSCCPassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LazyCallGraph.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AAResults
decl_stmt|;
comment|/// The three kinds of memory access relevant to 'readonly' and
comment|/// 'readnone' attributes.
enum|enum
name|MemoryAccessKind
block|{
name|MAK_ReadNone
init|=
literal|0
block|,
name|MAK_ReadOnly
init|=
literal|1
block|,
name|MAK_MayWrite
init|=
literal|2
block|}
enum|;
comment|/// Returns the memory access properties of this copy of the function.
name|MemoryAccessKind
name|computeFunctionBodyMemoryAccess
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|,
name|AAResults
modifier|&
name|AAR
parameter_list|)
function_decl|;
comment|/// Computes function attributes in post-order over the call graph.
comment|///
comment|/// By operating in post-order, this pass computes precise attributes for
comment|/// called functions prior to processsing their callers. This "bottom-up"
comment|/// approach allows powerful interprocedural inference of function attributes
comment|/// like memory access patterns, etc. It can discover functions that do not
comment|/// access memory, or only read memory, and give them the readnone/readonly
comment|/// attribute. It also discovers function arguments that are not captured by
comment|/// the function and marks them with the nocapture attribute.
name|struct
name|PostOrderFunctionAttrsPass
range|:
name|PassInfoMixin
operator|<
name|PostOrderFunctionAttrsPass
operator|>
block|{
name|PreservedAnalyses
name|run
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|C
argument_list|,
name|CGSCCAnalysisManager
operator|&
name|AM
argument_list|,
name|LazyCallGraph
operator|&
name|CG
argument_list|,
name|CGSCCUpdateResult
operator|&
name|UR
argument_list|)
block|; }
decl_stmt|;
comment|/// Create a legacy pass manager instance of a pass to compute function attrs
comment|/// in post-order.
name|Pass
modifier|*
name|createPostOrderFunctionAttrsLegacyPass
parameter_list|()
function_decl|;
comment|/// A pass to do RPO deduction and propagation of function attributes.
comment|///
comment|/// This pass provides a general RPO or "top down" propagation of
comment|/// function attributes. For a few (rare) cases, we can deduce significantly
comment|/// more about function attributes by working in RPO, so this pass
comment|/// provides the complement to the post-order pass above where the majority of
comment|/// deduction is performed.
comment|// FIXME: Currently there is no RPO CGSCC pass structure to slide into and so
comment|// this is a boring module pass, but eventually it should be an RPO CGSCC pass
comment|// when such infrastructure is available.
name|class
name|ReversePostOrderFunctionAttrsPass
range|:
name|public
name|PassInfoMixin
operator|<
name|ReversePostOrderFunctionAttrsPass
operator|>
block|{
name|public
operator|:
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_IPO_FUNCTIONATTRS_H
end_comment

end_unit


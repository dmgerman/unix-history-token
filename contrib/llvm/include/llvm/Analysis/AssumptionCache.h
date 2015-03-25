begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/AssumptionCache.h - Track @llvm.assume ---*- C++ -*-===//
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
comment|// This file contains a pass that keeps track of @llvm.assume intrinsics in
end_comment

begin_comment
comment|// the functions of a module (allowing assumptions within any function to be
end_comment

begin_comment
comment|// found cheaply by other parts of the optimizer).
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
name|LLVM_ANALYSIS_ASSUMPTIONCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_ASSUMPTIONCACHE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
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
comment|/// \brief A cache of @llvm.assume calls within a function.
comment|///
comment|/// This cache provides fast lookup of assumptions within a function by caching
comment|/// them and amortizing the cost of scanning for them across all queries. The
comment|/// cache is also conservatively self-updating so that it will never return
comment|/// incorrect results about a function even as the function is being mutated.
comment|/// However, flushing the cache and rebuilding it (or explicitly updating it)
comment|/// may allow it to discover new assumptions.
name|class
name|AssumptionCache
block|{
comment|/// \brief The function for which this cache is handling assumptions.
comment|///
comment|/// We track this to lazily populate our assumptions.
name|Function
modifier|&
name|F
decl_stmt|;
comment|/// \brief Vector of weak value handles to calls of the @llvm.assume
comment|/// intrinsic.
name|SmallVector
operator|<
name|WeakVH
operator|,
literal|4
operator|>
name|AssumeHandles
expr_stmt|;
comment|/// \brief Flag tracking whether we have scanned the function yet.
comment|///
comment|/// We want to be as lazy about this as possible, and so we scan the function
comment|/// at the last moment.
name|bool
name|Scanned
decl_stmt|;
comment|/// \brief Scan the function for assumptions and add them to the cache.
name|void
name|scanFunction
parameter_list|()
function_decl|;
name|public
label|:
comment|/// \brief Construct an AssumptionCache from a function by scanning all of
comment|/// its instructions.
name|AssumptionCache
argument_list|(
name|Function
operator|&
name|F
argument_list|)
operator|:
name|F
argument_list|(
name|F
argument_list|)
operator|,
name|Scanned
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Add an @llvm.assume intrinsic to this function's cache.
comment|///
comment|/// The call passed in must be an instruction within this fuction and must
comment|/// not already be in the cache.
name|void
name|registerAssumption
argument_list|(
name|CallInst
operator|*
name|CI
argument_list|)
expr_stmt|;
comment|/// \brief Clear the cache of @llvm.assume intrinsics for a function.
comment|///
comment|/// It will be re-scanned the next time it is requested.
name|void
name|clear
parameter_list|()
block|{
name|AssumeHandles
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Scanned
operator|=
name|false
expr_stmt|;
block|}
comment|/// \brief Access the list of assumption handles currently tracked for this
comment|/// fuction.
comment|///
comment|/// Note that these produce weak handles that may be null. The caller must
comment|/// handle that case.
comment|/// FIXME: We should replace this with pointee_iterator<filter_iterator<...>>
comment|/// when we can write that to filter out the null values. Then caller code
comment|/// will become simpler.
name|MutableArrayRef
operator|<
name|WeakVH
operator|>
name|assumptions
argument_list|()
block|{
if|if
condition|(
operator|!
name|Scanned
condition|)
name|scanFunction
argument_list|()
expr_stmt|;
return|return
name|AssumeHandles
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief An immutable pass that tracks lazily created \c AssumptionCache
end_comment

begin_comment
comment|/// objects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is essentially a workaround for the legacy pass manager's weaknesses
end_comment

begin_comment
comment|/// which associates each assumption cache with Function and clears it if the
end_comment

begin_comment
comment|/// function is deleted. The nature of the AssumptionCache is that it is not
end_comment

begin_comment
comment|/// invalidated by any changes to the function body and so this is sufficient
end_comment

begin_comment
comment|/// to be conservatively correct.
end_comment

begin_decl_stmt
name|class
name|AssumptionCacheTracker
range|:
name|public
name|ImmutablePass
block|{
comment|/// A callback value handle applied to function objects, which we use to
comment|/// delete our cache of intrinsics for a function when it is deleted.
name|class
name|FunctionCallbackVH
operator|:
name|public
name|CallbackVH
block|{
name|AssumptionCacheTracker
operator|*
name|ACT
block|;
name|void
name|deleted
argument_list|()
name|override
block|;
name|public
operator|:
typedef|typedef
name|DenseMapInfo
operator|<
name|Value
operator|*
operator|>
name|DMI
expr_stmt|;
name|FunctionCallbackVH
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|AssumptionCacheTracker
operator|*
name|ACT
operator|=
name|nullptr
argument_list|)
operator|:
name|CallbackVH
argument_list|(
name|V
argument_list|)
block|,
name|ACT
argument_list|(
argument|ACT
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|FunctionCallbackVH
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|FunctionCallbackVH
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|AssumptionCache
operator|>
operator|,
name|FunctionCallbackVH
operator|::
name|DMI
operator|>
name|FunctionCallsMap
expr_stmt|;
end_typedef

begin_decl_stmt
name|FunctionCallsMap
name|AssumptionCaches
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Get the cached assumptions for a function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If no assumptions are cached, this will scan the function. Otherwise, the
end_comment

begin_comment
comment|/// existing cache will be returned.
end_comment

begin_function_decl
name|AssumptionCache
modifier|&
name|getAssumptionCache
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|AssumptionCacheTracker
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|~
name|AssumptionCacheTracker
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|releaseMemory
parameter_list|()
function|override
block|{
name|AssumptionCaches
operator|.
name|shrink_and_clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|void
name|verifyAnalysis
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_function
name|bool
name|doFinalization
parameter_list|(
name|Module
modifier|&
parameter_list|)
function|override
block|{
name|verifyAnalysis
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|char
name|ID
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Pass identification, replacement for typeid
end_comment

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


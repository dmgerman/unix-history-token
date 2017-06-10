begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopVersioning.h - Utility to version a loop -------------*- C++ -*-===//
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
comment|// This file defines a utility class to perform loop versioning.  The versioned
end_comment

begin_comment
comment|// loop speculates that otherwise may-aliasing memory accesses don't overlap and
end_comment

begin_comment
comment|// emits checks to prove this.
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
name|LLVM_TRANSFORMS_UTILS_LOOPVERSIONING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_LOOPVERSIONING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopAccessAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolution.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/LoopUtils.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/ValueMapper.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Loop
decl_stmt|;
name|class
name|LoopAccessInfo
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
comment|/// \brief This class emits a version of the loop where run-time checks ensure
comment|/// that may-alias pointers can't overlap.
comment|///
comment|/// It currently only supports single-exit loops and assumes that the loop
comment|/// already has a preheader.
name|class
name|LoopVersioning
block|{
name|public
label|:
comment|/// \brief Expects LoopAccessInfo, Loop, LoopInfo, DominatorTree as input.
comment|/// It uses runtime check provided by the user. If \p UseLAIChecks is true,
comment|/// we will retain the default checks made by LAI. Otherwise, construct an
comment|/// object having no checks and we expect the user to add them.
name|LoopVersioning
argument_list|(
argument|const LoopAccessInfo&LAI
argument_list|,
argument|Loop *L
argument_list|,
argument|LoopInfo *LI
argument_list|,
argument|DominatorTree *DT
argument_list|,
argument|ScalarEvolution *SE
argument_list|,
argument|bool UseLAIChecks = true
argument_list|)
empty_stmt|;
comment|/// \brief Performs the CFG manipulation part of versioning the loop including
comment|/// the DominatorTree and LoopInfo updates.
comment|///
comment|/// The loop that was used to construct the class will be the "versioned" loop
comment|/// i.e. the loop that will receive control if all the memchecks pass.
comment|///
comment|/// This allows the loop transform pass to operate on the same loop regardless
comment|/// of whether versioning was necessary or not:
comment|///
comment|///    for each loop L:
comment|///        analyze L
comment|///        if versioning is necessary version L
comment|///        transform L
name|void
name|versionLoop
parameter_list|()
block|{
name|versionLoop
argument_list|(
name|findDefsUsedOutsideOfLoop
argument_list|(
name|VersionedLoop
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Same but if the client has already precomputed the set of values
comment|/// used outside the loop, this API will allows passing that.
name|void
name|versionLoop
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|DefsUsedOutside
argument_list|)
decl_stmt|;
comment|/// \brief Returns the versioned loop.  Control flows here if pointers in the
comment|/// loop don't alias (i.e. all memchecks passed).  (This loop is actually the
comment|/// same as the original loop that we got constructed with.)
name|Loop
modifier|*
name|getVersionedLoop
parameter_list|()
block|{
return|return
name|VersionedLoop
return|;
block|}
comment|/// \brief Returns the fall-back loop.  Control flows here if pointers in the
comment|/// loop may alias (i.e. one of the memchecks failed).
name|Loop
modifier|*
name|getNonVersionedLoop
parameter_list|()
block|{
return|return
name|NonVersionedLoop
return|;
block|}
comment|/// \brief Sets the runtime alias checks for versioning the loop.
name|void
name|setAliasChecks
argument_list|(
name|SmallVector
operator|<
name|RuntimePointerChecking
operator|::
name|PointerCheck
argument_list|,
literal|4
operator|>
name|Checks
argument_list|)
decl_stmt|;
comment|/// \brief Sets the runtime SCEV checks for versioning the loop.
name|void
name|setSCEVChecks
parameter_list|(
name|SCEVUnionPredicate
name|Check
parameter_list|)
function_decl|;
comment|/// \brief Annotate memory instructions in the versioned loop with no-alias
comment|/// metadata based on the memchecks issued.
comment|///
comment|/// This is just wrapper that calls prepareNoAliasMetadata and
comment|/// annotateInstWithNoAlias on the instructions of the versioned loop.
name|void
name|annotateLoopWithNoAlias
parameter_list|()
function_decl|;
comment|/// \brief Set up the aliasing scopes based on the memchecks.  This needs to
comment|/// be called before the first call to annotateInstWithNoAlias.
name|void
name|prepareNoAliasMetadata
parameter_list|()
function_decl|;
comment|/// \brief Add the noalias annotations to \p VersionedInst.
comment|///
comment|/// \p OrigInst is the instruction corresponding to \p VersionedInst in the
comment|/// original loop.  Initialize the aliasing scopes with
comment|/// prepareNoAliasMetadata once before this can be called.
name|void
name|annotateInstWithNoAlias
parameter_list|(
name|Instruction
modifier|*
name|VersionedInst
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|OrigInst
parameter_list|)
function_decl|;
name|private
label|:
comment|/// \brief Adds the necessary PHI nodes for the versioned loops based on the
comment|/// loop-defined values used outside of the loop.
comment|///
comment|/// This needs to be called after versionLoop if there are defs in the loop
comment|/// that are used outside the loop.
name|void
name|addPHINodes
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|DefsUsedOutside
argument_list|)
decl_stmt|;
comment|/// \brief Add the noalias annotations to \p I.  Initialize the aliasing
comment|/// scopes with prepareNoAliasMetadata once before this can be called.
name|void
name|annotateInstWithNoAlias
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
block|{
name|annotateInstWithNoAlias
argument_list|(
name|I
argument_list|,
name|I
argument_list|)
expr_stmt|;
block|}
comment|/// \brief The original loop.  This becomes the "versioned" one.  I.e.,
comment|/// control flows here if pointers in the loop don't alias.
name|Loop
modifier|*
name|VersionedLoop
decl_stmt|;
comment|/// \brief The fall-back loop.  I.e. control flows here if pointers in the
comment|/// loop may alias (memchecks failed).
name|Loop
modifier|*
name|NonVersionedLoop
decl_stmt|;
comment|/// \brief This maps the instructions from VersionedLoop to their counterpart
comment|/// in NonVersionedLoop.
name|ValueToValueMapTy
name|VMap
decl_stmt|;
comment|/// \brief The set of alias checks that we are versioning for.
name|SmallVector
operator|<
name|RuntimePointerChecking
operator|::
name|PointerCheck
operator|,
literal|4
operator|>
name|AliasChecks
expr_stmt|;
comment|/// \brief The set of SCEV checks that we are versioning for.
name|SCEVUnionPredicate
name|Preds
decl_stmt|;
comment|/// \brief Maps a pointer to the pointer checking group that the pointer
comment|/// belongs to.
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
specifier|const
name|RuntimePointerChecking
operator|::
name|CheckingPtrGroup
operator|*
operator|>
name|PtrToGroup
expr_stmt|;
comment|/// \brief The alias scope corresponding to a pointer checking group.
name|DenseMap
operator|<
specifier|const
name|RuntimePointerChecking
operator|::
name|CheckingPtrGroup
operator|*
operator|,
name|MDNode
operator|*
operator|>
name|GroupToScope
expr_stmt|;
comment|/// \brief The list of alias scopes that a pointer checking group can't alias.
name|DenseMap
operator|<
specifier|const
name|RuntimePointerChecking
operator|::
name|CheckingPtrGroup
operator|*
operator|,
name|MDNode
operator|*
operator|>
name|GroupToNonAliasingScopeList
expr_stmt|;
comment|/// \brief Analyses used.
specifier|const
name|LoopAccessInfo
modifier|&
name|LAI
decl_stmt|;
name|LoopInfo
modifier|*
name|LI
decl_stmt|;
name|DominatorTree
modifier|*
name|DT
decl_stmt|;
name|ScalarEvolution
modifier|*
name|SE
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


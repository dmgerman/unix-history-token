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
name|LoopVersioning
argument_list|(
specifier|const
name|LoopAccessInfo
operator|&
name|LAI
argument_list|,
name|Loop
operator|*
name|L
argument_list|,
name|LoopInfo
operator|*
name|LI
argument_list|,
name|DominatorTree
operator|*
name|DT
argument_list|,
specifier|const
name|SmallVector
operator|<
name|int
argument_list|,
literal|8
operator|>
operator|*
name|PtrToPartition
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|/// \brief Returns true if we need memchecks to disambiguate may-aliasing
comment|/// accesses.
name|bool
name|needsRuntimeChecks
argument_list|()
specifier|const
expr_stmt|;
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
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// \brief Adds the necessary PHI nodes for the versioned loops based on the
comment|/// loop-defined values used outside of the loop.
comment|///
comment|/// This needs to be called after versionLoop if there are defs in the loop
comment|/// that are used outside the loop.  FIXME: this should be invoked internally
comment|/// by versionLoop and made private.
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
name|private
label|:
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
comment|/// \brief For each memory pointer it contains the partitionId it is used in.
comment|/// If nullptr, no partitioning is used.
comment|///
comment|/// The I-th entry corresponds to I-th entry in LAI.getRuntimePointerCheck().
comment|/// If the pointer is used in multiple partitions the entry is set to -1.
specifier|const
name|SmallVector
operator|<
name|int
operator|,
literal|8
operator|>
operator|*
name|PtrToPartition
expr_stmt|;
comment|/// \brief This maps the instructions from VersionedLoop to their counterpart
comment|/// in NonVersionedLoop.
name|ValueToValueMapTy
name|VMap
decl_stmt|;
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
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


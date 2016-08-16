begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GlobalDCE.h - DCE unreachable internal functions ------------------===//
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
comment|// This transform is designed to eliminate unreachable internal globals from the
end_comment

begin_comment
comment|// program.  It uses an aggressive algorithm, searching out globals that are
end_comment

begin_comment
comment|// known to be alive.  After it finds all of the globals which are needed, it
end_comment

begin_comment
comment|// deletes whatever is left over.  This allows it to delete recursive chunks of
end_comment

begin_comment
comment|// the program which are unreachable.
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
name|LLVM_TRANSFORMS_IPO_GLOBALDCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_GLOBALDCE_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Pass to remove unused function declarations.
name|class
name|GlobalDCEPass
range|:
name|public
name|PassInfoMixin
operator|<
name|GlobalDCEPass
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
argument_list|)
block|;
name|private
operator|:
name|SmallPtrSet
operator|<
name|GlobalValue
operator|*
block|,
literal|32
operator|>
name|AliveGlobals
block|;
name|SmallPtrSet
operator|<
name|Constant
operator|*
block|,
literal|8
operator|>
name|SeenConstants
block|;
name|std
operator|::
name|unordered_multimap
operator|<
name|Comdat
operator|*
block|,
name|GlobalValue
operator|*
operator|>
name|ComdatMembers
block|;
comment|/// Mark the specific global value as needed, and
comment|/// recursively mark anything that it uses as also needed.
name|void
name|GlobalIsNeeded
argument_list|(
name|GlobalValue
operator|*
name|GV
argument_list|)
block|;
name|void
name|MarkUsedGlobalsAsNeeded
argument_list|(
name|Constant
operator|*
name|C
argument_list|)
block|;
name|bool
name|RemoveUnusedGlobalValue
argument_list|(
name|GlobalValue
operator|&
name|GV
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
comment|// LLVM_TRANSFORMS_IPO_GLOBALDCE_H
end_comment

end_unit


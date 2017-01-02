begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/Core/PassManager.h - Manage linker passes ----------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_CORE_PASS_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_PASS_MANAGER_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|SimpleFile
decl_stmt|;
name|class
name|Pass
decl_stmt|;
comment|/// \brief Owns and runs a collection of passes.
comment|///
comment|/// This class is currently just a container for passes and a way to run them.
comment|///
comment|/// In the future this should handle timing pass runs, running parallel passes,
comment|/// and validate/satisfy pass dependencies.
name|class
name|PassManager
block|{
name|public
label|:
name|void
name|add
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Pass
operator|>
name|pass
argument_list|)
block|{
name|_passes
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|pass
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|llvm
operator|::
name|Error
name|runOnFile
argument_list|(
argument|SimpleFile&file
argument_list|)
block|{
for|for
control|(
name|std
operator|::
name|unique_ptr
operator|<
name|Pass
operator|>
operator|&
name|pass
operator|:
name|_passes
control|)
if|if
condition|(
name|llvm
operator|::
name|Error
name|EC
operator|=
name|pass
operator|->
name|perform
argument_list|(
name|file
argument_list|)
condition|)
return|return
name|EC
return|;
return|return
name|llvm
operator|::
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|private
label|:
comment|/// \brief Passes in the order they should run.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Pass
operator|>>
name|_passes
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


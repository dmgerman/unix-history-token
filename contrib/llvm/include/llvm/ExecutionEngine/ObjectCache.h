begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjectCache.h - Class definition for the ObjectCache -----C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_EXECUTIONENGINE_OBJECTCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_OBJECTCACHE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
comment|/// This is the base ObjectCache type which can be provided to an
comment|/// ExecutionEngine for the purpose of avoiding compilation for Modules that
comment|/// have already been compiled and an object file is available.
name|class
name|ObjectCache
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|ObjectCache
argument_list|()
block|{ }
name|virtual
operator|~
name|ObjectCache
argument_list|()
block|{ }
comment|/// notifyObjectCompiled - Provides a pointer to compiled code for Module M.
name|virtual
name|void
name|notifyObjectCompiled
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|,
specifier|const
name|MemoryBuffer
operator|*
name|Obj
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// getObjectCopy - Returns a pointer to a newly allocated MemoryBuffer that
comment|/// contains the object which corresponds with Module M, or 0 if an object is
comment|/// not available. The caller owns both the MemoryBuffer returned by this
comment|/// and the memory it references.
name|virtual
name|MemoryBuffer
modifier|*
name|getObject
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


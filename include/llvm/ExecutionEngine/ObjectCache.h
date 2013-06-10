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
name|LLVM_LIB_EXECUTIONENGINE_OBJECTCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_EXECUTIONENGINE_OBJECTCACHE_H
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
comment|/// not available. The caller owns the MemoryBuffer returned by this function.
name|MemoryBuffer
modifier|*
name|getObjectCopy
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|)
block|{
specifier|const
name|MemoryBuffer
modifier|*
name|Obj
init|=
name|getObject
argument_list|(
name|M
argument_list|)
decl_stmt|;
if|if
condition|(
name|Obj
condition|)
return|return
name|MemoryBuffer
operator|::
name|getMemBufferCopy
argument_list|(
name|Obj
operator|->
name|getBuffer
argument_list|()
argument_list|)
return|;
else|else
return|return
literal|0
return|;
block|}
name|protected
label|:
comment|/// getObject - Returns a pointer to a MemoryBuffer that contains an object
comment|/// that corresponds with Module M, or 0 if an object is not available.
comment|/// The pointer returned by this function is not suitable for loading because
comment|/// the memory is read-only and owned by the ObjectCache. To retrieve an
comment|/// owning pointer to a MemoryBuffer (which is suitable for calling
comment|/// RuntimeDyld::loadObject() with) use getObjectCopy() instead.
name|virtual
specifier|const
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


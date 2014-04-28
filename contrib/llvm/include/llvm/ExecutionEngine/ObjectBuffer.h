begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- ObjectBuffer.h - Utility class to wrap object image memory -----===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//		       The LLVM Compiler Infrastructure
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
comment|// This file declares a wrapper class to hold the memory into which an
end_comment

begin_comment
comment|// object will be generated.
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
name|LLVM_EXECUTIONENGINE_OBJECTBUFFER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_OBJECTBUFFER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// ObjectBuffer - This class acts as a container for the memory buffer used during
comment|/// generation and loading of executable objects using MCJIT and RuntimeDyld.  The
comment|/// underlying memory for the object will be owned by the ObjectBuffer instance
comment|/// throughout its lifetime.  The getMemBuffer() method provides a way to create a
comment|/// MemoryBuffer wrapper object instance to be owned by other classes (such as
comment|/// ObjectFile) as needed, but the MemoryBuffer instance returned does not own the
comment|/// actual memory it points to.
name|class
name|ObjectBuffer
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|ObjectBuffer
argument_list|()
block|{}
name|ObjectBuffer
argument_list|(
name|MemoryBuffer
operator|*
name|Buf
argument_list|)
operator|:
name|Buffer
argument_list|(
argument|Buf
argument_list|)
block|{}
name|virtual
operator|~
name|ObjectBuffer
argument_list|()
block|{}
comment|/// getMemBuffer - Like MemoryBuffer::getMemBuffer() this function
comment|/// returns a pointer to an object that is owned by the caller. However,
comment|/// the caller does not take ownership of the underlying memory.
name|MemoryBuffer
operator|*
name|getMemBuffer
argument_list|()
specifier|const
block|{
return|return
name|MemoryBuffer
operator|::
name|getMemBuffer
argument_list|(
name|Buffer
operator|->
name|getBuffer
argument_list|()
argument_list|,
literal|""
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|const
name|char
operator|*
name|getBufferStart
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|->
name|getBufferStart
argument_list|()
return|;
block|}
name|size_t
name|getBufferSize
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|->
name|getBufferSize
argument_list|()
return|;
block|}
name|StringRef
name|getBuffer
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|->
name|getBuffer
argument_list|()
return|;
block|}
name|protected
label|:
comment|// The memory contained in an ObjectBuffer
name|OwningPtr
operator|<
name|MemoryBuffer
operator|>
name|Buffer
expr_stmt|;
block|}
empty_stmt|;
comment|/// ObjectBufferStream - This class encapsulates the SmallVector and
comment|/// raw_svector_ostream needed to generate an object using MC code emission
comment|/// while providing a common ObjectBuffer interface for access to the
comment|/// memory once the object has been generated.
name|class
name|ObjectBufferStream
range|:
name|public
name|ObjectBuffer
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|ObjectBufferStream
argument_list|()
operator|:
name|OS
argument_list|(
argument|SV
argument_list|)
block|{}
name|virtual
operator|~
name|ObjectBufferStream
argument_list|()
block|{}
name|raw_ostream
operator|&
name|getOStream
argument_list|()
block|{
return|return
name|OS
return|;
block|}
name|void
name|flush
argument_list|()
block|{
name|OS
operator|.
name|flush
argument_list|()
block|;
comment|// Make the data accessible via the ObjectBuffer::Buffer
name|Buffer
operator|.
name|reset
argument_list|(
name|MemoryBuffer
operator|::
name|getMemBuffer
argument_list|(
name|StringRef
argument_list|(
name|SV
operator|.
name|data
argument_list|()
argument_list|,
name|SV
operator|.
name|size
argument_list|()
argument_list|)
argument_list|,
literal|""
argument_list|,
name|false
argument_list|)
argument_list|)
block|;   }
name|protected
operator|:
name|SmallVector
operator|<
name|char
block|,
literal|4096
operator|>
name|SV
block|;
comment|// Working buffer into which we JIT.
name|raw_svector_ostream
name|OS
block|;
comment|// streaming wrapper
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


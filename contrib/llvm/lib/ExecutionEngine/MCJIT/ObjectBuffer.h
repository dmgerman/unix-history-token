begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ObjectBuffer.h - Utility class to wrap object memory ---*- C++ -*-===//
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
name|class
name|ObjectMemoryBuffer
range|:
name|public
name|MemoryBuffer
block|{
name|public
operator|:
name|template
operator|<
name|unsigned
name|N
operator|>
name|ObjectMemoryBuffer
argument_list|(
name|SmallVector
operator|<
name|char
argument_list|,
name|N
operator|>
name|SV
argument_list|)
operator|:
name|SV
argument_list|(
name|SV
argument_list|)
block|,
name|BufferName
argument_list|(
literal|"<in-memory object>"
argument_list|)
block|{
name|init
argument_list|(
name|this
operator|->
name|SV
operator|.
name|begin
argument_list|()
argument_list|,
name|this
operator|->
name|SV
operator|.
name|end
argument_list|()
argument_list|,
name|false
argument_list|)
block|;   }
name|template
operator|<
name|unsigned
name|N
operator|>
name|ObjectMemoryBuffer
argument_list|(
argument|SmallVector<char
argument_list|,
argument|N> SV
argument_list|,
argument|StringRef Name
argument_list|)
operator|:
name|SV
argument_list|(
name|SV
argument_list|)
block|,
name|BufferName
argument_list|(
argument|Name
argument_list|)
block|{
name|init
argument_list|(
name|this
operator|->
name|SV
operator|.
name|begin
argument_list|()
argument_list|,
name|this
operator|->
name|SV
operator|.
name|end
argument_list|()
argument_list|,
name|false
argument_list|)
block|;   }
specifier|const
name|char
operator|*
name|getBufferIdentifier
argument_list|()
specifier|const
name|override
block|{
return|return
name|BufferName
operator|.
name|c_str
argument_list|()
return|;
block|}
name|BufferKind
name|getBufferKind
argument_list|()
specifier|const
name|override
block|{
return|return
name|MemoryBuffer_Malloc
return|;
block|}
name|private
operator|:
name|SmallVector
operator|<
name|char
block|,
literal|4096
operator|>
name|SV
block|;
name|std
operator|::
name|string
name|BufferName
block|; }
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


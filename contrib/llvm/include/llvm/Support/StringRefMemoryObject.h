begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/StringRefMemoryObject.h ---------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the StringRefMemObject class, a simple
end_comment

begin_comment
comment|// wrapper around StringRef implementing the MemoryObject interface.
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
name|LLVM_SUPPORT_STRINGREFMEMORYOBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_STRINGREFMEMORYOBJECT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryObject.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// StringRefMemoryObject - Simple StringRef-backed MemoryObject
name|class
name|StringRefMemoryObject
range|:
name|public
name|MemoryObject
block|{
name|StringRef
name|Bytes
block|;
name|uint64_t
name|Base
block|;
name|public
operator|:
name|StringRefMemoryObject
argument_list|(
argument|StringRef Bytes
argument_list|,
argument|uint64_t Base =
literal|0
argument_list|)
operator|:
name|Bytes
argument_list|(
name|Bytes
argument_list|)
block|,
name|Base
argument_list|(
argument|Base
argument_list|)
block|{}
name|uint64_t
name|getBase
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
name|Base
return|;
block|}
name|uint64_t
name|getExtent
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
name|Bytes
operator|.
name|size
argument_list|()
return|;
block|}
name|int
name|readByte
argument_list|(
argument|uint64_t Addr
argument_list|,
argument|uint8_t *Byte
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|int
name|readBytes
argument_list|(
argument|uint64_t Addr
argument_list|,
argument|uint64_t Size
argument_list|,
argument|uint8_t *Buf
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


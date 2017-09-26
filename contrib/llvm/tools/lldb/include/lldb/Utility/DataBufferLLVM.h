begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DataBufferLLVM.h ---------------------------------------*- C++ -*-===//
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
name|LLDB_CORE_DATABUFFERLLVM_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_CORE_DATABUFFERLLVM_H
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/DataBuffer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for offset_t
end_comment

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint8_t, uint64_t
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|Twine
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DataBufferLLVM
range|:
name|public
name|DataBuffer
block|{
name|public
operator|:
operator|~
name|DataBufferLLVM
argument_list|()
block|;
specifier|static
name|std
operator|::
name|shared_ptr
operator|<
name|DataBufferLLVM
operator|>
name|CreateSliceFromPath
argument_list|(
argument|const llvm::Twine&Path
argument_list|,
argument|uint64_t Size
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|bool Private = false
argument_list|)
block|;
specifier|static
name|std
operator|::
name|shared_ptr
operator|<
name|DataBufferLLVM
operator|>
name|CreateFromPath
argument_list|(
argument|const llvm::Twine&Path
argument_list|,
argument|bool NullTerminate = false
argument_list|,
argument|bool Private = false
argument_list|)
block|;
name|uint8_t
operator|*
name|GetBytes
argument_list|()
name|override
block|;
specifier|const
name|uint8_t
operator|*
name|GetBytes
argument_list|()
specifier|const
name|override
block|;
name|lldb
operator|::
name|offset_t
name|GetByteSize
argument_list|()
specifier|const
name|override
block|;
name|char
operator|*
name|GetChars
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|GetBytes
argument_list|()
operator|)
return|;
block|}
name|private
operator|:
comment|/// \brief Construct a DataBufferLLVM from \p Buffer.  \p Buffer must be a
comment|/// valid pointer.
name|explicit
name|DataBufferLLVM
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Buffer
argument_list|)
block|;
specifier|const
name|uint8_t
operator|*
name|GetBuffer
argument_list|()
specifier|const
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Buffer
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


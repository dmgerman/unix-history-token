begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ObjectMemoryBuffer.h - SmallVector-backed MemoryBuffrer  -*- C++ -*-===//
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
name|LLVM_EXECUTIONENGINE_OBJECTMEMORYBUFFER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_OBJECTMEMORYBUFFER_H
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
comment|/// \brief SmallVector-backed MemoryBuffer instance.
comment|///
comment|/// This class enables efficient construction of MemoryBuffers from SmallVector
comment|/// instances. This is useful for MCJIT and Orc, where object files are streamed
comment|/// into SmallVectors, then inspected using ObjectFile (which takes a
comment|/// MemoryBuffer).
name|class
name|ObjectMemoryBuffer
range|:
name|public
name|MemoryBuffer
block|{
name|public
operator|:
comment|/// \brief Construct an ObjectMemoryBuffer from the given SmallVector r-value.
comment|///
comment|/// FIXME: It'd be nice for this to be a non-templated constructor taking a
comment|/// SmallVectorImpl here instead of a templated one taking a SmallVector<N>,
comment|/// but SmallVector's move-construction/assignment currently only take
comment|/// SmallVectors. If/when that is fixed we can simplify this constructor and
comment|/// the following one.
name|ObjectMemoryBuffer
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&&
name|SV
argument_list|)
operator|:
name|SV
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|SV
argument_list|)
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
comment|/// \brief Construct a named ObjectMemoryBuffer from the given SmallVector
comment|///        r-value and StringRef.
name|ObjectMemoryBuffer
argument_list|(
argument|SmallVectorImpl<char>&&SV
argument_list|,
argument|StringRef Name
argument_list|)
operator|:
name|SV
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|SV
argument_list|)
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
name|StringRef
name|getBufferIdentifier
argument_list|()
specifier|const
name|override
block|{
return|return
name|BufferName
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
literal|0
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


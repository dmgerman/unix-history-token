begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SequencedItemStream.h ------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_MSF_SEQUENCEDITEMSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_MSF_SEQUENCEDITEMSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/MSF/MSFError.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/MSF/StreamInterface.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|msf
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|SequencedItemTraits
block|{
specifier|static
name|size_t
name|length
argument_list|(
specifier|const
name|T
operator|&
name|Item
argument_list|)
operator|=
name|delete
block|;
specifier|static
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|bytes
argument_list|(
specifier|const
name|T
operator|&
name|Item
argument_list|)
operator|=
name|delete
block|; }
expr_stmt|;
comment|/// SequencedItemStream represents a sequence of objects stored in a
comment|/// standard container but for which it is useful to view as a stream of
comment|/// contiguous bytes.  An example of this might be if you have a std::vector
comment|/// of TPI records, where each record contains a byte sequence that
comment|/// represents that one record serialized, but where each consecutive item
comment|/// might not be allocated immediately after the previous item.  Using a
comment|/// SequencedItemStream, we can adapt the VarStreamArray class to trivially
comment|/// extract one item at a time, allowing the data to be used anywhere a
comment|/// VarStreamArray could be used.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Traits
operator|=
name|SequencedItemTraits
operator|<
name|T
operator|>>
name|class
name|SequencedItemStream
operator|:
name|public
name|ReadableStream
block|{
name|public
operator|:
name|SequencedItemStream
argument_list|()
operator|=
expr|default
block|;
name|Error
name|readBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|uint32_t Size
argument_list|,
argument|ArrayRef<uint8_t>&Buffer
argument_list|)
specifier|const
name|override
block|{
name|auto
name|ExpectedIndex
operator|=
name|translateOffsetIndex
argument_list|(
name|Offset
argument_list|)
block|;
if|if
condition|(
operator|!
name|ExpectedIndex
condition|)
return|return
name|ExpectedIndex
operator|.
name|takeError
argument_list|()
return|;
specifier|const
name|auto
operator|&
name|Item
operator|=
name|Items
index|[
operator|*
name|ExpectedIndex
index|]
block|;
if|if
condition|(
name|Size
operator|>
name|Traits
operator|::
name|length
argument_list|(
name|Item
argument_list|)
condition|)
return|return
name|make_error
operator|<
name|MSFError
operator|>
operator|(
name|msf_error_code
operator|::
name|insufficient_buffer
operator|)
return|;
name|Buffer
operator|=
name|Traits
operator|::
name|bytes
argument_list|(
name|Item
argument_list|)
operator|.
name|take_front
argument_list|(
name|Size
argument_list|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|Error
name|readLongestContiguousChunk
argument_list|(
name|uint32_t
name|Offset
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|Buffer
argument_list|)
decl|const
name|override
block|{
name|auto
name|ExpectedIndex
init|=
name|translateOffsetIndex
argument_list|(
name|Offset
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ExpectedIndex
condition|)
return|return
name|ExpectedIndex
operator|.
name|takeError
argument_list|()
return|;
name|Buffer
operator|=
name|Traits
operator|::
name|bytes
argument_list|(
name|Items
index|[
operator|*
name|ExpectedIndex
index|]
argument_list|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|void
name|setItems
argument_list|(
name|ArrayRef
operator|<
name|T
operator|>
name|ItemArray
argument_list|)
block|{
name|Items
operator|=
name|ItemArray
expr_stmt|;
block|}
name|uint32_t
name|getLength
argument_list|()
specifier|const
name|override
block|{
name|uint32_t
name|Size
operator|=
literal|0
block|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Item
range|:
name|Items
control|)
name|Size
operator|+=
name|Traits
operator|::
name|length
argument_list|(
name|Item
argument_list|)
expr_stmt|;
return|return
name|Size
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|Expected
operator|<
name|uint32_t
operator|>
name|translateOffsetIndex
argument_list|(
argument|uint32_t Offset
argument_list|)
specifier|const
block|{
name|uint32_t
name|CurrentOffset
operator|=
literal|0
block|;
name|uint32_t
name|CurrentIndex
operator|=
literal|0
block|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Item
range|:
name|Items
control|)
block|{
if|if
condition|(
name|CurrentOffset
operator|>=
name|Offset
condition|)
break|break;
name|CurrentOffset
operator|+=
name|Traits
operator|::
name|length
argument_list|(
name|Item
argument_list|)
expr_stmt|;
operator|++
name|CurrentIndex
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|CurrentOffset
operator|!=
name|Offset
condition|)
return|return
name|make_error
operator|<
name|MSFError
operator|>
operator|(
name|msf_error_code
operator|::
name|insufficient_buffer
operator|)
return|;
end_if

begin_return
return|return
name|CurrentIndex
return|;
end_return

begin_expr_stmt
unit|}    ArrayRef
operator|<
name|T
operator|>
name|Items
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace msf
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_MSF_SEQUENCEDITEMSTREAM_H
end_comment

end_unit


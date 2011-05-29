begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/circular_raw_ostream.h - Buffered streams --*- C++ -*-===//
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
comment|// This file contains raw_ostream implementations for streams to do circular
end_comment

begin_comment
comment|// buffering of their output.
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
name|LLVM_SUPPORT_CIRCULAR_RAW_OSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CIRCULAR_RAW_OSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// circular_raw_ostream - A raw_ostream which *can* save its data
comment|/// to a circular buffer, or can pass it through directly to an
comment|/// underlying stream if specified with a buffer of zero.
comment|///
name|class
name|circular_raw_ostream
range|:
name|public
name|raw_ostream
block|{
name|public
operator|:
comment|/// TAKE_OWNERSHIP - Tell this stream that it owns the underlying
comment|/// stream and is responsible for cleanup, memory management
comment|/// issues, etc.
comment|///
specifier|static
specifier|const
name|bool
name|TAKE_OWNERSHIP
operator|=
name|true
block|;
comment|/// REFERENCE_ONLY - Tell this stream it should not manage the
comment|/// held stream.
comment|///
specifier|static
specifier|const
name|bool
name|REFERENCE_ONLY
operator|=
name|false
block|;
name|private
operator|:
comment|/// TheStream - The real stream we output to. We set it to be
comment|/// unbuffered, since we're already doing our own buffering.
comment|///
name|raw_ostream
operator|*
name|TheStream
block|;
comment|/// OwnsStream - Are we responsible for managing the underlying
comment|/// stream?
comment|///
name|bool
name|OwnsStream
block|;
comment|/// BufferSize - The size of the buffer in bytes.
comment|///
name|size_t
name|BufferSize
block|;
comment|/// BufferArray - The actual buffer storage.
comment|///
name|char
operator|*
name|BufferArray
block|;
comment|/// Cur - Pointer to the current output point in BufferArray.
comment|///
name|char
operator|*
name|Cur
block|;
comment|/// Filled - Indicate whether the buffer has been completely
comment|/// filled.  This helps avoid garbage output.
comment|///
name|bool
name|Filled
block|;
comment|/// Banner - A pointer to a banner to print before dumping the
comment|/// log.
comment|///
specifier|const
name|char
operator|*
name|Banner
block|;
comment|/// flushBuffer - Dump the contents of the buffer to Stream.
comment|///
name|void
name|flushBuffer
argument_list|(
argument|void
argument_list|)
block|{
if|if
condition|(
name|Filled
condition|)
comment|// Write the older portion of the buffer.
name|TheStream
operator|->
name|write
argument_list|(
name|Cur
argument_list|,
name|BufferArray
operator|+
name|BufferSize
operator|-
name|Cur
argument_list|)
expr_stmt|;
comment|// Write the newer portion of the buffer.
name|TheStream
operator|->
name|write
argument_list|(
name|BufferArray
argument_list|,
name|Cur
operator|-
name|BufferArray
argument_list|)
block|;
name|Cur
operator|=
name|BufferArray
block|;
name|Filled
operator|=
name|false
block|;     }
name|virtual
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|)
decl_stmt|;
comment|/// current_pos - Return the current position within the stream,
comment|/// not counting the bytes currently in the buffer.
comment|///
name|virtual
name|uint64_t
name|current_pos
argument_list|()
specifier|const
block|{
comment|// This has the same effect as calling TheStream.current_pos(),
comment|// but that interface is private.
return|return
name|TheStream
operator|->
name|tell
argument_list|()
operator|-
name|TheStream
operator|->
name|GetNumBytesInBuffer
argument_list|()
return|;
block|}
name|public
label|:
comment|/// circular_raw_ostream - Construct an optionally
comment|/// circular-buffered stream, handing it an underlying stream to
comment|/// do the "real" output.
comment|///
comment|/// As a side effect, if BuffSize is nonzero, the given Stream is
comment|/// set to be Unbuffered.  This is because circular_raw_ostream
comment|/// does its own buffering, so it doesn't want another layer of
comment|/// buffering to be happening underneath it.
comment|///
comment|/// "Owns" tells the circular_raw_ostream whether it is
comment|/// responsible for managing the held stream, doing memory
comment|/// management of it, etc.
comment|///
name|circular_raw_ostream
argument_list|(
argument|raw_ostream&Stream
argument_list|,
argument|const char *Header
argument_list|,
argument|size_t BuffSize =
literal|0
argument_list|,
argument|bool Owns = REFERENCE_ONLY
argument_list|)
block|:
name|raw_ostream
argument_list|(
comment|/*unbuffered*/
name|true
argument_list|)
operator|,
name|TheStream
argument_list|(
literal|0
argument_list|)
operator|,
name|OwnsStream
argument_list|(
name|Owns
argument_list|)
operator|,
name|BufferSize
argument_list|(
name|BuffSize
argument_list|)
operator|,
name|BufferArray
argument_list|(
literal|0
argument_list|)
operator|,
name|Filled
argument_list|(
name|false
argument_list|)
operator|,
name|Banner
argument_list|(
argument|Header
argument_list|)
block|{
if|if
condition|(
name|BufferSize
operator|!=
literal|0
condition|)
name|BufferArray
operator|=
name|new
name|char
index|[
name|BufferSize
index|]
expr_stmt|;
name|Cur
operator|=
name|BufferArray
expr_stmt|;
name|setStream
argument_list|(
name|Stream
argument_list|,
name|Owns
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|circular_raw_ostream
argument_list|()
operator|:
name|raw_ostream
argument_list|(
comment|/*unbuffered*/
name|true
argument_list|)
operator|,
name|TheStream
argument_list|(
literal|0
argument_list|)
operator|,
name|OwnsStream
argument_list|(
name|REFERENCE_ONLY
argument_list|)
operator|,
name|BufferArray
argument_list|(
literal|0
argument_list|)
operator|,
name|Filled
argument_list|(
name|false
argument_list|)
operator|,
name|Banner
argument_list|(
literal|""
argument_list|)
block|{
name|Cur
operator|=
name|BufferArray
block|;     }
operator|~
name|circular_raw_ostream
argument_list|()
block|{
name|flush
argument_list|()
block|;
name|flushBufferWithBanner
argument_list|()
block|;
name|releaseStream
argument_list|()
block|;
name|delete
index|[]
name|BufferArray
block|;     }
comment|/// setStream - Tell the circular_raw_ostream to output a
comment|/// different stream.  "Owns" tells circular_raw_ostream whether
comment|/// it should take responsibility for managing the underlying
comment|/// stream.
comment|///
name|void
name|setStream
argument_list|(
argument|raw_ostream&Stream
argument_list|,
argument|bool Owns = REFERENCE_ONLY
argument_list|)
block|{
name|releaseStream
argument_list|()
block|;
name|TheStream
operator|=
operator|&
name|Stream
block|;
name|OwnsStream
operator|=
name|Owns
block|;     }
comment|/// flushBufferWithBanner - Force output of the buffer along with
comment|/// a small header.
comment|///
name|void
name|flushBufferWithBanner
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// releaseStream - Delete the held stream if needed. Otherwise,
end_comment

begin_comment
comment|/// transfer the buffer settings from this circular_raw_ostream
end_comment

begin_comment
comment|/// back to the underlying stream.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|void
name|releaseStream
parameter_list|()
block|{
if|if
condition|(
operator|!
name|TheStream
condition|)
return|return;
if|if
condition|(
name|OwnsStream
condition|)
name|delete
name|TheStream
decl_stmt|;
block|}
end_function

begin_comment
unit|}; }
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


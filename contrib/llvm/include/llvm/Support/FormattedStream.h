begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/FormattedStream.h - Formatted streams ------*- C++ -*-===//
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
comment|// This file contains raw_ostream implementations for streams to do
end_comment

begin_comment
comment|// things like pretty-print comments.
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
name|LLVM_SUPPORT_FORMATTEDSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FORMATTEDSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// formatted_raw_ostream - A raw_ostream that wraps another one and keeps track
comment|/// of line and column position, allowing padding out to specific column
comment|/// boundaries and querying the number of lines written to the stream.
comment|///
name|class
name|formatted_raw_ostream
range|:
name|public
name|raw_ostream
block|{
name|public
operator|:
comment|/// DELETE_STREAM - Tell the destructor to delete the held stream.
comment|///
specifier|static
specifier|const
name|bool
name|DELETE_STREAM
operator|=
name|true
block|;
comment|/// PRESERVE_STREAM - Tell the destructor to not delete the held
comment|/// stream.
comment|///
specifier|static
specifier|const
name|bool
name|PRESERVE_STREAM
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
comment|/// DeleteStream - Do we need to delete TheStream in the
comment|/// destructor?
comment|///
name|bool
name|DeleteStream
block|;
comment|/// Position - The current output column and line of the data that's
comment|/// been flushed and the portion of the buffer that's been
comment|/// scanned.  The line and column scheme is zero-based.
comment|///
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|Position
block|;
comment|/// Scanned - This points to one past the last character in the
comment|/// buffer we've scanned.
comment|///
specifier|const
name|char
operator|*
name|Scanned
block|;
name|virtual
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|)
name|LLVM_OVERRIDE
block|;
comment|/// current_pos - Return the current position within the stream,
comment|/// not counting the bytes currently in the buffer.
name|virtual
name|uint64_t
name|current_pos
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|{
comment|// Our current position in the stream is all the contents which have been
comment|// written to the underlying stream (*not* the current position of the
comment|// underlying stream).
return|return
name|TheStream
operator|->
name|tell
argument_list|()
return|;
block|}
comment|/// ComputePosition - Examine the given output buffer and figure out the new
comment|/// position after output.
comment|///
name|void
name|ComputePosition
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t size
argument_list|)
block|;
name|public
operator|:
comment|/// formatted_raw_ostream - Open the specified file for
comment|/// writing. If an error occurs, information about the error is
comment|/// put into ErrorInfo, and the stream should be immediately
comment|/// destroyed; the string will be empty if no error occurred.
comment|///
comment|/// As a side effect, the given Stream is set to be Unbuffered.
comment|/// This is because formatted_raw_ostream does its own buffering,
comment|/// so it doesn't want another layer of buffering to be happening
comment|/// underneath it.
comment|///
name|formatted_raw_ostream
argument_list|(
argument|raw_ostream&Stream
argument_list|,
argument|bool Delete = false
argument_list|)
operator|:
name|raw_ostream
argument_list|()
block|,
name|TheStream
argument_list|(
literal|0
argument_list|)
block|,
name|DeleteStream
argument_list|(
name|false
argument_list|)
block|,
name|Position
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
block|{
name|setStream
argument_list|(
name|Stream
argument_list|,
name|Delete
argument_list|)
block|;   }
name|explicit
name|formatted_raw_ostream
argument_list|()
operator|:
name|raw_ostream
argument_list|()
block|,
name|TheStream
argument_list|(
literal|0
argument_list|)
block|,
name|DeleteStream
argument_list|(
name|false
argument_list|)
block|,
name|Position
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
block|{
name|Scanned
operator|=
literal|0
block|;   }
operator|~
name|formatted_raw_ostream
argument_list|()
block|{
name|flush
argument_list|()
block|;
name|releaseStream
argument_list|()
block|;   }
name|void
name|setStream
argument_list|(
argument|raw_ostream&Stream
argument_list|,
argument|bool Delete = false
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
name|DeleteStream
operator|=
name|Delete
block|;
comment|// This formatted_raw_ostream inherits from raw_ostream, so it'll do its
comment|// own buffering, and it doesn't need or want TheStream to do another
comment|// layer of buffering underneath. Resize the buffer to what TheStream
comment|// had been using, and tell TheStream not to do its own buffering.
if|if
condition|(
name|size_t
name|BufferSize
init|=
name|TheStream
operator|->
name|GetBufferSize
argument_list|()
condition|)
name|SetBufferSize
argument_list|(
name|BufferSize
argument_list|)
expr_stmt|;
else|else
name|SetUnbuffered
argument_list|()
expr_stmt|;
name|TheStream
operator|->
name|SetUnbuffered
argument_list|()
block|;
name|Scanned
operator|=
literal|0
block|;   }
comment|/// PadToColumn - Align the output to some column number.  If the current
comment|/// column is already equal to or more than NewCol, PadToColumn inserts one
comment|/// space.
comment|///
comment|/// \param NewCol - The column to move to.
name|formatted_raw_ostream
operator|&
name|PadToColumn
argument_list|(
argument|unsigned NewCol
argument_list|)
decl_stmt|;
comment|/// getColumn - Return the column number
name|unsigned
name|getColumn
parameter_list|()
block|{
return|return
name|Position
operator|.
name|first
return|;
block|}
comment|/// getLine - Return the line number
name|unsigned
name|getLine
parameter_list|()
block|{
return|return
name|Position
operator|.
name|second
return|;
block|}
name|raw_ostream
modifier|&
name|resetColor
parameter_list|()
block|{
name|TheStream
operator|->
name|resetColor
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|raw_ostream
modifier|&
name|reverseColor
parameter_list|()
block|{
name|TheStream
operator|->
name|reverseColor
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|raw_ostream
modifier|&
name|changeColor
parameter_list|(
name|enum
name|Colors
name|Color
parameter_list|,
name|bool
name|Bold
parameter_list|,
name|bool
name|BG
parameter_list|)
block|{
name|TheStream
operator|->
name|changeColor
argument_list|(
name|Color
argument_list|,
name|Bold
argument_list|,
name|BG
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|bool
name|is_displayed
argument_list|()
specifier|const
block|{
return|return
name|TheStream
operator|->
name|is_displayed
argument_list|()
return|;
block|}
name|private
label|:
name|void
name|releaseStream
parameter_list|()
block|{
comment|// Delete the stream if needed. Otherwise, transfer the buffer
comment|// settings from this raw_ostream back to the underlying stream.
if|if
condition|(
operator|!
name|TheStream
condition|)
return|return;
if|if
condition|(
name|DeleteStream
condition|)
name|delete
name|TheStream
decl_stmt|;
elseif|else
if|if
condition|(
name|size_t
name|BufferSize
init|=
name|GetBufferSize
argument_list|()
condition|)
name|TheStream
operator|->
name|SetBufferSize
argument_list|(
name|BufferSize
argument_list|)
expr_stmt|;
else|else
name|TheStream
operator|->
name|SetUnbuffered
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// fouts() - This returns a reference to a formatted_raw_ostream for
end_comment

begin_comment
comment|/// standard output.  Use it like: fouts()<< "foo"<< "bar";
end_comment

begin_function_decl
name|formatted_raw_ostream
modifier|&
name|fouts
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// ferrs() - This returns a reference to a formatted_raw_ostream for
end_comment

begin_comment
comment|/// standard error.  Use it like: ferrs()<< "foo"<< "bar";
end_comment

begin_function_decl
name|formatted_raw_ostream
modifier|&
name|ferrs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// fdbgs() - This returns a reference to a formatted_raw_ostream for
end_comment

begin_comment
comment|/// debug output.  Use it like: fdbgs()<< "foo"<< "bar";
end_comment

begin_function_decl
name|formatted_raw_ostream
modifier|&
name|fdbgs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


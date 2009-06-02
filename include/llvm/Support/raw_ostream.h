begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- raw_ostream.h - Raw output stream ----------------------*- C++ -*-===//
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
comment|//  This file defines the raw_ostream class.
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
name|LLVM_SUPPORT_RAW_OSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_RAW_OSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringExtras.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|format_object_base
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|/// raw_ostream - This class implements an extremely fast bulk output stream
comment|/// that can *only* output to a stream.  It does not support seeking, reopening,
comment|/// rewinding, line buffered disciplines etc. It is a simple buffer that outputs
comment|/// a chunk at a time.
name|class
name|raw_ostream
block|{
name|private
label|:
comment|/// The buffer is handled in such a way that the buffer is
comment|/// uninitialized, unbuffered, or out of space when OutBufCur>=
comment|/// OutBufEnd. Thus a single comparison suffices to determine if we
comment|/// need to take the slow path to write a single character.
comment|///
comment|/// The buffer is in one of three states:
comment|///  1. Unbuffered (Unbuffered == true)
comment|///  1. Uninitialized (Unbuffered == false&& OutBufStart == 0).
comment|///  2. Buffered (Unbuffered == false&& OutBufStart != 0&&
comment|///               OutBufEnd - OutBufStart>= 64).
name|char
modifier|*
name|OutBufStart
decl_stmt|,
modifier|*
name|OutBufEnd
decl_stmt|,
modifier|*
name|OutBufCur
decl_stmt|;
name|bool
name|Unbuffered
decl_stmt|;
name|public
label|:
name|explicit
name|raw_ostream
argument_list|(
argument|bool unbuffered=false
argument_list|)
block|:
name|Unbuffered
argument_list|(
argument|unbuffered
argument_list|)
block|{
comment|// Start out ready to flush.
name|OutBufStart
operator|=
name|OutBufEnd
operator|=
name|OutBufCur
operator|=
literal|0
expr_stmt|;
block|}
name|virtual
operator|~
name|raw_ostream
argument_list|()
block|{
name|delete
index|[]
name|OutBufStart
block|;   }
comment|/// tell - Return the current offset with the file.
name|uint64_t
name|tell
argument_list|()
block|{
return|return
name|current_pos
argument_list|()
operator|+
name|GetNumBytesInBuffer
argument_list|()
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Configuration Interface
comment|//===--------------------------------------------------------------------===//
comment|/// SetBufferSize - Set the internal buffer size to the specified amount
comment|/// instead of the default.
name|void
name|SetBufferSize
parameter_list|(
name|unsigned
name|Size
init|=
literal|4096
parameter_list|)
block|{
name|assert
argument_list|(
name|Size
operator|>=
literal|64
operator|&&
literal|"Buffer size must be somewhat large for invariants to hold"
argument_list|)
expr_stmt|;
name|flush
argument_list|()
expr_stmt|;
name|delete
index|[]
name|OutBufStart
decl_stmt|;
name|OutBufStart
operator|=
name|new
name|char
index|[
name|Size
index|]
expr_stmt|;
name|OutBufEnd
operator|=
name|OutBufStart
operator|+
name|Size
expr_stmt|;
name|OutBufCur
operator|=
name|OutBufStart
expr_stmt|;
name|Unbuffered
operator|=
name|false
expr_stmt|;
block|}
comment|/// SetUnbuffered - Set the streams buffering status. When
comment|/// unbuffered the stream will flush after every write. This routine
comment|/// will also flush the buffer immediately when the stream is being
comment|/// set to unbuffered.
name|void
name|SetUnbuffered
parameter_list|()
block|{
name|flush
argument_list|()
expr_stmt|;
name|delete
index|[]
name|OutBufStart
decl_stmt|;
name|OutBufStart
operator|=
name|OutBufEnd
operator|=
name|OutBufCur
operator|=
literal|0
expr_stmt|;
name|Unbuffered
operator|=
name|true
expr_stmt|;
block|}
name|unsigned
name|GetNumBytesInBuffer
argument_list|()
specifier|const
block|{
return|return
name|OutBufCur
operator|-
name|OutBufStart
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Data Output Interface
comment|//===--------------------------------------------------------------------===//
name|void
name|flush
parameter_list|()
block|{
if|if
condition|(
name|OutBufCur
operator|!=
name|OutBufStart
condition|)
name|flush_nonempty
argument_list|()
expr_stmt|;
block|}
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|char
name|C
operator|)
block|{
if|if
condition|(
name|OutBufCur
operator|>=
name|OutBufEnd
condition|)
return|return
name|write
argument_list|(
name|C
argument_list|)
return|;
operator|*
name|OutBufCur
operator|++
operator|=
name|C
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|char
name|C
operator|)
block|{
if|if
condition|(
name|OutBufCur
operator|>=
name|OutBufEnd
condition|)
return|return
name|write
argument_list|(
name|C
argument_list|)
return|;
operator|*
name|OutBufCur
operator|++
operator|=
name|C
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|signed
name|char
name|C
operator|)
block|{
if|if
condition|(
name|OutBufCur
operator|>=
name|OutBufEnd
condition|)
return|return
name|write
argument_list|(
name|C
argument_list|)
return|;
operator|*
name|OutBufCur
operator|++
operator|=
name|C
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}    raw_ostream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|Str
operator|)
block|{
comment|// Inline fast path, particulary for constant strings where a
comment|// sufficiently smart compiler will simplify strlen.
name|unsigned
name|Size
operator|=
name|strlen
argument_list|(
name|Str
argument_list|)
block|;
comment|// Make sure we can use the fast path.
if|if
condition|(
name|OutBufCur
operator|+
name|Size
operator|>
name|OutBufEnd
condition|)
return|return
name|write
argument_list|(
name|Str
argument_list|,
name|Size
argument_list|)
return|;
name|memcpy
argument_list|(
name|OutBufCur
argument_list|,
name|Str
argument_list|,
name|Size
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OutBufCur
operator|+=
name|Size
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}    raw_ostream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
operator|)
block|{
name|write
argument_list|(
name|Str
operator|.
name|data
argument_list|()
argument_list|,
name|Str
operator|.
name|length
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|long
name|N
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|long
name|N
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|long
name|long
name|N
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|long
name|long
name|N
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|void
operator|*
name|P
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|int
name|N
operator|)
block|{
name|this
operator|->
name|operator
operator|<<
operator|(
name|static_cast
operator|<
name|unsigned
name|long
operator|>
operator|(
name|N
operator|)
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|int
name|N
operator|)
block|{
name|this
operator|->
name|operator
operator|<<
operator|(
name|static_cast
operator|<
name|long
operator|>
operator|(
name|N
operator|)
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|double
name|N
operator|)
block|{
name|this
operator|->
name|operator
operator|<<
operator|(
name|ftostr
argument_list|(
name|N
argument_list|)
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_function_decl
name|raw_ostream
modifier|&
name|write
parameter_list|(
name|unsigned
name|char
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|raw_ostream
modifier|&
name|write
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Formatted output, see the format() function in Support/Format.h.
end_comment

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|format_object_base
operator|&
name|Fmt
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Subclass Interface
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_label
name|private
label|:
end_label

begin_comment
comment|/// write_impl - The is the piece of the class that is implemented
end_comment

begin_comment
comment|/// by subclasses.  This writes the \args Size bytes starting at
end_comment

begin_comment
comment|/// \arg Ptr to the underlying stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \invariant { Size> 0 }
end_comment

begin_function_decl
name|virtual
name|void
name|write_impl
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|,
name|unsigned
name|Size
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|// An out of line virtual method to provide a home for the class vtable.
end_comment

begin_function_decl
name|virtual
name|void
name|handle
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// current_pos - Return the current position within the stream, not
end_comment

begin_comment
comment|/// counting the bytes currently in the buffer.
end_comment

begin_function_decl
name|virtual
name|uint64_t
name|current_pos
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Private Interface
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_label
name|private
label|:
end_label

begin_comment
comment|/// flush_nonempty - Flush the current buffer, which is known to be
end_comment

begin_comment
comment|/// non-empty. This outputs the currently buffered data and resets
end_comment

begin_comment
comment|/// the buffer to empty.
end_comment

begin_function_decl
name|void
name|flush_nonempty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// File Output Streams
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// raw_fd_ostream - A raw_ostream that writes to a file descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|raw_fd_ostream
range|:
name|public
name|raw_ostream
block|{
name|int
name|FD
block|;
name|bool
name|ShouldClose
block|;
name|uint64_t
name|pos
block|;
comment|/// write_impl - See raw_ostream::write_impl.
name|virtual
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|unsigned Size
argument_list|)
block|;
comment|/// current_pos - Return the current position within the stream, not
comment|/// counting the bytes currently in the buffer.
name|virtual
name|uint64_t
name|current_pos
argument_list|()
block|{
return|return
name|pos
return|;
block|}
name|public
operator|:
comment|/// raw_fd_ostream - Open the specified file for writing. If an
comment|/// error occurs, information about the error is put into ErrorInfo,
comment|/// and the stream should be immediately destroyed; the string will
comment|/// be empty if no error occurred.
comment|///
comment|/// \param Filename - The file to open. If this is "-" then the
comment|/// stream will use stdout instead.
comment|/// \param Binary - The file should be opened in binary mode on
comment|/// platforms that support this distinction.
name|raw_fd_ostream
argument_list|(
argument|const char *Filename
argument_list|,
argument|bool Binary
argument_list|,
argument|std::string&ErrorInfo
argument_list|)
block|;
comment|/// raw_fd_ostream ctor - FD is the file descriptor that this writes to.  If
comment|/// ShouldClose is true, this closes the file when the stream is destroyed.
name|raw_fd_ostream
argument_list|(
argument|int fd
argument_list|,
argument|bool shouldClose
argument_list|,
argument|bool unbuffered=false
argument_list|)
operator|:
name|raw_ostream
argument_list|(
name|unbuffered
argument_list|)
block|,
name|FD
argument_list|(
name|fd
argument_list|)
block|,
name|ShouldClose
argument_list|(
argument|shouldClose
argument_list|)
block|{}
operator|~
name|raw_fd_ostream
argument_list|()
block|;
comment|/// close - Manually flush the stream and close the file.
name|void
name|close
argument_list|()
block|;
comment|/// tell - Return the current offset with the file.
name|uint64_t
name|tell
argument_list|()
block|{
return|return
name|pos
operator|+
name|GetNumBytesInBuffer
argument_list|()
return|;
block|}
comment|/// seek - Flushes the stream and repositions the underlying file descriptor
comment|///  positition to the offset specified from the beginning of the file.
name|uint64_t
name|seek
argument_list|(
argument|uint64_t off
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// raw_stdout_ostream - This is a stream that always prints to stdout.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|raw_stdout_ostream
range|:
name|public
name|raw_fd_ostream
block|{
comment|// An out of line virtual method to provide a home for the class vtable.
name|virtual
name|void
name|handle
argument_list|()
block|;
name|public
operator|:
name|raw_stdout_ostream
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// raw_stderr_ostream - This is a stream that always prints to stderr.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|raw_stderr_ostream
range|:
name|public
name|raw_fd_ostream
block|{
comment|// An out of line virtual method to provide a home for the class vtable.
name|virtual
name|void
name|handle
argument_list|()
block|;
name|public
operator|:
name|raw_stderr_ostream
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// outs() - This returns a reference to a raw_ostream for standard output.
end_comment

begin_comment
comment|/// Use it like: outs()<< "foo"<< "bar";
end_comment

begin_function_decl
name|raw_ostream
modifier|&
name|outs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// errs() - This returns a reference to a raw_ostream for standard error.
end_comment

begin_comment
comment|/// Use it like: errs()<< "foo"<< "bar";
end_comment

begin_function_decl
name|raw_ostream
modifier|&
name|errs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Output Stream Adaptors
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// raw_os_ostream - A raw_ostream that writes to an std::ostream.  This is a
end_comment

begin_comment
comment|/// simple adaptor class.
end_comment

begin_decl_stmt
name|class
name|raw_os_ostream
range|:
name|public
name|raw_ostream
block|{
name|std
operator|::
name|ostream
operator|&
name|OS
block|;
comment|/// write_impl - See raw_ostream::write_impl.
name|virtual
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|unsigned Size
argument_list|)
block|;
comment|/// current_pos - Return the current position within the stream, not
comment|/// counting the bytes currently in the buffer.
name|virtual
name|uint64_t
name|current_pos
argument_list|()
block|;
name|public
operator|:
name|raw_os_ostream
argument_list|(
name|std
operator|::
name|ostream
operator|&
name|O
argument_list|)
operator|:
name|OS
argument_list|(
argument|O
argument_list|)
block|{}
operator|~
name|raw_os_ostream
argument_list|()
block|;
comment|/// tell - Return the current offset with the stream.
name|uint64_t
name|tell
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// raw_string_ostream - A raw_ostream that writes to an std::string.  This is a
end_comment

begin_comment
comment|/// simple adaptor class.
end_comment

begin_decl_stmt
name|class
name|raw_string_ostream
range|:
name|public
name|raw_ostream
block|{
name|std
operator|::
name|string
operator|&
name|OS
block|;
comment|/// write_impl - See raw_ostream::write_impl.
name|virtual
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|unsigned Size
argument_list|)
block|;
comment|/// current_pos - Return the current position within the stream, not
comment|/// counting the bytes currently in the buffer.
name|virtual
name|uint64_t
name|current_pos
argument_list|()
block|{
return|return
name|OS
operator|.
name|size
argument_list|()
return|;
block|}
name|public
operator|:
name|raw_string_ostream
argument_list|(
name|std
operator|::
name|string
operator|&
name|O
argument_list|)
operator|:
name|OS
argument_list|(
argument|O
argument_list|)
block|{}
operator|~
name|raw_string_ostream
argument_list|()
block|;
comment|/// tell - Return the current offset with the stream.
name|uint64_t
name|tell
argument_list|()
block|{
return|return
name|OS
operator|.
name|size
argument_list|()
operator|+
name|GetNumBytesInBuffer
argument_list|()
return|;
block|}
comment|/// str - Flushes the stream contents to the target string and returns
comment|///  the string's reference.
name|std
operator|::
name|string
operator|&
name|str
argument_list|()
block|{
name|flush
argument_list|()
block|;
return|return
name|OS
return|;
block|}
expr|}
block|;
comment|/// raw_svector_ostream - A raw_ostream that writes to an SmallVector or
comment|/// SmallString.  This is a simple adaptor class.
name|class
name|raw_svector_ostream
operator|:
name|public
name|raw_ostream
block|{
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|OS
block|;
comment|/// write_impl - See raw_ostream::write_impl.
name|virtual
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|unsigned Size
argument_list|)
block|;
comment|/// current_pos - Return the current position within the stream, not
comment|/// counting the bytes currently in the buffer.
name|virtual
name|uint64_t
name|current_pos
argument_list|()
block|;
name|public
operator|:
name|raw_svector_ostream
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|O
argument_list|)
operator|:
name|OS
argument_list|(
argument|O
argument_list|)
block|{}
operator|~
name|raw_svector_ostream
argument_list|()
block|;
comment|/// tell - Return the current offset with the stream.
name|uint64_t
name|tell
argument_list|()
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


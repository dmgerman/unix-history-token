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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
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
comment|// Do not implement. raw_ostream is noncopyable.
name|void
name|operator
init|=
operator|(
specifier|const
name|raw_ostream
operator|&
operator|)
decl_stmt|;
name|raw_ostream
argument_list|(
specifier|const
name|raw_ostream
operator|&
argument_list|)
expr_stmt|;
comment|/// The buffer is handled in such a way that the buffer is
comment|/// uninitialized, unbuffered, or out of space when OutBufCur>=
comment|/// OutBufEnd. Thus a single comparison suffices to determine if we
comment|/// need to take the slow path to write a single character.
comment|///
comment|/// The buffer is in one of three states:
comment|///  1. Unbuffered (BufferMode == Unbuffered)
comment|///  1. Uninitialized (BufferMode != Unbuffered&& OutBufStart == 0).
comment|///  2. Buffered (BufferMode != Unbuffered&& OutBufStart != 0&&
comment|///               OutBufEnd - OutBufStart>= 1).
comment|///
comment|/// If buffered, then the raw_ostream owns the buffer if (BufferMode ==
comment|/// InternalBuffer); otherwise the buffer has been set via SetBuffer and is
comment|/// managed by the subclass.
comment|///
comment|/// If a subclass installs an external buffer using SetBuffer then it can wait
comment|/// for a \see write_impl() call to handle the data which has been put into
comment|/// this buffer.
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
enum|enum
name|BufferKind
block|{
name|Unbuffered
init|=
literal|0
block|,
name|InternalBuffer
block|,
name|ExternalBuffer
block|}
name|BufferMode
enum|;
comment|/// Error This flag is true if an error of any kind has been detected.
comment|///
name|bool
name|Error
decl_stmt|;
name|public
label|:
comment|// color order matches ANSI escape sequence, don't change
enum|enum
name|Colors
block|{
name|BLACK
init|=
literal|0
block|,
name|RED
block|,
name|GREEN
block|,
name|YELLOW
block|,
name|BLUE
block|,
name|MAGENTA
block|,
name|CYAN
block|,
name|WHITE
block|,
name|SAVEDCOLOR
block|}
enum|;
name|explicit
name|raw_ostream
argument_list|(
argument|bool unbuffered=false
argument_list|)
block|:
name|BufferMode
argument_list|(
name|unbuffered
condition|?
name|Unbuffered
else|:
name|InternalBuffer
argument_list|)
operator|,
name|Error
argument_list|(
argument|false
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
block|;   }
name|virtual
operator|~
name|raw_ostream
argument_list|()
expr_stmt|;
comment|/// tell - Return the current offset with the file.
name|uint64_t
name|tell
parameter_list|()
block|{
return|return
name|current_pos
argument_list|()
operator|+
name|GetNumBytesInBuffer
argument_list|()
return|;
block|}
comment|/// has_error - Return the value of the flag in this raw_ostream indicating
comment|/// whether an output error has been encountered.
name|bool
name|has_error
argument_list|()
specifier|const
block|{
return|return
name|Error
return|;
block|}
comment|/// clear_error - Set the flag read by has_error() to false. If the error
comment|/// flag is set at the time when this raw_ostream's destructor is called,
comment|/// llvm_report_error is called to report the error. Use clear_error()
comment|/// after handling the error to avoid this behavior.
name|void
name|clear_error
parameter_list|()
block|{
name|Error
operator|=
name|false
expr_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Configuration Interface
comment|//===--------------------------------------------------------------------===//
comment|/// SetBuffered - Set the stream to be buffered, with an automatically
comment|/// determined buffer size.
name|void
name|SetBuffered
parameter_list|()
function_decl|;
comment|/// SetBufferSize - Set the stream to be buffered, using the
comment|/// specified buffer size.
name|void
name|SetBufferSize
parameter_list|(
name|size_t
name|Size
parameter_list|)
block|{
name|flush
argument_list|()
expr_stmt|;
name|SetBufferAndMode
argument_list|(
argument|new char[Size]
argument_list|,
argument|Size
argument_list|,
argument|InternalBuffer
argument_list|)
empty_stmt|;
block|}
name|size_t
name|GetBufferSize
parameter_list|()
block|{
comment|// If we're supposed to be buffered but haven't actually gotten around
comment|// to allocating the buffer yet, return the value that would be used.
if|if
condition|(
name|BufferMode
operator|!=
name|Unbuffered
operator|&&
name|OutBufStart
operator|==
literal|0
condition|)
return|return
name|preferred_buffer_size
argument_list|()
return|;
comment|// Otherwise just return the size of the allocated buffer.
return|return
name|OutBufEnd
operator|-
name|OutBufStart
return|;
block|}
comment|/// SetUnbuffered - Set the stream to be unbuffered. When
comment|/// unbuffered, the stream will flush after every write. This routine
comment|/// will also flush the buffer immediately when the stream is being
comment|/// set to unbuffered.
name|void
name|SetUnbuffered
parameter_list|()
block|{
name|flush
argument_list|()
expr_stmt|;
name|SetBufferAndMode
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|Unbuffered
argument_list|)
expr_stmt|;
block|}
name|size_t
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
name|StringRef
operator|&
name|Str
operator|)
block|{
comment|// Inline fast path, particularly for strings with a known length.
name|size_t
name|Size
operator|=
name|Str
operator|.
name|size
argument_list|()
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
operator|.
name|data
argument_list|()
argument_list|,
name|Size
argument_list|)
return|;
name|memcpy
argument_list|(
name|OutBufCur
argument_list|,
name|Str
operator|.
name|data
argument_list|()
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
name|char
operator|*
name|Str
operator|)
block|{
comment|// Inline fast path, particulary for constant strings where a sufficiently
comment|// smart compiler will simplify strlen.
name|this
operator|->
name|operator
operator|<<
operator|(
name|StringRef
argument_list|(
name|Str
argument_list|)
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
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
operator|)
block|{
comment|// Avoid the fast path, it would only increase code size for a marginal win.
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// write_hex - Output \arg N in hexadecimal, without any prefix or padding.
end_comment

begin_function_decl
name|raw_ostream
modifier|&
name|write_hex
parameter_list|(
name|unsigned
name|long
name|long
name|N
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// write_escaped - Output \arg Str, turning '\\', '\t', '\n', '"', and
end_comment

begin_comment
comment|/// anything that doesn't satisfy std::isprint into an escape sequence.
end_comment

begin_function_decl
name|raw_ostream
modifier|&
name|write_escaped
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

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
name|size_t
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
comment|/// indent - Insert 'NumSpaces' spaces.
end_comment

begin_function_decl
name|raw_ostream
modifier|&
name|indent
parameter_list|(
name|unsigned
name|NumSpaces
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Changes the foreground color of text that will be output from this point
end_comment

begin_comment
comment|/// forward.
end_comment

begin_comment
comment|/// @param colors ANSI color to use, the special SAVEDCOLOR can be used to
end_comment

begin_comment
comment|/// change only the bold attribute, and keep colors untouched
end_comment

begin_comment
comment|/// @param bold bold/brighter text, default false
end_comment

begin_comment
comment|/// @param bg if true change the background, default: change foreground
end_comment

begin_comment
comment|/// @returns itself so it can be used within<< invocations
end_comment

begin_function
name|virtual
name|raw_ostream
modifier|&
name|changeColor
parameter_list|(
name|enum
name|Colors
parameter_list|,
name|bool
init|=
name|false
parameter_list|,
name|bool
init|=
name|false
parameter_list|)
block|{
return|return
operator|*
name|this
return|;
block|}
end_function

begin_comment
comment|/// Resets the colors to terminal defaults. Call this when you are done
end_comment

begin_comment
comment|/// outputting colored text, or before program exit.
end_comment

begin_function
name|virtual
name|raw_ostream
modifier|&
name|resetColor
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
end_function

begin_comment
comment|/// This function determines if this stream is connected to a "tty" or
end_comment

begin_comment
comment|/// "console" window. That is, the output would be displayed to the user
end_comment

begin_comment
comment|/// rather than being put on a pipe or stored in a file.
end_comment

begin_expr_stmt
name|virtual
name|bool
name|is_displayed
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
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
comment|/// This function is guaranteed to only be called at a point at which it is
end_comment

begin_comment
comment|/// safe for the subclass to install a new buffer via SetBuffer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \arg Ptr - The start of the data to be written. For buffered streams this
end_comment

begin_comment
comment|/// is guaranteed to be the start of the buffer.
end_comment

begin_comment
comment|/// \arg Size - The number of bytes to be written.
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
name|size_t
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

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// SetBuffer - Use the provided buffer as the raw_ostream buffer. This is
end_comment

begin_comment
comment|/// intended for use only by subclasses which can arrange for the output to go
end_comment

begin_comment
comment|/// directly into the desired output buffer, instead of being copied on each
end_comment

begin_comment
comment|/// flush.
end_comment

begin_function
name|void
name|SetBuffer
parameter_list|(
name|char
modifier|*
name|BufferStart
parameter_list|,
name|size_t
name|Size
parameter_list|)
block|{
name|SetBufferAndMode
argument_list|(
name|BufferStart
argument_list|,
name|Size
argument_list|,
name|ExternalBuffer
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// preferred_buffer_size - Return an efficient buffer size for the
end_comment

begin_comment
comment|/// underlying output mechanism.
end_comment

begin_function_decl
name|virtual
name|size_t
name|preferred_buffer_size
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// error_detected - Set the flag indicating that an output error has
end_comment

begin_comment
comment|/// been encountered.
end_comment

begin_function
name|void
name|error_detected
parameter_list|()
block|{
name|Error
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getBufferStart - Return the beginning of the current stream buffer, or 0
end_comment

begin_comment
comment|/// if the stream is unbuffered.
end_comment

begin_expr_stmt
specifier|const
name|char
operator|*
name|getBufferStart
argument_list|()
specifier|const
block|{
return|return
name|OutBufStart
return|;
block|}
end_expr_stmt

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
comment|/// SetBufferAndMode - Install the given buffer and mode.
end_comment

begin_function_decl
name|void
name|SetBufferAndMode
parameter_list|(
name|char
modifier|*
name|BufferStart
parameter_list|,
name|size_t
name|Size
parameter_list|,
name|BufferKind
name|Mode
parameter_list|)
function_decl|;
end_function_decl

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
comment|/// copy_to_buffer - Copy data into the buffer. Size must not be
end_comment

begin_comment
comment|/// greater than the number of unused bytes in the buffer.
end_comment

begin_function_decl
name|void
name|copy_to_buffer
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|,
name|size_t
name|Size
parameter_list|)
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
argument|size_t Size
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
comment|/// preferred_buffer_size - Determine an efficient buffer size.
name|virtual
name|size_t
name|preferred_buffer_size
argument_list|()
block|;
name|public
operator|:
expr|enum
block|{
comment|/// F_Excl - When opening a file, this flag makes raw_fd_ostream
comment|/// report an error if the file already exists.
name|F_Excl
operator|=
literal|1
block|,
comment|/// F_Append - When opening a file, if it already exists append to the
comment|/// existing file instead of returning an error.  This may not be specified
comment|/// with F_Excl.
name|F_Append
operator|=
literal|2
block|,
comment|/// F_Binary - The file should be opened in binary mode on platforms that
comment|/// make this distinction.
name|F_Binary
operator|=
literal|4
block|}
block|;
comment|/// raw_fd_ostream - Open the specified file for writing. If an error occurs,
comment|/// information about the error is put into ErrorInfo, and the stream should
comment|/// be immediately destroyed; the string will be empty if no error occurred.
comment|/// This allows optional flags to control how the file will be opened.
comment|///
comment|/// \param Filename - The file to open. If this is "-" then the
comment|/// stream will use stdout instead.
name|raw_fd_ostream
argument_list|(
argument|const char *Filename
argument_list|,
argument|std::string&ErrorInfo
argument_list|,
argument|unsigned Flags =
literal|0
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
comment|/// seek - Flushes the stream and repositions the underlying file descriptor
comment|///  positition to the offset specified from the beginning of the file.
name|uint64_t
name|seek
argument_list|(
argument|uint64_t off
argument_list|)
block|;
name|virtual
name|raw_ostream
operator|&
name|changeColor
argument_list|(
argument|enum Colors colors
argument_list|,
argument|bool bold=false
argument_list|,
argument|bool bg=false
argument_list|)
block|;
name|virtual
name|raw_ostream
operator|&
name|resetColor
argument_list|()
block|;
name|virtual
name|bool
name|is_displayed
argument_list|()
specifier|const
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
comment|/// nulls() - This returns a reference to a raw_ostream which simply discards
end_comment

begin_comment
comment|/// output.
end_comment

begin_function_decl
name|raw_ostream
modifier|&
name|nulls
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
comment|/// raw_string_ostream - A raw_ostream that writes to an std::string.  This is a
end_comment

begin_comment
comment|/// simple adaptor class. This class does not encounter output errors.
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
argument|size_t Size
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
name|explicit
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
comment|/// SmallString.  This is a simple adaptor class. This class does not
comment|/// encounter output errors.
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
argument|size_t Size
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
comment|/// Construct a new raw_svector_ostream.
comment|///
comment|/// \arg O - The vector to write to; this should generally have at least 128
comment|/// bytes free to avoid any extraneous memory overhead.
name|explicit
name|raw_svector_ostream
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|O
argument_list|)
block|;
operator|~
name|raw_svector_ostream
argument_list|()
block|;
comment|/// str - Flushes the stream contents to the target vector and return a
comment|/// StringRef for the vector contents.
name|StringRef
name|str
argument_list|()
block|; }
block|;
comment|/// raw_null_ostream - A raw_ostream that discards all output.
name|class
name|raw_null_ostream
operator|:
name|public
name|raw_ostream
block|{
comment|/// write_impl - See raw_ostream::write_impl.
name|virtual
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t size
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
name|explicit
name|raw_null_ostream
argument_list|()
block|{}
operator|~
name|raw_null_ostream
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


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
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|format_object_base
decl_stmt|;
name|class
name|FormattedString
decl_stmt|;
name|class
name|FormattedNumber
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|namespace
name|sys
block|{
name|namespace
name|fs
block|{
enum_decl|enum
name|OpenFlags
enum_decl|:
name|unsigned
enum_decl|;
block|}
block|}
comment|/// This class implements an extremely fast bulk output stream that can *only*
comment|/// output to a stream.  It does not support seeking, reopening, rewinding, line
comment|/// buffered disciplines etc. It is a simple buffer that outputs
comment|/// a chunk at a time.
name|class
name|raw_ostream
block|{
name|private
label|:
name|void
name|operator
init|=
operator|(
specifier|const
name|raw_ostream
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|raw_ostream
argument_list|(
specifier|const
name|raw_ostream
operator|&
argument_list|)
operator|=
name|delete
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
argument|bool unbuffered = false
argument_list|)
block|:
name|BufferMode
argument_list|(
argument|unbuffered ? Unbuffered : InternalBuffer
argument_list|)
block|{
comment|// Start out ready to flush.
name|OutBufStart
operator|=
name|OutBufEnd
operator|=
name|OutBufCur
operator|=
name|nullptr
expr_stmt|;
block|}
name|virtual
operator|~
name|raw_ostream
argument_list|()
expr_stmt|;
comment|/// tell - Return the current offset with the file.
name|uint64_t
name|tell
argument_list|()
specifier|const
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
comment|/// Set the stream to be buffered, with an automatically determined buffer
comment|/// size.
name|void
name|SetBuffered
parameter_list|()
function_decl|;
comment|/// Set the stream to be buffered, using the specified buffer size.
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
argument_list|()
specifier|const
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
name|nullptr
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
comment|/// Set the stream to be unbuffered. When unbuffered, the stream will flush
comment|/// after every write. This routine will also flush the buffer immediately
comment|/// when the stream is being set to unbuffered.
name|void
name|SetUnbuffered
parameter_list|()
block|{
name|flush
argument_list|()
expr_stmt|;
name|SetBufferAndMode
argument_list|(
name|nullptr
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
end_decl_stmt

begin_expr_stmt
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
name|StringRef
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
name|Size
operator|>
call|(
name|size_t
call|)
argument_list|(
name|OutBufEnd
operator|-
name|OutBufCur
argument_list|)
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
end_expr_stmt

begin_if
if|if
condition|(
name|Size
condition|)
block|{
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
name|OutBufCur
operator|+=
name|Size
expr_stmt|;
block|}
end_if

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
comment|// Inline fast path, particularly for constant strings where a sufficiently
comment|// smart compiler will simplify strlen.
return|return
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
return|return
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
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Str
operator|)
block|{
return|return
name|write
argument_list|(
name|Str
operator|.
name|data
argument_list|()
argument_list|,
name|Str
operator|.
name|size
argument_list|()
argument_list|)
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
return|return
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
return|return
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
comment|/// Output \p N in hexadecimal, without any prefix or padding.
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
comment|/// Output \p Str, turning '\\', '\t', '\n', '"', and anything that doesn't
end_comment

begin_comment
comment|/// satisfy std::isprint into an escape sequence.
end_comment

begin_function_decl
name|raw_ostream
modifier|&
name|write_escaped
parameter_list|(
name|StringRef
name|Str
parameter_list|,
name|bool
name|UseHexEscapes
init|=
name|false
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
comment|// Formatted output, see the leftJustify() function in Support/Format.h.
end_comment

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|FormattedString
operator|&
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Formatted output, see the formatHex() function in Support/Format.h.
end_comment

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|FormattedNumber
operator|&
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
comment|/// @param Color ANSI color to use, the special SAVEDCOLOR can be used to
end_comment

begin_comment
comment|/// change only the bold attribute, and keep colors untouched
end_comment

begin_comment
comment|/// @param Bold bold/brighter text, default false
end_comment

begin_comment
comment|/// @param BG if true change the background, default: change foreground
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
name|Color
parameter_list|,
name|bool
name|Bold
init|=
name|false
parameter_list|,
name|bool
name|BG
init|=
name|false
parameter_list|)
block|{
operator|(
name|void
operator|)
name|Color
expr_stmt|;
operator|(
name|void
operator|)
name|Bold
expr_stmt|;
operator|(
name|void
operator|)
name|BG
expr_stmt|;
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
comment|/// Reverses the foreground and background colors.
end_comment

begin_function
name|virtual
name|raw_ostream
modifier|&
name|reverseColor
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
comment|/// This function determines if this stream is displayed and supports colors.
end_comment

begin_expr_stmt
name|virtual
name|bool
name|has_colors
argument_list|()
specifier|const
block|{
return|return
name|is_displayed
argument_list|()
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
comment|/// The is the piece of the class that is implemented by subclasses.  This
end_comment

begin_comment
comment|/// writes the \p Size bytes starting at
end_comment

begin_comment
comment|/// \p Ptr to the underlying stream.
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
comment|/// \param Ptr The start of the data to be written. For buffered streams this
end_comment

begin_comment
comment|/// is guaranteed to be the start of the buffer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Size The number of bytes to be written.
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
comment|/// Return the current position within the stream, not counting the bytes
end_comment

begin_comment
comment|/// currently in the buffer.
end_comment

begin_expr_stmt
name|virtual
name|uint64_t
name|current_pos
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Use the provided buffer as the raw_ostream buffer. This is intended for
end_comment

begin_comment
comment|/// use only by subclasses which can arrange for the output to go directly
end_comment

begin_comment
comment|/// into the desired output buffer, instead of being copied on each flush.
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
comment|/// Return an efficient buffer size for the underlying output mechanism.
end_comment

begin_expr_stmt
name|virtual
name|size_t
name|preferred_buffer_size
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the beginning of the current stream buffer, or 0 if the stream is
end_comment

begin_comment
comment|/// unbuffered.
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
comment|/// Install the given buffer and mode.
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
comment|/// Flush the current buffer, which is known to be non-empty. This outputs the
end_comment

begin_comment
comment|/// currently buffered data and resets the buffer to empty.
end_comment

begin_function_decl
name|void
name|flush_nonempty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Copy data into the buffer. Size must not be greater than the number of
end_comment

begin_comment
comment|/// unused bytes in the buffer.
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
comment|/// An abstract base class for streams implementations that also support a
end_comment

begin_comment
comment|/// pwrite operation. This is useful for code that can mostly stream out data,
end_comment

begin_comment
comment|/// but needs to patch in a header that needs to know the output size.
end_comment

begin_decl_stmt
name|class
name|raw_pwrite_stream
range|:
name|public
name|raw_ostream
block|{
name|virtual
name|void
name|pwrite_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|,
argument|uint64_t Offset
argument_list|)
operator|=
literal|0
block|;
name|public
operator|:
name|explicit
name|raw_pwrite_stream
argument_list|(
argument|bool Unbuffered = false
argument_list|)
operator|:
name|raw_ostream
argument_list|(
argument|Unbuffered
argument_list|)
block|{}
name|void
name|pwrite
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|,
argument|uint64_t Offset
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDBEBUG
name|uint64_t
name|Pos
operator|=
name|tell
argument_list|()
block|;
comment|// /dev/null always reports a pos of 0, so we cannot perform this check
comment|// in that case.
if|if
condition|(
name|Pos
condition|)
name|assert
argument_list|(
name|Size
operator|+
name|Offset
operator|<=
name|Pos
operator|&&
literal|"We don't support extending the stream"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|pwrite_impl
argument_list|(
name|Ptr
argument_list|,
name|Size
argument_list|,
name|Offset
argument_list|)
block|;   }
end_decl_stmt

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
comment|/// A raw_ostream that writes to a file descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|raw_fd_ostream
range|:
name|public
name|raw_pwrite_stream
block|{
name|int
name|FD
block|;
name|bool
name|ShouldClose
block|;
comment|/// Error This flag is true if an error of any kind has been detected.
comment|///
name|bool
name|Error
block|;
name|uint64_t
name|pos
block|;
name|bool
name|SupportsSeeking
block|;
comment|/// See raw_ostream::write_impl.
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|;
name|void
name|pwrite_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|,
argument|uint64_t Offset
argument_list|)
name|override
block|;
comment|/// Return the current position within the stream, not counting the bytes
comment|/// currently in the buffer.
name|uint64_t
name|current_pos
argument_list|()
specifier|const
name|override
block|{
return|return
name|pos
return|;
block|}
comment|/// Determine an efficient buffer size.
name|size_t
name|preferred_buffer_size
argument_list|()
specifier|const
name|override
block|;
comment|/// Set the flag indicating that an output error has been encountered.
name|void
name|error_detected
argument_list|()
block|{
name|Error
operator|=
name|true
block|; }
name|public
operator|:
comment|/// Open the specified file for writing. If an error occurs, information
comment|/// about the error is put into EC, and the stream should be immediately
comment|/// destroyed;
comment|/// \p Flags allows optional flags to control how the file will be opened.
comment|///
comment|/// As a special case, if Filename is "-", then the stream will use
comment|/// STDOUT_FILENO instead of opening a file. Note that it will still consider
comment|/// itself to own the file descriptor. In particular, it will close the
comment|/// file descriptor when it is done (this is necessary to detect
comment|/// output errors).
name|raw_fd_ostream
argument_list|(
argument|StringRef Filename
argument_list|,
argument|std::error_code&EC
argument_list|,
argument|sys::fs::OpenFlags Flags
argument_list|)
block|;
comment|/// FD is the file descriptor that this writes to.  If ShouldClose is true,
comment|/// this closes the file when the stream is destroyed.
name|raw_fd_ostream
argument_list|(
argument|int fd
argument_list|,
argument|bool shouldClose
argument_list|,
argument|bool unbuffered=false
argument_list|)
block|;
operator|~
name|raw_fd_ostream
argument_list|()
name|override
block|;
comment|/// Manually flush the stream and close the file. Note that this does not call
comment|/// fsync.
name|void
name|close
argument_list|()
block|;
name|bool
name|supportsSeeking
argument_list|()
block|{
return|return
name|SupportsSeeking
return|;
block|}
comment|/// Flushes the stream and repositions the underlying file descriptor position
comment|/// to the offset specified from the beginning of the file.
name|uint64_t
name|seek
argument_list|(
argument|uint64_t off
argument_list|)
block|;
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
name|override
block|;
name|raw_ostream
operator|&
name|resetColor
argument_list|()
name|override
block|;
name|raw_ostream
operator|&
name|reverseColor
argument_list|()
name|override
block|;
name|bool
name|is_displayed
argument_list|()
specifier|const
name|override
block|;
name|bool
name|has_colors
argument_list|()
specifier|const
name|override
block|;
comment|/// Return the value of the flag in this raw_fd_ostream indicating whether an
comment|/// output error has been encountered.
comment|/// This doesn't implicitly flush any pending output.  Also, it doesn't
comment|/// guarantee to detect all errors unless the stream has been closed.
name|bool
name|has_error
argument_list|()
specifier|const
block|{
return|return
name|Error
return|;
block|}
comment|/// Set the flag read by has_error() to false. If the error flag is set at the
comment|/// time when this raw_ostream's destructor is called, report_fatal_error is
comment|/// called to report the error. Use clear_error() after handling the error to
comment|/// avoid this behavior.
comment|///
comment|///   "Errors should never pass silently.
comment|///    Unless explicitly silenced."
comment|///      - from The Zen of Python, by Tim Peters
comment|///
name|void
name|clear_error
argument_list|()
block|{
name|Error
operator|=
name|false
block|;   }
expr|}
block|;
comment|/// This returns a reference to a raw_ostream for standard output. Use it like:
comment|/// outs()<< "foo"<< "bar";
name|raw_ostream
operator|&
name|outs
argument_list|()
block|;
comment|/// This returns a reference to a raw_ostream for standard error. Use it like:
comment|/// errs()<< "foo"<< "bar";
name|raw_ostream
operator|&
name|errs
argument_list|()
block|;
comment|/// This returns a reference to a raw_ostream which simply discards output.
name|raw_ostream
operator|&
name|nulls
argument_list|()
block|;
comment|//===----------------------------------------------------------------------===//
comment|// Output Stream Adaptors
comment|//===----------------------------------------------------------------------===//
comment|/// A raw_ostream that writes to an std::string.  This is a simple adaptor
comment|/// class. This class does not encounter output errors.
name|class
name|raw_string_ostream
operator|:
name|public
name|raw_ostream
block|{
name|std
operator|::
name|string
operator|&
name|OS
block|;
comment|/// See raw_ostream::write_impl.
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|;
comment|/// Return the current position within the stream, not counting the bytes
comment|/// currently in the buffer.
name|uint64_t
name|current_pos
argument_list|()
specifier|const
name|override
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
name|override
block|;
comment|/// Flushes the stream contents to the target string and returns  the string's
comment|/// reference.
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
comment|/// A raw_ostream that writes to an SmallVector or SmallString.  This is a
comment|/// simple adaptor class. This class does not encounter output errors.
comment|/// raw_svector_ostream operates without a buffer, delegating all memory
comment|/// management to the SmallString. Thus the SmallString is always up-to-date,
comment|/// may be used directly and there is no need to call flush().
name|class
name|raw_svector_ostream
operator|:
name|public
name|raw_pwrite_stream
block|{
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|OS
block|;
comment|/// See raw_ostream::write_impl.
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|;
name|void
name|pwrite_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|,
argument|uint64_t Offset
argument_list|)
name|override
block|;
comment|/// Return the current position within the stream.
name|uint64_t
name|current_pos
argument_list|()
specifier|const
name|override
block|;
name|public
operator|:
comment|/// Construct a new raw_svector_ostream.
comment|///
comment|/// \param O The vector to write to; this should generally have at least 128
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
operator|:
name|OS
argument_list|(
argument|O
argument_list|)
block|{
name|SetUnbuffered
argument_list|()
block|;   }
operator|~
name|raw_svector_ostream
argument_list|()
name|override
block|{}
name|void
name|flush
argument_list|()
operator|=
name|delete
block|;
comment|/// Return a StringRef for the vector contents.
name|StringRef
name|str
argument_list|()
block|{
return|return
name|StringRef
argument_list|(
name|OS
operator|.
name|data
argument_list|()
argument_list|,
name|OS
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// A raw_ostream that discards all output.
name|class
name|raw_null_ostream
operator|:
name|public
name|raw_pwrite_stream
block|{
comment|/// See raw_ostream::write_impl.
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t size
argument_list|)
name|override
block|;
name|void
name|pwrite_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|,
argument|uint64_t Offset
argument_list|)
name|override
block|;
comment|/// Return the current position within the stream, not counting the bytes
comment|/// currently in the buffer.
name|uint64_t
name|current_pos
argument_list|()
specifier|const
name|override
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
name|override
block|; }
block|;
name|class
name|buffer_ostream
operator|:
name|public
name|raw_svector_ostream
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|SmallVector
operator|<
name|char
block|,
literal|0
operator|>
name|Buffer
block|;
name|public
operator|:
name|buffer_ostream
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|raw_svector_ostream
argument_list|(
name|Buffer
argument_list|)
block|,
name|OS
argument_list|(
argument|OS
argument_list|)
block|{}
operator|~
name|buffer_ostream
argument_list|()
name|override
block|{
name|OS
operator|<<
name|str
argument_list|()
block|; }
block|}
block|;  }
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_RAW_OSTREAM_H
end_comment

end_unit


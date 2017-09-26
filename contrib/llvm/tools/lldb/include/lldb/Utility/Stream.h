begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Stream.h ------------------------------------------------*- C++ -*-===//
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
name|liblldb_Stream_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Stream_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for ByteOrder::eByteOrderInvalid
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/FormatVariadic.h"
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t, uint64_t, uint8_t
end_comment

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_comment
comment|// for forward
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Stream Stream.h "lldb/Utility/Stream.h"
comment|/// @brief A stream class that can stream formatted output to a file.
comment|//----------------------------------------------------------------------
name|class
name|Stream
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// \a m_flags bit values.
comment|//------------------------------------------------------------------
enum|enum
block|{
name|eBinary
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
comment|///< Get and put data as binary instead of as the default
comment|/// string mode.
block|}
enum|;
comment|//------------------------------------------------------------------
comment|/// Construct with flags and address size and byte order.
comment|///
comment|/// Construct with dump flags \a flags and the default address
comment|/// size. \a flags can be any of the above enumeration logical OR'ed
comment|/// together.
comment|//------------------------------------------------------------------
name|Stream
argument_list|(
argument|uint32_t flags
argument_list|,
argument|uint32_t addr_size
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct a default Stream, not binary, host byte order and
comment|/// host addr size.
comment|///
comment|//------------------------------------------------------------------
name|Stream
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|Stream
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Subclasses must override these methods
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Flush the stream.
comment|///
comment|/// Subclasses should flush the stream to make any output appear
comment|/// if the stream has any buffering.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|Flush
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Output character bytes to the stream.
comment|///
comment|/// Appends \a src_len characters from the buffer \a src to the
comment|/// stream.
comment|///
comment|/// @param[in] src
comment|///     A buffer containing at least \a src_len bytes of data.
comment|///
comment|/// @param[in] src_len
comment|///     A number of bytes to append to the stream.
comment|///
comment|/// @return
comment|///     The number of bytes that were appended to the stream.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|Write
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|src_len
parameter_list|)
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|// Member functions
comment|//------------------------------------------------------------------
name|size_t
name|PutChar
parameter_list|(
name|char
name|ch
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the byte_order value.
comment|///
comment|/// Sets the byte order of the data to extract. Extracted values
comment|/// will be swapped if necessary when decoding.
comment|///
comment|/// @param[in] byte_order
comment|///     The byte order value to use when extracting data.
comment|///
comment|/// @return
comment|///     The old byte order value.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ByteOrder
name|SetByteOrder
argument_list|(
argument|lldb::ByteOrder byte_order
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Format a C string from a printf style format and variable
comment|/// arguments and encode and append the resulting C string as hex
comment|/// bytes.
comment|///
comment|/// @param[in] format
comment|///     A printf style format string.
comment|///
comment|/// @param[in] ...
comment|///     Any additional arguments needed for the printf format string.
comment|///
comment|/// @return
comment|///     The number of bytes that were appended to the stream.
comment|//------------------------------------------------------------------
name|size_t
name|PrintfAsRawHex8
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
decl_stmt|)
block|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Format a C string from a printf style format and variable
end_comment

begin_comment
comment|/// arguments and encode and append the resulting C string as hex
end_comment

begin_comment
comment|/// bytes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] format
end_comment

begin_comment
comment|///     A printf style format string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] ...
end_comment

begin_comment
comment|///     Any additional arguments needed for the printf format string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The number of bytes that were appended to the stream.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|size_t
name|PutHex8
parameter_list|(
name|uint8_t
name|uvalue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|PutNHex8
parameter_list|(
name|size_t
name|n
parameter_list|,
name|uint8_t
name|uvalue
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|size_t
name|PutHex16
argument_list|(
name|uint16_t
name|uvalue
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|PutHex32
argument_list|(
name|uint32_t
name|uvalue
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|PutHex64
argument_list|(
name|uint64_t
name|uvalue
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|PutMaxHex64
argument_list|(
name|uint64_t
name|uvalue
argument_list|,
name|size_t
name|byte_size
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|PutFloat
argument_list|(
name|float
name|f
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|PutDouble
argument_list|(
name|double
name|d
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|PutLongDouble
argument_list|(
name|long
name|double
name|ld
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|size_t
name|PutPointer
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Append \a src_len bytes from \a src to the stream as hex characters
end_comment

begin_comment
comment|// (two ascii characters per byte of input data)
end_comment

begin_decl_stmt
name|size_t
name|PutBytesAsRawHex8
argument_list|(
specifier|const
name|void
operator|*
name|src
argument_list|,
name|size_t
name|src_len
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|src_byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|dst_byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Append \a src_len bytes from \a s to the stream as binary data.
end_comment

begin_decl_stmt
name|size_t
name|PutRawBytes
argument_list|(
specifier|const
name|void
operator|*
name|s
argument_list|,
name|size_t
name|src_len
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|src_byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|dst_byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|size_t
name|PutCStringAsRawHex8
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a NULL terminated C string \a cstr to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] cstr
end_comment

begin_comment
comment|///     A NULL terminated C string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|cstr
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|llvm
operator|::
name|StringRef
name|str
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a pointer value \a p to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] p
end_comment

begin_comment
comment|///     A void pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|void
operator|*
name|p
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a character \a ch to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] ch
end_comment

begin_comment
comment|///     A printable character value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|char
name|ch
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a uint8_t \a uval to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] uval
end_comment

begin_comment
comment|///     A uint8_t value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|uint8_t
name|uval
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a uint16_t \a uval to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] uval
end_comment

begin_comment
comment|///     A uint16_t value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|uint16_t
name|uval
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a uint32_t \a uval to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] uval
end_comment

begin_comment
comment|///     A uint32_t value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|uint32_t
name|uval
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a uint64_t \a uval to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] uval
end_comment

begin_comment
comment|///     A uint64_t value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|uint64_t
name|uval
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a int8_t \a sval to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] sval
end_comment

begin_comment
comment|///     A int8_t value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|int8_t
name|sval
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a int16_t \a sval to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] sval
end_comment

begin_comment
comment|///     A int16_t value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|int16_t
name|sval
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a int32_t \a sval to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] sval
end_comment

begin_comment
comment|///     A int32_t value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|int32_t
name|sval
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a int64_t \a sval to the stream \a s.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] sval
end_comment

begin_comment
comment|///     A int64_t value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to this class so multiple things can be streamed
end_comment

begin_comment
comment|///     in one statement.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|int64_t
name|sval
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output an address value to this stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Put an address \a addr out to the stream with optional \a prefix
end_comment

begin_comment
comment|/// and \a suffix strings.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] addr
end_comment

begin_comment
comment|///     An address value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] addr_size
end_comment

begin_comment
comment|///     Size in bytes of the address, used for formatting.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] prefix
end_comment

begin_comment
comment|///     A prefix C string. If nullptr, no prefix will be output.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] suffix
end_comment

begin_comment
comment|///     A suffix C string. If nullptr, no suffix will be output.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|Address
parameter_list|(
name|uint64_t
name|addr
parameter_list|,
name|uint32_t
name|addr_size
parameter_list|,
specifier|const
name|char
modifier|*
name|prefix
init|=
name|nullptr
parameter_list|,
specifier|const
name|char
modifier|*
name|suffix
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output an address range to this stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Put an address range \a lo_addr - \a hi_addr out to the stream
end_comment

begin_comment
comment|/// with optional \a prefix and \a suffix strings.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] lo_addr
end_comment

begin_comment
comment|///     The start address of the address range.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] hi_addr
end_comment

begin_comment
comment|///     The end address of the address range.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] addr_size
end_comment

begin_comment
comment|///     Size in bytes of the address, used for formatting.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] prefix
end_comment

begin_comment
comment|///     A prefix C string. If nullptr, no prefix will be output.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] suffix
end_comment

begin_comment
comment|///     A suffix C string. If nullptr, no suffix will be output.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|AddressRange
parameter_list|(
name|uint64_t
name|lo_addr
parameter_list|,
name|uint64_t
name|hi_addr
parameter_list|,
name|uint32_t
name|addr_size
parameter_list|,
specifier|const
name|char
modifier|*
name|prefix
init|=
name|nullptr
parameter_list|,
specifier|const
name|char
modifier|*
name|suffix
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a C string to the stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Print a C string \a cstr to the stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] cstr
end_comment

begin_comment
comment|///     The string to be output to the stream.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|size_t
name|PutCString
argument_list|(
name|llvm
operator|::
name|StringRef
name|cstr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output and End of Line character to the stream.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|size_t
name|EOL
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Get the address size in bytes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The size of an address in bytes that is used when outputting
end_comment

begin_comment
comment|///     address and pointer values to the stream.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// The flags accessor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A reference to the Flags member variable.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|Flags
modifier|&
name|GetFlags
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// The flags const accessor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A const reference to the Flags member variable.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
specifier|const
name|Flags
operator|&
name|GetFlags
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|//// The byte order accessor.
end_comment

begin_comment
comment|////
end_comment

begin_comment
comment|//// @return
end_comment

begin_comment
comment|////     The byte order.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Get the current indentation level.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The current indentation level as an integer.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|int
name|GetIndentLevel
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Indent the current line in the stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indent the current line using the current indentation level and
end_comment

begin_comment
comment|/// print an optional string following the indentation spaces.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] s
end_comment

begin_comment
comment|///     A C string to print following the indentation. If nullptr, just
end_comment

begin_comment
comment|///     output the indentation characters.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|size_t
name|Indent
parameter_list|(
specifier|const
name|char
modifier|*
name|s
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|size_t
name|Indent
argument_list|(
name|llvm
operator|::
name|StringRef
name|s
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Decrement the current indentation level.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|IndentLess
parameter_list|(
name|int
name|amount
init|=
literal|2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Increment the current indentation level.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|IndentMore
parameter_list|(
name|int
name|amount
init|=
literal|2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output an offset value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Put an offset \a uval out to the stream using the printf format
end_comment

begin_comment
comment|/// in \a format.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] offset
end_comment

begin_comment
comment|///     The offset value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] format
end_comment

begin_comment
comment|///     The printf style format to use when outputting the offset.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|Offset
parameter_list|(
name|uint32_t
name|offset
parameter_list|,
specifier|const
name|char
modifier|*
name|format
init|=
literal|"0x%8.8x: "
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output printf formatted output to the stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Print some formatted output to the stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] format
end_comment

begin_comment
comment|///     A printf style format string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] ...
end_comment

begin_comment
comment|///     Variable arguments that are needed for the printf style
end_comment

begin_comment
comment|///     format string \a format.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|size_t
name|Printf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|size_t
name|PrintfVarArg
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
name|void
name|Format
argument_list|(
argument|const char *format
argument_list|,
argument|Args&&... args
argument_list|)
block|{
name|PutCString
argument_list|(
name|llvm
operator|::
name|formatv
argument_list|(
name|format
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|args
operator|)
operator|...
argument_list|)
operator|.
name|str
argument_list|()
argument_list|)
block|;   }
comment|//------------------------------------------------------------------
comment|/// Output a quoted C string value to the stream.
comment|///
comment|/// Print a double quoted NULL terminated C string to the stream
comment|/// using the printf format in \a format.
comment|///
comment|/// @param[in] cstr
comment|///     A NULL terminated C string value.
comment|///
comment|/// @param[in] format
comment|///     The optional C string format that can be overridden.
comment|//------------------------------------------------------------------
name|void
name|QuotedCString
argument_list|(
specifier|const
name|char
operator|*
name|cstr
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
literal|"\"%s\""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Set the address size in bytes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] addr_size
end_comment

begin_comment
comment|///     The new size in bytes of an address to use when outputting
end_comment

begin_comment
comment|///     address and pointer values.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|SetAddressByteSize
parameter_list|(
name|uint32_t
name|addr_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Set the current indentation level.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] level
end_comment

begin_comment
comment|///     The new indentation level.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|SetIndentLevel
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a SLEB128 number to the stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Put an SLEB128 \a uval out to the stream using the printf format
end_comment

begin_comment
comment|/// in \a format.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] uval
end_comment

begin_comment
comment|///     A uint64_t value that was extracted as a SLEB128 value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] format
end_comment

begin_comment
comment|///     The optional printf format that can be overridden.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|size_t
name|PutSLEB128
parameter_list|(
name|int64_t
name|uval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Output a ULEB128 number to the stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Put an ULEB128 \a uval out to the stream using the printf format
end_comment

begin_comment
comment|/// in \a format.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] uval
end_comment

begin_comment
comment|///     A uint64_t value that was extracted as a ULEB128 value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] format
end_comment

begin_comment
comment|///     The optional printf format that can be overridden.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|size_t
name|PutULEB128
parameter_list|(
name|uint64_t
name|uval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|UnitTest
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Member variables
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|Flags
name|m_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Dump flags.
end_comment

begin_decl_stmt
name|uint32_t
name|m_addr_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Size of an address in bytes.
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ByteOrder
name|m_byte_order
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< Byte order to use when encoding scalar types.
end_comment

begin_decl_stmt
name|int
name|m_indent_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Indention level.
end_comment

begin_function_decl
name|size_t
name|_PutHex8
parameter_list|(
name|uint8_t
name|uvalue
parameter_list|,
name|bool
name|add_prefix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Stream_h_
end_comment

end_unit


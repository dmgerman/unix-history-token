begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DumpDataExtractor.h -------------------------------------*- C++ -*-===//
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
name|LLDB_CORE_DUMPDATAEXTRACTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_CORE_DUMPDATAEXTRACTOR_H
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for Format
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
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
comment|// for uint32_t, uint64_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DataExtractor
decl_stmt|;
name|class
name|ExecutionContextScope
decl_stmt|;
name|class
name|Stream
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dumps \a item_count objects into the stream \a s.
comment|///
comment|/// Dumps \a item_count objects using \a item_format, each of which
comment|/// are \a item_byte_size bytes long starting at offset \a offset
comment|/// bytes into the contained data, into the stream \a s. \a
comment|/// num_per_line objects will be dumped on each line before a new
comment|/// line will be output. If \a base_addr is a valid address, then
comment|/// each new line of output will be preceded by the address value
comment|/// plus appropriate offset, and a colon and space. Bitfield values
comment|/// can be dumped by calling this function multiple times with the
comment|/// same start offset, format and size, yet differing \a
comment|/// item_bit_size and \a item_bit_offset values.
comment|///
comment|/// @param[in] s
comment|///     The stream to dump the output to. This value can not be nullptr.
comment|///
comment|/// @param[in] offset
comment|///     The offset into the data at which to start dumping.
comment|///
comment|/// @param[in] item_format
comment|///     The format to use when dumping each item.
comment|///
comment|/// @param[in] item_byte_size
comment|///     The byte size of each item.
comment|///
comment|/// @param[in] item_count
comment|///     The number of items to dump.
comment|///
comment|/// @param[in] num_per_line
comment|///     The number of items to display on each line.
comment|///
comment|/// @param[in] base_addr
comment|///     The base address that gets added to the offset displayed on
comment|///     each line if the value is valid. Is \a base_addr is
comment|///     LLDB_INVALID_ADDRESS then no address values will be prepended
comment|///     to any lines.
comment|///
comment|/// @param[in] item_bit_size
comment|///     If the value to display is a bitfield, this value should
comment|///     be the number of bits that the bitfield item has within the
comment|///     item's byte size value. This function will need to be called
comment|///     multiple times with identical \a offset and \a item_byte_size
comment|///     values in order to display multiple bitfield values that
comment|///     exist within the same integer value. If the items being
comment|///     displayed are not bitfields, this value should be zero.
comment|///
comment|/// @param[in] item_bit_offset
comment|///     If the value to display is a bitfield, this value should
comment|///     be the offset in bits, or shift right amount, that the
comment|///     bitfield item occupies within the item's byte size value.
comment|///     This function will need to be called multiple times with
comment|///     identical \a offset and \a item_byte_size values in order
comment|///     to display multiple bitfield values that exist within the
comment|///     same integer value. If the items being displayed are not
comment|///     bitfields, this value should be zero.
comment|///
comment|/// @return
comment|///     The offset at which dumping ended.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|offset_t
name|DumpDataExtractor
argument_list|(
argument|const DataExtractor&DE
argument_list|,
argument|Stream *s
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::Format item_format
argument_list|,
argument|size_t item_byte_size
argument_list|,
argument|size_t item_count
argument_list|,
argument|size_t num_per_line
argument_list|,
argument|uint64_t base_addr
argument_list|,
argument|uint32_t item_bit_size
argument_list|,
argument|uint32_t item_bit_offset
argument_list|,
argument|ExecutionContextScope *exe_scope = nullptr
argument_list|)
expr_stmt|;
name|void
name|DumpHexBytes
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|void
operator|*
name|src
argument_list|,
name|size_t
name|src_len
argument_list|,
name|uint32_t
name|bytes_per_line
argument_list|,
name|lldb
operator|::
name|addr_t
name|base_addr
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


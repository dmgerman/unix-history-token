begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LineEntry.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_LineEntry_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_LineEntry_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/FileSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class LineEntry LineEntry.h "lldb/Symbol/LineEntry.h"
comment|/// @brief A line table entry class.
comment|//----------------------------------------------------------------------
struct|struct
name|LineEntry
block|{
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initialize all member variables to invalid values.
comment|//------------------------------------------------------------------
name|LineEntry
argument_list|()
expr_stmt|;
name|LineEntry
argument_list|(
argument|const lldb::SectionSP&section_sp
argument_list|,
argument|lldb::addr_t section_offset
argument_list|,
argument|lldb::addr_t byte_size
argument_list|,
argument|const FileSpec&file
argument_list|,
argument|uint32_t _line
argument_list|,
argument|uint16_t _column
argument_list|,
argument|bool _is_start_of_statement
argument_list|,
argument|bool _is_start_of_basic_block
argument_list|,
argument|bool _is_prologue_end
argument_list|,
argument|bool _is_epilogue_begin
argument_list|,
argument|bool _is_terminal_entry
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Clears all member variables to invalid values.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the contents of this object to the
comment|/// supplied stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|///
comment|/// @param[in] comp_unit
comment|///     The compile unit object that contains the support file
comment|///     list so the line entry can dump the file name (since this
comment|///     object contains a file index into the support file list).
comment|///
comment|/// @param[in] show_file
comment|///     If \b true, display the filename with the line entry which
comment|///     requires that the compile unit object \a comp_unit be a
comment|///     valid pointer.
comment|///
comment|/// @param[in] style
comment|///     The display style for the section offset address.
comment|///
comment|/// @return
comment|///     Returns \b true if the address was able to be displayed
comment|///     using \a style. File and load addresses may be unresolved
comment|///     and it may not be possible to display a valid address value.
comment|///     Returns \b false if the address was not able to be properly
comment|///     dumped.
comment|///
comment|/// @see Address::DumpStyle
comment|//------------------------------------------------------------------
name|bool
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|Target
operator|*
name|target
argument_list|,
name|bool
name|show_file
argument_list|,
name|Address
operator|::
name|DumpStyle
name|style
argument_list|,
name|Address
operator|::
name|DumpStyle
name|fallback_style
argument_list|,
name|bool
name|show_range
argument_list|)
decl|const
decl_stmt|;
name|bool
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|,
name|CompileUnit
operator|*
name|cu
argument_list|,
name|Target
operator|*
name|target
argument_list|,
name|bool
name|show_address_only
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dumps information specific to a process that stops at this
comment|/// line entry to the supplied stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|///
comment|/// @param[in] comp_unit
comment|///     The compile unit object that contains the support file
comment|///     list so the line entry can dump the file name (since this
comment|///     object contains a file index into the support file list).
comment|///
comment|/// @return
comment|///     Returns \b true if the file and line were properly dumped,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|DumpStopContext
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|bool
name|show_fullpaths
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if a line entry object is valid.
comment|///
comment|/// @return
comment|///     Returns \b true if the line entry contains a valid section
comment|///     offset address, file index, and line number, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Compare two LineEntry objects.
comment|///
comment|/// @param[in] lhs
comment|///     The Left Hand Side const LineEntry object reference.
comment|///
comment|/// @param[in] rhs
comment|///     The Right Hand Side const LineEntry object reference.
comment|///
comment|/// @return
comment|///     @li -1 if lhs< rhs
comment|///     @li 0 if lhs == rhs
comment|///     @li 1 if lhs> rhs
comment|//------------------------------------------------------------------
specifier|static
name|int
name|Compare
parameter_list|(
specifier|const
name|LineEntry
modifier|&
name|lhs
parameter_list|,
specifier|const
name|LineEntry
modifier|&
name|rhs
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|AddressRange
name|range
decl_stmt|;
comment|///< The section offset address range for this line entry.
name|FileSpec
name|file
decl_stmt|;
name|uint32_t
name|line
decl_stmt|;
comment|///< The source line number, or zero if there is no line number information.
name|uint16_t
name|column
decl_stmt|;
comment|///< The column number of the source line, or zero if there is no column information.
name|uint16_t
name|is_start_of_statement
range|:
literal|1
decl_stmt|,
comment|///< Indicates this entry is the beginning of a statement.
name|is_start_of_basic_block
range|:
literal|1
decl_stmt|,
comment|///< Indicates this entry is the beginning of a basic block.
name|is_prologue_end
range|:
literal|1
decl_stmt|,
comment|///< Indicates this entry is one (of possibly many) where execution should be suspended for an entry breakpoint of a function.
name|is_epilogue_begin
range|:
literal|1
decl_stmt|,
comment|///< Indicates this entry is one (of possibly many) where execution should be suspended for an exit breakpoint of a function.
name|is_terminal_entry
range|:
literal|1
decl_stmt|;
comment|///< Indicates this entry is that of the first byte after the end of a sequence of target machine instructions.
block|}
struct|;
comment|//------------------------------------------------------------------
comment|/// Less than operator.
comment|///
comment|/// @param[in] lhs
comment|///     The Left Hand Side const LineEntry object reference.
comment|///
comment|/// @param[in] rhs
comment|///     The Right Hand Side const LineEntry object reference.
comment|///
comment|/// @return
comment|///     Returns \b true if lhs< rhs, false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LineEntry
operator|&
name|lhs
operator|,
specifier|const
name|LineEntry
operator|&
name|rhs
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_LineEntry_h_
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LineTable.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_LineTable_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_LineTable_h_
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/LineEntry.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ModuleChild.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Section.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RangeMap.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class LineSequence LineTable.h "lldb/Symbol/LineTable.h"
comment|/// @brief An abstract base class used during symbol table creation.
comment|//----------------------------------------------------------------------
name|class
name|LineSequence
block|{
name|public
label|:
name|LineSequence
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|LineSequence
argument_list|()
block|{}
name|virtual
name|void
name|Clear
argument_list|()
operator|=
literal|0
expr_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|LineSequence
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class LineTable LineTable.h "lldb/Symbol/LineTable.h"
comment|/// @brief A line table class.
comment|//----------------------------------------------------------------------
name|class
name|LineTable
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Construct with compile unit.
comment|///
comment|/// @param[in] comp_unit
comment|///     The compile unit to which this line table belongs.
comment|//------------------------------------------------------------------
name|LineTable
argument_list|(
name|CompileUnit
operator|*
name|comp_unit
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|LineTable
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Adds a new line entry to this line table.
comment|///
comment|/// All line entries are maintained in file address order.
comment|///
comment|/// @param[in] line_entry
comment|///     A const reference to a new line_entry to add to this line
comment|///     table.
comment|///
comment|/// @see Address::DumpStyle
comment|//------------------------------------------------------------------
comment|//  void
comment|//  AddLineEntry (const LineEntry& line_entry);
comment|// Called when you can't guarantee the addresses are in increasing order
name|void
name|InsertLineEntry
argument_list|(
name|lldb
operator|::
name|addr_t
name|file_addr
argument_list|,
name|uint32_t
name|line
argument_list|,
name|uint16_t
name|column
argument_list|,
name|uint16_t
name|file_idx
argument_list|,
name|bool
name|is_start_of_statement
argument_list|,
name|bool
name|is_start_of_basic_block
argument_list|,
name|bool
name|is_prologue_end
argument_list|,
name|bool
name|is_epilogue_begin
argument_list|,
name|bool
name|is_terminal_entry
argument_list|)
decl_stmt|;
comment|// Used to instantiate the LineSequence helper class
name|LineSequence
modifier|*
name|CreateLineSequenceContainer
parameter_list|()
function_decl|;
comment|// Append an entry to a caller-provided collection that will later be
comment|// inserted in this line table.
name|void
name|AppendLineEntryToSequence
argument_list|(
name|LineSequence
operator|*
name|sequence
argument_list|,
name|lldb
operator|::
name|addr_t
name|file_addr
argument_list|,
name|uint32_t
name|line
argument_list|,
name|uint16_t
name|column
argument_list|,
name|uint16_t
name|file_idx
argument_list|,
name|bool
name|is_start_of_statement
argument_list|,
name|bool
name|is_start_of_basic_block
argument_list|,
name|bool
name|is_prologue_end
argument_list|,
name|bool
name|is_epilogue_begin
argument_list|,
name|bool
name|is_terminal_entry
argument_list|)
decl_stmt|;
comment|// Insert a sequence of entries into this line table.
name|void
name|InsertSequence
parameter_list|(
name|LineSequence
modifier|*
name|sequence
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dump all line entries in this line table to the stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|///
comment|/// @param[in] style
comment|///     The display style for the address.
comment|///
comment|/// @see Address::DumpStyle
comment|//------------------------------------------------------------------
name|void
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
name|show_line_ranges
argument_list|)
decl_stmt|;
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|Target
operator|*
name|target
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a line entry that contains the section offset address \a
comment|/// so_addr.
comment|///
comment|/// @param[in] so_addr
comment|///     A section offset address object containing the address we
comment|///     are searching for.
comment|///
comment|/// @param[out] line_entry
comment|///     A copy of the line entry that was found if \b true is
comment|///     returned, otherwise \a entry is left unmodified.
comment|///
comment|/// @param[out] index_ptr
comment|///     A pointer to a 32 bit integer that will get the actual line
comment|///     entry index if it is not NULL.
comment|///
comment|/// @return
comment|///     Returns \b true if \a so_addr is contained in a line entry
comment|///     in this line table, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|FindLineEntryByAddress
parameter_list|(
specifier|const
name|Address
modifier|&
name|so_addr
parameter_list|,
name|LineEntry
modifier|&
name|line_entry
parameter_list|,
name|uint32_t
modifier|*
name|index_ptr
init|=
name|NULL
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find a line entry index that has a matching file index and
comment|/// source line number.
comment|///
comment|/// Finds the next line entry that has a matching \a file_idx and
comment|/// source line number \a line starting at the \a start_idx entries
comment|/// into the line entry collection.
comment|///
comment|/// @param[in] start_idx
comment|///     The number of entries to skip when starting the search.
comment|///
comment|/// @param[out] file_idx
comment|///     The file index to search for that should be found prior
comment|///     to calling this function using the following functions:
comment|///     CompileUnit::GetSupportFiles()
comment|///     FileSpecList::FindFileIndex (uint32_t, const FileSpec&) const
comment|///
comment|/// @param[in] line
comment|///     The source line to match.
comment|///
comment|/// @param[in] exact
comment|///     If true, match only if you find a line entry exactly matching \a line.
comment|///     If false, return the closest line entry greater than \a line.
comment|///
comment|/// @param[out] line_entry
comment|///     A reference to a line entry object that will get a copy of
comment|///     the line entry if \b true is returned, otherwise \a
comment|///     line_entry is left untouched.
comment|///
comment|/// @return
comment|///     Returns \b true if a matching line entry is found in this
comment|///     line table, \b false otherwise.
comment|///
comment|/// @see CompileUnit::GetSupportFiles()
comment|/// @see FileSpecList::FindFileIndex (uint32_t, const FileSpec&) const
comment|//------------------------------------------------------------------
name|uint32_t
name|FindLineEntryIndexByFileIndex
parameter_list|(
name|uint32_t
name|start_idx
parameter_list|,
name|uint32_t
name|file_idx
parameter_list|,
name|uint32_t
name|line
parameter_list|,
name|bool
name|exact
parameter_list|,
name|LineEntry
modifier|*
name|line_entry_ptr
parameter_list|)
function_decl|;
name|uint32_t
name|FindLineEntryIndexByFileIndex
argument_list|(
name|uint32_t
name|start_idx
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|&
name|file_indexes
argument_list|,
name|uint32_t
name|line
argument_list|,
name|bool
name|exact
argument_list|,
name|LineEntry
operator|*
name|line_entry_ptr
argument_list|)
decl_stmt|;
name|size_t
name|FineLineEntriesForFileIndex
parameter_list|(
name|uint32_t
name|file_idx
parameter_list|,
name|bool
name|append
parameter_list|,
name|SymbolContextList
modifier|&
name|sc_list
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the line entry from the line table at index \a idx.
comment|///
comment|/// @param[in] idx
comment|///     An index into the line table entry collection.
comment|///
comment|/// @return
comment|///     A valid line entry if \a idx is a valid index, or an invalid
comment|///     line entry if \a idx is not valid.
comment|///
comment|/// @see LineTable::GetSize()
comment|/// @see LineEntry::IsValid() const
comment|//------------------------------------------------------------------
name|bool
name|GetLineEntryAtIndex
parameter_list|(
name|uint32_t
name|idx
parameter_list|,
name|LineEntry
modifier|&
name|line_entry
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the size of the line table in number of line table entries.
comment|///
comment|/// @return
comment|///     The number of line table entries in this line table.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
typedef|typedef
name|lldb_private
operator|::
name|RangeArray
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|,
literal|32
operator|>
name|FileAddressRanges
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets all contiguous file address ranges for the entire line table.
comment|///
comment|/// @param[out] file_ranges
comment|///     A collection of file address ranges that will be filled in
comment|///     by this function.
comment|///
comment|/// @param[out] append
comment|///     If \b true, then append to \a file_ranges, otherwise clear
comment|///     \a file_ranges prior to adding any ranges.
comment|///
comment|/// @return
comment|///     The number of address ranges added to \a file_ranges
comment|//------------------------------------------------------------------
name|size_t
name|GetContiguousFileAddressRanges
parameter_list|(
name|FileAddressRanges
modifier|&
name|file_ranges
parameter_list|,
name|bool
name|append
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Given a file range link map, relink the current line table
comment|/// and return a fixed up line table.
comment|///
comment|/// @param[out] file_range_map
comment|///     A collection of file ranges that maps to new file ranges
comment|///     that will be used when linking the line table.
comment|///
comment|/// @return
comment|///     A new line table if at least one line table entry was able
comment|///     to be mapped.
comment|//------------------------------------------------------------------
typedef|typedef
name|RangeDataVector
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|FileRangeMap
expr_stmt|;
name|LineTable
modifier|*
name|LinkLineTable
parameter_list|(
specifier|const
name|FileRangeMap
modifier|&
name|file_range_map
parameter_list|)
function_decl|;
name|protected
label|:
struct|struct
name|Entry
block|{
name|Entry
argument_list|()
operator|:
name|file_addr
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|line
argument_list|(
literal|0
argument_list|)
operator|,
name|column
argument_list|(
literal|0
argument_list|)
operator|,
name|file_idx
argument_list|(
literal|0
argument_list|)
operator|,
name|is_start_of_statement
argument_list|(
name|false
argument_list|)
operator|,
name|is_start_of_basic_block
argument_list|(
name|false
argument_list|)
operator|,
name|is_prologue_end
argument_list|(
name|false
argument_list|)
operator|,
name|is_epilogue_begin
argument_list|(
name|false
argument_list|)
operator|,
name|is_terminal_entry
argument_list|(
argument|false
argument_list|)
block|{         }
name|Entry
argument_list|(
argument|lldb::addr_t _file_addr
argument_list|,
argument|uint32_t _line
argument_list|,
argument|uint16_t _column
argument_list|,
argument|uint16_t _file_idx
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
operator|:
name|file_addr
argument_list|(
name|_file_addr
argument_list|)
operator|,
name|line
argument_list|(
name|_line
argument_list|)
operator|,
name|column
argument_list|(
name|_column
argument_list|)
operator|,
name|file_idx
argument_list|(
name|_file_idx
argument_list|)
operator|,
name|is_start_of_statement
argument_list|(
name|_is_start_of_statement
argument_list|)
operator|,
name|is_start_of_basic_block
argument_list|(
name|_is_start_of_basic_block
argument_list|)
operator|,
name|is_prologue_end
argument_list|(
name|_is_prologue_end
argument_list|)
operator|,
name|is_epilogue_begin
argument_list|(
name|_is_epilogue_begin
argument_list|)
operator|,
name|is_terminal_entry
argument_list|(
argument|_is_terminal_entry
argument_list|)
block|{         }
name|int
name|bsearch_compare
argument_list|(
specifier|const
name|void
operator|*
name|key
argument_list|,
specifier|const
name|void
operator|*
name|arrmem
argument_list|)
expr_stmt|;
name|void
name|Clear
parameter_list|()
block|{
name|file_addr
operator|=
name|LLDB_INVALID_ADDRESS
expr_stmt|;
name|line
operator|=
literal|0
expr_stmt|;
name|column
operator|=
literal|0
expr_stmt|;
name|file_idx
operator|=
literal|0
expr_stmt|;
name|is_start_of_statement
operator|=
name|false
expr_stmt|;
name|is_start_of_basic_block
operator|=
name|false
expr_stmt|;
name|is_prologue_end
operator|=
name|false
expr_stmt|;
name|is_epilogue_begin
operator|=
name|false
expr_stmt|;
name|is_terminal_entry
operator|=
name|false
expr_stmt|;
block|}
specifier|static
name|int
name|Compare
parameter_list|(
specifier|const
name|Entry
modifier|&
name|lhs
parameter_list|,
specifier|const
name|Entry
modifier|&
name|rhs
parameter_list|)
block|{
comment|// Compare the sections before calling
define|#
directive|define
name|SCALAR_COMPARE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|if (a< b) return -1; if (a> b) return +1
name|SCALAR_COMPARE
argument_list|(
name|lhs
operator|.
name|file_addr
argument_list|,
name|rhs
operator|.
name|file_addr
argument_list|)
expr_stmt|;
name|SCALAR_COMPARE
argument_list|(
name|lhs
operator|.
name|line
argument_list|,
name|rhs
operator|.
name|line
argument_list|)
expr_stmt|;
name|SCALAR_COMPARE
argument_list|(
name|lhs
operator|.
name|column
argument_list|,
name|rhs
operator|.
name|column
argument_list|)
expr_stmt|;
name|SCALAR_COMPARE
argument_list|(
name|lhs
operator|.
name|is_start_of_statement
argument_list|,
name|rhs
operator|.
name|is_start_of_statement
argument_list|)
expr_stmt|;
name|SCALAR_COMPARE
argument_list|(
name|lhs
operator|.
name|is_start_of_basic_block
argument_list|,
name|rhs
operator|.
name|is_start_of_basic_block
argument_list|)
expr_stmt|;
comment|// rhs and lhs reversed on purpose below.
name|SCALAR_COMPARE
argument_list|(
name|rhs
operator|.
name|is_prologue_end
argument_list|,
name|lhs
operator|.
name|is_prologue_end
argument_list|)
expr_stmt|;
name|SCALAR_COMPARE
argument_list|(
name|lhs
operator|.
name|is_epilogue_begin
argument_list|,
name|rhs
operator|.
name|is_epilogue_begin
argument_list|)
expr_stmt|;
comment|// rhs and lhs reversed on purpose below.
name|SCALAR_COMPARE
argument_list|(
name|rhs
operator|.
name|is_terminal_entry
argument_list|,
name|lhs
operator|.
name|is_terminal_entry
argument_list|)
expr_stmt|;
name|SCALAR_COMPARE
argument_list|(
name|lhs
operator|.
name|file_idx
argument_list|,
name|rhs
operator|.
name|file_idx
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|SCALAR_COMPARE
return|return
literal|0
return|;
block|}
name|class
name|LessThanBinaryPredicate
block|{
name|public
label|:
name|LessThanBinaryPredicate
argument_list|(
name|LineTable
operator|*
name|line_table
argument_list|)
expr_stmt|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|LineTable
operator|::
name|Entry
operator|&
operator|,
specifier|const
name|LineTable
operator|::
name|Entry
operator|&
operator|)
specifier|const
expr_stmt|;
name|protected
label|:
name|LineTable
modifier|*
name|m_line_table
decl_stmt|;
block|}
empty_stmt|;
specifier|static
name|bool
name|EntryAddressLessThan
parameter_list|(
specifier|const
name|Entry
modifier|&
name|lhs
parameter_list|,
specifier|const
name|Entry
modifier|&
name|rhs
parameter_list|)
block|{
return|return
name|lhs
operator|.
name|file_addr
operator|<
name|rhs
operator|.
name|file_addr
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|file_addr
expr_stmt|;
comment|///< The file address for this line entry
name|uint32_t
name|line
decl_stmt|;
comment|///< The source line number, or zero if there is no line number information.
name|uint16_t
name|column
decl_stmt|;
comment|///< The column number of the source line, or zero if there is no column information.
name|uint16_t
name|file_idx
range|:
literal|11
decl_stmt|,
comment|///< The file index into CompileUnit's file table, or zero if there is no file information.
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
struct|struct
name|EntrySearchInfo
block|{
name|LineTable
modifier|*
name|line_table
decl_stmt|;
name|lldb_private
operator|::
name|Section
operator|*
name|a_section
expr_stmt|;
name|Entry
modifier|*
name|a_entry
decl_stmt|;
block|}
struct|;
comment|//------------------------------------------------------------------
comment|// Types
comment|//------------------------------------------------------------------
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|Section
operator|*
operator|>
name|section_collection
expr_stmt|;
comment|///< The collection type for the sections.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|entry_collection
expr_stmt|;
comment|///< The collection type for the line entries.
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|CompileUnit
modifier|*
name|m_comp_unit
decl_stmt|;
comment|///< The compile unit that this line table belongs to.
name|entry_collection
name|m_entries
decl_stmt|;
comment|///< The collection of line entries in this line table.
comment|//------------------------------------------------------------------
comment|// Helper class
comment|//------------------------------------------------------------------
name|class
name|LineSequenceImpl
range|:
name|public
name|LineSequence
block|{
name|public
operator|:
name|LineSequenceImpl
argument_list|()
operator|:
name|LineSequence
argument_list|()
block|{}
name|virtual
operator|~
name|LineSequenceImpl
argument_list|()
block|{}
name|virtual
name|void
name|Clear
argument_list|()
block|;
name|entry_collection
name|m_entries
block|;
comment|///< The collection of line entries in this sequence.
block|}
decl_stmt|;
name|bool
name|ConvertEntryAtIndexToLineEntry
parameter_list|(
name|uint32_t
name|idx
parameter_list|,
name|LineEntry
modifier|&
name|line_entry
parameter_list|)
function_decl|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|LineTable
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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
comment|// liblldb_LineTable_h_
end_comment

end_unit


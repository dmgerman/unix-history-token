begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDebugLine.h ----------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFDebugLine_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFDebugLine_h_
end_define

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

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
file|"DWARFDataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"DWARFDefines.h"
end_include

begin_decl_stmt
name|class
name|SymbolFileDWARF
decl_stmt|;
end_decl_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// DWARFDebugLine
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|DWARFDebugLine
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// FileNameEntry
comment|//------------------------------------------------------------------
struct|struct
name|FileNameEntry
block|{
name|FileNameEntry
argument_list|()
operator|:
name|name
argument_list|(
name|nullptr
argument_list|)
operator|,
name|dir_idx
argument_list|(
literal|0
argument_list|)
operator|,
name|mod_time
argument_list|(
literal|0
argument_list|)
operator|,
name|length
argument_list|(
literal|0
argument_list|)
block|{}
specifier|const
name|char
operator|*
name|name
expr_stmt|;
name|dw_sleb128_t
name|dir_idx
decl_stmt|;
name|dw_sleb128_t
name|mod_time
decl_stmt|;
name|dw_sleb128_t
name|length
decl_stmt|;
block|}
struct|;
comment|//------------------------------------------------------------------
comment|// Prologue
comment|//------------------------------------------------------------------
struct|struct
name|Prologue
block|{
name|Prologue
argument_list|()
operator|:
name|total_length
argument_list|(
literal|0
argument_list|)
operator|,
name|version
argument_list|(
literal|0
argument_list|)
operator|,
name|prologue_length
argument_list|(
literal|0
argument_list|)
operator|,
name|min_inst_length
argument_list|(
literal|0
argument_list|)
operator|,
name|default_is_stmt
argument_list|(
literal|0
argument_list|)
operator|,
name|line_base
argument_list|(
literal|0
argument_list|)
operator|,
name|line_range
argument_list|(
literal|0
argument_list|)
operator|,
name|opcode_base
argument_list|(
literal|0
argument_list|)
operator|,
name|standard_opcode_lengths
argument_list|()
operator|,
name|include_directories
argument_list|()
operator|,
name|file_names
argument_list|()
block|{}
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|Prologue
operator|>
name|shared_ptr
expr_stmt|;
name|uint32_t
name|total_length
decl_stmt|;
comment|// The size in bytes of the statement information for
comment|// this compilation unit (not including the
comment|// total_length field itself).
name|uint16_t
name|version
decl_stmt|;
comment|// Version identifier for the statement information format.
name|uint32_t
name|prologue_length
decl_stmt|;
comment|// The number of bytes following the
comment|// prologue_length field to the beginning of the
comment|// first byte of the statement program itself.
name|uint8_t
name|min_inst_length
decl_stmt|;
comment|// The size in bytes of the smallest target machine
comment|// instruction. Statement program opcodes that
comment|// alter the address register first multiply their
comment|// operands by this value.
name|uint8_t
name|maximum_operations_per_instruction
decl_stmt|;
comment|// New in DWARF4. The maximum
comment|// number of individual
comment|// operations that may be
comment|// encoded in an instruction.
name|uint8_t
name|default_is_stmt
decl_stmt|;
comment|// The initial value of theis_stmtregister.
name|int8_t
name|line_base
decl_stmt|;
comment|// This parameter affects the meaning of the special
comment|// opcodes. See below.
name|uint8_t
name|line_range
decl_stmt|;
comment|// This parameter affects the meaning of the special
comment|// opcodes. See below.
name|uint8_t
name|opcode_base
decl_stmt|;
comment|// The number assigned to the first special opcode.
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|standard_opcode_lengths
expr_stmt|;
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
name|include_directories
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|FileNameEntry
operator|>
name|file_names
expr_stmt|;
name|int32_t
name|MaxLineIncrementForSpecialOpcode
argument_list|()
specifier|const
block|{
return|return
name|line_base
operator|+
operator|(
name|int8_t
operator|)
name|line_range
operator|-
literal|1
return|;
block|}
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
comment|//      void Append(BinaryStreamBuf& buff) const;
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|)
decl_stmt|;
name|void
name|Clear
parameter_list|()
block|{
name|total_length
operator|=
name|version
operator|=
name|prologue_length
operator|=
name|min_inst_length
operator|=
name|line_base
operator|=
name|line_range
operator|=
name|opcode_base
operator|=
literal|0
expr_stmt|;
name|line_base
operator|=
literal|0
expr_stmt|;
name|standard_opcode_lengths
operator|.
name|clear
argument_list|()
expr_stmt|;
name|include_directories
operator|.
name|clear
argument_list|()
expr_stmt|;
name|file_names
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|bool
name|GetFile
argument_list|(
name|uint32_t
name|file_idx
argument_list|,
specifier|const
name|char
operator|*
name|comp_dir
argument_list|,
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
comment|// Standard .debug_line state machine structure
struct|struct
name|Row
block|{
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Row
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|Row
argument_list|(
argument|bool default_is_stmt = false
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|Row
argument_list|()
block|{}
name|void
name|PostAppend
argument_list|()
expr_stmt|;
name|void
name|Reset
parameter_list|(
name|bool
name|default_is_stmt
parameter_list|)
function_decl|;
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|void
name|Insert
argument_list|(
name|Row
operator|::
name|collection
operator|&
name|state_coll
argument_list|,
specifier|const
name|Row
operator|&
name|state
argument_list|)
decl_stmt|;
specifier|static
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|,
specifier|const
name|Row
operator|::
name|collection
operator|&
name|state_coll
argument_list|)
decl_stmt|;
name|dw_addr_t
name|address
decl_stmt|;
comment|// The program-counter value corresponding to a machine
comment|// instruction generated by the compiler.
name|uint32_t
name|line
decl_stmt|;
comment|// An unsigned integer indicating a source line number. Lines
comment|// are numbered beginning at 1. The compiler may emit the
comment|// value 0 in cases where an instruction cannot be attributed
comment|// to any source line.
name|uint16_t
name|column
decl_stmt|;
comment|// An unsigned integer indicating a column number within a
comment|// source line. Columns are numbered beginning at 1. The
comment|// value 0 is reserved to indicate that a statement begins
comment|// at the 'left edge' of the line.
name|uint16_t
name|file
decl_stmt|;
comment|// An unsigned integer indicating the identity of the source
comment|// file corresponding to a machine instruction.
name|uint8_t
name|is_stmt
range|:
literal|1
decl_stmt|,
comment|// A boolean indicating that the current instruction is
comment|// the beginning of a statement.
name|basic_block
range|:
literal|1
decl_stmt|,
comment|// A boolean indicating that the current instruction is
comment|// the beginning of a basic block.
name|end_sequence
range|:
literal|1
decl_stmt|,
comment|// A boolean indicating that the current address is
comment|// that of the first byte after the end of a sequence
comment|// of target machine instructions.
name|prologue_end
range|:
literal|1
decl_stmt|,
comment|// A boolean indicating that the current address is
comment|// one (of possibly many) where execution should be
comment|// suspended for an entry breakpoint of a function.
name|epilogue_begin
range|:
literal|1
decl_stmt|;
comment|// A boolean indicating that the current address is
comment|// one (of possibly many) where execution should be
comment|// suspended for an exit breakpoint of a function.
name|uint32_t
name|isa
decl_stmt|;
comment|// An unsigned integer whose value encodes the applicable
comment|// instruction set architecture for the current instruction.
block|}
struct|;
comment|//------------------------------------------------------------------
comment|// LineTable
comment|//------------------------------------------------------------------
struct|struct
name|LineTable
block|{
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|LineTable
operator|>
name|shared_ptr
expr_stmt|;
name|LineTable
argument_list|()
operator|:
name|prologue
argument_list|()
operator|,
name|rows
argument_list|()
block|{}
name|void
name|AppendRow
argument_list|(
specifier|const
name|DWARFDebugLine
operator|::
name|Row
operator|&
name|state
argument_list|)
expr_stmt|;
name|void
name|Clear
parameter_list|()
block|{
name|prologue
operator|.
name|reset
argument_list|()
expr_stmt|;
name|rows
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|uint32_t
name|LookupAddress
argument_list|(
name|dw_addr_t
name|address
argument_list|,
name|dw_addr_t
name|cu_high_pc
argument_list|)
decl|const
decl_stmt|;
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|)
decl|const
decl_stmt|;
name|Prologue
operator|::
name|shared_ptr
name|prologue
expr_stmt|;
name|Row
operator|::
name|collection
name|rows
expr_stmt|;
block|}
struct|;
comment|//------------------------------------------------------------------
comment|// State
comment|//------------------------------------------------------------------
name|struct
name|State
range|:
name|public
name|Row
block|{
typedef|typedef
name|void
function_decl|(
modifier|*
name|Callback
function_decl|)
parameter_list|(
name|dw_offset_t
name|offset
parameter_list|,
specifier|const
name|State
modifier|&
name|state
parameter_list|,
name|void
modifier|*
name|userData
parameter_list|)
function_decl|;
comment|// Special row codes used when calling the callback
block|enum
block|{
name|StartParsingLineTable
operator|=
literal|0
block|,
name|DoneParsingLineTable
operator|=
operator|-
literal|1
block|}
decl_stmt|;
name|State
argument_list|(
argument|Prologue::shared_ptr&prologue_sp
argument_list|,
argument|lldb_private::Log *log
argument_list|,
argument|Callback callback
argument_list|,
argument|void *userData
argument_list|)
empty_stmt|;
name|void
name|AppendRowToMatrix
parameter_list|(
name|dw_offset_t
name|offset
parameter_list|)
function_decl|;
name|void
name|Finalize
parameter_list|(
name|dw_offset_t
name|offset
parameter_list|)
function_decl|;
name|void
name|Reset
parameter_list|()
function_decl|;
name|Prologue
operator|::
name|shared_ptr
name|prologue
expr_stmt|;
name|lldb_private
operator|::
name|Log
operator|*
name|log
expr_stmt|;
name|Callback
name|callback
decl_stmt|;
comment|// Callback function that gets called each time an entry
comment|// is to be added to the matrix
name|void
modifier|*
name|callbackUserData
decl_stmt|;
name|int
name|row
decl_stmt|;
comment|// The row number that starts at zero for the prologue, and
comment|// increases for each row added to the matrix
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|State
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
name|bool
name|DumpOpcodes
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|,
name|SymbolFileDWARF
operator|*
name|dwarf2Data
argument_list|,
name|dw_offset_t
name|line_offset
operator|=
name|DW_INVALID_OFFSET
argument_list|,
name|uint32_t
name|dump_flags
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If line_offset is invalid, dump everything
end_comment

begin_decl_stmt
specifier|static
name|bool
name|DumpLineTableRows
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|,
name|SymbolFileDWARF
operator|*
name|dwarf2Data
argument_list|,
name|dw_offset_t
name|line_offset
operator|=
name|DW_INVALID_OFFSET
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If line_offset is invalid, dump everything
end_comment

begin_decl_stmt
specifier|static
name|bool
name|ParseSupportFiles
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_line_data
argument_list|,
specifier|const
name|char
operator|*
name|cu_comp_dir
argument_list|,
name|dw_offset_t
name|stmt_list
argument_list|,
name|lldb_private
operator|::
name|FileSpecList
operator|&
name|support_files
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|ParsePrologue
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_line_data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|Prologue
operator|*
name|prologue
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|ParseStatementTable
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_line_data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|State
operator|::
name|Callback
name|callback
argument_list|,
name|void
operator|*
name|userData
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dw_offset_t
name|DumpStatementTable
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_line_data
argument_list|,
specifier|const
name|dw_offset_t
name|line_offset
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dw_offset_t
name|DumpStatementOpcodes
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_line_data
argument_list|,
specifier|const
name|dw_offset_t
name|line_offset
argument_list|,
name|uint32_t
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|ParseStatementTable
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_line_data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|LineTable
operator|*
name|line_table
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|Parse
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_line_data
argument_list|,
name|DWARFDebugLine
operator|::
name|State
operator|::
name|Callback
name|callback
argument_list|,
name|void
operator|*
name|userData
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//  static void AppendLineTableData(const DWARFDebugLine::Prologue* prologue,
end_comment

begin_comment
comment|//  const DWARFDebugLine::Row::collection& state_coll, const uint32_t
end_comment

begin_comment
comment|//  addr_size, BinaryStreamBuf&debug_line_data);
end_comment

begin_expr_stmt
name|DWARFDebugLine
argument_list|()
operator|:
name|m_lineTableMap
argument_list|()
block|{}
name|void
name|Parse
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_line_data
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|ParseIfNeeded
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_line_data
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|LineTable
operator|::
name|shared_ptr
name|GetLineTable
argument_list|(
argument|const dw_offset_t offset
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|dw_offset_t
operator|,
name|LineTable
operator|::
name|shared_ptr
operator|>
name|LineTableMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|LineTableMap
operator|::
name|iterator
name|LineTableIter
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|LineTableMap
operator|::
name|const_iterator
name|LineTableConstIter
expr_stmt|;
end_typedef

begin_decl_stmt
name|LineTableMap
name|m_lineTableMap
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DWARFDebugLine_h_
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFDebugLine.h -----------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFDEBUGLINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFDEBUGLINE_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DIContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFRelocMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DWARFDebugLine
block|{
name|public
label|:
name|DWARFDebugLine
argument_list|(
specifier|const
name|RelocAddrMap
operator|*
name|LineInfoRelocMap
argument_list|)
operator|:
name|RelocMap
argument_list|(
argument|LineInfoRelocMap
argument_list|)
block|{}
expr|struct
name|FileNameEntry
block|{
name|FileNameEntry
argument_list|()
operator|=
expr|default
block|;
name|StringRef
name|Name
operator|=
name|StringRef
argument_list|()
block|;
name|uint64_t
name|DirIdx
operator|=
literal|0
block|;
name|uint64_t
name|ModTime
operator|=
literal|0
block|;
name|uint64_t
name|Length
operator|=
literal|0
block|;   }
expr_stmt|;
struct|struct
name|Prologue
block|{
name|Prologue
argument_list|()
expr_stmt|;
comment|/// The size in bytes of the statement information for this compilation unit
comment|/// (not including the total_length field itself).
name|uint64_t
name|TotalLength
decl_stmt|;
comment|/// Version identifier for the statement information format.
name|uint16_t
name|Version
decl_stmt|;
comment|/// In v5, size in bytes of an address (or segment offset).
name|uint8_t
name|AddressSize
decl_stmt|;
comment|/// In v5, size in bytes of a segment selector.
name|uint8_t
name|SegSelectorSize
decl_stmt|;
comment|/// The number of bytes following the prologue_length field to the beginning
comment|/// of the first byte of the statement program itself.
name|uint64_t
name|PrologueLength
decl_stmt|;
comment|/// The size in bytes of the smallest target machine instruction. Statement
comment|/// program opcodes that alter the address register first multiply their
comment|/// operands by this value.
name|uint8_t
name|MinInstLength
decl_stmt|;
comment|/// The maximum number of individual operations that may be encoded in an
comment|/// instruction.
name|uint8_t
name|MaxOpsPerInst
decl_stmt|;
comment|/// The initial value of theis_stmtregister.
name|uint8_t
name|DefaultIsStmt
decl_stmt|;
comment|/// This parameter affects the meaning of the special opcodes. See below.
name|int8_t
name|LineBase
decl_stmt|;
comment|/// This parameter affects the meaning of the special opcodes. See below.
name|uint8_t
name|LineRange
decl_stmt|;
comment|/// The number assigned to the first special opcode.
name|uint8_t
name|OpcodeBase
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|StandardOpcodeLengths
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|IncludeDirectories
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|FileNameEntry
operator|>
name|FileNames
expr_stmt|;
name|bool
name|IsDWARF64
decl_stmt|;
name|uint32_t
name|sizeofTotalLength
argument_list|()
specifier|const
block|{
return|return
name|IsDWARF64
operator|?
literal|12
operator|:
literal|4
return|;
block|}
name|uint32_t
name|sizeofPrologueLength
argument_list|()
specifier|const
block|{
return|return
name|IsDWARF64
operator|?
literal|8
operator|:
literal|4
return|;
block|}
comment|/// Length of the prologue in bytes.
name|uint32_t
name|getLength
argument_list|()
specifier|const
block|{
return|return
name|PrologueLength
operator|+
name|sizeofTotalLength
argument_list|()
operator|+
sizeof|sizeof
argument_list|(
name|Version
argument_list|)
operator|+
name|sizeofPrologueLength
argument_list|()
return|;
block|}
comment|/// Length of the line table data in bytes (not including the prologue).
name|uint32_t
name|getStatementTableLength
argument_list|()
specifier|const
block|{
return|return
name|TotalLength
operator|+
name|sizeofTotalLength
argument_list|()
operator|-
name|getLength
argument_list|()
return|;
block|}
name|int32_t
name|getMaxLineIncrementForSpecialOpcode
argument_list|()
specifier|const
block|{
return|return
name|LineBase
operator|+
operator|(
name|int8_t
operator|)
name|LineRange
operator|-
literal|1
return|;
block|}
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|bool
name|parse
parameter_list|(
name|DataExtractor
name|DebugLineData
parameter_list|,
name|uint32_t
modifier|*
name|OffsetPtr
parameter_list|)
function_decl|;
block|}
struct|;
comment|/// Standard .debug_line state machine structure.
struct|struct
name|Row
block|{
name|explicit
name|Row
parameter_list|(
name|bool
name|DefaultIsStmt
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Called after a row is appended to the matrix.
name|void
name|postAppend
parameter_list|()
function_decl|;
name|void
name|reset
parameter_list|(
name|bool
name|DefaultIsStmt
parameter_list|)
function_decl|;
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|void
name|dumpTableHeader
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
specifier|static
name|bool
name|orderByAddress
parameter_list|(
specifier|const
name|Row
modifier|&
name|LHS
parameter_list|,
specifier|const
name|Row
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|Address
operator|<
name|RHS
operator|.
name|Address
return|;
block|}
comment|/// The program-counter value corresponding to a machine instruction
comment|/// generated by the compiler.
name|uint64_t
name|Address
decl_stmt|;
comment|/// An unsigned integer indicating a source line number. Lines are numbered
comment|/// beginning at 1. The compiler may emit the value 0 in cases where an
comment|/// instruction cannot be attributed to any source line.
name|uint32_t
name|Line
decl_stmt|;
comment|/// An unsigned integer indicating a column number within a source line.
comment|/// Columns are numbered beginning at 1. The value 0 is reserved to indicate
comment|/// that a statement begins at the 'left edge' of the line.
name|uint16_t
name|Column
decl_stmt|;
comment|/// An unsigned integer indicating the identity of the source file
comment|/// corresponding to a machine instruction.
name|uint16_t
name|File
decl_stmt|;
comment|/// An unsigned integer representing the DWARF path discriminator value
comment|/// for this location.
name|uint32_t
name|Discriminator
decl_stmt|;
comment|/// An unsigned integer whose value encodes the applicable instruction set
comment|/// architecture for the current instruction.
name|uint8_t
name|Isa
decl_stmt|;
comment|/// A boolean indicating that the current instruction is the beginning of a
comment|/// statement.
name|uint8_t
name|IsStmt
range|:
literal|1
decl_stmt|,
comment|/// A boolean indicating that the current instruction is the
comment|/// beginning of a basic block.
name|BasicBlock
range|:
literal|1
decl_stmt|,
comment|/// A boolean indicating that the current address is that of the
comment|/// first byte after the end of a sequence of target machine
comment|/// instructions.
name|EndSequence
range|:
literal|1
decl_stmt|,
comment|/// A boolean indicating that the current address is one (of possibly
comment|/// many) where execution should be suspended for an entry breakpoint
comment|/// of a function.
name|PrologueEnd
range|:
literal|1
decl_stmt|,
comment|/// A boolean indicating that the current address is one (of possibly
comment|/// many) where execution should be suspended for an exit breakpoint
comment|/// of a function.
name|EpilogueBegin
range|:
literal|1
decl_stmt|;
block|}
struct|;
comment|/// Represents a series of contiguous machine instructions. Line table for
comment|/// each compilation unit may consist of multiple sequences, which are not
comment|/// guaranteed to be in the order of ascending instruction address.
struct|struct
name|Sequence
block|{
name|Sequence
argument_list|()
expr_stmt|;
comment|/// Sequence describes instructions at address range [LowPC, HighPC)
comment|/// and is described by line table rows [FirstRowIndex, LastRowIndex).
name|uint64_t
name|LowPC
decl_stmt|;
name|uint64_t
name|HighPC
decl_stmt|;
name|unsigned
name|FirstRowIndex
decl_stmt|;
name|unsigned
name|LastRowIndex
decl_stmt|;
name|bool
name|Empty
decl_stmt|;
name|void
name|reset
parameter_list|()
function_decl|;
specifier|static
name|bool
name|orderByLowPC
parameter_list|(
specifier|const
name|Sequence
modifier|&
name|LHS
parameter_list|,
specifier|const
name|Sequence
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|LowPC
operator|<
name|RHS
operator|.
name|LowPC
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Empty
operator|&&
operator|(
name|LowPC
operator|<
name|HighPC
operator|)
operator|&&
operator|(
name|FirstRowIndex
operator|<
name|LastRowIndex
operator|)
return|;
block|}
name|bool
name|containsPC
argument_list|(
name|uint64_t
name|PC
argument_list|)
decl|const
block|{
return|return
operator|(
name|LowPC
operator|<=
name|PC
operator|&&
name|PC
operator|<
name|HighPC
operator|)
return|;
block|}
block|}
struct|;
struct|struct
name|LineTable
block|{
name|LineTable
argument_list|()
expr_stmt|;
comment|/// Represents an invalid row
specifier|const
name|uint32_t
name|UnknownRowIndex
init|=
name|UINT32_MAX
decl_stmt|;
name|void
name|appendRow
argument_list|(
specifier|const
name|DWARFDebugLine
operator|::
name|Row
operator|&
name|R
argument_list|)
block|{
name|Rows
operator|.
name|push_back
argument_list|(
name|R
argument_list|)
expr_stmt|;
block|}
name|void
name|appendSequence
argument_list|(
specifier|const
name|DWARFDebugLine
operator|::
name|Sequence
operator|&
name|S
argument_list|)
block|{
name|Sequences
operator|.
name|push_back
argument_list|(
name|S
argument_list|)
expr_stmt|;
block|}
comment|/// Returns the index of the row with file/line info for a given address,
comment|/// or UnknownRowIndex if there is no such row.
name|uint32_t
name|lookupAddress
argument_list|(
name|uint64_t
name|Address
argument_list|)
decl|const
decl_stmt|;
name|bool
name|lookupAddressRange
argument_list|(
name|uint64_t
name|Address
argument_list|,
name|uint64_t
name|Size
argument_list|,
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
name|bool
name|hasFileAtIndex
argument_list|(
name|uint64_t
name|FileIndex
argument_list|)
decl|const
decl_stmt|;
comment|/// Extracts filename by its index in filename table in prologue.
comment|/// Returns true on success.
name|bool
name|getFileNameByIndex
argument_list|(
name|uint64_t
name|FileIndex
argument_list|,
specifier|const
name|char
operator|*
name|CompDir
argument_list|,
name|DILineInfoSpecifier
operator|::
name|FileLineInfoKind
name|Kind
argument_list|,
name|std
operator|::
name|string
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
comment|/// Fills the Result argument with the file and line information
comment|/// corresponding to Address. Returns true on success.
name|bool
name|getFileLineInfoForAddress
argument_list|(
name|uint64_t
name|Address
argument_list|,
specifier|const
name|char
operator|*
name|CompDir
argument_list|,
name|DILineInfoSpecifier
operator|::
name|FileLineInfoKind
name|Kind
argument_list|,
name|DILineInfo
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// Parse prologue and all rows.
name|bool
name|parse
parameter_list|(
name|DataExtractor
name|DebugLineData
parameter_list|,
specifier|const
name|RelocAddrMap
modifier|*
name|RMap
parameter_list|,
name|uint32_t
modifier|*
name|OffsetPtr
parameter_list|)
function_decl|;
name|struct
name|Prologue
name|Prologue
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Row
operator|>
name|RowVector
expr_stmt|;
typedef|typedef
name|RowVector
operator|::
name|const_iterator
name|RowIter
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Sequence
operator|>
name|SequenceVector
expr_stmt|;
typedef|typedef
name|SequenceVector
operator|::
name|const_iterator
name|SequenceIter
expr_stmt|;
name|RowVector
name|Rows
decl_stmt|;
name|SequenceVector
name|Sequences
decl_stmt|;
name|private
label|:
name|uint32_t
name|findRowInSeq
argument_list|(
specifier|const
name|DWARFDebugLine
operator|::
name|Sequence
operator|&
name|Seq
argument_list|,
name|uint64_t
name|Address
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
specifier|const
name|LineTable
modifier|*
name|getLineTable
argument_list|(
name|uint32_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|LineTable
modifier|*
name|getOrParseLineTable
parameter_list|(
name|DataExtractor
name|DebugLineData
parameter_list|,
name|uint32_t
name|Offset
parameter_list|)
function_decl|;
name|private
label|:
struct|struct
name|ParsingState
block|{
name|ParsingState
argument_list|(
expr|struct
name|LineTable
operator|*
name|LT
argument_list|)
expr_stmt|;
name|void
name|resetRowAndSequence
parameter_list|()
function_decl|;
name|void
name|appendRowToMatrix
parameter_list|(
name|uint32_t
name|Offset
parameter_list|)
function_decl|;
comment|/// Line table we're currently parsing.
name|struct
name|LineTable
modifier|*
name|LineTable
decl_stmt|;
comment|/// The row number that starts at zero for the prologue, and increases for
comment|/// each row added to the matrix.
name|unsigned
name|RowNumber
decl_stmt|;
name|struct
name|Row
name|Row
decl_stmt|;
name|struct
name|Sequence
name|Sequence
decl_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint32_t
operator|,
name|LineTable
operator|>
name|LineTableMapTy
expr_stmt|;
typedef|typedef
name|LineTableMapTy
operator|::
name|iterator
name|LineTableIter
expr_stmt|;
typedef|typedef
name|LineTableMapTy
operator|::
name|const_iterator
name|LineTableConstIter
expr_stmt|;
specifier|const
name|RelocAddrMap
modifier|*
name|RelocMap
decl_stmt|;
name|LineTableMapTy
name|LineTableMap
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_DWARFDEBUGLINE_H
end_comment

end_unit


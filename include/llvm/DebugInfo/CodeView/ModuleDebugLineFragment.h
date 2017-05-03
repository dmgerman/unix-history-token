begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ModuleDebugLineFragment.h --------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGLINEFRAGMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGLINEFRAGMENT_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/Line.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/ModuleDebugFragment.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamReader.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|ModuleDebugFileChecksumFragment
decl_stmt|;
name|class
name|StringTable
decl_stmt|;
comment|// Corresponds to the `CV_DebugSLinesHeader_t` structure.
struct|struct
name|LineFragmentHeader
block|{
name|support
operator|::
name|ulittle32_t
name|RelocOffset
expr_stmt|;
comment|// Code offset of line contribution.
name|support
operator|::
name|ulittle16_t
name|RelocSegment
expr_stmt|;
comment|// Code segment of line contribution.
name|support
operator|::
name|ulittle16_t
name|Flags
expr_stmt|;
comment|// See LineFlags enumeration.
name|support
operator|::
name|ulittle32_t
name|CodeSize
expr_stmt|;
comment|// Code size of this line contribution.
block|}
struct|;
comment|// Corresponds to the `CV_DebugSLinesFileBlockHeader_t` structure.
struct|struct
name|LineBlockFragmentHeader
block|{
name|support
operator|::
name|ulittle32_t
name|NameIndex
expr_stmt|;
comment|// Offset of FileChecksum entry in File
comment|// checksums buffer.  The checksum entry then
comment|// contains another offset into the string
comment|// table of the actual name.
name|support
operator|::
name|ulittle32_t
name|NumLines
expr_stmt|;
comment|// Number of lines
name|support
operator|::
name|ulittle32_t
name|BlockSize
expr_stmt|;
comment|// Code size of block, in bytes.
comment|// The following two variable length arrays appear immediately after the
comment|// header.  The structure definitions follow.
comment|// LineNumberEntry   Lines[NumLines];
comment|// ColumnNumberEntry Columns[NumLines];
block|}
struct|;
comment|// Corresponds to `CV_Line_t` structure
struct|struct
name|LineNumberEntry
block|{
name|support
operator|::
name|ulittle32_t
name|Offset
expr_stmt|;
comment|// Offset to start of code bytes for line number
name|support
operator|::
name|ulittle32_t
name|Flags
expr_stmt|;
comment|// Start:24, End:7, IsStatement:1
block|}
struct|;
comment|// Corresponds to `CV_Column_t` structure
struct|struct
name|ColumnNumberEntry
block|{
name|support
operator|::
name|ulittle16_t
name|StartColumn
expr_stmt|;
name|support
operator|::
name|ulittle16_t
name|EndColumn
expr_stmt|;
block|}
struct|;
struct|struct
name|LineColumnEntry
block|{
name|support
operator|::
name|ulittle32_t
name|NameIndex
expr_stmt|;
name|FixedStreamArray
operator|<
name|LineNumberEntry
operator|>
name|LineNumbers
expr_stmt|;
name|FixedStreamArray
operator|<
name|ColumnNumberEntry
operator|>
name|Columns
expr_stmt|;
block|}
struct|;
name|class
name|LineColumnExtractor
block|{
name|public
label|:
typedef|typedef
specifier|const
name|LineFragmentHeader
modifier|*
name|ContextType
typedef|;
specifier|static
name|Error
name|extract
parameter_list|(
name|BinaryStreamRef
name|Stream
parameter_list|,
name|uint32_t
modifier|&
name|Len
parameter_list|,
name|LineColumnEntry
modifier|&
name|Item
parameter_list|,
specifier|const
name|LineFragmentHeader
modifier|*
name|Ctx
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|class
name|ModuleDebugLineFragmentRef
name|final
range|:
name|public
name|ModuleDebugFragmentRef
block|{
name|friend
name|class
name|LineColumnExtractor
block|;
typedef|typedef
name|VarStreamArray
operator|<
name|LineColumnEntry
operator|,
name|LineColumnExtractor
operator|>
name|LineInfoArray
expr_stmt|;
typedef|typedef
name|LineInfoArray
operator|::
name|Iterator
name|Iterator
expr_stmt|;
name|public
label|:
name|ModuleDebugLineFragmentRef
argument_list|()
expr_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ModuleDebugFragmentRef
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|ModuleDebugFragmentKind
operator|::
name|Lines
return|;
block|}
name|Error
name|initialize
parameter_list|(
name|BinaryStreamReader
name|Reader
parameter_list|)
function_decl|;
name|Iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|LinesAndColumns
operator|.
name|begin
argument_list|()
return|;
block|}
name|Iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|LinesAndColumns
operator|.
name|end
argument_list|()
return|;
block|}
specifier|const
name|LineFragmentHeader
operator|*
name|header
argument_list|()
specifier|const
block|{
return|return
name|Header
return|;
block|}
name|bool
name|hasColumnInfo
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
specifier|const
name|LineFragmentHeader
modifier|*
name|Header
init|=
name|nullptr
decl_stmt|;
name|LineInfoArray
name|LinesAndColumns
decl_stmt|;
block|}
empty_stmt|;
name|class
name|ModuleDebugLineFragment
name|final
range|:
name|public
name|ModuleDebugFragment
block|{   struct
name|Block
block|{
name|Block
argument_list|(
argument|uint32_t ChecksumBufferOffset
argument_list|)
operator|:
name|ChecksumBufferOffset
argument_list|(
argument|ChecksumBufferOffset
argument_list|)
block|{}
name|uint32_t
name|ChecksumBufferOffset
block|;
name|std
operator|::
name|vector
operator|<
name|LineNumberEntry
operator|>
name|Lines
block|;
name|std
operator|::
name|vector
operator|<
name|ColumnNumberEntry
operator|>
name|Columns
block|;   }
block|;
name|public
operator|:
name|ModuleDebugLineFragment
argument_list|(
name|ModuleDebugFileChecksumFragment
operator|&
name|Checksums
argument_list|,
name|StringTable
operator|&
name|Strings
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const ModuleDebugFragment *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|ModuleDebugFragmentKind
operator|::
name|Lines
return|;
block|}
name|void
name|createBlock
argument_list|(
argument|StringRef FileName
argument_list|)
block|;
name|void
name|addLineInfo
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|const LineInfo&Line
argument_list|)
block|;
name|void
name|addLineAndColumnInfo
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|const LineInfo&Line
argument_list|,
argument|uint32_t ColStart
argument_list|,
argument|uint32_t ColEnd
argument_list|)
block|;
name|uint32_t
name|calculateSerializedLength
argument_list|()
name|override
block|;
name|Error
name|commit
argument_list|(
argument|BinaryStreamWriter&Writer
argument_list|)
name|override
block|;
name|void
name|setRelocationAddress
argument_list|(
argument|uint16_t Segment
argument_list|,
argument|uint16_t Offset
argument_list|)
block|;
name|void
name|setCodeSize
argument_list|(
argument|uint32_t Size
argument_list|)
block|;
name|void
name|setFlags
argument_list|(
argument|LineFlags Flags
argument_list|)
block|;
name|bool
name|hasColumnInfo
argument_list|()
specifier|const
block|;
name|private
operator|:
name|ModuleDebugFileChecksumFragment
operator|&
name|Checksums
block|;
name|uint16_t
name|RelocOffset
operator|=
literal|0
block|;
name|uint16_t
name|RelocSegment
operator|=
literal|0
block|;
name|uint32_t
name|CodeSize
operator|=
literal|0
block|;
name|LineFlags
name|Flags
operator|=
name|LF_None
block|;
name|std
operator|::
name|vector
operator|<
name|Block
operator|>
name|Blocks
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit


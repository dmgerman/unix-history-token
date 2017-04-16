begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ModuleSubstream.h ----------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_MODULESUBSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_MODULESUBSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
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
comment|// Corresponds to the `CV_DebugSSubsectionHeader_t` structure.
struct|struct
name|ModuleSubsectionHeader
block|{
name|support
operator|::
name|ulittle32_t
name|Kind
expr_stmt|;
comment|// codeview::ModuleSubstreamKind enum
name|support
operator|::
name|ulittle32_t
name|Length
expr_stmt|;
comment|// number of bytes occupied by this record.
block|}
struct|;
comment|// Corresponds to the `CV_DebugSLinesHeader_t` structure.
struct|struct
name|LineSubstreamHeader
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
name|LineFileBlockHeader
block|{
name|support
operator|::
name|ulittle32_t
name|NameIndex
expr_stmt|;
comment|// Index in DBI name buffer of filename.
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
name|class
name|ModuleSubstream
block|{
name|public
label|:
name|ModuleSubstream
argument_list|()
expr_stmt|;
name|ModuleSubstream
argument_list|(
argument|ModuleSubstreamKind Kind
argument_list|,
argument|BinaryStreamRef Data
argument_list|)
empty_stmt|;
specifier|static
name|Error
name|initialize
parameter_list|(
name|BinaryStreamRef
name|Stream
parameter_list|,
name|ModuleSubstream
modifier|&
name|Info
parameter_list|)
function_decl|;
name|uint32_t
name|getRecordLength
argument_list|()
specifier|const
expr_stmt|;
name|ModuleSubstreamKind
name|getSubstreamKind
argument_list|()
specifier|const
expr_stmt|;
name|BinaryStreamRef
name|getRecordData
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|ModuleSubstreamKind
name|Kind
decl_stmt|;
name|BinaryStreamRef
name|Data
decl_stmt|;
block|}
empty_stmt|;
typedef|typedef
name|VarStreamArray
operator|<
name|ModuleSubstream
operator|>
name|ModuleSubstreamArray
expr_stmt|;
block|}
comment|// namespace codeview
name|template
operator|<
operator|>
expr|struct
name|VarStreamArrayExtractor
operator|<
name|codeview
operator|::
name|ModuleSubstream
operator|>
block|{
name|Error
name|operator
argument_list|()
operator|(
name|BinaryStreamRef
name|Stream
operator|,
name|uint32_t
operator|&
name|Length
operator|,
name|codeview
operator|::
name|ModuleSubstream
operator|&
name|Info
operator|)
specifier|const
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|codeview
operator|::
name|ModuleSubstream
operator|::
name|initialize
argument_list|(
name|Stream
argument_list|,
name|Info
argument_list|)
condition|)
return|return
name|EC
return|;
name|Length
operator|=
name|Info
operator|.
name|getRecordLength
argument_list|()
block|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_MODULESUBSTREAM_H
end_comment

end_unit


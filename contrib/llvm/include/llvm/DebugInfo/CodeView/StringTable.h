begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StringTable.h - CodeView String Table Reader/Writer ------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_STRINGTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_STRINGTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BinaryStreamReader
decl_stmt|;
name|class
name|BinaryStreamRef
decl_stmt|;
name|class
name|BinaryStreamWriter
decl_stmt|;
name|namespace
name|codeview
block|{
comment|/// Represents a read-only view of a CodeView string table.  This is a very
comment|/// simple flat buffer consisting of null-terminated strings, where strings
comment|/// are retrieved by their offset in the buffer.  StringTableRef does not own
comment|/// the underlying storage for the buffer.
name|class
name|StringTableRef
block|{
name|public
label|:
name|StringTableRef
argument_list|()
expr_stmt|;
name|Error
name|initialize
parameter_list|(
name|BinaryStreamRef
name|Contents
parameter_list|)
function_decl|;
name|Expected
operator|<
name|StringRef
operator|>
name|getString
argument_list|(
argument|uint32_t Offset
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|valid
argument_list|()
specifier|const
block|{
return|return
name|Stream
operator|.
name|valid
argument_list|()
return|;
block|}
name|private
label|:
name|BinaryStreamRef
name|Stream
decl_stmt|;
block|}
empty_stmt|;
comment|/// Represents a read-write view of a CodeView string table.  StringTable owns
comment|/// the underlying storage for the table, and is capable of serializing the
comment|/// string table into a format understood by StringTableRef.
name|class
name|StringTable
block|{
name|public
label|:
comment|// If string S does not exist in the string table, insert it.
comment|// Returns the ID for S.
name|uint32_t
name|insert
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
comment|// Return the ID for string S.  Assumes S exists in the table.
name|uint32_t
name|getStringId
argument_list|(
name|StringRef
name|S
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|calculateSerializedSize
argument_list|()
specifier|const
expr_stmt|;
name|Error
name|commit
argument_list|(
name|BinaryStreamWriter
operator|&
name|Writer
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|size
argument_list|()
specifier|const
expr_stmt|;
name|StringMap
operator|<
name|uint32_t
operator|>
operator|::
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Strings
operator|.
name|begin
argument_list|()
return|;
block|}
name|StringMap
operator|<
name|uint32_t
operator|>
operator|::
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Strings
operator|.
name|end
argument_list|()
return|;
block|}
name|private
label|:
name|StringMap
operator|<
name|uint32_t
operator|>
name|Strings
expr_stmt|;
name|uint32_t
name|StringSize
init|=
literal|1
decl_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugStringTableSubsection.h - CodeView String Table -----*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGSTRINGTABLESUBSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGSTRINGTABLESUBSECTION_H
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
file|"llvm/DebugInfo/CodeView/DebugSubsection.h"
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
comment|/// are retrieved by their offset in the buffer.  DebugStringTableSubsectionRef
comment|/// does not own the underlying storage for the buffer.
name|class
name|DebugStringTableSubsectionRef
range|:
name|public
name|DebugSubsectionRef
block|{
name|public
operator|:
name|DebugStringTableSubsectionRef
argument_list|()
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DebugSubsectionRef *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|DebugSubsectionKind
operator|::
name|StringTable
return|;
block|}
name|Error
name|initialize
argument_list|(
argument|BinaryStreamRef Contents
argument_list|)
block|;
name|Expected
operator|<
name|StringRef
operator|>
name|getString
argument_list|(
argument|uint32_t Offset
argument_list|)
specifier|const
block|;
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
operator|:
name|BinaryStreamRef
name|Stream
block|; }
decl_stmt|;
comment|/// Represents a read-write view of a CodeView string table.
comment|/// DebugStringTableSubsection owns the underlying storage for the table, and is
comment|/// capable of serializing the string table into a format understood by
comment|/// DebugStringTableSubsectionRef.
name|class
name|DebugStringTableSubsection
range|:
name|public
name|DebugSubsection
block|{
name|public
operator|:
name|DebugStringTableSubsection
argument_list|()
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DebugSubsection *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|DebugSubsectionKind
operator|::
name|StringTable
return|;
block|}
comment|// If string S does not exist in the string table, insert it.
comment|// Returns the ID for S.
name|uint32_t
name|insert
argument_list|(
argument|StringRef S
argument_list|)
block|;
comment|// Return the ID for string S.  Assumes S exists in the table.
name|uint32_t
name|getStringId
argument_list|(
argument|StringRef S
argument_list|)
specifier|const
block|;
name|uint32_t
name|calculateSerializedSize
argument_list|()
specifier|const
name|override
block|;
name|Error
name|commit
argument_list|(
argument|BinaryStreamWriter&Writer
argument_list|)
specifier|const
name|override
block|;
name|uint32_t
name|size
argument_list|()
specifier|const
block|;
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
operator|:
name|StringMap
operator|<
name|uint32_t
operator|>
name|Strings
block|;
name|uint32_t
name|StringSize
operator|=
literal|1
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


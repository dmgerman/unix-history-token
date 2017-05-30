begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugChecksumsSubsection.h -------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGCHECKSUMSSUBSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGCHECKSUMSSUBSECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/DebugSubsection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
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
file|"llvm/Support/Endian.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|DebugStringTableSubsection
decl_stmt|;
struct|struct
name|FileChecksumEntry
block|{
name|uint32_t
name|FileNameOffset
decl_stmt|;
comment|// Byte offset of filename in global stringtable.
name|FileChecksumKind
name|Kind
decl_stmt|;
comment|// The type of checksum.
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Checksum
expr_stmt|;
comment|// The bytes of the checksum.
block|}
struct|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|VarStreamArrayExtractor
operator|<
name|codeview
operator|::
name|FileChecksumEntry
operator|>
block|{
name|public
operator|:
typedef|typedef
name|void
name|ContextType
typedef|;
specifier|static
name|Error
name|extract
argument_list|(
argument|BinaryStreamRef Stream
argument_list|,
argument|uint32_t&Len
argument_list|,
argument|codeview::FileChecksumEntry&Item
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
unit|}  namespace
name|llvm
end_macro

begin_block
block|{
name|namespace
name|codeview
block|{
name|class
name|DebugChecksumsSubsectionRef
name|final
range|:
name|public
name|DebugSubsectionRef
block|{
typedef|typedef
name|VarStreamArray
operator|<
name|codeview
operator|::
name|FileChecksumEntry
operator|>
name|FileChecksumArray
expr_stmt|;
typedef|typedef
name|FileChecksumArray
operator|::
name|Iterator
name|Iterator
expr_stmt|;
name|public
label|:
name|DebugChecksumsSubsectionRef
argument_list|()
operator|:
name|DebugSubsectionRef
argument_list|(
argument|DebugSubsectionKind::FileChecksums
argument_list|)
block|{}
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
name|FileChecksums
return|;
block|}
name|bool
name|valid
argument_list|()
specifier|const
block|{
return|return
name|Checksums
operator|.
name|valid
argument_list|()
return|;
block|}
name|Error
name|initialize
parameter_list|(
name|BinaryStreamReader
name|Reader
parameter_list|)
function_decl|;
name|Error
name|initialize
parameter_list|(
name|BinaryStreamRef
name|Stream
parameter_list|)
function_decl|;
name|Iterator
name|begin
parameter_list|()
block|{
return|return
name|Checksums
operator|.
name|begin
argument_list|()
return|;
block|}
name|Iterator
name|end
parameter_list|()
block|{
return|return
name|Checksums
operator|.
name|end
argument_list|()
return|;
block|}
specifier|const
name|FileChecksumArray
operator|&
name|getArray
argument_list|()
specifier|const
block|{
return|return
name|Checksums
return|;
block|}
name|private
label|:
name|FileChecksumArray
name|Checksums
decl_stmt|;
block|}
empty_stmt|;
name|class
name|DebugChecksumsSubsection
name|final
range|:
name|public
name|DebugSubsection
block|{
name|public
operator|:
name|explicit
name|DebugChecksumsSubsection
argument_list|(
name|DebugStringTableSubsection
operator|&
name|Strings
argument_list|)
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
name|FileChecksums
return|;
block|}
name|void
name|addChecksum
argument_list|(
argument|StringRef FileName
argument_list|,
argument|FileChecksumKind Kind
argument_list|,
argument|ArrayRef<uint8_t> Bytes
argument_list|)
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
name|mapChecksumOffset
argument_list|(
argument|StringRef FileName
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DebugStringTableSubsection
operator|&
name|Strings
block|;
name|DenseMap
operator|<
name|uint32_t
block|,
name|uint32_t
operator|>
name|OffsetMap
block|;
name|uint32_t
name|SerializedSize
operator|=
literal|0
block|;
name|llvm
operator|::
name|BumpPtrAllocator
name|Storage
block|;
name|std
operator|::
name|vector
operator|<
name|FileChecksumEntry
operator|>
name|Checksums
block|; }
decl_stmt|;
block|}
end_block

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit


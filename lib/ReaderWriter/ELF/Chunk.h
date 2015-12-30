begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/Chunks.h --------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_READER_WRITER_ELF_CHUNKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_CHUNKS_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileOutputBuffer.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|ELFLinkingContext
decl_stmt|;
name|namespace
name|elf
block|{
name|class
name|ELFWriter
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|TargetLayout
expr_stmt|;
comment|/// \brief A chunk is a contiguous region of space
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|Chunk
block|{
name|public
operator|:
comment|/// \brief Describes the type of Chunk
expr|enum
name|Kind
operator|:
name|uint8_t
block|{
name|ELFHeader
block|,
comment|///< ELF Header
name|ProgramHeader
block|,
comment|///< Program Header
name|SectionHeader
block|,
comment|///< Section header
name|ELFSegment
block|,
comment|///< Segment
name|ELFSection
block|,
comment|///< Section
name|AtomSection
block|,
comment|///< A section containing atoms
name|Expression
comment|///< A linker script expression
block|}
block|;
comment|/// \brief the ContentType of the chunk
block|enum
name|ContentType
operator|:
name|uint8_t
block|{
name|Unknown
block|,
name|Header
block|,
name|Code
block|,
name|Data
block|,
name|Note
block|,
name|TLS
block|}
block|;
name|Chunk
argument_list|(
argument|StringRef name
argument_list|,
argument|Kind kind
argument_list|,
argument|const ELFLinkingContext&ctx
argument_list|)
operator|:
name|_name
argument_list|(
name|name
argument_list|)
block|,
name|_kind
argument_list|(
name|kind
argument_list|)
block|,
name|_ctx
argument_list|(
argument|ctx
argument_list|)
block|{}
name|virtual
operator|~
name|Chunk
argument_list|()
block|{}
comment|// The name of the chunk
name|StringRef
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
return|;
block|}
comment|// Kind of chunk
name|Kind
name|kind
argument_list|()
specifier|const
block|{
return|return
name|_kind
return|;
block|}
name|virtual
name|uint64_t
name|fileSize
argument_list|()
specifier|const
block|{
return|return
name|_fsize
return|;
block|}
name|virtual
name|void
name|setFileSize
argument_list|(
argument|uint64_t sz
argument_list|)
block|{
name|_fsize
operator|=
name|sz
block|; }
name|virtual
name|void
name|setAlign
argument_list|(
argument|uint64_t align
argument_list|)
block|{
name|_alignment
operator|=
name|align
block|; }
name|virtual
name|uint64_t
name|alignment
argument_list|()
specifier|const
block|{
return|return
name|_alignment
return|;
block|}
comment|// The ordinal value of the chunk
name|uint64_t
name|ordinal
argument_list|()
specifier|const
block|{
return|return
name|_ordinal
return|;
block|}
name|void
name|setOrdinal
argument_list|(
argument|uint64_t newVal
argument_list|)
block|{
name|_ordinal
operator|=
name|newVal
block|; }
comment|// The order in which the chunk would appear in the output file
name|uint64_t
name|order
argument_list|()
specifier|const
block|{
return|return
name|_order
return|;
block|}
name|void
name|setOrder
argument_list|(
argument|uint32_t order
argument_list|)
block|{
name|_order
operator|=
name|order
block|; }
comment|// Output file offset of the chunk
name|uint64_t
name|fileOffset
argument_list|()
specifier|const
block|{
return|return
name|_fileoffset
return|;
block|}
name|void
name|setFileOffset
argument_list|(
argument|uint64_t offset
argument_list|)
block|{
name|_fileoffset
operator|=
name|offset
block|; }
comment|// Output start address of the chunk
name|virtual
name|void
name|setVirtualAddr
argument_list|(
argument|uint64_t start
argument_list|)
block|{
name|_start
operator|=
name|start
block|; }
name|virtual
name|uint64_t
name|virtualAddr
argument_list|()
specifier|const
block|{
return|return
name|_start
return|;
block|}
comment|// Memory size of the chunk
name|uint64_t
name|memSize
argument_list|()
specifier|const
block|{
return|return
name|_msize
return|;
block|}
name|void
name|setMemSize
argument_list|(
argument|uint64_t msize
argument_list|)
block|{
name|_msize
operator|=
name|msize
block|; }
comment|// Returns the ContentType of the chunk
name|virtual
name|int
name|getContentType
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|// Writer the chunk
name|virtual
name|void
name|write
argument_list|(
name|ELFWriter
operator|*
name|writer
argument_list|,
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|layout
argument_list|,
name|llvm
operator|::
name|FileOutputBuffer
operator|&
name|buffer
argument_list|)
operator|=
literal|0
block|;
comment|// Finalize the chunk before assigning offsets/virtual addresses
name|virtual
name|void
name|doPreFlight
argument_list|()
block|{}
comment|// Finalize the chunk before writing
name|virtual
name|void
name|finalize
argument_list|()
block|{}
name|protected
operator|:
name|StringRef
name|_name
block|;
name|Kind
name|_kind
block|;
specifier|const
name|ELFLinkingContext
operator|&
name|_ctx
block|;
name|uint64_t
name|_fsize
operator|=
literal|0
block|;
name|uint64_t
name|_msize
operator|=
literal|0
block|;
name|uint64_t
name|_alignment
operator|=
literal|1
block|;
name|uint32_t
name|_order
operator|=
literal|0
block|;
name|uint64_t
name|_ordinal
operator|=
literal|1
block|;
name|uint64_t
name|_start
operator|=
literal|0
block|;
name|uint64_t
name|_fileoffset
operator|=
literal|0
block|; }
expr_stmt|;
block|}
comment|// end namespace elf
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


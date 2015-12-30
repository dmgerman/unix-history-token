begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/SegmentChunks.h -------------------------------===//
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
name|LLD_READER_WRITER_ELF_SEGMENT_CHUNKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_SEGMENT_CHUNKS_H
end_define

begin_include
include|#
directive|include
file|"Chunk.h"
end_include

begin_include
include|#
directive|include
file|"SectionChunks.h"
end_include

begin_include
include|#
directive|include
file|"Writer.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/range.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Writer.h"
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
name|namespace
name|elf
block|{
name|template
operator|<
name|typename
name|ELFT
operator|>
name|class
name|TargetLayout
expr_stmt|;
comment|/// \brief A segment can be divided into segment slices
comment|///        depending on how the segments can be split
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|SegmentSlice
block|{
name|public
operator|:
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
operator|>
operator|::
name|iterator
name|SectionIter
expr_stmt|;
comment|/// Set the start of the slice.
name|void
name|setStart
argument_list|(
argument|int32_t s
argument_list|)
block|{
name|_startSection
operator|=
name|s
block|; }
comment|// Set the segment slice start and end iterators. This is used to walk through
comment|// the sections that are part of the Segment slice
name|void
name|setSections
argument_list|(
argument|range<SectionIter> sections
argument_list|)
block|{
name|_sections
operator|=
name|sections
block|; }
comment|// Return the fileOffset of the slice
name|uint64_t
name|fileOffset
argument_list|()
specifier|const
block|{
return|return
name|_offset
return|;
block|}
name|void
name|setFileOffset
parameter_list|(
name|uint64_t
name|offset
parameter_list|)
block|{
name|_offset
operator|=
name|offset
expr_stmt|;
block|}
comment|// Return the size of the slice
name|uint64_t
name|fileSize
argument_list|()
specifier|const
block|{
return|return
name|_fsize
return|;
block|}
name|void
name|setFileSize
parameter_list|(
name|uint64_t
name|filesz
parameter_list|)
block|{
name|_fsize
operator|=
name|filesz
expr_stmt|;
block|}
comment|// Return the start of the slice
name|int32_t
name|startSection
argument_list|()
specifier|const
block|{
return|return
name|_startSection
return|;
block|}
comment|// Return the start address of the slice
name|uint64_t
name|virtualAddr
argument_list|()
specifier|const
block|{
return|return
name|_addr
return|;
block|}
comment|// Return the memory size of the slice
name|uint64_t
name|memSize
argument_list|()
specifier|const
block|{
return|return
name|_memSize
return|;
block|}
comment|// Return the alignment of the slice
name|uint64_t
name|alignment
argument_list|()
specifier|const
block|{
return|return
name|_alignment
return|;
block|}
name|void
name|setMemSize
parameter_list|(
name|uint64_t
name|memsz
parameter_list|)
block|{
name|_memSize
operator|=
name|memsz
expr_stmt|;
block|}
name|void
name|setVirtualAddr
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
block|{
name|_addr
operator|=
name|addr
expr_stmt|;
block|}
name|void
name|setAlign
parameter_list|(
name|uint64_t
name|align
parameter_list|)
block|{
name|_alignment
operator|=
name|align
expr_stmt|;
block|}
specifier|static
name|bool
name|compare_slices
argument_list|(
name|SegmentSlice
operator|<
name|ELFT
operator|>
operator|*
name|a
argument_list|,
name|SegmentSlice
operator|<
name|ELFT
operator|>
operator|*
name|b
argument_list|)
decl_stmt|;
name|range
operator|<
name|SectionIter
operator|>
name|sections
argument_list|()
block|{
return|return
name|_sections
return|;
block|}
name|private
label|:
name|range
operator|<
name|SectionIter
operator|>
name|_sections
expr_stmt|;
name|int32_t
name|_startSection
decl_stmt|;
name|uint64_t
name|_addr
decl_stmt|;
name|uint64_t
name|_offset
decl_stmt|;
name|uint64_t
name|_alignment
decl_stmt|;
name|uint64_t
name|_fsize
decl_stmt|;
name|uint64_t
name|_memSize
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief A segment contains a set of sections, that have similar properties
comment|//  the sections are already separated based on different flags and properties
comment|//  the segment is just a way to concatenate sections to segments
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|Segment
operator|:
name|public
name|Chunk
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|SegmentSlice
operator|<
name|ELFT
operator|>
operator|*
operator|>
operator|::
name|iterator
name|SliceIter
expr_stmt|;
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
operator|>
operator|::
name|iterator
name|SectionIter
expr_stmt|;
name|Segment
argument_list|(
argument|const ELFLinkingContext&ctx
argument_list|,
argument|StringRef name
argument_list|,
argument|const typename TargetLayout<ELFT>::SegmentType type
argument_list|)
empty_stmt|;
comment|/// \brief the Order of segments that appear in the output file
enum|enum
name|SegmentOrder
block|{
name|permUnknown
block|,
name|permRWX
block|,
name|permRX
block|,
name|permR
block|,
name|permRWL
block|,
name|permRW
block|,
name|permNonAccess
block|}
enum|;
comment|/// append a section to a segment
name|virtual
name|void
name|append
argument_list|(
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
name|chunk
argument_list|)
decl_stmt|;
comment|/// Sort segments depending on the property
comment|/// If we have a Program Header segment, it should appear first
comment|/// If we have a INTERP segment, that should appear after the Program Header
comment|/// All Loadable segments appear next in this order
comment|/// All Read Write Execute segments follow
comment|/// All Read Execute segments appear next
comment|/// All Read only segments appear first
comment|/// All Write execute segments follow
specifier|static
name|bool
name|compareSegments
argument_list|(
name|Segment
operator|<
name|ELFT
operator|>
operator|*
name|sega
argument_list|,
name|Segment
operator|<
name|ELFT
operator|>
operator|*
name|segb
argument_list|)
decl_stmt|;
comment|/// \brief Start assigning file offset to the segment chunks The fileoffset
comment|/// needs to be page at the start of the segment and in addition the
comment|/// fileoffset needs to be aligned to the max section alignment within the
comment|/// segment. This is required so that the ELF property p_poffset % p_align =
comment|/// p_vaddr mod p_align holds true.
comment|/// The algorithm starts off by assigning the startOffset thats passed in as
comment|/// parameter to the first section in the segment, if the difference between
comment|/// the newly computed offset is greater than a page, then we create a segment
comment|/// slice, as it would be a waste of virtual memory just to be filled with
comment|/// zeroes
name|void
name|assignFileOffsets
parameter_list|(
name|uint64_t
name|startOffset
parameter_list|)
function_decl|;
comment|/// \brief Assign virtual addresses to the slices
name|void
name|assignVirtualAddress
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
function_decl|;
comment|// Write the Segment
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
name|override
decl_stmt|;
name|int64_t
name|flags
argument_list|()
specifier|const
expr_stmt|;
comment|// Set segment flags directly.
name|void
name|setSegmentFlags
parameter_list|(
name|uint64_t
name|flags
parameter_list|)
function_decl|;
comment|/// Prepend a generic chunk to the segment.
name|void
name|prepend
argument_list|(
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
name|c
argument_list|)
block|{
name|_sections
operator|.
name|insert
argument_list|(
name|_sections
operator|.
name|begin
argument_list|()
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
comment|/// Finalize the segment, before we want to write the segment header
comment|/// information
name|void
name|finalize
argument_list|()
name|override
expr_stmt|;
comment|// For LLVM RTTI
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
name|c
argument_list|)
block|{
return|return
name|c
operator|->
name|kind
argument_list|()
operator|==
name|Chunk
operator|<
name|ELFT
operator|>
operator|::
name|Kind
operator|::
name|ELFSegment
return|;
block|}
comment|// Getters
name|int32_t
name|sectionCount
argument_list|()
specifier|const
block|{
return|return
name|_sections
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief, this function returns the type of segment (PT_*)
name|typename
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|::
name|SegmentType
name|segmentType
argument_list|()
specifier|const
block|{
return|return
name|_segmentType
return|;
block|}
comment|/// \brief return the segment type depending on the content,
comment|/// If the content corresponds to Code, this will return Segment::Code
comment|/// If the content corresponds to Data, this will return Segment::Data
comment|/// If the content corresponds to TLS, this will return Segment::TLS
name|int
name|getContentType
argument_list|()
specifier|const
name|override
expr_stmt|;
name|int
name|pageSize
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|_ctx
operator|.
name|getPageSize
argument_list|()
return|;
block|}
name|int
name|rawflags
argument_list|()
specifier|const
block|{
return|return
name|_atomflags
return|;
block|}
name|int64_t
name|atomflags
argument_list|()
specifier|const
expr_stmt|;
name|int64_t
name|numSlices
argument_list|()
specifier|const
block|{
return|return
name|_segmentSlices
operator|.
name|size
argument_list|()
return|;
block|}
name|range
operator|<
name|SliceIter
operator|>
name|slices
argument_list|()
block|{
return|return
name|_segmentSlices
return|;
block|}
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
name|firstSection
argument_list|()
block|{
return|return
name|_sections
index|[
literal|0
index|]
return|;
block|}
name|private
label|:
comment|/// \brief Check if the chunk needs to be aligned
name|bool
name|needAlign
argument_list|(
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
name|chunk
argument_list|)
decl|const
decl_stmt|;
comment|// Cached value of outputMagic
name|ELFLinkingContext
operator|::
name|OutputMagic
name|_outputMagic
expr_stmt|;
name|protected
label|:
comment|/// \brief Section or some other chunk type.
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|_sections
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|SegmentSlice
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|_segmentSlices
expr_stmt|;
name|typename
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|::
name|SegmentType
name|_segmentType
expr_stmt|;
name|uint64_t
name|_flags
decl_stmt|;
name|int64_t
name|_atomflags
decl_stmt|;
name|bool
name|_segmentFlags
decl_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|_segmentAllocate
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// This chunk represents a linker script expression that needs to be calculated
end_comment

begin_comment
comment|/// at the time the virtual addresses for the parent segment are being assigned.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ExpressionChunk
operator|:
name|public
name|Chunk
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|ExpressionChunk
argument_list|(
name|ELFLinkingContext
operator|&
name|ctx
argument_list|,
specifier|const
name|script
operator|::
name|SymbolAssignment
operator|*
name|expr
argument_list|)
operator|:
name|Chunk
operator|<
name|ELFT
operator|>
operator|(
name|StringRef
argument_list|()
operator|,
name|Chunk
operator|<
name|ELFT
operator|>
operator|::
name|Kind
operator|::
name|Expression
operator|,
name|ctx
operator|)
block|,
name|_expr
argument_list|(
name|expr
argument_list|)
block|,
name|_linkerScriptSema
argument_list|(
argument|ctx.linkerScriptSema()
argument_list|)
block|{
name|this
operator|->
name|_alignment
operator|=
literal|1
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Chunk<ELFT> *c
argument_list|)
block|{
return|return
name|c
operator|->
name|kind
argument_list|()
operator|==
name|Chunk
operator|<
name|ELFT
operator|>
operator|::
name|Kind
operator|::
name|Expression
return|;
block|}
name|int
name|getContentType
argument_list|()
specifier|const
name|override
block|{
return|return
name|Chunk
operator|<
name|ELFT
operator|>
operator|::
name|ContentType
operator|::
name|Unknown
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|write
argument_list|(
name|ELFWriter
operator|*
argument_list|,
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|&
argument_list|,
name|llvm
operator|::
name|FileOutputBuffer
operator|&
argument_list|)
name|override
block|{}
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|error_code
name|evalExpr
argument_list|(
argument|uint64_t&curPos
argument_list|)
block|{
return|return
name|_linkerScriptSema
operator|.
name|evalExpr
argument_list|(
name|_expr
argument_list|,
name|curPos
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|script
operator|::
name|SymbolAssignment
operator|*
name|_expr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|script
operator|::
name|Sema
operator|&
name|_linkerScriptSema
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief A Program Header segment contains a set of chunks instead of sections
end_comment

begin_comment
comment|/// The segment doesn't contain any slice
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ProgramHeaderSegment
operator|:
name|public
name|Segment
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|ProgramHeaderSegment
argument_list|(
specifier|const
name|ELFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|Segment
operator|<
name|ELFT
operator|>
operator|(
name|ctx
operator|,
literal|"PHDR"
operator|,
name|llvm
operator|::
name|ELF
operator|::
name|PT_PHDR
operator|)
block|{
name|this
operator|->
name|_alignment
operator|=
literal|8
block|;
name|this
operator|->
name|_flags
operator|=
operator|(
name|llvm
operator|::
name|ELF
operator|::
name|SHF_ALLOC
operator||
name|llvm
operator|::
name|ELF
operator|::
name|SHF_EXECINSTR
operator|)
block|;   }
comment|/// Finalize the segment, before we want to write the segment header
comment|/// information
name|void
name|finalize
argument_list|()
name|override
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace elf
end_comment

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_ELF_SEGMENT_CHUNKS_H
end_comment

end_unit


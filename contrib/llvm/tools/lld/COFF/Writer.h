begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Writer.h -------------------------------------------------*- C++ -*-===//
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
name|LLD_COFF_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_COFF_WRITER_H
end_define

begin_include
include|#
directive|include
file|"Chunks.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/COFF.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|coff
block|{
name|class
name|SymbolTable
decl_stmt|;
specifier|static
specifier|const
name|int
name|PageSize
init|=
literal|4096
decl_stmt|;
name|void
name|writeResult
parameter_list|(
name|SymbolTable
modifier|*
name|T
parameter_list|)
function_decl|;
comment|// OutputSection represents a section in an output file. It's a
comment|// container of chunks. OutputSection and Chunk are 1:N relationship.
comment|// Chunks cannot belong to more than one OutputSections. The writer
comment|// creates multiple OutputSections and assign them unique,
comment|// non-overlapping file offsets and RVAs.
name|class
name|OutputSection
block|{
name|public
label|:
name|OutputSection
argument_list|(
argument|llvm::StringRef N
argument_list|)
block|:
name|Name
argument_list|(
name|N
argument_list|)
operator|,
name|Header
argument_list|(
argument|{}
argument_list|)
block|{}
name|void
name|setRVA
argument_list|(
name|uint64_t
argument_list|)
expr_stmt|;
name|void
name|setFileOffset
parameter_list|(
name|uint64_t
parameter_list|)
function_decl|;
name|void
name|addChunk
parameter_list|(
name|Chunk
modifier|*
name|C
parameter_list|)
function_decl|;
name|llvm
operator|::
name|StringRef
name|getName
argument_list|()
block|{
return|return
name|Name
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|*
operator|>
operator|&
name|getChunks
argument_list|()
block|{
return|return
name|Chunks
return|;
block|}
name|void
name|addPermissions
parameter_list|(
name|uint32_t
name|C
parameter_list|)
function_decl|;
name|void
name|setPermissions
parameter_list|(
name|uint32_t
name|C
parameter_list|)
function_decl|;
name|uint32_t
name|getPermissions
parameter_list|()
block|{
return|return
name|Header
operator|.
name|Characteristics
operator|&
name|PermMask
return|;
block|}
name|uint32_t
name|getCharacteristics
parameter_list|()
block|{
return|return
name|Header
operator|.
name|Characteristics
return|;
block|}
name|uint64_t
name|getRVA
parameter_list|()
block|{
return|return
name|Header
operator|.
name|VirtualAddress
return|;
block|}
name|uint64_t
name|getFileOff
parameter_list|()
block|{
return|return
name|Header
operator|.
name|PointerToRawData
return|;
block|}
name|void
name|writeHeaderTo
parameter_list|(
name|uint8_t
modifier|*
name|Buf
parameter_list|)
function_decl|;
comment|// Returns the size of this section in an executable memory image.
comment|// This may be smaller than the raw size (the raw size is multiple
comment|// of disk sector size, so there may be padding at end), or may be
comment|// larger (if that's the case, the loader reserves spaces after end
comment|// of raw data).
name|uint64_t
name|getVirtualSize
parameter_list|()
block|{
return|return
name|Header
operator|.
name|VirtualSize
return|;
block|}
comment|// Returns the size of the section in the output file.
name|uint64_t
name|getRawSize
parameter_list|()
block|{
return|return
name|Header
operator|.
name|SizeOfRawData
return|;
block|}
comment|// Set offset into the string table storing this section name.
comment|// Used only when the name is longer than 8 bytes.
name|void
name|setStringTableOff
parameter_list|(
name|uint32_t
name|V
parameter_list|)
block|{
name|StringTableOff
operator|=
name|V
expr_stmt|;
block|}
comment|// N.B. The section index is one based.
name|uint32_t
name|SectionIndex
init|=
literal|0
decl_stmt|;
name|private
label|:
name|llvm
operator|::
name|StringRef
name|Name
expr_stmt|;
name|llvm
operator|::
name|object
operator|::
name|coff_section
name|Header
expr_stmt|;
name|uint32_t
name|StringTableOff
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|*
operator|>
name|Chunks
expr_stmt|;
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


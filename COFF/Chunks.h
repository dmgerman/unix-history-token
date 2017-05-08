begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Chunks.h -------------------------------------------------*- C++ -*-===//
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
name|LLD_COFF_CHUNKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_COFF_CHUNKS_H
end_define

begin_include
include|#
directive|include
file|"Config.h"
end_include

begin_include
include|#
directive|include
file|"InputFiles.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/COFF.h"
end_include

begin_include
include|#
directive|include
file|<utility>
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
name|using
name|llvm
operator|::
name|COFF
operator|::
name|ImportDirectoryTableEntry
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|COFFSymbolRef
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|SectionRef
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|coff_relocation
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|coff_section
expr_stmt|;
name|class
name|Baserel
decl_stmt|;
name|class
name|Defined
decl_stmt|;
name|class
name|DefinedImportData
decl_stmt|;
name|class
name|DefinedRegular
decl_stmt|;
name|class
name|ObjectFile
decl_stmt|;
name|class
name|OutputSection
decl_stmt|;
name|class
name|SymbolBody
decl_stmt|;
comment|// Mask for section types (code, data, bss, disacardable, etc.)
comment|// and permissions (writable, readable or executable).
specifier|const
name|uint32_t
name|PermMask
init|=
literal|0xFF0000F0
decl_stmt|;
comment|// A Chunk represents a chunk of data that will occupy space in the
comment|// output (if the resolver chose that). It may or may not be backed by
comment|// a section of an input file. It could be linker-created data, or
comment|// doesn't even have actual data (if common or bss).
name|class
name|Chunk
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|SectionKind
block|,
name|OtherKind
block|}
enum|;
name|Kind
name|kind
argument_list|()
specifier|const
block|{
return|return
name|ChunkKind
return|;
block|}
name|virtual
operator|~
name|Chunk
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|// Returns the size of this chunk (even if this is a common or BSS.)
name|virtual
name|size_t
name|getSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Write this chunk to a mmap'ed file, assuming Buf is pointing to
comment|// beginning of the file. Because this function may use RVA values
comment|// of other chunks for relocations, you need to set them properly
comment|// before calling this function.
name|virtual
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
decl|const
block|{}
comment|// The writer sets and uses the addresses.
name|uint64_t
name|getRVA
argument_list|()
specifier|const
block|{
return|return
name|RVA
return|;
block|}
name|uint32_t
name|getAlign
argument_list|()
specifier|const
block|{
return|return
name|Align
return|;
block|}
name|void
name|setRVA
parameter_list|(
name|uint64_t
name|V
parameter_list|)
block|{
name|RVA
operator|=
name|V
expr_stmt|;
block|}
name|void
name|setOutputSectionOff
parameter_list|(
name|uint64_t
name|V
parameter_list|)
block|{
name|OutputSectionOff
operator|=
name|V
expr_stmt|;
block|}
comment|// Returns true if this has non-zero data. BSS chunks return
comment|// false. If false is returned, the space occupied by this chunk
comment|// will be filled with zeros.
name|virtual
name|bool
name|hasData
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|// Returns readable/writable/executable bits.
name|virtual
name|uint32_t
name|getPermissions
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|// Returns the section name if this is a section chunk.
comment|// It is illegal to call this function on non-section chunks.
name|virtual
name|StringRef
name|getSectionName
argument_list|()
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"unimplemented getSectionName"
argument_list|)
block|;   }
comment|// An output section has pointers to chunks in the section, and each
comment|// chunk has a back pointer to an output section.
name|void
name|setOutputSection
argument_list|(
argument|OutputSection *O
argument_list|)
block|{
name|Out
operator|=
name|O
block|; }
name|OutputSection
operator|*
name|getOutputSection
argument_list|()
block|{
return|return
name|Out
return|;
block|}
comment|// Windows-specific.
comment|// Collect all locations that contain absolute addresses for base relocations.
name|virtual
name|void
name|getBaserels
argument_list|(
name|std
operator|::
name|vector
operator|<
name|Baserel
operator|>
operator|*
name|Res
argument_list|)
block|{}
comment|// Returns a human-readable name of this chunk. Chunks are unnamed chunks of
comment|// bytes, so this is used only for logging or debugging.
name|virtual
name|StringRef
name|getDebugName
parameter_list|()
block|{
return|return
literal|""
return|;
block|}
name|protected
label|:
name|Chunk
argument_list|(
argument|Kind K = OtherKind
argument_list|)
block|:
name|ChunkKind
argument_list|(
argument|K
argument_list|)
block|{}
specifier|const
name|Kind
name|ChunkKind
decl_stmt|;
comment|// The RVA of this chunk in the output. The writer sets a value.
name|uint64_t
name|RVA
init|=
literal|0
decl_stmt|;
comment|// The offset from beginning of the output section. The writer sets a value.
name|uint64_t
name|OutputSectionOff
init|=
literal|0
decl_stmt|;
comment|// The output section for this chunk.
name|OutputSection
modifier|*
name|Out
init|=
name|nullptr
decl_stmt|;
comment|// The alignment of this chunk. The writer uses the value.
name|uint32_t
name|Align
init|=
literal|1
decl_stmt|;
block|}
empty_stmt|;
comment|// A chunk corresponding a section of an input file.
name|class
name|SectionChunk
range|:
name|public
name|Chunk
block|{
comment|// Identical COMDAT Folding feature accesses section internal data.
name|friend
name|class
name|ICF
block|;
name|public
operator|:
name|class
name|symbol_iterator
operator|:
name|public
name|llvm
operator|::
name|iterator_adaptor_base
operator|<
name|symbol_iterator
block|,
specifier|const
name|coff_relocation
operator|*
block|,
name|std
operator|::
name|random_access_iterator_tag
block|,
name|SymbolBody
operator|*
operator|>
block|{
name|friend
name|SectionChunk
block|;
name|ObjectFile
operator|*
name|File
block|;
name|symbol_iterator
argument_list|(
name|ObjectFile
operator|*
name|File
argument_list|,
specifier|const
name|coff_relocation
operator|*
name|I
argument_list|)
operator|:
name|symbol_iterator
operator|::
name|iterator_adaptor_base
argument_list|(
name|I
argument_list|)
block|,
name|File
argument_list|(
argument|File
argument_list|)
block|{}
name|public
operator|:
name|symbol_iterator
argument_list|()
operator|=
expr|default
block|;
name|SymbolBody
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|File
operator|->
name|getSymbolBody
argument_list|(
name|I
operator|->
name|SymbolTableIndex
argument_list|)
return|;
block|}
expr|}
block|;
name|SectionChunk
argument_list|(
name|ObjectFile
operator|*
name|File
argument_list|,
specifier|const
name|coff_section
operator|*
name|Header
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Chunk *C
argument_list|)
block|{
return|return
name|C
operator|->
name|kind
argument_list|()
operator|==
name|SectionKind
return|;
block|}
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Header
operator|->
name|SizeOfRawData
return|;
block|}
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|getContents
argument_list|()
specifier|const
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
specifier|const
name|override
block|;
name|bool
name|hasData
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getPermissions
argument_list|()
specifier|const
name|override
block|;
name|StringRef
name|getSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
name|SectionName
return|;
block|}
name|void
name|getBaserels
argument_list|(
argument|std::vector<Baserel> *Res
argument_list|)
name|override
block|;
name|bool
name|isCOMDAT
argument_list|()
specifier|const
block|;
name|void
name|applyRelX64
argument_list|(
argument|uint8_t *Off
argument_list|,
argument|uint16_t Type
argument_list|,
argument|Defined *Sym
argument_list|,
argument|uint64_t P
argument_list|)
specifier|const
block|;
name|void
name|applyRelX86
argument_list|(
argument|uint8_t *Off
argument_list|,
argument|uint16_t Type
argument_list|,
argument|Defined *Sym
argument_list|,
argument|uint64_t P
argument_list|)
specifier|const
block|;
name|void
name|applyRelARM
argument_list|(
argument|uint8_t *Off
argument_list|,
argument|uint16_t Type
argument_list|,
argument|Defined *Sym
argument_list|,
argument|uint64_t P
argument_list|)
specifier|const
block|;
comment|// Called if the garbage collector decides to not include this chunk
comment|// in a final output. It's supposed to print out a log message to stdout.
name|void
name|printDiscardedMessage
argument_list|()
specifier|const
block|;
comment|// Adds COMDAT associative sections to this COMDAT section. A chunk
comment|// and its children are treated as a group by the garbage collector.
name|void
name|addAssociative
argument_list|(
name|SectionChunk
operator|*
name|Child
argument_list|)
block|;
name|StringRef
name|getDebugName
argument_list|()
name|override
block|;
name|void
name|setSymbol
argument_list|(
argument|DefinedRegular *S
argument_list|)
block|{
if|if
condition|(
operator|!
name|Sym
condition|)
name|Sym
operator|=
name|S
expr_stmt|;
block|}
comment|// Used by the garbage collector.
name|bool
name|isLive
argument_list|()
block|{
return|return
operator|!
name|Config
operator|->
name|DoGC
operator|||
name|Live
return|;
block|}
name|void
name|markLive
argument_list|()
block|{
name|assert
argument_list|(
operator|!
name|isLive
argument_list|()
operator|&&
literal|"Cannot mark an already live section!"
argument_list|)
block|;
name|Live
operator|=
name|true
block|;   }
comment|// Allow iteration over the bodies of this chunk's relocated symbols.
name|llvm
operator|::
name|iterator_range
operator|<
name|symbol_iterator
operator|>
name|symbols
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|make_range
argument_list|(
name|symbol_iterator
argument_list|(
name|File
argument_list|,
name|Relocs
operator|.
name|begin
argument_list|()
argument_list|)
argument_list|,
name|symbol_iterator
argument_list|(
name|File
argument_list|,
name|Relocs
operator|.
name|end
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
comment|// Allow iteration over the associated child chunks for this section.
name|ArrayRef
operator|<
name|SectionChunk
operator|*
operator|>
name|children
argument_list|()
specifier|const
block|{
return|return
name|AssocChildren
return|;
block|}
comment|// A pointer pointing to a replacement for this chunk.
comment|// Initially it points to "this" object. If this chunk is merged
comment|// with other chunk by ICF, it points to another chunk,
comment|// and this chunk is considrered as dead.
name|SectionChunk
operator|*
name|Repl
block|;
comment|// The CRC of the contents as described in the COFF spec 4.5.5.
comment|// Auxiliary Format 5: Section Definitions. Used for ICF.
name|uint32_t
name|Checksum
operator|=
literal|0
block|;
specifier|const
name|coff_section
operator|*
name|Header
block|;
comment|// The file that this chunk was created from.
name|ObjectFile
operator|*
name|File
block|;
name|private
operator|:
name|StringRef
name|SectionName
block|;
name|std
operator|::
name|vector
operator|<
name|SectionChunk
operator|*
operator|>
name|AssocChildren
block|;
name|llvm
operator|::
name|iterator_range
operator|<
specifier|const
name|coff_relocation
operator|*
operator|>
name|Relocs
block|;
name|size_t
name|NumRelocs
block|;
comment|// Used by the garbage collector.
name|bool
name|Live
block|;
comment|// Used for ICF (Identical COMDAT Folding)
name|void
name|replace
argument_list|(
name|SectionChunk
operator|*
name|Other
argument_list|)
block|;
name|uint32_t
name|Class
index|[
literal|2
index|]
operator|=
block|{
literal|0
block|,
literal|0
block|}
block|;
comment|// Sym points to a section symbol if this is a COMDAT chunk.
name|DefinedRegular
operator|*
name|Sym
operator|=
name|nullptr
block|; }
block|;
comment|// A chunk for common symbols. Common chunks don't have actual data.
name|class
name|CommonChunk
operator|:
name|public
name|Chunk
block|{
name|public
operator|:
name|CommonChunk
argument_list|(
argument|const COFFSymbolRef Sym
argument_list|)
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Sym
operator|.
name|getValue
argument_list|()
return|;
block|}
name|bool
name|hasData
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|uint32_t
name|getPermissions
argument_list|()
specifier|const
name|override
block|;
name|StringRef
name|getSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|".bss"
return|;
block|}
name|private
operator|:
specifier|const
name|COFFSymbolRef
name|Sym
block|; }
block|;
comment|// A chunk for linker-created strings.
name|class
name|StringChunk
operator|:
name|public
name|Chunk
block|{
name|public
operator|:
name|explicit
name|StringChunk
argument_list|(
argument|StringRef S
argument_list|)
operator|:
name|Str
argument_list|(
argument|S
argument_list|)
block|{}
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Str
operator|.
name|size
argument_list|()
operator|+
literal|1
return|;
block|}
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|StringRef
name|Str
block|; }
block|;
specifier|static
specifier|const
name|uint8_t
name|ImportThunkX86
index|[]
operator|=
block|{
literal|0xff
block|,
literal|0x25
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// JMP *0x0
block|}
block|;
specifier|static
specifier|const
name|uint8_t
name|ImportThunkARM
index|[]
operator|=
block|{
literal|0x40
block|,
literal|0xf2
block|,
literal|0x00
block|,
literal|0x0c
block|,
comment|// mov.w ip, #0
literal|0xc0
block|,
literal|0xf2
block|,
literal|0x00
block|,
literal|0x0c
block|,
comment|// mov.t ip, #0
literal|0xdc
block|,
literal|0xf8
block|,
literal|0x00
block|,
literal|0xf0
block|,
comment|// ldr.w pc, [ip]
block|}
block|;
comment|// Windows-specific.
comment|// A chunk for DLL import jump table entry. In a final output, it's
comment|// contents will be a JMP instruction to some __imp_ symbol.
name|class
name|ImportThunkChunkX64
operator|:
name|public
name|Chunk
block|{
name|public
operator|:
name|explicit
name|ImportThunkChunkX64
argument_list|(
name|Defined
operator|*
name|S
argument_list|)
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
sizeof|sizeof
argument_list|(
name|ImportThunkX86
argument_list|)
return|;
block|}
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|Defined
operator|*
name|ImpSymbol
block|; }
block|;
name|class
name|ImportThunkChunkX86
operator|:
name|public
name|Chunk
block|{
name|public
operator|:
name|explicit
name|ImportThunkChunkX86
argument_list|(
name|Defined
operator|*
name|S
argument_list|)
operator|:
name|ImpSymbol
argument_list|(
argument|S
argument_list|)
block|{}
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
sizeof|sizeof
argument_list|(
name|ImportThunkX86
argument_list|)
return|;
block|}
name|void
name|getBaserels
argument_list|(
argument|std::vector<Baserel> *Res
argument_list|)
name|override
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|Defined
operator|*
name|ImpSymbol
block|; }
block|;
name|class
name|ImportThunkChunkARM
operator|:
name|public
name|Chunk
block|{
name|public
operator|:
name|explicit
name|ImportThunkChunkARM
argument_list|(
name|Defined
operator|*
name|S
argument_list|)
operator|:
name|ImpSymbol
argument_list|(
argument|S
argument_list|)
block|{}
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
sizeof|sizeof
argument_list|(
name|ImportThunkARM
argument_list|)
return|;
block|}
name|void
name|getBaserels
argument_list|(
argument|std::vector<Baserel> *Res
argument_list|)
name|override
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|Defined
operator|*
name|ImpSymbol
block|; }
block|;
comment|// Windows-specific.
comment|// See comments for DefinedLocalImport class.
name|class
name|LocalImportChunk
operator|:
name|public
name|Chunk
block|{
name|public
operator|:
name|explicit
name|LocalImportChunk
argument_list|(
name|Defined
operator|*
name|S
argument_list|)
operator|:
name|Sym
argument_list|(
argument|S
argument_list|)
block|{}
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|;
name|void
name|getBaserels
argument_list|(
argument|std::vector<Baserel> *Res
argument_list|)
name|override
block|;
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|Defined
operator|*
name|Sym
block|; }
block|;
comment|// Windows-specific.
comment|// A chunk for SEH table which contains RVAs of safe exception handler
comment|// functions. x86-only.
name|class
name|SEHTableChunk
operator|:
name|public
name|Chunk
block|{
name|public
operator|:
name|explicit
name|SEHTableChunk
argument_list|(
name|std
operator|::
name|set
operator|<
name|Defined
operator|*
operator|>
name|S
argument_list|)
operator|:
name|Syms
argument_list|(
argument|std::move(S)
argument_list|)
block|{}
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Syms
operator|.
name|size
argument_list|()
operator|*
literal|4
return|;
block|}
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|std
operator|::
name|set
operator|<
name|Defined
operator|*
operator|>
name|Syms
block|; }
block|;
comment|// Windows-specific.
comment|// This class represents a block in .reloc section.
comment|// See the PE/COFF spec 5.6 for details.
name|class
name|BaserelChunk
operator|:
name|public
name|Chunk
block|{
name|public
operator|:
name|BaserelChunk
argument_list|(
argument|uint32_t Page
argument_list|,
argument|Baserel *Begin
argument_list|,
argument|Baserel *End
argument_list|)
block|;
name|size_t
name|getSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|Data
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|writeTo
argument_list|(
argument|uint8_t *Buf
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|Data
block|; }
block|;
name|class
name|Baserel
block|{
name|public
operator|:
name|Baserel
argument_list|(
argument|uint32_t V
argument_list|,
argument|uint8_t Ty
argument_list|)
operator|:
name|RVA
argument_list|(
name|V
argument_list|)
block|,
name|Type
argument_list|(
argument|Ty
argument_list|)
block|{}
name|explicit
name|Baserel
argument_list|(
argument|uint32_t V
argument_list|)
operator|:
name|Baserel
argument_list|(
argument|V
argument_list|,
argument|getDefaultType()
argument_list|)
block|{}
name|uint8_t
name|getDefaultType
argument_list|()
block|;
name|uint32_t
name|RVA
block|;
name|uint8_t
name|Type
block|; }
block|;  }
comment|// namespace coff
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


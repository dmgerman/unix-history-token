begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InputFiles.h ---------------------------------------------*- C++ -*-===//
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
name|LLD_COFF_INPUT_FILES_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_COFF_INPUT_FILES_H
end_define

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
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/LTO/LTO.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/Archive.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/COFF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/StringSaver.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<set>
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
name|IMAGE_FILE_MACHINE_UNKNOWN
expr_stmt|;
name|using
name|llvm
operator|::
name|COFF
operator|::
name|MachineTypes
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|Archive
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|COFFObjectFile
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
name|coff_import_header
expr_stmt|;
name|using
name|llvm
operator|::
name|object
operator|::
name|coff_section
expr_stmt|;
name|class
name|Chunk
decl_stmt|;
name|class
name|Defined
decl_stmt|;
name|class
name|DefinedImportData
decl_stmt|;
name|class
name|DefinedImportThunk
decl_stmt|;
name|class
name|Lazy
decl_stmt|;
name|class
name|SectionChunk
decl_stmt|;
struct_decl|struct
name|Symbol
struct_decl|;
name|class
name|SymbolBody
decl_stmt|;
name|class
name|Undefined
decl_stmt|;
comment|// The root class of input files.
name|class
name|InputFile
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|ArchiveKind
block|,
name|ObjectKind
block|,
name|ImportKind
block|,
name|BitcodeKind
block|}
enum|;
name|Kind
name|kind
argument_list|()
specifier|const
block|{
return|return
name|FileKind
return|;
block|}
name|virtual
operator|~
name|InputFile
argument_list|()
block|{}
comment|// Returns the filename.
name|StringRef
name|getName
argument_list|()
block|{
return|return
name|MB
operator|.
name|getBufferIdentifier
argument_list|()
return|;
block|}
comment|// Reads a file (the constructor doesn't do that).
name|virtual
name|void
name|parse
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Returns the CPU type this file was compiled to.
name|virtual
name|MachineTypes
name|getMachineType
parameter_list|()
block|{
return|return
name|IMAGE_FILE_MACHINE_UNKNOWN
return|;
block|}
name|MemoryBufferRef
name|MB
decl_stmt|;
comment|// An archive file name if this file is created from an archive.
name|StringRef
name|ParentName
decl_stmt|;
comment|// Returns .drectve section contents if exist.
name|StringRef
name|getDirectives
parameter_list|()
block|{
return|return
name|StringRef
argument_list|(
name|Directives
argument_list|)
operator|.
name|trim
argument_list|()
return|;
block|}
name|protected
label|:
name|InputFile
argument_list|(
argument|Kind K
argument_list|,
argument|MemoryBufferRef M
argument_list|)
block|:
name|MB
argument_list|(
name|M
argument_list|)
operator|,
name|FileKind
argument_list|(
argument|K
argument_list|)
block|{}
name|std
operator|::
name|string
name|Directives
expr_stmt|;
name|private
label|:
specifier|const
name|Kind
name|FileKind
decl_stmt|;
block|}
empty_stmt|;
comment|// .lib or .a file.
name|class
name|ArchiveFile
range|:
name|public
name|InputFile
block|{
name|public
operator|:
name|explicit
name|ArchiveFile
argument_list|(
argument|MemoryBufferRef M
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const InputFile *F
argument_list|)
block|{
return|return
name|F
operator|->
name|kind
argument_list|()
operator|==
name|ArchiveKind
return|;
block|}
name|void
name|parse
argument_list|()
name|override
block|;
comment|// Enqueues an archive member load for the given symbol. If we've already
comment|// enqueued a load for the same archive member, this function does nothing,
comment|// which ensures that we don't load the same member more than once.
name|void
name|addMember
argument_list|(
specifier|const
name|Archive
operator|::
name|Symbol
operator|*
name|Sym
argument_list|)
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|Archive
operator|>
name|File
block|;
name|std
operator|::
name|string
name|Filename
block|;
name|llvm
operator|::
name|DenseSet
operator|<
name|uint64_t
operator|>
name|Seen
block|; }
decl_stmt|;
comment|// .obj or .o file. This may be a member of an archive file.
name|class
name|ObjectFile
range|:
name|public
name|InputFile
block|{
name|public
operator|:
name|explicit
name|ObjectFile
argument_list|(
argument|MemoryBufferRef M
argument_list|)
operator|:
name|InputFile
argument_list|(
argument|ObjectKind
argument_list|,
argument|M
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const InputFile *F
argument_list|)
block|{
return|return
name|F
operator|->
name|kind
argument_list|()
operator|==
name|ObjectKind
return|;
block|}
name|void
name|parse
argument_list|()
name|override
block|;
name|MachineTypes
name|getMachineType
argument_list|()
name|override
block|;
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
name|std
operator|::
name|vector
operator|<
name|SectionChunk
operator|*
operator|>
operator|&
name|getDebugChunks
argument_list|()
block|{
return|return
name|DebugChunks
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|SymbolBody
operator|*
operator|>
operator|&
name|getSymbols
argument_list|()
block|{
return|return
name|SymbolBodies
return|;
block|}
comment|// Returns a SymbolBody object for the SymbolIndex'th symbol in the
comment|// underlying object file.
name|SymbolBody
operator|*
name|getSymbolBody
argument_list|(
argument|uint32_t SymbolIndex
argument_list|)
block|{
return|return
name|SparseSymbolBodies
index|[
name|SymbolIndex
index|]
return|;
block|}
comment|// Returns the underying COFF file.
name|COFFObjectFile
operator|*
name|getCOFFObj
argument_list|()
block|{
return|return
name|COFFObj
operator|.
name|get
argument_list|()
return|;
block|}
comment|// True if this object file is compatible with SEH.
comment|// COFF-specific and x86-only.
name|bool
name|SEHCompat
operator|=
name|false
block|;
comment|// The list of safe exception handlers listed in .sxdata section.
comment|// COFF-specific and x86-only.
name|std
operator|::
name|set
operator|<
name|SymbolBody
operator|*
operator|>
name|SEHandlers
block|;
name|private
operator|:
name|void
name|initializeChunks
argument_list|()
block|;
name|void
name|initializeSymbols
argument_list|()
block|;
name|void
name|initializeSEH
argument_list|()
block|;
name|SymbolBody
operator|*
name|createDefined
argument_list|(
argument|COFFSymbolRef Sym
argument_list|,
argument|const void *Aux
argument_list|,
argument|bool IsFirst
argument_list|)
block|;
name|SymbolBody
operator|*
name|createUndefined
argument_list|(
argument|COFFSymbolRef Sym
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|COFFObjectFile
operator|>
name|COFFObj
block|;
name|llvm
operator|::
name|BumpPtrAllocator
name|Alloc
block|;
specifier|const
name|coff_section
operator|*
name|SXData
operator|=
name|nullptr
block|;
comment|// List of all chunks defined by this file. This includes both section
comment|// chunks and non-section chunks for common symbols.
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|*
operator|>
name|Chunks
block|;
comment|// CodeView debug info sections.
name|std
operator|::
name|vector
operator|<
name|SectionChunk
operator|*
operator|>
name|DebugChunks
block|;
comment|// This vector contains the same chunks as Chunks, but they are
comment|// indexed such that you can get a SectionChunk by section index.
comment|// Nonexistent section indices are filled with null pointers.
comment|// (Because section number is 1-based, the first slot is always a
comment|// null pointer.)
name|std
operator|::
name|vector
operator|<
name|Chunk
operator|*
operator|>
name|SparseChunks
block|;
comment|// List of all symbols referenced or defined by this file.
name|std
operator|::
name|vector
operator|<
name|SymbolBody
operator|*
operator|>
name|SymbolBodies
block|;
comment|// This vector contains the same symbols as SymbolBodies, but they
comment|// are indexed such that you can get a SymbolBody by symbol
comment|// index. Nonexistent indices (which are occupied by auxiliary
comment|// symbols in the real symbol table) are filled with null pointers.
name|std
operator|::
name|vector
operator|<
name|SymbolBody
operator|*
operator|>
name|SparseSymbolBodies
block|; }
decl_stmt|;
comment|// This type represents import library members that contain DLL names
comment|// and symbols exported from the DLLs. See Microsoft PE/COFF spec. 7
comment|// for details about the format.
name|class
name|ImportFile
range|:
name|public
name|InputFile
block|{
name|public
operator|:
name|explicit
name|ImportFile
argument_list|(
argument|MemoryBufferRef M
argument_list|)
operator|:
name|InputFile
argument_list|(
name|ImportKind
argument_list|,
name|M
argument_list|)
block|,
name|StringAlloc
argument_list|(
argument|StringAllocAux
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const InputFile *F
argument_list|)
block|{
return|return
name|F
operator|->
name|kind
argument_list|()
operator|==
name|ImportKind
return|;
block|}
name|DefinedImportData
operator|*
name|ImpSym
operator|=
name|nullptr
block|;
name|DefinedImportData
operator|*
name|ConstSym
operator|=
name|nullptr
block|;
name|DefinedImportThunk
operator|*
name|ThunkSym
operator|=
name|nullptr
block|;
name|std
operator|::
name|string
name|DLLName
block|;
name|private
operator|:
name|void
name|parse
argument_list|()
name|override
block|;
name|llvm
operator|::
name|BumpPtrAllocator
name|StringAllocAux
block|;
name|llvm
operator|::
name|StringSaver
name|StringAlloc
block|;
name|public
operator|:
name|StringRef
name|ExternalName
block|;
specifier|const
name|coff_import_header
operator|*
name|Hdr
block|;
name|Chunk
operator|*
name|Location
operator|=
name|nullptr
block|; }
decl_stmt|;
comment|// Used for LTO.
name|class
name|BitcodeFile
range|:
name|public
name|InputFile
block|{
name|public
operator|:
name|explicit
name|BitcodeFile
argument_list|(
argument|MemoryBufferRef M
argument_list|)
operator|:
name|InputFile
argument_list|(
argument|BitcodeKind
argument_list|,
argument|M
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const InputFile *F
argument_list|)
block|{
return|return
name|F
operator|->
name|kind
argument_list|()
operator|==
name|BitcodeKind
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|SymbolBody
operator|*
operator|>
operator|&
name|getSymbols
argument_list|()
block|{
return|return
name|SymbolBodies
return|;
block|}
name|MachineTypes
name|getMachineType
argument_list|()
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|lto
operator|::
name|InputFile
operator|>
name|Obj
block|;
name|private
operator|:
name|void
name|parse
argument_list|()
name|override
block|;
name|std
operator|::
name|vector
operator|<
name|SymbolBody
operator|*
operator|>
name|SymbolBodies
block|; }
decl_stmt|;
block|}
comment|// namespace coff
name|std
operator|::
name|string
name|toString
argument_list|(
name|coff
operator|::
name|InputFile
operator|*
name|File
argument_list|)
expr_stmt|;
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


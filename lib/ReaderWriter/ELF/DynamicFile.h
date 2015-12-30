begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/DynamicFile.h ---------------------------------===//
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
name|LLD_READER_WRITER_ELF_DYNAMIC_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_DYNAMIC_FILE_H
end_define

begin_include
include|#
directive|include
file|"Atoms.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/SharedLibraryFile.h"
end_include

begin_include
include|#
directive|include
file|<unordered_map>
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
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|DynamicFile
operator|:
name|public
name|SharedLibraryFile
block|{
name|public
operator|:
name|DynamicFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|mb
argument_list|,
name|ELFLinkingContext
operator|&
name|ctx
argument_list|)
block|;
specifier|static
name|std
operator|::
name|error_code
name|isCompatible
argument_list|(
argument|MemoryBufferRef mb
argument_list|,
argument|ELFLinkingContext&ctx
argument_list|)
block|;
specifier|const
name|SharedLibraryAtom
operator|*
name|exports
argument_list|(
argument|StringRef name
argument_list|,
argument|bool dataSymbolOnly
argument_list|)
specifier|const
name|override
block|;
name|StringRef
name|getDSOName
argument_list|()
specifier|const
name|override
block|;
specifier|static
name|bool
name|canParse
argument_list|(
argument|file_magic magic
argument_list|)
block|;
name|protected
operator|:
name|std
operator|::
name|error_code
name|doParse
argument_list|()
name|override
block|;
name|private
operator|:
name|mutable
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>>
name|_objFile
block|;
comment|/// \brief DT_SONAME
name|StringRef
name|_soname
block|;    struct
name|SymAtomPair
block|{
specifier|const
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Sym
operator|*
name|_symbol
operator|=
name|nullptr
block|;
specifier|const
name|SharedLibraryAtom
operator|*
name|_atom
operator|=
name|nullptr
block|;   }
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|_mb
block|;
name|ELFLinkingContext
operator|&
name|_ctx
block|;
name|bool
name|_useShlibUndefines
block|;
name|mutable
name|std
operator|::
name|unordered_map
operator|<
name|StringRef
block|,
name|SymAtomPair
operator|>
name|_nameToSym
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


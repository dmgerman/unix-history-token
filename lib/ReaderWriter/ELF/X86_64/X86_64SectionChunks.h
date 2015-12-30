begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/X86_64/X86_64SectionChunks.h ----------------===//
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
name|LLD_READER_WRITER_ELF_X86_64_X86_64_SECTION_CHUNKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_X86_64_X86_64_SECTION_CHUNKS_H
end_define

begin_include
include|#
directive|include
file|"TargetLayout.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|X86_64GOTSection
range|:
name|public
name|AtomSection
operator|<
name|ELF64LE
operator|>
block|{
name|public
operator|:
name|X86_64GOTSection
argument_list|(
specifier|const
name|ELFLinkingContext
operator|&
name|ctx
argument_list|)
block|;
name|bool
name|hasGlobalGOTEntry
argument_list|(
argument|const Atom *a
argument_list|)
specifier|const
block|{
return|return
name|_tlsMap
operator|.
name|count
argument_list|(
name|a
argument_list|)
return|;
block|}
specifier|const
name|AtomLayout
operator|*
name|appendAtom
argument_list|(
argument|const Atom *atom
argument_list|)
name|override
block|;
name|private
operator|:
comment|/// \brief Map TLS Atoms to their GOT entry index.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Atom
operator|*
block|,
name|std
operator|::
name|size_t
operator|>
name|_tlsMap
block|; }
decl_stmt|;
block|}
comment|// elf
block|}
end_decl_stmt

begin_comment
comment|// lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


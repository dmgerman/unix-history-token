begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/Writer.h --------------------------------------===//
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
name|LLD_READER_WRITER_ELF_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_WRITER_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/File.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Writer.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|/// \brief The Writer class is a base class for the linker to write
comment|///        various kinds of ELF files.
name|class
name|ELFWriter
range|:
name|public
name|Writer
block|{
name|public
operator|:
comment|/// \brief builds the chunks that needs to be written to the output
comment|///        ELF file
name|virtual
name|void
name|buildChunks
argument_list|(
specifier|const
name|File
operator|&
name|file
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief Writes the chunks into the output file specified by path
name|std
operator|::
name|error_code
name|writeFile
argument_list|(
argument|const File&file
argument_list|,
argument|StringRef path
argument_list|)
name|override
operator|=
literal|0
block|;
comment|/// \brief Get the virtual address of \p atom after layout.
name|virtual
name|uint64_t
name|addressOfAtom
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
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

begin_comment
comment|// LLD_READER_WRITER_ELF_WRITER_H
end_comment

end_unit


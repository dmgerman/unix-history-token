begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/PECOFF/EdataPass.h --------------------------------===//
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file \brief This linker pass creates atoms for the DLL export
end_comment

begin_comment
comment|/// information. The defined atoms constructed in this pass will go into .edata
end_comment

begin_comment
comment|/// section.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For the details of the .edata section format, see Microsoft PE/COFF
end_comment

begin_comment
comment|/// Specification section 5.3, The .edata Section.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_PE_COFF_EDATA_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_PE_COFF_EDATA_PASS_H
end_define

begin_include
include|#
directive|include
file|"Atoms.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/File.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Pass.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Simple.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/PECOFFLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/COFF.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_expr_stmt
name|using
name|llvm
operator|::
name|COFF
operator|::
name|ImportDirectoryTableEntry
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|pecoff
block|{
name|namespace
name|edata
block|{
struct|struct
name|TableEntry
block|{
name|TableEntry
argument_list|(
argument|StringRef exp
argument_list|,
argument|int ord
argument_list|,
argument|const DefinedAtom *a
argument_list|,
argument|bool n
argument_list|)
block|:
name|exportName
argument_list|(
name|exp
argument_list|)
operator|,
name|ordinal
argument_list|(
name|ord
argument_list|)
operator|,
name|atom
argument_list|(
name|a
argument_list|)
operator|,
name|noname
argument_list|(
argument|n
argument_list|)
block|{}
name|std
operator|::
name|string
name|exportName
expr_stmt|;
name|int
name|ordinal
decl_stmt|;
specifier|const
name|DefinedAtom
modifier|*
name|atom
decl_stmt|;
name|bool
name|noname
decl_stmt|;
block|}
struct|;
comment|/// The root class of all edata atoms.
name|class
name|EdataAtom
range|:
name|public
name|COFFLinkerInternalAtom
block|{
name|public
operator|:
name|EdataAtom
argument_list|(
argument|VirtualFile&file
argument_list|,
argument|size_t size
argument_list|)
operator|:
name|COFFLinkerInternalAtom
argument_list|(
argument|file
argument_list|,
argument|file.getNextOrdinal()
argument_list|,
argument|std::vector<uint8_t>(size)
argument_list|)
block|{}
name|SectionChoice
name|sectionChoice
argument_list|()
specifier|const
name|override
block|{
return|return
name|sectionCustomRequired
return|;
block|}
name|StringRef
name|customSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|".edata"
return|;
block|}
name|ContentType
name|contentType
argument_list|()
specifier|const
name|override
block|{
return|return
name|typeData
return|;
block|}
name|ContentPermissions
name|permissions
argument_list|()
specifier|const
name|override
block|{
return|return
name|permR__
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|getContents
argument_list|()
specifier|const
block|{
return|return
operator|(
name|T
operator|*
operator|)
name|const_cast
operator|<
name|uint8_t
operator|*
operator|>
operator|(
name|rawContent
argument_list|()
operator|.
name|data
argument_list|()
operator|)
return|;
block|}
expr|}
block|;  }
comment|// namespace edata
name|class
name|EdataPass
operator|:
name|public
name|lld
operator|::
name|Pass
block|{
name|public
operator|:
name|EdataPass
argument_list|(
name|PECOFFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|_ctx
argument_list|(
name|ctx
argument_list|)
block|,
name|_file
argument_list|(
name|ctx
argument_list|)
block|,
name|_is64
argument_list|(
name|ctx
operator|.
name|is64Bit
argument_list|()
argument_list|)
block|,
name|_stringOrdinal
argument_list|(
literal|1024
argument_list|)
block|{}
name|void
name|perform
argument_list|(
argument|std::unique_ptr<MutableFile>&file
argument_list|)
name|override
block|;
name|private
operator|:
name|edata
operator|::
name|EdataAtom
operator|*
name|createExportDirectoryTable
argument_list|(
argument|const std::vector<edata::TableEntry>&namedEntries
argument_list|,
argument|int ordinalBase
argument_list|,
argument|int maxOrdinal
argument_list|)
block|;
name|edata
operator|::
name|EdataAtom
operator|*
name|createAddressTable
argument_list|(
argument|const std::vector<edata::TableEntry>&entries
argument_list|,
argument|int ordinalBase
argument_list|,
argument|int maxOrdinal
argument_list|)
block|;
name|edata
operator|::
name|EdataAtom
operator|*
name|createNamePointerTable
argument_list|(
specifier|const
name|PECOFFLinkingContext
operator|&
name|ctx
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|edata
operator|::
name|TableEntry
operator|>
operator|&
name|entries
argument_list|,
name|MutableFile
operator|*
name|file
argument_list|)
block|;
name|edata
operator|::
name|EdataAtom
operator|*
name|createOrdinalTable
argument_list|(
argument|const std::vector<edata::TableEntry>&entries
argument_list|,
argument|int ordinalBase
argument_list|)
block|;
name|PECOFFLinkingContext
operator|&
name|_ctx
block|;
name|VirtualFile
name|_file
block|;
name|bool
name|_is64
block|;
name|int
name|_stringOrdinal
block|;
name|mutable
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
block|; }
decl_stmt|;
block|}
comment|// namespace pecoff
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


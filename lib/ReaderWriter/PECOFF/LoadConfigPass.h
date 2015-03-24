begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/PECOFF/LoadConfigPass.h ---------------------------===//
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
comment|/// \file \brief This linker pass creates an atom for Load Configuration
end_comment

begin_comment
comment|/// structure.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For the details of the Load Configuration structure, see Microsoft PE/COFF
end_comment

begin_comment
comment|/// Specification section 5.8. The Load Configuration Structure (Image Only).
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
name|LLD_READER_WRITER_PE_COFF_LOAD_CONFIG_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_PE_COFF_LOAD_CONFIG_PASS_H
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
file|<map>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|pecoff
block|{
name|namespace
name|loadcfg
block|{
name|class
name|LoadConfigAtom
range|:
name|public
name|COFFLinkerInternalAtom
block|{
name|public
operator|:
name|LoadConfigAtom
argument_list|(
argument|VirtualFile&file
argument_list|,
argument|const DefinedAtom *sxdata
argument_list|,
argument|int count
argument_list|)
block|;
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
literal|".loadcfg"
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
comment|// namespace loadcfg
name|class
name|LoadConfigPass
operator|:
name|public
name|lld
operator|::
name|Pass
block|{
name|public
operator|:
name|LoadConfigPass
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
argument|ctx
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
name|PECOFFLinkingContext
operator|&
name|_ctx
block|;
name|VirtualFile
name|_file
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


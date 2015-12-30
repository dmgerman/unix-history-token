begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/Mips/MipsTargetLayout.h -----------------------===//
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
name|LLD_READER_WRITER_ELF_MIPS_MIPS_TARGET_LAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_MIPS_MIPS_TARGET_LAYOUT_H
end_define

begin_include
include|#
directive|include
file|"MipsAbiInfoHandler.h"
end_include

begin_include
include|#
directive|include
file|"MipsSectionChunks.h"
end_include

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
name|MipsLinkingContext
decl_stmt|;
comment|/// \brief TargetLayout for Mips
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|MipsTargetLayout
name|final
operator|:
name|public
name|TargetLayout
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
expr|enum
name|MipsSectionOrder
block|{
name|ORDER_MIPS_ABI_FLAGS
operator|=
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|::
name|ORDER_RO_NOTE
operator|+
literal|1
block|,
name|ORDER_MIPS_REGINFO
block|,
name|ORDER_MIPS_OPTIONS
block|,   }
block|;
name|MipsTargetLayout
argument_list|(
name|MipsLinkingContext
operator|&
name|ctx
argument_list|,
name|MipsAbiInfoHandler
operator|<
name|ELFT
operator|>
operator|&
name|abi
argument_list|)
block|;
specifier|const
name|MipsGOTSection
operator|<
name|ELFT
operator|>
operator|&
name|getGOTSection
argument_list|()
specifier|const
block|{
return|return
operator|*
name|_gotSection
return|;
block|}
specifier|const
name|MipsPLTSection
operator|<
name|ELFT
operator|>
operator|&
name|getPLTSection
argument_list|()
specifier|const
block|{
return|return
operator|*
name|_pltSection
return|;
block|}
name|AtomSection
operator|<
name|ELFT
operator|>
operator|*
name|createSection
argument_list|(
argument|StringRef name
argument_list|,
argument|int32_t type
argument_list|,
argument|DefinedAtom::ContentPermissions permissions
argument_list|,
argument|typename TargetLayout<ELFT>::SectionOrder order
argument_list|)
name|override
block|;
name|typename
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|::
name|SegmentType
name|getSegmentType
argument_list|(
argument|const Section<ELFT> *section
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief GP offset relative to .got section.
name|uint64_t
name|getGPOffset
argument_list|()
specifier|const
block|{
return|return
literal|0x7FF0
return|;
block|}
comment|/// \brief Get '_gp' symbol address.
name|uint64_t
name|getGPAddr
argument_list|()
block|;
comment|/// \brief Return the section order for a input section
name|typename
name|TargetLayout
operator|<
name|ELFT
operator|>
operator|::
name|SectionOrder
name|getSectionOrder
argument_list|(
argument|StringRef name
argument_list|,
argument|int32_t contentType
argument_list|,
argument|int32_t contentPermissions
argument_list|)
name|override
block|;
name|protected
operator|:
name|unique_bump_ptr
operator|<
name|RelocationTable
operator|<
name|ELFT
operator|>>
name|createRelocationTable
argument_list|(
argument|StringRef name
argument_list|,
argument|int32_t order
argument_list|)
name|override
block|;
name|uint64_t
name|getLookupSectionFlags
argument_list|(
argument|const OutputSection<ELFT> *os
argument_list|)
specifier|const
name|override
block|;
name|void
name|sortSegments
argument_list|()
name|override
block|;
name|private
operator|:
name|MipsAbiInfoHandler
operator|<
name|ELFT
operator|>
operator|&
name|_abiInfo
block|;
name|MipsGOTSection
operator|<
name|ELFT
operator|>
operator|*
name|_gotSection
block|;
name|MipsPLTSection
operator|<
name|ELFT
operator|>
operator|*
name|_pltSection
block|;
name|uint64_t
name|_gpAddr
operator|=
literal|0
block|;
name|std
operator|::
name|once_flag
name|_gpOnce
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


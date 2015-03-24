begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/TargetLayout.h --------------------------------===//
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
name|LLD_READER_WRITER_ELF_TARGET_LAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_TARGET_LAYOUT_H
end_define

begin_include
include|#
directive|include
file|"DefaultLayout.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|/// \brief The target can override certain functions in the DefaultLayout
comment|/// class so that the order, the name of the section and the segment type could
comment|/// be changed in the final layout
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|TargetLayout
operator|:
name|public
name|DefaultLayout
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|TargetLayout
argument_list|(
name|ELFLinkingContext
operator|&
name|context
argument_list|)
operator|:
name|DefaultLayout
operator|<
name|ELFT
operator|>
operator|(
name|context
operator|)
block|{}
block|}
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


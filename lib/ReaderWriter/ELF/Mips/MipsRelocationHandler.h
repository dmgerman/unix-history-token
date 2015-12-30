begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/ReaderWriter/ELF/Mips/MipsRelocationHandler.h ------------------===//
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
name|LLD_READER_WRITER_ELF_MIPS_MIPS_RELOCATION_HANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_MIPS_MIPS_RELOCATION_HANDLER_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/Reference.h"
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
name|template
operator|<
name|typename
name|ELFT
operator|>
name|class
name|MipsTargetLayout
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|std
operator|::
name|unique_ptr
operator|<
name|TargetRelocationHandler
operator|>
name|createMipsRelocationHandler
argument_list|(
name|MipsLinkingContext
operator|&
name|ctx
argument_list|,
name|MipsTargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|layout
argument_list|)
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|Reference
operator|::
name|Addend
name|readMipsRelocAddend
argument_list|(
argument|Reference::KindValue kind
argument_list|,
argument|const uint8_t *content
argument_list|)
expr_stmt|;
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


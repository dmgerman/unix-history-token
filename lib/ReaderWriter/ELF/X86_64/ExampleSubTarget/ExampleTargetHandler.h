begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/X86_64/ExampleTarget/ExampleTargetHandler.h ---===//
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
name|LLD_READER_WRITER_ELF_X86_64_EXAMPLE_TARGET_EXAMPLE_TARGET_HANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_X86_64_EXAMPLE_TARGET_EXAMPLE_TARGET_HANDLER_H
end_define

begin_include
include|#
directive|include
file|"X86_64TargetHandler.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|ExampleLinkingContext
decl_stmt|;
name|class
name|ExampleTargetHandler
name|final
range|:
name|public
name|X86_64TargetHandler
block|{
name|public
operator|:
name|ExampleTargetHandler
argument_list|(
name|ExampleLinkingContext
operator|&
name|c
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|Writer
operator|>
name|getWriter
argument_list|()
name|override
block|;
name|private
operator|:
name|ExampleLinkingContext
operator|&
name|_ctx
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

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/X86/X86TargetHandler.h ------------------------===//
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
name|LLD_READER_WRITER_ELF_X86_TARGET_HANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_X86_TARGET_HANDLER_H
end_define

begin_include
include|#
directive|include
file|"TargetLayout.h"
end_include

begin_include
include|#
directive|include
file|"ELFReader.h"
end_include

begin_include
include|#
directive|include
file|"X86RelocationHandler.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|X86LinkingContext
decl_stmt|;
name|class
name|X86TargetHandler
name|final
range|:
name|public
name|TargetHandler
block|{
name|public
operator|:
name|X86TargetHandler
argument_list|(
name|X86LinkingContext
operator|&
name|ctx
argument_list|)
block|;
specifier|const
name|TargetRelocationHandler
operator|&
name|getRelocationHandler
argument_list|()
specifier|const
name|override
block|{
return|return
operator|*
name|_relocationHandler
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|Reader
operator|>
name|getObjReader
argument_list|()
name|override
block|{
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|ELFReader
operator|<
name|ELFFile
operator|<
name|ELF32LE
operator|>>>
operator|(
name|_ctx
operator|)
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|Reader
operator|>
name|getDSOReader
argument_list|()
name|override
block|{
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|ELFReader
operator|<
name|DynamicFile
operator|<
name|ELF32LE
operator|>>>
operator|(
name|_ctx
operator|)
return|;
block|}
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
name|protected
operator|:
name|X86LinkingContext
operator|&
name|_ctx
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|TargetLayout
operator|<
name|ELF32LE
operator|>>
name|_targetLayout
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|X86TargetRelocationHandler
operator|>
name|_relocationHandler
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


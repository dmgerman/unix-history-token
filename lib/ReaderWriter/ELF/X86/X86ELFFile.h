begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/X86/X86ELFFile.h ------------------------------===//
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
name|LLD_READER_WRITER_ELF_X86_X86_ELF_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_X86_X86_ELF_FILE_H
end_define

begin_include
include|#
directive|include
file|"ELFReader.h"
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
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|X86ELFFile
operator|:
name|public
name|ELFFile
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|X86ELFFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|mb
argument_list|,
name|X86LinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|ELFFile
operator|<
name|ELFT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|mb
argument_list|)
operator|,
name|ctx
operator|)
block|{}
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|X86ELFFile
operator|>>
name|create
argument_list|(
argument|std::unique_ptr<MemoryBuffer> mb
argument_list|,
argument|X86LinkingContext&ctx
argument_list|)
block|{
return|return
name|std
operator|::
name|unique_ptr
operator|<
name|X86ELFFile
operator|<
name|ELFT
operator|>>
operator|(
name|new
name|X86ELFFile
operator|<
name|ELFT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|mb
argument_list|)
operator|,
name|ctx
operator|)
operator|)
return|;
block|}
expr|}
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|X86DynamicFile
operator|:
name|public
name|DynamicFile
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|X86DynamicFile
argument_list|(
argument|const X86LinkingContext&context
argument_list|,
argument|StringRef name
argument_list|)
operator|:
name|DynamicFile
operator|<
name|ELFT
operator|>
operator|(
name|context
operator|,
name|name
operator|)
block|{}
block|}
block|;  }
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

begin_comment
comment|// LLD_READER_WRITER_ELF_X86_X86_ELF_FILE_H
end_comment

end_unit


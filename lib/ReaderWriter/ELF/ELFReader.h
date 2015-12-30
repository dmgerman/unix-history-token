begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/ELFReader.h -----------------------------------===//
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
name|LLD_READER_WRITER_ELF_READER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_READER_H
end_define

begin_include
include|#
directive|include
file|"DynamicFile.h"
end_include

begin_include
include|#
directive|include
file|"ELFFile.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/File.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Reader.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ELF.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|template
operator|<
name|typename
name|FileT
operator|>
name|class
name|ELFReader
operator|:
name|public
name|Reader
block|{
name|public
operator|:
name|ELFReader
argument_list|(
name|ELFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|_ctx
argument_list|(
argument|ctx
argument_list|)
block|{}
name|bool
name|canParse
argument_list|(
argument|file_magic magic
argument_list|,
argument|MemoryBufferRef mb
argument_list|)
specifier|const
name|override
block|{
return|return
name|FileT
operator|::
name|canParse
argument_list|(
name|magic
argument_list|)
return|;
block|}
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
name|loadFile
argument_list|(
argument|std::unique_ptr<MemoryBuffer> mb
argument_list|,
argument|const class Registry&
argument_list|)
specifier|const
name|override
block|{
if|if
condition|(
name|std
operator|::
name|error_code
name|ec
operator|=
name|FileT
operator|::
name|isCompatible
argument_list|(
name|mb
operator|->
name|getMemBufferRef
argument_list|()
argument_list|,
name|_ctx
argument_list|)
condition|)
return|return
name|ec
return|;
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|ret
operator|=
name|llvm
operator|::
name|make_unique
operator|<
name|FileT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|mb
argument_list|)
operator|,
name|_ctx
operator|)
block|;
return|return
name|std
operator|::
name|move
argument_list|(
name|ret
argument_list|)
return|;
block|}
name|private
label|:
name|ELFLinkingContext
modifier|&
name|_ctx
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace elf
end_comment

begin_comment
unit|}
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_ELF_READER_H
end_comment

end_unit


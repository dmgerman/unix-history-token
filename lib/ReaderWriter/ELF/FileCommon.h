begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/FileCommon.h ----------------------------------===//
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
name|LLD_READER_WRITER_ELF_FILE_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_FILE_COMMON_H
end_define

begin_include
include|#
directive|include
file|"lld/ReaderWriter/ELFLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ELF.h"
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
name|class
name|ELFT
operator|>
name|std
operator|::
name|error_code
name|checkCompatibility
argument_list|(
argument|unsigned char size
argument_list|,
argument|unsigned char endian
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|ELFT
operator|>
name|std
operator|::
name|error_code
name|isCompatible
argument_list|(
argument|MemoryBufferRef mb
argument_list|,
argument|ELFLinkingContext&ctx
argument_list|)
block|{
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Ehdr_Impl
operator|<
name|ELFT
operator|>
name|Elf_Ehdr
expr_stmt|;
if|if
condition|(
name|uintptr_t
argument_list|(
name|mb
operator|.
name|getBufferStart
argument_list|()
argument_list|)
operator|&
literal|1
condition|)
return|return
name|make_dynamic_error_code
argument_list|(
literal|"invalid alignment"
argument_list|)
return|;
name|auto
operator|*
name|hdr
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|Elf_Ehdr
operator|*
operator|>
operator|(
name|mb
operator|.
name|getBuffer
argument_list|()
operator|.
name|data
argument_list|()
operator|)
expr_stmt|;
if|if
condition|(
name|hdr
operator|->
name|e_machine
operator|!=
name|ctx
operator|.
name|getMachineType
argument_list|()
condition|)
return|return
name|make_dynamic_error_code
argument_list|(
literal|"incompatible machine type"
argument_list|)
return|;
name|unsigned
name|char
name|size
decl_stmt|;
name|unsigned
name|char
name|endian
decl_stmt|;
name|std
operator|::
name|tie
argument_list|(
name|size
argument_list|,
name|endian
argument_list|)
operator|=
name|llvm
operator|::
name|object
operator|::
name|getElfArchType
argument_list|(
name|mb
operator|.
name|getBuffer
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|std
operator|::
name|error_code
name|ec
operator|=
name|checkCompatibility
operator|<
name|ELFT
operator|>
operator|(
name|size
operator|,
name|endian
operator|)
condition|)
return|return
name|ec
return|;
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace elf
end_comment

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


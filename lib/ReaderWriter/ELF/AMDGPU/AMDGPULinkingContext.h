begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/AMDGPU/AMDGPULinkingContext.h ---------------===//
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
name|LLD_READER_WRITER_ELF_AMDGPU_AMDGPU_LINKING_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_AMDGPU_AMDGPU_LINKING_CONTEXT_H
end_define

begin_include
include|#
directive|include
file|"OutputELFWriter.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/ELFLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ELF.h"
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
name|class
name|AMDGPULinkingContext
name|final
range|:
name|public
name|ELFLinkingContext
block|{
name|public
operator|:
name|AMDGPULinkingContext
argument_list|(
argument|llvm::Triple triple
argument_list|)
block|;
name|int
name|getMachineType
argument_list|()
specifier|const
name|override
block|{
return|return
name|llvm
operator|::
name|ELF
operator|::
name|EM_AMDGPU
return|;
block|}
name|void
name|registerRelocationNames
argument_list|(
argument|Registry&r
argument_list|)
name|override
block|;
name|StringRef
name|entrySymbolName
argument_list|()
specifier|const
name|override
block|; }
decl_stmt|;
name|void
name|setAMDGPUELFHeader
argument_list|(
name|ELFHeader
operator|<
name|ELF64LE
operator|>
operator|&
name|elfHeader
argument_list|)
decl_stmt|;
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

begin_comment
comment|// LLD_READER_WRITER_ELF_AMDGPU_AMDGPU_LINKING_CONTEXT_H
end_comment

end_unit


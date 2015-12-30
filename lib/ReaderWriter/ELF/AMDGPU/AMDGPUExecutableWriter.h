begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/AMDGPU/AMDGPUExecutableWriter.h ---------------===//
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
name|AMDGPU_EXECUTABLE_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPU_EXECUTABLE_WRITER_H
end_define

begin_include
include|#
directive|include
file|"ExecutableWriter.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPULinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPUSymbolTable.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPUTargetHandler.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|AMDGPUTargetLayout
decl_stmt|;
name|class
name|AMDGPUExecutableWriter
range|:
name|public
name|ExecutableWriter
operator|<
name|ELF64LE
operator|>
block|{
name|public
operator|:
name|AMDGPUExecutableWriter
argument_list|(
name|AMDGPULinkingContext
operator|&
name|ctx
argument_list|,
name|AMDGPUTargetLayout
operator|&
name|layout
argument_list|)
block|;
name|unique_bump_ptr
operator|<
name|SymbolTable
operator|<
name|ELF64LE
operator|>>
name|createSymbolTable
argument_list|()
name|override
block|{
return|return
name|unique_bump_ptr
operator|<
name|SymbolTable
operator|<
name|ELF64LE
operator|>>
operator|(
name|new
argument_list|(
argument|this->_alloc
argument_list|)
name|AMDGPUSymbolTable
argument_list|(
name|_ctx
argument_list|)
operator|)
return|;
block|}
name|void
name|createImplicitFiles
argument_list|(
argument|std::vector<std::unique_ptr<File>>&Result
argument_list|)
name|override
block|;
name|void
name|finalizeDefaultAtomValues
argument_list|()
name|override
block|;
name|private
operator|:
name|AMDGPULinkingContext
operator|&
name|_ctx
block|; }
decl_stmt|;
block|}
comment|// namespace elf
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDGPU_EXECUTABLE_WRITER_H
end_comment

end_unit


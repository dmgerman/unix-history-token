begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/AArch64/AArch64ExecutableWriter.h -------------===//
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
name|AARCH64_EXECUTABLE_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|AARCH64_EXECUTABLE_WRITER_H
end_define

begin_include
include|#
directive|include
file|"ExecutableWriter.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|AArch64TargetLayout
decl_stmt|;
name|class
name|AArch64LinkingContext
decl_stmt|;
name|class
name|AArch64ExecutableWriter
range|:
name|public
name|ExecutableWriter
operator|<
name|ELF64LE
operator|>
block|{
name|public
operator|:
name|AArch64ExecutableWriter
argument_list|(
name|AArch64LinkingContext
operator|&
name|ctx
argument_list|,
name|AArch64TargetLayout
operator|&
name|layout
argument_list|)
block|;
name|protected
operator|:
comment|// Add any runtime files and their atoms to the output
name|void
name|createImplicitFiles
argument_list|(
argument|std::vector<std::unique_ptr<File>>&
argument_list|)
name|override
block|;
name|void
name|buildDynamicSymbolTable
argument_list|(
argument|const File&file
argument_list|)
name|override
block|;
name|private
operator|:
name|AArch64TargetLayout
operator|&
name|_targetLayout
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

end_unit


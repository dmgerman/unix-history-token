begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------- lib/ReaderWriter/ELF/ARM/ARMExecutableWriter.h -------------===//
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
name|LLD_READER_WRITER_ELF_ARM_ARM_EXECUTABLE_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_ARM_ARM_EXECUTABLE_WRITER_H
end_define

begin_include
include|#
directive|include
file|"ExecutableWriter.h"
end_include

begin_include
include|#
directive|include
file|"ARMELFWriters.h"
end_include

begin_include
include|#
directive|include
file|"ARMLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"ARMTargetHandler.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|ARMExecutableWriter
range|:
name|public
name|ARMELFWriter
operator|<
name|ExecutableWriter
operator|<
name|ELF32LE
operator|>>
block|{
name|public
operator|:
name|ARMExecutableWriter
argument_list|(
name|ARMLinkingContext
operator|&
name|ctx
argument_list|,
name|ARMTargetLayout
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
name|processUndefinedSymbol
argument_list|(
argument|StringRef symName
argument_list|,
argument|RuntimeFile<ELF32LE>&file
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|ARMLinkingContext
operator|&
name|_ctx
block|; }
decl_stmt|;
name|ARMExecutableWriter
operator|::
name|ARMExecutableWriter
argument_list|(
name|ARMLinkingContext
operator|&
name|ctx
argument_list|,
name|ARMTargetLayout
operator|&
name|layout
argument_list|)
operator|:
name|ARMELFWriter
argument_list|(
name|ctx
argument_list|,
name|layout
argument_list|)
operator|,
name|_ctx
argument_list|(
argument|ctx
argument_list|)
block|{}
name|void
name|ARMExecutableWriter
operator|::
name|createImplicitFiles
argument_list|(
argument|std::vector<std::unique_ptr<File>>&result
argument_list|)
block|{
name|ExecutableWriter
operator|::
name|createImplicitFiles
argument_list|(
name|result
argument_list|)
block|;
comment|// Add default atoms for ARM.
if|if
condition|(
name|_ctx
operator|.
name|isDynamic
argument_list|()
condition|)
block|{
name|auto
name|file
init|=
name|llvm
operator|::
name|make_unique
operator|<
name|RuntimeFile
operator|<
name|ELF32LE
operator|>>
operator|(
name|_ctx
expr|,
literal|"ARM exec file"
operator|)
decl_stmt|;
name|file
operator|->
name|addAbsoluteAtom
argument_list|(
name|gotSymbol
argument_list|)
expr_stmt|;
name|file
operator|->
name|addAbsoluteAtom
argument_list|(
name|dynamicSymbol
argument_list|)
expr_stmt|;
name|result
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|file
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|void
name|ARMExecutableWriter
operator|::
name|processUndefinedSymbol
argument_list|(
argument|StringRef symName
argument_list|,
argument|RuntimeFile<ELF32LE>&file
argument_list|)
specifier|const
block|{
name|ARMELFWriter
operator|<
name|ExecutableWriter
operator|<
name|ELF32LE
operator|>>
operator|::
name|processUndefinedSymbol
argument_list|(
name|symName
argument_list|,
name|file
argument_list|)
block|;
if|if
condition|(
name|symName
operator|==
name|gotSymbol
condition|)
block|{
name|file
operator|.
name|addAbsoluteAtom
argument_list|(
name|gotSymbol
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|symName
operator|.
name|startswith
argument_list|(
literal|"__exidx"
argument_list|)
condition|)
block|{
name|file
operator|.
name|addAbsoluteAtom
argument_list|(
literal|"__exidx_start"
argument_list|)
expr_stmt|;
name|file
operator|.
name|addAbsoluteAtom
argument_list|(
literal|"__exidx_end"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|symName
operator|==
literal|"__ehdr_start"
condition|)
block|{
name|file
operator|.
name|addAbsoluteAtom
argument_list|(
literal|"__ehdr_start"
argument_list|)
expr_stmt|;
block|}
block|}
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
comment|// LLD_READER_WRITER_ELF_ARM_ARM_EXECUTABLE_WRITER_H
end_comment

end_unit


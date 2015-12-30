begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/ARM/ARMDynamicLibraryWriter.h -----------------===//
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
name|LLD_READER_WRITER_ELF_ARM_ARM_DYNAMIC_LIBRARY_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_ARM_ARM_DYNAMIC_LIBRARY_WRITER_H
end_define

begin_include
include|#
directive|include
file|"DynamicLibraryWriter.h"
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
name|ARMDynamicLibraryWriter
range|:
name|public
name|ARMELFWriter
operator|<
name|DynamicLibraryWriter
operator|<
name|ELF32LE
operator|>>
block|{
name|public
operator|:
name|ARMDynamicLibraryWriter
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
name|private
operator|:
name|ARMLinkingContext
operator|&
name|_ctx
block|; }
decl_stmt|;
name|ARMDynamicLibraryWriter
operator|::
name|ARMDynamicLibraryWriter
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
name|ARMDynamicLibraryWriter
operator|::
name|createImplicitFiles
argument_list|(
argument|std::vector<std::unique_ptr<File>>&result
argument_list|)
block|{
name|DynamicLibraryWriter
operator|::
name|createImplicitFiles
argument_list|(
name|result
argument_list|)
block|;
name|auto
name|file
operator|=
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
operator|,
literal|"ARM dynamic file"
operator|)
block|;
name|file
operator|->
name|addAbsoluteAtom
argument_list|(
name|gotSymbol
argument_list|)
block|;
name|file
operator|->
name|addAbsoluteAtom
argument_list|(
name|dynamicSymbol
argument_list|)
block|;
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
block|; }
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
comment|// LLD_READER_WRITER_ELF_ARM_ARM_DYNAMIC_LIBRARY_WRITER_H
end_comment

end_unit


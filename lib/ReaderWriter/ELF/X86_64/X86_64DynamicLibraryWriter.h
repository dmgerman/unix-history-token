begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/X86/X86_64DynamicLibraryWriter.h ---------------===//
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
name|X86_64_DYNAMIC_LIBRARY_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|X86_64_DYNAMIC_LIBRARY_WRITER_H
end_define

begin_include
include|#
directive|include
file|"DynamicLibraryWriter.h"
end_include

begin_include
include|#
directive|include
file|"X86_64LinkingContext.h"
end_include

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
name|X86_64DynamicLibraryWriter
range|:
name|public
name|DynamicLibraryWriter
operator|<
name|ELF64LE
operator|>
block|{
name|public
operator|:
name|X86_64DynamicLibraryWriter
argument_list|(
name|X86_64LinkingContext
operator|&
name|ctx
argument_list|,
name|X86_64TargetLayout
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
block|; }
decl_stmt|;
name|X86_64DynamicLibraryWriter
operator|::
name|X86_64DynamicLibraryWriter
argument_list|(
name|X86_64LinkingContext
operator|&
name|ctx
argument_list|,
name|X86_64TargetLayout
operator|&
name|layout
argument_list|)
operator|:
name|DynamicLibraryWriter
argument_list|(
argument|ctx
argument_list|,
argument|layout
argument_list|)
block|{}
name|void
name|X86_64DynamicLibraryWriter
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
name|gotFile
operator|=
name|llvm
operator|::
name|make_unique
operator|<
name|SimpleFile
operator|>
operator|(
literal|"GOTFile"
operator|)
block|;
name|gotFile
operator|->
name|addAtom
argument_list|(
operator|*
name|new
argument_list|(
argument|gotFile->allocator()
argument_list|)
name|GlobalOffsetTableAtom
argument_list|(
operator|*
name|gotFile
argument_list|)
argument_list|)
block|;
name|gotFile
operator|->
name|addAtom
argument_list|(
operator|*
name|new
argument_list|(
argument|gotFile->allocator()
argument_list|)
name|DynamicAtom
argument_list|(
operator|*
name|gotFile
argument_list|)
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
name|gotFile
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

end_unit


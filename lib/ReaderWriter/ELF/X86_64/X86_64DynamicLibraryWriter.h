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
file|"X86_64ElfType.h"
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
name|X86_64ELFType
operator|>
block|{
name|public
operator|:
name|X86_64DynamicLibraryWriter
argument_list|(
name|X86_64LinkingContext
operator|&
name|context
argument_list|,
name|X86_64TargetLayout
operator|&
name|layout
argument_list|)
block|;
name|protected
operator|:
comment|// Add any runtime files and their atoms to the output
name|virtual
name|bool
name|createImplicitFiles
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
operator|&
argument_list|)
block|;
name|virtual
name|void
name|finalizeDefaultAtomValues
argument_list|()
block|{
return|return
name|DynamicLibraryWriter
operator|::
name|finalizeDefaultAtomValues
argument_list|()
return|;
block|}
name|virtual
name|void
name|addDefaultAtoms
argument_list|()
block|{
return|return
name|DynamicLibraryWriter
operator|::
name|addDefaultAtoms
argument_list|()
return|;
block|}
name|private
operator|:
name|class
name|GOTFile
operator|:
name|public
name|SimpleFile
block|{
name|public
operator|:
name|GOTFile
argument_list|(
specifier|const
name|ELFLinkingContext
operator|&
name|eti
argument_list|)
operator|:
name|SimpleFile
argument_list|(
literal|"GOTFile"
argument_list|)
block|{}
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
block|;   }
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|GOTFile
operator|>
name|_gotFile
block|; }
decl_stmt|;
name|X86_64DynamicLibraryWriter
operator|::
name|X86_64DynamicLibraryWriter
argument_list|(
name|X86_64LinkingContext
operator|&
name|context
argument_list|,
name|X86_64TargetLayout
operator|&
name|layout
argument_list|)
operator|:
name|DynamicLibraryWriter
argument_list|(
name|context
argument_list|,
name|layout
argument_list|)
operator|,
name|_gotFile
argument_list|(
argument|new GOTFile(context)
argument_list|)
block|{}
name|bool
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
name|_gotFile
operator|->
name|addAtom
argument_list|(
operator|*
name|new
argument_list|(
argument|_gotFile->_alloc
argument_list|)
name|GLOBAL_OFFSET_TABLEAtom
argument_list|(
operator|*
name|_gotFile
argument_list|)
argument_list|)
block|;
name|_gotFile
operator|->
name|addAtom
argument_list|(
operator|*
name|new
argument_list|(
argument|_gotFile->_alloc
argument_list|)
name|DYNAMICAtom
argument_list|(
operator|*
name|_gotFile
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
name|_gotFile
argument_list|)
argument_list|)
block|;
return|return
name|true
return|;
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

end_unit


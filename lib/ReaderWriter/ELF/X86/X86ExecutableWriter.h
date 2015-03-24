begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/X86/X86ExecutableWriter.h ---------------------===//
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
name|X86_X86_EXECUTABLE_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|X86_X86_EXECUTABLE_WRITER_H
end_define

begin_include
include|#
directive|include
file|"ExecutableWriter.h"
end_include

begin_include
include|#
directive|include
file|"X86LinkingContext.h"
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
name|class
name|X86ExecutableWriter
operator|:
name|public
name|ExecutableWriter
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|X86ExecutableWriter
argument_list|(
name|X86LinkingContext
operator|&
name|context
argument_list|,
name|X86TargetLayout
operator|<
name|ELFT
operator|>
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
name|ExecutableWriter
operator|<
name|ELFT
operator|>
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
name|ExecutableWriter
operator|<
name|ELFT
operator|>
operator|::
name|addDefaultAtoms
argument_list|()
return|;
block|}
name|private
operator|:
name|X86LinkingContext
operator|&
name|_context
block|;
name|X86TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|_x86Layout
block|; }
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|X86ExecutableWriter
operator|<
name|ELFT
operator|>
operator|::
name|X86ExecutableWriter
argument_list|(
name|X86LinkingContext
operator|&
name|context
argument_list|,
name|X86TargetLayout
operator|<
name|ELFT
operator|>
operator|&
name|layout
argument_list|)
operator|:
name|ExecutableWriter
operator|<
name|ELFT
operator|>
operator|(
name|context
operator|,
name|layout
operator|)
operator|,
name|_context
argument_list|(
name|context
argument_list|)
operator|,
name|_x86Layout
argument_list|(
argument|layout
argument_list|)
block|{}
name|template
operator|<
name|class
name|ELFT
operator|>
name|bool
name|X86ExecutableWriter
operator|<
name|ELFT
operator|>
operator|::
name|createImplicitFiles
argument_list|(
argument|std::vector<std::unique_ptr<File>>&result
argument_list|)
block|{
name|ExecutableWriter
operator|<
name|ELFT
operator|>
operator|::
name|createImplicitFiles
argument_list|(
name|result
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


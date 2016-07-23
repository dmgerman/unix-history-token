begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/Core/Writer.h - Abstract File Format Interface -----------------===//
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
name|LLD_CORE_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_WRITER_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|File
decl_stmt|;
name|class
name|LinkingContext
decl_stmt|;
name|class
name|MachOLinkingContext
decl_stmt|;
comment|/// \brief The Writer is an abstract class for writing object files, shared
comment|/// library files, and executable files.  Each file format (e.g. mach-o, etc)
comment|/// has a concrete subclass of Writer.
name|class
name|Writer
block|{
name|public
label|:
name|virtual
operator|~
name|Writer
argument_list|()
expr_stmt|;
comment|/// \brief Write a file from the supplied File object
name|virtual
name|llvm
operator|::
name|Error
name|writeFile
argument_list|(
argument|const File&linkedFile
argument_list|,
argument|StringRef path
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief This method is called by Core Linking to give the Writer a chance
comment|/// to add file format specific "files" to set of files to be linked. This is
comment|/// how file format specific atoms can be added to the link.
name|virtual
name|void
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
block|{}
name|protected
label|:
comment|// only concrete subclasses can be instantiated
name|Writer
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Writer
operator|>
name|createWriterMachO
argument_list|(
specifier|const
name|MachOLinkingContext
operator|&
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Writer
operator|>
name|createWriterYAML
argument_list|(
specifier|const
name|LinkingContext
operator|&
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


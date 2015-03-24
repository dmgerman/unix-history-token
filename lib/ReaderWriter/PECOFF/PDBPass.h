begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/PECOFF/PDBPass.h ----------------------------------===//
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
name|LLD_READER_WRITER_PE_COFF_PDB_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_PE_COFF_PDB_PASS_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Process.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|pecoff
block|{
name|class
name|PDBPass
range|:
name|public
name|lld
operator|::
name|Pass
block|{
name|public
operator|:
name|PDBPass
argument_list|(
name|PECOFFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|_ctx
argument_list|(
argument|ctx
argument_list|)
block|{}
name|void
name|perform
argument_list|(
argument|std::unique_ptr<MutableFile>&file
argument_list|)
name|override
block|{
if|if
condition|(
name|_ctx
operator|.
name|getDebug
argument_list|()
condition|)
name|touch
argument_list|(
name|_ctx
operator|.
name|getPDBFilePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|private
operator|:
name|void
name|touch
argument_list|(
argument|StringRef path
argument_list|)
block|{
name|int
name|fd
block|;
if|if
condition|(
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|openFileForWrite
argument_list|(
name|path
argument_list|,
name|fd
argument_list|,
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|F_Append
argument_list|)
condition|)
name|llvm
operator|::
name|report_fatal_error
argument_list|(
literal|"failed to create a PDB file"
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|Process
operator|::
name|SafelyCloseFileDescriptor
argument_list|(
name|fd
argument_list|)
block|;   }
name|PECOFFLinkingContext
operator|&
name|_ctx
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace pecoff
end_comment

begin_comment
unit|}
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


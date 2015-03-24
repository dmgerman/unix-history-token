begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/PECOFF/WriterImportLibrary.h ----------------------===//
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
name|LLD_READER_WRITER_PE_COFF_WRITER_IMPORT_LIBRARY_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_PE_COFF_WRITER_IMPORT_LIBRARY_H
end_define

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|PECOFFLinkingContext
decl_stmt|;
name|namespace
name|pecoff
block|{
name|void
name|writeImportLibrary
parameter_list|(
specifier|const
name|PECOFFLinkingContext
modifier|&
name|ctx
parameter_list|)
function_decl|;
block|}
comment|// end namespace pecoff
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


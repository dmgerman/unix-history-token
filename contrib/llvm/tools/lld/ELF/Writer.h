begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Writer.h -------------------------------------------------*- C++ -*-===//
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
name|LLD_ELF_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_WRITER_H
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
block|}
end_decl_stmt

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
name|InputSectionBase
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ObjectFile
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|SymbolTable
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|writeResult
argument_list|(
name|SymbolTable
operator|<
name|ELFT
operator|>
operator|*
name|Symtab
argument_list|)
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|markLive
argument_list|()
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|llvm
operator|::
name|StringRef
name|getOutputSectionName
argument_list|(
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|S
argument_list|)
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|reportDiscarded
argument_list|(
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|IS
argument_list|,
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|elf
operator|::
name|ObjectFile
operator|<
name|ELFT
operator|>>
operator|&
name|File
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/X86_64/X86_64RelocationPass.h -----------------===//
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Declares the relocation processing pass for x86-64. This includes
end_comment

begin_comment
comment|///   GOT and PLT entries, TLS, COPY, and ifunc.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_ELF_X86_64_X86_64_RELOCATION_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_X86_64_X86_64_RELOCATION_PASS_H
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|Pass
decl_stmt|;
name|namespace
name|elf
block|{
name|class
name|X86_64LinkingContext
decl_stmt|;
comment|/// \brief Create x86-64 relocation pass for the given linking context.
name|std
operator|::
name|unique_ptr
operator|<
name|Pass
operator|>
name|createX86_64RelocationPass
argument_list|(
specifier|const
name|X86_64LinkingContext
operator|&
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


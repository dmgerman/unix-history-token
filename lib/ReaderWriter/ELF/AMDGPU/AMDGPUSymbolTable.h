begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------- lib/ReaderWriter/ELF/AMDGPU/AMDGPUSymbolTable.h ------------===//
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
name|LLD_READER_WRITER_ELF_AMDGPU_AMDGPU_SYMBOL_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_AMDGPU_AMDGPU_SYMBOL_TABLE_H
end_define

begin_include
include|#
directive|include
file|"TargetLayout.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|/// \brief The SymbolTable class represents the symbol table in a ELF file
name|class
name|AMDGPUSymbolTable
range|:
name|public
name|SymbolTable
operator|<
name|ELF64LE
operator|>
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Sym_Impl
operator|<
name|ELF64LE
operator|>
name|Elf_Sym
expr_stmt|;
name|AMDGPUSymbolTable
argument_list|(
specifier|const
name|ELFLinkingContext
operator|&
name|ctx
argument_list|)
decl_stmt|;
name|void
name|addDefinedAtom
argument_list|(
name|Elf_Sym
operator|&
name|sym
argument_list|,
specifier|const
name|DefinedAtom
operator|*
name|da
argument_list|,
name|int64_t
name|addr
argument_list|)
name|override
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// elf
end_comment

begin_comment
unit|}
comment|// lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit


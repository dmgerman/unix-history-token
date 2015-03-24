begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------- lib/ReaderWriter/ELF/ARM/ARMSymbolTable.h ------------------===//
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
name|LLD_READER_WRITER_ELF_ARM_ARM_SYMBOL_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_ARM_ARM_SYMBOL_TABLE_H
end_define

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|/// \brief The SymbolTable class represents the symbol table in a ELF file
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ARMSymbolTable
operator|:
name|public
name|SymbolTable
operator|<
name|ELFT
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
name|ELFT
operator|>
name|Elf_Sym
expr_stmt|;
name|ARMSymbolTable
argument_list|(
specifier|const
name|ELFLinkingContext
operator|&
name|context
argument_list|)
expr_stmt|;
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
name|template
operator|<
name|class
name|ELFT
operator|>
name|ARMSymbolTable
operator|<
name|ELFT
operator|>
operator|::
name|ARMSymbolTable
argument_list|(
specifier|const
name|ELFLinkingContext
operator|&
name|context
argument_list|)
operator|:
name|SymbolTable
operator|<
name|ELFT
operator|>
operator|(
name|context
operator|,
literal|".symtab"
operator|,
name|DefaultLayout
operator|<
name|ELFT
operator|>
operator|::
name|ORDER_SYMBOL_TABLE
operator|)
block|{}
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|ARMSymbolTable
operator|<
name|ELFT
operator|>
operator|::
name|addDefinedAtom
argument_list|(
argument|Elf_Sym&sym
argument_list|,
argument|const DefinedAtom *da
argument_list|,
argument|int64_t addr
argument_list|)
block|{
name|SymbolTable
operator|<
name|ELFT
operator|>
operator|::
name|addDefinedAtom
argument_list|(
name|sym
argument_list|,
name|da
argument_list|,
name|addr
argument_list|)
block|;
comment|// Set zero bit to distinguish symbols addressing Thumb instructions
if|if
condition|(
name|DefinedAtom
operator|::
name|codeARMThumb
operator|==
name|da
operator|->
name|codeModel
argument_list|()
condition|)
name|sym
operator|.
name|st_value
operator|=
name|static_cast
operator|<
name|int64_t
operator|>
operator|(
name|sym
operator|.
name|st_value
operator|)
operator||
literal|0x1
expr_stmt|;
block|}
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

begin_comment
comment|// LLD_READER_WRITER_ELF_ARM_ARM_SYMBOL_TABLE_H
end_comment

end_unit


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

begin_include
include|#
directive|include
file|"SectionChunks.h"
end_include

begin_include
include|#
directive|include
file|"TargetLayout.h"
end_include

begin_include
include|#
directive|include
file|"ARMELFFile.h"
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
name|ARMSymbolTable
range|:
name|public
name|SymbolTable
operator|<
name|ELF32LE
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
name|ELF32LE
operator|>
name|Elf_Sym
expr_stmt|;
name|ARMSymbolTable
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
name|ARMSymbolTable
operator|::
name|ARMSymbolTable
argument_list|(
specifier|const
name|ELFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|SymbolTable
argument_list|(
argument|ctx
argument_list|,
literal|".symtab"
argument_list|,
argument|TargetLayout<ELF32LE>::ORDER_SYMBOL_TABLE
argument_list|)
block|{}
name|void
name|ARMSymbolTable
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
if|if
condition|(
operator|(
name|ARMELFDefinedAtom
operator|::
name|ARMContentType
operator|)
name|da
operator|->
name|contentType
argument_list|()
operator|==
name|ARMELFDefinedAtom
operator|::
name|typeARMExidx
condition|)
name|sym
operator|.
name|st_value
operator|=
name|addr
expr_stmt|;
comment|// Set zero bit to distinguish real symbols addressing Thumb instructions.
comment|// Don't care about mapping symbols like $t and others.
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
comment|// Mapping symbols should have special values of binding, type and size set.
if|if
condition|(
operator|(
name|DefinedAtom
operator|::
name|codeARM_a
operator|==
name|da
operator|->
name|codeModel
argument_list|()
operator|)
operator|||
operator|(
name|DefinedAtom
operator|::
name|codeARM_d
operator|==
name|da
operator|->
name|codeModel
argument_list|()
operator|)
operator|||
operator|(
name|DefinedAtom
operator|::
name|codeARM_t
operator|==
name|da
operator|->
name|codeModel
argument_list|()
operator|)
condition|)
block|{
name|sym
operator|.
name|setBindingAndType
argument_list|(
name|llvm
operator|::
name|ELF
operator|::
name|STB_LOCAL
argument_list|,
name|llvm
operator|::
name|ELF
operator|::
name|STT_NOTYPE
argument_list|)
expr_stmt|;
name|sym
operator|.
name|st_size
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
unit|}
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


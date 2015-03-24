begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------- lib/ReaderWriter/ELF/ARM/ARMELFFile.h ----------------------===//
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
name|LLD_READER_WRITER_ELF_ARM_ARM_ELF_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_ARM_ARM_ELF_FILE_H
end_define

begin_include
include|#
directive|include
file|"ELFReader.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|ARMLinkingContext
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ARMELFDefinedAtom
operator|:
name|public
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
block|{
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
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Shdr_Impl
operator|<
name|ELFT
operator|>
name|Elf_Shdr
expr_stmt|;
name|public
label|:
name|ARMELFDefinedAtom
argument_list|(
argument|const ELFFile<ELFT>&file
argument_list|,
argument|StringRef symbolName
argument_list|,
argument|StringRef sectionName
argument_list|,
argument|const Elf_Sym *symbol
argument_list|,
argument|const Elf_Shdr *section
argument_list|,
argument|ArrayRef<uint8_t> contentData
argument_list|,
argument|unsigned int referenceStart
argument_list|,
argument|unsigned int referenceEnd
argument_list|,
argument|std::vector<ELFReference<ELFT> *>&referenceList
argument_list|)
block|:
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|(
name|file
operator|,
name|symbolName
operator|,
name|sectionName
operator|,
name|symbol
operator|,
name|section
operator|,
name|contentData
operator|,
name|referenceStart
operator|,
name|referenceEnd
operator|,
name|referenceList
operator|)
block|{}
name|bool
name|isThumbFunc
argument_list|(
argument|const Elf_Sym *symbol
argument_list|)
specifier|const
block|{
return|return
name|symbol
operator|->
name|getType
argument_list|()
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STT_FUNC
operator|&&
operator|(
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
name|symbol
operator|->
name|st_value
operator|)
operator|&
literal|0x1
operator|)
return|;
block|}
comment|/// Correct st_value for symbols addressing Thumb instructions
comment|/// by removing its zero bit.
name|uint64_t
name|getSymbolValue
argument_list|(
specifier|const
name|Elf_Sym
operator|*
name|symbol
argument_list|)
decl|const
name|override
block|{
specifier|const
specifier|auto
name|value
init|=
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
name|symbol
operator|->
name|st_value
operator|)
decl_stmt|;
return|return
name|isThumbFunc
argument_list|(
name|symbol
argument_list|)
condition|?
name|value
operator|&
operator|~
literal|0x1
else|:
name|value
return|;
block|}
name|DefinedAtom
operator|::
name|CodeModel
name|codeModel
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|isThumbFunc
argument_list|(
name|this
operator|->
name|_symbol
argument_list|)
condition|)
return|return
name|DefinedAtom
operator|::
name|codeARMThumb
return|;
return|return
name|DefinedAtom
operator|::
name|codeNA
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ARMELFFile
operator|:
name|public
name|ELFFile
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|ARMELFFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|mb
argument_list|,
name|ARMLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|ELFFile
operator|<
name|ELFT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|mb
argument_list|)
operator|,
name|ctx
operator|)
block|{}
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ARMELFFile
operator|>>
name|create
argument_list|(
argument|std::unique_ptr<MemoryBuffer> mb
argument_list|,
argument|ARMLinkingContext&ctx
argument_list|)
block|{
return|return
name|std
operator|::
name|unique_ptr
operator|<
name|ARMELFFile
operator|<
name|ELFT
operator|>>
operator|(
name|new
name|ARMELFFile
operator|<
name|ELFT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|mb
argument_list|)
operator|,
name|ctx
operator|)
operator|)
return|;
block|}
name|private
operator|:
end_expr_stmt

begin_typedef
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
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Shdr_Impl
operator|<
name|ELFT
operator|>
name|Elf_Shdr
expr_stmt|;
end_typedef

begin_comment
comment|/// Correct st_value for symbols addressing Thumb instructions
end_comment

begin_comment
comment|/// by removing its zero bit.
end_comment

begin_decl_stmt
name|uint64_t
name|getSymbolValue
argument_list|(
specifier|const
name|Elf_Sym
operator|*
name|symbol
argument_list|)
decl|const
name|override
block|{
specifier|const
specifier|auto
name|value
init|=
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
name|symbol
operator|->
name|st_value
operator|)
decl_stmt|;
return|return
name|symbol
operator|->
name|getType
argument_list|()
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STT_FUNC
condition|?
name|value
operator|&
operator|~
literal|0x1
else|:
name|value
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Process the Defined symbol and create an atom for it.
end_comment

begin_expr_stmt
name|ErrorOr
operator|<
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|handleDefinedSymbol
argument_list|(
argument|StringRef symName
argument_list|,
argument|StringRef sectionName
argument_list|,
argument|const Elf_Sym *sym
argument_list|,
argument|const Elf_Shdr *sectionHdr
argument_list|,
argument|ArrayRef<uint8_t> contentData
argument_list|,
argument|unsigned int referenceStart
argument_list|,
argument|unsigned int referenceEnd
argument_list|,
argument|std::vector<ELFReference<ELFT> *>&referenceList
argument_list|)
name|override
block|{
return|return
name|new
argument_list|(
argument|this->_readerStorage
argument_list|)
name|ARMELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|(
operator|*
name|this
operator|,
name|symName
operator|,
name|sectionName
operator|,
name|sym
operator|,
name|sectionHdr
operator|,
name|contentData
operator|,
name|referenceStart
operator|,
name|referenceEnd
operator|,
name|referenceList
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ARMDynamicFile
operator|:
name|public
name|DynamicFile
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|ARMDynamicFile
argument_list|(
argument|const ARMLinkingContext&context
argument_list|,
argument|StringRef name
argument_list|)
operator|:
name|DynamicFile
operator|<
name|ELFT
operator|>
operator|(
name|context
operator|,
name|name
operator|)
block|{}
block|}
expr_stmt|;
end_expr_stmt

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
comment|// LLD_READER_WRITER_ELF_ARM_ARM_ELF_FILE_H
end_comment

end_unit


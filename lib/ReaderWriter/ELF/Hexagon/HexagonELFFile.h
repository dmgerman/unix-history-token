begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/HexagonELFFile.h ------------------------------===//
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
name|LLD_READER_WRITER_ELF_HEXAGON_ELF_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_HEXAGON_ELF_FILE_H
end_define

begin_include
include|#
directive|include
file|"ELFReader.h"
end_include

begin_include
include|#
directive|include
file|"HexagonLinkingContext.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|HexagonELFFile
decl_stmt|;
name|class
name|HexagonELFDefinedAtom
range|:
name|public
name|ELFDefinedAtom
operator|<
name|ELF32LE
operator|>
block|{
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
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Shdr_Impl
operator|<
name|ELF32LE
operator|>
name|Elf_Shdr
expr_stmt|;
name|public
label|:
name|template
operator|<
name|typename
operator|...
name|T
operator|>
name|HexagonELFDefinedAtom
argument_list|(
name|T
operator|&&
operator|...
name|args
argument_list|)
operator|:
name|ELFDefinedAtom
argument_list|(
argument|std::forward<T>(args)...
argument_list|)
block|{}
name|DefinedAtom
operator|::
name|ContentType
name|contentType
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|_contentType
operator|!=
name|DefinedAtom
operator|::
name|typeUnknown
condition|)
return|return
name|_contentType
return|;
if|if
condition|(
name|_section
operator|->
name|sh_flags
operator|&
name|llvm
operator|::
name|ELF
operator|::
name|SHF_HEX_GPREL
condition|)
block|{
if|if
condition|(
name|_section
operator|->
name|sh_type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|SHT_NOBITS
condition|)
return|return
operator|(
name|_contentType
operator|=
name|DefinedAtom
operator|::
name|typeZeroFillFast
operator|)
return|;
return|return
operator|(
name|_contentType
operator|=
name|DefinedAtom
operator|::
name|typeDataFast
operator|)
return|;
block|}
return|return
name|ELFDefinedAtom
operator|::
name|contentType
argument_list|()
return|;
block|}
name|DefinedAtom
operator|::
name|ContentPermissions
name|permissions
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|_section
operator|->
name|sh_flags
operator|&
name|llvm
operator|::
name|ELF
operator|::
name|SHF_HEX_GPREL
condition|)
return|return
name|DefinedAtom
operator|::
name|permRW_
return|;
return|return
name|ELFDefinedAtom
operator|::
name|permissions
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
unit|};
name|class
name|HexagonELFCommonAtom
range|:
name|public
name|ELFCommonAtom
operator|<
name|ELF32LE
operator|>
block|{
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
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Shdr_Impl
operator|<
name|ELF32LE
operator|>
name|Elf_Shdr
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_macro
name|HexagonELFCommonAtom
argument_list|(
argument|const ELFFile<ELF32LE>&file
argument_list|,
argument|StringRef symbolName
argument_list|,
argument|const Elf_Sym *symbol
argument_list|)
end_macro

begin_macro
unit|:
name|ELFCommonAtom
argument_list|(
argument|file
argument_list|,
argument|symbolName
argument_list|,
argument|symbol
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|virtual
name|bool
name|isSmallCommonSymbol
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|_symbol
operator|->
name|st_shndx
condition|)
block|{
comment|// Common symbols
case|case
name|llvm
operator|::
name|ELF
operator|::
name|SHN_HEXAGON_SCOMMON
case|:
case|case
name|llvm
operator|::
name|ELF
operator|::
name|SHN_HEXAGON_SCOMMON_1
case|:
case|case
name|llvm
operator|::
name|ELF
operator|::
name|SHN_HEXAGON_SCOMMON_2
case|:
case|case
name|llvm
operator|::
name|ELF
operator|::
name|SHN_HEXAGON_SCOMMON_4
case|:
case|case
name|llvm
operator|::
name|ELF
operator|::
name|SHN_HEXAGON_SCOMMON_8
case|:
return|return
name|true
return|;
default|default:
break|break;
block|}
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_macro
unit|}    uint64_t
name|size
argument_list|()
end_macro

begin_expr_stmt
specifier|const
name|override
block|{
if|if
condition|(
name|isSmallCommonSymbol
argument_list|()
condition|)
return|return
name|_symbol
operator|->
name|st_size
return|;
end_expr_stmt

begin_return
return|return
name|ELFCommonAtom
operator|::
name|size
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    DefinedAtom
operator|::
name|Merge
name|merge
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|_symbol
operator|->
name|getBinding
argument_list|()
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STB_WEAK
condition|)
return|return
name|DefinedAtom
operator|::
name|mergeAsWeak
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|isSmallCommonSymbol
argument_list|()
condition|)
return|return
name|DefinedAtom
operator|::
name|mergeAsTentative
return|;
end_if

begin_return
return|return
name|ELFCommonAtom
operator|::
name|merge
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    DefinedAtom
operator|::
name|ContentType
name|contentType
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|isSmallCommonSymbol
argument_list|()
condition|)
return|return
name|DefinedAtom
operator|::
name|typeZeroFillFast
return|;
end_expr_stmt

begin_return
return|return
name|ELFCommonAtom
operator|::
name|contentType
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    DefinedAtom
operator|::
name|Alignment
name|alignment
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|isSmallCommonSymbol
argument_list|()
condition|)
return|return
name|DefinedAtom
operator|::
name|Alignment
argument_list|(
name|_symbol
operator|->
name|st_value
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
literal|1
return|;
end_return

begin_expr_stmt
unit|}    DefinedAtom
operator|::
name|ContentPermissions
name|permissions
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|isSmallCommonSymbol
argument_list|()
condition|)
return|return
name|DefinedAtom
operator|::
name|permRW_
return|;
end_expr_stmt

begin_return
return|return
name|ELFCommonAtom
operator|::
name|permissions
argument_list|()
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|HexagonELFFile
range|:
name|public
name|ELFFile
operator|<
name|ELF32LE
operator|>
block|{
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
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Shdr_Impl
operator|<
name|ELF32LE
operator|>
name|Elf_Shdr
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|HexagonELFFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|mb
argument_list|,
name|ELFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|ELFFile
argument_list|(
argument|std::move(mb)
argument_list|,
argument|ctx
argument_list|)
block|{}
name|bool
name|isCommonSymbol
argument_list|(
argument|const Elf_Sym *symbol
argument_list|)
specifier|const
name|override
block|{
switch|switch
condition|(
name|symbol
operator|->
name|st_shndx
condition|)
block|{
comment|// Common symbols
case|case
name|llvm
operator|::
name|ELF
operator|::
name|SHN_HEXAGON_SCOMMON
case|:
case|case
name|llvm
operator|::
name|ELF
operator|::
name|SHN_HEXAGON_SCOMMON_1
case|:
case|case
name|llvm
operator|::
name|ELF
operator|::
name|SHN_HEXAGON_SCOMMON_2
case|:
case|case
name|llvm
operator|::
name|ELF
operator|::
name|SHN_HEXAGON_SCOMMON_4
case|:
case|case
name|llvm
operator|::
name|ELF
operator|::
name|SHN_HEXAGON_SCOMMON_8
case|:
return|return
name|true
return|;
default|default:
break|break;
block|}
end_expr_stmt

begin_return
return|return
name|ELFFile
operator|::
name|isCommonSymbol
argument_list|(
name|symbol
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Process the Defined symbol and create an atom for it.
end_comment

begin_expr_stmt
unit|ELFDefinedAtom
operator|<
name|ELF32LE
operator|>
operator|*
name|createDefinedAtom
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
argument|std::vector<ELFReference<ELF32LE> *>&referenceList
argument_list|)
name|override
block|{
return|return
name|new
argument_list|(
argument|_readerStorage
argument_list|)
name|HexagonELFDefinedAtom
argument_list|(
operator|*
name|this
argument_list|,
name|symName
argument_list|,
name|sectionName
argument_list|,
name|sym
argument_list|,
name|sectionHdr
argument_list|,
name|contentData
argument_list|,
name|referenceStart
argument_list|,
name|referenceEnd
argument_list|,
name|referenceList
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Process the Common symbol and create an atom for it.
end_comment

begin_expr_stmt
name|ELFCommonAtom
operator|<
name|ELF32LE
operator|>
operator|*
name|createCommonAtom
argument_list|(
argument|StringRef symName
argument_list|,
argument|const Elf_Sym *sym
argument_list|)
name|override
block|{
return|return
name|new
argument_list|(
argument|_readerStorage
argument_list|)
name|HexagonELFCommonAtom
argument_list|(
operator|*
name|this
argument_list|,
name|symName
argument_list|,
name|sym
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
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
comment|// LLD_READER_WRITER_ELF_HEXAGON_ELF_FILE_H
end_comment

end_unit


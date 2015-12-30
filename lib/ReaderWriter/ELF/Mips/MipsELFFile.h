begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/MipsELFFile.h ---------------------------------===//
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
name|LLD_READER_WRITER_ELF_MIPS_MIPS_ELF_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_MIPS_MIPS_ELF_FILE_H
end_define

begin_include
include|#
directive|include
file|"ELFReader.h"
end_include

begin_include
include|#
directive|include
file|"MipsLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"MipsRelocationHandler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

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
name|MipsELFFile
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|MipsELFDefinedAtom
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
name|MipsELFDefinedAtom
argument_list|(
argument|const MipsELFFile<ELFT>&file
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
empty_stmt|;
specifier|const
name|MipsELFFile
operator|<
name|ELFT
operator|>
operator|&
name|file
argument_list|()
specifier|const
name|override
expr_stmt|;
name|DefinedAtom
operator|::
name|CodeModel
name|codeModel
argument_list|()
specifier|const
name|override
expr_stmt|;
name|bool
name|isPIC
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|MipsELFReference
operator|:
name|public
name|ELFReference
operator|<
name|ELFT
operator|>
block|{
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Rel_Impl
operator|<
name|ELFT
operator|,
name|false
operator|>
name|Elf_Rel
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Rel_Impl
operator|<
name|ELFT
operator|,
name|true
operator|>
name|Elf_Rela
expr_stmt|;
name|public
label|:
name|MipsELFReference
argument_list|(
argument|uint64_t symValue
argument_list|,
argument|const Elf_Rela&rel
argument_list|)
empty_stmt|;
name|MipsELFReference
argument_list|(
argument|uint64_t symValue
argument_list|,
argument|const Elf_Rel&rel
argument_list|)
empty_stmt|;
name|uint32_t
name|tag
argument_list|()
specifier|const
name|override
block|{
return|return
name|_tag
return|;
block|}
name|void
name|setTag
parameter_list|(
name|uint32_t
name|tag
parameter_list|)
block|{
name|_tag
operator|=
name|tag
expr_stmt|;
block|}
name|private
label|:
name|uint32_t
name|_tag
decl_stmt|;
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
name|MipsELFFile
operator|:
name|public
name|ELFFile
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
name|MipsELFFile
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
block|;
name|bool
name|isPIC
argument_list|()
specifier|const
block|;
comment|/// \brief gp register value stored in the .reginfo section.
name|int64_t
name|getGP0
argument_list|()
specifier|const
block|{
return|return
name|_gp0
return|;
block|}
comment|/// \brief .tdata section address plus fixed offset.
name|uint64_t
name|getTPOffset
argument_list|()
specifier|const
block|{
return|return
name|_tpOff
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|uint64_t
name|getDTPOffset
argument_list|()
specifier|const
block|{
return|return
name|_dtpOff
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|error_code
name|doParse
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

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

begin_typedef
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Rel
name|Elf_Rel
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Rela
name|Elf_Rela
expr_stmt|;
end_typedef

begin_enum
enum|enum
block|{
name|TP_OFFSET
init|=
literal|0x7000
block|,
name|DTP_OFFSET
init|=
literal|0x8000
block|}
enum|;
end_enum

begin_decl_stmt
name|int64_t
name|_gp0
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint64_t
name|_tpOff
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint64_t
name|_dtpOff
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ELFDefinedAtom
operator|<
name|ELFT
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
argument|std::vector<ELFReference<ELFT> *>&referenceList
argument_list|)
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|createRelocationReferences
argument_list|(
specifier|const
name|Elf_Sym
operator|*
name|symbol
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|content
argument_list|,
name|range
operator|<
specifier|const
name|Elf_Rela
operator|*
operator|>
name|rels
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|createRelocationReferences
argument_list|(
specifier|const
name|Elf_Sym
operator|*
name|symbol
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|symContent
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|secContent
argument_list|,
specifier|const
name|Elf_Shdr
operator|*
name|RelSec
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|Elf_Shdr
modifier|*
name|findSectionByType
argument_list|(
name|uint64_t
name|type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|Elf_Shdr
modifier|*
name|findSectionByFlags
argument_list|(
name|uint64_t
name|flags
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Ehdr
name|Elf_Ehdr
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Mips_RegInfo
operator|<
name|ELFT
operator|>
name|Elf_Mips_RegInfo
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Mips_Options
operator|<
name|ELFT
operator|>
name|Elf_Mips_Options
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Mips_ABIFlags
operator|<
name|ELFT
operator|>
name|Elf_Mips_ABIFlags
expr_stmt|;
end_typedef

begin_expr_stmt
name|ErrorOr
operator|<
specifier|const
name|Elf_Mips_RegInfo
operator|*
operator|>
name|findRegInfoSec
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ErrorOr
operator|<
specifier|const
name|Elf_Mips_ABIFlags
operator|*
operator|>
name|findAbiFlagsSec
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|error_code
name|readAuxData
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Reference
operator|::
name|Addend
name|readAddend
argument_list|(
argument|const Elf_Rel&ri
argument_list|,
argument|const ArrayRef<uint8_t> content
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|getPairRelocation
argument_list|(
specifier|const
name|Elf_Shdr
operator|*
name|Symtab
argument_list|,
specifier|const
name|Elf_Rel
operator|&
name|rel
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|Elf_Rel
modifier|*
name|findMatchingRelocation
argument_list|(
name|uint32_t
name|pairRelType
argument_list|,
specifier|const
name|Elf_Rel
operator|*
name|rit
argument_list|,
specifier|const
name|Elf_Rel
operator|*
name|eit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isLocalBinding
argument_list|(
specifier|const
name|Elf_Shdr
operator|*
name|Symtab
argument_list|,
specifier|const
name|Elf_Rel
operator|&
name|rel
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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

end_unit


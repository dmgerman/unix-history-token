begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSectionELF.h - ELF Machine Code Sections ---------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
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
comment|//
end_comment

begin_comment
comment|// This file declares the MCSectionELF class.
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
name|LLVM_MC_MCSECTIONELF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSECTIONELF_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MCSectionELF - This represents a section on linux, lots of unix variants
comment|/// and some bare metal systems.
name|class
name|MCSectionELF
range|:
name|public
name|MCSection
block|{
comment|/// SectionName - This is the name of the section.  The referenced memory is
comment|/// owned by TargetLoweringObjectFileELF's ELFUniqueMap.
name|StringRef
name|SectionName
block|;
comment|/// Type - This is the sh_type field of a section, drawn from the enums below.
name|unsigned
name|Type
block|;
comment|/// Flags - This is the sh_flags field of a section, drawn from the enums.
comment|/// below.
name|unsigned
name|Flags
block|;
comment|/// IsExplicit - Indicates that this section comes from globals with an
comment|/// explicit section specified.
name|bool
name|IsExplicit
block|;
name|private
operator|:
name|friend
name|class
name|MCContext
block|;
name|MCSectionELF
argument_list|(
argument|StringRef Section
argument_list|,
argument|unsigned type
argument_list|,
argument|unsigned flags
argument_list|,
argument|SectionKind K
argument_list|,
argument|bool isExplicit
argument_list|)
operator|:
name|MCSection
argument_list|(
name|SV_ELF
argument_list|,
name|K
argument_list|)
block|,
name|SectionName
argument_list|(
name|Section
argument_list|)
block|,
name|Type
argument_list|(
name|type
argument_list|)
block|,
name|Flags
argument_list|(
name|flags
argument_list|)
block|,
name|IsExplicit
argument_list|(
argument|isExplicit
argument_list|)
block|{}
operator|~
name|MCSectionELF
argument_list|()
block|;
name|public
operator|:
comment|/// ShouldOmitSectionDirective - Decides whether a '.section' directive
comment|/// should be printed before the section name
name|bool
name|ShouldOmitSectionDirective
argument_list|(
argument|StringRef Name
argument_list|,
argument|const MCAsmInfo&MAI
argument_list|)
specifier|const
block|;
comment|/// ShouldPrintSectionType - Only prints the section type if supported
name|bool
name|ShouldPrintSectionType
argument_list|(
argument|unsigned Ty
argument_list|)
specifier|const
block|;
comment|/// HasCommonSymbols - True if this section holds common symbols, this is
comment|/// indicated on the ELF object file by a symbol with SHN_COMMON section
comment|/// header index.
name|bool
name|HasCommonSymbols
argument_list|()
specifier|const
block|;
comment|/// These are the section type and flags fields.  An ELF section can have
comment|/// only one Type, but can have more than one of the flags specified.
comment|///
comment|/// Valid section types.
block|enum
block|{
comment|// This value marks the section header as inactive.
name|SHT_NULL
operator|=
literal|0x00U
block|,
comment|// Holds information defined by the program, with custom format and meaning.
name|SHT_PROGBITS
operator|=
literal|0x01U
block|,
comment|// This section holds a symbol table.
name|SHT_SYMTAB
operator|=
literal|0x02U
block|,
comment|// The section holds a string table.
name|SHT_STRTAB
operator|=
literal|0x03U
block|,
comment|// The section holds relocation entries with explicit addends.
name|SHT_RELA
operator|=
literal|0x04U
block|,
comment|// The section holds a symbol hash table.
name|SHT_HASH
operator|=
literal|0x05U
block|,
comment|// Information for dynamic linking.
name|SHT_DYNAMIC
operator|=
literal|0x06U
block|,
comment|// The section holds information that marks the file in some way.
name|SHT_NOTE
operator|=
literal|0x07U
block|,
comment|// A section of this type occupies no space in the file.
name|SHT_NOBITS
operator|=
literal|0x08U
block|,
comment|// The section holds relocation entries without explicit addends.
name|SHT_REL
operator|=
literal|0x09U
block|,
comment|// This section type is reserved but has unspecified semantics.
name|SHT_SHLIB
operator|=
literal|0x0AU
block|,
comment|// This section holds a symbol table.
name|SHT_DYNSYM
operator|=
literal|0x0BU
block|,
comment|// This section contains an array of pointers to initialization functions.
name|SHT_INIT_ARRAY
operator|=
literal|0x0EU
block|,
comment|// This section contains an array of pointers to termination functions.
name|SHT_FINI_ARRAY
operator|=
literal|0x0FU
block|,
comment|// This section contains an array of pointers to functions that are invoked
comment|// before all other initialization functions.
name|SHT_PREINIT_ARRAY
operator|=
literal|0x10U
block|,
comment|// A section group is a set of sections that are related and that must be
comment|// treated specially by the linker.
name|SHT_GROUP
operator|=
literal|0x11U
block|,
comment|// This section is associated with a section of type SHT_SYMTAB, when the
comment|// referenced symbol table contain the escape value SHN_XINDEX
name|SHT_SYMTAB_SHNDX
operator|=
literal|0x12U
block|,
name|LAST_KNOWN_SECTION_TYPE
operator|=
name|SHT_SYMTAB_SHNDX
block|}
block|;
comment|/// Valid section flags.
block|enum
block|{
comment|// The section contains data that should be writable.
name|SHF_WRITE
operator|=
literal|0x1U
block|,
comment|// The section occupies memory during execution.
name|SHF_ALLOC
operator|=
literal|0x2U
block|,
comment|// The section contains executable machine instructions.
name|SHF_EXECINSTR
operator|=
literal|0x4U
block|,
comment|// The data in the section may be merged to eliminate duplication.
name|SHF_MERGE
operator|=
literal|0x10U
block|,
comment|// Elements in the section consist of null-terminated character strings.
name|SHF_STRINGS
operator|=
literal|0x20U
block|,
comment|// A field in this section holds a section header table index.
name|SHF_INFO_LINK
operator|=
literal|0x40U
block|,
comment|// Adds special ordering requirements for link editors.
name|SHF_LINK_ORDER
operator|=
literal|0x80U
block|,
comment|// This section requires special OS-specific processing to avoid incorrect
comment|// behavior.
name|SHF_OS_NONCONFORMING
operator|=
literal|0x100U
block|,
comment|// This section is a member of a section group.
name|SHF_GROUP
operator|=
literal|0x200U
block|,
comment|// This section holds Thread-Local Storage.
name|SHF_TLS
operator|=
literal|0x400U
block|,
comment|// Start of target-specific flags.
comment|/// XCORE_SHF_CP_SECTION - All sections with the "c" flag are grouped
comment|/// together by the linker to form the constant pool and the cp register is
comment|/// set to the start of the constant pool by the boot code.
name|XCORE_SHF_CP_SECTION
operator|=
literal|0x800U
block|,
comment|/// XCORE_SHF_DP_SECTION - All sections with the "d" flag are grouped
comment|/// together by the linker to form the data section and the dp register is
comment|/// set to the start of the section by the boot code.
name|XCORE_SHF_DP_SECTION
operator|=
literal|0x1000U
block|}
block|;
name|StringRef
name|getSectionName
argument_list|()
specifier|const
block|{
return|return
name|SectionName
return|;
block|}
name|unsigned
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
name|void
name|PrintSwitchToSection
argument_list|(
argument|const MCAsmInfo&MAI
argument_list|,
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
comment|/// isBaseAddressKnownZero - We know that non-allocatable sections (like
comment|/// debug info) have a base of zero.
name|virtual
name|bool
name|isBaseAddressKnownZero
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|SHF_ALLOC
operator|)
operator|==
literal|0
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCSection *S
argument_list|)
block|{
return|return
name|S
operator|->
name|getVariant
argument_list|()
operator|==
name|SV_ELF
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCSectionELF *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

